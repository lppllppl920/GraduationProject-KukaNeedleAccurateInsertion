/*
 * Conversions.h
 *
 *  Created on: Apr 19, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_CONVERSIONS_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_CONVERSIONS_H_

#include "CommandHandling.h"

/*****************************************************************
 Defines
 *****************************************************************/
#define RAD_TO_DEGREES        (180 / 3.1415926)

/*****************************************************************
 Routine Definitions
 *****************************************************************/
unsigned int ASCIIToHex(char Str[], int Len);
bool ExtractValue(char *Val, unsigned Len, float Divisor, float *Value);

int GetHex2(char *sz);
int GetHex1(char *sz);
int GetHex4(char *sz);
float GetFloat(char *sz);

void CvtQuatToRotationMatrix(QuatRotation *QuatRot, RotationMatrix RotMatrix);
void DetermineEuler(RotationMatrix RotMatrix, Rotation *EulerRot);
void CvtQuatToEulerRotation(QuatRotation *QuatRot, Rotation *EulerRot);

void QuatRotatePoint(QuatRotation *RotationQuaternionPtr,
		Position3d *OriginalPositionPtr, Position3d *RotatedPositionPtr);
void QuatInverseXfrm(QuatTransformation *Xfrm, QuatTransformation *NewXfrm);
void QuatCombineXfrms(QuatTransformation *Xfrm12, QuatTransformation *Xfrm23,
		QuatTransformation *Xfrm13);

/************************END OF FILE*****************************/

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_CONVERSIONS_H_ */
