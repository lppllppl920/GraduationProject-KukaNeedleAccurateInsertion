/*
 * COMPortSettings.cpp
 *
 *  Created on: Apr 22, 2016
 *      Author: lxt12
 */

#include "ndi/COMPortSettings.h"

COMPortSettings::COMPortSettings(QWidget *parent) {

	setupUi(this);
	connect(pushButton_OK, SIGNAL(clicked()), this, SLOT(OK()));
	connect(pushButton_Cancel, SIGNAL(clicked()), this, SLOT(Cancel()));

	bWireless_ = false;
	bReset_ = false;
	bHardware_ = false;
	nCOMPort_ = 0;

// TODO: this address need to be specified
	if (!dtIniFile_.Load("/home/lxt12/NDIConfiguration.ini")) {
		ROS_ERROR("COMPortSettings: cannot find configuration file");
	}
	strConfigurationFile_ = "/home/lxt12/NDIConfiguration.ini";

}

COMPortSettings::~COMPortSettings() {
	// TODO Auto-generated destructor stub
}
void COMPortSettings::Init() {

	int nBaudRate = 0, nStopBits = 0, nParity = 0, nDataBits = 0;
	bWireless_ = false;
	bReset_ = false;
	bHardware_ = false;
	nCOMPort_ = 0;

	ReadINIParam<int>("Communication", "Baud Rate", nBaudRate);
	ReadINIParam<int>("Communication", "Stop Bits", nStopBits);
	ReadINIParam<int>("Communication", "Parity", nParity);
	ReadINIParam<int>("Communication", "Data Bits", nDataBits);
	ReadINIParam<int>("Communication", "COM Port", nCOMPort_);
	ReadINIParam<bool>("Communication", "Hardware", bHardware_);
	ReadINIParam<bool>("Communication", "Wireless", bWireless_);
	ReadINIParam<bool>("Communication", "Reset Hardware", bReset_);

	comboBox_Baud->setCurrentIndex(nBaudRate);
	comboBox_Stop->setCurrentIndex(nStopBits);
	comboBox_Parity->setCurrentIndex(nParity);
	comboBox_Data->setCurrentIndex(nDataBits);
	comboBox_COM->setCurrentIndex(nCOMPort_);
	checkBox_HardwareHandshaking->setChecked(bHardware_);
	checkBox_WirelessCommunicationPort->setChecked(bWireless_);
	checkBox_ResetHardware->setChecked(bReset_);
}
void COMPortSettings::OK() {
	ROS_INFO("COMPortSettings: OK button clicked");
	dtIniFile_.SetKeyValue("Communication", "Baud Rate",
			boost::lexical_cast<std::string>(comboBox_Baud->currentIndex()));
	dtIniFile_.SetKeyValue("Communication", "Stop Bits",
			boost::lexical_cast<std::string>(comboBox_Stop->currentIndex()));
	dtIniFile_.SetKeyValue("Communication", "Parity",
			boost::lexical_cast<std::string>(comboBox_Parity->currentIndex()));
	dtIniFile_.SetKeyValue("Communication", "Data Bits",
			boost::lexical_cast<std::string>(comboBox_Data->currentIndex()));
	dtIniFile_.SetKeyValue("Communication", "COM Port",
			boost::lexical_cast<std::string>(comboBox_COM->currentIndex()));
	dtIniFile_.SetKeyValue("Communication", "Hardware",
			boost::lexical_cast<std::string>(
					checkBox_HardwareHandshaking->isChecked()));
	dtIniFile_.SetKeyValue("Communication", "Wireless",
			boost::lexical_cast<std::string>(
					checkBox_WirelessCommunicationPort->isChecked()));
	dtIniFile_.SetKeyValue("Communication", "Reset Hardware",
			boost::lexical_cast<std::string>(
					checkBox_ResetHardware->isChecked()));
	dtIniFile_.Save(strConfigurationFile_);
	this->close();
	emit OK_signal();
}

void COMPortSettings::Cancel() {
	ROS_INFO("COMPortSettings: Close button clicked");
	this->close();
}

