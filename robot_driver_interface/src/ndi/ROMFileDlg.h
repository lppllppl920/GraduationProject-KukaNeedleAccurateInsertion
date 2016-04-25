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
	int TypeofSystem_;
	std::string PortID_;
	std::string ROMFile_;
	std::string ConfigurationFile_;
	int NoActivePorts_;
	int NoPassivePorts_;
	int NoMagneticPorts_;
	bool ChangesSaved_;
	CIniFile IniFile_;
	int ROMSelection_;

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
