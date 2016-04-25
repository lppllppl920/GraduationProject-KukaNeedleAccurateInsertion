/*
 * ProgramOptions.h
 *
 *  Created on: Apr 23, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_PROGRAMOPTIONS_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_PROGRAMOPTIONS_H_

#include <ros/ros.h>
#include <boost/lexical_cast.hpp>
#include <qfiledialog.h>
#include "gui/ui_robotInterface_ProgramOptions.h"
#include "ndi/inifile.h"

class ProgramOptions: public QWidget, private Ui::SubWindow_ProgramOptions {
Q_OBJECT
public:
	ProgramOptions(QWidget* parent = 0);
	virtual ~ProgramOptions();
	template<class T> void ReadINIParam(std::string Section, std::string Key,
			T& Value) {
		std::string temp_string;
		temp_string = IniFile_.GetKeyValue(Section, Key);
		if (!temp_string.empty()) {
			Value = boost::lexical_cast<T>(temp_string);
		}
		return;
	}
public:
	bool BeepOnError_;
	bool BeepOnWarning_;
	bool ClearLogFile_;
	bool DateTimeStampFile_;
	bool LogToFile_;
	int NoErrorBeeps_;
	int NoWarningBeeps_;
	bool ReportWhileTracking_;
	std::string LogFile_;
	std::string ConfigurationFile_;
	CIniFile IniFile_;

public slots:
	void Init();
	void OK();
	void Cancel();
	void LogToFile();
	void BeepOnError();
	void BeepOnWarning();
	void Browse();
	void FillForm();signals:
	void OK_signal();
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_PROGRAMOPTIONS_H_ */
