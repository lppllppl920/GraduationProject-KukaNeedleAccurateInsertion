/*
 * Interface.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: lxt12
 */

#include "Interface.h"


Interface::Interface(QWidget *parent):
		controller_() {

	ROS_INFO("Interface Constructing...");

	setupUi(this);

	node_handle_ = boost::make_shared<ros::NodeHandle>("");

//-------------------------------Settings----------------------------------------------


	// GUI related
		// Interaction Tab
	connect(pushButton_VisualizeJointPlan, SIGNAL(clicked()), this, SLOT(visualizeJointPlan()));
	connect(pushButton_VisualizePosePlan, SIGNAL(clicked()), this, SLOT(visualizePosePlan()));
	connect(pushButton_ExecutePlan, SIGNAL(clicked()), this, SLOT(executeMotionPlan()));
	connect(pushButton_CopyJointState, SIGNAL(clicked()), this, SLOT(copyJointState()));
	connect(pushButton_AddWaypoint, SIGNAL(clicked()), &controller_, SLOT(addWaypointsCb()));
	connect(pushButton_ExecuteWaypointsPlan, SIGNAL(clicked()), &controller_, SLOT(visualizeExecutePlanCb()));
	connect(pushButton_Do, SIGNAL(clicked()), this, SLOT(manipulateCollisionObject()));
		// Single Command Tab
/*	connect(send_config_button, SIGNAL(clicked()), this, SLOT(on_send_config_button_clicked()));
	connect(send_axis_button, SIGNAL(clicked()), this, SLOT(on_send_axis_button_clicked()));
	connect(send_pos_button, SIGNAL(clicked()), this, SLOT(on_send_pos_button_clicked()));
	connect(send_frame_button, SIGNAL(clicked()), this, SLOT(on_send_frame_button_clicked()));
	connect(copy_button, SIGNAL(clicked()), this, SLOT(on_copy_button_clicked()));
	connect(default_button, SIGNAL(clicked()), this, SLOT(on_default_button_clicked()));
	connect(debug_button, SIGNAL(clicked()), this, SLOT(on_debug_button_clicked()));
	connect(pause_buf_buton, SIGNAL(clicked()), this, SLOT(on_pause_buf_buton_clicked()));
	connect(pause_button, SIGNAL(clicked()), this, SLOT(on_pause_button_clicked()));
	connect(terminate_buf_button, SIGNAL(clicked()), this, SLOT(on_terminate_buf_button_clicked()));
	connect(terminate_imm_button, SIGNAL(clicked()), this, SLOT(on_terminate_imm_button_clicked()));
	connect(stop_button, SIGNAL(clicked()), this, SLOT(on_stop_button_clicked())); */

	// Others related
	connect(this,
			SIGNAL(
					sendTrajectory(const TrajectoryGoal&)),
			&controller_,
			SLOT(
					sendTrajectory(const TrajectoryGoal&)));

	connect(&controller_,
			SIGNAL(
					newFeedback(Feedback& )),
			this,
			SLOT(
					newFeedbackReceived(Feedback& )), Qt::DirectConnection);

	connect(&controller_,
			SIGNAL(
					newFeedback(Feedback& )),
			this,
			SLOT(
					displayFeedback(Feedback& )), Qt::DirectConnection);

	connect(&controller_,
			SIGNAL(
					shutdown()),
			this,
			SLOT(
					shutdown()));
	// When motion plan is obtain in controller_, transfer plan to interface object for visualization
	connect(&controller_,
			SIGNAL(
					visualizeMotionPlan(MotionPlan)),
			this,
			SLOT(
					visualizeMotionPlan(MotionPlan)));
	connect(this,
			SIGNAL(addWaypoints()),
			&controller_,
			SLOT(addWaypointsCb()));
	connect(this,
			SIGNAL(
					visualizeExecutePlan()),
			&controller_,
			SLOT(
					visualizeExecutePlanCb()));
	connect(this,
			SIGNAL(endEffectorPos(const InteractiveMarkerFeedbackConstPtr&)),
			&controller_,
			SLOT(endEffectorPosCb(const InteractiveMarkerFeedbackConstPtr&)));

	// Set publisher for planned path display
	display_publisher_ =
			node_handle_->advertise<moveit_msgs::DisplayTrajectory>(
					"/move_group/display_planned_path", 1, true);

	// Set publisher for joint state visualization
	joint_state_publisher_ = node_handle_->advertise<sensor_msgs::JointState>(
			"/joint_states", 1000, true);
	joint_state_subscriber_ = node_handle_->subscribe<sensor_msgs::JointState, Interface>(
			"/joint_states", 10, &Interface::jointStatesCb, this);

	// Set subscriber for obtaining interactive marker position
	interactive_marker_subsriber_ =
			node_handle_->subscribe<
					visualization_msgs::InteractiveMarkerFeedback, Interface>(
					"/rviz_moveit_motion_planning_display/robot_interaction_interactive_marker_topic/feedback",
					10, &Interface::endEffectorPosCb, this);

	// Set subscriber for Motion trajectory execution
	motion_trajectory_subsriber_ = node_handle_->subscribe<
			control_msgs::FollowJointTrajectoryActionGoal, Interface>(
			"/joint_trajectory_action/goal", 10,
			&Interface::trajectoryActionCb, this);

	planning_scene_diff_publisher_ = node_handle_->advertise<moveit_msgs::PlanningScene>("/planning_scene", 1);


//--------------------------Initialization----------------------------------------------------
	// Set up menu marker
	marker_pos_ = 0.0;
	interactive_marker_server_.reset( new interactive_markers::InteractiveMarkerServer("moveit_test","",false) );
	initMenu();
	makeMenuMarker("marker1");
	menu_handler_.apply(*interactive_marker_server_, "marker1");
	interactive_marker_server_->applyChanges();

	// initialize joint state publish count
	joint_state_publish_count_ = 0;

	// pointer to plannar_
	plannar_ptr_ = boost::shared_ptr<Plannar>(controller_.getPlannar());

	collision_operation_counter_ = 0;
}

