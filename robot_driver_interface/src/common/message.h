/**
 *   Copyright (C) Tsinghua University 2016
 *
 *   Version   : 2.0
 *   Date      : 2016
 *   Author    : Xingtong Liu
 *   Company   : Tsinghua University
 *   Email     : 327586708@qq.com
 *
 *   Header file for message, defines the data prototype transferring between
 *   PC and KUKA Control Cabinet (KRC).
 *   KRC4 Compact is used in this project, with KSS 8.2 and EthernetKRL 2.1.
 *   For more information about EthernetKRL, see KUKA documentation, including
 *   its installation and configuration.
 *   Two types of messages flowing over ethernet: Comamnd and Feedback.
 *       - Command : PC -> KRC4
 *       - Feedback: KRC4 -> PC
 *   QtXML library supports for XML file construction and parsing.
 *
 */

#ifndef MY_MESSAGE_H
#define MY_MESSAGE_H

#include "geometry.h"
#include <QFile>
#include <QtXml/QtXml>

// --------------------------------------------------------------------------
// Command message example
//  - PC -> KRC4
// --------------------------------------------------------------------------
//  <Command>
//      <Basic Type="1" Stamp="20" />
//      <Message Text="Synchronized Control Command" />
//      <Motion Style="1" End="1" Approximation="0">
//          <Frame X="0.0" Y="0.0" Z="0.0" A="0.0" B="0.0" C="0.0" />
//          <Axis A1="10.0" A2="-90.0" A3="90.0" A4="0.0" A5="0.0" A6="0.0" />
//          <POS S="1" T="19" />
//          <SIRC End="1">
//              <Frame X="0.0" Y="0.0" Z="0.0" A="0.0" B="0.0" C="0.0" />
//              <Axis A1="10.0" A2="-90.0" A3="90.0" A4="0.0" A5="0.0" A6="0.0" />
//              <POS S="1" T="19" />
//              <CA Degree="180.0" />
//          </SIRC>
//      </Motion>
//      <Configuration>
//          <Parameter Type="1" Number="20.0" />
//      </Configuration>
//      <Other Type="1" />
//  </Command>
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
// Command message description
//      ----------------------
//        Basic/Type
//            0: Invalid command
//            1: Motion command
//            2: Configuration command
//            3: Other command
//      ----------------------
//        Basic/Stamp: The sequence number of all commands issued by PC
//      ----------------------
//        Message/Text: Auxiliary information
//      ----------------------
//        Motion/Style
//            0: PTP
//            1: LIN
//            2: SIRC
//      ----------------------
//        Motion/End: End point type
//            0: Frame
//            1: POS
//            2: Axis
//      ----------------------
//        Motion/Approxiamtion
//            0: None
//            1: C_PTP
//            2: C_DIS
//            3: C_VEL
//            4: C_ORI
//            5: combined... (further development)
//      ----------------------
//        Motion/SIRC/End
//            0: Frame
//            1: POS
//            2：Axis
//      ----------------------
//        Configuration/Parameter/Type
//            0: $ADVANCE
//            1: $ACC_PTP
//            2: $VEL_PTP
//            3: $ACC_CP
//            4: $ACC.ORI1
//            5: $ACC.ORI2
//            6: $VEL_CP
//            7: $VEL.ORI1
//            8: $VEL.ORI2
//            9: $APO.CPTP
//            10: $APO.CDIS (mm)
//            11: $APO.CVEL
//            12: $APO.CORI
//      ----------------------
//        Other/Type"
//            0: PAUSE immediately
//            1: PAUSE buffered
//            2: STOP
//            3: CANCEL the last command (not supported)
//            4: TERMINATE buffered
//            5: TERMINATE immediately (after current command)
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Feedback message example
//  - KRC4 -> PC
// --------------------------------------------------------------------------
//  <Feedback>
//      <Basic Type="1" />
//      <Status Seq="200" Hour="0" Time="20000">
//          <Frame X="0.0" Y="0.0" Z="0.0" A="0.0" B="0.0" C="0.0" />
//          <Axis A1="0.0" A2="0.0" A3="0.0" A4="0.0" A5="0.0" A6="0.0" />
//          <Pos S="6" T="18">
//          <Buffer Front="21" Last="79" Extreme="0"/>
//      </Status>
//      <Result Stamp="20" Success="1">
//          <Message Text="Synchronized Control Complete" />
//      </Result>
//  </Feedback>
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
// Feedback message description
//      ----------------------
//        Basic/Type
//            0: Timer feedback
//            1: Timer feedback + Command feedback
//      ----------------------
//        Status/Seq: Sequence number of feedback message
//      ----------------------
//        Status/Hour: Hour count from the start of the program
//      ----------------------
//        Status/Time: Time less than one hour
//      ----------------------
//        Status/Buffer/Front: Current motion in the buffer
//      ----------------------
//        Status/Buffer/Last: Last motion command received in the buffer
//      ----------------------
//        Status/Buffer/Extreme
//            0: Normal
//            -1: Empty
//            1: Full
//      ----------------------
//        Result/Stamp: The sequence number of Command received
//      ----------------------
//        Result/Success: Whether the Command is successfully processed
//      ----------------------
//        Result/Message: Auxiliary message
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Default value for Command units
// --------------------------------------------------------------------------
#define DEF_COMMAND_TYPE 1
#define DEF_COMMAND_STYLE 0
#define DEF_COMMAND_END 0
#define DEF_COMMAND_APPROX 0
#define DEF_COMMAND_POS_S 0
#define DEF_COMMAND_POS_T 0
#define DEF_COMMAND_CIRC_END 0
#define DEF_COMMAND_CIRC_POS_S 0
#define DEF_COMMAND_CIRC_POS_T 0
#define DEF_COMMAND_CIRC_DEGREE 0
#define DEF_COMMAND_PARAM_TYPE 0
#define DEF_COMMAND_PARAM_NUM 5.0
#define DEF_COMMAND_OTHER_TYPE 4

