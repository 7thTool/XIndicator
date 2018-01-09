// XConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#if USE_PLATFORMAPI
#include <Platform/PlatformApi.h>
#elif USE_XPLATFORMAPI
#include <Platform/XPlatformApi.h>
#else
#include <Platform/XPlatform.h>
#include <Login/XLoginManager.h>
#include <Platform/XFrame.h>
#include <Indicator/XIndicator.h>
#include <Indicator/XIndicatorApi.h>
#endif//

wchar_t szAppPath[MAX_PATH] = { 0 };
wchar_t szAppData[MAX_PATH] = { 0 };

#if USE_PLATFORMAPI || USE_XPLATFORMAPI

class CPlatformSpi 
#if USE_PLATFORMAPI
	: public PlatformSpi
#elif USE_XPLATFORMAPI
	: public XPlatformSpi
#endif//
{
public:
	virtual int OnRun(bool bJoin)
	{
		printf("CPlatformSpi::OnRun\n");
#if USE_PLATFORMAPI
		PlatformApi::GetInstance()->CreateThread("MyMACD");
#elif USE_XPLATFORMAPI
		XPlatformApi::GetInstance()->CreateThread("MyMACD");
#endif//
		return __super::OnRun(bJoin);
	}

	virtual int OnRunThread()
	{
		printf("CPlatformSpi::OnRunThread\n");
		return __super::OnRunThread();
	}
};
CPlatformSpi g_Platform;

#else

#define USE_CUSTOM_XINDICATORAPI 1

#define MAX_INDICATOR_THREAD 4

#if USE_CUSTOM_XINDICATORAPI

class CCustomIndicatorSpi : public XIndicatorSpi
{
public:
};
CCustomIndicatorSpi g_Spi;

#endif//

unsigned int __stdcall IndicatorFunc(void* pParam)
{
	//定义事件loop
	EvtDispatcher theLoop;
#if USE_CUSTOM_XINDICATORAPI
	//自定义指标模块
	//XIndicatorApi::GetInstanceW(szAppPath,szAppData)->RegisterSpi(&g_Spi);
	XIndicatorApi::GetInstance()->RegisterSpi(&g_Spi);
#endif//USE_CUSTOM_XINDICATORAPI
	//定义框架模块
	XFrame Frame;
	//创建框架
	Frame.Create(NULL);

	iHandle hMyMACD = iRef("600000.SH",INDICATOR_PERIOD_DAY,_T("MyMACD"),NULL,XML_FLAG_STREAM);
	ASSERT(hMyMACD);

	//事件循环
#if 0
	system("pause");
#else
	theLoop.Run();
#endif//

	if (hMyMACD) {
		iRelease(hMyMACD);
		hMyMACD = NULL;
	}

	//销毁框架
	Frame.Destroy();
#if USE_CUSTOM_XINDICATORAPI
	//释放指标模块,Frame会自动释放，当然主动调用也不会出问题
	XIndicatorApi::ReleaseInstance();
#endif//USE_CUSTOM_XINDICATORAPI

	return 0;
}

