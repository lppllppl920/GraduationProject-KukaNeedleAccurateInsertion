/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 25 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#include "controller.h"

Controller::Controller(std::string group_name): plannar_() {

	ROS_INFO("Controller Constructing...");

	qRegisterMetaType<InteractiveMarkerFeedbackConstPtr>("InteractiveMarkerFeedbackConstPtr");
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
	connect(this,
			SIGNAL(
					sendTrajectorySignal(const TrajectoryGoal&) ),
			&plannar_,
			SLOT(
					executeTrajectory(const TrajectoryGoal&)) );

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


}

Controller::~Controller() {
	ROS_INFO("Controller Deconstructing...");
}

void Controller::sendTrajectory(
		const TrajectoryGoal& feedback) {
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

void Controller::addWaypointsCb() {
	ROS_INFO("Controller: add %d th way point", ++waypoint_count_);
	geometry_msgs::Pose temp_pos = end_effector_pos_;
	waypoints_.push_back(temp_pos);
}
void Controller::endEffectorPosCb(
		const visualization_msgs::InteractiveMarkerFeedbackConstPtr &feedback) {

	if(feedback->mouse_point_valid) {
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
		ROS_INFO("Controller: visualizing plan (pose goal) %s", success ? "" : "FAILED");
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

	// 1. Define sequence of points
	/* TrajectoryVec points;
 	  for (unsigned int i = 0; i < waypoints_.size(); ++i)
	  {
		Eigen::Affine3d pose;
		pose = Eigen::Translation3d(waypoints_[i].position.x, waypoints_[i].position.y, waypoints_[i].position.z);
		descartes_core::TrajectoryPtPtr pt = new descartes_core::TrajectoryPt(new descartes_trajectory::AxialSymmetricPt(pose, // Nominal pose
                M_PI/2.0, // Search discretization
				descartes_trajectory::AxialSymmetricPt::Z_AXIS) ); // Free axis
		points.push_back(pt);
	  }

	  /* for (unsigned int i = 0; i < 5; ++i)
	  {
		Eigen::Affine3d pose;
		pose = Eigen::Translation3d(0.0, 0.04 * i, 0.9);
		descartes_core::TrajectoryPtPtr pt = makeTolerancedCartesianPoint(pose);
		points.push_back(pt);
	  } */

	  // 2. Create a robot model and initialize it
	/*  descartes_core::RobotModelPtr model (new descartes_moveit::MoveitStateAdapter);

	  // Name of description on parameter server. Typically just "robot_description".
	  const std::string robot_description = "robot_description";

	  // name of the kinematic group you defined when running MoveitSetupAssistant
	  const std::string group_name = "manipulator";

	  // Name of frame in which you are expressing poses.
	  // Typically "world_frame" or "base_link".
	  const std::string world_frame = "base_link";

	  // tool center point frame (name of link associated with tool)
	  const std::string tcp_frame = "tip";

	  if (!model->initialize(robot_description, group_name, world_frame, tcp_frame))
	  {
		ROS_INFO("Could not initialize robot model");
		return;
	  }

	  // 3. Create a planner and initialize it with our robot model
	  descartes_planner::DensePlanner planner;
	  planner.initialize(model);

	  // 4. Feed the trajectory to the planner
	  if (!planner.planPath(points))
	  {
		ROS_ERROR("Could not solve for a valid path");
		return;
	  }

	  TrajectoryVec result;
	  if (!planner.getPath(result))
	  {
		ROS_ERROR("Could not retrieve path");
		return;
	  }

	  // 5. Translate the result into a type that ROS understands
	  // Get Joint Names
	  std::vector<std::string> names;
	  nh.getParam("controller_joint_names", names);
	  // Generate a ROS joint trajectory with the result path, robot model,
	  // joint names, and a certain time delta between each trajectory point
	  trajectory_msgs::JointTrajectory joint_solution =
	      toROSJointTrajectory(result, *model, names, 1.0);

	  ROS_INFO("Controller: Joint solution found: %d points", joint_solution.points.size()); */

}

/* trajectory_msgs::JointTrajectory
Controller::toROSJointTrajectory(const TrajectoryVec& trajectory,
                     const descartes_core::RobotModel& model,
                     const std::vector<std::string>& joint_names,
                     double time_delay)
{
  // Fill out information about our trajectory
  trajectory_msgs::JointTrajectory result;
  result.header.stamp = ros::Time::now();
  result.header.frame_id = "world_frame";
  result.joint_names = joint_names;

  // For keeping track of time-so-far in the trajectory
  double time_offset = 0.0;
  // Loop through the trajectory
  for (TrajectoryIter it = trajectory.begin(); it != trajectory.end(); ++it)
  {
    // Find nominal joint solution at this point
    std::vector<double> joints;
    it->get()->getNominalJointPose(std::vector<double>(), model, joints);

    // Fill out a ROS trajectory point
    trajectory_msgs::JointTrajectoryPoint pt;
    pt.positions = joints;
    // velocity, acceleration, and effort are given dummy values
    // we'll let the controller figure them out
    pt.velocities.resize(joints.size(), 0.0);
    pt.accelerations.resize(joints.size(), 0.0);
    pt.effort.resize(joints.size(), 0.0);
    // set the time into the trajectory
    pt.time_from_start = ros::Duration(time_offset);
    // increment time
    time_offset += time_delay;

    result.points.push_back(pt);
  }

  return result;
} */

// Get and set functions
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
