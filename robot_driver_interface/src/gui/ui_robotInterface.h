/********************************************************************************
** Form generated from reading UI file 'robotInterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTINTERFACE_H
#define UI_ROBOTINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_robotInterface
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_Interaction;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Do;
    QLabel *label_Operation;
    QLineEdit *lineEdit_TransX;
    QLabel *label_Joint5_S;
    QLabel *label_Joint3_S;
    QLineEdit *lineEdit_TransY;
    QLineEdit *lineEdit_Joint4;
    QLabel *label_Joint1;
    QLineEdit *lineEdit_RotateX;
    QLabel *label_Joint5;
    QLineEdit *lineEdit_Joint5;
    QLabel *label_PoseTarget;
    QLabel *label_Joint6;
    QLabel *label_RotateX;
    QLabel *label_Joint2;
    QLabel *label_Joint1_S;
    QLabel *label_RotateZ;
    QLineEdit *lineEdit_Joint2;
    QLineEdit *lineEdit_Joint2_S;
    QLabel *label_TransZ;
    QLineEdit *lineEdit_Joint1;
    QLabel *label_JointTarget;
    QLineEdit *lineEdit_RotateW;
    QLabel *label_RotateY;
    QLabel *label_Joint4;
    QLabel *label_RotateW;
    QLabel *label_Joint3;
    QLineEdit *lineEdit_Joint6;
    QLineEdit *lineEdit_TransZ;
    QLineEdit *lineEdit_RotateY;
    QLabel *label_TransY;
    QLabel *label_Joint4_S;
    QLabel *label_Joint2_S;
    QLabel *label_JointState;
    QLabel *label_TransX;
    QLineEdit *lineEdit_Joint3;
    QLineEdit *lineEdit_RotateZ;
    QLabel *label_Joint6_S;
    QLineEdit *lineEdit_Joint1_S;
    QLineEdit *lineEdit_Joint3_S;
    QLineEdit *lineEdit_Joint4_S;
    QLineEdit *lineEdit_Joint5_S;
    QLineEdit *lineEdit_Joint6_S;
    QPushButton *pushButton_CopyJointState;
    QPushButton *pushButton_VisualizeJointPlan;
    QPushButton *pushButton_VisualizePosePlan;
    QPushButton *pushButton_ExecutePlan;
    QPushButton *pushButton_AddWaypoint;
    QPushButton *pushButton_ExecuteWaypointsPlan;
    QLabel *label_CollisionObject;
    QComboBox *comboBox_Shape;
    QComboBox *comboBox_Operation;
    QLabel *label_Shape;
    QLabel *label_CurrenCollisionObject;
    QLabel *label_CollisionID;
    QLineEdit *lineEdit_Z_2;
    QLabel *label_Dimension_Z;
    QLineEdit *lineEdit_Z;
    QLabel *label_Dimension_Y_Height;
    QLineEdit *lineEdit_Y_Height;
    QLineEdit *lineEdit_X_Radius;
    QLabel *label_Dimension_X_Radius;
    QListWidget *listWidget_CurrentCollisionObject;
    QWidget *tab_SingleCommand;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *output_s;
    QLabel *label_9;
    QTextEdit *output_a2;
    QComboBox *comboBox_style;
    QTextEdit *input_config;
    QPushButton *send_config_button;
    QLabel *label_2;
    QLabel *label_5;
    QTextEdit *input_x;
    QTextEdit *output_y;
    QTextEdit *input_s;
    QPushButton *send_frame_button;
    QComboBox *comboBox_config;
    QTextEdit *input_t;
    QTextEdit *input_a3;
    QPushButton *send_pos_button;
    QTextEdit *output_buf_front;
    QTextEdit *input_b;
    QLabel *label_6;
    QPushButton *send_axis_button;
    QTextEdit *output_a3;
    QTextEdit *output_a1;
    QTextEdit *input_a;
    QTextEdit *input_a2;
    QTextEdit *output_a;
    QTextEdit *input_a1;
    QComboBox *comboBox_approx;
    QTextEdit *input_z;
    QLabel *label_3;
    QLabel *label_13;
    QPushButton *terminate_imm_button;
    QTextEdit *output_b;
    QLabel *label_4;
    QTextEdit *output_a4;
    QTextEdit *input_a4;
    QTextEdit *input_y;
    QTextEdit *output_a5;
    QPushButton *pause_buf_buton;
    QLabel *label_8;
    QPushButton *pause_button;
    QTextEdit *output_c;
    QTextEdit *input_a6;
    QTextEdit *input_c;
    QPushButton *terminate_buf_button;
    QTextEdit *output_result;
    QLabel *label_11;
    QTextEdit *input_a5;
    QTextEdit *output_a6;
    QTextEdit *output_message;
    QTextEdit *output_x;
    QPushButton *stop_button;
    QTextEdit *output_buf_last;
    QPushButton *default_button;
    QLabel *label_7;
    QLabel *label_12;
    QTextEdit *output_t;
    QPushButton *copy_button;
    QLabel *label_10;
    QTextEdit *output_z;
    QLabel *label_14;
    QTextEdit *output_seq;
    QPushButton *debug_button;

    void setupUi(QWidget *robotInterface)
    {
        if (robotInterface->objectName().isEmpty())
            robotInterface->setObjectName(QString::fromUtf8("robotInterface"));
        robotInterface->resize(840, 871);
        tabWidget = new QTabWidget(robotInterface);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 811, 841));
        tab_Interaction = new QWidget();
        tab_Interaction->setObjectName(QString::fromUtf8("tab_Interaction"));
        gridLayoutWidget_2 = new QWidget(tab_Interaction);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(40, 20, 717, 761));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Do = new QPushButton(gridLayoutWidget_2);
        pushButton_Do->setObjectName(QString::fromUtf8("pushButton_Do"));

        gridLayout_2->addWidget(pushButton_Do, 15, 1, 1, 1);

        label_Operation = new QLabel(gridLayoutWidget_2);
        label_Operation->setObjectName(QString::fromUtf8("label_Operation"));

        gridLayout_2->addWidget(label_Operation, 16, 0, 1, 1);

        lineEdit_TransX = new QLineEdit(gridLayoutWidget_2);
        lineEdit_TransX->setObjectName(QString::fromUtf8("lineEdit_TransX"));

        gridLayout_2->addWidget(lineEdit_TransX, 1, 3, 1, 1);

        label_Joint5_S = new QLabel(gridLayoutWidget_2);
        label_Joint5_S->setObjectName(QString::fromUtf8("label_Joint5_S"));

        gridLayout_2->addWidget(label_Joint5_S, 13, 0, 1, 1);

        label_Joint3_S = new QLabel(gridLayoutWidget_2);
        label_Joint3_S->setObjectName(QString::fromUtf8("label_Joint3_S"));

        gridLayout_2->addWidget(label_Joint3_S, 11, 0, 1, 1);

        lineEdit_TransY = new QLineEdit(gridLayoutWidget_2);
        lineEdit_TransY->setObjectName(QString::fromUtf8("lineEdit_TransY"));

        gridLayout_2->addWidget(lineEdit_TransY, 2, 3, 1, 1);

        lineEdit_Joint4 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint4->setObjectName(QString::fromUtf8("lineEdit_Joint4"));

        gridLayout_2->addWidget(lineEdit_Joint4, 5, 1, 1, 1);

        label_Joint1 = new QLabel(gridLayoutWidget_2);
        label_Joint1->setObjectName(QString::fromUtf8("label_Joint1"));

        gridLayout_2->addWidget(label_Joint1, 1, 0, 1, 1);

        lineEdit_RotateX = new QLineEdit(gridLayoutWidget_2);
        lineEdit_RotateX->setObjectName(QString::fromUtf8("lineEdit_RotateX"));

        gridLayout_2->addWidget(lineEdit_RotateX, 6, 3, 1, 1);

        label_Joint5 = new QLabel(gridLayoutWidget_2);
        label_Joint5->setObjectName(QString::fromUtf8("label_Joint5"));

        gridLayout_2->addWidget(label_Joint5, 6, 0, 1, 1);

        lineEdit_Joint5 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint5->setObjectName(QString::fromUtf8("lineEdit_Joint5"));

        gridLayout_2->addWidget(lineEdit_Joint5, 6, 1, 1, 1);

        label_PoseTarget = new QLabel(gridLayoutWidget_2);
        label_PoseTarget->setObjectName(QString::fromUtf8("label_PoseTarget"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_PoseTarget->setFont(font);

        gridLayout_2->addWidget(label_PoseTarget, 0, 2, 1, 1);

        label_Joint6 = new QLabel(gridLayoutWidget_2);
        label_Joint6->setObjectName(QString::fromUtf8("label_Joint6"));

        gridLayout_2->addWidget(label_Joint6, 7, 0, 1, 1);

        label_RotateX = new QLabel(gridLayoutWidget_2);
        label_RotateX->setObjectName(QString::fromUtf8("label_RotateX"));

        gridLayout_2->addWidget(label_RotateX, 6, 2, 1, 1);

        label_Joint2 = new QLabel(gridLayoutWidget_2);
        label_Joint2->setObjectName(QString::fromUtf8("label_Joint2"));

        gridLayout_2->addWidget(label_Joint2, 2, 0, 1, 1);

        label_Joint1_S = new QLabel(gridLayoutWidget_2);
        label_Joint1_S->setObjectName(QString::fromUtf8("label_Joint1_S"));

        gridLayout_2->addWidget(label_Joint1_S, 9, 0, 1, 1);

        label_RotateZ = new QLabel(gridLayoutWidget_2);
        label_RotateZ->setObjectName(QString::fromUtf8("label_RotateZ"));

        gridLayout_2->addWidget(label_RotateZ, 8, 2, 1, 1);

        lineEdit_Joint2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint2->setObjectName(QString::fromUtf8("lineEdit_Joint2"));

        gridLayout_2->addWidget(lineEdit_Joint2, 2, 1, 1, 1);

        lineEdit_Joint2_S = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint2_S->setObjectName(QString::fromUtf8("lineEdit_Joint2_S"));
        lineEdit_Joint2_S->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Joint2_S, 10, 1, 1, 1);

        label_TransZ = new QLabel(gridLayoutWidget_2);
        label_TransZ->setObjectName(QString::fromUtf8("label_TransZ"));

        gridLayout_2->addWidget(label_TransZ, 4, 2, 1, 1);

        lineEdit_Joint1 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint1->setObjectName(QString::fromUtf8("lineEdit_Joint1"));

        gridLayout_2->addWidget(lineEdit_Joint1, 1, 1, 1, 1);

        label_JointTarget = new QLabel(gridLayoutWidget_2);
        label_JointTarget->setObjectName(QString::fromUtf8("label_JointTarget"));
        label_JointTarget->setFont(font);

        gridLayout_2->addWidget(label_JointTarget, 0, 0, 1, 1);

        lineEdit_RotateW = new QLineEdit(gridLayoutWidget_2);
        lineEdit_RotateW->setObjectName(QString::fromUtf8("lineEdit_RotateW"));

        gridLayout_2->addWidget(lineEdit_RotateW, 5, 3, 1, 1);

        label_RotateY = new QLabel(gridLayoutWidget_2);
        label_RotateY->setObjectName(QString::fromUtf8("label_RotateY"));

        gridLayout_2->addWidget(label_RotateY, 7, 2, 1, 1);

        label_Joint4 = new QLabel(gridLayoutWidget_2);
        label_Joint4->setObjectName(QString::fromUtf8("label_Joint4"));

        gridLayout_2->addWidget(label_Joint4, 5, 0, 1, 1);

        label_RotateW = new QLabel(gridLayoutWidget_2);
        label_RotateW->setObjectName(QString::fromUtf8("label_RotateW"));

        gridLayout_2->addWidget(label_RotateW, 5, 2, 1, 1);

        label_Joint3 = new QLabel(gridLayoutWidget_2);
        label_Joint3->setObjectName(QString::fromUtf8("label_Joint3"));

        gridLayout_2->addWidget(label_Joint3, 4, 0, 1, 1);

        lineEdit_Joint6 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint6->setObjectName(QString::fromUtf8("lineEdit_Joint6"));

        gridLayout_2->addWidget(lineEdit_Joint6, 7, 1, 1, 1);

        lineEdit_TransZ = new QLineEdit(gridLayoutWidget_2);
        lineEdit_TransZ->setObjectName(QString::fromUtf8("lineEdit_TransZ"));

        gridLayout_2->addWidget(lineEdit_TransZ, 4, 3, 1, 1);

        lineEdit_RotateY = new QLineEdit(gridLayoutWidget_2);
        lineEdit_RotateY->setObjectName(QString::fromUtf8("lineEdit_RotateY"));

        gridLayout_2->addWidget(lineEdit_RotateY, 7, 3, 1, 1);

        label_TransY = new QLabel(gridLayoutWidget_2);
        label_TransY->setObjectName(QString::fromUtf8("label_TransY"));

        gridLayout_2->addWidget(label_TransY, 2, 2, 1, 1);

        label_Joint4_S = new QLabel(gridLayoutWidget_2);
        label_Joint4_S->setObjectName(QString::fromUtf8("label_Joint4_S"));

        gridLayout_2->addWidget(label_Joint4_S, 12, 0, 1, 1);

        label_Joint2_S = new QLabel(gridLayoutWidget_2);
        label_Joint2_S->setObjectName(QString::fromUtf8("label_Joint2_S"));

        gridLayout_2->addWidget(label_Joint2_S, 10, 0, 1, 1);

        label_JointState = new QLabel(gridLayoutWidget_2);
        label_JointState->setObjectName(QString::fromUtf8("label_JointState"));
        label_JointState->setFont(font);

        gridLayout_2->addWidget(label_JointState, 8, 0, 1, 1);

        label_TransX = new QLabel(gridLayoutWidget_2);
        label_TransX->setObjectName(QString::fromUtf8("label_TransX"));

        gridLayout_2->addWidget(label_TransX, 1, 2, 1, 1);

        lineEdit_Joint3 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint3->setObjectName(QString::fromUtf8("lineEdit_Joint3"));

        gridLayout_2->addWidget(lineEdit_Joint3, 4, 1, 1, 1);

        lineEdit_RotateZ = new QLineEdit(gridLayoutWidget_2);
        lineEdit_RotateZ->setObjectName(QString::fromUtf8("lineEdit_RotateZ"));

        gridLayout_2->addWidget(lineEdit_RotateZ, 8, 3, 1, 1);

        label_Joint6_S = new QLabel(gridLayoutWidget_2);
        label_Joint6_S->setObjectName(QString::fromUtf8("label_Joint6_S"));

        gridLayout_2->addWidget(label_Joint6_S, 14, 0, 1, 1);

        lineEdit_Joint1_S = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint1_S->setObjectName(QString::fromUtf8("lineEdit_Joint1_S"));
        lineEdit_Joint1_S->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Joint1_S, 9, 1, 1, 1);

        lineEdit_Joint3_S = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint3_S->setObjectName(QString::fromUtf8("lineEdit_Joint3_S"));
        lineEdit_Joint3_S->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Joint3_S, 11, 1, 1, 1);

        lineEdit_Joint4_S = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint4_S->setObjectName(QString::fromUtf8("lineEdit_Joint4_S"));
        lineEdit_Joint4_S->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Joint4_S, 12, 1, 1, 1);

        lineEdit_Joint5_S = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint5_S->setObjectName(QString::fromUtf8("lineEdit_Joint5_S"));
        lineEdit_Joint5_S->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Joint5_S, 13, 1, 1, 1);

        lineEdit_Joint6_S = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint6_S->setObjectName(QString::fromUtf8("lineEdit_Joint6_S"));
        lineEdit_Joint6_S->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Joint6_S, 14, 1, 1, 1);

        pushButton_CopyJointState = new QPushButton(gridLayoutWidget_2);
        pushButton_CopyJointState->setObjectName(QString::fromUtf8("pushButton_CopyJointState"));

        gridLayout_2->addWidget(pushButton_CopyJointState, 8, 1, 1, 1);

        pushButton_VisualizeJointPlan = new QPushButton(gridLayoutWidget_2);
        pushButton_VisualizeJointPlan->setObjectName(QString::fromUtf8("pushButton_VisualizeJointPlan"));

        gridLayout_2->addWidget(pushButton_VisualizeJointPlan, 0, 1, 1, 1);

        pushButton_VisualizePosePlan = new QPushButton(gridLayoutWidget_2);
        pushButton_VisualizePosePlan->setObjectName(QString::fromUtf8("pushButton_VisualizePosePlan"));

        gridLayout_2->addWidget(pushButton_VisualizePosePlan, 0, 3, 1, 1);

        pushButton_ExecutePlan = new QPushButton(gridLayoutWidget_2);
        pushButton_ExecutePlan->setObjectName(QString::fromUtf8("pushButton_ExecutePlan"));

        gridLayout_2->addWidget(pushButton_ExecutePlan, 10, 3, 1, 1);

        pushButton_AddWaypoint = new QPushButton(gridLayoutWidget_2);
        pushButton_AddWaypoint->setObjectName(QString::fromUtf8("pushButton_AddWaypoint"));

        gridLayout_2->addWidget(pushButton_AddWaypoint, 12, 3, 1, 1);

        pushButton_ExecuteWaypointsPlan = new QPushButton(gridLayoutWidget_2);
        pushButton_ExecuteWaypointsPlan->setObjectName(QString::fromUtf8("pushButton_ExecuteWaypointsPlan"));

        gridLayout_2->addWidget(pushButton_ExecuteWaypointsPlan, 13, 3, 1, 1);

        label_CollisionObject = new QLabel(gridLayoutWidget_2);
        label_CollisionObject->setObjectName(QString::fromUtf8("label_CollisionObject"));
        label_CollisionObject->setFont(font);

        gridLayout_2->addWidget(label_CollisionObject, 15, 0, 1, 1);

        comboBox_Shape = new QComboBox(gridLayoutWidget_2);
        comboBox_Shape->setObjectName(QString::fromUtf8("comboBox_Shape"));

        gridLayout_2->addWidget(comboBox_Shape, 17, 1, 1, 1);

        comboBox_Operation = new QComboBox(gridLayoutWidget_2);
        comboBox_Operation->setObjectName(QString::fromUtf8("comboBox_Operation"));

        gridLayout_2->addWidget(comboBox_Operation, 16, 1, 1, 1);

        label_Shape = new QLabel(gridLayoutWidget_2);
        label_Shape->setObjectName(QString::fromUtf8("label_Shape"));

        gridLayout_2->addWidget(label_Shape, 17, 0, 1, 1);

        label_CurrenCollisionObject = new QLabel(gridLayoutWidget_2);
        label_CurrenCollisionObject->setObjectName(QString::fromUtf8("label_CurrenCollisionObject"));

        gridLayout_2->addWidget(label_CurrenCollisionObject, 19, 0, 1, 1);

        label_CollisionID = new QLabel(gridLayoutWidget_2);
        label_CollisionID->setObjectName(QString::fromUtf8("label_CollisionID"));

        gridLayout_2->addWidget(label_CollisionID, 18, 0, 1, 1);

        lineEdit_Z_2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Z_2->setObjectName(QString::fromUtf8("lineEdit_Z_2"));
        lineEdit_Z_2->setReadOnly(false);

        gridLayout_2->addWidget(lineEdit_Z_2, 18, 1, 1, 1);

        label_Dimension_Z = new QLabel(gridLayoutWidget_2);
        label_Dimension_Z->setObjectName(QString::fromUtf8("label_Dimension_Z"));

        gridLayout_2->addWidget(label_Dimension_Z, 18, 2, 1, 1);

        lineEdit_Z = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Z->setObjectName(QString::fromUtf8("lineEdit_Z"));
        lineEdit_Z->setReadOnly(false);

        gridLayout_2->addWidget(lineEdit_Z, 18, 3, 1, 1);

        label_Dimension_Y_Height = new QLabel(gridLayoutWidget_2);
        label_Dimension_Y_Height->setObjectName(QString::fromUtf8("label_Dimension_Y_Height"));

        gridLayout_2->addWidget(label_Dimension_Y_Height, 17, 2, 1, 1);

        lineEdit_Y_Height = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Y_Height->setObjectName(QString::fromUtf8("lineEdit_Y_Height"));
        lineEdit_Y_Height->setReadOnly(false);

        gridLayout_2->addWidget(lineEdit_Y_Height, 17, 3, 1, 1);

        lineEdit_X_Radius = new QLineEdit(gridLayoutWidget_2);
        lineEdit_X_Radius->setObjectName(QString::fromUtf8("lineEdit_X_Radius"));
        lineEdit_X_Radius->setReadOnly(false);

        gridLayout_2->addWidget(lineEdit_X_Radius, 16, 3, 1, 1);

        label_Dimension_X_Radius = new QLabel(gridLayoutWidget_2);
        label_Dimension_X_Radius->setObjectName(QString::fromUtf8("label_Dimension_X_Radius"));

        gridLayout_2->addWidget(label_Dimension_X_Radius, 16, 2, 1, 1);

        listWidget_CurrentCollisionObject = new QListWidget(gridLayoutWidget_2);
        listWidget_CurrentCollisionObject->setObjectName(QString::fromUtf8("listWidget_CurrentCollisionObject"));

        gridLayout_2->addWidget(listWidget_CurrentCollisionObject, 19, 1, 1, 1);

        tabWidget->addTab(tab_Interaction, QString());
        tab_SingleCommand = new QWidget();
        tab_SingleCommand->setObjectName(QString::fromUtf8("tab_SingleCommand"));
        gridLayoutWidget = new QWidget(tab_SingleCommand);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 791, 451));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        output_s = new QTextEdit(gridLayoutWidget);
        output_s->setObjectName(QString::fromUtf8("output_s"));
        output_s->setMinimumSize(QSize(40, 27));
        output_s->setMaximumSize(QSize(40, 27));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(218, 218, 218, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(236, 236, 236, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(109, 109, 109, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(145, 145, 145, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_s->setPalette(palette);
        output_s->setTabChangesFocus(true);
        output_s->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_s, 6, 8, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(60, 27));
        label_9->setMaximumSize(QSize(60, 27));

        gridLayout->addWidget(label_9, 8, 1, 1, 1, Qt::AlignRight);

        output_a2 = new QTextEdit(gridLayoutWidget);
        output_a2->setObjectName(QString::fromUtf8("output_a2"));
        output_a2->setMinimumSize(QSize(80, 27));
        output_a2->setMaximumSize(QSize(80, 27));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_a2->setPalette(palette1);
        output_a2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a2->setTabChangesFocus(true);
        output_a2->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_a2, 7, 2, 1, 2);

        comboBox_style = new QComboBox(gridLayoutWidget);
        comboBox_style->setObjectName(QString::fromUtf8("comboBox_style"));

        gridLayout->addWidget(comboBox_style, 3, 1, 1, 1);

        input_config = new QTextEdit(gridLayoutWidget);
        input_config->setObjectName(QString::fromUtf8("input_config"));
        input_config->setMinimumSize(QSize(80, 27));
        input_config->setMaximumSize(QSize(80, 27));
        input_config->setAcceptDrops(false);
        input_config->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_config->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_config->setTabChangesFocus(true);

        gridLayout->addWidget(input_config, 4, 4, 1, 1);

        send_config_button = new QPushButton(gridLayoutWidget);
        send_config_button->setObjectName(QString::fromUtf8("send_config_button"));
        send_config_button->setMinimumSize(QSize(80, 25));
        send_config_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(send_config_button, 4, 5, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 40));
        label_2->setMaximumSize(QSize(400, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 4, 1, 2);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(60, 27));
        label_5->setMaximumSize(QSize(60, 27));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        input_x = new QTextEdit(gridLayoutWidget);
        input_x->setObjectName(QString::fromUtf8("input_x"));
        input_x->setEnabled(true);
        input_x->setMinimumSize(QSize(80, 27));
        input_x->setMaximumSize(QSize(80, 27));
        input_x->setAcceptDrops(false);
        input_x->setAutoFillBackground(false);
        input_x->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_x->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_x->setTabChangesFocus(true);

        gridLayout->addWidget(input_x, 1, 1, 1, 1);

        output_y = new QTextEdit(gridLayoutWidget);
        output_y->setObjectName(QString::fromUtf8("output_y"));
        output_y->setMinimumSize(QSize(80, 27));
        output_y->setMaximumSize(QSize(80, 27));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_y->setPalette(palette2);
        output_y->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_y->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_y->setTabChangesFocus(true);
        output_y->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_y, 6, 2, 1, 2);

        input_s = new QTextEdit(gridLayoutWidget);
        input_s->setObjectName(QString::fromUtf8("input_s"));
        input_s->setMinimumSize(QSize(40, 27));
        input_s->setMaximumSize(QSize(40, 27));

        gridLayout->addWidget(input_s, 1, 8, 1, 1);

        send_frame_button = new QPushButton(gridLayoutWidget);
        send_frame_button->setObjectName(QString::fromUtf8("send_frame_button"));
        send_frame_button->setMinimumSize(QSize(80, 25));
        send_frame_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(send_frame_button, 3, 6, 1, 1);

        comboBox_config = new QComboBox(gridLayoutWidget);
        comboBox_config->setObjectName(QString::fromUtf8("comboBox_config"));

        gridLayout->addWidget(comboBox_config, 4, 1, 1, 3);

        input_t = new QTextEdit(gridLayoutWidget);
        input_t->setObjectName(QString::fromUtf8("input_t"));
        input_t->setMinimumSize(QSize(40, 27));
        input_t->setMaximumSize(QSize(40, 27));

        gridLayout->addWidget(input_t, 1, 9, 1, 1);

        input_a3 = new QTextEdit(gridLayoutWidget);
        input_a3->setObjectName(QString::fromUtf8("input_a3"));
        input_a3->setMinimumSize(QSize(80, 27));
        input_a3->setMaximumSize(QSize(80, 27));
        input_a3->setAcceptDrops(false);
        input_a3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a3->setTabChangesFocus(true);

        gridLayout->addWidget(input_a3, 2, 4, 1, 1);

        send_pos_button = new QPushButton(gridLayoutWidget);
        send_pos_button->setObjectName(QString::fromUtf8("send_pos_button"));
        send_pos_button->setMinimumSize(QSize(80, 25));
        send_pos_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(send_pos_button, 3, 7, 1, 1);

        output_buf_front = new QTextEdit(gridLayoutWidget);
        output_buf_front->setObjectName(QString::fromUtf8("output_buf_front"));
        output_buf_front->setMinimumSize(QSize(35, 27));
        output_buf_front->setMaximumSize(QSize(35, 27));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_buf_front->setPalette(palette3);
        output_buf_front->setTabChangesFocus(true);
        output_buf_front->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_buf_front, 8, 2, 1, 1);

        input_b = new QTextEdit(gridLayoutWidget);
        input_b->setObjectName(QString::fromUtf8("input_b"));
        input_b->setMinimumSize(QSize(80, 27));
        input_b->setMaximumSize(QSize(80, 27));
        input_b->setAcceptDrops(false);
        input_b->setAutoFillBackground(false);
        input_b->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_b->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_b->setTabChangesFocus(true);

        gridLayout->addWidget(input_b, 1, 6, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(60, 27));
        label_6->setMaximumSize(QSize(60, 27));

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        send_axis_button = new QPushButton(gridLayoutWidget);
        send_axis_button->setObjectName(QString::fromUtf8("send_axis_button"));
        send_axis_button->setMinimumSize(QSize(80, 25));
        send_axis_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(send_axis_button, 3, 5, 1, 1);

        output_a3 = new QTextEdit(gridLayoutWidget);
        output_a3->setObjectName(QString::fromUtf8("output_a3"));
        output_a3->setMinimumSize(QSize(80, 27));
        output_a3->setMaximumSize(QSize(80, 27));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_a3->setPalette(palette4);
        output_a3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a3->setTabChangesFocus(true);
        output_a3->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_a3, 7, 4, 1, 1);

        output_a1 = new QTextEdit(gridLayoutWidget);
        output_a1->setObjectName(QString::fromUtf8("output_a1"));
        output_a1->setMinimumSize(QSize(80, 27));
        output_a1->setMaximumSize(QSize(80, 27));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_a1->setPalette(palette5);
        output_a1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a1->setTabChangesFocus(true);
        output_a1->setLineWrapMode(QTextEdit::NoWrap);
        output_a1->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_a1, 7, 1, 1, 1);

        input_a = new QTextEdit(gridLayoutWidget);
        input_a->setObjectName(QString::fromUtf8("input_a"));
        input_a->setMinimumSize(QSize(80, 27));
        input_a->setMaximumSize(QSize(80, 27));
        input_a->setAcceptDrops(false);
        input_a->setAutoFillBackground(false);
        input_a->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a->setTabChangesFocus(true);

        gridLayout->addWidget(input_a, 1, 5, 1, 1);

        input_a2 = new QTextEdit(gridLayoutWidget);
        input_a2->setObjectName(QString::fromUtf8("input_a2"));
        input_a2->setMinimumSize(QSize(80, 27));
        input_a2->setMaximumSize(QSize(80, 27));
        input_a2->setAcceptDrops(false);
        input_a2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a2->setTabChangesFocus(true);

        gridLayout->addWidget(input_a2, 2, 2, 1, 2);

        output_a = new QTextEdit(gridLayoutWidget);
        output_a->setObjectName(QString::fromUtf8("output_a"));
        output_a->setMinimumSize(QSize(80, 27));
        output_a->setMaximumSize(QSize(80, 27));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_a->setPalette(palette6);
        output_a->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a->setTabChangesFocus(true);
        output_a->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_a, 6, 5, 1, 1);

        input_a1 = new QTextEdit(gridLayoutWidget);
        input_a1->setObjectName(QString::fromUtf8("input_a1"));
        input_a1->setMinimumSize(QSize(80, 27));
        input_a1->setMaximumSize(QSize(80, 27));
        input_a1->setAcceptDrops(false);
        input_a1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a1->setTabChangesFocus(true);

        gridLayout->addWidget(input_a1, 2, 1, 1, 1);

        comboBox_approx = new QComboBox(gridLayoutWidget);
        comboBox_approx->setObjectName(QString::fromUtf8("comboBox_approx"));

        gridLayout->addWidget(comboBox_approx, 3, 4, 1, 1);

        input_z = new QTextEdit(gridLayoutWidget);
        input_z->setObjectName(QString::fromUtf8("input_z"));
        input_z->setMinimumSize(QSize(80, 27));
        input_z->setMaximumSize(QSize(80, 27));
        input_z->setAcceptDrops(false);
        input_z->setAutoFillBackground(false);
        input_z->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_z->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_z->setTabChangesFocus(true);

        gridLayout->addWidget(input_z, 1, 4, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 27));
        label_3->setMaximumSize(QSize(60, 27));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(60, 27));
        label_13->setMaximumSize(QSize(60, 27));

        gridLayout->addWidget(label_13, 3, 2, 1, 2, Qt::AlignRight);

        terminate_imm_button = new QPushButton(gridLayoutWidget);
        terminate_imm_button->setObjectName(QString::fromUtf8("terminate_imm_button"));
        terminate_imm_button->setMinimumSize(QSize(80, 25));
        terminate_imm_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(terminate_imm_button, 4, 7, 1, 1);

        output_b = new QTextEdit(gridLayoutWidget);
        output_b->setObjectName(QString::fromUtf8("output_b"));
        output_b->setMinimumSize(QSize(80, 27));
        output_b->setMaximumSize(QSize(80, 27));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_b->setPalette(palette7);
        output_b->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_b->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_b->setTabChangesFocus(true);
        output_b->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_b, 6, 6, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(60, 27));
        label_4->setMaximumSize(QSize(60, 27));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        output_a4 = new QTextEdit(gridLayoutWidget);
        output_a4->setObjectName(QString::fromUtf8("output_a4"));
        output_a4->setMinimumSize(QSize(80, 27));
        output_a4->setMaximumSize(QSize(80, 27));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_a4->setPalette(palette8);
        output_a4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a4->setTabChangesFocus(true);
        output_a4->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_a4, 7, 5, 1, 1);

        input_a4 = new QTextEdit(gridLayoutWidget);
        input_a4->setObjectName(QString::fromUtf8("input_a4"));
        input_a4->setMinimumSize(QSize(80, 27));
        input_a4->setMaximumSize(QSize(80, 27));
        input_a4->setAcceptDrops(false);
        input_a4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a4->setTabChangesFocus(true);

        gridLayout->addWidget(input_a4, 2, 5, 1, 1);

        input_y = new QTextEdit(gridLayoutWidget);
        input_y->setObjectName(QString::fromUtf8("input_y"));
        input_y->setMinimumSize(QSize(80, 27));
        input_y->setMaximumSize(QSize(80, 27));
        input_y->setAcceptDrops(false);
        input_y->setAutoFillBackground(false);
        input_y->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_y->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_y->setTabChangesFocus(true);

        gridLayout->addWidget(input_y, 1, 2, 1, 2);

        output_a5 = new QTextEdit(gridLayoutWidget);
        output_a5->setObjectName(QString::fromUtf8("output_a5"));
        output_a5->setMinimumSize(QSize(80, 27));
        output_a5->setMaximumSize(QSize(80, 27));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush7(QColor(231, 230, 230, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush7);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_a5->setPalette(palette9);
        output_a5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a5->setTabChangesFocus(true);
        output_a5->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_a5, 7, 6, 1, 1);

        pause_buf_buton = new QPushButton(gridLayoutWidget);
        pause_buf_buton->setObjectName(QString::fromUtf8("pause_buf_buton"));
        pause_buf_buton->setMinimumSize(QSize(80, 25));
        pause_buf_buton->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(pause_buf_buton, 4, 6, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(30, 27));
        label_8->setMaximumSize(QSize(30, 27));

        gridLayout->addWidget(label_8, 5, 7, 1, 1, Qt::AlignRight);

        pause_button = new QPushButton(gridLayoutWidget);
        pause_button->setObjectName(QString::fromUtf8("pause_button"));
        pause_button->setMinimumSize(QSize(80, 25));
        pause_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(pause_button, 6, 10, 1, 1);

        output_c = new QTextEdit(gridLayoutWidget);
        output_c->setObjectName(QString::fromUtf8("output_c"));
        output_c->setMinimumSize(QSize(80, 27));
        output_c->setMaximumSize(QSize(80, 27));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_c->setPalette(palette10);
        output_c->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_c->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_c->setTabChangesFocus(true);
        output_c->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_c, 6, 7, 1, 1);

        input_a6 = new QTextEdit(gridLayoutWidget);
        input_a6->setObjectName(QString::fromUtf8("input_a6"));
        input_a6->setMinimumSize(QSize(80, 27));
        input_a6->setMaximumSize(QSize(80, 27));
        input_a6->setAcceptDrops(false);
        input_a6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a6->setTabChangesFocus(true);

        gridLayout->addWidget(input_a6, 2, 7, 1, 1);

        input_c = new QTextEdit(gridLayoutWidget);
        input_c->setObjectName(QString::fromUtf8("input_c"));
        input_c->setMinimumSize(QSize(80, 27));
        input_c->setMaximumSize(QSize(80, 27));
        input_c->setAcceptDrops(false);
        input_c->setAutoFillBackground(false);
        input_c->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_c->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_c->setTabChangesFocus(true);

        gridLayout->addWidget(input_c, 1, 7, 1, 1);

        terminate_buf_button = new QPushButton(gridLayoutWidget);
        terminate_buf_button->setObjectName(QString::fromUtf8("terminate_buf_button"));
        terminate_buf_button->setMinimumSize(QSize(80, 25));
        terminate_buf_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(terminate_buf_button, 8, 10, 1, 1);

        output_result = new QTextEdit(gridLayoutWidget);
        output_result->setObjectName(QString::fromUtf8("output_result"));
        output_result->setMinimumSize(QSize(60, 27));
        output_result->setMaximumSize(QSize(60, 27));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette11.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_result->setPalette(palette11);
        output_result->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_result->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_result->setTabChangesFocus(true);
        output_result->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_result, 8, 5, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(70, 27));
        label_11->setMaximumSize(QSize(70, 27));

        gridLayout->addWidget(label_11, 8, 6, 1, 1, Qt::AlignRight);

        input_a5 = new QTextEdit(gridLayoutWidget);
        input_a5->setObjectName(QString::fromUtf8("input_a5"));
        input_a5->setMinimumSize(QSize(80, 27));
        input_a5->setMaximumSize(QSize(80, 27));
        input_a5->setAcceptDrops(false);
        input_a5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a5->setTabChangesFocus(true);

        gridLayout->addWidget(input_a5, 2, 6, 1, 1);

        output_a6 = new QTextEdit(gridLayoutWidget);
        output_a6->setObjectName(QString::fromUtf8("output_a6"));
        output_a6->setMinimumSize(QSize(80, 27));
        output_a6->setMaximumSize(QSize(80, 27));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette12.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette12.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_a6->setPalette(palette12);
        output_a6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a6->setTabChangesFocus(true);
        output_a6->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_a6, 7, 7, 1, 1);

        output_message = new QTextEdit(gridLayoutWidget);
        output_message->setObjectName(QString::fromUtf8("output_message"));
        output_message->setMinimumSize(QSize(40, 27));
        output_message->setMaximumSize(QSize(180, 27));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette13.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_message->setPalette(palette13);
        output_message->setTabChangesFocus(true);
        output_message->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_message, 8, 7, 1, 3);

        output_x = new QTextEdit(gridLayoutWidget);
        output_x->setObjectName(QString::fromUtf8("output_x"));
        output_x->setMinimumSize(QSize(80, 27));
        output_x->setMaximumSize(QSize(80, 27));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette14.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette14.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_x->setPalette(palette14);
        output_x->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_x->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_x->setTabChangesFocus(true);
        output_x->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_x, 6, 1, 1, 1);

        stop_button = new QPushButton(gridLayoutWidget);
        stop_button->setObjectName(QString::fromUtf8("stop_button"));
        stop_button->setMinimumSize(QSize(80, 25));
        stop_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(stop_button, 7, 10, 1, 1);

        output_buf_last = new QTextEdit(gridLayoutWidget);
        output_buf_last->setObjectName(QString::fromUtf8("output_buf_last"));
        output_buf_last->setMinimumSize(QSize(35, 27));
        output_buf_last->setMaximumSize(QSize(35, 27));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette15.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette15.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette15.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette15.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_buf_last->setPalette(palette15);
        output_buf_last->setTabChangesFocus(true);
        output_buf_last->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_buf_last, 8, 3, 1, 1);

        default_button = new QPushButton(gridLayoutWidget);
        default_button->setObjectName(QString::fromUtf8("default_button"));
        default_button->setMinimumSize(QSize(80, 25));
        default_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(default_button, 1, 10, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(80, 40));
        label_7->setMaximumSize(QSize(400, 40));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_7->setFont(font2);

        gridLayout->addWidget(label_7, 5, 4, 1, 2);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(60, 27));
        label_12->setMaximumSize(QSize(60, 27));

        gridLayout->addWidget(label_12, 3, 0, 1, 1);

        output_t = new QTextEdit(gridLayoutWidget);
        output_t->setObjectName(QString::fromUtf8("output_t"));
        output_t->setMinimumSize(QSize(40, 27));
        output_t->setMaximumSize(QSize(40, 27));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette16.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette16.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush);
        palette16.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette16.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_t->setPalette(palette16);
        output_t->setTabChangesFocus(true);
        output_t->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_t, 6, 9, 1, 1);

        copy_button = new QPushButton(gridLayoutWidget);
        copy_button->setObjectName(QString::fromUtf8("copy_button"));
        copy_button->setMinimumSize(QSize(80, 25));
        copy_button->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(copy_button, 2, 10, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(60, 27));
        label_10->setMaximumSize(QSize(60, 27));

        gridLayout->addWidget(label_10, 8, 4, 1, 1, Qt::AlignRight);

        output_z = new QTextEdit(gridLayoutWidget);
        output_z->setObjectName(QString::fromUtf8("output_z"));
        output_z->setMinimumSize(QSize(80, 27));
        output_z->setMaximumSize(QSize(80, 27));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette17.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette17.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette17.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush);
        palette17.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette17.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette17.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette17.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_z->setPalette(palette17);
        output_z->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_z->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_z->setTabChangesFocus(true);
        output_z->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_z, 6, 4, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(60, 27));
        label_14->setMaximumSize(QSize(60, 27));

        gridLayout->addWidget(label_14, 4, 0, 1, 1);

        output_seq = new QTextEdit(gridLayoutWidget);
        output_seq->setObjectName(QString::fromUtf8("output_seq"));
        output_seq->setMinimumSize(QSize(80, 27));
        output_seq->setMaximumSize(QSize(90, 27));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        output_seq->setPalette(palette18);
        output_seq->setTabChangesFocus(true);
        output_seq->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(output_seq, 5, 8, 1, 2);

        debug_button = new QPushButton(gridLayoutWidget);
        debug_button->setObjectName(QString::fromUtf8("debug_button"));
        debug_button->setMinimumSize(QSize(60, 15));
        debug_button->setMaximumSize(QSize(58, 15));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        debug_button->setFont(font3);

        gridLayout->addWidget(debug_button, 3, 10, 1, 1, Qt::AlignHCenter);

        tabWidget->addTab(tab_SingleCommand, QString());

        retranslateUi(robotInterface);

        tabWidget->setCurrentIndex(0);

        QStringList operation_list;
        operation_list << "ADD" << "REMOVE";
        comboBox_Operation->addItems(operation_list);

        QStringList shape_list;
        shape_list << "BOX" << "SPHERE" << "CYLINDER" << "CONE";
        comboBox_Shape->addItems(shape_list);

        QMetaObject::connectSlotsByName(robotInterface);
    } // setupUi

    void retranslateUi(QWidget *robotInterface)
    {
        robotInterface->setWindowTitle(QApplication::translate("robotInterface", "Kuka Robot Interface", 0, QApplication::UnicodeUTF8));
        pushButton_Do->setText(QApplication::translate("robotInterface", "Do", 0, QApplication::UnicodeUTF8));
        label_Operation->setText(QApplication::translate("robotInterface", "Operation", 0, QApplication::UnicodeUTF8));
        label_Joint5_S->setText(QApplication::translate("robotInterface", "Joint5", 0, QApplication::UnicodeUTF8));
        label_Joint3_S->setText(QApplication::translate("robotInterface", "Joint3", 0, QApplication::UnicodeUTF8));
        label_Joint1->setText(QApplication::translate("robotInterface", "Joint1", 0, QApplication::UnicodeUTF8));
        label_Joint5->setText(QApplication::translate("robotInterface", "Joint5", 0, QApplication::UnicodeUTF8));
        label_PoseTarget->setText(QApplication::translate("robotInterface", "Pose Target", 0, QApplication::UnicodeUTF8));
        label_Joint6->setText(QApplication::translate("robotInterface", "Joint6", 0, QApplication::UnicodeUTF8));
        label_RotateX->setText(QApplication::translate("robotInterface", "RotateX", 0, QApplication::UnicodeUTF8));
        label_Joint2->setText(QApplication::translate("robotInterface", "Joint2", 0, QApplication::UnicodeUTF8));
        label_Joint1_S->setText(QApplication::translate("robotInterface", "Joint1", 0, QApplication::UnicodeUTF8));
        label_RotateZ->setText(QApplication::translate("robotInterface", "RotateZ", 0, QApplication::UnicodeUTF8));
        label_TransZ->setText(QApplication::translate("robotInterface", "TransZ", 0, QApplication::UnicodeUTF8));
        label_JointTarget->setText(QApplication::translate("robotInterface", "Joint Target", 0, QApplication::UnicodeUTF8));
        label_RotateY->setText(QApplication::translate("robotInterface", "RotateY", 0, QApplication::UnicodeUTF8));
        label_Joint4->setText(QApplication::translate("robotInterface", "Joint4", 0, QApplication::UnicodeUTF8));
        label_RotateW->setText(QApplication::translate("robotInterface", "RotateW", 0, QApplication::UnicodeUTF8));
        label_Joint3->setText(QApplication::translate("robotInterface", "Joint3", 0, QApplication::UnicodeUTF8));
        label_TransY->setText(QApplication::translate("robotInterface", "TransY", 0, QApplication::UnicodeUTF8));
        label_Joint4_S->setText(QApplication::translate("robotInterface", "Joint4", 0, QApplication::UnicodeUTF8));
        label_Joint2_S->setText(QApplication::translate("robotInterface", "Joint2", 0, QApplication::UnicodeUTF8));
        label_JointState->setText(QApplication::translate("robotInterface", "Joint State", 0, QApplication::UnicodeUTF8));
        label_TransX->setText(QApplication::translate("robotInterface", "TransX", 0, QApplication::UnicodeUTF8));
        label_Joint6_S->setText(QApplication::translate("robotInterface", "Joint6", 0, QApplication::UnicodeUTF8));
        pushButton_CopyJointState->setText(QApplication::translate("robotInterface", "Copy Joint State to Target", 0, QApplication::UnicodeUTF8));
        pushButton_VisualizeJointPlan->setText(QApplication::translate("robotInterface", "Visualize Joint Plan", 0, QApplication::UnicodeUTF8));
        pushButton_VisualizePosePlan->setText(QApplication::translate("robotInterface", "Visualize Pose Plan", 0, QApplication::UnicodeUTF8));
        pushButton_ExecutePlan->setText(QApplication::translate("robotInterface", "Execute Single Target Plan", 0, QApplication::UnicodeUTF8));
        pushButton_AddWaypoint->setText(QApplication::translate("robotInterface", "Add Waypoint", 0, QApplication::UnicodeUTF8));
        pushButton_ExecuteWaypointsPlan->setText(QApplication::translate("robotInterface", "Execute Multiple Targets Plan", 0, QApplication::UnicodeUTF8));
        label_CollisionObject->setText(QApplication::translate("robotInterface", "Collision Object", 0, QApplication::UnicodeUTF8));
        label_Shape->setText(QApplication::translate("robotInterface", "Shape", 0, QApplication::UnicodeUTF8));
        label_CurrenCollisionObject->setText(QApplication::translate("robotInterface", "Current Collision Object", 0, QApplication::UnicodeUTF8));
        label_CollisionID->setText(QApplication::translate("robotInterface", "Collision ID", 0, QApplication::UnicodeUTF8));
        label_Dimension_Z->setText(QApplication::translate("robotInterface", "Z", 0, QApplication::UnicodeUTF8));
        label_Dimension_Y_Height->setText(QApplication::translate("robotInterface", "Y / Height", 0, QApplication::UnicodeUTF8));
        label_Dimension_X_Radius->setText(QApplication::translate("robotInterface", "X / Radius", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Interaction), QApplication::translate("robotInterface", "Interaction", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("robotInterface", "Buffer:", 0, QApplication::UnicodeUTF8));
        comboBox_style->clear();
        comboBox_style->insertItems(0, QStringList()
         << QApplication::translate("robotInterface", "PTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "LIN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "CIRC", 0, QApplication::UnicodeUTF8)
        );
        send_config_button->setText(QApplication::translate("robotInterface", "Config.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("robotInterface", "Command", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("robotInterface", "Position", 0, QApplication::UnicodeUTF8));
        send_frame_button->setText(QApplication::translate("robotInterface", "To Frame", 0, QApplication::UnicodeUTF8));
        comboBox_config->clear();
        comboBox_config->insertItems(0, QStringList()
         << QApplication::translate("robotInterface", "$ADVANCE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$ACC_PTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$VEL_PTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$ACC_CP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$ACC.ORI1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$ACC.ORI2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$VEL_CP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$VEL.ORI1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$VEL.ORI2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$APO.CPTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$APO.CDIS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$APO.CVEL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "$APO.CORI", 0, QApplication::UnicodeUTF8)
        );
        send_pos_button->setText(QApplication::translate("robotInterface", "To Pos.", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("robotInterface", "Axis", 0, QApplication::UnicodeUTF8));
        send_axis_button->setText(QApplication::translate("robotInterface", "To Axis", 0, QApplication::UnicodeUTF8));
        comboBox_approx->clear();
        comboBox_approx->insertItems(0, QStringList()
         << QApplication::translate("robotInterface", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "C_PTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "C_DIS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "C_VEL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "C_ORI", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("robotInterface", "Position", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("robotInterface", "Approx.", 0, QApplication::UnicodeUTF8));
        terminate_imm_button->setText(QApplication::translate("robotInterface", "Term. Imm.", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("robotInterface", "Axis", 0, QApplication::UnicodeUTF8));
        pause_buf_buton->setText(QApplication::translate("robotInterface", "Pause Buf.", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("robotInterface", "No.", 0, QApplication::UnicodeUTF8));
        pause_button->setText(QApplication::translate("robotInterface", "Pause", 0, QApplication::UnicodeUTF8));
        terminate_buf_button->setText(QApplication::translate("robotInterface", "Terminate", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("robotInterface", "Message:", 0, QApplication::UnicodeUTF8));
        stop_button->setText(QApplication::translate("robotInterface", "Stop", 0, QApplication::UnicodeUTF8));
        default_button->setText(QApplication::translate("robotInterface", "Default", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("robotInterface", "Feedback", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("robotInterface", "Style", 0, QApplication::UnicodeUTF8));
        copy_button->setText(QApplication::translate("robotInterface", "Copy", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("robotInterface", "Result:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("robotInterface", "Config.", 0, QApplication::UnicodeUTF8));
        debug_button->setText(QApplication::translate("robotInterface", "DEBUG", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_SingleCommand), QApplication::translate("robotInterface", "Single Command", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class robotInterface: public Ui_robotInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_H
