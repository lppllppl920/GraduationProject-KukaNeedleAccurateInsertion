/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 20 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#include "message.h"

// Motion Command: PTP, LIN
Command::Command(Type type, Style style, Frame &f, int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(f), circ_frame_(), axis_(), circ_axis_(), stamp_(
				st), type_(type), style_(style), end_( COMMAND_END_FRAME), approx_(
				approx), pos_s_( DEF_COMMAND_POS_S), pos_t_( DEF_COMMAND_POS_T), circ_end_(
		DEF_COMMAND_CIRC_END), circ_pos_s_( DEF_COMMAND_CIRC_POS_S), circ_pos_t_(
		DEF_COMMAND_CIRC_POS_T), circ_degree_( DEF_COMMAND_CIRC_DEGREE), param_type_(
				DEFAULT_PARAM), param_num_( DEF_COMMAND_PARAM_NUM), other_type_(
				DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style == CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		if (style == PTP)
			text_ = "Command: PTP FRAME";
		else if (style == LIN)
			text_ = "Command: LIN FRAME";
		constructCommand();
	}
}

Command::Command(Type type, Style style, Axis &a, int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(), circ_frame_(), axis_(
				a), circ_axis_(), stamp_(st), type_(type), style_(style), end_(
		COMMAND_END_AXIS), approx_(approx), pos_s_( DEF_COMMAND_POS_S), pos_t_(
		DEF_COMMAND_POS_T), circ_end_( DEF_COMMAND_CIRC_END), circ_pos_s_(
		DEF_COMMAND_CIRC_POS_S), circ_pos_t_( DEF_COMMAND_CIRC_POS_T), circ_degree_(
		DEF_COMMAND_CIRC_DEGREE), param_type_(DEFAULT_PARAM), param_num_(
		DEF_COMMAND_PARAM_NUM), other_type_(DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style == CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		if (style == PTP)
			text_ = "Command: PTP AXIS";
		else if (style == LIN)
			text_ = "Command: LIN AXIS";
		constructCommand();
	}
}

Command::Command(Type type, Style style, Pos &p, int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(p.F), circ_frame_(), axis_(), circ_axis_(), stamp_(
				st), type_(type), style_(style), end_( COMMAND_END_POS), approx_(
				approx), pos_s_(p.S), pos_t_(p.T), circ_end_(
		DEF_COMMAND_CIRC_END), circ_pos_s_( DEF_COMMAND_CIRC_POS_S), circ_pos_t_(
		DEF_COMMAND_CIRC_POS_T), circ_degree_( DEF_COMMAND_CIRC_DEGREE), param_type_(
				DEFAULT_PARAM), param_num_( DEF_COMMAND_PARAM_NUM), other_type_(
				DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style == CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		if (style == PTP)
			text_ = "Command: PTP POS";
		else if (style == LIN)
			text_ = "Command: LIN POS";
		constructCommand();
	}
}

// Motion Command: CIRC
Command::Command(Type type, Style style, Frame& f_end, Frame& f_aux,
		float degree, int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(f_end), circ_frame_(
				f_aux), axis_(), circ_axis_(), stamp_(st), type_(type), style_(
				style), end_( COMMAND_END_FRAME), approx_(approx), pos_s_(
		DEF_COMMAND_POS_S), pos_t_( DEF_COMMAND_POS_T), circ_end_(
		COMMAND_END_FRAME), circ_pos_s_( DEF_COMMAND_CIRC_POS_S), circ_pos_t_(
		DEF_COMMAND_CIRC_POS_T), circ_degree_(degree), param_type_(
				DEFAULT_PARAM), param_num_( DEF_COMMAND_PARAM_NUM), other_type_(
				DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style != CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		text_ = "Command: CIRC FRAME FRAME";
		constructCommand();
	}
}

Command::Command(Type type, Style style, Frame& f_end, Axis& a_aux,
		float degree, int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(f_end), circ_frame_(), axis_(), circ_axis_(
				a_aux), stamp_(st), type_(type), style_(style), end_(
		COMMAND_END_FRAME), approx_(approx), pos_s_( DEF_COMMAND_POS_S), pos_t_(
		DEF_COMMAND_POS_T), circ_end_( COMMAND_END_AXIS), circ_pos_s_(
		DEF_COMMAND_CIRC_POS_S), circ_pos_t_( DEF_COMMAND_CIRC_POS_T), circ_degree_(
				degree), param_type_(DEFAULT_PARAM), param_num_(
		DEF_COMMAND_PARAM_NUM), other_type_(DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style != CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		text_ = "Command: CIRC AXIS FRAME";
		constructCommand();
	}
}

