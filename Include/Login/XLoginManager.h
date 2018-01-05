#ifndef _H_XLOGINMANAGER_H_
#define _H_XLOGINMANAGER_H_

#include <Login/XLoginGuarder.h>

class XLoginManager 
	: public XLoginGuarder
{
	typedef XLoginManager This;
	typedef XLoginGuarder Base;
public:
	XLoginManager();
	~XLoginManager();

	long Instance();
	void Release();


protected:

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
		CHAIN_EVT_MAP(Base)
	END_EVT_MAP()

	long OnCall(Event& evt);
	long OnNotify(Event& evt);
};

extern XLoginManager* _LoginMgr;

#endif//_H_XLOGINMANAGER_H_