Interface::~Interface() {
	ROS_INFO("Interface Deconstructing...");
}

// Slots function
	//call back function for GUI push button
void Interface::manipulateCollisionObject() {

    int shape_index = comboBox_Shape->currentIndex();
    int operation_index = comboBox_Operation->currentIndex();

    moveit_msgs::CollisionObject collision_object;
    std::vector<double> collision_dimensions;
    collision_dimensions.resize(3);

    shape_msgs::SolidPrimitive collision_primitive;
    // This line has to be done, or the segmentation fault error will appear
    collision_primitive.dimensions.resize(3);

    geometry_msgs::Pose collision_pose;

	QListWidgetItem* collision_item = new QListWidgetItem;

	moveit_msgs::PlanningScene planning_scene;

    if(operation_index == 0) {
    	ROS_INFO("Add collision object");
		collision_dimensions[0] = lineEdit_X_Radius->text().toDouble();
		collision_dimensions[1] = lineEdit_Y_Height->text().toDouble();
		collision_dimensions[2] = lineEdit_Z->text().toDouble();

		ROS_INFO("Shape: %d", shape_index);
		switch(shape_index) {
			case 0:	{
				// BOX
				collision_primitive.dimensions[collision_primitive.BOX_X] = collision_dimensions[0];
				collision_primitive.dimensions[collision_primitive.BOX_Y] = collision_dimensions[1];
				collision_primitive.dimensions[collision_primitive.BOX_Z] = collision_dimensions[2];
				collision_primitive.type = collision_primitive.BOX;
				break;
			}
			case 1: {
				// SPHERE
				collision_primitive.dimensions[collision_primitive.SPHERE_RADIUS] = collision_dimensions[0];
				collision_primitive.type = collision_primitive.SPHERE;
				break;
			}
			case 2: {
				// CYLINDER
				collision_primitive.dimensions[collision_primitive.CYLINDER_RADIUS] = collision_dimensions[0];
				collision_primitive.dimensions[collision_primitive.CYLINDER_HEIGHT] = collision_dimensions[1];
				collision_primitive.type = collision_primitive.CYLINDER;
				break;
			}
			case 3: {
				// CONE
				collision_primitive.dimensions[collision_primitive.CONE_RADIUS] = collision_dimensions[0];
				collision_primitive.dimensions[collision_primitive.CONE_HEIGHT] = collision_dimensions[1];
				collision_primitive.type = collision_primitive.CONE;
				break;
			}
			default: {
				ROS_ERROR("shape index not found");
				return;
			}
		}

		collision_pose.position.x = lineEdit_TransX->text().toDouble();
		collision_pose.position.y = lineEdit_TransY->text().toDouble();
		collision_pose.position.z = lineEdit_TransZ->text().toDouble();

		collision_pose.orientation.w = lineEdit_RotateW->text().toDouble();
		collision_pose.orientation.x = lineEdit_RotateX->text().toDouble();
		collision_pose.orientation.y = lineEdit_RotateY->text().toDouble();
		collision_pose.orientation.z = lineEdit_RotateZ->text().toDouble();

		collision_object.operation = collision_object.ADD;
		collision_object.primitive_poses.push_back(collision_pose);
		collision_object.primitives.push_back(collision_primitive);
		collision_object.header.frame_id = "world";
		collision_object.id = lineEdit_Z_2->text().toStdString();
		collision_object.header.stamp = ros::Time::now();
		collision_object.header.seq = collision_operation_counter_++;

		planning_scene.world.collision_objects.clear();
		planning_scene.world.collision_objects.push_back(collision_object);

		planning_scene.is_diff = true;
		planning_scene_diff_publisher_.publish(planning_scene);

		collision_item->setText(lineEdit_Z_2->text());
		listWidget_CurrentCollisionObject->insertItem(1, collision_item);


    } else if(operation_index == 1){
    	ROS_INFO("Remove collision object");

    	collision_object.operation = collision_object.REMOVE;
    	collision_object.id = listWidget_CurrentCollisionObject->currentItem()->text().toStdString();

    	planning_scene.world.collision_objects.clear();
    	planning_scene.world.collision_objects.push_back(collision_object);
    	planning_scene.is_diff = true;

    	planning_scene_diff_publisher_.publish(planning_scene);

    	listWidget_CurrentCollisionObject->removeItemWidget(listWidget_CurrentCollisionObject->currentItem());
    	delete listWidget_CurrentCollisionObject->currentItem();
    }

}
void Interface::visualizeJointPlan() {
	std::map<std::string, double> target_joints;
	target_joints["joint1"] = lineEdit_Joint1->text().toDouble() / 180.0 * M_PI;
	target_joints["joint2"] = lineEdit_Joint2->text().toDouble() / 180.0 * M_PI;
	target_joints["joint3"] = lineEdit_Joint3->text().toDouble() / 180.0 * M_PI;
	target_joints["joint4"] = lineEdit_Joint4->text().toDouble() / 180.0 * M_PI;
	target_joints["joint5"] = lineEdit_Joint5->text().toDouble() / 180.0 * M_PI;
	target_joints["joint6"] = lineEdit_Joint6->text().toDouble() / 180.0 * M_PI;

	controller_.planTargetMotion(target_joints);

}
	//call back function for GUI push button
