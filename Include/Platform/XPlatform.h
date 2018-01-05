// XPlatform.h
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <Util/Objecter.h>
#include "XDataManager.h"

class XPlatform 
	: virtual public Objecter
{
public:
	XPlatform();
	virtual ~XPlatform();

	void SetAppName(LPCTSTR lpszName);
	void SetAppPath(LPCTSTR lpszPath);
	void SetAppData(LPCTSTR lpszData);

	void SetDataManager(XDataManager* pDataManager);
	void SetLoginModule(HMODULE hModule);
	void SetIndicatorModule(HMODULE hModule);

	virtual long Init();
	virtual long Instance();
	virtual void Release();
	virtual void Term();

protected:
	XDataManager* m_pDataManager;
	HMODULE m_hIndicator;
	HMODULE m_hLogin;

protected:
	CriticalSection m_Section;
	std::map<unsigned long,Objecter*> m_mapFrame;
public:
	void SetFrame(Objecter* pFrame, unsigned long ThreadId = Thread::GetCurrentThreadId());
	Objecter* GetFrame(unsigned long ThreadId = Thread::GetCurrentThreadId());
	Objecter* GetIndicator(unsigned long ThreadId = Thread::GetCurrentThreadId());
	void BroadcastSend(Event& evt);
	void BroadcastPost(Event& evt);

protected:
	LPCTSTR GetAppName();
	LPCTSTR GetAppPath();
	LPCTSTR GetAppData();
	TCHAR m_szAppName[MAX_PATH];
	TCHAR m_szAppPath[MAX_PATH];
	TCHAR m_szAppData[MAX_PATH];

	typedef std::map<std::tstring, Markup*, std::tstringiless> Name2pMarkup;
	Name2pMarkup m_Name2pMarkup;
	Markup* OpenMarkup(LPCTSTR lpszFile);
	void CloseMarkup(LPCTSTR lpszFile);
	//public:
	virtual long WriteValue(LPCSTR lpszName, LPCSTR lpszValue, int nValueCount = 0, LPCSTR lpszSpec = NULL, LPCSTR lpszFile = NULL);
	virtual long ReadValue(LPCSTR lpszName, LPSTR lpszValue, int nValueCount, LPCSTR lpszSpec = NULL, LPCSTR lpszFile = NULL);
	virtual long WriteValue(LPCWSTR lpszName, LPCWSTR lpszValue, int nValueCount = 0, LPCWSTR lpszSpec = NULL, LPCWSTR lpszFile = NULL);
	virtual long ReadValue(LPCWSTR lpszName, LPWSTR lpszValue, int nValueCount, LPCWSTR lpszSpec = NULL, LPCWSTR lpszFile = NULL);

protected:
	virtual long OnCreateThread(CreateThreadInfoPtr& objPtr);
	virtual long OnDestroyThread(DestroyThreadInfoPtr& objPtr);

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL, OnCall)
		ON_EVT(EVT_PLAT_NOTIFY, OnNotify)
	END_EVT_MAP()

	long OnCall(Event& evt);
	long OnNotify(Event& evt);
};

extern XPlatform* _Platform;

