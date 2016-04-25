/**
 *   Copyright (C) Tsinghua University 2016
 *
 *   Version   : 2.0
 *   Date      : 2016
 *   Author    : Xingtong Liu
 *   Company   : Tsinghua University
 *   Email     : 327586708@qq.com
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_INTERFACE_H_
#define ROBOT_DRIVER_INTERFACE_SRC_INTERFACE_H_


#include <boost/lexical_cast.hpp>
#include <boost/make_shared.hpp>

#include "gui/ui_robotInterface.h"
#include "ndi/CommandHandling.h"
#include "ndi/COMPortSettings.h"
#include "ndi/NewAlertFlagsDlg.h"
#include "ndi/SystemFeaturesDlg.h"
#include "ndi/ProgramOptions.h"
#include "ndi/IlluminatorFiringRate.h"
#include "ndi/ROMFileDlg.h"
#include "ndi/COMPortTimeOut.h"
#include "controller.h"


using namespace visualization_msgs;
using namespace interactive_markers;

class Interface: public QMainWindow, private Ui::MainWindow {
Q_OBJECT
public:
	typedef control_msgs::FollowJointTrajectoryActionGoalConstPtr TrajectoryGoal;
	typedef moveit::planning_interface::MoveGroup::Plan MotionPlan;

	Interface(QMainWindow *parent = 0);
	virtual ~Interface();

// interactive marker related function
	Marker makeBox(InteractiveMarker &msg);
	InteractiveMarkerControl& makeBoxControl(InteractiveMarker &msg);
	InteractiveMarker makeEmptyMarker(bool dummyBox);
	void initMenu();
	void makeMenuMarker(std::string name);
// Callback function
	void trajectoryActionCb(
			const control_msgs::FollowJointTrajectoryActionGoalConstPtr& feedback);
	void addWaypointsCb();
	void visualizeExecutePlanCb();
	void endEffectorPosCb(const InteractiveMarkerFeedbackConstPtr &feedback);

	void setAlignment();
// NDI related
	void setMode(int Mode);
	int activatePorts();
public slots:
	void newFeedbackReceived(Feedback* feedback);
	void shutdown();
	void visualizeMotionPlan(MotionPlan motion_plan);
	void visualizeJointPlan();
	void visualizePosePlan();
	void visualizeIncrPosePlan();
	void executeMotionPlan();
	void addWaypoints();
	void rotateAroundAxis();
	void displayFeedback(Feedback* feedback);
	void manipulateCollisionObject();
	void convertPoseTargettoJointTarget();
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
	void on_convert_button_clicked();
	//NDI related
	void resetNDISystem();
	void initializeNDISystem();
	void activateHandles();
	void trackingButton();
	int startTracking();
	int stopTracking();
	long getSystemTransformData();
	long comPortTimeout();
	void settingsComportsettings();
	void settingsRomfilesettings();
	void systemActivateports();
	void systemInitializesystem();
	void systemStarttracking();
	void systemStoptracking();
	void viewSystemproperties();
	void viewAlertFlags();
	void selchangePortHandles();
	void selchangeRefPortHandle();
	void optionsIlluminatorfiringrate();
	void optionsProgramoptions();
	void portEnabled();
	void reInitializeSystem();

	void optionsProgramoptions_OK();
	void settingsComPortSettings_OK();
	void optionsIlluminatorfiringrate_OK();


signals:
// Send trajectory to controller object
	void sendTrajectory(const TrajectoryGoal& feedback);
	void addWaypointsSignal();
	void visualizeExecutePlan();
	void endEffectorPos(const InteractiveMarkerFeedbackConstPtr &feedback);

private:
	boost::shared_ptr<ros::NodeHandle> node_handle_;

	Controller controller_;

// Subscriber for motion trajectory
	ros::Subscriber motion_trajectory_subsriber_;

// Display trajectory
	ros::Publisher display_publisher_;
	moveit_msgs::DisplayTrajectory display_trajectory_;

// Joints state publisher and subscriber
	ros::Publisher joint_state_publisher_;
	sensor_msgs::JointState joint_state_;
	int joint_state_publish_count_;

// Interactive Marker related
	ros::Subscriber interactive_marker_subsriber_;
	interactive_markers::MenuHandler menu_handler_;
	std::vector<interactive_markers::MenuHandler::EntryHandle> menu_entry_;
	boost::shared_ptr<interactive_markers::InteractiveMarkerServer> interactive_marker_server_;
	float marker_pos_;

// Pointer to Plannar object
	boost::shared_ptr<Plannar> plannar_ptr_;

// Publisher for planning scene
	ros::Publisher planning_scene_diff_publisher_;
	int collision_operation_counter_;

// counter for displaying robot state
	int joint_state_display_counter_;
	int joint_state_callback_counter_;

// latest joint state
	Axis last_Axis_;
// enum for rotating around a specific axis
	enum {
		X = 0, Y = 1, Z = 2, Custom = 3
	};

// NDI related

	boost::shared_ptr<CommandHandling> CommandHandling_; /* point to the command handling class */

	std::string FrameNumber_;
	std::string SystemMode_;
	std::string ManufID_;
	std::string SerialNo_;
	std::string ToolRev_;
	std::string ToolType_;
	std::string PartNumber_;

	bool Interference_;
	bool Use0x0800Option_;
	bool UseEulerAngles_;
	bool PortEnabled_;
	bool PortInitialized_;
	bool ResetHardware_; /* reset hardware variable */
	bool Wireless_; /* uses the wireless compatible settings */
	bool SystemInitialized_; /* is the system initialized */
	bool PortsActivated_; /* are ports activated */
	int COMPort_; /* the current com port number */
	int TrackingMode_;

	bool
		StopTracking_, /* flag that tells the thread to stop tracking */
		IsTracking_;   /* flag that specifies if we are tracking */

	COMPortSettings SubWindow_COMPortSettings_;
	NewAlertFlagsDlg SubWindow_NewAlertFlags_;
	SystemFeaturesDlg SubWindow_SystemFeatures_;
	ProgramOptions SubWindow_ProgramOptions_;
	IlluminatorFiringRate SubWindow_IlluminatorFiringRate_;
	ROMFileDlg SubWindow_ROMFile_;


};

void addWaypointsCb_global(const InteractiveMarkerFeedbackConstPtr &feedback);
void visualizeExecutePlanCb_global(
		const InteractiveMarkerFeedbackConstPtr &feedback);
extern boost::shared_ptr<Interface> kuka_interface;

#endif /* ROBOT_DRIVER_INTERFACE_SRC_INTERFACE_H_ */
