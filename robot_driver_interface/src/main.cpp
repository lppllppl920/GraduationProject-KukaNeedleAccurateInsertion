/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 25 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#include "Interface.h"

// TODO:
//  - replace definition with enum
//  - remove kdl_parser dependency
//  - check windows portability

// Feature:
//  1. 软pause/stop
//  2. 充分利用KRL motion primitive
//  3. 建立机器人Model，实现可达性校验
//  4. Plannar中的队列控制
//  5. Configuration Command功能
//  6. KRL Buffer + $ADVANCE，实现平滑运动
//  7. 使用ROS Rviz可视化，实现hardware in the loop仿真
//  8. 功能全面的GUI
//  9. 利用qt plot在运动中实现变量信息的可视化

// 控制 仿真 安全性 实验 总结展望

boost::shared_ptr<Interface> kuka_interface;
int main(int argc, char *argv[]) {

	QApplication a(argc, argv);
	ros::init(argc, argv, "Kuka_robot_node");
	//Interface kuka_interface(argc, argv, "manipulator");
	kuka_interface = boost::make_shared<Interface>();

	return a.exec();
}

