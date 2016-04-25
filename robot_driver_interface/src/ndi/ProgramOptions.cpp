/*
 * ProgramOptions.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: lxt12
 */

#include <ndi/ProgramOptions.h>

ProgramOptions::ProgramOptions(QWidget* parent) {
	setupUi(this);

	if (!IniFile_.Load("/home/lxt12/NDIConfiguration.ini")) {
		ROS_ERROR("ProgramOptions: cannot find configuration file");
	}

	BeepOnError_ = false;
	BeepOnWarning_ = false;
	ClearLogFile_ = false;
	DateTimeStampFile_ = false;
	LogToFile_ = false;
	NoErrorBeeps_ = 0;
	NoWarningBeeps_ = 0;
	ReportWhileTracking_ = false;
	LogFile_ = "";
	ConfigurationFile_ = "/home/lxt12/NDIConfiguration.ini";

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

	BeepOnError_ = false;
	BeepOnWarning_ = false;
	ClearLogFile_ = false;
	DateTimeStampFile_ = false;
	LogToFile_ = false;
	NoErrorBeeps_ = 0;
	NoWarningBeeps_ = 0;
	ReportWhileTracking_ = false;
	LogFile_ = "";

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

	LogFile_ = lineEdit_File->text().toStdString();

	if (LogFile_.size() > 0) {
		pfOut = fopen(LogFile_.c_str(), "a+t");
		if (pfOut == NULL) {
			szErrorMessage = "Invalid File Name: " + LogFile_;
			ROS_ERROR("%s", szErrorMessage.c_str());
			lineEdit_File->setFocus();
			bFileValid = false;
		} /* if */
		else
			fclose(pfOut);
	} /* if */

	if (LogToFile_ && LogFile_.size() == 0) {
		ROS_ERROR("Please specify a log file.");
		lineEdit_File->setFocus();
		bFileValid = false;
	}/* if */

	if (bFileValid) {
		//TODO: ini file need to be saved
		IniFile_.SetKeyValue("Logging Options", "Log File Name", LogFile_);
		IniFile_.SetKeyValue("Logging Options", "Log To File",
				boost::lexical_cast<std::string>(LogToFile_));
		IniFile_.SetKeyValue("Logging Options", "Clear File",
				boost::lexical_cast<std::string>(ClearLogFile_));
		IniFile_.SetKeyValue("Logging Options", "Date Time Stamp",
				boost::lexical_cast<std::string>(DateTimeStampFile_));

		IniFile_.SetKeyValue("Beeping Options", "Beep On Error",
				boost::lexical_cast<std::string>(BeepOnError_));
		IniFile_.SetKeyValue("Beeping Options", "No Error Beeps",
				boost::lexical_cast<std::string>(NoErrorBeeps_));
		IniFile_.SetKeyValue("Beeping Options", "Beep On Warning",
				boost::lexical_cast<std::string>(BeepOnWarning_));
		IniFile_.SetKeyValue("Beeping Options", "No Warning Beeps",
				boost::lexical_cast<std::string>(NoWarningBeeps_));
		IniFile_.SetKeyValue("Reporting Options", "Report While Tracking",
				boost::lexical_cast<std::string>(ReportWhileTracking_));
		if (!IniFile_.Save(ConfigurationFile_)) {
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
	LogToFile_ = checkBox_LogCOMPortToFile->isChecked();

	lineEdit_File->setEnabled(LogToFile_);
	pushButton_browse->setEnabled(LogToFile_);
	checkBox_ClearFileonSystemInitialization->setEnabled(LogToFile_);
	checkBox_IncludeTimeStamp->setEnabled(LogToFile_);
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
	BeepOnError_ = checkBox_BeepSystemOnERROR->isChecked();
	/* active or de-activate the appropriate fields */
	lineEdit_BeepERRORNum->setEnabled(BeepOnError_);
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
	BeepOnWarning_ = checkBox_BeepSystemOnWARNING->isChecked();
	/* active or de-activate the appropriate fields */
	lineEdit_BeepWARNINGNum->setEnabled(BeepOnWarning_);
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
	LogToFile_ = false;
	ClearLogFile_ = false;
	DateTimeStampFile_ = false;
	BeepOnError_ = false;
	NoErrorBeeps_ = 1;
	BeepOnWarning_ = false;
	NoWarningBeeps_ = 1;
	ReportWhileTracking_ = true;

	ReadINIParam("Logging Options", "Log File Name", LogFile_);
	ReadINIParam("Logging Options", "Log To File", LogToFile_);
	ReadINIParam("Logging Options", "Clear File", ClearLogFile_);
	ReadINIParam("Logging Options", "Date Time Stamp", DateTimeStampFile_);

	ReadINIParam("Beeping Options", "Beep On Error", BeepOnError_);
	ReadINIParam("Beeping Options", "No Error Beeps", NoErrorBeeps_);
	ReadINIParam("Beeping Options", "Beep On Warning", BeepOnWarning_);
	ReadINIParam("Beeping Options", "No Warning Beeps", NoWarningBeeps_);

	ReadINIParam("Reporting Options", "Report While Tracking",
			ReportWhileTracking_);

	lineEdit_File->setText(QString(LogFile_.c_str()));
	checkBox_LogCOMPortToFile->setChecked(LogToFile_);
	checkBox_ClearFileonSystemInitialization->setChecked(ClearLogFile_);
	checkBox_IncludeTimeStamp->setChecked(DateTimeStampFile_);

	checkBox_BeepSystemOnERROR->setChecked(BeepOnError_);
	checkBox_BeepSystemOnWARNING->setChecked(BeepOnWarning_);
	lineEdit_BeepERRORNum->setText(
			QString(boost::lexical_cast<std::string>(NoErrorBeeps_).c_str()));
	lineEdit_BeepWARNINGNum->setText(
			QString(boost::lexical_cast<std::string>(NoWarningBeeps_).c_str()));

	checkBox_DisplayError->setChecked(ReportWhileTracking_);

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

	LogFile_ = filename.toStdString();
	lineEdit_File->setText(QString(LogFile_.c_str()));

} /* Browse */
void ProgramOptions::Cancel() {
	FILE *pfOut;
	std::string szErrorMessage;

	LogFile_ = lineEdit_File->text().toStdString();

	if (LogFile_.size() > 0) {
		pfOut = fopen(LogFile_.c_str(), "a+t");
		if (pfOut == NULL) {
			szErrorMessage = std::string("Invalid File Name: \n"
					"The COM Stream will not be logged until this is fixed.\n"
					"Please reopen this dialog later for logging correctly.")
					+ LogFile_;
		} /* if */
		else
			fclose(pfOut);
	}

	this->close();
}
