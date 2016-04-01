/**
 *   Copyright (C) Tsinghua University 2016
 *
 *   Version   : 2.0
 *   Date      : 2016
 *   Author    : Xingtong Liu
 *   Company   : Tsinghua University
 *   Email     : 327586708@qq.com
 */

#include "controller.h"

Controller::Controller(std::string group_name) :
		plannar_() {

	ROS_INFO("Controller Constructing...");

	qRegisterMetaType<InteractiveMarkerFeedbackConstPtr>(
			"InteractiveMarkerFeedbackConstPtr");
	qRegisterMetaType<TrajectoryGoal>("TrajectoryGoal");
	qRegisterMetaType<MotionPlan>("MotionPlan");
	//qRegisterMetaType<Feedback>("Feedback");

	// When object plannar_'s "newFeedback" function is called, its parameter will be passed to Controller's "newFeedback" function 
	// and Controller's "newFeedback" function will be called.
	connect(&plannar_, SIGNAL(newFeedback(Feedback*)), this,
			SLOT(newFeedbackReceived(Feedback*)), Qt::DirectConnection);
	// The same with shutdownController() and shutdown().
	connect(&plannar_, SIGNAL(shutdownController()), this, SIGNAL(shutdown()));
	// Send Trajectory to plannar_ object
	connect(this, SIGNAL(sendTrajectorySignal(const TrajectoryGoal&)),
			&plannar_, SLOT(executeTrajectory(const TrajectoryGoal&)));

	// Settings for MoveGroup
	group_ = boost::make_shared<moveit::planning_interface::MoveGroup>(
			group_name);
	group_->setPlannerId("LBKPIECEkConfigDefault");
	group_->setNumPlanningAttempts(5);
	group_->setStartState(*group_->getCurrentState());

	// Initialize target pose
	target_pose_.orientation.w = target_pose_.orientation.z = 1.0;
	target_pose_.position.x = target_pose_.position.y =
			target_pose_.position.z = 0.1;
	// Initialize target Affine matrix
	target_affine_ = Eigen::Translation3d(0.1, 0.1, 0.1)
			* Eigen::Quaterniond(1.0, 0.0, 0.0, 1.0);
	// Initialize target joint values
	target_joints_["joint1"] = 0.0;
	target_joints_["joint2"] = 0.0;
	target_joints_["joint3"] = 0.0;
	target_joints_["joint4"] = 0.0;
	target_joints_["joint5"] = 0.0;
	target_joints_["joint6"] = 0.0;
	// Initialize collision pose
	collision_pose_.orientation.w = 1.0;
	// Initialize collision shape
	collision_shape_.type = collision_shape_.BOX;
	collision_shape_.dimensions.resize(3);
	collision_shape_.dimensions[0] = 0.3;
	collision_shape_.dimensions[1] = 0.3;
	collision_shape_.dimensions[2] = 0.3;
	// Initialize motion execution status
	plan_success_ = false;
	// Initialize number of way points
	waypoint_count_ = 0;

	// Publisher for planning scene
	//planning_scene_diff_publisher_ = node_handle.advertise<moveit_msgs::PlanningScene>("planning_scene", 1);

}

Controller::~Controller() {
	ROS_INFO("Controller Deconstructing...");
}

void Controller::sendTrajectory(const TrajectoryGoal& feedback) {
	ROS_INFO("Controller: motion plan received.");
	emit sendTrajectorySignal(feedback);
}

void Controller::newFeedbackReceived(Feedback* feedback) {
	emit newFeedback(*feedback);
}

// Obtain motion plan based on target pose
bool Controller::planTargetMotion(geometry_msgs::Pose target_pose) {

	group_->clearPoseTarget();
	group_->setPoseTarget(target_pose);
	group_->setStartState(*group_->getCurrentState());

	plan_success_ = group_->plan(motion_plan_);
	ROS_INFO("Motion plan %s", plan_success_ ? "SUCCEEDED" : "FAILED");

	return plan_success_;
}
bool Controller::planTargetPoseMotion() {

	group_->clearPoseTarget();
	group_->setPoseTarget(target_pose_);
	group_->setStartState(*group_->getCurrentState());

	plan_success_ = group_->plan(motion_plan_);
	ROS_INFO("Motion plan %s", plan_success_ ? "SUCCEEDED" : "FAILED");

	return plan_success_;
}

