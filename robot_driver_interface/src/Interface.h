/*
 * Interface.h
 *
 *  Created on: Mar 19, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_INTERFACE_H_
#define ROBOT_DRIVER_INTERFACE_SRC_INTERFACE_H_

#include "controller.h"
#include "gui/ui_robotInterface.h"

using namespace visualization_msgs;
using namespace interactive_markers;

class Interface: public QWidget, private Ui::robotInterface{
	Q_OBJECT
public:
	typedef control_msgs::FollowJointTrajectoryActionGoalConstPtr TrajectoryGoal;
	typedef moveit::planning_interface::MoveGroup::Plan MotionPlan;

	Interface(QWidget *parent = 0);
	virtual ~Interface();

// interactive marker related function
	Marker makeBox(InteractiveMarker &msg);
	InteractiveMarkerControl& makeBoxControl(InteractiveMarker &msg);
	InteractiveMarker makeEmptyMarker(bool dummyBox);
	void initMenu();
	void makeMenuMarker(std::string name);
	void trajectoryActionCb(
			const control_msgs::FollowJointTrajectoryActionGoalConstPtr& feedback);
	void addWaypointsCb();
	void visualizeExecutePlanCb();
	void endEffectorPosCb(
			const InteractiveMarkerFeedbackConstPtr &feedback);
// joint states subscribe function
	void jointStatesCb(const sensor_msgs::JointStateConstPtr &feedback);

	void setAlignment();


public slots:
	void newFeedbackReceived(Feedback& feedback);
	void shutdown();
	void visualizeMotionPlan(
			MotionPlan motion_plan);
	void visualizeJointPlan();
	void visualizePosePlan();
	void executeMotionPlan();
	void copyJointState();
	void displayFeedback(Feedback& fb);
	void manipulateCollisionObject();

signals:
	// Send trajectory to controller object
	void sendTrajectory(
			const TrajectoryGoal& feedback);
	void addWaypoints();
	void visualizeExecutePlan();
	void endEffectorPos(
			const InteractiveMarkerFeedbackConstPtr &feedback);

private slots:
	void on_send_frame_button_clicked();
	void on_send_axis_button_clicked();
	void on_copy_button_clicked();
	void on_default_button_clicked();
	void on_debug_button_clicked();
	void on_send_config_button_clicked();
	void on_pause_buf_buton_clicked();
	void on_terminate_imm_button_clicked();
	void on_send_pos_button_clicked();
	void on_pause_button_clicked();
	void on_stop_button_clicked();
	void on_terminate_buf_button_clicked();

private:
	boost::shared_ptr<ros::NodeHandle> node_handle_;
	boost::shared_ptr<ros::AsyncSpinner> spinner_;

	Controller controller_;

// Subscriber for motion trajectory
	ros::Subscriber motion_trajectory_subsriber_;

// Display trajectory
	ros::Publisher display_publisher_;
	moveit_msgs::DisplayTrajectory display_trajectory_;

// Joints state publisher and subscriber
	ros::Publisher joint_state_publisher_;
	ros::Subscriber joint_state_subscriber_;
	int joint_state_publish_count_;
	sensor_msgs::JointState joint_state_;

// Interactive Marker related
	ros::Subscriber interactive_marker_subsriber_;
	interactive_markers::MenuHandler menu_handler_;
	std::vector<interactive_markers::MenuHandler::EntryHandle> menu_entry_;
	boost::shared_ptr<interactive_markers::InteractiveMarkerServer> interactive_marker_server_;
	float marker_pos_;

// reference of Plannar object
	boost::shared_ptr<Plannar> plannar_ptr_;

// Publisher for planning scene
	ros::Publisher planning_scene_diff_publisher_;
	int collision_operation_counter_;
};

void addWaypointsCb_global(const InteractiveMarkerFeedbackConstPtr &feedback);
void visualizeExecutePlanCb_global(const InteractiveMarkerFeedbackConstPtr &feedback);
extern  boost::shared_ptr<Interface> kuka_interface;

#endif /* ROBOT_DRIVER_INTERFACE_SRC_INTERFACE_H_ */
