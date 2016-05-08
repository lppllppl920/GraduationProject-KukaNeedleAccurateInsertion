/*
 * CommandHandling.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: lxt12
 */

#include <CommandHandling.h>

/*****************************************************************
 Global Variables
 *****************************************************************/
static unsigned int CrcTable[256];
static int bFirst = 1;

/*****************************************************************
 Name:			CommandHandling

 Inputs:
 None.

 Return Value:
 None.

 Description:   CommandHandling Constructor
 *****************************************************************/
CommandHandling::CommandHandling() {
	/* set up com port class, start from new. */
	dtCOMPort_ = new Comm32Port;

	/* reinitialize the com ports */
	for (int i = 0; i < NUM_COM_PORTS; i++)
		pbComPortOpen_[i] = 0;

	nPortsEnabled_ = 0;
	bLogToFile_ = bDateTimeStampFile_ = false;
//TODO: this address need to be specified
	dtIniFile_.Load("/home/lxt12/NDIConfiguration.ini");
	dtErrorIniFile_.Load("/home/lxt12/NDIErrors.ini");
	strConfigurationFile_ = "/home/lxt12/NDIConfiguration.ini";
	bClearLogFile_ = false;
	bDisplayErrorsWhileTracking_ = false;
	nRefHandle_ = -1;
	nTimeout_ = 3;
	nDefaultTimeout_ = 10;
	strcpy(pchrLogFile_, "");

	ReadINIParam_array("Logging Options", "Log File Name", pchrLogFile_);
	ReadINIParam<bool>("Logging Options", "Log To File", bLogToFile_);
	ReadINIParam<bool>("Logging Options", "Date Time Stamp",
			bDateTimeStampFile_);
	ReadINIParam<int>("Communication", "Timeout Time", nDefaultTimeout_);
} /* CommandHandling()

 /*****************************************************************
 Name:			~CommandHandling

 Inputs:
 None.

 Return Value:
 None.

 Description:   CommandHandling Destructor
 *****************************************************************/
CommandHandling::~CommandHandling() {
	/* clean up */
	if (dtCOMPort_)
		delete (dtCOMPort_);
} /* ~CommandHandling */

/*****************************************************************
 Name:				CloseComPorts

 Inputs:
 None.

 Return Value:
 int , 0 if fails and 1 is passes

 Description:
 This routine closes all open COM ports.
 *****************************************************************/
int CommandHandling::CloseComPorts() {
	/*
	 * if the COM Port is already closed no need to check to see if
	 * we should close it
	 */
	for (int i = 0; i < NUM_COM_PORTS; i++) {
		if ((pbComPortOpen_[i]) &&(dtCOMPort_ != NULL)) {
			dtCOMPort_->SerialClose();
			pbComPortOpen_[i] = false;
			return 1;
		}/* if */
	}/* for */
	return 0;
} /* CloseComPorts */

/*****************************************************************
 Name:				OpenComPort

 Inputs:
 int nPort - the port number to be opened

 Return Value:
 int - 1if successful, 0 otherwise

 Description:
 This routine opens the selected com port and sets its settings
 to the default communication parameters
 *****************************************************************/
int CommandHandling::OpenComPort(int Port) {
	/*
	 * If the COM Port is open there is no sense in re-opening it.
	 * You can still change the PARAMETERS with no problem.  This
	 * reduces the time it takes to re-initialize the System
	 */
	if (pbComPortOpen_[Port]) {
		return 1;
	} else {
		if (dtCOMPort_ != NULL) {
			/* set the parameters to the defaults */
			if (dtCOMPort_->SerialOpen(Port, 9600, COMM_8N1, false, 256)) {
				pbComPortOpen_[Port] = TRUE;
				return 1;
			} /* if */
		} /* if */
	} /* else */

	return 0;
} /* OpenComPort */
/*****************************************************************
 Name:

 Inputs:
 None.

 Return Value:
 int - 0 if it fails, CheckResponse if passes

 Description:
 This routine sends a serial break to the system, reseting it.
 *****************************************************************/
int CommandHandling::HardWareReset(bool Wireless) {
	int Response = 0, InitTO = 3;

	/* Check COM port */
	if (dtCOMPort_ == NULL) {
		return 0;
	}/* if */

	if (!Wireless) {
		/* send serial break */
		dtCOMPort_->SerialBreak();

		boost::this_thread::sleep(boost::posix_time::milliseconds(500)); /* Give the break sometime to set */

		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		//TODO: problem: Didn't receive response when doing serial break
		//if (!GetResponse()) {
		//	ROS_ERROR("Hardware Reset: Serial Break get response failed");
		//	return 0;
		//}/* if */
		/* check for the RESET response */
		//Response = VerifyResponse(pchrLastReply_, TRUE);
		//if (!CheckResponse(Response)) {
		//	return 0;
		//}/* if */
		/*
		 * In order to support NDI enhanced Tool Interface Unit and Tool Docking Station,
		 * a time delay is recommended so that the Tool Docking Station
		 * can be recognised by the eTIU.
		 */
		boost::this_thread::sleep(
				boost::posix_time::milliseconds(InitTO * 1000));

		//if (Response & REPLY_RESET) {
		//	if (!SystemCheckCRC(pchrLastReply_))
		//		return REPLY_BADCRC;
		//	else
		//		return Response;
		//} /* if */
		//else {
		//	return Response;
		//}/* else */

		return 1;
	} /* if */
	else {
		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "RESET 0");
		if (SendMessage(pchrCommand_, TRUE))
			if (GetResponse())
				return CheckResponse(VerifyResponse(pchrLastReply_, TRUE));
		return 0;
	} /* else */
} /* HardwareReset */

/*****************************************************************
 Name:				SetSystemComParms

 Inputs:
 int BaudRate - the baud rate to set
 int DateBits - the data bit setting
 int Parity - the parity setting
 int StopBits - the stop bit setting
 int Hardware - whether or not to use hardware handshaking

 Return Value:
 int - 0 if fails, else CheckResponse

 Description:
 This routine sets the systems com port parameters, remember
 to immediatley set the computers com port settings after this
 routine is called.
 *****************************************************************/
int CommandHandling::SetSystemComParms(int BaudRate, int DataBits, int Parity,
		int StopBits, int Hardware) {
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "COMM %d%d%d%d%d", BaudRate, DataBits, Parity,
			StopBits, Hardware);
	if (SendMessage(pchrCommand_, TRUE))
		if (GetResponse())
			return CheckResponse(VerifyResponse(pchrLastReply_, TRUE));

	return 0;
} /* SetSystemComParms */
/*****************************************************************
 Name:				SetSystemComParms

 Inputs:
 int Baud - the baud rate to set
 int DateBits - the data bit setting
 int Parity - the parity setting
 int Stop - the stop bit setting
 int Hardware - whether or not to use hardware handshaking

 Return Value:
 int - 0 if fails, else 1

 Description:
 This routine sets the computer's com port parameters, remember
 to immediatley set the computer's com port settings after the
 system's com port parameters.
 *****************************************************************/
int CommandHandling::SetCompCommParms(int Baud, int DataBits, int Parity,
		int Stop, int FlowControl) {
	unsigned Format;

	/* Check COM port */
	if (dtCOMPort_ == NULL) {
		return 0;
	}/* if */

	switch (Baud) {
	case 0:
		Baud = 9600;
		break;
	case 1:
		Baud = 14400;
		break;
	case 2:
		Baud = 19200;
		break;
	case 3:
		Baud = 38400;
		break;
	case 4:
		Baud = 57600;
		break;
	case 5:
		Baud = 115200;
		break;
	case 6:
		Baud = 921600;
		break;
	case 7:
		Baud = 1228739;
		break;
	default:
		Baud = 9600;
		break;
	} /* switch */

	Format = (DataBits * 6) + (Parity * 2) + (Stop);

	if (dtCOMPort_->SerialSetBaud(Baud, Format, FlowControl ? true : false,
			256))
		return 1;

	return 0;
} /* SetCompCommParms */

/*****************************************************************
 Name:				BeepSystem

 Inputs:
 int nBeeps - the number of times the system should beep

 Return Value:
 int - 0 if fails, else CheckResponse

 Description:
 This routine sends the beep command to the System, causing
 it to beep.
 *****************************************************************/
int CommandHandling::BeepSystem(int Beeps) {
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "BEEP %d", Beeps);

	if (SendMessage(pchrCommand_, TRUE)) {
		if (GetResponse())
			return CheckResponse(VerifyResponse(pchrLastReply_, TRUE));
	} /* if */

	return 0;
} /* BeepSystem */

/*****************************************************************
 Name:				InitializeSystem

 Inputs:
 None.

 Return Value:
 int - 0 if fails, else CheckResponse

 Description:   This routine initializes the System by sending the
 INIT command.  Remember to reset the appropriate
 variables.
 *****************************************************************/
int CommandHandling::InitializeSystem() {
	FILE *pfOut = NULL;

	/* get the log file option settings */
	strcpy(pchrLogFile_, "");
	bClearLogFile_ = false;
	ReadINIParam_array("Logging Options", "Log File Name", pchrLogFile_);
	ReadINIParam<bool>("Logging Options", "Clear File", bClearLogFile_);

	if (bLogToFile_ && bClearLogFile_) {
		if (pchrLogFile_[0] != 0) {
			pfOut = fopen(pchrLogFile_, "w+t");
			if (pfOut == NULL) {
				bLogToFile_ = false;
				dtIniFile_.SetKeyValue("Logging Options", "Log To File", "0");
				dtIniFile_.Save(strConfigurationFile_);
				ROS_ERROR("Failed to open log file");
				return 0;
			}/* if */
			fclose(pfOut);
		} else {
			bLogToFile_ = false;
			dtIniFile_.SetKeyValue("Logging Options", "Log To File", "0");
			bClearLogFile_ = false;
			dtIniFile_.SetKeyValue("Logging Options", "Clear File", "0");
			dtIniFile_.Save(strConfigurationFile_);
		}/* else */
	}/* if */

	/* clear the handle information */
	for (int i = 0; i < NO_HANDLES; i++) {
		memset(pdtHandleInformation_[i].pchrPhysicalPort, 0, 5);
		pdtHandleInformation_[i].dtHandleInfo.nInitialized = false;
		pdtHandleInformation_[i].dtHandleInfo.nEnabled = false;
	} /* for */

	/* send the message */
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "INIT ");

	if (SendMessage(pchrCommand_, TRUE)) {
		if (GetResponse())
			return CheckResponse(VerifyResponse(pchrLastReply_, TRUE));
	} /* if */

	return 0;
} /* InitializeSystem */

/*****************************************************************
 Name:				SetFiringRate

 Inputs:
 None.

 Return Value:
 int - 0 if fails, else CheckResponse

 Description:   This routine sets the POLARIS System's firing rate
 by sending the IRATE command.
 *****************************************************************/
int CommandHandling::SetFiringRate() {
	int FiringRate = 0;

	ReadINIParam<int>("POLARIS Options", "Activation Rate", FiringRate);
	/*
	 * Polaris Accedo and Vicra only support default rate of 20Hz (FiringRate = 0).
	 */
	if (((dtSystemInformation_.nTypeofSystem == ACCEDO_SYSTEM)
			|| (dtSystemInformation_.nTypeofSystem == VICRA_SYSTEM))
			&& (FiringRate != 0)) {
		FiringRate = 0;
		dtIniFile_.SetKeyValue("POLARIS Options", "Activation Rate", "0");
		dtIniFile_.Save(strConfigurationFile_);
	}/* if */

	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "IRATE %d", FiringRate);

	if (SendMessage(pchrCommand_, TRUE)) {
		if (GetResponse())
			return CheckResponse(VerifyResponse(pchrLastReply_, TRUE));
	} /* if */

	return 0;
} /* SetFiringRate */
/*****************************************************************
 Name:				GetSystemInfo

 Inputs:
 None.

 Return Value:
 int - 0 if fails, 1 if passes

 Description:   This routine gets the System information through
 the VER and SFLIST commands, remember that it is
 not the same calls for the AURORA and POLARIS the
 reply mode numbers are different.
 *****************************************************************/
