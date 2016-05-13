/**
 *   Copyright (C) Tsinghua University 2016
 *
 *   Version   : 2.0
 *   Date      : 2016
 *   Author    : Xingtong Liu
 *   Company   : Tsinghua University
 *   Email     : 327586708@qq.com
 */

#include "tcpthread.h"

TCPThread::TCPThread(quint16 port) {
	ROS_INFO("TCPThread Constructing...");
	this->port_ = port;
	ROS_INFO("TCP Thread: %lu", QThread::currentThreadId());
	tcpServer_ = new QTcpServer();
	if (!tcpServer_->listen(QHostAddress("172.31.1.149"), port_)) {
		ROS_ERROR( "%s", tcpServer_->errorString().toStdString().c_str());
	}
	connect(tcpServer_, SIGNAL(newConnection()), this, SLOT(newConnect()),
			Qt::QueuedConnection);
	tcpSocket_ = NULL;
	sendLock_ = false;
	stdPrint_ = false;
}

TCPThread::~TCPThread() {
	std::cout << "TCPThread Deconstructing..." << std::endl;
	if (!feedbackQueue.empty() && stdPrint_)
		ROS_INFO("Sending remaining feedback to Plannar...");
	while (!feedbackQueue.empty()) {
		QString tp_qs = feedbackQueue.front();
		if (stdPrint_)
			ROS_INFO("Feedback TCPThread -> Plannar: ");
		emit feedbackReceived(tp_qs);
		feedbackQueue.pop_front();
	}
}

void TCPThread::run() {
	exec();
}

void TCPThread::newConnect() {
	ROS_INFO("New TCP connection");
	tcpSocket_ = tcpServer_->nextPendingConnection();
	connect(tcpSocket_, SIGNAL(readyRead()), this, SLOT(readMessage()),
			Qt::QueuedConnection);
	connect(tcpSocket_, SIGNAL(disconnected()), this, SLOT(destroyConnect()),
			Qt::QueuedConnection);
}

void TCPThread::destroyConnect() {
	//std::cout << "Destroy TCP connection" << std::endl;
	ROS_INFO("TCP disconnected, wait for a new connection");
	//emit disconnected();
}

void TCPThread::readMessage() {
	mutex_.lock();

	// Read message from Ethernet
	QByteArray qba = tcpSocket_->readAll();
	QString qs = QVariant(qba).toString();

	if (stdPrint_)
		ROS_INFO("Feedback KRC -> TCPThread: ");
	feedbackQueue.push_back(qs);
	while (!feedbackQueue.empty()) {
		QString tp_qs = feedbackQueue.front();
		if (stdPrint_)
			ROS_INFO("Feedback TCPThread -> Plannar: ");
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
			ROS_INFO("Command TCPThread -> KRC: %d", qHash(qs));
		tcpSocket_->write(qs.toAscii());
		mutex_.unlock();
		sendLock_ = true;
	}
}

void TCPThread::debug() {
	;
}

