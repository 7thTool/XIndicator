#ifndef _H_WNDOBJECTER_H_
#define _H_WNDOBJECTER_H_

#include "Util.h"

#include <XLib/UIXWnd2.h>
#include <XLib/UIEvent.h>
#include "Objecter.h"

class UTIL_API WndObjecter : virtual public Objecter
{
public:
	static WndObjecter* FromHandle(HWND hWnd);
public:
	//WndObjecter();
	//virtual ~WndObjecter();

	virtual HWND GetThisHwnd() = 0;

	virtual HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual void Destroy();
};
/*
#define DECLARE_DYNCCREATE_WND_CLASS(theclass) \
	DECLARE_DYNCCREATE_CLASS(theclass::GetWndClassName())

#define DECLARE_WND_OBJECTER(theclass) \
	public: \
	virtual HWND GetThisHwnd() { return m_hWnd; } 

#define DECLARE_DYNCREATE_WND_OBJECTER(theclass,object) \
	DECLARE_DYNCREATE_OBJECTER(theclass,theclass::GetWndClassName(),object) \
	DECLARE_WND_OBJECTER(theclass)

#define DECLARE_DYNCREATE_WND_OBJECTER_EX(theclass,object1,object2) \
	DECLARE_DYNCREATE_OBJECTER_EX(theclass,theclass::GetWndClassName(),object1,object2) \
	DECLARE_WND_OBJECTER(theclass)

#define IMPLEMENT_DYNCREATE_WND_OBJECTER(theclass,object) \
	IMPLEMENT_DYNCREATE_OBJECTER(theclass,object) 

#define IMPLEMENT_DYNCREATE_WND_OBJECTER_EX(theclass,object1,object2) \
	IMPLEMENT_DYNCREATE_OBJECTER_EX(theclass,object1,object2) */

#endif//_H_WNDOBJECTER_H_
