// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <Util/ObjecterMap.h>

//////////////////////////////////////////////////////////////////////////

class XFrameManager 
	: virtual public Objecter
	, public EvtIdler
{
	typedef XFrameManager This;
public:
	XFrameManager();
	virtual ~XFrameManager();

	virtual LPCTSTR GetThisClassName();

	virtual HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual void Destroy();

	Objecter* GetIndicator();
	virtual void GetPushInfo();

	virtual void OnIdle(unsigned int tick);

protected:
	Objecter* m_pIndicator;
	UINT m_nReqPushTimer;

protected:
	class SmartKBKindObject : public SmartKBObject
	{
	protected:
		const KindInfo& m_Kind;
	public:
		SmartKBKindObject(const KindInfo& Kind);

		const KindInfo& GetKind() { return m_Kind; }

		virtual LPCTSTR GetKey(COLORREF* lpColor = NULL);
		virtual LPCTSTR GetName(COLORREF* lpColor = NULL);
		virtual LPCTSTR GetOwner(COLORREF* lpColor = NULL);
		virtual BOOL GetObject(LPVOID lpObject, int nType);
	};

	class SmartKBCommodityObject : public SmartKBObject
	{
	protected:
		const KindInfo& m_Kind;
		const COMREF& m_Commodity;
	public:
		SmartKBCommodityObject(const KindInfo& Kind, const COMREF& Commodity);

		const KindInfo& GetKind() { return m_Kind; }
		const COMREF& GetCommodity() { return m_Commodity; }

		virtual LPCTSTR GetKey(COLORREF* lpColor = NULL);
		virtual LPCTSTR GetName(COLORREF* lpColor = NULL);
		virtual LPCTSTR GetOwner(COLORREF* lpColor = NULL);
		virtual BOOL GetObject(LPVOID lpObject, int nType);
	};

protected:
	AllKindListInfoPtr m_AllKindInfoPtr;
	struct CommodityListInfoPtrLess
	{
		bool operator()(const CommodityListInfoPtr& x, const CommodityListInfoPtr& y) const
		{
			ASSERT(x&&y);
			return x->Kind.KindList[0] < y->Kind.KindList[0];
		}
	};
	typedef std::set<CommodityListInfoPtr,CommodityListInfoPtrLess> AllCommodityListInfo;
	AllCommodityListInfo m_AllCommodityList;
	CommodityListInfoPtr m_AllCommodityListInfoPtr;

	CriticalSection m_SmartKBSection;
	SmartKBInfoPtr m_SmartKBKindInfoPtr;
	SmartKBInfoPtr m_SmartKBCommkodityInfoPtr;

	ObjectPushInfoPtr m_PushInfoPtr;
	REQ_PushInfoPtr m_ReqPushPtr;

	TradeInfoPtr m_TradeInfoPtr;

	void LoadTradeInfo();

	long GetTradeInfo(TradeInfoPtr& objPtr);

	void LoadKindInfoPtr();

	void LoadSmartKBInfoPtr();

	long GetSmartKBInfo(SmartKBInfoPtr& objPtr);

public:
	BEGIN_EVT_MAP(XFrame)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
	END_EVT_MAP()

	long OnCall(Event& evt);
	long OnNotify(Event& evt);
};

//////////////////////////////////////////////////////////////////////////

class XFrame 
	: public XFrameManager
	, public ObjecterMap<XFrame>
	, public MultiObjecterMap<XFrame>
{
	typedef XFrame This;
	typedef XFrameManager Base;
	typedef ObjecterMap<XFrame> ObjectMap;
	typedef MultiObjecterMap<XFrame> MultiObjectMap;
public:
	XFrame();

	virtual HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual void Destroy();

	virtual void GetPushInfo();

public:
	BEGIN_EVT_MAP(XFrame)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
		CHAIN_EVT_MAP(ObjectMap)
		CHAIN_EVT_MAP(Base)
	END_EVT_MAP()

	long OnCall(Event& evt);
	long OnNotify(Event& evt);
};
