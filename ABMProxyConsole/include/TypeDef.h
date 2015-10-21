

#ifndef  __TD_DEFINE__

#define  __TD_DEFINE__





#define   __ESU_TIME_STAMP_LENGTH	4

#define   __SYS_TIME_LENGTH			8

#define   ABM_MAX_CONNECTED_DEVICES 10



#include "EegAcqDefine.h"



#pragma pack (1)





typedef struct TD_ELECTRODE{

   char  chName[20]; //name of electrode

   BOOL  bImpedance; //if impedance is well (low)

   float fImpedanceValue; //value of impedance

}ELECTRODE;



typedef struct TD_CHANNEL_INFO{

   char  chName[20]; //name of electrode

   BOOL  bTechnicalInfo; //if impedance is well (low)

}CHANNEL_INFO;



typedef struct TD_DEVICE_INFO{

   char  chDeviceName[256];//device's name

   int   nCommPort; // comm port 

   int   nECGPos; //ecg position

   int   nNumberOfChannel; //number of channel

   int   nESUType; //type of connecting device

   int   nTymestampType; // type of timestamp

   int   nDeviceHandle; // handle to identify device   

   char  chDeviceID[MAX_PATH]; // ESU/dongle port device ID

}_DEVICE_INFO;



typedef struct TD_STATUS_INFO{

	float BatteryVoltage;

	int BatteryPercentage;

	//int Temperature;

	int Timestamp;

	int TotalMissedBlocks;   

	int ABMSDK_Mode;

	int LastErrorCode;

	int CustomMarkA;

	int CustomMarkB;

	int CustomMarkC;

	int CustomMarkD;

	int nTotalSamplesReceived;

}_STATUS_INFO;



//CWPC

typedef struct TD_BRAIN_STATE{

   float    fEpoch;

   float    fABMSDKTimeStampHour;//time stamp

   float    fABMSDKTimeStampMinute;//time stamp

   float    fABMSDKTimeStampSecond;//time stamp

   float    fABMSDKTimeStampMilsecond;//time stamp

   float 	fClassificationEstimate; //information about classification

   float 	fHighEngagementEstimate; //information about high-engagement

   float 	fLowEngagementEstimate; //information about low-engagement

   float 	fDistractionEstimate; //information about distraction

   float 	fDrowsyEstimate; //information about drowsy

   float 	fWorkloadFBDS; //information about FBDS workload

   float 	fWorkloadBDS; //information about BDS workload

   float 	fWorkloadAverage; //information about workload average

}_BRAIN_STATE;



typedef struct TD_SESSION_INFO{

	char  	chDefinitionPath[1024]; //full path of definition file (only needed for GetBrainState)

	char  	chDestionationPath[1024]; //full path for destination(ebs) file 

	DWORD    wRawChannels; //markers for which channel raw data need to be provided;// LSB used for first channel...if the corresponding bit is 1, raw data will be provided for that channel

	DWORD    wDecChannels; //markers for which channel dec data need to be provided;// LSB used for first channel...if the corresponding bit is 1, raw data will be provided for that channel

	DWORD    wPsdChannels; //markers for which channel PSD need to be calculated;// LSB used for first channel...if the corresponding bit is 1, PSD will be calculated for that channel

	DWORD    dwPSD[MAX_NUM_EEGCHANNELS][4];//markers for 128 bins for one channel. LSB is marker for 1Hz bin…

	char     chName[MAX_NUM_EEGCHANNELS][MAX_LENGTH_CHANNEL_NAME];//[in]the name of channels max 20 characters

	int     inputPinPositive[MAX_NUM_EEGCHANNELS];// holds positive pin asignment for each channel

	int     inputPinNegative[MAX_NUM_EEGCHANNELS];// holds negative pin asignment for each channel (not used for referential)

	int     channelImpedanceType[MAX_NUM_EEGCHANNELS];// IMPEDANCE_REFERENTIAL 0, IMPEDANCE_DIFERENTIAL 1, IMPEDANCE_NOT_AVAILABLE	2

	BOOL	bApply65HzFilter; // not used (should be removed)

	BYTE      bBrainState; // markers for (classification, high-engagement, low-engagement, distraction, drowsy, workload

	BYTE      bPlayEbsMode; // play ebs mode	

}_SESSION_INFO;   



typedef struct TD_ELECTRODES_INFO{	

	int     nNumElectrodes;

	int     nStabilization;

	int     nAgregationsSamples;

	int     nCurrentType;

	char    cElName[MAX_NUM_ELECTRODE][MAX_LENGTH_CHANNEL_NAME];//[in]the name of electrode max 20 characters

	int     nElCommand[MAX_NUM_ELECTRODE];// Impedance command to be sent for this electrode to be measured

	int     nElChannel[MAX_NUM_ELECTRODE];// EEG channel to be used when measuring electrode

	int     nElReferentialElectrode[MAX_NUM_ELECTRODE];// Electrode to be used when substracting ref el. (-1 for none)

}_ELECTRODES_INFO;   



