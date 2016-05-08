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
		dtPlannar_(), dtKukaFeedbackReceiver_() {

	ROS_INFO("Controller Constructing...");

	qRegisterMetaType<InteractiveMarkerFeedbackConstPtr>(
			"InteractiveMarkerFeedbackConstPtr");
	qRegisterMetaType<TrajectoryGoal>("TrajectoryGoal");
	qRegisterMetaType<MotionPlan>("MotionPlan");

	// When object plannar_'s "newFeedback" function is called, its parameter will be passed to Controller's "newFeedback" function 
	// and Controller's "newFeedback" function will be called.
	connect(&dtPlannar_, SIGNAL(newFeedback(Feedback*)), this,
			SLOT(newFeedbackReceived(Feedback*)), Qt::QueuedConnection);
	// This is to notify that the last motion command has been executed
	connect(&dtPlannar_, SIGNAL(shutdownController()), this, SIGNAL(shutdown()),
			Qt::QueuedConnection);
	connect(&dtPlannar_, SIGNAL(newFeedback(Feedback* )), &dtKukaFeedbackReceiver_,
			SLOT(ObtainJointFeedback(Feedback* )), Qt::QueuedConnection);
	connect(&dtPlannar_, SIGNAL(LastCommandComplete()), &dtKukaFeedbackReceiver_,
			SLOT(LastCommandComplete()), Qt::QueuedConnection);
	// Send Trajectory to plannar_ object
	connect(this, SIGNAL(sendTrajectorySignal(const MotionPlan&)), &dtPlannar_,
			SLOT(executeTrajectory(const MotionPlan&)), Qt::QueuedConnection);

	// Settings for MoveGroup
	pdtMoveGroup_ = boost::make_shared<moveit::planning_interface::MoveGroup>(
			group_name);
	pdtMoveGroup_->setPlannerId("LBKPIECEkConfigDefault");
	pdtMoveGroup_->setNumPlanningAttempts(5);
	pdtMoveGroup_->setStartState(*pdtMoveGroup_->getCurrentState());

	// Initialize target pose
	dtTargetPose_.orientation.w = dtTargetPose_.orientation.z = 1.0;
	dtTargetPose_.position.x = dtTargetPose_.position.y =
			dtTargetPose_.position.z = 0.1;
	// Initialize target Affine matrix
	dtTargetAffine_ = Eigen::Translation3d(0.1, 0.1, 0.1)
			* Eigen::Quaterniond(1.0, 0.0, 0.0, 1.0);
	// Initialize target joint values
	mpTargetJoints_["joint1"] = 0.0;
	mpTargetJoints_["joint2"] = 0.0;
	mpTargetJoints_["joint3"] = 0.0;
	mpTargetJoints_["joint4"] = 0.0;
	mpTargetJoints_["joint5"] = 0.0;
	mpTargetJoints_["joint6"] = 0.0;
	// Initialize collision pose
	dtCollisionPose_.orientation.w = 1.0;
	// Initialize collision shape
	dtCollisionShape_.type = dtCollisionShape_.BOX;
	dtCollisionShape_.dimensions.resize(3);
	dtCollisionShape_.dimensions[0] = 0.3;
	dtCollisionShape_.dimensions[1] = 0.3;
	dtCollisionShape_.dimensions[2] = 0.3;
	// Initialize motion execution status
	bPlanSuccess_ = false;
	// Initialize number of way points
	nWaypointCount_ = 0;

	// Assign a new thread to plannar
	dtPlannarThread_ = new QThread;
	dtPlannar_.moveToThread(dtPlannarThread_);
	ROS_INFO("Plannar thread starts...");
	dtPlannarThread_->start();

	dtKukaFeedbackThread_ = new QThread;
	dtKukaFeedbackReceiver_.moveToThread(dtKukaFeedbackThread_);
	ROS_INFO("Kuka feedback receiver thread starts...");
	dtKukaFeedbackThread_->start();

}

Controller::~Controller() {
	std::cout << "Controller Deconstructing..." << std::endl;

	std::cout << "Plannar thread ends..." << std::endl;
	dtPlannarThread_->exit();
	std::cout << "Kuka feedback receiver thread ends..." << std::endl;
	dtKukaFeedbackThread_->exit();
}

void Controller::newFeedbackReceived(Feedback* feedback) {
	emit newFeedback(feedback);
}

