/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 20 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#include "krc4_control_async_gui.h"
#include "ui_krc4_control_async_gui.h"

KRC4_control_async_GUI::KRC4_control_async_GUI(QWidget *parent) :
		QWidget(parent), ui(new Ui::KRC4_control_async_GUI), plannar_() {
	std::cout << "GUI Constructing..." << std::endl;
	ui->setupUi(this);
	setAlignment();
	connect(&plannar_, SIGNAL(newFeedback(Feedback*)), this,
			SLOT(displayFeedback(Feedback*)));
}

KRC4_control_async_GUI::~KRC4_control_async_GUI() {
	delete ui;
	std::cout << "GUI Deconstructing..." << std::endl;
	QApplication::exit();
}

void KRC4_control_async_GUI::setAlignment() {
	ui->input_x->setAlignment(Qt::AlignRight);
	ui->input_y->setAlignment(Qt::AlignRight);
	ui->input_z->setAlignment(Qt::AlignRight);
	ui->input_a->setAlignment(Qt::AlignRight);
	ui->input_b->setAlignment(Qt::AlignRight);
	ui->input_c->setAlignment(Qt::AlignRight);
	ui->input_a1->setAlignment(Qt::AlignRight);
	ui->input_a2->setAlignment(Qt::AlignRight);
	ui->input_a3->setAlignment(Qt::AlignRight);
	ui->input_a4->setAlignment(Qt::AlignRight);
	ui->input_a5->setAlignment(Qt::AlignRight);
	ui->input_a6->setAlignment(Qt::AlignRight);
	ui->input_s->setAlignment(Qt::AlignRight);
	ui->input_t->setAlignment(Qt::AlignRight);

	ui->output_x->setAlignment(Qt::AlignRight);
	ui->output_y->setAlignment(Qt::AlignRight);
	ui->output_z->setAlignment(Qt::AlignRight);
	ui->output_a->setAlignment(Qt::AlignRight);
	ui->output_b->setAlignment(Qt::AlignRight);
	ui->output_c->setAlignment(Qt::AlignRight);
	ui->output_a1->setAlignment(Qt::AlignRight);
	ui->output_a2->setAlignment(Qt::AlignRight);
	ui->output_a3->setAlignment(Qt::AlignRight);
	ui->output_a4->setAlignment(Qt::AlignRight);
	ui->output_a5->setAlignment(Qt::AlignRight);
	ui->output_a6->setAlignment(Qt::AlignRight);

	ui->output_buf_front->setAlignment(Qt::AlignRight);
	ui->output_buf_last->setAlignment(Qt::AlignRight);
	ui->output_result->setAlignment(Qt::AlignRight);
	ui->output_s->setAlignment(Qt::AlignRight);
	ui->output_t->setAlignment(Qt::AlignRight);
	ui->output_seq->setAlignment(Qt::AlignRight);

	ui->input_config->setAlignment(Qt::AlignRight);
	ui->output_message->setAlignment(Qt::AlignLeft);
}

void KRC4_control_async_GUI::on_send_frame_button_clicked() {
	Frame f(ui->input_x->toPlainText().toFloat(),
			ui->input_y->toPlainText().toFloat(),
			ui->input_z->toPlainText().toFloat(),
			ui->input_a->toPlainText().toFloat(),
			ui->input_b->toPlainText().toFloat(),
			ui->input_c->toPlainText().toFloat());
	Command::Style style;
	Command::Approx approx;
	if (ui->comboBox_approx->currentText() == "C_PTP")
		approx = Command::C_PTP;
	else if (ui->comboBox_approx->currentText() == "C_VEL")
		approx = Command::C_VEL;
	else if (ui->comboBox_approx->currentText() == "C_DIS")
		approx = Command::C_DIS;
	else if (ui->comboBox_approx->currentText() == "C_ORI")
		approx = Command::C_ORI;
	else if (ui->comboBox_approx->currentText() == "None")
		approx = Command::NONE;
	else {
		std::cout << "To Frame: Approx. not recognized, None is used"
				<< std::endl;
		approx = Command::NONE;
	}

	if (ui->comboBox_style->currentText() == "PTP")
		style = Command::PTP;
	else if (ui->comboBox_style->currentText() == "LIN")
		style = Command::LIN;
	else if (ui->comboBox_style->currentText() == "CIRC") {
		std::cout << "To Frame: CIRC command not supported in GUI, PTP is used"
				<< std::endl;
		style = Command::PTP;
	} else {
		std::cout << "To Frame: Style not recognized, PTP is used" << std::endl;
		style = Command::PTP;
	}

	plannar_.motion(style, f, approx);
}