// --------------------------------------------------------------------------
// Command type
// --------------------------------------------------------------------------
#define COMMAND_TYPE_INVALID 0
#define COMMAND_TYPE_MOTION 1
#define COMMAND_TYPE_CONFIG 2
#define COMMAND_TYPE_OTHER 3

// --------------------------------------------------------------------------
// Command style for motion
// --------------------------------------------------------------------------
#define COMMAND_STYLE_PTP 0
#define COMMAND_STYLE_LIN 1
#define COMMAND_STYLE_SIRC 2

// --------------------------------------------------------------------------
// End point type
// --------------------------------------------------------------------------
#define COMMAND_END_FRAME 0
#define COMMAND_END_POS 1
#define COMMAND_END_AXIS 2

// --------------------------------------------------------------------------
// Approximation methods for motion
// --------------------------------------------------------------------------
#define COMMAND_APPROX_NONE 0
#define COMMAND_APPROX_CPTP 1
#define COMMAND_APPROX_CDIS 2
#define COMMAND_APPROX_CVEL 3
#define COMMAND_APPROX_CORI 4

// --------------------------------------------------------------------------
// Configuration commands
// --------------------------------------------------------------------------
#define COMMAND_PARAM_ADVANCE 0
#define COMMAND_PARAM_ACC_PTP 1
#define COMMAND_PARAM_VEL_PTP 2
#define COMMAND_PARAM_ACC_CP 3
#define COMMAND_PARAM_ACC_ORI1 4
#define COMMAND_PARAM_ACC_ORI2 5
#define COMMAND_PARAM_VEL_CP 6
#define COMMAND_PARAM_VEL_ORI1 7
#define COMMAND_PARAM_VEL_ORI2 8
#define COMMAND_PARAM_APO_CPTP 9
#define COMMAND_PARAM_APO_CDIS 10
#define COMMAND_PARAM_APO_CVEL 11
#define COMMAND_PARAM_APO_CORI 12

