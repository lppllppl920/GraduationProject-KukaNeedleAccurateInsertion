/**
 *   Copyright (C) Tsinghua University 2016
 *
 *   Version   : 2.0
 *   Date      : 2016
 *   Author    : Xingtong Liu
 *   Company   : Tsinghua University
 *   Email     : 327586708@qq.com
 */

#include "Interface.h"
Interface::Interface(QMainWindow *parent) :
		dtController_(), dtLastAxis_(0, 0, 0, 0, 0, 0), dtSubWindowCOMPortSettings_(
				this), dtSubWindowIlluminatorFiringRate_(this), dtSubWindowNewAlertFlags_(
				this), dtSubWindowProgramOptions_(this), dtSubWindowROMFile_(
				this), dtSubWindowSystemFeatures_(this) {

	ROS_INFO("Interface Constructing...");

	setupUi(this);
	setAlignment();
//-2.531013 mm, 194.328284 mm, 29.655583 mm

	// GUI related
	// KUKA related
	connect(pushButton_VisualizeJointPlan, SIGNAL(clicked()), this,
			SLOT(visualizeJointPlan()));
	connect(pushButton_VisualizePosePlan, SIGNAL(clicked()), this,
			SLOT(visualizePosePlan()));
	connect(pushButton_ExecutePlan, SIGNAL(clicked()), this,
			SLOT(executeMotionPlan()));
	connect(pushButton_AddWaypoint, SIGNAL(clicked()), this,
			SLOT(addWaypoints()));
	connect(pushButton_ExecuteWaypointsPlan, SIGNAL(clicked()), &dtController_,
			SLOT(visualizeExecutePlanCb()), Qt::QueuedConnection);
	connect(pushButton_Do, SIGNAL(clicked()), this,
			SLOT(manipulateCollisionObject()));
	connect(pushButton_ConvertPosetoJoint, SIGNAL(clicked()), this,
			SLOT(convertPoseTargettoJointTarget()));
	connect(pushButton_VisualizeIncrPosePlan, SIGNAL(clicked()), this,
			SLOT(visualizeIncrPosePlan()));
	connect(pushButton_VisualizeRotatePlan, SIGNAL(clicked()), this,
			SLOT(rotateAroundAxis()));
	connect(pushButton_ExecuteRotatePlan, SIGNAL(clicked()), this,
			SLOT(executeMotionPlan()));
	connect(pushButton_CalculateNDIKUKARotation, SIGNAL(clicked()), this,
			SLOT(calculateRotationMatrix()));
	connect(pushButton_NDIFeedbackParallelMove, SIGNAL(clicked()), this,
			SLOT(ndiFeedbackParallelMove()));
	connect(pushButton_CalculateTCPMarkerTransform, SIGNAL(clicked()), this,
			SLOT(calculateTCPMarkerTransform()));
	connect(pushButton_CalculateNDIKUKATransform, SIGNAL(clicked()), this,
			SLOT(calculateNDIKUKATransform()));
	connect(pushButton_RecordKUKAFeedback, SIGNAL(clicked()), this,
			SLOT(recordKUKAFeedback()));
	connect(pushButton_XYZ4PointCalibrate, SIGNAL(clicked()), this,
			SLOT(XYZ4PointCalibrate()));
	connect(pushButton_AddOrUpdatePosition, SIGNAL(clicked()), this,
			SLOT(AddorUpdatePosition()));
	connect(comboBox_KUKAPosition, SIGNAL(currentIndexChanged(int)), this,
			SLOT(showSelectedKUKAPosition()));
	connect(pushButton_CalculateTCPFlangeRotation, SIGNAL(clicked()), this,
			SLOT(ABC2PointCalibrate()));
	connect(pushButton_NDIFeedbackMove, SIGNAL(clicked()), this,
			SLOT(ndiFeedbackMove()));
	connect(pushButton_CopyCurrentTCPXYZKUKAABC, SIGNAL(clicked()), this,
			SLOT(copyCurrentTCPXYZKUKAABC()));
	connect(pushButton_CopyCurrentTCPState, SIGNAL(clicked()), this,
			SLOT(copyCurrentTCPState()));
	// NDI related
	connect(pushButton_ResetSystem, SIGNAL(clicked()), this,
			SLOT(resetNDISystem()));
	connect(pushButton_InitializeSystem, SIGNAL(clicked()), this,
			SLOT(initializeNDISystem()));
	connect(pushButton_ActiveHandles, SIGNAL(clicked()), this,
			SLOT(activateHandles()));
	connect(pushButton_StartTracking, SIGNAL(clicked()), this,
			SLOT(trackingButton()));

	connect(actionCOM_Port_Settings, SIGNAL(triggered()), this,
			SLOT(settingsComportsettings()));
	connect(&dtSubWindowCOMPortSettings_, SIGNAL(OK_signal()), this,
			SLOT(settingsComPortSettings_OK()));

	connect(actionDiagnostic_Alerts, SIGNAL(triggered()), this,
			SLOT(viewAlertFlags()));
	connect(actionSystem_Properties, SIGNAL(triggered()), this,
			SLOT(viewSystemproperties()));
	connect(actionStart_Tracking, SIGNAL(triggered()), this,
			SLOT(systemStarttracking()));
	connect(actionStop_Tracking, SIGNAL(triggered()), this,
			SLOT(systemStoptracking()));
	connect(actionActivate_Handles, SIGNAL(triggered()), this,
			SLOT(systemActivateports()));
	connect(actionInitialize_System, SIGNAL(triggered()), this,
			SLOT(systemInitializesystem()));

	connect(actionProgram_Options, SIGNAL(triggered()), this,
			SLOT(optionsProgramoptions()));
	connect(&dtSubWindowProgramOptions_, SIGNAL(OK_signal()), this,
			SLOT(optionsProgramoptions_OK()));

	connect(actionIlluminator_Activation_Rate, SIGNAL(triggered()), this,
			SLOT(optionsIlluminatorfiringrate()));
	connect(&dtSubWindowIlluminatorFiringRate_, SIGNAL(OK_signal()), this,
			SLOT(optionsIlluminatorfiringrate_OK()));

	connect(actionSROM_Image_File_Settings, SIGNAL(triggered()), this,
			SLOT(settingsRomfilesettings()));
	connect(&dtSubWindowROMFile_, SIGNAL(ReInitialize_signal()), this,
			SLOT(reInitializeSystem()));

	connect(actionExit, SIGNAL(triggered()), this, SLOT(close()));

	connect(comboBox_Port, SIGNAL(currentIndexChanged(int)), this,
			SLOT(selchangePortHandles()));
	connect(comboBox_Marker, SIGNAL(currentIndexChanged(int)), this,
			SLOT(clearMarkerTransformData()));
	connect(comboBox_Indicator, SIGNAL(currentIndexChanged(int)), this,
			SLOT(clearIndicatorTransformData()));
	connect(comboBox_Reference, SIGNAL(currentIndexChanged(int)), this,
			SLOT(selchangeRefPortHandle()));
	connect(checkBox_HandleEnable, SIGNAL(clicked(bool)), this,
			SLOT(portEnabled()));
	connect(checkBox_UseTCPMarkerTransform, SIGNAL(clicked(bool)), this,
			SLOT(useTCPMarkerTransformChanged()));
	// Others related
	connect(&dtController_, SIGNAL(newFeedback(Feedback* )), this,
			SLOT(newFeedbackReceived(Feedback* )), Qt::QueuedConnection);
	connect(&dtController_, SIGNAL(newFeedback(Feedback* )), this,
			SLOT(displayFeedback(Feedback* )), Qt::QueuedConnection);
	connect(&dtController_, SIGNAL(shutdown()), this, SLOT(shutdown()),
			Qt::QueuedConnection);

	connect(&dtController_, SIGNAL(visualizeMotionPlan(MotionPlan)), this,
			SLOT(visualizeMotionPlan(MotionPlan)), Qt::QueuedConnection);
	connect(this, SIGNAL(addWaypointsSignal()), &dtController_,
			SLOT(addWaypointsCb()), Qt::QueuedConnection);
	connect(this, SIGNAL(visualizeExecutePlan()), &dtController_,
			SLOT(visualizeExecutePlanCb()), Qt::QueuedConnection);
	connect(this,
			SIGNAL(endEffectorPos(const InteractiveMarkerFeedbackConstPtr&)),
			&dtController_,
			SLOT(endEffectorPosCb(const InteractiveMarkerFeedbackConstPtr&)),
			Qt::QueuedConnection);
	connect(this, SIGNAL(executeMotionPlan_signal()), &dtController_,
			SLOT(executeMotionPlan()));

	connect(&dtController_, SIGNAL(closeWindow()), this,
			SLOT(closeDialogWindow()));
	connect(this, SIGNAL(changeMotionCompleteDelayTime(double)), &dtController_,
			SIGNAL(changeMotionCompleteDelayTime(double)),
			Qt::QueuedConnection);

	// pointer to node handle
	pdtNodeHandle_ = boost::make_shared<ros::NodeHandle>("");

// KUKA related
	// Set publisher for planned path display
	dtDisplayPublisher_ = pdtNodeHandle_->advertise<
			moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path",
			1, true);

	// Set publisher for joint state visualization
	dtJointStatePublisher_ = pdtNodeHandle_->advertise<sensor_msgs::JointState>(
			"/joint_states", 1000, true);

	// Set subscriber for obtaining interactive marker position
	dtInteractiveMarkerSubsriber_ =
			pdtNodeHandle_->subscribe<
					visualization_msgs::InteractiveMarkerFeedback, Interface>(
					"/rviz_moveit_motion_planning_display/robot_interaction_interactive_marker_topic/feedback",
					10, &Interface::endEffectorPosCb, this);

	dtPlanningSceneDiffPublisher_ = pdtNodeHandle_->advertise<
			moveit_msgs::PlanningScene>("/planning_scene", 1);

	// Set up menu marker
	marker_pos_ = 0.0;
	pdtInteractiveMarkerServer_.reset(
			new interactive_markers::InteractiveMarkerServer("moveit_test", "",
					false));
	initMenu();
	makeMenuMarker("marker1");
	dtMenuHandler_.apply(*pdtInteractiveMarkerServer_, "marker1");
	pdtInteractiveMarkerServer_->applyChanges();

	// initialize joint state publish count
	nJointStatePublishCount_ = 0;
	// allocate memory for position variable
	dtJointState_.position.resize(6);
	dtJointState_.name.resize(6);
	dtJointState_.name[0] = "joint1";
	dtJointState_.name[1] = "joint2";
	dtJointState_.name[2] = "joint3";
	dtJointState_.name[3] = "joint4";
	dtJointState_.name[4] = "joint5";
	dtJointState_.name[5] = "joint6";
	nJointStateDisplayCount_ = 0;
	nJointStateCallbackCount_ = 0;

	// pointer to plannar_
	pdtPlannar_ = boost::shared_ptr<Plannar>(dtController_.getPlannar());

	nCollisionOperationCount_ = 0;
// NDI related
	pdtCommandHandling_ = boost::make_shared<CommandHandling>();

	nCOMPort_ = 0;
	nTrackingMode_ = 0;
	bStopTracking_ = false;
	bIsTracking_ = false;
	bResetHardware_ = false;
	bWireless_ = false;
	bSystemInitialized_ = false;
	bPortsActivated_ = false;
	bInterference_ = false;
	bUse0x0800Option_ = false;
	bUseEulerAngles_ = false;
	bPortEnabled_ = false;
	bPortInitialized_ = false;
	strFrameNumber_ = "";
	strManufID_ = "";
	strSerialNo_ = "";
	strToolRev_ = "";
	strToolType_ = "";
	strPartNumber_ = "";

	lineEdit_Manufacturer->setText(QString(strManufID_.c_str()));
	lineEdit_Serial->setText(QString(strSerialNo_.c_str()));
	lineEdit_Tool->setText(QString(strToolType_.c_str()));
	lineEdit_Tool_2->setText(QString(strToolRev_.c_str()));
	lineEdit_Part->setText(QString(strPartNumber_.c_str()));
	checkBox_HandleEnable->setChecked(bPortEnabled_);
	checkBox_HandleInitialize->setChecked(bPortInitialized_);
	checkBox_0x0800->setChecked(bUse0x0800Option_);
	radioButton_TXMode->setChecked(!nTrackingMode_);

	// timer for periodically retrieving the transform data
	dtGetDataTimer_ = new QTimer(this);
	connect(dtGetDataTimer_, SIGNAL(timeout()), this,
			SLOT(getSystemTransformData()));

	strSystemMode_ = "Setup Mode";
	lineEdit_Mode->setText(QString(strSystemMode_.c_str()));
	setMode( MODE_PRE_INIT);

	bMotionComplete_ = false;

	dtControllerThread_ = new QThread;
	dtController_.moveToThread(dtControllerThread_);
	ROS_INFO("Controller thread starts...");
	dtControllerThread_->start();
	dtController_.pdtSubWindowWaitForExecution_ = &dtSubWindowWaitForExecution_;

	// This shouldn't be enabled until the needle point is calibrated
	pushButton_NDIFeedbackParallelMove->setEnabled(false);
	pushButton_NDIFeedbackMove->setEnabled(false);
	pushButton_CalculateTCPMarkerTransform->setEnabled(false);
	pushButton_CalculateTCPFlangeRotation->setEnabled(false);
	pushButton_XYZ4PointCalibrate->setEnabled(false);
	pushButton_CalculateNDIKUKATransform->setEnabled(false);
	checkBox_UseTCPMarkerTransform->setEnabled(false);
	label_MarkerNeedleWarning->setHidden(true);

	// KUKA Frames Initialization
	vecdtKUKAFrames_.resize(4);
	vecbFramesUpdated_.resize(4);

	for (int i = 0; i < 4; i++) {
		vecbFramesUpdated_[i] = false;
		vecdtKUKAFrames_[i] = Frame(0, 0, 0, 0, 0, 0);
	}
	//Log file
	pfOut_ = fopen("/home/lxt12/logfile_RobotInterface", "a+t");
	if (pfOut_ == NULL) {
		ROS_ERROR("Cannot open specified log file");
	}

	vecbCalibrationToDoList_.resize(12);
	for (int i = 0; i < 12; i++) {
		vecbCalibrationToDoList_[i] = false;
	}

	bTCPMarkerFlip_ = false;

	dParallelMoveThreshold_ = MINIMUM_PARALLEL_MOVE_THRESHOLD;
}

Interface::~Interface() {
	std::cout << "Interface Deconstructing..." << std::endl;

	std::cout << "Controller thread ends..." << std::endl;
	dtControllerThread_->exit();
}
int Interface::PlanAndExecuteTargetMotion(geometry_msgs::Pose target_pose,
		std::string end_effector_link) {

	do {
		if (!dtController_.planTargetMotion(target_pose, end_effector_link)) {
			ROS_ERROR("Motion plan failed");
			return MOTION_PLAN_FAIL;
		}
		moveit::planning_interface::MoveGroup::Plan motion_plan =
				dtController_.getMotionPlan();
		Axis axis_plan;
		axis_plan.set(0, 0, 0, 0, 0, 0);

		for (int i = 0;
				i < motion_plan.trajectory_.joint_trajectory.points.size() - 1;
				i++) {

			axis_plan.A1 +=
					fabs(
							motion_plan.trajectory_.joint_trajectory.points[i
									+ 1].positions[0]
									- motion_plan.trajectory_.joint_trajectory.points[i].positions[0]);
			axis_plan.A2 +=
					fabs(
							motion_plan.trajectory_.joint_trajectory.points[i
									+ 1].positions[1]
									- motion_plan.trajectory_.joint_trajectory.points[i].positions[1]);
			axis_plan.A3 +=
					fabs(
							motion_plan.trajectory_.joint_trajectory.points[i
									+ 1].positions[2]
									- motion_plan.trajectory_.joint_trajectory.points[i].positions[2]);
			axis_plan.A4 +=
					fabs(
							motion_plan.trajectory_.joint_trajectory.points[i
									+ 1].positions[3]
									- motion_plan.trajectory_.joint_trajectory.points[i].positions[3]);
			axis_plan.A5 +=
					fabs(
							motion_plan.trajectory_.joint_trajectory.points[i
									+ 1].positions[4]
									- motion_plan.trajectory_.joint_trajectory.points[i].positions[4]);
			axis_plan.A6 +=
					fabs(
							motion_plan.trajectory_.joint_trajectory.points[i
									+ 1].positions[5]
									- motion_plan.trajectory_.joint_trajectory.points[i].positions[5]);
		}
		axis_plan.A1 = axis_plan.A1 / M_PI * 180.0;
		axis_plan.A2 = axis_plan.A2 / M_PI * 180.0;
		axis_plan.A3 = axis_plan.A3 / M_PI * 180.0;
		axis_plan.A4 = axis_plan.A4 / M_PI * 180.0;
		axis_plan.A5 = axis_plan.A5 / M_PI * 180.0;
		axis_plan.A6 = axis_plan.A6 / M_PI * 180.0;

		// If any single axis's angle motion is larger than MAX_MOVE_ANGLE, we need to let the user know to check whether they want the motion plan or not
		if (axis_plan.A1 > MAX_MOVE_ANGLE || axis_plan.A2 > MAX_MOVE_ANGLE
				|| axis_plan.A3 > MAX_MOVE_ANGLE
				|| axis_plan.A4 > MAX_MOVE_ANGLE
				|| axis_plan.A5 > MAX_MOVE_ANGLE
				|| axis_plan.A6 > MAX_MOVE_ANGLE) {

			dtSubWindowMotionPlanDecision_.exec();
			if (dtSubWindowMotionPlanDecision_.nReturnValue_
					== MOTION_PLAN_EXECUTE) {
				emit changeMotionCompleteDelayTime(180.0);
				emit executeMotionPlan_signal();
				return MOTION_PLAN_EXECUTE;

			} else if (dtSubWindowMotionPlanDecision_.nReturnValue_
					== MOTION_PLAN_REPLAN) {
				continue;
			} else {
				return MOTION_PLAN_CANCEL;
			}
		} else {
			ROS_INFO("Small motion is allowed for automatic mode");
			emit changeMotionCompleteDelayTime(60.0);
			emit executeMotionPlan_signal();
			return MOTION_PLAN_EXECUTE;
		}

	} while (1);

}
void Interface::copyCurrentTCPState() {

	if(!checkBox_UseTCPMarkerTransform->isChecked()) {
		ROS_ERROR("Only support TCP Copy, please check the use tcp marker transform option");
		return;
	}

	lineEdit_NDI_X_2->setText(QString::number(lineEdit_Tx->text().toDouble()));
	lineEdit_NDI_Y_2->setText(QString::number(lineEdit_Ty->text().toDouble()));
	lineEdit_NDI_Z_2->setText(QString::number(lineEdit_Tz->text().toDouble()));

	Eigen::Vector3d EulerAngleVector = Quaternion2Euler(
			lineEdit_Qx->text().toDouble(), lineEdit_Qy->text().toDouble(),
			lineEdit_Qz->text().toDouble(), lineEdit_Qo->text().toDouble());

	lineEdit_NDI_A_2->setText(
			QString::number(EulerAngleVector.data()[0] / M_PI * 180.0));
	lineEdit_NDI_B_2->setText(
			QString::number(EulerAngleVector.data()[1] / M_PI * 180.0));
	lineEdit_NDI_C_2->setText(
			QString::number(EulerAngleVector.data()[2] / M_PI * 180.0));
}
void Interface::copyCurrentTCPXYZKUKAABC() {
	lineEdit_NDI_X->setText(QString::number(lineEdit_Tx->text().toDouble()));
	lineEdit_NDI_Y->setText(QString::number(lineEdit_Ty->text().toDouble()));
	lineEdit_NDI_Z->setText(QString::number(lineEdit_Tz->text().toDouble()));

	lineEdit_KUKA_A->setText(output_a->toPlainText());
	lineEdit_KUKA_B->setText(output_b->toPlainText());
	lineEdit_KUKA_C->setText(output_c->toPlainText());

}

