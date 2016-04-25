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
/* 	DDX_Control(pDX, IDC_FRAME_NO, m_ctlFrameNo);
	DDX_Control(pDX, IDC_PORT_HANDLES, m_ctlPortHandleCB);
	DDX_Control(pDX, IDC_REFERENCE_HANDLE_CMB, m_ctlRefHandleCB);
	DDX_Control(pDX, IDC_TRACKING_LIST, m_ctlTrackingList);
	DDX_Text(pDX, IDC_FRAME_NO, m_szFrameNumber);
	DDX_Text(pDX, IDC_SYSTEMMODE, m_szSystemMode);
	DDX_Check(pDX, IDC_TRACKING_REPORT_OOV, m_bUse0x0800Option);
	DDX_Check(pDX, IDC_EULER_ANGLES, m_bUseEulerAngles);
	DDX_Radio(pDX, IDC_TRACKING_TX, m_nTrackingMode);
	DDX_Text(pDX, IDC_MANUF_ID, m_szManufID);
	DDX_Check(pDX, IDC_PORT_ENABLED, m_bPortEnabled);
	DDX_Check(pDX, IDC_PORT_INIT, m_bPortInitialized);
	DDX_Text(pDX, IDC_SERIAL_NO, m_szSerialNo);
	DDX_Text(pDX, IDC_TOOL_REV, m_szToolRev);
	DDX_Text(pDX, IDC_TOOL_TYPE, m_szToolType);
	DDX_Text(pDX, IDC_PARTNUMBER, m_szPartNumber); */
Interface::Interface(QMainWindow *parent) :
		controller_(), last_Axis_(0, 0, 0, 0, 0, 0) {

	ROS_INFO("Interface Constructing...");

	setupUi(this);
	setAlignment();

	// pointer to node handle
	node_handle_ = boost::make_shared<ros::NodeHandle>("");

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
	connect(pushButton_ExecuteWaypointsPlan, SIGNAL(clicked()), &controller_,
			SLOT(visualizeExecutePlanCb()));
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
	connect(&SubWindow_COMPortSettings_, SIGNAL(OK_signal()), this,
			SLOT(settingsComPortSettings_OK()));

	connect(actionDiagnostic_Alerts, SIGNAL(triggered()), this,
			SLOT(viewAlertFlags()));
	connect(actionSystem_Properties, SIGNAL(triggered()), this,
			SLOT(viewSystemproperties()));
	connect(actionStart_Tracking, SIGNAL(triggered()), this,
			SLOT(systemStarttracking()));
	connect(actionStop_Tracking, SIGNAL(triggered()), this,
			SLOT(systemStarttracking()));
	connect(actionActivate_Handles, SIGNAL(triggered()), this,
			SLOT(systemActivateports()));
	connect(actionInitialize_System, SIGNAL(triggered()), this,
			SLOT(systemInitializesystem()));

	connect(actionProgram_Options, SIGNAL(triggered()), this,
			SLOT(optionsProgramoptions()));
	connect(&SubWindow_ProgramOptions_, SIGNAL(OK_signal()), this,
			SLOT(optionsProgramoptions_OK()));

	connect(actionIlluminator_Activation_Rate, SIGNAL(triggered()), this,
			SLOT(optionsIlluminatorfiringrate()));
	connect(&SubWindow_IlluminatorFiringRate_, SIGNAL(OK_signal()), this,
			SLOT(optionsIlluminatorfiringrate_OK()));

	connect(actionSROM_Image_File_Settings, SIGNAL(triggered()), this,
			SLOT(settingsRomfilesettings()));
	connect(&SubWindow_ROMFile_, SIGNAL(ReInitialize_signal()), this,
			SLOT(reInitializeSystem()));

	connect(actionExit, SIGNAL(triggered()), this, SLOT(close()));

	connect(comboBox_Port, SIGNAL(currentIndexChanged(int)), this,
			SLOT(selchangePortHandles()));
	connect(comboBox_Reference, SIGNAL(currentIndexChanged(int)), this,
			SLOT(selchangeRefPortHandle()));
	connect(checkBox_HandleEnable, SIGNAL(stateChanged(int)), this,
			SLOT(portEnabled()));

	// Others related
	connect(this, SIGNAL(sendTrajectory(const TrajectoryGoal&)), &controller_,
			SLOT(sendTrajectory(const TrajectoryGoal&)));

	connect(&controller_, SIGNAL(newFeedback(Feedback* )), this,
			SLOT(newFeedbackReceived(Feedback* )));

	connect(&controller_, SIGNAL(newFeedback(Feedback* )), this,
			SLOT(displayFeedback(Feedback* )));

	connect(&controller_, SIGNAL(shutdown()), this, SLOT(shutdown()));
	// When motion plan is obtain in controller_, transfer plan to interface object for visualization
	connect(&controller_, SIGNAL(visualizeMotionPlan(MotionPlan)), this,
			SLOT(visualizeMotionPlan(MotionPlan)));
	connect(this, SIGNAL(addWaypointsSignal()), &controller_,
			SLOT(addWaypointsCb()));
	connect(this, SIGNAL(visualizeExecutePlan()), &controller_,
			SLOT(visualizeExecutePlanCb()));
	connect(this,
			SIGNAL(endEffectorPos(const InteractiveMarkerFeedbackConstPtr&)),
			&controller_,
			SLOT(endEffectorPosCb(const InteractiveMarkerFeedbackConstPtr&)));

	// Set publisher for planned path display
	display_publisher_ =
			node_handle_->advertise<moveit_msgs::DisplayTrajectory>(
					"/move_group/display_planned_path", 1, true);

	// Set publisher for joint state visualization
	joint_state_publisher_ = node_handle_->advertise<sensor_msgs::JointState>(
			"/joint_states", 1000, true);

	// Set subscriber for obtaining interactive marker position
	interactive_marker_subsriber_ =
			node_handle_->subscribe<
					visualization_msgs::InteractiveMarkerFeedback, Interface>(
					"/rviz_moveit_motion_planning_display/robot_interaction_interactive_marker_topic/feedback",
					10, &Interface::endEffectorPosCb, this);

	// Set subscriber for Motion trajectory execution
	motion_trajectory_subsriber_ = node_handle_->subscribe<
			control_msgs::FollowJointTrajectoryActionGoal, Interface>(
			"/joint_trajectory_action/goal", 10, &Interface::trajectoryActionCb,
			this);

	planning_scene_diff_publisher_ = node_handle_->advertise<
			moveit_msgs::PlanningScene>("/planning_scene", 1);

	// Set up menu marker
	marker_pos_ = 0.0;
	interactive_marker_server_.reset(
			new interactive_markers::InteractiveMarkerServer("moveit_test", "",
					false));
	initMenu();
	makeMenuMarker("marker1");
	menu_handler_.apply(*interactive_marker_server_, "marker1");
	interactive_marker_server_->applyChanges();

	// initialize joint state publish count
	joint_state_publish_count_ = 0;
	// allocate memory for position variable
	joint_state_.position.resize(6);
	joint_state_.name.resize(6);
	joint_state_.name[0] = "joint1";
	joint_state_.name[1] = "joint2";
	joint_state_.name[2] = "joint3";
	joint_state_.name[3] = "joint4";
	joint_state_.name[4] = "joint5";
	joint_state_.name[5] = "joint6";
	joint_state_display_counter_ = 0;
	joint_state_callback_counter_ = 0;

	// pointer to plannar_
	plannar_ptr_ = boost::shared_ptr<Plannar>(controller_.getPlannar());

	collision_operation_counter_ = 0;


// NDI related
	CommandHandling_ = boost::make_shared<CommandHandling>();

	SystemMode_ = "Setup Mode";
	lineEdit_Mode->setText(QString(SystemMode_.c_str()));
	setMode( MODE_PRE_INIT );

	StopTracking_ = false;
	IsTracking_ = false;
	ResetHardware_ = false;
	Wireless_ = false;
	SystemInitialized_ = false;
	PortsActivated_ = false;

	COMPort_ = 0;
}

