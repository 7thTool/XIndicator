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

//���з�����첽�¼����ж�Ӧ֪ͨ
//��������ر�����¼���û��֪ͨ�������رգ���֪ͨ
//ԭ���������رգ�һ�����ϻ����ٶ���������滹��֪ͨ�Ļ������п��ܷ��ʷǷ���ַ

enum 
{
	EVT_DE_FIRST = EVT_NETIO_END,	//��NETIO������ʼ����ֹ�¼���ͻ
	
	EVT_DE_GET,						//��ȡ����

	EVT_DE_SET,						//��������

	EVT_DE_REQUEST,					//��������
	EVT_DE_NOTIFY,					//�����Ӧ,����֪ͨ��״̬֪ͨ�ȵ�

	EVT_DE_END
};

//��������ͻ�Ӧ����ͬһ��Event����

class DE_API EvtDataObject : public Object
{
	//strName��������strUser�˻���Ϣ
public:
	std::string strName; //����
	std::string strUser; //�û���

	EvtDataObject();
	EvtDataObject(const char* name, const char* user);
	EvtDataObject(const std::string& name, const std::string& user);
};

class DE_API EvtDataObjectEx : public ObjectEx
{
	//strName��������strUser�˻���Ϣ
public:
	std::string strName; //����
	std::string strUser; //�û���

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
	//����
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
	//����
	GET_DE_ORDER,
	GET_DE_TRADE,
	GET_DE_POSITION,
	GET_DE_BANK,
	GET_DE_END
};

//GET_DE_ACCOUNTINFO
#define ACCOUNT_FLAG_NONE		0	//��
#define ACCOUNT_FLAG_QUOTE		1	//֧�����飨ֻ������5������ļ����飩
#define ACCOUNT_FLAG_FULLQUOTE	2	//֧��ȫ���飨������ʷ���ݡ��������ݵȵ���ȫ�����飩
#define ACCOUNT_FLAG_TRADE		4	//֧�ֽ���

#define ACCOUNT_FIELD_UserA "User"						//�û��˺�
#define ACCOUNT_FIELD_MoneySymbolA "MoneySymbol"		//���ҷ���
#define ACCOUNT_FIELD_MoneyTotalA "MoneyTotal"			//��ǰ�ܽ��
#define ACCOUNT_FIELD_MoneyAvailableA "MoneyAvailable"	//��ǰ���ý��
#define ACCOUNT_FIELD_MoneyFreezeA "MoneyFreeze"		//��ǰ������
#define ACCOUNT_FIELD_MoneyFreeA "MoneyFree"			//��ǰ��ȡ���
#define ACCOUNT_FIELD_MoneyInA "MoneyIn"				//��ǰ�����
#define ACCOUNT_FIELD_MoneyOutA "MoneyOut"				//��ǰ������
//
#define ACCOUNT_OBJECT_PARENT "Parent"					//������
#define ACCOUNT_OBJECT_ORDERA "Order"					//ί��
#define ACCOUNT_OBJECT_HISORDERA "HistoryOrder"			//��ʷί��
#define ACCOUNT_OBJECT_TRADEA "Trade"					//�ɽ�
#define ACCOUNT_OBJECT_HISTRADEA "HistoryTrade"			//��ʷ�ɽ�
#define ACCOUNT_OBJECT_POSITIONA "Position"				//�ֲ�
#define ACCOUNT_OBJECT_BANKA "Bank"						//����
//
#define ACCOUNT_FIELD_UserW L"User"						//�û��˺�
#define ACCOUNT_FIELD_MoneySymbolW L"MoneySymbol"		//���ҷ���
#define ACCOUNT_FIELD_MoneyTotalW L"MoneyTotal"			//��ǰ�ܽ��
#define ACCOUNT_FIELD_MoneyAvailableW L"MoneyAvailable"	//��ǰ���ý��
#define ACCOUNT_FIELD_MoneyFreezeW L"MoneyFreeze"		//��ǰ������
#define ACCOUNT_FIELD_MoneyFreeW L"MoneyFree"			//��ǰ��ȡ���
#define ACCOUNT_FIELD_MoneyInW L"MoneyIn"				//��ǰ�����
#define ACCOUNT_FIELD_MoneyOutW L"MoneyOut"				//��ǰ������
//
#define ACCOUNT_OBJECT_ORDERW L"Order"					//ί��
#define ACCOUNT_OBJECT_HISORDERW L"HistoryOrder"		//��ʷί��
#define ACCOUNT_OBJECT_TRADEW L"Trade"					//�ɽ�
#define ACCOUNT_OBJECT_HISTRADEW L"HistoryTrade"		//��ʷ�ɽ�
#define ACCOUNT_OBJECT_POSITIONW L"Position"			//�ֲ�
#define ACCOUNT_OBJECT_BANKW L"Bank"					//����
//
class DE_API AccountInfo : public EvtDataObject
	, ThreadingModel<CriticalSection>
{
	typedef ThreadingModel<CriticalSection>::Lock SectionLocker;
	//strName��������strUser�˻���Ϣ
public:
	std::string strPassword; //�û�����

protected:
	std::map<unsigned long,unsigned long> SupportList; //֧���б�,�������г���KIND
	std::map<unsigned long,unsigned long> SelectList; //�����б�,�������г���KIND
	
	std::map<std::string,std::string> mapField;	//�˻��ֶ���Ϣ
	std::map<std::string,ObjectPtr> mapObjPtr; //�˻���ض��󣬱��罻�׵�ί�У��ֲ֣��ɽ������������е���Ϣ

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
	//strName���������˻��б���Ϣ
public:					//����
	std::vector<AccountInfoPtr> AccountList;	//�˻��б�
};
typedef Handle<AccountListInfo> AccountListInfoPtr;
//GET_DE_SERVERINFO
class ServerInfo : public EvtDataObject
{
	//strName��������strUser�˻��ķ�������Ϣ
public:
	ServerInfo()
	{
		memset(&ProxyInfo, 0, sizeof(ProxyInfo));
	}

