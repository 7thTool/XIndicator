#ifndef _H_DATAEVENT_H_
#define _H_DATAEVENT_H_

#include "DEDef.h"
#include <DataStd.h>
#include <FieldDef.h>
#include "../NetIO/EvtNetIO.h"
#include "../Base/Base.h"

#include <vector>
#include <string>
#include <utility>
using namespace std;

//所有发起的异步事件都有对应通知
//主动发起关闭相关事件，没有通知，被动关闭，有通知
//原因是主动关闭，一般马上会销毁对象，如果后面还有通知的话，就有可能访问非法地址

enum 
{
	EVT_DE_FIRST = EVT_NETIO_END,	//从NETIO结束开始，防止事件冲突
	
	EVT_DE_GET,						//获取数据

	EVT_DE_SET,						//设置数据

	EVT_DE_REQUEST,					//请求数据
	EVT_DE_NOTIFY,					//请求回应,推送通知，状态通知等等

	EVT_DE_END
};

//所有请求和回应都在同一个Event里面

class DE_API EvtDataObject : public Object
{
	//strName类型名的strUser账户信息
public:
	std::string strName; //名字
	std::string strUser; //用户名

	EvtDataObject();
	EvtDataObject(const char* name, const char* user);
	EvtDataObject(const std::string& name, const std::string& user);
};

class DE_API EvtDataObjectEx : public ObjectEx
{
	//strName类型名的strUser账户信息
public:
	std::string strName; //名字
	std::string strUser; //用户名

	EvtDataObjectEx();
	EvtDataObjectEx(const char* name, const char* user);
	EvtDataObjectEx(const std::string& name, const std::string& user);
};

//EVT_DATA_GET
enum
{
	GET_DE_NULL = 0,
	GET_DE_ACCOUNTINFO,
	GET_DE_SERVERINFO,
	GET_DE_ONLINE,
	//行情
	GET_DE_KIND,
	GET_DE_KIND_LIST,
	GET_DE_COMMODITY,
	GET_DE_COMMODITY_LIST,
	GET_DE_FIELD_ID,
	GET_DE_FIELD_NAME,
	GET_DE_FIELD_VALUE,
	GET_DE_FIELD_VALUETEXT,
	GET_DE_HISDATA,
	//GET_DE_TICK,
	//GET_DE_CONTRACT,
	//交易
	GET_DE_ORDER,
	GET_DE_TRADE,
	GET_DE_POSITION,
	GET_DE_BANK,
	GET_DE_END
};

//GET_DE_ACCOUNTINFO
#define ACCOUNT_FLAG_NONE		0	//无
#define ACCOUNT_FLAG_QUOTE		1	//支持行情（只有至多5档行情的简单行情）
#define ACCOUNT_FLAG_FULLQUOTE	2	//支持全行情（包括历史数据、财务数据等的完全的行情）
#define ACCOUNT_FLAG_TRADE		4	//支持交易

