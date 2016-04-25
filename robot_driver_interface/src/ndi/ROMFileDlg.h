/*
 * ROMFileDlg.h
 *
 *  Created on: Apr 24, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_ROMFILEDLG_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_ROMFILEDLG_H_

#include <ros/ros.h>
#include <qfiledialog.h>
#include <boost/lexical_cast.hpp>
#include "ndi/inifile.h"
#include "ndi/CommandHandling.h"
#include "gui/ui_robotInterface_ROMFile.h"

class ROMFileDlg: public QWidget, private Ui::SubWindow_ROMFile {
Q_OBJECT
public:
	ROMFileDlg();
	virtual ~ROMFileDlg();
	void ReadINIParam_array(std::string Section, std::string Key, char* array);

public:
	int nTypeofSystem_;
	int nROMSelection_;
	std::string strPortID_;
	std::string strROMFile_;
	std::string strConfigurationFile_;
	int nNoActivePorts_;
	int nNoPassivePorts_;
	int nNoMagneticPorts_;
	bool bChangesSaved_;
	CIniFile dtIniFile_;

public slots:
	void Init();
	void Browse();
	void Close();
	void ClickPortListing();
	void Accept();signals:
	void ReInitialize_signal();

public:
	void FillROMFileTable();
	void AddItemToList(char * pszPortID, char * pszROMFileName);
	void SaveItemToINI(const char * pszPortID, const char * pszROMFileName);

};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_ROMFILEDLG_H_ */
