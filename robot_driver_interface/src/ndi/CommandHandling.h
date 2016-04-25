/*
 * CommandHandling.h
 *
 *  Created on: Apr 19, 2016
 *      Author: lxt12
 */

#ifndef ROBOT_DRIVER_INTERFACE_SRC_NDI_COMMANDHANDLING_H_
#define ROBOT_DRIVER_INTERFACE_SRC_NDI_COMMANDHANDLING_H_

#include "Comm32Port.h"
#include "ndi/COMPortTimeOut.h"
#include "APIStructures.h"

class CommandHandling {
public:
	CommandHandling();
	virtual ~CommandHandling();

	int CloseComPorts();
	int OpenComPort(int Port);
	int HardWareReset(bool Wireless);
	int SetSystemComParms(int BaudRate, int DataBits, int Parity, int StopBits,
			int Hardware);
	int SetCompCommParms(int Baud, int DataBits, int Parity, int Stop,
			int FlowControl);
	int BeepSystem(int Beeps);
	int InitializeSystem();
	int SetFiringRate();
	int GetSystemInfo();
	int InitializeAllPorts();
	int InitializeHandle(int Handle);
	int EnableAllPorts();
	int EnableOnePorts(int PortHandle);
	int DisablePort(int PortHandle);
	int ActivateAllPorts();
	int LoadTTCFG(char *PortID);
	int GetHandleForPort(char *PortID);
	int LoadVirtualSROM(char *FileName, char *PhysicalPortID, bool Passive);
	int FreePortHandles();
	int GetPortInformation(int PortHandle);
	int StartTracking();
	int GetTXTransforms(bool ReportOOV);
	int GetBXTransforms(bool ReportOOV);
	int StopTracking();
	int GetAlerts(bool NewAlerts);

	void ErrorMessage();
	void WarningMessage();
	int CreateTimeoutTable();
	int LookupTimeout(char *Command);
	void ReadINIParam_array(std::string Section, std::string Key, char* array);
	template<class T> void ReadINIParam(std::string Section, std::string Key,
			T& Value) {
		std::string temp_string;
		temp_string = IniFile_.GetKeyValue(Section, Key);
		if (!temp_string.empty()) {
			Value = boost::lexical_cast<T>(temp_string);
		}
		return;
	}

	/*****************************************************************
	 Variables
	 *****************************************************************/
	bool LogToFile_, /* log to file */
	DateTimeStampFile_; /* include date and time stamp in log file */
	char LogFile_[_MAX_PATH]; /* log file name */

	SystemInformation SystemInformation_; /* System Information variable - structure */

	HandleInformation HandleInformation_[NO_HANDLES]; /* Handle Information varaible - structure */
	int RefHandle_; /* the handle for the tool acting as the reference tool */
	DiagNewAlertFlags NewAlerts_; /* alert information */
	std::map<std::string, int> TimeoutValues_;
	CIniFile IniFile_;
	CIniFile ErrorIniFile_;
	std::string ConfigurationFile_;
	COMPortTimeOut SubWindow_COMPortTimeOut_;
protected:
	/*****************************************************************
	 Routine Definitions
	 *****************************************************************/
	void ApplyXfrms();
	int SendMessage(char *Command, bool AddCRC);
	int GetResponse();
	int GetBinaryResponse();
	int VerifyResponse(char *Reply, bool CheckCRC);
	int CheckResponse(int Response);
	void LogToFile(int Direction, char *psz);

	void InitCrcTable();
	unsigned int CalcCrc16(unsigned int crc, int data);
	unsigned CalcCRCByLen(char *String, int Len);
	int SystemCheckCRC(char *psz);
	unsigned int SystemGetCRC(char *psz, int Length);

	int AddCRCToCommand(char *CommandString);
	int AddCRToCommand(char *CommandString);
	int BuildCommand(char *CommandString, bool AddCRC);

	void GetErrorResponse(char * Reply, char * ErrorMsg);

	/*****************************************************************
	 Variables
	 *****************************************************************/
	Comm32Port *COMPort_; /* pointer to the Comm32 class */

	char LastReply_[MAX_REPLY_MSG], /* Last reply received from the system */
	Command_[MAX_COMMAND_MSG]; /* command to send to the system */
	bool ClearLogFile_, /* clear log file on intialization */
	DisplayErrorsWhileTracking_; /* display the error while tracking */
	int Timeout_, DefaultTimeout_; /* timeout value in seconds */
	bool ComPortOpen_[NUM_COM_PORTS]; /* array of com ports - if true they are open */
	int PortsEnabled_; /* the number of port enable by nEnableAllPorts */
};

#endif /* ROBOT_DRIVER_INTERFACE_SRC_NDI_COMMANDHANDLING_H_ */
