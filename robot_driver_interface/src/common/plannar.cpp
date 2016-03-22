/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 20 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#include "plannar.h"
#include <cmath>
#include <qmath.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <QVector>

Plannar::Plannar() :
		tcpThread_(), robot_(), lastAxis_(), plot_() {
	ROS_INFO("Plannar Constructing...");

	stamp_ = 0;
	connect(&tcpThread_, SIGNAL(feedbackReceived(QString)), this,
			SLOT(feedbackReceived(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(sendMessage(QString)), &tcpThread_,
			SLOT(sendMessage(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(debug()), &tcpThread_, SLOT(debug()),
			Qt::QueuedConnection);
	connect(&tcpThread_, SIGNAL(disconnected()), this, SLOT(disconnected()),
			Qt::QueuedConnection);

	CommandIterBufFront = CommandList.begin();
	CommandIterBufLast = CommandList.begin();
	CommandIterNextSent = CommandList.begin();
	CommandIterNextACK = CommandList.begin();

	KRLBufLast = 1;
	KRLBufFront = 1;

	// default value for $ADVANCE
	advance_ = 3;

	ROS_INFO("TCP thread starts...");
	tcpThread_.start();

	lastTime_ = 0;
	feedbackCount_ = 0;
	averageTime_ = 0.0;
	firstTime_ = 0;

}

Plannar::~Plannar() {
	while (!CommandList.empty()) {
		Command * cmd = CommandList.front();
		CommandList.pop_front();
		delete cmd;
	}
	while (!FeedbackList.empty()) {
		Feedback* fb = FeedbackList.front();
		FeedbackList.pop_front();
		delete fb;
	}
	ROS_INFO("Plannar Deconstructing...");
}

void Plannar::executeTrajectory(
		const TrajectoryGoal& feedback) {

	Axis a;

	for (int i = 0; i < feedback->goal.trajectory.points.size(); i++) {
		ROS_INFO("%dth point joint positions: %.2f %.2f %.2f %.2f %.2f %.2f", i,
				feedback->goal.trajectory.points[i].positions[0]  / M_PI * 180.0,
				feedback->goal.trajectory.points[i].positions[1]  / M_PI * 180.0,
				feedback->goal.trajectory.points[i].positions[2]  / M_PI * 180.0,
				feedback->goal.trajectory.points[i].positions[3]  / M_PI * 180.0,
				feedback->goal.trajectory.points[i].positions[4]  / M_PI * 180.0,
				feedback->goal.trajectory.points[i].positions[5]  / M_PI * 180.0);
	}

	// TODO: For now, I just use every trajectory points as motion commands.
	// This could be simplified using some criteria to reduce the number of commands.
	for (int i = 0; i < feedback->goal.trajectory.points.size(); i++) {
		a.A1 = feedback->goal.trajectory.points[i].positions[0] / M_PI * 180.0;
		a.A2 = feedback->goal.trajectory.points[i].positions[1] / M_PI * 180.0;
		a.A3 = feedback->goal.trajectory.points[i].positions[2] / M_PI * 180.0;
		a.A4 = feedback->goal.trajectory.points[i].positions[3] / M_PI * 180.0;
		a.A5 = feedback->goal.trajectory.points[i].positions[4] / M_PI * 180.0;
		a.A6 = feedback->goal.trajectory.points[i].positions[5] / M_PI * 180.0;
		motion(Command::PTP, a, Command::C_DIS);
	}
}

void Plannar::feedbackReceived(QString qs) {
	while (FeedbackList.size() >= QUEUE_MAXLEN) {
		Feedback* fb = FeedbackList.front();
		FeedbackList.pop_front();
		delete fb;
	}
	Feedback* fb = new Feedback(qs);
	FeedbackList.push_back(fb);

	updateQueueStatus(fb);
}

void Plannar::disconnected() {
	// exit tcp thread for disconnecting
	tcpThread_.exit();
	ROS_INFO("TCP thread stops...");
	// emit signal to shut down Controller
	emit shutdownController();
}

void Plannar::appendCommandList(Command* cmd) {
	if (cmd->getEmergent() && CommandIterNextSent != CommandList.end()) {
		CommandList.insert(CommandIterNextSent, 1, cmd);
		if (CommandIterBufFront == CommandIterNextSent)
			CommandIterBufFront--;
		if (CommandIterBufLast == CommandIterNextSent)
			CommandIterBufLast--;
		if (CommandIterNextACK == CommandIterNextSent)
			CommandIterNextACK--;
		CommandIterNextSent--;
	} else {
//    std::cout << std::distance(CommandList.begin(),CommandIterBufFront) << " "
//              << std::distance(CommandList.begin(),CommandIterBufLast) << " "
//              << std::distance(CommandList.begin(),CommandIterNextACK) << " "
//              << std::distance(CommandList.begin(),CommandIterNextSent) << " "
//              << std::distance(CommandList.begin(),CommandList.end()) << std::endl;

		CommandList.push_back(cmd);

		// modify the previous iterator to the newly appended item
		if (CommandIterBufFront == CommandList.end())
			CommandIterBufFront--;
		if (CommandIterBufLast == CommandList.end())
			CommandIterBufLast--;
		if (CommandIterNextSent == CommandList.end())
			CommandIterNextSent--;
		if (CommandIterNextACK == CommandList.end())
			CommandIterNextACK--;
	}
}

void Plannar::updateQueueStatus(Feedback* fb) {
	// for debugging
//    checkStatusTurn(fb);

	std::cout << "--- Feedback, Seq = " << fb->getSeq() << ", Hour = "
			<< fb->getHour() << ", Time = " << fb->getTime() << ", Buffer: "
			<< fb->getBufferFront() << " - " << fb->getBufferLast()
			<< ", Text = " << fb->getText();

	updateFrequencyPerformance(fb);

	std::cout << std::endl;

	if (fb->getText() == "STOP immediately")
		stopRecv(fb);
	else if (fb->getText() == "PAUSE immediately")
		pauseImmRecv(fb);
	else if (fb->getText() == "TERMINATE immediately")
		terminateImmRecv(fb);
	else if (fb->getText() == "TERMINATE buffered")
		terminateBufRecv(fb);
	else
		updateIterators(fb);

	queryNextCommand();

	lastAxis_.set(fb->getAxis());

//    printFeedbackBasic();
//    printCommandList();
	emit newFeedback(fb);
}

void Plannar::updateCommandIterNextACK(Feedback* fb) {
	int fbType = fb->getType();
	int fbSuccess = fb->getSuccess();
	int fbStamp = fb->getStamp();

	// update CommandIterNextACK
	if (fbType == Feedback::Hybrid) {
		std::list<Command*>::iterator tp_it = CommandIterNextACK;
		for (tp_it = CommandIterNextACK; tp_it != CommandList.end(); tp_it++) {
			if (fbStamp == (*tp_it)->getStamp()) {
				if ((*tp_it)->getState() == Command::NOFEEDBACK) {
					if (fbSuccess)
						(*tp_it)->setState(Command::BUFFERED);
					else
						(*tp_it)->setState(Command::ERROR);
				}
				std::cout << "--- Command ACK, stamp: " << fbStamp << std::endl;
				CommandIterNextACK = tp_it;
				break;
			}
		}
		CommandIterNextACK++;
	}
}

void Plannar::updateCommandIterBufFront(Feedback* fb) {
	// update CommandIterBufFront
	int stepFront = fb->getBufferFront() - KRLBufFront;
	if (stepFront < 0)
		stepFront += KRL_BUF_LEN;
	while (stepFront != 0) {
		if ((*CommandIterBufFront)->getState() != Command::ERROR
				&& (*CommandIterBufFront)->getState() != Command::SUCCESS)
			stepFront--;
		CommandIterBufFront++;
	}
	while (((*CommandIterBufFront)->getState() == Command::ERROR
			|| (*CommandIterBufFront)->getState() == Command::SUCCESS)
			&& CommandIterBufFront != CommandList.end())
		CommandIterBufFront++;

	KRLBufFront = fb->getBufferFront();
}

void Plannar::stopRecv(Feedback* fb) {
	std::list<Command*>::iterator tp_it = CommandIterBufFront;
	for (; tp_it != CommandIterNextACK; tp_it++)
		(*tp_it)->setState(Command::ERROR);
	if (fb->getSuccess())
		(*CommandIterNextACK)->setState(Command::SUCCESS);
	else
		(*CommandIterNextACK)->setState(Command::ERROR);
	CommandIterBufLast = CommandIterNextSent;
	CommandIterNextACK++;

	updateCommandIterBufFront(fb);

	KRLBufLast = fb->getBufferLast();
}

void Plannar::pauseImmRecv(Feedback *fb) {
	updateCommandIterNextACK(fb);

	// update CommandIterBufLast
	if (fb->getSuccess())
		(*CommandIterBufLast)->setState(Command::SUCCESS);
	else
		(*CommandIterBufLast)->setState(Command::ERROR);
	CommandIterBufLast++;

	updateCommandIterBufFront(fb);

	KRLBufLast = fb->getBufferLast();
}

void Plannar::terminateImmRecv(Feedback* fb) {
	std::list<Command*>::iterator tp_it = CommandIterBufFront;
	if (tp_it != CommandIterNextACK) {
		for (tp_it++; tp_it != CommandIterNextACK; tp_it++)
			(*tp_it)->setState(Command::ERROR);
	}
	if (fb->getSuccess())
		(*CommandIterNextACK)->setState(Command::BUFFERED);
	else
		(*CommandIterNextACK)->setState(Command::ERROR);
	for (tp_it++; tp_it != CommandList.end(); tp_it++)
		(*tp_it)->setState(Command::ERROR);
	CommandIterBufLast = CommandList.end();
	CommandIterNextACK = CommandList.end();
	CommandIterNextSent = CommandList.end();

	updateCommandIterBufFront(fb);

	KRLBufLast = fb->getBufferLast();
}

void Plannar::terminateBufRecv(Feedback* fb) {
	std::list<Command*>::iterator tp_it = CommandIterNextACK;
	for (tp_it++; tp_it != CommandList.end(); tp_it++)
		(*tp_it)->setState(Command::ERROR);
	if (fb->getSuccess())
		(*CommandIterNextACK)->setState(Command::BUFFERED);
	else
		(*CommandIterNextACK)->setState(Command::ERROR);
	CommandIterNextACK = CommandList.end();
	CommandIterBufLast = CommandList.end();

	updateCommandIterBufFront(fb);

	KRLBufLast = fb->getBufferLast();
	CommandIterNextSent = CommandList.end();
}

void Plannar::queryNextCommand() {
	// send next command
	if (CommandIterNextSent != CommandList.end()) {
		if (std::distance(CommandIterBufFront,
				CommandIterBufLast) < KRL_BUF_THRESHOLD) {
			std::cout << "+++ Command sent, stamp: "
					<< (*CommandIterNextSent)->getStamp() << std::endl;
			sendMessage((*CommandIterNextSent)->getMessage());
			CommandIterNextSent++;
		} else if (std::distance(CommandIterBufFront, CommandIterBufLast)
				< KRL_BUF_THRESHOLD + KRL_BUF_THRESHOLD / 2
				&& (*CommandIterNextSent)->getEmergent()) {
			std::cout << "+++ Command sent, stamp: "
					<< (*CommandIterNextSent)->getStamp() << std::endl;
			sendMessage((*CommandIterNextSent)->getMessage());
			CommandIterNextSent++;
		}
	}
}

void Plannar::updateIterators(Feedback* fb) {
	updateCommandIterNextACK(fb);

	// update ComamndIterBufFront & CommandIterBufLast
	int stepLast = fb->getBufferLast() - KRLBufLast;
	int stepFront = fb->getBufferFront() - KRLBufFront;
	if (stepLast != 0 || stepFront != 0) {
		if (stepLast < 0)
			stepLast += KRL_BUF_LEN;
		if (stepFront < 0)
			stepFront += KRL_BUF_LEN;
		while (stepLast != 0) {
			if ((*CommandIterBufLast)->getState() != Command::ERROR
					&& (*CommandIterBufLast)->getState() != Command::SUCCESS)
				stepLast--;
			CommandIterBufLast++;
		}
		while (((*CommandIterBufLast)->getState() == Command::ERROR
				|| (*CommandIterBufLast)->getState() == Command::SUCCESS)
				&& CommandIterBufLast != CommandList.end())
			CommandIterBufLast++;
		while (stepFront != 0) {
			if ((*CommandIterBufFront)->getState() != Command::ERROR
					&& (*CommandIterBufFront)->getState() != Command::SUCCESS)
				stepFront--;
			CommandIterBufFront++;
		}
		while (((*CommandIterBufFront)->getState() == Command::ERROR
				|| (*CommandIterBufFront)->getState() == Command::SUCCESS)
				&& CommandIterBufFront != CommandList.end())
			CommandIterBufFront++;
		KRLBufFront = fb->getBufferFront();
		KRLBufLast = fb->getBufferLast();
	}
}

void Plannar::updateFrequencyPerformance(Feedback* fb) {
	if (feedbackCount_ == 0) {
		feedbackCount_++;
		lastTime_ = fb->getTime();
		firstTime_ = fb->getTime();
	} else {
		feedbackCount_++;
		std::cout << ", Cycle time: " << lastTime_ - fb->getTime() << " ms,";
		lastTime_ = fb->getTime();
		averageTime_ = (double) (firstTime_ - lastTime_)
				/ (double) (feedbackCount_ - 1);
		std::cout << " Avg time: " << averageTime_ << " ms";
	}
}

void Plannar::printFeedbackBasic() {
	std::cout << "       Buffer status: ";
	if (CommandIterBufFront == CommandList.end())
		std::cout << "end / ";
	else
		std::cout << (*CommandIterBufFront)->getStamp() << " / ";
	if (CommandIterBufLast == CommandList.end())
		std::cout << "end" << std::endl;
	else
		std::cout << (*CommandIterBufLast)->getStamp() << std::endl;
}

void Plannar::printCommandList() {
	std::list<Command*>::iterator tp_it;
	for (tp_it = CommandList.begin(); tp_it != CommandList.end(); tp_it++) {
		if ((*tp_it)->getState() == Command::ERROR)
			std::cout << std::setw(5) << "ER";
		else if ((*tp_it)->getState() == Command::NOFEEDBACK)
			std::cout << std::setw(5) << "NO";
		else if ((*tp_it)->getState() == Command::BUFFERED)
			std::cout << std::setw(5) << "BF";
		else
			std::cout << std::setw(5) << "XX";
	}
	std::cout << std::endl;
	for (tp_it = CommandList.begin(); tp_it != CommandList.end(); tp_it++) {
		std::cout << std::setw(5) << (*tp_it)->getAxis().A1;
	}
	std::cout << std::setw(5) << "END";
	std::cout << std::endl;
	for (tp_it = CommandList.begin(); tp_it != CommandList.end(); tp_it++) {
		if (tp_it == CommandIterBufFront)
			std::cout << std::setw(5) << "F";
		else
			std::cout << std::setw(5) << " ";
	}
	if (CommandIterBufFront == CommandList.end())
		std::cout << std::setw(5) << "F";
	std::cout << std::endl;
	for (tp_it = CommandList.begin(); tp_it != CommandList.end(); tp_it++) {
		if (tp_it == CommandIterBufLast)
			std::cout << std::setw(5) << "L";
		else
			std::cout << std::setw(5) << " ";
	}
	if (CommandIterBufLast == CommandList.end())
		std::cout << std::setw(5) << "L";
	std::cout << std::endl;
	for (tp_it = CommandList.begin(); tp_it != CommandList.end(); tp_it++) {
		if (tp_it == CommandIterNextSent)
			std::cout << std::setw(5) << "NS";
		else
			std::cout << std::setw(5) << " ";
	}
	if (CommandIterNextSent == CommandList.end())
		std::cout << std::setw(5) << "NS";
	std::cout << std::endl;
	for (tp_it = CommandList.begin(); tp_it != CommandList.end(); tp_it++) {
		if (tp_it == CommandIterNextACK)
			std::cout << std::setw(5) << "NA";
		else
			std::cout << std::setw(5) << " ";
	}
	if (CommandIterNextACK == CommandList.end())
		std::cout << std::setw(5) << "NA";
	std::cout << std::endl;
}

void Plannar::terminateBuffered() {
	appendCommandList(
			new Command(Command::Other, Command::Terminate, ++stamp_));
}

void Plannar::terminateImmediately() {
	appendCommandList(
			new Command(Command::Other, Command::TerminateImm, ++stamp_));
}

void Plannar::pauseBuffered() {
	appendCommandList(new Command(Command::Other, Command::PauseBuf, ++stamp_));
}

void Plannar::pauseImmediately() {
	appendCommandList(new Command(Command::Other, Command::Pause, ++stamp_));
}

void Plannar::stop() {
	appendCommandList(new Command(Command::Other, Command::Stop, ++stamp_));
}

void Plannar::motion(Command::Style style, Frame &f, Command::Approx approx) {
	if (!reachableCheck(f))
		std::cout << "Plannar::motion: Error, Frame not reachable" << std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, f, ++stamp_, approx));
}

void Plannar::motion(Command::Style style, Axis &a, Command::Approx approx) {
	if (!reachableCheck(a))
		std::cout << "Plannar::motion: Error, axis not reachable" << std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, a, ++stamp_, approx));
}

