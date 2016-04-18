/*
 * Comm32Port.h
 *
 *  Created on: Apr 17, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_COMM32PORT_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_COMM32PORT_H_

/*
 * Serial data formats
 */
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

#include <SerialStream.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <QtSerialPort/qserialport.h>
#include <QtSerialPort/qserialportinfo.h>
#include <QtSerialPort/qserialportglobal.h>

#include "Interface.h"

class Comm32Port: public QObject{
Q_OBJECT
public:
	Comm32Port();
	virtual ~Comm32Port();

	void SerialClose();
	int SerialOpen( unsigned port, unsigned long baud_rate, unsigned format,
			   bool flow_control, unsigned long server_break_delay );
	int SerialSetBaud( unsigned long baud_rate, unsigned format,
			   bool flow_control, unsigned long server_break_delay );

	int SerialInit();
	int SerialBreak();
	int SerialFlush();

	int SerialPutChar( unsigned char uch );
	int SerialPutString( unsigned char *pszString, unsigned long ulLen );

	int  SerialGetChar();
	int  SerialCharsAvailable();
	int  SerialGetString(unsigned char *pszString, unsigned long ulMaxLen );

	int	SerialErrorStatus();

private:
	boost::shared_ptr<QSerialPort> serial_port_;
	unsigned long server_break_delay_;

};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_COMM32PORT_H_ */
