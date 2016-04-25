/*
 * Comm32Port.h
 *
 *  Created on: Apr 17, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_COMM32PORT_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_COMM32PORT_H_

/*****************************************************************
 Defines
 *****************************************************************/
class Comm32Port;

#define COMM_8N1    0x00
#define COMM_8N2	0x01
#define COMM_8O1	0x02
#define COMM_8O2	0x03
#define COMM_8E1	0x04
#define COMM_8E2	0x05
#define COMM_7N1 	0x06
#define COMM_7N2	0x07
#define COMM_7O1	0x08
#define COMM_7O2	0x09
#define COMM_7E1	0x0A
#define COMM_7E2	0x0B

#define READ_BUFFER_SIZE 3000

#define NUM_COM_PORTS		10	/* number of com ports */
#define POLARIS_SYSTEM		1	/* type of system, POLARIS */
#define AURORA_SYSTEM		2	/* or AURORA */
#define ACCEDO_SYSTEM		3	/* or ACCEDO */
#define VICRA_SYSTEM		4	/* or VICRA */
#define SPECTRA_SYSTEM	    5	/* or SPECTRA */
#define _MAX_PATH   260 /* max. length of full pathname */
#define MAX_PATH 260

#define MODE_PRE_INIT		0x01
#define MODE_INIT			0x02
#define MODE_TRACKING		0x03
#define MODE_ACTIVATED		0x04

#include <iostream>
#include <unistd.h>
#include <cstdlib>

#include <boost/thread/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/make_shared.hpp>

#include <QtSerialPort/qserialport.h>
#include <QtSerialPort/qserialportinfo.h>
#include <QtSerialPort/qserialportglobal.h>

#include <ros/ros.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "inifile.h"
#include "APIStructures.h"
#include "Conversions.h"

class Comm32Port: public QObject {
Q_OBJECT
public:
	Comm32Port();
	virtual ~Comm32Port();

	void SerialClose();
	int SerialOpen(unsigned port, unsigned long baud_rate, unsigned format,
			bool flow_control, unsigned long server_break_delay);
	int SerialSetBaud(unsigned long baud_rate, unsigned format,
			bool flow_control, unsigned long server_break_delay);

	int SerialInit();
	int SerialBreak();
	int SerialFlush();

	int SerialPutChar(char chr);
	int SerialPutString(char *string, long long int len);

	int SerialGetChar();
	int SerialCharsAvailable();
	int SerialGetString(char *string, long long int max_length);

	int SerialErrorStatus();

	boost::shared_ptr<QSerialPort> pdtSerialPort_;
	unsigned long ulSerialBreakDelay_; /* delay after a serial break */
	bool bFlowControl_; /* hardware handshaking */
	char pchrInputBuffer_[READ_BUFFER_SIZE]; /* input buffer */
	int nIndexBuffer_; /* index of buffer */
	int nNumBytes_; /* number of bytes read or sent */

};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_COMM32PORT_H_ */