void Plannar::motion(Command::Style style, Pos &p, Command::Approx approx) {
	if (!reachableCheck(p))
		std::cout << "Plannar::motion: Error, Pos not reachable" << std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, p, ++stamp_, approx));
}

void Plannar::motion(Command::Style style, Frame &f_end, Frame &f_aux,
		float degree, Command::Approx approx) {
	if (!reachableCheck(f_end))
		std::cout << "Plannar::motion: Error, end point Frame not reachable"
				<< std::endl;
	else if (!reachableCheck(f_aux))
		std::cout
				<< "Plannar::motion: Error, auxiliary point Frame not reachable"
				<< std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, f_end, f_aux, degree,
						++stamp_, approx));
}

void Plannar::motion(Command::Style style, Frame &f_end, Axis &a_aux,
		float degree, Command::Approx approx) {
	if (!reachableCheck(f_end))
		std::cout << "Plannar::motion: Error, end point Frame not reachable"
				<< std::endl;
	else if (!reachableCheck(a_aux))
		std::cout
				<< "Plannar::motion: Error, auxiliary point Axis not reachable"
				<< std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, f_end, a_aux, degree,
						++stamp_, approx));
}

void Plannar::motion(Command::Style style, Frame &f_end, Pos &p_aux,
		float degree, Command::Approx approx) {
	if (!reachableCheck(f_end))
		std::cout << "Plannar::motion: Error, end point Frame not reachable"
				<< std::endl;
	else if (!reachableCheck(p_aux))
		std::cout << "Plannar::motion: Error, auxiliary point Pos not reachable"
				<< std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, f_end, p_aux, degree,
						++stamp_, approx));
}