Interface::~Interface() {
	ROS_INFO("Interface Deconstructing...");
	QApplication::exit();
	ros::shutdown();
}

// Slots function
//call back function for GUI push button
/*****************************************************************
Name:				OnTrackingBut

Inputs:
	None.

Return Value:
	None.

Description:   This routine handles what happens when the user
			   presses the Tracking Button.
*****************************************************************/
void Interface::trackingButton()
{
	/* if the text read Start, then we start, else we stop tracking */
	if (  pushButton_StartTracking->accessibleName() == "Start Tracking" )
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
	int
		nBaudRate = 0,
		nStopBits = 0,
		nParity   = 0,
		nDataBits = 0,
		nHardware = 0,
		nWireless = 0;
	COMPort_ = 0;
	Wireless_ = false;
	ResetHardware_ = false;

	/*
	 * read the COM port parameters from the ini file
	 */
	CommandHandling_->ReadINIParam<int>("Communication", "Baud Rate", nBaudRate);
	CommandHandling_->ReadINIParam<int>("Communication", "Stop Bits", nStopBits);
	CommandHandling_->ReadINIParam<int>("Communication", "Parity", nParity);
	CommandHandling_->ReadINIParam<int>("Communication", "Data Bits", nDataBits);
	CommandHandling_->ReadINIParam<int>("Communication", "Hardware", nHardware);
	CommandHandling_->ReadINIParam<int>("Communication", "COM Port", COMPort_);
	CommandHandling_->ReadINIParam<bool>("Communication", "Wireless", Wireless_);
	/*
	 * This feature is useful for debugging only, m_bResetHardware is set to
	 * true to disable it.
	 */
	CommandHandling_->ReadINIParam<bool>("Communication", "Reset Hardware", ResetHardware_);
	/*
	 * close, then open the port
	 */
	CommandHandling_->CloseComPorts();
	if (!CommandHandling_->OpenComPort( COMPort_ ))
	{
		ROS_ERROR("COM ERROR: COM Port could not be opened.  "
		"Check your COM Port settings and\n"
		"make sure you system is turned on.");
		return;
	} /* if */

	/*
	 * if we are supposed to reset, call the reset now
	 */
	if ( ResetHardware_ )
	{
		if (!CommandHandling_->HardWareReset(Wireless_))
			return;
	}/* if */

	/*
	 * get the timeout values for the commands
	 * this will return an error with all other systems, other than Vicra
	 */
	CommandHandling_->CreateTimeoutTable();

	/*
	 * set the System COM Port parameters, then the computers COM Port parameters.
	 * if that is successful, initialize the system
	 */
	if(CommandHandling_->SetSystemComParms( nBaudRate, nDataBits, nParity, nStopBits, nHardware ))
	{
		if(CommandHandling_->SetCompCommParms( nBaudRate, nDataBits, nParity, nStopBits, nHardware ))
		{
			if(CommandHandling_->InitializeSystem())
			{
				/*
				 * get the system information
				 */
				if (!CommandHandling_->GetSystemInfo())
				{
					/*
					 * Check system type: Polaris, Polaris Accedo, and Aurora
					 */
					ROS_ERROR( "INIT ERROR: Could not determine type of system\n"
					"(Polaris, Polaris Accedo, Polaris Vicra or Aurora)");
					return;
				} /* if */

				/*
				 * Set firing rate if system type is Polaris or Polaris Accedo.
				 */
				if( CommandHandling_->SystemInformation_.TypeofSystem != AURORA_SYSTEM )
				{
					CommandHandling_->SetFiringRate();
				}/* if */
				SystemMode_ = "System Initialized";
				lineEdit_Mode->setText(QString(SystemMode_.c_str()));
				setMode( MODE_INIT );
				SystemInitialized_ = true;

				ROS_INFO( "System successfully initialized");
				return;
			} /* if */
			else
			{
				ROS_ERROR( "INIT ERROR: System could not be initialized. "
				"Check your COM Port settings, make sure your\n"
				"system is turned on and the system components are compatible."
				);
			}/* else */
		}/* if */
	}/* if */

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
	COMPort_ = 0;
	Wireless_ = false;
	ResetHardware_ = false;
	/*
	 * read the reset variable from the ini file, this tells us
	 * if you want to reset the system.
	 */
	CommandHandling_->ReadINIParam<int>("Communication", "COM Port", COMPort_);
	CommandHandling_->ReadINIParam<bool>("Communication", "Wireless", Wireless_);
	/*
	 * This feature is useful for debugging only
	 */
	CommandHandling_->ReadINIParam<bool>("Communication", "Reset Hardware", ResetHardware_);

	CommandHandling_->CloseComPorts();

	if (!CommandHandling_->OpenComPort(COMPort_)) {
		ROS_ERROR("COM ERROR: COM Port could not be opened. "
				"Check your COM Port settings and "
				"make sure you system is turned on."
				);
		return;
	} /* if */

	if (ResetHardware_) {
		if (!CommandHandling_->HardWareReset(Wireless_))
			return;

		if (!CommandHandling_->SetSystemComParms(0, 0, 0, 0, 0))
			return;
	} /* if */

	/*
	 * set the new mode
	 */
	SystemMode_ = "Setup Mode";
	lineEdit_Mode->setText(QString(SystemMode_.c_str()));
	setMode (MODE_PRE_INIT);
	ROS_INFO( "System reset successful");
	//UpdateData(false);
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
void Interface::activateHandles()
{
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
int Interface::activatePorts()
{
	char
		pszPortID[9];
	int
		i = 0;

	/*
	 * if we can active the ports, we then fill the port information
	 * on the main dialog
	 */
	if (CommandHandling_->ActivateAllPorts())
	{
		PortsActivated_ = true;
		comboBox_Port->clear();
		comboBox_Reference->clear();

		comboBox_Handle->clear();
		lineEdit_Tx->clear();
		lineEdit_Ty->clear();
		lineEdit_Tz->clear();
		lineEdit_Qx->clear();
		lineEdit_Qy->clear();
		lineEdit_Qz->clear();
		lineEdit_Qo->clear();

		ManufID_ = "";
		PortEnabled_ = false;
		PortInitialized_ = false;
		SerialNo_ = "";
		ToolRev_ = "";
		ToolType_ = "";
		PartNumber_ = "";

		lineEdit_Manufacturer->setText(QString(ManufID_.c_str()));
		lineEdit_Serial->setText(QString(SerialNo_.c_str()));
		lineEdit_Tool->setText(QString(ToolType_.c_str()));
		lineEdit_Tool_2->setText(QString(ToolRev_.c_str()));
		lineEdit_Part->setText(QString(PartNumber_.c_str()));
		checkBox_HandleEnable->setChecked(PortEnabled_);
		checkBox_HandleInitialize->setChecked(PortInitialized_);

		comboBox_Reference->addItem(QString("None"));

		for ( int i = NO_HANDLES; i > 0; i-- )
		{
			if ( CommandHandling_->HandleInformation_[i].HandleInfo.Initialized == 1 )
			{
				sprintf( pszPortID, "%02X", i );
				//TODO:
				//if( CommandHandling_->HandleInformation_[i].ToolType[1] != '8' )
				//{
					//m_ctlTrackingList.InsertItem( 0, NULL );
					//m_ctlTrackingList.SetItemText( 0, 1,
					//	CommandHandling_->HandleInformation_[i].PhysicalPort );

					//m_ctlTrackingList.SetItemText( 0, 0, pszPortID );
				//}/* if */
				comboBox_Port->addItem(QString(pszPortID));
				comboBox_Reference->addItem(QString(pszPortID));
				comboBox_Handle->addItem(QString(pszPortID));
			} /* if */
		} /* for */
		comboBox_Port->setEnabled(true);
		comboBox_Reference->setEnabled(true);
		comboBox_Handle->setEnabled(true);
		// set to no reference tool
		comboBox_Reference->setCurrentIndex(0);
		setMode( MODE_ACTIVATED );

		if (!IsTracking_)
			ROS_INFO( "Ports successfully activated");
		return 1;
	} /* if */

	PortsActivated_ = false;
	ROS_ERROR( "PORT ACTIVATION ERROR: Ports could not be activated.\n"
	"Check your SROM image file settings and\n"
	"make sure your system is turned on and initialized.");
	setMode( MODE_PRE_INIT );
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
int Interface::startTracking()
{
	if ( CommandHandling_->StartTracking() )
	{
		/*
		 * if we can start tracking, set the appropriate window text,
		 * start the tracking thread and set the mode.
		 */
		IsTracking_ = true;
		StopTracking_ = false;

		pushButton_StartTracking->setAccessibleName(QString("Stop Tracking"));
		checkBox_HandleEnable->setEnabled(false);

		SystemMode_ = "System Tracking";
		lineEdit_Mode->setText(QString(SystemMode_.c_str()));
		setMode( MODE_TRACKING );

		if(comboBox_Port->count() > 0) {
			comboBox_Port->setCurrentIndex(0);
			selchangePortHandles();
		}
//TODO: Based on the current index of comboBox_Handle, display corresponding transform parameters
		//AfxBeginThread( FillTrackingTable,
		//			  m_hWnd,
		//			  THREAD_PRIORITY_NORMAL,
		//			  0,
		//			  0 );

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
int Interface::stopTracking()
{
	if ( CommandHandling_->StopTracking() )
	{
		/*
		 * set the variable that will stop the thread.
		 * set the text on the dialog and put program in proper mode.
		 */
		IsTracking_ = false;
		StopTracking_ = true;
		pushButton_StartTracking->setAccessibleName(QString("Start Tracking"));

		SystemMode_ = "System Initialized";
		lineEdit_Mode->setText(QString(SystemMode_.c_str()));
		setMode( MODE_ACTIVATED );

		pushButton_StartTracking->setAccessibleName(QString("Start Tracking"));
		if(comboBox_Port->count() > -1) {
			comboBox_Port->setEnabled(true);
		}
		return 1;
	} /* if */

	return 0;
} /* stopTracking */

/*****************************************************************
Name:				FillTrackingTable

Inputs:
	input LPVOID pParam - normal thread input

Return Value:
	UINT - normal thread return

Description:
	This is the thread call that controls the collection of data

	This thread allows the user to perform other tasks
	within the program while data is being collected
*****************************************************************/
//TODO: need to redesign this method
//UINT FillTrackingTable( LPVOID pParam)
//{
//	HWND hWnd = (HWND)pParam;

//	while ( !StopTracking_ )
//	{
		/*
		 * while tracking, post messages to fill the list
		 */
//		if ( IsTracking_ )
//			::SendMessage( hWnd, WM_FILL_LIST, 0, 0 );
//		else
//			StopTracking_ = true;
//	}/* while */

	/* when tracking stopped, kill the thread */
//	StopTracking_ = false;
//	AfxEndThread( 0, true );
//	return 0;
//} /* FillTrackingTable */
/*****************************************************************
Name:				getSystemTransformData

Inputs:

Return Value:
	long is the normal return for a message handling routine

Description:
	This routine gets the next set of transformation data and displays
	it in the main dialog.
*****************************************************************/
long Interface::getSystemTransformData()
{
	char
		pszTemp[256];
	std::string
		szCBHandle,
		szPortNo;
	int
		nRow = -1;

	Rotation
		dtEulerRot;

	if (!IsTracking_)
		return 0;

	Use0x0800Option_ = checkBox_0x0800->isChecked();
	TrackingMode_ = radioButton_TXMode->isChecked()? 0:1;
	/*
	 * if tracking mode is 0, we are asking for TX data, else we are
	 * asking for BX data.
	 */
	if ( TrackingMode_ == 0 )
	{
		if ( !CommandHandling_->GetTXTransforms( Use0x0800Option_ ? true : false ) )
			return 0;
	} /* if */
	else if ( TrackingMode_ == 1 )
	{
		if ( !CommandHandling_->GetBXTransforms( Use0x0800Option_ ? true : false ) )
			return 0;
	} /* else if */

	/*
	 * if a new port has become occupied we do the following:
	 * 1) Stop tracking
	 * 2) Activate Ports
	 * 3) Start Tracking
	 */
	if ( CommandHandling_->SystemInformation_.PortOccupied )
	{
		if ( CommandHandling_->StopTracking() &&
			 activatePorts() &&
			 CommandHandling_->StartTracking() )
		{
			return 1;
		}/* if */

		/*
		 * We don't want the tracking thread to track if
		 * activating the ports failed!
		 */
		StopTracking_ = true;
		IsTracking_ = false;
		return 0;
	} /* if */

	int i = ASCIIToHex((char*)(comboBox_Handle->currentText().toStdString().c_str()), 2);
	if ( CommandHandling_->HandleInformation_[i].HandleInfo.Initialized > 0 &&
		 CommandHandling_->HandleInformation_[i].ToolType[1] != '8' )
	{
		/* only update the frame if the handle isn't disabled*/
		if ( CommandHandling_->HandleInformation_[i].Xfrms.Flags == TRANSFORM_VALID ||
			 CommandHandling_->HandleInformation_[i].Xfrms.Flags == TRANSFORM_MISSING )
		{
			FrameNumber_ = boost::lexical_cast<std::string>(CommandHandling_->HandleInformation_[i].Xfrms.FrameNumber);
			lineEdit_Frame->setText(QString(FrameNumber_.c_str()));
		}/* if */

		if( i == CommandHandling_->RefHandle_ )
			sprintf( pszTemp, "R%02X", i );
		else
			sprintf( pszTemp, "%02X", i );

		if ( CommandHandling_->HandleInformation_[i].Xfrms.Flags == TRANSFORM_VALID )
		{
			sprintf( pszTemp, "%.2f",
				CommandHandling_->HandleInformation_[i].Xfrms.translation.x );
			lineEdit_Tx->setText(QString(pszTemp));
			sprintf( pszTemp, "%.2f",
				CommandHandling_->HandleInformation_[i].Xfrms.translation.y );
			lineEdit_Ty->setText(QString(pszTemp));
			sprintf( pszTemp, "%.2f",
				CommandHandling_->HandleInformation_[i].Xfrms.translation.z );
			lineEdit_Tz->setText(QString(pszTemp));
			sprintf( pszTemp, "%.4f",
				CommandHandling_->HandleInformation_[i].Xfrms.rotation.q0 );
			lineEdit_Qo->setText(QString(pszTemp));
			sprintf( pszTemp, "%.4f",
				CommandHandling_->HandleInformation_[i].Xfrms.rotation.qx );
			lineEdit_Qx->setText(QString(pszTemp));
			sprintf( pszTemp, "%.4f",
				CommandHandling_->HandleInformation_[i].Xfrms.rotation.qy );
			lineEdit_Qy->setText(QString(pszTemp));
			sprintf( pszTemp, "%.4f",
				CommandHandling_->HandleInformation_[i].Xfrms.rotation.qz );
			lineEdit_Qz->setText(QString(pszTemp));
			sprintf( pszTemp, "%.4f",
				CommandHandling_->HandleInformation_[i].Xfrms.Error );
			lineEdit_Error->setText(QString(pszTemp));

			if ( CommandHandling_->HandleInformation_[i].HandleInfo.PartiallyOutOfVolume )
				lineEdit_Status->setText(QString("POOV"));
			else if ( CommandHandling_->HandleInformation_[i].HandleInfo.OutOfVolume )
				lineEdit_Status->setText(QString("OOV"));
			else
				lineEdit_Status->setText(QString("OK"));
		}/* if */
		else
		{
			if ( CommandHandling_->HandleInformation_[i].Xfrms.Flags == TRANSFORM_MISSING ) {
				lineEdit_Status->setText(QString("MISSING"));
			} else {
				lineEdit_Status->setText(QString("DISABLED"));
			}

			if ( CommandHandling_->HandleInformation_[i].HandleInfo.PartiallyOutOfVolume )
				lineEdit_Status->setText(QString("POOV"));
			else if ( CommandHandling_->HandleInformation_[i].HandleInfo.OutOfVolume )
				lineEdit_Status->setText(QString("OOV"));
			else
				lineEdit_Status->setText(QString("---"));
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
long Interface::comPortTimeout()
{

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
void Interface::selchangePortHandles()
{
	int
		nPortHandle = 0,
		nSelection = 0;
	std::string
		szPortHandle = "";

	nSelection = comboBox_Port->currentIndex();
	szPortHandle = comboBox_Port->currentText().toStdString();
	nPortHandle = ASCIIToHex((char*)(szPortHandle.c_str()), 2);

	/* fill the form with the info that pertains to the selected handle */
	ManufID_ = CommandHandling_->HandleInformation_[nPortHandle].Manufact;
	PortEnabled_ = CommandHandling_->HandleInformation_[nPortHandle].HandleInfo.Enabled;
	PortInitialized_ = CommandHandling_->HandleInformation_[nPortHandle].HandleInfo.Initialized;
	SerialNo_ = CommandHandling_->HandleInformation_[nPortHandle].SerialNo;
	ToolRev_ = CommandHandling_->HandleInformation_[nPortHandle].Rev;
	ToolType_ = CommandHandling_->HandleInformation_[nPortHandle].ToolType;
	PartNumber_ = CommandHandling_->HandleInformation_[nPortHandle].PartNumber;

	lineEdit_Manufacturer->setText(QString(ManufID_.c_str()));
	lineEdit_Serial->setText(QString(SerialNo_.c_str()));
	lineEdit_Tool->setText(QString(ToolType_.c_str()));
	lineEdit_Tool_2->setText(QString(ToolRev_.c_str()));
	lineEdit_Part->setText(QString(PartNumber_.c_str()));
	checkBox_HandleEnable->setChecked(PortEnabled_);
	checkBox_HandleInitialize->setChecked(PortInitialized_);
	if(!IsTracking_) {
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
void Interface::selchangeRefPortHandle()
{
	int
		nPortHandle = 0,
		nSelection = 0;
	std::string
		szPortHandle = "";

	nSelection = comboBox_Reference->currentIndex();
	szPortHandle = comboBox_Reference->currentText().toStdString();

	if( szPortHandle != "None" )
		CommandHandling_->RefHandle_ = ASCIIToHex((char*)(szPortHandle.c_str()), 2 );
	else
		CommandHandling_->RefHandle_ = -1;
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
void Interface::portEnabled()
{
	int
		nPortHandle = 0,
		nSelection = 0;
	std::string
		szPortHandle = "";

	nSelection = comboBox_Port->currentIndex();
	szPortHandle = comboBox_Port->currentText().toStdString();
	/* get the port handle */
	nPortHandle = ASCIIToHex((char*)(szPortHandle.c_str()), 2 );
	PortEnabled_ = checkBox_HandleEnable->isChecked();

	/*
	 * enable or disable the port depending on the status of
	 * the check box
	 */

	if ( !PortEnabled_ )
			CommandHandling_->DisablePort( nPortHandle );
	else
			CommandHandling_->EnableOnePorts( nPortHandle );
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
void Interface::settingsComportsettings()
{
	SubWindow_COMPortSettings_.Init();
	SubWindow_COMPortSettings_.show();
} /* settingsComportsettings */

void Interface::settingsComPortSettings_OK(){
	ROS_INFO("Interface: COM Port Settings OK signal received");
	ResetHardware_ = SubWindow_COMPortSettings_.Reset_;
	COMPort_ = SubWindow_COMPortSettings_.COMPort_;
	Wireless_ = SubWindow_COMPortSettings_.Wireless_;
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
void Interface::settingsRomfilesettings()
{

	/*
	 * we need to know what system we are connect to so we need to
	 * initialize the system if not already done.
	 */
	if ( !SystemInitialized_ )
		initializeNDISystem();

	SubWindow_ROMFile_.Init();
	SubWindow_ROMFile_.NoActivePorts_ = CommandHandling_->SystemInformation_.NoActivePorts;
	SubWindow_ROMFile_.NoPassivePorts_ = CommandHandling_->SystemInformation_.NoPassivePorts;
	SubWindow_ROMFile_.NoMagneticPorts_ = CommandHandling_->SystemInformation_.NoMagneticPorts;
	SubWindow_ROMFile_.TypeofSystem_ = CommandHandling_->SystemInformation_.TypeofSystem;
	SubWindow_ROMFile_.show();

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
void Interface::systemActivateports()
{
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
void Interface::systemInitializesystem()
{
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
void Interface::systemStarttracking()
{
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
void Interface::systemStoptracking()
{
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
void Interface::viewSystemproperties()
{

	/* if we are connected to a POLARIS set the POLARIS variables */
	if(!CommandHandling_->GetSystemInfo()) {
		ROS_ERROR("Get System Info failed");
		return;
	}
	SubWindow_SystemFeatures_.Init();
	if(CommandHandling_->SystemInformation_.TypeofSystem != AURORA_SYSTEM)
	{
		SubWindow_SystemFeatures_.SetVariables( std::string(CommandHandling_->SystemInformation_.VersionInfo),
									  CommandHandling_->SystemInformation_.NoActivePorts,
									  CommandHandling_->SystemInformation_.NoPassivePorts,
									  CommandHandling_->SystemInformation_.NoActWirelessPorts,
									  CommandHandling_->SystemInformation_.NoActTIPPorts,
									  CommandHandling_->SystemInformation_.TypeofSystem );
	} /* if */
	else
	{
		/* if we are connected to a AURORA set the AURORA variables */
		SubWindow_SystemFeatures_.SetVariables( std::string(CommandHandling_->SystemInformation_.VersionInfo),
									  CommandHandling_->SystemInformation_.NoMagneticPorts,
									  CommandHandling_->SystemInformation_.NoFGs,
									  CommandHandling_->SystemInformation_.NoFGCards,
									  CommandHandling_->SystemInformation_.TypeofSystem );
	} /* else */
	SubWindow_SystemFeatures_.show();
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
void Interface::viewAlertFlags()
{
	if(	CommandHandling_->GetAlerts( false ) ){
		ROS_ERROR("Get Alerts failed");
		return;
	}

	SubWindow_NewAlertFlags_.Init();
	SubWindow_NewAlertFlags_.NewAlerts_ = CommandHandling_->NewAlerts_;
	SubWindow_NewAlertFlags_.show();

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
void Interface::optionsIlluminatorfiringrate()
{

	if(CommandHandling_->SystemInformation_.TypeofSystem != AURORA_SYSTEM)
	{
		SubWindow_IlluminatorFiringRate_.Init();
		SubWindow_IlluminatorFiringRate_.TypeOfSystem_ = CommandHandling_->SystemInformation_.TypeofSystem;
		SubWindow_IlluminatorFiringRate_.show();
	}/* if */

} /* optionsIlluminatorfiringrate */
void Interface::optionsIlluminatorfiringrate_OK() {
	ROS_INFO("Interface: Illuminator Firing Rate OK signal received");
	CommandHandling_->SetFiringRate();
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
void Interface::optionsProgramoptions()
{
	SubWindow_ProgramOptions_.Init();
	SubWindow_ProgramOptions_.show();
} /* optionsProgramoptions */

void Interface::optionsProgramoptions_OK() {
	ROS_INFO("Interface: Program Options OK signal received");
	strcpy(CommandHandling_->LogFile_, SubWindow_ProgramOptions_.LogFile_.c_str());
	CommandHandling_->LogToFile_ = SubWindow_ProgramOptions_.LogToFile_;
	CommandHandling_->DateTimeStampFile_ = SubWindow_ProgramOptions_.DateTimeStampFile_;
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
void Interface::setMode( int nMode )
{
	bool
		bTrackingMode = false,
		bPreInitialization = false,
		bInitialized = false;

	//pMainMenu = GetMenu();

	switch (nMode)
	{
		case MODE_PRE_INIT:
			{
				bPreInitialization = true;
				break;
			} /* case */
		case MODE_INIT:
			{
				bInitialized = true;
				bPreInitialization = false;
				PortsActivated_ = false;
				break;
			} /* case */
		case MODE_ACTIVATED:
			{
				bInitialized = true;
				break;
			} /* case */
		case MODE_TRACKING:
			{
				bTrackingMode = true;
				break;
			} /* case */
	} /* switch */

	if ( nMode == MODE_PRE_INIT || nMode == MODE_INIT )
	{
		comboBox_Port->clear();
		comboBox_Port->setEnabled(false);
		comboBox_Reference->clear();
		comboBox_Reference->setEnabled(false);
		//Handle1 stands for port_enabled
		checkBox_HandleEnable->setEnabled(false);
		//replace the original List to comboBox and lineEdit
		comboBox_Handle->clear();
		comboBox_Handle->setEnabled(false);
		lineEdit_Tx->clear();
		lineEdit_Ty->clear();
		lineEdit_Tz->clear();
		lineEdit_Qx->clear();
		lineEdit_Qy->clear();
		lineEdit_Qz->clear();
		lineEdit_Qo->clear();
		// replace original method called "SetWindowText"
		pushButton_StartTracking->setAccessibleName(QString("Start Tracking"));

		bInitialized = true;
		ManufID_ = "";
		SerialNo_ = "";
		ToolRev_ = "";
		ToolType_ = "";
		PartNumber_ = "";
		PortEnabled_ = false;
		PortInitialized_ = false;

		lineEdit_Manufacturer->setText(QString(ManufID_.c_str()));
		lineEdit_Serial->setText(QString(SerialNo_.c_str()));
		lineEdit_Tool->setText(QString(ToolType_.c_str()));
		lineEdit_Tool_2->setText(QString(ToolRev_.c_str()));
		lineEdit_Part->setText(QString(PartNumber_.c_str()));
		checkBox_HandleEnable->setChecked(PortEnabled_);
		checkBox_HandleInitialize->setChecked(PortInitialized_);
	} /* if */

/* buttons */
	pushButton_ResetSystem->setEnabled(!bTrackingMode);
	pushButton_InitializeSystem->setEnabled(!bTrackingMode);
	pushButton_ActiveHandles->setEnabled(!bPreInitialization && !bTrackingMode);
	pushButton_StartTracking->setEnabled((bInitialized && !bPreInitialization && PortsActivated_) || bTrackingMode);


/* fields */
	radioButton_TXMode->setEnabled(bTrackingMode);
	radioButton_BXMode->setEnabled(bTrackingMode);
	lineEdit_Mode->setEnabled(bTrackingMode);
	checkBox_0x0800->setEnabled(bTrackingMode);
/* menu options */
	actionInitialize_System->setEnabled(bTrackingMode);
	actionActivate_Handles->setEnabled(bPreInitialization || bTrackingMode);
	actionStart_Tracking->setEnabled(bPreInitialization || bTrackingMode || !PortsActivated_);
	actionStop_Tracking->setEnabled(!bTrackingMode);
	actionSystem_Properties->setEnabled(bPreInitialization || bTrackingMode);
	actionDiagnostic_Alerts->setEnabled(bPreInitialization || bTrackingMode ||
							   (CommandHandling_->SystemInformation_.TypeofSystem != VICRA_SYSTEM &&
							    CommandHandling_->SystemInformation_.TypeofSystem != SPECTRA_SYSTEM));
	actionIlluminator_Activation_Rate->setEnabled(bPreInitialization || bTrackingMode ||
							   CommandHandling_->SystemInformation_.TypeofSystem == AURORA_SYSTEM);
	actionCOM_Port_Settings->setEnabled(bTrackingMode);
	actionSROM_Image_File_Settings->setEnabled(bTrackingMode);
	actionProgram_Options->setEnabled(bTrackingMode);

} /* setMode */

void Interface::manipulateCollisionObject() {

	int shape_index = comboBox_Shape->currentIndex();
	int operation_index = comboBox_Operation->currentIndex();

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

		collision_pose.position.x = lineEdit_TransX->text().toDouble();
		collision_pose.position.y = lineEdit_TransY->text().toDouble();
		collision_pose.position.z = lineEdit_TransZ->text().toDouble();

		std::vector<double> euler_angle(3);
		euler_angle[0] = lineEdit_RotateA->text().toDouble() / 180.0 * M_PI;
		euler_angle[1] = lineEdit_RotateB->text().toDouble() / 180.0 * M_PI;
		euler_angle[2] = lineEdit_RotateC->text().toDouble() / 180.0 * M_PI;

		KDL::Rotation rotation = KDL::Rotation::RPY(euler_angle[2],
				euler_angle[1], euler_angle[0]);
		rotation.GetQuaternion(collision_pose.orientation.x,
				collision_pose.orientation.y, collision_pose.orientation.z,
				collision_pose.orientation.w);

		collision_object.operation = collision_object.ADD;
		collision_object.primitive_poses.push_back(collision_pose);
		collision_object.primitives.push_back(collision_primitive);
		collision_object.header.frame_id = "world";
		collision_object.id = lineEdit_CollisionID->text().toStdString();
		collision_object.header.stamp = ros::Time::now();
		collision_object.header.seq = collision_operation_counter_++;

		planning_scene.world.collision_objects.clear();
		planning_scene.world.collision_objects.push_back(collision_object);

		planning_scene.is_diff = true;
		planning_scene_diff_publisher_.publish(planning_scene);

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

		planning_scene_diff_publisher_.publish(planning_scene);

		listWidget_CurrentCollisionObject->removeItemWidget(
				listWidget_CurrentCollisionObject->currentItem());
		delete listWidget_CurrentCollisionObject->currentItem();
	}

}
void Interface::visualizeJointPlan() {
	std::map<std::string, double> target_joints;
	target_joints["joint1"] = lineEdit_Joint1->text().toDouble() / 180.0 * M_PI;
	target_joints["joint2"] = lineEdit_Joint2->text().toDouble() / 180.0 * M_PI;
	target_joints["joint3"] = lineEdit_Joint3->text().toDouble() / 180.0 * M_PI;
	target_joints["joint4"] = lineEdit_Joint4->text().toDouble() / 180.0 * M_PI;
	target_joints["joint5"] = lineEdit_Joint5->text().toDouble() / 180.0 * M_PI;
	target_joints["joint6"] = lineEdit_Joint6->text().toDouble() / 180.0 * M_PI;

	controller_.planTargetMotion(target_joints);
}
void Interface::visualizePosePlan() {
	geometry_msgs::Pose target_pose;
	target_pose.position.x = lineEdit_TransX->text().toDouble();
	target_pose.position.y = lineEdit_TransY->text().toDouble();
	target_pose.position.z = lineEdit_TransZ->text().toDouble();

	std::vector<double> euler_angle(3);
	euler_angle[0] = lineEdit_RotateA->text().toDouble() / 180.0 * M_PI;
	euler_angle[1] = lineEdit_RotateB->text().toDouble() / 180.0 * M_PI;
	euler_angle[2] = lineEdit_RotateC->text().toDouble() / 180.0 * M_PI;

	KDL::Rotation rotation = KDL::Rotation::RPY(euler_angle[2], euler_angle[1],
			euler_angle[0]);
	rotation.GetQuaternion(target_pose.orientation.x, target_pose.orientation.y,
			target_pose.orientation.z, target_pose.orientation.w);

	//Axis2Frame()
	controller_.planTargetMotion(target_pose);
}
void Interface::visualizeIncrPosePlan() {
	geometry_msgs::Pose target_pose;
	target_pose.position.x = output_x->toPlainText().toDouble() / 1000.0
			+ lineEdit_incrTransX->text().toDouble();
	target_pose.position.y = output_y->toPlainText().toDouble() / 1000.0
			+ lineEdit_incrTransY->text().toDouble();
	target_pose.position.z = output_z->toPlainText().toDouble() / 1000.0
			+ lineEdit_incrTransZ->text().toDouble();

	std::vector<double> euler_angle(3);
	euler_angle[0] = output_a->toPlainText().toDouble() / 180.0 * M_PI
			+ lineEdit_incrRotateA->text().toDouble() / 180.0 * M_PI;
	euler_angle[1] = output_b->toPlainText().toDouble() / 180.0 * M_PI
			+ lineEdit_incrRotateB->text().toDouble() / 180.0 * M_PI;
	euler_angle[2] = output_c->toPlainText().toDouble() / 180.0 * M_PI
			+ lineEdit_incrRotateC->text().toDouble() / 180.0 * M_PI;

	KDL::Rotation rotation = KDL::Rotation::RPY(euler_angle[2], euler_angle[1],
			euler_angle[0]);
	rotation.GetQuaternion(target_pose.orientation.x, target_pose.orientation.y,
			target_pose.orientation.z, target_pose.orientation.w);

	controller_.planTargetMotion(target_pose);
}
void Interface::addWaypoints() {
	geometry_msgs::Pose target_pose;
	target_pose.position.x = lineEdit_TransX->text().toDouble();
	target_pose.position.y = lineEdit_TransY->text().toDouble();
	target_pose.position.z = lineEdit_TransZ->text().toDouble();

	std::vector<double> euler_angle(3);
	euler_angle[0] = lineEdit_RotateA->text().toDouble() / 180.0 * M_PI;
	euler_angle[1] = lineEdit_RotateB->text().toDouble() / 180.0 * M_PI;
	euler_angle[2] = lineEdit_RotateC->text().toDouble() / 180.0 * M_PI;

	KDL::Rotation rotation = KDL::Rotation::RPY(euler_angle[2], euler_angle[1],
			euler_angle[0]);
	rotation.GetQuaternion(target_pose.orientation.x, target_pose.orientation.y,
			target_pose.orientation.z, target_pose.orientation.w);

	controller_.addWaypoints(target_pose);
}
void Interface::rotateAroundAxis() {
	// Axis type
	int axis_type = comboBox_AxisType->currentIndex();
	// Pose target
	geometry_msgs::Pose target_pose;
	// Euler angle
	std::vector<double> euler_angle(3);
	std::vector<double> euler_angle_rotate(3);
	// rotation matrix
	KDL::Rotation rotation;

	target_pose.position.x = output_x->toPlainText().toDouble() / 1000.0;
	target_pose.position.y = output_y->toPlainText().toDouble() / 1000.0;
	target_pose.position.z = output_z->toPlainText().toDouble() / 1000.0;

	/*target_pose.position.x = lineEdit_TransX->text().toDouble();
	 target_pose.position.y = lineEdit_TransY->text().toDouble();
	 target_pose.position.z = lineEdit_TransZ->text().toDouble();*/

	// position of TCP
	KDL::Vector vector(target_pose.position.x, target_pose.position.y,
			target_pose.position.z);
	KDL::Vector vector_rotate;

	euler_angle[0] = output_a->toPlainText().toDouble() / 180.0 * M_PI;
	euler_angle[1] = output_b->toPlainText().toDouble() / 180.0 * M_PI;
	euler_angle[2] = output_c->toPlainText().toDouble() / 180.0 * M_PI;

	/*euler_angle[0] = lineEdit_RotateA->text().toDouble() / 180.0 * M_PI;
	 euler_angle[1] = lineEdit_RotateB->text().toDouble() / 180.0 * M_PI;
	 euler_angle[2] = lineEdit_RotateC->text().toDouble() / 180.0 * M_PI;*/
	// rotate degree
	double rotate_degree = lineEdit_RotateDegree->text().toDouble();

	switch (axis_type) {
	case Interface::X: {
		rotation = KDL::Rotation::RotX(rotate_degree / 180.0 * M_PI)
				* KDL::Rotation::RPY(euler_angle[2], euler_angle[1],
						euler_angle[0]);
		vector_rotate = KDL::Rotation::RotX(rotate_degree / 180.0 * M_PI)
				* vector;
		break;
	}
	case Interface::Y: {
		rotation = KDL::Rotation::RotY(rotate_degree / 180.0 * M_PI)
				* KDL::Rotation::RPY(euler_angle[2], euler_angle[1],
						euler_angle[0]);
		vector_rotate = KDL::Rotation::RotY(rotate_degree / 180.0 * M_PI)
				* vector;
		break;
	}
	case Interface::Z: {
		rotation = KDL::Rotation::RotZ(rotate_degree / 180.0 * M_PI)
				* KDL::Rotation::RPY(euler_angle[2], euler_angle[1],
						euler_angle[0]);
		vector_rotate = KDL::Rotation::RotZ(rotate_degree / 180.0 * M_PI)
				* vector;
		break;
	}
	case Interface::Custom: {
		// custom rotate axis
		KDL::Vector rotate_axis(lineEdit_AxisVectorX->text().toDouble(),
				lineEdit_AxisVectorY->text().toDouble(),
				lineEdit_AxisVectorZ->text().toDouble());
		rotation = KDL::Rotation::Rot(rotate_axis, rotate_degree / 180.0 * M_PI)
				* KDL::Rotation::RPY(euler_angle[2], euler_angle[1],
						euler_angle[0]);
		vector_rotate = KDL::Rotation::Rot(rotate_axis,
				rotate_degree / 180.0 * M_PI) * vector;
		break;
	}
	default: {
		ROS_ERROR("Axis type is wrong");
	}
	}

	rotation.GetQuaternion(target_pose.orientation.x, target_pose.orientation.y,
			target_pose.orientation.z, target_pose.orientation.w);

	target_pose.position.x = vector_rotate.data[0];
	target_pose.position.y = vector_rotate.data[1];
	target_pose.position.z = vector_rotate.data[2];

	controller_.planTargetMotion(target_pose);

}
void Interface::executeMotionPlan() {

	controller_.executeMotionPlan();
}

void Interface::newFeedbackReceived(Feedback* feedback) {

	Axis feedback_axis;
	feedback_axis = feedback->getAxis();

	joint_state_publish_count_++;
	joint_state_.header.seq = joint_state_publish_count_;
	joint_state_.position[0] = feedback_axis.A1 / 180.0 * M_PI;
	joint_state_.position[1] = feedback_axis.A2 / 180.0 * M_PI;
	joint_state_.position[2] = feedback_axis.A3 / 180.0 * M_PI;
	joint_state_.position[3] = feedback_axis.A4 / 180.0 * M_PI;
	joint_state_.position[4] = feedback_axis.A5 / 180.0 * M_PI;
	joint_state_.position[5] = feedback_axis.A6 / 180.0 * M_PI;
	joint_state_.header.stamp = ros::Time::now();
	joint_state_publisher_.publish(joint_state_);
}
void Interface::visualizeMotionPlan(
		moveit::planning_interface::MoveGroup::Plan motion_plan) {

	ROS_INFO("Visualizing plan");

	display_trajectory_.trajectory_start = motion_plan.start_state_;
	display_trajectory_.trajectory.push_back(motion_plan.trajectory_);

	display_publisher_.publish(display_trajectory_);
}

void Interface::shutdown() {
	QApplication::exit();
	ros::shutdown();
}

// Callback function
void Interface::trajectoryActionCb(const TrajectoryGoal& feedback) {
	ROS_INFO("Trajectory received.");
	emit sendTrajectory(feedback);
}
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
			QString("%1").arg(feedback->pose.position.x, 8, 'f', 4));
	lineEdit_TransY->setText(
			QString("%1").arg(feedback->pose.position.y, 8, 'f', 4));
	lineEdit_TransZ->setText(
			QString("%1").arg(feedback->pose.position.z, 8, 'f', 4));

	std::vector<double> euler_angle(3);
	KDL::Rotation rotation = KDL::Rotation::Quaternion(
			feedback->pose.orientation.x, feedback->pose.orientation.y,
			feedback->pose.orientation.z, feedback->pose.orientation.w);
	rotation.GetRPY(euler_angle[2], euler_angle[1], euler_angle[0]);
	lineEdit_RotateA->setText(
			QString("%1").arg(euler_angle[0] / M_PI * 180.0, 8, 'f', 4));
	lineEdit_RotateB->setText(
			QString("%1").arg(euler_angle[1] / M_PI * 180.0, 8, 'f', 4));
	lineEdit_RotateC->setText(
			QString("%1").arg(euler_angle[2] / M_PI * 180.0, 8, 'f', 4));

	Frame temp_frame(feedback->pose.position.x * 1000.0,
			feedback->pose.position.y * 1000.0,
			feedback->pose.position.z * 1000.0, euler_angle[0] / M_PI * 180.0,
			euler_angle[1] / M_PI * 180.0, euler_angle[2] / M_PI * 180.0);
	Axis temp_axis;
	controller_.getPlannar()->getModel().Frame2Axis(last_Axis_, temp_frame,
			temp_axis);
	last_Axis_.set(temp_axis);

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

	interactive_marker_server_->insert(int_marker);
}
void Interface::initMenu() {

	menu_entry_.push_back(
			menu_handler_.insert("Add into way points", addWaypointsCb_global));
	menu_entry_.push_back(
			menu_handler_.insert("Visualize and Execute motion plan",
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
	plannar_ptr_->motion(style, f, approx);
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
	plannar_ptr_->motion(style, a, approx);
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
	plannar_ptr_->motion(style, p, approx);
}

void Interface::displayFeedback(Feedback* feedback) {

	joint_state_display_counter_++;
	if (joint_state_display_counter_ >= 100) {
		if (feedback->getSetOK() && feedback->getParsedOK()) {
			Axis feedback_axis;
			Frame feedback_frame;
			feedback_axis = feedback->getAxis();

			last_Axis_.set(feedback_axis);
			plannar_ptr_->getModel().Axis2Frame(feedback_axis, feedback_frame);

			output_a1->setText(QString("%1").arg(feedback_axis.A1, 8, 'f', 4));
			output_a2->setText(QString("%1").arg(feedback_axis.A2, 8, 'f', 4));
			output_a3->setText(QString("%1").arg(feedback_axis.A3, 8, 'f', 4));
			output_a4->setText(QString("%1").arg(feedback_axis.A4, 8, 'f', 4));
			output_a5->setText(QString("%1").arg(feedback_axis.A5, 8, 'f', 4));
			output_a6->setText(QString("%1").arg(feedback_axis.A6, 8, 'f', 4));

			output_x->setText(QString("%1").arg(feedback_frame.X, 8, 'f', 4));
			output_y->setText(QString("%1").arg(feedback_frame.Y, 8, 'f', 4));
			output_z->setText(QString("%1").arg(feedback_frame.Z, 8, 'f', 4));
			output_a->setText(QString("%1").arg(feedback_frame.A, 8, 'f', 4));
			output_b->setText(QString("%1").arg(feedback_frame.B, 8, 'f', 4));
			output_c->setText(QString("%1").arg(feedback_frame.C, 8, 'f', 4));

			output_s->setText(QString::number(feedback->getPos().S));
			output_t->setText(QString::number(feedback->getPos().T));

			output_buf_front->setText(
					QString::number(feedback->getBufferFront()));
			output_buf_last->setText(
					QString::number(feedback->getBufferLast()));

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

			//setAlignment();
		} else {
			output_message->setText("Feedback parsing failed");
			QPalette pm = output_message->palette();
			pm.setColor(QPalette::Base, QColor(170, 0, 0));
			output_message->setPalette(pm);

			//setAlignment();
		}
		joint_state_display_counter_ = 0;
	}

}
void Interface::convertPoseTargettoJointTarget() {
	Frame temp_frame(lineEdit_TransX->text().toDouble() * 1000.0,
			lineEdit_TransY->text().toDouble() * 1000.0,
			lineEdit_TransZ->text().toDouble() * 1000.0,
			lineEdit_RotateA->text().toDouble(),
			lineEdit_RotateB->text().toDouble(),
			lineEdit_RotateC->text().toDouble());
	Axis temp_axis;

	controller_.getPlannar()->getModel().Frame2Axis(last_Axis_, temp_frame,
			temp_axis);
	last_Axis_.set(temp_axis);

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

	controller_.getPlannar()->getModel().Frame2Axis(last_Axis_, temp_frame,
			temp_axis);
	last_Axis_.set(temp_axis);

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
			QString("%1").arg(output_x->toPlainText().toDouble() / 1000.0, 8,
					'f', 4));
	lineEdit_TransY->setText(
			QString("%1").arg(output_y->toPlainText().toDouble() / 1000.0, 8,
					'f', 4));
	lineEdit_TransZ->setText(
			QString("%1").arg(output_z->toPlainText().toDouble() / 1000.0, 8,
					'f', 4));
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
		plannar_ptr_->configuration(param, value);

	ROS_INFO("Send config button clicked");

}

void Interface::on_pause_buf_buton_clicked() {
	plannar_ptr_->pauseBuffered();
	ROS_INFO("Pause buffer button clicked");
}

void Interface::on_terminate_imm_button_clicked() {
	plannar_ptr_->terminateImmediately();
	ROS_INFO("Terminate immediately button clicked");
}

void Interface::on_pause_button_clicked() {
	plannar_ptr_->pauseImmediately();
	ROS_INFO("Pause immediately button clicked");
}

void Interface::on_stop_button_clicked() {
	plannar_ptr_->stop();
	ROS_INFO("Stop button clicked");
}

void Interface::on_terminate_buf_button_clicked() {
	plannar_ptr_->terminateBuffered();
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

