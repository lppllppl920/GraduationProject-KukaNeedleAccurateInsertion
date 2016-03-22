/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 20 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#include "tcpthread.h"
#include <iostream>

TCPThread::TCPThread(quint16 port) {
	std::cout << "TCPThread Constructing..." << std::endl;
	this->port_ = port;
	tcpServer_ = new QTcpServer();
	tcpServer_->listen(QHostAddress::Any, port_);
	connect(tcpServer_, SIGNAL(newConnection()), this, SLOT(newConnect()));
	sendLock_ = false;
	stdPrint_ = false;
}

TCPThread::~TCPThread() {
	if (!feedbackQueue.empty() && stdPrint_)
		std::cout << "Sending remaining feedback to Plannar..." << std::endl;
	while (!feedbackQueue.empty()) {
		QString tp_qs = feedbackQueue.front();
		if (stdPrint_)
			std::cout << "Feedback TCPThread -> Plannar: " << qHash(tp_qs)
					<< std::endl;
		emit feedbackReceived(tp_qs);
		feedbackQueue.pop_front();
	}
	delete tcpSocket_;
	delete tcpServer_;
	std::cout << "TCPThread Deconstructing..." << std::endl;
}

void TCPThread::run() {
	std::cout << "Fuck tcp thread!\n";
	ros::spin();
}

void TCPThread::newConnect() {
	std::cout << "New connection" << std::endl;
	tcpSocket_ = tcpServer_->nextPendingConnection();
	connect(tcpSocket_, SIGNAL(readyRead()), this, SLOT(readMessage()));
	connect(tcpSocket_, SIGNAL(disconnected()), this, SLOT(destroyConnect()));
}

void TCPThread::destroyConnect() {
	std::cout << "Destroy connection" << std::endl;
	emit disconnected();
}

void TCPThread::readMessage() {
	mutex_.lock();

	// Read message from Ethernet
	QByteArray qba = tcpSocket_->readAll();
	QString qs = QVariant(qba).toString();

	if (stdPrint_)
		std::cout << "Feedback KRC -> TCPThread: " << qHash(qs) << std::endl;
	feedbackQueue.push_back(qs);
	while (!feedbackQueue.empty()) {
		QString tp_qs = feedbackQueue.front();
		if (stdPrint_)
			std::cout << "Feedback TCPThread -> Plannar: " << qHash(tp_qs)
					<< std::endl;
		emit feedbackReceived(tp_qs);
		feedbackQueue.pop_front();
	}
	mutex_.unlock();
	sendLock_ = false;
}

void TCPThread::sendMessage(QString qs) {
	if (!sendLock_) {
		mutex_.lock();
		if (stdPrint_)
			std::cout << "Command TCPThread -> KRC: " << qHash(qs) << std::endl;
		tcpSocket_->write(qs.toAscii());
		mutex_.unlock();
		sendLock_ = true;
	}
}

void TCPThread::debug() {
	;
}

