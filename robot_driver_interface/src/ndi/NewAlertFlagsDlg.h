/*
 * NewAlertFlagsDlg.h
 *
 *  Created on: Apr 23, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_NEWALERTFLAGSDLG_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_NEWALERTFLAGSDLG_H_

#include <ros/ros.h>
#include "gui/ui_robotInterface_NewAlertFlags.h"
#include "ndi/APIStructures.h"

class NewAlertFlagsDlg: public QWidget, private Ui::SubWindow_NewAlertFlags {
Q_OBJECT
public:
	NewAlertFlagsDlg(QWidget *parent = 0);
	virtual ~NewAlertFlagsDlg();

	void Init();
public slots:
	void OK();
public:
	DiagNewAlertFlags NewAlerts_;
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_NEWALERTFLAGSDLG_H_ */