// Obtain motion plan based on target pose
bool Controller::planTargetMotion(geometry_msgs::Pose target_pose) {

	pdtMoveGroup_->clearPoseTarget();
	pdtMoveGroup_->setPoseTarget(target_pose);
	pdtMoveGroup_->setStartState(*pdtMoveGroup_->getCurrentState());

	bPlanSuccess_ = pdtMoveGroup_->plan(dtMotionPlan_);
	ROS_INFO("Motion plan %s", bPlanSuccess_ ? "SUCCEEDED" : "FAILED");

	return bPlanSuccess_;
}

bool Controller::planTargetPoseMotion() {

	pdtMoveGroup_->clearPoseTarget();
	pdtMoveGroup_->setPoseTarget(dtTargetPose_);
	pdtMoveGroup_->setStartState(*pdtMoveGroup_->getCurrentState());

	bPlanSuccess_ = pdtMoveGroup_->plan(dtMotionPlan_);
	ROS_INFO("Motion plan %s", bPlanSuccess_ ? "SUCCEEDED" : "FAILED");

	return bPlanSuccess_;
}

// Obtain motion plan based on target joint values
bool Controller::planTargetMotion(std::map<std::string, double> target_joints) {

	pdtMoveGroup_->clearPoseTarget();
	pdtMoveGroup_->setJointValueTarget(target_joints);
	pdtMoveGroup_->setStartState(*pdtMoveGroup_->getCurrentState());

	bPlanSuccess_ = pdtMoveGroup_->plan(dtMotionPlan_);
	ROS_INFO("Motion plan %s", bPlanSuccess_ ? "SUCCEEDED" : "FAILED");

	return bPlanSuccess_;
}
bool Controller::planTargetJointsMotion() {

	pdtMoveGroup_->clearPoseTarget();
	pdtMoveGroup_->setJointValueTarget(mpTargetJoints_);

	bPlanSuccess_ = pdtMoveGroup_->plan(dtMotionPlan_);
	ROS_INFO("Motion plan %s", bPlanSuccess_ ? "SUCCEEDED" : "FAILED");

	return bPlanSuccess_;
}
// Obtain motion plan based on target Affine matrix
bool Controller::planTargetMotion(Eigen::Affine3d target_affine) {

	pdtMoveGroup_->clearPoseTarget();
	pdtMoveGroup_->setPoseTarget(target_affine);
	pdtMoveGroup_->setStartState(*pdtMoveGroup_->getCurrentState());

	bPlanSuccess_ = pdtMoveGroup_->plan(dtMotionPlan_);
	ROS_INFO("Motion plan %s", bPlanSuccess_ ? "SUCCEEDED" : "FAILED");

	return bPlanSuccess_;
}
bool Controller::planTargetAffineMotion() {

	pdtMoveGroup_->clearPoseTarget();
	pdtMoveGroup_->setPoseTarget(dtTargetAffine_);
	pdtMoveGroup_->setStartState(*pdtMoveGroup_->getCurrentState());

	bPlanSuccess_ = pdtMoveGroup_->plan(dtMotionPlan_);
	ROS_INFO("Motion plan %s", bPlanSuccess_ ? "SUCCEEDED" : "FAILED");

	return bPlanSuccess_;
}

