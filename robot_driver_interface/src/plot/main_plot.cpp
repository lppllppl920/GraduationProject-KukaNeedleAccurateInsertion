/**
 *   Copyright (C) Tsinghua University 2015
 *
 *   Version   : 2.0
 *   Date      : 20 May 2015
 *   Author    : Long Qian
 *   Company   : Tsinghua University
 *   Email     : joewalker.ql@gmail.com
 */

#include <QApplication>
#include "plot.h"

// TODO
//  1. transplant to Windows
//  2. compile as a standalone library

int main(int argc, char *argv[]) {
	QApplication::setGraphicsSystem("raster");
	QApplication app(argc, argv);

	plot plot;
	plot.show();

	return app.exec();
}
