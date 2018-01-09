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
	//�����¼�loop
	EvtDispatcher theLoop;
#if USE_CUSTOM_XINDICATORAPI
	//�Զ���ָ��ģ��
	//XIndicatorApi::GetInstanceW(szAppPath,szAppData)->RegisterSpi(&g_Spi);
	XIndicatorApi::GetInstance()->RegisterSpi(&g_Spi);
#endif//USE_CUSTOM_XINDICATORAPI
	//������ģ��
	XFrame Frame;
	//�������
	Frame.Create(NULL);

	iHandle hMyMACD = iRef("600000.SH",INDICATOR_PERIOD_DAY,_T("MyMACD"),NULL,XML_FLAG_STREAM);
	ASSERT(hMyMACD);

	//�¼�ѭ��
#if 0
	system("pause");
#else
	theLoop.Run();
#endif//

	if (hMyMACD) {
		iRelease(hMyMACD);
		hMyMACD = NULL;
	}

	//���ٿ��
	Frame.Destroy();
#if USE_CUSTOM_XINDICATORAPI
	//�ͷ�ָ��ģ��,Frame���Զ��ͷţ���Ȼ��������Ҳ���������
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

	//�����¼�loop
	EvtDispatcher theLoop;

	//����ƽ̨
	XPlatform Plat;

	//��ʼ��ƽ̨

	_Platform->SetAppName(szAppName);
	_Platform->SetAppPath(szAppPath);
	_Platform->SetAppData(szAppData);

	_Platform->Init();

	//��ʼ�������
	char szNetXml[1024] = { 0 };
	sprintf((char*)szNetXml, "<root workdir=\"%s\" datadir=\"%s\"><module name=\"QNetModule.dll\"></module></root>", szAppPathA, szAppDataA);
	printf("Start NetIOEngine:\n%s\n", szNetXml);
	_NetIOEngine->Start((char*)szNetXml);
	printf("Start NetIOEngine OK.\n");

	//��ʼ�����ݲ�
	char szDEXml[1024] = { 0 };
	sprintf((char*)szDEXml, "<root workdir=\"%s\" datadir=\"%s\"><module name=\"QDataModule.dll\"></module><module name=\"CTPTrader.dll\"></module></root>", szAppPathA, szAppDataA);
	printf("Start DataEngine:\n%s\n", szDEXml);
	_DataEngine->Start(szDEXml);
	printf("Start DataEngine OK.\n");

	_Platform->SetDataManager(new XDataManager);

	//��ʼ��ָ��ϵͳ
	TCHAR szIndicatorPath[MAX_PATH] = { 0 };
	_tmakepath(szIndicatorPath, NULL, szAppPath, _T("XIndicator.dll"), NULL);
	//iLogW(LOGLEVEL_INFO,szIndicatorPath);
	_Platform->SetIndicatorModule(LoadLibrary(szIndicatorPath));

	//ƽ̨����
	_Platform->Instance();

	//�����¼ģ��
	XLoginManager Login;

	//��¼����
	_LoginMgr->Instance();

	_LoginMgr->PostEvent(EVT_PLAT_CALL, MAKEVALUE(MCALL_PLAT_LOGIN, CCALL_LOGIN_LOGIN), 0);

	//����ָ���̳߳�
	Thread thrd[MAX_INDICATOR_THREAD];
	for(i=0; i<MAX_INDICATOR_THREAD; i++)
	{
		thrd[i].CreateThread(IndicatorFunc, NULL);
	}

	//�¼�ѭ��
#if 0
	system("pause");
#else
	theLoop.Run();
#endif//

	//�ͷ�ָ���̳߳�
	for(i=0; i<MAX_INDICATOR_THREAD; i++)
	{
		EvtDispatcher* pThrdDispatcher = EvtDispatcher::GetEvtDispatcher(thrd[i].GetThreadId());
		if (pThrdDispatcher) {
			pThrdDispatcher->PostQuitEvent();
		}
		thrd[i].StopThread();
	}

	//�ͷŵ�¼ģ��
	_LoginMgr->Release();

	//ֹͣƽ̨
	_Platform->Release();

	//ֹͣ���ݲ�
	_DataEngine->Stop();

	//ֹͣ�����
	_NetIOEngine->Stop();

	//����ƽ̨
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
	//��ʼ��XLib
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
	
	//�ͷ�XLib
	XLibInit::Release();
#endif//

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return Run();
	return 0;
}