Command::Command(Type type, Style style, Frame& f_end, Pos& p_aux, float degree,
		int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(f_end), circ_frame_(
				p_aux.F), axis_(), circ_axis_(), stamp_(st), type_(type), style_(
				style), end_( COMMAND_END_FRAME), approx_(approx), pos_s_(
		DEF_COMMAND_POS_S), pos_t_( DEF_COMMAND_POS_T), circ_end_(
		COMMAND_END_POS), circ_pos_s_(p_aux.S), circ_pos_t_(p_aux.T), circ_degree_(
				degree), param_type_(DEFAULT_PARAM), param_num_(
		DEF_COMMAND_PARAM_NUM), other_type_(DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style != CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		text_ = "Command: CIRC POS FRAME";
		constructCommand();
	}
}

Command::Command(Type type, Style style, Axis& a_end, Frame& f_aux,
		float degree, int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(), circ_frame_(
				f_aux), axis_(a_end), circ_axis_(), stamp_(st), type_(type), style_(
				style), end_( COMMAND_END_AXIS), approx_(approx), pos_s_(
		DEF_COMMAND_POS_S), pos_t_( DEF_COMMAND_POS_T), circ_end_(
		COMMAND_END_FRAME), circ_pos_s_( DEF_COMMAND_CIRC_POS_S), circ_pos_t_(
		DEF_COMMAND_CIRC_POS_T), circ_degree_(degree), param_type_(
				DEFAULT_PARAM), param_num_( DEF_COMMAND_PARAM_NUM), other_type_(
				DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style != CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		text_ = "Command: CIRC FRAME AXIS";
		constructCommand();
	}
}

Command::Command(Type type, Style style, Axis& a_end, Axis& a_aux, float degree,
		int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(), circ_frame_(), axis_(
				a_end), circ_axis_(a_aux), stamp_(st), type_(type), style_(
				style), end_( COMMAND_END_AXIS), approx_(approx), pos_s_(
		DEF_COMMAND_POS_S), pos_t_( DEF_COMMAND_POS_T), circ_end_(
		COMMAND_END_AXIS), circ_pos_s_( DEF_COMMAND_CIRC_POS_S), circ_pos_t_(
		DEF_COMMAND_CIRC_POS_T), circ_degree_(degree), param_type_(
				DEFAULT_PARAM), param_num_( DEF_COMMAND_PARAM_NUM), other_type_(
				DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style != CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		text_ = "Command: CIRC AXIS AXIS";
		constructCommand();
	}
}

Command::Command(Type type, Style style, Axis& a_end, Pos& p_aux, float degree,
		int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(), circ_frame_(
				p_aux.F), axis_(a_end), circ_axis_(), stamp_(st), type_(type), style_(
				style), end_( COMMAND_END_AXIS), approx_(approx), pos_s_(
		DEF_COMMAND_POS_S), pos_t_( DEF_COMMAND_POS_T), circ_end_(
		COMMAND_END_POS), circ_pos_s_(p_aux.S), circ_pos_t_(p_aux.T), circ_degree_(
				degree), param_type_(DEFAULT_PARAM), param_num_(
		DEF_COMMAND_PARAM_NUM), other_type_(DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style != CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		text_ = "Command: CIRC POS AXIS";
		constructCommand();
	}
}

Command::Command(Type type, Style style, Pos& p_end, Frame& f_aux, float degree,
		int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(p_end.F), circ_frame_(
				f_aux), axis_(), circ_axis_(), stamp_(st), type_(type), style_(
				style), end_( COMMAND_END_POS), approx_(approx), pos_s_(
				p_end.S), pos_t_(p_end.T), circ_end_( COMMAND_END_FRAME), circ_pos_s_(
		DEF_COMMAND_CIRC_POS_S), circ_pos_t_( DEF_COMMAND_CIRC_POS_T), circ_degree_(
				degree), param_type_(DEFAULT_PARAM), param_num_(
		DEF_COMMAND_PARAM_NUM), other_type_(DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style != CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		text_ = "Command: CIRC FRAME POS";
		constructCommand();
	}
}

