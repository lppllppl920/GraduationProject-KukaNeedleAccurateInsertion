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
		temp_string = dtIniFile_.GetKeyValue(Section, Key);
		if (!temp_string.empty()) {
			Value = boost::lexical_cast<T>(temp_string);
		}
		return;
	}
public:
	bool bBeepOnError_;
	bool bBeepOnWarning_;
	bool bClearLogFile_;
	bool bDateTimeStampFile_;
	bool bLogToFile_;
	int nNoErrorBeeps_;
	int nNoWarningBeeps_;
	bool bReportWhileTracking_;
	std::string strLogFile_;
	std::string strConfigurationFile_;
	CIniFile dtIniFile_;

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