void KRC4_control_async_GUI::on_send_axis_button_clicked() {
	Axis a(ui->input_a1->toPlainText().toFloat(),
			ui->input_a2->toPlainText().toFloat(),
			ui->input_a3->toPlainText().toFloat(),
			ui->input_a4->toPlainText().toFloat(),
			ui->input_a5->toPlainText().toFloat(),
			ui->input_a6->toPlainText().toFloat());

	Command::Style style;
	Command::Approx approx;
	if (ui->comboBox_approx->currentText() == "C_PTP")
		approx = Command::C_PTP;
	else if (ui->comboBox_approx->currentText() == "C_VEL")
		approx = Command::C_VEL;
	else if (ui->comboBox_approx->currentText() == "C_DIS")
		approx = Command::C_DIS;
	else if (ui->comboBox_approx->currentText() == "C_ORI")
		approx = Command::C_ORI;
	else if (ui->comboBox_approx->currentText() == "None")
		approx = Command::NONE;
	else {
		std::cout << "To Axis: Approx. not recognized, None is used"
				<< std::endl;
		approx = Command::NONE;
	}

	if (ui->comboBox_style->currentText() == "PTP")
		style = Command::PTP;
	else if (ui->comboBox_style->currentText() == "LIN")
		style = Command::LIN;
	else if (ui->comboBox_style->currentText() == "CIRC") {
		std::cout << "To Axis: CIRC command not supported in GUI, PTP is used"
				<< std::endl;
		style = Command::PTP;
	} else {
		std::cout << "To Axis: Style not recognized, PTP is used" << std::endl;
		style = Command::PTP;
	}

	plannar_.motion(style, a, approx);
}

void KRC4_control_async_GUI::on_send_pos_button_clicked() {
	Frame f(ui->input_x->toPlainText().toFloat(),
			ui->input_y->toPlainText().toFloat(),
			ui->input_z->toPlainText().toFloat(),
			ui->input_a->toPlainText().toFloat(),
			ui->input_b->toPlainText().toFloat(),
			ui->input_c->toPlainText().toFloat());
	Pos p(f, ui->input_s->toPlainText().toInt(),
			ui->input_t->toPlainText().toInt());

	Command::Style style;
	Command::Approx approx;
	if (ui->comboBox_approx->currentText() == "C_PTP")
		approx = Command::C_PTP;
	else if (ui->comboBox_approx->currentText() == "C_VEL")
		approx = Command::C_VEL;
	else if (ui->comboBox_approx->currentText() == "C_DIS")
		approx = Command::C_DIS;
	else if (ui->comboBox_approx->currentText() == "C_ORI")
		approx = Command::C_ORI;
	else if (ui->comboBox_approx->currentText() == "None")
		approx = Command::NONE;
	else {
		std::cout << "To Pos: Approx. not recognized, None is used"
				<< std::endl;
		approx = Command::NONE;
	}

	if (ui->comboBox_style->currentText() == "PTP")
		style = Command::PTP;
	else if (ui->comboBox_style->currentText() == "LIN")
		style = Command::LIN;
	else if (ui->comboBox_style->currentText() == "CIRC") {
		std::cout << "To Pos: CIRC command not supported in GUI, PTP is used"
				<< std::endl;
		style = Command::PTP;
	} else {
		std::cout << "To Pos: Style not recognized, PTP is used" << std::endl;
		style = Command::PTP;
	}

	plannar_.motion(style, p, approx);
}

