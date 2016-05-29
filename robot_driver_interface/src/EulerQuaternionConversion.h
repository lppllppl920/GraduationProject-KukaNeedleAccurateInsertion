/*
 * EulerQuaternionConversion.h
 *
 *  Created on: May 26, 2016
 *      Author: root
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_EULERQUATERNIONCONVERSION_H_
#define ROBOT_DRIVER_INTERFACE_SRC_EULERQUATERNIONCONVERSION_H_

#include <Eigen/Geometry>
#include <Eigen/Dense>

Eigen::Affine3d createRotationMatrix(double ax, double ay, double az);
Eigen::Matrix3d createRotationMatrix(double x, double y, double z, double w);
Eigen::Quaterniond Euler2Quaternion(double ax, double ay, double az);
Eigen::Vector3d Quaternion2Euler(double x, double y, double z, double w);

Eigen::Affine3d createRotationMatrix(float ax, float ay, float az);
Eigen::Matrix3d createRotationMatrix(float x, float y, float z, float w);
Eigen::Quaterniond Euler2Quaternion(float ax, float ay, float az);
Eigen::Vector3d Quaternion2Euler(float x, float y, float z, float w);

#endif /* ROBOT_DRIVER_INTERFACE_SRC_EULERQUATERNIONCONVERSION_H_ */
