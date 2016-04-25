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

	Wireless_ = false;
	Reset_ = false;
	Hardware_ = false;
	COMPort_ = 0;

// TODO: this address need to be specified
	if (!IniFile_.Load("/home/lxt12/NDIConfiguration.ini")) {
		ROS_ERROR("COMPortSettings: cannot find configuration file");
	}
	ConfigurationFile_ = "/home/lxt12/NDIConfiguration.ini";

}

COMPortSettings::~COMPortSettings() {
	// TODO Auto-generated destructor stub
}
void COMPortSettings::Init() {

	int nBaudRate = 0, nStopBits = 0, nParity = 0, nDataBits = 0;
	Wireless_ = false;
	Reset_ = false;
	Hardware_ = false;
	COMPort_ = 0;

	ReadINIParam<int>("Communication", "Baud Rate", nBaudRate);
	ReadINIParam<int>("Communication", "Stop Bits", nStopBits);
	ReadINIParam<int>("Communication", "Parity", nParity);
	ReadINIParam<int>("Communication", "Data Bits", nDataBits);
	ReadINIParam<int>("Communication", "COM Port", COMPort_);
	ReadINIParam<bool>("Communication", "Hardware", Hardware_);
	ReadINIParam<bool>("Communication", "Wireless", Wireless_);
	ReadINIParam<bool>("Communication", "Reset Hardware", Reset_);

	comboBox_Baud->setCurrentIndex(nBaudRate);
	comboBox_Stop->setCurrentIndex(nStopBits);
	comboBox_Parity->setCurrentIndex(nParity);
	comboBox_Data->setCurrentIndex(nDataBits);
	comboBox_COM->setCurrentIndex(COMPort_);
	checkBox_HardwareHandshaking->setChecked(Hardware_);
	checkBox_WirelessCommunicationPort->setChecked(Wireless_);
	checkBox_ResetHardware->setChecked(Reset_);
}
void COMPortSettings::OK() {
	ROS_INFO("COMPortSettings: OK button clicked");
	IniFile_.SetKeyValue("Communication", "Baud Rate",
			boost::lexical_cast<std::string>(comboBox_Baud->currentIndex()));
	IniFile_.SetKeyValue("Communication", "Stop Bits",
			boost::lexical_cast<std::string>(comboBox_Stop->currentIndex()));
	IniFile_.SetKeyValue("Communication", "Parity",
			boost::lexical_cast<std::string>(comboBox_Parity->currentIndex()));
	IniFile_.SetKeyValue("Communication", "Data Bits",
			boost::lexical_cast<std::string>(comboBox_Data->currentIndex()));
	IniFile_.SetKeyValue("Communication", "COM Port",
			boost::lexical_cast<std::string>(comboBox_COM->currentIndex()));
	IniFile_.SetKeyValue("Communication", "Hardware",
			boost::lexical_cast<std::string>(
					checkBox_HardwareHandshaking->isChecked()));
	IniFile_.SetKeyValue("Communication", "Wireless",
			boost::lexical_cast<std::string>(
					checkBox_WirelessCommunicationPort->isChecked()));
	IniFile_.SetKeyValue("Communication", "Reset Hardware",
			boost::lexical_cast<std::string>(
					checkBox_ResetHardware->isChecked()));
	IniFile_.Save(ConfigurationFile_);
	this->close();
	emit OK_signal();
}

void COMPortSettings::Cancel() {
	ROS_INFO("COMPortSettings: Close button clicked");
	this->close();
}

