/*
 * IlluminatorFiringRate.h
 *
 *  Created on: Apr 24, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_ILLUMINATORFIRINGRATE_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_ILLUMINATORFIRINGRATE_H_

#include <ros/ros.h>
#include <boost/lexical_cast.hpp>
#include "ndi/inifile.h"
#include "ndi/CommandHandling.h"
#include "ui_robotInterface_IlluminatorFiringRate.h"

class IlluminatorFiringRate: public QWidget,
		private Ui::SubWindow_IlluminatorFiringRate {
Q_OBJECT
public:
	IlluminatorFiringRate();
	virtual ~IlluminatorFiringRate();
	template<class T> void ReadINIParam(std::string Section, std::string Key,
			T& Value) {
		std::string temp_string;
		temp_string = dtIniFile_.GetKeyValue(Section, Key);
		if (!temp_string.empty()) {
			Value = boost::lexical_cast<T>(temp_string);
		}
		return;
	}

	int nFiringRate_;
	int nTypeOfSystem_;
	CIniFile dtIniFile_;
	std::string strConfigurationFile_;

public slots:
	void Init();
	void OK();
	void Cancel();signals:
	void OK_signal();
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_ILLUMINATORFIRINGRATE_H_ */