	std::vector<tagServerInfo> ServerList;		//�������б�
	PROXYINFO ProxyInfo;						//����
};
typedef Handle<ServerInfo> ServerInfoPtr;
class ServerListInfo : public EvtDataObject
{
public:
	std::vector<ServerInfoPtr> ServerList;		//�������б�
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
	//strName��������strUser�˻��ĵ�¼��Ϣ
public:
	OnlineInfo(const char* name, const char* user):EvtDataObject(name,user)
		,bOnline(false),nStatus(DE_OFFLINE),nError(0),strError()
	{}
	OnlineInfo(const std::string & name, const std::string & user):EvtDataObject(name,user)
		,bOnline(false),nStatus(DE_OFFLINE),nError(0),strError()
	{}

	bool bOnline; //�Ƿ�����
	unsigned char nStatus; //����״̬

	//�ϲ㷢���¼ʱ������ҵ���Լ�ʶ��
	//���ڵ�¼�����У��ײ㱨���¼״̬ʱ��С��0Ϊ���󣬴���0Ϊ��ȷ������ҵ���Լ�ʶ���ϲ�Ҫȡ����¼���̣����Խ�nError��Ϊ0
	//��¼����ʱ������ҵ���Լ�ʶ�𣬱�����֤������֤��Ϣ
	long nError; //����ֵ
	std::string strError; //������Ϣ
};
typedef Handle<OnlineInfo> OnlineInfoPtr;
class OnlineListInfo : public EvtDataObject
{
public:
	std::vector<OnlineInfoPtr> OnlineList;		//�����б�
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
	ORDER_TYPE_NONE		= 0,	//δ֪
	ORDER_TYPE_ORDER	= 1,	//ί��
	ORDER_TYPE_TRADE	= 2,	//�ɽ�
	ORDER_TYPE_POSITION	= 4,	//�ֲ�
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
	//������Ĭ��״̬������ί�У���ʾδ֪�����ڳɽ��ͳֲ�ֻ����Ĭ��״̬
	///��/δ֪
	ORDER_STATE_NONE	= 0,