#define ACCOUNT_FIELD_UserA "User"						//用户账号
#define ACCOUNT_FIELD_MoneySymbolA "MoneySymbol"		//货币符号
#define ACCOUNT_FIELD_MoneyTotalA "MoneyTotal"			//当前总金额
#define ACCOUNT_FIELD_MoneyAvailableA "MoneyAvailable"	//当前可用金额
#define ACCOUNT_FIELD_MoneyFreezeA "MoneyFreeze"		//当前冻结金额
#define ACCOUNT_FIELD_MoneyFreeA "MoneyFree"			//当前可取金额
#define ACCOUNT_FIELD_MoneyInA "MoneyIn"				//当前入金金额
#define ACCOUNT_FIELD_MoneyOutA "MoneyOut"				//当前出金金额
//
#define ACCOUNT_OBJECT_PARENT "Parent"					//父对象
#define ACCOUNT_OBJECT_ORDERA "Order"					//委托
#define ACCOUNT_OBJECT_HISORDERA "HistoryOrder"			//历史委托
#define ACCOUNT_OBJECT_TRADEA "Trade"					//成交
#define ACCOUNT_OBJECT_HISTRADEA "HistoryTrade"			//历史成交
#define ACCOUNT_OBJECT_POSITIONA "Position"				//持仓
#define ACCOUNT_OBJECT_BANKA "Bank"						//银行
//
#define ACCOUNT_FIELD_UserW L"User"						//用户账号
#define ACCOUNT_FIELD_MoneySymbolW L"MoneySymbol"		//货币符号
#define ACCOUNT_FIELD_MoneyTotalW L"MoneyTotal"			//当前总金额
#define ACCOUNT_FIELD_MoneyAvailableW L"MoneyAvailable"	//当前可用金额
#define ACCOUNT_FIELD_MoneyFreezeW L"MoneyFreeze"		//当前冻结金额
#define ACCOUNT_FIELD_MoneyFreeW L"MoneyFree"			//当前可取金额
#define ACCOUNT_FIELD_MoneyInW L"MoneyIn"				//当前入金金额
#define ACCOUNT_FIELD_MoneyOutW L"MoneyOut"				//当前出金金额
//
#define ACCOUNT_OBJECT_ORDERW L"Order"					//委托
#define ACCOUNT_OBJECT_HISORDERW L"HistoryOrder"		//历史委托
#define ACCOUNT_OBJECT_TRADEW L"Trade"					//成交
#define ACCOUNT_OBJECT_HISTRADEW L"HistoryTrade"		//历史成交
#define ACCOUNT_OBJECT_POSITIONW L"Position"			//持仓
#define ACCOUNT_OBJECT_BANKW L"Bank"					//银行
//
class DE_API AccountInfo : public EvtDataObject
	, ThreadingModel<CriticalSection>
{
	typedef ThreadingModel<CriticalSection>::Lock SectionLocker;
	//strName类型名的strUser账户信息
public:
	std::string strPassword; //用户密码

protected:
	std::map<unsigned long,unsigned long> SupportList; //支持列表,可以是市场或KIND
	std::map<unsigned long,unsigned long> SelectList; //设置列表,可以是市场或KIND
	
	std::map<std::string,std::string> mapField;	//账户字段信息
	std::map<std::string,ObjectPtr> mapObjPtr; //账户相关对象，比如交易的委托，持仓，成交，撤单，银行等信息

public:
	AccountInfo();

	//AccountInfo* Clone();

	//void SetFlags(unsigned long flag);
	//unsigned long GetFlags();

	void AddSupport(unsigned long exchange, unsigned long flag);
	void RemoveSupport(unsigned long exchange, unsigned long flag);
	bool IsSupport(unsigned long exchange, unsigned long flag);

	void AddSelect(unsigned long exchange, unsigned long flag);
	void RemoveSelect(unsigned long exchange, unsigned long flag);
	bool IsSelect(unsigned long exchange, unsigned long flag);

	void SetField(const std::string& field, const std::string & value);
	bool GetField(const std::string& field, std::string & value);

	void SetObject(const std::string& field, const ObjectPtr & value);
	bool GetObject(const std::string& field, ObjectPtr & value);
};
typedef Handle<AccountInfo> AccountInfoPtr;
class AccountListInfo : public EvtDataObject
{
	//strName类型名的账户列表信息
public:					//名字
	std::vector<AccountInfoPtr> AccountList;	//账户列表
};
typedef Handle<AccountListInfo> AccountListInfoPtr;
//GET_DE_SERVERINFO
class ServerInfo : public EvtDataObject
{
	//strName类型名的strUser账户的服务器信息
public:
	ServerInfo()
	{
		memset(&ProxyInfo, 0, sizeof(ProxyInfo));
	}

