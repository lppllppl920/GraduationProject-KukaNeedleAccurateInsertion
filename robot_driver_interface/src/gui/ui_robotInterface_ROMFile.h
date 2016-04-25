/********************************************************************************
** Form generated from reading UI file 'robotInterface_ROMFile.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTINTERFACE_ROMFILE_H
#define UI_ROBOTINTERFACE_ROMFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWindow_ROMFile
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_SROMImageFile;
    QLabel *label_Port;
    QPushButton *pushButton_Save;
    QLineEdit *lineEdit_SROMImageFile;
    QPushButton *pushButton_Browse;
    QLineEdit *lineEdit_Port;
    QListWidget *listWidget;
    QPushButton *pushButton_Close;

    void setupUi(QWidget *SubWindow_ROMFile)
    {
        if (SubWindow_ROMFile->objectName().isEmpty())
            SubWindow_ROMFile->setObjectName(QString::fromUtf8("SubWindow_ROMFile"));
        SubWindow_ROMFile->resize(403, 300);
        gridLayoutWidget = new QWidget(SubWindow_ROMFile);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_SROMImageFile = new QLabel(gridLayoutWidget);
        label_SROMImageFile->setObjectName(QString::fromUtf8("label_SROMImageFile"));

        gridLayout->addWidget(label_SROMImageFile, 2, 0, 1, 1);

        label_Port = new QLabel(gridLayoutWidget);
        label_Port->setObjectName(QString::fromUtf8("label_Port"));

        gridLayout->addWidget(label_Port, 1, 0, 1, 1);

        pushButton_Save = new QPushButton(gridLayoutWidget);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));
        pushButton_Save->setEnabled(false);
        pushButton_Save->setCheckable(false);

        gridLayout->addWidget(pushButton_Save, 3, 0, 1, 3, Qt::AlignHCenter);

        lineEdit_SROMImageFile = new QLineEdit(gridLayoutWidget);
        lineEdit_SROMImageFile->setObjectName(QString::fromUtf8("lineEdit_SROMImageFile"));
        lineEdit_SROMImageFile->setReadOnly(true);

        gridLayout->addWidget(lineEdit_SROMImageFile, 2, 1, 1, 1);

        pushButton_Browse = new QPushButton(gridLayoutWidget);
        pushButton_Browse->setObjectName(QString::fromUtf8("pushButton_Browse"));
        pushButton_Browse->setMaximumSize(QSize(51, 27));

        gridLayout->addWidget(pushButton_Browse, 2, 2, 1, 1);

        lineEdit_Port = new QLineEdit(gridLayoutWidget);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));
        lineEdit_Port->setMaximumSize(QSize(131, 27));
        lineEdit_Port->setReadOnly(true);

        gridLayout->addWidget(lineEdit_Port, 1, 1, 1, 1);

        listWidget = new QListWidget(gridLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 3);

        pushButton_Close = new QPushButton(SubWindow_ROMFile);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setGeometry(QRect(290, 260, 98, 27));

        retranslateUi(SubWindow_ROMFile);

        QMetaObject::connectSlotsByName(SubWindow_ROMFile);
    } // setupUi

    void retranslateUi(QWidget *SubWindow_ROMFile)
    {
        SubWindow_ROMFile->setWindowTitle(QApplication::translate("SubWindow_ROMFile", "ROM File", 0, QApplication::UnicodeUTF8));
        label_SROMImageFile->setText(QApplication::translate("SubWindow_ROMFile", "SROM Image File", 0, QApplication::UnicodeUTF8));
        label_Port->setText(QApplication::translate("SubWindow_ROMFile", "Port", 0, QApplication::UnicodeUTF8));
        pushButton_Save->setText(QApplication::translate("SubWindow_ROMFile", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_Browse->setText(QApplication::translate("SubWindow_ROMFile", "...", 0, QApplication::UnicodeUTF8));
        pushButton_Close->setText(QApplication::translate("SubWindow_ROMFile", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SubWindow_ROMFile: public Ui_SubWindow_ROMFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_ROMFILE_H
