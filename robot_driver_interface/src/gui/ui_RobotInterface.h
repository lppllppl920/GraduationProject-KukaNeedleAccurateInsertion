/********************************************************************************
** Form generated from reading UI file 'RobotInterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotInterface
{
public:
    QLabel *label_File;
    QTextEdit *textEdit;
    QLabel *label_Number1;
    QLabel *label_Number2;
    QSpinBox *spinBox_Number1;
    QSpinBox *spinBox_Number2;
    QCheckBox *checkBox_YesorNo;
    QComboBox *comboBox;
    QPushButton *pushButton_Do;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_About;

    void setupUi(QWidget *RobotInterface)
    {
        if (RobotInterface->objectName().isEmpty())
            RobotInterface->setObjectName(QString::fromUtf8("RobotInterface"));
        RobotInterface->resize(400, 300);
        label_File = new QLabel(RobotInterface);
        label_File->setObjectName(QString::fromUtf8("label_File"));
        label_File->setGeometry(QRect(10, 20, 31, 17));
        textEdit = new QTextEdit(RobotInterface);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 140, 361, 111));
        label_Number1 = new QLabel(RobotInterface);
        label_Number1->setObjectName(QString::fromUtf8("label_Number1"));
        label_Number1->setGeometry(QRect(10, 56, 71, 31));
        label_Number2 = new QLabel(RobotInterface);
        label_Number2->setObjectName(QString::fromUtf8("label_Number2"));
        label_Number2->setGeometry(QRect(10, 100, 71, 31));
        spinBox_Number1 = new QSpinBox(RobotInterface);
        spinBox_Number1->setObjectName(QString::fromUtf8("spinBox_Number1"));
        spinBox_Number1->setGeometry(QRect(100, 60, 60, 27));
        spinBox_Number2 = new QSpinBox(RobotInterface);
        spinBox_Number2->setObjectName(QString::fromUtf8("spinBox_Number2"));
        spinBox_Number2->setGeometry(QRect(100, 100, 60, 27));
        checkBox_YesorNo = new QCheckBox(RobotInterface);
        checkBox_YesorNo->setObjectName(QString::fromUtf8("checkBox_YesorNo"));
        checkBox_YesorNo->setGeometry(QRect(190, 60, 97, 22));
        comboBox = new QComboBox(RobotInterface);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(190, 100, 121, 27));
        pushButton_Do = new QPushButton(RobotInterface);
        pushButton_Do->setObjectName(QString::fromUtf8("pushButton_Do"));
        pushButton_Do->setGeometry(QRect(20, 260, 98, 27));
        pushButton_Clear = new QPushButton(RobotInterface);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(150, 260, 98, 27));
        pushButton_About = new QPushButton(RobotInterface);
        pushButton_About->setObjectName(QString::fromUtf8("pushButton_About"));
        pushButton_About->setGeometry(QRect(280, 260, 98, 27));

        retranslateUi(RobotInterface);

        QMetaObject::connectSlotsByName(RobotInterface);
    } // setupUi

    void retranslateUi(QWidget *RobotInterface)
    {
        RobotInterface->setWindowTitle(QApplication::translate("RobotInterface", "Robot Interface", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        RobotInterface->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        label_File->setText(QApplication::translate("RobotInterface", "File", 0, QApplication::UnicodeUTF8));
        label_Number1->setText(QApplication::translate("RobotInterface", "Number 1", 0, QApplication::UnicodeUTF8));
        label_Number2->setText(QApplication::translate("RobotInterface", "Number 2", 0, QApplication::UnicodeUTF8));
        checkBox_YesorNo->setText(QApplication::translate("RobotInterface", "Yes or No", 0, QApplication::UnicodeUTF8));
        pushButton_Do->setText(QApplication::translate("RobotInterface", "Do", 0, QApplication::UnicodeUTF8));
        pushButton_Clear->setText(QApplication::translate("RobotInterface", "Clear", 0, QApplication::UnicodeUTF8));
        pushButton_About->setText(QApplication::translate("RobotInterface", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RobotInterface: public Ui_RobotInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ROBOTINTERFACE_H
