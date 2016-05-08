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
#include "MotionPlanDecision.h"
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
	void calculateRotationMatrix();
	void calibrateNeedle();
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
	void clearTransformData();
	void optionsProgramoptions_OK();
	void settingsComPortSettings_OK();
	void optionsIlluminatorfiringrate_OK();

signals:
// Send trajectory to controller object
	void addWaypointsSignal();
	void visualizeExecutePlan();
	void endEffectorPos(const InteractiveMarkerFeedbackConstPtr &feedback);

private:
	boost::shared_ptr<ros::NodeHandle> pdtNodeHandle_;

// Subscriber for motion trajectory
	//ros::Subscriber dtMotionTrajectorySubsriber_;

// Display trajectory
	ros::Publisher dtDisplayPublisher_;
	moveit_msgs::DisplayTrajectory dtDisplayTrajectory_;

// Joints state publisher and subscriber
	ros::Publisher dtJointStatePublisher_;
	sensor_msgs::JointState dtJointState_;
	int nJointStatePublishCount_;

// Interactive Marker related
	ros::Subscriber dtInteractiveMarkerSubsriber_;
	interactive_markers::MenuHandler dtMenuHandler_;
	std::vector<interactive_markers::MenuHandler::EntryHandle> vecdtMenuEntry_;
	boost::shared_ptr<interactive_markers::InteractiveMarkerServer> pdtInteractiveMarkerServer_;
	float marker_pos_;

// Pointer to Plannar object
	boost::shared_ptr<Plannar> pdtPlannar_;

// Publisher for planning scene
	ros::Publisher dtPlanningSceneDiffPublisher_;
	int nCollisionOperationCount_;

// counter for displaying robot state
	int nJointStateDisplayCount_;
	int nJointStateCallbackCount_;

// latest joint state
	Axis dtLastAxis_;
// enum for rotating around a specific axis
	enum {
		X = 0, Y = 1, Z = 2, Custom = 3
	};

// NDI related

	boost::shared_ptr<CommandHandling> pdtCommandHandling_; /* point to the command handling class */

	std::string strFrameNumber_;
	std::string strSystemMode_;
	std::string strManufID_;
	std::string strSerialNo_;
	std::string strToolRev_;
	std::string strToolType_;
	std::string strPartNumber_;

	bool bInterference_;
	bool bUse0x0800Option_;
	bool bUseEulerAngles_;
	bool bPortEnabled_;
	bool bPortInitialized_;
	bool bResetHardware_; /* reset hardware variable */
	bool bWireless_; /* uses the wireless compatible settings */
	bool bSystemInitialized_; /* is the system initialized */
	bool bPortsActivated_; /* are ports activated */
	int nCOMPort_; /* the current com port number */
	int nTrackingMode_;

	bool bStopTracking_; /* flag that tells the thread to stop tracking */
	bool bIsTracking_; /* flag that specifies if we are tracking */

	COMPortSettings dtSubWindowCOMPortSettings_;
	NewAlertFlagsDlg dtSubWindowNewAlertFlags_;
	SystemFeaturesDlg dtSubWindowSystemFeatures_;
	ProgramOptions dtSubWindowProgramOptions_;
	IlluminatorFiringRate dtSubWindowIlluminatorFiringRate_;
	ROMFileDlg dtSubWindowROMFile_;
	MotionPlanDecision dtSubWindowMotionPlanDecision_;

	QTimer *dtGetDataTimer_;

	KDL::Rotation dtNDIKUKARotationMatrix_;
	bool bMotionComplete_;

	Controller dtController_;
	QThread* dtControllerThread_;

	Frame dtFrameFeedback_;

};

void addWaypointsCb_global(const InteractiveMarkerFeedbackConstPtr &feedback);
void visualizeExecutePlanCb_global(
		const InteractiveMarkerFeedbackConstPtr &feedback);
extern boost::shared_ptr<Interface> kuka_interface;

#endif /* ROBOT_DRIVER_INTERFACE_SRC_INTERFACE_H_ */
