/********************************************************************************
 ** Form generated from reading UI file 'robotInterface_IlluminatorFiringRate.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.6
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef UI_ROBOTINTERFACE_ILLUMINATORFIRINGRATE_H
#define UI_ROBOTINTERFACE_ILLUMINATORFIRINGRATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWindow_IlluminatorFiringRate {
public:
	QGroupBox *groupBox_ActivationRate;
	QWidget *gridLayoutWidget;
	QGridLayout *gridLayout;
	QRadioButton *radioButton;
	QRadioButton *radioButton_2;
	QRadioButton *radioButton_3;
	QPushButton *pushButton_OK;
	QPushButton *pushButton_Cancel;
	QButtonGroup *buttonGroup;

	void setupUi(QWidget *SubWindow_IlluminatorFiringRate) {
		if (SubWindow_IlluminatorFiringRate->objectName().isEmpty())
			SubWindow_IlluminatorFiringRate->setObjectName(
					QString::fromUtf8("SubWindow_IlluminatorFiringRate"));
		SubWindow_IlluminatorFiringRate->resize(316, 144);
		groupBox_ActivationRate = new QGroupBox(
				SubWindow_IlluminatorFiringRate);
		groupBox_ActivationRate->setObjectName(
				QString::fromUtf8("groupBox_ActivationRate"));
		groupBox_ActivationRate->setGeometry(QRect(10, 20, 291, 81));
		gridLayoutWidget = new QWidget(groupBox_ActivationRate);
		gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
		gridLayoutWidget->setGeometry(QRect(0, 30, 291, 51));
		gridLayout = new QGridLayout(gridLayoutWidget);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		gridLayout->setContentsMargins(0, 0, 0, 0);
		radioButton = new QRadioButton(gridLayoutWidget);
		buttonGroup = new QButtonGroup(SubWindow_IlluminatorFiringRate);
		buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
		buttonGroup->setExclusive(true);
		buttonGroup->addButton(radioButton);
		radioButton->setObjectName(QString::fromUtf8("radioButton"));

		gridLayout->addWidget(radioButton, 0, 0, 1, 1);

		radioButton_2 = new QRadioButton(gridLayoutWidget);
		buttonGroup->addButton(radioButton_2);
		radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

		gridLayout->addWidget(radioButton_2, 0, 1, 1, 1);

		radioButton_3 = new QRadioButton(gridLayoutWidget);
		buttonGroup->addButton(radioButton_3);
		radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

		gridLayout->addWidget(radioButton_3, 0, 2, 1, 1);

		pushButton_OK = new QPushButton(SubWindow_IlluminatorFiringRate);
		pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
		pushButton_OK->setGeometry(QRect(50, 110, 98, 27));
		pushButton_Cancel = new QPushButton(SubWindow_IlluminatorFiringRate);
		pushButton_Cancel->setObjectName(
				QString::fromUtf8("pushButton_Cancel"));
		pushButton_Cancel->setGeometry(QRect(170, 110, 98, 27));

		retranslateUi(SubWindow_IlluminatorFiringRate);

		QMetaObject::connectSlotsByName(SubWindow_IlluminatorFiringRate);
	} // setupUi

	void retranslateUi(QWidget *SubWindow_IlluminatorFiringRate) {
		SubWindow_IlluminatorFiringRate->setWindowTitle(
				QApplication::translate("SubWindow_IlluminatorFiringRate",
						"Illuminator Firing Rate", 0,
						QApplication::UnicodeUTF8));
		groupBox_ActivationRate->setTitle(
				QApplication::translate("SubWindow_IlluminatorFiringRate",
						"Activation Rate", 0, QApplication::UnicodeUTF8));
		radioButton->setText(
				QApplication::translate("SubWindow_IlluminatorFiringRate",
						"20Hz", 0, QApplication::UnicodeUTF8));
		radioButton_2->setText(
				QApplication::translate("SubWindow_IlluminatorFiringRate",
						"30Hz", 0, QApplication::UnicodeUTF8));
		radioButton_3->setText(
				QApplication::translate("SubWindow_IlluminatorFiringRate",
						"60Hz", 0, QApplication::UnicodeUTF8));
		pushButton_OK->setText(
				QApplication::translate("SubWindow_IlluminatorFiringRate", "OK",
						0, QApplication::UnicodeUTF8));
		pushButton_Cancel->setText(
				QApplication::translate("SubWindow_IlluminatorFiringRate",
						"Cancel", 0, QApplication::UnicodeUTF8));
	} // retranslateUi

};

namespace Ui {
class SubWindow_IlluminatorFiringRate: public Ui_SubWindow_IlluminatorFiringRate {
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_ILLUMINATORFIRINGRATE_H
