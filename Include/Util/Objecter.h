#ifndef _H_OBJECTERIMPL_H_
#define _H_OBJECTERIMPL_H_

#include "XUtil.h"

#include <XLib/XObjectEx.h>
#include <XLib/XEvent.h>

#define USES_MULTITHREAD 0

class Objecter;

DECLARE_DYNCCREATE_FACTORY_EXPORT(XUTIL_API,Objecter)

enum
{
	XML_FLAG_CREATE		= 0,			//默认CREATE
	XML_FLAG_DOMODAL	= 0X10,			//对话框的话可以使用DoModal
};

//STR
#define STR_CREATE_XMLA		"CreateXml"	//返回Create使用的配置XML结构数据，如果没有变化，就返回NULL
#define STR_CREATE_XMLW		L"CreateXml"
#define STR_CONFIG_XMLA		"ConfigXml"	//
#define STR_CONFIG_XMLW		L"ConfigXml"
#ifdef UNICODE
#define STR_CREATE_XML		STR_CREATE_XMLA		
#define STR_CONFIG_XML		STR_CONFIG_XMLA	
#else
#define STR_CREATE_XML		STR_CREATE_XMLW		
#define STR_CONFIG_XML		STR_CONFIG_XMLW	
#endif//

//配置相关

#define WORKDIRA			"WorkDir"		//exe work directory
#define DATADIRA			"DataDir"		//exe data directory
#define USERDIRA			"UserDir"		//user directory

#define WORKDIRW			L"WorkDir"		//exe work directory
#define DATADIRW			L"DataDir"		//exe data directory 
#define USERDIRW			L"UserDir"		//user directory


#ifdef UNICODE
#define WORKDIR				WORKDIRW		
#define DATADIR				DATADIRW	
#define USERDIR				USERDIRW
#else
#define WORKDIR				WORKDIRA		
#define DATADIR				DATADIRA	
#define USERDIR				USERDIRA
#endif//

#define MEMFILEA			"MEM"
#define APPFILEA			"APP"
#define USERFILEA			"USER"
#define THEMEFILEA			"THEME"

#define MEMFILEW			L"MEM"
#define APPFILEW			L"APP"
#define USERFILEW			L"USER"
#define THEMEFILEW			L"THEME"

#ifdef UNICODE
#define MEMFILE				MEMFILEW
#define APPFILE				APPFILEW
#define USERFILE			USERFILEW
#define THEMEFILE			THEMEFILEW
#else
#define MEMFILE				MEMFILEA
#define APPFILE				APPFILEA
#define USERFILE			USERFILEA
#define USERFILE			THEMEFILEA
#endif//

/*extern Objecter* _pPlat;
extern Objecter* _pData;
extern Objecter* _pLogin;
extern __declspec(selectany,thread) Objecter* _pIndicator;
extern __declspec(selectany,thread) Objecter* _pFrame;*/

class XUTIL_API Objecter : virtual public EvtObjecter
{
	//DECLARE_DYNCREATE_OBJECT(Objecter,_T("Object"),Objecter)
//private:
//	static Objecter* m_pPlat;
//	static Objecter* m_pData;
//	static Objecter* m_pLogin;
//	static Objecter* m_pIndicator;
//	static Objecter* m_pFrame;
public:
	static void SetPlatPtr(Objecter* pPlat);
	static Objecter* GetPlatPtr();
	static void SetDataPtr(Objecter* pData);
	static Objecter* GetDataPtr();
	static void SetLoginPtr(Objecter* pLogin);
	static Objecter* GetLoginPtr();
	static void SetIndicatorPtr(Objecter* pIndicator);
	static Objecter* GetIndicatorPtr();
	static void SetFramePtr(Objecter* pFrame);
	static Objecter* GetFramePtr();

public:
	template<class TObjecter>
	static HWND CreateObject(TObjecter* & pObjecter, LPCTSTR lpszName, HWND hWndParent, LPCTSTR lpszXml, UINT XmlFlag)
	{
		Objecter* pObject = DYNCREATE_OBJECT(Objecter,lpszName);
		if (pObject) {
			pObjecter = dynamic_cast<TObjecter*>(pObject);
			if (pObjecter) {
				return pObjecter->Create(hWndParent, lpszXml, XmlFlag);
			} else {
				DYNDELETE_OBJECT(pObject);
			}
		}
		return NULL;
	}
	template<class TObjecter>
	static void DestroyObject(TObjecter* & pObjecter)
	{
		if (pObjecter) {
			pObjecter->Destroy();
			DYNDELETE_OBJECT(pObjecter);
			pObjecter = NULL;
		}
	}
	//static long WriteValue(LPCSTR lpszName, LPCSTR lpszValue, int nValueCount = 0, LPCSTR lpszSpec = NULL, LPCSTR lpszFile = NULL);
	//static long ReadValue(LPCSTR lpszName, LPSTR lpszValue, int nValueCount, LPCSTR lpszSpec = NULL, LPCSTR lpszFile = NULL);
	//static long WriteValue(LPCWSTR lpszName, LPCWSTR lpszValue, int nValueCount = 0, LPCWSTR lpszSpec = NULL, LPCWSTR lpszFile = NULL);
	//static long ReadValue(LPCWSTR lpszName, LPWSTR lpszValue, int nValueCount, LPCWSTR lpszSpec = NULL, LPCWSTR lpszFile = NULL);