void Interface::ndiFeedbackMove() {

	if (lineEdit_NDI_X_2->text().isEmpty() || lineEdit_NDI_Y_2->text().isEmpty()
			|| lineEdit_NDI_Z_2->text().isEmpty()
			|| lineEdit_NDI_A_2->text().isEmpty()
			|| lineEdit_NDI_B_2->text().isEmpty()
			|| lineEdit_NDI_C_2->text().isEmpty()) {
		ROS_ERROR("value of the target point is empty");
		return;
	}

	if (output_x->toPlainText().isEmpty() || output_y->toPlainText().isEmpty()
			|| output_z->toPlainText().isEmpty()
			|| output_a->toPlainText().isEmpty()
			|| output_b->toPlainText().isEmpty()
			|| output_c->toPlainText().isEmpty()) {
		ROS_ERROR("KUKA feedback value is empty");
		return;
	}

	int nMarker = ASCIIToHex(
			(char*) (comboBox_Marker->currentText().toStdString().c_str()), 2);

	if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
			!= TRANSFORM_VALID) {
		ROS_ERROR("NDI failed to track Marker");
		return;
	}

	if (!vecbCalibrationToDoList_[Interface::NDIKUKATransform]
			|| !vecbCalibrationToDoList_[Interface::TCPMarkerTransform]) {
		ROS_ERROR(
				"Calibration prerequisite is not complete for NDI Feedback Move");
		return;
	}
	pushButton_NDIFeedbackMove->setEnabled(false);
	dtGetDataTimer_->stop();

	QuatTransformation dtMarker, dtDummy;

	Axis AxisFeedback;
	Frame FrameFeedback;

	//Eigen::Vector3d EulerAngleVector;
	std::vector<double> Translation(3);
	Eigen::Vector4d Quaternion;
	Eigen::Affine3d RotationPart;
	Eigen::Affine3d TranslationPart;
	Eigen::Matrix3d Rotation;

	Eigen::Matrix4d TCPMarkerTransform;
	Eigen::Matrix4d NDIKUKATransform;
	Eigen::Matrix4d TCPFlangeTransform;

	Eigen::Matrix4d CurrentMarkerNDITransform;
	Eigen::Matrix4d CurrentTCPNDITransform;
	Eigen::Matrix4d TargetTCPNDITransform;
	Eigen::Matrix4d CurrentTCPKUKATransform;
	Eigen::Matrix4d TargetTCPKUKATransform;
	Eigen::Matrix4d CurrentFlangeKUKATransform;
	Eigen::Matrix4d TargetFlangeKUKATransform;

	Eigen::Matrix4d TCPErrorNDITransform;
	Eigen::Matrix4d TCPErrorKUKATransform;
	Eigen::Matrix4d FlangeErrorKUKATransform;

	bool Replan_flag;
	geometry_msgs::Pose TargetPose;
	Eigen::Vector3d EulerAngleVector;

	double dPositionError, dAngleError;
	int motion_return_value;

	EulerAngleVector.data()[0] = lineEdit_NDI_A_2->text().toDouble()
			/ 180.0* M_PI;
	EulerAngleVector.data()[1] = lineEdit_NDI_B_2->text().toDouble()
			/ 180.0* M_PI;
	EulerAngleVector.data()[2] = lineEdit_NDI_C_2->text().toDouble()
			/ 180.0* M_PI;
	Translation[0] = lineEdit_NDI_X_2->text().toDouble();
	Translation[1] = lineEdit_NDI_Y_2->text().toDouble();
	Translation[2] = lineEdit_NDI_Z_2->text().toDouble();
	RotationPart = createRotationMatrix(EulerAngleVector.data()[2],
			EulerAngleVector.data()[1], EulerAngleVector.data()[0]);
	TranslationPart = Eigen::Affine3d(
			Eigen::Translation3d(
					Eigen::Vector3d(Translation[0], Translation[1],
							Translation[2])));
	TargetTCPNDITransform = (TranslationPart * RotationPart).matrix();

	// From ABC 2-point method and pivoting method
	RotationPart = dtTCPMarkerRotationMatrix_;
	TranslationPart = Eigen::Affine3d(
			Eigen::Translation3d(dtTCPMarkerTranslationVector_));
	TCPMarkerTransform = (TranslationPart * RotationPart).matrix();

	// From NDI to KUKA complete Transform calculation
	RotationPart = dtNDIKUKARotationMatrix_;
	TranslationPart = Eigen::Affine3d(
			Eigen::Translation3d(dtNDIKUKATranslationVector_));
	NDIKUKATransform = (TranslationPart * RotationPart).matrix();

	// Here we need to obtain the marker position instead of the tip position
	checkBox_UseTCPMarkerTransform->setChecked(false);
	bUseTCPMarkerTransform_ = false;

	do {

		if (!getNDIFramesAverage(nMarker, -1, dtMarker, dtDummy, true,
		NDI_FRAME_COUNT)) {
			ROS_ERROR("Cannot get marker position data");
			pushButton_NDIFeedbackMove->setEnabled(true);
			dtGetDataTimer_->start(NDI_TIME_INTERVAL);
			return;
		}

		// Marker to NDI Transform
		EulerAngleVector = Quaternion2Euler(dtMarker.dtRotation.fQx,
				dtMarker.dtRotation.fQy, dtMarker.dtRotation.fQz,
				dtMarker.dtRotation.fQ0);
		RotationPart = createRotationMatrix(EulerAngleVector.data()[2],
				EulerAngleVector.data()[1], EulerAngleVector.data()[0]);
		TranslationPart = Eigen::Affine3d(
				Eigen::Translation3d(
						Eigen::Vector3d(dtMarker.dtTranslation.fTx,
								dtMarker.dtTranslation.fTy,
								dtMarker.dtTranslation.fTz)));
		CurrentMarkerNDITransform = (TranslationPart * RotationPart).matrix();

		CurrentTCPNDITransform = CurrentMarkerNDITransform * TCPMarkerTransform;
		TCPErrorNDITransform = TargetTCPNDITransform
				* CurrentTCPNDITransform.inverse();

		// For error calculation
		Rotation = TargetTCPNDITransform.block(0, 0, 3, 3);
		EulerAngleVector = Rotation.eulerAngles(2, 1, 0);

		Rotation = CurrentTCPNDITransform.block(0, 0, 3, 3);
		EulerAngleVector -= Rotation.eulerAngles(2, 1, 0);

		dPositionError = sqrt(
				TCPErrorNDITransform.coeff(0, 3)
						* TCPErrorNDITransform.coeff(0, 3)
						+ TCPErrorNDITransform.coeff(1, 3)
								* TCPErrorNDITransform.coeff(1, 3)
						+ TCPErrorNDITransform.coeff(2, 3)
								* TCPErrorNDITransform.coeff(2, 3));
		dAngleError = sqrt(
				EulerAngleVector.data()[0] * EulerAngleVector.data()[0]
						+ EulerAngleVector.data()[1]
								* EulerAngleVector.data()[1]
						+ EulerAngleVector.data()[2]
								* EulerAngleVector.data()[2]) / M_PI * 180.0;
		ROS_INFO("Position Error: %f mm, Angle Error: %f deg", dPositionError,
				dAngleError);
		if (dPositionError < 0.3 && dAngleError < 0.3) {
			ROS_INFO("NDI Feedback Move succeed");
			pushButton_NDIFeedbackMove->setEnabled(true);
			dtGetDataTimer_->start(NDI_TIME_INTERVAL);
			checkBox_UseTCPMarkerTransform->setChecked(true);
			bUseTCPMarkerTransform_ = true;
			break;
		}

		// Obtain current TCP position of KUKA robot
		AxisFeedback = dtController_.getFeedbackAxis();
		dtLastAxis_.set(AxisFeedback);
		pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);
		RotationPart = createRotationMatrix(FrameFeedback.C / 180.0 * M_PI,
				FrameFeedback.B / 180.0 * M_PI, FrameFeedback.A / 180.0 * M_PI);
		TranslationPart = Eigen::Affine3d(
				Eigen::Translation3d(
						Eigen::Vector3d(FrameFeedback.X, FrameFeedback.Y,
								FrameFeedback.Z)));
		CurrentTCPKUKATransform = (TranslationPart * RotationPart).matrix();

		TCPErrorKUKATransform = NDIKUKATransform * TCPErrorNDITransform
				* NDIKUKATransform.inverse();
		TargetTCPKUKATransform = TCPErrorKUKATransform
				* CurrentTCPKUKATransform;

		Rotation = TargetTCPKUKATransform.block(0, 0, 3, 3);
		EulerAngleVector = Rotation.eulerAngles(2, 1, 0);
		Quaternion = Euler2Quaternion(EulerAngleVector.data()[2],
				EulerAngleVector.data()[1], EulerAngleVector.data()[0]);
		TargetPose.orientation.x = Quaternion.data()[0];
		TargetPose.orientation.y = Quaternion.data()[1];
		TargetPose.orientation.z = Quaternion.data()[2];
		TargetPose.orientation.w = Quaternion.data()[3];
		TargetPose.position.x = TargetTCPKUKATransform.coeff(0, 3) / 1000.0;
		TargetPose.position.y = TargetTCPKUKATransform.coeff(1, 3) / 1000.0;
		TargetPose.position.z = TargetTCPKUKATransform.coeff(2, 3) / 1000.0;

		motion_return_value = PlanAndExecuteTargetMotion(TargetPose, "tip");

		if (motion_return_value == MOTION_PLAN_EXECUTE) {

		} else {
			pushButton_NDIFeedbackMove->setEnabled(true);
			dtGetDataTimer_->start(NDI_TIME_INTERVAL);
			checkBox_UseTCPMarkerTransform->setChecked(true);
			bUseTCPMarkerTransform_ = true;
			return;
		}
		dtSubWindowWaitForExecution_.exec();

	} while (1);

	checkBox_UseTCPMarkerTransform->setChecked(true);
	bUseTCPMarkerTransform_ = true;
}

void Interface::XYZNPointMethod(std::vector<Frame> &KUKAFrames,
		Eigen::Vector3d &TCPTranslation) {

	Eigen::MatrixX3d StackRotationMatrix(
			3 * KUKAFrames.size() * (KUKAFrames.size() - 1) / 2, 3);
	Eigen::VectorXd StackTranslationVector(
			3 * KUKAFrames.size() * (KUKAFrames.size() - 1) / 2);
	Eigen::Matrix3d TempRotation1, TempRotation2, TempMatrix;
	int Count = 0;
	// Use all combinations of N different positions to calculate the least square solution of TCP translation
	for (int i = 0; i < KUKAFrames.size() - 1; i++) {
		for (int j = i + 1; j < KUKAFrames.size(); j++) {

			TempRotation1 = createRotationMatrix(KUKAFrames[i].C / 180.0 * M_PI,
					KUKAFrames[i].B / 180.0 * M_PI,
					KUKAFrames[i].A / 180.0 * M_PI).rotation();
			TempRotation2 = createRotationMatrix(KUKAFrames[j].C / 180.0 * M_PI,
					KUKAFrames[j].B / 180.0 * M_PI,
					KUKAFrames[j].A / 180.0 * M_PI).rotation();
			TempMatrix = TempRotation1 - TempRotation2;

			StackRotationMatrix.block(3 * Count, 0, 3, 3) = TempMatrix;
			StackTranslationVector.data()[3 * Count] = (KUKAFrames[j].X
					- KUKAFrames[i].X);
			StackTranslationVector.data()[3 * Count + 1] = (KUKAFrames[j].Y
					- KUKAFrames[i].Y);
			StackTranslationVector.data()[3 * Count + 2] = (KUKAFrames[j].Z
					- KUKAFrames[i].Z);

			Count++;
		}
	}

	Eigen::Matrix3d LeftPart(
			StackRotationMatrix.transpose() * StackRotationMatrix);
	Eigen::Vector3d RightPart(
			StackRotationMatrix.transpose() * StackTranslationVector);

	TCPTranslation = LeftPart.inverse() * RightPart;

	// Average Error Calculation
	Eigen::VectorXd LeastSquareResult(
			3 * KUKAFrames.size() * (KUKAFrames.size() - 1) / 2);
	LeastSquareResult = StackRotationMatrix * TCPTranslation;
	LeastSquareResult -= StackTranslationVector;

	double Error = sqrt(LeastSquareResult.dot(LeastSquareResult));

	ROS_INFO("Average Error for XYZNPoint Method: %f mm", Error * 1000);

}
// Slots function
//TODO: After using this function, we had better change the content of URDF file
void Interface::ABC2PointCalibrate() {

#ifndef USE_FIXED_TCP_FLANGE_ROTATION
	if (!vecbCalibrationToDoList_[Interface::NDIKUKARotation]
			|| !vecbCalibrationToDoList_[Interface::TCPMarkerTransform]) {
		ROS_ERROR(
				"Calibration prerequisite is not complete for ABC 2-point method");
		return;
	}

	pushButton_CalculateTCPFlangeRotation->setEnabled(false);
	dtGetDataTimer_->stop();

	// Use TCP Marker Transform so that NDI could track the TCP position
	checkBox_UseTCPMarkerTransform->setEnabled(true);
	bUseTCPMarkerTransform_ = true;

	int nMarker = ASCIIToHex(
			(char*) (comboBox_Marker->currentText().toStdString().c_str()), 2);
	int nIndicator = ASCIIToHex(
			(char*) (comboBox_Indicator->currentText().toStdString().c_str()),
			2);

	Axis AxisFeedback;
	Frame FrameFeedback;
	QuatTransformation dtMarker, dtIndicator, dtDummy;

	// Obtain current state of KUKA robot
	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame_flange(AxisFeedback, FrameFeedback);
	// Derive Ra and Ta of KUKA
	Eigen::Matrix3d RotationA = createRotationMatrix(
			FrameFeedback.C / 180.0 * M_PI, FrameFeedback.B / 180.0 * M_PI,
			FrameFeedback.A / 180.0 * M_PI).rotation();
	Eigen::Vector3d TranslationA(FrameFeedback.X,
			FrameFeedback.Y, FrameFeedback.Z);
	bool bTracking = false;

	//----------------------------------------------------------------------------------------------
	//Move the needle point of KUKA to where the indicator pointed (positive part of tool's X axis)
	// To check whether the NDI can track both the marker of KUKA and indicator or not
	ROS_INFO("Please indicate a point on the x direction of the needle");
	do {
		bTracking = false;
		do {
			dtSubWindowWaitForIndicatorPlaced_.exec();
			getSystemTransformData(false);
			if (dtSubWindowWaitForIndicatorPlaced_.nReturnValue_ == INDICATOR_OK) {
				if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
						!= TRANSFORM_VALID) {
					ROS_ERROR("NDI failed to track Marker or Point Indicator");
					bTracking = false;
				} else {
					bTracking = true;
				}
			} else {
				ROS_INFO("ABC 2-Point Calibration canceled");
				dtGetDataTimer_->start(NDI_TIME_INTERVAL);
				pushButton_CalculateTCPFlangeRotation->setEnabled(true);
				return;
			}
		}while (!bTracking);

		// Derive the average NDI position of the needle point indicator
		if (!getNDIFramesAverage(-1, nIndicator, dtDummy, dtIndicator, false,
						NDI_FRAME_COUNT)) {
			ROS_ERROR("Cannot get tool position data");
			dtGetDataTimer_->start(NDI_TIME_INTERVAL);
			pushButton_CalculateTCPFlangeRotation->setEnabled(true);
			return;
		}

		lineEdit_NDI_X->setText(
				QString::number(dtIndicator.dtTranslation.fTx));
		lineEdit_NDI_Y->setText(
				QString::number(dtIndicator.dtTranslation.fTy));
		lineEdit_NDI_Z->setText(
				QString::number(dtIndicator.dtTranslation.fTz));

		// Obtain current state of KUKA robot
		AxisFeedback = dtController_.getFeedbackAxis();
		dtLastAxis_.set(AxisFeedback);
		pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);

		// Set the target KUKA ABC pose to the current KUKA ABC pose
		lineEdit_KUKA_A->setText(QString::number(FrameFeedback.A));
		lineEdit_KUKA_B->setText(QString::number(FrameFeedback.B));
		lineEdit_KUKA_C->setText(QString::number(FrameFeedback.C));
		// Let KUKA move to the position that the needle point indicator pointed

	}while (!ndiFeedbackParallelMove());

	//----------------------------------------------------------------------------------------------
	// Derive Tb
	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame_flange(AxisFeedback, FrameFeedback);
	Eigen::Vector3d TranslationB(FrameFeedback.X,
			FrameFeedback.Y, FrameFeedback.Z);

	//----------------------------------------------------------------------------------------------
	//Move the needle point of KUKA to where the indicator pointed (positive part of tool's XY plane)
	ROS_INFO("Please indicate a point on the xy plane of the needle");
	do {
		bTracking = false;
		do {
			dtSubWindowWaitForIndicatorPlaced_.exec();
			getSystemTransformData(false);
			if (dtSubWindowWaitForIndicatorPlaced_.nReturnValue_ == INDICATOR_OK) {
				if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
						!= TRANSFORM_VALID
						|| pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
						!= TRANSFORM_VALID) {
					ROS_ERROR("NDI failed to track Marker or Point Indicator");
					bTracking = false;
				} else {
					bTracking = true;
				}
			} else {
				ROS_INFO("ABC 2-Point Calibration canceled");
				dtGetDataTimer_->start(NDI_TIME_INTERVAL);
				pushButton_CalculateTCPFlangeRotation->setEnabled(true);
				return;
			}
		}while (!bTracking);

		// Derive the NDI position of the needle point indicator
		if (!getNDIFramesAverage(nMarker, nIndicator, dtMarker, dtIndicator,
						false, NDI_FRAME_COUNT)) {
			ROS_ERROR("Cannot get tool position data");
			dtGetDataTimer_->start(NDI_TIME_INTERVAL);
			pushButton_CalculateTCPFlangeRotation->setEnabled(true);
			return;
		}
		lineEdit_NDI_X->setText(
				QString::number(dtIndicator.dtTranslation.fTx));
		lineEdit_NDI_Y->setText(
				QString::number(dtIndicator.dtTranslation.fTy));
		lineEdit_NDI_Z->setText(
				QString::number(dtIndicator.dtTranslation.fTz));

		// Obtain current state of KUKA robot
		AxisFeedback = dtController_.getFeedbackAxis();
		dtLastAxis_.set(AxisFeedback);
		pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);

		// Set the target KUKA ABC pose to the current KUKA ABC pose
		lineEdit_KUKA_A->setText(QString::number(FrameFeedback.A));
		lineEdit_KUKA_B->setText(QString::number(FrameFeedback.B));
		lineEdit_KUKA_C->setText(QString::number(FrameFeedback.C));
		// Let KUKA move to the position that the needle point indicator pointed
	}while (!ndiFeedbackParallelMove());

	//----------------------------------------------------------------------------------------------
	// Derive Tc
	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame_flange(AxisFeedback, FrameFeedback);
	Eigen::Vector3d TranslationC(FrameFeedback.X,
			FrameFeedback.Y, FrameFeedback.Z);

	// Rotation matrix of Flange to TCP
	Eigen::Vector3d TransBA(TranslationB - TranslationA);
	Eigen::Vector3d ToolUnitX(TransBA / TransBA.norm());

	Eigen::Vector3d TransCA(TranslationC - TranslationA);
	Eigen::Vector3d ToolUnitC(TransCA / TransCA.norm());
	Eigen::Vector3d ToolUnitY(ToolUnitC - ToolUnitC.dot(ToolUnitX) * ToolUnitX);
	ToolUnitY.normalize();

	// Calculate how the TCP is moved after TranslationA position
	double deltaY2 = TransCA.dot(ToolUnitY);
	double deltaX2 = sqrt(
			(TransCA.norm() * TransCA.norm()) - deltaY2 * deltaY2);

	// Calculate each column of RaR matrix
	Eigen::Vector3d RotationCol1(ToolUnitX);
	Eigen::Vector3d RotationCol2((TransCA - RotationCol1 * deltaX2) / deltaY2);
	Eigen::Vector3d RotationCol3(RotationCol1.cross(RotationCol2));
	RotationCol1.normalize();
	RotationCol2.normalize();
	RotationCol3.normalize();

	Eigen::Matrix3d RaR;
	RaR.col(0) = RotationCol1;
	RaR.col(1) = RotationCol2;
	RaR.col(2) = RotationCol3;

	Eigen::Matrix3d TCPToFlange = RotationA.inverse() * RaR;
	dtTCPFlangeRotationMatrix_ = TCPToFlange;

	ROS_INFO(
			"TCP to Flange rotation matrix: \n%f, %f, %f \n%f, %f, %f \n%f, %f, %f\n",
			dtTCPFlangeRotationMatrix_.data()[0],
			dtTCPFlangeRotationMatrix_.data()[3],
			dtTCPFlangeRotationMatrix_.data()[6],
			dtTCPFlangeRotationMatrix_.data()[1],
			dtTCPFlangeRotationMatrix_.data()[4],
			dtTCPFlangeRotationMatrix_.data()[7],
			dtTCPFlangeRotationMatrix_.data()[2],
			dtTCPFlangeRotationMatrix_.data()[5],
			dtTCPFlangeRotationMatrix_.data()[8]);

	Eigen::Vector3d EulerAngleVector = dtTCPFlangeRotationMatrix_.eulerAngles(2,
			1, 0);
	ROS_INFO(
			"Please change the content of URDF file, euler angle of TCP to Flange: A %f rad, B %f rad, C %f rad",
			EulerAngleVector.data()[0], EulerAngleVector.data()[1],
			EulerAngleVector.data()[2]);

#else
	dtTCPFlangeRotationMatrix_.data()[0] = -0.019601;
	dtTCPFlangeRotationMatrix_.data()[1] = -0.012737;
	dtTCPFlangeRotationMatrix_.data()[2] = -0.999727;
	dtTCPFlangeRotationMatrix_.data()[3] = -0.165045;
	dtTCPFlangeRotationMatrix_.data()[4] = -0.986159;
	dtTCPFlangeRotationMatrix_.data()[5] = 0.015800;
	dtTCPFlangeRotationMatrix_.data()[6] = -0.986091;
	dtTCPFlangeRotationMatrix_.data()[7] = 0.165310;
	dtTCPFlangeRotationMatrix_.data()[8] = 0.017227;
#endif

	dtGetDataTimer_->start(NDI_TIME_INTERVAL);
	pushButton_CalculateTCPFlangeRotation->setEnabled(true);
	ROS_INFO("Needle direction is successfully calibrated");

	vecbCalibrationToDoList_[Interface::TCPFlangeRotation] = true;
}
void Interface::showSelectedKUKAPosition() {
	int index = comboBox_KUKAPosition->currentIndex();
	if (!vecbFramesUpdated_[index]) {
		ROS_INFO("KUKA Position %d not added yet", index + 1);
		return;
	}
	Frame FrameFeedback = vecdtKUKAFrames_[index];
	ROS_INFO(
			"KUKA Position %d: X %f mm, Y %f mm, Z %f mm, A %f deg, B %f deg, C %f deg",
			index + 1, FrameFeedback.X, FrameFeedback.Y, FrameFeedback.Z,
			FrameFeedback.A, FrameFeedback.B, FrameFeedback.C);

}
void Interface::XYZ4PointCalibrate() {
	pushButton_XYZ4PointCalibrate->setEnabled(false);
	dtGetDataTimer_->stop();
	Eigen::Vector3d TCPTranslation;
	if (!vecbFramesUpdated_[0] || !vecbFramesUpdated_[1]
			|| !vecbFramesUpdated_[2] || !vecbFramesUpdated_[3]) {
		ROS_ERROR("Part of 4 KUKA frames not recorded");
		pushButton_XYZ4PointCalibrate->setEnabled(true);
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		return;
	}
	XYZNPointMethod(vecdtKUKAFrames_, TCPTranslation);

	// Store corresponding translation vector
	if (comboBox_Transform->currentIndex() == 0) {
#ifndef USE_FIXED_MARKER_FLANGE_TRANSLATION
		dtMarkerFlangeTranslationVector_.data()[0] = TCPTranslation.data()[0];
		dtMarkerFlangeTranslationVector_.data()[1] = TCPTranslation.data()[1];
		dtMarkerFlangeTranslationVector_.data()[2] = TCPTranslation.data()[2];
#else
		//TODO: This is measured by Xingtong Liu
		//If you need to change that, just uncomment the previous codes and comment codes below
		dtMarkerFlangeTranslationVector_.data()[0] = -7.759;
		dtMarkerFlangeTranslationVector_.data()[1] = 148.458;
		dtMarkerFlangeTranslationVector_.data()[2] = -259.918;

		/*-0.007759 m, 0.148458 m, -0.259918 m*/

#endif
		ROS_INFO("Marker to Flange translation vector:\n%f mm, %f mm, %f mm\n",
				dtMarkerFlangeTranslationVector_.data()[0],
				dtMarkerFlangeTranslationVector_.data()[1],
				dtMarkerFlangeTranslationVector_.data()[2]);
		pushButton_CalculateNDIKUKATransform->setEnabled(true);
		vecbCalibrationToDoList_[Interface::MarkerFlangeTranslation] = true;
	} else {
#ifndef USE_FIXED_TCP_FLANGE_TRANSLATION
		dtTCPFlangeTranslationVector_.data()[0] = TCPTranslation.data()[0];
		dtTCPFlangeTranslationVector_.data()[1] = TCPTranslation.data()[1];
		dtTCPFlangeTranslationVector_.data()[2] = TCPTranslation.data()[2];
#else
		//TODO: This is measured by Xingtong Liu
		//If you need to change that, just uncomment the previous codes and comment codes below
		dtTCPFlangeTranslationVector_.data()[0] = 5.189830;
		dtTCPFlangeTranslationVector_.data()[1] = 171.790068;
		dtTCPFlangeTranslationVector_.data()[2] = 26.065161;
		/*5.189830 mm, 171.790068 mm, 26.065161 mm*/
#endif
		ROS_INFO("TCP to Flange translation vector:\n%f mm, %f mm, %f mm\n",
				dtTCPFlangeTranslationVector_.data()[0],
				dtTCPFlangeTranslationVector_.data()[1],
				dtTCPFlangeTranslationVector_.data()[2]);
		vecbCalibrationToDoList_[Interface::TCPFlangeTranslation] = true;
	}

	pushButton_XYZ4PointCalibrate->setEnabled(true);
	dtGetDataTimer_->start(NDI_TIME_INTERVAL);
}
void Interface::AddorUpdatePosition() {

	Axis AxisFeedback;
	Frame FrameFeedback;

	int index = comboBox_KUKAPosition->currentIndex();
	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame_flange(AxisFeedback, FrameFeedback);
	vecdtKUKAFrames_[index] = FrameFeedback;
	vecbFramesUpdated_[index] = true;
	ROS_INFO(
			"Flange Position: X %f mm, Y %f mm, Z %f mm, A %f deg, B %f deg, C %f deg",
			FrameFeedback.X, FrameFeedback.Y, FrameFeedback.Z, FrameFeedback.A,
			FrameFeedback.B, FrameFeedback.C);

	if (vecbFramesUpdated_[0] && vecbFramesUpdated_[1] && vecbFramesUpdated_[2]
			&& vecbFramesUpdated_[3]) {
		ROS_INFO("All 4 frames recorded");
		pushButton_XYZ4PointCalibrate->setEnabled(true);
	}
}
void Interface::recordKUKAFeedback() {
	std::string strPrefix = lineEdit_PrefixMessage->text().toStdString();
	std::stringstream strFeedbackData;

	Axis AxisFeedback;
	AxisFeedback = dtController_.getFeedbackAxis();
	strFeedbackData << AxisFeedback.A1 << " deg\r" << AxisFeedback.A2
			<< " deg\r" << AxisFeedback.A3 << " deg\r" << AxisFeedback.A4
			<< " deg\r" << AxisFeedback.A5 << " deg\r" << AxisFeedback.A6
			<< "deg";

	std::string record = strPrefix + ": " + strFeedbackData.str();
	fprintf(pfOut_, "%s\n", record.c_str());

	ROS_INFO("KUKA feedback recorded successfully");
}

