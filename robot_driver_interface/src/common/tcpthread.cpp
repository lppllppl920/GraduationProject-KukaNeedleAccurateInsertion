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
	tcpServer_ = new QTcpServer();
	if (!tcpServer_->listen(QHostAddress("172.31.1.149"), port_)) {
		std::cout << tcpServer_->errorString().toStdString() << std::endl;
	}
	tcpSocket_ = NULL;
	connect(tcpServer_, SIGNAL(newConnection()), this, SLOT(newConnect()),
			Qt::QueuedConnection);
	sendLock_ = false;
	stdPrint_ = false;
	tcpServerThread_ = NULL;
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
	std::cout << "TCP Server thread ends..." << std::endl;
	if (tcpServerThread_ != NULL) {
		tcpServerThread_->exit();
	}
}

void TCPThread::newConnect() {
	ROS_INFO("New TCP connection");
	tcpSocket_ = tcpServer_->nextPendingConnection();

	tcpServerThread_ = new QThread;
	ROS_INFO("TCP Server Thread starts...");
	tcpSocket_->moveToThread(tcpServerThread_);
	tcpServerThread_->start();

	connect(tcpSocket_, SIGNAL(readyRead()), this, SLOT(readMessage()),
			Qt::QueuedConnection);
	connect(tcpSocket_, SIGNAL(disconnected()), this, SLOT(destroyConnect()),
			Qt::QueuedConnection);
}

void TCPThread::destroyConnect() {
	std::cout << "Destroy TCP connection" << std::endl;
	std::cout << "TCP Server ends..." << std::endl;
	tcpServerThread_->exit();
	emit disconnected();
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

