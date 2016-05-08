#ifndef UI_ROBOTINTERFACE_H
#define UI_ROBOTINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionCOM_Port_Settings;
    QAction *actionSROM_Image_File_Settings;
    QAction *actionInitialize_System;
    QAction *actionActivate_Handles;
    QAction *actionStart_Tracking;
    QAction *actionStop_Tracking;
    QAction *actionSystem_Properties;
    QAction *actionDiagnostic_Alerts;
    QAction *actionIlluminator_Activation_Rate;
    QAction *actionProgram_Options;
    QWidget *centralwidget;
    QTabWidget *tabWidget_Device;
    QWidget *tab;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_6;
    QTextEdit *output_result;
    QLabel *label_Feedback;
    QTextEdit *output_b;
    QTextEdit *output_a4;
    QLabel *label_Joint;
    QTextEdit *output_a2;
    QPushButton *pause_button;
    QLabel *label_Position;
    QTextEdit *output_a1;
    QTextEdit *output_a6;
    QTextEdit *output_buf_front;
    QTextEdit *output_y;
    QTextEdit *output_seq;
    QTextEdit *output_a5;
    QTextEdit *output_a;
    QLabel *label_Buffer;
    QTextEdit *output_buf_last;
    QTextEdit *output_s;
    QTextEdit *output_c;
    QTextEdit *output_a3;
    QTextEdit *output_t;
    QTextEdit *output_message;
    QLabel *label_Message;
    QPushButton *terminate_buf_button;
    QPushButton *copy_button;
    QTextEdit *output_z;
    QTextEdit *output_x;
    QLabel *label_Result;
    QLabel *label_No;
    QPushButton *stop_button;
    QTabWidget *tabWidget_Robot;
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
    QWidget *tab_NDICalibration;
    QGroupBox *groupBox_ReferencePoint;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_X;
    QLabel *label_Y;
    QLabel *label_Z;
    QLineEdit *lineEdit_NDI_X;
    QLineEdit *lineEdit_NDI_Z;
    QLineEdit *lineEdit_NDI_Y;
    QLabel *label_A;
    QLabel *label_B;
    QLabel *label_C;
    QLineEdit *lineEdit_KUKA_A;
    QLineEdit *lineEdit_KUKA_B;
    QLineEdit *lineEdit_KUKA_C;
    QPushButton *pushButton_CalculateRotationMatrix;
    QPushButton *pushButton_NeedleCalibration;
    QGroupBox *groupBox_ReferencePoint_2;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_dX;
    QLabel *label_dY;
    QLabel *label_dZ;
    QLineEdit *lineEdit_dX;
    QLineEdit *lineEdit_dY;
    QLineEdit *lineEdit_dZ;
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
    QLabel *label_RotateA_3;
    QLabel *label_TransY_4;
    QLabel *label_T;
    QPushButton *default_button;
    QLabel *labe_TransZ_2;
    QLabel *label_Config;
    QLabel *label_RotateB_3;
    QLabel *label_RotateC_3;
    QPushButton *debug_button;
    QLabel *label_Joint1_4;
    QLabel *label_Joint3_4;
    QLabel *label_Joint4_4;
    QLabel *label_Joint5_4;
    QLabel *label_Joint6_4;
    QWidget *tab_2;
    QGroupBox *groupBox_ToolProperties;
    QWidget *gridLayoutWidget_11;
    QGridLayout *gridLayout_11;
    QLabel *label_ToolType;
    QCheckBox *checkBox_HandleInitialize;
    QLineEdit *lineEdit_Tool;
    QComboBox *comboBox_Port;
    QLineEdit *lineEdit_Manufacturer;
    QLabel *label_Manufacturer;
    QLineEdit *lineEdit_Part;
    QLabel *label_Part;
    QLabel *label_Port;
    QCheckBox *checkBox_HandleEnable;
    QLabel *label_Serial;
    QLabel *label_ToolRev;
    QLabel *label_Reference;
    QLineEdit *lineEdit_Serial;
    QLineEdit *lineEdit_Tool_2;
    QComboBox *comboBox_Reference;
    QGroupBox *groupBox_System;
    QWidget *gridLayoutWidget_12;
    QGridLayout *gridLayout_12;
    QPushButton *pushButton_ActiveHandles;
    QPushButton *pushButton_InitializeSystem;
    QPushButton *pushButton_ResetSystem;
    QPushButton *pushButton_StartTracking;
    QGroupBox *groupBox_TrackingInformation;
    QWidget *gridLayoutWidget_13;
    QGridLayout *gridLayout_13;
    QComboBox *comboBox_Handle;
    QLabel *label_Tz;
    QLabel *label_Qx;
    QLabel *label_Qo;
    QLabel *label_Error;
    QLabel *label_Qz;
    QLabel *label_Tx;
    QLabel *label_Handle;
    QLabel *label_Ty;
    QLabel *label_Status;
    QLabel *label_Qy;
    QLineEdit *lineEdit_Tx;
    QLineEdit *lineEdit_Ty;
    QLineEdit *lineEdit_Tz;
    QLineEdit *lineEdit_Qo;
    QLineEdit *lineEdit_Qx;
    QLineEdit *lineEdit_Qy;
    QLineEdit *lineEdit_Qz;
    QLineEdit *lineEdit_Error;
    QLineEdit *lineEdit_Status;
    QGroupBox *groupBox_TrackingMode;
    QWidget *gridLayoutWidget_14;
    QGridLayout *gridLayout_14;
    QRadioButton *radioButton_BXMode;
    QRadioButton *radioButton_TXMode;
    QCheckBox *checkBox_0x0800;
    QGroupBox *groupBox_SystemInformation;
    QWidget *gridLayoutWidget_16;
    QGridLayout *gridLayout_16;
    QLineEdit *lineEdit_Frame;
    QLabel *label_Frame;
    QGroupBox *groupBox_StatusLegend;
    QWidget *gridLayoutWidget_17;
    QGridLayout *gridLayout_17;
    QLabel *label_Mode;
    QLineEdit *lineEdit_Mode;
    QLabel *label_OOV;
    QLabel *label_POOV;
    QLabel *label_OK;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuSystem;
    QMenu *menuView;
    QMenu *menuOptions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1002, 610);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCOM_Port_Settings = new QAction(MainWindow);
        actionCOM_Port_Settings->setObjectName(QString::fromUtf8("actionCOM_Port_Settings"));
        actionSROM_Image_File_Settings = new QAction(MainWindow);
        actionSROM_Image_File_Settings->setObjectName(QString::fromUtf8("actionSROM_Image_File_Settings"));
        actionInitialize_System = new QAction(MainWindow);
        actionInitialize_System->setObjectName(QString::fromUtf8("actionInitialize_System"));
        actionActivate_Handles = new QAction(MainWindow);
        actionActivate_Handles->setObjectName(QString::fromUtf8("actionActivate_Handles"));
        actionStart_Tracking = new QAction(MainWindow);
        actionStart_Tracking->setObjectName(QString::fromUtf8("actionStart_Tracking"));
        actionStop_Tracking = new QAction(MainWindow);
        actionStop_Tracking->setObjectName(QString::fromUtf8("actionStop_Tracking"));
        actionSystem_Properties = new QAction(MainWindow);
        actionSystem_Properties->setObjectName(QString::fromUtf8("actionSystem_Properties"));
        actionDiagnostic_Alerts = new QAction(MainWindow);
        actionDiagnostic_Alerts->setObjectName(QString::fromUtf8("actionDiagnostic_Alerts"));
        actionIlluminator_Activation_Rate = new QAction(MainWindow);
        actionIlluminator_Activation_Rate->setObjectName(QString::fromUtf8("actionIlluminator_Activation_Rate"));
        actionProgram_Options = new QAction(MainWindow);
        actionProgram_Options->setObjectName(QString::fromUtf8("actionProgram_Options"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget_Device = new QTabWidget(centralwidget);
        tabWidget_Device->setObjectName(QString::fromUtf8("tabWidget_Device"));
        tabWidget_Device->setGeometry(QRect(0, 0, 1001, 561));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget_3 = new QWidget(tab);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(20, 370, 781, 151));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        output_result = new QTextEdit(gridLayoutWidget_3);
        output_result->setObjectName(QString::fromUtf8("output_result"));
        output_result->setMinimumSize(QSize(84, 30));
        output_result->setMaximumSize(QSize(84, 30));
        output_result->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_result->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_result->setTabChangesFocus(true);
        output_result->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_result, 3, 5, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_Feedback = new QLabel(gridLayoutWidget_3);
        label_Feedback->setObjectName(QString::fromUtf8("label_Feedback"));
        label_Feedback->setMinimumSize(QSize(146, 40));
        label_Feedback->setMaximumSize(QSize(146, 40));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_Feedback->setFont(font);

        gridLayout_6->addWidget(label_Feedback, 0, 0, 1, 2);

        output_b = new QTextEdit(gridLayoutWidget_3);
        output_b->setObjectName(QString::fromUtf8("output_b"));
        output_b->setMinimumSize(QSize(84, 30));
        output_b->setMaximumSize(QSize(84, 30));
        output_b->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_b->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_b->setTabChangesFocus(true);
        output_b->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_b, 1, 5, 1, 1);

        output_a4 = new QTextEdit(gridLayoutWidget_3);
        output_a4->setObjectName(QString::fromUtf8("output_a4"));
        output_a4->setMinimumSize(QSize(83, 30));
        output_a4->setMaximumSize(QSize(83, 30));
        output_a4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a4->setTabChangesFocus(true);
        output_a4->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a4, 2, 4, 1, 1);

        label_Joint = new QLabel(gridLayoutWidget_3);
        label_Joint->setObjectName(QString::fromUtf8("label_Joint"));
        label_Joint->setMinimumSize(QSize(60, 27));
        label_Joint->setMaximumSize(QSize(60, 27));

        gridLayout_6->addWidget(label_Joint, 2, 0, 1, 1);

        output_a2 = new QTextEdit(gridLayoutWidget_3);
        output_a2->setObjectName(QString::fromUtf8("output_a2"));
        output_a2->setMinimumSize(QSize(84, 30));
        output_a2->setMaximumSize(QSize(84, 30));
        output_a2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a2->setTabChangesFocus(true);
        output_a2->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a2, 2, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        pause_button = new QPushButton(gridLayoutWidget_3);
        pause_button->setObjectName(QString::fromUtf8("pause_button"));
        pause_button->setMinimumSize(QSize(80, 27));
        pause_button->setMaximumSize(QSize(80, 27));

        gridLayout_6->addWidget(pause_button, 0, 3, 1, 1);

        label_Position = new QLabel(gridLayoutWidget_3);
        label_Position->setObjectName(QString::fromUtf8("label_Position"));
        label_Position->setMinimumSize(QSize(60, 27));
        label_Position->setMaximumSize(QSize(60, 27));

        gridLayout_6->addWidget(label_Position, 1, 0, 1, 1);

        output_a1 = new QTextEdit(gridLayoutWidget_3);
        output_a1->setObjectName(QString::fromUtf8("output_a1"));
        output_a1->setMinimumSize(QSize(84, 30));
        output_a1->setMaximumSize(QSize(84, 30));
        output_a1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a1->setTabChangesFocus(true);
        output_a1->setLineWrapMode(QTextEdit::NoWrap);
        output_a1->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a1, 2, 1, 1, 1);

        output_a6 = new QTextEdit(gridLayoutWidget_3);
        output_a6->setObjectName(QString::fromUtf8("output_a6"));
        output_a6->setMinimumSize(QSize(84, 30));
        output_a6->setMaximumSize(QSize(84, 30));
        output_a6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a6->setTabChangesFocus(true);
        output_a6->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a6, 2, 6, 1, 1);

        output_buf_front = new QTextEdit(gridLayoutWidget_3);
        output_buf_front->setObjectName(QString::fromUtf8("output_buf_front"));
        output_buf_front->setMinimumSize(QSize(84, 30));
        output_buf_front->setMaximumSize(QSize(84, 30));
        output_buf_front->setTabChangesFocus(true);
        output_buf_front->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_buf_front, 3, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        output_y = new QTextEdit(gridLayoutWidget_3);
        output_y->setObjectName(QString::fromUtf8("output_y"));
        output_y->setMinimumSize(QSize(84, 30));
        output_y->setMaximumSize(QSize(84, 30));
        output_y->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_y->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_y->setTabChangesFocus(true);
        output_y->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_y, 1, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        output_seq = new QTextEdit(gridLayoutWidget_3);
        output_seq->setObjectName(QString::fromUtf8("output_seq"));
        output_seq->setMinimumSize(QSize(174, 31));
        output_seq->setMaximumSize(QSize(174, 40));
        output_seq->setTabChangesFocus(true);
        output_seq->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_seq, 0, 7, 1, 2);

        output_a5 = new QTextEdit(gridLayoutWidget_3);
        output_a5->setObjectName(QString::fromUtf8("output_a5"));
        output_a5->setMinimumSize(QSize(84, 30));
        output_a5->setMaximumSize(QSize(84, 30));
        output_a5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a5->setTabChangesFocus(true);
        output_a5->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a5, 2, 5, 1, 1);

        output_a = new QTextEdit(gridLayoutWidget_3);
        output_a->setObjectName(QString::fromUtf8("output_a"));
        output_a->setMinimumSize(QSize(83, 30));
        output_a->setMaximumSize(QSize(83, 30));
        output_a->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a->setTabChangesFocus(true);
        output_a->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a, 1, 4, 1, 1);

        label_Buffer = new QLabel(gridLayoutWidget_3);
        label_Buffer->setObjectName(QString::fromUtf8("label_Buffer"));
        label_Buffer->setMinimumSize(QSize(60, 27));
        label_Buffer->setMaximumSize(QSize(60, 27));

        gridLayout_6->addWidget(label_Buffer, 3, 1, 1, 1);

        output_buf_last = new QTextEdit(gridLayoutWidget_3);
        output_buf_last->setObjectName(QString::fromUtf8("output_buf_last"));
        output_buf_last->setMinimumSize(QSize(84, 30));
        output_buf_last->setMaximumSize(QSize(84, 30));
        output_buf_last->setTabChangesFocus(true);
        output_buf_last->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_buf_last, 3, 3, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        output_s = new QTextEdit(gridLayoutWidget_3);
        output_s->setObjectName(QString::fromUtf8("output_s"));
        output_s->setMinimumSize(QSize(84, 30));
        output_s->setMaximumSize(QSize(84, 30));
        output_s->setTabChangesFocus(true);
        output_s->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_s, 1, 7, 1, 1);

        output_c = new QTextEdit(gridLayoutWidget_3);
        output_c->setObjectName(QString::fromUtf8("output_c"));
        output_c->setMinimumSize(QSize(84, 30));
        output_c->setMaximumSize(QSize(84, 30));
        output_c->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_c->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_c->setTabChangesFocus(true);
        output_c->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_c, 1, 6, 1, 1);

        output_a3 = new QTextEdit(gridLayoutWidget_3);
        output_a3->setObjectName(QString::fromUtf8("output_a3"));
        output_a3->setMinimumSize(QSize(84, 30));
        output_a3->setMaximumSize(QSize(84, 30));
        output_a3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_a3->setTabChangesFocus(true);
        output_a3->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_a3, 2, 3, 1, 1);

        output_t = new QTextEdit(gridLayoutWidget_3);
        output_t->setObjectName(QString::fromUtf8("output_t"));
        output_t->setMinimumSize(QSize(84, 30));
        output_t->setMaximumSize(QSize(84, 30));
        output_t->setTabChangesFocus(true);
        output_t->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_t, 1, 8, 1, 1);

        output_message = new QTextEdit(gridLayoutWidget_3);
        output_message->setObjectName(QString::fromUtf8("output_message"));
        output_message->setMinimumSize(QSize(174, 30));
        output_message->setMaximumSize(QSize(174, 30));
        output_message->setTabChangesFocus(true);
        output_message->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_message, 3, 7, 1, 2);

        label_Message = new QLabel(gridLayoutWidget_3);
        label_Message->setObjectName(QString::fromUtf8("label_Message"));
        label_Message->setMinimumSize(QSize(70, 27));
        label_Message->setMaximumSize(QSize(70, 27));

        gridLayout_6->addWidget(label_Message, 3, 6, 1, 1);

        terminate_buf_button = new QPushButton(gridLayoutWidget_3);
        terminate_buf_button->setObjectName(QString::fromUtf8("terminate_buf_button"));
        terminate_buf_button->setMinimumSize(QSize(81, 27));
        terminate_buf_button->setMaximumSize(QSize(81, 27));

        gridLayout_6->addWidget(terminate_buf_button, 0, 5, 1, 1);

        copy_button = new QPushButton(gridLayoutWidget_3);
        copy_button->setObjectName(QString::fromUtf8("copy_button"));
        copy_button->setMinimumSize(QSize(81, 27));
        copy_button->setMaximumSize(QSize(81, 27));

        gridLayout_6->addWidget(copy_button, 0, 2, 1, 1);

        output_z = new QTextEdit(gridLayoutWidget_3);
        output_z->setObjectName(QString::fromUtf8("output_z"));
        output_z->setMinimumSize(QSize(84, 30));
        output_z->setMaximumSize(QSize(84, 30));
        output_z->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_z->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_z->setTabChangesFocus(true);
        output_z->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_z, 1, 3, 1, 1);

        output_x = new QTextEdit(gridLayoutWidget_3);
        output_x->setObjectName(QString::fromUtf8("output_x"));
        output_x->setMinimumSize(QSize(84, 30));
        output_x->setMaximumSize(QSize(84, 30));
        output_x->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_x->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        output_x->setTabChangesFocus(true);
        output_x->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(output_x, 1, 1, 1, 1);

        label_Result = new QLabel(gridLayoutWidget_3);
        label_Result->setObjectName(QString::fromUtf8("label_Result"));
        label_Result->setMinimumSize(QSize(60, 27));
        label_Result->setMaximumSize(QSize(60, 27));

        gridLayout_6->addWidget(label_Result, 3, 4, 1, 1);

        label_No = new QLabel(gridLayoutWidget_3);
        label_No->setObjectName(QString::fromUtf8("label_No"));
        label_No->setMinimumSize(QSize(30, 27));
        label_No->setMaximumSize(QSize(30, 27));

        gridLayout_6->addWidget(label_No, 0, 6, 1, 1);

        stop_button = new QPushButton(gridLayoutWidget_3);
        stop_button->setObjectName(QString::fromUtf8("stop_button"));
        stop_button->setMinimumSize(QSize(81, 27));
        stop_button->setMaximumSize(QSize(81, 27));

        gridLayout_6->addWidget(stop_button, 0, 4, 1, 1);

        tabWidget_Robot = new QTabWidget(tab);
        tabWidget_Robot->setObjectName(QString::fromUtf8("tabWidget_Robot"));
        tabWidget_Robot->setGeometry(QRect(20, 0, 791, 371));
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
        pushButton_ExecutePlan->setEnabled(false);
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
        pushButton_ExecuteWaypointsPlan->setEnabled(false);
        pushButton_ExecuteWaypointsPlan->setMaximumSize(QSize(217, 27));

        gridLayout->addWidget(pushButton_ExecuteWaypointsPlan, 8, 1, 1, 1);

        label_Target = new QLabel(gridLayoutWidget_2);
        label_Target->setObjectName(QString::fromUtf8("label_Target"));
        label_Target->setMaximumSize(QSize(111, 41));
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

        tabWidget_Robot->addTab(tab_PathPlanning, QString());
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
        pushButton_ExecuteRotatePlan->setEnabled(false);

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

        tabWidget_Robot->addTab(tab_Calibration, QString());
        tab_NDICalibration = new QWidget();
        tab_NDICalibration->setObjectName(QString::fromUtf8("tab_NDICalibration"));
        groupBox_ReferencePoint = new QGroupBox(tab_NDICalibration);
        groupBox_ReferencePoint->setObjectName(QString::fromUtf8("groupBox_ReferencePoint"));
        groupBox_ReferencePoint->setGeometry(QRect(10, 170, 411, 141));
        gridLayoutWidget_4 = new QWidget(groupBox_ReferencePoint);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 30, 251, 101));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_X = new QLabel(gridLayoutWidget_4);
        label_X->setObjectName(QString::fromUtf8("label_X"));

        gridLayout_4->addWidget(label_X, 0, 0, 1, 1);

        label_Y = new QLabel(gridLayoutWidget_4);
        label_Y->setObjectName(QString::fromUtf8("label_Y"));

        gridLayout_4->addWidget(label_Y, 0, 1, 1, 1);

        label_Z = new QLabel(gridLayoutWidget_4);
        label_Z->setObjectName(QString::fromUtf8("label_Z"));

        gridLayout_4->addWidget(label_Z, 0, 2, 1, 1);

        lineEdit_NDI_X = new QLineEdit(gridLayoutWidget_4);
        lineEdit_NDI_X->setObjectName(QString::fromUtf8("lineEdit_NDI_X"));

        gridLayout_4->addWidget(lineEdit_NDI_X, 1, 0, 1, 1);

        lineEdit_NDI_Z = new QLineEdit(gridLayoutWidget_4);
        lineEdit_NDI_Z->setObjectName(QString::fromUtf8("lineEdit_NDI_Z"));

        gridLayout_4->addWidget(lineEdit_NDI_Z, 1, 2, 1, 1);

        lineEdit_NDI_Y = new QLineEdit(gridLayoutWidget_4);
        lineEdit_NDI_Y->setObjectName(QString::fromUtf8("lineEdit_NDI_Y"));

        gridLayout_4->addWidget(lineEdit_NDI_Y, 1, 1, 1, 1);

        label_A = new QLabel(gridLayoutWidget_4);
        label_A->setObjectName(QString::fromUtf8("label_A"));

        gridLayout_4->addWidget(label_A, 2, 0, 1, 1);

        label_B = new QLabel(gridLayoutWidget_4);
        label_B->setObjectName(QString::fromUtf8("label_B"));

        gridLayout_4->addWidget(label_B, 2, 1, 1, 1);

        label_C = new QLabel(gridLayoutWidget_4);
        label_C->setObjectName(QString::fromUtf8("label_C"));

        gridLayout_4->addWidget(label_C, 2, 2, 1, 1);

        lineEdit_KUKA_A = new QLineEdit(gridLayoutWidget_4);
        lineEdit_KUKA_A->setObjectName(QString::fromUtf8("lineEdit_KUKA_A"));

        gridLayout_4->addWidget(lineEdit_KUKA_A, 3, 0, 1, 1);

        lineEdit_KUKA_B = new QLineEdit(gridLayoutWidget_4);
        lineEdit_KUKA_B->setObjectName(QString::fromUtf8("lineEdit_KUKA_B"));

        gridLayout_4->addWidget(lineEdit_KUKA_B, 3, 1, 1, 1);

        lineEdit_KUKA_C = new QLineEdit(gridLayoutWidget_4);
        lineEdit_KUKA_C->setObjectName(QString::fromUtf8("lineEdit_KUKA_C"));

        gridLayout_4->addWidget(lineEdit_KUKA_C, 3, 2, 1, 1);

        pushButton_CalculateRotationMatrix = new QPushButton(tab_NDICalibration);
        pushButton_CalculateRotationMatrix->setObjectName(QString::fromUtf8("pushButton_CalculateRotationMatrix"));
        pushButton_CalculateRotationMatrix->setGeometry(QRect(470, 70, 95, 24));
        pushButton_NeedleCalibration = new QPushButton(tab_NDICalibration);
        pushButton_NeedleCalibration->setObjectName(QString::fromUtf8("pushButton_NeedleCalibration"));
        pushButton_NeedleCalibration->setGeometry(QRect(470, 110, 95, 24));
        groupBox_ReferencePoint_2 = new QGroupBox(tab_NDICalibration);
        groupBox_ReferencePoint_2->setObjectName(QString::fromUtf8("groupBox_ReferencePoint_2"));
        groupBox_ReferencePoint_2->setGeometry(QRect(10, 50, 271, 91));
        gridLayoutWidget_5 = new QWidget(groupBox_ReferencePoint_2);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 30, 251, 51));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_dX = new QLabel(gridLayoutWidget_5);
        label_dX->setObjectName(QString::fromUtf8("label_dX"));

        gridLayout_5->addWidget(label_dX, 0, 0, 1, 1);

        label_dY = new QLabel(gridLayoutWidget_5);
        label_dY->setObjectName(QString::fromUtf8("label_dY"));

        gridLayout_5->addWidget(label_dY, 0, 1, 1, 1);

        label_dZ = new QLabel(gridLayoutWidget_5);
        label_dZ->setObjectName(QString::fromUtf8("label_dZ"));

        gridLayout_5->addWidget(label_dZ, 0, 2, 1, 1);

        lineEdit_dX = new QLineEdit(gridLayoutWidget_5);
        lineEdit_dX->setObjectName(QString::fromUtf8("lineEdit_dX"));

        gridLayout_5->addWidget(lineEdit_dX, 1, 0, 1, 1);

        lineEdit_dY = new QLineEdit(gridLayoutWidget_5);
        lineEdit_dY->setObjectName(QString::fromUtf8("lineEdit_dY"));

        gridLayout_5->addWidget(lineEdit_dY, 1, 1, 1, 1);

        lineEdit_dZ = new QLineEdit(gridLayoutWidget_5);
        lineEdit_dZ->setObjectName(QString::fromUtf8("lineEdit_dZ"));

        gridLayout_5->addWidget(lineEdit_dZ, 1, 2, 1, 1);

        tabWidget_Robot->addTab(tab_NDICalibration, QString());
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

        tabWidget_Robot->addTab(tab_Environment, QString());
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
        input_s->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_s->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
        input_t->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        input_t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_3->addWidget(input_t, 2, 9, 1, 1);

        convert_button = new QPushButton(gridLayoutWidget);
        convert_button->setObjectName(QString::fromUtf8("convert_button"));
        convert_button->setMinimumSize(QSize(62, 25));
        convert_button->setMaximumSize(QSize(62, 25));

        gridLayout_3->addWidget(convert_button, 4, 10, 1, 1);

        label_RotateA_3 = new QLabel(gridLayoutWidget);
        label_RotateA_3->setObjectName(QString::fromUtf8("label_RotateA_3"));
        label_RotateA_3->setMinimumSize(QSize(80, 23));
        label_RotateA_3->setMaximumSize(QSize(80, 23));

        gridLayout_3->addWidget(label_RotateA_3, 1, 5, 1, 1);

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

        labe_TransZ_2 = new QLabel(gridLayoutWidget);
        labe_TransZ_2->setObjectName(QString::fromUtf8("labe_TransZ_2"));
        labe_TransZ_2->setMinimumSize(QSize(80, 23));
        labe_TransZ_2->setMaximumSize(QSize(80, 23));

        gridLayout_3->addWidget(labe_TransZ_2, 1, 4, 1, 1);

        label_Config = new QLabel(gridLayoutWidget);
        label_Config->setObjectName(QString::fromUtf8("label_Config"));
        label_Config->setMinimumSize(QSize(60, 27));
        label_Config->setMaximumSize(QSize(60, 27));

        gridLayout_3->addWidget(label_Config, 6, 0, 1, 1);

        label_RotateB_3 = new QLabel(gridLayoutWidget);
        label_RotateB_3->setObjectName(QString::fromUtf8("label_RotateB_3"));
        label_RotateB_3->setMinimumSize(QSize(80, 23));
        label_RotateB_3->setMaximumSize(QSize(80, 23));

        gridLayout_3->addWidget(label_RotateB_3, 1, 6, 1, 1);

        label_RotateC_3 = new QLabel(gridLayoutWidget);
        label_RotateC_3->setObjectName(QString::fromUtf8("label_RotateC_3"));
        label_RotateC_3->setMinimumSize(QSize(80, 23));
        label_RotateC_3->setMaximumSize(QSize(80, 23));

        gridLayout_3->addWidget(label_RotateC_3, 1, 7, 1, 1);

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

        tabWidget_Robot->addTab(tab_SingleCommand, QString());
        tabWidget_Device->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_ToolProperties = new QGroupBox(tab_2);
        groupBox_ToolProperties->setObjectName(QString::fromUtf8("groupBox_ToolProperties"));
        groupBox_ToolProperties->setGeometry(QRect(20, 0, 701, 171));
        gridLayoutWidget_11 = new QWidget(groupBox_ToolProperties);
        gridLayoutWidget_11->setObjectName(QString::fromUtf8("gridLayoutWidget_11"));
        gridLayoutWidget_11->setGeometry(QRect(0, 30, 701, 141));
        gridLayout_11 = new QGridLayout(gridLayoutWidget_11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        label_ToolType = new QLabel(gridLayoutWidget_11);
        label_ToolType->setObjectName(QString::fromUtf8("label_ToolType"));

        gridLayout_11->addWidget(label_ToolType, 1, 0, 1, 1);

        checkBox_HandleInitialize = new QCheckBox(gridLayoutWidget_11);
        checkBox_HandleInitialize->setObjectName(QString::fromUtf8("checkBox_HandleInitialize"));
        checkBox_HandleInitialize->setCheckable(false);

        gridLayout_11->addWidget(checkBox_HandleInitialize, 0, 2, 1, 1);

        lineEdit_Tool = new QLineEdit(gridLayoutWidget_11);
        lineEdit_Tool->setObjectName(QString::fromUtf8("lineEdit_Tool"));
        lineEdit_Tool->setReadOnly(true);

        gridLayout_11->addWidget(lineEdit_Tool, 1, 1, 1, 1);

        comboBox_Port = new QComboBox(gridLayoutWidget_11);
        comboBox_Port->setObjectName(QString::fromUtf8("comboBox_Port"));

        gridLayout_11->addWidget(comboBox_Port, 0, 1, 1, 1);

        lineEdit_Manufacturer = new QLineEdit(gridLayoutWidget_11);
        lineEdit_Manufacturer->setObjectName(QString::fromUtf8("lineEdit_Manufacturer"));
        lineEdit_Manufacturer->setReadOnly(true);

        gridLayout_11->addWidget(lineEdit_Manufacturer, 2, 1, 1, 1);

        label_Manufacturer = new QLabel(gridLayoutWidget_11);
        label_Manufacturer->setObjectName(QString::fromUtf8("label_Manufacturer"));

        gridLayout_11->addWidget(label_Manufacturer, 2, 0, 1, 1);

        lineEdit_Part = new QLineEdit(gridLayoutWidget_11);
        lineEdit_Part->setObjectName(QString::fromUtf8("lineEdit_Part"));
        lineEdit_Part->setReadOnly(true);

        gridLayout_11->addWidget(lineEdit_Part, 3, 1, 1, 1);

        label_Part = new QLabel(gridLayoutWidget_11);
        label_Part->setObjectName(QString::fromUtf8("label_Part"));

        gridLayout_11->addWidget(label_Part, 3, 0, 1, 1);

        label_Port = new QLabel(gridLayoutWidget_11);
        label_Port->setObjectName(QString::fromUtf8("label_Port"));

        gridLayout_11->addWidget(label_Port, 0, 0, 1, 1);

        checkBox_HandleEnable = new QCheckBox(gridLayoutWidget_11);
        checkBox_HandleEnable->setObjectName(QString::fromUtf8("checkBox_HandleEnable"));

        gridLayout_11->addWidget(checkBox_HandleEnable, 0, 3, 1, 1);

        label_Serial = new QLabel(gridLayoutWidget_11);
        label_Serial->setObjectName(QString::fromUtf8("label_Serial"));

        gridLayout_11->addWidget(label_Serial, 1, 2, 1, 1);

        label_ToolRev = new QLabel(gridLayoutWidget_11);
        label_ToolRev->setObjectName(QString::fromUtf8("label_ToolRev"));

        gridLayout_11->addWidget(label_ToolRev, 2, 2, 1, 1);

        label_Reference = new QLabel(gridLayoutWidget_11);
        label_Reference->setObjectName(QString::fromUtf8("label_Reference"));

        gridLayout_11->addWidget(label_Reference, 3, 2, 1, 1);

        lineEdit_Serial = new QLineEdit(gridLayoutWidget_11);
        lineEdit_Serial->setObjectName(QString::fromUtf8("lineEdit_Serial"));
        lineEdit_Serial->setReadOnly(true);

        gridLayout_11->addWidget(lineEdit_Serial, 1, 3, 1, 1);

        lineEdit_Tool_2 = new QLineEdit(gridLayoutWidget_11);
        lineEdit_Tool_2->setObjectName(QString::fromUtf8("lineEdit_Tool_2"));
        lineEdit_Tool_2->setReadOnly(true);

        gridLayout_11->addWidget(lineEdit_Tool_2, 2, 3, 1, 1);

        comboBox_Reference = new QComboBox(gridLayoutWidget_11);
        comboBox_Reference->setObjectName(QString::fromUtf8("comboBox_Reference"));

        gridLayout_11->addWidget(comboBox_Reference, 3, 3, 1, 1);

        groupBox_System = new QGroupBox(tab_2);
        groupBox_System->setObjectName(QString::fromUtf8("groupBox_System"));
        groupBox_System->setGeometry(QRect(740, 0, 241, 171));
        gridLayoutWidget_12 = new QWidget(groupBox_System);
        gridLayoutWidget_12->setObjectName(QString::fromUtf8("gridLayoutWidget_12"));
        gridLayoutWidget_12->setGeometry(QRect(0, 30, 241, 141));
        gridLayout_12 = new QGridLayout(gridLayoutWidget_12);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        pushButton_ActiveHandles = new QPushButton(gridLayoutWidget_12);
        pushButton_ActiveHandles->setObjectName(QString::fromUtf8("pushButton_ActiveHandles"));

        gridLayout_12->addWidget(pushButton_ActiveHandles, 2, 0, 1, 1);

        pushButton_InitializeSystem = new QPushButton(gridLayoutWidget_12);
        pushButton_InitializeSystem->setObjectName(QString::fromUtf8("pushButton_InitializeSystem"));

        gridLayout_12->addWidget(pushButton_InitializeSystem, 1, 0, 1, 1);

        pushButton_ResetSystem = new QPushButton(gridLayoutWidget_12);
        pushButton_ResetSystem->setObjectName(QString::fromUtf8("pushButton_ResetSystem"));

        gridLayout_12->addWidget(pushButton_ResetSystem, 0, 0, 1, 1);

        pushButton_StartTracking = new QPushButton(gridLayoutWidget_12);
        pushButton_StartTracking->setObjectName(QString::fromUtf8("pushButton_StartTracking"));

        gridLayout_12->addWidget(pushButton_StartTracking, 3, 0, 1, 1);

        groupBox_TrackingInformation = new QGroupBox(tab_2);
        groupBox_TrackingInformation->setObjectName(QString::fromUtf8("groupBox_TrackingInformation"));
        groupBox_TrackingInformation->setGeometry(QRect(20, 180, 961, 271));
        gridLayoutWidget_13 = new QWidget(groupBox_TrackingInformation);
        gridLayoutWidget_13->setObjectName(QString::fromUtf8("gridLayoutWidget_13"));
        gridLayoutWidget_13->setGeometry(QRect(0, 30, 961, 91));
        gridLayout_13 = new QGridLayout(gridLayoutWidget_13);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        comboBox_Handle = new QComboBox(gridLayoutWidget_13);
        comboBox_Handle->setObjectName(QString::fromUtf8("comboBox_Handle"));

        gridLayout_13->addWidget(comboBox_Handle, 0, 1, 1, 1);

        label_Tz = new QLabel(gridLayoutWidget_13);
        label_Tz->setObjectName(QString::fromUtf8("label_Tz"));

        gridLayout_13->addWidget(label_Tz, 1, 2, 1, 1);

        label_Qx = new QLabel(gridLayoutWidget_13);
        label_Qx->setObjectName(QString::fromUtf8("label_Qx"));

        gridLayout_13->addWidget(label_Qx, 1, 4, 1, 1);

        label_Qo = new QLabel(gridLayoutWidget_13);
        label_Qo->setObjectName(QString::fromUtf8("label_Qo"));

        gridLayout_13->addWidget(label_Qo, 1, 3, 1, 1);

        label_Error = new QLabel(gridLayoutWidget_13);
        label_Error->setObjectName(QString::fromUtf8("label_Error"));

        gridLayout_13->addWidget(label_Error, 1, 7, 1, 1);

        label_Qz = new QLabel(gridLayoutWidget_13);
        label_Qz->setObjectName(QString::fromUtf8("label_Qz"));

        gridLayout_13->addWidget(label_Qz, 1, 6, 1, 1);

        label_Tx = new QLabel(gridLayoutWidget_13);
        label_Tx->setObjectName(QString::fromUtf8("label_Tx"));

        gridLayout_13->addWidget(label_Tx, 1, 0, 1, 1);

        label_Handle = new QLabel(gridLayoutWidget_13);
        label_Handle->setObjectName(QString::fromUtf8("label_Handle"));

        gridLayout_13->addWidget(label_Handle, 0, 0, 1, 1);

        label_Ty = new QLabel(gridLayoutWidget_13);
        label_Ty->setObjectName(QString::fromUtf8("label_Ty"));

        gridLayout_13->addWidget(label_Ty, 1, 1, 1, 1);

        label_Status = new QLabel(gridLayoutWidget_13);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));

        gridLayout_13->addWidget(label_Status, 1, 8, 1, 1);

        label_Qy = new QLabel(gridLayoutWidget_13);
        label_Qy->setObjectName(QString::fromUtf8("label_Qy"));

        gridLayout_13->addWidget(label_Qy, 1, 5, 1, 1);

        lineEdit_Tx = new QLineEdit(gridLayoutWidget_13);
        lineEdit_Tx->setObjectName(QString::fromUtf8("lineEdit_Tx"));
        lineEdit_Tx->setReadOnly(true);

        gridLayout_13->addWidget(lineEdit_Tx, 2, 0, 1, 1);

        lineEdit_Ty = new QLineEdit(gridLayoutWidget_13);
        lineEdit_Ty->setObjectName(QString::fromUtf8("lineEdit_Ty"));
        lineEdit_Ty->setReadOnly(true);

        gridLayout_13->addWidget(lineEdit_Ty, 2, 1, 1, 1);

        lineEdit_Tz = new QLineEdit(gridLayoutWidget_13);
        lineEdit_Tz->setObjectName(QString::fromUtf8("lineEdit_Tz"));
        lineEdit_Tz->setReadOnly(true);

        gridLayout_13->addWidget(lineEdit_Tz, 2, 2, 1, 1);

        lineEdit_Qo = new QLineEdit(gridLayoutWidget_13);
        lineEdit_Qo->setObjectName(QString::fromUtf8("lineEdit_Qo"));
        lineEdit_Qo->setReadOnly(true);

        gridLayout_13->addWidget(lineEdit_Qo, 2, 3, 1, 1);

        lineEdit_Qx = new QLineEdit(gridLayoutWidget_13);
        lineEdit_Qx->setObjectName(QString::fromUtf8("lineEdit_Qx"));
        lineEdit_Qx->setReadOnly(true);

        gridLayout_13->addWidget(lineEdit_Qx, 2, 4, 1, 1);

        lineEdit_Qy = new QLineEdit(gridLayoutWidget_13);
        lineEdit_Qy->setObjectName(QString::fromUtf8("lineEdit_Qy"));
        lineEdit_Qy->setReadOnly(true);

        gridLayout_13->addWidget(lineEdit_Qy, 2, 5, 1, 1);

        lineEdit_Qz = new QLineEdit(gridLayoutWidget_13);
        lineEdit_Qz->setObjectName(QString::fromUtf8("lineEdit_Qz"));
        lineEdit_Qz->setReadOnly(true);

        gridLayout_13->addWidget(lineEdit_Qz, 2, 6, 1, 1);

        lineEdit_Error = new QLineEdit(gridLayoutWidget_13);
        lineEdit_Error->setObjectName(QString::fromUtf8("lineEdit_Error"));
        lineEdit_Error->setReadOnly(true);

        gridLayout_13->addWidget(lineEdit_Error, 2, 7, 1, 1);

        lineEdit_Status = new QLineEdit(gridLayoutWidget_13);
        lineEdit_Status->setObjectName(QString::fromUtf8("lineEdit_Status"));
        lineEdit_Status->setReadOnly(true);

        gridLayout_13->addWidget(lineEdit_Status, 2, 8, 1, 1);

        groupBox_TrackingMode = new QGroupBox(groupBox_TrackingInformation);
        groupBox_TrackingMode->setObjectName(QString::fromUtf8("groupBox_TrackingMode"));
        groupBox_TrackingMode->setGeometry(QRect(0, 130, 361, 131));
        gridLayoutWidget_14 = new QWidget(groupBox_TrackingMode);
        gridLayoutWidget_14->setObjectName(QString::fromUtf8("gridLayoutWidget_14"));
        gridLayoutWidget_14->setGeometry(QRect(0, 30, 361, 101));
        gridLayout_14 = new QGridLayout(gridLayoutWidget_14);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        radioButton_BXMode = new QRadioButton(gridLayoutWidget_14);
        radioButton_BXMode->setObjectName(QString::fromUtf8("radioButton_BXMode"));

        gridLayout_14->addWidget(radioButton_BXMode, 1, 0, 1, 1);

        radioButton_TXMode = new QRadioButton(gridLayoutWidget_14);
        radioButton_TXMode->setObjectName(QString::fromUtf8("radioButton_TXMode"));

        gridLayout_14->addWidget(radioButton_TXMode, 0, 0, 1, 1);

        checkBox_0x0800 = new QCheckBox(gridLayoutWidget_14);
        checkBox_0x0800->setObjectName(QString::fromUtf8("checkBox_0x0800"));

        gridLayout_14->addWidget(checkBox_0x0800, 2, 0, 1, 1);

        groupBox_SystemInformation = new QGroupBox(groupBox_TrackingInformation);
        groupBox_SystemInformation->setObjectName(QString::fromUtf8("groupBox_SystemInformation"));
        groupBox_SystemInformation->setGeometry(QRect(380, 130, 211, 131));
        gridLayoutWidget_16 = new QWidget(groupBox_SystemInformation);
        gridLayoutWidget_16->setObjectName(QString::fromUtf8("gridLayoutWidget_16"));
        gridLayoutWidget_16->setGeometry(QRect(0, 30, 201, 31));
        gridLayout_16 = new QGridLayout(gridLayoutWidget_16);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        lineEdit_Frame = new QLineEdit(gridLayoutWidget_16);
        lineEdit_Frame->setObjectName(QString::fromUtf8("lineEdit_Frame"));
        lineEdit_Frame->setReadOnly(true);

        gridLayout_16->addWidget(lineEdit_Frame, 0, 1, 1, 1);

        label_Frame = new QLabel(gridLayoutWidget_16);
        label_Frame->setObjectName(QString::fromUtf8("label_Frame"));
        label_Frame->setMinimumSize(QSize(71, 27));

        gridLayout_16->addWidget(label_Frame, 0, 0, 1, 1);

        groupBox_StatusLegend = new QGroupBox(groupBox_TrackingInformation);
        groupBox_StatusLegend->setObjectName(QString::fromUtf8("groupBox_StatusLegend"));
        groupBox_StatusLegend->setGeometry(QRect(610, 130, 361, 131));
        gridLayoutWidget_17 = new QWidget(groupBox_StatusLegend);
        gridLayoutWidget_17->setObjectName(QString::fromUtf8("gridLayoutWidget_17"));
        gridLayoutWidget_17->setGeometry(QRect(0, 30, 351, 101));
        gridLayout_17 = new QGridLayout(gridLayoutWidget_17);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        label_Mode = new QLabel(gridLayoutWidget_17);
        label_Mode->setObjectName(QString::fromUtf8("label_Mode"));

        gridLayout_17->addWidget(label_Mode, 3, 0, 1, 1);

        lineEdit_Mode = new QLineEdit(gridLayoutWidget_17);
        lineEdit_Mode->setObjectName(QString::fromUtf8("lineEdit_Mode"));
        lineEdit_Mode->setReadOnly(true);

        gridLayout_17->addWidget(lineEdit_Mode, 3, 1, 1, 1);

        label_OOV = new QLabel(gridLayoutWidget_17);
        label_OOV->setObjectName(QString::fromUtf8("label_OOV"));

        gridLayout_17->addWidget(label_OOV, 0, 0, 1, 2);

        label_POOV = new QLabel(gridLayoutWidget_17);
        label_POOV->setObjectName(QString::fromUtf8("label_POOV"));

        gridLayout_17->addWidget(label_POOV, 1, 0, 1, 2);

        label_OK = new QLabel(gridLayoutWidget_17);
        label_OK->setObjectName(QString::fromUtf8("label_OK"));

        gridLayout_17->addWidget(label_OK, 2, 0, 1, 2);

        tabWidget_Device->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1002, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuSystem = new QMenu(menubar);
        menuSystem->setObjectName(QString::fromUtf8("menuSystem"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menubar);
#ifndef QT_NO_SHORTCUT
        label_Position->setBuddy(label_Position);
#endif // QT_NO_SHORTCUT

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuSystem->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionExit);
        menuSettings->addAction(actionCOM_Port_Settings);
        menuSettings->addAction(actionSROM_Image_File_Settings);
        menuSystem->addAction(actionInitialize_System);
        menuSystem->addAction(actionActivate_Handles);
        menuSystem->addSeparator();
        menuSystem->addAction(actionStart_Tracking);
        menuSystem->addAction(actionStop_Tracking);
        menuView->addAction(actionSystem_Properties);
        menuView->addAction(actionDiagnostic_Alerts);
        menuOptions->addAction(actionIlluminator_Activation_Rate);
        menuOptions->addAction(actionProgram_Options);

        retranslateUi(MainWindow);

        tabWidget_Device->setCurrentIndex(0);
        tabWidget_Robot->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "KUKA NDI Interface", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionCOM_Port_Settings->setText(QApplication::translate("MainWindow", "COM Port  Settings", 0, QApplication::UnicodeUTF8));
        actionSROM_Image_File_Settings->setText(QApplication::translate("MainWindow", "SROM Image File Settings", 0, QApplication::UnicodeUTF8));
        actionInitialize_System->setText(QApplication::translate("MainWindow", "Initialize System", 0, QApplication::UnicodeUTF8));
        actionActivate_Handles->setText(QApplication::translate("MainWindow", "Activate Handles", 0, QApplication::UnicodeUTF8));
        actionStart_Tracking->setText(QApplication::translate("MainWindow", "Start Tracking", 0, QApplication::UnicodeUTF8));
        actionStop_Tracking->setText(QApplication::translate("MainWindow", "Stop Tracking", 0, QApplication::UnicodeUTF8));
        actionSystem_Properties->setText(QApplication::translate("MainWindow", "System Properties", 0, QApplication::UnicodeUTF8));
        actionDiagnostic_Alerts->setText(QApplication::translate("MainWindow", "Diagnostic Alerts", 0, QApplication::UnicodeUTF8));
        actionIlluminator_Activation_Rate->setText(QApplication::translate("MainWindow", "Illuminator Activation Rate", 0, QApplication::UnicodeUTF8));
        actionProgram_Options->setText(QApplication::translate("MainWindow", "Program Options", 0, QApplication::UnicodeUTF8));
        label_Feedback->setText(QApplication::translate("MainWindow", "Feedback", 0, QApplication::UnicodeUTF8));
        label_Joint->setText(QApplication::translate("MainWindow", "Joint", 0, QApplication::UnicodeUTF8));
        pause_button->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        label_Position->setText(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        label_Buffer->setText(QApplication::translate("MainWindow", "Buffer", 0, QApplication::UnicodeUTF8));
        label_Message->setText(QApplication::translate("MainWindow", "Message", 0, QApplication::UnicodeUTF8));
        terminate_buf_button->setText(QApplication::translate("MainWindow", "Term", 0, QApplication::UnicodeUTF8));
        copy_button->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        label_Result->setText(QApplication::translate("MainWindow", "Result", 0, QApplication::UnicodeUTF8));
        label_No->setText(QApplication::translate("MainWindow", "No.", 0, QApplication::UnicodeUTF8));
        stop_button->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        pushButton_ConvertPosetoJoint->setText(QApplication::translate("MainWindow", "Pose to Joint", 0, QApplication::UnicodeUTF8));
        label_incrRotateC->setText(QApplication::translate("MainWindow", "Incr. RotateC", 0, QApplication::UnicodeUTF8));
        label_incrTransY->setText(QApplication::translate("MainWindow", "Incr. TransY", 0, QApplication::UnicodeUTF8));
        label_incrRotateB->setText(QApplication::translate("MainWindow", "Incr. RotateB", 0, QApplication::UnicodeUTF8));
        label_incrTransZ->setText(QApplication::translate("MainWindow", "Incr. TransZ", 0, QApplication::UnicodeUTF8));
        pushButton_ExecutePlan->setText(QApplication::translate("MainWindow", "Exe. Singl. Targt.", 0, QApplication::UnicodeUTF8));
        label_Joint1->setText(QApplication::translate("MainWindow", "Joint1", 0, QApplication::UnicodeUTF8));
        label_Joint5->setText(QApplication::translate("MainWindow", "Joint5", 0, QApplication::UnicodeUTF8));
        label_Joint6->setText(QApplication::translate("MainWindow", "Joint6", 0, QApplication::UnicodeUTF8));
        label_RotateB->setText(QApplication::translate("MainWindow", "RotateB", 0, QApplication::UnicodeUTF8));
        label_Joint2->setText(QApplication::translate("MainWindow", "Joint2", 0, QApplication::UnicodeUTF8));
        label_TransZ->setText(QApplication::translate("MainWindow", "TransZ", 0, QApplication::UnicodeUTF8));
        label_RotateC->setText(QApplication::translate("MainWindow", "RotateC", 0, QApplication::UnicodeUTF8));
        label_Joint4->setText(QApplication::translate("MainWindow", "Joint4", 0, QApplication::UnicodeUTF8));
        label_RotateA->setText(QApplication::translate("MainWindow", "RotateA", 0, QApplication::UnicodeUTF8));
        label_Joint3->setText(QApplication::translate("MainWindow", "Joint3", 0, QApplication::UnicodeUTF8));
        label_TransY->setText(QApplication::translate("MainWindow", "TransY", 0, QApplication::UnicodeUTF8));
        label_TransX->setText(QApplication::translate("MainWindow", "TransX", 0, QApplication::UnicodeUTF8));
        pushButton_VisualizeJointPlan->setText(QApplication::translate("MainWindow", "Joint Plan", 0, QApplication::UnicodeUTF8));
        pushButton_VisualizePosePlan->setText(QApplication::translate("MainWindow", "Pose Plan", 0, QApplication::UnicodeUTF8));
        pushButton_ExecuteWaypointsPlan->setText(QApplication::translate("MainWindow", "Exe. Multi. Targt.", 0, QApplication::UnicodeUTF8));
        label_Target->setText(QApplication::translate("MainWindow", "Target", 0, QApplication::UnicodeUTF8));
        label_incrTransX->setText(QApplication::translate("MainWindow", "Incr. TransX", 0, QApplication::UnicodeUTF8));
        label_incrRotateA->setText(QApplication::translate("MainWindow", "Incr. RotateA", 0, QApplication::UnicodeUTF8));
        pushButton_VisualizeIncrPosePlan->setText(QApplication::translate("MainWindow", "Incr. Pose Plan", 0, QApplication::UnicodeUTF8));
        pushButton_AddWaypoint->setText(QApplication::translate("MainWindow", "Add Waypoint", 0, QApplication::UnicodeUTF8));
        tabWidget_Robot->setTabText(tabWidget_Robot->indexOf(tab_PathPlanning), QApplication::translate("MainWindow", "Path Planning", 0, QApplication::UnicodeUTF8));
        label_AxisType->setText(QApplication::translate("MainWindow", "Axis Type", 0, QApplication::UnicodeUTF8));
        label_RotateDegree->setText(QApplication::translate("MainWindow", "Rotate Degree", 0, QApplication::UnicodeUTF8));
        label_AxisVector->setText(QApplication::translate("MainWindow", "Axis Vector", 0, QApplication::UnicodeUTF8));
        pushButton_ExecuteRotatePlan->setText(QApplication::translate("MainWindow", "Execute Rotate Plan", 0, QApplication::UnicodeUTF8));
        pushButton_VisualizeRotatePlan->setText(QApplication::translate("MainWindow", "Visualize Rotate Plan", 0, QApplication::UnicodeUTF8));
        comboBox_AxisType->clear();
        comboBox_AxisType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Custom", 0, QApplication::UnicodeUTF8)
        );
        tabWidget_Robot->setTabText(tabWidget_Robot->indexOf(tab_Calibration), QApplication::translate("MainWindow", "Calibration", 0, QApplication::UnicodeUTF8));
        groupBox_ReferencePoint->setTitle(QApplication::translate("MainWindow", "Target Reference Point (XYZ for NDI frame, ABC for KUKA frame)", 0, QApplication::UnicodeUTF8));
        label_X->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_Y->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_Z->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        label_A->setText(QApplication::translate("MainWindow", "A", 0, QApplication::UnicodeUTF8));
        label_B->setText(QApplication::translate("MainWindow", "B", 0, QApplication::UnicodeUTF8));
        label_C->setText(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        pushButton_CalculateRotationMatrix->setText(QApplication::translate("MainWindow", "Calc. Rot. Mat.", 0, QApplication::UnicodeUTF8));
        pushButton_NeedleCalibration->setText(QApplication::translate("MainWindow", "Needle Calib.", 0, QApplication::UnicodeUTF8));
        groupBox_ReferencePoint_2->setTitle(QApplication::translate("MainWindow", "Translation for Rot. Calc. (KUKA frame)", 0, QApplication::UnicodeUTF8));
        label_dX->setText(QApplication::translate("MainWindow", "dX", 0, QApplication::UnicodeUTF8));
        label_dY->setText(QApplication::translate("MainWindow", "dY", 0, QApplication::UnicodeUTF8));
        label_dZ->setText(QApplication::translate("MainWindow", "dZ", 0, QApplication::UnicodeUTF8));
        tabWidget_Robot->setTabText(tabWidget_Robot->indexOf(tab_NDICalibration), QApplication::translate("MainWindow", "NDI Calibration", 0, QApplication::UnicodeUTF8));
        label_Dimension_Z->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        label_CurrenCollisionObject->setText(QApplication::translate("MainWindow", "Current Collision Object", 0, QApplication::UnicodeUTF8));
        label_Operation->setText(QApplication::translate("MainWindow", "Operation", 0, QApplication::UnicodeUTF8));
        label_Dimension_X_Radius->setText(QApplication::translate("MainWindow", "X / Radius", 0, QApplication::UnicodeUTF8));
        comboBox_Shape->clear();
        comboBox_Shape->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Box", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Sphere", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Cylinder", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Cone", 0, QApplication::UnicodeUTF8)
        );
        comboBox_Operation->clear();
        comboBox_Operation->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8)
        );
        pushButton_Do->setText(QApplication::translate("MainWindow", "Do", 0, QApplication::UnicodeUTF8));
        label_Dimension_Y_Height->setText(QApplication::translate("MainWindow", "Y / Height", 0, QApplication::UnicodeUTF8));
        label_CollisionID->setText(QApplication::translate("MainWindow", "Collision ID", 0, QApplication::UnicodeUTF8));
        label_Shape->setText(QApplication::translate("MainWindow", "Shape", 0, QApplication::UnicodeUTF8));
        label_CollisionObject->setText(QApplication::translate("MainWindow", "Collision Object", 0, QApplication::UnicodeUTF8));
        tabWidget_Robot->setTabText(tabWidget_Robot->indexOf(tab_Environment), QApplication::translate("MainWindow", "Environment", 0, QApplication::UnicodeUTF8));
        label_Joint2_4->setText(QApplication::translate("MainWindow", "Joint2", 0, QApplication::UnicodeUTF8));
        label_S->setText(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
        comboBox_style->clear();
        comboBox_style->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "PTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "LIN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "CIRC", 0, QApplication::UnicodeUTF8)
        );
        send_config_button->setText(QApplication::translate("MainWindow", "Config.", 0, QApplication::UnicodeUTF8));
        send_frame_button->setText(QApplication::translate("MainWindow", "To Frame", 0, QApplication::UnicodeUTF8));
        comboBox_config->clear();
        comboBox_config->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "$ADVANCE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$ACC_PTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$VEL_PTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$ACC_CP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$ACC.ORI1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$ACC.ORI2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$VEL_CP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$VEL.ORI1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$VEL.ORI2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$APO.CPTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$APO.CDIS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$APO.CVEL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "$APO.CORI", 0, QApplication::UnicodeUTF8)
        );
        send_pos_button->setText(QApplication::translate("MainWindow", "To Pos.", 0, QApplication::UnicodeUTF8));
        send_axis_button->setText(QApplication::translate("MainWindow", "To Axis", 0, QApplication::UnicodeUTF8));
        comboBox_approx->clear();
        comboBox_approx->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "C_PTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "C_DIS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "C_VEL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "C_ORI", 0, QApplication::UnicodeUTF8)
        );
        label_Position_2->setText(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        label_Approx->setText(QApplication::translate("MainWindow", "Approx.", 0, QApplication::UnicodeUTF8));
        terminate_imm_button->setText(QApplication::translate("MainWindow", "Term. Imm.", 0, QApplication::UnicodeUTF8));
        label_Joint_2->setText(QApplication::translate("MainWindow", "Joint", 0, QApplication::UnicodeUTF8));
        pause_buf_buton->setText(QApplication::translate("MainWindow", "Pause Buf.", 0, QApplication::UnicodeUTF8));
        label_Style->setText(QApplication::translate("MainWindow", "Style", 0, QApplication::UnicodeUTF8));
        label_Command->setText(QApplication::translate("MainWindow", "Command", 0, QApplication::UnicodeUTF8));
        label_TransX_4->setText(QApplication::translate("MainWindow", "TransX", 0, QApplication::UnicodeUTF8));
        convert_button->setText(QApplication::translate("MainWindow", "Convert", 0, QApplication::UnicodeUTF8));
        label_RotateA_3->setText(QApplication::translate("MainWindow", "RotateA", 0, QApplication::UnicodeUTF8));
        label_TransY_4->setText(QApplication::translate("MainWindow", "TransY", 0, QApplication::UnicodeUTF8));
        label_T->setText(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        default_button->setText(QApplication::translate("MainWindow", "Default", 0, QApplication::UnicodeUTF8));
        labe_TransZ_2->setText(QApplication::translate("MainWindow", "TransZ", 0, QApplication::UnicodeUTF8));
        label_Config->setText(QApplication::translate("MainWindow", "Config.", 0, QApplication::UnicodeUTF8));
        label_RotateB_3->setText(QApplication::translate("MainWindow", "RotateB", 0, QApplication::UnicodeUTF8));
        label_RotateC_3->setText(QApplication::translate("MainWindow", "RotateC", 0, QApplication::UnicodeUTF8));
        debug_button->setText(QApplication::translate("MainWindow", "DEBUG", 0, QApplication::UnicodeUTF8));
        label_Joint1_4->setText(QApplication::translate("MainWindow", "Joint1", 0, QApplication::UnicodeUTF8));
        label_Joint3_4->setText(QApplication::translate("MainWindow", "Joint3", 0, QApplication::UnicodeUTF8));
        label_Joint4_4->setText(QApplication::translate("MainWindow", "Joint4", 0, QApplication::UnicodeUTF8));
        label_Joint5_4->setText(QApplication::translate("MainWindow", "Joint5", 0, QApplication::UnicodeUTF8));
        label_Joint6_4->setText(QApplication::translate("MainWindow", "Joint6", 0, QApplication::UnicodeUTF8));
        tabWidget_Robot->setTabText(tabWidget_Robot->indexOf(tab_SingleCommand), QApplication::translate("MainWindow", "Single Command", 0, QApplication::UnicodeUTF8));
        tabWidget_Device->setTabText(tabWidget_Device->indexOf(tab), QApplication::translate("MainWindow", "KUKA", 0, QApplication::UnicodeUTF8));
        groupBox_ToolProperties->setTitle(QApplication::translate("MainWindow", "Tool Properties", 0, QApplication::UnicodeUTF8));
        label_ToolType->setText(QApplication::translate("MainWindow", "Tool Type", 0, QApplication::UnicodeUTF8));
        checkBox_HandleInitialize->setText(QApplication::translate("MainWindow", "Handle Initialize", 0, QApplication::UnicodeUTF8));
        label_Manufacturer->setText(QApplication::translate("MainWindow", "Manufacturer's", 0, QApplication::UnicodeUTF8));
        label_Part->setText(QApplication::translate("MainWindow", "Part", 0, QApplication::UnicodeUTF8));
        label_Port->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        checkBox_HandleEnable->setText(QApplication::translate("MainWindow", "Handle Enable", 0, QApplication::UnicodeUTF8));
        label_Serial->setText(QApplication::translate("MainWindow", "Serial", 0, QApplication::UnicodeUTF8));
        label_ToolRev->setText(QApplication::translate("MainWindow", "Tool Rev", 0, QApplication::UnicodeUTF8));
        label_Reference->setText(QApplication::translate("MainWindow", "Reference", 0, QApplication::UnicodeUTF8));
        groupBox_System->setTitle(QApplication::translate("MainWindow", "System", 0, QApplication::UnicodeUTF8));
        pushButton_ActiveHandles->setText(QApplication::translate("MainWindow", "Active Handles", 0, QApplication::UnicodeUTF8));
        pushButton_InitializeSystem->setText(QApplication::translate("MainWindow", "Initialize System", 0, QApplication::UnicodeUTF8));
        pushButton_ResetSystem->setText(QApplication::translate("MainWindow", "Reset System", 0, QApplication::UnicodeUTF8));
        pushButton_StartTracking->setText(QApplication::translate("MainWindow", "Start Tracking", 0, QApplication::UnicodeUTF8));
        groupBox_TrackingInformation->setTitle(QApplication::translate("MainWindow", "Tracking Information", 0, QApplication::UnicodeUTF8));
        label_Tz->setText(QApplication::translate("MainWindow", "Tz", 0, QApplication::UnicodeUTF8));
        label_Qx->setText(QApplication::translate("MainWindow", "Qx", 0, QApplication::UnicodeUTF8));
        label_Qo->setText(QApplication::translate("MainWindow", "Qo", 0, QApplication::UnicodeUTF8));
        label_Error->setText(QApplication::translate("MainWindow", "Error", 0, QApplication::UnicodeUTF8));
        label_Qz->setText(QApplication::translate("MainWindow", "Qz", 0, QApplication::UnicodeUTF8));
        label_Tx->setText(QApplication::translate("MainWindow", "Tx", 0, QApplication::UnicodeUTF8));
        label_Handle->setText(QApplication::translate("MainWindow", "Handle", 0, QApplication::UnicodeUTF8));
        label_Ty->setText(QApplication::translate("MainWindow", "Ty", 0, QApplication::UnicodeUTF8));
        label_Status->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        label_Qy->setText(QApplication::translate("MainWindow", "Qy", 0, QApplication::UnicodeUTF8));
        groupBox_TrackingMode->setTitle(QApplication::translate("MainWindow", "Tracking Mode", 0, QApplication::UnicodeUTF8));
        radioButton_BXMode->setText(QApplication::translate("MainWindow", "BX Mode (Binary return for allocated port)", 0, QApplication::UnicodeUTF8));
        radioButton_TXMode->setText(QApplication::translate("MainWindow", "TX Mode (ASCII return for allocated port)", 0, QApplication::UnicodeUTF8));
        checkBox_0x0800->setText(QApplication::translate("MainWindow", "Use the 0x0800 option with the TX or BX Mode", 0, QApplication::UnicodeUTF8));
        groupBox_SystemInformation->setTitle(QApplication::translate("MainWindow", "System Information", 0, QApplication::UnicodeUTF8));
        label_Frame->setText(QApplication::translate("MainWindow", "Frame", 0, QApplication::UnicodeUTF8));
        groupBox_StatusLegend->setTitle(QApplication::translate("MainWindow", "Status Legend", 0, QApplication::UnicodeUTF8));
        label_Mode->setText(QApplication::translate("MainWindow", "Mode: ", 0, QApplication::UnicodeUTF8));
        label_OOV->setText(QApplication::translate("MainWindow", "OOV - Out of volume", 0, QApplication::UnicodeUTF8));
        label_POOV->setText(QApplication::translate("MainWindow", "POOV - Partially out of volume", 0, QApplication::UnicodeUTF8));
        label_OK->setText(QApplication::translate("MainWindow", "OK - Tool is being tracked", 0, QApplication::UnicodeUTF8));
        tabWidget_Device->setTabText(tabWidget_Device->indexOf(tab_2), QApplication::translate("MainWindow", "NDI", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        menuSystem->setTitle(QApplication::translate("MainWindow", "System", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTINTERFACE_H
