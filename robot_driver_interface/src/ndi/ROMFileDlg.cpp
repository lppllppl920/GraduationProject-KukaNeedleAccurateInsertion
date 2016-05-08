/*
 * ROMFileDlg.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: lxt12
 */

#include <ndi/ROMFileDlg.h>

ROMFileDlg::ROMFileDlg(QWidget* parent) {
	setupUi(this);
	strPortID_ = "";
	strROMFile_ = "";
	bChangesSaved_ = false;
	nNoActivePorts_ = 0;
	nNoPassivePorts_ = 0;
	nNoMagneticPorts_ = 0;
	nTypeofSystem_ = 0;
	nROMSelection_ = 0;
	strConfigurationFile_ = "/home/lxt12/NDIConfiguration.ini";

	if (!dtIniFile_.Load("/home/lxt12/NDIConfiguration.ini")) {
		ROS_ERROR("Cannot load configuration file");
	}

	connect(pushButton_Save, SIGNAL(clicked()), this, SLOT(Accept()));
	connect(pushButton_Browse, SIGNAL(clicked()), this, SLOT(Browse()));
	connect(pushButton_Close, SIGNAL(clicked()), this, SLOT(Close()));
	connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this,
			SLOT(ClickPortListing()));
}

ROMFileDlg::~ROMFileDlg() {
	// TODO Auto-generated destructor stub
}
/*****************************************************************
 Init
 VISUAL C++ FUNCTION CALL
 *****************************************************************/

void ROMFileDlg::Init() {
	//listWidget->addScrollBarWidget(new QWidget,
	//		Qt::Alignment::enum_type::AlignRight);
	listWidget->insertItem(0, QString("Port ID    SROM Image File"));
	listWidget->setFocusPolicy(Qt::FocusPolicy::ClickFocus);

	FillROMFileTable();

	nROMSelection_ = 0;

	return;
}

/*****************************************************************
 Name:				Browse

 Inputs:
 None.

 Return Value:
 None.

 Description:   This function controls what happens when the "..."
 button is pressed.  This button brings up a file dialog
 box, so the user can select a ROM file.
 *****************************************************************/
void ROMFileDlg::Browse() {
	QString filename = QFileDialog::getOpenFileName(this, tr("Open Document"),
			QDir::currentPath(), tr("*.rom;*.ROM"));

	if (!filename.isNull()) {
		qDebug("%s", filename.toStdString().c_str());

	}
	strROMFile_ = filename.toStdString();
	lineEdit_SROMImageFile->setText(QString(strROMFile_.c_str()));
	pushButton_Save->setEnabled(true);
} /* Browse */
/*****************************************************************
 Name:				Close

 Inputs:
 None.

 Return Value:
 None.

 Description:   This function controls what happens when the Close
 button is pressed.  If the form has information in
 the ROM file selection area, the user is asked if
 they wish to save their changes.
 *****************************************************************/
void ROMFileDlg::Close() {
	bool bOkToClose = true;
	std::string szErrorMsg;

	if (bOkToClose) {
		if (bChangesSaved_) {
			ROS_INFO("You must re-initialize your system before SROM Image File"
					"changes will be applied.");

			/* TODO: Force to re-initialize the system  */
			emit ReInitialize_signal();
		} /* if */
		this->close();
	}
} /* Close */
/*****************************************************************
 Name:				ClickPortListing

 Inputs:
 Visual C++ specifics...

 Return Value:
 None.

 Description:   This routine control what happens when the user
 clicks in the Port Listing for ROM Files.  It
 fills the form with the appropriate information as
 taken from the list.
 *****************************************************************/
void ROMFileDlg::ClickPortListing() {
	std::string item = listWidget->currentItem()->text().toStdString();
	int pos;

	if (!(pos = item.find("   ", 0))) {
		return;
	}

	strPortID_ = item.substr(0, pos);
	strROMFile_ = item.substr(pos + 3, item.length() - 1);
	/* get the text and values for the selected item */
	nROMSelection_ = listWidget->currentRow();

	lineEdit_Port->setText(QString(strPortID_.c_str()));
	lineEdit_SROMImageFile->setText(QString(strROMFile_.c_str()));
	/* set the appropriate dialog items */
	/*
	 * Handle the special TDS expansion port case.
	 * - Also make sure it's an aurora system!
	 */
	if ((nTypeofSystem_ != AURORA_SYSTEM) && (strPortID_ == "Port 4")) {
		lineEdit_SROMImageFile->setHidden(true);
		label_SROMImageFile->setHidden(true);
		pushButton_Browse->setHidden(true);
	} else {
		lineEdit_SROMImageFile->setHidden(false);
		label_SROMImageFile->setHidden(false);
		pushButton_Browse->setHidden(false);

		pushButton_Browse->setEnabled(true);
		pushButton_Save->setEnabled(true);
		lineEdit_SROMImageFile->setReadOnly(false);
	}/* else */

} /* ClickPortListing */
/*****************************************************************
 Name:				FillROMFileTable

 Inputs:
 None.

 Return Value:
 None.

 Description:   This routine handles the filling of the ROM file
 listing based on the type of system you are attached
 to.
 *****************************************************************/