Command::Command(Type type, Style style, Pos& p_end, Axis& a_aux, float degree,
		int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(p_end.F), circ_frame_(), axis_(), circ_axis_(
				a_aux), stamp_(st), type_(type), style_(style), end_(
		COMMAND_END_POS), approx_(approx), pos_s_(p_end.S), pos_t_(p_end.T), circ_end_(
		COMMAND_END_AXIS), circ_pos_s_(
		DEF_COMMAND_CIRC_POS_S), circ_pos_t_( DEF_COMMAND_CIRC_POS_T), circ_degree_(
				degree), param_type_(DEFAULT_PARAM), param_num_(
		DEF_COMMAND_PARAM_NUM), other_type_(DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style != CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		text_ = "Command: CIRC AXIS POS";
		constructCommand();
	}
}

Command::Command(Type type, Style style, Pos& p_end, Pos& p_aux, float degree,
		int st, Approx approx) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(p_end.F), circ_frame_(
				p_aux.F), axis_(), circ_axis_(), stamp_(st), type_(type), style_(
				style), end_( COMMAND_END_POS), approx_(approx), pos_s_(
				p_end.S), pos_t_(p_end.T), circ_end_( COMMAND_END_POS), circ_pos_s_(
				p_aux.S), circ_pos_t_(p_aux.T), circ_degree_(degree), param_type_(
				DEFAULT_PARAM), param_num_( DEF_COMMAND_PARAM_NUM), other_type_(
				DEFAULT_OTHERTYPE) {
	if (type != Motion) {
		std::cout << "Command::Command: Invalid type" << std::endl;
		valid_ = false;
	}
	if (style != CIRC) {
		std::cout << "Command::Command: Invalid style" << std::endl;
		valid_ = false;
	}
	if (valid_) {
		text_ = "Command: CIRC POS POS";
		constructCommand();
	}
}

// Configuration Command
Command::Command(Type type, Param param, float number, int st) :
		valid_(true), emergent_(false), state_(DEFAULT_STATE), frame_(), circ_frame_(), axis_(), circ_axis_(), stamp_(
				st), type_(type), style_(DEFAULT_STYLE), end_( DEF_COMMAND_END), approx_(
				DEFAULT_APPROX), pos_s_( DEF_COMMAND_POS_S), pos_t_(
		DEF_COMMAND_POS_T), circ_end_( DEF_COMMAND_CIRC_END), circ_pos_s_(
		DEF_COMMAND_CIRC_POS_S), circ_pos_t_( DEF_COMMAND_CIRC_POS_T), circ_degree_(
		DEF_COMMAND_CIRC_DEGREE), param_type_(param), param_num_(number), other_type_(
				DEFAULT_OTHERTYPE) {
	if (type != Config) {
		valid_ = false;
		std::cout << "Command::Command: Invalid type" << std::endl;
	} else {
		text_ = "Command: Configuration";
		constructCommand();
	}
}

// Other Command
Command::Command(Type type, OtherType other_type, int st) :
		valid_(true), state_(DEFAULT_STATE), frame_(), circ_frame_(), axis_(), circ_axis_(), stamp_(
				st), type_(type), style_(DEFAULT_STYLE), end_( DEF_COMMAND_END), approx_(
				DEFAULT_APPROX), pos_s_( DEF_COMMAND_POS_S), pos_t_(
		DEF_COMMAND_POS_T), circ_end_( DEF_COMMAND_CIRC_END), circ_pos_s_(
		DEF_COMMAND_CIRC_POS_S), circ_pos_t_( DEF_COMMAND_CIRC_POS_T), circ_degree_(
		DEF_COMMAND_CIRC_DEGREE), param_type_(DEFAULT_PARAM), param_num_(
		DEF_COMMAND_PARAM_NUM), other_type_(other_type) {
	text_ = "Command: Other";
	constructCommand();
	if (other_type_ == TerminateImm || other_type_ == Pause
			|| other_type_ == Stop) {
		emergent_ = true;
	} else
		emergent_ = false;
}

Command::~Command() {
	if (valid_)
		delete doc_;
}

void Command::setStamp(int st) {
	stamp_ = st;
	if (valid_)
		eleBasic.setAttribute("Stamp", stamp_);
	else
		std::cout << "Command::setStamp: Command invalid" << std::endl;
}

QDomDocument* Command::getDocument() {
	return doc_;
}