// Execute motion plan
bool Controller::executeMotionPlan(
		moveit::planning_interface::MoveGroup::Plan motion_plan) {
#ifdef KUKA_SIM
	dtMotionStatus_ = pdtMoveGroup_->execute(motion_plan);
	if (dtMotionStatus_.val != moveit_msgs::MoveItErrorCodes::SUCCESS) {
		ROS_INFO("Motion execution failed");
		return false;
	} else {
		ROS_INFO("Motion execution succeeded");
		return true;
	}
#else
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.lockForWrite();
	dtKukaFeedbackReceiver_.bLastCommandComplete_ = false;
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.unlock();

	emit sendTrajectorySignal((const MotionPlan) motion_plan);

	while (!dtKukaFeedbackReceiver_.bLastCommandComplete_) {

	}
	ROS_INFO("Motion plan executed successfully");
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.lockForWrite();
	dtKukaFeedbackReceiver_.bLastCommandComplete_ = false;
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.unlock();
	return true;
#endif

}
bool Controller::executeMotionPlan() {
#ifdef KUKA_SIM
	dtMotionStatus_ = pdtMoveGroup_->execute(dtMotionPlan_);
	if (dtMotionStatus_.val != moveit_msgs::MoveItErrorCodes::SUCCESS) {
		ROS_INFO("Motion execution failed");
		return false;
	} else {
		ROS_INFO("Motion execution succeeded");
		return true;
	}
#else
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.lockForWrite();
	dtKukaFeedbackReceiver_.bLastCommandComplete_ = false;
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.unlock();

	emit sendTrajectorySignal((const MotionPlan) dtMotionPlan_);

	while (!dtKukaFeedbackReceiver_.bLastCommandComplete_) {

	}
	ROS_INFO("Motion plan executed successfully");
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.lockForWrite();
	dtKukaFeedbackReceiver_.bLastCommandComplete_ = false;
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.unlock();
	return true;
#endif

}
// Async execute motion plan
bool Controller::asyncExecuteMotionPlan(
		moveit::planning_interface::MoveGroup::Plan motion_plan) {
#ifdef KUKA_SIM
	dtMotionStatus_ = pdtMoveGroup_->asyncExecute(motion_plan);
	if (dtMotionStatus_.val != moveit_msgs::MoveItErrorCodes::SUCCESS) {
		ROS_INFO("Async motion execution failed");
		return false;
	} else {
		ROS_INFO("Async motion execution succeeded");
		return true;
	}
#else
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.lockForWrite();
	dtKukaFeedbackReceiver_.bLastCommandComplete_ = false;
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.unlock();

	emit sendTrajectorySignal((const MotionPlan) motion_plan);
	while (!dtKukaFeedbackReceiver_.bLastCommandComplete_) {

	}
	ROS_INFO("Motion plan executed successfully");
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.lockForWrite();
	dtKukaFeedbackReceiver_.bLastCommandComplete_ = false;
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.unlock();
	return true;
#endif
}
bool Controller::asyncExecuteMotionPlan() {
#ifdef KUKA_SIM
	dtMotionStatus_ = pdtMoveGroup_->asyncExecute(dtMotionPlan_);
	if (dtMotionStatus_.val != moveit_msgs::MoveItErrorCodes::SUCCESS) {
		ROS_INFO("Async motion execution failed");
		return false;
	} else {
		ROS_INFO("Async motion execution succeeded");
		return true;
	}
#else
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.lockForWrite();
	dtKukaFeedbackReceiver_.bLastCommandComplete_ = false;
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.unlock();

	emit sendTrajectorySignal((const MotionPlan) dtMotionPlan_);
	while (!dtKukaFeedbackReceiver_.bLastCommandComplete_) {

	}
	ROS_INFO("Motion plan executed successfully");
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.lockForWrite();
	dtKukaFeedbackReceiver_.bLastCommandComplete_ = false;
	dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.unlock();
	return true;
#endif
}
void Controller::visualizeMotionPlan() {
	emit visualizeMotionPlan(dtMotionPlan_);
}

void Controller::stopMotion() {
#ifdef KUKA_SIM
	pdtMoveGroup_->stop();
#else
	//TODO:
#endif
}
void Controller::addWaypoints(geometry_msgs::Pose waypoint_pose) {
	ROS_INFO("Controller: add %d th way point", ++nWaypointCount_);
	//ROS_INFO("Controller: Thread %d", QThread::currentThreadId());
	vecdtWaypoints_.push_back(waypoint_pose);
}
void Controller::addWaypointsCb() {
	ROS_INFO("Controller: add %d th way point", ++nWaypointCount_);
	geometry_msgs::Pose temp_pos = dtEndEffectorPos_;
	vecdtWaypoints_.push_back(temp_pos);
}
void Controller::endEffectorPosCb(
		const visualization_msgs::InteractiveMarkerFeedbackConstPtr &feedback) {
	if (feedback->mouse_point_valid) {
		dtEndEffectorPos_ = feedback->pose;
	}
}
void Controller::visualizeExecutePlanCb() {

	moveit::planning_interface::MoveGroup::Plan temp_plan;

	for (int i = 0; i < vecdtWaypoints_.size(); i++) {

		pdtMoveGroup_->setPoseTarget(vecdtWaypoints_[i], "tip");
		pdtMoveGroup_->setStartState(*pdtMoveGroup_->getCurrentState());

		bool success = pdtMoveGroup_->plan(temp_plan);
		ROS_INFO("Controller: visualizing plan (pose goal) %s",
				success ? "" : "FAILED");
		if (success) {
#ifdef KUKA_SIM
			pdtMoveGroup_->execute(temp_plan);
#else
			dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.lockForWrite();
			dtKukaFeedbackReceiver_.bLastCommandComplete_ = false;
			dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.unlock();

			emit sendTrajectorySignal((const MotionPlan) temp_plan);
			while (!dtKukaFeedbackReceiver_.bLastCommandComplete_) {

			}
			ROS_INFO("Motion plan executed successfully");
			dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.lockForWrite();
			dtKukaFeedbackReceiver_.bLastCommandComplete_ = false;
			dtKukaFeedbackReceiver_.dtLastCommandCompleteLock_.unlock();
#endif
		} else {
			// This one ensures that no unreachable motion command will be sent to Kuka,
			// so no need to do reachable check in plannar_ object
			ROS_ERROR(
					"Controller: error while planning position of arm, no move command was sent!\n");
		}
	}

	vecdtWaypoints_.clear();
	nWaypointCount_ = 0;

}