// --------------------------------------------------------------------------
// Other commands: for execution control
// --------------------------------------------------------------------------
// PAUSE_IMM:
//  - realized by BRAKE -> HALT -> RESUME combination
//  - pressing "continue" button on the KRC pad resumes the program
//  - the next motion will be the one follows the advance pointer
//  - if $ADVANCE == 0, the program will continus to execute the paused motion
//  - if $ADVANCE == 1, the program will execute the next motion
//  - global clock is not paused
//  - feedback message: PAUSE immediately
#define COMMAND_OTHER_PAUSE_IMM 0

// PAUSE_BUF:
//  - realized by HALT
//  - the program will be paused where the command is buffered
//  - pressing "continue" button on the KRC pad resumes the program
//  - global clock is not paused
//  - feedback message: PAUSE buffered
#define COMMAND_OTHER_PAUSE_BUF 1

// STOP:
//  - realized by BRAKE -> CLEAR BUF -> HALT -> RESUME
//  - pressing "continue" button on the KRC pad resumes the program
//  - KRL buffer will be emptied
//  - no motion will be executed without arrival of new motion commands
//  - feedback message: STOP immediately
#define COMMAND_OTHER_STOP 2

// CANCEL:
//  - not supported at this stage
#define COMMAND_OTHER_CANCEL 3

// TERMINATE_BUF:
//  - terminate command buffered in KRL
//  - when terminate command executed, KRL program finishes
//  - feedback message: TERMINATE buffered
//  - error message: TERMINATE command not buffered: Buffer full
#define COMMAND_OTHER_TERMINATE_BUF 4

// TERMINATE_IMM:
//  - terminate command pushed to the front of KRL buffer (right behind advance run pointer)
//  - all other motion commands afterwards are ignored
//  - the program will finish after advance run motion completes
//  - feedback message: TERMINATE immediately
#define COMMAND_OTHER_TERMINATE_IMM 5

// --------------------------------------------------------------------------
// Command state: for queue management on PC side
// --------------------------------------------------------------------------
// NOFEEDBACK:
//  - new command not sent to KRL
//  - command just sent without feedback received
#define COMMAND_STATE_NOFEEDBACK 0

// ERROR:
//  - command with error reported by KRL
//  - command ignored for execution control purposes
//  - caused by STOP, TERMINATE_BUF, TERMINATE_IMM
#define COMMAND_STATE_ERROR -1

// BUFFERED:
//  - command pushed into the buffer in KRL
//  - motion command, PAUSE_BUF, TERMINATE_BUF, TERMINATE_IMM
#define COMMAND_STATE_BUFFERED 1

// SUCCESS:
//  - only for execution control command which has higher priority over other command
//  - this kind of command is never buffered in KRL
//  - STOP, PAUSE_IMM
#define COMMAND_STATE_SUCCESS 2

// --------------------------------------------------------------------------
// Feedback message type
// --------------------------------------------------------------------------
// Pure timer feedback, initiated with KRL timer
#define FEEDBACK_TYPE_TIMER 0
// Hybrid feedback, initiated with KRL timer + information about last Command
#define FEEDBACK_TYPE_HYBRID 1

// --------------------------------------------------------------------------
// Feedback buffer status
// --------------------------------------------------------------------------
#define FEEDBACK_BUFFER_EXTREME_FULL 1
#define FEEDBACK_BUFFER_EXTREME_EMPTY -1
#define FEEDBACK_BUFFER_EXTREME_NORMAL 0

// --------------------------------------------------------------------------
// Indent for printing XML message
// --------------------------------------------------------------------------
// Without any indent between elements and nodes (one space between attributes)
#define INDENT_NONE 0
// With one space indent between elements and nodes
#define INDENT_SPACE 1

// --------------------------------------------------------------------------
// Command class
// --------------------------------------------------------------------------
class Command {
public:
	enum Type {
		Motion = COMMAND_TYPE_MOTION,
		Config = COMMAND_TYPE_CONFIG,
		Other = COMMAND_TYPE_OTHER,
		Invalid = COMMAND_TYPE_INVALID
	}const static DEFAULT_TYPE = Motion;