	std::vector<tagServerInfo> ServerList;		//服务器列表
	PROXYINFO ProxyInfo;						//代理
};
typedef Handle<ServerInfo> ServerInfoPtr;
class ServerListInfo : public EvtDataObject
{
public:
	std::vector<ServerInfoPtr> ServerList;		//服务器列表
};
typedef Handle<ServerListInfo> ServerListInfoPtr;
//GET_DE_ONLINE
enum
{
	DE_OFFLINE = 0,
	DE_INITDATA,
	DE_ONLINE,
};
class OnlineInfo : public EvtDataObject
{
	//strName类型名的strUser账户的登录信息
public:
	OnlineInfo(const char* name, const char* user):EvtDataObject(name,user)
		,bOnline(false),nStatus(DE_OFFLINE),nError(0),strError()
	{}
	OnlineInfo(const std::string & name, const std::string & user):EvtDataObject(name,user)
		,bOnline(false),nStatus(DE_OFFLINE),nError(0),strError()
	{}

	bool bOnline; //是否在线
	unsigned char nStatus; //在线状态

	//上层发起登录时，具体业务自己识别
	//对于登录过程中，底层报告登录状态时，小于0为错误，大于0为正确，具体业务自己识别，上层要取消登录过程，可以将nError置为0
	//登录结算时，具体业务自己识别，比如认证返回认证信息
	long nError; //错误值
	std::string strError; //错误信息
};
typedef Handle<OnlineInfo> OnlineInfoPtr;
class OnlineListInfo : public EvtDataObject
{
public:
	std::vector<OnlineInfoPtr> OnlineList;		//在线列表
};
typedef Handle<OnlineListInfo> OnlineListInfoPtr;
//GET_DE_KIND
class KINDInfo : public EvtDataObject
{
public:
	KINDInfo()
	{
		memset(&Kind, 0, sizeof(Kind));
	}

	KIND Kind;
	KINDINFO Info;
};
typedef Handle<KINDInfo> KINDInfoPtr;
//GET_DE_KIND_LIST
typedef std::vector<KIND> KINDLIST;
class KINDListInfo : public EvtDataObject
{
public:
	KINDListInfo() 
	{
		//KindList;
	}

	KINDLIST KindList;
};
typedef Handle<KINDListInfo> KINDListInfoPtr;
//GET_DE_COMMODITY
class COMREFInfo : public EvtDataObject
{
public:
	COMREFInfo()
	{
		memset(&Commodity, 0, sizeof(Commodity));
	}

	COMREF Commodity;
	COMMODITYINFO Info;
	
};
typedef Handle<COMREFInfo> COMREFInfoPtr;
//GET_DE_COMMODITY_LIST
typedef std::vector<COMREF> COMREFLIST;
class COMREFListInfo : public EvtDataObject
{
public:
	COMREFListInfo() 
	{
		memset(&Kind, 0, sizeof(Kind));
		//CommodityList;
	}

	KIND Kind;
	COMREFLIST CommodityList;
};
typedef Handle<COMREFListInfo> COMREFListInfoPtr;
//GET_DE_FIELD_ID,
//GET_DE_FIELD_NAME,
typedef std::vector<FIELD_NAME> FIELDNAMELIST;
class FIELDNAMEListInfo : public EvtDataObject
{
public:
	FIELDNAMEListInfo()
	{
		memset(&Commodity, 0, sizeof(Commodity));
	}
	COMREF Commodity;
	FIELDNAMELIST FieldNameList;
};
typedef Handle<FIELDNAMEListInfo> FIELDNAMEListInfoPtr;
//GET_DE_FIELD_VALUE,
//GET_DE_FIELD_VALUETEXT,
typedef std::vector<FIELD_VALUE> FIELDVALUELIST;
class FIELDVALUEListInfo : public EvtDataObject
{
public:
	FIELDVALUEListInfo()
	{
		memset(&Commodity, 0, sizeof(Commodity));
	}
	COMREF Commodity;
	FIELDVALUELIST FieldValueList;
};
typedef Handle<FIELDVALUEListInfo> FIELDVALUEListInfoPtr;
//GET_DE_HISDATA
typedef std::vector<HISDATA> HISDATALIST;
class HisData : public EvtDataObject
{
public:
	HISDATALIST HisDataList;
};
typedef Handle<HisData> HisDataPtr;
typedef std::vector<WEIGHT> WEIGHTLIST;
class WeightInfo : public EvtDataObject
{
public:
	WEIGHTLIST WeightList;
};
typedef Handle<WeightInfo> WeightInfoPtr;
class HisDataInfo : public EvtDataObject
{
public:
	HisDataInfo() 
	{
		memset(&Commodity, 0, sizeof(Commodity));
		Period = CYC_MAX;
		PeriodEx = 0;
		Digits = 0;
		DWType = DW_FORWARD;
		DWDate = 0;
	}
	/*HisDataInfo(const HisDataInfo& o) 
	{
		Commodity = o.Commodity;
		Period = CYC_MAX;
		DWType = DW_FORWARD;
		DWDate = 0;
	}*/
	COMREF Commodity;
	ENUM_TIMEFRAMES Period;
	int PeriodEx;
	int Digits;
	HisDataPtr DataPtr;
	WeightInfoPtr WeightPtr;