// This function should be called only when the positions that NDI and KUKA return represent the same point in the world coordinate
void Interface::calculateNDIKUKATransform() {

#ifndef USE_FIXED_NDI_KUKA_TRANSFORM
	dtGetDataTimer_->stop();
	pushButton_CalculateNDIKUKATransform->setEnabled(false);

	int nMarker = ASCIIToHex(
			(char*) (comboBox_Marker->currentText().toStdString().c_str()), 2);

	if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
			!= TRANSFORM_VALID) {
		ROS_ERROR("NDI failed to track Marker");
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		pushButton_CalculateNDIKUKATransform->setEnabled(true);
		return;
	}
	if (output_x->toPlainText().isEmpty() || output_y->toPlainText().isEmpty()
			|| output_z->toPlainText().isEmpty()
			|| output_a->toPlainText().isEmpty()
			|| output_b->toPlainText().isEmpty()
			|| output_c->toPlainText().isEmpty()) {
		ROS_ERROR("KUKA feedback value is empty");
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		pushButton_CalculateNDIKUKATransform->setEnabled(true);
		return;
	}
	if (lineEdit_incrDistance->text().isEmpty()) {
		ROS_ERROR("Distance Step is empty");
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		pushButton_CalculateNDIKUKATransform->setEnabled(true);
		return;
	}

	if (!vecbCalibrationToDoList_[Interface::MarkerFlangeTranslation]) {
		ROS_ERROR(
				"Calibration prerequisite is not complete for NDI to KUKA Transform Calculation");
		return;
	}

	// Use the marker position instead of the top position
	checkBox_UseTCPMarkerTransform->setChecked(false);
	bUseTCPMarkerTransform_ = false;

	Axis AxisFeedback;
	Frame FrameFeedback;

	geometry_msgs::Pose initial_pose, target_pose;
	Eigen::Vector3d EulerAngleVector;

	std::vector<Eigen::Vector3d> vecdtNDIPosition(75);
	std::vector<Eigen::Vector3d> vecdtKUKAPosition(75);

	std::vector<double> Translation(3);
	Eigen::Affine3d RotationPart, TranslationPart;
	Eigen::Matrix4d CurrentFlangeKUKATransform;
	Eigen::Matrix4d CurrentMarkerKUKATransform;
	Eigen::Matrix4d MarkerFlangeTransform;
	Eigen::Vector4d q;
	QuatTransformation dtMarker, dtDummy;

	RotationPart = Eigen::Affine3d::Identity();
	TranslationPart = Eigen::Affine3d(
			Eigen::Translation3d(dtMarkerFlangeTranslationVector_));
	MarkerFlangeTransform = (TranslationPart * RotationPart).matrix();

	// Obtain current state of KUKA robot
	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);

	EulerAngleVector.data()[0] = FrameFeedback.A / 180.0 * M_PI;
	EulerAngleVector.data()[1] = FrameFeedback.B / 180.0 * M_PI;
	EulerAngleVector.data()[2] = FrameFeedback.C / 180.0 * M_PI;

	q = Euler2Quaternion(EulerAngleVector.data()[2], EulerAngleVector.data()[1],
			EulerAngleVector.data()[0]);
	initial_pose.orientation.x = q.data()[0];
	initial_pose.orientation.y = q.data()[1];
	initial_pose.orientation.z = q.data()[2];
	initial_pose.orientation.w = q.data()[3];

	initial_pose.position.x = FrameFeedback.X / 1000.0;
	initial_pose.position.y = FrameFeedback.Y / 1000.0;
	initial_pose.position.z = FrameFeedback.Z / 1000.0;

	target_pose.orientation.x = initial_pose.orientation.x;
	target_pose.orientation.y = initial_pose.orientation.y;
	target_pose.orientation.z = initial_pose.orientation.z;
	target_pose.orientation.w = initial_pose.orientation.w;

	double incrDistance = lineEdit_incrDistance->text().toDouble();
	int posCount = 0;
	// We iterate KUKA positions to obtain corresponding NDI positions
	for (int incrX = 0; incrX <= 1; incrX++) {
		for (int incrY = 0; incrY <= 1; incrY++) {
			for (int incrZ = 0; incrZ <= 1; incrZ++) {
				target_pose.position.x = initial_pose.position.x
						+ incrX * incrDistance / 1000.0;
				target_pose.position.y = initial_pose.position.y
						+ incrY * incrDistance / 1000.0;
				target_pose.position.z = initial_pose.position.z
						+ incrZ * incrDistance / 1000.0;

				int motion_return_value = PlanAndExecuteTargetMotion(
						target_pose, "tip");
				if (motion_return_value == MOTION_PLAN_EXECUTE) {
					ROS_INFO("Motion plan execute");
				} else if (motion_return_value == MOTION_PLAN_FAIL) {
					continue;
				} else {
					pushButton_CalculateNDIKUKATransform->setEnabled(true);
					dtGetDataTimer_->start(NDI_TIME_INTERVAL);
					return;
				}

				dtSubWindowWaitForExecution_.exec();

				// Obtain the current flange position of KUKA
				AxisFeedback = dtController_.getFeedbackAxis();
				dtLastAxis_.set(AxisFeedback);
				pdtPlannar_->getModel().Axis2Frame_flange(AxisFeedback,
						FrameFeedback);

				EulerAngleVector.data()[0] = FrameFeedback.A / 180.0 * M_PI;
				EulerAngleVector.data()[1] = FrameFeedback.B / 180.0 * M_PI;
				EulerAngleVector.data()[2] = FrameFeedback.C / 180.0 * M_PI;
				Translation[0] = FrameFeedback.X;
				Translation[1] = FrameFeedback.Y;
				Translation[2] = FrameFeedback.Z;
				RotationPart = createRotationMatrix(EulerAngleVector.data()[2],
						EulerAngleVector.data()[1], EulerAngleVector.data()[0]);
				TranslationPart = Eigen::Affine3d(
						Eigen::Translation3d(
								Eigen::Vector3d(Translation[0], Translation[1],
										Translation[2])));
				CurrentFlangeKUKATransform =
						(TranslationPart * RotationPart).matrix();

				// Transform the flange position to marker position
				CurrentMarkerKUKATransform = CurrentFlangeKUKATransform
						* MarkerFlangeTransform;
				vecdtKUKAPosition[posCount][0] =
						CurrentMarkerKUKATransform.coeff(0, 3);
				vecdtKUKAPosition[posCount][1] =
						CurrentMarkerKUKATransform.coeff(1, 3);
				vecdtKUKAPosition[posCount][2] =
						CurrentMarkerKUKATransform.coeff(2, 3);

				if (!getNDIFramesAverage(nMarker, -1, dtMarker, dtDummy, false,
				NDI_FRAME_COUNT)) {
					ROS_ERROR("Cannot get NDI Marker position data");
					continue;
				}

				vecdtNDIPosition[posCount][0] = dtMarker.dtTranslation.fTx;
				vecdtNDIPosition[posCount][1] = dtMarker.dtTranslation.fTy;
				vecdtNDIPosition[posCount][2] = dtMarker.dtTranslation.fTz;
				//TODO: This is for preventing the wrong NDI posiiton data
				if (vecdtNDIPosition[posCount][0] > 5000
						|| vecdtNDIPosition[posCount][1] > 5000
						|| vecdtNDIPosition[posCount][2] > 5000
						|| vecdtNDIPosition[posCount][0] < -5000
						|| vecdtNDIPosition[posCount][1] < -5000
						|| vecdtNDIPosition[posCount][2] < -5000) {
					ROS_ERROR("NDI measured data error");
					continue;
				}
				ROS_INFO("%dth KUKA position: %f, %f, %f", posCount + 1,
						vecdtKUKAPosition[posCount][0],
						vecdtKUKAPosition[posCount][1],
						vecdtKUKAPosition[posCount][2]);
				ROS_INFO("%dth NDI position: %f, %f, %f", posCount + 1,
						vecdtNDIPosition[posCount][0],
						vecdtNDIPosition[posCount][1],
						vecdtNDIPosition[posCount][2]);
				posCount++;
			}
		}
	}

	Eigen::Vector3d dtKUKAAveragePosition(0, 0, 0);
	Eigen::Vector3d dtNDIAveragePosition(0, 0, 0);

	for (int i = 0; i < posCount; i++) {
		dtKUKAAveragePosition += vecdtKUKAPosition[i];
		dtNDIAveragePosition += vecdtNDIPosition[i];
	}
	dtKUKAAveragePosition /= posCount;
	dtNDIAveragePosition /= posCount;

	Eigen::Matrix3d dtCovarianceMatrix;
	dtCovarianceMatrix = Eigen::Matrix3d::Zero();
	for (int i = 0; i < posCount; i++) {
		dtCovarianceMatrix += (vecdtKUKAPosition[i] - dtKUKAAveragePosition)
				* ((vecdtNDIPosition[i] - dtNDIAveragePosition).transpose());
	}
	dtCovarianceMatrix /= posCount;

	// Singular Value Decomposition A = U * S * V'
	Eigen::JacobiSVD<Eigen::MatrixXd> dtSVD(dtCovarianceMatrix,
			Eigen::ComputeFullU | Eigen::ComputeFullV);
	Eigen::Matrix3d dtU = dtSVD.matrixU();
	Eigen::Matrix3d dtV = dtSVD.matrixV();
	Eigen::Vector3d dtSingularValues = dtSVD.singularValues();

	Eigen::Matrix3d dtS;
	if (dtCovarianceMatrix.determinant() > 0) {
		dtS = Eigen::Matrix3d::Identity();
	} else if (dtCovarianceMatrix.determinant() < 0) {
		dtS = Eigen::Matrix3d::Identity();
		dtS.data()[8] = -1.0;
	} else {
		//Which means the rank is m-1
		if (dtU.determinant() * dtV.determinant() == 1) {
			dtS = Eigen::Matrix3d::Identity();
		} else {
			dtS = Eigen::Matrix3d::Identity();
			dtS.data()[8] = -1.0;
		}
	}

	// Derive rotation and translation result
	Eigen::Matrix3d dtRotationMatrix = dtU * dtS * dtV.transpose();
	Eigen::Vector3d dtTranslation = dtKUKAAveragePosition
			- dtRotationMatrix * dtNDIAveragePosition;

	dtNDIKUKARotationMatrix_ = dtRotationMatrix;
	dtNDIKUKATranslationVector_ = dtTranslation;

	ROS_INFO(
			"NDI to KUKA frame rotation matrix: \n%f, %f, %f \n%f, %f, %f \n%f, %f, %f\n",
			dtNDIKUKARotationMatrix_.data()[0],
			dtNDIKUKARotationMatrix_.data()[3],
			dtNDIKUKARotationMatrix_.data()[6],
			dtNDIKUKARotationMatrix_.data()[1],
			dtNDIKUKARotationMatrix_.data()[4],
			dtNDIKUKARotationMatrix_.data()[7],
			dtNDIKUKARotationMatrix_.data()[2],
			dtNDIKUKARotationMatrix_.data()[5],
			dtNDIKUKARotationMatrix_.data()[8]);

	ROS_INFO("NDI to KUKA frame translation vector: \n%f mm, %f mm, %f mm\n",
			dtNDIKUKATranslationVector_.data()[0],
			dtNDIKUKATranslationVector_.data()[1],
			dtNDIKUKATranslationVector_.data()[2]);

#else
	dtNDIKUKARotationMatrix_.data()[0] = 0.048885;
	dtNDIKUKARotationMatrix_.data()[1] = 0.116951;
	dtNDIKUKARotationMatrix_.data()[2] = -0.991934;
	dtNDIKUKARotationMatrix_.data()[3] = -0.934143;
	dtNDIKUKARotationMatrix_.data()[4] = 0.356877;
	dtNDIKUKARotationMatrix_.data()[5] = -0.003961;
	dtNDIKUKARotationMatrix_.data()[6] = 0.353535;
	dtNDIKUKARotationMatrix_.data()[7] = 0.926802;
	dtNDIKUKARotationMatrix_.data()[8] = 0.126695;

	/*0.048885, -0.934143, 0.353535
0.116951, 0.356877, 0.926802
-0.991934, -0.003961, 0.126695

836.268213 mm, 1160.435967 mm, 740.464462 mm
*/

	dtNDIKUKATranslationVector_.data()[0] = 836.268213;
	dtNDIKUKATranslationVector_.data()[1] = 1160.435967;
	dtNDIKUKATranslationVector_.data()[2] = 740.464462;

	/* [ INFO] [1464875668.418977364]: NDI and KUKA frame rotation matrix:
	 0.067906, -0.862463, 0.501543
	 0.105537, 0.506093, 0.855998
	 -0.992094, -0.005196, 0.125388

	 [ INFO] [1464875668.419024658]: NDI and KUKA frame translation vector:
	 1.055570 m, 1.155677 m, 0.717713 m */

#endif
	pushButton_CalculateNDIKUKATransform->setEnabled(true);
	pushButton_NDIFeedbackMove->setEnabled(true);
	dtGetDataTimer_->start(NDI_TIME_INTERVAL);
	ROS_INFO("Calculate NDI and KUKA Transform succeed");
	vecbCalibrationToDoList_[Interface::NDIKUKATransform] = true;
}
bool Interface::getNDIFramesAverage(int nMarker, int nIndicator,
		QuatTransformation& dtMarker, QuatTransformation& dtIndicator,
		bool bCalculateABC, int nMaxFramesCount) {

	int nFrameCount = 0, nValidFrameCount = 0;
	std::vector<QuatTransformation> vecdtIndicator(nMaxFramesCount),
			vecdtMarker(nMaxFramesCount);
	QuatTransformation dtMarkerInverse;

	KDL::Rotation dtRotation;
	Eigen::Vector3d IndicatorEulerAngleVector(Eigen::Vector3d::Zero()),
			MarkerEulerAngleVector(Eigen::Vector3d::Zero()),
			tempEulerAngleVector(Eigen::Vector3d::Zero());
	Eigen::Vector4d q;

	dtIndicator.dtTranslation.fTx = 0;
	dtIndicator.dtTranslation.fTy = 0;
	dtIndicator.dtTranslation.fTz = 0;

	dtMarker.dtTranslation.fTx = 0;
	dtMarker.dtTranslation.fTy = 0;
	dtMarker.dtTranslation.fTz = 0;

	while (nFrameCount < nMaxFramesCount) {

		ROS_INFO("Recording %d th frame", nFrameCount);

		if (!getSystemTransformData(false)) {
			ROS_ERROR("Cannot get tool position data");
			continue;
		}

		if (nIndicator != -1 && nMarker != -1) {
			if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
					== TRANSFORM_VALID
					&& pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
							== TRANSFORM_VALID) {

				vecdtIndicator[nFrameCount].dtTranslation =
						pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.dtTranslation;
				vecdtMarker[nFrameCount].dtTranslation =
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtTranslation;

				dtIndicator.dtTranslation.fTx +=
						vecdtIndicator[nFrameCount].dtTranslation.fTx;
				dtIndicator.dtTranslation.fTy +=
						vecdtIndicator[nFrameCount].dtTranslation.fTy;
				dtIndicator.dtTranslation.fTz +=
						vecdtIndicator[nFrameCount].dtTranslation.fTz;

				dtMarker.dtTranslation.fTx +=
						vecdtMarker[nFrameCount].dtTranslation.fTx;
				dtMarker.dtTranslation.fTy +=
						vecdtMarker[nFrameCount].dtTranslation.fTy;
				dtMarker.dtTranslation.fTz +=
						vecdtMarker[nFrameCount].dtTranslation.fTz;

				if (bCalculateABC) {
					vecdtIndicator[nFrameCount].dtRotation =
							pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.dtRotation;
					vecdtMarker[nFrameCount].dtRotation =
							pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtRotation;

					IndicatorEulerAngleVector += Quaternion2Euler(
							vecdtIndicator[nFrameCount].dtRotation.fQx,
							vecdtIndicator[nFrameCount].dtRotation.fQy,
							vecdtIndicator[nFrameCount].dtRotation.fQz,
							vecdtIndicator[nFrameCount].dtRotation.fQ0);
					MarkerEulerAngleVector += Quaternion2Euler(
							vecdtMarker[nFrameCount].dtRotation.fQx,
							vecdtMarker[nFrameCount].dtRotation.fQy,
							vecdtMarker[nFrameCount].dtRotation.fQz,
							vecdtMarker[nFrameCount].dtRotation.fQ0);
				}

				nFrameCount++;
				nValidFrameCount++;
			} else {
				ROS_ERROR("Tracking failed");
				nFrameCount++;
			}
		} else if (nIndicator == -1 && nMarker != -1) {
			if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
					== TRANSFORM_VALID) {

				vecdtMarker[nFrameCount].dtTranslation =
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtTranslation;

				dtMarker.dtTranslation.fTx +=
						vecdtMarker[nFrameCount].dtTranslation.fTx;
				dtMarker.dtTranslation.fTy +=
						vecdtMarker[nFrameCount].dtTranslation.fTy;
				dtMarker.dtTranslation.fTz +=
						vecdtMarker[nFrameCount].dtTranslation.fTz;

				if (bCalculateABC) {
					vecdtMarker[nFrameCount].dtRotation =
							pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtRotation;
					MarkerEulerAngleVector += Quaternion2Euler(
							vecdtMarker[nFrameCount].dtRotation.fQx,
							vecdtMarker[nFrameCount].dtRotation.fQy,
							vecdtMarker[nFrameCount].dtRotation.fQz,
							vecdtMarker[nFrameCount].dtRotation.fQ0);
				}

				nFrameCount++;
				nValidFrameCount++;
			} else {
				ROS_ERROR("Tracking failed");
				nFrameCount++;
			}
		} else if (nIndicator != -1 && nMarker == -1) {
			if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
					== TRANSFORM_VALID) {
				vecdtIndicator[nFrameCount].dtTranslation =
						pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.dtTranslation;

				dtIndicator.dtTranslation.fTx +=
						vecdtIndicator[nFrameCount].dtTranslation.fTx;
				dtIndicator.dtTranslation.fTy +=
						vecdtIndicator[nFrameCount].dtTranslation.fTy;
				dtIndicator.dtTranslation.fTz +=
						vecdtIndicator[nFrameCount].dtTranslation.fTz;

				if (bCalculateABC) {
					vecdtIndicator[nFrameCount].dtRotation =
							pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.dtRotation;
					IndicatorEulerAngleVector += Quaternion2Euler(
							vecdtIndicator[nFrameCount].dtRotation.fQx,
							vecdtIndicator[nFrameCount].dtRotation.fQy,
							vecdtIndicator[nFrameCount].dtRotation.fQz,
							vecdtIndicator[nFrameCount].dtRotation.fQ0);
				}
				nFrameCount++;
				nValidFrameCount++;
			} else {
				ROS_ERROR("Tracking failed");
				nFrameCount++;
			}
		} else {
			ROS_ERROR("nIndicator and nMarker cannot both be -1");
			return false;
		}

	}

	if (nValidFrameCount != 0) {

		if (nIndicator != -1) {
			dtIndicator.dtTranslation.fTx /= nValidFrameCount;
			dtIndicator.dtTranslation.fTy /= nValidFrameCount;
			dtIndicator.dtTranslation.fTz /= nValidFrameCount;

			IndicatorEulerAngleVector.data()[0] /= nValidFrameCount;
			IndicatorEulerAngleVector.data()[1] /= nValidFrameCount;
			IndicatorEulerAngleVector.data()[2] /= nValidFrameCount;

			if (bCalculateABC) {
				q = Euler2Quaternion(IndicatorEulerAngleVector.data()[2],
						IndicatorEulerAngleVector.data()[1],
						IndicatorEulerAngleVector.data()[0]);
				dtIndicator.dtRotation.fQ0 = q.data()[0];
				dtIndicator.dtRotation.fQx = q.data()[1];
				dtIndicator.dtRotation.fQy = q.data()[2];
				dtIndicator.dtRotation.fQz = q.data()[3];
			}
		}

		if (nMarker != -1) {
			dtMarker.dtTranslation.fTx /= nValidFrameCount;
			dtMarker.dtTranslation.fTy /= nValidFrameCount;
			dtMarker.dtTranslation.fTz /= nValidFrameCount;

			MarkerEulerAngleVector.data()[0] /= nValidFrameCount;
			MarkerEulerAngleVector.data()[1] /= nValidFrameCount;
			MarkerEulerAngleVector.data()[2] /= nValidFrameCount;

			if (bCalculateABC) {
				q = Euler2Quaternion(MarkerEulerAngleVector.data()[2],
						MarkerEulerAngleVector.data()[1],
						MarkerEulerAngleVector.data()[0]);
				dtMarker.dtRotation.fQ0 = q.data()[3];
				dtMarker.dtRotation.fQx = q.data()[0];
				dtMarker.dtRotation.fQy = q.data()[1];
				dtMarker.dtRotation.fQz = q.data()[2];
			}
		}

		return true;
	} else {
		ROS_ERROR("Recorded no tool position data");
		return false;
	}

}
void Interface::calculateTCPMarkerTransform() {

#ifndef USE_FIXED_TCP_MARKER_TRANSFORM
	dtGetDataTimer_->stop();

	int nMarker = ASCIIToHex(
			(char*) (comboBox_Marker->currentText().toStdString().c_str()), 2);
	int nIndicator = ASCIIToHex(
			(char*) (comboBox_Indicator->currentText().toStdString().c_str()),
			2);

	QuatTransformation dtDummy, dtIndicator, dtMarker, dtMarkerInverse;
	std::vector<Eigen::Vector3d> TCPNDITranslation(3);
	std::vector<Eigen::Vector3d> TCPNDIRotationColumn(3);
	Eigen::Matrix3d TCPNDIRotation;
	Eigen::Matrix3d MarkerNDIRotation;
	Eigen::Vector3d ToolUnitX, ToolUnitC, ToolUnitY, ToolUnitZ;

	const int ndi_frame_count = 60;
// Translation part of TCP Marker Transform
	//obtain the point of TCP
	ROS_INFO("Please indicate the point of TCP");
	bool bTracking = false;
	do {
		dtSubWindowWaitForIndicatorPlaced_.exec();
		getSystemTransformData(false);
		if (dtSubWindowWaitForIndicatorPlaced_.nReturnValue_ == INDICATOR_OK) {
			if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
					!= TRANSFORM_VALID
					|| pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
					!= TRANSFORM_VALID) {
				ROS_ERROR("NDI failed to track Marker or Point Indicator");
				bTracking = false;
			} else {
				bTracking = true;
			}
		} else {
			ROS_INFO("TCP Marker Transform calculation canceled");
			dtGetDataTimer_->start(NDI_TIME_INTERVAL);
			pushButton_CalculateTCPMarkerTransform->setEnabled(true);
			return;
		}
	}while (!bTracking);

	if (!getNDIFramesAverage(nMarker, nIndicator, dtMarker, dtIndicator, true,
					ndi_frame_count)) {
		ROS_ERROR("Cannot get tool position data");
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		pushButton_CalculateTCPMarkerTransform->setEnabled(true);
		return;
	}
	MarkerNDIRotation = createRotationMatrix(dtMarker.dtRotation.fQx,
			dtMarker.dtRotation.fQy, dtMarker.dtRotation.fQz,
			dtMarker.dtRotation.fQ0);

	dtIndicator.dtRotation =
	pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtRotation;
	dtMarker.dtRotation =
	pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtRotation;

	QuatInverseXfrm(&dtMarker, &dtMarkerInverse);
	QuatCombineXfrms(&dtIndicator, &dtMarkerInverse, &dtTCPMarkerTransform_);

	dtTCPMarkerTranslationVector_.data()[0] =
	dtTCPMarkerTransform_.dtTranslation.fTx;
	dtTCPMarkerTranslationVector_.data()[1] =
	dtTCPMarkerTransform_.dtTranslation.fTy;
	dtTCPMarkerTranslationVector_.data()[2] =
	dtTCPMarkerTransform_.dtTranslation.fTz;

	TCPNDITranslation[0].data()[0] = dtIndicator.dtTranslation.fTx;
	TCPNDITranslation[0].data()[1] = dtIndicator.dtTranslation.fTy;
	TCPNDITranslation[0].data()[2] = dtIndicator.dtTranslation.fTz;

