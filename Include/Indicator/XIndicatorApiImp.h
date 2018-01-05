#ifndef _H_XINDICATORAPIIMP_H_
#define _H_XINDICATORAPIIMP_H_

#include "XIndicatorApi.h"
#if XINDICATORSERVER
#include "XIndicatorImp.h"
#else
#include "XIndicatorExImp.h"
#endif//
#include <Util/Objecter.h>
#include <XLib/XStr.h>

#include <map>
#include <set>
#include <vector>
#include <functional>
using namespace std;

#define USE_MAPINDICATORS	0

class XINDICATOR_API XIndicatorApiImp 
	: public Objecter
	, public XIndicatorApi
	, public EvtIdler
{
	DECLARE_DYNCREATE_OBJECTER(XIndicatorApiImp,_T("XIndicatorApi"),Objecter)
protected:
	XIndicatorSpi* m_pSpi;
	XIndicatorQuoteProvider* m_pQuoteProvider;
	XIndicatorTradeProvider* m_pTradeProvider;
	vector<iHandle> m_iHandles;
public:
	XIndicatorApiImp();
	virtual ~XIndicatorApiImp();

	virtual HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual void Destroy();

	virtual LRESULT SetAttributeString(LPCTSTR lpszAttr, LPCTSTR lpszValue, UINT uFlags = 0);

	LPCTSTR GetAppPath();
	LPCTSTR GetAppData();
	LPCTSTR GetIndicatorPath();
	LPCTSTR GetInidcatorData();
	//LPCTSTR GetTraderPath();

protected:
	TCHAR m_szAppPath[MAX_PATH];
	TCHAR m_szIndicatorPath[MAX_PATH];
	TCHAR m_szIndicatorData[MAX_PATH];
	//TCHAR m_szTraderPath[MAX_PATH];
	TCHAR m_szDataPath[MAX_PATH];

	std::tstringarray m_AllIndicatorNames;
	typedef std::map<std::tstring,INDICATORCONTEXTINFO> DefaultIndicatorMap;
	DefaultIndicatorMap m_DefaultIndicatorMap;

	//指标引用信息，非引用指标引用信息都为空
	class IndicatorRefers
	{
	public:
		IndicatorRefers()
		{
			depth = 0;
			parents.reserve(10);
			LastRemoveRefTime = 0;
		}
		IndicatorRefers(const IndicatorRefers& o):depth(o.depth),parents(o.parents),LastRemoveRefTime(o.LastRemoveRefTime)
		{

		}
		void Add(XIndicator* parent)
		{
			parents.push_back(parent);
		}
		void Remove(XIndicator* parent)
		{
			LastRemoveRefTime = GetTickCount();
			std::vector<XIndicator*>::iterator it = std::find(parents.begin(),parents.end(),parent);
			if (it!=parents.end()) {
				parents.erase(it);
			}
		}
		bool Find(XIndicator* parent)
		{
			std::vector<XIndicator*>::iterator it = std::find(parents.begin(),parents.end(),parent);
			if (it!=parents.end()) {
				return true;
			}
			return false;
		}
		XIndicator* At(int pos)
		{
			return parents[pos];
		}
		int Count()
		{
			return parents.size();
		}
		bool IsEmpty()
		{
			return parents.empty();
		}
		bool IsDelectable()
		{
			if (IsEmpty()) {
				//if((GetTickCount()-LastRemoveRefTime)>1000) {
				return true;
				//}
			}
			return false;
		}

		int depth;
		std::vector<XIndicator*> parents;
		unsigned long LastRemoveRefTime;
	};
	class IndicatorRefInfo
	{
	public:
		IndicatorRefInfo(const wchar_t* n = NULL):name(n),handle(NULL),refers()
		{

		}
		IndicatorRefInfo(XIndicator* h):name(h->ctx.name),handle(h),refers()
		{

		}
		IndicatorRefInfo(const IndicatorRefInfo& o):name(o.name),handle(o.handle),refers(o.refers)
		{

		}

		const wchar_t* name;
		XIndicator* handle;
		IndicatorRefers refers;
	};
	struct RefIndicatorInfoLess
	{
		bool operator()(const IndicatorRefInfo const& x, const IndicatorRefInfo const& y) const
		{
			return wcsicmp(x.name,y.name)<0;
		}
	};
	std::vector<IndicatorRefInfo> m_IndicatorRefInfos;
	void InnerAllocIndicatorRefInfo(XIndicator* handle);
	void InnerFreeIndicatorRefInfo(XIndicator* handle);
	//所有创建的指标，包括界面显示的容器指标
	typedef std::map<XIndicator*,long> MapIndicator2RefInfoPos;
	MapIndicator2RefInfoPos m_pIndicator2RefInfoPos;
	long m_nMaxDepth;
	void InnerAddIndicatorRef(IndicatorRefInfo& refInfo, XIndicator* parent);
	void InnerRemoveIndicatorRef(IndicatorRefInfo& refInfo, XIndicator* parent);
#if !USE_MAPINDICATORS
#if 0
	void InnerAddIndicatorRef(int pos, XIndicator* parent);
	void InnerRemoveIndicatorRef(int pos, XIndicator* parent);
#endif//
#endif//
	void InnerUpdateIndicatorRefInfos();

	//这里不包含界面显示的指标，只有后台引用的指标；
	//因为界面的指标参数会因为用户操作发生变化，或者直接被界面删除；
	//而后台指标，是不会的。
#if USE_MAPINDICATORS
	class RefIndicatorKey
	{
	public:
		RefIndicatorKey()
		{
			parent = NULL;
			//name;
			memset(&input,0,sizeof(input));
			pool = false;
			memset(&object,0,sizeof(object));
			period = 0;
			dwtype = DW_NONE;
			dwdate = 0;
			//scripts;
			//language;
			dataptr = NULL;
		}

		XIndicator* parent;
		std::tstring name;
		INPUTINFO input;
		bool pool;
		COMREF object;
		int period;
		ENUM_DWTYPE dwtype;
		unsigned long dwdate;
		std::tstring scripts;
		std::tstring language;
		voidptr dataptr;
	};
	struct RefIndicatorKeyLess
	{
		bool operator()(const RefIndicatorKey const& x, const RefIndicatorKey const& y) const
		{
			/*if (x.indicator && y.indicator) {
				return x.indicator<y.indicator;
			} else */{
				if (x.parent<y.parent) {
					return true;
				} else if (x.parent>y.parent) {
					return false;
				}
				int cmp = _tcsicmp(x.name.c_str(),y.name.c_str());
				if (cmp<0) {
					return true;
				} else if (cmp>0) {
					return false;
				}
				cmp = _tcsicmp(x.language.c_str(),y.language.c_str());
				if (cmp<0) {
					return true;
				} else if (cmp>0) {
					return false;
				}
				cmp = _tcsicmp(x.scripts.c_str(),y.scripts.c_str());
				if (cmp<0) {
					return true;
				} else if (cmp>0) {
					return false;
				}
				if (x.pool || y.pool) {
					if (x.pool < y.pool) {
						return true;
					} else if (x.pool > y.pool) {
						return false;
					} 
				} else {
					if(x.dataptr || y.dataptr) {
						if (x.dataptr < y.dataptr) {
							return true;
						} else if (x.dataptr > y.dataptr) {
							return false;
						} 
					} else {
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
					}
				}
				InputHelper helper(const_cast<INPUTINFO*>(&x.input));
				return helper.IsLess(&y.input);
			}
		}
	};
	typedef std::map<RefIndicatorKey,long,RefIndicatorKeyLess> pRefIndicatorMap;
	pRefIndicatorMap m_mapRefIndicators; //所有创建的Ref引用指标
	pRefIndicatorMap m_mapRemoveRefIndicators; //所有需要移除的Ref引用指标

	pRefIndicatorMap::iterator InnerFindRefIndicatorIterator(pRefIndicatorMap& mapIndicators, XIndicator* handle);
	void InnerEraseRefIndicatorIterator(pRefIndicatorMap& mapIndicators, XIndicator* handle);
#else
	class RefIndicatorsLess
	{
	private:
		const std::vector<IndicatorRefInfo>& refInfos;
		const wchar_t* name;
	public:
		RefIndicatorsLess(const std::vector<IndicatorRefInfo>& r, const wchar_t* n):refInfos(r),name(n) {}

		bool operator()(const long const& x, const long const& y) const
		{
			return wcsicmp(x<0?name:refInfos[x].name,y<0?name:refInfos[y].name)<0;
		}
	};
	std::vector<long> m_RefIndicators; //所有创建的Ref引用指标，按name排过序的
	int InnerFindRefIndicatorPos(XIndicator* handle);
	int InnerFindRefIndicatorPos(const wchar_t* name, int* count);
	int InnerFindRefIndicatorPos(XIndicator* parent, LPCTSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate
		, LPCTSTR scripts = NULL, LPCTSTR language = NULL, voidptr dataptr = NULL);
#endif//
	int InnerAddRefIndicator(XIndicator* handle, XIndicator* parent);
	void InnerRemoveRefIndicator(XIndicator* handle, XIndicator* parent);

public:
	virtual void SetIndicatorDefault(LPCTSTR name, INDICATORCONTEXTINFO* ctx);
	virtual bool GetIndicatorDefault(LPCTSTR name, INDICATORCONTEXTINFO* ctx);

	virtual int IndicatorsTotal();
	virtual int IndicatorGet(int offset, wchar_t* str, int len, INDICATORCONTEXTINFO* ctx = NULL);

	virtual void AddIndicator(XIndicator* pIndicator);
	virtual void RemoveIndicator(XIndicator* pIndicator);
	virtual void BroadcastToIndicator(Event& evt);

	virtual XIndicator* RefIndicator(XIndicator* parent, LPCTSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate
		, LPCTSTR scripts = NULL, LPCTSTR language = NULL, voidptr dataptr = NULL);
	virtual XIndicator* iCalc(XIndicator* parent, LPCTSTR name, INPUTINFO* input, voidptr dataptr);
	virtual XIndicator* iScript(XIndicator* parent, LPCTSTR name, INPUTINFO* input, LPCTSTR scripts, LPCTSTR language, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	virtual XIndicator* iScriptCalc(XIndicator* parent, LPCTSTR name, INPUTINFO* input, LPCTSTR scripts, LPCTSTR language, voidptr dataptr);
	virtual void ReleaseIndicator(XIndicator* parent, XIndicator* handle);
	virtual void ReleaseIndicatorAll();

public:

	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	//virtual void Init();
	//virtual void Term();

	virtual void OnIdle(unsigned int tick);

	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	virtual void RegisterSpi(XIndicatorSpi *pSpi);
	virtual void RegisterQuoteProvider(XIndicatorQuoteProvider *pProvider);
	virtual void RegisterTradeProvider(XIndicatorTradeProvider *pProvider);

	virtual void Handle();

	virtual void UpdateHisData(const char* symbol);

	virtual void UpdateFinanceData(const char* symbol);

	virtual void UpdateFieldData(const char* symbol);

	virtual void UpdateOrderData();

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
	virtual void ReleaseCalcData(voidptr dataptr);
	virtual void ReleaseCalcDataAll();

	virtual int UsersTotal();
	virtual int UserSelectReset();
	virtual int UserSelectByIndex(int index);
	virtual int UserSelectByName(const char* name);
	virtual int UserSelectByName(const wchar_t* name);
	virtual int UserSelectByObject(COMREF object);
	virtual double UserFieldValue(const char* field);
	virtual double UserFieldValue(const wchar_t* field);
	virtual const char* UserFieldString(const char* field, char* str, int len);
	virtual const wchar_t* UserFieldString(const wchar_t* field, wchar_t* str, int len);

	virtual int ObjectsFind(const char* key, unsigned int flags);
	virtual int ObjectsFind(const wchar_t* key, unsigned int flags);
	virtual int ObjectsTotal(const char* market);
	virtual int ObjectsTotal(const wchar_t* market);
	virtual int ObjectSelect(int index, COMREF* object, int count);

	virtual bool IsTradeable();

	virtual int OrderSend(COMREF object, int cmd, double volume, double price, int slippage, double stoploss, double takeprofit,
		const char* comment = NULL, int magic = 0, unsigned long date = 0, unsigned long time = 0);
	virtual int OrderSend(COMREF object, int cmd, double volume, double price, int slippage, double stoploss, double takeprofit,
		const wchar_t* comment = NULL, int magic = 0, unsigned long date = 0, unsigned long time = 0);
	
	virtual int OrderSelectReset();
	virtual int OrdersSelect(int pool);
	virtual int OrdersTotal();
	virtual int OrderSelectByIndex(int index);
	virtual int OrderSelectByTicket(const char* ticket);
	virtual int OrderSelectByTicket(const wchar_t* ticket);
	virtual int OrderSelectByMagic(int magic);

	virtual int OrderType();
	virtual const char* OrderTicket(char* str, int len);

	virtual int OrderClose(double lots, double price, int slippage);
	virtual int OrderCloseBy(int opposite);
	virtual int OrderDelete();
	virtual int OrderModify(double price,double stoploss,double takeprofit,unsigned long expiration);

	virtual COMREF OrderObject();

	virtual double OrderOpenPrice();
	virtual double OrderClosePrice();

	virtual unsigned long OrderOpenTime(unsigned long* date);
	virtual unsigned long OrderCloseTime(unsigned long* date);
	virtual unsigned long OrderExpiration(unsigned long* date);

	virtual double OrderLots();
	virtual double OrderProfit();
	virtual double OrderTakeProfit();
	virtual double OrderStopLoss();
	virtual double OrderCommission();
	virtual int OrderMagicNumber();
	virtual const char* OrderComment(char* str, int len);

	virtual double OrderFieldValue(const char* field);
	virtual const char* OrderFieldString(const char* field, char* str, int len);

};

#define _XIndicatorPtr ((XIndicatorApiImp*)_IndicatorPtr)


#endif//_H_XINDICATORAPIIMP_H_
