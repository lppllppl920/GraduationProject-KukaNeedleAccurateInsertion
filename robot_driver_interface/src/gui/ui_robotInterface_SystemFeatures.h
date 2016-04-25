/********************************************************************************
** Form generated from reading UI file 'robotInterface_SystemFeatures.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTINTERFACE_SYSTEMFEATURES_H
#define UI_ROBOTINTERFACE_SYSTEMFEATURES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWindow_SystemFeatures
{
public:
    QGroupBox *groupBox_VersionInformation;
    QListWidget *listWidget;
    QGroupBox *groupBox_SystemInformation;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_ActivePortsNum;
    QLabel *label_WirelessNum;
    QLineEdit *lineEdit_ActiveWirelessPorts;
    QLabel *label_ActiveWirelessPorts;
    QLabel *label_ActivePortsNum;
    QLineEdit *lineEdit_WirelessNum;
    QLabel *label_SupportingPortsNum;
    QLineEdit *lineEdit_SupportingPortsNum;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;

    void setupUi(QWidget *SubWindow_SystemFeatures)
    {
        if (SubWindow_SystemFeatures->objectName().isEmpty())
            SubWindow_SystemFeatures->setObjectName(QString::fromUtf8("SubWindow_SystemFeatures"));
        SubWindow_SystemFeatures->resize(323, 401);
        groupBox_VersionInformation = new QGroupBox(SubWindow_SystemFeatures);
        groupBox_VersionInformation->setObjectName(QString::fromUtf8("groupBox_VersionInformation"));
        groupBox_VersionInformation->setGeometry(QRect(10, 10, 301, 141));
        listWidget = new QListWidget(groupBox_VersionInformation);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(5, 30, 291, 111));
        groupBox_SystemInformation = new QGroupBox(SubWindow_SystemFeatures);
        groupBox_SystemInformation->setObjectName(QString::fromUtf8("groupBox_SystemInformation"));
        groupBox_SystemInformation->setGeometry(QRect(10, 160, 301, 171));
        gridLayoutWidget = new QWidget(groupBox_SystemInformation);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 30, 291, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_ActivePortsNum = new QLineEdit(gridLayoutWidget);
        lineEdit_ActivePortsNum->setObjectName(QString::fromUtf8("lineEdit_ActivePortsNum"));
        lineEdit_ActivePortsNum->setReadOnly(true);

        gridLayout->addWidget(lineEdit_ActivePortsNum, 0, 1, 1, 1);

        label_WirelessNum = new QLabel(gridLayoutWidget);
        label_WirelessNum->setObjectName(QString::fromUtf8("label_WirelessNum"));

        gridLayout->addWidget(label_WirelessNum, 1, 0, 1, 1);

        lineEdit_ActiveWirelessPorts = new QLineEdit(gridLayoutWidget);
        lineEdit_ActiveWirelessPorts->setObjectName(QString::fromUtf8("lineEdit_ActiveWirelessPorts"));
        lineEdit_ActiveWirelessPorts->setReadOnly(true);

        gridLayout->addWidget(lineEdit_ActiveWirelessPorts, 2, 1, 1, 1);

        label_ActiveWirelessPorts = new QLabel(gridLayoutWidget);
        label_ActiveWirelessPorts->setObjectName(QString::fromUtf8("label_ActiveWirelessPorts"));

        gridLayout->addWidget(label_ActiveWirelessPorts, 2, 0, 1, 1);

        label_ActivePortsNum = new QLabel(gridLayoutWidget);
        label_ActivePortsNum->setObjectName(QString::fromUtf8("label_ActivePortsNum"));

        gridLayout->addWidget(label_ActivePortsNum, 0, 0, 1, 1);

        lineEdit_WirelessNum = new QLineEdit(gridLayoutWidget);
        lineEdit_WirelessNum->setObjectName(QString::fromUtf8("lineEdit_WirelessNum"));
        lineEdit_WirelessNum->setReadOnly(true);

        gridLayout->addWidget(lineEdit_WirelessNum, 1, 1, 1, 1);

        label_SupportingPortsNum = new QLabel(gridLayoutWidget);
        label_SupportingPortsNum->setObjectName(QString::fromUtf8("label_SupportingPortsNum"));

        gridLayout->addWidget(label_SupportingPortsNum, 3, 0, 1, 1);

        lineEdit_SupportingPortsNum = new QLineEdit(gridLayoutWidget);
        lineEdit_SupportingPortsNum->setObjectName(QString::fromUtf8("lineEdit_SupportingPortsNum"));
        lineEdit_SupportingPortsNum->setReadOnly(true);

        gridLayout->addWidget(lineEdit_SupportingPortsNum, 3, 1, 1, 1);

        pushButton_OK = new QPushButton(SubWindow_SystemFeatures);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(20, 350, 98, 27));
        pushButton_Cancel = new QPushButton(SubWindow_SystemFeatures);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(170, 350, 98, 27));

        retranslateUi(SubWindow_SystemFeatures);

        QMetaObject::connectSlotsByName(SubWindow_SystemFeatures);
    } // setupUi

    void retranslateUi(QWidget *SubWindow_SystemFeatures)
    {
        SubWindow_SystemFeatures->setWindowTitle(QApplication::translate("SubWindow_SystemFeatures", "System Features", 0, QApplication::UnicodeUTF8));
        groupBox_VersionInformation->setTitle(QApplication::translate("SubWindow_SystemFeatures", "Version Information", 0, QApplication::UnicodeUTF8));
        groupBox_SystemInformation->setTitle(QApplication::translate("SubWindow_SystemFeatures", "System Information", 0, QApplication::UnicodeUTF8));
        label_WirelessNum->setText(QApplication::translate("SubWindow_SystemFeatures", "Number of wireless:", 0, QApplication::UnicodeUTF8));
        label_ActiveWirelessPorts->setText(QApplication::translate("SubWindow_SystemFeatures", "Number of active wireless ports", 0, QApplication::UnicodeUTF8));
        label_ActivePortsNum->setText(QApplication::translate("SubWindow_SystemFeatures", "Number of active ports:", 0, QApplication::UnicodeUTF8));
        label_SupportingPortsNum->setText(QApplication::translate("SubWindow_SystemFeatures", "Number of ports supporting \n"
"tool-in-port detection:", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("SubWindow_SystemFeatures", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_Cancel->setText(QApplication::translate("SubWindow_SystemFeatures", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SubWindow_SystemFeatures: public Ui_SubWindow_SystemFeatures {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_SYSTEMFEATURES_H