// Obtain motion plan based on target joint values
bool Controller::planTargetMotion(std::map<std::string, double> target_joints) {

	group_->clearPoseTarget();
	group_->setJointValueTarget(target_joints);
	group_->setStartState(*group_->getCurrentState());

	plan_success_ = group_->plan(motion_plan_);
	ROS_INFO("Motion plan %s", plan_success_ ? "SUCCEEDED" : "FAILED");

	return plan_success_;
}
bool Controller::planTargetJointsMotion() {

	group_->clearPoseTarget();
	group_->setJointValueTarget(target_joints_);

	plan_success_ = group_->plan(motion_plan_);
	ROS_INFO("Motion plan %s", plan_success_ ? "SUCCEEDED" : "FAILED");

	return plan_success_;
}
// Obtain motion plan based on target Affine matrix
bool Controller::planTargetMotion(Eigen::Affine3d target_affine) {

	group_->clearPoseTarget();
	group_->setPoseTarget(target_affine);
	group_->setStartState(*group_->getCurrentState());

	plan_success_ = group_->plan(motion_plan_);
	ROS_INFO("Motion plan %s", plan_success_ ? "SUCCEEDED" : "FAILED");

	return plan_success_;
}
bool Controller::planTargetAffineMotion() {

	group_->clearPoseTarget();
	group_->setPoseTarget(target_affine_);
	group_->setStartState(*group_->getCurrentState());

	plan_success_ = group_->plan(motion_plan_);
	ROS_INFO("Motion plan %s", plan_success_ ? "SUCCEEDED" : "FAILED");

	return plan_success_;
}

// Execute motion plan
bool Controller::executeMotionPlan(
		moveit::planning_interface::MoveGroup::Plan motion_plan) {

	motion_status_ = group_->execute(motion_plan);
	if (motion_status_.val != moveit_msgs::MoveItErrorCodes::SUCCESS) {
		ROS_INFO("Motion execution failed");
		return false;
	} else {
		ROS_INFO("Motion execution succeeded");
		return true;
	}

}
bool Controller::executeMotionPlan() {

	motion_status_ = group_->execute(motion_plan_);
	if (motion_status_.val != moveit_msgs::MoveItErrorCodes::SUCCESS) {
		ROS_INFO("Motion execution failed");
		return false;
	} else {
		ROS_INFO("Motion execution succeeded");
		return true;
	}

}
// Async execute motion plan
bool Controller::asyncExecuteMotionPlan(
		moveit::planning_interface::MoveGroup::Plan motion_plan) {

	motion_status_ = group_->asyncExecute(motion_plan);
	if (motion_status_.val != moveit_msgs::MoveItErrorCodes::SUCCESS) {
		ROS_INFO("Async motion execution failed");
		return false;
	} else {
		ROS_INFO("Async motion execution succeeded");
		return true;
	}

}
bool Controller::asyncExecuteMotionPlan() {

	motion_status_ = group_->asyncExecute(motion_plan_);
	if (motion_status_.val != moveit_msgs::MoveItErrorCodes::SUCCESS) {
		ROS_INFO("Async motion execution failed");
		return false;
	} else {
		ROS_INFO("Async motion execution succeeded");
		return true;
	}

}
void Controller::visualizeMotionPlan() {
	emit visualizeMotionPlan(motion_plan_);
}

void Controller::stopMotion() {
	group_->stop();
}