void Plannar::motion(Command::Style style, Axis &a_end, Frame &f_aux,
		float degree, Command::Approx approx) {
	if (!reachableCheck(a_end))
		std::cout << "Plannar::motion: Error, end point Axis not reachable"
				<< std::endl;
	else if (!reachableCheck(f_aux))
		std::cout
				<< "Plannar::motion: Error, auxiliary point Frame not reachable"
				<< std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, a_end, f_aux, degree,
						++stamp_, approx));
}

void Plannar::motion(Command::Style style, Axis &a_end, Axis &a_aux,
		float degree, Command::Approx approx) {
	if (!reachableCheck(a_end))
		std::cout << "Plannar::motion: Error, end point Axis not reachable"
				<< std::endl;
	else if (!reachableCheck(a_aux))
		std::cout
				<< "Plannar::motion: Error, auxiliary point Axis not reachable"
				<< std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, a_end, a_aux, degree,
						++stamp_, approx));
}

void Plannar::motion(Command::Style style, Axis &a_end, Pos &p_aux,
		float degree, Command::Approx approx) {
	if (!reachableCheck(a_end))
		std::cout << "Plannar::motion: Error, end point Axis not reachable"
				<< std::endl;
	else if (!reachableCheck(p_aux))
		std::cout << "Plannar::motion: Error, auxiliary point Pos not reachable"
				<< std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, a_end, p_aux, degree,
						++stamp_, approx));
}