void Interface::visualizePosePlan() {
	geometry_msgs::Pose target_pose;
	target_pose.position.x = lineEdit_TransX->text().toDouble();
	target_pose.position.y = lineEdit_TransY->text().toDouble();
	target_pose.position.z = lineEdit_TransZ->text().toDouble();

	target_pose.orientation.x = lineEdit_RotateX->text().toDouble();
	target_pose.orientation.y = lineEdit_RotateY->text().toDouble();
	target_pose.orientation.z = lineEdit_RotateZ->text().toDouble();
	target_pose.orientation.w = lineEdit_RotateW->text().toDouble();

	double scale = sqrt(target_pose.orientation.w * target_pose.orientation.w +
			target_pose.orientation.x * target_pose.orientation.x +
			target_pose.orientation.y * target_pose.orientation.y +
			target_pose.orientation.z * target_pose.orientation.z);
	// Normalize orientation vector
	target_pose.orientation.w /= scale;
	target_pose.orientation.x /= scale;
	target_pose.orientation.y /= scale;
	target_pose.orientation.z /= scale;

	controller_.planTargetMotion(target_pose);
}
void Interface::copyJointState() {

	lineEdit_Joint1->setText(lineEdit_Joint1_S->text());
	lineEdit_Joint2->setText(lineEdit_Joint2_S->text());
	lineEdit_Joint3->setText(lineEdit_Joint3_S->text());
	lineEdit_Joint4->setText(lineEdit_Joint4_S->text());
	lineEdit_Joint5->setText(lineEdit_Joint5_S->text());
	lineEdit_Joint6->setText(lineEdit_Joint6_S->text());
}

