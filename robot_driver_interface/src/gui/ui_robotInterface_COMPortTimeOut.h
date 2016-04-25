/********************************************************************************
** Form generated from reading UI file 'robotInterface_COMPortTimeOut.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTINTERFACE_COMPORTTIMEOUT_H
#define UI_ROBOTINTERFACE_COMPORTTIMEOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWindow_COMPortTimeOut
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Retry;
    QPushButton *pushButton_Restart;
    QPushButton *pushButton_CloseApplication;
    QLabel *label;

    void setupUi(QDialog *SubWindow_COMPortTimeOut)
    {
        if (SubWindow_COMPortTimeOut->objectName().isEmpty())
            SubWindow_COMPortTimeOut->setObjectName(QString::fromUtf8("SubWindow_COMPortTimeOut"));
        SubWindow_COMPortTimeOut->resize(505, 176);
        gridLayoutWidget = new QWidget(SubWindow_COMPortTimeOut);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 20, 441, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Retry = new QPushButton(gridLayoutWidget);
        pushButton_Retry->setObjectName(QString::fromUtf8("pushButton_Retry"));

        gridLayout->addWidget(pushButton_Retry, 1, 0, 1, 1);

        pushButton_Restart = new QPushButton(gridLayoutWidget);
        pushButton_Restart->setObjectName(QString::fromUtf8("pushButton_Restart"));

        gridLayout->addWidget(pushButton_Restart, 1, 1, 1, 1);

        pushButton_CloseApplication = new QPushButton(gridLayoutWidget);
        pushButton_CloseApplication->setObjectName(QString::fromUtf8("pushButton_CloseApplication"));

        gridLayout->addWidget(pushButton_CloseApplication, 1, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);


        retranslateUi(SubWindow_COMPortTimeOut);

        QMetaObject::connectSlotsByName(SubWindow_COMPortTimeOut);
    } // setupUi

    void retranslateUi(QDialog *SubWindow_COMPortTimeOut)
    {
        SubWindow_COMPortTimeOut->setWindowTitle(QApplication::translate("SubWindow_COMPortTimeOut", "COM Port TimeOut", 0, QApplication::UnicodeUTF8));
        pushButton_Retry->setText(QApplication::translate("SubWindow_COMPortTimeOut", "Retry", 0, QApplication::UnicodeUTF8));
        pushButton_Restart->setText(QApplication::translate("SubWindow_COMPortTimeOut", "Restart", 0, QApplication::UnicodeUTF8));
        pushButton_CloseApplication->setText(QApplication::translate("SubWindow_COMPortTimeOut", "Close Application", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SubWindow_COMPortTimeOut", "A timeout occured in COM Port\n"
"\n"
"To resend the command press the \"Retry\" button.  \n"
"To restart the application press the \"Restart\" button.  \n"
"To Close the Application press the \"Close Application\" button.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SubWindow_COMPortTimeOut: public Ui_SubWindow_COMPortTimeOut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_COMPORTTIMEOUT_H
