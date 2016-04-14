/**
 *   Copyright (C) Tsinghua University 2016
 *
 *   Version   : 2.0
 *   Date      : 2016
 *   Author    : Xingtong Liu
 *   Company   : Tsinghua University
 *   Email     : 327586708@qq.com
 */

#include "Interface.h"

Interface::Interface(QWidget *parent) :
		controller_(), last_Axis_(0,0,0,0,0,0) {

	ROS_INFO("Interface Constructing...");

	setupUi(this);
	setAlignment();

	// pointer to node handle
	node_handle_ = boost::make_shared<ros::NodeHandle>("");

	// GUI related
	connect(pushButton_VisualizeJointPlan, SIGNAL(clicked()), this,
			SLOT(visualizeJointPlan()));
	connect(pushButton_VisualizePosePlan, SIGNAL(clicked()), this,
			SLOT(visualizePosePlan()));
	connect(pushButton_ExecutePlan, SIGNAL(clicked()), this,
			SLOT(executeMotionPlan()));
	connect(pushButton_AddWaypoint, SIGNAL(clicked()), this,
			SLOT(addWaypoints()));
	connect(pushButton_ExecuteWaypointsPlan, SIGNAL(clicked()), &controller_,
			SLOT(visualizeExecutePlanCb()));
	connect(pushButton_Do, SIGNAL(clicked()), this,
			SLOT(manipulateCollisionObject()));
	connect(pushButton_ConvertPosetoJoint, SIGNAL(clicked()), this,
			SLOT(convertPoseTargettoJointTarget()));
	connect(pushButton_VisualizeIncrPosePlan, SIGNAL(clicked()), this,
			SLOT(visualizeIncrPosePlan()));
	connect(pushButton_VisualizeRotatePlan, SIGNAL(clicked()), this,
			SLOT(rotateAroundAxis()));
	connect(pushButton_ExecuteRotatePlan, SIGNAL(clicked()), this,
			SLOT(executeMotionPlan()));

	// Others related
	connect(this, SIGNAL(sendTrajectory(const TrajectoryGoal&)), &controller_,
			SLOT(sendTrajectory(const TrajectoryGoal&)));

	connect(&controller_, SIGNAL(newFeedback(Feedback* )), this,
			SLOT(newFeedbackReceived(Feedback* )));

	connect(&controller_, SIGNAL(newFeedback(Feedback* )), this,
			SLOT(displayFeedback(Feedback* )));

	connect(&controller_, SIGNAL(shutdown()), this, SLOT(shutdown()));
	// When motion plan is obtain in controller_, transfer plan to interface object for visualization
	connect(&controller_, SIGNAL(visualizeMotionPlan(MotionPlan)), this,
			SLOT(visualizeMotionPlan(MotionPlan)));
	connect(this, SIGNAL(addWaypointsSignal()), &controller_, SLOT(addWaypointsCb()));
	connect(this, SIGNAL(visualizeExecutePlan()), &controller_,
			SLOT(visualizeExecutePlanCb()));
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

	// Set subscriber for obtaining interactive marker position
	interactive_marker_subsriber_ =
			node_handle_->subscribe<
					visualization_msgs::InteractiveMarkerFeedback, Interface>(
					"/rviz_moveit_motion_planning_display/robot_interaction_interactive_marker_topic/feedback",
					10, &Interface::endEffectorPosCb, this);

	// Set subscriber for Motion trajectory execution
	motion_trajectory_subsriber_ = node_handle_->subscribe<
			control_msgs::FollowJointTrajectoryActionGoal, Interface>(
			"/joint_trajectory_action/goal", 10, &Interface::trajectoryActionCb,
			this);

	planning_scene_diff_publisher_ = node_handle_->advertise<
			moveit_msgs::PlanningScene>("/planning_scene", 1);

	// Set up menu marker
	marker_pos_ = 0.0;
	interactive_marker_server_.reset(
			new interactive_markers::InteractiveMarkerServer("moveit_test", "",
					false));
	initMenu();
	makeMenuMarker("marker1");
	menu_handler_.apply(*interactive_marker_server_, "marker1");
	interactive_marker_server_->applyChanges();

	// initialize joint state publish count
	joint_state_publish_count_ = 0;
	// allocate memory for position variable
	joint_state_.position.resize(6);
	joint_state_.name.resize(6);
	joint_state_.name[0] = "joint1";
	joint_state_.name[1] = "joint2";
	joint_state_.name[2] = "joint3";
	joint_state_.name[3] = "joint4";
	joint_state_.name[4] = "joint5";
	joint_state_.name[5] = "joint6";
	joint_state_display_counter_ = 0;
	joint_state_callback_counter_ = 0;

	// pointer to plannar_
	plannar_ptr_ = boost::shared_ptr<Plannar>(controller_.getPlannar());

	collision_operation_counter_ = 0;
}

