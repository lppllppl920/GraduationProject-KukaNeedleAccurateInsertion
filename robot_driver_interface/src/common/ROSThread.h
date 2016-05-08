/*
 * ROSThread.h
 *
 *  Created on: May 7, 2016
 *      Author: root
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_COMMON_ROSTHREAD_H_
#define ROBOT_DRIVER_INTERFACE_SRC_COMMON_ROSTHREAD_H_

#include <QThread>
#include <QMutex>
#include <QApplication>
#include <ros/ros.h>

class ROSThread: public QThread {
Q_OBJECT
public:
	ROSThread();
	virtual ~ROSThread();
	void run();
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_COMMON_ROSTHREAD_H_ */