void Plannar::motion(Command::Style style, Pos &p_end, Frame &f_aux,
		float degree, Command::Approx approx) {
	if (!reachableCheck(p_end))
		std::cout << "Plannar::motion: Error, end point Pos not reachable"
				<< std::endl;
	else if (!reachableCheck(f_aux))
		std::cout
				<< "Plannar::motion: Error, auxiliary point Frame not reachable"
				<< std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, p_end, f_aux, degree,
						++stamp_, approx));
}

void Plannar::motion(Command::Style style, Pos &p_end, Axis &a_aux,
		float degree, Command::Approx approx) {
	if (!reachableCheck(p_end))
		std::cout << "Plannar::motion: Error, end point Pos not reachable"
				<< std::endl;
	else if (!reachableCheck(a_aux))
		std::cout
				<< "Plannar::motion: Error, auxiliary point Axis not reachable"
				<< std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, p_end, a_aux, degree,
						++stamp_, approx));
}

void Plannar::motion(Command::Style style, Pos &p_end, Pos &p_aux, float degree,
		Command::Approx approx) {
	if (!reachableCheck(p_end))
		std::cout << "Plannar::motion: Error, end point Pos not reachable"
				<< std::endl;
	else if (!reachableCheck(p_aux))
		std::cout << "Plannar::motion: Error, auxiliary point Pos not reachable"
				<< std::endl;
	else
		appendCommandList(
				new Command(Command::Motion, style, p_end, p_aux, degree,
						++stamp_, approx));
}

bool Plannar::reachableCheck(Axis& a) {
	bool reachable = true;
	if (a.A1 > A1_UPPER || a.A1 < A1_LOWER)
		reachable = false;
	if (a.A2 > A2_UPPER || a.A2 < A2_LOWER)
		reachable = false;
	if (a.A3 > A3_UPPER || a.A3 < A3_LOWER)
		reachable = false;
	if (a.A4 > A4_UPPER || a.A4 < A4_LOWER)
		reachable = false;
	if (a.A5 > A5_UPPER || a.A5 < A5_LOWER)
		reachable = false;
	if (a.A6 > A6_UPPER || a.A6 < A6_LOWER)
		reachable = false;

	return reachable;
}
// reachableCheck for Frame and Pos is not accomplished yet
bool Plannar::reachableCheck(Frame &f) {
//    Axis a_convert;
//    if ( robot.Frame2Axis(lastAxis_, f, a_convert) )
//        return reachableCheck(a_convert);
//    else
//        return false;
	return true;
}