	enum Style {
		PTP = COMMAND_STYLE_PTP,
		LIN = COMMAND_STYLE_LIN,
		CIRC = COMMAND_STYLE_SIRC
	}const static DEFAULT_STYLE = PTP;

	enum Approx {
		NONE = COMMAND_APPROX_NONE,
		C_PTP = COMMAND_APPROX_CPTP,
		C_DIS = COMMAND_APPROX_CDIS,
		C_VEL = COMMAND_APPROX_CVEL,
		C_ORI = COMMAND_APPROX_CORI
	}const static DEFAULT_APPROX = NONE;

	enum Param {
		ADVANCE = COMMAND_PARAM_ADVANCE,
		ACC_PTP = COMMAND_PARAM_ACC_PTP,
		VEL_PTP = COMMAND_PARAM_VEL_PTP,
		ACC_CP = COMMAND_PARAM_ACC_CP,
		ACC_ORI1 = COMMAND_PARAM_ACC_ORI1,
		ACC_ORI2 = COMMAND_PARAM_ACC_ORI2,
		VEL_CP = COMMAND_PARAM_VEL_CP,
		VEL_ORI1 = COMMAND_PARAM_VEL_ORI1,
		VEL_ORI2 = COMMAND_PARAM_VEL_ORI2,
		APO_CPTP = COMMAND_PARAM_APO_CPTP,
		APO_CDIS = COMMAND_PARAM_APO_CDIS,
		APO_CVEL = COMMAND_PARAM_APO_CVEL,
		APO_CORI = COMMAND_PARAM_APO_CORI
	}const static DEFAULT_PARAM = ADVANCE;

	enum OtherType {
		Pause = COMMAND_OTHER_PAUSE_IMM,
		PauseBuf = COMMAND_OTHER_PAUSE_BUF,
		Stop = COMMAND_OTHER_STOP,
		Cancel = COMMAND_OTHER_CANCEL,
		Terminate = COMMAND_OTHER_TERMINATE_BUF,
		TerminateImm = COMMAND_OTHER_TERMINATE_IMM
	}const static DEFAULT_OTHERTYPE = Terminate;

	enum State {
		SUCCESS = COMMAND_STATE_SUCCESS,
		ERROR = COMMAND_STATE_ERROR,
		NOFEEDBACK = COMMAND_STATE_NOFEEDBACK,
		BUFFERED = COMMAND_STATE_BUFFERED
	}const static DEFAULT_STATE = NOFEEDBACK;

	enum Indent {
		IndentSpace = INDENT_SPACE, IndentNone = INDENT_NONE
	};

	// Motion Command constructor: PTP, LIN
	// End point could be Frame, Axis or Pos
	// Error check: type should be COMMAND_TYPE_MOTION
	// Error check: style should be COMMAND_STYLE_PTP or COMMAND_STYLE_LIN
	Command(Type type, Style style, Frame& f, int st, Approx approx = NONE);
	Command(Type type, Style style, Axis& a, int st, Approx approx = NONE);
	Command(Type type, Style style, Pos& p, int st, Approx approx = NONE);

	// Motion Command constructor: CIRC
	// End point and auxiliary point could be Frame, Axis or Pos
	// Error check: type should be COMMAND_TYPE_MOTION
	// Error check: style should be COMMAND_STYLE_CIRC
	// SIRC CA parameter specified in deg. (not rad.)
	Command(Type type, Style style, Frame& f_end, Frame& f_aux, float degree,
			int st, Approx approx = NONE);
	Command(Type type, Style style, Frame& f_end, Axis& a_aux, float degree,
			int st, Approx approx = NONE);
	Command(Type type, Style style, Frame& f_end, Pos& p_aux, float degree,
			int st, Approx approx = NONE);
	Command(Type type, Style style, Axis& a_end, Frame& f_aux, float degree,
			int st, Approx approx = NONE);
	Command(Type type, Style style, Axis& a_end, Axis& a_aux, float degree,
			int st, Approx approx = NONE);
	Command(Type type, Style style, Axis& a_end, Pos& p_aux, float degree,
			int st, Approx approx = NONE);
	Command(Type type, Style style, Pos& p_end, Frame& f_aux, float degree,
			int st, Approx approx = NONE);
	Command(Type type, Style style, Pos& p_end, Axis& a_aux, float degree,
			int st, Approx approx = NONE);
	Command(Type type, Style style, Pos& p_end, Pos& p_aux, float degree,
			int st, Approx approx = NONE);

