/*
 * COMPortTimeOut.h
 *
 *  Created on: Apr 24, 2016
 *      Author: root
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_COMPORTTIMEOUT_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_COMPORTTIMEOUT_H_

#include <boost/lexical_cast.hpp>
#include <ros/ros.h>

#include "ui_robotInterface_COMPortTimeOut.h"
#include "ndi/APIStructures.h"
#include "inifile.h"

class COMPortTimeOut:public QDialog, private Ui::SubWindow_COMPortTimeOut {
Q_OBJECT
public:
	COMPortTimeOut(QDialog* parent = 0);
	virtual ~COMPortTimeOut();

public slots:
	void Retry();
	void Closeapplication();
	void Restart();

public:
	int ReturnValue_;
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_COMPORTTIMEOUT_H_ */