typedef struct TD_EEGCHANNELS_INFO{

	char    cChName[MAX_NUM_EEGCHANNELS][MAX_LENGTH_CHANNEL_NAME];//[in]the name of channels max 20 characters

	BOOL    bChUsed[MAX_NUM_EEGCHANNELS];// whether channel is used or not		

	BOOL    bChUsedInQualityData[MAX_NUM_EEGCHANNELS];// whether channel is used or not for quality

	BOOL	bChCanBeDecontaminated[MAX_NUM_EEGCHANNELS];

	BOOL	bIsChEEG[MAX_NUM_EEGCHANNELS];

}_EEGCHANNELS_INFO;   



typedef struct TD_AUXDATA_INFO{	

	BOOL	bIred;

	BOOL	bRed;

	BOOL	bTilt;

	int 	nEcgIndex;	

	BOOL	bMic;

	BOOL	bHaptic;

}_AUXDATA_INFO;   



typedef struct TD_HARDWARE_INFO{	

	int nBatteryMax; //millivolts

	int nBatteryMin; //millivolts	

	int nTiltLinearTransformA;

	int nTiltLinearTransformB;

}_HARDWARE_INFO;   





typedef struct TD_SESSIONTYPES_INFO{	

	BOOL	bDecon; //whether decontamination is supported or not

	BOOL	bBalert;//whether b-alert classification is supported or not

	BOOL	bWorkload;	//whether workload calculation is supported or not

}_SESSIONTYPES_INFO;   



typedef struct TD_CHANNELMAP_INFO{

	int nDeviceTypeCode;

	int nSize;

	_EEGCHANNELS_INFO stEEGChannels;

	_ELECTRODES_INFO stElectrodes;	

	_AUXDATA_INFO stAuxData;

	_HARDWARE_INFO stHardwareInfo;

	_SESSIONTYPES_INFO stSessionTypes;	

}_CHANNELMAP_INFO;   





typedef struct TD_SESSION_INFO_PE{

	int nNumberOfChannels;

	int nEKG;

	BOOL	bApply65HzFilter;

	char chName[MAX_NUM_EEGCHANNELS][MAX_LENGTH_CHANNEL_NAME];//[in]the name of channels max 20 characters

}_SESSION_INFO_PE;



typedef union __ESU_TIME_STAMP{

   float  time_ms;

   BYTE   pByteStream[__ESU_TIME_STAMP_LENGTH];

}_ESU_TIME_STAMP;



typedef struct __EXTERN_CALC_TABLE_NAME{

	int     iRealIndex;		//index into block

	int     iIndex;         //index into calculated block

	int     iCalcIndex1;	//real index from real block of data

	int     iCalcIndex2;	//real index from real block of data

}_EXTERN_CALC_TABLE_NAME;



// REFCOM moved struct to typedef.h

typedef struct __BALERT_DATA_INFO{

	int                  nPlayedSamples;	// samples already in channels

	int                  nNotReceiving;		// elapsed time in milliseconds when nothing is received from device

	int                  nTotalSeconds;		// total number of seconds in EBS file

	int                  nFirstSecond;		// first second in stream and buffers

	int                  nActiveSecond;		// active second = slider position for EBS file

	void*	      pActivTable;	// pointer to active table

	int                  nActiveScreen;//which screen is presented	

} _BALERT_DATA_INFO;



typedef struct __ELECTRODE{

	char    elName[50];

	int     nHirose;//hirose plug-in

	int     nSwitch;//switch which need to press

	int     nChannel;//where that electrode will be seen on screen

	int     nSubChannel;//what channel we need to substract to get correct values 

	int     nSubEl;//what electrode we need to substract to get correct values 

	float   fImpedance;

	int     nNumberOfSaturation;//how many times saturation found on this electrode

}_ELECTRODE;



typedef struct __ESU_PORT_INFO{

	int   nESU_TYPE;	 // UNKNOWN - 0, DONGLE - 1,SINGLE_CH 2,MULTI_CH - 3

	int   bWired; // Wired - 1, Wireless - 0

	int   nSerialPortType[ABM_THIRD_PARTY_PORTS_NUM];

	int   nParalelPortType;

	int   bIsRegularConfig; // Regular - 1, Irregular - 0

	char BDA[13];

} _ESU_PORT_INFO;







#pragma pack()





#endif //__TD_DEFINE__

