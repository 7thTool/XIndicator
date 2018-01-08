#ifndef _H_XLoginGuarder_H_
#define _H_XLoginGuarder_H_

#include <Util/ObjecterMap.h>

class XLoginGuarder 
	: virtual public Objecter
{
	typedef XLoginGuarder This;
public:
	XLoginGuarder();
	~XLoginGuarder();

	long Init();
	void Release();

	LPCTSTR GetAppPath();
	LPCTSTR GetAppData();
	LPCTSTR GetLoginPath();
	LPCTSTR GetLoginData();

protected:
	TCHAR m_szAppPath[MAX_PATH];
	TCHAR m_szDataPath[MAX_PATH];
	TCHAR m_szLoginPath[MAX_PATH];
	TCHAR m_szLoginData[MAX_PATH];

	std::vector<AccountInfoPtr> m_AccountList;
	int FindAccount(LPCSTR lpszName, LPCSTR lpszUser);

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
	END_EVT_MAP()

	long OnCall(Event& evt);
	long OnNotify(Event& evt);
};

#endif//_H_XLoginGuarder_H_