void Interface::executeMotionPlan(){

	controller_.executeMotionPlan();
}

void Interface::newFeedbackReceived(Feedback& feedback) {

	joint_state_publish_count_++;
	joint_state_.header.seq = joint_state_publish_count_;
	joint_state_.position[0] = feedback.getAxis().A1 / 180.0 * M_PI;
	joint_state_.position[1] = feedback.getAxis().A2 / 180.0 * M_PI;
	joint_state_.position[2] = feedback.getAxis().A3 / 180.0 * M_PI;
	joint_state_.position[3] = feedback.getAxis().A4 / 180.0 * M_PI;
	joint_state_.position[4] = feedback.getAxis().A5 / 180.0 * M_PI;
	joint_state_.position[5] = feedback.getAxis().A6 / 180.0 * M_PI;
	joint_state_.header.stamp = ros::Time::now();
	joint_state_publisher_.publish(joint_state_);

	// Display feedback of joint state
	lineEdit_Joint1_S->setText(QString::number(feedback.getAxis().A1));
	lineEdit_Joint2_S->setText(QString::number(feedback.getAxis().A2));
	lineEdit_Joint3_S->setText(QString::number(feedback.getAxis().A3));
	lineEdit_Joint4_S->setText(QString::number(feedback.getAxis().A4));
	lineEdit_Joint5_S->setText(QString::number(feedback.getAxis().A5));
	lineEdit_Joint6_S->setText(QString::number(feedback.getAxis().A6));
}
void Interface::visualizeMotionPlan(
		moveit::planning_interface::MoveGroup::Plan motion_plan) {

	ROS_INFO("Visualizing plan");

	display_trajectory_.trajectory_start = motion_plan.start_state_;
	display_trajectory_.trajectory.push_back(motion_plan.trajectory_);

	display_publisher_.publish(display_trajectory_);
}
void Interface::shutdown() {
	QApplication::exit();
	//spinner_->stop();
	ros::shutdown();
}

// Callback function
void Interface::trajectoryActionCb(const TrajectoryGoal& feedback) {
	ROS_INFO("Trajectory received.");
	emit sendTrajectory(feedback);
}
void Interface::addWaypointsCb() {
	ROS_INFO("Interface: add way points callback");
	emit addWaypoints();
}
void Interface::visualizeExecutePlanCb() {
	ROS_INFO("Interface: visualize and execute plan callback");
	emit visualizeExecutePlan();
}
void Interface::endEffectorPosCb(
		const InteractiveMarkerFeedbackConstPtr &feedback) {
	lineEdit_TransX->setText(QString::number(feedback->pose.position.x));
	lineEdit_TransY->setText(QString::number(feedback->pose.position.y));
	lineEdit_TransZ->setText(QString::number(feedback->pose.position.z));
	lineEdit_RotateX->setText(QString::number(feedback->pose.orientation.x));
	lineEdit_RotateY->setText(QString::number(feedback->pose.orientation.y));
	lineEdit_RotateZ->setText(QString::number(feedback->pose.orientation.z));
	lineEdit_RotateW->setText(QString::number(feedback->pose.orientation.w));
	emit endEffectorPos(feedback);
}
void addWaypointsCb_global(const InteractiveMarkerFeedbackConstPtr &feedback) {
	// The Workaround of the MenuHandler insert function problem
	ROS_INFO("Global: add way points");
	kuka_interface->addWaypointsCb();
}
void visualizeExecutePlanCb_global(const InteractiveMarkerFeedbackConstPtr &feedback) {
	// The Workaround of the MenuHandler insert function problem
	ROS_INFO("Global: visualize and execute plan");
	kuka_interface->visualizeExecutePlanCb();
}
void Interface::jointStatesCb(const sensor_msgs::JointStateConstPtr &feedback) {

	lineEdit_Joint1_S->setText(QString::number(feedback->position[0] / M_PI * 180.0));
	lineEdit_Joint2_S->setText(QString::number(feedback->position[1] / M_PI * 180.0));
	lineEdit_Joint3_S->setText(QString::number(feedback->position[2] / M_PI * 180.0));
	lineEdit_Joint4_S->setText(QString::number(feedback->position[3] / M_PI * 180.0));
	lineEdit_Joint5_S->setText(QString::number(feedback->position[4] / M_PI * 180.0));
	lineEdit_Joint6_S->setText(QString::number(feedback->position[5] / M_PI * 180.0));

}


