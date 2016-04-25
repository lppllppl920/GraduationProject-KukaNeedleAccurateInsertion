/*
 * IlluminatorFiringRate.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: lxt12
 */

#include <ndi/IlluminatorFiringRate.h>

IlluminatorFiringRate::IlluminatorFiringRate() {
	setupUi(this);
	nFiringRate_ = 0;
	nTypeOfSystem_ = POLARIS_SYSTEM;
	//TODO: this address need to be specified
	dtIniFile_.Load("/home/lxt12/NDIConfiguration.ini");
	strConfigurationFile_ = "/home/lxt12/NDIConfiguration.ini";

	connect(pushButton_OK, SIGNAL(clicked()), this, SLOT(OK()));

	connect(pushButton_Cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
}

IlluminatorFiringRate::~IlluminatorFiringRate() {
	// TODO Auto-generated destructor stub
}

void IlluminatorFiringRate::Init() {
	nFiringRate_ = 0;
	nTypeOfSystem_ = POLARIS_SYSTEM;
	ReadINIParam("POLARIS Options", "Activation Rate", nFiringRate_);
	/*
	 * Polaris Accedo and Vicra systems only support default activation rate of 20Hz.
	 */
	if ((nTypeOfSystem_ == ACCEDO_SYSTEM) || (nTypeOfSystem_ == VICRA_SYSTEM)) {
		radioButton_2->setEnabled(false);
		radioButton_3->setEnabled(false);
	}/* if */
	switch (nFiringRate_) {
	case 0: {
		radioButton->setChecked(true);
		break;
	}
	case 1: {
		radioButton_2->setChecked(true);
		break;
	}
	case 2: {
		radioButton_3->setChecked(true);
		break;
	}
	}
	return;  // return TRUE unless you set the focus to a control
			 // EXCEPTION: OCX Property Pages should return FALSE
}

void IlluminatorFiringRate::OK() {

	if (radioButton->isChecked()) {
		nFiringRate_ = 0;
	}
	if (radioButton_2->isChecked()) {
		nFiringRate_ = 1;
	}
	if (radioButton_3->isChecked()) {
		nFiringRate_ = 2;
	}
	dtIniFile_.SetKeyValue("POLARIS Options", "Activation Rate",
			boost::lexical_cast<std::string>(nFiringRate_));
	if (!dtIniFile_.Save(strConfigurationFile_)) {
		ROS_ERROR("Cannot save configuration file");
		return;
	}
	emit OK_signal();
	this->close();

}
void IlluminatorFiringRate::Cancel() {

	this->close();
}
