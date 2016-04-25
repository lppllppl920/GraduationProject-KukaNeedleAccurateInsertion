/*
 * Conversions.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: lxt12
 */

#include "Conversions.h"
#include "math.h"

/*****************************************************************
 Defines
 *****************************************************************/
/* None. */

/*****************************************************************
 Global Variables
 *****************************************************************/
/* None. */

/***************************************************************************
 Name:               uASCIIToHex

 Input Values:
 char
 szStr[]				:String of ASCII characters that make up a hex
 integer value to be converted.
 Note that the string may NOT be null-terminated.
 int
 nLen				:Length of input string.

 Output Values:
 None.

 Returned Value:
 unsigned int			:Integer equivalent of input array.

 Description:
 This routine translates a character ASCII array which is
 hex to its equivalent integer value.

 ***************************************************************************/
unsigned int ASCIIToHex(char szStr[], int nLen) {
	char chTemp;
	unsigned int uVal;
	int nCnt;

	uVal = 0;
	for (nCnt = 0; nCnt < nLen; ++nCnt) {
		chTemp = szStr[nCnt];
		/*
		 * Convert hex ASCII digits to values to add to total value.
		 */
		if ((chTemp >= '0') && (chTemp <= '9')) {
			chTemp -= '0';
		} /* if */
		else if ((chTemp >= 'A') && (chTemp <= 'F')) {
			chTemp = 0x0000000a + (chTemp - 'A');
		} /* else if */
		else if ((chTemp >= 'a') && (chTemp <= 'f')) {
			chTemp = 0x0000000a + (chTemp - 'a');
		} /* else if */
		else {
			/*
			 * We've hit a non-hex character.
			 */
			return (0);
		} /* else */

		/*
		 * Shift result into position of total value.
		 */
		uVal |= (chTemp << (4 * (nLen - 1 - nCnt)));
	} /* for */

	return (uVal);
} /* uASCIIToHex */
/*****************************************************************
 Routine:    bExtractValue

 Inputs:	pszVal - value to be extracted, uLen - length of value
 fDivisor - how to break up information, pfValue - data

 Returns:

 Description: This routine breaks up the transformation into
 there individual components

 *****************************************************************/
bool ExtractValue(char *pszVal, unsigned uLen, float fDivisor, float *pfValue) {
	unsigned i;
	char szBuff[10];

	*pfValue = BAD_FLOAT;

	/*
	 * Make sure that the first character is either a + or -.
	 */
	if (*pszVal != '-' && *pszVal != '+') {
		return false;
	} /* if */

	/*
	 * Copy the + or - character to the buffer
	 */
	szBuff[0] = *pszVal;

	/*
	 * Copy the rest of the value.  Make sure that the remainder of
	 * the value string contains only digits 0 - 9.
	 */
	for (i = 1; i < uLen; i++) {
		if (pszVal[i] < '0' || pszVal[i] > '9') {
			return false;
		} /* if */

		szBuff[i] = pszVal[i];
	} /* for */

	/*
	 * Null terminate the string.
	 */
	szBuff[i] = '\0';

	*pfValue = float(atof(szBuff) / fDivisor);

	return true;
} /* bExtractValue */
/*****************************************************************
 Routine:   nGetHex1

 Inputs:		char *sz - the buffer that contains the 2 hex chars
 of information to be decoded

 Returns:	int u - the decimal value of the decoding

 Description:
 Converts two (2) hex characters to its decimal equivialent

 *****************************************************************/
int GetHex1(char *sz) {
	unsigned int u;

	u = sz[0] & 0xff;

	return u;
} /* nGetHex1 */
/*****************************************************************
 Routine:   nGetHex2

 Inputs:		char *sz - the buffer that contains the 2 hex chars
 of information to be decoded

 Returns:	int u - the decimal value of the decoding

 Description:
 Converts two (2) hex characters to its decimal equivialent

 *****************************************************************/
int GetHex2(char *sz) {
	unsigned int u;

	u = sz[0] & 0xff;
	u |= ((sz[1] & 0xFF) << 8);

	return u;
} /* nGetHex2 */
/*****************************************************************
 Routine:   nGetHex4

 Inputs:		char *sz - the buffer that contains the 4 hex chars
 of information to be decoded

 Returns:	int u - the decimal value of the decoding

 Description:
 Converts two (4) hex characters to its decimal equivialent

 *****************************************************************/
int GetHex4(char *sz) {
	unsigned int u;

	u = sz[0] & 0xff;
	u |= ((sz[1] & 0xFF) << 8);
	u |= ((sz[2] & 0xFF) << 16);
	u |= ((sz[3] & 0xFF) << 24);

	return (int) u;
} /* nGetHex4 */
/*****************************************************************
 Routine:   fGetFloat

 Inputs:		char *sz - the buffer that contains the 2 hex chars
 of information to be decoded

 Returns:	int f - the float value of the decoding

 Description:
 Converts two (2) hex characters to its float equivialent

 *****************************************************************/
