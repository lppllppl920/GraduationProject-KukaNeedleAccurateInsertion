/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 25 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#ifndef PLOT_H
#define PLOT_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QVector>

#define DEF_PLOT_ALL -1

namespace Ui {
class plotWindow;
}

class plotWindow: public QMainWindow {
Q_OBJECT

public:
	explicit plotWindow(QWidget *parent = 0);
	~plotWindow();

	enum Label {
		X, Y
	};
	enum PlotMethod {
		AddPlot, NewPlot
	};

	void clearPlots();
	void newPlot(QVector<double> x, QVector<double> y);
	void newPlot(QVector<double> x);
	void addPlot(QVector<double> x, QVector<double> y);
	void addPlot(QVector<double> x);
	void setLabel(Label lb, QString qs);
	void setLabel(QString qs1, QString qs2);
	void setLineStyle(QCPGraph::LineStyle ls);
	void setScatterStyle(QCPScatterStyle::ScatterShape ss, double sz = 6);
	void setName(QString qs);
	void setRange(double x1, double x2, double y1, double y2);

	void display();

	void closeEvent(QCloseEvent *event);

private:
	Ui::plotWindow *ui;

	int graphCount_;
};

#endif // PLOT_H