// Rotation part of TCP Marker Transform
	//Obtain a point on needle x direction
	ROS_INFO("Please indicate a point on the x direction of the needle");
	bTracking = false;
	do {
		dtSubWindowWaitForIndicatorPlaced_.exec();
		getSystemTransformData(false);
		if (dtSubWindowWaitForIndicatorPlaced_.nReturnValue_ == INDICATOR_OK) {
			if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
					!= TRANSFORM_VALID) {
				ROS_ERROR("NDI failed to track Point Indicator");
				bTracking = false;
			} else {
				bTracking = true;
			}
		} else {
			ROS_INFO("TCP Marker Transform calculation canceled");
			dtGetDataTimer_->start(NDI_TIME_INTERVAL);
			pushButton_CalculateTCPMarkerTransform->setEnabled(true);
			return;
		}
	}while (!bTracking);

	if (!getNDIFramesAverage(-1, nIndicator, dtDummy, dtIndicator, false,
					ndi_frame_count)) {
		ROS_ERROR("Cannot get tool position data");
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		pushButton_CalculateTCPMarkerTransform->setEnabled(true);
		return;
	}

	TCPNDITranslation[1].data()[0] = dtIndicator.dtTranslation.fTx;
	TCPNDITranslation[1].data()[1] = dtIndicator.dtTranslation.fTy;
	TCPNDITranslation[1].data()[2] = dtIndicator.dtTranslation.fTz;

	double delta_x1 = (TCPNDITranslation[1] - TCPNDITranslation[0]).norm();
	TCPNDIRotationColumn[0] = (TCPNDITranslation[1] - TCPNDITranslation[0])
	/ delta_x1;
	TCPNDIRotationColumn[0].normalize();
	ToolUnitX = TCPNDIRotationColumn[0];

	//Obtain a point on needle x-y plane
	ROS_INFO("Please indicate a point on the x-y direction of the needle");
	bTracking = false;
	do {
		dtSubWindowWaitForIndicatorPlaced_.exec();
		getSystemTransformData(false);
		if (dtSubWindowWaitForIndicatorPlaced_.nReturnValue_ == INDICATOR_OK) {
			if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
					!= TRANSFORM_VALID) {
				ROS_ERROR("NDI failed to track Point Indicator");
				bTracking = false;
			} else {
				bTracking = true;
			}
		} else {
			ROS_INFO("TCP Marker Transform calculation canceled");
			dtGetDataTimer_->start(NDI_TIME_INTERVAL);
			pushButton_CalculateTCPMarkerTransform->setEnabled(true);
			return;
		}
	}while (!bTracking);

	if (!getNDIFramesAverage(-1, nIndicator, dtDummy, dtIndicator, false,
					NDI_FRAME_COUNT)) {
		ROS_ERROR("Cannot get tool position data");
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		pushButton_CalculateTCPMarkerTransform->setEnabled(true);
		return;
	}
	TCPNDITranslation[2].data()[0] = dtIndicator.dtTranslation.fTx;
	TCPNDITranslation[2].data()[1] = dtIndicator.dtTranslation.fTy;
	TCPNDITranslation[2].data()[2] = dtIndicator.dtTranslation.fTz;

	ToolUnitC = (TCPNDITranslation[2] - TCPNDITranslation[0])
	/ (TCPNDITranslation[2] - TCPNDITranslation[0]).norm();
	ToolUnitY = ToolUnitC - ToolUnitC.dot(ToolUnitX) * ToolUnitX;
	ToolUnitY.normalize();

	double delta_y2 = (TCPNDITranslation[2] - TCPNDITranslation[0]).dot(
			ToolUnitY);
	double delta_x2 = sqrt(
			((TCPNDITranslation[2] - TCPNDITranslation[0]).norm()
					* (TCPNDITranslation[2] - TCPNDITranslation[0]).norm())
			- delta_y2 * delta_y2);

	TCPNDIRotationColumn[1] = (((TCPNDITranslation[2] - TCPNDITranslation[0])
					- delta_x2 * TCPNDIRotationColumn[0]) / delta_y2);
	TCPNDIRotationColumn[1].normalize();
	TCPNDIRotationColumn[2] = TCPNDIRotationColumn[0].cross(
			TCPNDIRotationColumn[1]);
	TCPNDIRotationColumn[2].normalize();
	TCPNDIRotation.col(0) = TCPNDIRotationColumn[0];
	TCPNDIRotation.col(1) = TCPNDIRotationColumn[1];
	TCPNDIRotation.col(2) = TCPNDIRotationColumn[2];
	dtTCPMarkerRotationMatrix_ = MarkerNDIRotation.inverse() * TCPNDIRotation;

	ROS_INFO(
			"TCP to Marker rotation matrix: \n%f, %f, %f \n%f, %f, %f \n%f, %f, %f\n\n",
			dtTCPMarkerRotationMatrix_.data()[0],
			dtTCPMarkerRotationMatrix_.data()[3],
			dtTCPMarkerRotationMatrix_.data()[6],
			dtTCPMarkerRotationMatrix_.data()[1],
			dtTCPMarkerRotationMatrix_.data()[4],
			dtTCPMarkerRotationMatrix_.data()[7],
			dtTCPMarkerRotationMatrix_.data()[2],
			dtTCPMarkerRotationMatrix_.data()[5],
			dtTCPMarkerRotationMatrix_.data()[8]);

	Eigen::Vector3d EulerAngle_NDI = dtTCPMarkerRotationMatrix_.eulerAngles(2,
			1, 0);
	Eigen::Vector4d q = Euler2Quaternion(EulerAngle_NDI.data()[2],
			EulerAngle_NDI.data()[1], EulerAngle_NDI.data()[0]);
	dtTCPMarkerTransform_.dtRotation.fQx = q.data()[0];
	dtTCPMarkerTransform_.dtRotation.fQy = q.data()[1];
	dtTCPMarkerTransform_.dtRotation.fQz = q.data()[2];
	dtTCPMarkerTransform_.dtRotation.fQ0 = q.data()[3];

	// Use the needle tip to Marker Translation
	// instead of the exit point of needle holder to Marker Translation
	dtTCPMarkerTranslationVector_.data()[0] = 18.70;
	dtTCPMarkerTranslationVector_.data()[1] = -162.73;
	dtTCPMarkerTranslationVector_.data()[2] = 245.85;
	dtTCPMarkerTransform_.dtTranslation.fTx = 18.70;
	dtTCPMarkerTransform_.dtTranslation.fTy = -162.73;
	dtTCPMarkerTransform_.dtTranslation.fTz = 245.85;

	ROS_INFO("TCP to Marker Translation: X %f mm, Y %f mm, Z %f mm",
			dtTCPMarkerTransform_.dtTranslation.fTx,
			dtTCPMarkerTransform_.dtTranslation.fTy,
			dtTCPMarkerTransform_.dtTranslation.fTz);

#else
	// TODO: This field is measured using pivoting method of NDI
	// This should be obtained using pivoting method for test only
	// In future, this one should also be obtained by semi-automatic method
//Translation part
	dtTCPMarkerTranslationVector_.data()[0] = 18.70;
	dtTCPMarkerTranslationVector_.data()[1] = -162.73;
	dtTCPMarkerTranslationVector_.data()[2] = 245.85;

	dtTCPMarkerTransform_.dtTranslation.fTx = 18.70;
	dtTCPMarkerTransform_.dtTranslation.fTy = -162.73;
	dtTCPMarkerTransform_.dtTranslation.fTz = 245.85;
//Rotation part

	dtTCPMarkerRotationMatrix_.data()[0] = 0.025170;
	dtTCPMarkerRotationMatrix_.data()[1] = 0.416873;
	dtTCPMarkerRotationMatrix_.data()[2] = -0.908616;
	dtTCPMarkerRotationMatrix_.data()[3] = -0.714938;
	dtTCPMarkerRotationMatrix_.data()[4] = 0.642790;
	dtTCPMarkerRotationMatrix_.data()[5] = 0.275107;
	dtTCPMarkerRotationMatrix_.data()[6] = 0.698734;
	dtTCPMarkerRotationMatrix_.data()[7] = 0.642680;
	dtTCPMarkerRotationMatrix_.data()[8] = 0.314218;

	Eigen::Vector3d EulerAngle_NDI = dtTCPMarkerRotationMatrix_.eulerAngles(2,
			1, 0);
	Eigen::Vector4d q = Euler2Quaternion(EulerAngle_NDI.data()[2],
			EulerAngle_NDI.data()[1], EulerAngle_NDI.data()[0]);
	dtTCPMarkerTransform_.dtRotation.fQx = q.data()[0];
	dtTCPMarkerTransform_.dtRotation.fQy = q.data()[1];
	dtTCPMarkerTransform_.dtRotation.fQz = q.data()[2];
	dtTCPMarkerTransform_.dtRotation.fQ0 = q.data()[3];

	/* -0.688046, -0.140105, -0.712013
	 0.667092, -0.508313, -0.544615
	 -0.285622, -0.849699, 0.443206

	 dtTCPMarkerRotationMatrix_.data()[0] = -0.081698;
	 dtTCPMarkerRotationMatrix_.data()[1] = -0.626926;
	 dtTCPMarkerRotationMatrix_.data()[2] = 0.774784;
	 dtTCPMarkerRotationMatrix_.data()[3] = 0.476683;
	 dtTCPMarkerRotationMatrix_.data()[4] = 0.658123;
	 dtTCPMarkerRotationMatrix_.data()[5] = 0.582792;
	 dtTCPMarkerRotationMatrix_.data()[6] = -0.875271;
	 dtTCPMarkerRotationMatrix_.data()[7] = 0.416939;
	 dtTCPMarkerRotationMatrix_.data()[8] = 0.245078;

	 0.025170, -0.714938, 0.698734
	 0.416873, 0.642790, 0.642680
	 -0.908616, 0.275107, 0.314218
	 */

	/*dtTCPMarkerRotationMatrix_.data()[0] = -0.688046;
	 dtTCPMarkerRotationMatrix_.data()[1] = 0.667092;
	 dtTCPMarkerRotationMatrix_.data()[2] = -0.285622;
	 dtTCPMarkerRotationMatrix_.data()[3] = -0.140105;
	 dtTCPMarkerRotationMatrix_.data()[4] = -0.508313;
	 dtTCPMarkerRotationMatrix_.data()[5] = -0.849699;
	 dtTCPMarkerRotationMatrix_.data()[6] = -0.712013;
	 dtTCPMarkerRotationMatrix_.data()[7] = -0.544615;
	 dtTCPMarkerRotationMatrix_.data()[8] = 0.443206; */

#endif

	dtGetDataTimer_->start(NDI_TIME_INTERVAL);
	pushButton_CalculateTCPMarkerTransform->setEnabled(true);
	pushButton_CalculateTCPFlangeRotation->setEnabled(true);
	checkBox_UseTCPMarkerTransform->setEnabled(true);
	ROS_INFO("Calculate TCP to Marker Transform succeed");

	vecbCalibrationToDoList_[Interface::TCPMarkerTransform] = true;
}
bool Interface::ndiFeedbackParallelMove() {
	// TODO: After calibration, we need to change URDF file to save these settings
	if (lineEdit_NDI_X->text().isEmpty() || lineEdit_NDI_Y->text().isEmpty()
			|| lineEdit_NDI_Z->text().isEmpty()
			|| lineEdit_KUKA_A->text().isEmpty()
			|| lineEdit_KUKA_B->text().isEmpty()
			|| lineEdit_KUKA_C->text().isEmpty()) {
		ROS_ERROR("value of the reference point is empty");
		return false;
	}

	if (output_x->toPlainText().isEmpty() || output_y->toPlainText().isEmpty()
			|| output_z->toPlainText().isEmpty()
			|| output_a->toPlainText().isEmpty()
			|| output_b->toPlainText().isEmpty()
			|| output_c->toPlainText().isEmpty()) {
		ROS_ERROR("KUKA feedback value is empty");
		return false;
	}

	int nMarker = ASCIIToHex(
			(char*) (comboBox_Marker->currentText().toStdString().c_str()), 2);
	int nIndicator = ASCIIToHex(
			(char*) (comboBox_Indicator->currentText().toStdString().c_str()),
			2);
	if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
			!= TRANSFORM_VALID) {
		ROS_ERROR("NDI failed to track Marker");
		return false;
	}

	if (!vecbCalibrationToDoList_[Interface::NDIKUKARotation]) {
		ROS_ERROR(
				"Calibration prerequisite is not complete for NDI Feedback Parallel Move");
		return false;
	}

	pushButton_NDIFeedbackParallelMove->setEnabled(false);
	dtGetDataTimer_->stop();

	Axis AxisFeedback;
	Frame FrameFeedback;

	std::vector<double> NDI_reference_point(6);
	std::vector<double> KUKA_position(3);

	Eigen::Vector3d NDI_delta_position;
	Eigen::Vector3d KUKA_delta_position;

	geometry_msgs::Pose target_pose;
	Eigen::Vector3d EulerAngleVector;
	Eigen::Vector4d q;
	QuatTransformation dtMarker, dtDummy;

// Pos for reference point in NDI frame
	NDI_reference_point[0] = lineEdit_NDI_X->text().toDouble();
	NDI_reference_point[1] = lineEdit_NDI_Y->text().toDouble();
	NDI_reference_point[2] = lineEdit_NDI_Z->text().toDouble();
	NDI_reference_point[3] = lineEdit_KUKA_A->text().toDouble() / 180.0 * M_PI;
	NDI_reference_point[4] = lineEdit_KUKA_B->text().toDouble() / 180.0 * M_PI;
	NDI_reference_point[5] = lineEdit_KUKA_C->text().toDouble() / 180.0 * M_PI;

// Rotate KUKA to specified ABC pos
	EulerAngleVector.data()[0] = NDI_reference_point[3];
	EulerAngleVector.data()[1] = NDI_reference_point[4];
	EulerAngleVector.data()[2] = NDI_reference_point[5];

	q = Euler2Quaternion(EulerAngleVector.data()[2], EulerAngleVector.data()[1],
			EulerAngleVector.data()[0]);
	target_pose.orientation.x = q.data()[0];
	target_pose.orientation.y = q.data()[1];
	target_pose.orientation.z = q.data()[2];
	target_pose.orientation.w = q.data()[3];

	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);
	target_pose.position.x = FrameFeedback.X / 1000.0;
	target_pose.position.y = FrameFeedback.Y / 1000.0;
	target_pose.position.z = FrameFeedback.Z / 1000.0;

	int motion_return_value = PlanAndExecuteTargetMotion(target_pose, "tip");
	if (motion_return_value == MOTION_PLAN_EXECUTE) {
		ROS_INFO("Motion plan execute");
	} else {
		pushButton_NDIFeedbackParallelMove->setEnabled(true);
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		return false;
	}

	dtSubWindowWaitForExecution_.exec();
// Then move KUKA to specified XYZ reference point in NDI frame
	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);
	EulerAngleVector.data()[0] = FrameFeedback.A / 180.0 * M_PI;
	EulerAngleVector.data()[1] = FrameFeedback.B / 180.0 * M_PI;
	EulerAngleVector.data()[2] = FrameFeedback.C / 180.0 * M_PI;

	q = Euler2Quaternion(EulerAngleVector.data()[2], EulerAngleVector.data()[1],
			EulerAngleVector.data()[0]);
	target_pose.orientation.x = q.data()[0];
	target_pose.orientation.y = q.data()[1];
	target_pose.orientation.z = q.data()[2];
	target_pose.orientation.w = q.data()[3];

	if (!getNDIFramesAverage(nMarker, -1, dtMarker, dtDummy, false,
	NDI_FRAME_COUNT)) {
		ROS_ERROR("Cannot get tool position data");
		pushButton_NDIFeedbackParallelMove->setEnabled(true);
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		return false;
	}

	NDI_delta_position.data()[0] = NDI_reference_point[0]
			- dtMarker.dtTranslation.fTx;
	NDI_delta_position.data()[1] = NDI_reference_point[1]
			- dtMarker.dtTranslation.fTy;
	NDI_delta_position.data()[2] = NDI_reference_point[2]
			- dtMarker.dtTranslation.fTz;

	KUKA_delta_position = dtNDIKUKARotationMatrix_ * NDI_delta_position;
	ROS_INFO("Delta NDI position: %f, %f, %f", NDI_delta_position.data()[0],
			NDI_delta_position.data()[1], NDI_delta_position.data()[2]);
	ROS_INFO("Delta KUKA position: %f, %f, %f", KUKA_delta_position.data()[0],
			KUKA_delta_position.data()[1], KUKA_delta_position.data()[2]);

	int nIterationCount = 0;
	std::vector<double> distance_error(2, 0);

	while (sqrt(
			NDI_delta_position.data()[0] * NDI_delta_position.data()[0]
					+ NDI_delta_position.data()[1]
							* NDI_delta_position.data()[1]
					+ NDI_delta_position.data()[2]
							* NDI_delta_position.data()[2])
			> dParallelMoveThreshold_) {

		AxisFeedback = dtController_.getFeedbackAxis();
		dtLastAxis_.set(AxisFeedback);
		pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);
		target_pose.position.x = (FrameFeedback.X
				+ KUKA_delta_position.data()[0]) / 1000.0;
		target_pose.position.y = (FrameFeedback.Y
				+ KUKA_delta_position.data()[1]) / 1000.0;
		target_pose.position.z = (FrameFeedback.Z
				+ KUKA_delta_position.data()[2]) / 1000.0;

		motion_return_value = PlanAndExecuteTargetMotion(target_pose, "tip");
		if (motion_return_value == MOTION_PLAN_EXECUTE) {
			ROS_INFO("Motion plan execute");
		} else {
			pushButton_NDIFeedbackParallelMove->setEnabled(true);
			dtGetDataTimer_->start(NDI_TIME_INTERVAL);
			dParallelMoveThreshold_ = MINIMUM_PARALLEL_MOVE_THRESHOLD;
			return false;
		}

		dtSubWindowWaitForExecution_.exec();

		if (!getNDIFramesAverage(nMarker, -1, dtMarker, dtDummy, false,
		NDI_FRAME_COUNT)) {
			ROS_ERROR("Cannot get tool position data");
			pushButton_NDIFeedbackParallelMove->setEnabled(true);
			dtGetDataTimer_->start(NDI_TIME_INTERVAL);
			dParallelMoveThreshold_ = MINIMUM_PARALLEL_MOVE_THRESHOLD;
			return false;
		}

		NDI_delta_position.data()[0] = NDI_reference_point[0]
				- dtMarker.dtTranslation.fTx;
		NDI_delta_position.data()[1] = NDI_reference_point[1]
				- dtMarker.dtTranslation.fTy;
		NDI_delta_position.data()[2] = NDI_reference_point[2]
				- dtMarker.dtTranslation.fTz;

		KUKA_delta_position = dtNDIKUKARotationMatrix_ * NDI_delta_position;

		ROS_INFO("Delta NDI position: %f, %f, %f", NDI_delta_position.data()[0],
				NDI_delta_position.data()[1], NDI_delta_position.data()[2]);
		ROS_INFO("Delta KUKA position: %f, %f, %f",
				KUKA_delta_position.data()[0], KUKA_delta_position.data()[1],
				KUKA_delta_position.data()[2]);



		// If the distance error is still going down, don't count the iteration.
		// Count the iteration only when the distance error starts to diverge
		distance_error[0] = distance_error[1];
		distance_error[1] = sqrt(
				NDI_delta_position.data()[0]
						* NDI_delta_position.data()[0]
						+ NDI_delta_position.data()[1]
								* NDI_delta_position.data()[1]
						+ NDI_delta_position.data()[2]
								* NDI_delta_position.data()[2]);
		ROS_INFO("NDI measured error: %f mm", distance_error[1]);
		// To check whether the last distance error exists
		if(distance_error[0] != 0 && distance_error[1] - distance_error[0] > 0) {
			nIterationCount++;
		}

		if(nIterationCount >= 4) {
			dParallelMoveThreshold_ += 0.05;
			nIterationCount = 0;
			ROS_INFO("Threshold changed to %f", dParallelMoveThreshold_);
		}

	}

	dtGetDataTimer_->start(NDI_TIME_INTERVAL);
	pushButton_NDIFeedbackParallelMove->setEnabled(true);
	dParallelMoveThreshold_ = MINIMUM_PARALLEL_MOVE_THRESHOLD;
	ROS_INFO("NDI Feedback Move succeed");
	return true;
}
//Calculate robotation matrix between NDI frame and KUKA frame
void Interface::calculateRotationMatrix() {

#ifndef USE_FIXED_NDI_KUKA_ROTATION
	if (output_x->toPlainText().isEmpty() || output_y->toPlainText().isEmpty()
			|| output_z->toPlainText().isEmpty()) {
		ROS_ERROR("KUKA feedback value is empty");
		return;
	}
	if (lineEdit_dX->text().isEmpty() || lineEdit_dY->text().isEmpty()
			|| lineEdit_dZ->text().isEmpty()) {
		ROS_ERROR("value of the delta pos is empty");
		return;
	}

	int nMarker = ASCIIToHex(
			(char*) (comboBox_Marker->currentText().toStdString().c_str()), 2);
	int nIndicator = ASCIIToHex(
			(char*) (comboBox_Indicator->currentText().toStdString().c_str()),
			2);
	if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
			!= TRANSFORM_VALID) {
		ROS_ERROR("NDI failed to track Marker");
		return;
	}

	pushButton_CalculateNDIKUKARotation->setEnabled(false);
	dtGetDataTimer_->stop();

	Axis AxisFeedback;
	Frame FrameFeedback;

	// move x, y, z independently so that we could calculate each column of the rotation matrix separately
	std::vector<double> Kuka_position_x(4), Kuka_position_y(4), Kuka_position_z(
			4);
	std::vector<double> NDI_position_x(4), NDI_position_y(4), NDI_position_z(4);

	geometry_msgs::Pose target_pose;
	Eigen::Vector3d EulerAngleVector;
	Eigen::Vector4d q;

	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);
	Kuka_position_x[0] = FrameFeedback.X;
	Kuka_position_y[0] = FrameFeedback.Y;
	Kuka_position_z[0] = FrameFeedback.Z;
	EulerAngleVector.data()[0] = FrameFeedback.A / 180.0 * M_PI;
	EulerAngleVector.data()[1] = FrameFeedback.B / 180.0 * M_PI;
	EulerAngleVector.data()[2] = FrameFeedback.C / 180.0 * M_PI;
	q = Euler2Quaternion(EulerAngleVector.data()[2], EulerAngleVector.data()[1],
			EulerAngleVector.data()[0]);
	target_pose.orientation.x = q.data()[0];
	target_pose.orientation.y = q.data()[1];
	target_pose.orientation.z = q.data()[2];
	target_pose.orientation.w = q.data()[3];

	QuatTransformation dtMarker, dtDummy;
	if (!getNDIFramesAverage(nMarker, -1, dtMarker, dtDummy, false,
					NDI_FRAME_COUNT)) {
		ROS_ERROR("Cannot get tool position data");
		pushButton_CalculateNDIKUKARotation->setEnabled(true);
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		return;
	}
	NDI_position_x[0] = dtMarker.dtTranslation.fTx;
	NDI_position_y[0] = dtMarker.dtTranslation.fTy;
	NDI_position_z[0] = dtMarker.dtTranslation.fTz;

	// --------------------------------------------------------
	// Pose 1
	// --------------------------------------------------------
	target_pose.position.x = (Kuka_position_x[0]
			+ lineEdit_dX->text().toDouble()) / 1000.0;
	target_pose.position.y = Kuka_position_y[0] / 1000.0;
	target_pose.position.z = Kuka_position_z[0] / 1000.0;

	int motion_return_value = PlanAndExecuteTargetMotion(target_pose, "tip");
	if (motion_return_value == MOTION_PLAN_EXECUTE) {
		ROS_INFO("Motion plan execute");
	} else {
		pushButton_CalculateNDIKUKARotation->setEnabled(true);
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		return;
	}

	dtSubWindowWaitForExecution_.exec();
	// Derive NDI position
	if (!getNDIFramesAverage(nMarker, -1, dtMarker, dtDummy, false,
					NDI_FRAME_COUNT)) {
		ROS_ERROR("Cannot get tool position data");
		pushButton_CalculateNDIKUKARotation->setEnabled(true);
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		return;
	}
	// Derive KUKA position
	NDI_position_x[1] = dtMarker.dtTranslation.fTx;
	NDI_position_y[1] = dtMarker.dtTranslation.fTy;
	NDI_position_z[1] = dtMarker.dtTranslation.fTz;

	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);
	Kuka_position_x[1] = FrameFeedback.X;
	Kuka_position_y[1] = FrameFeedback.Y;
	Kuka_position_z[1] = FrameFeedback.Z;
	// --------------------------------------------------------
	// Pose 2
	// --------------------------------------------------------
	target_pose.position.x = Kuka_position_x[0] / 1000.0;
	target_pose.position.y = (Kuka_position_y[0]
			+ lineEdit_dY->text().toDouble()) / 1000.0;
	target_pose.position.z = Kuka_position_z[0] / 1000.0;

	motion_return_value = PlanAndExecuteTargetMotion(target_pose, "tip");
	if (motion_return_value == MOTION_PLAN_EXECUTE) {
		ROS_INFO("Motion plan execute");
	} else {
		pushButton_CalculateNDIKUKARotation->setEnabled(true);
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		return;
	}

	dtSubWindowWaitForExecution_.exec();

	if (!getNDIFramesAverage(nMarker, -1, dtMarker, dtDummy, false,
					NDI_FRAME_COUNT)) {
		ROS_ERROR("Cannot get tool position data");
		pushButton_CalculateNDIKUKARotation->setEnabled(true);
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		return;
	}
	NDI_position_x[2] = dtMarker.dtTranslation.fTx;
	NDI_position_y[2] = dtMarker.dtTranslation.fTy;
	NDI_position_z[2] = dtMarker.dtTranslation.fTz;

	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);
	Kuka_position_x[2] = FrameFeedback.X;
	Kuka_position_y[2] = FrameFeedback.Y;
	Kuka_position_z[2] = FrameFeedback.Z;
	// --------------------------------------------------------
	// Pose 3
	// --------------------------------------------------------
	target_pose.position.x = Kuka_position_x[0] / 1000.0;
	target_pose.position.y = Kuka_position_y[0] / 1000.0;
	target_pose.position.z = (Kuka_position_z[0]
			+ lineEdit_dZ->text().toDouble()) / 1000.0;

	motion_return_value = PlanAndExecuteTargetMotion(target_pose, "tip");
	if (motion_return_value == MOTION_PLAN_EXECUTE) {
		ROS_INFO("Motion plan execute");
	} else {
		pushButton_CalculateNDIKUKARotation->setEnabled(true);
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		return;
	}

	dtSubWindowWaitForExecution_.exec();

	if (!getNDIFramesAverage(nMarker, -1, dtMarker, dtDummy, false,
					NDI_FRAME_COUNT)) {
		ROS_ERROR("Cannot get tool position data");
		pushButton_CalculateNDIKUKARotation->setEnabled(true);
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		return;
	}
	NDI_position_x[3] = dtMarker.dtTranslation.fTx;
	NDI_position_y[3] = dtMarker.dtTranslation.fTy;
	NDI_position_z[3] = dtMarker.dtTranslation.fTz;

	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);
	Kuka_position_x[3] = FrameFeedback.X;
	Kuka_position_y[3] = FrameFeedback.Y;
	Kuka_position_z[3] = FrameFeedback.Z;

	std::vector<Eigen::Vector3d> delta_NDI_position(6);
	std::vector<Eigen::Vector3d> delta_KUKA_position(6);
	Eigen::Matrix3d Temp1(Eigen::Matrix3d::Zero()), Temp2(
			Eigen::Matrix3d::Zero()), RotationMatrix;

	int nPairCount = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j <= 3; j++) {
			delta_NDI_position[nPairCount].data()[0] = NDI_position_x[j]
			- NDI_position_x[i];
			delta_NDI_position[nPairCount].data()[1] = NDI_position_y[j]
			- NDI_position_y[i];
			delta_NDI_position[nPairCount].data()[2] = NDI_position_z[j]
			- NDI_position_z[i];
			delta_KUKA_position[nPairCount].data()[0] = Kuka_position_x[j]
			- Kuka_position_x[i];
			delta_KUKA_position[nPairCount].data()[1] = Kuka_position_y[j]
			- Kuka_position_y[i];
			delta_KUKA_position[nPairCount].data()[2] = Kuka_position_z[j]
			- Kuka_position_z[i];
			nPairCount++;
		}
	}

	for (int i = 0; i < 6; i++) {
		Temp1 += delta_NDI_position[i] * delta_KUKA_position[i].transpose();
		Temp2 += delta_KUKA_position[i] * delta_KUKA_position[i].transpose();
	}

	//RotationMatrix is KUKA to NDI Rotation, we need to transpose it to assign it to dtNDIKUKARotatioMatrix
	RotationMatrix = Temp1 * Temp2.inverse();
	RotationMatrix.transposeInPlace();

	for (int i = 0; i < 9; i++) {
		dtNDIKUKARotationMatrix_.data()[i] = RotationMatrix.data()[i];
	}
	ROS_INFO(
			"NDI and KUKA frame rotation matrix: \n%f, %f, %f \n%f, %f, %f \n%f, %f, %f\n\n",
			dtNDIKUKARotationMatrix_.data()[0],
			dtNDIKUKARotationMatrix_.data()[3],
			dtNDIKUKARotationMatrix_.data()[6],
			dtNDIKUKARotationMatrix_.data()[1],
			dtNDIKUKARotationMatrix_.data()[4],
			dtNDIKUKARotationMatrix_.data()[7],
			dtNDIKUKARotationMatrix_.data()[2],
			dtNDIKUKARotationMatrix_.data()[5],
			dtNDIKUKARotationMatrix_.data()[8]);

	dtGetDataTimer_->start(NDI_TIME_INTERVAL);