float GetFloat(char *sz) {
	float f;
	unsigned int *pu;

	pu = ((unsigned int *) &f);

	(*pu) = sz[0] & 0xff;
	(*pu) |= ((sz[1] & 0xFF) << 8);
	(*pu) |= ((sz[2] & 0xFF) << 16);
	(*pu) |= ((sz[3] & 0xFF) << 24);

	return f;
} /* fGetFloat */

/****** MATH FUNCTIONS FOR EULER AND QUATERNION MATH ******/
/********************************************************************
 Name:        CvtQuatToRotationMatrix

 Input Values:
 QuatRotation
 *pdtQuatRot :Ptr to the quaternion rotation.

 Output Values:
 RotationMatrix
 dtRotationMatrix :The 3x3 determined rotation matrix.

 Returned Value:
 None.
 Description:
 This routine determines the rotation matrix that corresponds
 to the given quaternion.

 Let the quaternion be represented by:

 | Q0 |
 Q = | Qx |
 | Qy |
 | Qz |

 and the rotation matrix by:

 | M00 M01 M02 |
 M = | M10 M11 M12 |
 | M20 M21 M22 |

 then assuming the quaternion, Q, has been normalized to convert
 Q to M we use the following equations:

 M00 = (Q0 * Q0) + (Qx * Qx) - (Qy * Qy) - (Qz * Qz)
 M01 = 2 * ((Qx * Qy) - (Q0 * Qz))
 M02 = 2 * ((Qx * Qz) + (Q0 * Qy))
 M10 = 2 * ((Qx * Qy) + (Q0 * Qz))
 M11 = (Q0 * Q0) - (Qx * Qx) + (Qy * Qy) - (Qz * Qz)
 M12 = 2 * ((Qy * Qz) - (Q0 * Qx))
 M20 = 2 * ((Qx * Qz) - (Q0 * Qy))
 M21 = 2 * ((Qy * Qz) + (Q0 * Qx))
 M22 = (Q0 * Q0) - (Qx * Qx) - (Qy * Qy) + (Qz * Qz)
 *********************************************************************/
void CvtQuatToRotationMatrix(QuatRotation *pdtQuatRot,
		RotationMatrix dtRotMatrix) {
	float fQ0Q0, fQxQx, fQyQy, fQzQz, fQ0Qx, fQ0Qy, fQ0Qz, fQxQy, fQxQz, fQyQz;

	/*
	 * Determine some calculations done more than once.
	 */
	fQ0Q0 = pdtQuatRot->fQ0 * pdtQuatRot->fQ0;
	fQxQx = pdtQuatRot->fQx * pdtQuatRot->fQx;
	fQyQy = pdtQuatRot->fQy * pdtQuatRot->fQy;
	fQzQz = pdtQuatRot->fQz * pdtQuatRot->fQz;
	fQ0Qx = pdtQuatRot->fQ0 * pdtQuatRot->fQx;
	fQ0Qy = pdtQuatRot->fQ0 * pdtQuatRot->fQy;
	fQ0Qz = pdtQuatRot->fQ0 * pdtQuatRot->fQz;
	fQxQy = pdtQuatRot->fQx * pdtQuatRot->fQy;
	fQxQz = pdtQuatRot->fQx * pdtQuatRot->fQz;
	fQyQz = pdtQuatRot->fQy * pdtQuatRot->fQz;

	/*
	 * Determine the rotation matrix elements.
	 */
	dtRotMatrix[0][0] = fQ0Q0 + fQxQx - fQyQy - fQzQz;
	dtRotMatrix[0][1] = 2.0 * (-fQ0Qz + fQxQy);
	dtRotMatrix[0][2] = 2.0 * (fQ0Qy + fQxQz);
	dtRotMatrix[1][0] = 2.0 * (fQ0Qz + fQxQy);
	dtRotMatrix[1][1] = fQ0Q0 - fQxQx + fQyQy - fQzQz;
	dtRotMatrix[1][2] = 2.0 * (-fQ0Qx + fQyQz);
	dtRotMatrix[2][0] = 2.0 * (-fQ0Qy + fQxQz);
	dtRotMatrix[2][1] = 2.0 * (fQ0Qx + fQyQz);
	dtRotMatrix[2][2] = fQ0Q0 - fQxQx - fQyQy + fQzQz;

} /* CvtQuatToRotationMatrix */

/*******************************************************************
 Name:         DetermineEuler

 Input Values:
 RotationMatrix
 dtRotationMatrix :The 3x3 rotation matrix to convert.

 Output Values:
 Rotation
 *pdtEulerRot :Rotation is Euler angle format.
 Roll, pitch, yaw Euler angles which define the required rotation.

 Returned Value:
 None.

 Description:
 This routine calculates the Euler angles given the 3x3 rotation matrix.
 *******************************************************************/
