/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 25 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#include "plot.h"
#include "ui_plot.h"
#include <iostream>

plotWindow::plotWindow(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::plotWindow) {
	std::cout << "PlotWindow Constructing..." << std::endl;
	ui->setupUi(this);
	graphCount_ = -1;
	this->hide();
}

plotWindow::~plotWindow() {
	delete ui;
	std::cout << "PlotWindow Deconstructing..." << std::endl;
}

void plotWindow::display() {
	ui->customPlot->replot();
	this->show();
}

void plotWindow::newPlot(QVector<double> x, QVector<double> y) {
	this->clearPlots();
	this->addPlot(x, y);
}

void plotWindow::newPlot(QVector<double> x) {
	this->clearPlots();
	this->addPlot(x);
}

void plotWindow::addPlot(QVector<double> x, QVector<double> y) {
	ui->customPlot->addGraph();
	graphCount_++;
	ui->customPlot->graph(graphCount_)->setData(x, y);
	std::cout << "plotWindow::addPlot: Current plots: " << graphCount_ + 1
			<< std::endl;
}

void plotWindow::addPlot(QVector<double> x) {
	ui->customPlot->addGraph();
	graphCount_++;
	QVector<double> key;
	for (int i = 0; i < x.size(); i++)
		key.push_back(i + 1);
	ui->customPlot->graph(graphCount_)->setData(key, x);
	std::cout << "plotWindow::addPlot: Current plots: " << graphCount_ + 1
			<< std::endl;
}

void plotWindow::clearPlots() {
	if (graphCount_ != -1) {
		std::cout << "plotWindow::clearPlots: Delete old plots" << std::endl;
		ui->customPlot->clearGraphs();
		graphCount_ = -1;
	} else
		std::cout << "plotWindow::clearPlots: No plot exists" << std::endl;
}

void plotWindow::setLabel(plotWindow::Label lb, QString qs) {
	if (lb == X)
		ui->customPlot->xAxis->setLabel(qs);
	else if (lb == Y)
		ui->customPlot->yAxis->setLabel(qs);
}

void plotWindow::setLabel(QString qs1, QString qs2) {
	ui->customPlot->xAxis->setLabel(qs1);
	ui->customPlot->yAxis->setLabel(qs2);
}

void plotWindow::setLineStyle(QCPGraph::LineStyle ls) {
	if (graphCount_ != -1)
		ui->customPlot->graph(graphCount_)->setLineStyle(ls);
	else
		std::cout << "plotWindow::setLineStyle: Error, no graph exists"
				<< std::endl;
}

void plotWindow::setScatterStyle(QCPScatterStyle::ScatterShape ss, double sz) {
	if (graphCount_ != -1)
		ui->customPlot->graph(graphCount_)->setScatterStyle(
				QCPScatterStyle(ss, sz));
	else
		std::cout << "plotWindow::setScatterStyle: Error, no graph exists"
				<< std::endl;
}

void plotWindow::setName(QString qs) {
	if (graphCount_ != -1)
		ui->customPlot->graph(graphCount_)->setName(qs);
	else
		std::cout << "plotWindow::setName: Error, no graph exists" << std::endl;
}

void plotWindow::setRange(double x1, double x2, double y1, double y2) {
	ui->customPlot->xAxis->setRange(x1, x2);
	ui->customPlot->yAxis->setRange(y1, y2);
}

void plotWindow::closeEvent(QCloseEvent *event) {
	event->ignore();
	this->hide();
}
