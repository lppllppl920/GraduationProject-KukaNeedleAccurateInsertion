/*
 * NewAlertFlagsDlg.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: lxt12
 */

#include <ndi/NewAlertFlagsDlg.h>

NewAlertFlagsDlg::NewAlertFlagsDlg(QWidget *parent) {
	setupUi(this);
	connect(pushButton_OK, SIGNAL(clicked()), this, SLOT(OK()));
}

NewAlertFlagsDlg::~NewAlertFlagsDlg() {
	// TODO Auto-generated destructor stub
}

void NewAlertFlagsDlg::Init() {
	label->setEnabled(dtNewAlerts_.nFatalParamterFault);
	label_3->setEnabled(dtNewAlerts_.nSensorParameterFault);
	label_5->setEnabled(dtNewAlerts_.nMainVoltageFault);
	label_7->setEnabled(dtNewAlerts_.nSensorVoltageFault);
	label_9->setEnabled(dtNewAlerts_.nIlluminatorVoltageFault);
	label_11->setEnabled(dtNewAlerts_.nIlluminatorCurrentFault);
	label_13->setEnabled(dtNewAlerts_.nLeftSensorTempFault);
	label_15->setEnabled(dtNewAlerts_.nRightSensorTempFault);
	label_17->setEnabled(dtNewAlerts_.nMainBoardTempFault);

	label_2->setEnabled(dtNewAlerts_.nBatteryFaultAlarm);
	label_4->setEnabled(dtNewAlerts_.nBumpDetectedAlarm);
	label_6->setEnabled(dtNewAlerts_.nCableFaultAlarm);
	label_8->setEnabled(dtNewAlerts_.nFirmwareIncompatible);
	label_10->setEnabled(dtNewAlerts_.nInternalFlashFull);
	label_12->setEnabled(dtNewAlerts_.nLaserBatteryFaultAlarm);
	label_14->setEnabled(dtNewAlerts_.nNonFatalParamFault);
	label_16->setEnabled(dtNewAlerts_.nTempTooHigh);
	label_18->setEnabled(dtNewAlerts_.nTempTooLow);
}

void NewAlertFlagsDlg::OK() {
	ROS_INFO("NewAlertFlagsDlg: OK button clicked");
	this->close();
}
