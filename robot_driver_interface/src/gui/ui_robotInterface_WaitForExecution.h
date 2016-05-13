/********************************************************************************
** Form generated from reading UI file 'robotInterface_WaitForExecution.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTINTERFACE_WAITFOREXECUTION_H
#define UI_ROBOTINTERFACE_WAITFOREXECUTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SubWindow_WaitForExecution
{
public:
    QLabel *label;

    void setupUi(QDialog *SubWindow_WaitForExecution)
    {
        if (SubWindow_WaitForExecution->objectName().isEmpty())
            SubWindow_WaitForExecution->setObjectName(QString::fromUtf8("SubWindow_WaitForExecution"));
        SubWindow_WaitForExecution->resize(400, 140);
        label = new QLabel(SubWindow_WaitForExecution);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 301, 81));

        retranslateUi(SubWindow_WaitForExecution);

        QMetaObject::connectSlotsByName(SubWindow_WaitForExecution);
    } // setupUi

    void retranslateUi(QDialog *SubWindow_WaitForExecution)
    {
        SubWindow_WaitForExecution->setWindowTitle(QApplication::translate("SubWindow_WaitForExecution", "Wait For Execution", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SubWindow_WaitForExecution", "Please wait for motion execution complete...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SubWindow_WaitForExecution: public Ui_SubWindow_WaitForExecution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_WAITFOREXECUTION_H