bool Plannar::reachableCheck(Pos &p) {
//    Axis a_convert;
//    if ( robot.Pos2Axis(lastAxis_, p, a_convert) )
//        return reachableCheck(a_convert);
//    else
//        return false;
	return true;
}

void Plannar::configuration(Command::Param param, float number) {
	if (param < Command::ADVANCE || param > Command::APO_CORI) {
		std::cout << "Plannar::configuration: Param out of range" << std::endl;
		return;
	}
	if (param == Command::ADVANCE) {
		if (number < -0.1 || number > 5.1) {
			std::cout
					<< "Plannar::configuration: $ADVANCE value should be in 0 - 5"
					<< std::endl;
			return;
		}
	}
	appendCommandList(new Command(Command::Config, param, number, ++stamp_));
	if (param == Command::ADVANCE)
		advance_ = number;
}

void Plannar::test() {
	testRandomWalk(50);
}

void Plannar::axisCycles(int cycle) {
	Axis a;
	if (cycle > 0) {
		for (int i = 0; i < cycle; i++) {
			a.set(60.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(120.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(60.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(0.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(-60.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(-120.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(-60.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(0.0);
			motion(Command::PTP, a, Command::C_DIS);
		}
	} else {
		for (int i = 0; i < -cycle; i++) {
			a.set(-60.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(-120.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(-60.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(0.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(60.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(120.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(60.0);
			motion(Command::PTP, a, Command::C_DIS);
			a.set(0.0);
			motion(Command::PTP, a, Command::C_DIS);
		}
	}
}

void Plannar::testAxisCycle() {
	configuration(Command::APO_CDIS, 1);
	configuration(Command::ADVANCE, 1);
	configuration(Command::VEL_PTP, 10.0);
	axisCycles(2);
	terminateBuffered();
}

void Plannar::testApproximation() {
	configuration(Command::APO_CDIS, 0.01);
	configuration(Command::ADVANCE, 0);
	configuration(Command::VEL_PTP, 10.0);
	axisCycles();

	configuration(Command::ADVANCE, 1);
	configuration(Command::APO_CDIS, 1);
	axisCycles();
	terminateBuffered();
}

void Plannar::testStop() {
	configuration(Command::APO_CDIS, 1);
	configuration(Command::ADVANCE, 3);
	configuration(Command::VEL_PTP, 10.0);

	axisCycles(1);
	stop();
	axisCycles(-1);
	terminateBuffered();
}

void Plannar::testPauseBuf() {
	configuration(Command::APO_CDIS, 1);
	configuration(Command::ADVANCE, 1);
	configuration(Command::VEL_PTP, 10.0);

	axisCycles(1);
	pauseBuffered();
	axisCycles(-1);
	terminateBuffered();
}

void Plannar::testPauseImm() {
	configuration(Command::APO_CDIS, 1);
	configuration(Command::ADVANCE, 1);
	configuration(Command::VEL_PTP, 10.0);

	axisCycles(1);
	pauseImmediately();
	axisCycles(-1);
	terminateBuffered();
}

void Plannar::testTerminateBuf() {
	configuration(Command::APO_CDIS, 1);
	configuration(Command::ADVANCE, 0);
	configuration(Command::VEL_PTP, 10.0);

	axisCycles(1);
	terminateBuffered();
	axisCycles(-1);
	terminateBuffered();
}

void Plannar::testTerminateImm() {
	configuration(Command::APO_CDIS, 1);
	configuration(Command::ADVANCE, 2);
	configuration(Command::VEL_PTP, 10.0);

	axisCycles(1);
	terminateImmediately();
	axisCycles(-1);
	terminateBuffered();
}

void Plannar::testKRLBuffer() {
	configuration(Command::APO_CDIS, 1);
	configuration(Command::ADVANCE, 0);
	configuration(Command::VEL_PTP, 10.0);
	axisCycles(20);
	terminateBuffered();
}

void Plannar::testRandomWalk(int count) {
	Axis a;
	srand(static_cast<unsigned>(time(0)));
	for (int i = 0; i < count; i++) {
		a.A1 = -120
				+ static_cast<float>(rand())
						/ (static_cast<float>(RAND_MAX / (240)));
		a.A2 = -120
				+ static_cast<float>(rand())
						/ (static_cast<float>(RAND_MAX / (60)));
		a.A3 = -90
				+ static_cast<float>(rand())
						/ (static_cast<float>(RAND_MAX / (180)));
		a.A4 =
				A4_LOWER
						+ static_cast<float>(rand())
								/ (static_cast<float>(RAND_MAX
										/ (A4_UPPER - A4_LOWER)));
		a.A5 =
				A5_LOWER
						+ static_cast<float>(rand())
								/ (static_cast<float>(RAND_MAX
										/ (A5_UPPER - A5_LOWER)));
		a.A6 =
				A6_LOWER
						+ static_cast<float>(rand())
								/ (static_cast<float>(RAND_MAX
										/ (A6_UPPER - A6_LOWER)));
		motion(Command::PTP, a, Command::C_DIS);
	}

}

bool Plannar::checkStatusTurn(Feedback *fb) {
	Pos p_convert;

	if (robot_.Axis2Pos(fb->getAxis(), p_convert)) {
		if (p_convert.S != fb->getPos().S) {
			std::cout << "Plannar::checkStatusTurn: Error, Status not match"
					<< std::endl;
			fb->getAxis().printAxis();
			std::cout << "Converted ";
			p_convert.printPos();
			std::cout << "Feedback  ";
			fb->getPos().printPos();
			return false;
		}
		if (p_convert.T != fb->getPos().T) {
			std::cout << "Plannar::checkStatusTurn: Error, Turn not match"
					<< std::endl;
			fb->getAxis().printAxis();
			std::cout << "Converted ";
			p_convert.printPos();
			std::cout << "Feedback  ";
			fb->getPos().printPos();
			return false;
		}
		return true;
	} else {
		std::cout << "Plannar::checkStatusTurn: Error, Axis2Pos failed"
				<< std::endl;
		return false;
	}
}

void Plannar::plot(Frame::Param val, int count, plotWindow::PlotMethod pm) {
	int total = FeedbackList.size();
	int plotnumber = count;
	if (total < count) {
		std::cout
				<< "Plannar::plot: Warning, data not adequate, plot all available"
				<< std::endl;
		plotnumber = total;
	}
	if (count == DEF_PLOT_ALL)
		plotnumber = total;
	if (plotnumber <= 0) {
		std::cout << "Plannar::plot: Error, no data available" << std::endl;
		return;
	}
	QVector<double> val_vct;
	std::list<Feedback*>::iterator it = FeedbackList.end();
	QString xlabel;
	QString ylabel;
	double y1 = 0.0;
	double y2 = 0.0;
	if (val == Frame::ValX) {
		xlabel = "Frame.X";
		ylabel = "mm";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().X);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Frame::ValY) {
		xlabel = "Frame.Y";
		ylabel = "mm";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().Y);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Frame::ValZ) {
		xlabel = "Frame.Z";
		ylabel = "mm";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().Z);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Frame::ValA) {
		xlabel = "Frame.A";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().A);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Frame::ValB) {
		xlabel = "Frame.B";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().B);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Frame::ValC) {
		xlabel = "Frame.C";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().C);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else {
		std::cout << "Plannar::plot, Error, Val not recognized" << std::endl;
		return;
	}

	if (pm == plotWindow::NewPlot) {
		plot_.newPlot(val_vct);
	} else if (pm == plotWindow::AddPlot) {
		plot_.addPlot(val_vct);
	} else {
		std::cout << "Plannar::plot: Error, plot method not recognized"
				<< std::endl;
		return;
	}

	plot_.setLabel(xlabel, ylabel);
	plot_.setName(xlabel);
	plot_.setLineStyle(QCPGraph::lsLine);
	plot_.setScatterStyle(QCPScatterStyle::ssCircle, 2);
	plot_.setRange(0, plotnumber + 1, y1 - (y2 - y1) / 10.0,
			y2 + (y2 - y1) / 10.0);
	plot_.display();
}

void Plannar::plot(Axis::Param val, int count, plotWindow::PlotMethod pm) {
	int total = FeedbackList.size();
	int plotnumber = count;
	if (total < count) {
		std::cout
				<< "Plannar::plot: Warning, data not adequate, plot all available"
				<< std::endl;
		plotnumber = total;
	}
	if (count == DEF_PLOT_ALL)
		plotnumber = total;
	if (plotnumber <= 0) {
		std::cout << "Plannar::plot: Error, no data available" << std::endl;
		return;
	}
	QVector<double> val_vct;
	std::list<Feedback*>::iterator it = FeedbackList.end();
	QString xlabel;
	QString ylabel;
	double y1 = 0.0;
	double y2 = 0.0;
	if (val == Axis::ValA1) {
		xlabel = "Axis.A1";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A1);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Axis::ValA2) {
		xlabel = "Axis.A2";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A2);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Axis::ValA3) {
		xlabel = "Axis.A3";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A3);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Axis::ValA4) {
		xlabel = "Axis.A4";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A4);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Axis::ValA5) {
		xlabel = "Axis.A5";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A5);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Axis::ValA6) {
		xlabel = "Axis.A6";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A6);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else {
		std::cout << "Plannar::plot, Error, Val not recognized" << std::endl;
		return;
	}

	if (pm == plotWindow::NewPlot) {
		plot_.newPlot(val_vct);
	} else if (pm == plotWindow::AddPlot) {
		plot_.addPlot(val_vct);
	} else {
		std::cout << "Plannar::plot: Error, plot method not recognized"
				<< std::endl;
		return;
	}

	plot_.setLabel(xlabel, ylabel);
	plot_.setName(xlabel);
	plot_.setLineStyle(QCPGraph::lsLine);
	plot_.setScatterStyle(QCPScatterStyle::ssCircle, 2);
	plot_.setRange(0, plotnumber + 1, y1 - (y2 - y1) / 10.0,
			y2 + (y2 - y1) / 10.0);
	plot_.display();
}

void Plannar::plot(Pos::Param val, int count, plotWindow::PlotMethod pm) {
	int total = FeedbackList.size();
	int plotnumber = count;
	if (total < count) {
		std::cout
				<< "Plannar::plot: Warning, data not adequate, plot all available"
				<< std::endl;
		plotnumber = total;
	}
	if (count == DEF_PLOT_ALL)
		plotnumber = total;
	if (plotnumber <= 0) {
		std::cout << "Plannar::plot: Error, no data available" << std::endl;
		return;
	}
	QVector<double> val_vct;
	std::list<Feedback*>::iterator it = FeedbackList.end();
	QString xlabel;
	QString ylabel;
	double y1 = 0.0;
	double y2 = 0.0;
	if (val == Pos::ValX) {
		xlabel = "Pos::ValX";
		ylabel = "mm";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.X);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Pos::ValY) {
		xlabel = "Pos::ValY";
		ylabel = "mm";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.Y);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Pos::ValZ) {
		xlabel = "Pos::ValZ";
		ylabel = "mm";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.Z);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Pos::ValA) {
		xlabel = "Pos::ValA";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.A);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Pos::ValB) {
		xlabel = "Pos::ValB";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.B);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Pos::ValC) {
		xlabel = "Pos::ValC";
		ylabel = "deg";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.C);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Pos::ValS) {
		xlabel = "Pos::ValS";
		ylabel = "val";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().S);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val == Pos::ValT) {
		xlabel = "Pos::ValT";
		ylabel = "val";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().T);
			val_vct.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else {
		std::cout << "Plannar::plot, Error, Val not recognized" << std::endl;
		return;
	}

	if (pm == plotWindow::NewPlot) {
		plot_.newPlot(val_vct);
	} else if (pm == plotWindow::AddPlot) {
		plot_.addPlot(val_vct);
	} else {
		std::cout << "Plannar::plot: Error, plot method not recognized"
				<< std::endl;
		return;
	}

	plot_.setLabel(xlabel, ylabel);
	plot_.setName(xlabel);
	plot_.setLineStyle(QCPGraph::lsLine);
	plot_.setScatterStyle(QCPScatterStyle::ssCircle, 2);
	plot_.setRange(0, plotnumber + 1, y1 - (y2 - y1) / 10.0,
			y2 + (y2 - y1) / 10.0);
	plot_.display();
}

