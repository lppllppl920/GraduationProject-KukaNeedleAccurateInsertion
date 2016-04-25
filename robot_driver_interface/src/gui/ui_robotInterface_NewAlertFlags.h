/********************************************************************************
** Form generated from reading UI file 'robotInterface_NewAlertFlags.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTINTERFACE_NEWALERTFLAGS_H
#define UI_ROBOTINTERFACE_NEWALERTFLAGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWindow_NewAlertFlags
{
public:
    QGroupBox *groupBox_Flags;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_12;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_15;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *pushButton_OK;

    void setupUi(QWidget *SubWindow_NewAlertFlags)
    {
        if (SubWindow_NewAlertFlags->objectName().isEmpty())
            SubWindow_NewAlertFlags->setObjectName(QString::fromUtf8("SubWindow_NewAlertFlags"));
        SubWindow_NewAlertFlags->resize(482, 401);
        groupBox_Flags = new QGroupBox(SubWindow_NewAlertFlags);
        groupBox_Flags->setObjectName(QString::fromUtf8("groupBox_Flags"));
        groupBox_Flags->setGeometry(QRect(20, 20, 441, 321));
        gridLayoutWidget = new QWidget(groupBox_Flags);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 30, 402, 291));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 5, 0, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 6, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 6, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 5, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 7, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 4, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 7, 1, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 8, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 8, 1, 1, 1);

        pushButton_OK = new QPushButton(SubWindow_NewAlertFlags);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(350, 360, 98, 27));

        retranslateUi(SubWindow_NewAlertFlags);

        QMetaObject::connectSlotsByName(SubWindow_NewAlertFlags);
    } // setupUi

    void retranslateUi(QWidget *SubWindow_NewAlertFlags)
    {
        SubWindow_NewAlertFlags->setWindowTitle(QApplication::translate("SubWindow_NewAlertFlags", "New Alert Flags", 0, QApplication::UnicodeUTF8));
        groupBox_Flags->setTitle(QApplication::translate("SubWindow_NewAlertFlags", "Flags", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SubWindow_NewAlertFlags", "Bump Detected", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SubWindow_NewAlertFlags", "Illuminator", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("SubWindow_NewAlertFlags", "Left Sensor Temperature", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("SubWindow_NewAlertFlags", "Laser Battery", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SubWindow_NewAlertFlags", "Illuminator Voltage", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SubWindow_NewAlertFlags", "Main Voltage", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SubWindow_NewAlertFlags", "Internal Flash Memory", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SubWindow_NewAlertFlags", "System Battery Fault", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SubWindow_NewAlertFlags", "Sensor Parameter", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SubWindow_NewAlertFlags", "Cable Fault", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SubWindow_NewAlertFlags", "Fatal Parameter", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SubWindow_NewAlertFlags", "Sensor Voltage", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("SubWindow_NewAlertFlags", "Right Sensor Temperature", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SubWindow_NewAlertFlags", "Firmware Incompatible", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SubWindow_NewAlertFlags", "Non-Fatal Parameter Fault", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("SubWindow_NewAlertFlags", "Temperature Characterized High", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("SubWindow_NewAlertFlags", "Main Board Temperature", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("SubWindow_NewAlertFlags", "Temperature Characterized Low", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("SubWindow_NewAlertFlags", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SubWindow_NewAlertFlags: public Ui_SubWindow_NewAlertFlags {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_NEWALERTFLAGS_H
