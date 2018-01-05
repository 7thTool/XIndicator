#ifndef _H_VIEWSPLITTER_H_
#define _H_VIEWSPLITTER_H_

#include <XLib/UIXPane2.h>
#include "ViewObjecterMap.h"

template <class T>
class ViewSplitterImpl
	: public UIXPaneSplitterImpl<T,UIXPane2>
	, public MultiNameViewObjecterMap<T>
{
	typedef ViewSplitterImpl<T> This;
	typedef UIXPaneSplitterImpl<T,UIXPane2> Base;
	typedef MultiNameViewObjecterMap<T> MultiViewerMap;
public:
	ViewSplitterImpl()
	{

	}

	void LoadAllObjecter(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		T* pT = static_cast<T*>(this);
		BEGIN_XML_MAP(T::GetWndClassName())
			BEGIN_XML_WND_CONTROL_HANDLER()
				XML_WND_CONTROL_HANDLER_DEFAULT()
			END_XML_WND_CONTROL_HANDLER()
		END_XML_MAP()
	}

	void SaveAllObjecter(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		T* pT = static_cast<T*>(this);
		BEGIN_XML_WRITE_MAP(T::GetWndClassName())
			Format(xml);
			UINT Pos = 0;
			HWND hWnd = NULL;
			while(hWnd = ChildWindowFromPos(Pos)) 
			{
				WndObjecter* pWndObjecter = NULL;
				strName2pObject::iterator it = m_Name2pObject.begin();
				for (; it != m_Name2pObject.end(); ++it)
				{
					pWndObjecter = dynamic_cast<WndObjecter*>(it->second);
					if(pWndObjecter) {
						if (hWnd == pWndObjecter->GetThisHwnd()) {
							break;
						}
					}
				}
				ASSERT (it!=m_Name2pObject.end());
				//UIWnd2 wndObjecter(hWnd);
				//TCHAR strBuffer[1024] = {0};
				xml->New(it->second->GetThisClassName());
				xml->IntoElem();
				xml->SetAttributeString(_T(""), _T("name"), (TCHAR*)it->first.c_str());
				//xml->SetAttributeString(_T(""), _T("style"), _HEXSTRING(strBuffer,wndObjecter.GetStyle()));
				//xml->SetAttributeString(_T(""), _T("exstyle"), _HEXSTRING(strBuffer,wndObjecter.GetExStyle()));
				it->second->Save((LPCTSTR)xml,XML_FLAG_MARKUP);
				xml->OutofElem();
				++Pos;
			}
		END_XML_WRITE_MAP()
	}

	HWND CreateControl(HWND hWndParent, LPCTSTR lpszWndClass, LPCTSTR lpszCtrlName, UINT nID, LPCTSTR lpszXml, UINT XmlFlag)
	{
		T* pT = static_cast<T*>(this);
		if (_tcsicmp(lpszWndClass, Pane::GetXmlPaneName()) != 0) {
			HWND hWndCtrl = MultiViewerMap::CreateObjecter(lpszWndClass, lpszCtrlName, hWndParent, lpszXml, XmlFlag);
			pT->OnCreateControl(hWndParent, hWndCtrl, lpszWndClass, lpszCtrlName, nID);
			return hWndCtrl;
		}
		return Base::CreateControl(hWndParent, lpszWndClass, lpszCtrlName, nID, lpszXml, XmlFlag);
	}

	/*HWND InsertObjecter(LPCRECT lpRect, long nStyle, LPCTSTR lpszName
		, Pane* pBefore
		, LPCTSTR lpszWndClass
		, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_NONE
		, Pane* pParent = NULL)
	{
		T* pT = static_cast<T*>(this);
		//Insert Pane
		pT->Insert(lpRect, nStyle, lpszName, pBefore, pParent);
		//Insert Window
		return pT->CreateControl(*pT, lpszWndClass, lpszName, 0, lpszXml, XmlFlag);
	}

	void RemoveObjecterBy(Pane* pPane)
	{
		T* pT = static_cast<T*>(this);
		if (pPane) {
			HWND hWnd = *pPane;
			WndObjecter* pObjecter = pT->GetObjecterBy(hWnd);
			pT->DestroyObjecter(pObjecter);

			m_pP1 = pPane;
			pT->SendMessage(WM_COMMAND, ID_PANE_CLOSE, (LPARAM)m_pP1);
		}
	}

	void RemoveObjecterBy(WndObjecter* pObjecter)
	{
		T* pT = static_cast<T*>(this);
		if (pObjecter) {
			Pane* pPane = pT->PaneFromWindow(pObjecter->GetThisHwnd());

			pT->DestroyObjecter(pObjecter);
			
			if (pPane) {
				m_pP1 = pPane;
				pT->SendMessage(WM_COMMAND, ID_PANE_CLOSE, (LPARAM)m_pP1);
			}
		}
	}*/

	void RemoveAllObjecter()
	{
		T* pT = static_cast<T*>(this);
		MultiViewerMap::DestroyAllObjecter();

		m_pP1 = m_pP;
		pT->SendMessage(WM_COMMAND, ID_PANE_CLOSE, (LPARAM)m_pP1);
	}

	WndObjecter* ChildObjecterFromPos(UINT Pos)
	{
		T* pT = static_cast<T*>(this);
		return pT->GetObjecterBy(pT->ChildWindowFromPos(Pos));
	}

	WndObjecter* ChildObjecterFromName(LPCTSTR lpszName)
	{
		T* pT = static_cast<T*>(this);
		return pT->GetObjecterBy(lpszName);
	}

	void Relayout(LPCRECT lpRect = NULL)
	{
		//调整合适位置
		Base::Relayout(lpRect);
	}

	BEGIN_MSG_MAP(This)
		CHAIN_MSG_MAP(MultiViewerMap)
		CHAIN_MSG_MAP(Base)
	END_MSG_MAP()


	BEGIN_EVT_MAP(This)
		CHAIN_EVT_MAP(MultiViewerMap)
	END_EVT_MAP()
};

#endif//_H_VIEWSPLITTER_H_