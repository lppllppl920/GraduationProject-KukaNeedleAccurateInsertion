/*
 * COMPortSettings.h
 *
 *  Created on: Apr 22, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_COMPORTSETTINGS_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_COMPORTSETTINGS_H_
#include <boost/lexical_cast.hpp>
#include <ros/ros.h>
#include "ui_robotInterface_COMPortSettings.h"
#include "inifile.h"

class COMPortSettings: public QWidget, private Ui::SubWindow_COMPortSettings {
Q_OBJECT
public:
	COMPortSettings(QWidget *parent = 0);
	virtual ~COMPortSettings();

	template<class T> void ReadINIParam(std::string Section, std::string Key,
			T& Value) {
		std::string temp_string;
		temp_string = dtIniFile_.GetKeyValue(Section, Key);
		if (!temp_string.empty()) {
			Value = boost::lexical_cast<T>(temp_string);
		}
		return;
	}
	void Init();
public slots:
	void OK();
	void Cancel();signals:
	void OK_signal();
	void Cancel_signal();

public:
	bool bHardware_;
	bool bWireless_;
	bool bReset_;
	int nCOMPort_;
	std::string strLogFile_;
	std::string strConfigurationFile_;
	CIniFile dtIniFile_;
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_COMPORTSETTINGS_H_ */
