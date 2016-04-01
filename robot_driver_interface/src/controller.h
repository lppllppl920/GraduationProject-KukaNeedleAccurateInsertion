/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 25 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#ifndef KRC_CONTROLLER
#define KRC_CONTROLLER

#include "plannar.h"

using namespace visualization_msgs;
using namespace interactive_markers;

class Controller: public QObject {
	Q_OBJECT
public:

	typedef control_msgs::FollowJointTrajectoryActionGoalConstPtr TrajectoryGoal;
	typedef moveit::planning_interface::MoveGroup::Plan MotionPlan;
	typedef std::vector<descartes_core::TrajectoryPtPtr> TrajectoryVec;
	typedef TrajectoryVec::const_iterator TrajectoryIter;

	Controller(std::string group_name = "manipulator");
	~Controller();
	// ROS node "KRC4_joint_state_publisher" initialization
	void addPublisher();
	// Called when new trajectory is computed
	//void trajectoryActionCallback(
		//	const control_msgs::FollowJointTrajectoryActionGoalConstPtr& feedback);

// get function
	boost::shared_ptr<moveit::planning_interface::MoveGroup> getMoveGroup();
	moveit::planning_interface::MoveGroup::Plan& getMotionPlan();
	geometry_msgs::Pose& getTargetPose();
	Eigen::Affine3d& getTargetAffine();
	std::map<std::string, double>& getTargetJoints();
	Plannar* getPlannar();

// set function
	void setMotionPlan(moveit::planning_interface::MoveGroup::Plan motion_plan);
	void setTargetPose(geometry_msgs::Pose target_pose);
	void setTargetJoints(std::map<std::string, double> target_joints);
	void setTargetAffine(Eigen::Affine3d target_affine);

// Motion planning related function
	bool planTargetMotion(geometry_msgs::Pose target_pose);
	bool planTargetMotion(std::map<std::string, double> target_joints);
	bool planTargetMotion(Eigen::Affine3d target_affine);
	bool executeMotionPlan(
			moveit::planning_interface::MoveGroup::Plan motion_plan);
	bool asyncExecuteMotionPlan(
			moveit::planning_interface::MoveGroup::Plan motion_plan);
	bool planTargetJointsMotion();
	bool planTargetPoseMotion();
	bool planTargetAffineMotion();
	bool executeMotionPlan();
	bool asyncExecuteMotionPlan();
	void visualizeMotionPlan();
	void stopMotion();

// collision object related function
	void addCollisionObject(std::string collision_id);
	void addCollisionObject(std::string collision_id,
			shape_msgs::SolidPrimitive collision_shape,
			geometry_msgs::Pose collision_pose);
	void removeCollisionObject(std::string collision_id);
	void updateWorkcell();

public slots:
	void addWaypointsCb();
	void visualizeExecutePlanCb();
	void endEffectorPosCb(
			const InteractiveMarkerFeedbackConstPtr &feedback);
	void newFeedbackReceived(Feedback* feedback);
	// Send trajectory to plannar object
	void sendTrajectory(
			const TrajectoryGoal& feedback);
signals:
	// Shut down
	void shutdown();
	// joint state feedback
	void newFeedback(Feedback& fb);
	void visualizeMotionPlan(
			MotionPlan motion_plan);
	void sendTrajectorySignal(
			const TrajectoryGoal& feedback);

private:
// Motion
	boost::shared_ptr<moveit::planning_interface::MoveGroup> group_;
	moveit::planning_interface::PlanningSceneInterface planning_scene_interface_;
	moveit::planning_interface::MoveGroup::Plan motion_plan_;
	ros::Publisher planning_scene_diff_publisher_;
	// Target pose for motion
	geometry_msgs::Pose target_pose_;
	std::map<std::string, double> target_joints_;
	Eigen::Affine3d target_affine_;
	// Indicator for motion plan
	bool plan_success_;
	// Indicator for motion execution
	moveit_msgs::MoveItErrorCodes motion_status_;
	Plannar plannar_;
	// Way points for motion planning
	std::vector<geometry_msgs::Pose> waypoints_;
	// current interactive marker position
	geometry_msgs::Pose end_effector_pos_;
	int waypoint_count_;

// Add or remove collision object
	std::vector<std::string> remove_collision_ids_;
	geometry_msgs::Pose collision_pose_;
	shape_msgs::SolidPrimitive collision_shape_;
	moveit_msgs::CollisionObject collision_object_;
	std::vector<moveit_msgs::CollisionObject> collision_objects_;



};

#endif
