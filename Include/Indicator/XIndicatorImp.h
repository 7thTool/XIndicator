#ifndef _H_XINDICATOR_HPP_
#define _H_XINDICATOR_HPP_

#include "XIndicatorEx.h"

#include "../Util/Objecter.h"

/*!
 *	@brief XINDICATORSERVER 定义.
 *
 *	用来区分XIndicator是否运行在服务器
 *	服务器基类：Indicator
 *	客户端基类：IndicatorEx
 *	Indicator和IndicatorEx接口一样，实现有所不同
 */
#define XINDICATORSERVER 0

class Indicator;
#if XINDICATORSERVER
typedef Indicator XIndicator;
#else
class IndicatorEx;
class IndicatorContainer;
typedef IndicatorEx XIndicator;
#endif//

class XINDICATOR_API InputHelper
{
public:
	INPUTINFO* m_input;
public:
	InputHelper(LPCTSTR name, INPUTINFO* input);
	InputHelper(INPUTINFO* input);

	long SetInput(LPCTSTR name, LPCTSTR value, bool visible = true, bool addorupdate = false);
	long SetInput(LPCTSTR name, double value, bool visible = true, bool addorupdate = false);
	LPCTSTR GetInput(LPCTSTR name, bool* visible = NULL) const;

	bool IsLess(const INPUTINFO* input) const;
	bool IsEqual(const INPUTINFO* input) const;
};