void Plannar::plot(Frame::Param val1, Frame::Param val2, int count,
		plotWindow::PlotMethod pm) {
	int total = FeedbackList.size();
	int plotnumber = count;
	if (total < count) {
		std::cout
				<< "Plannar::plot: Warning, data not adequate, plot all available"
				<< std::endl;
		plotnumber = total;
	}
	if (count == DEF_PLOT_ALL)
		plotnumber = total;
	if (plotnumber <= 0) {
		std::cout << "Plannar::plot: Error, no data available" << std::endl;
		return;
	}
	QVector<double> val_vct1;
	QVector<double> val_vct2;
	std::list<Feedback*>::iterator it = FeedbackList.end();
	QString xlabel;
	QString ylabel;
	double x1 = 0.0;
	double x2 = 0.0;
	double y1 = 0.0;
	double y2 = 0.0;
	if (val1 == Frame::ValX) {
		xlabel = "Frame.X (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().X);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Frame::ValY) {
		xlabel = "Frame.Y (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().Y);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Frame::ValZ) {
		xlabel = "Frame.Z (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().Z);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Frame::ValA) {
		xlabel = "Frame.A (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().A);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Frame::ValB) {
		xlabel = "Frame.B (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().B);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Frame::ValC) {
		xlabel = "Frame.C (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().C);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else {
		std::cout << "Plannar::plot, Error, Val1 not recognized" << std::endl;
		return;
	}

	it = FeedbackList.end();
	if (val2 == Frame::ValX) {
		ylabel = "Frame.X (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().X);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Frame::ValY) {
		ylabel = "Frame.Y (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().Y);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Frame::ValZ) {
		ylabel = "Frame.Z (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().Z);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Frame::ValA) {
		ylabel = "Frame.A (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().A);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Frame::ValB) {
		ylabel = "Frame.B (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().B);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Frame::ValC) {
		ylabel = "Frame.C (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getFrame().C);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else {
		std::cout << "Plannar::plot, Error, Val2 not recognized" << std::endl;
		return;
	}

	if (pm == plotWindow::NewPlot) {
		plot_.newPlot(val_vct1, val_vct2);
	} else if (pm == plotWindow::AddPlot) {
		plot_.addPlot(val_vct1, val_vct2);
	} else {
		std::cout << "Plannar::plot: Error, plot method not recognized"
				<< std::endl;
		return;
	}

	plot_.setLabel(xlabel, ylabel);
	plot_.setName(ylabel + " / " + xlabel);
	plot_.setLineStyle(QCPGraph::lsNone);
	plot_.setScatterStyle(QCPScatterStyle::ssCircle, 2);
	plot_.setRange(x1 - (x2 - x1) / 10.0, x2 + (x2 - x1) / 10.0,
			y1 - (y2 - y1) / 10.0, y2 + (y2 - y1) / 10.0);
	plot_.display();
}

