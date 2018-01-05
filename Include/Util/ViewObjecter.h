#ifndef _H_VIEWOBJECTER_H_
#define _H_VIEWOBJECTER_H_

#include <XLib/UIXWnd2.h>
#include "../Util/WndObjecterMap.h"

template<class T,class TBase = UIXWnd2>
class DlgObjecterImpl
	: public UIXDialog2Impl<T,TBase> 
	, public UIPreTranslateMessageMap<T>
	, public WndObjecter
	, public WndObjecterMap<T>
{
public:
	typedef DlgObjecterImpl<T,TBase> This;
	typedef UIXDialog2Impl<T,TBase> Base;
	typedef UIPreTranslateMessageMap<T> PreTranslateMessageMap;
	typedef WndObjecterMap<T> ObjectMap;
	//DECLARE_XMLWND_CLASS(_T("xxxDlg"))
	//DECLARE_DYNCREATE_WND_OBJECTER(xxxDlg,Objecter)

	DlgObjecterImpl()
	{

	}

	virtual ~DlgObjecterImpl()
	{

	}

	int DoModal(HWND hWndParent = ::GetActiveWindow(), LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		return Base::DoModal(hWndParent, lpszXml, XmlFlag);
	}

	HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		if (XmlFlag&XML_FLAG_DOMODAL) {
			return (HWND)DoModal(hWndParent, lpszXml, XmlFlag&~XML_FLAG_DOMODAL);
		}
		return Base::Create(hWndParent, lpszXml, XmlFlag);
	}

	BOOL PreInitDialog(LPARAM lParam)
	{
		T* pT = static_cast<T*>(this);
		SetWindowLong(GWL_USERDATA, (LONG)dynamic_cast<WndObjecter*>(pT));

		return Base::PreInitDialog(lParam);
	}

	BEGIN_MSG_MAP(This)
		CHAIN_MSG_MAP(PreTranslateMessageMap)
		CHAIN_MSG_MAP(Base)
	END_MSG_MAP()

protected:

public:
	BEGIN_EVT_MAP(This)
		//ON_EVT(EVT_PLAT_CALL,OnCall)
		//ON_EVT(EVT_DE_NOTIFY,OnNotify)
		CHAIN_EVT_MAP(ObjectMap)
	END_EVT_MAP()
};

template<class T,class TBase = UIXWnd2>
class WndObjecterImpl 
	: public UIXWnd2Impl<T,TBase>
	, public UIPreTranslateMessageMap<T>
	, public WndObjecter
	, public WndObjecterMap<T>
{
	typedef WndObjecterImpl<T,TBase> This;
	typedef UIXWnd2Impl<T,TBase> Base;
	typedef UIPreTranslateMessageMap<T> PreTranslateMessageMap;
	typedef WndObjecterMap<T> ObjectMap;
	//DECLARE_XMLWND_CLASS(_T("xxxView"))
	//DECLARE_DYNCREATE_WND_OBJECTER(xxxView,Objecter)

public:
	WndObjecterImpl()
	{

	}
	virtual ~WndObjecterImpl()
	{

	}

	HWND Create(HWND hWndParent, RECT& rcPos
		, LPCTSTR szWindowName = NULL, DWORD dwStyle = 0, DWORD dwExStyle = 0, UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return Base::Create(hWndParent, rcPos, szWindowName
			, dwStyle
			, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		return Base::Create(hWndParent, lpszXml, XmlFlag);
	}

	void Load(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		T* pT = static_cast<T*>(this);
		BEGIN_XML_MAP(T::GetWndClassName())
			BEGIN_XML_WND_PRECREATED_HANDLER()
				BEGIN_XML_WND_CONTROL_HANDLER()
					XML_WND_CONTROL_HANDLER_DEFAULT()
				END_XML_WND_CONTROL_HANDLER()
			END_XML_WND_PRECREATED_HANDLER()
		END_XML_MAP()
	}

	void Save(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		T* pT = static_cast<T*>(this);
		BEGIN_XML_WRITE_MAP(T::GetWndClassName())
			TCHAR strBuffer[1024] = {0};
			CString strTitle;
			pT->GetWindowText(strTitle);
			xml->SetAttributeString(_T(""), _T("title"), (TCHAR*)(LPCTSTR)strTitle);
			xml->SetAttributeString(_T(""), _T("style"), _HEXSTRING(strBuffer,pT->GetStyle()));
			xml->SetAttributeString(_T(""), _T("exstyle"), _HEXSTRING(strBuffer,pT->GetExStyle()));
		END_XML_WRITE_MAP()
	}

	BOOL PreInitWindow(CREATESTRUCT& cs)
	{
		T* pT = static_cast<T*>(this);
		SetWindowLong(GWL_USERDATA, (LONG)dynamic_cast<WndObjecter*>(pT));

		if(cs.lpCreateParams) {
			Markup* xml = (Markup*)cs.lpCreateParams;
			Load((LPCTSTR)xml,XML_FLAG_MARKUP);
		}
		return TRUE;
		//return Base::PreInitWindow(cs);
	}

	void GetMinMaxInfo(MINMAXINFO* pMMInfo)
	{
		
	}

	BEGIN_MSG_MAP(This)
		MESSAGE_HANDLER(WM_GETMINMAXINFO, OnGetMinMaxInfo)
		CHAIN_MSG_MAP(PreTranslateMessageMap)
		CHAIN_MSG_MAP(Base)
	END_MSG_MAP()

	LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		T* pT = static_cast<T*>(this);
		pT->DefWindowProc();
		MINMAXINFO* pMMInfo = (MINMAXINFO*)lParam;
		pT->GetMinMaxInfo(pMMInfo);
		return 0;
	}

protected:

public:
	BEGIN_EVT_MAP(This)
		//ON_EVT(EVT_PLAT_CALL,OnCall)
		//ON_EVT(EVT_DE_NOTIFY,OnNotify)
		CHAIN_EVT_MAP(ObjectMap)
	END_EVT_MAP()
};