#else
	dtNDIKUKARotationMatrix_.data()[0] = 0.050280;
	dtNDIKUKARotationMatrix_.data()[1] = 0.134701;
	dtNDIKUKARotationMatrix_.data()[2] = -0.992092;
	dtNDIKUKARotationMatrix_.data()[3] = -0.937355;
	dtNDIKUKARotationMatrix_.data()[4] = 0.391280;
	dtNDIKUKARotationMatrix_.data()[5] = 0.002654;
	dtNDIKUKARotationMatrix_.data()[6] = 0.353481;
	dtNDIKUKARotationMatrix_.data()[7] = 0.877706;
	dtNDIKUKARotationMatrix_.data()[8] = 0.115206;

	/*0.050280, -0.937355, 0.353481
	 0.134701, 0.391280, 0.877706
	 -0.992092, 0.002654, 0.115206
	 * */

	/* 0.069839, -0.864405, 0.506806
	 0.105046, 0.504057, 0.856554
	 -0.993359, -0.006206, 0.121104
	 * */
#endif
	pushButton_CalculateNDIKUKARotation->setEnabled(true);
	pushButton_NDIFeedbackParallelMove->setEnabled(true);
	pushButton_CalculateTCPMarkerTransform->setEnabled(true);
	ROS_INFO("Calculate Rotation Matrix succeed");
	vecbCalibrationToDoList_[Interface::NDIKUKARotation] = true;
}

void Interface::closeDialogWindow() {
	dtSubWindowWaitForExecution_.close();
}

void Interface::useTCPMarkerTransformChanged() {
	bUseTCPMarkerTransform_ = checkBox_UseTCPMarkerTransform->isChecked();

	// Display warning message on the interface
	if (bUseTCPMarkerTransform_) {
		label_MarkerNeedleWarning->setHidden(false);
	} else {
		label_MarkerNeedleWarning->setHidden(true);
	}
	ROS_INFO("Use Marker Needle Transform checkbox is clicked");
}

/*****************************************************************
 Name:				OnTrackingBut

 Inputs:
 None.

 Return Value:
 None.

 Description:   This routine handles what happens when the user
 presses the Tracking Button.
 *****************************************************************/
void Interface::trackingButton() {
	/* if the text read Start, then we start, else we stop tracking */
	if (pushButton_StartTracking->accessibleName() == "Start Tracking")
		startTracking();
	else
		stopTracking();
} /* OnTrackingBut */
/*****************************************************************
 Name:				initializeNDISystem

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles what happen when the user
 presses the Intialize System button.  We initialize
 the System.
 *****************************************************************/
void Interface::initializeNDISystem() {
	int nBaudRate = 0, nStopBits = 0, nParity = 0, nDataBits = 0, nHardware = 0,
			nWireless = 0;
	nCOMPort_ = 0;
	bWireless_ = false;
	bResetHardware_ = false;

	/*
	 * read the COM port parameters from the ini file
	 */
	pdtCommandHandling_->ReadINIParam<int>("Communication", "Baud Rate",
			nBaudRate);
	pdtCommandHandling_->ReadINIParam<int>("Communication", "Stop Bits",
			nStopBits);
	pdtCommandHandling_->ReadINIParam<int>("Communication", "Parity", nParity);
	pdtCommandHandling_->ReadINIParam<int>("Communication", "Data Bits",
			nDataBits);
	pdtCommandHandling_->ReadINIParam<int>("Communication", "Hardware",
			nHardware);
	pdtCommandHandling_->ReadINIParam<int>("Communication", "COM Port",
			nCOMPort_);
	pdtCommandHandling_->ReadINIParam<bool>("Communication", "Wireless",
			bWireless_);
	/*
	 * This feature is useful for debugging only, m_bResetHardware is set to
	 * true to disable it.
	 */
	pdtCommandHandling_->ReadINIParam<bool>("Communication", "Reset Hardware",
			bResetHardware_);
	/*
	 * close, then open the port
	 */
	pdtCommandHandling_->CloseComPorts();
	if (!pdtCommandHandling_->OpenComPort(nCOMPort_)) {
		ROS_ERROR("COM ERROR: COM Port could not be opened.  "
				"Check your COM Port settings and\n"
				"make sure you system is turned on.");
		return;
	} /* if */

	/*
	 * if we are supposed to reset, call the reset now
	 */
	if (bResetHardware_) {
		if (!pdtCommandHandling_->HardWareReset(bWireless_)) {
			ROS_ERROR("Interface: Cannot reset hardware");
			return;
		}
	}/* if */
	/*
	 * get the timeout values for the commands
	 * this will return an error with all other systems, other than Vicra
	 */
	if (!pdtCommandHandling_->CreateTimeoutTable()) {
		ROS_ERROR("Create Timeout Table failed");
	}
	/*
	 * set the System COM Port parameters, then the computers COM Port parameters.
	 * if that is successful, initialize the system
	 */
	if (pdtCommandHandling_->SetSystemComParms(nBaudRate, nDataBits, nParity,
			nStopBits, nHardware)) {
		if (pdtCommandHandling_->SetCompCommParms(nBaudRate, nDataBits, nParity,
				nStopBits, nHardware)) {
			if (pdtCommandHandling_->InitializeSystem()) {
				/*
				 * get the system information
				 */
				if (!pdtCommandHandling_->GetSystemInfo()) {
					/*
					 * Check system type: Polaris, Polaris Accedo, and Aurora
					 */
					ROS_ERROR(
							"INIT ERROR: Could not determine type of system\n"
									"(Polaris, Polaris Accedo, Polaris Vicra or Aurora)");
					return;
				} /* if */

				/*
				 * Set firing rate if system type is Polaris or Polaris Accedo.
				 */
				if (pdtCommandHandling_->dtSystemInformation_.nTypeofSystem
						!= AURORA_SYSTEM) {
					pdtCommandHandling_->SetFiringRate();
				}/* if */
				strSystemMode_ = "System Initialized";
				lineEdit_Mode->setText(QString(strSystemMode_.c_str()));
				setMode( MODE_INIT);
				bSystemInitialized_ = true;
				ROS_INFO("System successfully initialized");
				return;
			} /* if */
			else {
				ROS_ERROR(
						"INIT ERROR: System could not be initialized. "
								"Check your COM Port settings, make sure your\n"
								"system is turned on and the system components are compatible.");
			}/* else */
		}/* if */
		else {
			ROS_ERROR("SetCompComParms failed");
		}/* else */
	}/* if */
	else {
		ROS_ERROR("SetSystemComParms failed");
	}/* else */

	//Set Timer
	dtGetDataTimer_->stop();
}/* initializeNDISystem */
/*****************************************************************
 Name:				resetNDISystem

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles what happens when the user
 presses the Reset System button.  It resets the
 system they are connected to.
 *****************************************************************/
void Interface::resetNDISystem() {
	nCOMPort_ = 0;
	bWireless_ = false;
	bResetHardware_ = false;
	/*
	 * read the reset variable from the ini file, this tells us
	 * if you want to reset the system.
	 */
	pdtCommandHandling_->ReadINIParam<int>("Communication", "COM Port",
			nCOMPort_);
	pdtCommandHandling_->ReadINIParam<bool>("Communication", "Wireless",
			bWireless_);
	/*
	 * This feature is useful for debugging only
	 */
	pdtCommandHandling_->ReadINIParam<bool>("Communication", "Reset Hardware",
			bResetHardware_);
	pdtCommandHandling_->CloseComPorts();
	if (!pdtCommandHandling_->OpenComPort(nCOMPort_)) {
		ROS_ERROR("COM ERROR: COM Port could not be opened. "
				"Check your COM Port settings and "
				"make sure you system is turned on.");
		return;
	} /* if */
	if (bResetHardware_) {
		if (!pdtCommandHandling_->HardWareReset(bWireless_))
			return;

		if (!pdtCommandHandling_->SetSystemComParms(0, 0, 0, 0, 0))
			return;
	} /* if */
	/*
	 * set the new mode
	 */
	strSystemMode_ = "Setup Mode";
	lineEdit_Mode->setText(QString(strSystemMode_.c_str()));
	setMode(MODE_PRE_INIT);
	ROS_INFO("System reset successful");

	//Set Timer
	dtGetDataTimer_->stop();
} /* resetNDISystem */
/*****************************************************************
 Name:				activateHandles

 Inputs:
 None.

 Return Value:
 None.

 Description:   This routine handles what happens when the user presses
 the active ports button.
 *****************************************************************/
void Interface::activateHandles() {
	activatePorts();
} /* activateHandles */
/*****************************************************************
 Name:				activePorts

 Inputs:
 None.

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:   This routine actives the ports plugged into the system
 *****************************************************************/
int Interface::activatePorts() {
	char pszPortID[9];
	int i = 0;

	/*
	 * if we can active the ports, we then fill the port information
	 * on the main dialog
	 */
	if (pdtCommandHandling_->ActivateAllPorts()) {
		bPortsActivated_ = true;
		comboBox_Port->clear();
		comboBox_Reference->clear();

		comboBox_Marker->clear();
		comboBox_Indicator->clear();
		lineEdit_Tx->clear();
		lineEdit_Ty->clear();
		lineEdit_Tz->clear();
		lineEdit_Qx->clear();
		lineEdit_Qy->clear();
		lineEdit_Qz->clear();
		lineEdit_Qo->clear();

		lineEdit_Tx_2->clear();
		lineEdit_Ty_2->clear();
		lineEdit_Tz_2->clear();
		lineEdit_Qx_2->clear();
		lineEdit_Qy_2->clear();
		lineEdit_Qz_2->clear();
		lineEdit_Qo_2->clear();

		strManufID_ = "";
		bPortEnabled_ = false;
		bPortInitialized_ = false;
		strSerialNo_ = "";
		strToolRev_ = "";
		strToolType_ = "";
		strPartNumber_ = "";

		lineEdit_Manufacturer->setText(QString(strManufID_.c_str()));
		lineEdit_Serial->setText(QString(strSerialNo_.c_str()));
		lineEdit_Tool->setText(QString(strToolType_.c_str()));
		lineEdit_Tool_2->setText(QString(strToolRev_.c_str()));
		lineEdit_Part->setText(QString(strPartNumber_.c_str()));
		checkBox_HandleEnable->setChecked(bPortEnabled_);
		checkBox_HandleInitialize->setChecked(bPortInitialized_);

		comboBox_Reference->addItem(QString("None"));

		for (int i = NO_HANDLES; i > 0; i--) {
			if (pdtCommandHandling_->pdtHandleInformation_[i].dtHandleInfo.nInitialized
					== 1) {
				sprintf(pszPortID, "%02X", i);
				comboBox_Port->addItem(QString(pszPortID));
				comboBox_Reference->addItem(QString(pszPortID));
				comboBox_Marker->addItem(QString(pszPortID));
				comboBox_Indicator->addItem(QString(pszPortID));
			} /* if */
		} /* for */
		comboBox_Port->setEnabled(true);
		comboBox_Reference->setEnabled(true);
		comboBox_Marker->setEnabled(true);
		comboBox_Indicator->setEnabled(true);
		// set to no reference tool
		comboBox_Reference->setCurrentIndex(0);
		setMode( MODE_ACTIVATED);

		if (!bIsTracking_)
			ROS_INFO("Ports successfully activated");
		return 1;
	} /* if */

	bPortsActivated_ = false;
	ROS_ERROR("PORT ACTIVATION ERROR: Ports could not be activated.\n"
			"Check your SROM image file settings and\n"
			"make sure your system is turned on and initialized.");
	setMode( MODE_PRE_INIT);
	return 0;
} /* activatePorts */
/*****************************************************************
 Name:				startTracking

 Inputs:
 None.

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:   This routine starts the System tracking
 *****************************************************************/
int Interface::startTracking() {
	if (pdtCommandHandling_->StartTracking()) {
		/*
		 * if we can start tracking, set the appropriate window text,
		 * start the tracking thread and set the mode.
		 */
		bIsTracking_ = true;
		bStopTracking_ = false;

		pushButton_StartTracking->setAccessibleName(QString("Stop Tracking"));
		checkBox_HandleEnable->setEnabled(false);

		strSystemMode_ = "System Tracking";
		lineEdit_Mode->setText(QString(strSystemMode_.c_str()));
		setMode( MODE_TRACKING);

		if (comboBox_Port->count() > 0) {
			comboBox_Port->setCurrentIndex(0);
			selchangePortHandles();
		}
		return 1;
	} /* if */

	return 0;
} /* startTracking */
/*****************************************************************
 Name:				stopTracking

 Inputs:
 None.

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:
 This routine stops the tracking procedure.
 *****************************************************************/
int Interface::stopTracking() {
	if (pdtCommandHandling_->StopTracking()) {
		/*
		 * set the variable that will stop the thread.
		 * set the text on the dialog and put program in proper mode.
		 */
		bIsTracking_ = false;
		bStopTracking_ = true;
		pushButton_StartTracking->setAccessibleName(QString("Start Tracking"));

		strSystemMode_ = "System Initialized";
		lineEdit_Mode->setText(QString(strSystemMode_.c_str()));
		setMode( MODE_ACTIVATED);

		pushButton_StartTracking->setAccessibleName(QString("Start Tracking"));
		if (comboBox_Port->count() > -1) {
			comboBox_Port->setEnabled(true);
		}
		return 1;
	} /* if */

	return 0;
} /* stopTracking */

long Interface::getSystemTransformData() {
	char pszTemp[256];
	std::string szCBHandle, szPortNo;
	int nRow = -1;

	Rotation dtEulerRot;
	QuatTransformation dtNeedleTransform, dtMarkerTransform;

	if (!bIsTracking_)
		return 0;

	bUse0x0800Option_ = checkBox_0x0800->isChecked();
	nTrackingMode_ = radioButton_TXMode->isChecked() ? 0 : 1;

	/*
	 * if tracking mode is 0, we are asking for TX data, else we are
	 * asking for BX data.
	 */
	if (nTrackingMode_ == 0) {
		if (!pdtCommandHandling_->GetTXTransforms(
				bUse0x0800Option_ ? true : false))
			return 0;
	} /* if */
	else if (nTrackingMode_ == 1) {
		if (!pdtCommandHandling_->GetBXTransforms(
				bUse0x0800Option_ ? true : false))
			return 0;
	} /* else if */

	/*
	 * if a new port has become occupied we do the following:
	 * 1) Stop tracking
	 * 2) Activate Ports
	 * 3) Start Tracking
	 */
	if (pdtCommandHandling_->dtSystemInformation_.nPortOccupied) {
		if (pdtCommandHandling_->StopTracking() && activatePorts()
				&& pdtCommandHandling_->StartTracking()) {
		} else {
			ROS_ERROR("New occupied port is not available");
			bStopTracking_ = true;
			bIsTracking_ = false;
		}
	} /* if */
//-----------------------------------------------------------
// This is only for Point Indicator
//-----------------------------------------------------------
	int nActiveTool = ASCIIToHex((char*) "02", 2);
	Eigen::Vector4d q;
	QuatTransformation Original, OriginaltoNew, New;
	std::vector<double> Quartenion(4);

	q = Euler2Quaternion(0.0, 0.0, 0.0);
	Original.dtRotation =
			pdtCommandHandling_->pdtHandleInformation_[nActiveTool].dtXfrms.dtRotation;
	Original.dtTranslation =
			pdtCommandHandling_->pdtHandleInformation_[nActiveTool].dtXfrms.dtTranslation;

	OriginaltoNew.dtRotation.fQx = q.data()[0];
	OriginaltoNew.dtRotation.fQy = q.data()[1];
	OriginaltoNew.dtRotation.fQz = q.data()[2];
	OriginaltoNew.dtRotation.fQ0 = q.data()[3];
	//TODO: This tool tip offset is calculated using pivoting method
	OriginaltoNew.dtTranslation.fTx = -6.70;
	OriginaltoNew.dtTranslation.fTy = 1.05;
	OriginaltoNew.dtTranslation.fTz = -118.49;

	QuatCombineXfrms(&OriginaltoNew, &Original, &New);

	pdtCommandHandling_->pdtHandleInformation_[nActiveTool].dtXfrms.dtRotation =
			New.dtRotation;
	pdtCommandHandling_->pdtHandleInformation_[nActiveTool].dtXfrms.dtTranslation =
			New.dtTranslation;

//---------------------------------------------------------------
//---------------------------------------------------------------
	int nMarker = ASCIIToHex(
			(char*) (comboBox_Marker->currentText().toStdString().c_str()), 2);
	int nIndicator = ASCIIToHex(
			(char*) (comboBox_Indicator->currentText().toStdString().c_str()),
			2);
	if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtHandleInfo.nInitialized
			> 0
			&& pdtCommandHandling_->pdtHandleInformation_[nMarker].pchrToolType[1]
					!= '8') {
		/* only update the frame if the handle isn't disabled*/
		if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
				== TRANSFORM_VALID
				|| pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
						== TRANSFORM_MISSING) {
			strFrameNumber_ =
					boost::lexical_cast<std::string>(
							pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFrameNumber);
			lineEdit_Frame->setText(QString(strFrameNumber_.c_str()));
		}/* if */

		if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
				== TRANSFORM_VALID) {

			if (bUseTCPMarkerTransform_) {
				dtMarkerTransform.dtRotation =
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtRotation;
				dtMarkerTransform.dtTranslation =
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtTranslation;
				QuatCombineXfrms(&dtTCPMarkerTransform_, &dtMarkerTransform,
						&dtNeedleTransform);
				// Update the Marker port data
				pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtRotation =
						dtNeedleTransform.dtRotation;
				pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtTranslation =
						dtNeedleTransform.dtTranslation;
			} else {
				dtNeedleTransform.dtRotation =
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtRotation;
				dtNeedleTransform.dtTranslation =
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtTranslation;
			}

			sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTx);
			lineEdit_Tx->setText(QString(pszTemp));
			sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTy);
			lineEdit_Ty->setText(QString(pszTemp));
			sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTz);
			lineEdit_Tz->setText(QString(pszTemp));
			sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQ0);
			lineEdit_Qo->setText(QString(pszTemp));
			sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQx);
			lineEdit_Qx->setText(QString(pszTemp));
			sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQy);
			lineEdit_Qy->setText(QString(pszTemp));
			sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQz);
			lineEdit_Qz->setText(QString(pszTemp));
			sprintf(pszTemp, "%.4f",
					pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.fError);
			lineEdit_Error->setText(QString(pszTemp));

			if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtHandleInfo.nPartiallyOutOfVolume)
				lineEdit_Status->setText(QString("POOV"));
			else if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtHandleInfo.nOutOfVolume)
				lineEdit_Status->setText(QString("OOV"));
			else
				lineEdit_Status->setText(QString("OK"));
		}/* if */
		else {
			if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
					== TRANSFORM_MISSING) {
				lineEdit_Status->setText(QString("MISSING"));
			} else {
				lineEdit_Status->setText(QString("DISABLED"));
			}

			if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtHandleInfo.nPartiallyOutOfVolume)
				lineEdit_Status->setText(QString("POOV"));
			else if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtHandleInfo.nOutOfVolume)
				lineEdit_Status->setText(QString("OOV"));
			else
				lineEdit_Status->setText(QString("---"));
		}/* else */
	}/* if */

	if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtHandleInfo.nInitialized
			> 0
			&& pdtCommandHandling_->pdtHandleInformation_[nIndicator].pchrToolType[1]
					!= '8') {
		/* only update the frame if the handle isn't disabled*/
		if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
				== TRANSFORM_VALID
				|| pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
						== TRANSFORM_MISSING) {
			strFrameNumber_ =
					boost::lexical_cast<std::string>(
							pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFrameNumber);
			lineEdit_Frame->setText(QString(strFrameNumber_.c_str()));
		}/* if */

		if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
				== TRANSFORM_VALID) {

			dtNeedleTransform.dtRotation =
					pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.dtRotation;
			dtNeedleTransform.dtTranslation =
					pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.dtTranslation;

			sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTx);
			lineEdit_Tx_2->setText(QString(pszTemp));
			sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTy);
			lineEdit_Ty_2->setText(QString(pszTemp));
			sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTz);
			lineEdit_Tz_2->setText(QString(pszTemp));
			sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQ0);
			lineEdit_Qo_2->setText(QString(pszTemp));
			sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQx);
			lineEdit_Qx_2->setText(QString(pszTemp));
			sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQy);
			lineEdit_Qy_2->setText(QString(pszTemp));
			sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQz);
			lineEdit_Qz_2->setText(QString(pszTemp));
			sprintf(pszTemp, "%.4f",
					pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.fError);
			lineEdit_Error_2->setText(QString(pszTemp));

			if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtHandleInfo.nPartiallyOutOfVolume)
				lineEdit_Status_2->setText(QString("POOV"));
			else if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtHandleInfo.nOutOfVolume)
				lineEdit_Status_2->setText(QString("OOV"));
			else
				lineEdit_Status_2->setText(QString("OK"));
		}/* if */
		else {
			if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
					== TRANSFORM_MISSING) {
				lineEdit_Status_2->setText(QString("MISSING"));
			} else {
				lineEdit_Status_2->setText(QString("DISABLED"));
			}

			if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtHandleInfo.nPartiallyOutOfVolume)
				lineEdit_Status->setText(QString("POOV"));
			else if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtHandleInfo.nOutOfVolume)
				lineEdit_Status_2->setText(QString("OOV"));
			else
				lineEdit_Status_2->setText(QString("---"));
		}/* else */
	}/* if */



	//TODO: For debug

