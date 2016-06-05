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

// order: x, y, z, w
Eigen::Vector4d Euler2Quaternion(double ax, double ay, double az) {
	Eigen::Vector4d result;
	KDL::Rotation kdl_rotation = KDL::Rotation::RPY(ax, ay, az);
	kdl_rotation.GetQuaternion(result.data()[0], result.data()[1], result.data()[2], result.data()[3]);
	return result;
}

Eigen::Vector4d Euler2Quaternion(float ax, float ay, float az) {
	Eigen::Vector4d result;
	KDL::Rotation kdl_rotation = KDL::Rotation::RPY(ax, ay, az);
	kdl_rotation.GetQuaternion(result.data()[0], result.data()[1], result.data()[2], result.data()[3]);
	return result;
}

// order: A, B, C
Eigen::Vector3d Quaternion2Euler(double x, double y, double z, double w) {
	KDL::Rotation kdl_rotation = KDL::Rotation::Quaternion(x, y, z, w);
	Eigen::Vector3d result;
	kdl_rotation.GetRPY(result.data()[2], result.data()[1], result.data()[0]);
	return result;
}

Eigen::Vector3d Quaternion2Euler(float x, float y, float z, float w) {
	KDL::Rotation kdl_rotation = KDL::Rotation::Quaternion(x, y, z, w);
	Eigen::Vector3d result;
	kdl_rotation.GetRPY(result.data()[2], result.data()[1], result.data()[0]);
	return result;
}

Eigen::Matrix3d createRotationMatrix(double x, double y, double z, double w) {
	KDL::Rotation kdl_rotaion = KDL::Rotation::Quaternion(x, y, z, w);
	Eigen::Matrix3d result;
	for(int i = 0; i < 9; i++) {
		result.data()[i] = kdl_rotaion.data[i];
	}
	result.transposeInPlace();
	return result;
}

Eigen::Matrix3d createRotationMatrix(float x, float y, float z, float w) {
	KDL::Rotation kdl_rotaion = KDL::Rotation::Quaternion(x, y, z, w);
	Eigen::Matrix3d result;
	for(int i = 0; i < 9; i++) {
		result.data()[i] = kdl_rotaion.data[i];
	}
	result.transposeInPlace();
	return result;


}
