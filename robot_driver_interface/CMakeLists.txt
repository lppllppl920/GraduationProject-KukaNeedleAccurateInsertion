cmake_minimum_required(VERSION 2.8.3)
project(robot_driver_interface)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  moveit_ros_planning_interface
  visualization_msgs
  interactive_markers
  descartes_planner
  descartes_moveit
  descartes_trajectory
)

find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

include_directories( src )
include_directories( src/common )
include_directories( src/gui )
include_directories( src/ndi )

qt4_wrap_ui(UISrcs src/gui/robotInterface.ui)
qt4_wrap_cpp(UIMOCSrcs src/gui/ui_robotInterface.h)
qt4_wrap_ui(UISUB1Srcs src/gui/robotInterface_COMPortSettings.ui)
qt4_wrap_cpp(UISUB1MOCSrcs src/gui/ui_robotInterface_COMPortSettings.h)
qt4_wrap_ui(UISUB2Srcs src/gui/robotInterface_NewAlertFlags.ui)
qt4_wrap_cpp(UISUB2MOCSrcs src/gui/ui_robotInterface_NewAlertFlags.h)
qt4_wrap_ui(UISUB3Srcs src/gui/robotInterface_SystemFeatures.ui)
qt4_wrap_cpp(UISUB3MOCSrcs src/gui/ui_robotInterface_SystemFeatures.h)
qt4_wrap_ui(UISUB4Srcs src/gui/robotInterface_ProgramOptions.ui)
qt4_wrap_cpp(UISUB4MOCSrcs src/gui/ui_robotInterface_ProgramOptions.h)
qt4_wrap_ui(UISUB5Srcs src/gui/robotInterface_IlluminatorFiringRate.ui)
qt4_wrap_cpp(UISUB5MOCSrcs src/gui/ui_robotInterface_IlluminatorFiringRate.h)
qt4_wrap_ui(UISUB6Srcs src/gui/robotInterface_ROMFile.ui)
qt4_wrap_cpp(UISUB6MOCSrcs src/gui/ui_robotInterface_ROMFile.h)
qt4_wrap_ui(UISUB6Srcs src/gui/robotInterface_COMPortTimeOut.ui)
qt4_wrap_cpp(UISUB6MOCSrcs src/gui/ui_robotInterface_COMPortTimeOut.h)
qt4_wrap_ui(UISUB7Srcs src/gui/robotInterface_MotionPlanDecision.ui)
qt4_wrap_cpp(UISUB7MOCSrcs src/gui/ui_robotInterface_MotionPlanDecision.h)
qt4_wrap_ui(UISUB8Srcs src/gui/robotInterface_WaitForExecution.ui)
qt4_wrap_cpp(UISUB8MOCSrcs src/gui/ui_robotInterface_WaitForExecution.h)
qt4_wrap_ui(UISUB9Srcs src/gui/robotInterface_WaitForIndicatorPlaced.ui)
qt4_wrap_cpp(UISUB9MOCSrcs src/gui/ui_robotInterface_WaitForIndicatorPlaced.h)

qt4_wrap_cpp(THREADMOCSrcs src/common/tcpthread.h)
qt4_wrap_cpp(PLANMOCSrcs src/common/plannar.h)
qt4_wrap_cpp(ROSTHREADMOCSrcs src/common/ROSThread.h)
qt4_wrap_cpp(KUKAFEEDBACKMOCSrcs src/KukaFeedback.h)
qt4_wrap_cpp(CTRLMOCSrcs src/controller.h)
qt4_wrap_cpp(INTERFACEMOCSrcs src/Interface.h)
qt4_wrap_cpp(COMM32PORTMOCSrcs src/ndi/Comm32Port.h)
qt4_wrap_cpp(COMPORTSETTINGSMOCSrcs src/ndi/COMPortSettings.h)
qt4_wrap_cpp(NEWALERTFLAGSMOCSrcs src/ndi/NewAlertFlagsDlg.h)
qt4_wrap_cpp(SYSTEMFEATURESMOCSrcs src/ndi/SystemFeaturesDlg.h)
qt4_wrap_cpp(PROGRAMOPTIONSMOCSrcs src/ndi/ProgramOptions.h)
qt4_wrap_cpp(ILLUMINATORFIRINGRATEMOCSrcs src/ndi/IlluminatorFiringRate.h)
qt4_wrap_cpp(ROMFILEMOCSrcs src/ndi/ROMFileDlg.h)
qt4_wrap_cpp(COMPORTTIMEOUTMOCSrcs src/ndi/COMPortTimeOut.h)
qt4_wrap_cpp(MOTIONPLANDECISIONMOCSrcs src/MotionPlanDecision.h)
qt4_wrap_cpp(WAITFOREXECUTIONMOCSrcs src/common/WaitForExecution.h)
qt4_wrap_cpp(WAITFORINDICATORPLACEDMOCSrcs src/common/WaitForIndicatorPlaced.h)

