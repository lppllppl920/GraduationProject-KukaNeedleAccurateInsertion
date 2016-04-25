/*
 * ProgramOptions.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: lxt12
 */

#include <ndi/ProgramOptions.h>

ProgramOptions::ProgramOptions(QWidget* parent) {
	setupUi(this);

	if (!dtIniFile_.Load("/home/lxt12/NDIConfiguration.ini")) {
		ROS_ERROR("ProgramOptions: cannot find configuration file");
	}

	bBeepOnError_ = false;
	bBeepOnWarning_ = false;
	bClearLogFile_ = false;
	bDateTimeStampFile_ = false;
	bLogToFile_ = false;
	nNoErrorBeeps_ = 0;
	nNoWarningBeeps_ = 0;
	bReportWhileTracking_ = false;
	strLogFile_ = "";
	strConfigurationFile_ = "/home/lxt12/NDIConfiguration.ini";

	connect(pushButton_OK, SIGNAL(clicked()), this, SLOT(OK()));
	connect(pushButton_Cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
	connect(pushButton_browse, SIGNAL(clicked()), this, SLOT(Browse()));
	connect(checkBox_LogCOMPortToFile, SIGNAL(stateChanged(int)), this,
			SLOT(LogToFile()));
	connect(checkBox_BeepSystemOnERROR, SIGNAL(stateChanged(int)), this,
			SLOT(BeepOnError()));
	connect(checkBox_BeepSystemOnWARNING, SIGNAL(stateChanged(int)), this,
			SLOT(BeepOnWarning()));

}

ProgramOptions::~ProgramOptions() {
	// TODO Auto-generated destructor stub
}
void ProgramOptions::Init() {

	bBeepOnError_ = false;
	bBeepOnWarning_ = false;
	bClearLogFile_ = false;
	bDateTimeStampFile_ = false;
	bLogToFile_ = false;
	nNoErrorBeeps_ = 0;
	nNoWarningBeeps_ = 0;
	bReportWhileTracking_ = false;
	strLogFile_ = "";

	FillForm();
	LogToFile();
	BeepOnError();
	BeepOnWarning();
}
/*****************************************************************
 Name:		OK

 Inputs:
 None.

 Return Value:
 None.

 Description:   This routine handles the pushing of the OK button
 on this dialog.
 *****************************************************************/
void ProgramOptions::OK() {
	FILE *pfOut;
	std::string szErrorMessage;
	bool bFileValid = TRUE;

	strLogFile_ = lineEdit_File->text().toStdString();

	if (strLogFile_.size() > 0) {
		pfOut = fopen(strLogFile_.c_str(), "a+t");
		if (pfOut == NULL) {
			szErrorMessage = "Invalid File Name: " + strLogFile_;
			ROS_ERROR("%s", szErrorMessage.c_str());
			lineEdit_File->setFocus();
			bFileValid = false;
		} /* if */
		else
			fclose(pfOut);
	} /* if */

	if (bLogToFile_ && strLogFile_.size() == 0) {
		ROS_ERROR("Please specify a log file.");
		lineEdit_File->setFocus();
		bFileValid = false;
	}/* if */

	if (bFileValid) {
		//TODO: ini file need to be saved
		dtIniFile_.SetKeyValue("Logging Options", "Log File Name", strLogFile_);
		dtIniFile_.SetKeyValue("Logging Options", "Log To File",
				boost::lexical_cast<std::string>(bLogToFile_));
		dtIniFile_.SetKeyValue("Logging Options", "Clear File",
				boost::lexical_cast<std::string>(bClearLogFile_));
		dtIniFile_.SetKeyValue("Logging Options", "Date Time Stamp",
				boost::lexical_cast<std::string>(bDateTimeStampFile_));

		dtIniFile_.SetKeyValue("Beeping Options", "Beep On Error",
				boost::lexical_cast<std::string>(bBeepOnError_));
		dtIniFile_.SetKeyValue("Beeping Options", "No Error Beeps",
				boost::lexical_cast<std::string>(nNoErrorBeeps_));
		dtIniFile_.SetKeyValue("Beeping Options", "Beep On Warning",
				boost::lexical_cast<std::string>(bBeepOnWarning_));
		dtIniFile_.SetKeyValue("Beeping Options", "No Warning Beeps",
				boost::lexical_cast<std::string>(nNoWarningBeeps_));
		dtIniFile_.SetKeyValue("Reporting Options", "Report While Tracking",
				boost::lexical_cast<std::string>(bReportWhileTracking_));
		if (!dtIniFile_.Save(strConfigurationFile_)) {
			ROS_ERROR("Cannot save configuration file");
			return;
		}
		this->close();
		emit OK_signal();
	} /* if */

} /* OK */
/*****************************************************************
 Name:		OnLogToFile()

 Inputs:
 None.

 Return Value:
 None.

 Description:   This routine handles what happens whe the Log To File
 check box is select or unselected.
 *****************************************************************/
void ProgramOptions::LogToFile() {
	bLogToFile_ = checkBox_LogCOMPortToFile->isChecked();

	lineEdit_File->setEnabled(bLogToFile_);
	pushButton_browse->setEnabled(bLogToFile_);
	checkBox_ClearFileonSystemInitialization->setEnabled(bLogToFile_);
	checkBox_IncludeTimeStamp->setEnabled(bLogToFile_);
}
/*****************************************************************
 Name:		BeepError()

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles what occurs when the "Beep on
 Error" check box is clicked.
 *****************************************************************/
void ProgramOptions::BeepOnError() {
	bBeepOnError_ = checkBox_BeepSystemOnERROR->isChecked();
	/* active or de-activate the appropriate fields */
	lineEdit_BeepERRORNum->setEnabled(bBeepOnError_);
} /* BeepError */
/*****************************************************************
 /*****************************************************************
 Name:		BeepOnWarning()

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles what occurs when the "Beep on
 Warning" check box is clicked.
 *****************************************************************/
void ProgramOptions::BeepOnWarning() {
	bBeepOnWarning_ = checkBox_BeepSystemOnWARNING->isChecked();
	/* active or de-activate the appropriate fields */
	lineEdit_BeepWARNINGNum->setEnabled(bBeepOnWarning_);
} /* BeepOnWarning */
/*****************************************************************
 Name:				FillForm()

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine gathers the information from the INI
 file and displays it in the form.
 *****************************************************************/
void ProgramOptions::FillForm() {
	bLogToFile_ = false;
	bClearLogFile_ = false;
	bDateTimeStampFile_ = false;
	bBeepOnError_ = false;
	nNoErrorBeeps_ = 1;
	bBeepOnWarning_ = false;
	nNoWarningBeeps_ = 1;
	bReportWhileTracking_ = true;

	ReadINIParam("Logging Options", "Log File Name", strLogFile_);
	ReadINIParam("Logging Options", "Log To File", bLogToFile_);
	ReadINIParam("Logging Options", "Clear File", bClearLogFile_);
	ReadINIParam("Logging Options", "Date Time Stamp", bDateTimeStampFile_);

	ReadINIParam("Beeping Options", "Beep On Error", bBeepOnError_);
	ReadINIParam("Beeping Options", "No Error Beeps", nNoErrorBeeps_);
	ReadINIParam("Beeping Options", "Beep On Warning", bBeepOnWarning_);
	ReadINIParam("Beeping Options", "No Warning Beeps", nNoWarningBeeps_);

	ReadINIParam("Reporting Options", "Report While Tracking",
			bReportWhileTracking_);

	lineEdit_File->setText(QString(strLogFile_.c_str()));
	checkBox_LogCOMPortToFile->setChecked(bLogToFile_);
	checkBox_ClearFileonSystemInitialization->setChecked(bClearLogFile_);
	checkBox_IncludeTimeStamp->setChecked(bDateTimeStampFile_);

	checkBox_BeepSystemOnERROR->setChecked(bBeepOnError_);
	checkBox_BeepSystemOnWARNING->setChecked(bBeepOnWarning_);
	lineEdit_BeepERRORNum->setText(
			QString(boost::lexical_cast<std::string>(nNoErrorBeeps_).c_str()));
	lineEdit_BeepWARNINGNum->setText(
			QString(
					boost::lexical_cast<std::string>(nNoWarningBeeps_).c_str()));

	checkBox_DisplayError->setChecked(bReportWhileTracking_);

} /* FillForm */
/*****************************************************************
 Name:				Browse()

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine controls the pushing of the "..." button.
 It brings up a file dialog box that allow the user to
 select a log file location.
 *****************************************************************/
void ProgramOptions::Browse() {

	QString filename = QFileDialog::getOpenFileName(this, tr("Open Document"),
			QDir::currentPath(), tr("All files (*.*)"));

	if (!filename.isNull()) {
		qDebug("%s", filename.toStdString().c_str());
	}

	strLogFile_ = filename.toStdString();
	lineEdit_File->setText(QString(strLogFile_.c_str()));

} /* Browse */
void ProgramOptions::Cancel() {
	FILE *pfOut;
	std::string szErrorMessage;

	strLogFile_ = lineEdit_File->text().toStdString();

	if (strLogFile_.size() > 0) {
		pfOut = fopen(strLogFile_.c_str(), "a+t");
		if (pfOut == NULL) {
			szErrorMessage = std::string("Invalid File Name: \n"
					"The COM Stream will not be logged until this is fixed.\n"
					"Please reopen this dialog later for logging correctly.")
					+ strLogFile_;
		} /* if */
		else
			fclose(pfOut);
	}

	this->close();
}
