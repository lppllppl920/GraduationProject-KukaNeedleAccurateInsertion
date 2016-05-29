/*
 * WaitForIndicatorPlaced.h
 *
 *  Created on: May 15, 2016
 *      Author: root
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_COMMON_WAITFORINDICATORPLACED_H_
#define ROBOT_DRIVER_INTERFACE_SRC_COMMON_WAITFORINDICATORPLACED_H_

#include <ros/ros.h>
#include "ui_robotInterface_WaitForIndicatorPlaced.h"

#define INDICATOR_CANCEL 0
#define INDICATOR_OK 1

class WaitForIndicatorPlaced: public QDialog, private Ui::SubWindow_WaitForIndicatorPlaced {
Q_OBJECT
public:
	WaitForIndicatorPlaced(QDialog* parent = 0);
	virtual ~WaitForIndicatorPlaced();
	int nReturnValue_;

public slots:
	void OK();
	void Cancel();
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_COMMON_WAITFORINDICATORPLACED_H_ */