//////////////////////////////////////////////////////////////////////////

template<class T>
class ContainerImpl 
	: public WndObjecterImpl<T>
{
	typedef ContainerImpl<T> This;
	typedef WndObjecterImpl<T> Base;
public:
	ContainerImpl()
	{

	}

protected:
	//
	ContainerInfoPtr m_InfoPtr;

public:
	const ContainerInfoPtr & GetInfoPtr()
	{
		return m_InfoPtr;
	}
	bool IsContainerOk()
	{
		return (m_InfoPtr!=0);
	}
	bool IsInteractive() 
	{
		return m_InfoPtr->IsInteractive();
	}
	const std::vector<KindInfo>& GetKindList()
	{
		return m_InfoPtr->GetKindList();
	}
	int GetCurKindPos()
	{
		return m_InfoPtr->GetCurKindPos();
	}
	const KindInfo& GetCurKind()
	{
		return m_InfoPtr->GetCurKind();
	}
	const COMREFLIST& GetCommodityList()
	{
		return m_InfoPtr->GetCommodityList();
	}
	int GetCurCommodityPos()
	{
		return m_InfoPtr->GetCurCommodityPos();
	}
	int GetCurCommodity(COMREF* pCommodity = NULL)
	{
		return m_InfoPtr->GetCurCommodity(pCommodity);
	}
	int SetCurCommodity(int Pos)
	{
		return m_InfoPtr->SetCurCommodity(Pos);
	}
	int SetCurCommodity(const COMREF& Commodity)
	{
		return m_InfoPtr->SetCurCommodity(Commodity);
	}

	void OnInfoChanged()
	{
		//T* pT = static_cast<T*>(this);
		//pT->Invalidate();
	}

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		//ON_EVT(EVT_DE_NOTIFY,OnNotify)
		CHAIN_EVT_MAP(Base)
	END_EVT_MAP()

	long OnCall(Event& evt)
	{
		T* pT = static_cast<T*>(this);
		switch(evt.value)
		{
		case MAKEVALUE(MSET_PLAT_OBJECT,CSET_CONTAINER_INFO):
			{
				m_InfoPtr = ContainerInfoPtr::dynamicCast(evt.objPtr);
				pT->OnInfoChanged();
				return RLT_OK;
			}
			break;
			//////////////////////////////////////////////////////////////////////////
		default:
			evt.handled = false;
			break;
		}
		return RLT_UNKNOWN;
	}
};

//////////////////////////////////////////////////////////////////////////

template<class T,class TBase = UIXWnd2>
class ViewObjecterImpl 
	: public WndObjecterImpl<T,TBase>
{
	typedef ViewObjecterImpl<T,TBase> This;
	typedef WndObjecterImpl<T,TBase> Base;
public:
	ViewObjecterImpl()
	{
		
	}

protected:
	//
	ViewInfoPtr m_vInfoPtr;
	ViewDispInfoPtr m_vDispInfoPtr;

public:
	const ViewInfoPtr& GetViewInfoPtr()
	{
		return m_vInfoPtr;
	}
	const ViewDispInfoPtr& GetViewDispInfoPtr()
	{
		return m_vDispInfoPtr;
	}
	bool IsViewOk()
	{
		return (m_vInfoPtr!=0 && m_vDispInfoPtr!=0);
	}

	bool IsInteractive() 
	{
		return m_vInfoPtr->InfoPtr->IsInteractive();
	}
	WndObjecter* GetContainer()
	{
		return m_vInfoPtr->InfoPtr->GetContainer();
	}
	const std::vector<KindInfo>& GetKindList()
	{
		return m_vInfoPtr->InfoPtr->GetKindList();
	}
	int GetCurKindPos()
	{
		return m_vInfoPtr->InfoPtr->GetCurKindPos();
	}
	const KindInfo& GetCurKind()
	{
		return m_vInfoPtr->InfoPtr->GetCurKind();
	}
	const COMREFLIST& GetCommodityList()
	{
		return m_vInfoPtr->InfoPtr->GetCommodityList();
	}
	int GetCurCommodityPos()
	{
		return m_vInfoPtr->InfoPtr->GetCurCommodityPos();
	}
	int GetCurCommodity(COMREF* pCommodity = NULL)
	{
		return m_vInfoPtr->InfoPtr->GetCurCommodity(pCommodity);
	}

	void OnViewInfoChanged()
	{
		
	}
	void OnViewDispInfoChanged()
	{
		
	}

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		//ON_EVT(EVT_DE_NOTIFY,OnNotify)
		CHAIN_EVT_MAP(Base)
	END_EVT_MAP()

	long OnCall(Event& evt)
	{
		switch(evt.value)
		{
		case MAKEVALUE(MSET_PLAT_OBJECT,CSET_VIEW_INFO):
			{
				T* pT = static_cast<T*>(this);
				m_vInfoPtr = ViewInfoPtr::dynamicCast(evt.objPtr);
				pT->OnViewInfoChanged();
				return RLT_OK;
			}
			break;
		case MAKEVALUE(MSET_PLAT_OBJECT,CSET_VIEW_DISPINFO):
			{
				T* pT = static_cast<T*>(this);
				m_vDispInfoPtr = ViewDispInfoPtr::dynamicCast(evt.objPtr);
				pT->OnViewDispInfoChanged();
				return RLT_OK;
			}
			break;
		//////////////////////////////////////////////////////////////////////////
		default:
			evt.handled = false;
			break;
		}
		return RLT_UNKNOWN;
	}
};


#endif//_H_VIEWOBJECTER_H_