	ENUM_DWTYPE DWType;
	unsigned long DWDate;
	HisDataPtr DWDataPtr;
};
typedef Handle<HisDataInfo> HisDataInfoPtr;
//GET_DE_ORDER/GET_DE_TRADE/GET_DE_POSITION
enum
{
	ORDER_TYPE_NONE		= 0,	//未知
	ORDER_TYPE_ORDER	= 1,	//委托
	ORDER_TYPE_TRADE	= 2,	//成交
	ORDER_TYPE_POSITION	= 4,	//持仓
};
enum
{
	ORDER_CMD_NONE			= 0,
	ORDER_CMD_BUY,
	ORDER_CMD_SELL,	
	ORDER_CMD_BUYLIMIT,
	ORDER_CMD_SELLLIMIT,
	ORDER_CMD_BUYSTOP,
	ORDER_CMD_SELLSTOP,
	ORDER_CMD_CLOSE,
	ORDER_CMD_CLOSETODAY,
	ORDER_CMD_DELETE,
	ORDER_CMD_MODIFY,
};
enum
{
	//////////////////////////////////////////////////////////////////////////
	//以下是默认状态，对于委托，表示未知，对于成交和持仓只能是默认状态
	///无/未知
	ORDER_STATE_NONE	= 0,

	//////////////////////////////////////////////////////////////////////////
	//以下是提交状态
	///已经提交
	ORDER_STATE_INSERT_SUBMITTED,
	///撤单已经提交
	ORDER_STATE_CANCEL_SUBMITTED,
	///修改已经提交
	ORDER_STATE_MODIFY_SUBMITTED,
	///已经接受
	ORDER_STATE_ACCEPTED,
	///报单已经被拒绝
	ORDER_STATE_INSERT_REJECTED,
	///撤单已经被拒绝
	ORDER_STATE_CANCEL_REJECTED,
	///改单已经被拒绝
	ORDER_STATE_MODIFY_REJECTED,

	//////////////////////////////////////////////////////////////////////////
	//以下是交易状态
	///全部成交
	ORDER_STATE_ALLTRADED,
	///部分成交还在队列中
	ORDER_STATE_PARTTRADED_QUEUEING,
	///部分成交不在队列中
	ORDER_STATE_PARTTRADED_NOT_QUEUEING,
	///未成交还在队列中
	ORDER_STATE_NOTRADE_QUEUEING,
	///未成交不在队列中
	ORDER_STATE_NOTRADE_NOT_QUEUEING,
	///已撤单
	ORDER_STATE_CANCELED,
	///已触发
	ORDER_STATE_TOUCHED,
};
class OrderInfo
{
public:
	OrderInfo():type(ORDER_TYPE_ORDER)
		,ticket()
		//,Commodity(0)
		,cmd(ORDER_CMD_NONE)
		,currency()
		,volume(0)
		,available(0)
		,open(0)
		,slippage(0)
		,stoploss(0)
		,takeprofit(0)
		,close(0)
		,commission(0)
		,comment()
		,magic(0)
		,date(0)
		,time(0)
		,opendate(0)
		,opentime(0)
		,closedate(0)
		,closetime(0)
		,modifydate(0)
		,modifytime(0)
		,state(ORDER_STATE_NONE)
		,error()
		,mapExtra()
	{
		memset(&Commodity, 0, sizeof(Commodity));
	}

