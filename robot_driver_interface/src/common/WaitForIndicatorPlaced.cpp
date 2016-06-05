/*
 * WaitForIndicatorPlaced.cpp
 *
 *  Created on: May 15, 2016
 *      Author: root
 */

#include <WaitForIndicatorPlaced.h>

WaitForIndicatorPlaced::WaitForIndicatorPlaced(QDialog* parent) {
	setupUi(this);
	connect(pushButton_OK, SIGNAL(clicked()), this, SLOT(OK()));
	connect(pushButton_Cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
	nReturnValue_ = -1;
}

WaitForIndicatorPlaced::~WaitForIndicatorPlaced() {
}

void WaitForIndicatorPlaced::OK() {
	nReturnValue_ = INDICATOR_OK;
	sleep(5);
	this->close();
}

void WaitForIndicatorPlaced::Cancel() {
	nReturnValue_ = INDICATOR_CANCEL;
	this->close();
}