void Controller::addWaypointsCb() {
	ROS_INFO("Controller: add %d th way point", ++waypoint_count_);
	geometry_msgs::Pose temp_pos = end_effector_pos_;
	waypoints_.push_back(temp_pos);
}
void Controller::endEffectorPosCb(
		const visualization_msgs::InteractiveMarkerFeedbackConstPtr &feedback) {

	if (feedback->mouse_point_valid) {
		end_effector_pos_ = feedback->pose;
	} else {
		ROS_INFO("end effector invalid");
	}

}
void Controller::visualizeExecutePlanCb() {

	moveit::planning_interface::MoveGroup::Plan temp_plan;

	for (int i = 0; i < waypoints_.size(); i++) {

		group_->setPoseTarget(waypoints_[i], "tip");
		group_->setStartState(*group_->getCurrentState());

		bool success = group_->plan(temp_plan);
		ROS_INFO("Controller: visualizing plan (pose goal) %s",
				success ? "" : "FAILED");
		// this sleep function could be commented to speed up
		//sleep(5.0);
		if (success) {
			group_->execute(temp_plan);
		} else {
			// This one ensures that no unreachable motion command will be sent to Kuka,
			// so no need to do reachable check in plannar_ object
			ROS_ERROR(
					"Controller: error while planning position of arm, no move command was sent!\n");;
		}
	}

	waypoints_.clear();
	waypoint_count_ = 0;

}

// Add collision object to be added to wait list
void Controller::addCollisionObject(std::string collision_id,
		shape_msgs::SolidPrimitive collision_shape,
		geometry_msgs::Pose collision_pose) {

	collision_object_.header.frame_id = group_->getPlanningFrame();

	/* The id of the object is used to identify it. */
	collision_object_.id = collision_id;

	collision_object_.primitives.push_back(collision_shape);
	collision_object_.primitive_poses.push_back(collision_pose);
	collision_object_.operation = moveit_msgs::CollisionObject::ADD;

	collision_objects_.push_back(collision_object_);

}
void Controller::addCollisionObject(std::string collision_id) {

	collision_object_.header.frame_id = group_->getPlanningFrame();

	/* The id of the object is used to identify it. */
	collision_object_.id = collision_id;

	collision_object_.primitives.push_back(collision_shape_);
	collision_object_.primitive_poses.push_back(collision_pose_);
	collision_object_.operation = moveit_msgs::CollisionObject::ADD;

	collision_objects_.push_back(collision_object_);

}
// Add collision object to be removed to wait list
void Controller::removeCollisionObject(std::string collision_id) {

	remove_collision_ids_.push_back(collision_id);
}
// Update work cell
void Controller::updateWorkcell() {

	ROS_INFO("Add collision objects into the world");
	planning_scene_interface_.addCollisionObjects(collision_objects_);
	planning_scene_interface_.removeCollisionObjects(remove_collision_ids_);

	// Clear the contents of collision_objects_ and remove_collision_ids
	collision_objects_.clear();
	remove_collision_ids_.clear();
}

Plannar* Controller::getPlannar() {
	return &plannar_;
}
boost::shared_ptr<moveit::planning_interface::MoveGroup> Controller::getMoveGroup() {
	return group_;
}

moveit::planning_interface::MoveGroup::Plan& Controller::getMotionPlan() {
	return motion_plan_;
}

geometry_msgs::Pose& Controller::getTargetPose() {
	return target_pose_;
}

std::map<std::string, double>& Controller::getTargetJoints() {
	return target_joints_;
}

Eigen::Affine3d& Controller::getTargetAffine() {
	return target_affine_;
}

void Controller::setMotionPlan(
		moveit::planning_interface::MoveGroup::Plan motion_plan) {
	motion_plan_ = motion_plan;
}

void Controller::setTargetPose(geometry_msgs::Pose target_pose) {
	target_pose_ = target_pose;
}

void Controller::setTargetJoints(std::map<std::string, double> target_joints) {
	target_joints_ = target_joints;
}

void Controller::setTargetAffine(Eigen::Affine3d target_affine) {
	target_affine_ = target_affine;
}
