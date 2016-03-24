/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 21 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 *
 *   Header file for Plannar, normally employed by the main thread.
 *   TCPThread is created here. Plannar provides direct API for higher
 *   level controllers.
 *   Plannar class offers API for sending motion command / configuration
 *   command / other command, processes feedback received from KRC4, and
 *   manages commandList and feedbackList, with a few error handling.
 *   Plannar wraps up some testing functions, could be used to test
 *   communications between controller and KRC4.
 *
 *   Signals:
 *       \sendMessage(QString)       -> self.tcpthread_/
 *       \debug()                    -> self.tcpthread_/ - for debugging
 *       \displayFeedback(Feedback*) -> controller/
 *   Slots:
 *       \self.tcpthread_            -> feedbackReceived(QString)/
 *       \self.tcpthread_            -> disconnected()/
 *
 *
 */

#ifndef MY_PLANNAR
#define MY_PLANNAR

#include "message.h"
#include "tcpthread.h"
#include "plot.h"
// Includes the descartes robot model we will be using
#include <descartes_moveit/moveit_state_adapter.h>
// Includes the descartes trajectory type we will be using
#include <descartes_trajectory/axial_symmetric_pt.h>
#include <descartes_trajectory/cart_trajectory_pt.h>
// Includes the planner we will be using
#include <descartes_planner/dense_planner.h>

// --------------------------------------------------------------------------
// Plannar class
//  - publicly inherited from QObect, for signal-slot connection between main
//      program (higher level controller) and plannar
// --------------------------------------------------------------------------
class Plannar: public QObject {
	Q_OBJECT
public:

	typedef control_msgs::FollowJointTrajectoryActionGoalConstPtr TrajectoryGoal;
	typedef moveit::planning_interface::MoveGroup::Plan MotionPlan;

	// plannar constructor
	//  - initialize robot model and tcpthread
	//  - initialize iterators for CommandList management
	//  - start tcpthread: waiting for connection...
	Plannar();

	// Clear up CommandList and FeedbackList
	~Plannar();

	// APIs for motion control
	//  - PTP and LIN motion:
	//  - style should be COMMAND_STYLE_PTP or COMMAND_STYLE_LIN
	//  - Error check: if Frame / Axis / Pos is reachable
	void motion(Command::Style style, Frame &f, Command::Approx approx =
			Command::NONE);
	void motion(Command::Style style, Axis &a, Command::Approx approx =
			Command::NONE);
	void motion(Command::Style style, Pos &p, Command::Approx approx =
			Command::NONE);
	// APIs for motion control
	//  - CIRC motion:
	//  - style should be COMMAND_STYLE_CIRC
	//  - Error check: if end point and auxiliary point Frame / Axis / Pos are reachable
	void motion(Command::Style style, Frame &f_end, Frame &f_aux, float degree,
			Command::Approx approx = Command::NONE);
	void motion(Command::Style style, Frame &f_end, Axis &a_aux, float degree,
			Command::Approx approx = Command::NONE);
	void motion(Command::Style style, Frame &f_end, Pos &p_aux, float degree,
			Command::Approx approx = Command::NONE);
	void motion(Command::Style style, Axis &a_end, Frame &f_aux, float degree,
			Command::Approx approx = Command::NONE);
	void motion(Command::Style style, Axis &a_end, Axis &a_aux, float degree,
			Command::Approx approx = Command::NONE);
	void motion(Command::Style style, Axis &a_end, Pos &p_aux, float degree,
			Command::Approx approx = Command::NONE);
	void motion(Command::Style style, Pos &p_end, Frame &f_aux, float degree,
			Command::Approx approx = Command::NONE);
	void motion(Command::Style style, Pos &p_end, Axis &a_aux, float degree,
			Command::Approx approx = Command::NONE);
	void motion(Command::Style style, Pos &p_end, Pos &p_aux, float degree,
			Command::Approx approx = Command::NONE);

	// Check if the target is reachable
	// Robot Model should be initialized before
	// reachableCheck for Frame and Pos is not accomplished yet
	bool reachableCheck(Frame &f);
	bool reachableCheck(Axis &a);
	bool reachableCheck(Pos &p);

