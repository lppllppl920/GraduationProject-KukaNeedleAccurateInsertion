/*
 * WaitForExecution.h
 *
 *  Created on: May 8, 2016
 *      Author: root
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_COMMON_WAITFOREXECUTION_H_
#define ROBOT_DRIVER_INTERFACE_SRC_COMMON_WAITFOREXECUTION_H_

#include <ros/ros.h>
#include "ui_robotInterface_WaitForExecution.h"

class WaitForExecution: public QDialog, private Ui::SubWindow_WaitForExecution {
Q_OBJECT
public:
	WaitForExecution(QDialog* parent = 0);
	virtual ~WaitForExecution();
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_COMMON_WAITFOREXECUTION_H_ */
