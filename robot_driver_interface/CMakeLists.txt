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

qt4_wrap_ui(UISrcs src/gui/robotInterface.ui)
qt4_wrap_cpp(UIMOCSrcs src/gui/ui_robotInterface.h)
qt4_wrap_cpp(THREADMOCSrcs src/common/tcpthread.h)
qt4_wrap_cpp(PLANMOCSrcs src/common/plannar.h)
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
include_directories( /opt/ros/indigo/include )
link_directories( /opt/ros/indigo/lib )

IF (QtSerialPort_INCLUDE_DIR AND QtSerialPort_LIBRARIES) 
      SET (QtSerialPort_FOUND TRUE) 
ELSE (QtSerialPort_INCLUDE_DIR AND QtSerialPort_LIBRARIES) 
      IF (UNIX) 
              FIND_LIBRARY (QtSerialPort_LIBRARIES 
                              NAMES 
                                      SerialPort 
                              PATH_SUFFIXES 
                                      qt4 
                              ) 
              FIND_PATH (QtSerialPort_INCLUDE_DIR QtAddOnSerialPort/serialport.h 
                              PATHS 
                                      ${QtSerialPort_DIR}/include 
                                      ENV PATH 
                              ) 
      ELSE () 
              IF (MINGW) 
                      IF (NOT QtSerialPort_DIR) 
                              MESSAGE (FATAL_ERRO "Set the QtSerialPort_DIR") 
                      ELSE () 
                              FIND_LIBRARY (QtSerialPort_LIBRARIES 
                                      NAMES 
                                              SerialPort1 
                                      PATH_SUFFIXES 
                                              release 
                                      PATHS 
                                              ${QtSerialPort_DIR}/src/serialport 
                                      ) 
                              FIND_PATH (QtSerialPort_INCLUDE_DIR QtAddOnSerialPort/serialport.h 
                                      PATHS 
                                              ${QtSerialPort_DIR}/include 
                                      ENV PATH 
                                      ) 
                      ENDIF () 
              ENDIF () 
      ENDIF () 
ENDIF () 
 
IF (QtSerialPort_LIBRARIES AND QtSerialPort_INCLUDE_DIR) 
      SET (QtSerialPort_FOUND 1) 
ENDIF () 
 
IF (QtSerialPort_FOUND) 
      MESSAGE (STATU "Found the QtSerialPort libraries at: ${QtSerialPort_LIBRARIES}") 
      MESSAGE (STATU "Found QtSerialPort headers at: ${QtSerialPort_INCLUDE_DIR}") 
ELSE (QtSerialPort_FOUND) 
      IF (QtSerialPort_FIND_REQUIRED) 
              MESSAGE (FATAL_ERRO "Could NOT find required QtSerialPort library, aborting") 
      ELSE (QtSerialPort_FIND_REQUIRED) 
              MESSAGE (STATU "Could NOT find QtSerialPort") 
      ENDIF () 
ENDIF ()  


add_executable(
    KRC4_control_async
    src/main.cpp
    src/controller.cpp
    src/Interface.cpp
    src/common/plannar.cpp
    src/common/geometry.cpp
    src/common/message.cpp
    src/common/tcpthread.cpp
    ${UISrcs}
    ${UIMOCSrcs}
    ${THREADMOCSrcs}
    ${PLANMOCSrcs}
    ${CTRLMOCSrcs}
    ${INTERFACEMOCSrcs})
target_link_libraries(KRC4_control_async ${QT_LIBRARIES} ${catkin_LIBRARIES} -lQtNetwork -lQtXml orocos-kdl kdl_parser roscpp rosconsole roscpp_serialization rostime interactive_markers)


