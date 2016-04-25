/********************************************************************************
 ** Form generated from reading UI file 'robotInterface_COMPortSettings.ui'
 **
 ** Created by: Qt User Interface Compiler version 4.8.6
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef UI_ROBOTINTERFACE_COMPORTSETTINGS_H
#define UI_ROBOTINTERFACE_COMPORTSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWindow_COMPortSettings {
public:
	QWidget *gridLayoutWidget;
	QGridLayout *gridLayout;
	QCheckBox *checkBox_WirelessCommunicationPort;
	QCheckBox *checkBox_HardwareHandshaking;
	QLabel *label_Data;
	QLabel *label_Stop;
	QLabel *label_COM;
	QLabel *label_Baud;
	QComboBox *comboBox_Parity;
	QComboBox *comboBox_Stop;
	QLabel *label_Parity;
	QComboBox *comboBox_COM;
	QComboBox *comboBox_Baud;
	QComboBox *comboBox_Data;
	QCheckBox *checkBox_ResetHardware;
	QPushButton *pushButton_OK;
	QPushButton *pushButton_Cancel;

	void setupUi(QWidget *SubWindow_COMPortSettings) {
		if (SubWindow_COMPortSettings->objectName().isEmpty())
			SubWindow_COMPortSettings->setObjectName(
					QString::fromUtf8("SubWindow_COMPortSettings"));
		SubWindow_COMPortSettings->resize(303, 414);
		gridLayoutWidget = new QWidget(SubWindow_COMPortSettings);
		gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
		gridLayoutWidget->setGeometry(QRect(20, 20, 261, 321));
		gridLayout = new QGridLayout(gridLayoutWidget);
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		gridLayout->setContentsMargins(0, 0, 0, 0);
		checkBox_WirelessCommunicationPort = new QCheckBox(gridLayoutWidget);
		checkBox_WirelessCommunicationPort->setObjectName(
				QString::fromUtf8("checkBox_WirelessCommunicationPort"));

		gridLayout->addWidget(checkBox_WirelessCommunicationPort, 6, 0, 1, 2);

		checkBox_HardwareHandshaking = new QCheckBox(gridLayoutWidget);
		checkBox_HardwareHandshaking->setObjectName(
				QString::fromUtf8("checkBox_HardwareHandshaking"));

		gridLayout->addWidget(checkBox_HardwareHandshaking, 5, 0, 1, 2);

		label_Data = new QLabel(gridLayoutWidget);
		label_Data->setObjectName(QString::fromUtf8("label_Data"));

		gridLayout->addWidget(label_Data, 2, 0, 1, 1);

		label_Stop = new QLabel(gridLayoutWidget);
		label_Stop->setObjectName(QString::fromUtf8("label_Stop"));

		gridLayout->addWidget(label_Stop, 4, 0, 1, 1);

		label_COM = new QLabel(gridLayoutWidget);
		label_COM->setObjectName(QString::fromUtf8("label_COM"));

		gridLayout->addWidget(label_COM, 0, 0, 1, 1);

		label_Baud = new QLabel(gridLayoutWidget);
		label_Baud->setObjectName(QString::fromUtf8("label_Baud"));

		gridLayout->addWidget(label_Baud, 1, 0, 1, 1);

		comboBox_Parity = new QComboBox(gridLayoutWidget);
		comboBox_Parity->setObjectName(QString::fromUtf8("comboBox_Parity"));

		gridLayout->addWidget(comboBox_Parity, 3, 1, 1, 1);

		comboBox_Stop = new QComboBox(gridLayoutWidget);
		comboBox_Stop->setObjectName(QString::fromUtf8("comboBox_Stop"));

		gridLayout->addWidget(comboBox_Stop, 4, 1, 1, 1);

		label_Parity = new QLabel(gridLayoutWidget);
		label_Parity->setObjectName(QString::fromUtf8("label_Parity"));

		gridLayout->addWidget(label_Parity, 3, 0, 1, 1);

		comboBox_COM = new QComboBox(gridLayoutWidget);
		comboBox_COM->setObjectName(QString::fromUtf8("comboBox_COM"));

		gridLayout->addWidget(comboBox_COM, 0, 1, 1, 1);

		comboBox_Baud = new QComboBox(gridLayoutWidget);
		comboBox_Baud->setObjectName(QString::fromUtf8("comboBox_Baud"));

		gridLayout->addWidget(comboBox_Baud, 1, 1, 1, 1);

		comboBox_Data = new QComboBox(gridLayoutWidget);
		comboBox_Data->setObjectName(QString::fromUtf8("comboBox_Data"));

		gridLayout->addWidget(comboBox_Data, 2, 1, 1, 1);

		checkBox_ResetHardware = new QCheckBox(gridLayoutWidget);
		checkBox_ResetHardware->setObjectName(
				QString::fromUtf8("checkBox_ResetHardware"));

		gridLayout->addWidget(checkBox_ResetHardware, 7, 0, 1, 2);

		pushButton_OK = new QPushButton(SubWindow_COMPortSettings);
		pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
		pushButton_OK->setGeometry(QRect(10, 360, 111, 27));
		pushButton_Cancel = new QPushButton(SubWindow_COMPortSettings);
		pushButton_Cancel->setObjectName(
				QString::fromUtf8("pushButton_Cancel"));
		pushButton_Cancel->setGeometry(QRect(170, 360, 111, 27));

		retranslateUi(SubWindow_COMPortSettings);

		QMetaObject::connectSlotsByName(SubWindow_COMPortSettings);
	} // setupUi

	void retranslateUi(QWidget *SubWindow_COMPortSettings) {
		SubWindow_COMPortSettings->setWindowTitle(
				QApplication::translate("SubWindow_COMPortSettings",
						"COM Port Settings", 0, QApplication::UnicodeUTF8));
		checkBox_WirelessCommunicationPort->setText(
				QApplication::translate("SubWindow_COMPortSettings",
						"Wireless Communication Port", 0,
						QApplication::UnicodeUTF8));
		checkBox_HardwareHandshaking->setText(
				QApplication::translate("SubWindow_COMPortSettings",
						"Hardware handshaking", 0, QApplication::UnicodeUTF8));
		label_Data->setText(
				QApplication::translate("SubWindow_COMPortSettings", "Data", 0,
						QApplication::UnicodeUTF8));
		label_Stop->setText(
				QApplication::translate("SubWindow_COMPortSettings", "Stop", 0,
						QApplication::UnicodeUTF8));
		label_COM->setText(
				QApplication::translate("SubWindow_COMPortSettings", "COM", 0,
						QApplication::UnicodeUTF8));
		label_Baud->setText(
				QApplication::translate("SubWindow_COMPortSettings", "Baud", 0,
						QApplication::UnicodeUTF8));
		comboBox_Parity->clear();
		comboBox_Parity->insertItems(0,
				QStringList()
						<< QApplication::translate("SubWindow_COMPortSettings",
								"None", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"Odd", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"Even", 0, QApplication::UnicodeUTF8));
		comboBox_Stop->clear();
		comboBox_Stop->insertItems(0,
				QStringList()
						<< QApplication::translate("SubWindow_COMPortSettings",
								"1 bit", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"2 bits", 0, QApplication::UnicodeUTF8));
		label_Parity->setText(
				QApplication::translate("SubWindow_COMPortSettings", "Parity",
						0, QApplication::UnicodeUTF8));
		comboBox_COM->clear();
		comboBox_COM->insertItems(0,
				QStringList()
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM1", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM2", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM3", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM4", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM5", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM6", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM7", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM8", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM9", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM10", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM11", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM12", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM13", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM14", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM15", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM16", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM17", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM18", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"COM19", 0, QApplication::UnicodeUTF8));
		comboBox_Baud->clear();
		comboBox_Baud->insertItems(0,
				QStringList()
						<< QApplication::translate("SubWindow_COMPortSettings",
								"9600", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"14400", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"19200", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"38400", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"57600", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"115200", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"921600", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"1228739", 0, QApplication::UnicodeUTF8));
		comboBox_Data->clear();
		comboBox_Data->insertItems(0,
				QStringList()
						<< QApplication::translate("SubWindow_COMPortSettings",
								"8 bits", 0, QApplication::UnicodeUTF8)
						<< QApplication::translate("SubWindow_COMPortSettings",
								"7 bits", 0, QApplication::UnicodeUTF8));
		checkBox_ResetHardware->setText(
				QApplication::translate("SubWindow_COMPortSettings",
						"Reset hardware upon initialization", 0,
						QApplication::UnicodeUTF8));
		pushButton_OK->setText(
				QApplication::translate("SubWindow_COMPortSettings", "OK", 0,
						QApplication::UnicodeUTF8));
		pushButton_Cancel->setText(
				QApplication::translate("SubWindow_COMPortSettings", "Cancel",
						0, QApplication::UnicodeUTF8));
	} // retranslateUi

};

namespace Ui {
class SubWindow_COMPortSettings: public Ui_SubWindow_COMPortSettings {
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_COMPORTSETTINGS_H
