#ifndef _H_XINDICATOR_MODULE_H_
#define _H_XINDICATOR_MODULE_H_

#include "XIndicator.h"
#include "../Util/ObjecterMap.h"

class XIndicatorModule 
	: public Objecter
	, public ObjecterMap<XIndicatorModule>
	, public EvtIdler
{
	typedef XIndicatorModule This;
	typedef Objecter Base;
	typedef ObjecterMap<XIndicatorModule> ObjectMap;
public:
	XIndicatorModule();
	~XIndicatorModule();

	long Start(char*);
	void Stop();

	LPCTSTR GetAppPath();
	LPCTSTR GetAppData();
	LPCTSTR GetIndicatorPath();
	LPCTSTR GetInidcatorData();
	//LPCTSTR GetTraderPath();

	virtual void OnIdle(unsigned int tick);

private:
	TCHAR m_szAppPath[MAX_PATH];
	TCHAR m_szDataPath[MAX_PATH];
	TCHAR m_szIndicatorPath[MAX_PATH];
	TCHAR m_szIndicatorData[MAX_PATH];
	//TCHAR m_szTraderPath[MAX_PATH];

public:
	BEGIN_EVT_MAP(This)
		//ON_EVT(EVT_PLAT_CALL, OnCall)
		//ON_EVT(EVT_PLAT_NOTIFY, OnNotify)
		CHAIN_EVT_MAP(ObjectMap)
	END_EVT_MAP()

	//long OnCall(Event& evt);
	//long OnNotify(Event& evt);
};

extern XIndicatorModule _XIndicatorModule;

#endif//_H_XINDICATOR_MODULE_H_