int CommandHandling::GetSystemInfo() {
	int HexResponse = 0, i = 0;

	/* version Information */
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "VER 4");

	if (SendMessage(pchrCommand_, TRUE)) {
		if (!GetResponse()) {
			return 0;
		}/* if */

		if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE))) {
			return 0;
		}/* if */

		if (!strncmp(pchrLastReply_, "POLARIS", 7)
				|| !strncmp(pchrLastReply_, "polaris", 7)
				|| !strncmp(pchrLastReply_, "Polaris", 7)) {
			if (strstr(pchrLastReply_, "ACCEDO")) {
				dtSystemInformation_.nTypeofSystem = ACCEDO_SYSTEM;
			} else if (strstr(pchrLastReply_, "VICRA")
					|| strstr(pchrLastReply_, "vicra")
					|| strstr(pchrLastReply_, "Vicra")) {
				dtSystemInformation_.nTypeofSystem = VICRA_SYSTEM;
			} else if (strstr(pchrLastReply_, "SPECTRA")
					|| strstr(pchrLastReply_, "spectra")
					|| strstr(pchrLastReply_, "Spectra")) {
				dtSystemInformation_.nTypeofSystem = SPECTRA_SYSTEM;
			} else {
				dtSystemInformation_.nTypeofSystem = POLARIS_SYSTEM;
			}/* else */
		} else if (!strncmp(pchrLastReply_, "AURORA", 6)
				|| !strncmp(pchrLastReply_, "aurora", 6)
				|| !strncmp(pchrLastReply_, "Aurora", 6)) {
			dtSystemInformation_.nTypeofSystem = AURORA_SYSTEM;
		} else {
			return 0;
		}/* else */
		//Print out system information
		ROS_INFO("%s %s", dtSystemInformation_.pchrVersionInfo, pchrLastReply_);
		dtSystemInformation_.pchrVersionInfo[strlen(
				dtSystemInformation_.pchrVersionInfo) - 5] = 0;
	} else {
		return 0;
	}

	if (dtSystemInformation_.nTypeofSystem != AURORA_SYSTEM) {
		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "SFLIST 00");
		if (SendMessage(pchrCommand_, TRUE)) {
			if (!GetResponse())
				return 0;
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
			/* supported features summary list */
			HexResponse = ASCIIToHex(pchrLastReply_, 8);
			dtSystemInformation_.nActivePortsAvail =
					(0x01 & HexResponse ? 1 : 0);
			dtSystemInformation_.nPassivePortsAvail = (
					0x02 & HexResponse ? 1 : 0);
			dtSystemInformation_.nMultiVolumeParms =
					(0x04 & HexResponse ? 1 : 0);
			dtSystemInformation_.nTIPSensing = (0x08 & HexResponse ? 1 : 0);
			dtSystemInformation_.nActiveWirelessAvail = (
					0x10 & HexResponse ? 1 : 0);
			dtSystemInformation_.nMagneticPortsAvail = (
					0x8000 & HexResponse ? 1 : 0);
			dtSystemInformation_.nFieldGeneratorAvail = (
					0x40000 & HexResponse ? 1 : 0);
		} else {
			return 0;
		}

		sprintf(pchrCommand_, "SFLIST 01");
		if (SendMessage(pchrCommand_, TRUE)) {
			if (!GetResponse())
				return 0;
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
			/* number of active ports */
			dtSystemInformation_.nNoActivePorts = ASCIIToHex(&pchrLastReply_[0],
					1);
		} else {
			return 0;
		}

		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "SFLIST 02");
		if (SendMessage(pchrCommand_, TRUE)) {
			if (!GetResponse())
				return 0;
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
			/* number of passive ports */
			dtSystemInformation_.nNoPassivePorts = ASCIIToHex(
					&pchrLastReply_[0], 1);
		} else {
			return 0;
		}

		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "SFLIST 04");
		if (SendMessage(pchrCommand_, TRUE)) {
			if (!GetResponse())
				return 0;
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
			/* number of active tool ports supporting TIP detection */
			dtSystemInformation_.nNoActTIPPorts = ASCIIToHex(&pchrLastReply_[0],
					1);
		} else {
			return 0;
		}

		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "SFLIST 05");
		if (SendMessage(pchrCommand_, TRUE)) {
			if (!GetResponse())
				return 0;
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
			/* number of active wireless ports */
			dtSystemInformation_.nNoActWirelessPorts = ASCIIToHex(
					&pchrLastReply_[0], 1);
		} else {
			return 0;
		}

	} /* if */
	else {
		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "SFLIST 10");
		if (SendMessage(pchrCommand_, TRUE)) {
			if (!GetResponse())
				return 0;
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
			/* number of magnetic ports */
			//TODO: ? 2?
			dtSystemInformation_.nNoMagneticPorts = ASCIIToHex(
					&pchrLastReply_[0], 2);
		} else {
			return 0;
		}

		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "SFLIST 12");
		if (SendMessage(pchrCommand_, TRUE)) {
			if (!GetResponse())
				return 0;
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
			/* number of FGs */
			dtSystemInformation_.nNoFGCards = ASCIIToHex(&pchrLastReply_[0], 1);
			dtSystemInformation_.nNoFGs = ASCIIToHex(&pchrLastReply_[1], 1);
		} else {
			return 0;
		}

		/* Field Generator Version Information */
		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "VER 7");

		if (SendMessage(pchrCommand_, TRUE)) {
			if (!GetResponse()) {
				return 0;
			}/* if */

			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE))) {
				return 0;
			}/* if */

			strcat(dtSystemInformation_.pchrVersionInfo, "\n");
			strcat(dtSystemInformation_.pchrVersionInfo, pchrLastReply_);
			dtSystemInformation_.pchrVersionInfo[strlen(
					dtSystemInformation_.pchrVersionInfo) - 5] = 0;
		} else {
			return 0;
		}

		/* SIU Version Information */
		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "VER 8");

		if (SendMessage(pchrCommand_, TRUE)) {
			if (!GetResponse()) {
				return 0;
			}/* if */

			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE))) {
				return 0;
			}/* if */

			strcat(dtSystemInformation_.pchrVersionInfo, "\n");
			strcat(dtSystemInformation_.pchrVersionInfo, pchrLastReply_);
			dtSystemInformation_.pchrVersionInfo[strlen(
					dtSystemInformation_.pchrVersionInfo) - 5] = 0;
		} else {
			return 0;
		}
	} /* else */

	return 1;
} /* GetSystemInfo */
/*****************************************************************
 Name:				InitializeAllPorts

 Inputs:
 None.

 Return Value:
 int - 1 is successful, 0 otherwise

 Description:   This routine intializes all the ports using the
 PINIT call.  It also makes calls to the PVWR routine
 and TTCFG routine to virtual load tool definitions.
 *****************************************************************/
int CommandHandling::InitializeAllPorts() {
	int i = 0, nRet = 0, nPhysicalPorts = 0, nNoHandles = 0, nHandle = 0, n = 0;
	char pszINISection[32], pszPortID[32], pszROMFileName[MAX_PATH],
			szHandleList[MAX_REPLY_MSG], szErrorMessage[98];

	// passive
	for (i = 0; i < dtSystemInformation_.nNoPassivePorts; i++) {
		/* load the ROM if one is specified */
		sprintf(pszPortID, "Wireless Tool %02d", i + 1);
		strcpy(pszROMFileName, "");
		ReadINIParam_array("POLARIS SROM Image Files", std::string(pszPortID),
				pszROMFileName);
		if (*pszROMFileName) {
			LoadVirtualSROM(pszROMFileName, pszPortID, TRUE);
		} /* if */
	} /* for */

	do {
		n = 0;
		/* get the handles that need to be initialized */
		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "PHSR 02");

		if (!SendMessage(pchrCommand_, TRUE))
			return 0;

		if (!GetResponse())
			return 0;

		if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
			return 0;

		sprintf(szHandleList, "%s", pchrLastReply_);
		nNoHandles = ASCIIToHex(&pchrLastReply_[n], 2);
		n += 2;

		if (nNoHandles > 0) {
			// active
			nPhysicalPorts = (
					dtSystemInformation_.nNoActivePorts > 0 ?
							dtSystemInformation_.nNoActivePorts :
					dtSystemInformation_.nNoMagneticPorts > 0 ?
							dtSystemInformation_.nNoMagneticPorts : 0);

			if (dtSystemInformation_.nNoActivePorts == 4)
				nPhysicalPorts = 12;

			sprintf(pszINISection,
					dtSystemInformation_.nNoActivePorts > 0 ?
							"POLARIS SROM Image Files" :
					dtSystemInformation_.nNoMagneticPorts > 0 ?
							"AURORA SROM Image Files" : "");

			for (i = 0; i < nPhysicalPorts; i++) {
				/* if the tool has a ROM defined load it, if TTCFG is defined, load that */
				sprintf(pszPortID, "Port %d", i + 1);
				strcpy(pszROMFileName, "");
				ReadINIParam_array(std::string(pszINISection),
						std::string(pszPortID), pszROMFileName);

				if (*pszROMFileName) {
					if (!strncmp(pszROMFileName, "TTCFG", 5))
						// sets up a configuration for a wired tool, so that you can test the tool without using
						// a tool definition file.
						LoadTTCFG(pszPortID);
					else
						LoadVirtualSROM(pszROMFileName, pszPortID, false);
					nHandle = GetHandleForPort(pszPortID);
					if (nHandle != 0) {
						if (!InitializeHandle(nHandle)) {
							/* Inform user which port fails on PINIT */
							sprintf(szErrorMessage,
									"Port %s could not be initialized.\n"
											"Check your SROM image file settings.",
									pszPortID);
							ROS_ERROR("PINIT ERROR: %s", szErrorMessage);
							return 0;
						}/* if */
					} /* if */
				} /* if */
			} /* for */

			for (int i = 0; i < nNoHandles; i++) {
				nHandle = ASCIIToHex(&szHandleList[n], 2);
				if (!GetPortInformation(nHandle))
					return 0;

				if (!pdtHandleInformation_[nHandle].dtHandleInfo.nInitialized) {
					if (!InitializeHandle(nHandle)) {
						/* Inform user which port fails on PINIT */
						sprintf(szErrorMessage,
								"Port %s could not be initialized.\n"
										"Check your SROM image file settings.",
								pdtHandleInformation_[nHandle].pchrPhysicalPort);
						ROS_ERROR("PINIT ERROR: %s", szErrorMessage);

						return 0;
					}/* if */
					n += 5;
				} /* if */
			} /* for */
		} /* if */
		/* do this until there are no new handles */
	} while (nNoHandles > 0);

	return 1;
} /* InitializeAllPorts */
/*****************************************************************
 Name:				InitializeHandle

 Inputs:
 int nHandle - the handle to be intialized

 Return Value:
 int - 1 if successful, otherwise 0

 Description:   This routine initializes the specified handle using
 the PINIT command.
 *****************************************************************/
