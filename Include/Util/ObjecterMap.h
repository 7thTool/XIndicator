#ifndef _H_OBJECTERMAP_H_
#define _H_OBJECTERMAP_H_

#include "XEvtDefine.h"
#include "Objecter.h"

template<class T>
class ObjecterMap
{
	typedef ObjecterMap<T> This;

public:
	long AddKind(const KindInfo& Kind)
	{
		return RLT_UNKNOWN;
	}

	long RemoveKind(const KindInfo& Kind)
	{
		return RLT_UNKNOWN;
	}

	long AddCommodity(const KindInfo& Kind, const COMREF* pCommodityList, int nCommodityCount = 1)
	{
		T* pT = static_cast<T*>(this);
		AddSelfCommodityPtr objPtr = new AddSelfCommodity();
		objPtr->Kind = Kind;
		objPtr->CommodityList.assign(pCommodityList, pCommodityList+nCommodityCount);
		return pT->SendEvent(_DataPtr, EVT_PLAT_CALL, MAKEVALUE(MCALL_PLAT_DE,CCALL_DE_ADDSELFCOMMODITY), objPtr);
	}

	long RemoveCommodity(const KindInfo& Kind, const COMREF* pCommodityList, int nCommodityCount = 1)
	{
		T* pT = static_cast<T*>(this);
		RemoveSelfCommodityPtr objPtr = new RemoveSelfCommodity();
		objPtr->Kind = Kind;
		objPtr->CommodityList.assign(pCommodityList, pCommodityList+nCommodityCount);
		return pT->SendEvent(_DataPtr, EVT_PLAT_CALL, MAKEVALUE(MCALL_PLAT_DE,CCALL_DE_REMOVESELFCOMMODITY), objPtr);
	}

	long AddCommodity(int nSelfKind, const COMREF* pCommodityList, int nCommodityCount = 1)
	{
		KIND Kind;
		Kind.Type = KIND_TYPE_USER;
		Kind.Exchange = 0;
		Kind.Index = nSelfKind;
		return AddCommodity(KindInfo(Kind), pCommodityList, nCommodityCount);
	}

	long RemoveCommodity(int nSelfKind, const COMREF* pCommodityList, int nCommodityCount = 1)
	{
		KIND Kind;
		Kind.Type = KIND_TYPE_USER;
		Kind.Exchange = 0;
		Kind.Index = nSelfKind;
		return RemoveCommodity(KindInfo(Kind), pCommodityList, nCommodityCount);
	}

public:
	void Clear()
	{
		
	}

	void OnIdle()
	{
		
	}

	void OnRefresh(ObjectPtr objPtr)
	{

	}

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL,OnCall)
	END_EVT_MAP()

	long OnCall(Event& evt)
	{
		switch(evt.value)
		{
		//Method
		case MAKEVALUE(MCALL_PLAT_OBJECT,CCALL_OBJECT_REFRESH):
			{
				T* pT = static_cast<T*>(this);
				pT->OnRefresh(evt.objPtr);
				return RLT_OK;
			}
			break;
		default:
			evt.handled = false;
			break;
		}
		return RLT_UNKNOWN;
	}
};

template<class T>
class MultiObjecterMap 
{
	typedef MultiObjecterMap<T> This;
protected:
	typedef std::vector<Objecter*> pObjecterList;
	pObjecterList m_pObjecterList;

public:

	void LoadAllObjecter(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		T* pT = static_cast<T*>(this);
		BEGIN_XML_MAP(T::GetClassName())
			//
		END_XML_MAP()
	}

	void SaveAllObjecter(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		T* pT = static_cast<T*>(this);
		BEGIN_XML_WRITE_MAP(T::GetClassName())
			pObjecterList::iterator it = m_pObjecterList.begin();
			for (; it != m_pObjecterList.end(); ++it)
			{
				xml->New((*it)->GetThisClassName());
				xml->IntoElem();
				(*it)->Save((LPCTSTR)xml,XML_FLAG_MARKUP);
				xml->OutofElem();
			}
		END_XML_WRITE_MAP()
	}

	BOOL IsObjecterEmpty()
	{
		return m_pObjecterList.empty() ? TRUE : FALSE;
	}