void ROMFileDlg::FillROMFileTable() {
	char pszROMFileName[MAX_PATH];
	char pszPortID[20];
	int i = 0;
	/* for the number of passive ports supported */
	for (i = nNoPassivePorts_; i > 0; i--) {
		sprintf(pszPortID, "Wireless Tool %02d", i);
		ROS_INFO("%s", pszPortID);
		strcpy(pszROMFileName, "");
		ReadINIParam_array("POLARIS SROM Image Files", pszPortID,
				pszROMFileName);
		ROS_INFO("%s", pszROMFileName);
		AddItemToList(pszPortID, pszROMFileName);
	} /* for */

	/*
	 * if the system supports 4 active ports show 12
	 * for the case that the TDS is plugged in and active
	 */
	if (nNoActivePorts_ == 4)
		nNoActivePorts_ = 12;

	/* for the number of active ports supported */
	for (i = nNoActivePorts_; i > 0; i--) {
		/*
		 * TDS expansion port shall not be treated as a normal port.
		 */
		if (i == 4) {
			sprintf(pszPortID, "Port %d", i);
			strcpy(pszROMFileName, "TDS Expansion Port");
			AddItemToList(pszPortID, pszROMFileName);
			continue;
		}/* if */

		sprintf(pszPortID, "Port %d", i);
		strcpy(pszROMFileName, "");
		ReadINIParam_array("POLARIS SROM Image Files", pszPortID,
				pszROMFileName);
		AddItemToList(pszPortID, pszROMFileName);
	} /* for */

	/* for the number of magnetic ports supported */
	for (i = nNoMagneticPorts_; i > 0; i--) {
		sprintf(pszPortID, "Port %d", i);
		strcpy(pszROMFileName, "");
		ReadINIParam_array("AURORA SROM Image Files", pszPortID,
				pszROMFileName);
		AddItemToList(pszPortID, pszROMFileName);
	} /* for */
} /* FillROMFileTable */
/*****************************************************************
 Name:				AddItemToList

 Inputs:
 char * pszPortID - the Port ID of the item being added to list
 char * pszROMFileName - the ROM file to be added to the list attached
 to pszPortID

 Return Value:
 None.

 Description:   This routine adds the inputs to the list of ROM files
 in the spot the corresponds to the specified pszPortID.
 *****************************************************************/
void ROMFileDlg::AddItemToList(char* pszPortID, char* pszROMFileName) {
	std::string item = std::string(pszPortID) + std::string("   ")
			+ std::string(pszROMFileName);
	listWidget->insertItem(1, QString(item.c_str()));

} /* AddItemToList */
/*****************************************************************
 Name:				SaveItemToINI

 Inputs:
 char * pszPortID - the Port ID of the item being saved to the INI
 char * pszROMFileName - the ROM file to be saved to the INI attached
 to pszPortID

 Return Value:
 None.

 Description:   This routine saves the specified Port ID and ROM file
 to the INI file under the correct section.
 *****************************************************************/
void ROMFileDlg::SaveItemToINI(const char* pszPortID,
		const char* pszROMFileName) {
	/* if Magnetic Ports is greater than zero, attached to AURORA */
	if (nNoMagneticPorts_ > 0)
		dtIniFile_.SetKeyValue("AURORA SROM Image Files",
				std::string(pszPortID), std::string(pszROMFileName));
	else
		dtIniFile_.SetKeyValue("POLARIS SROM Image Files",
				std::string(pszPortID), std::string(pszROMFileName));

	dtIniFile_.Save(strConfigurationFile_);
} /* SaveItemToINI */

/*****************************************************************
 Name:				Accept

 Inputs:
 Visual C++ specifics...

 Return Value:
 None.

 Description:   This routine control what happens when the user
 presses the Save button, it saves the current listed
 SROM Image file to the INI file
 *****************************************************************/
void ROMFileDlg::Accept() {
	std::string szErrorMsg;
	bool bValidFile = true;

	std::string item = listWidget->currentItem()->text().toStdString();
	int pos;

	if (!(pos = item.find("   ", 0))) {
		ROS_ERROR("Save: cannot find valid PortID and ROMFile");
		return;
	}
	strPortID_ = item.substr(0, pos);
	strROMFile_ = lineEdit_SROMImageFile->text().toStdString();
	nROMSelection_ = listWidget->currentRow();

	if (strROMFile_.size() < 0) {
		bValidFile = false;
	} /* if */

	/*
	 * if this is a valid file set the
	 * dialog options accordingly
	 */
	if (bValidFile) {
		listWidget->currentItem()->setText(
				QString(
						std::string(
								strPortID_ + std::string("   ") + strROMFile_).c_str()));
		pushButton_Browse->setEnabled(false);
		listWidget->setEnabled(true);
		lineEdit_SROMImageFile->setReadOnly(true);
		SaveItemToINI(strPortID_.c_str(), strROMFile_.c_str());
		bChangesSaved_ = true;

		strROMFile_ = "";
		lineEdit_SROMImageFile->setText(QString(""));
	} /* if */
} /* On Accept */

void ROMFileDlg::ReadINIParam_array(std::string Section, std::string Key,
		char* array) {
	std::string temp_string;
	temp_string = dtIniFile_.GetKeyValue(Section, Key);
	strcpy(array, temp_string.c_str());
}

