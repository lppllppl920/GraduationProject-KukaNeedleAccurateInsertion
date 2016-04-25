/*
 * Comm32Port.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: lxt12
 */

#include <ndi/Comm32Port.h>

Comm32Port::Comm32Port() {
	// TODO Auto-generated constructor stub
	server_break_delay_ = 100; /* 100 milliseconds */
	num_bytes_ = 0;
	flow_control_ = true;
	index_buffer_ = 0;
	serial_port_ = boost::make_shared<QSerialPort>();

	memset(input_buffer_, '\0', sizeof(input_buffer_));
}

Comm32Port::~Comm32Port() {
	// TODO Auto-generated destructor stub
}

void Comm32Port::SerialClose() {
	if (serial_port_->isOpen()) {
		serial_port_->close();
		serial_port_ = NULL;
		ROS_INFO("Serial port closed successfully");
	} else {
		ROS_INFO("Serial port not found");
	}

}

int Comm32Port::SerialOpen(unsigned port, unsigned long baud_rate,
		unsigned format, bool flow_control, unsigned long server_break_delay) {

	std::vector<QString> port_name(19);
	for (int i = 0; i < 19; i++) {
		port_name[i] = QString("/dev/ttyUSB") + QString::number(i, 10);
		ROS_INFO("%s", port_name[i].toStdString().c_str());
	}

	server_break_delay_ = server_break_delay;
	// Port name and baud rate
	serial_port_->setPortName(port_name[port]);
	ROS_INFO("%s", port_name[port].toStdString().c_str());
	serial_port_->setBaudRate(baud_rate);

	// Communication protocol
	if (format == (unsigned) COMM_8N1) {
		serial_port_->setParity(QSerialPort::Parity::NoParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* if */

	else if (format == (unsigned) COMM_8N2) {
		serial_port_->setParity(QSerialPort::Parity::NoParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* else if */

	else if (format == (unsigned) COMM_8O1) {
		serial_port_->setParity(QSerialPort::Parity::OddParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* else if */

	else if (format == (unsigned) COMM_8O2) {
		serial_port_->setParity(QSerialPort::Parity::OddParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* else if */

	else if (format == (unsigned) COMM_8E1) {
		serial_port_->setParity(QSerialPort::Parity::EvenParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* else if */

	else if (format == (unsigned) COMM_8E2) {
		serial_port_->setParity(QSerialPort::Parity::EvenParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* else if */

	else if (format == (unsigned) COMM_7N1) {
		serial_port_->setParity(QSerialPort::Parity::NoParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else if (format == (unsigned) COMM_7N2) {
		serial_port_->setParity(QSerialPort::Parity::NoParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else if (format == (unsigned) COMM_7O1) {
		serial_port_->setParity(QSerialPort::Parity::OddParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else if (format == (unsigned) COMM_7O2) {
		serial_port_->setParity(QSerialPort::Parity::OddParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else if (format == (unsigned) COMM_7E1) {
		serial_port_->setParity(QSerialPort::Parity::EvenParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else if (format == (unsigned) COMM_7E2) {
		serial_port_->setParity(QSerialPort::Parity::EvenParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else {
		ROS_ERROR("unknown communication format");
		return -1;
	} /* else if */

	// Flow control
	if (flow_control) {
		serial_port_->setFlowControl(QSerialPort::FlowControl::SoftwareControl);
	} else {
		serial_port_->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
	}

	// Open serial port
	if (serial_port_->open(QIODevice::ReadWrite)) {
		ROS_INFO("Comm32Port: SerialOpen: Serial port opened successfully");
		return 1;

	} else {
		ROS_ERROR("Comm32Port: SerialOpen: Serial port failed to open");
		return -1;
	}

}

int Comm32Port::SerialSetBaud(unsigned long baud_rate, unsigned format,
		bool flow_control, unsigned long server_break_delay) {
	// Serial port should be initialized first
	if (!serial_port_->isOpen()) {
		return -1;
	}

	server_break_delay_ = server_break_delay;
	// Baud rate
	serial_port_->setBaudRate(baud_rate);

	// Communication protocol
	if (format == (unsigned) COMM_8N1) {
		serial_port_->setParity(QSerialPort::Parity::NoParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* if */

	else if (format == (unsigned) COMM_8N2) {
		serial_port_->setParity(QSerialPort::Parity::NoParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* else if */

	else if (format == (unsigned) COMM_8O1) {
		serial_port_->setParity(QSerialPort::Parity::OddParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* else if */

	else if (format == (unsigned) COMM_8O2) {
		serial_port_->setParity(QSerialPort::Parity::OddParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* else if */

	else if (format == (unsigned) COMM_8E1) {
		serial_port_->setParity(QSerialPort::Parity::EvenParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* else if */

	else if (format == (unsigned) COMM_8E2) {
		serial_port_->setParity(QSerialPort::Parity::EvenParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data8);
	} /* else if */

	else if (format == (unsigned) COMM_7N1) {
		serial_port_->setParity(QSerialPort::Parity::NoParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else if (format == (unsigned) COMM_7N2) {
		serial_port_->setParity(QSerialPort::Parity::NoParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else if (format == (unsigned) COMM_7O1) {
		serial_port_->setParity(QSerialPort::Parity::OddParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else if (format == (unsigned) COMM_7O2) {
		serial_port_->setParity(QSerialPort::Parity::OddParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else if (format == (unsigned) COMM_7E1) {
		serial_port_->setParity(QSerialPort::Parity::EvenParity);
		serial_port_->setStopBits(QSerialPort::StopBits::OneStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else if (format == (unsigned) COMM_7E2) {
		serial_port_->setParity(QSerialPort::Parity::EvenParity);
		serial_port_->setStopBits(QSerialPort::StopBits::TwoStop);
		serial_port_->setDataBits(QSerialPort::DataBits::Data7);
	} /* else if */

	else {
		ROS_ERROR("unknown communication format");
		return -1;
	} /* else if */

	// Flow control
	if (flow_control) {
		serial_port_->setFlowControl(QSerialPort::FlowControl::SoftwareControl);
	} else {
		serial_port_->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
	}

	return 1;

}

int Comm32Port::SerialBreak() {

	if (serial_port_->setBreakEnabled(true)) {
		ROS_INFO("Serial port break");
	} else {
		ROS_ERROR("Serial port cannot break");
		return -1;
	}

	boost::this_thread::sleep(
			boost::posix_time::milliseconds(server_break_delay_));

	if (serial_port_->setBreakEnabled(false)) {
		ROS_INFO("Serial port restart transmission");
		return 1;
	} else {
		ROS_ERROR("Serial port cannot restart");
		return -1;
	}
}

int Comm32Port::SerialFlush() {

	if (serial_port_->flush()) {
		ROS_INFO("Comm32Port: SerialFlush: Serial port flush succeed");
		return 1;
	} else {
		ROS_ERROR("Comm32Port: SerialFlush: Serial port cannot flush");
		return -1;
	}
}

int Comm32Port::SerialPutChar(char chr) {

	if (serial_port_->putChar(chr)) {
		ROS_INFO("Serial port write char successfully");
		return 1;
	} else {
		ROS_ERROR("Serial port cannot write char to specified device");
		return -1;
	}
}

int Comm32Port::SerialErrorStatus() {

	int error_type = serial_port_->error();

	switch (error_type) {
	case QSerialPort::SerialPortError::NotOpenError: {
		ROS_ERROR("Serial port not open");
		break;
	}
	case QSerialPort::SerialPortError::OpenError: {
		ROS_ERROR("Serial port open error");
		break;
	}
	case QSerialPort::SerialPortError::BreakConditionError: {
		ROS_ERROR("Serial port break condition error");
		break;
	}
	case QSerialPort::SerialPortError::DeviceNotFoundError: {
		ROS_ERROR("Serial port device not found");
		break;
	}
	case QSerialPort::SerialPortError::FramingError: {
		ROS_ERROR("Serial port framing error");
		break;
	}
	case QSerialPort::SerialPortError::NoError: {
		ROS_INFO("No error detected");
		break;
	}
	case QSerialPort::SerialPortError::ParityError: {
		ROS_ERROR("Serial port parity error");
		break;
	}
	case QSerialPort::SerialPortError::PermissionError: {
		ROS_ERROR("Serial port permission error");
		break;
	}
	case QSerialPort::SerialPortError::ReadError: {
		ROS_ERROR("Serial port read error");
		break;
	}
	case QSerialPort::SerialPortError::ResourceError: {
		ROS_ERROR("Serial port resource error");
		break;
	}
	case QSerialPort::SerialPortError::TimeoutError: {
		ROS_ERROR("Serial port time out");
		break;
	}
	case QSerialPort::SerialPortError::UnknownError: {
		ROS_ERROR("Serial port unknown error");
		break;
	}
	case QSerialPort::SerialPortError::UnsupportedOperationError: {
		ROS_ERROR("Serial port unsupported operation");
		break;
	}
	case QSerialPort::SerialPortError::WriteError: {
		ROS_ERROR("Serial port write error");
		break;
	}
	default: {
		ROS_ERROR("unknown error");
	}
	}

	return error_type;
}

int Comm32Port::SerialPutString(char* string, long long int length) {
	return serial_port_->write(string, length);
}

int Comm32Port::SerialGetChar() {
	int return_char;

	if (!num_bytes_) {
		num_bytes_ = serial_port_->read(input_buffer_, READ_BUFFER_SIZE);
		index_buffer_ = 0;
	}

	if (num_bytes_) {
		return_char = input_buffer_[index_buffer_];
		index_buffer_++;
		num_bytes_--;
	}

	return return_char;
}

int Comm32Port::SerialCharsAvailable() {

	if (num_bytes_) {
		num_bytes_ = serial_port_->read(input_buffer_, READ_BUFFER_SIZE);
		index_buffer_ = 0;
	}
	return num_bytes_;
}

int Comm32Port::SerialGetString(char* string, long long int max_length) {
	return serial_port_->read(string, max_length);
}