void Command::checkZero(Frame &f) {
	checkZero(f.X);
	checkZero(f.Y);
	checkZero(f.Z);
	checkZero(f.A);
	checkZero(f.B);
	checkZero(f.C);
}

void Command::checkZero(Axis &a) {
	checkZero(a.A1);
	checkZero(a.A2);
	checkZero(a.A3);
	checkZero(a.A4);
	checkZero(a.A5);
	checkZero(a.A6);
}

void Command::checkZero(float &num) {
	if (num < 0.0001 && num > -0.0001)
		num = 0.0;
}

void Command::constructCommand() {
	if (!valid_) {
		std::cout << "Command::constructCommand: Command invalid" << std::endl;
		return;
	}
	doc_ = new QDomDocument();

	eleCommand = doc_->createElement("Command");
	eleBasic = doc_->createElement("Basic");
	eleMessage = doc_->createElement("Message");
	eleMotion = doc_->createElement("Motion");
	eleMotionFrame = doc_->createElement("Frame");
	eleMotionAxis = doc_->createElement("Axis");
	eleMotionPOS = doc_->createElement("POS");
	eleMotionSIRC = doc_->createElement("SIRC");
	eleMotionSIRCFrame = doc_->createElement("Frame");
	eleMotionSIRCAxis = doc_->createElement("Axis");
	eleMotionSIRCPOS = doc_->createElement("POS");
	eleMotionSIRCCA = doc_->createElement("CA");
	eleConfig = doc_->createElement("Configuration");
	eleConfigParam = doc_->createElement("Parameter");
	eleOther = doc_->createElement("Other");

	checkZero(frame_);
	checkZero(axis_);
	checkZero(circ_frame_);
	checkZero(circ_axis_);

	eleBasic.setAttribute("Type", type_);
	eleBasic.setAttribute("Stamp", stamp_);
	eleMessage.setAttribute("Text", text_);
	eleMotion.setAttribute("Style", style_);
	eleMotion.setAttribute("End", end_);
	eleMotion.setAttribute("Approximation", approx_);
	eleMotionFrame.setAttribute("X", frame_.X);
	eleMotionFrame.setAttribute("Y", frame_.Y);
	eleMotionFrame.setAttribute("Z", frame_.Z);
	eleMotionFrame.setAttribute("A", frame_.A);
	eleMotionFrame.setAttribute("B", frame_.B);
	eleMotionFrame.setAttribute("C", frame_.C);
	eleMotionAxis.setAttribute("A1", axis_.A1);
	eleMotionAxis.setAttribute("A2", axis_.A2);
	eleMotionAxis.setAttribute("A3", axis_.A3);
	eleMotionAxis.setAttribute("A4", axis_.A4);
	eleMotionAxis.setAttribute("A5", axis_.A5);
	eleMotionAxis.setAttribute("A6", axis_.A6);
	eleMotionPOS.setAttribute("S", pos_s_);
	eleMotionPOS.setAttribute("T", pos_t_);
	eleMotionSIRC.setAttribute("End", circ_end_);
	eleMotionSIRCFrame.setAttribute("X", circ_frame_.X);
	eleMotionSIRCFrame.setAttribute("Y", circ_frame_.Y);
	eleMotionSIRCFrame.setAttribute("Z", circ_frame_.Z);
	eleMotionSIRCFrame.setAttribute("A", circ_frame_.A);
	eleMotionSIRCFrame.setAttribute("B", circ_frame_.B);
	eleMotionSIRCFrame.setAttribute("C", circ_frame_.C);
	eleMotionSIRCAxis.setAttribute("A1", circ_axis_.A1);
	eleMotionSIRCAxis.setAttribute("A2", circ_axis_.A2);
	eleMotionSIRCAxis.setAttribute("A3", circ_axis_.A3);
	eleMotionSIRCAxis.setAttribute("A4", circ_axis_.A4);
	eleMotionSIRCAxis.setAttribute("A5", circ_axis_.A5);
	eleMotionSIRCAxis.setAttribute("A6", circ_axis_.A6);
	eleMotionSIRCPOS.setAttribute("S", circ_pos_s_);
	eleMotionSIRCPOS.setAttribute("T", circ_pos_t_);
	eleMotionSIRCCA.setAttribute("Degree", circ_degree_);
	eleConfigParam.setAttribute("Type", param_type_);
	eleConfigParam.setAttribute("Number", param_num_);
	eleOther.setAttribute("Type", other_type_);

	doc_->appendChild(eleCommand);
	eleCommand.appendChild(eleBasic);
	eleCommand.appendChild(eleMessage);
	eleCommand.appendChild(eleMotion);
	eleMotion.appendChild(eleMotionFrame);
	eleMotion.appendChild(eleMotionAxis);
	eleMotion.appendChild(eleMotionPOS);
	eleMotion.appendChild(eleMotionSIRC);
	eleMotionSIRC.appendChild(eleMotionSIRCFrame);
	eleMotionSIRC.appendChild(eleMotionSIRCAxis);
	eleMotionSIRC.appendChild(eleMotionSIRCPOS);
	eleMotionSIRC.appendChild(eleMotionSIRCCA);
	eleCommand.appendChild(eleConfig);
	eleConfig.appendChild(eleConfigParam);
	eleCommand.appendChild(eleOther);

	msg_ = doc_->toString(-1);
}

