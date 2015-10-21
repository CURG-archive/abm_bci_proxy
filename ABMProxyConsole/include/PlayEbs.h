// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PLAYEBS_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PLAYEBS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PLAYEBS_EXPORTS
#define PLAYEBS_API __declspec(dllexport)
#else
#define PLAYEBS_API __declspec(dllimport)
#endif

#include "TypeDef.h"



PLAYEBS_API BOOL Open(char* sFullPath, char* definitionfile);

PLAYEBS_API BOOL OpenCustom(char* sFullPath, _SESSION_INFO* pSessionInfo, int nDeviceType);

PLAYEBS_API _SESSION_INFO_PE*  __stdcall  GetSessionInfo();

PLAYEBS_API BOOL PlayFile(double nPauseInMiliseconds = 78.125 );

PLAYEBS_API void Close();

PLAYEBS_API void Pause();

PLAYEBS_API void Resume();

//get functions
PLAYEBS_API _BRAIN_STATE*  __stdcall  GetBrainStatePE(int& );

PLAYEBS_API float*  __stdcall  GetRawDataPE(int&);

PLAYEBS_API float*  __stdcall  GetRawRawDataPE(int&);

PLAYEBS_API float*  __stdcall  GetFilteredDataPE(int&);

PLAYEBS_API float*  __stdcall  GetDeconDataPE(int& );

PLAYEBS_API float*  __stdcall  GetQualityChannelDataPE(int& );

PLAYEBS_API float*  __stdcall  GetPSDDataPE(int& );

PLAYEBS_API float*  __stdcall  GetPSDDatarawPE(int& );

PLAYEBS_API float*  __stdcall  GetEKGDataPE(int& );

PLAYEBS_API float*  __stdcall  GetPulseRateDataPE(int& );

PLAYEBS_API float*  __stdcall  GetMovementDataPE(int& );

PLAYEBS_API float*  __stdcall  GetRawTiltDataPE(int& );

PLAYEBS_API float*  __stdcall  GetAnglesDataPE(int& );

PLAYEBS_API int  __stdcall  InitZScoreDataPE( char* );

PLAYEBS_API float*  __stdcall  GetZScoreDataPE(int&, int& );

PLAYEBS_API float* __stdcall  GetHapticDataPE(int& nCount);

PLAYEBS_API float* __stdcall  GetOpticalDataPE(int& nCount);

PLAYEBS_API int   __stdcall  ShowChannelPE(int nChannel, 
										DWORD rgbBackground,
										DWORD rgbSignal,
										DWORD rgbTitle,
										DWORD rgbAxes,
										DWORD rgbGuidlines,
										DWORD rgbAxesValues,
										float fGain,
										int   nTimeScale
										);

PLAYEBS_API int   __stdcall  SetArtifactsCallbackFuncsPE(void (__stdcall *pFuncEB)(int epstart, int offstart,  float shour, float sminute, float ssecond, float smili , int epend, int offend,  float ehour, float eminute, float esecond, float emili), 
													  void (__stdcall *pFuncExc)(int indexch,int epstart, int offstart,  float shour, float sminute, float ssecond, float smili, int epend, int offend, float ehour, float eminute, float esecond, float emili),
													  void (__stdcall *pFuncSat)(int indexch,int epstart, int offstart,  float shour, float sminute, float ssecond, float smili, int epend, int offend, float ehour, float eminute, float esecond, float emili),
													  void (__stdcall *pFuncSpk)(int indexch, int epstart,  int offstart,  float shour, float sminute, float ssecond, float smili, int epend, int offend, float ehour, float eminute, float esecond, float emili),
													  void (__stdcall *pFuncEMG)(int indexch,int epstart, int offstart,  float shour, float sminute, float ssecond, float smili, int epend, int offend, float ehour, float eminute, float esecond, float emili));

