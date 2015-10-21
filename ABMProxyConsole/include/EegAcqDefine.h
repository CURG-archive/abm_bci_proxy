

#ifndef   __EEGACQ_DEFINE__

#define   __EEGACQ_DEFINE__





#define     MAX_NUM_ELECTRODE				24//fz,cz,po,veog,heog,ref

#define		MAX_NUM_EEGCHANNELS				24

#define     MAX_NUM_ALLCHANNELS				26 //the number of channels including time channels (X24 has 24 eeg + 2 time ch)





#define		ABM_SESSION_RAW			0	// - gives RAW and RAW PSD data

#define		ABM_SESSION_DECON		1	//- gives  all of ABM_SESSION_RAW plus  DECON and DECON PSD

#define		ABM_SESSION_BSTATE		2	//- gives all of ABM_SESSION_DECON plus BSTATE

#define		ABM_SESSION_WORKLOAD	3	//- gives all of  ABM_SESSION_BSTATE  plus WORKLOAD



#define		ABM_DEVICE_X10Standard		0

#define		ABM_DEVICE_X4APPT			1		

#define		ABM_DEVICE_X4BAlert			2

#define		ABM_DEVICE_X24Standard		3



#define		ABM_THIRD_PARTY_PORTS_NUM  3



#define		ESU_TYPE_UNKNOWN			0

#define		ESU_TYPE_DONGLE				1

#define		ESU_TYPE_SINGLE_CHANNEL		2

#define		ESU_TYPE_MULTI_CHANNEL		3





#define     IMPEDANCE_REFERENTIAL	0

#define     IMPEDANCE_DIFERENTIAL	1

#define     IMPEDANCE_NOT_AVAILABLE	2

#define     IMPEDANCE_REFERENTIAL_SECONDARY 10





// windows messages for communication between threads

#define		WM_DATARECEIVED		     WM_USER

#define		WM_COMMANDRECEIVED	    (WM_USER + 1)

#define		WM_NOTRECEIVING		    (WM_USER + 2)

#define		WM_ANSWERECEIVED		    (WM_USER + 3)

#define		WM_DEVCHANGEFREQ		    (WM_USER + 4)

#define		WM_TECHNICAL_MON_RESET	 (WM_USER + 5)

#define		WM_AMP_ABD_LINK_CHECKED	 (WM_USER + 6)

#define     WM_UPDATE_COMMUNICATION_PORTS (WM_USER + 7)

#define     WM_IMPEDANCE_MSG         (WM_USER + 8)

#define     WM_TM_FINISHED_MSG       (WM_USER + 9)

#define     WM_TM_START_MSG			 (WM_USER + 10)

#define     WM_IMPEDANCE_START_MSG	 (WM_USER + 11)





#define		SDK_WAITING_MODE           -1

#define		SDK_NORMAL_MODE            0

#define		SDK_IMPEDANCE_MODE         1

#define		SDK_TECHNICALMON_MODE      2



#define		MAX_LENGTH_CHANNEL_NAME		20



#define		TIMESTAMP_RAW				0

#define		TIMESTAMP_PSD				1

#define		TIMESTAMP_DECON				2

#define		TIMESTAMP_CLASS				3

#define		TIMESTAMP_EKG				4

#define		TIMESTAMP_PSDRAW			5

#define		TIMESTAMP_MOVEMENT			6

#define		TIMESTAMP_BANDOVERPSD		7

#define		TIMESTAMP_PSDBANDWIDTH		8

#define		TIMESTAMP_PSDBANDWIDTHRAW	9

#define		TIMESTAMP_ZSCORE			10

#define		TIMESTAMP_PULSERATE			11

#define		TIMESTAMP_FILTERED			12

#define		TIMESTAMP_RAWRAW			13

#define		TIMESTAMP_BANDOVERPSDRAW	14

#define		TIMESTAMP_RAWTILTS			15

#define		TIMESTAMP_ANGLES			16

#define		TIMESTAMP_OPTICAL			17

#define		TIMESTAMP_HAPTIC			18

#define		TIMESTAMP_QUALITY			19



#define		ESU_TIMESTAMP_LENGTH		4

#define		SYSTEM_TIMESTAMP_LENGTH		8





#endif //__EEGACQ_DEFINE__