int CommandHandling::InitializeHandle(int nHandle) {
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "PINIT %02X", nHandle);
	if (!SendMessage(pchrCommand_, TRUE))
		return 0;
	if (!GetResponse())
		return 0;

	if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE))) {
		return 0;
	} /* if */
	pdtHandleInformation_[nHandle].dtHandleInfo.nInitialized = TRUE;

	return 1;
} /* InitializeHandle */

/*****************************************************************
 Name:				EnableAllPorts

 Inputs:
 None.

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:   This routine enables all the port handles that need
 to be enabled using the PENA command.
 *****************************************************************/
int CommandHandling::EnableAllPorts() {
	int nNoHandles = 0, nPortHandle = 0, n = 0;
	char szHandleList[MAX_REPLY_MSG];

	nPortsEnabled_ = 0;
	/* get all the ports that need to be enabled */
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "PHSR 03");

	if (SendMessage(pchrCommand_, TRUE)) {
		if (!GetResponse())
			return 0;

		if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
			return 0;

		sprintf(szHandleList, "%s", pchrLastReply_);
		nNoHandles = ASCIIToHex(&szHandleList[n], 2);
		n += 2;

		for (int i = 0; i < nNoHandles; i++) {
			nPortHandle = ASCIIToHex(&szHandleList[n], 2);
			memset(pchrCommand_, 0, sizeof(pchrCommand_));
			sprintf(pchrCommand_, "PENA %02X%c", nPortHandle, 'D');
			n += 5;
			if (!SendMessage(pchrCommand_, TRUE))
				return 0;
			if (!GetResponse())
				return 0;
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
			GetPortInformation(nPortHandle);
			nPortsEnabled_++;
		} /* for */
		return 1;
	} /* if */
	return 0;
} /* EnableAllPorts */

/*****************************************************************
 Name:				EnableOnePorts

 Inputs:
 None.

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:   This routine enables specified port handles that need
 to be enabled using the PENA command.
 *****************************************************************/
int CommandHandling::EnableOnePort(int nPortHandle) {
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "PENA %02X%c", nPortHandle, 'D');
	if (!SendMessage(pchrCommand_, TRUE))
		return 0;
	if (!GetResponse())
		return 0;
	if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
		return 0;
	GetPortInformation(nPortHandle);
	return 1;
} /* EnableOnePorts */

/*****************************************************************
 Name:				DisablePort

 Inputs:
 int nPortHandle - handle to be disabled

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:    This routine disables the supplied port handle
 using the PDIS call.
 *****************************************************************/
int CommandHandling::DisablePort(int nPortHandle) {
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "PDIS %02X", nPortHandle);

	if (SendMessage(pchrCommand_, TRUE)) {
		if (!GetResponse())
			return 0;
		if (CheckResponse(VerifyResponse(pchrLastReply_, TRUE))) {
			GetPortInformation(nPortHandle);
			return 1;
		} /* if */
	} /* if */

	return 0;
} /* DisablePort */
/*****************************************************************
 Name:				ActivateAllPorts

 Inputs:
 None.

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:    This is the routine that activates all ports using

 *****************************************************************/
int CommandHandling::ActivateAllPorts() {
	if (!FreePortHandles())
		return 0;

	if (!InitializeAllPorts())
		return 0;

	if (!EnableAllPorts())
		return 0;

	return 1;
} /* ActivateAllPorts */
/*****************************************************************
 Name:				LoadVirtualSROM

 Inputs:
 char * pszFileName - the file to be loaded
 char * pPhysicalPortID - the physical port id that is being
 loaded to.
 bool bPassive - is this a passive port or not

 Return Value:
 int - 1 if successful, 0 otherwise.

 Description:
 This routine virtual loads a SROM file to the specified port.
 It uses the PVWR command to do this.
 *****************************************************************/
int CommandHandling::LoadVirtualSROM(char * pszFileName, char * pPhysicalPortID,
		bool bPassive) {
	FILE *pFileHandle = NULL;
	int nRet = 0, nHandle = 0, nBytes = 0, nCnt = 0, i = 0, n = 0;
	static unsigned char gruchBuff[1024];
	char cMessage[256];

	if (!*pszFileName)
		return 0;

	if (bPassive) {
		for (i = 0; i < NO_HANDLES; i++) {
			if (!strncmp(pdtHandleInformation_[i].pchrPhysicalPort,
					pPhysicalPortID, 16))
				return 0;
		}
		/* if passive we need a port handle */
		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "PHRQ ********01****");
		if (!SendMessage(pchrCommand_, TRUE))
			return 0;

		if (!GetResponse())
			return 0;
		if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
			return 0;
		nHandle = ASCIIToHex(&pchrLastReply_[n], 2);
		if (pdtHandleInformation_[nHandle].dtHandleInfo.nInitialized == 1)
			return 0;

		if (dtSystemInformation_.nTypeofSystem == VICRA_SYSTEM
				|| dtSystemInformation_.nTypeofSystem == SPECTRA_SYSTEM)
			sprintf(pdtHandleInformation_[nHandle].pchrPhysicalPort, "%s",
					pPhysicalPortID);
	}/* if */
	else {
		/* if active a handle has already been assigned */
		nHandle = GetHandleForPort(pPhysicalPortID);
		if (nHandle == 0
				|| pdtHandleInformation_[nHandle].dtHandleInfo.nInitialized
						== 1)
			return 0;
	}/* else */

	if (!(pFileHandle = fopen(pszFileName, "rb"))) {
		return 0;
	} /* if */

	if ((nBytes = fread(gruchBuff, 1, sizeof(gruchBuff), pFileHandle)) < 1) {
		sprintf(cMessage, "Unable to read ROM image file %s.", pszFileName);
		ROS_ERROR("SROM Error: %s", cMessage);
		goto cleanup;
	} /* if */

	for (nCnt = 0; nCnt < nBytes;) {
		/*
		 * write the data to the tool description section of
		 * the virtual SROM on a per port basis
		 */
		memset(pchrCommand_, 0, sizeof(pchrCommand_));
		sprintf(pchrCommand_, "PVWR:%02X%04X", nHandle, nCnt);

		for (i = 0; i < 64; i++, nCnt++) {
			/* (plus eleven for the PVWR:XX0000 ) */
			sprintf(pchrCommand_ + 11 + 2 * i, "%02X", gruchBuff[nCnt]);
		} /* for */
		int n = strlen(pchrCommand_);
		if (!SendMessage(pchrCommand_, TRUE))
			goto cleanup;

		if (!GetResponse()) {
			sprintf(cMessage, "Failed writing to %s.", pPhysicalPortID);
			ROS_ERROR("SROM Image Error: %s", cMessage);
			goto cleanup;
		} /* if */
		if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE))) {
			goto cleanup;
		} /* if */
	} /* for */

	cleanup: if (!(fclose(pFileHandle)))
		return 0;

	return 1;
} /* LoadVirtualSROM */
/*****************************************************************
 Name:			LoadTTCFG

 Inputs:
 char * pszPortID - the physical port to be loaded with TTCFG

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:
 This routine loads the Test Tool ConFiGuration to the specified
 port.
 *****************************************************************/
int CommandHandling::LoadTTCFG(char * pszPortID) {
	int nPortHandle = 0;

	/* get the handle for the port */
	nPortHandle = GetHandleForPort(pszPortID);
	if (nPortHandle == 0)
		return 0;

	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "TTCFG %02X", nPortHandle);
	if (SendMessage(pchrCommand_, TRUE)) {
		if (GetResponse())
			return (CheckResponse(VerifyResponse(pchrLastReply_, TRUE)));
	} /* if */
	return 0;
} /* LoadTTCFG */
/*****************************************************************
 Name:				GetHandleForPort

 Inputs:
 char * pszPortID - the physical port to match a handle to

 Return Value:
 int - 0 if fails, port handle if passes

 Description:
 This routine takes a physical port location and matches a handle
 to it.  These handles have already been defined with a PHSR
 *****************************************************************/
int CommandHandling::GetHandleForPort(char * pszPortID) {
	int nPortHandle = 0, nNoHandles = 0, n = 0;
	char szHandleList[MAX_REPLY_MSG];

	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "PHSR 00");

	if (SendMessage(pchrCommand_, TRUE)) {
		if (GetResponse())
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
	} /* if */

	sprintf(szHandleList, "%s", pchrLastReply_);
	nNoHandles = ASCIIToHex(&szHandleList[n], 2);
	n += 2;

	for (int i = 0; i < nNoHandles; i++) {
		/* for all the handles, get their physical location with PHINF */
		nPortHandle = ASCIIToHex(&szHandleList[n], 2);
		n += 5;
		GetPortInformation(nPortHandle);
		/* if the physical location match pszPortID, return the handle */
		if (!strncmp(pdtHandleInformation_[nPortHandle].pchrPhysicalPort,
				pszPortID, 2))
			return nPortHandle;
	} /* for */

	return 0;
} /* GetHandleForPort */
/*****************************************************************
 Name:				FreePortHandles

 Inputs:
 None.

 Return Value:
 int - 0 if fails, 1 if passes

 Description:
 This routine frees all port handles that need to be freed
 using the PHF command.
 *****************************************************************/
int CommandHandling::FreePortHandles() {
	int nNoHandles = 0, nHandle = 0, n = 0;
	char szHandleList[MAX_REPLY_MSG];

	/* get all the handles that need freeing */
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "PHSR 01");

	if (SendMessage(pchrCommand_, TRUE)) {
		if (!GetResponse())
			return 0;
		if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
			return 0;

		sprintf(szHandleList, "%s", pchrLastReply_);
		nNoHandles = ASCIIToHex(&szHandleList[n], 2);
		n += 2;
		for (int i = 0; i < nNoHandles; i++) {
			nHandle = ASCIIToHex(&szHandleList[n], 2);
			memset(pchrCommand_, 0, sizeof(pchrCommand_));
			sprintf(pchrCommand_, "PHF %02X", nHandle);
			n += 5;
			if (!SendMessage(pchrCommand_, TRUE))
				return 0;
			if (!GetResponse())
				return 0;
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
			pdtHandleInformation_[nHandle].dtHandleInfo.nInitialized = false;
			pdtHandleInformation_[nHandle].dtHandleInfo.nEnabled = false;
			/* EC-03-0071 */
			memset(pdtHandleInformation_[nHandle].pchrPhysicalPort, 0, 5);
		} /* for */
		return 1;
	} /* if */

	return 0;
} /* FreePortHandles */
/*****************************************************************
 Name:				GetPortInformation

 Inputs:
 int nPortHandle - the handle to get information for

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:
 This routine gets the port handling information for the supplied
 handle.  It uses the PHINF call to get this information.
 *****************************************************************/