template<class T>
class IndicatorT
{
public:
	LPCTSTR GetName() const
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.name;
	}

	void SetName(LPCTSTR name)
	{
		T* pT = static_cast<T*>(this);
		_tcscpy(pT->ctx.name,name);
	}


	bool IsKLine() const
	{
		const T* pT = static_cast<const T*>(this);
		if (_tcsicmp(pT->ctx.name,_T("K"))==0) {
			return true;
		}
		return false;
	}

	bool IsVolume() const
	{
		const T* pT = static_cast<const T*>(this);
		if (_tcsicmp(pT->ctx.name,_T("Volume"))==0) {
			return true;
		}
		return false;
	}

	bool IsAmount() const
	{
		const T* pT = static_cast<const T*>(this);
		if (_tcsicmp(pT->ctx.name,_T("Amount"))==0) {
			return true;
		}
		return false;
	}

	long GetType() const
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.type;
	}

	void SetType(long type)
	{
		T* pT = static_cast<T*>(this);
		pT->ctx.type = type;
	}

	bool IsMain() const 
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.type==INDICATOR_TYPE_MAIN;
	}

	bool IsSecond() const 
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.type==INDICATOR_TYPE_SECOND;
	}

	bool IsPool() const 
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.type==INDICATOR_TYPE_POOL;
	}

	long GetStyle() const
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.style;
	}

	bool IsTrader() const 
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.style&INDICATOR_STYLE_TRADER;
	}

	bool IsContainer() const 
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.style&INDICATOR_STYLE_CONTAINER;
	}

	bool IsDrawLine() const 
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.style&INDICATOR_STYLE_DRAWLINE;
	}

	void SetStyle(long style)
	{
		T* pT = static_cast<T*>(this);
		pT->ctx.style = style;
	}

	bool IsRefable(XIndicator* parent) const
	{
		if (IsKLine() || IsVolume() || IsAmount()) {
			return false;
		}
		if(IsContainer()) { //不能引用容器指标
			return false;
		}
		if(IsDrawLine()) { //划线指标必须在指标视图下运行，即在IndicatorEx下运行，这样就保证了不会被随便引用，只能被指标视图或者交易指标引用
			if(parent) {
				if (!parent->IsContainer()) {
					return false;
				}
			} else {
				return false;
			}
		}
		if (IsTrader()) { //交易指标必须在指标视图下运行，即在IndicatorEx下运行，这样就保证了不会被随便引用，只能被指标视图引用或者独立调用（parent为NULL）
			if(parent) {
				if (!parent->IsContainer()) {
					return false;
				}
			}
		}
		return true;
	}

	unsigned char GetShift() const
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.shift;
	}

	void SetShift(unsigned char shift)
	{
		T* pT = static_cast<T*>(this);
		pT->ctx.shift = shift;
	}

	long SetInput(INPUTINFO* input)
	{
		T* pT = static_cast<T*>(this);
		if (input) {
			pT->ctx.input = *input;
		} else {
			memset(&pT->ctx.input,0,sizeof(INPUTINFO));
		}
		return 1;
	}

	long SetInput(LPCTSTR name, LPCTSTR value, bool visible = true, bool addorupdate = false)
	{
		T* pT = static_cast<T*>(this);
		InputHelper helper(&pT->ctx.input);
		return helper.SetInput(name,value,visible,addorupdate);
	}

	long SetInput(LPCTSTR name, double value, bool visible = true, bool addorupdate = false)
	{
		T* pT = static_cast<T*>(this);
		InputHelper helper(&pT->ctx.input);
		return helper.SetInput(name,value,visible,addorupdate);
	}

	LPCTSTR GetInput(LPCTSTR name, bool* visible = NULL) const
	{
		const T* pT = static_cast<const T*>(this);
		InputHelper helper(const_cast<INPUTINFO*>(&pT->ctx.input));
		return helper.GetInput(name,visible);
	}

	bool IsEqual(const INPUTINFO* input) const
	{
		const T* pT = static_cast<const T*>(this);
		InputHelper helper(const_cast<INPUTINFO*>(&pT->ctx.input));
		return helper.IsEqual(input);
	}

	long GetIndexCount() const
	{
		const T* pT = static_cast<const T*>(this);
		return pT->ctx.count;
	}

	LPCTSTR GetIndexName(int index) const
	{
		const T* pT = static_cast<const T*>(this);
		if (index>=0 && index<pT->ctx.count) {
			return pT->ctx.index[index].name;
		}
		return NULL;
	}

	long GetIndexStyle(int index) const
	{
		const T* pT = static_cast<const T*>(this);
		if (index>=0 && index<pT->ctx.count) {
			//return ctx.index[index].style;
		}
		return 0;
	}

	long GetIndexDigits(int index) const
	{
		const T* pT = static_cast<const T*>(this);
		if (index>=0 && index<pT->ctx.count) {
			return pT->ctx.index[index].digits;
		}
		return 0;
	}

	long GetIndexShift(int index) const
	{
		const T* pT = static_cast<const T*>(this);
		if (index>=0 && index<pT->ctx.count) {
			return pT->ctx.index[index].shift;
		}
		return 0;
	}

	long GetIndexDrawBegin(int index) const
	{
		const T* pT = static_cast<const T*>(this);
		if (index>=0 && index<pT->ctx.count) {
			return pT->ctx.index[index].begin;
		}
		return 0;
	}

	long GetIndexDraw(int index) const
	{
		const T* pT = static_cast<const T*>(this);
		if (index>=0 && index<pT->ctx.count) {
			return pT->ctx.index[index].draw;
		}
		return 0;
	}

	long GetIndexLine(int index) const
	{
		const T* pT = static_cast<const T*>(this);
		if (index>=0 && index<pT->ctx.count) {
			return pT->ctx.index[index].line;
		}
		return 0;
	}

	long GetIndexNext(int index) const
	{
		const T* pT = static_cast<const T*>(this);
		if (index>=0 && index<pT->ctx.count) {
			return pT->ctx.index[index].next;
		}
		return 0;
	}

	long GetIndexWidth(int index) const
	{
		const T* pT = static_cast<const T*>(this);
		if (index>=0 && index<pT->ctx.count) {
			return pT->ctx.index[index].width;
		}
		return 0;
	}

	COLORREF GetIndexColor(int index) const
	{
		const T* pT = static_cast<const T*>(this);
		if (index>=0 && index<pT->ctx.count) {
			return pT->ctx.index[index].color;
		}
		return 0;
	}

	long SetIndexName(int index, LPCTSTR value)
	{
		T* pT = static_cast<T*>(this);
		if (pT->IsPool()) {
			return 0;
		}
		if (index>=0 && index<MAX_INDICATOR_INDEX) {
			pT->ctx.count = max(pT->ctx.count,index+1);
			_tcscpy(pT->ctx.index[index].name,value);
			return 1;
		}
		return 0;
	}

	long SetIndexType(int index, long type)
	{
		T* pT = static_cast<T*>(this);
		if (pT->IsPool()) {
			return 0;
		}
		if (index>=0 && index<MAX_INDICATOR_INDEX) {
			pT->ctx.count = max(pT->ctx.count,index+1);
			pT->ctx.index[index].type = type;
			return RLT_OK;
		}
		return 0;
	}

	long SetIndexDigits(int index, long digits)
	{
		T* pT = static_cast<T*>(this);
		if (pT->IsPool()) {
			return 0;
		}
		if (index>=0 && index<MAX_INDICATOR_INDEX) {
			pT->ctx.count = max(pT->ctx.count,index+1);
			pT->ctx.index[index].digits = digits;
			return RLT_OK;
		}
		return 0;
	}

	long SetIndexShift(int index, long shift)
	{
		T* pT = static_cast<T*>(this);
		if (pT->IsPool()) {
			return 0;
		}
		if (index>=0 && index<MAX_INDICATOR_INDEX) {
			pT->ctx.count = max(pT->ctx.count,index+1);
			pT->ctx.index[index].shift = shift;
			return RLT_OK;
		}
		return 0;
	}

	long SetIndexBegin(int index, long begin)
	{
		T* pT = static_cast<T*>(this);
		if (pT->IsPool()) {
			return 0;
		}
		if (index>=0 && index<MAX_INDICATOR_INDEX) {
			pT->ctx.count = max(pT->ctx.count,index+1);
			pT->ctx.index[index].begin = begin;
			return RLT_OK;
		}
		return 0;
	}

	long SetIndexDraw(int index, long draw)
	{
		T* pT = static_cast<T*>(this);
		if (pT->IsPool()) {
			return 0;
		}
		if (index>=0 && index<MAX_INDICATOR_INDEX) {
			pT->ctx.count = max(pT->ctx.count,index+1);
			pT->ctx.index[index].draw = draw;
			return RLT_OK;
		}
		return 0;
	}

	long SetIndexLine(int index, long line)
	{
		T* pT = static_cast<T*>(this);
		if (pT->IsPool()) {
			return 0;
		}
		if (index>=0 && index<MAX_INDICATOR_INDEX) {
			pT->ctx.count = max(pT->ctx.count,index+1);
			pT->ctx.index[index].line = line;
			return RLT_OK;
		}
		return 0;
	}

	long SetIndexNext(int index, long next)
	{
		T* pT = static_cast<T*>(this);
		if (pT->IsPool()) {
			return 0;
		}
		if (index>=0 && index<MAX_INDICATOR_INDEX && next>=0 && next<MAX_INDICATOR_INDEX) {
			pT->ctx.count = max(pT->ctx.count,index+1);
			pT->ctx.index[index].next = next;
			return RLT_OK;
		}
		return 0;
	}

	long SetIndexWidth(int index, long width)
	{
		T* pT = static_cast<T*>(this);
		if (pT->IsPool()) {
			return 0;
		}
		if (index>=0 && index<MAX_INDICATOR_INDEX) {
			pT->ctx.count = max(pT->ctx.count,index+1);
			pT->ctx.index[index].width = width;
			return RLT_OK;
		}
		return 0;
	}

	long SetIndexColor(int index, long color)
	{
		T* pT = static_cast<T*>(this);
		if (pT->IsPool()) {
			return 0;
		}
		if (index>=0 && index<MAX_INDICATOR_INDEX) {
			pT->ctx.count = max(pT->ctx.count,index+1);
			pT->ctx.index[index].color = color;
			return RLT_OK;
		}
		return 0;
	}

};

