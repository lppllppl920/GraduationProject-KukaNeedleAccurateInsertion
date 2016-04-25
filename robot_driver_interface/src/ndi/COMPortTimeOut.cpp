/*
 * COMPortTimeOut.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: root
 */

#include <ndi/COMPortTimeOut.h>

COMPortTimeOut::COMPortTimeOut(QDialog* parent) {
	setupUi(this);
	connect(pushButton_CloseApplication, SIGNAL(clicked()), this,
			SLOT(Closeapplication()));
	connect(pushButton_Retry, SIGNAL(clicked()), this, SLOT(Retry()));
	connect(pushButton_Restart, SIGNAL(clicked()), this, SLOT(Restart()));
	nReturnValue_ = 0;
}

COMPortTimeOut::~COMPortTimeOut() {
	// TODO Auto-generated destructor stub
}

/*****************************************************************
 Name:				Retry

 Inputs:
 None.

 Return Value:
 None.

 Description:   This routine handles what happens when the user
 chooses to retry the command.
 *****************************************************************/
void COMPortTimeOut::Retry() {
	/* return Continue value */
	nReturnValue_ = ERROR_TIMEOUT_CONT;
	this->close();
} /* Retry */
/*****************************************************************
 Name:				CloseApplication

 Inputs:
 None.

 Return Value:
 None.

 Description:	This routine handles what happens when the user
 chooses to close the application.
 *****************************************************************/
void COMPortTimeOut::Closeapplication() {
	/* get the main window handle */
	nReturnValue_ = ERROR_TIMEOUT_CLOSE;
	this->close();
} /* Closeapplication */
/*****************************************************************
 Name:				Restart

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine handles what happens when the user
 pressed the Restart button.
 *****************************************************************/
void COMPortTimeOut::Restart() {
	/* get the main window handle */
	nReturnValue_ = ERROR_TIMEOUT_RESTART;
	this->close();
} /* Restart */
