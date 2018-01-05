#ifndef _H_XINDICATORAPI_MODULE_H_
#define _H_XINDICATORAPI_MODULE_H_

#include "../Util/ObjecterMap.h"
#include "../Util/OrderTicketMap.h"
#include "XIndicatorApiImp.h"

class XINDICATOR_API XIndicatorApiModule 
	: public XIndicatorApiImp
	, public ObjecterMap<XIndicatorApiModule>
	, public OrderTicketMap<XIndicatorApiModule>
{
	typedef XIndicatorApiModule This;
	typedef XIndicatorApiImp Base;
	typedef ObjecterMap<XIndicatorApiModule> ObjectMap;
	typedef OrderTicketMap<XIndicatorApiModule> OrderMap;
	DECLARE_DYNCREATE_OBJECTER(XIndicatorApiModule,_T("XIndicatorApiModule"),Objecter)
public:
	XIndicatorApiModule();
	virtual ~XIndicatorApiModule();

	virtual HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual void Destroy();

	/*LPCTSTR GetAppPath();
	LPCTSTR GetAppData();
	LPCTSTR GetIndicatorPath();
	LPCTSTR GetInidcatorData();*/
	//LPCTSTR GetTraderPath();

	virtual void OnIdle(unsigned int tick);

protected:
	//TCHAR m_szAppPath[MAX_PATH];
	//TCHAR m_szIndicatorPath[MAX_PATH];
	//TCHAR m_szIndicatorData[MAX_PATH];
	////TCHAR m_szTraderPath[MAX_PATH];
	//TCHAR m_szDataPath[MAX_PATH];

protected:
	AccountListInfoPtr m_AccountListPtr;
	int m_AccountIndex;
	AccountInfoPtr m_AccountPtr;

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
	COMREFLIST m_ObjectList;
	SmartKBInfoPtr m_FindInfoPtr;

	typedef std::map<COMREF,FIELDVALUEListInfoPtr> FIELDDataMap;
	FIELDDataMap m_FieldDataMap;
	class ReqFieldDataInfo
	{
	public:
		ReqFieldDataInfo()
		{
			//memset(&object,0,sizeof(object));
			flags = 0;
			reqPtr = 0;
			LastTickCount = 0;
		}

		//COMREF object;
		UINT flags;
		REQ_FIELDDATAInfoPtr reqPtr;
		unsigned long LastTickCount;
	};
	/*struct ReqFieldDataInfoLess
	{
		bool operator()(const ReqFieldDataInfo const& x, const ReqFieldDataInfo const& y) const
		{
			if (x.object < y.object) {
				return true;
			} else if (x.object > y.object) {
				return false;
			}
			return false;
		}
	};*/
	typedef std::map<COMREF,ReqFieldDataInfo> ReqFieldDataMap;
	ReqFieldDataMap m_ReqFieldDataMap;

	class CalcDataKey
	{
	public:
		CalcDataKey()
		{
			memset(&object,0,sizeof(object));
			period = 0;
			dwtype = DW_FORWARD;
			dwdate = 0;
		}

		COMREF object;				//当前商品
		int period;					//当前交易品种的周期,以秒为单位的周期1秒=1 1分钟=60 5分钟=300......。
		ENUM_DWTYPE dwtype;			//除权类型
		unsigned long dwdate;		//指定权息日
	};
	struct CalcDataKeyLess
	{
		bool operator()(const CalcDataKey & x, const CalcDataKey & y) const
		{
			if (x.object < y.object) {
				return true;
			} else if (x.object > y.object) {
				return false;
			}

			if (x.period < y.period) {
				return true;
			} else if (x.period > y.period) {
				return false;
			}

			if (x.dwtype < y.dwtype) {
				return true;
			} else if (x.dwtype > y.dwtype) {
				return false;
			}
			if (x.dwdate < y.dwdate) {
				return true;
			} else if (x.dwdate > y.dwdate) {
				return false;
			}
			
			return false;
		}
	};
	class CalcDataValue
	{
	public:
		CalcDataValue()
		{
			flags = 0;
			pCalcData = NULL;
			//hisdataptr;
			refcount = 0;
		}

		UINT flags;
		CALCDATA* pCalcData;		//计算数据
		HisDataInfoPtr hisdataptr;	//数据源
		long refcount;				//引用计数
	};
	typedef std::map<CalcDataKey,CalcDataValue,CalcDataKeyLess> CALCDATAMap;
	CALCDATAMap m_CalcDataMap;
	CALCDATAMap m_RemoveCalcDataMap;
	class ReqCalcDataKey
	{
	public:
		ReqCalcDataKey()
		{
			memset(&object,0,sizeof(object));
			period = 0;
		}

		COMREF object;
		int period;
	};
	struct ReqCalcDataKeyLess
	{
		bool operator()(const ReqCalcDataKey const& x, const ReqCalcDataKey const& y) const
		{
			if (x.object < y.object) {
				return true;
			} else if (x.object > y.object) {
				return false;
			}
			if (x.period < y.period) {
				return true;
			}
			return false;
		}
	};
	class ReqCalcDataValue
	{
	public:
		ReqCalcDataValue()
		{
			reqPtr = 0;
			LastTickCount = 0;
		}

		REQ_HISDATAInfoPtr reqPtr;
		unsigned long LastTickCount;
	};
	typedef std::map<ReqCalcDataKey,ReqCalcDataValue,ReqCalcDataKeyLess> ReqCalcDataMap;
	ReqCalcDataMap m_ReqCalcDataMap;

	//

	//std::tstringarray m_AllIndicatorNames;
	//typedef std::map<std::tstring,INDICATORCONTEXTINFO> DefaultIndicatorMap;
	//DefaultIndicatorMap m_DefaultIndicatorMap;
	//typedef std::set<Indicator*> pIndicatorSet;
	//pIndicatorSet m_pIndicatorSet;

	////这里不包含界面显示的指标，只有后台引用的指标；
	////因为界面的指标参数会因为用户操作发生变化，或者直接被界面删除；
	////而后台指标，是不会的。
	//class IndicatorRefInfo
	//{
	//public:
	//	IndicatorRefInfo()
	//		//:ref(0)
	//		:dataptr(NULL)
	//	{
	//		//
	//	}
	//	void AddRef(Indicator* parent, LPCTSTR scripts, LPCTSTR language, CALCDATA* dataptr)
	//	{
	//		parents.push_back(parent);
	//		this->scripts = scripts?scripts:_T("");
	//		this->language = language?language:_T("");
	//		this->dataptr = dataptr;
	//	}
	//	void AddRef(Indicator* parent)
	//	{
	//		parents.push_back(parent);
	//	}
	//	void RemoveRef(Indicator* parent)
	//	{
	//		std::vector<Indicator*>::iterator it = std::find(parents.begin(),parents.end(),parent);
	//		if (it!=parents.end()) {
	//			parents.erase(it);
	//		}
	//	}
	//	bool FindRef(Indicator* parent)
	//	{
	//		std::vector<Indicator*>::iterator it = std::find(parents.begin(),parents.end(),parent);
	//		if (it!=parents.end()) {
	//			return true;
	//		}
	//		return false;
	//	}
	//	int Count()
	//	{
	//		return parents.size();
	//	}
	//	bool IsEmpty()
	//	{
	//		return parents.empty();
	//	}
	//	//long ref;
	//	std::vector<Indicator*> parents;
	//	std::tstring scripts;
	//	std::tstring language;
	//	voidptr dataptr;
	//};
	//typedef std::map<Indicator*,IndicatorRefInfo> pIndicatorMap;
	//pIndicatorMap m_mapIndicators; 
	//pIndicatorMap m_mapRemoveIndicators;

	bool m_bTradeable;
	int m_OrderPool; //MODE_ORDERS,MODE_TRADES
	OrderListInfoPtr m_OrderListPtr;
	int m_OrderIndex; 
	OrderInfo m_OrderInfo; //当前操作的Order

	//////////////////////////////////////////////////////////////////////////

public:
	int TemplatesTotal();
	int TemplateGet(int offset, wchar_t* str, int len);

protected:
	int FindUser(LPCSTR lpszUser, LPCSTR lpszName = NULL);
	void UpdateUserInfo();
public:
	virtual int UsersTotal();
	int UserFindByIndex(int index, AccountInfoPtr& user);
	int UserFindByName(LPCSTR name, AccountInfoPtr& user);
	int UserFindByName(LPCWSTR name, AccountInfoPtr& user);
	int UserFindByObject(COMREF object, BOOL trade, AccountInfoPtr& user);

	virtual int UserSelectReset();
	virtual int UserSelectByIndex(int index);
	virtual int UserSelectByName(const char* name);
	int UserSelectByName(LPCWSTR name);
	virtual int UserSelectByObject(COMREF object);
	int UserSelectByObject(COMREF object, BOOL trade);
	int User(AccountInfoPtr& user);

	virtual double UserFieldValue(const char* field);
	virtual double UserFieldValue(const wchar_t* field);
	virtual const char* UserFieldString(const char* field, char* str, int len);
	virtual const wchar_t* UserFieldString(const wchar_t* field, wchar_t* str, int len);
	double UserFieldValue(LPCSTR field, AccountInfo* user);
	double UserFieldValue(LPCWSTR field, AccountInfo* user);
	LPCSTR UserFieldString(LPCSTR field, LPSTR str, int len, AccountInfo* user);
	LPCWSTR UserFieldString(LPCWSTR field, LPWSTR str, int len, AccountInfo* user);

protected:
	void LoadObjectInfo();
public:
	virtual int ObjectsFind(LPCSTR key, unsigned long flags);
	virtual int ObjectsFind(LPCWSTR key, unsigned long flags);
	virtual int ObjectsTotal(const char* market);
	virtual int ObjectsTotal(const wchar_t* market);
	int ObjectsTotal(unsigned char exchange, unsigned char group);
	virtual int ObjectSelect(int index, COMREF* object, int count);

	//指标数据更新和计算都是在指标模块实现，流程如下
	//首先，更新数据，清理旧数据，这样旧数据丢到Remove里
	//然后各个指标会ReleaseCalcData,而这些些数据我们已经丢到Remove过了，所以ReleaseCalcData(CALCDATA* dataptr)需要判断是否已经在Remove里了
	//组后，各个指标ReqCalcData，引用最新数据
	//注意，这整个更新过程，需要同步完成，不然可能会引用已经移除的数据，访问非法内存了。
protected:
	FIELDVALUEListInfoPtr RefFieldValue(COMREF object);
	bool ReqFieldInfo(COMREF object, UINT flags);
	bool UpdateFieldInfo(COMREF object);
	void CleanAllFieldInfo();
public:
	virtual voidptr RefCalcData(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, unsigned int flags = REF_CALCDATA_DEFAULT);
	virtual const COMREF* GetObject(voidptr dataptr, COMREF* object);
	virtual int GetPeriod(voidptr dataptr);
	virtual ENUM_DWTYPE GetExRight(voidptr dataptr, unsigned int* dwdate);
	virtual int GetPriceCount(voidptr dataptr);
	virtual unsigned int GetPriceDate(voidptr dataptr, int offset);
	virtual unsigned int GetPriceTime(voidptr dataptr, int offset);
	virtual double GetPriceValue(voidptr dataptr, int price, int offset);
	virtual double GetFinanceValue(voidptr dataptr, int finance, int offset);
	virtual double GetFieldValue(voidptr dataptr, INDICATOR_FIELD field);
	virtual int GetPriceBar(voidptr dataptr, int offset, BAR* bar);
	virtual int GetPricePosByDateTime(voidptr dataptr, unsigned long date, unsigned long time);
	virtual int GetWeightCount(voidptr dataptr);
	bool ReqCalcData(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, BOOL bForward = FALSE);
	bool UpdateCalcData(COMREF object);
	virtual void ReleaseCalcData(voidptr dataptr);
	virtual void ReleaseCalcDataAll();

	/*void SetIndicatorDefault(LPCTSTR name, INDICATORCONTEXTINFO* ctx);
	bool GetIndicatorDefault(LPCTSTR name, INDICATORCONTEXTINFO* ctx);

	int IndicatorsTotal();
	int IndicatorGet(int offset, wchar_t* str, int len, INDICATORCONTEXTINFO* ctx = NULL);

	void AddIndicator(Indicator* pIndicator);
	void RemoveIndicator(Indicator* pIndicator);
	void BroadcastToIndicator(Event& evt);

	Indicator* iRef(Indicator* parent, LPCTSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate
		, LPCTSTR scripts = NULL, LPCTSTR language = NULL, CALCDATA* dataptr = NULL);
	Indicator* iCalc(Indicator* parent, LPCTSTR name, INPUTINFO* input, CALCDATA* dataptr);
	Indicator* iScript(Indicator* parent, LPCTSTR name, INPUTINFO* input, LPCTSTR scripts, LPCTSTR language, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	Indicator* iScriptCalc(Indicator* parent, LPCTSTR name, INPUTINFO* input, LPCTSTR scripts, LPCTSTR language, CALCDATA* dataptr);
	void iRelease(Indicator* parent, Indicator* handle);
	void iReleaseAll();*/

	void SetTradeable(bool bTradeable = true);
	virtual bool IsTradeable();

	int OrderSend(COMREF object, int cmd, double volume, double price, int slippage, double stoploss, double takeprofit,
		LPCSTR comment = NULL, int magic = 0, unsigned long date = 0, unsigned long time = 0);
	int OrderSend(COMREF object, int cmd, double volume, double price, int slippage, double stoploss, double takeprofit,
		LPCWSTR comment = NULL, int magic = 0, unsigned long date = 0, unsigned long time = 0);
	
	int OrdersFind(int pool, OrderListInfoPtr& orders);
	int OrdersTotal(const OrderListInfoPtr& orders);
	int OrderFindByIndex(int index, const OrderListInfoPtr& orders, OrderInfo& order);
	int OrderFindByTicket(LPCSTR ticket, const OrderListInfoPtr& orders, OrderInfo& order);
	int OrderFindByTicket(LPCWSTR ticket, const OrderListInfoPtr& orders, OrderInfo& order);
	int OrderFindByMagic(int magic, const OrderListInfoPtr& orders, OrderInfo& order);

	int OrdersSelectReset();
	int OrdersSelect(int pool);
	int Orders(OrderListInfoPtr& orders);
	
	int OrdersTotal();
	int OrderSelectReset();
	int OrderSelectByIndex(int index);
	int OrderSelectByTicket(LPCSTR ticket);
	int OrderSelectByTicket(LPCWSTR ticket);
	int OrderSelectByMagic(int magic);

	int OrderType();
	const char* OrderTicket(char* str, int len);
	//const wchar_t* OrderTicket(wchar_t* str, int len);

	int OrderClose(double lots, double price, int slippage);
	int OrderCloseBy(int opposite);
	int OrderDelete();
	int OrderModify(double price,double stoploss,double takeprofit, unsigned long expiration);

	COMREF OrderObject();

	double OrderOpenPrice();
	double OrderClosePrice();

	unsigned long OrderOpenTime(unsigned long* date = NULL);
	unsigned long OrderCloseTime(unsigned long* date = NULL);
	unsigned long OrderExpiration(unsigned long* date = NULL);

	double OrderLots();
	double OrderProfit();
	double OrderTakeProfit();
	double OrderStopLoss();
	double OrderCommission();
	int OrderMagicNumber();
	const char* OrderComment(char* str, int len);

	double OrderFieldValue(const char* field);
	const char* OrderFieldString(const char* field, char* str, int len);

	void OnOrderTicketChanged(int orderType);

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL, OnCall)
		ON_EVT(EVT_PLAT_NOTIFY, OnNotify)
		CHAIN_EVT_MAP(ObjectMap)
		CHAIN_EVT_MAP(OrderMap)
	END_EVT_MAP()

	long OnCall(Event& evt);
	long OnNotify(Event& evt);

public:
};

#define _iModule (*(XIndicatorApiModule*)_IndicatorPtr)

#endif//_H_XINDICATORAPI_MODULE_H_