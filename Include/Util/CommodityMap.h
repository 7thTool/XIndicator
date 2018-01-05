#ifndef _H_COMMODITYMAP_H_
#define _H_COMMODITYMAP_H_

#include <Indicator/IndicatorEx.h>

template<class T>
class FieldDataMap
{
	typedef FieldDataMap<T> This;
public:
	FieldDataMap()
	{
	}

public:
	void OnFieldDataChanged(Event& evt)
	{
		evt.handled = false;
	}

	BEGIN_EVT_MAP(This)
		//ON_EVT(EVT_PLAT_CALL,OnCall)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
	END_EVT_MAP()

	//long OnCall(Event& evt);
	long OnNotify(Event& evt)
	{
		switch(evt.value)
		{
		case MAKEVALUE(MNOTIFY_PLAT_DE,CNOTIFY_DE_RESPONSE_FIELD_VALUE):
			{
				REQ_FIELDDATAInfoPtr reqfieldptr = REQ_FIELDDATAInfoPtr::dynamicCast(evt.objPtr);
				if (reqfieldptr) {
					if (reqfieldptr->IsFinished()) {
						T* pT = static_cast<T*>(this);
						COMREF Commodity = {0};
						pT->GetCurCommodity(&Commodity);
						if (std::find(reqfieldptr->Commoditys.begin(), reqfieldptr->Commoditys.end(), Commodity) != reqfieldptr->Commoditys.end()) {
							pT->OnFieldDataChanged(evt);
						}
					}
				}
			}
			break;
		case MAKEVALUE(MNOTIFY_PLAT_DE,CNOTIFY_DE_PUSH_FIELD_VALUE):
			{
				N_FIELDDATAInfoPtr fielddataPtr = N_FIELDDATAInfoPtr::dynamicCast(evt.objPtr);
				if (fielddataPtr) {
					T* pT = static_cast<T*>(this);
					COMREF Commodity = {0};
					pT->GetCurCommodity(&Commodity);
					if (fielddataPtr->Commodity == Commodity) {
						pT->OnFieldDataChanged(evt);
					}
				}
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

template<class T>
class CalcDataMap : public FieldDataMap<T>
{
	typedef CalcDataMap<T> This;
	typedef FieldDataMap<T> Base;
public:
	CalcDataMap():m_pCalcData(NULL)
	{
	}
	~CalcDataMap()
	{
		ClearCalcData();
	}

protected:
	CALCDATA* m_pCalcData;
	//REQ_HISDATAInfoPtr m_ReqHisDataPtr;

public:
	void ClearCalcData()
	{
		if (m_pCalcData) {
			iReleaseData((voidptr)m_pCalcData);
			m_pCalcData = NULL;
		}
	}
	void LoadCalcData(COMREF Commodity, ENUM_TIMEFRAMES Period, int PeriodEx = 0, ENUM_DWTYPE dwtype = DW_FORWARD, unsigned long dwdate = 0, UINT uFlags = REF_CALCDATA_NONE)
	{
		ASSERT(!m_pCalcData);
		m_pCalcData = (CALCDATA*)iRefDataEx(Commodity, Period2iPeriod(Period,PeriodEx), dwtype, dwdate, uFlags);
	}
	/*void ResetRequestHisData()
	{
		T* pT = static_cast<T*>(this);
		if (m_ReqHisDataPtr) {
			pT->SendEvent(_DataPtr, EVT_PLAT_POST, MAKEVALUE(MREQUEST_PLAT_DE,CREQUEST_DE_CANCEL), m_ReqHisDataPtr);
		}
	}
	void RequestHisData(COMREF Commodity, ENUM_TIMEFRAMES Period, int PeriodEx = 0)
	{
		T* pT = static_cast<T*>(this);
		if (!m_ReqHisDataPtr) {
			m_ReqHisDataPtr = new REQ_HISDATAInfo();
		}
		m_ReqHisDataPtr->Commodity = Commodity;
		m_ReqHisDataPtr->Period = Period;
		m_ReqHisDataPtr->PeriodEx = PeriodEx;
		m_ReqHisDataPtr->Type = 1;
		m_ReqHisDataPtr->DateTime = (unsigned long)(-1);
		m_ReqHisDataPtr->Size = 288;
		m_ReqHisDataPtr->SetFinishRate(0);
		pT->SendEvent(_DataPtr, EVT_PLAT_POST, MAKEVALUE(MREQUEST_PLAT_DE,CREQUEST_DE_HISDATA), m_ReqHisDataPtr);
	}*/

	ENUM_TIMEFRAMES GetPeriod(int* pPeriodEx = NULL)
	{
		if (m_pCalcData) {
			return iPeriod2Period(m_pCalcData->period,pPeriodEx);
		}
		return CYC_MAX;
	}

	int GetDigits()
	{
		if (m_pCalcData) {
			return m_pCalcData->digits;
		}
		return 0;
	}

	BOOL IsBarOk()
	{
		if (m_pCalcData) {
			if (m_pCalcData->count>0 && m_pCalcData->bars) {
				return TRUE;
			}
		}
		return FALSE;
	}

	BAR* GetBar()
	{
		if (m_pCalcData) {
			return m_pCalcData->bars;
		}
		return NULL;
	}

	UINT GetBarCount()
	{
		if (m_pCalcData) {
			return m_pCalcData->count;
		}
		return 0;
	}

	BOOL IsBarPosOk(int nPos)
	{
		if (nPos>=0&&nPos<m_pCalcData->count) {
			return TRUE;
		}
		return FALSE;
	}

	double GetFieldValue(INDICATOR_FIELD field)
	{
		if (m_pCalcData) {
			return m_pCalcData->field[field];
		}
		return 0.;
	}

	void OnHisDataChanged(Event& evt)
	{
		evt.handled = false;
	}

	BEGIN_EVT_MAP(This)
		//ON_EVT(EVT_PLAT_CALL,OnCall)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
		CHAIN_EVT_MAP(Base)
	END_EVT_MAP()

	//long OnCall(Event& evt);
	long OnNotify(Event& evt)
	{
		switch(evt.value)
		{
			//////////////////////////////////////////////////////////////////////////
		case MAKEVALUE(MNOTIFY_PLAT_DE,CNOTIFY_DE_RESPONSE_HISDATA):
			{
				REQ_HISDATAInfoPtr hisdataPtr = REQ_HISDATAInfoPtr::dynamicCast(evt.objPtr);
				if (hisdataPtr) {
					if (hisdataPtr->IsFinished() && hisdataPtr->IsChanged()) {
						T* pT = static_cast<T*>(this);
						COMREF Commodity = {0};
						pT->GetCurCommodity(&Commodity);
						if (hisdataPtr->Commodity == Commodity) {
							pT->OnHisDataChanged(evt);
						} else {
						}
					}
				}
			}
			break;
		case MAKEVALUE(MNOTIFY_PLAT_DE,CNOTIFY_DE_PUSH_HISDATA):
			{
				N_HISDATAInfoPtr hisdataPtr = N_HISDATAInfoPtr::dynamicCast(evt.objPtr);
				if (hisdataPtr) {
					T* pT = static_cast<T*>(this);
					COMREF Commodity = {0};
					pT->GetCurCommodity(&Commodity);
					if (hisdataPtr->Commodity == Commodity) {
						pT->OnHisDataChanged(evt);
					}
				}
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


#endif//_H_COMMODITYMAP_H_