/*	Axis AxisFeedback;
	Frame FrameFeedback;
	AxisFeedback = dtController_.getFeedbackAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);

	q = Euler2Quaternion(FrameFeedback.C / 180.0 * M_PI, FrameFeedback.B / 180.0 * M_PI,
			FrameFeedback.A / 180.0 * M_PI);
	ROS_INFO("x %f y %f z %f w %f", q.x(), q.y(), q.z(), q.w());

	KDL::Rotation h = KDL::Rotation::RPY(FrameFeedback.C / 180.0 * M_PI, FrameFeedback.B / 180.0 * M_PI,
			FrameFeedback.A / 180.0 * M_PI);
	std::vector<double> qua(4), eul(3);
	h.GetQuaternion(qua[0], qua[1], qua[2], qua[3]);
	ROS_INFO("x %f y %f z %f w %f", qua[0], qua[1], qua[2], qua[3]);

	Eigen::Vector3d EulerAngleVector = Quaternion2Euler(q.x(), q.y(), q.z(), q.w());

	h = KDL::Rotation::Quaternion(q.x(), q.y(), q.z(), q.w());
	h.GetRPY(eul[0], eul[1], eul[2]);
	ROS_INFO("right A %f B %f C %f", eul[2], eul[1], eul[0]);

	ROS_INFO("Recovered A %f B %f C %f", EulerAngleVector[0], EulerAngleVector[1], EulerAngleVector[2]);
	ROS_INFO("Original A %f B %f C %f", FrameFeedback.A / 180.0 * M_PI, FrameFeedback.B / 180.0 * M_PI,
			FrameFeedback.C / 180.0 * M_PI); */

	return 1;
} /* getSystemTransformData */

/*****************************************************************
 Name:				getSystemTransformData

 Inputs:

 Return Value:
 long is the normal return for a message handling routine

 Description:
 This routine gets the next set of transformation data and displays
 it in the main dialog.
 *****************************************************************/
long Interface::getSystemTransformData(bool bUpdateGUI) {
	char pszTemp[256];
	std::string szCBHandle, szPortNo;
	int nRow = -1;

	Rotation dtEulerRot;
	QuatTransformation dtNeedleTransform, dtMarkerTransform;

	if (!bIsTracking_)
		return 0;

	bUse0x0800Option_ = checkBox_0x0800->isChecked();
	nTrackingMode_ = radioButton_TXMode->isChecked() ? 0 : 1;

	/*
	 * if tracking mode is 0, we are asking for TX data, else we are
	 * asking for BX data.
	 */
	if (nTrackingMode_ == 0) {
		if (!pdtCommandHandling_->GetTXTransforms(
				bUse0x0800Option_ ? true : false))
			return 0;
	} /* if */
	else if (nTrackingMode_ == 1) {
		if (!pdtCommandHandling_->GetBXTransforms(
				bUse0x0800Option_ ? true : false))
			return 0;
	} /* else if */

	/*
	 * if a new port has become occupied we do the following:
	 * 1) Stop tracking
	 * 2) Activate Ports
	 * 3) Start Tracking
	 */
	if (pdtCommandHandling_->dtSystemInformation_.nPortOccupied) {
		if (pdtCommandHandling_->StopTracking() && activatePorts()
				&& pdtCommandHandling_->StartTracking()) {
		} else {
			ROS_ERROR("New occupied port is not available");
			bStopTracking_ = true;
			bIsTracking_ = false;
		}
	} /* if */
//-----------------------------------------------------------
// This is only for Point Indicator
//-----------------------------------------------------------
	int nActiveTool = ASCIIToHex((char*) "02", 2);
	Eigen::Vector4d q;
	QuatTransformation Original, OriginaltoNew, New;
	std::vector<double> Quartenion(4);

	q = Euler2Quaternion(0.0, 0.0, 0.0);
	Original.dtRotation =
			pdtCommandHandling_->pdtHandleInformation_[nActiveTool].dtXfrms.dtRotation;
	Original.dtTranslation =
			pdtCommandHandling_->pdtHandleInformation_[nActiveTool].dtXfrms.dtTranslation;

	OriginaltoNew.dtRotation.fQx = q.data()[0];
	OriginaltoNew.dtRotation.fQy = q.data()[1];
	OriginaltoNew.dtRotation.fQz = q.data()[2];
	OriginaltoNew.dtRotation.fQ0 = q.data()[3];
	//TODO: This tool tip offset is calculated using pivoting method
	OriginaltoNew.dtTranslation.fTx = -6.70;
	OriginaltoNew.dtTranslation.fTy = 1.05;
	OriginaltoNew.dtTranslation.fTz = -118.49;

	QuatCombineXfrms(&OriginaltoNew, &Original, &New);

	pdtCommandHandling_->pdtHandleInformation_[nActiveTool].dtXfrms.dtRotation =
			New.dtRotation;
	pdtCommandHandling_->pdtHandleInformation_[nActiveTool].dtXfrms.dtTranslation =
			New.dtTranslation;

//---------------------------------------------------------------
//---------------------------------------------------------------
	int nMarker = ASCIIToHex(
			(char*) (comboBox_Marker->currentText().toStdString().c_str()), 2);
	int nIndicator = ASCIIToHex(
			(char*) (comboBox_Indicator->currentText().toStdString().c_str()),
			2);
	if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtHandleInfo.nInitialized
			> 0
			&& pdtCommandHandling_->pdtHandleInformation_[nMarker].pchrToolType[1]
					!= '8') {
		/* only update the frame if the handle isn't disabled*/
		if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
				== TRANSFORM_VALID
				|| pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
						== TRANSFORM_MISSING) {
			strFrameNumber_ =
					boost::lexical_cast<std::string>(
							pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFrameNumber);
			lineEdit_Frame->setText(QString(strFrameNumber_.c_str()));
		}/* if */

		if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
				== TRANSFORM_VALID) {

			if (bUseTCPMarkerTransform_) {
				dtMarkerTransform.dtRotation =
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtRotation;
				dtMarkerTransform.dtTranslation =
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtTranslation;
				QuatCombineXfrms(&dtTCPMarkerTransform_, &dtMarkerTransform,
						&dtNeedleTransform);
				// Update the Marker port data
				pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtRotation =
						dtNeedleTransform.dtRotation;
				pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtTranslation =
						dtNeedleTransform.dtTranslation;
			} else {
				dtNeedleTransform.dtRotation =
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtRotation;
				dtNeedleTransform.dtTranslation =
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.dtTranslation;
			}

			if (bUpdateGUI) {
				sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTx);
				lineEdit_Tx->setText(QString(pszTemp));
				sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTy);
				lineEdit_Ty->setText(QString(pszTemp));
				sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTz);
				lineEdit_Tz->setText(QString(pszTemp));
				sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQ0);
				lineEdit_Qo->setText(QString(pszTemp));
				sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQx);
				lineEdit_Qx->setText(QString(pszTemp));
				sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQy);
				lineEdit_Qy->setText(QString(pszTemp));
				sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQz);
				lineEdit_Qz->setText(QString(pszTemp));
				sprintf(pszTemp, "%.4f",
						pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.fError);
				lineEdit_Error->setText(QString(pszTemp));

				if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtHandleInfo.nPartiallyOutOfVolume)
					lineEdit_Status->setText(QString("POOV"));
				else if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtHandleInfo.nOutOfVolume)
					lineEdit_Status->setText(QString("OOV"));
				else
					lineEdit_Status->setText(QString("OK"));
			}
		}/* if */
		else {
			if (bUpdateGUI) {
				if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtXfrms.ulFlags
						== TRANSFORM_MISSING) {
					lineEdit_Status->setText(QString("MISSING"));
				} else {
					lineEdit_Status->setText(QString("DISABLED"));
				}

				if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtHandleInfo.nPartiallyOutOfVolume)
					lineEdit_Status->setText(QString("POOV"));
				else if (pdtCommandHandling_->pdtHandleInformation_[nMarker].dtHandleInfo.nOutOfVolume)
					lineEdit_Status->setText(QString("OOV"));
				else
					lineEdit_Status->setText(QString("---"));
			}
		}/* else */
	}/* if */

	if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtHandleInfo.nInitialized
			> 0
			&& pdtCommandHandling_->pdtHandleInformation_[nIndicator].pchrToolType[1]
					!= '8') {
		/* only update the frame if the handle isn't disabled*/
		if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
				== TRANSFORM_VALID
				|| pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
						== TRANSFORM_MISSING) {
			strFrameNumber_ =
					boost::lexical_cast<std::string>(
							pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFrameNumber);
			lineEdit_Frame->setText(QString(strFrameNumber_.c_str()));
		}/* if */

		if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
				== TRANSFORM_VALID) {

			dtNeedleTransform.dtRotation =
					pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.dtRotation;
			dtNeedleTransform.dtTranslation =
					pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.dtTranslation;

			if (bUpdateGUI) {
				sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTx);
				lineEdit_Tx_2->setText(QString(pszTemp));
				sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTy);
				lineEdit_Ty_2->setText(QString(pszTemp));
				sprintf(pszTemp, "%.2f", dtNeedleTransform.dtTranslation.fTz);
				lineEdit_Tz_2->setText(QString(pszTemp));
				sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQ0);
				lineEdit_Qo_2->setText(QString(pszTemp));
				sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQx);
				lineEdit_Qx_2->setText(QString(pszTemp));
				sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQy);
				lineEdit_Qy_2->setText(QString(pszTemp));
				sprintf(pszTemp, "%.4f", dtNeedleTransform.dtRotation.fQz);
				lineEdit_Qz_2->setText(QString(pszTemp));
				sprintf(pszTemp, "%.4f",
						pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.fError);
				lineEdit_Error_2->setText(QString(pszTemp));

				if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtHandleInfo.nPartiallyOutOfVolume)
					lineEdit_Status_2->setText(QString("POOV"));
				else if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtHandleInfo.nOutOfVolume)
					lineEdit_Status_2->setText(QString("OOV"));
				else
					lineEdit_Status_2->setText(QString("OK"));
			}
		}/* if */
		else {
			if (bUpdateGUI) {
				if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtXfrms.ulFlags
						== TRANSFORM_MISSING) {
					lineEdit_Status_2->setText(QString("MISSING"));
				} else {
					lineEdit_Status_2->setText(QString("DISABLED"));
				}

				if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtHandleInfo.nPartiallyOutOfVolume)
					lineEdit_Status->setText(QString("POOV"));
				else if (pdtCommandHandling_->pdtHandleInformation_[nIndicator].dtHandleInfo.nOutOfVolume)
					lineEdit_Status_2->setText(QString("OOV"));
				else
					lineEdit_Status_2->setText(QString("---"));
			}
		}/* else */
	}/* if */
	return 1;
} /* getSystemTransformData */
/*****************************************************************
 Name:				comPortTimeout

 Inputs:
 UNIT wParam and long lParam are normal message handling inputs

 Return Value:
 long is the normal return for a message handling routine

 Description:
 This routine is the message handler for a WM_COM_TIMEOUT posting.
 This routine handles what happens when a COM port timeout occurs.
 *****************************************************************/
long Interface::comPortTimeout() {

	//switch (wParam)
	//{
	/* if close application was choosen */
	//	case ERROR_TIMEOUT_CLOSE:
	//	{
	//		IsTracking_ = false;
	//		PostMessage( WM_CLOSE, 0, 0l );
	//		break;
	//	}
	/* if restart application was selected */
	//	case ERROR_TIMEOUT_RESTART:
	//	{
	//		IsTracking_ = false;
	//		CommandHandling_->CloseComPorts();
	//		SystemMode_ = "Setup Mode";
	//		setMode( MODE_PRE_INIT );
	//		UpdateData(false);
	//		break;
	//	}
	/* if retry was choosen */
	//	case ERROR_TIMEOUT_CONT:
	//		break;
	//}; /* switch */
	return 0;
} /* comPortTimeout */
void Interface::clearMarkerTransformData() {
	lineEdit_Tx->clear();
	lineEdit_Ty->clear();
	lineEdit_Tz->clear();
	lineEdit_Qo->clear();
	lineEdit_Qx->clear();
	lineEdit_Qy->clear();
	lineEdit_Qz->clear();
}

void Interface::clearIndicatorTransformData() {
	lineEdit_Tx_2->clear();
	lineEdit_Ty_2->clear();
	lineEdit_Tz_2->clear();
	lineEdit_Qo_2->clear();
	lineEdit_Qx_2->clear();
	lineEdit_Qy_2->clear();
	lineEdit_Qz_2->clear();
}
/*****************************************************************
 Name:				selchangePortHandles

 Inputs:
 None.

 Return Value:
 None.

 Description:   This routine handles the selection of port handles
 from the port handle combo box.  It fills the form
 with the information that pertains to the select
 port handle.
 *****************************************************************/
void Interface::selchangePortHandles() {
	int nPortHandle = 0, nSelection = 0;
	std::string szPortHandle = "";

	nSelection = comboBox_Port->currentIndex();
	szPortHandle = comboBox_Port->currentText().toStdString();
	nPortHandle = ASCIIToHex((char*) (szPortHandle.c_str()), 2);

	/* fill the form with the info that pertains to the selected handle */
	strManufID_ =
			pdtCommandHandling_->pdtHandleInformation_[nPortHandle].pchrManufact;
	bPortEnabled_ =
			pdtCommandHandling_->pdtHandleInformation_[nPortHandle].dtHandleInfo.nEnabled;
	bPortInitialized_ =
			pdtCommandHandling_->pdtHandleInformation_[nPortHandle].dtHandleInfo.nInitialized;
	strSerialNo_ =
			pdtCommandHandling_->pdtHandleInformation_[nPortHandle].pchrSerialNo;
	strToolRev_ =
			pdtCommandHandling_->pdtHandleInformation_[nPortHandle].pchrRev;
	strToolType_ =
			pdtCommandHandling_->pdtHandleInformation_[nPortHandle].pchrToolType;
	strPartNumber_ =
			pdtCommandHandling_->pdtHandleInformation_[nPortHandle].pchrPartNumber;

	lineEdit_Manufacturer->setText(QString(strManufID_.c_str()));
	lineEdit_Serial->setText(QString(strSerialNo_.c_str()));
	lineEdit_Tool->setText(QString(strToolType_.c_str()));
	lineEdit_Tool_2->setText(QString(strToolRev_.c_str()));
	lineEdit_Part->setText(QString(strPartNumber_.c_str()));
	checkBox_HandleEnable->setChecked(bPortEnabled_);
	checkBox_HandleInitialize->setChecked(bPortInitialized_);
	if (!bIsTracking_) {
		checkBox_HandleEnable->setEnabled(true);
	}
} /* selchangePortHandles */

/*****************************************************************
 Name:				selchangeRefPortHandles

 Inputs:
 None.

 Return Value:
 None.

 Description:   This routine handles the selection of port handles
 from the port handle combo box.  It fills the form
 with the information that pertains to the select
 port handle.
 *****************************************************************/
void Interface::selchangeRefPortHandle() {
	int nPortHandle = 0, nSelection = 0;
	std::string szPortHandle = "";

	nSelection = comboBox_Reference->currentIndex();
	szPortHandle = comboBox_Reference->currentText().toStdString();

	if (szPortHandle != "None")
		pdtCommandHandling_->nRefHandle_ = ASCIIToHex(
				(char*) (szPortHandle.c_str()), 2);
	else
		pdtCommandHandling_->nRefHandle_ = -1;
} /* selchangeRefPortHandles */
/*****************************************************************
 Name:				portEnabled

 Inputs:
 None.

 Return Value:
 None.

 Description:   This routine enables or disables the select port
 handle depending on the status of the check box
 *****************************************************************/
void Interface::portEnabled() {
	int nPortHandle = 0, nSelection = 0;
	std::string szPortHandle = "";

	nSelection = comboBox_Port->currentIndex();
	szPortHandle = comboBox_Port->currentText().toStdString();
	/* get the port handle */
	nPortHandle = ASCIIToHex((char*) (szPortHandle.c_str()), 2);
	bPortEnabled_ = checkBox_HandleEnable->isChecked();

	/*
	 * enable or disable the port depending on the status of
	 * the check box
	 */

	if (!bPortEnabled_)
		pdtCommandHandling_->DisablePort(nPortHandle);
	else
		pdtCommandHandling_->EnableOnePort(nPortHandle);
} /* portEnabled */

/*****************************************************************
 Name:			settingsComportsettings

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles the Setting Menu's COM Port
 Settings call
 *****************************************************************/
void Interface::settingsComportsettings() {
	dtSubWindowCOMPortSettings_.Init();
	dtSubWindowCOMPortSettings_.show();
} /* settingsComportsettings */

void Interface::settingsComPortSettings_OK() {
	ROS_INFO("Interface: COM Port Settings OK signal received");
	bResetHardware_ = dtSubWindowCOMPortSettings_.bReset_;
	nCOMPort_ = dtSubWindowCOMPortSettings_.nCOMPort_;
	bWireless_ = dtSubWindowCOMPortSettings_.bWireless_;
}
/*****************************************************************
 Name:			settingsRomfilesettings

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles the Setting Menu's ROM File
 Settings call
 *****************************************************************/
void Interface::settingsRomfilesettings() {

	/*
	 * we need to know what system we are connect to so we need to
	 * initialize the system if not already done.
	 */
	if (!bSystemInitialized_)
		initializeNDISystem();

	dtSubWindowROMFile_.nNoActivePorts_ =
			pdtCommandHandling_->dtSystemInformation_.nNoActivePorts;
	dtSubWindowROMFile_.nNoPassivePorts_ =
			pdtCommandHandling_->dtSystemInformation_.nNoPassivePorts;
	dtSubWindowROMFile_.nNoMagneticPorts_ =
			pdtCommandHandling_->dtSystemInformation_.nNoMagneticPorts;
	dtSubWindowROMFile_.nTypeofSystem_ =
			pdtCommandHandling_->dtSystemInformation_.nTypeofSystem;
	ROS_INFO("ROMFileSettings: %d %d %d %d",
			dtSubWindowROMFile_.nNoActivePorts_,
			dtSubWindowROMFile_.nNoPassivePorts_,
			dtSubWindowROMFile_.nNoMagneticPorts_,
			dtSubWindowROMFile_.nTypeofSystem_);
	dtSubWindowROMFile_.Init();
	dtSubWindowROMFile_.show();

} /* settingsRomfilesettings */
void Interface::reInitializeSystem() {
	/* Force to re-initialize the system  */
	pushButton_ActiveHandles->setEnabled(false);
	pushButton_StartTracking->setEnabled(false);
	actionActivate_Handles->setEnabled(true);
}
/*****************************************************************
 Name:			systemActivateports

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles the System Menu's Activate
 Ports call
 *****************************************************************/
void Interface::systemActivateports() {
	activateHandles();
} /* systemActivateports */
/*****************************************************************
 Name:			systemInitializesystem

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles the Systems Menu's Initialize
 System call
 *****************************************************************/
void Interface::systemInitializesystem() {
	initializeNDISystem();
} /* systemInitializesystem */
/*****************************************************************
 Name:			systemStarttracking

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles the System Menu's Start
 Tracking call
 *****************************************************************/
void Interface::systemStarttracking() {
	startTracking();
} /* systemStarttracking */
/*****************************************************************
 Name:			systemStoptracking

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles the System Menu's Stop
 Tracking call
 *****************************************************************/
void Interface::systemStoptracking() {
	stopTracking();
} /* systemStoptracking */
/*****************************************************************
 Name:			viewSystemproperties

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles the View Menu's System
 Properties call
 *****************************************************************/
void Interface::viewSystemproperties() {

	/* if we are connected to a POLARIS set the POLARIS variables */
	if (!pdtCommandHandling_->GetSystemInfo()) {
		ROS_ERROR("Get System Info failed");
		return;
	}
	dtSubWindowSystemFeatures_.Init();
	if (pdtCommandHandling_->dtSystemInformation_.nTypeofSystem != AURORA_SYSTEM) {
		dtSubWindowSystemFeatures_.SetVariables(
				std::string(
						pdtCommandHandling_->dtSystemInformation_.pchrVersionInfo),
				pdtCommandHandling_->dtSystemInformation_.nNoActivePorts,
				pdtCommandHandling_->dtSystemInformation_.nNoPassivePorts,
				pdtCommandHandling_->dtSystemInformation_.nNoActWirelessPorts,
				pdtCommandHandling_->dtSystemInformation_.nNoActTIPPorts,
				pdtCommandHandling_->dtSystemInformation_.nTypeofSystem);
	} /* if */
	else {
		/* if we are connected to a AURORA set the AURORA variables */
		dtSubWindowSystemFeatures_.SetVariables(
				std::string(
						pdtCommandHandling_->dtSystemInformation_.pchrVersionInfo),
				pdtCommandHandling_->dtSystemInformation_.nNoMagneticPorts,
				pdtCommandHandling_->dtSystemInformation_.nNoFGs,
				pdtCommandHandling_->dtSystemInformation_.nNoFGCards,
				pdtCommandHandling_->dtSystemInformation_.nTypeofSystem);
	} /* else */
	dtSubWindowSystemFeatures_.show();
} /* OnViewSytemproperties */

/*****************************************************************
 Name:			viewAlertFlags

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles the View Menu's System
 Properties call
 *****************************************************************/
void Interface::viewAlertFlags() {
	if (pdtCommandHandling_->GetAlerts(false)) {
		ROS_ERROR("Get Alerts failed");
		return;
	}

	dtSubWindowNewAlertFlags_.Init();
	dtSubWindowNewAlertFlags_.dtNewAlerts_ = pdtCommandHandling_->dtNewAlerts_;
	dtSubWindowNewAlertFlags_.show();

} /* viewAlertFlags */
/*****************************************************************
 Name:			optionsIlluminatorfiringrate

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles the Options Menu's
 Illuminator Activation Rate call
 *****************************************************************/
void Interface::optionsIlluminatorfiringrate() {

	if (pdtCommandHandling_->dtSystemInformation_.nTypeofSystem != AURORA_SYSTEM) {
		dtSubWindowIlluminatorFiringRate_.Init();
		dtSubWindowIlluminatorFiringRate_.nTypeOfSystem_ =
				pdtCommandHandling_->dtSystemInformation_.nTypeofSystem;
		dtSubWindowIlluminatorFiringRate_.show();
	}/* if */

} /* optionsIlluminatorfiringrate */
void Interface::optionsIlluminatorfiringrate_OK() {
	ROS_INFO("Interface: Illuminator Firing Rate OK signal received");
	pdtCommandHandling_->SetFiringRate();
}
/*****************************************************************
 Name:			optionsProgramoptions

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles the Options Menu's Program
 Options call
 *****************************************************************/