set(eigen_DIRS /usr/include/eigen3)
set(orocos_kdl_DIRS /opt/ros/indigo/include)
set(orocos_kdl_LIBS /opt/ros/indigo/lib)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES robot_driver_interface
#  CATKIN_DEPENDS moveit_ros_planning_interface roscpp visualization_msgs
#  DEPENDS system_lib
)

link_directories(${orocos_kdl_LIBS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${orocos_kdl_DIRS} ${eigen_DIRS} ${catkin_INCLUDE_DIRS})
include_directories( /opt/ros/indigo/include )
link_directories( /opt/ros/indigo/lib )

add_executable(
    KRC4_control_async
    src/main.cpp
    src/controller.cpp
    src/Interface.cpp
    src/KukaFeedback.cpp
    src/MotionPlanDecision.cpp
    src/EulerQuaternionConversion.cpp
    src/common/plannar.cpp
    src/common/geometry.cpp
    src/common/message.cpp
    src/common/tcpthread.cpp
    src/common/ROSThread.cpp
    src/common/WaitForExecution.cpp
    src/common/WaitForIndicatorPlaced.cpp
    src/ndi/Comm32Port.cpp
    src/ndi/CommandHandling.cpp
    src/ndi/Conversions.cpp
    src/ndi/inifile.cpp
    src/ndi/COMPortSettings.cpp
    src/ndi/NewAlertFlagsDlg.cpp
    src/ndi/SystemFeaturesDlg.cpp
    src/ndi/ProgramOptions.cpp
    src/ndi/IlluminatorFiringRate.cpp
    src/ndi/ROMFileDlg.cpp
    src/ndi/COMPortTimeOut.cpp
    ${UISrcs}
    ${UIMOCSrcs}
    ${UISUB1Srcs}
    ${UISUB1MOCSrcs}
    ${UISUB2Srcs}
    ${UISUB2MOCSrcs}
    ${UISUB3Srcs}
    ${UISUB3MOCSrcs}
    ${UISUB4Srcs}
    ${UISUB4MOCSrcs}
    ${UISUB5Srcs}
    ${UISUB5MOCSrcs}
    ${UISUB6Srcs}
    ${UISUB6MOCSrcs}
    ${UISUB7Srcs}
    ${UISUB7MOCSrcs}
    ${UISUB8Srcs}
    ${UISUB8MOCSrcs}
    ${UISUB9Srcs}
    ${UISUB9MOCSrcs}
    ${THREADMOCSrcs}
    ${ROSTHREADMOCSrcs}
    ${KUKAFEEDBACKMOCSrcs}
    ${PLANMOCSrcs}
    ${CTRLMOCSrcs}
    ${INTERFACEMOCSrcs}
    ${COMM32PORTMOCSrcs}
    ${COMPORTSETTINGSMOCSrcs}
    ${NEWALERTFLAGSMOCSrcs}
    ${SYSTEMFEATURESMOCSrcs}
    ${PROGRAMOPTIONSMOCSrcs}
    ${ILLUMINATORFIRINGRATEMOCSrcs}
    ${ROMFILEMOCSrcs}
    ${COMPORTTIMEOUTMOCSrcs}
    ${MOTIONPLANDECISIONMOCSrcs}
    ${WAITFOREXECUTIONMOCSrcs}
    ${WAITFORINDICATORPLACEDMOCSrcs}
    )
target_link_libraries(KRC4_control_async ${QT_LIBRARIES} ${catkin_LIBRARIES} QtNetwork QtXml QtSerialPort orocos-kdl kdl_parser roscpp rosconsole roscpp_serialization rostime interactive_markers)


