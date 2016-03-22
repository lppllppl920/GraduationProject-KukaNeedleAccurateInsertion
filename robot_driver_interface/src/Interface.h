/*
 * Interface.h
 *
 *  Created on: Mar 19, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_INTERFACE_H_
#define ROBOT_DRIVER_INTERFACE_SRC_INTERFACE_H_

#include "controller.h"

using namespace visualization_msgs;
using namespace interactive_markers;

class Interface: public QObject {
	Q_OBJECT
public:

	typedef control_msgs::FollowJointTrajectoryActionGoalConstPtr TrajectoryGoal;
	typedef moveit::planning_interface::MoveGroup::Plan MotionPlan;

	Interface();
	virtual ~Interface();

// interactive marker related function
	Marker makeBox(InteractiveMarker &msg);
	InteractiveMarkerControl& makeBoxControl(InteractiveMarker &msg);
	InteractiveMarker makeEmptyMarker(bool dummyBox);
	void initMenu();
	void makeMenuMarker(std::string name);
	void trajectoryActionCallback(
			const control_msgs::FollowJointTrajectoryActionGoalConstPtr& feedback);
	void addWaypointsCb(const InteractiveMarkerFeedbackConstPtr &feedback);
	void visualizeExecutePlanCb(
			const InteractiveMarkerFeedbackConstPtr &feedback);
	void endEffectorPosCb(
			const InteractiveMarkerFeedbackConstPtr &feedback);
	void spin();

public slots:

	void newFeedbackReceived(Feedback& feedback);
	void shutdown();
	void visualizeMotionPlan(
			MotionPlan motion_plan);

signals:
	// Send trajectory to controller object
	void sendTrajectory(
			const TrajectoryGoal& feedback);
	void addWaypoints(const InteractiveMarkerFeedbackConstPtr &feedback);
	void visualizeExecutePlan(
			const InteractiveMarkerFeedbackConstPtr &feedback);
	void endEffectorPos(
			const InteractiveMarkerFeedbackConstPtr &feedback);

private:
	boost::shared_ptr<ros::NodeHandle> node_handle_;
	boost::shared_ptr<ros::AsyncSpinner> spinner_;

	Controller controller_;

// Subscriber for motion trajectory
	ros::Subscriber motion_trajectory_subsriber_;

// Display trajectory
	ros::Publisher display_publisher_;
	moveit_msgs::DisplayTrajectory display_trajectory_;

// Joints state publisher
	ros::Publisher joint_state_publisher_;
	int joint_state_publish_count_;
	sensor_msgs::JointState joint_state_;

// Interactive Marker related
	ros::Subscriber interactive_marker_subsriber_;
	interactive_markers::MenuHandler menu_handler_;
	std::vector<interactive_markers::MenuHandler::EntryHandle> menu_entry_;
	boost::shared_ptr<interactive_markers::InteractiveMarkerServer> interactive_marker_server_;
	float marker_pos_;

	ros::CallbackQueue callback_queue_;
};

void addWaypointsCb_global(const InteractiveMarkerFeedbackConstPtr &feedback);
void visualizeExecutePlanCb_global(const InteractiveMarkerFeedbackConstPtr &feedback);
extern  boost::shared_ptr<Interface> kuka_interface;

#endif /* ROBOT_DRIVER_INTERFACE_SRC_INTERFACE_H_ */
