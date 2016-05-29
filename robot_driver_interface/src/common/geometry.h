/**
 *   Copyright (C) Tsinghua University 2016
 *
 *   Version   : 2.0
 *   Date      : 2016
 *   Author    : Xingtong Liu
 *   Company   : Tsinghua University
 *   Email     : 327586708@qq.com
 *   Header file for robot geometry, including basic data type associated
 *   with kuka robot description: Frame, Axis, Pos.
 *   Forward and inverse kinematics of robot is setup in Model class.
 *   For this project, KUKA KR6 R700 sixx is used. Thus, other robot type
 *   should load its own default value and URDF description.
 *   kdl_parser and orocos_kdl support for robot model construction.
 *
 */

#ifndef KRC4_GEOMETRY
#define KRC4_GEOMETRY

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <kdl_parser/kdl_parser.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolverpos_lma.hpp>
#include <kdl/frames.hpp>
#include <ros/ros.h>
// --------------------------------------------------------------------------
// Default value for robot position (in mm), $H_POS
// --------------------------------------------------------------------------
#define DEFAULT_X 470.0
#define DEFAULT_Y 0.0
#define DEFAULT_Z 750.0
#define DEFAULT_A 0.0
#define DEFAULT_B 90.0
#define DEFAULT_C 0.0
#define DEFAULT_S 2
#define DEFAULT_T 2

// --------------------------------------------------------------------------
// Default value for robot axis position (in degrees)
// --------------------------------------------------------------------------
#define DEFAULT_A1 0.0
#define DEFAULT_A2 -90.0
#define DEFAULT_A3 90.0
#define DEFAULT_A4 0.0
#define DEFAULT_A5 0.0
#define DEFAULT_A6 0.0

// --------------------------------------------------------------------------
// Limitation for each axis (in degrees)
// Values could be found on smartPAD:
//  - Menu/Configuration/Machine Configuration/Software limit switches
// --------------------------------------------------------------------------
#define A1_LOWER -170
#define A1_UPPER 170
#define A2_LOWER -190
#define A2_UPPER 45
#define A3_LOWER -120
#define A3_UPPER 156
#define A4_LOWER -185
#define A4_UPPER 185
#define A5_LOWER -120
#define A5_UPPER 120
#define A6_LOWER -350
#define A6_UPPER 350

// --------------------------------------------------------------------------
// For calculating POS.S from AXIS
// STATUS_A3_THRESHOLD: atan(35/365)
// --------------------------------------------------------------------------
#define STATUS_A3_THRESHOLD 5.477368729

// --------------------------------------------------------------------------
// Data structure: Frame
//  - corresponds to FRAME in KRL
//  - X, Y, Z is cartesian position
//  - A, B, C is EulerZYX angle to represent orientation (in degrees)
//    * First rotate around Z with A,
//      then around the new Y with B,
//      then around new X with C.
//    * Range of A, B, C :
//      -180 <= A <= 180
//      -180 <= B <= 180
//      -90  <= C <= 90
//    * if B == 90 or B == -90, multiple solutions for C and A exist.
//      The solution where C == 0 is chosen.
// --------------------------------------------------------------------------
struct Frame {
	enum Param {
		ValX, ValY, ValZ, ValA, ValB, ValC
	};

	float X;
	float Y;
	float Z;
	float A;
	float B;
	float C;

	// Operator + support for Frame calculation
	// add each component of the two frames
	Frame& operator+(const Frame& right);

	Frame& operator=(const Frame& right);

	// Frame constructor, with offset of cartesian position
	Frame(const Frame& f, float x_add = 0.0, float y_add = 0.0, float z_add = 0.0);

	// Default Frame constructor, with default value set to $H_POS
	Frame(float x = DEFAULT_X, float y = DEFAULT_Y, float z = DEFAULT_Z,
			float a = DEFAULT_A, float b = DEFAULT_B, float c = DEFAULT_C);

	// Set Frame with individual numbers
	void set(float x = DEFAULT_X, float y = DEFAULT_Y, float z = DEFAULT_Z,
			float a = DEFAULT_A, float b = DEFAULT_B, float c = DEFAULT_C);

	// Set Frame with reference of other Frame
	void set(Frame& f);

	// Print out the Frame
	void printFrame();
};

// --------------------------------------------------------------------------
// Data structure: Axis
//  - corresponds to AXIS in KRL
//  - A1, A2, A3, A4, A5, A6 represents the angle of each joint (in degrees)
// --------------------------------------------------------------------------
struct Axis {
	enum Param {
		ValA1, ValA2, ValA3, ValA4, ValA5, ValA6
	};

	float A1;
	float A2;
	float A3;
	float A4;
	float A5;
	float A6;

	// Default constructor for Axis, with default value set to home AXIS
	Axis(float a1 = DEFAULT_A1, float a2 = DEFAULT_A2, float a3 = DEFAULT_A3,
			float a4 = DEFAULT_A4, float a5 = DEFAULT_A5,
			float a6 = DEFAULT_A6);

	// Copy constructor for Axis
	Axis(Axis& a);

	// Operator + support for Axis, adds up two Axis
	void operator+(const Axis& right);

