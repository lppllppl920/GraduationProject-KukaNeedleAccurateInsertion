cmake_minimum_required(VERSION 2.8.3)
project(robot_driver_interface)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  moveit_ros_planning_interface
  visualization_msgs
  interactive_markers
)

find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

include_directories( src )
include_directories( src/plot )
include_directories( src/common )
include_directories( src/gui )

#qt4_wrap_ui(UISrcs src/gui/krc4_control_async_gui.ui)
#qt4_wrap_cpp(UIMOCSrcs src/gui/krc4_control_async_gui.h)
qt4_wrap_ui(UISrcs src/gui/RobotInterface.ui)
qt4_wrap_ui(UIMOCSrcs src/gui/ui_RobotInterface.h)
qt4_wrap_ui(UIPLOTSrcs src/plot/plot.ui)
qt4_wrap_cpp(UIPLOTMOCSrcs src/plot/plot.h)
qt4_wrap_cpp(THREADMOCSrcs src/common/tcpthread.h)
qt4_wrap_cpp(PLANMOCSrcs src/common/plannar.h)
qt4_wrap_cpp(PLOTMOCSrcs src/plot/qcustomplot.h)
qt4_wrap_cpp(CTRLMOCSrcs src/controller.h)
qt4_wrap_cpp(INTERFACEMOCSrcs src/Interface.h)

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

#add_executable(
#    KRC4_control_async_gui
#    src/main_gui.cpp
#    src/gui/krc4_control_async_gui.cpp
#    src/plot/plot.cpp
#    src/plot/qcustomplot.cpp
#    src/common/geometry.cpp
#    src/common/message.cpp
#    src/common/tcpthread.cpp
#    src/common/plannar.cpp
#    ${UIMOCSrcs}
#    ${UISrcs}
#    ${THREADMOCSrcs}
#    ${PLANMOCSrcs}
#    ${UIPLOTSrcs}
#    ${UIPLOTMOCSrcs}
#    ${PLOTMOCSrcs}
#    ${INTERFACEMOCSrcs})
#target_link_libraries(KRC4_control_async_gui ${QT_LIBRARIES} ${catkin_LIBRARIES} -lQtNetwork -lQtXml orocos-kdl kdl_parser )


include_directories( /opt/ros/indigo/include )
#include_directories( src/ros )

link_directories( /opt/ros/indigo/lib )

add_executable(
    KRC4_control_async
    src/main.cpp
    src/controller.cpp
    src/Interface.cpp
    src/plot/plot.cpp
    src/plot/qcustomplot.cpp
    src/common/plannar.cpp
    src/common/geometry.cpp
    src/common/message.cpp
    src/common/tcpthread.cpp
    ${UISrcs}
    ${UIMOCSrcs}
    ${THREADMOCSrcs}
    ${PLANMOCSrcs}
    ${UIPLOTSrcs}
    ${UIPLOTMOCSrcs}
    ${PLOTMOCSrcs}
    ${CTRLMOCSrcs}
    ${INTERFACEMOCSrcs})
target_link_libraries(KRC4_control_async ${QT_LIBRARIES} ${catkin_LIBRARIES} -lQtNetwork -lQtXml orocos-kdl kdl_parser roscpp rosconsole roscpp_serialization rostime interactive_markers)