void Interface::optionsProgramoptions() {
	dtSubWindowProgramOptions_.Init();
	dtSubWindowProgramOptions_.show();
} /* optionsProgramoptions */

void Interface::optionsProgramoptions_OK() {
	ROS_INFO("Interface: Program Options OK signal received");
	strcpy(pdtCommandHandling_->pchrLogFile_,
			dtSubWindowProgramOptions_.strLogFile_.c_str());
	pdtCommandHandling_->bLogToFile_ = dtSubWindowProgramOptions_.bLogToFile_;
	pdtCommandHandling_->bDateTimeStampFile_ =
			dtSubWindowProgramOptions_.bDateTimeStampFile_;
}
/*****************************************************************
 Name:				setMode

 Inputs:
 int nMode - the mode to be set in to

 Return Value:
 none

 Description:   This routine handles the setting of the dialog
 items depending on the mode to be placed into.
 There are four modes:
 MODE_PRE_INIT - the preinitialization mode, first time
 program is opened or a reset has been called
 MODE_INIT - the initialization mode, the system is
 intialized
 MODE_ACTIVATED - the ports have been activated or
 tracking has been stopped.
 MODE_TRACKING - we are tracking
 *****************************************************************/
void Interface::setMode(int nMode) {
	bool bTrackingMode = false, bPreInitialization = false,
			bInitialized = false;

	//pMainMenu = GetMenu();

	switch (nMode) {
	case MODE_PRE_INIT: {
		dtGetDataTimer_->stop();
		bPreInitialization = true;
		break;
	} /* case */
	case MODE_INIT: {
		dtGetDataTimer_->stop();
		bInitialized = true;
		bPreInitialization = false;
		bPortsActivated_ = false;
		break;
	} /* case */
	case MODE_ACTIVATED: {
		dtGetDataTimer_->stop();
		bInitialized = true;
		break;
	} /* case */
	case MODE_TRACKING: {
		dtGetDataTimer_->start(NDI_TIME_INTERVAL);
		bTrackingMode = true;
		break;
	} /* case */
	} /* switch */

	if (nMode == MODE_PRE_INIT || nMode == MODE_INIT) {
		comboBox_Port->clear();
		comboBox_Port->setEnabled(false);
		comboBox_Reference->clear();
		comboBox_Reference->setEnabled(false);
		//Handle1 stands for port_enabled
		checkBox_HandleEnable->setEnabled(false);
		//replace the original List to comboBox and lineEdit
		comboBox_Marker->clear();
		comboBox_Marker->setEnabled(false);
		comboBox_Indicator->clear();
		comboBox_Indicator->setEnabled(false);
		lineEdit_Tx->clear();
		lineEdit_Ty->clear();
		lineEdit_Tz->clear();
		lineEdit_Qx->clear();
		lineEdit_Qy->clear();
		lineEdit_Qz->clear();
		lineEdit_Qo->clear();

		lineEdit_Tx_2->clear();
		lineEdit_Ty_2->clear();
		lineEdit_Tz_2->clear();
		lineEdit_Qx_2->clear();
		lineEdit_Qy_2->clear();
		lineEdit_Qz_2->clear();
		lineEdit_Qo_2->clear();
		// replace original method called "SetWindowText"
		pushButton_StartTracking->setAccessibleName(QString("Start Tracking"));

		bInitialized = true;
		strManufID_ = "";
		strSerialNo_ = "";
		strToolRev_ = "";
		strToolType_ = "";
		strPartNumber_ = "";
		bPortEnabled_ = false;
		bPortInitialized_ = false;

		lineEdit_Manufacturer->setText(QString(strManufID_.c_str()));
		lineEdit_Serial->setText(QString(strSerialNo_.c_str()));
		lineEdit_Tool->setText(QString(strToolType_.c_str()));
		lineEdit_Tool_2->setText(QString(strToolRev_.c_str()));
		lineEdit_Part->setText(QString(strPartNumber_.c_str()));
		checkBox_HandleEnable->setChecked(bPortEnabled_);
		checkBox_HandleInitialize->setChecked(bPortInitialized_);
	} /* if */

	/* buttons */
	pushButton_ResetSystem->setEnabled(!bTrackingMode);
	pushButton_InitializeSystem->setEnabled(!bTrackingMode);
	pushButton_ActiveHandles->setEnabled(!bPreInitialization && !bTrackingMode);
	pushButton_StartTracking->setEnabled(
			(bInitialized && !bPreInitialization && bPortsActivated_)
					|| bTrackingMode);

	/* fields */
	radioButton_TXMode->setEnabled(bTrackingMode);
	radioButton_BXMode->setEnabled(bTrackingMode);
	lineEdit_Mode->setEnabled(bTrackingMode);
	checkBox_0x0800->setEnabled(bTrackingMode);
	/* menu options */
	actionInitialize_System->setDisabled(bTrackingMode);
	actionActivate_Handles->setDisabled(bPreInitialization || bTrackingMode);
	actionStart_Tracking->setDisabled(
			bPreInitialization || bTrackingMode || !bPortsActivated_);
	actionStop_Tracking->setDisabled(!bTrackingMode);
	actionSystem_Properties->setDisabled(bPreInitialization || bTrackingMode);
	actionDiagnostic_Alerts->setDisabled(
			bPreInitialization || bTrackingMode
					|| (pdtCommandHandling_->dtSystemInformation_.nTypeofSystem
							!= VICRA_SYSTEM
							&& pdtCommandHandling_->dtSystemInformation_.nTypeofSystem
									!= SPECTRA_SYSTEM));
	actionIlluminator_Activation_Rate->setDisabled(
			bPreInitialization || bTrackingMode
					|| pdtCommandHandling_->dtSystemInformation_.nTypeofSystem
							== AURORA_SYSTEM);
	actionCOM_Port_Settings->setDisabled(bTrackingMode);
	actionSROM_Image_File_Settings->setDisabled(bTrackingMode);
	actionProgram_Options->setDisabled(bTrackingMode);

} /* setMode */

void Interface::manipulateCollisionObject() {

	int shape_index = comboBox_Shape->currentIndex();
	int operation_index = comboBox_Operation->currentIndex();

	// if operation is ADD
	if (operation_index == 0) {
		if (lineEdit_CollisionID->text().isEmpty()) {
			ROS_ERROR("Collision ID is empty, Cannot add collision object");
			return;
		}
		switch (shape_index) {
		case 0: {
			//BOX
			if (lineEdit_X_Radius->text().isEmpty()
					|| lineEdit_Y_Height->text().isEmpty()
					|| lineEdit_Z->text().isEmpty()) {
				ROS_ERROR(
						"Certain box dimention is empty, Cannot add collision object");
				return;
			}
			break;
		}
		case 1: {
			//SPHERE
			if (lineEdit_X_Radius->text().isEmpty()) {
				ROS_ERROR(
						"Certain sphere dimention is empty, Cannot add collision object");
				return;
			}
			break;
		}
		case 2: {
			//CYLINDER
			if (lineEdit_X_Radius->text().isEmpty()
					|| lineEdit_Y_Height->text().isEmpty()) {
				ROS_ERROR(
						"Certain cylinder dimention is empty, Cannot add collision object");
				return;
			}
			break;
		}
		case 3: {
			//CONE
			if (lineEdit_X_Radius->text().isEmpty()
					|| lineEdit_Y_Height->text().isEmpty()) {
				ROS_ERROR(
						"Certain cone dimention is empty, Cannot add collision object");
				return;
			}
			break;
		}
		default: {
			return;
		}
		}

		if (lineEdit_TransX->text().isEmpty()
				|| lineEdit_TransY->text().isEmpty()
				|| lineEdit_TransZ->text().isEmpty()
				|| lineEdit_RotateA->text().isEmpty()
				|| lineEdit_RotateB->text().isEmpty()
				|| lineEdit_RotateC->text().isEmpty()) {
			ROS_ERROR(
					"Some descartes value is empty, Cannot add collision object");
			return;
		}
	} else {
		if (listWidget_CurrentCollisionObject->currentItem()->text().isEmpty()) {
			ROS_ERROR("Cannot remove empty collision object");
			return;
		}
	}
	moveit_msgs::CollisionObject collision_object;
	std::vector<double> collision_dimensions;
	collision_dimensions.resize(3);

	shape_msgs::SolidPrimitive collision_primitive;
	// This line has to be done, or the segmentation fault error will appear
	collision_primitive.dimensions.resize(3);

	geometry_msgs::Pose collision_pose;

	QListWidgetItem* collision_item = new QListWidgetItem;

	moveit_msgs::PlanningScene planning_scene;

	geometry_msgs::Pose::_orientation_type collision_quaternion;
	std::vector<double> collision_euler_angle;

	if (operation_index == 0) {
		ROS_INFO("Add collision object");
		collision_dimensions[0] = lineEdit_X_Radius->text().toDouble();
		collision_dimensions[1] = lineEdit_Y_Height->text().toDouble();
		collision_dimensions[2] = lineEdit_Z->text().toDouble();

		ROS_INFO("Shape: %d", shape_index);
		switch (shape_index) {
		case 0: {
			// BOX
			collision_primitive.dimensions[collision_primitive.BOX_X] =
					collision_dimensions[0];
			collision_primitive.dimensions[collision_primitive.BOX_Y] =
					collision_dimensions[1];
			collision_primitive.dimensions[collision_primitive.BOX_Z] =
					collision_dimensions[2];
			collision_primitive.type = collision_primitive.BOX;
			break;
		}
		case 1: {
			// SPHERE
			collision_primitive.dimensions[collision_primitive.SPHERE_RADIUS] =
					collision_dimensions[0];
			collision_primitive.type = collision_primitive.SPHERE;
			break;
		}
		case 2: {
			// CYLINDER
			collision_primitive.dimensions[collision_primitive.CYLINDER_RADIUS] =
					collision_dimensions[0];
			collision_primitive.dimensions[collision_primitive.CYLINDER_HEIGHT] =
					collision_dimensions[1];
			collision_primitive.type = collision_primitive.CYLINDER;
			break;
		}
		case 3: {
			// CONE
			collision_primitive.dimensions[collision_primitive.CONE_RADIUS] =
					collision_dimensions[0];
			collision_primitive.dimensions[collision_primitive.CONE_HEIGHT] =
					collision_dimensions[1];
			collision_primitive.type = collision_primitive.CONE;
			break;
		}
		default: {
			ROS_ERROR("shape index not found");
			return;
		}
		}

		collision_pose.position.x = lineEdit_TransX->text().toDouble() / 1000.0;
		collision_pose.position.y = lineEdit_TransY->text().toDouble() / 1000.0;
		collision_pose.position.z = lineEdit_TransZ->text().toDouble() / 1000.0;

		Eigen::Vector3d EulerAngleVector;
		EulerAngleVector.data()[0] = lineEdit_RotateA->text().toDouble()
				/ 180.0* M_PI;
		EulerAngleVector.data()[1] = lineEdit_RotateB->text().toDouble()
				/ 180.0* M_PI;
		EulerAngleVector.data()[2] = lineEdit_RotateC->text().toDouble()
				/ 180.0* M_PI;
		Eigen::Vector4d q;
		q = Euler2Quaternion(EulerAngleVector.data()[2],
				EulerAngleVector.data()[1], EulerAngleVector.data()[0]);
		collision_pose.orientation.x = q.data()[0];
		collision_pose.orientation.y = q.data()[1];
		collision_pose.orientation.z = q.data()[2];
		collision_pose.orientation.w = q.data()[3];

		collision_object.operation = collision_object.ADD;
		collision_object.primitive_poses.push_back(collision_pose);
		collision_object.primitives.push_back(collision_primitive);
		collision_object.header.frame_id = "world";
		collision_object.id = lineEdit_CollisionID->text().toStdString();
		collision_object.header.stamp = ros::Time::now();
		collision_object.header.seq = nCollisionOperationCount_++;

		planning_scene.world.collision_objects.clear();
		planning_scene.world.collision_objects.push_back(collision_object);

		planning_scene.is_diff = true;
		dtPlanningSceneDiffPublisher_.publish(planning_scene);

		collision_item->setText(lineEdit_CollisionID->text());
		listWidget_CurrentCollisionObject->insertItem(1, collision_item);

	} else if (operation_index == 1) {
		ROS_INFO("Remove collision object");

		collision_object.operation = collision_object.REMOVE;
		collision_object.id =
				listWidget_CurrentCollisionObject->currentItem()->text().toStdString();

		planning_scene.world.collision_objects.clear();
		planning_scene.world.collision_objects.push_back(collision_object);
		planning_scene.is_diff = true;

		dtPlanningSceneDiffPublisher_.publish(planning_scene);

		listWidget_CurrentCollisionObject->removeItemWidget(
				listWidget_CurrentCollisionObject->currentItem());
		delete listWidget_CurrentCollisionObject->currentItem();
	}

}
//TODO: Do remember the Euler angle has singularity
//RPY(roll,pitch,yaw) == RPY( roll +/- PI, PI-pitch, yaw +/- PI )
//Avoid with +-90 and +-180 for ABC angle value !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Interface::visualizeJointPlan() {

	if (lineEdit_Joint1->text().isEmpty() || lineEdit_Joint2->text().isEmpty()
			|| lineEdit_Joint3->text().isEmpty()
			|| lineEdit_Joint4->text().isEmpty()
			|| lineEdit_Joint5->text().isEmpty()
			|| lineEdit_Joint6->text().isEmpty()) {
		ROS_ERROR("Some joint value is empty, Cannot plan a motion");
		return;
	}

	std::map<std::string, double> target_joints;
	target_joints["joint1"] = lineEdit_Joint1->text().toDouble() / 180.0 * M_PI;
	target_joints["joint2"] = lineEdit_Joint2->text().toDouble() / 180.0 * M_PI;
	target_joints["joint3"] = lineEdit_Joint3->text().toDouble() / 180.0 * M_PI;
	target_joints["joint4"] = lineEdit_Joint4->text().toDouble() / 180.0 * M_PI;
	target_joints["joint5"] = lineEdit_Joint5->text().toDouble() / 180.0 * M_PI;
	target_joints["joint6"] = lineEdit_Joint6->text().toDouble() / 180.0 * M_PI;

	if (!dtController_.planTargetMotion(target_joints)) {
		ROS_ERROR("Motion plan failed");
		return;
	}
	pushButton_ExecutePlan->setEnabled(true);
}
void Interface::visualizePosePlan() {

	if (lineEdit_TransX->text().isEmpty() || lineEdit_TransY->text().isEmpty()
			|| lineEdit_TransZ->text().isEmpty()
			|| lineEdit_RotateA->text().isEmpty()
			|| lineEdit_RotateB->text().isEmpty()
			|| lineEdit_RotateC->text().isEmpty()) {
		ROS_ERROR("Some descartes value is empty, Cannot plan a motion");
		return;
	}

	geometry_msgs::Pose target_pose;
	target_pose.position.x = lineEdit_TransX->text().toDouble() / 1000.0;
	target_pose.position.y = lineEdit_TransY->text().toDouble() / 1000.0;
	target_pose.position.z = lineEdit_TransZ->text().toDouble() / 1000.0;

	Eigen::Vector3d EulerAngleVector;
	EulerAngleVector.data()[0] = lineEdit_RotateA->text().toDouble()
			/ 180.0* M_PI;
	EulerAngleVector.data()[1] = lineEdit_RotateB->text().toDouble()
			/ 180.0* M_PI;
	EulerAngleVector.data()[2] = lineEdit_RotateC->text().toDouble()
			/ 180.0* M_PI;

	Eigen::Vector4d Quaternion;
	Quaternion = Euler2Quaternion(EulerAngleVector.data()[2], EulerAngleVector.data()[1],
			EulerAngleVector.data()[0]);

	target_pose.orientation.x = Quaternion.data()[0];
	target_pose.orientation.y = Quaternion.data()[1];
	target_pose.orientation.z = Quaternion.data()[2];
	target_pose.orientation.w = Quaternion.data()[3];

	if (!dtController_.planTargetMotion(target_pose, "tip")) {
		ROS_ERROR("Motion plan failed");
		return;
	}
	pushButton_ExecutePlan->setEnabled(true);
}
void Interface::visualizeIncrPosePlan() {

	if (output_x->toPlainText().isEmpty() || output_y->toPlainText().isEmpty()
			|| output_z->toPlainText().isEmpty()
			|| lineEdit_incrTransX->text().isEmpty()
			|| lineEdit_incrTransY->text().isEmpty()
			|| lineEdit_incrTransZ->text().isEmpty()
			|| lineEdit_incrRotateA->text().isEmpty()
			|| lineEdit_incrRotateB->text().isEmpty()
			|| lineEdit_incrRotateC->text().isEmpty()) {
		ROS_ERROR("Some descartes value is empty, Cannot plan a motion");
		return;
	}

	geometry_msgs::Pose target_pose;
	target_pose.position.x = (output_x->toPlainText().toDouble()
			+ lineEdit_incrTransX->text().toDouble()) / 1000.0;
	target_pose.position.y = (output_y->toPlainText().toDouble()
			+ lineEdit_incrTransY->text().toDouble()) / 1000.0;
	target_pose.position.z = (output_z->toPlainText().toDouble()
			+ lineEdit_incrTransZ->text().toDouble()) / 1000.0;

	Eigen::Vector3d EulerAngleVector;
	EulerAngleVector.data()[0] = output_a->toPlainText().toDouble() / 180.0
			* M_PI + lineEdit_incrRotateA->text().toDouble() / 180.0 * M_PI;
	EulerAngleVector.data()[1] = output_b->toPlainText().toDouble() / 180.0
			* M_PI + lineEdit_incrRotateB->text().toDouble() / 180.0 * M_PI;
	EulerAngleVector.data()[2] = output_c->toPlainText().toDouble() / 180.0
			* M_PI + lineEdit_incrRotateC->text().toDouble() / 180.0 * M_PI;

	Eigen::Vector4d Quarternion;
	Quarternion = Euler2Quaternion(EulerAngleVector.data()[2], EulerAngleVector.data()[1],
			EulerAngleVector.data()[0]);
	target_pose.orientation.x = Quarternion.data()[0];
	target_pose.orientation.y = Quarternion.data()[1];
	target_pose.orientation.z = Quarternion.data()[2];
	target_pose.orientation.w = Quarternion.data()[3];

	if (!dtController_.planTargetMotion(target_pose, "tip")) {
		ROS_ERROR("Motion plan failed");
		return;
	}
	pushButton_ExecutePlan->setEnabled(true);
}
void Interface::addWaypoints() {
	if (lineEdit_TransX->text().isEmpty() || lineEdit_TransY->text().isEmpty()
			|| lineEdit_TransZ->text().isEmpty()
			|| lineEdit_RotateA->text().isEmpty()
			|| lineEdit_RotateB->text().isEmpty()
			|| lineEdit_RotateC->text().isEmpty()) {
		ROS_ERROR("Some descartes value is empty, Cannot add as a waypoint");
		return;
	}

	geometry_msgs::Pose target_pose;
	target_pose.position.x = lineEdit_TransX->text().toDouble() / 1000.0;
	target_pose.position.y = lineEdit_TransY->text().toDouble() / 1000.0;
	target_pose.position.z = lineEdit_TransZ->text().toDouble() / 1000.0;

	Eigen::Vector3d EulerAngleVector;
	EulerAngleVector.data()[0] = lineEdit_RotateA->text().toDouble()
			/ 180.0* M_PI;
	EulerAngleVector.data()[1] = lineEdit_RotateB->text().toDouble()
			/ 180.0* M_PI;
	EulerAngleVector.data()[2] = lineEdit_RotateC->text().toDouble()
			/ 180.0* M_PI;

	Eigen::Vector4d Quarternion;
	Quarternion = Euler2Quaternion(EulerAngleVector.data()[2], EulerAngleVector.data()[1],
			EulerAngleVector.data()[0]);
	target_pose.orientation.x = Quarternion.data()[0];
	target_pose.orientation.y = Quarternion.data()[1];
	target_pose.orientation.z = Quarternion.data()[2];
	target_pose.orientation.w = Quarternion.data()[3];

	dtController_.addWaypoints(target_pose);
	pushButton_ExecuteWaypointsPlan->setEnabled(true);
}
void Interface::rotateAroundAxis() {

	if (output_x->toPlainText().isEmpty() || output_y->toPlainText().isEmpty()
			|| output_z->toPlainText().isEmpty()
			|| output_a->toPlainText().isEmpty()
			|| output_b->toPlainText().isEmpty()
			|| output_c->toPlainText().isEmpty()) {
		ROS_ERROR("Some feedback value is empty, Cannot plan a rotate motion");
		return;
	}

	// Axis type
	int axis_type = comboBox_AxisType->currentIndex();
	// Pose target
	geometry_msgs::Pose target_pose;
	// Euler angle
	Eigen::Vector3d EulerAngleVector;
	std::vector<double> euler_angle_rotate(3);
	// dtRotation matrix
	KDL::Rotation dtRotation;

	target_pose.position.x = output_x->toPlainText().toDouble() / 1000.0;
	target_pose.position.y = output_y->toPlainText().toDouble() / 1000.0;
	target_pose.position.z = output_z->toPlainText().toDouble() / 1000.0;

	// position of TCP
	KDL::Vector vector(target_pose.position.x, target_pose.position.y,
			target_pose.position.z);
	KDL::Vector vector_rotate;

	EulerAngleVector.data()[0] = output_a->toPlainText().toDouble()
			/ 180.0* M_PI;
	EulerAngleVector.data()[1] = output_b->toPlainText().toDouble()
			/ 180.0* M_PI;
	EulerAngleVector.data()[2] = output_c->toPlainText().toDouble()
			/ 180.0* M_PI;

	// rotate degree
	double rotate_degree = lineEdit_RotateDegree->text().toDouble();

	switch (axis_type) {
	case Interface::X: {
		dtRotation = KDL::Rotation::RotX(rotate_degree / 180.0 * M_PI)
				* KDL::Rotation::RPY(EulerAngleVector.data()[2],
						EulerAngleVector.data()[1], EulerAngleVector.data()[0]);
		vector_rotate = KDL::Rotation::RotX(rotate_degree / 180.0 * M_PI)
				* vector;
		break;
	}
	case Interface::Y: {
		dtRotation = KDL::Rotation::RotY(rotate_degree / 180.0 * M_PI)
				* KDL::Rotation::RPY(EulerAngleVector.data()[2],
						EulerAngleVector.data()[1], EulerAngleVector.data()[0]);
		vector_rotate = KDL::Rotation::RotY(rotate_degree / 180.0 * M_PI)
				* vector;
		break;
	}
	case Interface::Z: {
		dtRotation = KDL::Rotation::RotZ(rotate_degree / 180.0 * M_PI)
				* KDL::Rotation::RPY(EulerAngleVector.data()[2],
						EulerAngleVector.data()[1], EulerAngleVector.data()[0]);
		vector_rotate = KDL::Rotation::RotZ(rotate_degree / 180.0 * M_PI)
				* vector;
		break;
	}
	case Interface::Custom: {
		// custom rotate axis
		KDL::Vector rotate_axis(lineEdit_AxisVectorX->text().toDouble(),
				lineEdit_AxisVectorY->text().toDouble(),
				lineEdit_AxisVectorZ->text().toDouble());
		dtRotation = KDL::Rotation::Rot(rotate_axis,
				rotate_degree / 180.0 * M_PI)
				* KDL::Rotation::RPY(EulerAngleVector.data()[2],
						EulerAngleVector.data()[1], EulerAngleVector.data()[0]);
		vector_rotate = KDL::Rotation::Rot(rotate_axis,
				rotate_degree / 180.0 * M_PI) * vector;
		break;
	}
	default: {
		ROS_ERROR("Axis type is wrong");
	}
	}

	dtRotation.GetQuaternion(target_pose.orientation.x,
			target_pose.orientation.y, target_pose.orientation.z,
			target_pose.orientation.w);

	target_pose.position.x = vector_rotate.data[0] / 1000.0;
	target_pose.position.y = vector_rotate.data[1] / 1000.0;
	target_pose.position.z = vector_rotate.data[2] / 1000.0;

	if (!dtController_.planTargetMotion(target_pose, "tip")) {
		ROS_ERROR("motion plan failed");
		return;
	}

	pushButton_ExecuteRotatePlan->setEnabled(true);

}
void Interface::executeMotionPlan() {

	if (dtController_.executeMotionPlan()) {
		pushButton_ExecutePlan->setEnabled(false);
	}
}

