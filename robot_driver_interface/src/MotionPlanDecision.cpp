/*
 * MotionPlanDecision.cpp
 *
 *  Created on: May 6, 2016
 *      Author: root
 */

#include <MotionPlanDecision.h>

MotionPlanDecision::MotionPlanDecision(QDialog* parent) {
	setupUi(this);

	connect(pushButton_ExecutePlan, SIGNAL(clicked()), this,
			SLOT(ExecutePlan()));
	connect(pushButton_Replan, SIGNAL(clicked()), this, SLOT(Replan()));
	connect(pushButton_Cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
	nReturnValue_ = -1;
}

MotionPlanDecision::~MotionPlanDecision() {

}

void MotionPlanDecision::ExecutePlan() {
	nReturnValue_ = MOTION_PLAN_EXECUTE;
	this->close();
}

void MotionPlanDecision::Replan() {
	nReturnValue_ = MOTION_PLAN_REPLAN;
	this->close();
}

void MotionPlanDecision::Cancel() {
	nReturnValue_ = MOTION_PLAN_CANCEL;
	this->close();
}