class XINDICATOR_API IndicatorHelper : public IndicatorT<IndicatorHelper>
{
public:
	INDICATORCONTEXTINFO ctx;
public:
	IndicatorHelper(INDICATORCONTEXTINFO* p = NULL);
	IndicatorHelper(LPCTSTR name, INPUTINFO* input);
};

extern __declspec(selectany,thread) XIndicator* _pCurIndicator;

//////////////////////////////////////////////////////////////////////////

class XINDICATOR_API Indicator 
	: virtual public Objecter
	, public IndicatorT<Indicator>
{
	typedef Indicator This;
	typedef Objecter Base;
	typedef IndicatorT<Indicator> IndicatorBase;
#if XINDICATORSERVER
#else
	friend class IndicatorContainer;
#endif//
public:
	//指标信息(上下文和计算信息)
	INDICATORCONTEXTINFO ctx;
	INDICATORCALCCONTEXTINFO clx;
	INDICATORCALCINFO clc;
protected:
	//正常计算指标都父对象指针都为空，因为可以被多个父指标共同引用，但是如果不为空，说明该计算指标属于特定指标，比如策略交易指标
	XIndicator* m_pParent; 

	bool m_bInited; //是否初始化了
	bool m_bInput; //输入参数是否改变了

	//////////////////////////////////////////////////////////////////////////
	//指标计算相关信息
	std::vector<double> index[MAX_INDICATOR_INDEX]; //指标

	//依据历史数据是连续的，所以用最后和最先的BAR来判断历史数据是不是变化了
	int weight_count; //上次的权息数据
	BAR startbar;	//已经计算过的第一个BAR信息,用于辅助计算
	BAR endbar;		//已经计算过的最后一个BAR信息,用于辅助计算
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	//策略/池指标计算相关信息
	typedef std::map<COMREF,voidptr> MapPoolObjects;
	MapPoolObjects m_PoolObjects;
	//////////////////////////////////////////////////////////////////////////

	//引用的DynInfo
	std::set<COMREF> RefFieldValues;
	//引用的数据
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

		COMREF object;			//当前商品
		int period;				//当前交易品种的周期,以秒为单位的周期1秒=1 1分钟=60 5分钟=300......。
		ENUM_DWTYPE dwtype;		//除权类型
		unsigned long dwdate;   //指定权息日
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
			dataptr = NULL;
			refcount = 0;
		}

		voidptr dataptr;		//计算数据
		long refcount;			//引用计数
	};
	typedef std::map<CalcDataKey,CalcDataValue,CalcDataKeyLess> CALCDATAMap;
	CALCDATAMap refcalcdatas;
	//引用的指标
	typedef std::map<XIndicator*,long> pIndicatorMap;
	pIndicatorMap refindicators;

	//当前用户
	int m_UserIndex;
	//当前订单
	int m_OrderPool;
	int m_OrderIndex;