void DetermineEuler(RotationMatrix dtRotMatrix, Rotation *pdtEulerRot) {
	float Roll, fCosRoll, fSinRoll;

	Roll = atan2(dtRotMatrix[1][0], dtRotMatrix[0][0]);
	fCosRoll = cos(Roll);
	fSinRoll = sin(Roll);

	pdtEulerRot->fRoll = Roll;
	pdtEulerRot->fPitch = atan2(-dtRotMatrix[2][0],
			(fCosRoll * dtRotMatrix[0][0]) + (fSinRoll * dtRotMatrix[1][0]));
	pdtEulerRot->fYaw = atan2(
			(fSinRoll * dtRotMatrix[0][2]) - (fCosRoll * dtRotMatrix[1][2]),
			(-fSinRoll * dtRotMatrix[0][1]) + (fCosRoll * dtRotMatrix[1][1]));

} /* DetermineEuler */

/**************************************************************
 Name:        CvtQuatToEulerRotation

 Input Values:
 QuatRotation
 *pdtQuatRot :Ptr to the quaternion rotation.

 Output Values:
 Rotation
 *pdtEulerRot :Ptr to the determined rotation Euler angles.

 Returned Value:
 None.

 Description:
 This routine determines the rotation in Euler angles (degrees)that
 corresponds to the given quaternion rotation.
 ******************************************************************/
void CvtQuatToEulerRotation(QuatRotation *pdtQuatRot, Rotation *pdtEulerRot) {
	RotationMatrix dtRotMatrix;

	CvtQuatToRotationMatrix(pdtQuatRot, dtRotMatrix);

	DetermineEuler(dtRotMatrix, pdtEulerRot);

	pdtEulerRot->fYaw *= RAD_TO_DEGREES;
	pdtEulerRot->fPitch *= RAD_TO_DEGREES;
	pdtEulerRot->fRoll *= RAD_TO_DEGREES;

} /* CvtQuatToEulerRotation */

/*****************************************************************
 Name:               QuatRotatePoint

 Input Values:
 QuatRotation
 *RotationQuaternionPtr: pointer to the quaternion
 defining the rotation

 QuatVector3dStruct
 *OriginalPositionPtr  : pointer to struct containing the
 original position of the given point
 *RotatedPositionPtr   : pointer to struct containing the
 rotated position of the given point

 Output Values:
 The vector pointed to by RotatedPositionPtr is over written
 with the calculated position of the point after rotation.

 Returned Value:
 None

 Description:
 This routine calculates the 3-D position of a given point after
 being rotated by a rotation defined by the given quaternion

 *****************************************************************/
void QuatRotatePoint(QuatRotation *RotationQuaternionPtr,
		Position3d *OriginalPositionPtr, Position3d *RotatedPositionPtr) {
	Position3d UCrossV; /* The cross product of the vector part of the rotation
	 quaternion with the original position vector */

	if (OriginalPositionPtr->fTx < MAX_NEGATIVE
			|| OriginalPositionPtr->fTy < MAX_NEGATIVE
			|| OriginalPositionPtr->fTz < MAX_NEGATIVE) {
		RotatedPositionPtr->fTx = RotatedPositionPtr->fTy =
				RotatedPositionPtr->fTz =
				BAD_FLOAT;

		return;
	} /* if */

	UCrossV.fTx = RotationQuaternionPtr->fQy * OriginalPositionPtr->fTz
			- RotationQuaternionPtr->fQz * OriginalPositionPtr->fTy;
	UCrossV.fTy = RotationQuaternionPtr->fQz * OriginalPositionPtr->fTx
			- RotationQuaternionPtr->fQx * OriginalPositionPtr->fTz;
	UCrossV.fTz = RotationQuaternionPtr->fQx * OriginalPositionPtr->fTy
			- RotationQuaternionPtr->fQy * OriginalPositionPtr->fTx;

	RotatedPositionPtr->fTx =
			float(
					OriginalPositionPtr->fTx
							+ 2.0
									* (RotationQuaternionPtr->fQ0 * UCrossV.fTx
											+ RotationQuaternionPtr->fQy
													* UCrossV.fTz
											- RotationQuaternionPtr->fQz
													* UCrossV.fTy));
	RotatedPositionPtr->fTy =
			float(
					OriginalPositionPtr->fTy
							+ 2.0
									* (RotationQuaternionPtr->fQ0 * UCrossV.fTy
											+ RotationQuaternionPtr->fQz
													* UCrossV.fTx
											- RotationQuaternionPtr->fQx
													* UCrossV.fTz));
	RotatedPositionPtr->fTz =
			float(
					OriginalPositionPtr->fTz
							+ 2.0
									* (RotationQuaternionPtr->fQ0 * UCrossV.fTz
											+ RotationQuaternionPtr->fQx
													* UCrossV.fTy
											- RotationQuaternionPtr->fQy
													* UCrossV.fTx));
} /* QuatRotatePoint */