// Add collision object to be added to wait list
void Controller::addCollisionObject(std::string collision_id,
		shape_msgs::SolidPrimitive collision_shape,
		geometry_msgs::Pose collision_pose) {

	dtCollisionObject_.header.frame_id = pdtMoveGroup_->getPlanningFrame();

	/* The id of the object is used to identify it. */
	dtCollisionObject_.id = collision_id;

	dtCollisionObject_.primitives.push_back(collision_shape);
	dtCollisionObject_.primitive_poses.push_back(collision_pose);
	dtCollisionObject_.operation = moveit_msgs::CollisionObject::ADD;

	vecdtCollisionObjects_.push_back(dtCollisionObject_);

}
void Controller::addCollisionObject(std::string collision_id) {

	dtCollisionObject_.header.frame_id = pdtMoveGroup_->getPlanningFrame();

	/* The id of the object is used to identify it. */
	dtCollisionObject_.id = collision_id;

	dtCollisionObject_.primitives.push_back(dtCollisionShape_);
	dtCollisionObject_.primitive_poses.push_back(dtCollisionPose_);
	dtCollisionObject_.operation = moveit_msgs::CollisionObject::ADD;

	vecdtCollisionObjects_.push_back(dtCollisionObject_);

}
// Add collision object to be removed to wait list
void Controller::removeCollisionObject(std::string collision_id) {

	vecstrRemoveCollisionIds_.push_back(collision_id);
}
// Update work cell
void Controller::updateWorkcell() {

	ROS_INFO("Add collision objects into the world");
	dtPlanningSceneInterface_.addCollisionObjects(vecdtCollisionObjects_);
	dtPlanningSceneInterface_.removeCollisionObjects(vecstrRemoveCollisionIds_);

	// Clear the contents of collision_objects_ and remove_collision_ids
	vecdtCollisionObjects_.clear();
	vecstrRemoveCollisionIds_.clear();
}

Plannar* Controller::getPlannar() {
	return &dtPlannar_;
}
boost::shared_ptr<moveit::planning_interface::MoveGroup> Controller::getMoveGroup() {
	return pdtMoveGroup_;
}

moveit::planning_interface::MoveGroup::Plan& Controller::getMotionPlan() {
	return dtMotionPlan_;
}

geometry_msgs::Pose& Controller::getTargetPose() {
	return dtTargetPose_;
}

std::map<std::string, double>& Controller::getTargetJoints() {
	return mpTargetJoints_;
}

Eigen::Affine3d& Controller::getTargetAffine() {
	return dtTargetAffine_;
}
geometry_msgs::Pose& Controller::getEndEffectorPos() {
	return dtEndEffectorPos_;
}

Axis Controller::getFeedbackAxis() {
	Axis feedback_axis;
	dtKukaFeedbackReceiver_.dtFeedbackLock_.lockForRead();
	feedback_axis = dtKukaFeedbackReceiver_.dtJointFeedback_.getAxis();
	dtKukaFeedbackReceiver_.dtFeedbackLock_.unlock();
	return feedback_axis;
}

void Controller::setMotionPlan(
		moveit::planning_interface::MoveGroup::Plan motion_plan) {
	dtMotionPlan_ = motion_plan;
}

void Controller::setTargetPose(geometry_msgs::Pose target_pose) {
	dtTargetPose_ = target_pose;
}

void Controller::setTargetJoints(std::map<std::string, double> target_joints) {
	mpTargetJoints_ = target_joints;
}

void Controller::setTargetAffine(Eigen::Affine3d target_affine) {
	dtTargetAffine_ = target_affine;
}

