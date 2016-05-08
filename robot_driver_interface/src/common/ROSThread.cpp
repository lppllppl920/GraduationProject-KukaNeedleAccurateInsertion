/*
 * ROSThread.cpp
 *
 *  Created on: May 7, 2016
 *      Author: root
 */

#include <ROSThread.h>

ROSThread::ROSThread() {
	ROS_INFO("ROSThread Constructing...");
}

ROSThread::~ROSThread() {
	std::cout << "ROSThread Deconstructing..." << std::endl;
	ros::shutdown();
	QApplication::exit();
}

void ROSThread::run() {
	ROS_INFO("ROS thread starts...");
	ros::spin();
}
