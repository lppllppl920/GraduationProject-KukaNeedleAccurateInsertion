/**
 *   Copyright (C) Tsinghua University 2016
 *
 *   Version   : 2.0
 *   Date      : 2016
 *   Author    : Xingtong Liu
 *   Company   : Tsinghua University
 *   Email     : 327586708@qq.com
 */

#include "Interface.h"

boost::shared_ptr<Interface> kuka_interface;
int main(int argc, char *argv[]) {

	QApplication a(argc, argv);
	ros::init(argc, argv, "Kuka_robot_node");
	kuka_interface = boost::make_shared<Interface>();
	kuka_interface->show();

	return a.exec();
}

