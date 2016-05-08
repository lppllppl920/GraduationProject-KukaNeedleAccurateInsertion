/*
 * SystemFeaturesDlg.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: lxt12
 */

#include <ndi/SystemFeaturesDlg.h>

SystemFeaturesDlg::SystemFeaturesDlg(QWidget* parent) {
	setupUi(this);
	nNoActivePorts_ = 0;
	nNoActiveWireless_ = 0;
	nNoPassivePorts_ = 0;
	nNoTIPDetectionPorts_ = 0;
	strVersionInfo_ = "";
	nTypeOfSystem_ = 0;

	connect(pushButton_OK, SIGNAL(clicked()), this, SLOT(close()));
	connect(pushButton_Cancel, SIGNAL(clicked()), this, SLOT(close()));
}

SystemFeaturesDlg::~SystemFeaturesDlg() {
	// TODO Auto-generated destructor stub
}

void SystemFeaturesDlg::Init() {

	nNoActivePorts_ = 0;
	nNoActiveWireless_ = 0;
	nNoPassivePorts_ = 0;
	nNoTIPDetectionPorts_ = 0;
	strVersionInfo_ = "";
	nTypeOfSystem_ = 0;

	if (nTypeOfSystem_ == AURORA_SYSTEM) {
		label_ActivePortsNum->setText(QString("Number of tool ports:"));

		label_SupportingPortsNum->setHidden(true);
		lineEdit_SupportingPortsNum->setHidden(true);

		label_WirelessNum->setHidden(true);
		lineEdit_WirelessNum->setHidden(true);

		label_ActiveWirelessPorts->setHidden(true);
		lineEdit_ActiveWirelessPorts->setHidden(true);
	}

}
/*****************************************************************
 Name:				SetVariables

 Inputs:
 char * pszVersionInfo - the string that contains the info
 pertaining to the firmware version of
 the POLARIS attached to
 int nNoActivePorts -  the number of active ports supported by
 the POLARIS
 int nNoPassivePorts - the number of passive ports supported by
 the POLARIS
 int nNoActiveWireless - the number of active wireless ports supported
 by the POLARIS
 int nNoTIPDetection - the number of ports that support Tool-In-Port
 detection with the POLARIS connected to.

 Return Value:
 None.

 Description:
 This routine sets the dialogs member variables with the
 information gathered from the POLARIS System,  These variables
 are set prior to calling the dialogs DoModal routine.
 *****************************************************************/
void SystemFeaturesDlg::SetVariables(std::string pszVersionInfo,
		int nNoActivePorts, int nNoPassivePorts, int nNoActiveWireless,
		int nNoTIPDetection, int nTypeofSystem) {
	QListWidgetItem* TypeofSystem = new QListWidgetItem;

	strVersionInfo_ = pszVersionInfo;
	switch (nNoActivePorts) {
	case 12:	// TDS supported and present
	case 4:		// TDS supported but not present
		nNoActivePorts_ = nNoActivePorts - 1;
		break;
	default:
		nNoActivePorts_ = nNoActivePorts;
		break;
	}/* switch */
	nNoActiveWireless_ = nNoActiveWireless;
	nNoPassivePorts_ = nNoPassivePorts;
	nNoTIPDetectionPorts_ = nNoTIPDetection;
	nTypeOfSystem_ = nTypeofSystem;

	TypeofSystem->setText(
			QString(
					boost::lexical_cast<std::string>(nNoActiveWireless_).c_str()));
	listWidget->insertItem(1, TypeofSystem);

	lineEdit_ActiveWirelessPorts->setText(
			QString(
					boost::lexical_cast<std::string>(nNoActiveWireless_).c_str()));
	lineEdit_ActivePortsNum->setText(
			QString(boost::lexical_cast<std::string>(nNoActivePorts_).c_str()));
	lineEdit_SupportingPortsNum->setText(
			QString(
					boost::lexical_cast<std::string>(nNoTIPDetectionPorts_).c_str()));
	lineEdit_WirelessNum->setText(
			QString(
					boost::lexical_cast<std::string>(nNoPassivePorts_).c_str()));

}

/*****************************************************************
 Name:				SetVariables

 Inputs:
 char * pszVersionInfo - the string that contains the info
 pertaining to the firmware version of
 the AURORA attached to
 int nNoMagneticPorts -  the number of magnetic ports supported by
 the AURORA
 int nNoFieldGenerators - the number of FG's supported by
 the AURORA
 int nNoFieldGeneratorCards - the number of FG Cards supported
 by the AURORA

 Return Value:
 None.

 Description:
 This routine sets the dialogs member variables with the
 information gathered from the AURORA System,  These variables
 are set prior to calling the dialogs DoModal routine.
 *****************************************************************/
void SystemFeaturesDlg::SetVariables(std::string pszVersionInfo,
		int nNoMagneticPorts, int nNoFieldGenerators,
		int nNoFieldGeneratorCards, int nTypeofSystem) {
	QListWidgetItem* TypeofSystem = new QListWidgetItem;

	strVersionInfo_ = pszVersionInfo;
	nNoActivePorts_ = nNoMagneticPorts;
	nNoActiveWireless_ = nNoFieldGenerators;
	nNoPassivePorts_ = nNoFieldGeneratorCards;
	nTypeOfSystem_ = nTypeofSystem;

	TypeofSystem->setText(
			QString(
					boost::lexical_cast<std::string>(nNoActiveWireless_).c_str()));
	listWidget->insertItem(1, TypeofSystem);

	lineEdit_ActiveWirelessPorts->setText(
			QString(
					boost::lexical_cast<std::string>(nNoActiveWireless_).c_str()));
	lineEdit_ActivePortsNum->setText(
			QString(boost::lexical_cast<std::string>(nNoActivePorts_).c_str()));
	lineEdit_SupportingPortsNum->setText(
			QString(
					boost::lexical_cast<std::string>(nNoTIPDetectionPorts_).c_str()));
	lineEdit_WirelessNum->setText(
			QString(
					boost::lexical_cast<std::string>(nNoPassivePorts_).c_str()));

} /* SetVariables */

