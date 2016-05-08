/**
 *   Copyright (C) Tsinghua University 2016
 *
 *   Version   : 2.0
 *   Date      : 2016
 *   Author    : Xingtong Liu
 *   Company   : Tsinghua University
 *   Email     : 327586708@qq.com
 */

#ifndef KRC_CONTROLLER
#define KRC_CONTROLLER

#include "plannar.h"
#include "KukaFeedback.h"

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

// get function
	boost::shared_ptr<moveit::planning_interface::MoveGroup> getMoveGroup();
	moveit::planning_interface::MoveGroup::Plan& getMotionPlan();
	std::map<std::string, double>& getTargetJoints();
	geometry_msgs::Pose& getEndEffectorPos();
	geometry_msgs::Pose& getTargetPose();
	Eigen::Affine3d& getTargetAffine();
	Plannar* getPlannar();
	Axis getFeedbackAxis();
// set function
	void setMotionPlan(moveit::planning_interface::MoveGroup::Plan motion_plan);
	void setTargetPose(geometry_msgs::Pose target_pose);
	void setTargetJoints(std::map<std::string, double> target_joints);
	void setTargetAffine(Eigen::Affine3d target_affine);

// Motion planning related function
	void addWaypoints(geometry_msgs::Pose waypoint_pose);
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
	void endEffectorPosCb(const InteractiveMarkerFeedbackConstPtr &feedback);
	void newFeedbackReceived(Feedback* feedback);
	// Send trajectory to plannar object
	//void sendTrajectory(const TrajectoryGoal& feedback);
signals:
	// Shut down
	void shutdown();
	// joint state feedback
	void newFeedback(Feedback* feedback);
	void visualizeMotionPlan(MotionPlan motion_plan);
	void sendTrajectorySignal(const MotionPlan& motion_plan);

private:
// Motion
	boost::shared_ptr<moveit::planning_interface::MoveGroup> pdtMoveGroup_;
	moveit::planning_interface::PlanningSceneInterface dtPlanningSceneInterface_;
	moveit::planning_interface::MoveGroup::Plan dtMotionPlan_;
	ros::Publisher dtPlanningSceneDiffPublisher_;
	// Target pose for motion
	geometry_msgs::Pose dtTargetPose_;
	std::map<std::string, double> mpTargetJoints_;
	Eigen::Affine3d dtTargetAffine_;
	// Indicator for motion plan
	bool bPlanSuccess_;
	// Indicator for motion execution
	moveit_msgs::MoveItErrorCodes dtMotionStatus_;
	Plannar dtPlannar_;
	// Way points for motion planning
	std::vector<geometry_msgs::Pose> vecdtWaypoints_;
	// current interactive marker position
	geometry_msgs::Pose dtEndEffectorPos_;
	int nWaypointCount_;

// Add or remove collision object
	geometry_msgs::Pose dtCollisionPose_;
	shape_msgs::SolidPrimitive dtCollisionShape_;
	moveit_msgs::CollisionObject dtCollisionObject_;
	std::vector<std::string> vecstrRemoveCollisionIds_;
	std::vector<moveit_msgs::CollisionObject> vecdtCollisionObjects_;

	QThread *dtPlannarThread_;

	KukaFeedback dtKukaFeedbackReceiver_;
	QThread* dtKukaFeedbackThread_;
};

#endif
