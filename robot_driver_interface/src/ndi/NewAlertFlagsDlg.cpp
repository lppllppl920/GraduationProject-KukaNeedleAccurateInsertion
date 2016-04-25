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
	label->setEnabled(NewAlerts_.FatalParamterFault);
	label_3->setEnabled(NewAlerts_.SensorParameterFault);
	label_5->setEnabled(NewAlerts_.MainVoltageFault);
	label_7->setEnabled(NewAlerts_.SensorVoltageFault);
	label_9->setEnabled(NewAlerts_.IlluminatorVoltageFault);
	label_11->setEnabled(NewAlerts_.IlluminatorCurrentFault);
	label_13->setEnabled(NewAlerts_.LeftSensorTempFault);
	label_15->setEnabled(NewAlerts_.RightSensorTempFault);
	label_17->setEnabled(NewAlerts_.MainBoardTempFault);

	label_2->setEnabled(NewAlerts_.BatteryFaultAlarm);
	label_4->setEnabled(NewAlerts_.BumpDetectedAlarm);
	label_6->setEnabled(NewAlerts_.CableFaultAlarm);
	label_8->setEnabled(NewAlerts_.FirmwareIncompatible);
	label_10->setEnabled(NewAlerts_.InternalFlashFull);
	label_12->setEnabled(NewAlerts_.LaserBatteryFaultAlarm);
	label_14->setEnabled(NewAlerts_.NonFatalParamFault);
	label_16->setEnabled(NewAlerts_.TempTooHigh);
	label_18->setEnabled(NewAlerts_.TempTooLow);
}

void NewAlertFlagsDlg::OK() {
	ROS_INFO("NewAlertFlagsDlg: OK button clicked");
	this->close();
}