void KRC4_control_async_GUI::displayFeedback(Feedback *fb) {
	if (fb->getSetOK() && fb->getParsedOK()) {
		ui->output_x->setText(QString("%1").arg(fb->getFrame().X, 8, 'f', 4));
		ui->output_y->setText(QString("%1").arg(fb->getFrame().Y, 8, 'f', 4));
		ui->output_z->setText(QString("%1").arg(fb->getFrame().Z, 8, 'f', 4));
		ui->output_a->setText(QString("%1").arg(fb->getFrame().A, 8, 'f', 4));
		ui->output_b->setText(QString("%1").arg(fb->getFrame().B, 8, 'f', 4));
		ui->output_c->setText(QString("%1").arg(fb->getFrame().C, 8, 'f', 4));

		ui->output_a1->setText(QString("%1").arg(fb->getAxis().A1, 8, 'f', 4));
		ui->output_a2->setText(QString("%1").arg(fb->getAxis().A2, 8, 'f', 4));
		ui->output_a3->setText(QString("%1").arg(fb->getAxis().A3, 8, 'f', 4));
		ui->output_a4->setText(QString("%1").arg(fb->getAxis().A4, 8, 'f', 4));
		ui->output_a5->setText(QString("%1").arg(fb->getAxis().A5, 8, 'f', 4));
		ui->output_a6->setText(QString("%1").arg(fb->getAxis().A6, 8, 'f', 4));

		ui->output_s->setText(QString::number(fb->getPos().S));
		ui->output_t->setText(QString::number(fb->getPos().T));

		ui->output_buf_front->setText(QString::number(fb->getBufferFront()));
		ui->output_buf_last->setText(QString::number(fb->getBufferLast()));

		ui->output_seq->setText(QString::number(fb->getSeq()));
		ui->output_result->setText(QString::number(fb->getStamp()));

		if (fb->getText() != "Timer Feedback")
			ui->output_message->setText(QString::fromStdString(fb->getText()));

		if (fb->getBufferExtreme() == Feedback::Full) {
			QPalette pf = ui->output_buf_front->palette();
			pf.setColor(QPalette::Base, QColor(170, 0, 0));
			ui->output_buf_front->setPalette(pf);

			QPalette pl = ui->output_buf_last->palette();
			pl.setColor(QPalette::Base, QColor(170, 0, 0));
			ui->output_buf_last->setPalette(pl);
		} else {
			QPalette pf = ui->output_buf_front->palette();
			pf.setColor(QPalette::Base, QColor(0, 170, 0));
			ui->output_buf_front->setPalette(pf);

			QPalette pl = ui->output_buf_last->palette();
			pl.setColor(QPalette::Base, QColor(0, 170, 0));
			ui->output_buf_last->setPalette(pl);
		}

		if (fb->getSuccess() == 0 && fb->getType() == Feedback::Hybrid) {
			QPalette pr = ui->output_result->palette();
			pr.setColor(QPalette::Base, QColor(170, 0, 0));
			ui->output_result->setPalette(pr);
		} else if (fb->getType() == Feedback::Hybrid) {
			QPalette pr = ui->output_result->palette();
			pr.setColor(QPalette::Base, QColor(0, 170, 0));
			ui->output_result->setPalette(pr);
		}

		setAlignment();
	} else {
		ui->output_message->setText("Feedback parsing failed");
		QPalette pm = ui->output_message->palette();
		pm.setColor(QPalette::Base, QColor(170, 0, 0));
		ui->output_message->setPalette(pm);

		setAlignment();
	}
}

void KRC4_control_async_GUI::on_copy_button_clicked() {
	ui->input_x->setText(ui->output_x->toPlainText());
	ui->input_y->setText(ui->output_y->toPlainText());
	ui->input_z->setText(ui->output_z->toPlainText());
	ui->input_a->setText(ui->output_a->toPlainText());
	ui->input_b->setText(ui->output_b->toPlainText());
	ui->input_c->setText(ui->output_c->toPlainText());

	ui->input_s->setText(ui->output_s->toPlainText());
	ui->input_t->setText(ui->output_t->toPlainText());

	ui->input_a1->setText(ui->output_a1->toPlainText());
	ui->input_a2->setText(ui->output_a2->toPlainText());
	ui->input_a3->setText(ui->output_a3->toPlainText());
	ui->input_a4->setText(ui->output_a4->toPlainText());
	ui->input_a5->setText(ui->output_a5->toPlainText());
	ui->input_a6->setText(ui->output_a6->toPlainText());

	setAlignment();
}