// Menu Interaction related
Marker Interface::makeBox(InteractiveMarker &msg) {
	Marker marker;

	marker.type = Marker::CUBE;
	marker.scale.x = msg.scale * 0.45;
	marker.scale.y = msg.scale * 0.45;
	marker.scale.z = msg.scale * 0.45;
	marker.color.r = 0.5;
	marker.color.g = 0.5;
	marker.color.b = 0.5;
	marker.color.a = 0;

	return marker;
}
InteractiveMarkerControl& Interface::makeBoxControl(InteractiveMarker &msg) {
	InteractiveMarkerControl control;
	control.always_visible = false;
	control.markers.push_back(makeBox(msg));
	msg.controls.push_back(control);

	return msg.controls.back();
}
InteractiveMarker Interface::makeEmptyMarker(bool dummyBox = true) {
	InteractiveMarker int_marker;
	int_marker.header.frame_id = "base_link";
	int_marker.pose.position.y = -3.0 * marker_pos_++;
	int_marker.scale = 1;

	return int_marker;
}
void Interface::makeMenuMarker(std::string name) {
	InteractiveMarker int_marker = makeEmptyMarker();
	int_marker.name = name;

	InteractiveMarkerControl control;

	control.interaction_mode = InteractiveMarkerControl::BUTTON;
	control.always_visible = false;

	control.markers.push_back(makeBox(int_marker));
	int_marker.controls.push_back(control);

	interactive_marker_server_->insert(int_marker);
}
void Interface::initMenu() {

	menu_entry_.push_back(menu_handler_.insert("Add into way points", addWaypointsCb_global));
	menu_entry_.push_back(menu_handler_.insert("Visualize and Execute motion plan", visualizeExecutePlanCb_global));
}

// Functions for Sing Command Tab
void Interface::on_send_frame_button_clicked() {
	Frame f(input_x->toPlainText().toFloat(),
			input_y->toPlainText().toFloat(),
			input_z->toPlainText().toFloat(),
			input_a->toPlainText().toFloat(),
			input_b->toPlainText().toFloat(),
			input_c->toPlainText().toFloat());
	Command::Style style;
	Command::Approx approx;
	if (comboBox_approx->currentText() == "C_PTP")
		approx = Command::C_PTP;
	else if (comboBox_approx->currentText() == "C_VEL")
		approx = Command::C_VEL;
	else if (comboBox_approx->currentText() == "C_DIS")
		approx = Command::C_DIS;
	else if (comboBox_approx->currentText() == "C_ORI")
		approx = Command::C_ORI;
	else if (comboBox_approx->currentText() == "None")
		approx = Command::NONE;
	else {
		std::cout << "To Frame: Approx. not recognized, None is used"
				<< std::endl;
		approx = Command::NONE;
	}

	if (comboBox_style->currentText() == "PTP")
		style = Command::PTP;
	else if (comboBox_style->currentText() == "LIN")
		style = Command::LIN;
	else if (comboBox_style->currentText() == "CIRC") {
		std::cout << "To Frame: CIRC command not supported in GUI, PTP is used"
				<< std::endl;
		style = Command::PTP;
	} else {
		std::cout << "To Frame: Style not recognized, PTP is used" << std::endl;
		style = Command::PTP;
	}

	ROS_INFO("Send frame button clicked");
	plannar_ptr_->motion(style, f, approx);
}

