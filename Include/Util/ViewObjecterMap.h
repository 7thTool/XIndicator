#ifndef _H_VIEWOBJECTERMAP_H_
#define _H_VIEWOBJECTERMAP_H_

#include "WndObjecterMap.h"
#include "WndObjecter.h"

template<class T>
class MultiViewObjecterMap : public MultiWndObjecterMap<T>
{
	typedef MultiViewObjecterMap<T> This;
	typedef MultiWndObjecterMap<T> Base;
public:
	void OnCreateObjecter(Objecter* pObjecter)
	{
		T* pT = static_cast<T*>(this);

		Base::OnCreateObjecter(pObjecter);

		WndObjecter* pWndObjecter = dynamic_cast<WndObjecter*>(pObjecter);
		if (pWndObjecter) {
			const ViewInfoPtr & vInfoPtr = pT->GetViewInfoPtr();
			if (vInfoPtr) {
				pT->SendEvent(pWndObjecter, EVT_PLAT_CALL, MAKEVALUE(MSET_PLAT_OBJECT,CSET_VIEW_INFO), vInfoPtr);
			}
			const ViewDispInfoPtr & vDispInfoPtr = pT->GetViewDispInfoPtr();
			if (vDispInfoPtr) {
				pT->SendEvent(pWndObjecter, EVT_PLAT_CALL, MAKEVALUE(MSET_PLAT_OBJECT,CSET_VIEW_DISPINFO), vDispInfoPtr);
			}
		}
	}
};

template<class T>
class MultiNameViewObjecterMap : public MultiNameWndObjecterMap<T>
{
	typedef MultiNameViewObjecterMap<T> This;
	typedef MultiNameWndObjecterMap<T> Base;
public:
	void OnCreateObjecter(LPCTSTR lpszName, Objecter* pObjecter)
	{
		T* pT = static_cast<T*>(this);

		Base::OnCreateObjecter(lpszName, pObjecter);

		WndObjecter* pWndObjecter = dynamic_cast<WndObjecter*>(pObjecter);
		if (pWndObjecter) {
			const ViewInfoPtr & vInfoPtr = pT->GetViewInfoPtr();
			if (vInfoPtr) {
				pT->SendEvent(pWndObjecter, EVT_PLAT_CALL, MAKEVALUE(MSET_PLAT_OBJECT,CSET_VIEW_INFO), vInfoPtr);
			}
			const ViewDispInfoPtr & vDispInfoPtr = pT->GetViewDispInfoPtr();
			if (vDispInfoPtr) {
				pT->SendEvent(pWndObjecter, EVT_PLAT_CALL, MAKEVALUE(MSET_PLAT_OBJECT,CSET_VIEW_DISPINFO), vDispInfoPtr);
			}
		}
	}
};

template<class T>
class ViewObjecterMap : public WndObjecterMap<T>
{
	typedef ViewObjecterMap<T> This;
	typedef WndObjecterMap<T> Base;
public:
};

#endif//_H_VIEWOBJECTERMAP_H_