void Interface::newFeedbackReceived(Feedback* feedback) {

	Axis AxisFeedback;
	AxisFeedback = feedback->getAxis();

	nJointStatePublishCount_++;
	dtJointState_.header.seq = nJointStatePublishCount_;
	dtJointState_.position[0] = AxisFeedback.A1 / 180.0 * M_PI;
	dtJointState_.position[1] = AxisFeedback.A2 / 180.0 * M_PI;
	dtJointState_.position[2] = AxisFeedback.A3 / 180.0 * M_PI;
	dtJointState_.position[3] = AxisFeedback.A4 / 180.0 * M_PI;
	dtJointState_.position[4] = AxisFeedback.A5 / 180.0 * M_PI;
	dtJointState_.position[5] = AxisFeedback.A6 / 180.0 * M_PI;
	dtJointState_.header.stamp = ros::Time::now();
	dtJointStatePublisher_.publish(dtJointState_);
}
void Interface::visualizeMotionPlan(
		moveit::planning_interface::MoveGroup::Plan motion_plan) {

	ROS_INFO("Visualizing plan");

	dtDisplayTrajectory_.trajectory_start = motion_plan.start_state_;
	dtDisplayTrajectory_.trajectory.push_back(motion_plan.trajectory_);

	dtDisplayPublisher_.publish(dtDisplayTrajectory_);
}

void Interface::shutdown() {
	//QApplication::exit();
	//ros::shutdown();
}

// Callback function
//void Interface::trajectoryActionCb(const TrajectoryGoal& feedback) {
//	ROS_INFO("Trajectory received.");
//	emit sendTrajectory(feedback);
//}
void Interface::addWaypointsCb() {
	ROS_INFO("Interface: add way points callback");
	emit addWaypointsSignal();
}
void Interface::visualizeExecutePlanCb() {
	ROS_INFO("Interface: visualize and execute plan callback");
	emit visualizeExecutePlan();
}
void Interface::endEffectorPosCb(
		const InteractiveMarkerFeedbackConstPtr &feedback) {
	lineEdit_TransX->setText(
			QString("%1").arg(feedback->pose.position.x * 1000.0, 8, 'f', 4));
	lineEdit_TransY->setText(
			QString("%1").arg(feedback->pose.position.y * 1000.0, 8, 'f', 4));
	lineEdit_TransZ->setText(
			QString("%1").arg(feedback->pose.position.z * 1000.0, 8, 'f', 4));

	Eigen::Vector3d EulerAngleVector;
	KDL::Rotation dtRotation = KDL::Rotation::Quaternion(
			feedback->pose.orientation.x, feedback->pose.orientation.y,
			feedback->pose.orientation.z, feedback->pose.orientation.w);
	dtRotation.GetRPY(EulerAngleVector.data()[2], EulerAngleVector.data()[1],
			EulerAngleVector.data()[0]);
	lineEdit_RotateA->setText(
			QString("%1").arg(EulerAngleVector.data()[0] / M_PI * 180.0, 8, 'f',
					4));
	lineEdit_RotateB->setText(
			QString("%1").arg(EulerAngleVector.data()[1] / M_PI * 180.0, 8, 'f',
					4));
	lineEdit_RotateC->setText(
			QString("%1").arg(EulerAngleVector.data()[2] / M_PI * 180.0, 8, 'f',
					4));

	Frame temp_frame(feedback->pose.position.x * 1000.0,
			feedback->pose.position.y * 1000.0,
			feedback->pose.position.z * 1000.0,
			EulerAngleVector.data()[0] / M_PI * 180.0,
			EulerAngleVector.data()[1] / M_PI * 180.0,
			EulerAngleVector.data()[2] / M_PI * 180.0);
	Axis temp_axis;
	dtController_.getPlannar()->getModel().Frame2Axis(dtLastAxis_, temp_frame,
			temp_axis);
	dtLastAxis_.set(temp_axis);

	lineEdit_Joint1->setText(QString("%1").arg(temp_axis.A1, 8, 'f', 4));
	lineEdit_Joint2->setText(QString("%1").arg(temp_axis.A2, 8, 'f', 4));
	lineEdit_Joint3->setText(QString("%1").arg(temp_axis.A3, 8, 'f', 4));
	lineEdit_Joint4->setText(QString("%1").arg(temp_axis.A4, 8, 'f', 4));
	lineEdit_Joint5->setText(QString("%1").arg(temp_axis.A5, 8, 'f', 4));
	lineEdit_Joint6->setText(QString("%1").arg(temp_axis.A6, 8, 'f', 4));

	emit endEffectorPos(feedback);
}
void addWaypointsCb_global(const InteractiveMarkerFeedbackConstPtr &feedback) {
	// The Workaround of the MenuHandler insert function problem
	ROS_INFO("Global: add way points");
	kuka_interface->addWaypointsCb();
}
void visualizeExecutePlanCb_global(
		const InteractiveMarkerFeedbackConstPtr &feedback) {
	// The Workaround of the MenuHandler insert function problem
	ROS_INFO("Global: visualize and execute plan");
	kuka_interface->visualizeExecutePlanCb();
}

// Menu Interaction related
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

	pdtInteractiveMarkerServer_->insert(int_marker);
}
void Interface::initMenu() {

	vecdtMenuEntry_.push_back(
			dtMenuHandler_.insert("Add into way points",
					addWaypointsCb_global));
	vecdtMenuEntry_.push_back(
			dtMenuHandler_.insert("Visualize and Execute motion plan",
					visualizeExecutePlanCb_global));
}

// Functions for Sing Command Tab
void Interface::on_send_frame_button_clicked() {
	Frame f(input_x->toPlainText().toFloat(), input_y->toPlainText().toFloat(),
			input_z->toPlainText().toFloat(), input_a->toPlainText().toFloat(),
			input_b->toPlainText().toFloat(), input_c->toPlainText().toFloat());
	Command::Style style;
	Command::Approx approx;
	if (comboBox_approx->currentText() == "C_PTP")
		approx = Command::C_PTP;
	else if (comboBox_approx->currentText() == "C_VEL")
		approx = Command::C_VEL;
	else if (comboBox_approx->currentText() == "C_DIS")
		approx = Command::C_DIS;
	else if (comboBox_approx->currentText() == "C_ORI")
		approx = Command::C_ORI;
	else if (comboBox_approx->currentText() == "None")
		approx = Command::NONE;
	else {
		std::cout << "To Frame: Approx. not recognized, None is used"
				<< std::endl;
		approx = Command::NONE;
	}

	if (comboBox_style->currentText() == "PTP")
		style = Command::PTP;
	else if (comboBox_style->currentText() == "LIN")
		style = Command::LIN;
	else if (comboBox_style->currentText() == "CIRC") {
		std::cout << "To Frame: CIRC command not supported in GUI, PTP is used"
				<< std::endl;
		style = Command::PTP;
	} else {
		std::cout << "To Frame: Style not recognized, PTP is used" << std::endl;
		style = Command::PTP;
	}

	ROS_INFO("Send frame button clicked");
	pdtPlannar_->motion(style, f, approx);
}

void Interface::on_send_axis_button_clicked() {
	Axis a(input_a1->toPlainText().toFloat(), input_a2->toPlainText().toFloat(),
			input_a3->toPlainText().toFloat(),
			input_a4->toPlainText().toFloat(),
			input_a5->toPlainText().toFloat(),
			input_a6->toPlainText().toFloat());

	Command::Style style;
	Command::Approx approx;
	if (comboBox_approx->currentText() == "C_PTP")
		approx = Command::C_PTP;
	else if (comboBox_approx->currentText() == "C_VEL")
		approx = Command::C_VEL;
	else if (comboBox_approx->currentText() == "C_DIS")
		approx = Command::C_DIS;
	else if (comboBox_approx->currentText() == "C_ORI")
		approx = Command::C_ORI;
	else if (comboBox_approx->currentText() == "None")
		approx = Command::NONE;
	else {
		std::cout << "To Axis: Approx. not recognized, None is used"
				<< std::endl;
		approx = Command::NONE;
	}

	if (comboBox_style->currentText() == "PTP")
		style = Command::PTP;
	else if (comboBox_style->currentText() == "LIN")
		style = Command::LIN;
	else if (comboBox_style->currentText() == "CIRC") {
		std::cout << "To Axis: CIRC command not supported in GUI, PTP is used"
				<< std::endl;
		style = Command::PTP;
	} else {
		std::cout << "To Axis: Style not recognized, PTP is used" << std::endl;
		style = Command::PTP;
	}

	ROS_INFO("Send axis button clicked");
	pdtPlannar_->motion(style, a, approx);
}

void Interface::on_send_pos_button_clicked() {
	Frame f(input_x->toPlainText().toFloat(), input_y->toPlainText().toFloat(),
			input_z->toPlainText().toFloat(), input_a->toPlainText().toFloat(),
			input_b->toPlainText().toFloat(), input_c->toPlainText().toFloat());
	Pos p(f, input_s->toPlainText().toInt(), input_t->toPlainText().toInt());

	Command::Style style;
	Command::Approx approx;
	if (comboBox_approx->currentText() == "C_PTP")
		approx = Command::C_PTP;
	else if (comboBox_approx->currentText() == "C_VEL")
		approx = Command::C_VEL;
	else if (comboBox_approx->currentText() == "C_DIS")
		approx = Command::C_DIS;
	else if (comboBox_approx->currentText() == "C_ORI")
		approx = Command::C_ORI;
	else if (comboBox_approx->currentText() == "None")
		approx = Command::NONE;
	else {
		std::cout << "To Pos: Approx. not recognized, None is used"
				<< std::endl;
		approx = Command::NONE;
	}

	if (comboBox_style->currentText() == "PTP")
		style = Command::PTP;
	else if (comboBox_style->currentText() == "LIN")
		style = Command::LIN;
	else if (comboBox_style->currentText() == "CIRC") {
		std::cout << "To Pos: CIRC command not supported in GUI, PTP is used"
				<< std::endl;
		style = Command::PTP;
	} else {
		std::cout << "To Pos: Style not recognized, PTP is used" << std::endl;
		style = Command::PTP;
	}

	ROS_INFO("Send pos button clicked");
	pdtPlannar_->motion(style, p, approx);
}

void Interface::displayFeedback(Feedback* feedback) {

	if (!feedback->getSetOK() || !feedback->getParsedOK()) {
		output_message->setText("Feedback parsing failed");
		QPalette pm = output_message->palette();
		pm.setColor(QPalette::Base, QColor(170, 0, 0));
		output_message->setPalette(pm);
		return;
	}

	Axis AxisFeedback;
	Frame FrameFeedback;
	AxisFeedback = feedback->getAxis();
	dtLastAxis_.set(AxisFeedback);
	pdtPlannar_->getModel().Axis2Frame(AxisFeedback, FrameFeedback);

	if (feedback->getBufferExtreme() == feedback->Empty) {
		bMotionComplete_ = true;
	} else {
		bMotionComplete_ = false;
	}

	nJointStateDisplayCount_++;
	if (nJointStateDisplayCount_ >= 10) {
		output_a1->setText(QString("%1").arg(AxisFeedback.A1, 8, 'f', 4));
		output_a2->setText(QString("%1").arg(AxisFeedback.A2, 8, 'f', 4));
		output_a3->setText(QString("%1").arg(AxisFeedback.A3, 8, 'f', 4));
		output_a4->setText(QString("%1").arg(AxisFeedback.A4, 8, 'f', 4));
		output_a5->setText(QString("%1").arg(AxisFeedback.A5, 8, 'f', 4));
		output_a6->setText(QString("%1").arg(AxisFeedback.A6, 8, 'f', 4));

		output_x->setText(QString("%1").arg(FrameFeedback.X, 8, 'f', 4));
		output_y->setText(QString("%1").arg(FrameFeedback.Y, 8, 'f', 4));
		output_z->setText(QString("%1").arg(FrameFeedback.Z, 8, 'f', 4));
		output_a->setText(QString("%1").arg(FrameFeedback.A, 8, 'f', 4));
		output_b->setText(QString("%1").arg(FrameFeedback.B, 8, 'f', 4));
		output_c->setText(QString("%1").arg(FrameFeedback.C, 8, 'f', 4));

		output_s->setText(QString::number(feedback->getPos().S));
		output_t->setText(QString::number(feedback->getPos().T));

		output_buf_front->setText(QString::number(feedback->getBufferFront()));
		output_buf_last->setText(QString::number(feedback->getBufferLast()));

		output_seq->setText(QString::number(feedback->getSeq()));
		output_result->setText(QString::number(feedback->getStamp()));

		if (feedback->getText() != "Timer Feedback")
			output_message->setText(
					QString::fromStdString(feedback->getText()));

		if (feedback->getBufferExtreme() == Feedback::Full) {
			QPalette pf = output_buf_front->palette();
			pf.setColor(QPalette::Base, QColor(170, 0, 0));
			output_buf_front->setPalette(pf);

			QPalette pl = output_buf_last->palette();
			pl.setColor(QPalette::Base, QColor(170, 0, 0));
			output_buf_last->setPalette(pl);
		} else {
			QPalette pf = output_buf_front->palette();
			pf.setColor(QPalette::Base, QColor(0, 170, 0));
			output_buf_front->setPalette(pf);

			QPalette pl = output_buf_last->palette();
			pl.setColor(QPalette::Base, QColor(0, 170, 0));
			output_buf_last->setPalette(pl);
		}

		if (feedback->getSuccess() == 0
				&& feedback->getType() == Feedback::Hybrid) {
			QPalette pr = output_result->palette();
			pr.setColor(QPalette::Base, QColor(170, 0, 0));
			output_result->setPalette(pr);
		} else if (feedback->getType() == Feedback::Hybrid) {
			QPalette pr = output_result->palette();
			pr.setColor(QPalette::Base, QColor(0, 170, 0));
			output_result->setPalette(pr);
		}
		nJointStateDisplayCount_ = 0;
	}

}
void Interface::convertPoseTargettoJointTarget() {

	if (lineEdit_TransX->text().isEmpty() || lineEdit_TransY->text().isEmpty()
			|| lineEdit_TransZ->text().isEmpty()
			|| lineEdit_RotateA->text().isEmpty()
			|| lineEdit_RotateB->text().isEmpty()
			|| lineEdit_RotateC->text().isEmpty()) {
		ROS_ERROR(
				"Some descartes value is empty, Cannot convert pose target to joint target");
		return;
	}

	Frame temp_frame(lineEdit_TransX->text().toDouble(),
			lineEdit_TransY->text().toDouble(),
			lineEdit_TransZ->text().toDouble(),
			lineEdit_RotateA->text().toDouble(),
			lineEdit_RotateB->text().toDouble(),
			lineEdit_RotateC->text().toDouble());
	Axis temp_axis;

	dtController_.getPlannar()->getModel().Frame2Axis(dtLastAxis_, temp_frame,
			temp_axis);
	dtLastAxis_.set(temp_axis);

	lineEdit_Joint1->setText(QString("%1").arg(temp_axis.A1, 8, 'f', 4));
	lineEdit_Joint2->setText(QString("%1").arg(temp_axis.A2, 8, 'f', 4));
	lineEdit_Joint3->setText(QString("%1").arg(temp_axis.A3, 8, 'f', 4));
	lineEdit_Joint4->setText(QString("%1").arg(temp_axis.A4, 8, 'f', 4));
	lineEdit_Joint5->setText(QString("%1").arg(temp_axis.A5, 8, 'f', 4));
	lineEdit_Joint6->setText(QString("%1").arg(temp_axis.A6, 8, 'f', 4));

}

void Interface::on_convert_button_clicked() {
	Frame temp_frame(input_x->toPlainText().toDouble(),
			input_y->toPlainText().toDouble(),
			input_z->toPlainText().toDouble(),
			input_a->toPlainText().toDouble(),
			input_b->toPlainText().toDouble(),
			input_c->toPlainText().toDouble());
	Axis temp_axis;

	dtController_.getPlannar()->getModel().Frame2Axis(dtLastAxis_, temp_frame,
			temp_axis);
	dtLastAxis_.set(temp_axis);

	output_a1->setText(QString("%1").arg(temp_axis.A1, 8, 'f', 4));
	output_a2->setText(QString("%1").arg(temp_axis.A2, 8, 'f', 4));
	output_a3->setText(QString("%1").arg(temp_axis.A3, 8, 'f', 4));
	output_a4->setText(QString("%1").arg(temp_axis.A4, 8, 'f', 4));
	output_a5->setText(QString("%1").arg(temp_axis.A5, 8, 'f', 4));
	output_a6->setText(QString("%1").arg(temp_axis.A6, 8, 'f', 4));
}
void Interface::on_copy_button_clicked() {
// Single Command tab
	input_x->setText(output_x->toPlainText());
	input_y->setText(output_y->toPlainText());
	input_z->setText(output_z->toPlainText());
	input_a->setText(output_a->toPlainText());
	input_b->setText(output_b->toPlainText());
	input_c->setText(output_c->toPlainText());

	input_s->setText(output_s->toPlainText());
	input_t->setText(output_t->toPlainText());

	input_a1->setText(output_a1->toPlainText());
	input_a2->setText(output_a2->toPlainText());
	input_a3->setText(output_a3->toPlainText());
	input_a4->setText(output_a4->toPlainText());
	input_a5->setText(output_a5->toPlainText());
	input_a6->setText(output_a6->toPlainText());
// Path Planning tab
	// this tab the x y z is presented in meter unit
	lineEdit_TransX->setText(
			QString("%1").arg(output_x->toPlainText().toDouble(), 8, 'f', 4));
	lineEdit_TransY->setText(
			QString("%1").arg(output_y->toPlainText().toDouble(), 8, 'f', 4));
	lineEdit_TransZ->setText(
			QString("%1").arg(output_z->toPlainText().toDouble(), 8, 'f', 4));
	lineEdit_RotateA->setText(output_a->toPlainText());
	lineEdit_RotateB->setText(output_b->toPlainText());
	lineEdit_RotateC->setText(output_c->toPlainText());

	lineEdit_Joint1->setText(output_a1->toPlainText());
	lineEdit_Joint2->setText(output_a2->toPlainText());
	lineEdit_Joint3->setText(output_a3->toPlainText());
	lineEdit_Joint4->setText(output_a4->toPlainText());
	lineEdit_Joint5->setText(output_a5->toPlainText());
	lineEdit_Joint6->setText(output_a6->toPlainText());

	ROS_INFO("Copy button clicked");
	//setAlignment();
}

void Interface::on_default_button_clicked() {
	input_x->setText(QString("%1").arg( DEFAULT_X, 8, 'f', 4));
	input_y->setText(QString("%1").arg( DEFAULT_Y, 8, 'f', 4));
	input_z->setText(QString("%1").arg( DEFAULT_Z, 8, 'f', 4));
	input_a->setText(QString("%1").arg( DEFAULT_A, 8, 'f', 4));
	input_b->setText(QString("%1").arg( DEFAULT_B, 8, 'f', 4));
	input_c->setText(QString("%1").arg( DEFAULT_C, 8, 'f', 4));

	input_s->setText(QString::number(DEFAULT_S));
	input_t->setText(QString::number(DEFAULT_T));

	input_a1->setText(QString("%1").arg( DEFAULT_A1, 8, 'f', 4));
	input_a2->setText(QString("%1").arg( DEFAULT_A2, 8, 'f', 4));
	input_a3->setText(QString("%1").arg( DEFAULT_A3, 8, 'f', 4));
	input_a4->setText(QString("%1").arg( DEFAULT_A4, 8, 'f', 4));
	input_a5->setText(QString("%1").arg( DEFAULT_A5, 8, 'f', 4));
	input_a6->setText(QString("%1").arg( DEFAULT_A6, 8, 'f', 4));

	ROS_INFO("Default button clicked");
	//setAlignment();
}

void Interface::on_debug_button_clicked() {
	ROS_INFO("Debug button clicked");
	//plannar_ptr_->test();
	rotateAroundAxis();
}

void Interface::on_send_config_button_clicked() {
	Command::Param param;
	float value;
	int ok = true;
	if (comboBox_config->currentText() == "$ADVANCE")
		param = Command::ADVANCE;
	else if (comboBox_config->currentText() == "$ACC_PTP")
		param = Command::ACC_PTP;
	else if (comboBox_config->currentText() == "$VEL_PTP")
		param = Command::VEL_PTP;
	else if (comboBox_config->currentText() == "$ACC_CP")
		param = Command::ACC_CP;
	else if (comboBox_config->currentText() == "$ACC.ORI1")
		param = Command::ACC_ORI1;
	else if (comboBox_config->currentText() == "$ACC.ORI2")
		param = Command::ACC_ORI2;
	else if (comboBox_config->currentText() == "$VEL_CP")
		param = Command::VEL_CP;
	else if (comboBox_config->currentText() == "$VEL.ORI1")
		param = Command::VEL_ORI1;
	else if (comboBox_config->currentText() == "$VEL.ORI2")
		param = Command::VEL_ORI2;
	else if (comboBox_config->currentText() == "$APO.CPTP")
		param = Command::APO_CPTP;
	else if (comboBox_config->currentText() == "$APO.CDIS")
		param = Command::APO_CDIS;
	else if (comboBox_config->currentText() == "$APO.CVEL")
		param = Command::APO_CVEL;
	else if (comboBox_config->currentText() == "$APO.CORI")
		param = Command::APO_CORI;
	else {
		std::cout << "Config: Parameter not recognized" << std::endl;
		ok = false;
	}
	value = input_config->toPlainText().toFloat();
	if (ok)
		pdtPlannar_->configuration(param, value);

	ROS_INFO("Send config button clicked");

}

void Interface::on_pause_buf_buton_clicked() {
	pdtPlannar_->pauseBuffered();
	ROS_INFO("Pause buffer button clicked");
}

void Interface::on_terminate_imm_button_clicked() {
	pdtPlannar_->terminateImmediately();
	ROS_INFO("Terminate immediately button clicked");
}

void Interface::on_pause_button_clicked() {
	pdtPlannar_->pauseImmediately();
	ROS_INFO("Pause immediately button clicked");
}

void Interface::on_stop_button_clicked() {
	pdtPlannar_->stop();
	ROS_INFO("Stop button clicked");
}

void Interface::on_terminate_buf_button_clicked() {
	pdtPlannar_->terminateBuffered();
	ROS_INFO("Terminate buffer button clicked");
}

void Interface::setAlignment() {
	input_x->setAlignment(Qt::AlignRight);
	input_y->setAlignment(Qt::AlignRight);
	input_z->setAlignment(Qt::AlignRight);
	input_a->setAlignment(Qt::AlignRight);
	input_b->setAlignment(Qt::AlignRight);
	input_c->setAlignment(Qt::AlignRight);
	input_a1->setAlignment(Qt::AlignRight);
	input_a2->setAlignment(Qt::AlignRight);
	input_a3->setAlignment(Qt::AlignRight);
	input_a4->setAlignment(Qt::AlignRight);
	input_a5->setAlignment(Qt::AlignRight);
	input_a6->setAlignment(Qt::AlignRight);
	input_s->setAlignment(Qt::AlignRight);
	input_t->setAlignment(Qt::AlignRight);

	output_x->setAlignment(Qt::AlignRight);
	output_y->setAlignment(Qt::AlignRight);
	output_z->setAlignment(Qt::AlignRight);
	output_a->setAlignment(Qt::AlignRight);
	output_b->setAlignment(Qt::AlignRight);
	output_c->setAlignment(Qt::AlignRight);
	output_a1->setAlignment(Qt::AlignRight);
	output_a2->setAlignment(Qt::AlignRight);
	output_a3->setAlignment(Qt::AlignRight);
	output_a4->setAlignment(Qt::AlignRight);
	output_a5->setAlignment(Qt::AlignRight);
	output_a6->setAlignment(Qt::AlignRight);

	output_buf_front->setAlignment(Qt::AlignRight);
	output_buf_last->setAlignment(Qt::AlignRight);
	output_result->setAlignment(Qt::AlignRight);
	output_s->setAlignment(Qt::AlignRight);
	output_t->setAlignment(Qt::AlignRight);
	output_seq->setAlignment(Qt::AlignRight);

	input_config->setAlignment(Qt::AlignRight);
	output_message->setAlignment(Qt::AlignLeft);
}