int CommandHandling::GetPortInformation(int nPortHandle) {
	unsigned int uASCIIConv = 0;
	char *pszPortInformation = NULL;

	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	if (dtSystemInformation_.nTypeofSystem == VICRA_SYSTEM
			|| dtSystemInformation_.nTypeofSystem == SPECTRA_SYSTEM)
		sprintf(pchrCommand_, "PHINF %02X0005", nPortHandle);
	else
		sprintf(pchrCommand_, "PHINF %02X0025", nPortHandle);

	if (SendMessage(pchrCommand_, TRUE)) {
		if (GetResponse()) {
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;

			pszPortInformation = pchrLastReply_;

			strncpy(pdtHandleInformation_[nPortHandle].pchrToolType,
					pszPortInformation, 8);
			pdtHandleInformation_[nPortHandle].pchrToolType[8] = '\0';
			pszPortInformation += 8;
			strncpy(pdtHandleInformation_[nPortHandle].pchrManufact,
					pszPortInformation, 12);
			pdtHandleInformation_[nPortHandle].pchrManufact[12] = '\0';
			pszPortInformation += 12;
			strncpy(pdtHandleInformation_[nPortHandle].pchrRev,
					pszPortInformation, 3);
			pdtHandleInformation_[nPortHandle].pchrRev[3] = '\0';
			pszPortInformation += 3;
			strncpy(pdtHandleInformation_[nPortHandle].pchrSerialNo,
					pszPortInformation, 8);
			pdtHandleInformation_[nPortHandle].pchrSerialNo[8] = '\0';
			pszPortInformation += 8;
			uASCIIConv = ASCIIToHex(pszPortInformation, 2);
			pszPortInformation += 2;
			pdtHandleInformation_[nPortHandle].dtHandleInfo.nToolInPort = (
					uASCIIConv & 0x01 ? 1 : 0);
			pdtHandleInformation_[nPortHandle].dtHandleInfo.nGPIO1 = (
					uASCIIConv & 0x02 ? 1 : 0);
			pdtHandleInformation_[nPortHandle].dtHandleInfo.nGPIO2 = (
					uASCIIConv & 0x04 ? 1 : 0);
			pdtHandleInformation_[nPortHandle].dtHandleInfo.nGPIO3 = (
					uASCIIConv & 0x08 ? 1 : 0);
			pdtHandleInformation_[nPortHandle].dtHandleInfo.nInitialized = (
					uASCIIConv & 0x10 ? 1 : 0);
			pdtHandleInformation_[nPortHandle].dtHandleInfo.nEnabled = (
					uASCIIConv & 0x20 ? 1 : 0);
			pdtHandleInformation_[nPortHandle].dtHandleInfo.TIPCurrentSensing =
					(uASCIIConv & 0x80 ? 1 : 0);

			/* parse the part number 0x0004 */
			strncpy(pdtHandleInformation_[nPortHandle].pchrPartNumber,
					pszPortInformation, 20);
			pdtHandleInformation_[nPortHandle].pchrPartNumber[20] = '\0';
			pszPortInformation += 20;

			if (dtSystemInformation_.nTypeofSystem != VICRA_SYSTEM
					&& dtSystemInformation_.nTypeofSystem != SPECTRA_SYSTEM) {
				pszPortInformation += 10;
				sprintf(pdtHandleInformation_[nPortHandle].pchrPhysicalPort,
						"%d", nPortHandle);
				strncpy(pdtHandleInformation_[nPortHandle].pchrPhysicalPort,
						pszPortInformation, 2);
				/* EC-03-0071
				 HandleInformation_[nPortHandle].pchrPhysicalPort[2] = '\0';
				 */
				pszPortInformation += 2;
				strncpy(pdtHandleInformation_[nPortHandle].pchrChannel,
						pszPortInformation, 2);
				pdtHandleInformation_[nPortHandle].pchrChannel[2] = '\0';
				if (!strncmp(pdtHandleInformation_[nPortHandle].pchrChannel,
						"01", 2)) {
					/* EC-03-0071
					 strncat(HandleInformation_[nPortHandle].pchrPhysicalPort, "-b", 2 );
					 */
					strncpy(
							&pdtHandleInformation_[nPortHandle].pchrPhysicalPort[2],
							"-b", 2);
					for (int i = 0; i < NO_HANDLES; i++) {
						if (strncmp(pdtHandleInformation_[i].pchrPhysicalPort,
								pdtHandleInformation_[nPortHandle].pchrPhysicalPort,
								4)
								&& !strncmp(
										pdtHandleInformation_[i].pchrPhysicalPort,
										pdtHandleInformation_[nPortHandle].pchrPhysicalPort,
										2))
							/* EC-03-0071
							 strncat(HandleInformation_[i].pchrPhysicalPort, "-a", 2 );
							 */
							strncpy(
									&pdtHandleInformation_[i].pchrPhysicalPort[2],
									"-a", 2);
					} /* for */
				} /* if */
			} /* if */
		} /* if */
		else
			return 0;
	} /* if */

	return 1;
} /* GetPortInformation */
/*****************************************************************
 Name:				StartTracking

 Inputs:
 None.

 Return Value:
 int - 0 if fails, else CheckResponse

 Description:    This routine starts that System tracking.  It uses
 the TSTART command to do this.
 *****************************************************************/
int CommandHandling::StartTracking() {
	bDisplayErrorsWhileTracking_ = true;
	ReadINIParam<bool>("Reporting Options", "Report While Tracking",
			bDisplayErrorsWhileTracking_);

	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "TSTART ");

	if (SendMessage(pchrCommand_, TRUE)) {
		GetResponse();
		return CheckResponse(VerifyResponse(pchrLastReply_, TRUE));
	} /* if */

	return 0;
} /* StartTracking */
/*****************************************************************
 Name:				GetTXTransforms

 Inputs:
 bool bReturnOOV - whether or not to return values outside
 of the characterized volume.

 Return Value:
 int - 1 if successful, 0 otherwise.

 Description:
 This routine gets the transformation information using the TX
 command.  Remember that if you want to track outside the
 characterized volume you need to set the flag.
 *****************************************************************/