public:
	Indicator();
	virtual ~Indicator();

	virtual const char* c_strof(const char* name);
	virtual const wchar_t* c_strof(const wchar_t* name);

	virtual HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual void Destroy();

	void Load(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	void Save(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);

	//virtual BOOL SetInput(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual LRESULT SetAttributeString(LPCTSTR lpszAttr, LPCTSTR lpszValue, UINT uFlags = 0);
	virtual LPCTSTR GetAttributeString(LPCTSTR lpszAttr, LPTSTR lpszValue = NULL, UINT nValueLen = 0);

	virtual BOOL SetIndex(UINT nIndex, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual LRESULT SetIndexAttributeString(UINT nIndex, LPCTSTR lpszAttr, LPCTSTR lpszValue, UINT uFlags = 0);
	
public:
	XIndicator* GetParent() { return m_pParent; }

	virtual bool IsInit();

	virtual void SetTradeable(bool bTradeable = true);
	virtual bool IsTradeable();

	virtual bool IsTest(int* cursor = NULL);

	virtual long Init();
	virtual long Filter();
	virtual bool IsCalc();
	virtual long Calc(PINDICATORCALCCONTEXTINFO in);
protected:
	virtual long Calc();
	virtual void DeInit();
protected:
	virtual long DoInit();
	virtual void DoInput();
	virtual void DoPreFilter();
	virtual long DoFilter();
	virtual void DoAfterFilter();
	virtual void DoPreCalc();
	virtual long DoCalc();
	virtual void DoAfterCalc(long counted);
	virtual void DoDeInit();

public:
	virtual bool IsRefObject(COMREF object);

	virtual bool IsRefFieldValue(COMREF object);
	virtual double GetFieldValue(voidptr dataptr, INDICATOR_FIELD field);

	virtual bool IsRefCalcData(COMREF object);
	virtual voidptr RefCalcData(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, UINT uFlags = REF_CALCDATA_NONE);
	virtual long ReleaseCalcData(voidptr dataptr);
	virtual void ReleaseCalcDataAll();

	virtual XIndicator* RefIndicator(LPCTSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	virtual XIndicator* iCalc(LPCTSTR name, INPUTINFO* input, voidptr dataptr);
	virtual XIndicator* iScript(LPCTSTR name, INPUTINFO* input, LPCTSTR scripts, LPCTSTR language, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	virtual XIndicator* iScriptCalc(LPCTSTR name, INPUTINFO* input, LPCTSTR scripts, LPCTSTR language, voidptr dataptr);
	virtual long ReleaseIndicator(XIndicator* handle); //返回引用计数
	virtual void ReleaseIndicatorAll();

	virtual int UsersTotal();
	virtual int UserCurrent();
	virtual int UserSelectReset();
	virtual int UserSelectByIndex(int index);
	virtual int UserSelectByName(LPCSTR name);
	virtual int UserSelectByName(LPCWSTR name);
	virtual int UserSelectByObject(COMREF object);
	virtual double UserFieldValue(LPCSTR field);
	virtual double UserFieldValue(LPCWSTR field);
	virtual LPCSTR UserFieldString(LPCSTR field, LPSTR str, int len);
	virtual LPCWSTR UserFieldString(LPCWSTR field, LPWSTR str, int len);

	virtual int ObjectsFind(LPCSTR key, unsigned long flags);
	virtual int ObjectsFind(LPCWSTR key, unsigned long flags);
	virtual int ObjectsTotal(const char* market);
	virtual int ObjectsTotal(const wchar_t* market);
	virtual int ObjectSelect(int index, COMREF* object, int count);

	virtual int OrderSend(COMREF object, int cmd, double volume, double price, int slippage, double stoploss, double takeprofit,
		LPCSTR comment = NULL, int magic = 0, unsigned long date = 0, unsigned long time = 0);
	virtual int OrderSend(COMREF object, int cmd, double volume, double price, int slippage, double stoploss, double takeprofit,
		LPCWSTR comment = NULL, int magic = 0, unsigned long date = 0, unsigned long time = 0);

	virtual int OrdersSelect(int pool);
	virtual int OrdersCurrent();
	virtual int OrdersTotal();
	virtual int OrderCurrent();
	virtual int OrderSelectReset();
	virtual int OrderSelectByIndex(int index);
	virtual int OrderSelectByTicket(LPCSTR ticket);
	virtual int OrderSelectByTicket(LPCWSTR ticket);
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

	virtual const char* OrderFieldString(LPCSTR field, char* str, int len);

public:
	virtual long SetInput(INPUTINFO* input);
	virtual long SetInput(LPCTSTR name, LPCTSTR value, bool visible = true);
	virtual long SetInput(LPCTSTR name, double value, bool visible = true);
	virtual long SetAttribute(LPCTSTR attr, LPCTSTR value);
	/*virtual long SetIndexCount(int value);
	virtual long SetIndexName(int index, LPCTSTR value);
	virtual long SetIndexType(int index, long type);
	virtual long SetIndexDigits(int index, long digits);
	virtual long SetIndexShift(int index, long shift);
	virtual long SetIndexBegin(int index, long begin);
	virtual long SetIndexDraw(int index, long draw);
	virtual long SetIndexLine(int index, long line);
	virtual long SetIndexNext(int index, long next);*/
	virtual long SetIndexAttribute(int index, LPCTSTR attr, LPCTSTR value);
	virtual long SetIndexValue(int index, int offset, double value);

	virtual void AddPool(unsigned char exchange, unsigned char group);
	virtual void AddPool(COMREF object);
	virtual void RemovePool(unsigned char exchange, unsigned char group);
	virtual void RemovePool(COMREF object);
	virtual int PoolsTotal();
	virtual int PoolSelect(int offset, COMREF* object, int count);
	virtual bool IsRefPool(COMREF object);
	virtual void RefPool(PINDICATORCALCCONTEXTINFO in);
	virtual void CleanPool();

	virtual LPCTSTR GetAttribute(LPCTSTR attr);
	/*virtual long GetIndexCount();
	virtual LPCTSTR GetIndexName(int index);
	virtual long GetIndexStyle(int index);
	virtual long GetIndexDigits(int index);
	virtual long GetIndexShift(int index);
	virtual long GetIndexDrawBegin(int index);
	virtual long GetIndexDraw(int index);
	virtual long GetIndexLine(int index);
	virtual long GetIndexNext(int index);*/
	virtual double GetIndexAttribute(int index, LPCTSTR attr);
	virtual double GetIndexValue(int index, int offset);

	virtual long GetPriceCount();

	virtual unsigned long GetPriceDate(int offset);
	virtual unsigned long GetPriceTime(int offset);

	virtual double GetLineValue(
		int       line,
		int       offset
		);
	virtual double GetPriceValue(
		int       price,
		int       offset
		);
	virtual double GetFinanceValue(
		int       finance,
		int       offset
		);
	virtual double GetFieldValue(
		INDICATOR_FIELD field
		);

	virtual long  CopyIndexValue(
		int       index,		// 指标缓冲位置
		int       offset,		// 启动位置
		int       count,		// 复制总额
		double*   buffer		// 复制的目标数组
		);

protected:
	virtual double InnerGetPriceValue(
		int       price,
		int       offset
		);
public:
	//buffer必须和Index一样大小
	//均值
	long iMABufferOnPrice(double* buffer, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price, int start, int count);
	long iMABufferOnIndex(double* buffer, int period, INDICATOR_MA_METHOD method, int index, int start, int count);
	long iMAIndexOnPrice(int index, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price);
	long iMAIndexOnLine(int index, int period, INDICATOR_MA_METHOD method, int line);

	//方差
	long iS2BufferOnPrice(double* buffer, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price, int start, int count);
	long iS2BufferOnIndex(double* buffer, int period, INDICATOR_MA_METHOD method, int index, int start, int count);
	long iS2IndexOnPrice(int index, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price);
	long iS2IndexOnLine(int index, int period, INDICATOR_MA_METHOD method, int line);
	//标准差
	long iStdDevBufferOnPrice(double* buffer, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price, int start, int count);
	long iStdDevBufferOnIndex(double* buffer, int period, INDICATOR_MA_METHOD method, int index, int start, int count);
	long iStdDevIndexOnPrice(int index, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price);
	long iStdDevIndexOnLine(int index, int period, INDICATOR_MA_METHOD method, int line);

	//RSV是英文Raw Stochastic Value的缩写，中文意思是未成熟随机值
	long iRSVBuffer(double* buffer, int period, INDICATOR_STO_PRICE sto_price, int start, int count);
	long iRSVIndex(int index, int period, INDICATOR_STO_PRICE sto_price);

	int iReverseOffset(int offset);
	int iIsCross(int src, int dst, int offset);

public:
	virtual long GetPos(unsigned long date,
		unsigned long time,
		unsigned long *pos
		);

	virtual long GetTime(unsigned long pos,
		unsigned long *date,
		unsigned long *time
		);

public:
	virtual bool OnUserUpdate();
	virtual bool OnCalcDataUpdate(COMREF object);
	virtual bool OnFieldDataUpdate(COMREF object);
	virtual bool OnOrderUpdate();

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
	END_EVT_MAP()

	long OnCall(Event& evt);
	long OnNotify(Event& evt);
};

/*struct IndicatorLess
{
	bool operator()(const Indicator const& x, const Indicator const& y) const
	{
		XIndicator* xparent = x.GetParent();
		XIndicator* yparent = y.GetParent();
		if (xparent<yparent) {
			return true;
		} else if (xparent>yparent) {
			return false;
		}
		int cmp = _tcsicmp(x.ctx.name,y.ctx.name);
		if (cmp<0) {
			return true;
		} else if (cmp>0) {
			return false;
		}
		InputHelper helper(const_cast<INPUTINFO*>(&x.ctx.input));
		return helper.IsLess(&y.ctx.input);
	}
};*/

#endif//_H_XINDICATOR_HPP_

