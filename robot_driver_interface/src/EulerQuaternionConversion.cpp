/*
 * EulerQuaternionConversion.cpp
 *
 *  Created on: May 26, 2016
 *      Author: root
 */
#include "EulerQuaternionConversion.h"

Eigen::Affine3d createRotationMatrix(double ax, double ay, double az) {
	Eigen::Affine3d rx = Eigen::Affine3d(
			Eigen::AngleAxisd(ax, Eigen::Vector3d(1, 0, 0)));
	Eigen::Affine3d ry = Eigen::Affine3d(
			Eigen::AngleAxisd(ay, Eigen::Vector3d(0, 1, 0)));
	Eigen::Affine3d rz = Eigen::Affine3d(
			Eigen::AngleAxisd(az, Eigen::Vector3d(0, 0, 1)));
	return rz * ry * rx;
}

Eigen::Affine3d createRotationMatrix(float ax, float ay, float az) {
	Eigen::Affine3d rx = Eigen::Affine3d(
			Eigen::AngleAxisd(ax, Eigen::Vector3d(1, 0, 0)));
	Eigen::Affine3d ry = Eigen::Affine3d(
			Eigen::AngleAxisd(ay, Eigen::Vector3d(0, 1, 0)));
	Eigen::Affine3d rz = Eigen::Affine3d(
			Eigen::AngleAxisd(az, Eigen::Vector3d(0, 0, 1)));
	return rz * ry * rx;
}

Eigen::Quaterniond Euler2Quaternion(double ax, double ay, double az) {
	Eigen::AngleAxisd rollAngle(ax, Eigen::Vector3d(1, 0, 0));
	Eigen::AngleAxisd yawAngle(ay, Eigen::Vector3d(0, 1, 0));
	Eigen::AngleAxisd pitchAngle(az, Eigen::Vector3d(0, 0, 1));

	Eigen::Quaterniond q = pitchAngle * yawAngle * rollAngle;

	return q;
}

Eigen::Quaterniond Euler2Quaternion(float ax, float ay, float az) {
	Eigen::AngleAxisd rollAngle(ax, Eigen::Vector3d(1, 0, 0));
	Eigen::AngleAxisd yawAngle(ay, Eigen::Vector3d(0, 1, 0));
	Eigen::AngleAxisd pitchAngle(az, Eigen::Vector3d(0, 0, 1));

	Eigen::Quaterniond q = pitchAngle * yawAngle * rollAngle;

	return q;
}

Eigen::Vector3d Quaternion2Euler(double x, double y, double z, double w) {
	Eigen::Quaterniond q;
	q.x() = x;
	q.y() = y;
	q.z() = z;
	q.w() = w;

	Eigen::Matrix3d rotation = q.toRotationMatrix();
	return rotation.eulerAngles(2, 1, 0);

}

Eigen::Vector3d Quaternion2Euler(float x, float y, float z, float w) {
	Eigen::Quaterniond q;
	q.x() = x;
	q.y() = y;
	q.z() = z;
	q.w() = w;

	Eigen::Matrix3d rotation = q.toRotationMatrix();
	return rotation.eulerAngles(2, 1, 0);

}

Eigen::Matrix3d createRotationMatrix(double x, double y, double z, double w) {
	Eigen::Quaterniond q;
	q.x() = x;
	q.y() = y;
	q.z() = z;
	q.w() = w;

	return q.toRotationMatrix();
}

Eigen::Matrix3d createRotationMatrix(float x, float y, float z, float w) {
	Eigen::Quaterniond q;
	q.x() = x;
	q.y() = y;
	q.z() = z;
	q.w() = w;

	return q.toRotationMatrix();
}