void Plannar::plot(Axis::Param val1, Axis::Param val2, int count,
		plotWindow::PlotMethod pm) {
	int total = FeedbackList.size();
	int plotnumber = count;
	if (total < count) {
		std::cout
				<< "Plannar::plot: Warning, data not adequate, plot all available"
				<< std::endl;
		plotnumber = total;
	}
	if (count == DEF_PLOT_ALL)
		plotnumber = total;
	if (plotnumber <= 0) {
		std::cout << "Plannar::plot: Error, no data available" << std::endl;
		return;
	}
	QVector<double> val_vct1;
	QVector<double> val_vct2;
	std::list<Feedback*>::iterator it = FeedbackList.end();
	QString xlabel;
	QString ylabel;
	double x1 = 0.0;
	double x2 = 0.0;
	double y1 = 0.0;
	double y2 = 0.0;
	if (val1 == Axis::ValA1) {
		xlabel = "Axis.A1 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A1);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Axis::ValA2) {
		xlabel = "Axis.A2 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A2);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Axis::ValA3) {
		xlabel = "Axis.A3 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A3);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Axis::ValA4) {
		xlabel = "Axis.A4 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A4);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Axis::ValA5) {
		xlabel = "Axis.A5 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A5);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Axis::ValA6) {
		xlabel = "Axis.A6 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A6);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else {
		std::cout << "Plannar::plot, Error, Val1 not recognized" << std::endl;
		return;
	}

	it = FeedbackList.end();
	if (val2 == Axis::ValA1) {
		ylabel = "Axis.A1 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A1);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Axis::ValA2) {
		ylabel = "Axis.A2 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A2);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Axis::ValA3) {
		ylabel = "Axis.A3 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A3);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Axis::ValA4) {
		ylabel = "Axis.A4 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A4);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Axis::ValA5) {
		ylabel = "Axis.A5 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A5);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Axis::ValA6) {
		ylabel = "Axis.A6 (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getAxis().A6);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else {
		std::cout << "Plannar::plot, Error, Val2 not recognized" << std::endl;
		return;
	}

	if (pm == plotWindow::NewPlot) {
		plot_.newPlot(val_vct1, val_vct2);
	} else if (pm == plotWindow::AddPlot) {
		plot_.addPlot(val_vct1, val_vct2);
	} else {
		std::cout << "Plannar::plot: Error, plot method not recognized"
				<< std::endl;
		return;
	}

	plot_.setLabel(xlabel, ylabel);
	plot_.setName(ylabel + " / " + xlabel);
	plot_.setLineStyle(QCPGraph::lsNone);
	plot_.setScatterStyle(QCPScatterStyle::ssCircle, 2);
	plot_.setRange(x1 - (x2 - x1) / 10.0, x2 + (x2 - x1) / 10.0,
			y1 - (y2 - y1) / 10.0, y2 + (y2 - y1) / 10.0);
	plot_.display();
}