	int type;
	std::string ticket;				// order num
	COMREF Commodity;
	int cmd;						// operation
	std::string currency;			// currency
	double volume;					// volume
	double available;				// available
	double open;					// open
	int slippage;					// slippage
	double stoploss;				// stop loss
	double takeprofit;				// take profit
	double close;					// close
	double commission;				// commission
	std::string comment;			// comment //utf-8
	int magic;						// magic number
	unsigned long date;				// pending order expiration
	unsigned long time;				// pending order expiration
	unsigned long opendate;
	unsigned long opentime;
	unsigned long closedate;
	unsigned long closetime;
	unsigned long modifydate;
	unsigned long modifytime;
	int state;
	std::string error;
	std::map<std::string,std::string> mapExtra; //extra field info
};
class OrderListInfo : public EvtDataObject
	, ThreadingModel<CriticalSection>
{
	typedef ThreadingModel<CriticalSection>::Lock SectionLocker;
public:
	int OrderType;
private:
	std::vector<OrderInfo> OrderList;
protected:
	int FindOrderByTicket(const std::string & ticket)
	{
		int i;
		for (i=0; i<OrderList.size(); i++)
		{
			if (OrderList[i].ticket == ticket) {
				return i;
				break;
			}
		}
		return RLT_UNKNOWN;
	}
	int FindOrderByMagic(const int & magic)
	{
		int i;
		for (i=0; i<OrderList.size(); i++)
		{
			if (OrderList[i].magic == magic) {
				return i;
				break;
			}
		}
		return RLT_UNKNOWN;
	}

public:
	OrderListInfo(int orderType = 0):OrderType(orderType)
	{

	}

	void Clear()
	{
		SectionLocker Lock(*this);
		OrderList.clear();
	}

	void Add(const OrderInfo& order, bool bUpdateIfExist = false)
	{
		SectionLocker Lock(*this);
		if (bUpdateIfExist) {
			int index = FindOrderByTicket(order.ticket);
			if (index>=0 && index<OrderList.size()) {
				OrderList[index] = order;
				return;
			}
		} 
		OrderList.push_back(order);
	}

	void Assign(OrderInfo* pOrder, int nCount)
	{
		SectionLocker Lock(*this);
		OrderList.assign(pOrder,pOrder+nCount);
	}

	int GetOrderCount()
	{
		return (int)OrderList.size();
	}

	int GetOrderByIndex(const int & index, OrderInfo & Order)
	{
		SectionLocker Lock(*this);
		if (index>=0 && index<OrderList.size()) {
			Order = OrderList[index];
			return index;
		}
		return RLT_UNKNOWN;
	}

	int GetOrderByTicket(const std::string & ticket, OrderInfo & Order)
	{
		SectionLocker Lock(*this);
		return GetOrderByIndex(FindOrderByTicket(ticket),Order);
	}

	int GetOrderByMagic(const int & magic, OrderInfo & Order)
	{
		SectionLocker Lock(*this);
		return GetOrderByIndex(FindOrderByMagic(magic),Order);
	}
};
typedef Handle<OrderListInfo> OrderListInfoPtr;
//GET_DE_BANK
class BankInfo
{
public:
	///银行代码
	std::string	BankID;
	///银行分中心代码
	std::string	BankBranchID;
	///银行名称
	std::string	BankName;
	///银行帐号
	std::string	BankAccount;
	///币种代码
	std::string	CurrencyID;
	///银行可用金额
	double BankUseAmount;
	///银行可取金额
	double BankFetchAmount;
};
//EVT_DE_SET
enum
{
	SET_DE_NULL = 0,
	//SET_DE_ADD_ACCOUNTINFO,		//添加账户信息
	//SET_DE_REMOVE_ACCOUNTINFO,	//删除账户信息
	SET_DE_ACCOUNTINFO,			//设置账户信息
	//SET_DE_ADD_SERVERINFO,		//添加服务器信息
	//SET_DE_REMOVE_SERVERINFO,	//删除服务器信息
	SET_DE_SERVERINFO,			//设置服务器信息
	SET_DE_ONLINE,				//会收到登录相关通知
	SET_DE_OFFLINE,				//主动设置离线是没有离线通知事件的，只有被动才有
	SET_DE_END
};
//SET_DE_Add/REMOVE_ACCOUNTINFO
//SET_DE_ADD/REMOVE_SERVERINFO
//SET_DE_ONLINE
//EVT_DE_REQUEST
enum
{
	REQUEST_DE_NULL = 0,
	REQUEST_DE_CANCEL,
	REQUEST_DE_REGPUSH,
	REQUEST_DE_ECONOMIC_DATA,
	REQUEST_DE_DYNAMIC_DATA,
	REQUEST_DE_FIELD_DATA,
	REQUEST_DE_HISDATA,
	REQUEST_DE_ORDERSEND,
	REQUEST_DE_END
};
class DE_API RequestInfo : public EvtDataObject
{
public:
	RequestInfo();

