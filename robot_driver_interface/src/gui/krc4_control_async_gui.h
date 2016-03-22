/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 20 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 *
 *   Header file for krc_control_async_GUI. GUI created by Qt Designer.
 *   Plannar as a public member of GUI class.
 *   Control loop is:
 *
 *         1. QString               2. Feedback            3. Widgets
 *     | ---------------> |     | ---------------> |   | ---------------> |
 *   KRC4                TCPThread                Plannar                GUI
 *     | <--------------- |     | <--------------- |   | <--------------- |
 *         (6. QString)             (5. Command)           (4. Buttons)
 *
 *   NOTE: CIRC motion is supported in GUI.
 *
 */

#ifndef KRC4_control_async_GUI_H
#define KRC4_control_async_GUI_H

#include <QWidget>
#include "plannar.h"

namespace Ui {
class KRC4_control_async_GUI;
}

class KRC4_control_async_GUI: public QWidget {
Q_OBJECT

public:
	// KRC4_control_async_GUI constructor
	//  - initialize Plannar
	//  - set up signal-slot connections
	explicit KRC4_control_async_GUI(QWidget *parent = 0);

	// KRC4_control_async_GUI deconstructor
	//  - delete plannar_ pointer and ui pointer
	~KRC4_control_async_GUI();

	// Plannar
	Plannar plannar_;

private slots:
	void on_send_frame_button_clicked();

	void on_send_axis_button_clicked();

	void on_copy_button_clicked();

	void on_default_button_clicked();

	void on_debug_button_clicked();

	void on_send_config_button_clicked();

	void on_pause_buf_buton_clicked();

	void on_terminate_imm_button_clicked();

	void on_send_pos_button_clicked();

	void on_pause_button_clicked();

	void on_stop_button_clicked();

	void on_terminate_buf_button_clicked();

public slots:
	// triggered by plannar_->displayFeedback(Feedback*)
	void displayFeedback(Feedback* fb);

private:
	// setAlignment:
	//  - all numbers align right
	//  - string aligns left
	void setAlignment();

	Ui::KRC4_control_async_GUI *ui;
};

#endif // KRC4_control_async_GUI_H