void KRC4_control_async_GUI::on_default_button_clicked() {
	ui->input_x->setText(QString("%1").arg( DEFAULT_X, 8, 'f', 4));
	ui->input_y->setText(QString("%1").arg( DEFAULT_Y, 8, 'f', 4));
	ui->input_z->setText(QString("%1").arg( DEFAULT_Z, 8, 'f', 4));
	ui->input_a->setText(QString("%1").arg( DEFAULT_A, 8, 'f', 4));
	ui->input_b->setText(QString("%1").arg( DEFAULT_B, 8, 'f', 4));
	ui->input_c->setText(QString("%1").arg( DEFAULT_C, 8, 'f', 4));

	ui->input_s->setText(QString::number(DEFAULT_S));
	ui->input_t->setText(QString::number(DEFAULT_T));

	ui->input_a1->setText(QString("%1").arg( DEFAULT_A1, 8, 'f', 4));
	ui->input_a2->setText(QString("%1").arg( DEFAULT_A2, 8, 'f', 4));
	ui->input_a3->setText(QString("%1").arg( DEFAULT_A3, 8, 'f', 4));
	ui->input_a4->setText(QString("%1").arg( DEFAULT_A4, 8, 'f', 4));
	ui->input_a5->setText(QString("%1").arg( DEFAULT_A5, 8, 'f', 4));
	ui->input_a6->setText(QString("%1").arg( DEFAULT_A6, 8, 'f', 4));

	setAlignment();
}

void KRC4_control_async_GUI::on_debug_button_clicked() {
	plannar_.test();
}

void KRC4_control_async_GUI::on_send_config_button_clicked() {
	Command::Param param;
	float value;
	int ok = true;
	if (ui->comboBox_config->currentText() == "$ADVANCE")
		param = Command::ADVANCE;
	else if (ui->comboBox_config->currentText() == "$ACC_PTP")
		param = Command::ACC_PTP;
	else if (ui->comboBox_config->currentText() == "$VEL_PTP")
		param = Command::VEL_PTP;
	else if (ui->comboBox_config->currentText() == "$ACC_CP")
		param = Command::ACC_CP;
	else if (ui->comboBox_config->currentText() == "$ACC.ORI1")
		param = Command::ACC_ORI1;
	else if (ui->comboBox_config->currentText() == "$ACC.ORI2")
		param = Command::ACC_ORI2;
	else if (ui->comboBox_config->currentText() == "$VEL_CP")
		param = Command::VEL_CP;
	else if (ui->comboBox_config->currentText() == "$VEL.ORI1")
		param = Command::VEL_ORI1;
	else if (ui->comboBox_config->currentText() == "$VEL.ORI2")
		param = Command::VEL_ORI2;
	else if (ui->comboBox_config->currentText() == "$APO.CPTP")
		param = Command::APO_CPTP;
	else if (ui->comboBox_config->currentText() == "$APO.CDIS")
		param = Command::APO_CDIS;
	else if (ui->comboBox_config->currentText() == "$APO.CVEL")
		param = Command::APO_CVEL;
	else if (ui->comboBox_config->currentText() == "$APO.CORI")
		param = Command::APO_CORI;
	else {
		std::cout << "Config: Parameter not recognized" << std::endl;
		ok = false;
	}
	value = ui->input_config->toPlainText().toFloat();
	if (ok)
		plannar_.configuration(param, value);

}

void KRC4_control_async_GUI::on_pause_buf_buton_clicked() {
	plannar_.pauseBuffered();
}

void KRC4_control_async_GUI::on_terminate_imm_button_clicked() {
	plannar_.terminateImmediately();
}

void KRC4_control_async_GUI::on_pause_button_clicked() {
	plannar_.pauseImmediately();
}

void KRC4_control_async_GUI::on_stop_button_clicked() {
	plannar_.stop();
}

void KRC4_control_async_GUI::on_terminate_buf_button_clicked() {
	plannar_.terminateBuffered();
}