	UINT GetObjecterCount() 
	{
		return m_pObjecterList.size();
	}

	UINT GetObjecterPosBy(Objecter* pObjecter)
	{
		UINT Pos = 0;
		for (; Pos<m_pObjecterList.size(); Pos++)
		{
			if (pObjecter==m_pObjecterList[Pos]) {
				break;
			}
		}
		return Pos;
	}

	Objecter* GetObjecterBy(UINT Pos)
	{
		if (Pos >= m_pObjecterList.size()) {
			return NULL;
		}
		return m_pObjecterList[Pos];
	}

	HWND CreateObjecter(LPCTSTR lpszClass, HWND hWndParent, LPCTSTR lpszXml, UINT XmlFlag)
	{
		T* pT = static_cast<T*>(this);
		Objecter* pObjecter = NULL;
		HWND hWndCtrl = Objecter::CreateObject(pObjecter, lpszClass, hWndParent, lpszXml, XmlFlag);
		if (!hWndCtrl) {
			Objecter::DestroyObject(pObjecter);
		} 
		hWndCtrl = (HWND)pObjecter;
		if (pObjecter) {
			pT->OnCreateObjecter(pObjecter);
			m_pObjecterList.push_back(pObjecter);
		}
		return hWndCtrl;
	}

	void OnCreateObjecter(Objecter* pObjecter)
	{
		
	}

	void DestroyObjecter(UINT Pos)
	{
		T* pT = static_cast<T*>(this);
		ASSERT(Pos < m_pObjecterList.size());
		if (Pos >= m_pObjecterList.size()) {
			return;
		}
		Objecter* pObjecter = *(m_pObjecterList.begin()+Pos);
		pT->OnDestroyObjecter(pObjecter);
		Objecter::DestroyObject(pObjecter);
		m_pObjecterList.erase(m_pObjecterList.begin()+Pos);
	}

	void DestroyObjecter(Objecter* pObjecter)
	{
		T* pT = static_cast<T*>(this);
		ASSERT(pObjecter);
		if (!pObjecter) {
			return;
		}
		pObjecterList::iterator it = m_pObjecterList.begin();
		for (; it != m_pObjecterList.end(); ++it)
		{
			if (pObjecter == *it) {
				pT->OnDestroyObjecter(pObjecter);
				Objecter::DestroyObject(pObjecter);
				m_pObjecterList.erase(it);
				break;
			}
		}
	}

	void DestroyAllObjecter()
	{
		T* pT = static_cast<T*>(this);
		pObjecterList::iterator it = m_pObjecterList.begin();
		for (; it != m_pObjecterList.end(); ++it)
		{
			pT->OnDestroyObjecter(*it);
			Objecter::DestroyObject(*it);
		}
		m_pObjecterList.clear();
	}

	void OnDestroyObjecter(Objecter* pObjecter)
	{

	}

	void BroadcastSend(Event& evt)
	{
		T* pT = static_cast<T*>(this);
		pObjecterList::iterator it = m_pObjecterList.begin();
		for (; it != m_pObjecterList.end(); ++it)
		{
			Objecter* pObject = *it;
			if (pObject) {
				pT->SendEvent(pObject, evt);
			}
		}
	}

	void BroadcastPost(Event& evt)
	{
		T* pT = static_cast<T*>(this);
		pObjecterList::iterator it = m_pObjecterList.begin();
		for (; it != m_pObjecterList.end(); ++it)
		{
			Objecter* pObject = *it;
			if (pObject) {
				pT->SendEvent(pObject, evt);
			}
		}
	}

	void BroadcastSend(long evt, long value, ObjectPtr objPtr)
	{
		T* pT = static_cast<T*>(this);
		pT->BroadcastSend(Event(pT, 0, evt, value, objPtr));
	}

	void BroadcastPost(long evt, long value, ObjectPtr objPtr)
	{
		T* pT = static_cast<T*>(this);
		pT->BroadcastPost(Event(pT, 0, evt, value, objPtr));
	}

