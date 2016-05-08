/********************************************************************************
** Form generated from reading UI file 'robotInterface_MotionPlanDecision.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTINTERFACE_MOTIONPLANDECISION_H
#define UI_ROBOTINTERFACE_MOTIONPLANDECISION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SubWindow_PlanDecision
{
public:
    QLabel *label;
    QPushButton *pushButton_ExecutePlan;
    QPushButton *pushButton_Replan;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *SubWindow_PlanDecision)
    {
        if (SubWindow_PlanDecision->objectName().isEmpty())
            SubWindow_PlanDecision->setObjectName(QString::fromUtf8("SubWindow_PlanDecision"));
        SubWindow_PlanDecision->resize(407, 287);
        label = new QLabel(SubWindow_PlanDecision);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 60, 261, 71));
        pushButton_ExecutePlan = new QPushButton(SubWindow_PlanDecision);
        pushButton_ExecutePlan->setObjectName(QString::fromUtf8("pushButton_ExecutePlan"));
        pushButton_ExecutePlan->setGeometry(QRect(40, 170, 95, 24));
        pushButton_Replan = new QPushButton(SubWindow_PlanDecision);
        pushButton_Replan->setObjectName(QString::fromUtf8("pushButton_Replan"));
        pushButton_Replan->setGeometry(QRect(150, 170, 95, 24));
        pushButton_Cancel = new QPushButton(SubWindow_PlanDecision);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(260, 170, 95, 24));

        retranslateUi(SubWindow_PlanDecision);

        QMetaObject::connectSlotsByName(SubWindow_PlanDecision);
    } // setupUi

    void retranslateUi(QDialog *SubWindow_PlanDecision)
    {
        SubWindow_PlanDecision->setWindowTitle(QApplication::translate("SubWindow_PlanDecision", "Motion Plan Decision", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SubWindow_PlanDecision", "A motion plan has been made.\n"
"\n"
"Please choose one of the options below \n"
"\n"
"(The motion plan can be previewed in RViz)", 0, QApplication::UnicodeUTF8));
        pushButton_ExecutePlan->setText(QApplication::translate("SubWindow_PlanDecision", "Execute", 0, QApplication::UnicodeUTF8));
        pushButton_Replan->setText(QApplication::translate("SubWindow_PlanDecision", "Replan", 0, QApplication::UnicodeUTF8));
        pushButton_Cancel->setText(QApplication::translate("SubWindow_PlanDecision", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SubWindow_PlanDecision: public Ui_SubWindow_PlanDecision {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_MOTIONPLANDECISION_H
