// The following ifdef block is the standard way of creating macros which make exporting 

// from a DLL simpler. All files within this DLL are compiled with the FFFFFF_EXPORTS

// symbol defined on the command line. this symbol should not be defined on any project

// that uses this DLL. This way any other project whose source files include this file see 

// FFFFFF_API functions as being imported from a DLL, whereas this DLL sees symbols

// defined with this macro as being exported.

#ifdef ATHENA_EXPORTS

#define ATHENA_API __declspec(dllexport)

#else

#define ATHENA_API __declspec(dllimport)

#endif



#include "TypeDef.h"



ATHENA_API _DEVICE_INFO*  __stdcall  GetConnectedDevices(int& );



ATHENA_API int  __stdcall  StartAcquisition();



 

ATHENA_API int  __stdcall  StopAcquisition();

 

ATHENA_API int  __stdcall  InitiateSession(_SESSION_INFO* pSessionInfo, _DEVICE_INFO* pDeviceInfo = NULL);



ATHENA_API int  __stdcall  InitSession(int DeviceType,int SessionType,int nSelectedDeviceHandle, BOOL bPlayEBS );



ATHENA_API int  __stdcall  CheckImpedances(void (__stdcall *pFunc)(ELECTRODE*, int&), _DEVICE_INFO* pDeviceInfo = NULL );

ATHENA_API int __stdcall  CheckSelectedImpedances(void (__stdcall *pFunc)(ELECTRODE* pEl, int& nCount), char **pszChannelNames, int nNmbElectrodeToMeasure, int nSamplesForMeasuring=0);



ATHENA_API _BRAIN_STATE*  __stdcall  GetBrainState(int& ); 



ATHENA_API float*  __stdcall  GetRawData(int&);



ATHENA_API float*  __stdcall  GetDeconData(int& );



ATHENA_API int  __stdcall  GetQualityData(int& );



ATHENA_API float*  __stdcall  GetQualityChannelData(int& );



ATHENA_API float*  __stdcall  GetPSDData(int& );



ATHENA_API float*  __stdcall  GetMovementData(int& );



ATHENA_API float*  __stdcall  GetPSDDataraw(int& );



ATHENA_API float*  __stdcall  GetBandOverallPSDData(int& nCountPackages, int& nPackageSize);



ATHENA_API float*  __stdcall  GetBandOverallPSDRawData(int& nCountPackages, int& nPackageSize);



ATHENA_API float*  __stdcall  GetPSDBandwidthData(int& nCountPackages, int& nPackageSize);



ATHENA_API float*  __stdcall  GetPSDBandwidthRawData(int& nCountPackages, int& nPackageSize);



ATHENA_API int __stdcall  GetPSDCountBands(int& nCountBandwidths, int& nCountBandwidthsOverall );



ATHENA_API int  __stdcall  InitZScoreData( char* sZScoreSourceList );



ATHENA_API int  __stdcall  ResetZScoreData( char* sNewZScoreSourceList );



ATHENA_API int  __stdcall  ReleaseZScoreData();



ATHENA_API float*  __stdcall  GetZScoreData(int& nCountPackages, int& nPackageSize);



ATHENA_API _DEVICE_INFO*  __stdcall  GetDeviceInfo(_DEVICE_INFO* pDeviceInfo = NULL);



ATHENA_API _DEVICE_INFO*  __stdcall  GetDeviceInfoByID(char* chDeviceInstanceID);



ATHENA_API _ESU_PORT_INFO* __stdcall  GetESUPortInfo();



ATHENA_API int  __stdcall SaveESUPortInfo(_ESU_PORT_INFO* pESUPortInfo);



ATHENA_API int   __stdcall  PauseAcquisition();



ATHENA_API int   __stdcall  ResumeAcquisition();



ATHENA_API int   __stdcall  StopImpedance();



ATHENA_API int   __stdcall  TechnicalMonitoring(void (__stdcall *pFunc)(CHANNEL_INFO*, int&), int nSeconds, _DEVICE_INFO* pDeviceInfo = NULL);



ATHENA_API int   __stdcall  ShowChannel(int nChannel, 

                                        DWORD rgbBackground,

                                        DWORD rgbSignal,

                                        DWORD rgbTitle,

                                        DWORD rgbAxes,

                                        DWORD rgbGuidlines,

                                        DWORD rgbAxesValues,

                                        float fGain,

                                        int   nTimeScale

                                        );



ATHENA_API int   __stdcall  AlignChannels();



ATHENA_API unsigned char*  __stdcall  GetThirdPartyData(int& );



ATHENA_API unsigned char*  __stdcall  GetTimeStampsStreamData(int nType);