	long BroadcastHandle(Event& evt)
	{
		ASSERT(!evt.handled);
		T* pT = static_cast<T*>(this);
		long rlt = RLT_UNKNOWN;
		pObjecterList::iterator it = m_pObjecterList.begin();
		for (; it != m_pObjecterList.end(); ++it)
		{
			Objecter* pObject = *it;
			if (pObject) {
				pT->SendEvent(pObject, evt);
				if (evt.handled) {
					break;
				}
			}
		}
		return rlt;
	}

	long BroadcastHandle(long evt, long value, ObjectPtr objPtr)
	{
		T* pT = static_cast<T*>(this);
		return pT->BroadcastHandle(Event(pT, 0, evt, value, objPtr));
	}

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_DE_NOTIFY,OnNotify)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
	END_EVT_MAP()

	long OnNotify(Event& evt)
	{
		T* pT = static_cast<T*>(this);
		pObjecterList::iterator it = m_pObjecterList.begin();
		for (; it != m_pObjecterList.end(); ++it)
		{
			Objecter* pObject = *it;
			if (pObject) {
				pT->SendEvent(pObject, evt);
			}
		}
		return RLT_OK;
	}
};

template<class T>
class MultiNameObjecterMap 
{
	typedef MultiNameObjecterMap<T> This;
protected:
	typedef std::map<std::tstring,Objecter*,std::tstringiless> strName2pObject;
	strName2pObject m_Name2pObject;

public:

	void LoadAllObjecter(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		T* pT = static_cast<T*>(this);
		BEGIN_XML_MAP(T::GetClassName())
			//
		END_XML_MAP()
	}

	void SaveAllObjecter(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE)
	{
		T* pT = static_cast<T*>(this);
		BEGIN_XML_WRITE_MAP(T::GetClassName())
			strName2pObject::iterator it = m_Name2pObject.begin();
			for (; it != m_Name2pObject.end(); ++it)
			{
				xml->New(it->second->GetThisClassName());
				xml->IntoElem();
				xml->SetAttributeString(_T(""), _T("name"), (TCHAR*)it->first.c_str());
				it->second->Save((LPCTSTR)xml,XML_FLAG_MARKUP);
				xml->OutofElem();
			}
		END_XML_WRITE_MAP()
	}

	BOOL IsObjecterEmpty()
	{
		return m_Name2pObject.empty() ? TRUE : FALSE;
	}

	UINT GetObjecterCount() 
	{
		return m_Name2pObject.size();
	}

	/*Objecter* GetObjecterBy(UINT Pos)
	{
		if (Pos >= m_Name2pObject.size()) {
			return NULL;
		}
		strName2pObject::iterator it = m_Name2pObject.begin();
		for (; Pos>0; --Pos,++it)
		{
			
		}
		return it->second;
		return NULL;
	}*/

	Objecter* GetObjecterBy(LPCTSTR lpszName)
	{
		ASSERT(lpszName);
		if (!lpszName || !lpszName[0]) {
			return NULL;
		}
		strName2pObject::iterator it = m_Name2pObject.find(lpszName);
		if (it != m_Name2pObject.end()) {
			return it->second;
		}
		return NULL;
	}

	HWND CreateObjecter(LPCTSTR lpszClass, LPCTSTR lpszName, HWND hWndParent, LPCTSTR lpszXml, UINT XmlFlag)
	{
		T* pT = static_cast<T*>(this);
		HWND hWndCtrl = NULL;
		Objecter* pObjecter = pT->GetObjecterBy(lpszName);
		if (pObjecter) {
			hWndCtrl = (HWND)pObjecter;
		} else {
			hWndCtrl = Objecter::CreateObject(pObjecter, lpszClass, hWndParent, lpszXml, XmlFlag);
			if (!hWndCtrl) {
				Objecter::DestroyObject(pObjecter);
			} 
			hWndCtrl = (HWND)pObjecter;
			if (pObjecter) {
				pT->OnCreateObjecter(lpszName, pObjecter);
				m_Name2pObject[lpszName] = pObjecter;
			}
		}
		return hWndCtrl;
		return NULL;
	}

	void OnCreateObjecter(LPCTSTR lpszName, Objecter* pObjecter)
	{
		
	}

