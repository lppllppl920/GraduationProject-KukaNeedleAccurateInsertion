/*
 * SystemFeaturesDlg.h
 *
 *  Created on: Apr 23, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_SYSTEMFEATURESDLG_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_SYSTEMFEATURESDLG_H_

#include <ros/ros.h>
#include <boost/lexical_cast.hpp>
#include "gui/ui_robotInterface_SystemFeatures.h"
#include "ndi/CommandHandling.h"

class SystemFeaturesDlg: public QWidget, private Ui::SubWindow_SystemFeatures {
Q_OBJECT
public:
	SystemFeaturesDlg();
	virtual ~SystemFeaturesDlg();
	void Init();
	void SetVariables(std::string pszVersionInfo, int nNoActivePorts,
			int nNoPassivePorts, int nNoActiveWireless, int nNoTIPDetection,
			int nTypeofSystem);
	void SetVariables(std::string pszVersionInfo, int nNoMagneticPorts,
			int nNoFieldGenerators, int nNoFieldGeneratorCards,
			int nTypeofSystem);

	int NoActivePorts_;
	int NoActiveWireless_;
	int NoPassivePorts_;
	int NoTIPDetectionPorts_;
	int TypeOfSystem_;
	std::string VersionInfo_;
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_SYSTEMFEATURESDLG_H_ */