void Command::printCommandFormated() {
//    std::cout << "Stamp: " << std::setw(10) << stamp_ << std::endl;
//    std::cout << "Message: " << text_.toStdString() << std::endl;
//    if ( style_ == XML_MOTION_STYLE_LIN || style_ == XML_MOTION_STYLE_PTP )
//    {
//        if ( type_ == XML_MOTION_TYPE_FRAME )
//            frame_.printFrame();
//        else if ( type_ == XML_MOTION_TYPE_AXIS )
//            axis_.printAxis();
//    }
	std::cout << "Command::printCommandFormated not supported yet" << std::endl;
}

void Command::printDocumentPlain(Indent indent) {
	if (!valid_) {
		std::cout << "Command::printDocumentPlain: Command invalid"
				<< std::endl;
		return;
	}
	if (indent == IndentSpace)
		std::cout << doc_->toString().toStdString() << std::endl;
	else if (indent == IndentNone)
		std::cout << msg_.toStdString() << std::endl;
	else
		std::cout << "Command::printDocumentPlain: Indent not recognized"
				<< std::endl;
}

QString& Command::getMessage() {
	return msg_;
}

int Command::getStamp() {
	return stamp_;
}

Command::State Command::getState() {
	return state_;
}

void Command::setState(State state) {
	state_ = state;
}

Command::Type Command::getType() {
	return type_;
}

Command::OtherType Command::getOtherType() {
	return other_type_;
}

Frame& Command::getFrame() {
	return frame_;
}

Axis& Command::getAxis() {
	return axis_;
}

bool Command::getEmergent() {
	return emergent_;
}

Feedback::Feedback() :
		frame_(), axis_(), pos_() {
	parsedOK_ = false;
	setOK_ = false;
}

Feedback::Feedback(const char *filename) :
		frame_(), axis_() {
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly)) {
		setOK_ = false;
		std::cout << "Feedback::Feedback: Cannot open file" << filename
				<< std::endl;
	} else if (!doc_.setContent(&file)) {
		setOK_ = false;
		std::cout << "Feedback::Feedback: Cannot set document" << std::endl;
		file.close();
	} else {
		file.close();
		parsedOK_ = false;
		setOK_ = true;
		parseDocument();
	}
}

Feedback::Feedback(const QString &qs) :
		frame_(), axis_() {
	if (!doc_.setContent(qs)) {
		setOK_ = false;
		std::cout << "Feedback::Feedback: Cannot set document" << std::endl;
	} else {
		setOK_ = true;
		parsedOK_ = false;
		parseDocument();
	}
}