	/*void DestroyObjecter(UINT Pos)
	{
		ASSERT(Pos < m_Name2pObject.size());
		if (Pos >= m_Name2pObject.size()) {
			return;
		}
		strName2pObject::iterator it = m_Name2pObject.begin() + Pos;
		Objecter::DestroyObject(it->second);
		m_Name2pObject.erase(it);
	}*/

	void DestroyObjecter(LPCTSTR lpszName)
	{
		T* pT = static_cast<T*>(this);
		ASSERT(lpszName);
		if (!lpszName || !lpszName[0]) {
			return;
		}
		strName2pObject::iterator it = m_Name2pObject.find(lpszName);
		if (it != m_Name2pObject.end()) {
			pT->OnDestroyObjecter(it->first.c_str(), it->second);
			Objecter::DestroyObject(it->second);
			m_Name2pObject.erase(it);
		}
	}

	void DestroyObjecter(Objecter* pObjecter)
	{
		T* pT = static_cast<T*>(this);
		ASSERT(pObjecter);
		if (!pObjecter) {
			return;
		}
		strName2pObject::iterator it = m_Name2pObject.begin();
		for (; it != m_Name2pObject.end(); ++it)
		{
			if (it->second == pObjecter) {
				pT->OnDestroyObjecter(it->first.c_str(), it->second);
				Objecter::DestroyObject(it->second);
				m_Name2pObject.erase(it);
				break;
			}
		}
	}

	void DestroyAllObjecter()
	{
		T* pT = static_cast<T*>(this);
		strName2pObject::iterator it = m_Name2pObject.begin();
		for (; it != m_Name2pObject.end(); ++it)
		{
			pT->OnDestroyObjecter(it->first.c_str(), it->second);
			Objecter::DestroyObject(it->second);
		}
		m_Name2pObject.clear();
	}

	void OnDestroyObjecter(LPCTSTR lpszName, Objecter* pObjecter)
	{
		ASSERT(pObjecter);
	}

	void BroadcastSend(Event& evt)
	{
		T* pT = static_cast<T*>(this);
		strName2pObject::iterator it = m_Name2pObject.begin();
		for (; it != m_Name2pObject.end(); ++it)
		{
			Objecter* pObject = it->second;
			if (pObject) {
				pT->SendEvent(pObject, evt);
			}
		}
	}

	void BroadcastPost(Event& evt)
	{
		strName2pObject::iterator it = m_Name2pObject.begin();
		for (; it != m_Name2pObject.end(); ++it)
		{
			Objecter* pObject = it->second;
			if (pObject) {
				pT->SendEvent(pObject, evt);
			}
		}
	}

	void BroadcastSend(long evt, long value, ObjectPtr objPtr)
	{
		T* pT = static_cast<T*>(this);
		pT->BroadcastSend(Event(pT, 0, evt, value, objPtr));
	}

	void BroadcastPost(long evt, long value, ObjectPtr objPtr)
	{
		T* pT = static_cast<T*>(this);
		pT->BroadcastPost(Event(pT, 0, evt, value, objPtr));
	}

	long BroadcastHandle(Event& evt)
	{
		ASSERT(!evt.handled);
		T* pT = static_cast<T*>(this);
		long rlt = RLT_UNKNOWN;
		strName2pObject::iterator it = m_Name2pObject.begin();
		for (; it != m_Name2pObject.end(); ++it)
		{
			Objecter* pObject = it->second;
			if (pObject) {
				pT->SendEvent(pObject, evt);
				if (evt.handled) {
					break;
				}
			}
		}
		return rlt;
	}

	long BroadcastHandle(long evt, long value, ObjectPtr objPtr)
	{
		T* pT = static_cast<T*>(this);
		return pT->BroadcastHandle(Event(pT, 0, evt, value, objPtr));
	}

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_DE_NOTIFY,OnNotify)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
	END_EVT_MAP()

	long OnNotify(Event& evt)
	{
		T* pT = static_cast<T*>(this);
		strName2pObject::iterator it = m_Name2pObject.begin();
		for (; it != m_Name2pObject.end(); ++it)
		{
			Objecter* pObject = it->second;
			if (pObject) {
				pT->SendEvent(pObject, evt);
			}
		}
		return RLT_OK;
	}
};

#endif//_H_OBJECTERMAP_H_