	unsigned char FinishRate:7; //完成百分比,放大100倍, 100为完成
	unsigned char Changed:1; //数据是否发送变化，0则没有变化，也就不用重新获取数据了
	
	void SetFinishRate(unsigned long nPos);
	void SetChange(bool bChanged = true);
	unsigned char GetFinishRate();
	bool IsFinished();
	bool IsChanged();
};
typedef Handle<RequestInfo> RequestInfoPtr;
template<class T, class _Ty, class _Pr=less<_Ty>>
class EvtRequestInfoT : public EvtRequestT<T,_Ty,_Pr>
{
	typedef EvtRequestT<T,_Ty,_Pr> Base;
public:
	bool UpdateRequest(const _Ty& SubReq, bool bChanged, Event& Req)
	{
		bool bUpdate = Base::UpdateRequest(SubReq,Req);
		if (bUpdate) {
			RequestInfoPtr ReqPtr = RequestInfoPtr::dynamicCast(Req.objPtr);
			if (ReqPtr) {
				ReqPtr->SetChange(bChanged);
			}
		}
		return bUpdate;
	}
	bool UpdateRequest(const _Ty& SubReq, bool bChanged = true)
	{
		T* pT = static_cast<T*>(this);
		Event Req;
		return pT->UpdateRequest(SubReq,bChanged,Req);
	}
};
//REQUEST_DE_REGPUSH
class REQ_PushInfo : public RequestInfo
{
public:
	std::vector<COMREF> Commoditys; //[IN]
};
typedef Handle<REQ_PushInfo> REQ_PushInfoPtr;
//REQUEST_DE_ECONOMIC_DATA
class REQ_EconomicDataInfo : public RequestInfo
{
public:
	
};
typedef Handle<REQ_EconomicDataInfo> REQ_EconomicDataInfoPtr;
//REQUEST_DE_DYNAMIC_DATA
//REQUEST_DE_FIELD_DATA
enum
{
	//REQ_FIELD_FLAG_ONE = 0,
	REQ_FIELD_FLAG_SOME,
	REQ_FIELD_FLAG_ALL,
};
class REQ_FIELDDATAInfo : public RequestInfo
{
public:
	UINT uFlags; //[IN]
	std::vector<COMREF> Commoditys; //[IN]
	std::vector<unsigned long> Fields; //[IN]
	//[OUT]
};
typedef Handle<REQ_FIELDDATAInfo> REQ_FIELDDATAInfoPtr;
//REQUEST_DE_HISDATA
class REQ_HISDATAInfo : public RequestInfo
{
public:
	COMREF Commodity;			//[IN]
	ENUM_TIMEFRAMES Period;		//[IN] 周期
	int PeriodEx;				//[IN] 如果是用户自定义周期，表示每个周期有多少分钟数(对应于CycleType = CYC_ANYMIN)
								//或者每个周期有多少天数(对应于CycleType = CYC_ANYDAY)
	unsigned char Type;			//[IN] 类型
								// Type = 0、请求某日期之后多少条记录
								// Type = 1、请求某日期之前多少条记录
	unsigned long DateTime;		//[IN] 起始时间[YYYYMMDD]
	unsigned long Size;			//[IN] 请求长度
};
typedef Handle<REQ_HISDATAInfo> REQ_HISDATAInfoPtr;
//REQUEST_DE_ORDERSEND
class REQ_OrderSend : public RequestInfo
{
public:
	COMREF Commodity;
	int cmd;
	double volume;
	double price;
	int slippage;
	double stoploss;
	double takeprofit;
	std::string comment; //UTF-8
	int magic;
	unsigned long date;
	unsigned long time;

