/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 20 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#include "geometry.h"
#include <iomanip>
#include <cmath>

Frame& Frame::operator+(const Frame& right) {
	X = this->X + right.X;
	Y = this->Y + right.Y;
	Z = this->Z + right.Z;
	A = this->A + right.A;
	B = this->B + right.B;
	C = this->C + right.C;
	return *this;
}

Frame::Frame(Frame& f, float x_add, float y_add, float z_add) {
	X = f.X + x_add;
	Y = f.Y + y_add;
	Z = f.Z + z_add;
	A = f.A;
	B = f.B;
	C = f.C;
}

Frame::Frame(float x, float y, float z, float a, float b, float c) {
	X = x;
	Y = y;
	Z = z;
	A = a;
	B = b;
	C = c;
}

void Frame::set(float x, float y, float z, float a, float b, float c) {
	X = x;
	Y = y;
	Z = z;
	A = a;
	B = b;
	C = c;
}

void Frame::set(Frame& f) {
	X = f.X;
	Y = f.Y;
	Z = f.Z;
	A = f.A;
	B = f.B;
	C = f.C;
}

void Frame::printFrame() {
	std::cout << "Frame: " << std::setw(16) << X << std::setw(16) << Y
			<< std::setw(16) << Z << std::setw(16) << A << std::setw(16) << B
			<< std::setw(16) << C << std::endl;
}

Axis::Axis(float a1, float a2, float a3, float a4, float a5, float a6) {
	A1 = a1;
	A2 = a2;
	A3 = a3;
	A4 = a4;
	A5 = a5;
	A6 = a6;
}

Axis::Axis(Axis& a) {
	A1 = a.A1;
	A2 = a.A2;
	A3 = a.A3;
	A4 = a.A4;
	A5 = a.A5;
	A6 = a.A6;
}

Axis& Axis::operator+(const Axis& right) {
	A1 = this->A1 + right.A1;
	A2 = this->A2 + right.A2;
	A3 = this->A3 + right.A3;
	A4 = this->A4 + right.A4;
	A5 = this->A5 + right.A5;
	A6 = this->A6 + right.A6;
}

void Axis::set(float a1, float a2, float a3, float a4, float a5, float a6) {
	A1 = a1;
	A2 = a2;
	A3 = a3;
	A4 = a4;
	A5 = a5;
	A6 = a6;
}

void Axis::set(Axis &a) {
	A1 = a.A1;
	A2 = a.A2;
	A3 = a.A3;
	A4 = a.A4;
	A5 = a.A5;
	A6 = a.A6;
}

void Axis::printAxis() {
	std::cout << "Axis : " << std::setw(16) << A1 << std::setw(16) << A2
			<< std::setw(16) << A3 << std::setw(16) << A4 << std::setw(16) << A5
			<< std::setw(16) << A6 << std::endl;
}

Pos::Pos(Frame &f, int s, int t) {
	F.set(f);
	S = s;
	T = t;
}

Pos::Pos(int s, int t) {
	F.X = DEFAULT_X;
	F.Y = DEFAULT_Y;
	F.Z = DEFAULT_Z;
	F.A = DEFAULT_A;
	F.B = DEFAULT_B;
	F.C = DEFAULT_C;
	S = s;
	T = t;
}

void Pos::set(Frame &f, int s, int t) {
	F.set(f);
	S = s;
	T = t;
}

void Pos::printPos() {
	std::cout << "Pos  : " << std::setw(16) << F.X << std::setw(16) << F.Y
			<< std::setw(16) << F.Z << std::setw(16) << F.A << std::setw(16)
			<< F.B << std::setw(16) << F.C << std::setw(16) << S
			<< std::setw(16) << T << std::endl;
}