	// Configuration Command constructor
	// For $ADVANCE, number is still float, for sake of integrity
	// KRL is able to process this command
	// Error check: type should be COMMAND_TYPE_CONFIG
	Command(Type type, Param param, float number, int st);

	// Other Command constructor
	// Error check: type should be COMMAND_TYPE_OTHER
	Command(Type type, OtherType other_type, int st);

	// Deconstructor of Command
	// Delete pointer: doc_
	~Command();

	// Construct a Command
	// QtXML library is used to construct XML file (DOM method)
	// More information see Qt documentation
	void constructCommand();

	// checkZero is called when constructing an XML
	// For small number represented in forms like 1.0e-6,
	// EthernetKRL is not able to parse it as REAL number
	void checkZero(Frame& f);
	void checkZero(Axis& a);
	void checkZero(float& num);

	// Set method: stamp_
	void setStamp(int st);
	// Set method: state_
	void setState(State state);

	// Get method: doc_
	QDomDocument* getDocument();
	// Get method: msg_, no indent
	QString& getMessage();
	// Get method: stamp_
	int getStamp();
	// Get method: state_
	State getState();
	// Get method: type_
	Type getType();
	// Get method: other_type_
	OtherType getOtherType();
	// Get method: frame_
	Frame& getFrame();
	// Get method: axis_
	Axis& getAxis();
	// Get method: emergent_
	bool getEmergent();

	// print a Command in well format: not supported yet
	void printCommandFormated();
	// print a Command as plain text, with indent selectable
	void printDocumentPlain(Indent indent = IndentSpace);

private:
	// if Command is well constructed
	bool valid_;
	// emergent_ is set true if type_ == COMMAND_TYPE_OTHER
	// and ( other_type == COMMAND_OTHER_TERMINATE_IMM
	//    or other_type == COMMAND_OTHER_PAUSE_IMM
	//    or other_type == COMMAND_OTHER_STOP )
	bool emergent_;

	// state:
	// NOFEEDBACK:
	//  - new command not sent to KRL
	//  - command just sent without feedback received
	// ERROR:
	//  - command with error reported by KRL
	//  - command ignored for execution control purposes
	//  - caused by STOP, TERMINATE_BUF, TERMINATE_IMM
	// BUFFERED:
	//  - command pushed into the buffer in KRL
	//  - motion command, PAUSE_BUF, TERMINATE_BUF, TERMINATE_IMM
	// SUCCESS:
	//  - only for execution control command which has higher priority over other command
	//  - this kind of command is never buffered in KRL
	//  - STOP, PAUSE_IMM
	State state_;

	// Data member of a Command
	// Frame for end point
	Frame frame_;
	// Frame for circ auxiliary point
	Frame circ_frame_;
	// Axis for end point
	Axis axis_;
	// Axis for circ auxiliary point
	Axis circ_axis_;
	Type type_;
	int stamp_;
	QString text_;
	Style style_;
	int end_;
	Approx approx_;
	int pos_s_;
	int pos_t_;
	int circ_end_;
	int circ_pos_s_;
	int circ_pos_t_;
	float circ_degree_;
	Param param_type_;
	float param_num_;
	OtherType other_type_;

	// A Command as text, without any indent
	QString msg_;