void Interface::on_send_axis_button_clicked() {
	Axis a(input_a1->toPlainText().toFloat(),
			input_a2->toPlainText().toFloat(),
			input_a3->toPlainText().toFloat(),
			input_a4->toPlainText().toFloat(),
			input_a5->toPlainText().toFloat(),
			input_a6->toPlainText().toFloat());

	Command::Style style;
	Command::Approx approx;
	if (comboBox_approx->currentText() == "C_PTP")
		approx = Command::C_PTP;
	else if (comboBox_approx->currentText() == "C_VEL")
		approx = Command::C_VEL;
	else if (comboBox_approx->currentText() == "C_DIS")
		approx = Command::C_DIS;
	else if (comboBox_approx->currentText() == "C_ORI")
		approx = Command::C_ORI;
	else if (comboBox_approx->currentText() == "None")
		approx = Command::NONE;
	else {
		std::cout << "To Axis: Approx. not recognized, None is used"
				<< std::endl;
		approx = Command::NONE;
	}

	if (comboBox_style->currentText() == "PTP")
		style = Command::PTP;
	else if (comboBox_style->currentText() == "LIN")
		style = Command::LIN;
	else if (comboBox_style->currentText() == "CIRC") {
		std::cout << "To Axis: CIRC command not supported in GUI, PTP is used"
				<< std::endl;
		style = Command::PTP;
	} else {
		std::cout << "To Axis: Style not recognized, PTP is used" << std::endl;
		style = Command::PTP;
	}

	ROS_INFO("Send axis button clicked");
	plannar_ptr_->motion(style, a, approx);
}

void Interface::on_send_pos_button_clicked() {
	Frame f(input_x->toPlainText().toFloat(),
			input_y->toPlainText().toFloat(),
			input_z->toPlainText().toFloat(),
			input_a->toPlainText().toFloat(),
			input_b->toPlainText().toFloat(),
			input_c->toPlainText().toFloat());
	Pos p(f, input_s->toPlainText().toInt(),
			input_t->toPlainText().toInt());

	Command::Style style;
	Command::Approx approx;
	if (comboBox_approx->currentText() == "C_PTP")
		approx = Command::C_PTP;
	else if (comboBox_approx->currentText() == "C_VEL")
		approx = Command::C_VEL;
	else if (comboBox_approx->currentText() == "C_DIS")
		approx = Command::C_DIS;
	else if (comboBox_approx->currentText() == "C_ORI")
		approx = Command::C_ORI;
	else if (comboBox_approx->currentText() == "None")
		approx = Command::NONE;
	else {
		std::cout << "To Pos: Approx. not recognized, None is used"
				<< std::endl;
		approx = Command::NONE;
	}

	if (comboBox_style->currentText() == "PTP")
		style = Command::PTP;
	else if (comboBox_style->currentText() == "LIN")
		style = Command::LIN;
	else if (comboBox_style->currentText() == "CIRC") {
		std::cout << "To Pos: CIRC command not supported in GUI, PTP is used"
				<< std::endl;
		style = Command::PTP;
	} else {
		std::cout << "To Pos: Style not recognized, PTP is used" << std::endl;
		style = Command::PTP;
	}

	ROS_INFO("Send pos button clicked");
	plannar_ptr_->motion(style, p, approx);
}

