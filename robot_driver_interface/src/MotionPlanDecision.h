/*
 * MotionPlanDecision.h
 *
 *  Created on: May 6, 2016
 *      Author: root
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_MOTIONPLANDECISION_H_
#define ROBOT_DRIVER_INTERFACE_SRC_MOTIONPLANDECISION_H_
#include "ui_robotInterface_MotionPlanDecision.h"

#define MOTION_PLAN_EXECUTE 0
#define MOTION_PLAN_REPLAN 1
#define MOTION_PLAN_CANCEL 2
#define MOTION_PLAN_FAIL 3

class MotionPlanDecision: public QDialog, private Ui::SubWindow_PlanDecision {
Q_OBJECT
public:
	MotionPlanDecision(QDialog* parent = 0);
	virtual ~MotionPlanDecision();

public slots:
	void ExecutePlan();
	void Replan();
	void Cancel();

public:
	int nReturnValue_;
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_MOTIONPLANDECISION_H_ */
