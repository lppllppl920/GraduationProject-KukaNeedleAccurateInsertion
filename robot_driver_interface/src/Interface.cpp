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
	node_handle_ = boost::make_shared<ros::NodeHandle>("");

//-------------------------------Settings----------------------------------------------


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
			SIGNAL(addWaypoints(const InteractiveMarkerFeedbackConstPtr&)),
			&controller_,
			SLOT(addWaypointsCb(const InteractiveMarkerFeedbackConstPtr&)));
	connect(this,
			SIGNAL(
					visualizeExecutePlan(const InteractiveMarkerFeedbackConstPtr&)),
			&controller_,
			SLOT(
					visualizeExecutePlanCb(const InteractiveMarkerFeedbackConstPtr&)));
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
			"/joint_trajectory_action/goal", 10,
			&Interface::trajectoryActionCallback, this);

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
	ROS_INFO("Callback queue set up");
}

Interface::~Interface() {
	ROS_INFO("Interface Deconstructing...");
}

void Interface::spin() {
	callback_queue_.callAvailable(ros::WallDuration());
}

void Interface::shutdown() {
	QApplication::exit();
	//spinner_->stop();
	ros::shutdown();
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
}

void Interface::trajectoryActionCallback(
		const control_msgs::FollowJointTrajectoryActionGoalConstPtr& feedback) {
	ROS_INFO("Trajectory received.");
	emit sendTrajectory(feedback);
}

// Visualize motion plan
void Interface::visualizeMotionPlan(
		moveit::planning_interface::MoveGroup::Plan motion_plan) {

	ROS_INFO("Visualizing plan");

	display_trajectory_.trajectory_start = motion_plan.start_state_;
	display_trajectory_.trajectory.push_back(motion_plan.trajectory_);

	display_publisher_.publish(display_trajectory_);
}

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

	// Nice try!
	/*boost::function<
	void(const interactive_markers::MenuHandler::FeedbackConstPtr&)> f1 = boost::function<
			void(const interactive_markers::MenuHandler::FeedbackConstPtr&)>(this->addWaypointsCb); */

	menu_entry_.push_back(menu_handler_.insert("Add into way points", addWaypointsCb_global));

	/* boost::function<
	void(const interactive_markers::MenuHandler::FeedbackConstPtr&)> f2 = boost::function<
			void(const interactive_markers::MenuHandler::FeedbackConstPtr&)>(this->addWaypointsCb); */

	menu_entry_.push_back(menu_handler_.insert("Visualize and Execute motion plan", visualizeExecutePlanCb_global));
}

void Interface::addWaypointsCb(
		const InteractiveMarkerFeedbackConstPtr &feedback) {
	ROS_INFO("Interface: add way points callback");
	emit addWaypoints(feedback);
}
void Interface::visualizeExecutePlanCb(
		const InteractiveMarkerFeedbackConstPtr &feedback) {
	ROS_INFO("Interface: visualize and execute plan callback");
	emit visualizeExecutePlan(feedback);
}
void Interface::endEffectorPosCb(
		const InteractiveMarkerFeedbackConstPtr &feedback) {
	ROS_INFO("Interface: Interactive Marker position received");
	emit endEffectorPos(feedback);
}
void addWaypointsCb_global(const InteractiveMarkerFeedbackConstPtr &feedback) {
	// The Workaround of the MenuHandler insert function problem
	ROS_INFO("Global: add way points");
	kuka_interface->addWaypointsCb(feedback);
}

void visualizeExecutePlanCb_global(const InteractiveMarkerFeedbackConstPtr &feedback) {
	// The Workaround of the MenuHandler insert function problem
	ROS_INFO("Global: visualize and execute plan");
	kuka_interface->visualizeExecutePlanCb(feedback);
}