void Plannar::plot(Pos::Param val1, Pos::Param val2, int count,
		plotWindow::PlotMethod pm) {
	int total = FeedbackList.size();
	int plotnumber = count;
	if (total < count) {
		std::cout
				<< "Plannar::plot: Warning, data not adequate, plot all available"
				<< std::endl;
		plotnumber = total;
	}
	if (count == DEF_PLOT_ALL)
		plotnumber = total;
	if (plotnumber <= 0) {
		std::cout << "Plannar::plot: Error, no data available" << std::endl;
		return;
	}
	QVector<double> val_vct1;
	QVector<double> val_vct2;
	std::list<Feedback*>::iterator it = FeedbackList.end();
	QString xlabel;
	QString ylabel;
	double x1 = 0.0;
	double x2 = 0.0;
	double y1 = 0.0;
	double y2 = 0.0;
	if (val1 == Pos::ValX) {
		xlabel = "Pos.X (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.X);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Pos::ValY) {
		xlabel = "Pos.Y (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.Y);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Pos::ValZ) {
		xlabel = "Pos.Z (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.Z);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Pos::ValA) {
		xlabel = "Pos.A (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.A);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Pos::ValB) {
		xlabel = "Pos.B (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.B);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Pos::ValC) {
		xlabel = "Pos.C (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.C);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Pos::ValT) {
		xlabel = "Pos.T";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().T);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else if (val1 == Pos::ValS) {
		xlabel = "Pos.S";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().S);
			val_vct1.push_front(v);
			if (v < x1)
				x1 = v;
			if (v > x2)
				x2 = v;
		}
	} else {
		std::cout << "Plannar::plot, Error, Val1 not recognized" << std::endl;
		return;
	}

	it = FeedbackList.end();
	if (val2 == Pos::ValX) {
		ylabel = "Pos.X (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.X);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Pos::ValY) {
		ylabel = "Pos.Y (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.Y);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Pos::ValZ) {
		ylabel = "Pos.Z (mm)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.Z);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Pos::ValA) {
		ylabel = "Pos.A (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.A);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Pos::ValB) {
		ylabel = "Pos.B (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.B);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Pos::ValC) {
		ylabel = "Pos.C (deg)";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().F.C);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Pos::ValS) {
		ylabel = "Pos.S";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().S);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else if (val2 == Pos::ValT) {
		ylabel = "Pos.T";
		for (int i = 0; i < plotnumber; i++) {
			if (it == FeedbackList.begin()) {
				std::cout << "Plannar::plot: Warning, data not adequate"
						<< std::endl;
				plotnumber = std::distance(it, FeedbackList.end());
				break;
			}
			it--;
			double v = (double) ((*it)->getPos().T);
			val_vct2.push_front(v);
			if (v < y1)
				y1 = v;
			if (v > y2)
				y2 = v;
		}
	} else {
		std::cout << "Plannar::plot, Error, Val2 not recognized" << std::endl;
		return;
	}

	if (pm == plotWindow::NewPlot) {
		plot_.newPlot(val_vct1, val_vct2);
	} else if (pm == plotWindow::AddPlot) {
		plot_.addPlot(val_vct1, val_vct2);
	} else {
		std::cout << "Plannar::plot: Error, plot method not recognized"
				<< std::endl;
		return;
	}

	plot_.setLabel(xlabel, ylabel);
	plot_.setName(ylabel + " / " + xlabel);
	plot_.setLineStyle(QCPGraph::lsNone);
	plot_.setScatterStyle(QCPScatterStyle::ssCircle, 2);
	plot_.setRange(x1 - (x2 - x1) / 10.0, x2 + (x2 - x1) / 10.0,
			y1 - (y2 - y1) / 10.0, y2 + (y2 - y1) / 10.0);
	plot_.display();
}

void Plannar::clearPlots() {
	plot_.clearPlots();
}

TCPThread& Plannar::getTCPThread() {
	return tcpThread_;
}

Model& Plannar::getModel() {
	return robot_;
}

plotWindow& Plannar::getPlotWindow() {
	return plot_;
}

std::list<Command*>& Plannar::getCommandList() {
	return CommandList;
}

std::list<Feedback*>& Plannar::getFeedbackList() {
	return FeedbackList;
}

std::list<Command*>::iterator& Plannar::getCommandIterBufFront() {
	return CommandIterBufFront;
}

std::list<Command*>::iterator& Plannar::getCommandIterBufLast() {
	return CommandIterBufLast;
}

std::list<Command*>::iterator& Plannar::getCommandIterNextACK() {
	return CommandIterNextACK;
}

std::list<Command*>::iterator& Plannar::getCommandIterNextSent() {
	return CommandIterNextSent;
}

int Plannar::getFeedbackCount() {
	return feedbackCount_;
}