Model::Model(std::string fn) :
		filename(fn) {
	std::cout << "Model Constructing..." << std::endl;

	valid_ = true;
	if (!kdl_parser::treeFromFile(filename, tree_)) {
		std::cout << "Model::Model: Failed to construct kdl tree" << std::endl;
		valid_ = false;
	} else {
		std::cout << "Number of Joints in Tree = " << tree_.getNrOfJoints()
				<< std::endl;

		// kdl::tree -> kdl::chain
		std::string rootLink = "base_link";
		std::string tipLink = "tip";
		std::string rot_center = "link6";
		if (!tree_.getChain(rootLink, tipLink, chain_)) {
			std::cout
					<< "Model::Model: Failed to get chain from kdl tree, check root/tip link"
					<< std::endl;
			valid_ = false;
		}
		if (!tree_.getChain(rootLink, rot_center, chain_rot_)) {
			std::cout
					<< "Model::Model: Failed to get chain from kdl tree, check root/rot link"
					<< std::endl;
			valid_ = false;
		} else
			std::cout << "Number of Joints in Chain = "
					<< chain_.getNrOfJoints() << std::endl;
	}
	setupSolver();
}

Model::~Model() {
	delete ikSolver_;
	delete fkSolver_;
	delete fkSolver_rot_;
	std::cout << "Model Deconstructing..." << std::endl;
}

void Model::setupSolver() {
	if (valid_) {
		fkSolver_ = new KDL::ChainFkSolverPos_recursive(chain_);
		fkSolver_rot_ = new KDL::ChainFkSolverPos_recursive(chain_rot_);
		ikSolver_ = new KDL::ChainIkSolverPos_LMA(chain_);
		std::cout << "Model::setupSolver: OK" << std::endl;
	} else
		std::cout << "Model::setupSolver: Failed, chain_ invalid" << std::endl;
}

bool Model::Axis2Frame(Axis &a, Frame &f) {
	int ret_val = 0;
	if (valid_) {
		// Init KDL variables
		KDL::JntArray jnt_q = KDL::JntArray(6);
		KDL::Frame tipFrame;
		jnt_q(0) = a.A1 / 180.0 * M_PI;
		jnt_q(1) = a.A2 / 180.0 * M_PI;
		jnt_q(2) = a.A3 / 180.0 * M_PI;
		jnt_q(3) = a.A4 / 180.0 * M_PI;
		jnt_q(4) = a.A5 / 180.0 * M_PI;
		jnt_q(5) = a.A6 / 180.0 * M_PI;

		// Forward Solver
		ret_val = fkSolver_->JntToCart(jnt_q, tipFrame);
		if (ret_val < 0) {
			std::cout
					<< "Model::Axis2Frame: JntToCart error, Frame set to Home value"
					<< std::endl;
			f.set();
			return false;
		}

		// Cast into old format
		f.X = tipFrame.p.data[0] * 1000.0;
		f.Y = tipFrame.p.data[1] * 1000.0;
		f.Z = tipFrame.p.data[2] * 1000.0;
		double r, p, y;
		tipFrame.M.GetEulerZYX(r, p, y);
		f.A = (float) r * 180.0 / M_PI;
		f.B = (float) p * 180.0 / M_PI;
		f.C = (float) y * 180.0 / M_PI;

		return true;
	} else {
		std::cout << "Model::Axis2Frame: Failed, solver invalid" << std::endl;
		f.set();
		return false;
	}
}

bool Model::Frame2Axis(Axis &a_init, Frame &f, Axis &a) {
	int ret_val = 0;
	if (valid_) {
		// Init KDL variables
		KDL::JntArray jnt_init = KDL::JntArray(6);
		KDL::JntArray jnt_q = KDL::JntArray(6);
		KDL::Frame tipFrame;
		jnt_init(0) = a_init.A1 / 180.0 * M_PI;
		jnt_init(1) = a_init.A2 / 180.0 * M_PI;
		jnt_init(2) = a_init.A3 / 180.0 * M_PI;
		jnt_init(3) = a_init.A4 / 180.0 * M_PI;
		jnt_init(4) = a_init.A5 / 180.0 * M_PI;
		jnt_init(5) = a_init.A6 / 180.0 * M_PI;
		tipFrame.p.data[0] = f.X / 1000.0;
		tipFrame.p.data[1] = f.Y / 1000.0;
		tipFrame.p.data[2] = f.Z / 1000.0;
		tipFrame.M = KDL::Rotation::EulerZYX((double) (f.A) / 180.0 * M_PI,
				(double) (f.B) / 180.0 * M_PI, (double) (f.C) / 180.0 * M_PI);

		// Forward Solver
		ret_val = ikSolver_->CartToJnt(jnt_init, tipFrame, jnt_q);
		if (ret_val < 0) {
			std::cout
					<< "Model::Frame2Axis: CartToJnt error, Axis set to Home value"
					<< std::endl;
			a.set();
			return false;
		}

		// Cast into old format
		a.A1 = jnt_q.data[0] * 180.0 / M_PI;
		a.A2 = jnt_q.data[1] * 180.0 / M_PI;
		a.A3 = jnt_q.data[2] * 180.0 / M_PI;
		a.A4 = jnt_q.data[3] * 180.0 / M_PI;
		a.A5 = jnt_q.data[4] * 180.0 / M_PI;
		a.A6 = jnt_q.data[5] * 180.0 / M_PI;

		return true;
	} else {
		std::cout << "Model::Frame2Axis: Failed, solver invalid" << std::endl;
		a.set();
		return false;
	}
}

