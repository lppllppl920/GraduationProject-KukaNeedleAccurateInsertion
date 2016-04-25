/********************************************************************************
 ** Form generated from reading UI file 'robotInterface_ProgramOptions.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.6
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef UI_ROBOTINTERFACE_PROGRAMOPTIONS_H
#define UI_ROBOTINTERFACE_PROGRAMOPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWindow_ProgramOptions {
public:
	QGroupBox *groupBox_LoggingToaFile;
	QWidget *gridLayoutWidget;
	QGridLayout *gridLayout;
	QLineEdit *lineEdit_File;
	QPushButton *pushButton_browse;
	QCheckBox *checkBox_LogCOMPortToFile;
	QLabel *label_File;
	QCheckBox *checkBox_IncludeTimeStamp;
	QCheckBox *checkBox_ClearFileonSystemInitialization;
	QGroupBox *groupBox_BeepOptions;
	QWidget *gridLayoutWidget_2;
	QGridLayout *gridLayout_2;
	QCheckBox *checkBox_BeepSystemOnWARNING;
	QLabel *label_Noof;
	QLineEdit *lineEdit_BeepWARNINGNum;
	QLabel *label_Noof_2;
	QLineEdit *lineEdit_BeepERRORNum;
	QCheckBox *checkBox_BeepSystemOnERROR;
	QLabel *label_Num;
	QLabel *label_Num_2;
	QGroupBox *groupBox_Messaging;
	QCheckBox *checkBox_DisplayError;
	QPushButton *pushButton_OK;
	QPushButton *pushButton_Cancel;

	void setupUi(QWidget *SubWindow_ProgramOptions) {
		if (SubWindow_ProgramOptions->objectName().isEmpty())
			SubWindow_ProgramOptions->setObjectName(
					QString::fromUtf8("SubWindow_ProgramOptions"));
		SubWindow_ProgramOptions->resize(532, 427);
		groupBox_LoggingToaFile = new QGroupBox(SubWindow_ProgramOptions);
		groupBox_LoggingToaFile->setObjectName(
				QString::fromUtf8("groupBox_LoggingToaFile"));
		groupBox_LoggingToaFile->setGeometry(QRect(20, 10, 491, 151));
		gridLayoutWidget = new QWidget(groupBox_LoggingToaFile);
		gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
		gridLayoutWidget->setGeometry(QRect(9, 30, 481, 121));
		gridLayout = new QGridLayout(gridLayoutWidget);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		gridLayout->setContentsMargins(0, 0, 0, 0);
		lineEdit_File = new QLineEdit(gridLayoutWidget);
		lineEdit_File->setObjectName(QString::fromUtf8("lineEdit_File"));

		gridLayout->addWidget(lineEdit_File, 1, 1, 1, 1);

		pushButton_browse = new QPushButton(gridLayoutWidget);
		pushButton_browse->setObjectName(
				QString::fromUtf8("pushButton_browse"));

		gridLayout->addWidget(pushButton_browse, 1, 2, 1, 1);

		checkBox_LogCOMPortToFile = new QCheckBox(gridLayoutWidget);
		checkBox_LogCOMPortToFile->setObjectName(
				QString::fromUtf8("checkBox_LogCOMPortToFile"));

		gridLayout->addWidget(checkBox_LogCOMPortToFile, 0, 0, 1, 3,
				Qt::AlignHCenter);

		label_File = new QLabel(gridLayoutWidget);
		label_File->setObjectName(QString::fromUtf8("label_File"));

		gridLayout->addWidget(label_File, 1, 0, 1, 1);

		checkBox_IncludeTimeStamp = new QCheckBox(gridLayoutWidget);
		checkBox_IncludeTimeStamp->setObjectName(
				QString::fromUtf8("checkBox_IncludeTimeStamp"));

		gridLayout->addWidget(checkBox_IncludeTimeStamp, 2, 0, 1, 3,
				Qt::AlignHCenter);

		checkBox_ClearFileonSystemInitialization = new QCheckBox(
				gridLayoutWidget);
		checkBox_ClearFileonSystemInitialization->setObjectName(
				QString::fromUtf8("checkBox_ClearFileonSystemInitialization"));

		gridLayout->addWidget(checkBox_ClearFileonSystemInitialization, 3, 0, 1,
				3, Qt::AlignHCenter);

		groupBox_BeepOptions = new QGroupBox(SubWindow_ProgramOptions);
		groupBox_BeepOptions->setObjectName(
				QString::fromUtf8("groupBox_BeepOptions"));
		groupBox_BeepOptions->setGeometry(QRect(19, 180, 491, 91));
		gridLayoutWidget_2 = new QWidget(groupBox_BeepOptions);
		gridLayoutWidget_2->setObjectName(
				QString::fromUtf8("gridLayoutWidget_2"));
		gridLayoutWidget_2->setGeometry(QRect(10, 20, 481, 62));
		gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
		gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
		gridLayout_2->setContentsMargins(0, 0, 0, 0);
		checkBox_BeepSystemOnWARNING = new QCheckBox(gridLayoutWidget_2);
		checkBox_BeepSystemOnWARNING->setObjectName(
				QString::fromUtf8("checkBox_BeepSystemOnWARNING"));

		gridLayout_2->addWidget(checkBox_BeepSystemOnWARNING, 1, 0, 1, 1);

		label_Noof = new QLabel(gridLayoutWidget_2);
		label_Noof->setObjectName(QString::fromUtf8("label_Noof"));

		gridLayout_2->addWidget(label_Noof, 0, 1, 1, 1);

		lineEdit_BeepWARNINGNum = new QLineEdit(gridLayoutWidget_2);
		lineEdit_BeepWARNINGNum->setObjectName(
				QString::fromUtf8("lineEdit_BeepWARNINGNum"));

		gridLayout_2->addWidget(lineEdit_BeepWARNINGNum, 1, 2, 1, 1);

		label_Noof_2 = new QLabel(gridLayoutWidget_2);
		label_Noof_2->setObjectName(QString::fromUtf8("label_Noof_2"));

		gridLayout_2->addWidget(label_Noof_2, 1, 1, 1, 1);

		lineEdit_BeepERRORNum = new QLineEdit(gridLayoutWidget_2);
		lineEdit_BeepERRORNum->setObjectName(
				QString::fromUtf8("lineEdit_BeepERRORNum"));

		gridLayout_2->addWidget(lineEdit_BeepERRORNum, 0, 2, 1, 1);

		checkBox_BeepSystemOnERROR = new QCheckBox(gridLayoutWidget_2);
		checkBox_BeepSystemOnERROR->setObjectName(
				QString::fromUtf8("checkBox_BeepSystemOnERROR"));

		gridLayout_2->addWidget(checkBox_BeepSystemOnERROR, 0, 0, 1, 1);

		label_Num = new QLabel(gridLayoutWidget_2);
		label_Num->setObjectName(QString::fromUtf8("label_Num"));

		gridLayout_2->addWidget(label_Num, 0, 3, 1, 1);

		label_Num_2 = new QLabel(gridLayoutWidget_2);
		label_Num_2->setObjectName(QString::fromUtf8("label_Num_2"));

		gridLayout_2->addWidget(label_Num_2, 1, 3, 1, 1);

		groupBox_Messaging = new QGroupBox(SubWindow_ProgramOptions);
		groupBox_Messaging->setObjectName(
				QString::fromUtf8("groupBox_Messaging"));
		groupBox_Messaging->setGeometry(QRect(20, 280, 491, 80));
		checkBox_DisplayError = new QCheckBox(groupBox_Messaging);
		checkBox_DisplayError->setObjectName(
				QString::fromUtf8("checkBox_DisplayError"));
		checkBox_DisplayError->setGeometry(QRect(40, 30, 421, 41));
		pushButton_OK = new QPushButton(SubWindow_ProgramOptions);
		pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
		pushButton_OK->setGeometry(QRect(130, 390, 98, 27));
		pushButton_Cancel = new QPushButton(SubWindow_ProgramOptions);
		pushButton_Cancel->setObjectName(
				QString::fromUtf8("pushButton_Cancel"));
		pushButton_Cancel->setGeometry(QRect(280, 390, 98, 27));
		groupBox_Messaging->raise();
		groupBox_LoggingToaFile->raise();
		groupBox_BeepOptions->raise();
		pushButton_OK->raise();
		pushButton_Cancel->raise();

		retranslateUi(SubWindow_ProgramOptions);

		QMetaObject::connectSlotsByName(SubWindow_ProgramOptions);
	} // setupUi

	void retranslateUi(QWidget *SubWindow_ProgramOptions) {
		SubWindow_ProgramOptions->setWindowTitle(
				QApplication::translate("SubWindow_ProgramOptions",
						"Program Options", 0, QApplication::UnicodeUTF8));
		groupBox_LoggingToaFile->setTitle(
				QApplication::translate("SubWindow_ProgramOptions",
						"Logging To a File", 0, QApplication::UnicodeUTF8));
		pushButton_browse->setText(
				QApplication::translate("SubWindow_ProgramOptions", "...", 0,
						QApplication::UnicodeUTF8));
		checkBox_LogCOMPortToFile->setText(
				QApplication::translate("SubWindow_ProgramOptions",
						"Log COM port communication to a file", 0,
						QApplication::UnicodeUTF8));
		label_File->setText(
				QApplication::translate("SubWindow_ProgramOptions",
						"File                     ", 0,
						QApplication::UnicodeUTF8));
		checkBox_IncludeTimeStamp->setText(
				QApplication::translate("SubWindow_ProgramOptions",
						"Include time stamp", 0, QApplication::UnicodeUTF8));
		checkBox_ClearFileonSystemInitialization->setText(
				QApplication::translate("SubWindow_ProgramOptions",
						"Clear file on system initialization", 0,
						QApplication::UnicodeUTF8));
		groupBox_BeepOptions->setTitle(
				QApplication::translate("SubWindow_ProgramOptions",
						"Beep Options", 0, QApplication::UnicodeUTF8));
		checkBox_BeepSystemOnWARNING->setText(
				QApplication::translate("SubWindow_ProgramOptions",
						"Beep system on WARNING return", 0,
						QApplication::UnicodeUTF8));
		label_Noof->setText(
				QApplication::translate("SubWindow_ProgramOptions", "No. of", 0,
						QApplication::UnicodeUTF8));
		label_Noof_2->setText(
				QApplication::translate("SubWindow_ProgramOptions", "No. of", 0,
						QApplication::UnicodeUTF8));
		checkBox_BeepSystemOnERROR->setText(
				QApplication::translate("SubWindow_ProgramOptions",
						"Beep system on ERROR return", 0,
						QApplication::UnicodeUTF8));
		label_Num->setText(
				QApplication::translate("SubWindow_ProgramOptions", "(1-9)", 0,
						QApplication::UnicodeUTF8));
		label_Num_2->setText(
				QApplication::translate("SubWindow_ProgramOptions", "(1-9)", 0,
						QApplication::UnicodeUTF8));
		groupBox_Messaging->setTitle(
				QApplication::translate("SubWindow_ProgramOptions", "Messaging",
						0, QApplication::UnicodeUTF8));
		checkBox_DisplayError->setText(
				QApplication::translate("SubWindow_ProgramOptions",
						"Display error messages while in tracking mode\n"
								"System needs to restart tracking for setting to take effect",
						0, QApplication::UnicodeUTF8));
		pushButton_OK->setText(
				QApplication::translate("SubWindow_ProgramOptions", "OK", 0,
						QApplication::UnicodeUTF8));
		pushButton_Cancel->setText(
				QApplication::translate("SubWindow_ProgramOptions", "Cancel", 0,
						QApplication::UnicodeUTF8));
	} // retranslateUi

};

namespace Ui {
class SubWindow_ProgramOptions: public Ui_SubWindow_ProgramOptions {
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_PROGRAMOPTIONS_H