int CommandHandling::GetTXTransforms(bool bReturn0x0800Option) {
	int nReplyMode = 0x0001, nNoHandles = 0, nHandle = 0, nRet = 0;
	unsigned int unHandleStatus = 0, unSystemStatus = 0;
	bool bDisabled = false;
	char *pszTransformInfo = NULL;

	/* report in volume only or out of volume as well */
	nReplyMode = bReturn0x0800Option ? 0x0801 : 0x0001;

	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "TX %04X", nReplyMode);

	if (SendMessage(pchrCommand_, TRUE)) {
		if (!GetResponse()) {
			return 0;
		}/* if */

		if (bDisplayErrorsWhileTracking_) {
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
		} else {
			if (!VerifyResponse(pchrLastReply_, false))
				return 0;
		}/* else */

		/* TX Parsing Routines */
		pszTransformInfo = pchrLastReply_;

		nNoHandles = ASCIIToHex(pszTransformInfo, 2);
		pszTransformInfo += 2;

		for (int i = 0; i < nNoHandles; i++) {
			nHandle = ASCIIToHex(pszTransformInfo, 2);
			pszTransformInfo += 2;

			bDisabled = false;

			if (strlen(pszTransformInfo) < 18)
				return 0;

			if (!strncmp(pszTransformInfo, "MISSING", 7)
					|| !strncmp(pszTransformInfo, "DISABLED", 8)
					|| !strncmp(pszTransformInfo, "UNOCCUPIED", 10)) {
				if (!strncmp(pszTransformInfo, "UNOCCUPIED", 10)) {

					pdtHandleInformation_[nHandle].dtXfrms.ulFlags =
					TRANSFORM_UNOCCUPIED;
					pszTransformInfo += 10;
					bDisabled = TRUE;
				} /* if */
				else if (!strncmp(pszTransformInfo, "DISABLED", 8)) {
					pdtHandleInformation_[nHandle].dtXfrms.ulFlags =
					TRANSFORM_DISABLED;
					pszTransformInfo += 8;
					bDisabled = TRUE;
				} /* else if */
				else {
					pdtHandleInformation_[nHandle].dtXfrms.ulFlags =
					TRANSFORM_MISSING;
					pszTransformInfo += 7;
				} /* else */
				pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQ0 =
						pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQx =
								pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQy =
										pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQz =
												pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTx =
														pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTy =
																pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTz =
																		pdtHandleInformation_[nHandle].dtXfrms.fError =
																				BAD_FLOAT;
			} /* if */
			else {
				pdtHandleInformation_[nHandle].dtXfrms.ulFlags =
				TRANSFORM_VALID;

				if (!ExtractValue(pszTransformInfo, 6, 10000.,
						&pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQ0)
						|| !ExtractValue(pszTransformInfo + 6, 6, 10000.,
								&pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQx)
						|| !ExtractValue(pszTransformInfo + 12, 6, 10000.,
								&pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQy)
						|| !ExtractValue(pszTransformInfo + 18, 6, 10000.,
								&pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQz)
						|| !ExtractValue(pszTransformInfo + 24, 7, 100.,
								&pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTx)
						|| !ExtractValue(pszTransformInfo + 31, 7, 100.,
								&pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTy)
						|| !ExtractValue(pszTransformInfo + 38, 7, 100.,
								&pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTz)
						|| !ExtractValue(pszTransformInfo + 45, 6, 10000.,
								&pdtHandleInformation_[nHandle].dtXfrms.fError)) {
					pdtHandleInformation_[nHandle].dtXfrms.ulFlags =
					TRANSFORM_MISSING;
					return 0;
				} /* if */
				else {
					pszTransformInfo += 51;
				} /* else */
			} /* else */
			/*get handle status...*/
			if (!bDisabled) {
				unHandleStatus = ASCIIToHex(pszTransformInfo, 8);
				pszTransformInfo += 8;
				pdtHandleInformation_[nHandle].dtHandleInfo.nToolInPort = (
						unHandleStatus & 0x01 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nGPIO1 = (
						unHandleStatus & 0x02 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nGPIO2 = (
						unHandleStatus & 0x04 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nGPIO3 = (
						unHandleStatus & 0x08 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nInitialized = (
						unHandleStatus & 0x10 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nEnabled = (
						unHandleStatus & 0x20 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nOutOfVolume = (
						unHandleStatus & 0x40 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nPartiallyOutOfVolume =
						(unHandleStatus & 0x80 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nDisturbanceDet = (
						unHandleStatus & 0x200 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nSignalTooSmall = (
						unHandleStatus & 0x400 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nSignalTooBig = (
						unHandleStatus & 0x800 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nProcessingException =
						(unHandleStatus & 0x1000 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nHardwareFailure = (
						unHandleStatus & 0x2000 ? 1 : 0);

				/*get frame number...*/
				pdtHandleInformation_[nHandle].dtXfrms.ulFrameNumber =
						ASCIIToHex(pszTransformInfo, 8);
				pszTransformInfo += 8;
			} /* if */
			pszTransformInfo++; /*for the carriage return*/
		} /* for */

		unSystemStatus = ASCIIToHex(pszTransformInfo, 4);
		dtSystemInformation_.nCommunicationSyncError = (
				unSystemStatus & 0x01 ? 1 : 0);
		dtSystemInformation_.nTooMuchInterference = (
				unSystemStatus & 0x02 ? 1 : 0);
		dtSystemInformation_.nSystemCRCError = (unSystemStatus & 0x04 ? 1 : 0);
		dtSystemInformation_.nRecoverableException = (
				unSystemStatus & 0x08 ? 1 : 0);
		dtSystemInformation_.nHardwareFailure = (unSystemStatus & 0x10 ? 1 : 0);
		dtSystemInformation_.nHardwareChange = (unSystemStatus & 0x20 ? 1 : 0);
		dtSystemInformation_.nPortOccupied = (unSystemStatus & 0x40 ? 1 : 0);
		dtSystemInformation_.nPortUnoccupied = (unSystemStatus & 0x80 ? 1 : 0);
		dtSystemInformation_.nDiagnosticsPending = (
				unSystemStatus & 0x100 ? 1 : 0);
		dtSystemInformation_.nTemperatureOutOfRange = (
				unSystemStatus & 0x200 ? 1 : 0);

	} /* if */

	/*
	 * reference tracking...apply at the end of all the parsing so that
	 * it is all the latest xfrms being applied
	 */
	ApplyXfrms();

	return 1;
} /* GetTXTransforms */

/*****************************************************************
 Name:				GetBXTransforms

 Inputs:
 bool bReturnOOV - whether or not to return values outside
 of the characterized volume.

 Return Value:
 int - 1 if successful, 0 otherwise.

 Description:
 This routine gets the transformation information using the BX
 command.  Remember that if you want to track outside the
 characterized volume you need to set the flag.
 *****************************************************************/
int CommandHandling::GetBXTransforms(bool bReturn0x0800Option) {
	int nReplyMode = 0x0001, nReplySize = 0, nSpot = 0, nNoHandles = 0,
			nHandle = 0, nRet = 0;
	unsigned int unSystemStatus = 0, uTransStatus = 0, unHandleStatus = 0,
			uHeaderCRC = 0, uBodyCRC = 0, uCalcCRC = 0;
	char *pszTransformInfo = NULL;

	/* set reply mode depending on bReturnOOV */
	nReplyMode = bReturn0x0800Option ? 0x0801 : 0x0001;

	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "BX %04X", nReplyMode);

	if (SendMessage(pchrCommand_, TRUE)) {
		if (!GetBinaryResponse()) {
			return 0;
		}/* if */

		if (bDisplayErrorsWhileTracking_) {
			if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
				return 0;
		} else {
			if (!VerifyResponse(pchrLastReply_, false))
				return 0;
		}/* else */

		pszTransformInfo = pchrLastReply_;
		uCalcCRC = SystemGetCRC(pchrLastReply_, 4);

		/* check for preamble ( A5C4 ) */
		while (((pszTransformInfo[0] & 0xff) != 0xc4)) {
			pszTransformInfo++;
		}/* while */

		if ((pszTransformInfo[0] & 0xff) != 0xc4
				|| (pszTransformInfo[1] & 0xff) != 0xa5) {
			return REPLY_INVALID;
		}/* if */

		/* parse the header */
		nSpot += 2;
		nReplySize = GetHex2(&pszTransformInfo[nSpot]);
		nSpot += 2;
		uHeaderCRC = GetHex2(&pszTransformInfo[nSpot]);
		nSpot += 2;

		if (uCalcCRC != uHeaderCRC) {
			if (bDisplayErrorsWhileTracking_)
				CheckResponse( REPLY_BADCRC); /* display the Bad CRC error message */
			return REPLY_BADCRC;
		} /* if */

		nNoHandles = GetHex1(&pszTransformInfo[nSpot]);
		nSpot++;

		for (int i = 0; i < nNoHandles; i++) {
			nHandle = GetHex1(&pszTransformInfo[nSpot]);
			nSpot++;

			uTransStatus = GetHex1(&pszTransformInfo[nSpot]);
			nSpot++;

			if (uTransStatus == 1) /* one means that the transformation was returned */
			{
				/* parse out the individual components by converting binary to floats */
				pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQ0 =
						GetFloat(&pszTransformInfo[nSpot]);
				nSpot += 4;
				pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQx =
						GetFloat(&pszTransformInfo[nSpot]);
				nSpot += 4;
				pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQy =
						GetFloat(&pszTransformInfo[nSpot]);
				nSpot += 4;
				pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQz =
						GetFloat(&pszTransformInfo[nSpot]);
				nSpot += 4;
				pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTx =
						GetFloat(&pszTransformInfo[nSpot]);
				nSpot += 4;
				pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTy =
						GetFloat(&pszTransformInfo[nSpot]);
				nSpot += 4;
				pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTz =
						GetFloat(&pszTransformInfo[nSpot]);
				nSpot += 4;
				pdtHandleInformation_[nHandle].dtXfrms.fError = GetFloat(
						&pszTransformInfo[nSpot]);
				nSpot += 4;
				unHandleStatus = GetHex4(&pszTransformInfo[nSpot]);
				nSpot += 4;
				pdtHandleInformation_[nHandle].dtXfrms.ulFrameNumber = GetHex4(
						&pszTransformInfo[nSpot]);
				nSpot += 4;
				pdtHandleInformation_[nHandle].dtXfrms.ulFlags =
				TRANSFORM_VALID;
			} /* if */

			if (uTransStatus == 2 || uTransStatus == 4) /* 2 means the tool is missing and */
			/* 4 means DISABLED */
			{
				/*
				 * no transformation information is returned but the port status and time
				 * are return
				 */
				if (uTransStatus == 2) {
					unHandleStatus = GetHex4(&pszTransformInfo[nSpot]);
					nSpot += 4;
					pdtHandleInformation_[nHandle].dtXfrms.ulFrameNumber =
							GetHex4(&pszTransformInfo[nSpot]);
					nSpot += 4;
					pdtHandleInformation_[nHandle].dtXfrms.ulFlags =
					TRANSFORM_MISSING;
				} /* if */
				else
					pdtHandleInformation_[nHandle].dtXfrms.ulFlags =
					TRANSFORM_DISABLED;

				pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQ0 =
						pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQx =
								pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQy =
										pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQz =
												pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTx =
														pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTy =
																pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTz =
																		pdtHandleInformation_[nHandle].dtXfrms.fError =
																				BAD_FLOAT;
			}/* if */

			if (uTransStatus == 1 || uTransStatus == 2) {
				pdtHandleInformation_[nHandle].dtHandleInfo.nToolInPort = (
						unHandleStatus & 0x01 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nGPIO1 = (
						unHandleStatus & 0x02 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nGPIO2 = (
						unHandleStatus & 0x04 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nGPIO3 = (
						unHandleStatus & 0x08 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nInitialized = (
						unHandleStatus & 0x10 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nEnabled = (
						unHandleStatus & 0x20 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nOutOfVolume = (
						unHandleStatus & 0x40 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nPartiallyOutOfVolume =
						(unHandleStatus & 0x80 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nDisturbanceDet = (
						unHandleStatus & 0x200 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nSignalTooSmall = (
						unHandleStatus & 0x400 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nSignalTooBig = (
						unHandleStatus & 0x800 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nProcessingException =
						(unHandleStatus & 0x1000 ? 1 : 0);
				pdtHandleInformation_[nHandle].dtHandleInfo.nHardwareFailure = (
						unHandleStatus & 0x2000 ? 1 : 0);
			}/* if */
		} /* for */

		unSystemStatus = GetHex2(&pszTransformInfo[nSpot]);
		nSpot += 2;
		uBodyCRC = GetHex2(&pszTransformInfo[nSpot]);
		dtSystemInformation_.nCommunicationSyncError = (
				unSystemStatus & 0x01 ? 1 : 0);
		dtSystemInformation_.nTooMuchInterference = (
				unSystemStatus & 0x02 ? 1 : 0);
		dtSystemInformation_.nSystemCRCError = (unSystemStatus & 0x04 ? 1 : 0);
		dtSystemInformation_.nRecoverableException = (
				unSystemStatus & 0x08 ? 1 : 0);
		dtSystemInformation_.nHardwareFailure = (unSystemStatus & 0x10 ? 1 : 0);
		dtSystemInformation_.nHardwareChange = (unSystemStatus & 0x20 ? 1 : 0);
		dtSystemInformation_.nPortOccupied = (unSystemStatus & 0x40 ? 1 : 0);
		dtSystemInformation_.nPortUnoccupied = (unSystemStatus & 0x80 ? 1 : 0);
		dtSystemInformation_.nDiagnosticsPending = (
				unSystemStatus & 0x100 ? 1 : 0);
		dtSystemInformation_.nTemperatureOutOfRange = (
				unSystemStatus & 0x200 ? 1 : 0);

		uCalcCRC = SystemGetCRC(pszTransformInfo += 6, nSpot - 6);
		if (uCalcCRC != uBodyCRC) {
			CheckResponse( REPLY_BADCRC); /* display the Bad CRC error message */
			return REPLY_BADCRC;
		} /* if */

	} /* if */

	/*
	 * reference tracking...apply at the end of all the parsing so that
	 * it is all the latest xfrms being applied
	 */
	ApplyXfrms();

	return 1;
} /* GetBXTransforms */

/*****************************************************************
 Name:				ApplyXfrm

 Inputs:
 int nHandle - the handle to change

 Return Value:

 Description:   Switch the tools coordinate system to that of the
 specified reference handle.
 *****************************************************************/
void CommandHandling::ApplyXfrms() {
	QuatTransformation dtRefQuatXfrm, dtRefQuatXfrmInv, dtPortQuatXfrm,
			dtNewQuatXfrm;

	if (nRefHandle_ == -1) //if no reference handle do nothing
		return;

	for (int nHandle = 0; nHandle < NO_HANDLES; nHandle++) {
		if (nHandle != nRefHandle_ &&	// don't apply the reference to itself
				pdtHandleInformation_[nHandle].dtHandleInfo.nEnabled) // only apply if the handle is enabled
				{
			if (pdtHandleInformation_[nRefHandle_].dtXfrms.dtTranslation.fTx
					<= MAX_NEGATIVE) {
				pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTx =
						pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTy =
								pdtHandleInformation_[nHandle].dtXfrms.dtTranslation.fTz =
										pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQ0 =
												pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQx =
														pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQy =
																pdtHandleInformation_[nHandle].dtXfrms.dtRotation.fQz =
																BAD_FLOAT;
				pdtHandleInformation_[nHandle].dtXfrms.ulFlags =
				TRANSFORM_MISSING;
			}/* if */
			else {
				dtRefQuatXfrm.dtRotation =
						pdtHandleInformation_[nRefHandle_].dtXfrms.dtRotation;
				dtRefQuatXfrm.dtTranslation =
						pdtHandleInformation_[nRefHandle_].dtXfrms.dtTranslation;
				QuatInverseXfrm(&dtRefQuatXfrm, &dtRefQuatXfrmInv);

				dtPortQuatXfrm.dtRotation =
						pdtHandleInformation_[nHandle].dtXfrms.dtRotation;
				dtPortQuatXfrm.dtTranslation =
						pdtHandleInformation_[nHandle].dtXfrms.dtTranslation;
				QuatCombineXfrms(&dtPortQuatXfrm, &dtRefQuatXfrmInv,
						&dtNewQuatXfrm);
				pdtHandleInformation_[nHandle].dtXfrms.dtRotation =
						dtNewQuatXfrm.dtRotation;
				pdtHandleInformation_[nHandle].dtXfrms.dtTranslation =
						dtNewQuatXfrm.dtTranslation;
			}/* else */
		} /* if */
	} /* for */
} /* ApplyXfrm */

/*****************************************************************
 Name:				nStopTracking

 Inputs:
 None.

 Return Value:
 int - 0 if fails, CheckResponse if passes

 Description:   This routine stops the System's tracking by using
 the TSTOP call.
 *****************************************************************/
int CommandHandling::StopTracking() {
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "TSTOP ");

	if (SendMessage(pchrCommand_, TRUE)) {
		GetResponse();
		return CheckResponse(VerifyResponse(pchrLastReply_, TRUE));
	} /* if */

	return 0;
} /* nStopTracking */

/*****************************************************************
 Name:				GetNewAlerts

 Inputs:
 None.

 Return Value:
 int - 0 if fails, 1 if passes

 Description:   This routine gets the new alerts and fills the
 new alerts structure with the appropriate flags.
 ***********************************************************/
int CommandHandling::GetAlerts(bool bNewAlerts) {
	unsigned int unAlertsStatus = 0;
	char *pszAlertsInfo = NULL;

	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	if (bNewAlerts)
		sprintf(pchrCommand_, "GET Info.Status.New Alerts");
	else
		sprintf(pchrCommand_, "GET Info.Status.Alerts");

	if (SendMessage(pchrCommand_, TRUE)) {
		if (!GetResponse()) {
			return 0;
		}/* if */

		if (!CheckResponse(VerifyResponse(pchrLastReply_, TRUE)))
			return 0;

		/* Parsing Timeouts */

		pchrLastReply_[strlen(pchrLastReply_) - 5] = '\0'; // 4 for CRC and 1 for <CR>
		pszAlertsInfo = pchrLastReply_;

		while (*pszAlertsInfo != '=')
			pszAlertsInfo++;

		pszAlertsInfo++;

		//convert the ascii to integer format
		unAlertsStatus = atoi(pszAlertsInfo);

		dtNewAlerts_.nFatalParamterFault = (
				unAlertsStatus & ALERT_FATAL_PARAM_FAULT ? 1 : 0);
		dtNewAlerts_.nSensorParameterFault = (
				unAlertsStatus & ALERT_SENSOR_PARAM_FAULT ? 1 : 0);
		dtNewAlerts_.nMainVoltageFault = (
				unAlertsStatus & ALERT_MAIN_VOLTAGE_FAULT ? 1 : 0);
		dtNewAlerts_.nSensorVoltageFault = (
				unAlertsStatus & ALERT_SENSOR_VOLTAGE_FAULT ? 1 : 0);
		dtNewAlerts_.nIlluminatorVoltageFault = (
				unAlertsStatus & ALERT_ILLUM_VOLTAGE_FAULT ? 1 : 0);
		dtNewAlerts_.nIlluminatorCurrentFault = (
				unAlertsStatus & ALERT_ILLUM_CURRENT_FAULT ? 1 : 0);
		dtNewAlerts_.nLeftSensorTempFault = (
				unAlertsStatus & ALERT_LEFT_SENSOR_TEMP ? 1 : 0);
		dtNewAlerts_.nRightSensorTempFault = (
				unAlertsStatus & ALERT_RIGHT_SENSOR_TEMP ? 1 : 0);
		dtNewAlerts_.nMainBoardTempFault = (
				unAlertsStatus & ALERT_MAIN_BOARD_TEMP ? 1 : 0);
		dtNewAlerts_.nBatteryFaultAlarm = (
				unAlertsStatus & ALERT_BATTERY_FAULT ? 1 : 0);
		dtNewAlerts_.nBumpDetectedAlarm = (
				unAlertsStatus & ALERT_BUMP_DETECTED ? 1 : 0);
		dtNewAlerts_.nCableFaultAlarm = (
				unAlertsStatus & ALERT_CABLE_FAULT ? 1 : 0);
		dtNewAlerts_.nFirmwareIncompatible = (
				unAlertsStatus & ALERT_FIRMWARE_INCOMPAT ? 1 : 0);
		dtNewAlerts_.nNonFatalParamFault = (
				unAlertsStatus & ALERT_NON_FATAL_PARAM_FAULT ? 1 : 0);
		dtNewAlerts_.nInternalFlashFull = (
				unAlertsStatus & ALERT_INTERNAL_FLASH_FULL ? 1 : 0);
		dtNewAlerts_.nLaserBatteryFaultAlarm = (
				unAlertsStatus & ALERT_LASER_BATTERY_FAULT ? 1 : 0);
		dtNewAlerts_.nTempTooHigh = (
				unAlertsStatus & ALERT_TEMP_TOO_HIGH ? 1 : 0);
		dtNewAlerts_.nTempTooLow =
				(unAlertsStatus & ALERT_TEMP_TOO_LOW ? 1 : 0);

		return 1;
	} else {
		return 0;
	}
}

/***********************************************************
 Name: LookupTimeout

 Returns: int
 Argument: char *szCommand

 Description: Looks up the command in the Timeout value list
 (TimeoutValues_) and returns the timeout
 value for the specified command
 ***********************************************************/
int CommandHandling::LookupTimeout(char *szCommand) {
	std::string sCommand(szCommand);
	int nTimeoutValue;

	/*
	 * Please note that the Get Info.Timeout.* functionality is
	 * enabled on the Aurora, but the timeout values returned may
	 * not work for the communication speed selected. For this reason
	 * we will use the Default Timeout Value.
	 */
	if (dtSystemInformation_.nTypeofSystem == AURORA_SYSTEM)
		return nDefaultTimeout_;

	//int nPos = sCommand.indexOf(" :");
	int nPos = sCommand.find_first_of(" :");
	if (nPos > 0)
		sCommand = sCommand.substr(0, nPos - 1);
	else
		return nDefaultTimeout_;

	std::map<std::string, int>::const_iterator pos = mpTimeoutValues_.find(
			sCommand);
	if (pos == mpTimeoutValues_.end()) {
		return nDefaultTimeout_;
	} else {
		nTimeoutValue = pos->second;
	}

	return nTimeoutValue;
}

/***********************************************************
 Name: CreateTimeoutTable

 Returns: int

 Description: Retrieves the timeout values for each API
 command and creates a list of them
 ***********************************************************/
int CommandHandling::CreateTimeoutTable() {
	char *pszTimeoutInfo = NULL;
	char szTimeoutString[] = "Info.Timeout.\0";

	mpTimeoutValues_.clear();
	memset(pchrCommand_, 0, sizeof(pchrCommand_));
	sprintf(pchrCommand_, "GET Info.Timeout.*");
	if (SendMessage(pchrCommand_, TRUE)) {
		if (!GetResponse()) {
			return 0;
		}/* if */

		if (!VerifyResponse(pchrLastReply_, TRUE))
			return 0;

		/* Parsing Timeouts */
		pchrLastReply_[strlen(pchrLastReply_) - 5] = LINE_FEED; // 4 for CRC and 1 for <CR>
		pchrLastReply_[strlen(pchrLastReply_) - 4] = 0;

		pszTimeoutInfo = pchrLastReply_;

		char *chValue, *chNext;
		while (strchr(pszTimeoutInfo, '=')) {
			pszTimeoutInfo += strlen(szTimeoutString);
			chValue = strchr(pszTimeoutInfo, '=');
			*chValue++ = 0;
			chNext = strchr(chValue, LINE_FEED);
			*chNext++ = 0;

			int a = atoi(chValue);
			mpTimeoutValues_[std::string(pszTimeoutInfo)] = a;

			pszTimeoutInfo = chNext;
		}

	} /* if */

	return 1;
}

/*****************************************************************
 Name:				SendMessage

 Inputs:
 char * Command_ - the command string, coming in.  The command
 to be sent to the System
 bool bAddCRC - if true, we add the CRC to the command and replace the
 space with the :

 Return Value:
 int -  0 if fails, 1 if passes.

 Description:
 This command takes in a command string and parses it depending
 on the value of bAddCRC.  If bAddCRC is true, we replace the
 space with a : and calculate and add the CRC to the command.
 We then send the command to the System.
 *****************************************************************/
int CommandHandling::SendMessage(char *Command_, bool bAddCRC) {
	unsigned int i;
	bool bComplete = false;

	/* Check COM port */
	if (dtCOMPort_ == NULL) {
		return bComplete;
	}/* if */

	nTimeout_ = LookupTimeout(Command_);

	/* build the command, by adding a carraige return to it and crc if specified */
	if (!BuildCommand(Command_, bAddCRC))
		return bComplete;

	if (strlen(Command_) >= (MAX_COMMAND_MSG)) {
		return bComplete;
	} /* if */
	//ROS_INFO("Sending Command: %s", Command_);
	for (i = 0; i < strlen(Command_); i++) {
		if (dtCOMPort_->SerialPutChar(Command_[i]) <= 0) {
			bComplete = false;
			break;
		} /* if */
		else if (Command_[i] == CARRIAGE_RETURN) {
			bComplete = TRUE;
			break;
		}/* if */
	} /* for */

	/*flush the COM Port...this sends out any info still sitting in the buffer*/
	dtCOMPort_->SerialFlush();
	LogToFile(0, Command_);

	return bComplete;
} /* SendMessage */

/*****************************************************************
 Name:				GetResponse

 Inputs:
 None.

 Return Value:
 int - 1 if passes, else 0

 Description:
 This routine gets the response from the system that is to be
 poled through the com port.  The routine gets it start time
 ( the time it started polling ) and continues until one of two
 things happens.  First, if the end of response (Carriage Return)
 if found the reply is complete and 1 is returned.  If the time
 it takes to get a response exceeds the timeout value, the system
 assumes no response is coming and timeouts.  The timeout dialog
 is then displayed.  Use this response routine for all calls except
 the BX call.
 *****************************************************************/
int CommandHandling::GetResponse() {
	char chChar;
	time_t currenttime, starttime;
	bool bDone = false;
	int nCount = 0, nRet = 0, nRetry = 0;

	memset(pchrLastReply_, 0, sizeof(pchrLastReply_));
	/*
	 * Get the start time that the call was initialized.
	 */
	time(&starttime);

	boost::shared_ptr<QSerialPort> serial = this->dtCOMPort_->pdtSerialPort_;

	do {
		if (serial->waitForReadyRead(nTimeout_ * 1000)) {
			// read response
			QByteArray requestData = serial->readAll();
			while (serial->waitForReadyRead(10))
				requestData += serial->readAll();
			//ROS_INFO("Response: %s", requestData.data());
			strcpy(pchrLastReply_, requestData.data());
			bDone = true;
		} else {
			nRetry++;
			if (nRetry > 3) {
				memset(pchrLastReply_, 0, sizeof(pchrLastReply_));
				// Resending the last command
				SendMessage(pchrCommand_, false); /* Command already has CRC */
			} else {
				dtSubWindowCOMPortTimeOut_.exec();
				nRet = dtSubWindowCOMPortTimeOut_.nReturnValue_;
				memset(pchrLastReply_, 0, sizeof(pchrLastReply_));

				/*
				 * if the user chooses to retry sending the command
				 * handle that here.
				 */
				if (nRet == ERROR_TIMEOUT_CONT) {
					if (strlen(pchrCommand_) > 0) {
						nRetry = 1;
						memset(pchrLastReply_, 0, sizeof(pchrLastReply_));
						/*
						 * Do not clear the Command_ at this point, since
						 * we are re-sending the same command.
						 */
						SendMessage(pchrCommand_, false); /* Command already has CRC */
						/* Reset the start time. */
					} else {
						dtCOMPort_->SerialBreak();
					} /* else */
				} else {
					ROS_ERROR("CommandHandling: Get response failed");
					return false;
				}/* else */
			}
		}
	} while (!bDone);

	return true;
	//do {
	/* Check COM port */
	//	if (dtCOMPort_ == NULL) {
	//		return false;
	//	}/* if */
	//	while ((dtCOMPort_->SerialCharsAvailable() > 0) && (!bDone)) {
	//		chChar = dtCOMPort_->SerialGetChar();
	/* if carriage return, we are done */
	//		if (chChar == '\r') {
	//			pchrLastReply_[nCount] = CARRIAGE_RETURN;
	//			pchrLastReply_[nCount + 1] = '\0';
	//			bDone = TRUE;
	//		} /* if */
	//		else {
	//			pchrLastReply_[nCount] = chChar;
	//			nCount++;
	//		} /* else */
	//	} /* while */
	//	if (!bDone) {
	/*
	 * Get the current time and compare with start time
	 * if longer "timeout" assume no response and timeout
	 */
	//	time(&currenttime);
	//	if (difftime(currenttime, starttime) >= nTimeout_) {
	/*
	 * If a COM port timeout is noted, we will try to
	 * send the command again, up to 3 times.
	 */
	//		nCount = 0;
	//		if (nRetry < 3) {
	//			nRetry++;
	//			memset(pchrLastReply_, 0, sizeof(pchrLastReply_));
	/*
	 * Do not clear the Command_ at this point, since
	 * we are re-sending the same command.
	 */
	//		SendMessage(pchrCommand_, false); /* Command already has CRC */
	/* Reset the start time. */
	//		time(&starttime);
	//	} else {
	/*
	 * If a COM port timeout is noted again, the communication
	 * error seems not recoverable and we will stop sending
	 * the command and spawns a dialog. The dialog allows
	 * the user to retry the current command, restart the application
	 * or close the application. You could eliminate this dialog and
	 * return false from this area and handle the false return
	 * directly.
	 */
	//		dtSubWindowCOMPortTimeOut_.exec();
	//		nRet = dtSubWindowCOMPortTimeOut_.nReturnValue_;
	//		memset(pchrLastReply_, 0, sizeof(pchrLastReply_));
	/*
	 * if the user chooses to retry sending the command
	 * handle that here.
	 */
	//		if (nRet == ERROR_TIMEOUT_CONT) {
	//			if (strlen(pchrCommand_) > 0) {
	//				nRetry = 1;
	//				memset(pchrLastReply_, 0, sizeof(pchrLastReply_));
	/*
	 * Do not clear the Command_ at this point, since
	 * we are re-sending the same command.
	 */
	//					SendMessage(pchrCommand_, false); /* Command already has CRC */
	/* Reset the start time. */
	//				time(&starttime);
	//			} else {
	//				dtCOMPort_->SerialBreak();
	//			} /* else */
	//			} else {
	//				ROS_ERROR("Time out when getting response ");
	//				return false;
	//			}/* else */
	//		}/* else */
	//	}/* if */
	//} /* if */
	//} while (!bDone);
//
	//LogToFile(1, pchrLastReply_);
	return 1;
} /* GetResponse */

/*****************************************************************
 Name:				GetBinaryResponse

 Inputs:
 None.

 Return Value:
 int - 1 if passes, else 0

 Description:
 This routine gets the response from the system that is to be
 poled through the com port.  The routine gets its start time
 ( the time it started polling ) and continues until one of two
 things happens.  First, if the end of response ( the number of bytes
 specified in the header is found ) the reply is complete and 1 is
 returned.  If the time it takes to get a response exceeds the timeout
 value, the system assumes no response is coming and timeouts.  The
 timeout dialog 	is then displayed.  Use this response routine for
 all calls except the BX call.
 *****************************************************************/
int CommandHandling::GetBinaryResponse() {
	char chChar;
	time_t currenttime, starttime;
	bool bDone = false;
	int nTotalBinaryLength = -1, //initialize it to a number smaller than nCount
			nCount = 0, nRet = 0, nRetry = 0;

	memset(pchrLastReply_, 0, sizeof(pchrLastReply_));

	/*
	 * Get the start time that the call was initialized.
	 */
	time(&starttime);

	do {
		/* Check COM port */
		if (dtCOMPort_ == NULL) {
			return false;
		}/* if */

		while ((dtCOMPort_->SerialCharsAvailable() > 0) && (!bDone)) {
			chChar = dtCOMPort_->SerialGetChar();

			pchrLastReply_[nCount] = chChar;

			/*
			 * Get the total length of the buffer
			 */
			if (nCount == 3) {
				/* + 7 to account for header information */
				nTotalBinaryLength = GetHex2(&pchrLastReply_[2]) + 7 + 1;
			}/* if */

			nCount++;

			if (nCount == nTotalBinaryLength) {
				bDone = TRUE;
			}/* if */
		} /* while */

		if (!bDone) {
			/*
			 * Get the current time and compare with start time
			 * if longer "timeout" assume no response and timeout
			 */
			time(&currenttime);

			if (difftime(currenttime, starttime) >= nTimeout_) {
				/*
				 * If a COM port timeout is noted, we will try to
				 * send the command again, up to 3 times.
				 */
				nCount = 0;
				if (nRetry < 3) {
					nRetry++;
					memset(pchrLastReply_, 0, sizeof(pchrLastReply_));

					/*
					 * Do not clear the Command_ at this point, since
					 * we are re-sending the same command.
					 */
					SendMessage(pchrCommand_, false); /* Command already has CRC */

					/* Reset the start time. */
					time(&starttime);
				} else {
					/*
					 * If a COM port timeout is noted again, the communication
					 * error seems not recoverable and we will stop sending
					 * the command and spawns a dialog. The dialog allows
					 * the user to retry the current command, restart the application
					 * or close the application. You could eliminate this dialog and
					 * return false from this area and handle the false return
					 * directly.
					 */
					dtSubWindowCOMPortTimeOut_.exec();
					nRet = dtSubWindowCOMPortTimeOut_.nReturnValue_;
					memset(pchrLastReply_, 0, sizeof(pchrLastReply_));

					/*
					 * if the user chooses to retry sending the command
					 * handle that here.
					 */
					if (nRet == ERROR_TIMEOUT_CONT) {
						if (strlen(pchrCommand_) > 0) {
							nRetry = 1;
							memset(pchrLastReply_, 0, sizeof(pchrLastReply_));
							/*
							 * Do not clear the Command_ at this point, since
							 * we are re-sending the same command.
							 */
							SendMessage(pchrCommand_, false); /* Command already has CRC */
							/* Reset the start time. */
							time(&starttime);
						} else {
							dtCOMPort_->SerialBreak();
						} /* else */
					} else {
						ROS_ERROR("Time out when getting binary response ");
						return false;
					}/* else */
				}/* else */
			}/* if */
		} /* if */
	} while (!bDone);

	LogToFile(1, pchrLastReply_);
	return bDone;

} /* GetBinaryResponse */

/*****************************************************************
 Name:				CheckResponse

 Inputs:
 int nReturnedValue - the value returned by VerifyResponse

 Return Value:
 int - 1 if the response is valid, 0 if the response is invalid
 or an error.

 Description:
 This routine checks the value from VerifyResponse.
 The following occurs:
 REPLY_ERROR - the response from the system was an error, we
 beep the system if required and post the error
 message ( ErrorMessage() )
 REPLY_BADCRC - a bad crc was returned with the response
 i.e. the crc returned doesn't match the one
 calculated for the response. Post a message
 REPLY_WARNING - the warning message was recieve from the system
 while intializing a tool (see API for reasons)
 post a message and beep if required.
 REPLY_INVALID - an invalid response was received from the system
 post a message
 *****************************************************************/
int CommandHandling::CheckResponse(int nReturnedValue) {
	if (nReturnedValue == REPLY_ERROR) {
		ErrorMessage();
		return 0;
	} /* if */

	if (nReturnedValue == REPLY_BADCRC) {
		ROS_ERROR("CRC Error: Bad CRC received with reply.");
		return 0;
	} /* if */

	if (nReturnedValue == REPLY_WARNING) {
		WarningMessage();
		return 1;
	} /* if */

	if (nReturnedValue == REPLY_INVALID) {
		ROS_ERROR(
				"Invalid Response: Invalid response received from the system");
		return 0;
	} /* if */

	return 1;
} /* CheckResponse */
/*****************************************************************
 Name:				VerifyResponse

 Inputs:
 char * pszReply - the reply to verify
 bool bCheckCRC - perform the CRC check on the response

 Return Value:
 int - the response that is found, defined in the APIStructures.h

 Description:    This routine checks the given response for the predetermined
 response values and returns the corresponding reply value.
 *****************************************************************/
int CommandHandling::VerifyResponse(char *pszReply, bool bCheckCRC) {
	int nResponse = 0;

	/* verify the response by comparing it with the possible responses */
	if (!strncasecmp(pszReply, "RESET", 5))
		nResponse = REPLY_RESET;
	else if (!strncasecmp(pszReply, "OKAY", 4))
		nResponse = REPLY_OKAY;
	else if (!strncasecmp(pszReply, "ERROR", 5))
		nResponse = REPLY_ERROR;
	else if (!strncasecmp(pszReply, "WARNING", 7))
		nResponse = REPLY_WARNING;
	else if (strlen(pszReply) > 0)
		nResponse = REPLY_OTHER;
	else
		return REPLY_OTHER;

	if ((nResponse & REPLY_OKAY) || ((nResponse & REPLY_OTHER) && bCheckCRC)) {
		if (!SystemCheckCRC(pszReply))
			return REPLY_BADCRC;
		else
			return nResponse;
	} /* if */
	else
		return nResponse;
} /* VerifyResponse */
/*****************************************************************
 Name:				ErrorMessage

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine loads and displays the error that
 corresponds with the reply string from the system.
 *****************************************************************/
void CommandHandling::ErrorMessage() {
	char pchErrorMessage[256], pchErrorNumber[8];
	bool bBeepOnError = false;
	int nNoErrorBeeps = 1;
	/* get the error response and display it */
	GetErrorResponse(pchrLastReply_, pchErrorMessage);
	strncpy(pchErrorNumber, pchrLastReply_, 7);
	pchErrorNumber[7] = '\0';

	ReadINIParam<bool>("Beeping Options", "Beep On Error", bBeepOnError);
	ReadINIParam<int>("Beeping Options", "No Error Beeps", nNoErrorBeeps);

	if (bBeepOnError)
		BeepSystem(nNoErrorBeeps);

	ROS_ERROR("%s %s", pchErrorMessage, pchErrorNumber);
} /* ErrorMessage */

/*****************************************************************
 Name:				WarningMessage

 Inputs:
 None.

 Return Value:
 None.

 Description:    This routine loads and displays the warning that
 corresponds with the reply string from the system.
 *****************************************************************/
void CommandHandling::WarningMessage() {
	char pchWarningMessage[256], pchWarningNumber[10];
	bool bBeepOnWarning = false;
	int nNoWarningBeeps = 1;
	std::string temp_string;

	GetErrorResponse(pchrLastReply_, pchWarningMessage);
	strncpy(pchWarningNumber, pchrLastReply_, 9);
	pchWarningNumber[9] = '\0';

	ReadINIParam<bool>("Beeping Options", "Beep On Warning", bBeepOnWarning);
	ReadINIParam<int>("Beeping Options", "No Warning Beeps", nNoWarningBeeps);

	if (bBeepOnWarning)
		BeepSystem(nNoWarningBeeps);

	ROS_ERROR("%s %s", pchWarningMessage, pchWarningNumber);

} /* ErrorMessage */

/*****************************************************************

 Name:			  LogToFile

 Inputs:			int nDirection - the direction of the message
 0 for out
 1 for in
 char * psz - the message to write to the file
 Return Value:
 None.

 Description:	this routine writes the information sent and
 received from the COM port to a file, who's name
 is defined by the user and stored in the INI file
 *****************************************************************/
void CommandHandling::LogToFile(int nDirection, char *psz) {
	int n;
	FILE *pfOut = NULL;
	time_t ltime;
	char *pszTimeStamp = NULL, szMessage[256];

	if (!bLogToFile_)
		return;

	pfOut = fopen(pchrLogFile_, "a+t");
	if (pfOut == NULL) {
		sprintf(szMessage, "The log file (%s) could not be opened.\n"
				"COM Port logging will be turned off.\n\n"
				"To reactivate this feature, please do so under\n"
				"the Options menu.", pchrLogFile_);
		bLogToFile_ = false;
		dtIniFile_.SetKeyValue("Logging Options", "Log To File", "0");
		dtIniFile_.Save(strConfigurationFile_);
		ROS_ERROR("Log File Error: %s", szMessage);
		return;
	}

	if (bDateTimeStampFile_) {
		time(&ltime);
		pszTimeStamp = ctime(&ltime);
		//pszTimeStamp = strftime(pszTimeStamp);
		do {
			putc(*pszTimeStamp, pfOut);
			pszTimeStamp++;
		} while (*pszTimeStamp);
	} /* if */

	putc(nDirection ? '<' : '>', pfOut);
	putc(' ', pfOut);

	if (!*psz) {
		psz[0] = CARRIAGE_RETURN;
	}/* if */

	/* BX reply */
	if (((psz[0] & 0xff) == 0xc4) && ((psz[1] & 0xff) == 0xa5)) {
		fprintf(pfOut, "BINARY REPLY");
	}/* if */
	else {
		for (n = 0; (n < MAX_REPLY_MSG) && (psz[n] != CARRIAGE_RETURN);
				putc(psz[n++], pfOut))
			;
	}/* else */

	putc(LINE_FEED, pfOut);
	putc(LINE_FEED, pfOut);

	fclose(pfOut);
}
/*****************************************************************

 Name:					GetErrorResponse

 Input Values:
 char
 *pszReply - the error message reply to extract
 the error number from
 Output Values:

 Return Value:
 char * pszErrorMsg - the error string found for the
 corresponding error code.

 Description:
 This routine takes the error message which is in
 form (ERRORXX) pasrses out the XX and finds the
 corresponding error message.
 *****************************************************************/
void CommandHandling::GetErrorResponse(char * pszReply, char * pszErrorMsg) {
	char chErrorToSearchFor[8], chReturnedMsg[256], cExecPath[MAX_PATH],
			*pszPathofFile;
	std::string temp_string;

	if (!strncasecmp(pszReply, "ERROR", 5)) {
		pszReply += 5;
		sprintf(chErrorToSearchFor, "0x%c%c", pszReply[0], pszReply[1]);
		temp_string = dtErrorIniFile_.GetKeyValue("Error Messages",
				chErrorToSearchFor);
		if (temp_string.empty()) {
			strcpy(chReturnedMsg, "Unknown Error");
		} else {
			strcpy(chReturnedMsg, temp_string.c_str());
		}
	} /* if */
	else if (!strncasecmp(pszReply, "WARNING", 7)) {
		pszReply += 7;
		sprintf(chErrorToSearchFor, "0x%c%c", pszReply[0], pszReply[1]);
		temp_string = dtErrorIniFile_.GetKeyValue("Warning Messages",
				chErrorToSearchFor);
		if (temp_string.empty()) {
			strcpy(chReturnedMsg,
					"A non-fatal tool error has been encountered");
		} else {
			strcpy(chReturnedMsg, temp_string.c_str());
		}
	} /* else if */
	else
		sprintf(chReturnedMsg, "Unknown Error response");

	sprintf(pszErrorMsg, "%s", chReturnedMsg);
} /* GetErrorResponse */

/*****************************************************************

 Name:				AddCRCToCommand

 Input Values:
 char
 *pszCommandString - the message to have a CRC added
 remeber, we substitute the space with a :

 Output Values:
 char *

 Return Value:
 int - 1 if succesful, 0 otherwise

 Description:
 This function adds a CRC to the end of a command
 and replaces the space with a :.  The CRC is calc'd
 using the CRC functionality found in the API
 *****************************************************************/
int CommandHandling::AddCRCToCommand(char * pszCommandString) {
	int m, n;
	unsigned int uCrc;
	bool bFirstSpace = false;

	if (strlen(pszCommandString) >= (MAX_COMMAND_MSG - 6))
		return 0;

	n = strlen(pszCommandString);
	/*
	 * determine 16 bit CRC
	 */
	uCrc = 0;
	for (m = 0; m < n; m++) {
		/*
		 * replace space character with : if sending CRC
		 * since parameter names can have spaces we need to
		 * replace only the first space with the :
		 */
		if (pszCommandString[m] == ' ' && !bFirstSpace) {
			pszCommandString[m] = ':';
			bFirstSpace = TRUE;
		}
		uCrc = CalcCrc16(uCrc, pszCommandString[m]);
	} /* for */
	sprintf(&pszCommandString[n], "%04X", uCrc);
	n += 4;

	/*
	 *Add the carriage return to the end
	 */
	return 1;
} /* AddCRCToCommand */
/*****************************************************************

 Name:				AddCRToCommand

 Input Values:
 char
 *pszCommandString - the message to have a carriage
 return added to the end
 remeber, all command need a carriage return

 Output Values:
 char *

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:
 This function adds a carriage return  to the end of
 a command
 *****************************************************************/
int CommandHandling::AddCRToCommand(char * pszCommandString) {
	int n;

	if (strlen(pszCommandString) >= (MAX_COMMAND_MSG - 1))
		return 0;

	n = strlen(pszCommandString);
	pszCommandString[n++] = CARRIAGE_RETURN;
	pszCommandString[n++] = '\0';
	return 1;
} /* AddCRToCommand */
/*****************************************************************

 Name:				BuildCommand

 Input Values:
 char *pszCommandString - the message to be built
 bool bAddCRC - whether or not to add the CRC to the command

 Output Values:
 char *

 Return Value:
 int - 1 if successful, 0 otherwise

 Description:
 This routine builds the message.  If bAddCRC is true, replace
 the space with a : and add the commands CRC to the end of it.
 *****************************************************************/
int CommandHandling::BuildCommand(char *pszCommandString, bool bAddCRC) {
	int nCnt = 0, nNumCR = 0;

	/*
	 * If the command is re-sent, it should already have a CR added.
	 */
	for (nCnt = 0; nCnt < MAX_COMMAND_MSG; nCnt++) {
		if (pszCommandString[nCnt++] == CARRIAGE_RETURN) {
			pszCommandString[nCnt++] = '\0';
			return 1;
		}/* if */
	}/* if */

	if (bAddCRC)
		if (!AddCRCToCommand(pszCommandString))
			return 0;

	if (!AddCRToCommand(pszCommandString))
		return 0;

	return 1;
} /* BuilCommand */

/*****************************************************************
 Name:			InitCrcTable

 Inputs:
 None.

 Return Value:
 None.

 Description:   Sets up CRC table for use with CalcCRC16
 Sets up static global var CrcTable
 *****************************************************************/
void CommandHandling::InitCrcTable() {
	int i, j;
	long lCrcTable;
	/*
	 * Create the CRC lookup table
	 */
	for (i = 0; i < 256; i++) {
		lCrcTable = i;
		for (j = 0; j < 8; j++)
			lCrcTable = (lCrcTable >> 1) ^ ((lCrcTable & 1) ? 0xA001L : 0);

		CrcTable[i] = (unsigned int) lCrcTable & 0xFFFF;
	} /* for */
} /* InitCrcTable */
/*****************************************************************
 Name:		    CalcCRC16

 Inputs:
 int
 data			: Data value to add to running CRC16
 unsigned int
 *puCRC16		: Ptr. to running CRC16

 Return Value:
 None.

 Description:
 This routine calcualted a running CRC16 using the polynomial
 X^16 + X^15 + X^2 + 1.

 NOTE:  This routine was taken from the back of the System API.
 *****************************************************************/
unsigned int CommandHandling::CalcCrc16(unsigned int crc, int data) {
	if (bFirst) /* if this is the first time perform this */
	{
		bFirst = 0;
		InitCrcTable();
	} /* if */
	crc = CrcTable[(crc ^ data) & 0xFF] ^ (crc >> 8);
	return (crc & 0xFFFF);
} /* CalcCRC16 */

/*****************************************************************
 Name:                   CalcCRCByLen

 Input Values:
 char *pszString : String for which CRC should be computed.
 int  nLen       : Length of string (since string is not ASCII)

 Output Values:
 None.

 Returned Value:
 unsigned        : CRC for computed for input string.

 Description:
 This routine calculates a running CRC16 using the polynomial
 X^16 + X^15 + X^2 + 1.

 *****************************************************************/
unsigned CommandHandling::CalcCRCByLen(char *pszString, int nLen) {
	static unsigned char oddparity[16] = { 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1,
			0, 1, 1, 0 };
	unsigned data, uCrc = 0;
	unsigned char *puch = (unsigned char *) pszString;
	int nCnt = 0;

	while (nCnt < nLen) {
		data = (*puch ^ (uCrc & 0xff)) & 0xff;
		uCrc >>= 8;

		if (oddparity[data & 0x0f] ^ oddparity[data >> 4]) {
			uCrc ^= 0xc001;
		} /* if */

		data <<= 6;
		uCrc ^= data;
		data <<= 1;
		uCrc ^= data;
		puch++;
		nCnt++;
	} /* while */

	return uCrc;

} /* CalcCRCByLen */

/*****************************************************************
 Name:				SystemCheckCRC

 Inputs:
 char * pointer to string to check

 Return Value:
 int - 0 if CRC failure
 1 if CRC successful

 Description:
 This command will check the System reply for the correct
 CRC value.
 *****************************************************************/
int CommandHandling::SystemCheckCRC(char *psz) {

	unsigned int uCrc = 0, uReplyCrc = 0, uReplySize = 0;

	int m, n;
	/*
	 * calculate CRC
	 */
	uCrc = 0;

	/*
	 * We need to check if the reply is for BX, in binary format.
	 * The start byte shall be 0xA5C4
	 */
	if (((psz[0] & 0xff) == 0xc4) && ((psz[1] & 0xff) == 0xa5)) {
		uReplyCrc = (psz[4] & 0xff) | ((psz[5] & 0xff) << 8); //get the header CRC

		if (CalcCRCByLen(psz, 4) == uReplyCrc) //Check the header CRC
				{
			/*
			 *  Get the reply size.
			 *  = reply size at [2] and [3] + 6 header bytes + 2 CRC bytes.
			 */
			uReplySize = ((psz[2] & 0xff) | ((psz[3] & 0xff) << 8)) + 8;

			/* Get the body CRC */
			uReplyCrc = (psz[uReplySize - 2] & 0xff)
					| ((psz[uReplySize - 1] & 0xff) << 8);

			if (CalcCRCByLen(&psz[6], (uReplySize - 8)) == uReplyCrc) // Check the CRC
					{
				return 1; /* CRC check OK */
			} else {
				return 0; /* Bad CRC */
			}/* else */
		} else {
			return 0; /* Bad CRC */
		}/* else */
	} else {
		for (n = 0; (psz[n] != CARRIAGE_RETURN) && (n < MAX_REPLY_MSG); n++) {
			; /* get total number of bytes n */
		}/* for */

		/*
		 * if rolled over the buffer size then something is wrong and
		 * we will say the CRC is bad
		 */
		if (n >= MAX_REPLY_MSG)
			return 0;

		/*
		 * NULL terminate the string to be tidy
		 */
		psz[n + 1] = 0;

		/*
		 * determine 16 bit CRC
		 */
		for (m = 0; m < (n - 4); m++)
			uCrc = CalcCrc16(uCrc, psz[m]);

		/*
		 * read CRC from message
		 */
		sscanf(&(psz[n - 4]), "%04x", &uReplyCrc);

		/*
		 * return the comparison of the calculated and received CRC values
		 */
		return (uCrc == uReplyCrc);

	}/* else */
} /* SystemCheckCrc */

/*****************************************************************
 Name:				SystemGetCRC

 Inputs:
 char * pointer to string to check

 Return Value:
 int - the CRC calculated for the string
 Description:
 This command will calc the crc for the inputed reply string
 *****************************************************************/
unsigned int CommandHandling::SystemGetCRC(char *psz, int nLength) {
	unsigned int uCrc = 0;
	int m = 0;

	for (m = 0; m < (nLength); m++) {
		uCrc = CalcCrc16(uCrc, psz[m]);
	}

	return uCrc;
}
void CommandHandling::ReadINIParam_array(std::string Section, std::string Key,
		char* array) {
	std::string temp_string;
	temp_string = dtIniFile_.GetKeyValue(Section, Key);
	strcpy(array, temp_string.c_str());
}

/**************************END OF FILE***************************/