int Feedback::parseDocument() {
	parsedOK_ = false;
	QDomElement eleFeedback = doc_.documentElement();
	if (eleFeedback.tagName() != "Feedback") {
		std::cout << "Feedback::parseDocument: Root name doesn't match"
				<< std::endl;
		return -1;
	}

	QDomElement n = eleFeedback.firstChildElement();

	while (!n.isNull()) {
		if (n.tagName() == "Basic") {
			type_ = Type(n.attribute("Type").toInt());
		} else if (n.tagName() == "Status") {
			seq_ = n.attribute("Seq").toInt();
			hour_ = n.attribute("Hour").toInt();
			time_ = n.attribute("Time").toInt();
			QDomElement nn = n.firstChildElement();
			while (!nn.isNull()) {
				if (nn.tagName() == "Frame")
					parseDocumentFrame(nn);
				else if (nn.tagName() == "Axis")
					parseDocumentAxis(nn);
				else if (nn.tagName() == "Pos")
					parseDocumentPos(nn);
				else if (nn.tagName() == "Buffer") {
					buffer_front_ = nn.attribute("Front").toInt();
					buffer_last_ = nn.attribute("Last").toInt();
					buffer_extreme_ = Extreme(nn.attribute("Extreme").toInt());
					buffer_full_ = false;
					buffer_empty_ = false;
					if (buffer_extreme_ == 1)
						buffer_full_ = true;
					else if (buffer_extreme_ == -1)
						buffer_empty_ = true;
				}
				nn = nn.nextSiblingElement();
			}
			pos_.set(frame_, pos_s_, pos_t_);
		} else if (n.tagName() == "Result") {
			stamp_ = n.attribute("Stamp").toInt();
			success_ = n.attribute("Success").toInt();
			QDomElement nn = n.firstChildElement();
			text_ = nn.attribute("Text").toStdString();
		}
		n = n.nextSiblingElement();
	}

	parsedOK_ = true;
	msg_ = doc_.toString(-1);

	return 1;
}

void Feedback::parseDocumentFrame(QDomElement domElementFrame) {
	frame_.set(domElementFrame.attribute("X").toFloat(),
			domElementFrame.attribute("Y").toFloat(),
			domElementFrame.attribute("Z").toFloat(),
			domElementFrame.attribute("A").toFloat(),
			domElementFrame.attribute("B").toFloat(),
			domElementFrame.attribute("C").toFloat());
}

void Feedback::parseDocumentAxis(QDomElement domElementAxis) {
	axis_.set(domElementAxis.attribute("A1").toFloat(),
			domElementAxis.attribute("A2").toFloat(),
			domElementAxis.attribute("A3").toFloat(),
			domElementAxis.attribute("A4").toFloat(),
			domElementAxis.attribute("A5").toFloat(),
			domElementAxis.attribute("A6").toFloat());
}

void Feedback::parseDocumentPos(QDomElement domElementPos) {
	pos_s_ = domElementPos.attribute("S").toInt();
	pos_t_ = domElementPos.attribute("T").toInt();
}

void Feedback::printFeedbackFormated() {
//    if ( !parsedOK_ )
//        std::cout << "Document parsing failed" << std::endl;
//    else
//    {
//        std::cout << "Stamp: " << std::setw(10) << stamp_ << std::setw(10) << "Valid:";
//        if ( valid_ )
//            std::cout << std::setw(10) << "True" << std::endl;
//        else
//            std::cout << std::setw(10) << "False" << std::endl;
//        frame_.printFrame();
//        axis_.printAxis();
//    }
	std::cout << "Feedback::printFeedbackFormated not supported yet"
			<< std::endl;
}

void Feedback::printDocumentPlain(Indent indent) {
	if (!parsedOK_) {
		std::cout << "Feedback::printDocumentPlain: Document parsing failed"
				<< std::endl;
		return;
	}
	if (indent == IndentSpace)
		std::cout << doc_.toString().toStdString() << std::endl;
	else if (indent == IndentNone)
		std::cout << msg_.toStdString() << std::endl;
	else
		std::cout << "Feedback::printDocumentPlain: Indent not recognized"
				<< std::endl;
}

Frame& Feedback::getFrame() {
	return frame_;
}

Axis& Feedback::getAxis() {
	return axis_;
}

QString& Feedback::getMessage() {
	return msg_;
}

std::string& Feedback::getText() {
	return text_;
}

int Feedback::getStamp() {
	return parsedOK_ ? stamp_ : -1;
}

int Feedback::getSuccess() {
	return success_;
}

Feedback::Type Feedback::getType() {
	return type_;
}

bool Feedback::getSetOK() {
	return setOK_;
}

bool Feedback::getParsedOK() {
	return parsedOK_;
}

int Feedback::getBufferFront() {
	return buffer_front_;
}

int Feedback::getBufferLast() {
	return buffer_last_;
}

int Feedback::getSeq() {
	return seq_;
}

int Feedback::getHour() {
	return hour_;
}

int Feedback::getTime() {
	return time_;
}

Pos& Feedback::getPos() {
	return pos_;
}

Feedback::Extreme Feedback::getBufferExtreme() {
	return buffer_extreme_;
}
