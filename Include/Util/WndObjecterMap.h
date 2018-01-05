#ifndef _H_WNDOBJECTERMAP_H_
#define _H_WNDOBJECTERMAP_H_

#include "UIObjecterMap.h"
#include "WndObjecter.h"

template<class T>
class WndObjecterMap : public UIObjecterMap<T>
{
	typedef WndObjecterMap<T> This;
	typedef UIObjecterMap<T> Base;
public:

public:
	/*void OnInvalidate(ObjectPtr objPtr)
	{
		T* pT = static_cast<T*>(this);
		pT->Invalidate();
	}*/
};

template<class T>
class MultiWndObjecterMap : public MultiObjecterMap<T>
{
	typedef MultiWndObjecterMap<T> This;
	typedef MultiObjecterMap<T> Base;
public:
	HWND CreateObjecter(LPCTSTR lpszClass, HWND hWndParent, LPCTSTR lpszXml, UINT XmlFlag)
	{
		T* pT = static_cast<T*>(this);
		HWND hWndCtrl = Base::CreateObjecter(lpszClass, hWndParent, lpszXml, XmlFlag);
		if (hWndCtrl) {
			WndObjecter* pWndObjecter = dynamic_cast<WndObjecter*>((Objecter*)hWndCtrl);
			if (pWndObjecter) {
				hWndCtrl = pWndObjecter->GetThisHwnd();
			} else {
				ASSERT(1);
				hWndCtrl = NULL;
			}
		}
		return hWndCtrl;
		return NULL;
	}

	void OnCreateObjecter(Objecter* pObjecter)
	{
		T* pT = static_cast<T*>(this);
		ASSERT(pObjecter);
		const ObjectDispInfoPtr& DispInfoPtr = pT->GetDispInfoPtr();
		if (DispInfoPtr) {
			pT->SendEvent(pObjecter, EVT_PLAT_CALL, MAKEVALUE(MSET_PLAT_OBJECT,CSET_OBJECT_DISPINFO), DispInfoPtr);
		}
	}

	WndObjecter* GetObjecterBy(UINT Pos)
	{
		return dynamic_cast<WndObjecter*>(Base::GetObjecterBy(Pos));
	}

	WndObjecter* GetObjecterBy(HWND hWnd)
	{
		if (hWnd) {
			pObjecterList::iterator it = m_pObjecterList.begin();
			for (; it != m_pObjecterList.end(); ++it)
			{
				WndObjecter* pWndObjecter = dynamic_cast<WndObjecter*>(*it);
				if (pWndObjecter && pWndObjecter->GetThisHwnd() == hWnd) {
					return pWndObjecter;
				}
			}
		}
		return NULL;
	}

	BEGIN_MSG_MAP(This)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
	END_MSG_MAP()

	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
	{
		bHandled = FALSE;

		T* pT = static_cast<T*>(this);
		pT->DestroyAllObjecter();

		return bHandled;
	}
};

template<class T>
class MultiNameWndObjecterMap : public MultiNameObjecterMap<T>
{
	typedef MultiNameWndObjecterMap<T> This;
	typedef MultiNameObjecterMap<T> Base;
public:
	HWND CreateObjecter(LPCTSTR lpszClass, LPCTSTR lpszName, HWND hWndParent, LPCTSTR lpszXml, UINT XmlFlag)
	{
		T* pT = static_cast<T*>(this);
		HWND hWndCtrl = Base::CreateObjecter(lpszClass, lpszName, hWndParent, lpszXml, XmlFlag);
		if (hWndCtrl) {
			WndObjecter* pWndObjecter = dynamic_cast<WndObjecter*>((Objecter*)hWndCtrl);
			if (pWndObjecter) {
				hWndCtrl = pWndObjecter->GetThisHwnd();
			} else {
				ASSERT(1);
				hWndCtrl = NULL;
			}
		}
		return hWndCtrl;
		return NULL;
	}

	void OnCreateObjecter(LPCTSTR lpszName, Objecter* pObjecter)
	{
		T* pT = static_cast<T*>(this);
		ASSERT(pObjecter);
		const ObjectDispInfoPtr& DispInfoPtr = pT->GetDispInfoPtr();
		if (DispInfoPtr) {
			pT->SendEvent(pObjecter, EVT_PLAT_CALL, MAKEVALUE(MSET_PLAT_OBJECT,CSET_OBJECT_DISPINFO), DispInfoPtr);
		}
	}

	/*WndObjecter* GetObjecterBy(UINT Pos)
	{
		return dynamic_cast<WndObjecter*>(Base::GetObjecterBy(Pos));
	}*/

	WndObjecter* GetObjecterBy(LPCTSTR lpszName)
	{
		return dynamic_cast<WndObjecter*>(Base::GetObjecterBy(lpszName));
	}

	WndObjecter* GetObjecterBy(HWND hWnd)
	{
		if (hWnd) {
			strName2pObject::iterator it = m_Name2pObject.begin();
			for (; it != m_Name2pObject.end(); ++it)
			{
				WndObjecter* pObjecter = dynamic_cast<WndObjecter*>(it->second);
				if (pObjecter && pObjecter->GetThisHwnd() == hWnd) {
					return pObjecter;
				}
			}
		}
		return NULL;
	}

	BEGIN_MSG_MAP(This)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
	END_MSG_MAP()

	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
	{
		bHandled = FALSE;

		T* pT = static_cast<T*>(this);
		pT->DestroyAllObjecter();

		return bHandled;
	}
};

#endif//_H_WNDOBJECTERMAP_H_