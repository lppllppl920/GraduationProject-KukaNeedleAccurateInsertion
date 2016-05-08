/*
 * KukaFeedback.cpp
 *
 *  Created on: May 7, 2016
 *      Author: root
 */

#include <KukaFeedback.h>

KukaFeedback::KukaFeedback() {
	ROS_INFO("KukaFeedback Constructing...");
	bLastCommandComplete_ = false;
}

KukaFeedback::~KukaFeedback() {
	std::cout << "KukaFeedback Deconstructing..." << std::endl;
}

void KukaFeedback::ObtainJointFeedback(Feedback* feedback) {
	ROS_INFO("Joint feedback of KUKA received");
	dtFeedbackLock_.lockForWrite();
	dtJointFeedback_ = *feedback;
	dtFeedbackLock_.unlock();
}

void KukaFeedback::LastCommandComplete() {
	dtLastCommandCompleteLock_.lockForWrite();
	bLastCommandComplete_ = true;
	dtLastCommandCompleteLock_.unlock();
}
