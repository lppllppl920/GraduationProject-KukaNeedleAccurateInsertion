/*
 * KukaFeedback.h
 *
 *  Created on: May 7, 2016
 *      Author: root
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_KUKAFEEDBACK_H_
#define ROBOT_DRIVER_INTERFACE_SRC_KUKAFEEDBACK_H_

#include <QApplication>
#include <ros/ros.h>
#include <qreadwritelock.h>

#include "message.h"

class KukaFeedback: public QObject {
Q_OBJECT
public:
	KukaFeedback();
	virtual ~KukaFeedback();

public slots:
	void ObtainJointFeedback(Feedback* feedback);
	void LastCommandComplete();signals:
	void closeWindow();

public:
	QReadWriteLock dtFeedbackLock_;
	QReadWriteLock dtLastCommandCompleteLock_;
	Feedback dtJointFeedback_;
	bool bLastCommandComplete_;
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_KUKAFEEDBACK_H_ */