	// Set Axis with individual angle values of each joint
	void set(float a1 = DEFAULT_A1, float a2 = DEFAULT_A2,
			float a3 = DEFAULT_A3, float a4 = DEFAULT_A4, float a5 = DEFAULT_A5,
			float a6 = DEFAULT_A6);

	// Set Axis with reference of other Axis
	void set(Axis &a);

	// Print out the Axis
	void printAxis();
};

// --------------------------------------------------------------------------
// Data structure: Pos
//  - corresponds to POS in KRL
//  - Pos = Frame + S(Status) + T(Turn)
//  - For more information about Status and Turn, see KUKA KSS8.2
//      << Operating and Programming Instructions for System Integrators>>, P284
//  - Status and Turn are integers
// --------------------------------------------------------------------------
struct Pos {
	enum Param {
		ValX, ValY, ValZ, ValA, ValB, ValC, ValS, ValT
	};

	Frame F;
	int S;
	int T;

	// Constructor for Pos, with Frame, Status, Turn specified
	Pos(Frame& f, int s = DEFAULT_S, int t = DEFAULT_T);

	// Default constructor for Pos, with position same with $H_POS
	Pos(int s = DEFAULT_S, int t = DEFAULT_T);

	// Set method for Pos
	void set(Frame& f, int s = DEFAULT_S, int t = DEFAULT_T);

	// Print out a Pos parameter
	void printPos();
};

// --------------------------------------------------------------------------
// Data structure: Model
//  - Geometry of a robot with URDF description file
//  - URFD description is derived from DH parameters of robot
//  - KUKA KR6 R700 sixx is used here
//  - DH parameters could be found on KUKA smartPAD:
//      Menu/Configuration/Safety configuration/Machine data, press "View"
//  - kdl_parser and orocos_kdl library is utilized
//  - Note that inverse kinematics is iteratively calculated rather than close-form
//      expressed, could be inaccurate, and the result is dependent on initial value.
// --------------------------------------------------------------------------
class Model {
public:
	// Default constructor for Model
	// Default URDF file path = ../robot/kuka_kr6_description.urdf
	// KDL::Tree and KDL::Chain are constructed here
	Model(
			std::string fn =
					"/home/lxt12/Kuka_interface/src/kuka_kr6/robots/kuka_kr6_needle.urdf");

	// Deconstructor for Model
	// Delete pointer contents: forward and inverse solver
	~Model();

	// Setup forward and inverse solver
	// Two forward solver are set up
	// fkSolver_    : recursive solver, from root to tip
	// fkSolver_rot_: recursive solver, from root to intersection of A4, A5 and A6
	//                                                      (for calculating Pos.S)
	// ikSolver_    : LMA solver
	void setupSolver();

	// Convertion from Axis to Frame
	// output is passed through reference parameter &f
	// if return false, something went wrong
	bool Axis2Frame(Axis &a, Frame &f);
	bool Axis2Frame_flange(Axis &a, Frame &f);
	// Convertion from Frame to Axis
	// output is passed through reference Axis &a
	// Axis &a_init used as initial point for iteration
	// if return false, something went wrong
	bool Frame2Axis(Axis &a_init, Frame &f, Axis &a);

	// Converstion from Axis to Pos
	// output is passed through reference parameter &p
	// if return false, something went wrong
	bool Axis2Pos(Axis &a, Pos &p);

	// Conversion from Pos to Axis
	// output is passed through reference Axis &a
	// Axis &a_init used as initial point for iteration
	// this function inherit from Frame2Axis
	// status and turn are redundant parameter
	// if return false, something went wrong
	bool Pos2Axis(Axis &a_init, Pos &p, Axis &a);

	// Calculate Turn from Axis &a, save to Pos &p
	// Turn = bit0 + bit1 + bit2 + bit3 + bit4 + bit5;
	// bit(X-1) is set true if A(X) is less than 0
	// More information see KUKA_KSS_8_2_SI.pdf, p287
	int getTurn(Pos &p, Axis &a);

	// Calculate Status from Axis &a and (x, y), save to Pos &p
	// (x, y) is the X, Y value for the intersection point of A4, A5 and A6
	// Status = bit0 + bit1 + bit2;
	// bit0 is set true if intersetion point (x, y) is overhead
	// bit1 is set true if A3 > STATUS_A3_THRESHOLD = atan(35/365)
	// bit2 is set true if A5 < 0
	// More information see KUKA_KSS_8_2_SI.pdf, p284
	int getStatus(Pos &p, Axis &a, double x, double y);

private:

	// True if KDL::Tree and KDL::Chain is successfully parsed
	bool valid_;

	// KDL::Tree from root to tip
	KDL::Tree tree_;

	// KDL::Chain from root to tip
	KDL::Chain chain_;

	// KDL::Chain from root to intersetion point of A4, A5 and A6
	// for calculating Pos.S
	KDL::Chain chain_flange_;

	// Path and filename for URDF description
	std::string filename;

	// Solver pointers for conversion between Axis, Frame, Pos
	KDL::ChainFkSolverPos_recursive* fkSolver_;
	KDL::ChainFkSolverPos_recursive* fkSolver_flange_;
	KDL::ChainIkSolverPos_LMA* ikSolver_;
};

#endif