ATHENA_API int   __stdcall  SetArtifactsCallbackFuncs(void (__stdcall *pFuncEB)(int epstart, int offstart,  float shour, float sminute, float ssecond, float smili , int epend, int offend,  float ehour, float eminute, float esecond, float emili), 

															  void (__stdcall *pFuncExc)(int indexch,int epstart, int offstart,  float shour, float sminute, float ssecond, float smili, int epend, int offend, float ehour, float eminute, float esecond, float emili),

															  void (__stdcall *pFuncSat)(int indexch,int epstart, int offstart,  float shour, float sminute, float ssecond, float smili, int epend, int offend, float ehour, float eminute, float esecond, float emili),

															  void (__stdcall *pFuncSpk)(int indexch, int epstart,  int offstart,  float shour, float sminute, float ssecond, float smili, int epend, int offend, float ehour, float eminute, float esecond, float emili),

															  void (__stdcall *pFuncEMG)(int indexch,int epstart, int offstart,  float shour, float sminute, float ssecond, float smili, int epend, int offend, float ehour, float eminute, float esecond, float emili));



ATHENA_API int __stdcall RegisterCallbackOnError(void (__stdcall *pFunc)(int));



ATHENA_API int __stdcall RegisterCallbackOnStatusInfo(void (__stdcall *pFunc)(_STATUS_INFO*));



ATHENA_API int __stdcall RegisterCallbackImpedanceElectrodeFinished(void (__stdcall *pFunc)(int, float));



ATHENA_API int __stdcall RegisterCallbackImpedanceElectrodeFinishedA(void (__stdcall *pFunc)(char*, float));



ATHENA_API int __stdcall RegisterCallbackDataArrived(void (__stdcall *pFunc)(int));



ATHENA_API int __stdcall RegisterCallbackMissedBlocks(void (__stdcall *pFunc)(int, int));



ATHENA_API int __stdcall StopTechnicalMonitoring();



ATHENA_API float*  __stdcall  GetEKGData(int& );



ATHENA_API float*  __stdcall  GetPulseRateData(int& );



ATHENA_API float* __stdcall  GetHapticData(int& nCount);



ATHENA_API float*  __stdcall  GetOpticalData(int&);



ATHENA_API int  __stdcall  SetMarker(int epoch, int offset, int val);



ATHENA_API int  __stdcall  SetMarkerWithComment(int epoch, int offset, int val, char* comment);



//play ebs mode functions



ATHENA_API BOOL __stdcall PlayInEbsModeDataAll(float* pEegData, int nSamples, WORD* pOpticalData, int nOpticalSamples, int* nTiltData, int nTiltSamples, short* pHapticData, int nHapticDataSamples);



ATHENA_API BOOL    __stdcall  PlayInEbsModeData(float* data, int nSamples );



ATHENA_API BOOL    __stdcall  PlayInEbsModeDataWithTilt(float* data, int* nTiltData, int nSamples, int nTiltSamples);





ATHENA_API _EXTERN_CALC_TABLE_NAME*   __stdcall  GetMapCalcChannels( int& nSize );



ATHENA_API void    __stdcall  StopPlayEbsData();

 



ATHENA_API float* __stdcall  GetQualityChannelData(int& nCount);



ATHENA_API int __stdcall  GetQualityData(int& nCount);



// Differential or referential channels

ATHENA_API int __stdcall GetChannelConnectorType(int channelIndex);





ATHENA_API int __stdcall GetElectrodes(_SESSION_INFO* pSessionInfo,_ELECTRODE** ptrElectrodes, int& nNumElectrodes);



ATHENA_API int __stdcall GetCurrentSDKMode();

ATHENA_API int __stdcall GetMissedBlocks();



ATHENA_API int  __stdcall  InitiatePlaybackSession(_SESSION_INFO* pSessionInfo, int nDeviceType, _DEVICE_INFO* pDeviceInfo, BOOL bTilt);



ATHENA_API float*  __stdcall  GetRawRawData(int&);



ATHENA_API float*  __stdcall  GetFilteredData(int&);



ATHENA_API float* __stdcall  GetTiltRawData(int& nCount);



ATHENA_API float* __stdcall  GetTiltAnglesData(int& nCount);



ATHENA_API int __stdcall SetDefinitionFile(char* pDefinitionFile);



ATHENA_API int __stdcall SetDestinationFile(char* pDestinationFile);



ATHENA_API int __stdcall SendBytes(int nDeviceHandle, unsigned char* pBytes, int nBytes,int nRetry, int nPause, int bCloseConnection);



ATHENA_API int __stdcall SetAttribute(int nType,int nValue);



ATHENA_API int __stdcall GetBatteryLevel(float &fBatteryLevel, int &nBatteryPercentage);



ATHENA_API int __stdcall GetPacketChannelNmbInfo(int& nRawPacketChannelsNmb, int& nDeconPacketChannelsNmb,  int& nPSDPacketChannelsNmb, int& nRawPSDPacketChannelNmb, int& nQualityPacketChannelNmb);



ATHENA_API int __stdcall GetChannelMapInfo( _CHANNELMAP_INFO & stChannelMapInfo);



ATHENA_API int __stdcall GetEEGChannelsInfo( _EEGCHANNELS_INFO & stEEGChannelsInfo);



ATHENA_API int __stdcall GetTimestampType();