void Interface::displayFeedback(Feedback& fb) {
	if (fb.getSetOK() && fb.getParsedOK()) {
		output_x->setText(QString("%1").arg(fb.getFrame().X, 8, 'f', 4));
		output_y->setText(QString("%1").arg(fb.getFrame().Y, 8, 'f', 4));
		output_z->setText(QString("%1").arg(fb.getFrame().Z, 8, 'f', 4));
		output_a->setText(QString("%1").arg(fb.getFrame().A, 8, 'f', 4));
		output_b->setText(QString("%1").arg(fb.getFrame().B, 8, 'f', 4));
		output_c->setText(QString("%1").arg(fb.getFrame().C, 8, 'f', 4));

		output_a1->setText(QString("%1").arg(fb.getAxis().A1, 8, 'f', 4));
		output_a2->setText(QString("%1").arg(fb.getAxis().A2, 8, 'f', 4));
		output_a3->setText(QString("%1").arg(fb.getAxis().A3, 8, 'f', 4));
		output_a4->setText(QString("%1").arg(fb.getAxis().A4, 8, 'f', 4));
		output_a5->setText(QString("%1").arg(fb.getAxis().A5, 8, 'f', 4));
		output_a6->setText(QString("%1").arg(fb.getAxis().A6, 8, 'f', 4));

		output_s->setText(QString::number(fb.getPos().S));
		output_t->setText(QString::number(fb.getPos().T));

		output_buf_front->setText(QString::number(fb.getBufferFront()));
		output_buf_last->setText(QString::number(fb.getBufferLast()));

		output_seq->setText(QString::number(fb.getSeq()));
		output_result->setText(QString::number(fb.getStamp()));

		if (fb.getText() != "Timer Feedback")
			output_message->setText(QString::fromStdString(fb.getText()));

		if (fb.getBufferExtreme() == Feedback::Full) {
			QPalette pf = output_buf_front->palette();
			pf.setColor(QPalette::Base, QColor(170, 0, 0));
			output_buf_front->setPalette(pf);

			QPalette pl = output_buf_last->palette();
			pl.setColor(QPalette::Base, QColor(170, 0, 0));
			output_buf_last->setPalette(pl);
		} else {
			QPalette pf = output_buf_front->palette();
			pf.setColor(QPalette::Base, QColor(0, 170, 0));
			output_buf_front->setPalette(pf);

			QPalette pl = output_buf_last->palette();
			pl.setColor(QPalette::Base, QColor(0, 170, 0));
			output_buf_last->setPalette(pl);
		}

		if (fb.getSuccess() == 0 && fb.getType() == Feedback::Hybrid) {
			QPalette pr = output_result->palette();
			pr.setColor(QPalette::Base, QColor(170, 0, 0));
			output_result->setPalette(pr);
		} else if (fb.getType() == Feedback::Hybrid) {
			QPalette pr = output_result->palette();
			pr.setColor(QPalette::Base, QColor(0, 170, 0));
			output_result->setPalette(pr);
		}

		setAlignment();
	} else {
		output_message->setText("Feedback parsing failed");
		QPalette pm = output_message->palette();
		pm.setColor(QPalette::Base, QColor(170, 0, 0));
		output_message->setPalette(pm);

		setAlignment();
	}
}

void Interface::on_copy_button_clicked() {
	input_x->setText(output_x->toPlainText());
	input_y->setText(output_y->toPlainText());
	input_z->setText(output_z->toPlainText());
	input_a->setText(output_a->toPlainText());
	input_b->setText(output_b->toPlainText());
	input_c->setText(output_c->toPlainText());

	input_s->setText(output_s->toPlainText());
	input_t->setText(output_t->toPlainText());

	input_a1->setText(output_a1->toPlainText());
	input_a2->setText(output_a2->toPlainText());
	input_a3->setText(output_a3->toPlainText());
	input_a4->setText(output_a4->toPlainText());
	input_a5->setText(output_a5->toPlainText());
	input_a6->setText(output_a6->toPlainText());

	ROS_INFO("Copy button clicked");
	setAlignment();
}

void Interface::on_default_button_clicked() {
	input_x->setText(QString("%1").arg( DEFAULT_X, 8, 'f', 4));
	input_y->setText(QString("%1").arg( DEFAULT_Y, 8, 'f', 4));
	input_z->setText(QString("%1").arg( DEFAULT_Z, 8, 'f', 4));
	input_a->setText(QString("%1").arg( DEFAULT_A, 8, 'f', 4));
	input_b->setText(QString("%1").arg( DEFAULT_B, 8, 'f', 4));
	input_c->setText(QString("%1").arg( DEFAULT_C, 8, 'f', 4));

	input_s->setText(QString::number(DEFAULT_S));
	input_t->setText(QString::number(DEFAULT_T));

	input_a1->setText(QString("%1").arg( DEFAULT_A1, 8, 'f', 4));
	input_a2->setText(QString("%1").arg( DEFAULT_A2, 8, 'f', 4));
	input_a3->setText(QString("%1").arg( DEFAULT_A3, 8, 'f', 4));
	input_a4->setText(QString("%1").arg( DEFAULT_A4, 8, 'f', 4));
	input_a5->setText(QString("%1").arg( DEFAULT_A5, 8, 'f', 4));
	input_a6->setText(QString("%1").arg( DEFAULT_A6, 8, 'f', 4));

	ROS_INFO("Default button clicked");
	setAlignment();
}

void Interface::on_debug_button_clicked() {
	ROS_INFO("Debug button clicked");
	plannar_ptr_->test();
}