	//////////////////////////////////////////////////////////////////////////
	//�������ύ״̬
	///�Ѿ��ύ
	ORDER_STATE_INSERT_SUBMITTED,
	///�����Ѿ��ύ
	ORDER_STATE_CANCEL_SUBMITTED,
	///�޸��Ѿ��ύ
	ORDER_STATE_MODIFY_SUBMITTED,
	///�Ѿ�����
	ORDER_STATE_ACCEPTED,
	///�����Ѿ����ܾ�
	ORDER_STATE_INSERT_REJECTED,
	///�����Ѿ����ܾ�
	ORDER_STATE_CANCEL_REJECTED,
	///�ĵ��Ѿ����ܾ�
	ORDER_STATE_MODIFY_REJECTED,

	//////////////////////////////////////////////////////////////////////////
	//�����ǽ���״̬
	///ȫ���ɽ�
	ORDER_STATE_ALLTRADED,
	///���ֳɽ����ڶ�����
	ORDER_STATE_PARTTRADED_QUEUEING,
	///���ֳɽ����ڶ�����
	ORDER_STATE_PARTTRADED_NOT_QUEUEING,
	///δ�ɽ����ڶ�����
	ORDER_STATE_NOTRADE_QUEUEING,
	///δ�ɽ����ڶ�����
	ORDER_STATE_NOTRADE_NOT_QUEUEING,
	///�ѳ���
	ORDER_STATE_CANCELED,
	///�Ѵ���
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
	///���д���
	std::string	BankID;
	///���з����Ĵ���
	std::string	BankBranchID;
	///��������
	std::string	BankName;
	///�����ʺ�
	std::string	BankAccount;
	///���ִ���
	std::string	CurrencyID;
	///���п��ý��
	double BankUseAmount;
	///���п�ȡ���
	double BankFetchAmount;
};
//EVT_DE_SET
enum
{
	SET_DE_NULL = 0,
	//SET_DE_ADD_ACCOUNTINFO,		//����˻���Ϣ
	//SET_DE_REMOVE_ACCOUNTINFO,	//ɾ���˻���Ϣ
	SET_DE_ACCOUNTINFO,			//�����˻���Ϣ
	//SET_DE_ADD_SERVERINFO,		//��ӷ�������Ϣ
	//SET_DE_REMOVE_SERVERINFO,	//ɾ����������Ϣ
	SET_DE_SERVERINFO,			//���÷�������Ϣ
	SET_DE_ONLINE,				//���յ���¼���֪ͨ
	SET_DE_OFFLINE,				//��������������û������֪ͨ�¼��ģ�ֻ�б�������
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

	unsigned char FinishRate:7; //��ɰٷֱ�,�Ŵ�100��, 100Ϊ���
	unsigned char Changed:1; //�����Ƿ��ͱ仯��0��û�б仯��Ҳ�Ͳ������»�ȡ������
	
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
	ENUM_TIMEFRAMES Period;		//[IN] ����
	int PeriodEx;				//[IN] ������û��Զ������ڣ���ʾÿ�������ж��ٷ�����(��Ӧ��CycleType = CYC_ANYMIN)
								//����ÿ�������ж�������(��Ӧ��CycleType = CYC_ANYDAY)
	unsigned char Type;			//[IN] ����
								// Type = 0������ĳ����֮���������¼
								// Type = 1������ĳ����֮ǰ��������¼
	unsigned long DateTime;		//[IN] ��ʼʱ��[YYYYMMDD]
	unsigned long Size;			//[IN] ���󳤶�
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

	OrderInfo order; //��orderִ��OrderSend������Ϊ��
};
typedef Handle<REQ_OrderSend> REQ_OrderSendPtr;
//EVT_DE_NOTIFY,�������ʹ���ȫ0���߶���Ϊ�ձ�ʾȫ�г�
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

	//ObjectPtr ReqPtr;			//���������Ӧ������������󣬶���������Ϊ�ն���
};
typedef Handle<NotifyInfo> NotifyInfoPtr;
class N_FIELDDATAInfo 
	//: public EvtDataObject
	: public ObjectExT<N_FIELDDATAInfo,NotifyInfo>
{
public:
	COMREF Commodity; //[IN]
	std::vector<unsigned short> Fields; //[IN] ����
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
	ENUM_TIMEFRAMES Period; //[IN] ����
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