	// QDomDocument and QDom Element for constructing an XML file
	QDomDocument* doc_;
	QDomElement eleCommand;
	QDomElement eleBasic;
	QDomElement eleMessage;
	QDomElement eleMotion;
	QDomElement eleMotionFrame;
	QDomElement eleMotionAxis;
	QDomElement eleMotionPOS;
	QDomElement eleMotionSIRC;
	QDomElement eleMotionSIRCFrame;
	QDomElement eleMotionSIRCAxis;
	QDomElement eleMotionSIRCPOS;
	QDomElement eleMotionSIRCCA;
	QDomElement eleConfig;
	QDomElement eleConfigParam;
	QDomElement eleOther;

};

// --------------------------------------------------------------------------
// Feedback class
// --------------------------------------------------------------------------
class Feedback {

public:
	enum Type {
		Timer = FEEDBACK_TYPE_TIMER, Hybrid = FEEDBACK_TYPE_HYBRID
	};
	enum Extreme {
		Full = FEEDBACK_BUFFER_EXTREME_FULL,
		Empty = FEEDBACK_BUFFER_EXTREME_EMPTY,
		Normal = FEEDBACK_BUFFER_EXTREME_NORMAL
	};
	enum Indent {
		IndentSpace = INDENT_SPACE, IndentNone = INDENT_NONE
	};

	// Default Feedback constructor, an invalid Feedback is created
	// setOK_ and parsedOK_ are both false
	Feedback();
	// Feedback constructed from file
	// path and filename specified in const char* filename
	// When error, setOK_ is false
	// Feedback::parseDocument is automatically called
	Feedback(const char* filename);
	// Feedback constructed from plain text QString &qs
	// When error, setOK_ is false
	// Feedback::parseDocument is automatically called
	Feedback(const QString &qs, bool& isParsed);

	// Automatically called if QDocument is successfully set
	// Parse the document as format inexplicitly specified in this function
	// If correctly parsed, parsedOK_ is set to true
	int parseDocument();
	// Construct frame_ from QDomElement domElementFrame
	void parseDocumentFrame(QDomElement domElementFrame);
	// Construct axis_ from QDomElement domElementAxis
	void parseDocumentAxis(QDomElement domElementAxis);
	// Get pos_s_ and pos_t_ from QDomElement domElementPos
	// The complete pos_ member is created with frame_, pos_s_ and pos_t_ later
	void parseDocumentPos(QDomElement domElementPos);

	// print a Feedback in well format: not supported yet
	void printFeedbackFormated();
	// print a Feedback as plain text, with indent selectable
	void printDocumentPlain(Indent indent = IndentSpace);

	// Get method: frame_
	Frame& getFrame();
	// Get method: axis_
	Axis& getAxis();
	// Get method: pos_
	Pos& getPos();
	// Get method: msg_, without indent
	QString& getMessage();
	// Get method: text_
	std::string &getText();
	// Get method: stamp_
	int getStamp();
	// Get method: success_
	int getSuccess();
	// Get method: type_
	Type getType();
	// Get method: setOK_
	bool getSetOK();
	// Get method: parsedOK_
	bool getParsedOK();
	// Get method: buffer_front_
	int getBufferFront();
	// Get method: buffer_last_
	int getBufferLast();
	// Get method: buffer_extreme_
	Extreme getBufferExtreme();
	// Get method: seq_
	int getSeq();
	// Get method: hour_
	int getHour();
	// Get method: time_
	int getTime();

private:
	// no indent in msg_, plain text
	QString msg_;

	// QDomDocument for root
	QDomDocument doc_;
	// If Feedback is correctly parsed
	bool parsedOK_;
	// If Feedback is correctly set, from file or plain text
	bool setOK_;

	// Data member of a Feedback
	Type type_;
	int seq_;
	int hour_;
	int time_;
	Frame frame_;
	Axis axis_;
	Pos pos_;
	int pos_s_;
	int pos_t_;
	int buffer_front_;
	int buffer_last_;
	Extreme buffer_extreme_;
	int stamp_;
	bool success_;
	bool buffer_full_;
	bool buffer_empty_;
	std::string text_;
};

#endif