bool Model::Axis2Pos(Axis &a, Pos &p) {
	int ret_val1 = 0;
	int ret_val2 = 0;
	if (valid_) {
		// Init KDL variables
		KDL::JntArray jnt_q = KDL::JntArray(6);
		KDL::Frame tipFrame, rotFrame;
		jnt_q(0) = a.A1 / 180.0 * M_PI;
		jnt_q(1) = a.A2 / 180.0 * M_PI;
		jnt_q(2) = a.A3 / 180.0 * M_PI;
		jnt_q(3) = a.A4 / 180.0 * M_PI;
		jnt_q(4) = a.A5 / 180.0 * M_PI;
		jnt_q(5) = a.A6 / 180.0 * M_PI;

		// Forward Solver
		ret_val1 = fkSolver_->JntToCart(jnt_q, tipFrame);
		ret_val2 = fkSolver_rot_->JntToCart(jnt_q, rotFrame);

		if (ret_val1 < 0 || ret_val2 < 0) {
			std::cout
					<< "Model::Axis2Pos: JntToCart error, Pos set to Home value"
					<< std::endl;
			Frame f;
			p.set(f);
			return false;
		}

		// Cast into old format
		p.F.X = tipFrame.p.data[0] * 1000.0;
		p.F.Y = tipFrame.p.data[1] * 1000.0;
		p.F.Z = tipFrame.p.data[2] * 1000.0;
		double rr, pp, yy;
		tipFrame.M.GetEulerZYX(rr, pp, yy);
		p.F.A = (float) rr * 180.0 / M_PI;
		p.F.B = (float) pp * 180.0 / M_PI;
		p.F.C = (float) yy * 180.0 / M_PI;

		getStatus(p, a, rotFrame.p.data[0], rotFrame.p.data[1]);
		getTurn(p, a);

		return true;
	} else {
		std::cout << "Model::Axis2Pos: Failed, solver invalid" << std::endl;
		Frame f;
		p.set(f);
		return false;
	}
}

bool Model::Pos2Axis(Axis &a_init, Pos &p, Axis &a) {
	if (valid_)
		return Frame2Axis(a_init, p.F, a);
	else {
		std::cout << "Model::Pos2Axis: Failed, solver invalid" << std::endl;
		return false;
	}
}

int Model::getStatus(Pos& p, Axis &a, double x, double y) {
	int b0, b1, b2;
	double s1_temp = atan2(y, x);
	if (abs(-s1_temp - a.A1 / 180.0 * M_PI) < M_PI_2)
		b0 = 0;
	else
		b0 = 1;
	if (a.A3 > STATUS_A3_THRESHOLD)
		b1 = 2;
	else
		b1 = 0;
	if (a.A5 >= 0.0)
		b2 = 0;
	else
		b2 = 4;
	p.S = b0 + b1 + b2;
	return p.S;
}

int Model::getTurn(Pos& p, Axis &a) {
	int t = 0;
	if (a.A1 < 0)
		t |= 1;
	if (a.A2 < 0)
		t |= 2;
	if (a.A3 < 0)
		t |= 4;
	if (a.A4 < 0)
		t |= 8;
	if (a.A5 < 0)
		t |= 16;
	if (a.A6 < 0)
		t |= 32;
	p.T = t;
	return t;
}
