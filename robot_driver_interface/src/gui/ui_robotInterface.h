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
    QWidget *tab_PathPlanning;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_ConvertPosetoJoint;
    QLabel *label_incrRotateC;
    QLabel *label_incrTransY;
    QLabel *label_incrRotateB;
    QLabel *label_incrTransZ;
    QPushButton *pushButton_ExecutePlan;
    QLineEdit *lineEdit_TransX;
    QLineEdit *lineEdit_TransY;
    QLineEdit *lineEdit_Joint4;
    QLabel *label_Joint1;
    QLineEdit *lineEdit_RotateB;
    QLabel *label_Joint5;
    QLineEdit *lineEdit_Joint5;
    QLabel *label_Joint6;
    QLabel *label_RotateB;
    QLabel *label_Joint2;
    QLineEdit *lineEdit_Joint2;
    QLabel *label_TransZ;
    QLineEdit *lineEdit_Joint1;
    QLineEdit *lineEdit_RotateA;
    QLabel *label_RotateC;
    QLabel *label_Joint4;
    QLabel *label_RotateA;
    QLabel *label_Joint3;
    QLineEdit *lineEdit_RotateC;
    QLineEdit *lineEdit_Joint6;
    QLineEdit *lineEdit_TransZ;
    QLabel *label_TransY;
    QLabel *label_TransX;
    QLineEdit *lineEdit_Joint3;
    QPushButton *pushButton_VisualizeJointPlan;
    QPushButton *pushButton_VisualizePosePlan;
    QPushButton *pushButton_ExecuteWaypointsPlan;
    QLabel *label_Target;
    QLabel *label_incrTransX;
    QLabel *label_incrRotateA;
    QLineEdit *lineEdit_incrTransX;
    QLineEdit *lineEdit_incrTransY;
    QLineEdit *lineEdit_incrTransZ;
    QLineEdit *lineEdit_incrRotateA;
    QLineEdit *lineEdit_incrRotateB;
    QLineEdit *lineEdit_incrRotateC;
    QPushButton *pushButton_VisualizeIncrPosePlan;
    QPushButton *pushButton_AddWaypoint;
    QWidget *tab_Calibration;
    QWidget *gridLayoutWidget_10;
    QGridLayout *gridLayout_10;
    QLineEdit *lineEdit_AxisVectorZ;
    QLabel *label_AxisType;
    QLabel *label_RotateDegree;
    QLineEdit *lineEdit_RotateDegree;
    QLabel *label_AxisVector;
    QPushButton *pushButton_ExecuteRotatePlan;
    QPushButton *pushButton_VisualizeRotatePlan;
    QComboBox *comboBox_AxisType;
    QLineEdit *lineEdit_AxisVectorX;
    QLineEdit *lineEdit_AxisVectorY;
    QWidget *tab_Environment;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_X_Radius;
    QLabel *label_Dimension_Z;
    QLabel *label_CurrenCollisionObject;
    QLabel *label_Operation;
    QLabel *label_Dimension_X_Radius;
    QComboBox *comboBox_Shape;
    QLineEdit *lineEdit_Z;
    QLineEdit *lineEdit_CollisionID;
    QLineEdit *lineEdit_Y_Height;
    QComboBox *comboBox_Operation;
    QPushButton *pushButton_Do;
    QLabel *label_Dimension_Y_Height;
    QLabel *label_CollisionID;
    QLabel *label_Shape;
    QLabel *label_CollisionObject;
    QListWidget *listWidget_CurrentCollisionObject;
    QWidget *tab_SingleCommand;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_Joint2_4;
    QLabel *label_S;
    QComboBox *comboBox_style;
    QPushButton *send_config_button;
    QTextEdit *input_config;
    QTextEdit *input_x;
    QPushButton *send_frame_button;
    QComboBox *comboBox_config;
    QTextEdit *input_a3;
    QPushButton *send_pos_button;
    QTextEdit *input_b;
    QPushButton *send_axis_button;
    QTextEdit *input_a;
    QTextEdit *input_a2;
    QTextEdit *input_a1;
    QComboBox *comboBox_approx;
    QTextEdit *input_z;
    QLabel *label_Position_2;
    QLabel *label_Approx;
    QPushButton *terminate_imm_button;
    QLabel *label_Joint_2;
    QTextEdit *input_a4;
    QTextEdit *input_y;
    QPushButton *pause_buf_buton;
    QTextEdit *input_a6;
    QTextEdit *input_c;
    QTextEdit *input_a5;
    QLabel *label_Style;
    QTextEdit *input_s;
    QLabel *label_Command;
    QLabel *label_TransX_4;
    QTextEdit *input_t;
    QPushButton *convert_button;
    QLabel *label_RotateA_4;
    QLabel *label_TransY_4;
    QLabel *label_T;
    QPushButton *default_button;
    QLabel *labe_TransZ_4;
    QLabel *label_Config;
    QLabel *label_RotateB_4;
    QLabel *label_RotateC_4;
    QPushButton *debug_button;
    QLabel *label_Joint1_4;
    QLabel *label_Joint3_4;
    QLabel *label_Joint4_4;
    QLabel *label_Joint5_4;
    QLabel *label_Joint6_4;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_6;
    QTextEdit *output_a;
    QTextEdit *output_result;
    QLabel *label_Feedback;
    QTextEdit *output_buf_front;
    QTextEdit *output_b;
    QTextEdit *output_message;
    QLabel *label_Message;
    QTextEdit *output_a6;
    QTextEdit *output_s;
    QTextEdit *output_c;
    QLabel *label_Result;
    QTextEdit *output_z;
    QTextEdit *output_x;
    QLabel *label_Buffer;
    QTextEdit *output_buf_last;
    QTextEdit *output_a2;
    QLabel *label_Position;
    QLabel *label_No;
    QTextEdit *output_a1;
    QLabel *label_Joint;
    QTextEdit *output_a4;
    QTextEdit *output_t;
    QTextEdit *output_a3;
    QTextEdit *output_seq;
    QTextEdit *output_a5;
    QTextEdit *output_y;
    QPushButton *copy_button;
    QPushButton *pause_button;
    QPushButton *stop_button;
    QPushButton *terminate_buf_button;

    void setupUi(QWidget *robotInterface)
    {
        if (robotInterface->objectName().isEmpty())
            robotInterface->setObjectName(QString::fromUtf8("robotInterface"));
        robotInterface->resize(918, 643);
        tabWidget = new QTabWidget(robotInterface);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 791, 371));
        tab_PathPlanning = new QWidget();
        tab_PathPlanning->setObjectName(QString::fromUtf8("tab_PathPlanning"));
        gridLayoutWidget_2 = new QWidget(tab_PathPlanning);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 10, 781, 321));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_ConvertPosetoJoint = new QPushButton(gridLayoutWidget_2);
        pushButton_ConvertPosetoJoint->setObjectName(QString::fromUtf8("pushButton_ConvertPosetoJoint"));
        pushButton_ConvertPosetoJoint->setMaximumSize(QSize(217, 27));

        gridLayout->addWidget(pushButton_ConvertPosetoJoint, 7, 3, 1, 1);

        label_incrRotateC = new QLabel(gridLayoutWidget_2);
        label_incrRotateC->setObjectName(QString::fromUtf8("label_incrRotateC"));
        label_incrRotateC->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_incrRotateC, 6, 4, 1, 1);

        label_incrTransY = new QLabel(gridLayoutWidget_2);
        label_incrTransY->setObjectName(QString::fromUtf8("label_incrTransY"));
        label_incrTransY->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_incrTransY, 2, 4, 1, 1);

        label_incrRotateB = new QLabel(gridLayoutWidget_2);
        label_incrRotateB->setObjectName(QString::fromUtf8("label_incrRotateB"));
        label_incrRotateB->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_incrRotateB, 5, 4, 1, 1);

        label_incrTransZ = new QLabel(gridLayoutWidget_2);
        label_incrTransZ->setObjectName(QString::fromUtf8("label_incrTransZ"));
        label_incrTransZ->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_incrTransZ, 3, 4, 1, 1);

        pushButton_ExecutePlan = new QPushButton(gridLayoutWidget_2);
        pushButton_ExecutePlan->setObjectName(QString::fromUtf8("pushButton_ExecutePlan"));
        pushButton_ExecutePlan->setMaximumSize(QSize(217, 27));

        gridLayout->addWidget(pushButton_ExecutePlan, 8, 3, 1, 1);

        lineEdit_TransX = new QLineEdit(gridLayoutWidget_2);
        lineEdit_TransX->setObjectName(QString::fromUtf8("lineEdit_TransX"));
        lineEdit_TransX->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_TransX, 1, 3, 1, 1);

        lineEdit_TransY = new QLineEdit(gridLayoutWidget_2);
        lineEdit_TransY->setObjectName(QString::fromUtf8("lineEdit_TransY"));
        lineEdit_TransY->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_TransY, 2, 3, 1, 1);

        lineEdit_Joint4 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint4->setObjectName(QString::fromUtf8("lineEdit_Joint4"));
        lineEdit_Joint4->setMaximumSize(QSize(160, 27));

        gridLayout->addWidget(lineEdit_Joint4, 4, 1, 1, 1);

        label_Joint1 = new QLabel(gridLayoutWidget_2);
        label_Joint1->setObjectName(QString::fromUtf8("label_Joint1"));
        label_Joint1->setMaximumSize(QSize(111, 27));

        gridLayout->addWidget(label_Joint1, 1, 0, 1, 1);

        lineEdit_RotateB = new QLineEdit(gridLayoutWidget_2);
        lineEdit_RotateB->setObjectName(QString::fromUtf8("lineEdit_RotateB"));
        lineEdit_RotateB->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_RotateB, 5, 3, 1, 1);

        label_Joint5 = new QLabel(gridLayoutWidget_2);
        label_Joint5->setObjectName(QString::fromUtf8("label_Joint5"));
        label_Joint5->setMaximumSize(QSize(111, 27));

        gridLayout->addWidget(label_Joint5, 5, 0, 1, 1);

        lineEdit_Joint5 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint5->setObjectName(QString::fromUtf8("lineEdit_Joint5"));
        lineEdit_Joint5->setMaximumSize(QSize(160, 27));

        gridLayout->addWidget(lineEdit_Joint5, 5, 1, 1, 1);

        label_Joint6 = new QLabel(gridLayoutWidget_2);
        label_Joint6->setObjectName(QString::fromUtf8("label_Joint6"));
        label_Joint6->setMaximumSize(QSize(111, 27));

        gridLayout->addWidget(label_Joint6, 6, 0, 1, 1);

        label_RotateB = new QLabel(gridLayoutWidget_2);
        label_RotateB->setObjectName(QString::fromUtf8("label_RotateB"));
        label_RotateB->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_RotateB, 5, 2, 1, 1);

        label_Joint2 = new QLabel(gridLayoutWidget_2);
        label_Joint2->setObjectName(QString::fromUtf8("label_Joint2"));
        label_Joint2->setMaximumSize(QSize(111, 27));

        gridLayout->addWidget(label_Joint2, 2, 0, 1, 1);

        lineEdit_Joint2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint2->setObjectName(QString::fromUtf8("lineEdit_Joint2"));
        lineEdit_Joint2->setMaximumSize(QSize(160, 27));

        gridLayout->addWidget(lineEdit_Joint2, 2, 1, 1, 1);

        label_TransZ = new QLabel(gridLayoutWidget_2);
        label_TransZ->setObjectName(QString::fromUtf8("label_TransZ"));
        label_TransZ->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_TransZ, 3, 2, 1, 1);

        lineEdit_Joint1 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint1->setObjectName(QString::fromUtf8("lineEdit_Joint1"));
        lineEdit_Joint1->setMaximumSize(QSize(160, 27));

        gridLayout->addWidget(lineEdit_Joint1, 1, 1, 1, 1);

        lineEdit_RotateA = new QLineEdit(gridLayoutWidget_2);
        lineEdit_RotateA->setObjectName(QString::fromUtf8("lineEdit_RotateA"));
        lineEdit_RotateA->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_RotateA, 4, 3, 1, 1);

        label_RotateC = new QLabel(gridLayoutWidget_2);
        label_RotateC->setObjectName(QString::fromUtf8("label_RotateC"));
        label_RotateC->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_RotateC, 6, 2, 1, 1);

        label_Joint4 = new QLabel(gridLayoutWidget_2);
        label_Joint4->setObjectName(QString::fromUtf8("label_Joint4"));
        label_Joint4->setMaximumSize(QSize(111, 27));

        gridLayout->addWidget(label_Joint4, 4, 0, 1, 1);

        label_RotateA = new QLabel(gridLayoutWidget_2);
        label_RotateA->setObjectName(QString::fromUtf8("label_RotateA"));
        label_RotateA->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_RotateA, 4, 2, 1, 1);

        label_Joint3 = new QLabel(gridLayoutWidget_2);
        label_Joint3->setObjectName(QString::fromUtf8("label_Joint3"));
        label_Joint3->setMaximumSize(QSize(111, 27));

        gridLayout->addWidget(label_Joint3, 3, 0, 1, 1);

        lineEdit_RotateC = new QLineEdit(gridLayoutWidget_2);
        lineEdit_RotateC->setObjectName(QString::fromUtf8("lineEdit_RotateC"));
        lineEdit_RotateC->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_RotateC, 6, 3, 1, 1);

        lineEdit_Joint6 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint6->setObjectName(QString::fromUtf8("lineEdit_Joint6"));
        lineEdit_Joint6->setMaximumSize(QSize(160, 27));

        gridLayout->addWidget(lineEdit_Joint6, 6, 1, 1, 1);

        lineEdit_TransZ = new QLineEdit(gridLayoutWidget_2);
        lineEdit_TransZ->setObjectName(QString::fromUtf8("lineEdit_TransZ"));
        lineEdit_TransZ->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_TransZ, 3, 3, 1, 1);

        label_TransY = new QLabel(gridLayoutWidget_2);
        label_TransY->setObjectName(QString::fromUtf8("label_TransY"));
        label_TransY->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_TransY, 2, 2, 1, 1);

        label_TransX = new QLabel(gridLayoutWidget_2);
        label_TransX->setObjectName(QString::fromUtf8("label_TransX"));
        label_TransX->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_TransX, 1, 2, 1, 1);

        lineEdit_Joint3 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Joint3->setObjectName(QString::fromUtf8("lineEdit_Joint3"));
        lineEdit_Joint3->setMaximumSize(QSize(160, 27));

        gridLayout->addWidget(lineEdit_Joint3, 3, 1, 1, 1);

        pushButton_VisualizeJointPlan = new QPushButton(gridLayoutWidget_2);
        pushButton_VisualizeJointPlan->setObjectName(QString::fromUtf8("pushButton_VisualizeJointPlan"));
        pushButton_VisualizeJointPlan->setMaximumSize(QSize(271, 27));

        gridLayout->addWidget(pushButton_VisualizeJointPlan, 0, 1, 1, 1);

        pushButton_VisualizePosePlan = new QPushButton(gridLayoutWidget_2);
        pushButton_VisualizePosePlan->setObjectName(QString::fromUtf8("pushButton_VisualizePosePlan"));
        pushButton_VisualizePosePlan->setMaximumSize(QSize(271, 27));

        gridLayout->addWidget(pushButton_VisualizePosePlan, 0, 3, 1, 1);

        pushButton_ExecuteWaypointsPlan = new QPushButton(gridLayoutWidget_2);
        pushButton_ExecuteWaypointsPlan->setObjectName(QString::fromUtf8("pushButton_ExecuteWaypointsPlan"));
        pushButton_ExecuteWaypointsPlan->setMaximumSize(QSize(217, 27));

        gridLayout->addWidget(pushButton_ExecuteWaypointsPlan, 8, 1, 1, 1);

        label_Target = new QLabel(gridLayoutWidget_2);
        label_Target->setObjectName(QString::fromUtf8("label_Target"));
        label_Target->setMaximumSize(QSize(111, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_Target->setFont(font);

        gridLayout->addWidget(label_Target, 0, 0, 1, 1);

        label_incrTransX = new QLabel(gridLayoutWidget_2);
        label_incrTransX->setObjectName(QString::fromUtf8("label_incrTransX"));
        label_incrTransX->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_incrTransX, 1, 4, 1, 1);

        label_incrRotateA = new QLabel(gridLayoutWidget_2);
        label_incrRotateA->setObjectName(QString::fromUtf8("label_incrRotateA"));
        label_incrRotateA->setMaximumSize(QSize(108, 27));

        gridLayout->addWidget(label_incrRotateA, 4, 4, 1, 1);

        lineEdit_incrTransX = new QLineEdit(gridLayoutWidget_2);
        lineEdit_incrTransX->setObjectName(QString::fromUtf8("lineEdit_incrTransX"));
        lineEdit_incrTransX->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_incrTransX, 1, 5, 1, 1);

        lineEdit_incrTransY = new QLineEdit(gridLayoutWidget_2);
        lineEdit_incrTransY->setObjectName(QString::fromUtf8("lineEdit_incrTransY"));
        lineEdit_incrTransY->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_incrTransY, 2, 5, 1, 1);

        lineEdit_incrTransZ = new QLineEdit(gridLayoutWidget_2);
        lineEdit_incrTransZ->setObjectName(QString::fromUtf8("lineEdit_incrTransZ"));
        lineEdit_incrTransZ->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_incrTransZ, 3, 5, 1, 1);

        lineEdit_incrRotateA = new QLineEdit(gridLayoutWidget_2);
        lineEdit_incrRotateA->setObjectName(QString::fromUtf8("lineEdit_incrRotateA"));
        lineEdit_incrRotateA->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_incrRotateA, 4, 5, 1, 1);

        lineEdit_incrRotateB = new QLineEdit(gridLayoutWidget_2);
        lineEdit_incrRotateB->setObjectName(QString::fromUtf8("lineEdit_incrRotateB"));
        lineEdit_incrRotateB->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_incrRotateB, 5, 5, 1, 1);

        lineEdit_incrRotateC = new QLineEdit(gridLayoutWidget_2);
        lineEdit_incrRotateC->setObjectName(QString::fromUtf8("lineEdit_incrRotateC"));
        lineEdit_incrRotateC->setMaximumSize(QSize(159, 27));

        gridLayout->addWidget(lineEdit_incrRotateC, 6, 5, 1, 1);

        pushButton_VisualizeIncrPosePlan = new QPushButton(gridLayoutWidget_2);
        pushButton_VisualizeIncrPosePlan->setObjectName(QString::fromUtf8("pushButton_VisualizeIncrPosePlan"));
        pushButton_VisualizeIncrPosePlan->setMaximumSize(QSize(271, 27));

        gridLayout->addWidget(pushButton_VisualizeIncrPosePlan, 0, 5, 1, 1);

        pushButton_AddWaypoint = new QPushButton(gridLayoutWidget_2);
        pushButton_AddWaypoint->setObjectName(QString::fromUtf8("pushButton_AddWaypoint"));
        pushButton_AddWaypoint->setMaximumSize(QSize(217, 27));

        gridLayout->addWidget(pushButton_AddWaypoint, 7, 1, 1, 1);

        tabWidget->addTab(tab_PathPlanning, QString());
        tab_Calibration = new QWidget();
        tab_Calibration->setObjectName(QString::fromUtf8("tab_Calibration"));
        gridLayoutWidget_10 = new QWidget(tab_Calibration);
        gridLayoutWidget_10->setObjectName(QString::fromUtf8("gridLayoutWidget_10"));
        gridLayoutWidget_10->setGeometry(QRect(0, 10, 481, 281));
        gridLayout_10 = new QGridLayout(gridLayoutWidget_10);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        lineEdit_AxisVectorZ = new QLineEdit(gridLayoutWidget_10);
        lineEdit_AxisVectorZ->setObjectName(QString::fromUtf8("lineEdit_AxisVectorZ"));
        lineEdit_AxisVectorZ->setMaximumSize(QSize(160, 27));

        gridLayout_10->addWidget(lineEdit_AxisVectorZ, 1, 3, 1, 1);

        label_AxisType = new QLabel(gridLayoutWidget_10);
        label_AxisType->setObjectName(QString::fromUtf8("label_AxisType"));

        gridLayout_10->addWidget(label_AxisType, 0, 0, 1, 1);

        label_RotateDegree = new QLabel(gridLayoutWidget_10);
        label_RotateDegree->setObjectName(QString::fromUtf8("label_RotateDegree"));

        gridLayout_10->addWidget(label_RotateDegree, 2, 0, 1, 1);

        lineEdit_RotateDegree = new QLineEdit(gridLayoutWidget_10);
        lineEdit_RotateDegree->setObjectName(QString::fromUtf8("lineEdit_RotateDegree"));
        lineEdit_RotateDegree->setMaximumSize(QSize(160, 27));

        gridLayout_10->addWidget(lineEdit_RotateDegree, 2, 1, 1, 1);

        label_AxisVector = new QLabel(gridLayoutWidget_10);
        label_AxisVector->setObjectName(QString::fromUtf8("label_AxisVector"));

        gridLayout_10->addWidget(label_AxisVector, 1, 0, 1, 1);

        pushButton_ExecuteRotatePlan = new QPushButton(gridLayoutWidget_10);
        pushButton_ExecuteRotatePlan->setObjectName(QString::fromUtf8("pushButton_ExecuteRotatePlan"));

        gridLayout_10->addWidget(pushButton_ExecuteRotatePlan, 4, 0, 1, 1);

        pushButton_VisualizeRotatePlan = new QPushButton(gridLayoutWidget_10);
        pushButton_VisualizeRotatePlan->setObjectName(QString::fromUtf8("pushButton_VisualizeRotatePlan"));

        gridLayout_10->addWidget(pushButton_VisualizeRotatePlan, 3, 0, 1, 1);

        comboBox_AxisType = new QComboBox(gridLayoutWidget_10);
        comboBox_AxisType->setObjectName(QString::fromUtf8("comboBox_AxisType"));
        comboBox_AxisType->setMaximumSize(QSize(266, 27));

        gridLayout_10->addWidget(comboBox_AxisType, 0, 1, 1, 1);

        lineEdit_AxisVectorX = new QLineEdit(gridLayoutWidget_10);
        lineEdit_AxisVectorX->setObjectName(QString::fromUtf8("lineEdit_AxisVectorX"));
        lineEdit_AxisVectorX->setMaximumSize(QSize(160, 27));

        gridLayout_10->addWidget(lineEdit_AxisVectorX, 1, 1, 1, 1);

        lineEdit_AxisVectorY = new QLineEdit(gridLayoutWidget_10);
        lineEdit_AxisVectorY->setObjectName(QString::fromUtf8("lineEdit_AxisVectorY"));
        lineEdit_AxisVectorY->setMaximumSize(QSize(160, 27));

        gridLayout_10->addWidget(lineEdit_AxisVectorY, 1, 2, 1, 1);

        tabWidget->addTab(tab_Calibration, QString());
        tab_Environment = new QWidget();
        tab_Environment->setObjectName(QString::fromUtf8("tab_Environment"));
        gridLayoutWidget_6 = new QWidget(tab_Environment);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(0, 10, 781, 321));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_X_Radius = new QLineEdit(gridLayoutWidget_6);
        lineEdit_X_Radius->setObjectName(QString::fromUtf8("lineEdit_X_Radius"));
        lineEdit_X_Radius->setMinimumSize(QSize(266, 27));
        lineEdit_X_Radius->setMaximumSize(QSize(266, 27));
        lineEdit_X_Radius->setReadOnly(false);

        gridLayout_2->addWidget(lineEdit_X_Radius, 1, 3, 1, 1);

        label_Dimension_Z = new QLabel(gridLayoutWidget_6);
        label_Dimension_Z->setObjectName(QString::fromUtf8("label_Dimension_Z"));
        label_Dimension_Z->setMinimumSize(QSize(68, 27));
        label_Dimension_Z->setMaximumSize(QSize(68, 27));

        gridLayout_2->addWidget(label_Dimension_Z, 3, 2, 1, 1);

        label_CurrenCollisionObject = new QLabel(gridLayoutWidget_6);
        label_CurrenCollisionObject->setObjectName(QString::fromUtf8("label_CurrenCollisionObject"));
        label_CurrenCollisionObject->setMinimumSize(QSize(161, 173));
        label_CurrenCollisionObject->setMaximumSize(QSize(161, 173));

        gridLayout_2->addWidget(label_CurrenCollisionObject, 4, 0, 1, 1);

        label_Operation = new QLabel(gridLayoutWidget_6);
        label_Operation->setObjectName(QString::fromUtf8("label_Operation"));
        label_Operation->setMinimumSize(QSize(161, 27));
        label_Operation->setMaximumSize(QSize(161, 27));

        gridLayout_2->addWidget(label_Operation, 1, 0, 1, 1);

        label_Dimension_X_Radius = new QLabel(gridLayoutWidget_6);
        label_Dimension_X_Radius->setObjectName(QString::fromUtf8("label_Dimension_X_Radius"));
        label_Dimension_X_Radius->setMinimumSize(QSize(68, 27));
        label_Dimension_X_Radius->setMaximumSize(QSize(68, 27));

        gridLayout_2->addWidget(label_Dimension_X_Radius, 1, 2, 1, 1);

        comboBox_Shape = new QComboBox(gridLayoutWidget_6);
        comboBox_Shape->setObjectName(QString::fromUtf8("comboBox_Shape"));
        comboBox_Shape->setMinimumSize(QSize(266, 27));
        comboBox_Shape->setMaximumSize(QSize(266, 27));

        gridLayout_2->addWidget(comboBox_Shape, 2, 1, 1, 1);

        lineEdit_Z = new QLineEdit(gridLayoutWidget_6);
        lineEdit_Z->setObjectName(QString::fromUtf8("lineEdit_Z"));
        lineEdit_Z->setMinimumSize(QSize(266, 27));
        lineEdit_Z->setMaximumSize(QSize(266, 27));
        lineEdit_Z->setReadOnly(false);

        gridLayout_2->addWidget(lineEdit_Z, 3, 3, 1, 1);

        lineEdit_CollisionID = new QLineEdit(gridLayoutWidget_6);
        lineEdit_CollisionID->setObjectName(QString::fromUtf8("lineEdit_CollisionID"));
        lineEdit_CollisionID->setMinimumSize(QSize(266, 27));
        lineEdit_CollisionID->setMaximumSize(QSize(266, 27));
        lineEdit_CollisionID->setReadOnly(false);

        gridLayout_2->addWidget(lineEdit_CollisionID, 3, 1, 1, 1);

        lineEdit_Y_Height = new QLineEdit(gridLayoutWidget_6);
        lineEdit_Y_Height->setObjectName(QString::fromUtf8("lineEdit_Y_Height"));
        lineEdit_Y_Height->setMinimumSize(QSize(266, 27));
        lineEdit_Y_Height->setMaximumSize(QSize(266, 27));
        lineEdit_Y_Height->setReadOnly(false);

        gridLayout_2->addWidget(lineEdit_Y_Height, 2, 3, 1, 1);

        comboBox_Operation = new QComboBox(gridLayoutWidget_6);
        comboBox_Operation->setObjectName(QString::fromUtf8("comboBox_Operation"));
        comboBox_Operation->setMinimumSize(QSize(266, 27));
        comboBox_Operation->setMaximumSize(QSize(266, 27));

        gridLayout_2->addWidget(comboBox_Operation, 1, 1, 1, 1);

        pushButton_Do = new QPushButton(gridLayoutWidget_6);
        pushButton_Do->setObjectName(QString::fromUtf8("pushButton_Do"));
        pushButton_Do->setMinimumSize(QSize(266, 27));
        pushButton_Do->setMaximumSize(QSize(266, 27));

        gridLayout_2->addWidget(pushButton_Do, 0, 1, 1, 1);

        label_Dimension_Y_Height = new QLabel(gridLayoutWidget_6);
        label_Dimension_Y_Height->setObjectName(QString::fromUtf8("label_Dimension_Y_Height"));
        label_Dimension_Y_Height->setMinimumSize(QSize(68, 27));
        label_Dimension_Y_Height->setMaximumSize(QSize(68, 27));

        gridLayout_2->addWidget(label_Dimension_Y_Height, 2, 2, 1, 1);

        label_CollisionID = new QLabel(gridLayoutWidget_6);
        label_CollisionID->setObjectName(QString::fromUtf8("label_CollisionID"));
        label_CollisionID->setMinimumSize(QSize(161, 27));
        label_CollisionID->setMaximumSize(QSize(161, 27));

        gridLayout_2->addWidget(label_CollisionID, 3, 0, 1, 1);

        label_Shape = new QLabel(gridLayoutWidget_6);
        label_Shape->setObjectName(QString::fromUtf8("label_Shape"));
        label_Shape->setMinimumSize(QSize(161, 27));
        label_Shape->setMaximumSize(QSize(161, 27));

        gridLayout_2->addWidget(label_Shape, 2, 0, 1, 1);

        label_CollisionObject = new QLabel(gridLayoutWidget_6);
        label_CollisionObject->setObjectName(QString::fromUtf8("label_CollisionObject"));
        label_CollisionObject->setMinimumSize(QSize(161, 41));
        label_CollisionObject->setMaximumSize(QSize(161, 41));
        label_CollisionObject->setFont(font);

        gridLayout_2->addWidget(label_CollisionObject, 0, 0, 1, 1);

        listWidget_CurrentCollisionObject = new QListWidget(gridLayoutWidget_6);
        listWidget_CurrentCollisionObject->setObjectName(QString::fromUtf8("listWidget_CurrentCollisionObject"));
        listWidget_CurrentCollisionObject->setMinimumSize(QSize(612, 173));
        listWidget_CurrentCollisionObject->setMaximumSize(QSize(612, 173));

        gridLayout_2->addWidget(listWidget_CurrentCollisionObject, 4, 1, 1, 3);

        tabWidget->addTab(tab_Environment, QString());
        tab_SingleCommand = new QWidget();
        tab_SingleCommand->setObjectName(QString::fromUtf8("tab_SingleCommand"));
        gridLayoutWidget = new QWidget(tab_SingleCommand);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 781, 321));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Joint2_4 = new QLabel(gridLayoutWidget);
        label_Joint2_4->setObjectName(QString::fromUtf8("label_Joint2_4"));
        label_Joint2_4->setMinimumSize(QSize(80, 22));
        label_Joint2_4->setMaximumSize(QSize(80, 22));

        gridLayout_3->addWidget(label_Joint2_4, 3, 2, 1, 2);

        label_S = new QLabel(gridLayoutWidget);
        label_S->setObjectName(QString::fromUtf8("label_S"));
        label_S->setMinimumSize(QSize(62, 23));
        label_S->setMaximumSize(QSize(62, 23));

        gridLayout_3->addWidget(label_S, 1, 8, 1, 1);

        comboBox_style = new QComboBox(gridLayoutWidget);
        comboBox_style->setObjectName(QString::fromUtf8("comboBox_style"));
        comboBox_style->setMinimumSize(QSize(80, 27));
        comboBox_style->setMaximumSize(QSize(80, 27));

        gridLayout_3->addWidget(comboBox_style, 5, 1, 1, 1);

        send_config_button = new QPushButton(gridLayoutWidget);
        send_config_button->setObjectName(QString::fromUtf8("send_config_button"));
        send_config_button->setMinimumSize(QSize(80, 25));
        send_config_button->setMaximumSize(QSize(80, 25));

        gridLayout_3->addWidget(send_config_button, 6, 5, 1, 1);

        input_config = new QTextEdit(gridLayoutWidget);
        input_config->setObjectName(QString::fromUtf8("input_config"));
        input_config->setMinimumSize(QSize(80, 27));
        input_config->setMaximumSize(QSize(80, 27));
        input_config->setAcceptDrops(false);
        input_config->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_config->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_config->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_config, 6, 4, 1, 1);

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

        gridLayout_3->addWidget(input_x, 2, 1, 1, 1);

        send_frame_button = new QPushButton(gridLayoutWidget);
        send_frame_button->setObjectName(QString::fromUtf8("send_frame_button"));
        send_frame_button->setMinimumSize(QSize(80, 25));
        send_frame_button->setMaximumSize(QSize(80, 25));

        gridLayout_3->addWidget(send_frame_button, 5, 6, 1, 1);

        comboBox_config = new QComboBox(gridLayoutWidget);
        comboBox_config->setObjectName(QString::fromUtf8("comboBox_config"));
        comboBox_config->setMinimumSize(QSize(166, 27));
        comboBox_config->setMaximumSize(QSize(166, 27));

        gridLayout_3->addWidget(comboBox_config, 6, 1, 1, 3);

        input_a3 = new QTextEdit(gridLayoutWidget);
        input_a3->setObjectName(QString::fromUtf8("input_a3"));
        input_a3->setMinimumSize(QSize(80, 27));
        input_a3->setMaximumSize(QSize(80, 27));
        input_a3->setAcceptDrops(false);
        input_a3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a3->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_a3, 4, 4, 1, 1);

        send_pos_button = new QPushButton(gridLayoutWidget);
        send_pos_button->setObjectName(QString::fromUtf8("send_pos_button"));
        send_pos_button->setMinimumSize(QSize(80, 25));
        send_pos_button->setMaximumSize(QSize(80, 25));

        gridLayout_3->addWidget(send_pos_button, 5, 7, 1, 1);

        input_b = new QTextEdit(gridLayoutWidget);
        input_b->setObjectName(QString::fromUtf8("input_b"));
        input_b->setMinimumSize(QSize(80, 27));
        input_b->setMaximumSize(QSize(80, 27));
        input_b->setAcceptDrops(false);
        input_b->setAutoFillBackground(false);
        input_b->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_b->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_b->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_b, 2, 6, 1, 1);

        send_axis_button = new QPushButton(gridLayoutWidget);
        send_axis_button->setObjectName(QString::fromUtf8("send_axis_button"));
        send_axis_button->setMinimumSize(QSize(80, 25));
        send_axis_button->setMaximumSize(QSize(80, 25));

        gridLayout_3->addWidget(send_axis_button, 5, 5, 1, 1);

        input_a = new QTextEdit(gridLayoutWidget);
        input_a->setObjectName(QString::fromUtf8("input_a"));
        input_a->setMinimumSize(QSize(80, 27));
        input_a->setMaximumSize(QSize(80, 27));
        input_a->setAcceptDrops(false);
        input_a->setAutoFillBackground(false);
        input_a->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_a, 2, 5, 1, 1);

        input_a2 = new QTextEdit(gridLayoutWidget);
        input_a2->setObjectName(QString::fromUtf8("input_a2"));
        input_a2->setMinimumSize(QSize(80, 27));
        input_a2->setMaximumSize(QSize(80, 27));
        input_a2->setAcceptDrops(false);
        input_a2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a2->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_a2, 4, 2, 1, 2);

        input_a1 = new QTextEdit(gridLayoutWidget);
        input_a1->setObjectName(QString::fromUtf8("input_a1"));
        input_a1->setMinimumSize(QSize(80, 27));
        input_a1->setMaximumSize(QSize(80, 27));
        input_a1->setAcceptDrops(false);
        input_a1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a1->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_a1, 4, 1, 1, 1);

        comboBox_approx = new QComboBox(gridLayoutWidget);
        comboBox_approx->setObjectName(QString::fromUtf8("comboBox_approx"));
        comboBox_approx->setMinimumSize(QSize(80, 27));
        comboBox_approx->setMaximumSize(QSize(80, 27));

        gridLayout_3->addWidget(comboBox_approx, 5, 4, 1, 1);

        input_z = new QTextEdit(gridLayoutWidget);
        input_z->setObjectName(QString::fromUtf8("input_z"));
        input_z->setMinimumSize(QSize(80, 27));
        input_z->setMaximumSize(QSize(80, 27));
        input_z->setAcceptDrops(false);
        input_z->setAutoFillBackground(false);
        input_z->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_z->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_z->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_z, 2, 4, 1, 1);

        label_Position_2 = new QLabel(gridLayoutWidget);
        label_Position_2->setObjectName(QString::fromUtf8("label_Position_2"));
        label_Position_2->setMinimumSize(QSize(60, 27));
        label_Position_2->setMaximumSize(QSize(60, 27));

        gridLayout_3->addWidget(label_Position_2, 2, 0, 1, 1);

        label_Approx = new QLabel(gridLayoutWidget);
        label_Approx->setObjectName(QString::fromUtf8("label_Approx"));
        label_Approx->setMinimumSize(QSize(60, 27));
        label_Approx->setMaximumSize(QSize(60, 27));

        gridLayout_3->addWidget(label_Approx, 5, 2, 1, 2, Qt::AlignRight);

        terminate_imm_button = new QPushButton(gridLayoutWidget);
        terminate_imm_button->setObjectName(QString::fromUtf8("terminate_imm_button"));
        terminate_imm_button->setMinimumSize(QSize(80, 25));
        terminate_imm_button->setMaximumSize(QSize(80, 25));

        gridLayout_3->addWidget(terminate_imm_button, 6, 7, 1, 1);

        label_Joint_2 = new QLabel(gridLayoutWidget);
        label_Joint_2->setObjectName(QString::fromUtf8("label_Joint_2"));
        label_Joint_2->setMinimumSize(QSize(60, 27));
        label_Joint_2->setMaximumSize(QSize(60, 27));

        gridLayout_3->addWidget(label_Joint_2, 4, 0, 1, 1);

        input_a4 = new QTextEdit(gridLayoutWidget);
        input_a4->setObjectName(QString::fromUtf8("input_a4"));
        input_a4->setMinimumSize(QSize(80, 27));
        input_a4->setMaximumSize(QSize(80, 27));
        input_a4->setAcceptDrops(false);
        input_a4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a4->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_a4, 4, 5, 1, 1);

        input_y = new QTextEdit(gridLayoutWidget);
        input_y->setObjectName(QString::fromUtf8("input_y"));
        input_y->setMinimumSize(QSize(80, 27));
        input_y->setMaximumSize(QSize(80, 27));
        input_y->setAcceptDrops(false);
        input_y->setAutoFillBackground(false);
        input_y->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_y->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_y->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_y, 2, 2, 1, 2);

        pause_buf_buton = new QPushButton(gridLayoutWidget);
        pause_buf_buton->setObjectName(QString::fromUtf8("pause_buf_buton"));
        pause_buf_buton->setMinimumSize(QSize(80, 25));
        pause_buf_buton->setMaximumSize(QSize(80, 25));

        gridLayout_3->addWidget(pause_buf_buton, 6, 6, 1, 1);

        input_a6 = new QTextEdit(gridLayoutWidget);
        input_a6->setObjectName(QString::fromUtf8("input_a6"));
        input_a6->setMinimumSize(QSize(80, 27));
        input_a6->setMaximumSize(QSize(80, 27));
        input_a6->setAcceptDrops(false);
        input_a6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a6->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_a6, 4, 7, 1, 1);

        input_c = new QTextEdit(gridLayoutWidget);
        input_c->setObjectName(QString::fromUtf8("input_c"));
        input_c->setMinimumSize(QSize(80, 27));
        input_c->setMaximumSize(QSize(80, 27));
        input_c->setAcceptDrops(false);
        input_c->setAutoFillBackground(false);
        input_c->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_c->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_c->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_c, 2, 7, 1, 1);

        input_a5 = new QTextEdit(gridLayoutWidget);
        input_a5->setObjectName(QString::fromUtf8("input_a5"));
        input_a5->setMinimumSize(QSize(80, 27));
        input_a5->setMaximumSize(QSize(80, 27));
        input_a5->setAcceptDrops(false);
        input_a5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_a5->setTabChangesFocus(true);

        gridLayout_3->addWidget(input_a5, 4, 6, 1, 1);

        label_Style = new QLabel(gridLayoutWidget);
        label_Style->setObjectName(QString::fromUtf8("label_Style"));
        label_Style->setMinimumSize(QSize(60, 27));
        label_Style->setMaximumSize(QSize(60, 27));

        gridLayout_3->addWidget(label_Style, 5, 0, 1, 1);

        input_s = new QTextEdit(gridLayoutWidget);
        input_s->setObjectName(QString::fromUtf8("input_s"));
        input_s->setMinimumSize(QSize(62, 27));
        input_s->setMaximumSize(QSize(62, 27));

        gridLayout_3->addWidget(input_s, 2, 8, 1, 1);

        label_Command = new QLabel(gridLayoutWidget);
        label_Command->setObjectName(QString::fromUtf8("label_Command"));
        label_Command->setMinimumSize(QSize(146, 40));
        label_Command->setMaximumSize(QSize(146, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_Command->setFont(font1);

        gridLayout_3->addWidget(label_Command, 0, 0, 1, 2);

        label_TransX_4 = new QLabel(gridLayoutWidget);
        label_TransX_4->setObjectName(QString::fromUtf8("label_TransX_4"));
        label_TransX_4->setMinimumSize(QSize(80, 23));
        label_TransX_4->setMaximumSize(QSize(80, 23));

        gridLayout_3->addWidget(label_TransX_4, 1, 1, 1, 1);

        input_t = new QTextEdit(gridLayoutWidget);
        input_t->setObjectName(QString::fromUtf8("input_t"));
        input_t->setMinimumSize(QSize(61, 27));
        input_t->setMaximumSize(QSize(61, 27));

        gridLayout_3->addWidget(input_t, 2, 9, 1, 1);

        convert_button = new QPushButton(gridLayoutWidget);
        convert_button->setObjectName(QString::fromUtf8("convert_button"));
        convert_button->setMinimumSize(QSize(62, 25));
        convert_button->setMaximumSize(QSize(62, 25));

        gridLayout_3->addWidget(convert_button, 4, 10, 1, 1);

        label_RotateA_4 = new QLabel(gridLayoutWidget);
        label_RotateA_4->setObjectName(QString::fromUtf8("label_RotateA_4"));
        label_RotateA_4->setMinimumSize(QSize(80, 23));
        label_RotateA_4->setMaximumSize(QSize(80, 23));

        gridLayout_3->addWidget(label_RotateA_4, 1, 5, 1, 1);

        label_TransY_4 = new QLabel(gridLayoutWidget);
        label_TransY_4->setObjectName(QString::fromUtf8("label_TransY_4"));
        label_TransY_4->setMinimumSize(QSize(80, 23));
        label_TransY_4->setMaximumSize(QSize(80, 23));

        gridLayout_3->addWidget(label_TransY_4, 1, 2, 1, 2);

        label_T = new QLabel(gridLayoutWidget);
        label_T->setObjectName(QString::fromUtf8("label_T"));
        label_T->setMinimumSize(QSize(61, 23));
        label_T->setMaximumSize(QSize(61, 23));

        gridLayout_3->addWidget(label_T, 1, 9, 1, 1);

        default_button = new QPushButton(gridLayoutWidget);
        default_button->setObjectName(QString::fromUtf8("default_button"));
        default_button->setMinimumSize(QSize(62, 25));
        default_button->setMaximumSize(QSize(62, 25));

        gridLayout_3->addWidget(default_button, 2, 10, 1, 1);

        labe_TransZ_4 = new QLabel(gridLayoutWidget);
        labe_TransZ_4->setObjectName(QString::fromUtf8("labe_TransZ_4"));
        labe_TransZ_4->setMinimumSize(QSize(80, 23));
        labe_TransZ_4->setMaximumSize(QSize(80, 23));

        gridLayout_3->addWidget(labe_TransZ_4, 1, 4, 1, 1);

        label_Config = new QLabel(gridLayoutWidget);
        label_Config->setObjectName(QString::fromUtf8("label_Config"));
        label_Config->setMinimumSize(QSize(60, 27));
        label_Config->setMaximumSize(QSize(60, 27));

        gridLayout_3->addWidget(label_Config, 6, 0, 1, 1);

        label_RotateB_4 = new QLabel(gridLayoutWidget);
        label_RotateB_4->setObjectName(QString::fromUtf8("label_RotateB_4"));
        label_RotateB_4->setMinimumSize(QSize(80, 23));
        label_RotateB_4->setMaximumSize(QSize(80, 23));

        gridLayout_3->addWidget(label_RotateB_4, 1, 6, 1, 1);

        label_RotateC_4 = new QLabel(gridLayoutWidget);
        label_RotateC_4->setObjectName(QString::fromUtf8("label_RotateC_4"));
        label_RotateC_4->setMinimumSize(QSize(80, 23));
        label_RotateC_4->setMaximumSize(QSize(80, 23));

        gridLayout_3->addWidget(label_RotateC_4, 1, 7, 1, 1);

        debug_button = new QPushButton(gridLayoutWidget);
        debug_button->setObjectName(QString::fromUtf8("debug_button"));
        debug_button->setMinimumSize(QSize(58, 15));
        debug_button->setMaximumSize(QSize(58, 15));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        debug_button->setFont(font2);

        gridLayout_3->addWidget(debug_button, 5, 10, 1, 1);

        label_Joint1_4 = new QLabel(gridLayoutWidget);
        label_Joint1_4->setObjectName(QString::fromUtf8("label_Joint1_4"));
        label_Joint1_4->setMinimumSize(QSize(80, 22));
        label_Joint1_4->setMaximumSize(QSize(80, 22));

        gridLayout_3->addWidget(label_Joint1_4, 3, 1, 1, 1);

        label_Joint3_4 = new QLabel(gridLayoutWidget);
        label_Joint3_4->setObjectName(QString::fromUtf8("label_Joint3_4"));
        label_Joint3_4->setMinimumSize(QSize(80, 22));
        label_Joint3_4->setMaximumSize(QSize(80, 22));

        gridLayout_3->addWidget(label_Joint3_4, 3, 4, 1, 1);

        label_Joint4_4 = new QLabel(gridLayoutWidget);
        label_Joint4_4->setObjectName(QString::fromUtf8("label_Joint4_4"));
        label_Joint4_4->setMinimumSize(QSize(80, 22));
        label_Joint4_4->setMaximumSize(QSize(80, 22));

        gridLayout_3->addWidget(label_Joint4_4, 3, 5, 1, 1);

        label_Joint5_4 = new QLabel(gridLayoutWidget);
        label_Joint5_4->setObjectName(QString::fromUtf8("label_Joint5_4"));
        label_Joint5_4->setMinimumSize(QSize(80, 22));
        label_Joint5_4->setMaximumSize(QSize(80, 22));

        gridLayout_3->addWidget(label_Joint5_4, 3, 6, 1, 1);

        label_Joint6_4 = new QLabel(gridLayoutWidget);
        label_Joint6_4->setObjectName(QString::fromUtf8("label_Joint6_4"));
        label_Joint6_4->setMinimumSize(QSize(80, 22));
        label_Joint6_4->setMaximumSize(QSize(80, 22));

        gridLayout_3->addWidget(label_Joint6_4, 3, 7, 1, 1);

        tabWidget->addTab(tab_SingleCommand, QString());
        gridLayoutWidget_3 = new QWidget(robotInterface);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(20, 390, 721, 201));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        output_a = new QTextEdit(gridLayoutWidget_3);
        output_a->setObjectName(QString::fromUtf8("output_a"));
        output_a->setMinimumSize(QSize(80, 27));
        output_a->setMaximumSize(QSize(80, 27));
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
        output_a->setPalette(palette);
        output_a->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a->setTabChangesFocus(true);
        output_a->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a, 1, 4, 1, 1);

        output_result = new QTextEdit(gridLayoutWidget_3);
        output_result->setObjectName(QString::fromUtf8("output_result"));
        output_result->setMinimumSize(QSize(80, 27));
        output_result->setMaximumSize(QSize(80, 27));
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
        output_result->setPalette(palette1);
        output_result->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_result->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_result->setTabChangesFocus(true);
        output_result->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_result, 3, 5, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_Feedback = new QLabel(gridLayoutWidget_3);
        label_Feedback->setObjectName(QString::fromUtf8("label_Feedback"));
        label_Feedback->setMinimumSize(QSize(146, 40));
        label_Feedback->setMaximumSize(QSize(146, 40));
        label_Feedback->setFont(font);

        gridLayout_6->addWidget(label_Feedback, 0, 0, 1, 2);

        output_buf_front = new QTextEdit(gridLayoutWidget_3);
        output_buf_front->setObjectName(QString::fromUtf8("output_buf_front"));
        output_buf_front->setMinimumSize(QSize(80, 27));
        output_buf_front->setMaximumSize(QSize(80, 27));
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
        output_buf_front->setPalette(palette2);
        output_buf_front->setTabChangesFocus(true);
        output_buf_front->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_buf_front, 3, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        output_b = new QTextEdit(gridLayoutWidget_3);
        output_b->setObjectName(QString::fromUtf8("output_b"));
        output_b->setMinimumSize(QSize(80, 27));
        output_b->setMaximumSize(QSize(80, 27));
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
        output_b->setPalette(palette3);
        output_b->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_b->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_b->setTabChangesFocus(true);
        output_b->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_b, 1, 5, 1, 1);

        output_message = new QTextEdit(gridLayoutWidget_3);
        output_message->setObjectName(QString::fromUtf8("output_message"));
        output_message->setMinimumSize(QSize(86, 27));
        output_message->setMaximumSize(QSize(86, 27));
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
        output_message->setPalette(palette4);
        output_message->setTabChangesFocus(true);
        output_message->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_message, 3, 7, 1, 2);

        label_Message = new QLabel(gridLayoutWidget_3);
        label_Message->setObjectName(QString::fromUtf8("label_Message"));
        label_Message->setMinimumSize(QSize(70, 27));
        label_Message->setMaximumSize(QSize(70, 27));

        gridLayout_6->addWidget(label_Message, 3, 6, 1, 1);

        output_a6 = new QTextEdit(gridLayoutWidget_3);
        output_a6->setObjectName(QString::fromUtf8("output_a6"));
        output_a6->setMinimumSize(QSize(80, 27));
        output_a6->setMaximumSize(QSize(80, 27));
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
        output_a6->setPalette(palette5);
        output_a6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a6->setTabChangesFocus(true);
        output_a6->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a6, 2, 6, 1, 1);

        output_s = new QTextEdit(gridLayoutWidget_3);
        output_s->setObjectName(QString::fromUtf8("output_s"));
        output_s->setMinimumSize(QSize(40, 27));
        output_s->setMaximumSize(QSize(40, 27));
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
        output_s->setPalette(palette6);
        output_s->setTabChangesFocus(true);
        output_s->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_s, 1, 7, 1, 1);

        output_c = new QTextEdit(gridLayoutWidget_3);
        output_c->setObjectName(QString::fromUtf8("output_c"));
        output_c->setMinimumSize(QSize(80, 27));
        output_c->setMaximumSize(QSize(80, 27));
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
        output_c->setPalette(palette7);
        output_c->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_c->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_c->setTabChangesFocus(true);
        output_c->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_c, 1, 6, 1, 1);

        label_Result = new QLabel(gridLayoutWidget_3);
        label_Result->setObjectName(QString::fromUtf8("label_Result"));
        label_Result->setMinimumSize(QSize(60, 27));
        label_Result->setMaximumSize(QSize(60, 27));

        gridLayout_6->addWidget(label_Result, 3, 4, 1, 1);

        output_z = new QTextEdit(gridLayoutWidget_3);
        output_z->setObjectName(QString::fromUtf8("output_z"));
        output_z->setMinimumSize(QSize(80, 27));
        output_z->setMaximumSize(QSize(80, 27));
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
        output_z->setPalette(palette8);
        output_z->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_z->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_z->setTabChangesFocus(true);
        output_z->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_z, 1, 3, 1, 1);

        output_x = new QTextEdit(gridLayoutWidget_3);
        output_x->setObjectName(QString::fromUtf8("output_x"));
        output_x->setMinimumSize(QSize(80, 27));
        output_x->setMaximumSize(QSize(80, 27));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush2);
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
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush2);
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
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush2);
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
        output_x->setPalette(palette9);
        output_x->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_x->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_x->setTabChangesFocus(true);
        output_x->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_x, 1, 1, 1, 1);

        label_Buffer = new QLabel(gridLayoutWidget_3);
        label_Buffer->setObjectName(QString::fromUtf8("label_Buffer"));
        label_Buffer->setMinimumSize(QSize(60, 27));
        label_Buffer->setMaximumSize(QSize(60, 27));

        gridLayout_6->addWidget(label_Buffer, 3, 1, 1, 1);

        output_buf_last = new QTextEdit(gridLayoutWidget_3);
        output_buf_last->setObjectName(QString::fromUtf8("output_buf_last"));
        output_buf_last->setMinimumSize(QSize(81, 27));
        output_buf_last->setMaximumSize(QSize(81, 27));
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
        output_buf_last->setPalette(palette10);
        output_buf_last->setTabChangesFocus(true);
        output_buf_last->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_buf_last, 3, 3, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        output_a2 = new QTextEdit(gridLayoutWidget_3);
        output_a2->setObjectName(QString::fromUtf8("output_a2"));
        output_a2->setMinimumSize(QSize(80, 27));
        output_a2->setMaximumSize(QSize(80, 27));
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
        output_a2->setPalette(palette11);
        output_a2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a2->setTabChangesFocus(true);
        output_a2->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a2, 2, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_Position = new QLabel(gridLayoutWidget_3);
        label_Position->setObjectName(QString::fromUtf8("label_Position"));
        label_Position->setMinimumSize(QSize(60, 27));
        label_Position->setMaximumSize(QSize(60, 27));

        gridLayout_6->addWidget(label_Position, 1, 0, 1, 1);

        label_No = new QLabel(gridLayoutWidget_3);
        label_No->setObjectName(QString::fromUtf8("label_No"));
        label_No->setMinimumSize(QSize(30, 27));
        label_No->setMaximumSize(QSize(30, 27));

        gridLayout_6->addWidget(label_No, 0, 6, 1, 1);

        output_a1 = new QTextEdit(gridLayoutWidget_3);
        output_a1->setObjectName(QString::fromUtf8("output_a1"));
        output_a1->setMinimumSize(QSize(80, 27));
        output_a1->setMaximumSize(QSize(80, 27));
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
        output_a1->setPalette(palette12);
        output_a1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a1->setTabChangesFocus(true);
        output_a1->setLineWrapMode(QTextEdit::NoWrap);
        output_a1->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a1, 2, 1, 1, 1);

        label_Joint = new QLabel(gridLayoutWidget_3);
        label_Joint->setObjectName(QString::fromUtf8("label_Joint"));
        label_Joint->setMinimumSize(QSize(60, 27));
        label_Joint->setMaximumSize(QSize(60, 27));

        gridLayout_6->addWidget(label_Joint, 2, 0, 1, 1);

        output_a4 = new QTextEdit(gridLayoutWidget_3);
        output_a4->setObjectName(QString::fromUtf8("output_a4"));
        output_a4->setMinimumSize(QSize(80, 27));
        output_a4->setMaximumSize(QSize(80, 27));
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
        output_a4->setPalette(palette13);
        output_a4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a4->setTabChangesFocus(true);
        output_a4->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a4, 2, 4, 1, 1);

        output_t = new QTextEdit(gridLayoutWidget_3);
        output_t->setObjectName(QString::fromUtf8("output_t"));
        output_t->setMinimumSize(QSize(40, 27));
        output_t->setMaximumSize(QSize(40, 27));
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
        output_t->setPalette(palette14);
        output_t->setTabChangesFocus(true);
        output_t->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_t, 1, 8, 1, 1);

        output_a3 = new QTextEdit(gridLayoutWidget_3);
        output_a3->setObjectName(QString::fromUtf8("output_a3"));
        output_a3->setMinimumSize(QSize(80, 27));
        output_a3->setMaximumSize(QSize(80, 27));
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
        output_a3->setPalette(palette15);
        output_a3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a3->setTabChangesFocus(true);
        output_a3->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a3, 2, 3, 1, 1);

        output_seq = new QTextEdit(gridLayoutWidget_3);
        output_seq->setObjectName(QString::fromUtf8("output_seq"));
        output_seq->setMinimumSize(QSize(86, 40));
        output_seq->setMaximumSize(QSize(86, 40));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        output_seq->setPalette(palette16);
        output_seq->setTabChangesFocus(true);
        output_seq->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_seq, 0, 7, 1, 2);

        output_a5 = new QTextEdit(gridLayoutWidget_3);
        output_a5->setObjectName(QString::fromUtf8("output_a5"));
        output_a5->setMinimumSize(QSize(80, 27));
        output_a5->setMaximumSize(QSize(80, 27));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush7(QColor(231, 230, 230, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette17.setBrush(QPalette::Active, QPalette::Light, brush7);
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
        palette17.setBrush(QPalette::Inactive, QPalette::Light, brush7);
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
        palette17.setBrush(QPalette::Disabled, QPalette::Light, brush7);
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
        output_a5->setPalette(palette17);
        output_a5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a5->setTabChangesFocus(true);
        output_a5->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a5, 2, 5, 1, 1);

        output_y = new QTextEdit(gridLayoutWidget_3);
        output_y->setObjectName(QString::fromUtf8("output_y"));
        output_y->setMinimumSize(QSize(80, 27));
        output_y->setMaximumSize(QSize(80, 27));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette18.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette18.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette18.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette18.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush);
        palette18.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette18.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette18.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette18.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette18.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette18.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette18.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        output_y->setPalette(palette18);
        output_y->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_y->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_y->setTabChangesFocus(true);
        output_y->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_y, 1, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        copy_button = new QPushButton(gridLayoutWidget_3);
        copy_button->setObjectName(QString::fromUtf8("copy_button"));
        copy_button->setMinimumSize(QSize(81, 27));
        copy_button->setMaximumSize(QSize(81, 27));

        gridLayout_6->addWidget(copy_button, 0, 2, 1, 1);

        pause_button = new QPushButton(gridLayoutWidget_3);
        pause_button->setObjectName(QString::fromUtf8("pause_button"));
        pause_button->setMinimumSize(QSize(80, 27));
        pause_button->setMaximumSize(QSize(80, 27));

        gridLayout_6->addWidget(pause_button, 0, 3, 1, 1);

        stop_button = new QPushButton(gridLayoutWidget_3);
        stop_button->setObjectName(QString::fromUtf8("stop_button"));
        stop_button->setMinimumSize(QSize(81, 27));
        stop_button->setMaximumSize(QSize(81, 27));

        gridLayout_6->addWidget(stop_button, 0, 4, 1, 1);

        terminate_buf_button = new QPushButton(gridLayoutWidget_3);
        terminate_buf_button->setObjectName(QString::fromUtf8("terminate_buf_button"));
        terminate_buf_button->setMinimumSize(QSize(81, 27));
        terminate_buf_button->setMaximumSize(QSize(81, 27));

        gridLayout_6->addWidget(terminate_buf_button, 0, 5, 1, 1);

        gridLayoutWidget_3->raise();
        tabWidget->raise();

        retranslateUi(robotInterface);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(robotInterface);
    } // setupUi

    void retranslateUi(QWidget *robotInterface)
    {
        robotInterface->setWindowTitle(QApplication::translate("robotInterface", "robotInterface", 0, QApplication::UnicodeUTF8));
        pushButton_ConvertPosetoJoint->setText(QApplication::translate("robotInterface", "Pose to Joint", 0, QApplication::UnicodeUTF8));
        label_incrRotateC->setText(QApplication::translate("robotInterface", "Incr. RotateC", 0, QApplication::UnicodeUTF8));
        label_incrTransY->setText(QApplication::translate("robotInterface", "Incr. TransY", 0, QApplication::UnicodeUTF8));
        label_incrRotateB->setText(QApplication::translate("robotInterface", "Incr. RotateB", 0, QApplication::UnicodeUTF8));
        label_incrTransZ->setText(QApplication::translate("robotInterface", "Incr. TransZ", 0, QApplication::UnicodeUTF8));
        pushButton_ExecutePlan->setText(QApplication::translate("robotInterface", "Exe. Singl. Targt.", 0, QApplication::UnicodeUTF8));
        label_Joint1->setText(QApplication::translate("robotInterface", "Joint1", 0, QApplication::UnicodeUTF8));
        label_Joint5->setText(QApplication::translate("robotInterface", "Joint5", 0, QApplication::UnicodeUTF8));
        label_Joint6->setText(QApplication::translate("robotInterface", "Joint6", 0, QApplication::UnicodeUTF8));
        label_RotateB->setText(QApplication::translate("robotInterface", "RotateB", 0, QApplication::UnicodeUTF8));
        label_Joint2->setText(QApplication::translate("robotInterface", "Joint2", 0, QApplication::UnicodeUTF8));
        label_TransZ->setText(QApplication::translate("robotInterface", "TransZ", 0, QApplication::UnicodeUTF8));
        label_RotateC->setText(QApplication::translate("robotInterface", "RotateC", 0, QApplication::UnicodeUTF8));
        label_Joint4->setText(QApplication::translate("robotInterface", "Joint4", 0, QApplication::UnicodeUTF8));
        label_RotateA->setText(QApplication::translate("robotInterface", "RotateA", 0, QApplication::UnicodeUTF8));
        label_Joint3->setText(QApplication::translate("robotInterface", "Joint3", 0, QApplication::UnicodeUTF8));
        label_TransY->setText(QApplication::translate("robotInterface", "TransY", 0, QApplication::UnicodeUTF8));
        label_TransX->setText(QApplication::translate("robotInterface", "TransX", 0, QApplication::UnicodeUTF8));
        pushButton_VisualizeJointPlan->setText(QApplication::translate("robotInterface", "Joint Plan", 0, QApplication::UnicodeUTF8));
        pushButton_VisualizePosePlan->setText(QApplication::translate("robotInterface", "Pose Plan", 0, QApplication::UnicodeUTF8));
        pushButton_ExecuteWaypointsPlan->setText(QApplication::translate("robotInterface", "Exe. Multi. Targt.", 0, QApplication::UnicodeUTF8));
        label_Target->setText(QApplication::translate("robotInterface", "Target", 0, QApplication::UnicodeUTF8));
        label_incrTransX->setText(QApplication::translate("robotInterface", "Incr. TransX", 0, QApplication::UnicodeUTF8));
        label_incrRotateA->setText(QApplication::translate("robotInterface", "Incr. RotateA", 0, QApplication::UnicodeUTF8));
        pushButton_VisualizeIncrPosePlan->setText(QApplication::translate("robotInterface", "Incr. Pose Plan", 0, QApplication::UnicodeUTF8));
        pushButton_AddWaypoint->setText(QApplication::translate("robotInterface", "Add Waypoint", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_PathPlanning), QApplication::translate("robotInterface", "Path Planning", 0, QApplication::UnicodeUTF8));
        label_AxisType->setText(QApplication::translate("robotInterface", "Axis Type", 0, QApplication::UnicodeUTF8));
        label_RotateDegree->setText(QApplication::translate("robotInterface", "Rotate Degree", 0, QApplication::UnicodeUTF8));
        label_AxisVector->setText(QApplication::translate("robotInterface", "Axis Vector", 0, QApplication::UnicodeUTF8));
        pushButton_ExecuteRotatePlan->setText(QApplication::translate("robotInterface", "Execute Rotate Plan", 0, QApplication::UnicodeUTF8));
        pushButton_VisualizeRotatePlan->setText(QApplication::translate("robotInterface", "Visualize Rotate Plan", 0, QApplication::UnicodeUTF8));
        comboBox_AxisType->clear();
        comboBox_AxisType->insertItems(0, QStringList()
         << QApplication::translate("robotInterface", "X", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "Y", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "Z", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "Custom", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_Calibration), QApplication::translate("robotInterface", "Calibration", 0, QApplication::UnicodeUTF8));
        label_Dimension_Z->setText(QApplication::translate("robotInterface", "Z", 0, QApplication::UnicodeUTF8));
        label_CurrenCollisionObject->setText(QApplication::translate("robotInterface", "Current Collision Object", 0, QApplication::UnicodeUTF8));
        label_Operation->setText(QApplication::translate("robotInterface", "Operation", 0, QApplication::UnicodeUTF8));
        label_Dimension_X_Radius->setText(QApplication::translate("robotInterface", "X / Radius", 0, QApplication::UnicodeUTF8));
        comboBox_Shape->clear();
        comboBox_Shape->insertItems(0, QStringList()
         << QApplication::translate("robotInterface", "Box", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "Sphere", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "Cylinder", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "Cone", 0, QApplication::UnicodeUTF8)
        );
        comboBox_Operation->clear();
        comboBox_Operation->insertItems(0, QStringList()
         << QApplication::translate("robotInterface", "Add", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "Remove", 0, QApplication::UnicodeUTF8)
        );
        pushButton_Do->setText(QApplication::translate("robotInterface", "Do", 0, QApplication::UnicodeUTF8));
        label_Dimension_Y_Height->setText(QApplication::translate("robotInterface", "Y / Height", 0, QApplication::UnicodeUTF8));
        label_CollisionID->setText(QApplication::translate("robotInterface", "Collision ID", 0, QApplication::UnicodeUTF8));
        label_Shape->setText(QApplication::translate("robotInterface", "Shape", 0, QApplication::UnicodeUTF8));
        label_CollisionObject->setText(QApplication::translate("robotInterface", "Collision Object", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Environment), QApplication::translate("robotInterface", "Environment", 0, QApplication::UnicodeUTF8));
        label_Joint2_4->setText(QApplication::translate("robotInterface", "Joint2", 0, QApplication::UnicodeUTF8));
        label_S->setText(QApplication::translate("robotInterface", "S", 0, QApplication::UnicodeUTF8));
        comboBox_style->clear();
        comboBox_style->insertItems(0, QStringList()
         << QApplication::translate("robotInterface", "PTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "LIN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "CIRC", 0, QApplication::UnicodeUTF8)
        );
        send_config_button->setText(QApplication::translate("robotInterface", "Config.", 0, QApplication::UnicodeUTF8));
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
        send_axis_button->setText(QApplication::translate("robotInterface", "To Axis", 0, QApplication::UnicodeUTF8));
        comboBox_approx->clear();
        comboBox_approx->insertItems(0, QStringList()
         << QApplication::translate("robotInterface", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "C_PTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "C_DIS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "C_VEL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("robotInterface", "C_ORI", 0, QApplication::UnicodeUTF8)
        );
        label_Position_2->setText(QApplication::translate("robotInterface", "Position", 0, QApplication::UnicodeUTF8));
        label_Approx->setText(QApplication::translate("robotInterface", "Approx.", 0, QApplication::UnicodeUTF8));
        terminate_imm_button->setText(QApplication::translate("robotInterface", "Term. Imm.", 0, QApplication::UnicodeUTF8));
        label_Joint_2->setText(QApplication::translate("robotInterface", "Joint", 0, QApplication::UnicodeUTF8));
        pause_buf_buton->setText(QApplication::translate("robotInterface", "Pause Buf.", 0, QApplication::UnicodeUTF8));
        label_Style->setText(QApplication::translate("robotInterface", "Style", 0, QApplication::UnicodeUTF8));
        label_Command->setText(QApplication::translate("robotInterface", "Command", 0, QApplication::UnicodeUTF8));
        label_TransX_4->setText(QApplication::translate("robotInterface", "TransX", 0, QApplication::UnicodeUTF8));
        convert_button->setText(QApplication::translate("robotInterface", "Convert", 0, QApplication::UnicodeUTF8));
        label_RotateA_4->setText(QApplication::translate("robotInterface", "RotateA", 0, QApplication::UnicodeUTF8));
        label_TransY_4->setText(QApplication::translate("robotInterface", "TransY", 0, QApplication::UnicodeUTF8));
        label_T->setText(QApplication::translate("robotInterface", "T", 0, QApplication::UnicodeUTF8));
        default_button->setText(QApplication::translate("robotInterface", "Default", 0, QApplication::UnicodeUTF8));
        labe_TransZ_4->setText(QApplication::translate("robotInterface", "TransZ", 0, QApplication::UnicodeUTF8));
        label_Config->setText(QApplication::translate("robotInterface", "Config.", 0, QApplication::UnicodeUTF8));
        label_RotateB_4->setText(QApplication::translate("robotInterface", "RotateB", 0, QApplication::UnicodeUTF8));
        label_RotateC_4->setText(QApplication::translate("robotInterface", "RotateC", 0, QApplication::UnicodeUTF8));
        debug_button->setText(QApplication::translate("robotInterface", "DEBUG", 0, QApplication::UnicodeUTF8));
        label_Joint1_4->setText(QApplication::translate("robotInterface", "Joint1", 0, QApplication::UnicodeUTF8));
        label_Joint3_4->setText(QApplication::translate("robotInterface", "Joint3", 0, QApplication::UnicodeUTF8));
        label_Joint4_4->setText(QApplication::translate("robotInterface", "Joint4", 0, QApplication::UnicodeUTF8));
        label_Joint5_4->setText(QApplication::translate("robotInterface", "Joint5", 0, QApplication::UnicodeUTF8));
        label_Joint6_4->setText(QApplication::translate("robotInterface", "Joint6", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_SingleCommand), QApplication::translate("robotInterface", "Single Command", 0, QApplication::UnicodeUTF8));
        label_Feedback->setText(QApplication::translate("robotInterface", "Feedback", 0, QApplication::UnicodeUTF8));
        label_Message->setText(QApplication::translate("robotInterface", "Message", 0, QApplication::UnicodeUTF8));
        label_Result->setText(QApplication::translate("robotInterface", "Result", 0, QApplication::UnicodeUTF8));
        label_Buffer->setText(QApplication::translate("robotInterface", "Buffer", 0, QApplication::UnicodeUTF8));
        label_Position->setText(QApplication::translate("robotInterface", "Position", 0, QApplication::UnicodeUTF8));
        label_No->setText(QApplication::translate("robotInterface", "No.", 0, QApplication::UnicodeUTF8));
        label_Joint->setText(QApplication::translate("robotInterface", "Joint", 0, QApplication::UnicodeUTF8));
        copy_button->setText(QApplication::translate("robotInterface", "Copy", 0, QApplication::UnicodeUTF8));
        pause_button->setText(QApplication::translate("robotInterface", "Pause", 0, QApplication::UnicodeUTF8));
        stop_button->setText(QApplication::translate("robotInterface", "Stop", 0, QApplication::UnicodeUTF8));
        terminate_buf_button->setText(QApplication::translate("robotInterface", "Term", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class robotInterface: public Ui_robotInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_H