	OrderInfo order; //对order执行OrderSend，可以为空
};
typedef Handle<REQ_OrderSend> REQ_OrderSendPtr;
//EVT_DE_NOTIFY,对于推送代码全0或者对象为空表示全市场
enum
{
	NOTIFY_DE_NULL = 0,
	NOTIFY_DE_ONLINE,
	NOTIFY_DE_RESPONSE_REGPUSH,
	NOTIFY_DE_RESPONSE_FIELD_DATA,
	NOTIFY_DE_PUSH_FIELD_DATA,
	NOTIFY_DE_RESPONSE_HISDATA,
	NOTIFY_DE_PUSH_HISDATA,
	//
	NOTIFY_DE_RESPONSE_ORDERSEND,
	NOTIFY_DE_PUSH_ORDER,
	NOTIFY_DE_PUSH_TRADE,
	NOTIFY_DE_PUSH_POSITION,

	NOTIFY_DE_END
};
class NotifyInfo : public EvtDataObjectEx
{
public:
	NotifyInfo() {}

	//ObjectPtr ReqPtr;			//对于请求回应，则是请求对象，对于推送则为空对象
};
typedef Handle<NotifyInfo> NotifyInfoPtr;
class N_FIELDDATAInfo 
	//: public EvtDataObject
	: public ObjectExT<N_FIELDDATAInfo,NotifyInfo>
{
public:
	COMREF Commodity; //[IN]
	std::vector<unsigned short> Fields; //[IN] 周期
};
typedef Handle<N_FIELDDATAInfo> N_FIELDDATAInfoPtr; 
class N_HISDATAInfo 
	//: public EvtDataObject
	: public ObjectExT<N_HISDATAInfo,NotifyInfo>
{
public:
	N_HISDATAInfo(COMREF& c, ENUM_TIMEFRAMES p = CYC_TICK):Commodity(c),Period(p)
	{

	}

	COMREF Commodity; //[IN]
	ENUM_TIMEFRAMES Period; //[IN] 周期
};
typedef Handle<N_HISDATAInfo> N_HISDATAInfoPtr; 
class N_OrderInfo 
	: public ObjectExT<N_OrderInfo,NotifyInfo>
{
public:
	N_OrderInfo()
	{
	}

	OrderInfo order;
};
typedef Handle<N_OrderInfo> N_OrderInfoPtr; 

//////////////////////////////////////////////////////////////////////////

class DE_API RequestMap
{
public:
	RequestMap();
	virtual ~RequestMap();

protected:
	typedef std::set<SendBufferPtr> SendPtrs;
	typedef std::map<RequestInfoPtr,SendPtrs> RequestPtr2SendPtrs;
	typedef std::map<SendBufferPtr,RequestInfoPtr> SendPtr2RequestPtr;
	RequestPtr2SendPtrs m_ReqPtr2SendPtrs;
	SendPtr2RequestPtr m_SendPtr2ReqPtr;
	virtual void Clear(bool bUpdate = true);
	virtual void MapRequest(const RequestInfoPtr& ReqPtr, const SendBufferPtr& SendPtr);
	virtual RequestInfoPtr MapRequest(const SendBufferPtr& SendPtr);
	virtual void UpdateRequest(const RequestInfoPtr& ReqPtr, const SendBufferPtr& SendPtr);
};

long DE_API EvtDataRequest2ResponseValue(long req);
long DE_API EvtDataResponse2RequestValue(long res);


#endif//_H_DATAEVENT_H_