	// API for configuration
	//  - param should be:
	//      0 (COMMAND_PARAM_ADVANCE)   : $ADVANCE  (0-5)
	//      1 (COMMAND_PARAM_ACC_PTP)   : $ACC_PTP  (%)
	//      2 (COMMAND_PARAM_VEL_PTP)   : $VEL_PTP  (%)
	//      3 (COMMAND_PARAM_ACC_CP)    : $ACC_CP   (%)
	//      4 (COMMAND_PARAM_ACC_ORI1)  : $ACC.ORI1
	//      5 (COMMAND_PARAM_ACC_ORI2)  : $ACC.ORI2
	//      6 (COMMAND_PARAM_VEL_CP)    : $VEL_CP   (m/s)
	//      7 (COMMAND_PARAM_VEL_ORI1)  : $VEL.ORI1
	//      8 (COMMAND_PARAM_VEL_ORI2)  : $VEL.ORI2
	//      9 (COMMAND_PARAM_APO_CPTP)  : $APO.CPTP
	//      10(COMMAND_PARAM_APO_CDIS)  : $APO.CDIS (mm)
	//      11(COMMAND_PARAM_APO_CVEL)  : $APO.CVEL
	//      12(COMMAND_PARAM_APO_CORI)  : $APO.CORI
	//  - if param == $ADVANCE, number should be an integer from 0 to 5
	//      e.g. configuration( COMMAND_PARAM_ADVANCE, 3.0 );
	//  - Error check: if param is in range
	//  - Error check: if param == COMMAND_PARAM_ADVANCE, number be from 0 to 5
	void configuration(Command::Param param, float number);

	// TERMINATE_BUF:
	//  - terminate command buffered in KRL
	//  - when terminate command executed, KRL program finishes
	//  - feedback message: TERMINATE buffered
	//  - error message: TERMINATE command not buffered: Buffer full
	void terminateBuffered();

	// TERMINATE_IMM:
	//  - terminate command pushed to the front of KRL buffer (right behind advance run pointer)
	//  - all other motion commands afterwards are ignored
	//  - the program will finish after advance run motion completes
	//  - feedback message: TERMINATE immediately
	void terminateImmediately();

	// PAUSE_IMM:
	//  - realized by BRAKE -> HALT -> RESUME combination
	//  - pressing "continue" button on the KRC pad resumes the program after pause
	//  - the next motion will be the one follows the advance pointer
	//  - if $ADVANCE == 0, the program will continus to execute the paused motion
	//  - if $ADVANCE == 1 the program will execute the next motion
	//  - global clock is not paused
	//  - feedback message: PAUSE immediately
	void pauseImmediately();

	// PAUSE_BUF:
	//  - realized by HALT
	//  - the program will be paused where the command is buffered
	//  - pressing "continue" button on the KRC pad resumes the program
	//  - global clock is not paused
	//  - feedback message: PAUSE buffered
	void pauseBuffered();

	// STOP:
	//  - realized by BRAKE -> CLEAR BUF -> HALT -> RESUME
	//  - pressing "continue" button on the KRC pad resumes the program
	//  - KRL buffer will be emptied
	//  - no motion will be executed without arrival of new motion commands
	//  - feedback message: STOP immediately
	void stop();

	// Reserved for test use
	//  - used to call various test functions
	//  - linked with "debug" button on GUI
	void test();

	void plot(Axis::Param val, int count = DEF_PLOT_ALL,
			plotWindow::PlotMethod pm = plotWindow::NewPlot);

	void plot(Pos::Param val, int count = DEF_PLOT_ALL,
			plotWindow::PlotMethod pm = plotWindow::NewPlot);

	void plot(Frame::Param val, int count = DEF_PLOT_ALL,
			plotWindow::PlotMethod pm = plotWindow::NewPlot);

	void plot(Frame::Param val1, Frame::Param val2, int count = DEF_PLOT_ALL,
			plotWindow::PlotMethod pm = plotWindow::NewPlot);