void Interface::on_send_config_button_clicked() {
	Command::Param param;
	float value;
	int ok = true;
	if (comboBox_config->currentText() == "$ADVANCE")
		param = Command::ADVANCE;
	else if (comboBox_config->currentText() == "$ACC_PTP")
		param = Command::ACC_PTP;
	else if (comboBox_config->currentText() == "$VEL_PTP")
		param = Command::VEL_PTP;
	else if (comboBox_config->currentText() == "$ACC_CP")
		param = Command::ACC_CP;
	else if (comboBox_config->currentText() == "$ACC.ORI1")
		param = Command::ACC_ORI1;
	else if (comboBox_config->currentText() == "$ACC.ORI2")
		param = Command::ACC_ORI2;
	else if (comboBox_config->currentText() == "$VEL_CP")
		param = Command::VEL_CP;
	else if (comboBox_config->currentText() == "$VEL.ORI1")
		param = Command::VEL_ORI1;
	else if (comboBox_config->currentText() == "$VEL.ORI2")
		param = Command::VEL_ORI2;
	else if (comboBox_config->currentText() == "$APO.CPTP")
		param = Command::APO_CPTP;
	else if (comboBox_config->currentText() == "$APO.CDIS")
		param = Command::APO_CDIS;
	else if (comboBox_config->currentText() == "$APO.CVEL")
		param = Command::APO_CVEL;
	else if (comboBox_config->currentText() == "$APO.CORI")
		param = Command::APO_CORI;
	else {
		std::cout << "Config: Parameter not recognized" << std::endl;
		ok = false;
	}
	value = input_config->toPlainText().toFloat();
	if (ok)
		plannar_ptr_->configuration(param, value);

	ROS_INFO("Send config button clicked");

}

void Interface::on_pause_buf_buton_clicked() {
	plannar_ptr_->pauseBuffered();
	ROS_INFO("Pause buffer button clicked");
}

void Interface::on_terminate_imm_button_clicked() {
	plannar_ptr_->terminateImmediately();
	ROS_INFO("Terminate immediately button clicked");
}

void Interface::on_pause_button_clicked() {
	plannar_ptr_->pauseImmediately();
	ROS_INFO("Pause immediately button clicked");
}

void Interface::on_stop_button_clicked() {
	plannar_ptr_->stop();
	ROS_INFO("Stop button clicked");
}

void Interface::on_terminate_buf_button_clicked() {
	plannar_ptr_->terminateBuffered();
	ROS_INFO("Terminate buffer button clicked");
}


void Interface::setAlignment() {
	input_x->setAlignment(Qt::AlignRight);
	input_y->setAlignment(Qt::AlignRight);
	input_z->setAlignment(Qt::AlignRight);
	input_a->setAlignment(Qt::AlignRight);
	input_b->setAlignment(Qt::AlignRight);
	input_c->setAlignment(Qt::AlignRight);
	input_a1->setAlignment(Qt::AlignRight);
	input_a2->setAlignment(Qt::AlignRight);
	input_a3->setAlignment(Qt::AlignRight);
	input_a4->setAlignment(Qt::AlignRight);
	input_a5->setAlignment(Qt::AlignRight);
	input_a6->setAlignment(Qt::AlignRight);
	input_s->setAlignment(Qt::AlignRight);
	input_t->setAlignment(Qt::AlignRight);

	output_x->setAlignment(Qt::AlignRight);
	output_y->setAlignment(Qt::AlignRight);
	output_z->setAlignment(Qt::AlignRight);
	output_a->setAlignment(Qt::AlignRight);
	output_b->setAlignment(Qt::AlignRight);
	output_c->setAlignment(Qt::AlignRight);
	output_a1->setAlignment(Qt::AlignRight);
	output_a2->setAlignment(Qt::AlignRight);
	output_a3->setAlignment(Qt::AlignRight);
	output_a4->setAlignment(Qt::AlignRight);
	output_a5->setAlignment(Qt::AlignRight);
	output_a6->setAlignment(Qt::AlignRight);

	output_buf_front->setAlignment(Qt::AlignRight);
	output_buf_last->setAlignment(Qt::AlignRight);
	output_result->setAlignment(Qt::AlignRight);
	output_s->setAlignment(Qt::AlignRight);
	output_t->setAlignment(Qt::AlignRight);
	output_seq->setAlignment(Qt::AlignRight);

	input_config->setAlignment(Qt::AlignRight);
	output_message->setAlignment(Qt::AlignLeft);
}