#endif//
#if USE_PLATFORMAPI || USE_XPLATFORMAPI
DWORD WINAPI ThreadFunc(LPVOID lpParam)
#else
unsigned int __stdcall ThreadFunc(void* pParam)
#endif//
{
	int i;
	HMODULE hModule = GetModuleHandleW(NULL);
	wchar_t szPath[_MAX_PATH] = { 0 };
	::GetModuleFileNameW(hModule, szPath, _MAX_PATH);

	wchar_t szAppDrive[_MAX_DRIVE] = { 0 };
	wchar_t szAppDir[_MAX_DIR] = { 0 };
	wchar_t szAppName[_MAX_FNAME] = { 0 };
	wchar_t szAppExt[_MAX_EXT] = { 0 };
	_wsplitpath(szPath, szAppDrive, szAppDir, szAppName, szAppExt);

	//wchar_t szAppPath[_MAX_PATH] = { 0 };
	_snwprintf(szAppPath, _MAX_PATH, _T("%s%s"), szAppDrive, szAppDir);
	::PathRemoveBackslashW(szAppPath);

	//wchar_t szAppData[MAX_PATH] = { 0 };
	::SHGetSpecialFolderPathW(NULL, szPath, CSIDL_APPDATA, TRUE);
	_sntprintf(szAppData, _MAX_PATH, _T("%s\\%s"), szPath, szAppName);
	::SHCreateDirectoryExW(NULL, szAppData, NULL);

	char szAppNameA[_MAX_FNAME] = { 0 };
	char szAppPathA[_MAX_PATH] = { 0 };
	char szAppDataA[_MAX_PATH] = { 0 };
	wcstombs(szAppNameA, szAppName, _MAX_FNAME);
	wcstombs(szAppPathA, szAppPath, _MAX_PATH);
	wcstombs(szAppDataA, szAppData, _MAX_PATH);

#if USE_PLATFORMAPI
	PlatformApi* pApi = PlatformApi::GetInstance();
	if(pApi) {
		pApi->RegisterSpi(&g_Platform);
		pApi->Init(szAppNameA,szAppPathA,szAppDataA);
		pApi->Run();
		pApi->Term();
	}
#elif USE_XPLATFORMAPI
	XPlatformApi* pApi = XPlatformApi::GetInstance();
	if(pApi) {
		pApi->RegisterSpi(&g_Platform);
		pApi->Init(szAppNameA,szAppPathA,szAppDataA);
		pApi->Login("","");
		pApi->Run();
		pApi->Term();
	}
#else
	printf(
		"\
/******************************************************************************\\\n\
 %s\n\
 %s\n\
 %s\n\
\\******************************************************************************/\n\
"
, szAppNameA, szAppPathA, szAppDataA);

	//定义事件loop
	EvtDispatcher theLoop;

	//定义平台
	XPlatform Plat;

	//初始化平台

	_Platform->SetAppName(szAppName);
	_Platform->SetAppPath(szAppPath);
	_Platform->SetAppData(szAppData);

	_Platform->Init();

	//初始化网络层
	char szNetXml[1024] = { 0 };
	sprintf((char*)szNetXml, "<root workdir=\"%s\" datadir=\"%s\"><module name=\"QNetModule.dll\"></module></root>", szAppPathA, szAppDataA);
	printf("Start NetIOEngine:\n%s\n", szNetXml);
	_NetIOEngine->Start((char*)szNetXml);
	printf("Start NetIOEngine OK.\n");

	//初始化数据层
	char szDEXml[1024] = { 0 };
	sprintf((char*)szDEXml, "<root workdir=\"%s\" datadir=\"%s\"><module name=\"QDataModule.dll\"></module><module name=\"CTPTrader.dll\"></module></root>", szAppPathA, szAppDataA);
	printf("Start DataEngine:\n%s\n", szDEXml);
	_DataEngine->Start(szDEXml);
	printf("Start DataEngine OK.\n");

	_Platform->SetDataManager(new XDataManager);

	//初始化指标系统
	TCHAR szIndicatorPath[MAX_PATH] = { 0 };
	_tmakepath(szIndicatorPath, NULL, szAppPath, _T("XIndicator.dll"), NULL);
	//iLogW(LOGLEVEL_INFO,szIndicatorPath);
	_Platform->SetIndicatorModule(LoadLibrary(szIndicatorPath));

	//平台运行
	_Platform->Instance();

	//定义登录模块
	XLoginManager Login;

	//登录运行
	_LoginMgr->Instance();

	_LoginMgr->PostEvent(EVT_PLAT_CALL, MAKEVALUE(MCALL_PLAT_LOGIN, CCALL_LOGIN_LOGIN), 0);

	//创建指标线程池
	Thread thrd[MAX_INDICATOR_THREAD];
	for(i=0; i<MAX_INDICATOR_THREAD; i++)
	{
		thrd[i].CreateThread(IndicatorFunc, NULL);
	}

	//事件循环
#if 0
	system("pause");
#else
	theLoop.Run();
#endif//

	//释放指标线程池
	for(i=0; i<MAX_INDICATOR_THREAD; i++)
	{
		EvtDispatcher* pThrdDispatcher = EvtDispatcher::GetEvtDispatcher(thrd[i].GetThreadId());
		if (pThrdDispatcher) {
			pThrdDispatcher->PostQuitEvent();
		}
		thrd[i].StopThread();
	}

	//释放登录模块
	_LoginMgr->Release();

	//停止平台
	_Platform->Release();

	//停止数据层
	_DataEngine->Stop();

	//停止网络层
	_NetIOEngine->Stop();

	//销毁平台
	_Platform->Term();
#endif//

	return 0;
}

int Run()
{
#if USE_PLATFORMAPI || USE_XPLATFORMAPI
	HANDLE hThread = ::CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

	getchar();
#if USE_PLATFORMAPI
	if(PlatformApi::IsInstanced()) {
		PlatformApi::GetInstance()->PostQuit();
	}
#else
	if(XPlatformApi::IsInstanced()) {
		XPlatformApi::GetInstance()->PostQuit();
	}
#endif//
	DWORD dwRet = ::WaitForSingleObject(hThread, INFINITE);
	if (dwRet == WAIT_TIMEOUT || dwRet == WAIT_FAILED) {
		::TerminateThread(hThread, -1);
	}
	::CloseHandle(hThread);
	hThread = NULL;
#if USE_PLATFORMAPI
	if (PlatformApi::IsInstanced()) {
		PlatformApi::ReleaseInstance();
	}
#else
	if (XPlatformApi::IsInstanced()) {
		XPlatformApi::ReleaseInstance();
	}
#endif//
#else
	//初始化XLib
	XLibInit::Init();

	Thread thrd;

	thrd.CreateThread(ThreadFunc, NULL);

	//thrd.Join();
	//system("pause");
	getchar();

	EvtDispatcher* pThrdDispatcher = EvtDispatcher::GetEvtDispatcher(thrd.GetThreadId());
	if (pThrdDispatcher) {
		pThrdDispatcher->PostQuitEvent();
	}
	thrd.StopThread();
	
	//释放XLib
	XLibInit::Release();
#endif//

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return Run();
	return 0;
}

