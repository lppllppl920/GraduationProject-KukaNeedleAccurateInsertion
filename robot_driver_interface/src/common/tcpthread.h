/**
 *   Copyright (C) Tsinghua University 2016
 *
 *   Version   : 2.0
 *   Date      : 2016
 *   Author    : Xingtong Liu
 *   Company   : Tsinghua University
 *   Email     : 327586708@qq.com
 *
 *   Header file for TCPThread. A new QThread is created apart from the main
 *   thread (plannar thread, used by krc4_control_async_GUI.cpp, test.cpp or
 *   main.cpp).
 *   TCHThread communicated with KRC4 through Ethernet. EthernetKRL package
 *   should be installed in KRC4.
 *   Signals:
 *       \feedbackReceived(QString)  -> Plannar/
 *       \disconnected()             -> Plannar/
 *   Slots:
 *       \self.tcpServer_            -> newConnect()/
 *       \self.tcpSocket_            -> destroyConnect()/
 *       \self.tcpSocket_            -> readMessage()/
 *       \Plannar                    -> sendMessage(QString)/
 *       \Plannar                    -> debug()/  - not used, for debugging
 *
 *           1. QString                   2. Feedback
 *     | ------------------> |     | ------------------> |
 *   KRC4                   TCPThread                 Plannar
 *     | <------------------ |     | <------------------ |
 *          (4. QString)                 (3. Command)
 *
 *   Messages 1 and 2 are initiated by KRC timer interrupt, which is periodic,
 *   while messages 3 and 4 are responses of Plannar, not required for each
 *   period. Ideally, the whole loop is the combination of 1-2 and 1-2-3-4.
 *   e.g. 1-2 - 1-2 - 1-2-3-4 - 1-2 - 1-2-3-4 - 1-2-3-4 - 1-2 - ......
 *
 *   For real-time performance and for avoiding delays, Feedbacks are stored
 *   to the buffer in TCPThread before being transferred to Plannar. It is
 *   rare but possible to have several Feedback held up in TCPThread.
 *
 */

#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include <QThread>
#include <QMutex>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>
#include <QtCore/qmetatype.h>
#include <list>
#include <QHash>
#include <QApplication>
#include <ros/ros.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

// Max length of feedbackQueue
#define QUEUE_MAXLEN 2048
// Buffer size in KRL
#define KRL_BUF_LEN 64
// Threshold to keep sending Command to KRC4
#define KRL_BUF_THRESHOLD 32

// --------------------------------------------------------------------------
// TCPThread class
//  - publicly inherited from QThread
// --------------------------------------------------------------------------
class TCPThread: public QThread {
Q_OBJECT
public:
	// TCPThread constructor, default port number: 59152
	// port number is changeable, should be correspond to port number specified
	// in EthernetKRL configuration file
	TCPThread(quint16 port = 59152);

	// TCPThread deconstructor
	// Delete pointer component and send rest feedback to plannar
	~TCPThread();

	void run();

public slots:
	// Called when new connection to tcpSocket_ is established
	// Set up two signal-slot connections:
	//       \self.tcpSocket_    -> destroyConnect()/
	//       \self.tcpSocket_    -> readMessage()/
	void newConnect();

	// Called when tcpSocket_ is disconnected
	// Emit disconnected() signal to plannar, plannar will shut down TCPThread
	void destroyConnect();

	// Called when new message arrived on tcpSocket_
	//  - first store the new message to buffer
	//  - then send all messages to plannar, clear the buffer
	void readMessage();

	// Called when plannar initiated a send message signal
	// When sendLock_ is false, directly write to tcpSocket_
	void sendMessage(QString qs);

	// Called when plannar initiated debug signal
	// Not implemented, could be used for debugging
	void debug();

signals:
	// Send feedback as raw text to plannar
	// Emit in readMessage()
	void feedbackReceived(QString qs);

	// Emit when tcpSocket_ is disconnected with KRC4
	void disconnected();

private:
	// port number, equal to the port number specified in EthernetKRL configuration file
	quint16 port_;
	// QTcpServer pointer
	QTcpServer* tcpServer_;
	// QTcpSocket pointer
	QTcpSocket* tcpSocket_;

	// Feedback buffer
	// List element is QString, not Feedback
	std::list<QString> feedbackQueue;

	// Protect data IO from being accessed by main thread and TCPThread simultaneously
	QMutex mutex_;

	// Used to guarantee the message flow loop sequence: 1-2 or 1-2-3-4
	bool sendLock_;

	// verbose output enabled if set to true
	// for debugging purposes
	bool stdPrint_;

};

#endif
