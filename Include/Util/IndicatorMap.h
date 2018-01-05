#ifndef _H_INDICATORMAP_H_
#define _H_INDICATORMAP_H_

#include "ObjecterMap.h"
#include "CommodityMap.h"

template<class T>
class IndicatorMap
{
	typedef IndicatorMap<T> This;
public:
	IndicatorMap()
	{
		
	}
	~IndicatorMap()
	{

	}

protected:
	IndicatorCalcInfoPtr m_iCalcInfoPtr;
	IndicatorDispInfoPtr m_iDispInfoPtr;
	IndicatorDispInfoExPtr m_iDispInfoExPtr;

public:
	void Clear()
	{
		m_iCalcInfoPtr = 0;
		m_iDispInfoPtr = 0;
		m_iDispInfoExPtr = 0;
	}
	const IndicatorCalcInfoPtr& GetiCalcInfoPtr()
	{
		return m_iCalcInfoPtr;
	}
	const IndicatorDispInfoPtr& GetiDispInfoPtr()
	{
		return m_iDispInfoPtr;
	}
	const IndicatorDispInfoExPtr& GetiDispInfoExPtr()
	{
		return m_iDispInfoExPtr;
	}

	const COMREF& GetObject()
	{
		return m_iCalcInfoPtr->Object;
	}

	ENUM_TIMEFRAMES GetPeriod(int* pPeriodEx)
	{
		if (pPeriodEx) {
			*pPeriodEx = m_iCalcInfoPtr->PeriodEx;
		}
		return m_iCalcInfoPtr->Period;
	}

	ENUM_DWTYPE GetDWType(unsigned long* pDWDate)
	{
		if (pDWDate) {
			*pDWDate = m_iCalcInfoPtr->DWDate;
		}
		return m_iCalcInfoPtr->DWType;
	}

	void GetRect(LPRECT lpRect)
	{
		
	}

	void GetLeftRect(LPRECT lpRect)
	{
		T* pT = static_cast<T*>(this);
		pT->GetRect(lpRect);
		if(m_iDispInfoPtr->InfoWidth>0) {
			lpRect->right = m_iDispInfoPtr->InfoWidth;
		} else {
			lpRect->right = lpRect->left;
		}
	}

	void GetTopRect(LPRECT lpRect)
	{
		T* pT = static_cast<T*>(this);
		pT->GetRect(lpRect);
		lpRect->bottom = lpRect->top + m_iDispInfoPtr->InfoHeight + m_iDispInfoPtr->TopSpace;
	}

	void GetRightRect(LPRECT lpRect)
	{
		T* pT = static_cast<T*>(this);
		pT->GetRect(lpRect);
		if(m_iDispInfoPtr->InfoWidth >= 0) {
			lpRect->left = lpRect->right;
		} else {
			lpRect->left = lpRect->right + m_iDispInfoPtr->InfoWidth;
		}
	}

	void GetBottomRect(LPRECT lpRect)
	{
		T* pT = static_cast<T*>(this);
		pT->GetRect(lpRect);
		lpRect->top = lpRect->bottom - m_iDispInfoPtr->BottomSpace;
	}

	void GetTitleRect(LPRECT lpRect)
	{
		GetTopRect(lpRect);
		if (IsInfoBarLeft()) {
			RECT rcLeft;
			GetLeftRect(&rcLeft);
			lpRect->left = rcLeft.right;
		} else {
			RECT rcRight;
			GetLeftRect(&rcRight);
			lpRect->right = rcRight.left;
		}
		lpRect->bottom = lpRect->top + m_iDispInfoPtr->InfoHeight;
	}

	void GetMainRect(LPRECT lpRect)
	{
		T* pT = static_cast<T*>(this);
		pT->GetRect(lpRect);
		RECT rcTop,rcBottom;
		GetTopRect(&rcTop);
		GetBottomRect(&rcBottom);
		lpRect->top = rcTop.bottom;
		lpRect->bottom = rcBottom.top;
	}

	void GetTechRect(LPRECT lpRect)
	{
		T* pT = static_cast<T*>(this);
		pT->GetRect(lpRect);
		RECT rcTop,rcBottom;
		GetTopRect(&rcTop);
		GetBottomRect(&rcBottom);
		lpRect->top = rcTop.bottom;
		lpRect->bottom = rcBottom.top;

		RECT rcLeft,rcRight;
		GetLeftRect(&rcLeft);
		GetRightRect(&rcRight);
		lpRect->left = rcLeft.right;
		lpRect->right = rcRight.left;
	}

	void GetInfoBarRect(LPRECT lpRect)
	{
		if (m_iDispInfoPtr->InfoWidth >= 0) {
			GetLeftRect(lpRect);
		} else {
			GetRightRect(lpRect);
		}
	}

	bool IsInfoBarLeft()
	{
		if (m_iDispInfoPtr->InfoWidth < 0) {
			return false;
		}
		return true;
	}

	int GetBarWidth()
	{
		T* pT = static_cast<T*>(this);
		return pT->GetDispInfoPtr()->nBarWidth[m_iDispInfoPtr->Scale];
	}

	int GetBarPitch()
	{
		T* pT = static_cast<T*>(this);
		return pT->GetDispInfoPtr()->nBarSpace[m_iDispInfoPtr->Scale];
	}

	bool IsBarDispOk()
	{
		if (m_iDispInfoPtr->Start>=0&&m_iDispInfoPtr->Count>=0) {
			return true;
		}
		return false;
	}

	int GetBarDispStart()
	{
		return m_iDispInfoPtr->Start;
	}

	int GetBarDispEnd()
	{
		return m_iDispInfoPtr->Start + m_iDispInfoPtr->Count;
	}

	int GetBarDispCount()
	{
		return m_iDispInfoPtr->Count;
	}

	int GetBarDispMaxCount()
	{
		return m_iDispInfoPtr->MaxCount;
	}

	bool IsBarDispPosOk(int nPos)
	{
		if (nPos>=m_iDispInfoPtr->Start&&nPos<(m_iDispInfoPtr->Start+m_iDispInfoPtr->Count)) {
			return true;
		}
		return false;
	}

	void OnIndicatorCalcInfoChanged()
	{

	}

	void OnIndicatorDispInfoChanged()
	{

	}

	void OnIndicatorDispInfoExChanged()
	{

	}

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		//ON_EVT(EVT_DE_NOTIFY,OnNotify)
	END_EVT_MAP()

	long OnCall(Event& evt)
	{
		switch(evt.value)
		{
		case MAKEVALUE(MSET_PLAT_INDICATOR,CSET_INDICATOR_CALCINFO):
			{
				T* pT = static_cast<T*>(this);
				m_iCalcInfoPtr = IndicatorCalcInfoPtr::dynamicCast(evt.objPtr);
				pT->OnIndicatorCalcInfoChanged();
				return RLT_OK;
			}
			break;
		case MAKEVALUE(MSET_PLAT_INDICATOR,CSET_INDICATOR_DISPINFO):
			{
				T* pT = static_cast<T*>(this);
				m_iDispInfoPtr = IndicatorDispInfoPtr::dynamicCast(evt.objPtr);
				pT->OnIndicatorDispInfoChanged();
				return RLT_OK;
			}
			break;
		case MAKEVALUE(MSET_PLAT_INDICATOR,CSET_INDICATOR_DISPINFOEX):
			{
				T* pT = static_cast<T*>(this);
				m_iDispInfoExPtr = IndicatorDispInfoExPtr::dynamicCast(evt.objPtr);
				pT->OnIndicatorDispInfoExChanged();
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


#endif//_H_INDICATORMAP_H_