/*****************************************************************
 Name:            QuatInverseXfrm

 Input Values:
 QuatTransformation
 *pdtXfrm             : input transformation

 Output Values:
 QuatTransformation
 *pdtNewXfrm          : new inversed transformation

 Returned Value:
 None

 Description:
 This routine determines the inverse transform to the given
 transformation

 *****************************************************************/
void QuatInverseXfrm(QuatTransformation *pdtXfrm,
		QuatTransformation *pdtNewXfrm) {
	pdtNewXfrm->dtRotation.fQ0 = pdtXfrm->dtRotation.fQ0;
	pdtNewXfrm->dtRotation.fQx = -pdtXfrm->dtRotation.fQx;
	pdtNewXfrm->dtRotation.fQy = -pdtXfrm->dtRotation.fQy;
	pdtNewXfrm->dtRotation.fQz = -pdtXfrm->dtRotation.fQz;

	QuatRotatePoint(&pdtNewXfrm->dtRotation, &pdtXfrm->dtTranslation,
			&pdtNewXfrm->dtTranslation);

	pdtNewXfrm->dtTranslation.fTx = -pdtNewXfrm->dtTranslation.fTx;
	pdtNewXfrm->dtTranslation.fTy = -pdtNewXfrm->dtTranslation.fTy;
	pdtNewXfrm->dtTranslation.fTz = -pdtNewXfrm->dtTranslation.fTz;
} /* QuatInverseXfrm */

/*****************************************************************
 Name:            QuatCombineXfrms

 Input Values:
 QuatTransformation
 *pdtXfrm12           : Transformation from RF 1 to RF 2
 *pdtXfrm23           : Transformation from RF 2 to RF 3

 Output Values:
 QuatTransformation
 *pdtXfrm13           : Output Transformation from RF 1 to RF 3

 Returned Value:
 None

 Description:
 This routine combines the input transformations from RF 1 to RF 2
 and RF 2 to RF 3 to generate a new transformation from RF 1 to RF 3
 *****************************************************************/
void QuatCombineXfrms(QuatTransformation *pdtXfrm12,
		QuatTransformation *pdtXfrm23, QuatTransformation *pdtXfrm13) {
	QuatRotation *pdtQ12 = &pdtXfrm12->dtRotation, *pdtQ23 =
			&pdtXfrm23->dtRotation, *pdtQ13 = &pdtXfrm13->dtRotation;
	float fA, /* some useful temporary variables */
	fB, fC, fD, fE, fF, fG, fH;

	fA = (pdtQ23->fQ0 + pdtQ23->fQx) * (pdtQ12->fQ0 + pdtQ12->fQx);
	fB = (pdtQ23->fQz - pdtQ23->fQy) * (pdtQ12->fQy - pdtQ12->fQz);
	fC = (pdtQ23->fQx - pdtQ23->fQ0) * (pdtQ12->fQy + pdtQ12->fQz);
	fD = (pdtQ23->fQy + pdtQ23->fQz) * (pdtQ12->fQx - pdtQ12->fQ0);
	fE = (pdtQ23->fQx + pdtQ23->fQz) * (pdtQ12->fQx + pdtQ12->fQy);
	fF = (pdtQ23->fQx - pdtQ23->fQz) * (pdtQ12->fQx - pdtQ12->fQy);
	fG = (pdtQ23->fQ0 + pdtQ23->fQy) * (pdtQ12->fQ0 - pdtQ12->fQz);
	fH = (pdtQ23->fQ0 - pdtQ23->fQy) * (pdtQ12->fQ0 + pdtQ12->fQz);

	pdtQ13->fQ0 = float(fB + (-fE - fF + fG + fH) / 2.0);
	pdtQ13->fQx = float(fA - (fE + fF + fG + fH) / 2.0);
	pdtQ13->fQy = float(-fC + (fE - fF + fG - fH) / 2.0);
	pdtQ13->fQz = float(-fD + (fE - fF - fG + fH) / 2.0);

	QuatRotatePoint(&pdtXfrm23->dtRotation, &pdtXfrm12->dtTranslation,
			&pdtXfrm13->dtTranslation);
	pdtXfrm13->dtTranslation.fTx += pdtXfrm23->dtTranslation.fTx;
	pdtXfrm13->dtTranslation.fTy += pdtXfrm23->dtTranslation.fTy;
	pdtXfrm13->dtTranslation.fTz += pdtXfrm23->dtTranslation.fTz;
} /* QuatCombineXfrms */
/**************************END OF FILE***************************/