	void plot(Axis::Param val1, Axis::Param val2, int count = DEF_PLOT_ALL,
			plotWindow::PlotMethod pm = plotWindow::NewPlot);

	void plot(Pos::Param val1, Pos::Param val2, int count = DEF_PLOT_ALL,
			plotWindow::PlotMethod pm = plotWindow::NewPlot);

	void clearPlots();

	TCPThread& getTCPThread();

	Model& getModel();

	plotWindow& getPlotWindow();

	std::list<Command*>& getCommandList();

	std::list<Feedback*>& getFeedbackList();

	std::list<Command*>::iterator& getCommandIterBufFront();

	std::list<Command*>::iterator& getCommandIterBufLast();

	std::list<Command*>::iterator& getCommandIterNextACK();

	std::list<Command*>::iterator& getCommandIterNextSent();

	int getFeedbackCount();

	void robotInterfaceCallback(
			const control_msgs::FollowJointTrajectoryActionGoalConstPtr& feedback);

public slots:
	// Called when tcpthread_ emit feedbackReceived(QString) signal
	void feedbackReceived(QString qs);
	// Called when tcpSocket_ in tcpthread_ is disconencted
	void disconnected();
	// Called when Controller emit sendTrajectory() signal
	void executeTrajectory(
			const TrajectoryGoal& feedback);
signals:
	// Connected with tcpthread_.sendMessage()
	// send a message to KRC4
	void sendMessage(QString qs);
	// Connected with tcpthread_.debug()
	// for debugging purposes
	void debug();
	// Connected with GUI, or higher level controller
	void newFeedback(Feedback* fb);
	void shutdownController();

private:
	// CommandList & FeedbackList management
	// Append CommandList, waiting to be sent to tcpthread
	//  - cmd->emergent_ is checked, if it is an emergent command,
	//      push to the front of the CommandList, otherwise append
	//      to the end of the CommandList
	//  - iterators are updated when CommandList is modified
	//  - if any iterator points at CommandList.end(), change it to the one before
	//      CommandList.end(), that is, points to the one just appended
	void appendCommandList(Command* cmd);

	// Update FeedbackList and CommandList according to the new feedback
	//  - called when a new feedback received
	//  - update CommandList iterators
	//  - in case of feedback of special messages, update iterators accordingly
	//  - queryNextCommand when feedback is processed
	//  - emit displayFeedback(Feedback*) signal
	void updateQueueStatus(Feedback *fb);

	// Called when the feedback received is pure timer feedback or normal command feedback
	//  - modify KRLBufFront and KRLBufLast
	void updateIterators(Feedback *fb);

	// Update CommandIterNextACK according to the stamp number of the Feedback
	//  - point the iterator to the next Command in the CommandList after the one acknowledged
	//  - point to CommandList.end() if the acknowledged command is the last one in CommandList
	void updateCommandIterNextACK(Feedback* fb);

	// Update CommandIterBufFront according to the change of parameter: KRLBufFront
	//  - Command with state == COMMAND_STATE_SUCCESS or state == COMMAND_STATE_ERROR are skipped,
	//      because the command is not stored in KRL Buffer, but processed right in the interrupt
	//      function of KRL, e.g. PAUSE_IMM / STOP / TERMINATE_IMM
	//  - If the buffer is empty and no CommandList is all executed, point the iterator to CommandList.end()
	void updateCommandIterBufFront(Feedback* fb);

	// Called if the feedback is the feedback of a STOP command
	//  - modify the iterators accordingly: points all iterators to the first command that is not buffered in KRL
	void stopRecv(Feedback* fb);

	// Called if the feedback is the feedback of a PAUSE_IMM command
	//  - modify the iterators accordingly
	void pauseImmRecv(Feedback* fb);

	// Called if the feedback is the feedback of a TERMINATE_IMM command
	//  - modify the iterators accordingly
	void terminateImmRecv(Feedback* fb);

	// Called if the feedback is the feedback of a STOP command
	//  - modify the iterators accordingly: cancel all the unsent command in CommandList
	void terminateBufRecv(Feedback* fb);

