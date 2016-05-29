/********************************************************************************
** Form generated from reading UI file 'robotInterface_WaitForIndicatorPlaced.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTINTERFACE_WAITFORINDICATORPLACED_H
#define UI_ROBOTINTERFACE_WAITFORINDICATORPLACED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SubWindow_WaitForIndicatorPlaced
{
public:
    QLabel *label;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *SubWindow_WaitForIndicatorPlaced)
    {
        if (SubWindow_WaitForIndicatorPlaced->objectName().isEmpty())
            SubWindow_WaitForIndicatorPlaced->setObjectName(QString::fromUtf8("SubWindow_WaitForIndicatorPlaced"));
        SubWindow_WaitForIndicatorPlaced->resize(400, 217);
        label = new QLabel(SubWindow_WaitForIndicatorPlaced);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 341, 101));
        pushButton_OK = new QPushButton(SubWindow_WaitForIndicatorPlaced);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(70, 150, 98, 27));
        pushButton_Cancel = new QPushButton(SubWindow_WaitForIndicatorPlaced);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(220, 150, 98, 27));

        retranslateUi(SubWindow_WaitForIndicatorPlaced);

        QMetaObject::connectSlotsByName(SubWindow_WaitForIndicatorPlaced);
    } // setupUi

    void retranslateUi(QDialog *SubWindow_WaitForIndicatorPlaced)
    {
        SubWindow_WaitForIndicatorPlaced->setWindowTitle(QApplication::translate("SubWindow_WaitForIndicatorPlaced", "Wait For Indicator Placed", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SubWindow_WaitForIndicatorPlaced", "Please place Point Indicator to correct position,\n"
"then click OK. If you want to cancel this calibration\n"
"procedure, click Cancel.", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("SubWindow_WaitForIndicatorPlaced", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_Cancel->setText(QApplication::translate("SubWindow_WaitForIndicatorPlaced", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SubWindow_WaitForIndicatorPlaced: public Ui_SubWindow_WaitForIndicatorPlaced {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_WAITFORINDICATORPLACED_H