Interface::~Interface() {
	ROS_INFO("Interface Deconstructing...");
	QApplication::exit();
	ros::shutdown();
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

	geometry_msgs::Pose::_orientation_type collision_quaternion;
	std::vector<double> collision_euler_angle;

	if (operation_index == 0) {
		ROS_INFO("Add collision object");
		collision_dimensions[0] = lineEdit_X_Radius->text().toDouble();
		collision_dimensions[1] = lineEdit_Y_Height->text().toDouble();
		collision_dimensions[2] = lineEdit_Z->text().toDouble();

		ROS_INFO("Shape: %d", shape_index);
		switch (shape_index) {
		case 0: {
			// BOX
			collision_primitive.dimensions[collision_primitive.BOX_X] =
					collision_dimensions[0];
			collision_primitive.dimensions[collision_primitive.BOX_Y] =
					collision_dimensions[1];
			collision_primitive.dimensions[collision_primitive.BOX_Z] =
					collision_dimensions[2];
			collision_primitive.type = collision_primitive.BOX;
			break;
		}
		case 1: {
			// SPHERE
			collision_primitive.dimensions[collision_primitive.SPHERE_RADIUS] =
					collision_dimensions[0];
			collision_primitive.type = collision_primitive.SPHERE;
			break;
		}
		case 2: {
			// CYLINDER
			collision_primitive.dimensions[collision_primitive.CYLINDER_RADIUS] =
					collision_dimensions[0];
			collision_primitive.dimensions[collision_primitive.CYLINDER_HEIGHT] =
					collision_dimensions[1];
			collision_primitive.type = collision_primitive.CYLINDER;
			break;
		}
		case 3: {
			// CONE
			collision_primitive.dimensions[collision_primitive.CONE_RADIUS] =
					collision_dimensions[0];
			collision_primitive.dimensions[collision_primitive.CONE_HEIGHT] =
					collision_dimensions[1];
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

		std::vector<double> euler_angle(3);
		euler_angle[0] = lineEdit_RotateA->text().toDouble() / 180.0 * M_PI;
		euler_angle[1] = lineEdit_RotateB->text().toDouble() / 180.0 * M_PI;
		euler_angle[2] = lineEdit_RotateC->text().toDouble() / 180.0 * M_PI;

		KDL::Rotation rotation = KDL::Rotation::RPY(euler_angle[2], euler_angle[1], euler_angle[0]);
		rotation.GetQuaternion(collision_pose.orientation.x, collision_pose.orientation.y, collision_pose.orientation.z, collision_pose.orientation.w);

		collision_object.operation = collision_object.ADD;
		collision_object.primitive_poses.push_back(collision_pose);
		collision_object.primitives.push_back(collision_primitive);
		collision_object.header.frame_id = "world";
		collision_object.id = lineEdit_CollisionID->text().toStdString();
		collision_object.header.stamp = ros::Time::now();
		collision_object.header.seq = collision_operation_counter_++;

		planning_scene.world.collision_objects.clear();
		planning_scene.world.collision_objects.push_back(collision_object);

		planning_scene.is_diff = true;
		planning_scene_diff_publisher_.publish(planning_scene);

		collision_item->setText(lineEdit_CollisionID->text());
		listWidget_CurrentCollisionObject->insertItem(1, collision_item);

	} else if (operation_index == 1) {
		ROS_INFO("Remove collision object");

		collision_object.operation = collision_object.REMOVE;
		collision_object.id =
				listWidget_CurrentCollisionObject->currentItem()->text().toStdString();

		planning_scene.world.collision_objects.clear();
		planning_scene.world.collision_objects.push_back(collision_object);
		planning_scene.is_diff = true;

		planning_scene_diff_publisher_.publish(planning_scene);

		listWidget_CurrentCollisionObject->removeItemWidget(
				listWidget_CurrentCollisionObject->currentItem());
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
void Interface::visualizePosePlan() {
	geometry_msgs::Pose target_pose;
	target_pose.position.x = lineEdit_TransX->text().toDouble();
	target_pose.position.y = lineEdit_TransY->text().toDouble();
	target_pose.position.z = lineEdit_TransZ->text().toDouble();

	std::vector<double> euler_angle(3);
	euler_angle[0] = lineEdit_RotateA->text().toDouble() / 180.0 * M_PI;
	euler_angle[1] = lineEdit_RotateB->text().toDouble() / 180.0 * M_PI;
	euler_angle[2] = lineEdit_RotateC->text().toDouble() / 180.0 * M_PI;

	KDL::Rotation rotation = KDL::Rotation::RPY(euler_angle[2], euler_angle[1], euler_angle[0]);
	rotation.GetQuaternion(target_pose.orientation.x, target_pose.orientation.y, target_pose.orientation.z, target_pose.orientation.w);

	//Axis2Frame()
	controller_.planTargetMotion(target_pose);
}
void Interface::visualizeIncrPosePlan() {
	geometry_msgs::Pose target_pose;
	target_pose.position.x = output_x->toPlainText().toDouble() / 1000.0 + lineEdit_incrTransX->text().toDouble();
	target_pose.position.y = output_y->toPlainText().toDouble() / 1000.0 + lineEdit_incrTransY->text().toDouble();
	target_pose.position.z = output_z->toPlainText().toDouble() / 1000.0 + lineEdit_incrTransZ->text().toDouble();

	std::vector<double> euler_angle(3);
	euler_angle[0] = output_a->toPlainText().toDouble() / 180.0 * M_PI + lineEdit_incrRotateA->text().toDouble() / 180.0 * M_PI;
	euler_angle[1] = output_b->toPlainText().toDouble() / 180.0 * M_PI + lineEdit_incrRotateB->text().toDouble() / 180.0 * M_PI;
	euler_angle[2] = output_c->toPlainText().toDouble() / 180.0 * M_PI + lineEdit_incrRotateC->text().toDouble() / 180.0 * M_PI;


	KDL::Rotation rotation = KDL::Rotation::RPY(euler_angle[2], euler_angle[1], euler_angle[0]);
	rotation.GetQuaternion(target_pose.orientation.x, target_pose.orientation.y, target_pose.orientation.z, target_pose.orientation.w);

	controller_.planTargetMotion(target_pose);
}
void Interface::addWaypoints() {
	geometry_msgs::Pose target_pose;
	target_pose.position.x = lineEdit_TransX->text().toDouble();
	target_pose.position.y = lineEdit_TransY->text().toDouble();
	target_pose.position.z = lineEdit_TransZ->text().toDouble();

	std::vector<double> euler_angle(3);
	euler_angle[0] = lineEdit_RotateA->text().toDouble() / 180.0 * M_PI;
	euler_angle[1] = lineEdit_RotateB->text().toDouble() / 180.0 * M_PI;
	euler_angle[2] = lineEdit_RotateC->text().toDouble() / 180.0 * M_PI;

	KDL::Rotation rotation = KDL::Rotation::RPY(euler_angle[2], euler_angle[1], euler_angle[0]);
	rotation.GetQuaternion(target_pose.orientation.x, target_pose.orientation.y, target_pose.orientation.z, target_pose.orientation.w);

	controller_.addWaypoints(target_pose);
}
void Interface::rotateAroundAxis() {
	// Axis type
	int axis_type = comboBox_AxisType->currentIndex();
	// Pose target
	geometry_msgs::Pose target_pose;
	// Euler angle
	std::vector<double> euler_angle(3);
	std::vector<double> euler_angle_rotate(3);
	// rotation matrix
	KDL::Rotation rotation;

	target_pose.position.x = output_x->toPlainText().toDouble() / 1000.0;
	target_pose.position.y = output_y->toPlainText().toDouble() / 1000.0;
	target_pose.position.z = output_z->toPlainText().toDouble() / 1000.0;

	/*target_pose.position.x = lineEdit_TransX->text().toDouble();
	target_pose.position.y = lineEdit_TransY->text().toDouble();
	target_pose.position.z = lineEdit_TransZ->text().toDouble();*/

	// position of TCP
	KDL::Vector vector(target_pose.position.x, target_pose.position.y, target_pose.position.z);
	KDL::Vector vector_rotate;

	euler_angle[0] = output_a->toPlainText().toDouble() / 180.0 * M_PI;
	euler_angle[1] = output_b->toPlainText().toDouble() / 180.0 * M_PI;
	euler_angle[2] = output_c->toPlainText().toDouble() / 180.0 * M_PI;

	/*euler_angle[0] = lineEdit_RotateA->text().toDouble() / 180.0 * M_PI;
	euler_angle[1] = lineEdit_RotateB->text().toDouble() / 180.0 * M_PI;
	euler_angle[2] = lineEdit_RotateC->text().toDouble() / 180.0 * M_PI;*/
	// rotate degree
	double rotate_degree = lineEdit_RotateDegree->text().toDouble();

	switch(axis_type) {
	case Interface::X: {
		rotation = KDL::Rotation::RotX(rotate_degree / 180.0 * M_PI) * KDL::Rotation::RPY(euler_angle[2], euler_angle[1], euler_angle[0]);
		vector_rotate = KDL::Rotation::RotX(rotate_degree / 180.0 * M_PI) * vector;
		break;
	}
	case Interface::Y: {
		rotation = KDL::Rotation::RotY(rotate_degree / 180.0 * M_PI) * KDL::Rotation::RPY(euler_angle[2], euler_angle[1], euler_angle[0]);
		vector_rotate = KDL::Rotation::RotY(rotate_degree / 180.0 * M_PI) * vector;
		break;
	}
	case Interface::Z: {
		rotation = KDL::Rotation::RotZ(rotate_degree / 180.0 * M_PI) * KDL::Rotation::RPY(euler_angle[2], euler_angle[1], euler_angle[0]);
		vector_rotate = KDL::Rotation::RotZ(rotate_degree / 180.0 * M_PI) * vector;
		break;
	}
	case Interface::Custom: {
		// custom rotate axis
		KDL::Vector rotate_axis(lineEdit_AxisVectorX->text().toDouble(),
				lineEdit_AxisVectorY->text().toDouble(), lineEdit_AxisVectorZ->text().toDouble());
		rotation = KDL::Rotation::Rot(rotate_axis, rotate_degree / 180.0 * M_PI) * KDL::Rotation::RPY(euler_angle[2], euler_angle[1], euler_angle[0]);
		vector_rotate = KDL::Rotation::Rot(rotate_axis, rotate_degree / 180.0 * M_PI) * vector;
		break;
	}
	default: {
		ROS_ERROR("Axis type is wrong");
	}
	}

//	rotation.GetRPY(euler_angle_rotate[2], euler_angle_rotate[1], euler_angle_rotate[0]);
//	ROS_INFO("euler_angle: %f %f %f, euler_angle_rotate: %f %f %f", euler_angle[0] / M_PI * 180.0, euler_angle[1] / M_PI * 180.0, euler_angle[2] / M_PI * 180.0,
//			euler_angle_rotate[0] /M_PI * 180.0, euler_angle_rotate[1] /M_PI * 180.0, euler_angle_rotate[2] /M_PI * 180.0);
//	ROS_INFO("vector: %f %f %f, vector_rotate: %f %f %f", vector.data[0], vector.data[1], vector.data[2],
//			vector_rotate.data[0], vector_rotate.data[1], vector_rotate.data[2]);

	//rotation = KDL::Rotation::RPY(euler_angle[2], euler_angle[1], euler_angle[0]);
	rotation.GetQuaternion(target_pose.orientation.x, target_pose.orientation.y, target_pose.orientation.z, target_pose.orientation.w);

	target_pose.position.x = vector_rotate.data[0];
	target_pose.position.y = vector_rotate.data[1];
	target_pose.position.z = vector_rotate.data[2];

	controller_.planTargetMotion(target_pose);

}
void Interface::executeMotionPlan() {

	controller_.executeMotionPlan();
}

void Interface::newFeedbackReceived(Feedback* feedback) {

	Axis feedback_axis;
	feedback_axis = feedback->getAxis();

	joint_state_publish_count_++;
	joint_state_.header.seq = joint_state_publish_count_;
	joint_state_.position[0] = feedback_axis.A1 / 180.0 * M_PI;
	joint_state_.position[1] = feedback_axis.A2 / 180.0 * M_PI;
	joint_state_.position[2] = feedback_axis.A3 / 180.0 * M_PI;
	joint_state_.position[3] = feedback_axis.A4 / 180.0 * M_PI;
	joint_state_.position[4] = feedback_axis.A5 / 180.0 * M_PI;
	joint_state_.position[5] = feedback_axis.A6 / 180.0 * M_PI;
	joint_state_.header.stamp = ros::Time::now();
	joint_state_publisher_.publish(joint_state_);
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
	ros::shutdown();
}

// Callback function
void Interface::trajectoryActionCb(const TrajectoryGoal& feedback) {
	ROS_INFO("Trajectory received.");
	emit sendTrajectory(feedback);
}
void Interface::addWaypointsCb() {
	ROS_INFO("Interface: add way points callback");
	emit addWaypointsSignal();
}
void Interface::visualizeExecutePlanCb() {
	ROS_INFO("Interface: visualize and execute plan callback");
	emit visualizeExecutePlan();
}
void Interface::endEffectorPosCb(
		const InteractiveMarkerFeedbackConstPtr &feedback) {
	lineEdit_TransX->setText(QString("%1").arg(feedback->pose.position.x, 8, 'f', 4));
	lineEdit_TransY->setText(QString("%1").arg(feedback->pose.position.y, 8, 'f', 4));
	lineEdit_TransZ->setText(QString("%1").arg(feedback->pose.position.z, 8, 'f', 4));

	std::vector<double> euler_angle(3);
	KDL::Rotation rotation = KDL::Rotation::Quaternion(feedback->pose.orientation.x, feedback->pose.orientation.y, feedback->pose.orientation.z, feedback->pose.orientation.w);
	rotation.GetRPY(euler_angle[2], euler_angle[1], euler_angle[0]);
	lineEdit_RotateA->setText(QString("%1").arg(euler_angle[0] / M_PI * 180.0, 8, 'f', 4));
	lineEdit_RotateB->setText(QString("%1").arg(euler_angle[1] / M_PI * 180.0, 8, 'f', 4));
	lineEdit_RotateC->setText(QString("%1").arg(euler_angle[2] / M_PI * 180.0, 8, 'f', 4));


	Frame temp_frame(feedback->pose.position.x * 1000.0, feedback->pose.position.y * 1000.0, feedback->pose.position.z * 1000.0,
			euler_angle[0] / M_PI * 180.0, euler_angle[1] / M_PI * 180.0, euler_angle[2] / M_PI * 180.0);
	Axis temp_axis;
	controller_.getPlannar()->getModel().Frame2Axis(last_Axis_, temp_frame, temp_axis);
	last_Axis_.set(temp_axis);

	lineEdit_Joint1->setText(QString("%1").arg(temp_axis.A1, 8, 'f', 4));
	lineEdit_Joint2->setText(QString("%1").arg(temp_axis.A2, 8, 'f', 4));
	lineEdit_Joint3->setText(QString("%1").arg(temp_axis.A3, 8, 'f', 4));
	lineEdit_Joint4->setText(QString("%1").arg(temp_axis.A4, 8, 'f', 4));
	lineEdit_Joint5->setText(QString("%1").arg(temp_axis.A5, 8, 'f', 4));
	lineEdit_Joint6->setText(QString("%1").arg(temp_axis.A6, 8, 'f', 4));

	emit endEffectorPos(feedback);
}
void addWaypointsCb_global(const InteractiveMarkerFeedbackConstPtr &feedback) {
	// The Workaround of the MenuHandler insert function problem
	ROS_INFO("Global: add way points");
	kuka_interface->addWaypointsCb();
}
void visualizeExecutePlanCb_global(
		const InteractiveMarkerFeedbackConstPtr &feedback) {
	// The Workaround of the MenuHandler insert function problem
	ROS_INFO("Global: visualize and execute plan");
	kuka_interface->visualizeExecutePlanCb();
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

	menu_entry_.push_back(
			menu_handler_.insert("Add into way points", addWaypointsCb_global));
	menu_entry_.push_back(
			menu_handler_.insert("Visualize and Execute motion plan",
					visualizeExecutePlanCb_global));
}

// Functions for Sing Command Tab
void Interface::on_send_frame_button_clicked() {
	Frame f(input_x->toPlainText().toFloat(), input_y->toPlainText().toFloat(),
			input_z->toPlainText().toFloat(), input_a->toPlainText().toFloat(),
			input_b->toPlainText().toFloat(), input_c->toPlainText().toFloat());
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
	Axis a(input_a1->toPlainText().toFloat(), input_a2->toPlainText().toFloat(),
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
	Frame f(input_x->toPlainText().toFloat(), input_y->toPlainText().toFloat(),
			input_z->toPlainText().toFloat(), input_a->toPlainText().toFloat(),
			input_b->toPlainText().toFloat(), input_c->toPlainText().toFloat());
	Pos p(f, input_s->toPlainText().toInt(), input_t->toPlainText().toInt());

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

void Interface::displayFeedback(Feedback* feedback) {

	joint_state_display_counter_++;
	if(joint_state_display_counter_ >= 100) {
		if (feedback->getSetOK() && feedback->getParsedOK()) {
			Axis feedback_axis;
			Frame feedback_frame;
			feedback_axis = feedback->getAxis();

			last_Axis_.set(feedback_axis);
			// TODO: Trying to solve the ABC orientation problem
			plannar_ptr_->getModel().Axis2Frame(feedback_axis, feedback_frame);

			output_a1->setText(QString("%1").arg(feedback_axis.A1, 8, 'f', 4));
			output_a2->setText(QString("%1").arg(feedback_axis.A2, 8, 'f', 4));
			output_a3->setText(QString("%1").arg(feedback_axis.A3, 8, 'f', 4));
			output_a4->setText(QString("%1").arg(feedback_axis.A4, 8, 'f', 4));
			output_a5->setText(QString("%1").arg(feedback_axis.A5, 8, 'f', 4));
			output_a6->setText(QString("%1").arg(feedback_axis.A6, 8, 'f', 4));

			output_x->setText(QString("%1").arg(feedback_frame.X, 8, 'f', 4));
			output_y->setText(QString("%1").arg(feedback_frame.Y, 8, 'f', 4));
			output_z->setText(QString("%1").arg(feedback_frame.Z, 8, 'f', 4));
			output_a->setText(QString("%1").arg(feedback_frame.A, 8, 'f', 4));
			output_b->setText(QString("%1").arg(feedback_frame.B, 8, 'f', 4));
			output_c->setText(QString("%1").arg(feedback_frame.C, 8, 'f', 4));

			output_s->setText(QString::number(feedback->getPos().S));
			output_t->setText(QString::number(feedback->getPos().T));

			output_buf_front->setText(QString::number(feedback->getBufferFront()));
			output_buf_last->setText(QString::number(feedback->getBufferLast()));

			output_seq->setText(QString::number(feedback->getSeq()));
			output_result->setText(QString::number(feedback->getStamp()));

			if (feedback->getText() != "Timer Feedback")
				output_message->setText(QString::fromStdString(feedback->getText()));

			if (feedback->getBufferExtreme() == Feedback::Full) {
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

			if (feedback->getSuccess() == 0 && feedback->getType() == Feedback::Hybrid) {
				QPalette pr = output_result->palette();
				pr.setColor(QPalette::Base, QColor(170, 0, 0));
				output_result->setPalette(pr);
			} else if (feedback->getType() == Feedback::Hybrid) {
				QPalette pr = output_result->palette();
				pr.setColor(QPalette::Base, QColor(0, 170, 0));
				output_result->setPalette(pr);
			}

			//setAlignment();
		} else {
			output_message->setText("Feedback parsing failed");
			QPalette pm = output_message->palette();
			pm.setColor(QPalette::Base, QColor(170, 0, 0));
			output_message->setPalette(pm);

			//setAlignment();
		}
		joint_state_display_counter_ = 0;
	}

}
void Interface::convertPoseTargettoJointTarget() {
	Frame temp_frame(lineEdit_TransX->text().toDouble() * 1000.0, lineEdit_TransY->text().toDouble() * 1000.0, lineEdit_TransZ->text().toDouble() * 1000.0,
			lineEdit_RotateA->text().toDouble(), lineEdit_RotateB->text().toDouble(), lineEdit_RotateC->text().toDouble());
	Axis temp_axis;

	controller_.getPlannar()->getModel().Frame2Axis(last_Axis_, temp_frame, temp_axis);
	last_Axis_.set(temp_axis);

	lineEdit_Joint1->setText(QString("%1").arg(temp_axis.A1, 8, 'f', 4));
	lineEdit_Joint2->setText(QString("%1").arg(temp_axis.A2, 8, 'f', 4));
	lineEdit_Joint3->setText(QString("%1").arg(temp_axis.A3, 8, 'f', 4));
	lineEdit_Joint4->setText(QString("%1").arg(temp_axis.A4, 8, 'f', 4));
	lineEdit_Joint5->setText(QString("%1").arg(temp_axis.A5, 8, 'f', 4));
	lineEdit_Joint6->setText(QString("%1").arg(temp_axis.A6, 8, 'f', 4));

}

void Interface::on_convert_button_clicked() {
	Frame temp_frame(input_x->toPlainText().toDouble(), input_y->toPlainText().toDouble(), input_z->toPlainText().toDouble(),
			input_a->toPlainText().toDouble(), input_b->toPlainText().toDouble(), input_c->toPlainText().toDouble());
	Axis temp_axis;

	controller_.getPlannar()->getModel().Frame2Axis(last_Axis_, temp_frame, temp_axis);
	last_Axis_.set(temp_axis);

	output_a1->setText(QString("%1").arg(temp_axis.A1, 8, 'f', 4));
	output_a2->setText(QString("%1").arg(temp_axis.A2, 8, 'f', 4));
	output_a3->setText(QString("%1").arg(temp_axis.A3, 8, 'f', 4));
	output_a4->setText(QString("%1").arg(temp_axis.A4, 8, 'f', 4));
	output_a5->setText(QString("%1").arg(temp_axis.A5, 8, 'f', 4));
	output_a6->setText(QString("%1").arg(temp_axis.A6, 8, 'f', 4));
}
void Interface::on_copy_button_clicked() {
// Single Command tab
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
// Path Planning tab
	// this tab the x y z is presented in meter unit
	lineEdit_TransX->setText(QString("%1").arg(output_x->toPlainText().toDouble() / 1000.0, 8, 'f', 4));
	lineEdit_TransY->setText(QString("%1").arg(output_y->toPlainText().toDouble() / 1000.0, 8, 'f', 4));
	lineEdit_TransZ->setText(QString("%1").arg(output_z->toPlainText().toDouble() / 1000.0, 8, 'f', 4));
	lineEdit_RotateA->setText(output_a->toPlainText());
	lineEdit_RotateB->setText(output_b->toPlainText());
	lineEdit_RotateC->setText(output_c->toPlainText());

	lineEdit_Joint1->setText(output_a1->toPlainText());
	lineEdit_Joint2->setText(output_a2->toPlainText());
	lineEdit_Joint3->setText(output_a3->toPlainText());
	lineEdit_Joint4->setText(output_a4->toPlainText());
	lineEdit_Joint5->setText(output_a5->toPlainText());
	lineEdit_Joint6->setText(output_a6->toPlainText());

	ROS_INFO("Copy button clicked");
	//setAlignment();
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
	//setAlignment();
}

void Interface::on_debug_button_clicked() {
	ROS_INFO("Debug button clicked");
	//plannar_ptr_->test();
	rotateAroundAxis();
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