	// Called when feedback processing finishes
	//  - if there is command in CommandList and there is adequate space in KRL buffer, send it to tcpthread_
	//  - if the first command in CommandList is an emergent command (probably just pushed front by controller),
	//      and there is some space in KRL buffer, send it to tcpthread_
	//  - update CommandIterNextSent accordingly
	void queryNextCommand();

	// axisCycles: if cycle < 0, execute inversely
	void axisCycles(int cycle = 1);
	// printCommandList information formatedly, including all iterators associated with CommandList
	void printCommandList();
	// printFeedbackBasic, print basic information about the feedback message: buffer & stamp
	void printFeedbackBasic();
	// updateFrequencyPerformance, monitor timing issues
	void updateFrequencyPerformance(Feedback *fb);

	// Test functions
	void testAxisCycle();
	void testApproximation();
	void testStop();
	void testPauseBuf();
	void testPauseImm();
	void testTerminateBuf();
	void testTerminateImm();
	void testKRLBuffer();
	void testSquare(int count);
	// Random walk in a proper workspace
	//  - mainly upper part of the robot
	void testRandomWalk(int count);
	// Check if the Pos and Axis information in feedback right
	//  - mainly used to test if Model::getTurn and Model::getStatus functions
	bool checkStatusTurn(Feedback *fb);

	// Trajectory subscriber

	// private members
	// thread representing tcp port
	TCPThread tcpThread_;
	// stamp to record the sequence of command initiated
	//  - automatically increase when a command is successfully appended to CommandList
	//  - stamp of the first command appended to CommandList is 1
	//  - stamp of the last command appended to CommandList is (stamp_ - 1)
	int stamp_;
	// Position of BufFront in KRL buffer
	//  - update when new feedback received
	int KRLBufFront;
	// Position of BufLast in KRL buffer
	//  - update when new feedback received
	int KRLBufLast;
	// advance_ record the $ADVANCE value of KRL program
	//  - default value: 3
	int advance_;

	// Model of robot
	//  - KUKA KR6 R700 sixx is used here
	//  - initialized in Plannar constructor
	Model robot_;

	// Record the most recent Axis information
	//  - act as initial guess for inverse kinematics iteration
	//  - update when new feedback received
	Axis lastAxis_;

	// CommandList used to buffer commands
	//  - new Command usually pushed at the back of the list
	//  - emergent Command pushed where the next command will be sent
	//  - no upper limit for the size of CommandList
	std::list<Command*> CommandList;
	// FeedbackList used to store feedbacks received
	//  - aid for analyzing robot motion and command execution
	//  - when size upper bound reached, pop_front is used to keep the size under limit
	//  - size limit: QUEUE_MAXLEN, written in tcpthread.h
	std::list<Feedback*> FeedbackList;
	// CommandIterBufFront points to the first command in KRL buffer
	//  - NOTE: "First" command may not be the motion currently being executed,
	//      only true when $ADVANCE == 0, otherwise, the motion currently being
	//      executed is the $ADVANCE command ahead of this iterator.
	//      e.g. if $ADVANCE == 1, the motion currently being executed is (CommandIterBufFront - 1)
	std::list<Command*>::iterator CommandIterBufFront;
	// CommandIterBufLast points to the next place after the last command in KRL buffer
	//  - in KRL, BufLast also points to the next place after the last command
	//  - if Commands in CommandList are all sent, CommandIterBufLast == CommandList.end()
	std::list<Command*>::iterator CommandIterBufLast;
	// CommandIterNextSent points to the next command to be sent
	//  - if Commands in CommandList are all sent, CommandIterNextSent == CommandList.end()
	std::list<Command*>::iterator CommandIterNextSent;
	// CommandIterNextACK points to the Command just sent but not acknowledged (feedback not yet arrived)
	//  - if the last sent command is sent, CommandIterNextACK == CommandIterNextSent
	std::list<Command*>::iterator CommandIterNextACK;

	// parameters to monitor timing performance of control loop
	int feedbackCount_;
	int lastTime_;
	int firstTime_;
	double averageTime_;

	plotWindow plot_;


};

#endif