	//static LPCTSTR GetClassName() { return NULL; }
public:
	Objecter();
	virtual ~Objecter();

	//动态对象都应该实现GetThisClassName接口
	virtual LPCTSTR GetThisClassName();

	//对于窗口要实现基于XML的动态创建接口
	virtual HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual void Destroy();

	virtual void Load(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual void Save(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);

//protected:
	virtual long WriteValue(LPCSTR lpszName, LPCSTR lpszValue, int nValueCount = 0, LPCSTR lpszSpec = NULL, LPCSTR lpszFile = NULL);
	virtual long ReadValue(LPCSTR lpszName, LPSTR lpszValue, int nValueCount, LPCSTR lpszSpec = NULL, LPCSTR lpszFile = NULL);
	virtual long WriteValue(LPCWSTR lpszName, LPCWSTR lpszValue, int nValueCount = 0, LPCWSTR lpszSpec = NULL, LPCWSTR lpszFile = NULL);
	virtual long ReadValue(LPCWSTR lpszName, LPWSTR lpszValue, int nValueCount, LPCWSTR lpszSpec = NULL, LPCWSTR lpszFile = NULL);
};

//////////////////////////////////////////////////////////////////////////

#define _PlatPtr			(Objecter::GetPlatPtr())
#define _DataPtr			(Objecter::GetDataPtr())
#define _LoginPtr			(Objecter::GetLoginPtr())
#define _IndicatorPtr		(Objecter::GetIndicatorPtr())
#define _FramePtr			(Objecter::GetFramePtr())

//////////////////////////////////////////////////////////////////////////
/*
#define BEGIN_DYNCREATE_OBJECT_MAP(theClass) \
	HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE) \
	{ \
		HWND Res = NULL;

#define END_DYNCREATE_OBJECT_MAP() \
		return Res; \
	}

#define DECLARE_OBJECTER(theclass) \
	public: \
	virtual LPCTSTR GetThisClassName() { return theclass::GetClassName(); } 

#define DECLARE_DYNCREATE_OBJECTER(theclass,classname,object) \
	DECLARE_DYNCCREATE_CLASS(classname) \
	DECLARE_DYNCREATE_OBJECT(theclass,object) \
	DECLARE_OBJECTER(theclass)

#define DECLARE_DYNCREATE_OBJECTER_EX(theclass,classname,object1,object2) \
	DECLARE_DYNCCREATE_CLASS(classname) \
	DECLARE_DYNCREATE_OBJECT(theclass,object1) \
	DECLARE_DYNCREATE_OBJECT(theclass,object2) \
	DECLARE_OBJECTER(theclass)

#define IMPLEMENT_DYNCREATE_OBJECTER(theclass,object) \
	IMPLEMENT_DYNCREATE_OBJECT(theclass,object) \
	IMPLEMENT_DYNCREATE_REGISTER(theclass,object)

#define IMPLEMENT_DYNCREATE_OBJECTER_EX(theclass,object1,object2) \
	IMPLEMENT_DYNCREATE_OBJECT(theclass,object1) \
	IMPLEMENT_DYNCREATE_REGISTER(theclass,object1) \
	IMPLEMENT_DYNCREATE_OBJECT(theclass,object2) \
	IMPLEMENT_DYNCREATE_REGISTER(theclass,object2)*/


//////////////////////////////////////////////////////////////////////////

#endif//_H_OBJECTERIMPL_H_