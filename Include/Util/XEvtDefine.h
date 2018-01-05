#ifndef _H_XEVTDEFINE_H_
#define _H_XEVTDEFINE_H_

#include <DataStd.h>
#include <FieldDef.h>
#include "../DataEngine/EvtData.h"
#include "../Indicator/IndicatorExDef.h"

//#include "Objecter.h"
#include <XLib/XEvent.h>
#include <XLib/XXml.h>

#include <XLib/XAsync.h>

class Objecter;

//���з�����첽�¼����ж�Ӧ֪ͨ
//��������ر�����¼���û��֪ͨ�������رգ���֪ͨ
//ԭ���������رգ�һ�����ϻ����ٶ���������滹��֪ͨ�Ļ������п��ܷ��ʷǷ���ַ

enum 
{
	EVT_PLAT_FIRST = EVT_DE_END,

	EVT_PLAT_CALL,						//���ã�ȡ���� �������ݣ����÷�����

	EVT_PLAT_POST,						//�ʵݣ��첽�¼����������ݣ����ݲ����ݣ���

	EVT_PLAT_NOTIFY,					//֪ͨ���������ݲ㡢ƽ̨��֪ͨ�������Ӧ������֪ͨ����Ϣ�¼��Լ���������״̬֪ͨ��,���߳���ͬ������

	EVT_PLAT_MAX
};

//��������ͻ�Ӧ����ͬһ��Event����

#define MAKEVALUE(main,child)	MAKELONG(main,child)

//EVT_PLAT_CALL
//MGET_PLAT_MAX			//ȡ����
//MSET_PLAT_MAX			//������Ϣ
//MCALL_PLAT_MAX		//���÷���

enum
{
	MGET_PLAT_NULL = 0,
	MGET_PLAT_OBJECT,
	MGET_PLAT_PLAT,
	MGET_PLAT_FRAME,
	MGET_PLAT_DE,
	MGET_PLAT_LOGIN,
	MGET_PLAT_INDICATOR,
	MGET_PLAT_MAX,
};
//MGET_PLAT_OBJECT
enum
{
	CGET_OBJECT_NULL = 0,
	//CGET_OBJECT_ID,
	//CGET_OBJECT_HWND,
	CGET_OBJECT_DISPINFO,
	CGET_OBJECT_ACCOUNTINFO,
	CGET_OBJECT_SERVERINFO,
	CGET_OBJECT_PUSHINFO,
	
	CGET_OBJECT_MAX
};
class ObjectPushInfo : public Object
{
public:
	std::set<COMREF> Commoditys;
};
typedef Handle<ObjectPushInfo> ObjectPushInfoPtr;
//MGET_PLAT_PLAT
enum
{
	CGET_PLAT_NULL = 0,

	CGET_PLAT_MAX
};
//MGET_PLAT_FRAME
enum
{
	CGET_FRAME_NULL = 0,
	CGET_FRAME_TRADEINFO,
	CGET_FRAME_SMARTKBINFO,

	CGET_FRAME_MAX
};
//CGET_FRAME_TRADEINFO
enum
{
	TRADE_FLAG_NONE			= 0,
	TRADE_MODE_VOLUME		= 1,		//�̶�������
	TRADE_MODE_AMOUNT		= 2,		//�̶����
	TRADE_MODE_MASK			= 0X0F,
	TRADE_FLAG_SPLITORDER	= 0X10,		//��
};
class TradeInfo : public Object
{
public:
	TradeInfo()
	{
		memset(&Commodity, 0, sizeof(Commodity));
		nFlags = 0;
		Volume = 0.;
		MaxVolume = 0.;
		Amount = 0.;
		MaxAmount = 0.;
	}

	COMREF Commodity;							//��Ʒ

	UINT nFlags;								//��־
	double Volume;								//��
	double MaxVolume;							//�����
	double Amount;								//��
	double MaxAmount;							//����

	double CalcOrderVolume(double dvalue, double lotsize, double price = 0., UINT flag = TRADE_FLAG_NONE)
	{
		if (IsZeroFloat(dvalue)) {
			if (flag==TRADE_FLAG_NONE) {
				flag = nFlags;
			}
			switch (flag)
			{
			case TRADE_MODE_AMOUNT:
				{
					dvalue = Amount;
				}
			case TRADE_MODE_VOLUME:
				{
					dvalue = Volume;
				}
				break;
			default:
				ASSERT(0);
				return 0.;
			}
		}
		switch (flag)
		{
		case TRADE_MODE_AMOUNT:
			{
				if(IsZeroFloat(price)) {
					ASSERT(0);
					dvalue = 0.;
					break;
				}
				if (dvalue>MaxAmount) {
					dvalue = MaxAmount;
				}
				dvalue = dvalue/price;
			}
		case TRADE_MODE_VOLUME:
			{
				if(IsZeroFloat(lotsize)) {
					ASSERT(0);
					dvalue = 0.;
					break;
				}
				if (dvalue<lotsize) {
					dvalue = lotsize;
				} else if (dvalue>MaxVolume) {
					dvalue = MaxVolume;
				}
				dvalue = (dvalue/lotsize)*lotsize;
			}
			break;
		default:
			ASSERT(0);
			return 0.;
		}
		return dvalue;
	}
};
typedef Handle<TradeInfo> TradeInfoPtr;
//CGET_FRAME_SMARTKB
class SmartKBObject : public Object
{
public:
	std::tstring Key;
	long Result;
public:
	SmartKBObject(LPCTSTR lpszKey = NULL)
	{
		if (lpszKey) {
			Key = lpszKey;
		}
		Result = 0;
	}

	virtual LPCTSTR GetKey(COLORREF* lpColor = NULL) 
	{ 
		return Key.c_str(); 
	}
	virtual LPCTSTR GetName(COLORREF* lpColor = NULL) 
	{
		return NULL;
	}
	virtual LPCTSTR GetOwner(COLORREF* lpColor = NULL) 
	{
		return NULL;
	}
	virtual BOOL GetObject(LPVOID lpObject, int nType) //nTypeΪSMARTKB_FLAG_KIND,SMARTKB_FLAG_COMMODITY��
	{ 
		return FALSE; 
	}
};
enum
{
	SMARTKB_FLAG_DEFAULT		= 0,
	SMARTKB_FLAG_INDICATOR		= 0X01,
	SMARTKB_FLAG_KIND			= 0X02,
	SMARTKB_FLAG_COMMODITY		= 0X04,
	SMARTKB_FLAG_COMMAND		= 0X08,
	SMARTKB_FLAG_MASK			= 0XFF,
	SMARTKB_MATCH_DEFAULT		= 0,
	SMARTKB_MATCH_KEY			= 0X0100,			//ƥ��KEY
	SMARTKB_MATCH_NAME			= 0X0200,			//ƥ��NAME
	SMARTKB_MATCH_OWNER			= 0X0400,			//ƥ��OWNER
	SMARTKB_MATCH_CASE			= 0X0800,			//���ִ�Сд
	SMARTKB_MATCH_MASK			= 0XFF00,
	SMARTKB_MAXRESULT_MASK		= 0XFFFF0000,
};
typedef Handle<SmartKBObject> SmartKBObjectPtr;
struct SmartKBObjectPtrLess
{
	bool operator()(const SmartKBObjectPtr& x, const SmartKBObjectPtr& y) const
	{
		ASSERT(x&&y);
		return x->Result < y->Result;
	}
};
class SmartKBInfo 
	: public Object
	, public FindKey
{
public:
	SmartKBInfo(AsyncFinder* pFinder = NULL):FindKey(pFinder)
	{
		//strKey;
		uFlag = 0;
		//SmartKBPtrList;
	}
	std::tstring strKey;
	UINT uFlag;
	std::vector<SmartKBObjectPtr> SmartKBPtrList;
};
typedef Handle<SmartKBInfo> SmartKBInfoPtr;
//MGET_PLAT_DE
enum
{
	CGET_DE_NULL = 0,
	CGET_DE_ACCOUNTINFO,
	CGET_DE_SERVERINFO,
	CGET_DE_ONLINE,
	CGET_DE_KIND,
	CGET_DE_KINDLIST,
	CGET_DE_COMMODITY,			//�ṹ��Commdotiy
	CGET_DE_COMMODITYATTR,
	CGET_DE_COMMODITYLIST,		//ȡ��Ʒ�б�������Ч��COMREF
	CGET_DE_FIELD_NAME,			//ȡ�ֶ���
	CGET_DE_FIELD_VALUE,		//ȡ�ֶ�ֵ
	CGET_DE_FIELD_VALUETEXT,	//ȡ�ֶ��ı�
	CGET_DE_HISDATA,			//ȡ��ʷ����
	//CGET_DE_TICK,				//ȡ��ϸ
	//CGET_DE_CONTRACT,			//ȡ�����ϸ
	CGET_DE_ORDER,				//ȡ����
	CGET_DE_BANK,				//ȡ����
	CGET_DE_BANKTRANSFERLIST,	//ȡ����ת�˼�¼
	//CGET_DE_INFO,
	CGET_DE_MAX
};
//CGET_DE_KIND

//CGET_DE_KINDLIST
class KindInfo
{
public:
	KindInfo()
	{
		memset(Name, 0, sizeof(Name));
		//KindList;
	}

	KindInfo(const KIND& Kind)
	{
		memset(Name, 0, sizeof(Name));
		KindList.resize(1, Kind);
	}

	bool IsInvalid() const
	{
		return KindList.empty();
	}

	LPCTSTR GetName() const
	{
		return KindList.size() == 1 ? KindList[0].Name : Name;
	}

	bool operator == (const KindInfo& x) const
	{
		if (KindList.size() == x.KindList.size()) {
			std::vector<KIND>::const_iterator it = KindList.begin();
			std::vector<KIND>::const_iterator it_x = x.KindList.begin();
			for (; it != KindList.end(); ++it,++it_x)
			{
				if (*it != *it_x) {
					break;
				}
			}
			if (it == KindList.end()) {
				return true;
			}
		}
		return false;
	}
	bool operator != (const KindInfo& x) const
	{
		return !(*this==x);
	}

	wchar_t Name[MAX_NAME_LENGTH+1];
	std::vector<KIND> KindList; //һ�����������ж��С�������
};
class KindListInfo
{
public:
	KindListInfo()
	{
		memset(Name, 0, sizeof(Name));
		//KindList;
		CurKindPos = 0;
	}

	/*int GetNameLength() const 
	{
		return Name.length();
	}

	LPCTSTR GetName() const
	{
		return Name.c_str();
	}*/

	wchar_t Name[MAX_NAME_LENGTH+1];
	std::vector<KindInfo> KindList;
	int CurKindPos;
};
class AllKindListInfo : public Object
{
public:
	std::vector<KindListInfo> AllKindList;
};
typedef Handle<AllKindListInfo> AllKindListInfoPtr;
//CGET_DE_COMMODITY
//CGET_DE_COMMODITYATTR
enum
{
	COMMODITY_ATTR_NONE = 0,
	COMMODITY_ATTR_SELF = 1<<0,
	COMMODITY_ATTR_SELF1 = 1<<1,
	COMMODITY_ATTR_SELF2 = 1<<2,
	COMMODITY_ATTR_SELF3 = 1<<3,
	COMMODITY_ATTR_SELF4 = 1<<4,
	COMMODITY_ATTR_SELF5 = 1<<5,
	COMMODITY_ATTR_SELF6 = 1<<6,
	COMMODITY_ATTR_SELF7 = 1<<7,
	COMMODITY_ATTR_SELF8 = 1<<8,
	COMMODITY_ATTR_SELFMASK = 0X0000FFFF,
	COMMODITY_ATTR_USERMASK	= 0XFFFF0000,
};
class CommodityAttr : public Object
{
public:
	COMREF Commodity;
	unsigned long Attr;
	std::tstring Description;
};
typedef Handle<CommodityAttr> CommodityAttrPtr;
//CGET_DE_COMMODITYLIST
class CommodityListInfo : public Object
{
public:
	KindInfo Kind;
	COMREFLIST CommodityList;
};
typedef Handle<CommodityListInfo> CommodityListInfoPtr;
//CGET_DE_FIELD_NAME
//CGET_DE_FIELD_VALUE/CGET_DE_FIELD_VALUETEXT
//CGET_DE_ORDER
/*class OrderInfo
{
public:
	int ticket;
	COMREF Commodity;
	int cmd;						// operation
	double volume;					// volume
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
};
class OrderListInfo : public Object
{
public:
	int OrderMode;
	std::vector<OrderInfo> OrderList;
};
typedef Handle<OrderListInfo> OrderListInfoPtr;*/
enum
{
	INFORMATION_ID_NONE = 0,
	INFORMATION_ID_NEWS,				//����
	INFORMATION_ID_COMMODITY_NEWS,		//��������
	INFORMATION_ID_COMMODITY_NOTICE,	//���ɹ���
	INFORMATION_ID_COMMODITY_F10,		//���ɻ�������
};
#define INFORMATION_ATTR_NONE		0
#define INFORMATION_ATTR_ROLL		0X00000001
#define INFORMATION_ATTR_POPUP		0X00000002
#define	INFORMATION_ATTR_AD			0X00000004
#define INFORMATION_ATTR_SYS_MASK	0X0000FFFF
#define INFORMATION_ATTR_USER_MASK	0XFFFF0000
#define INFORMATION_ATTR_DELETED	0X80000000
#define INFORMATION_ATTR_READED		0X40000000
//������Ѷ��Ӧ����name�����Ƕ�����Ѷ
class Information : public Object
{
public:
	Information()
	{
		id = 0;
		attr = 0;
		date = 0;
		time = 0;
		modifydate = 0;
		modifytime = 0;
		//name;
		//content;
	}

	unsigned long id;
	unsigned long attr;
	unsigned long date,time;
	unsigned long modifydate,modifytime;
	std::tstring name;
	//std::tstring content;
};
typedef Handle<Information> InformationPtr;
class InformationEx : public Information
{
public:
	std::tstring content;
	std::vector<InformationPtr> infolist;
};
typedef Handle<InformationEx> InformationExPtr;

//MGET_PLAT_LOGIN
enum
{
	CGET_LOGIN_NULL = 0,
	CGET_LOGIN_INFO,

	CGET_LOGIN_MAX
};
//CGET_LOGIN_INFO
class LoginInfo : public Object
{
public:
};
typedef Handle<LoginInfo> LoginInfoPtr;

//MGET_PLAT_INDICATOR
enum
{
	CGET_INDICATOR_NULL = 0,
	CGET_INDICATOR_INFO,
	CGET_INDICATOR_INDEXINFO,
	CGET_INDICATOR_INDEXINFOEX,
	CGET_INDICATOR_POINTINFO,
	CGET_INDICATOR_POINTINFOEX,

	CGET_INDICATOR_MAX
};
//CGET_INDICATOR_INFO
class IndicatorInfo
	: public Object
	, public INDICATORCONTEXTINFO
{
public:
	IndicatorInfo()
	{
		bOk = FALSE;
		//
		type = 0;
		style = 0;
		memset(&input, 0, sizeof(INPUTINFO));
		tradeable = 0;
		refcount = 0;
		memset(refline, 0, sizeof(refline));
		count = 0;
		memset(index, 0, MAX_INDICATOR_INDEX*sizeof(INDEXINFO));
	}

	BOOL bOk;
};
typedef Handle<IndicatorInfo> IndicatorInfoPtr;
//CGET_INDICATOR_INDEXINFO/CGET_INDICATOR_INDEXINFOEX
class IndicatorIndexInfo : public Object
{
public:
	IndicatorIndexInfo()
	{
		index = 0;

		minvalue = EMPTY_VALUE;
		maxvalue = EMPTY_VALUE;
		mindispvalue = EMPTY_VALUE;
		maxdispvalue = EMPTY_VALUE;

		pos = 0;
		result = 0.;
		memset(&pt, 0, sizeof(POINT));
	}

	unsigned long index;

	//CGET_INDICATOR_INDEXINFO

	//��ȡ��Сֵ���ֵ
	double minvalue;
	double maxvalue;
	double mindispvalue;
	double maxdispvalue;

	//CGET_INDICATOR_INDEXINFOEX

	unsigned long pos;
	//���posλ�õ�buffer�ߵ�ֵ�͵����Ϣ
	double result;
	POINT pt;
};
typedef Handle<IndicatorIndexInfo> IndicatorIndexInfoPtr;
//CGET_INDICATOR_POINTINFO
class IndicatorPointInfo : public Object
{
public:
	IndicatorPointInfo()
	{
		memset(&pt, 0, sizeof(POINT));
		pos = 0;
		result = 0.;
	}

	POINT pt;
	//��õ�pt���ڵ�pos��ֵ����Ϣ
	unsigned long pos;
	double result;
};
typedef Handle<IndicatorPointInfo> IndicatorPointInfoPtr;
//CGET_INDICATOR_POINTINFOEX
class IndicatorPointInfoEx : public IndicatorPointInfo
{
public:
	IndicatorPointInfoEx():IndicatorPointInfo()
	{
		indicator = NULL;
		index = 0;
	}

	//���pt�Ƿ���indicator��index���ϣ����index<index��������index���ϣ����������ָ����index==index����������Ϊ����index��
	Objecter* indicator;
	unsigned long index;
};
typedef Handle<IndicatorPointInfoEx> IndicatorPointInfoExPtr;

//EVT_PLAT_CALL
enum
{
	MSET_PLAT_NULL = MGET_PLAT_MAX,
	MSET_PLAT_OBJECT,
	MSET_PLAT_PLAT,
	MSET_PLAT_FRAME,
	MSET_PLAT_DE,
	MSET_PLAT_LOGIN,
	MSET_PLAT_INDICATOR,

	MSET_PLAT_MAX,
};
//MSET_PLAT_OBJECT
enum
{
	CSET_OBJECT_NULL = 0,

	CSET_OBJECT_DISPINFO,

	//CSET_OBJECT_ACCOUNTINFO,
	//CSET_OBJECT_SERVERINFO,
	//CSET_OBJECT_TRADEINFO,

	CSET_CONTAINER_INFO,

	//���齻����ض���
	CSET_VIEW_INFO,
	CSET_VIEW_DISPINFO,

	//���ܼ���
	CSET_VIEW_SMARTKBINFO,

	CSET_OBJECT_MAX
};
//CSET_OBJECT_DISPINFO
//ObjectDispInfo

//MSET_PLAT_PLAT
enum
{
	CSET_PLAT_NULL = 0,

	CSET_PLAT_MAX
};

//MSET_PLAT_FRAME
enum
{
	CSET_FRAME_NULL = 0,

	CSET_FRAME_MAX
};

//MSET_PLAT_LOGIN
enum
{
	CSET_LOGIN_NULL = 0,

	CSET_LOGIN_MAX
};
//MSET_PLAT_DE
enum
{
	CSET_DE_NULL = 0,
	CSET_DE_ADD_ACCOUNTINFO,
	CSET_DE_REMOVE_ACCOUNTINFO,
	CSET_DE_SERVERINFO,
	CSET_DE_ONLINE,
	CSET_DE_OFFLINE,
	CSET_DE_COMMODITYATTR,
	CSET_DE_INFORMATIONATTR,

	CSET_DE_MAX
};
//CSET_DE_ADD_ACCOUNTINFO
//CSET_DE_REMOVE_ACCOUNTINFO
/////////////////////////////////////////////////////////////////////////////////////
//���ʺ�֧�֣���Ҫ����Handler�ı�ʶ��Name����������+User���û��˻�����
//�ʺŹ������̣�
//1���û�ѡ����֤����ȡ��֤��Ϣ�����顢���׷�������Ϣ�Լ�������չ��Ϣ����Щ��Ϣ������Ҫ��׼����
//2��������֤��������;�������������˻��ͷ�������Ϣ������¼����
//3���û�ѡ���¼����
//ADD_ACCOUNTINFO(REG)->ADD_SERVERINFO(REG)->REG->NOTIFY_DE_REG->ADD_ACCOUNTINFO(����)->ADD_SERVERINFO(����)->ONLINE->NOTIFY_DE_OFFLINE/INITDATA/ONLINE
//															   ->ADD_ACCOUNTINFO(����)->ADD_SERVERINFO(����)->
//���Ͻӿ�ʵ����DataEngineʵ�֣��ⲿʹ�øýӿ�
//���磺��Login(ֻҪ��������ʺŵ�¼)���ã���MainFrameʵ������ͽ���
//���ȣ�����������֤�����Զ����֤Handler����֤�ɹ��󣬱�����֤��Ϣ������Ҳ����ѡ���¼����
//Ȼ�󣬵�¼����
//������û�е�¼���ף�����ѡ���¼����
//����ĺ����߼����ǣ���Ҫ��ЩHandler��ҪԤ��֪����Ȼ��ȥ�������߻�ȡ����������DataEngine�����ϲ�֧����ЩHandler,����Ҳ����������Ȩ�޿���
//ֻ�ж�̬֧��ȫHandler��Ӧ�ò���ҪDataEngine�����ϲ�DataEngine֧�ֵ�Handler
/////////////////////////////////////////////////////////////////////////////////////
/*////////////////////////////////////////////////////////////////////////
��֤XML��׼��Ϣ
<root>
<user name="xxx">XXX</user>
<hander name="SH">XXX</hander>
<hander name="SZ">XXX</hander>
<hander name="CF">XXX</hander>
<hander name="CTP">XXX</hander>
</root>
////////////////////////////////////////////////////////////////////////*/
#define STR_REGISTERA	"Register"
#define STR_REGISTERW	L"Register"
//��Ϊ����
#define STR_TRADERA		"Trader"
#define STR_TRADERW		L"Trader"
#ifndef UNICODE
#define STR_REGISTER	STR_REGISTERA
#define STR_TRADER		STR_TRADERA
#else
#define STR_REGISTER	STR_REGISTERW
#define STR_TRADER		STR_TRADERW
#endif//

//CSET_DE_ADD_SERVERINFO
//CSET_DE_REMOVE_SERVERINFO

//CSET_DE_SETONLINE
//1��ʾ���ߣ�0��ʾ����
//CSET_DE_COMMODITYATTR

//MSET_PLAT_INDICATOR
enum
{
	CSET_INDICATOR_NULL = 0,
	CSET_INDICATOR_INPUTINFO,
	CSET_INDICATOR_CALCINFO,
	CSET_INDICATOR_DISPINFO,
	CSET_INDICATOR_DISPINFOEX,

	CSET_INDICATOR_MAX
};
//CSET_INDICATOR_CALCINFO
class IndicatorCalcInfo : public Object
{
public:
	IndicatorCalcInfo()
	{
		memset(&Object, 0, sizeof(Object));
		Period = CYC_DAY;
		PeriodEx = 0;
		DWType = DW_FORWARD;
		DWDate = 0;

		//TestStart = 0;
		//TestEnd = 0;
		TestCursor = -1;
	}

	//��������
	COMREF Object;
	ENUM_TIMEFRAMES Period;
	int PeriodEx;
	ENUM_DWTYPE DWType;
	unsigned long DWDate;

	//�ع����
	//unsigned long TestStart; //���Կ�ʼ
	//unsigned long TestEnd; //���Խ���
	int TestCursor; //���Ե�ǰ�α�
};
typedef Handle<IndicatorCalcInfo> IndicatorCalcInfoPtr;
//CSET_INDICATOR_DISPINFO
class IndicatorDispInfo : public Object
{
public:
	IndicatorDispInfo()
	{
		//MinOpen = 0;
		//MaxOpen = 0;
		//MinHigh = 0;
		//MaxHigh = 0;
		//MinLow = 0;
		//MaxLow = 0;
		//MinClose = 0;
		//MaxClose = 0;
		//MinVolume = 0;
		//MaxVolume = 0;

		HighPrice = 0;
		LowPrice = 0;
		HighVolume = 0;
		LowVolume = 0;
		StartDate = 0;
		StartTime = 0;
		Start = 0;
		Count = 0;
		Shift = 0;
		MaxCount = 0;

		Current = 0;
		bCrossCursor = FALSE;

		InfoHeight = 0;
		InfoWidth = 0;
		TopSpace = 0;
		BottomSpace = 0;

		Scale = 0;

		KLineType = 0;
		YCoordType = 0;
		XCoordType = 0;
	}

	//int MinOpen;
	//int MaxOpen;
	//int MinHigh;
	//int MaxHigh;
	//int MinLow;
	//int MaxLow;
	//int MinClose;
	//int MaxClose;
	//int MinVolume;
	//int MaxVolume;

	int HighPrice;				//��߼�λ��
	int LowPrice;				//��ͼ�λ��
	int HighVolume;				//�����λ��	
	int LowVolume;				//�����λ��
	int StartDate;				//��ʼ����
	int StartTime;				//��ʼʱ��
	int Start;					//��ʼλ��
	int Count;					//��ʾ��Ŀ
	int Shift;					//ƫ����Ŀ��Ĭ����ʾʱƫ�ƣ�
	int MaxCount;				//������ʾ��Ŀ

	int Current;				//��ǰλ��
	BOOL bCrossCursor;			//�Ƿ���ʾ��ǰλ��ʮ���α�

	int InfoHeight;				//����������Ϣ���߶�
	int InfoWidth;				//����Ҳ�������Ϣ�����
	int TopSpace;				//����������ͼ��϶
	int BottomSpace;			//�ײ���϶

	int Scale;					//BAR�ĵ���

	int KLineType;				//K������
	int KVolumeType;			//��������
	int YCoordType;				//Y����������
	int XCoordType;				//X����������
};
typedef Handle<IndicatorDispInfo> IndicatorDispInfoPtr;
//CSET_INDICATOR_DISPINFOEX
class IndicatorDispInfoEx : public Object
{
public:
	IndicatorDispInfoEx()
	{
		MaxValue = EMPTY_VALUE;
		MinValue = EMPTY_VALUE;
	}

	double MaxValue; //���ֵ
	double MinValue; //��Сֵ
};
typedef Handle<IndicatorDispInfoEx> IndicatorDispInfoExPtr;

//EVT_PLAT_CALL
enum
{
	MCALL_PLAT_NULL = MSET_PLAT_MAX,
	MCALL_PLAT_OBJECT,
	MCALL_PLAT_PLAT,
	MCALL_PLAT_FRAME,
	MCALL_PLAT_LOGIN,
	MCALL_PLAT_INDICATOR,
	MCALL_PLAT_DE,

	MCALL_PLAT_MAX
};

//MCALL_PLAT_OBJECT
enum
{
	CCALL_OBJECT_NULL = 0,
	//User Interface
	//
	//MSG
	CCALL_OBJECT_KEY,
	CCALL_OBJECT_MOUSE,
	CCALL_OBJECT_COMMAND,
	CCALL_OBJECT_MOVE,
	CCALL_OBJECT_SIZE,
	CCALL_OBJECT_ERASEBKGND,
	CCALL_OBJECT_PAINT,
	//Method
	CCALL_OBJECT_REFRESH,		//���ú������Ϣ֮�󣬵��ø�������
	CCALL_OBJECT_INVALIDATE,	//�ػ滭��
	//END User Interface

	CCALL_OBJECT_MAX
};
//CCALL_OBJECT_KEY
//CCALL_OBJECT_MOUSE
//CCALL_OBJECT_COMMAND
//CCALL_OBJECT_MOVE
//CCALL_OBJECT_SIZE
//CCALL_OBJECT_ERASEBKGND
//CCALL_OBJECT_PAINT
class MsgEvent 
	: public Object
	, public MSG
{
public:
	MsgEvent()
	{
		hwnd = NULL;
		message = WM_NULL;
		wParam = 0;
		lParam = 0;
		time = 0;
		pt.x = 0;
		pt.y = 0;
	}
	/*std::string reserved;

	template<class T>
	int To(T* p, int size = -1)
	{
		if (p==NULL || size < 0) {
			return reserved.size()/sizeof(T);
		}
		size = min(size,reserved.size()/sizeof(T));
		memcpy(p, &reserved[0], size*sizeof(T));
	}
	void* ToPtr()
	{
		void* ptr = NULL;
		To(&ptr, 1);
		return ptr;
	}
	const char* ToStrA()
	{
		return (const char*)reserved.c_str();
	}
	const wchar_t* ToStrW()
	{
		return (const wchar_t*)reserved.c_str();
	}
#ifndef UNICODE
#define ToStr	ToStrA
#else
#define ToStr	ToStrW
#endif//

	template<class T>
	void Set(T* p, int size)
	{
		size = sizeof(T)*size;
		reserved.resize(size, 0);
		memcpy(&reserved[0], p, size);
	}
	void SetPtr(void* ptr)
	{
		Set(&ptr, 1);
	}
	void SetStrA(char* str, int len = -1)
	{
		if (len < 0) {
			len = strlen(str);
		}
		len += 1;
		Set(str, len);
	}
	void SetStrW(wchar_t* str, int len = -1)
	{
		if (len < 0) {
			len = wcslen(str);
		}
		len += 1;
		Set(str, len);
	}
#ifndef UNICODE
#define SetStr	SetStrA
#else
#define SetStr	SetStrW
#endif//*/
};
typedef Handle<MsgEvent> MsgEventPtr;
//MCALL_PLAT_PLAT
enum
{
	CCALL_PLAT_NULL = 0,
	CCALL_PLAT_CREATETHREAD,
	CCALL_PLAT_DESTROYTHREAD,

	CCALL_PLAT_MAX
};
//CCALL_PLAT_CREATETHREAD
class CreateThreadInfo : public Object
{
public:
	CreateThreadInfo(const wchar_t* n, LPCTSTR lpstrCmdLine=NULL, int nCmdShow=0):cmdline(lpstrCmdLine?lpstrCmdLine:_T("")),show(nCmdShow) {
		memset(Name,0,sizeof(Name));
		if (n) {
			wcsncpy(Name,n,MAX_NAME_LENGTH);
		}
	}

	wchar_t Name[MAX_NAME_LENGTH+1]; //�߳����֣��ձ�ʾĬ��
	std::tstring cmdline;
	int show;
};
typedef Handle<CreateThreadInfo> CreateThreadInfoPtr;
//CCALL_PLAT_DESTROYTHREAD
class DestroyThreadInfo : public Object
{
public:
	DestroyThreadInfo(const wchar_t* n) {
		memset(Name,0,sizeof(Name));
		if (n) {
			wcsncpy(Name,n,MAX_NAME_LENGTH);
		}
	}

	wchar_t Name[MAX_NAME_LENGTH+1]; //�߳����֣��ձ�ʾĬ��
};
typedef Handle<DestroyThreadInfo> DestroyThreadInfoPtr;
//MCALL_PLAT_FRAME
enum
{
	CCALL_FRAME_NULL = 0,
	CCALL_FRAME_SMARTKB,
	CCALL_FRAME_GOTOCONTAINER,
	CCALL_FRAME_REQPUSH,

	CCALL_FRAME_MAX
};
//CCALL_FRAME_REQPUSH

//MNOTIFY_PLAT_LOGIN
enum
{
	CCALL_LOGIN_NULL = 0,
	CCALL_LOGIN_LOGIN,

	CCALL_LOGIN_MAX
};

//MCALL_PLAT_INDICATOR
enum
{
	CCALL_INDICATOR_NULL = 0,

	CCALL_INDICATOR_MAX
};
//MCALL_PLAT_DE
enum
{
	CCALL_DE_NULL = 0,
	CCALL_DE_ADDSELFKIND,
	CCALL_DE_REMOVESELFKIND,
	CCALL_DE_ADDSELFCOMMODITY,
	CCALL_DE_REMOVESELFCOMMODITY,
	CCALL_DE_ADDINFORMATION,
	CCALL_DE_REMOVEINFORMATION,

	CCALL_DE_MAX
};
//CCALL_DE_ADDSELFKIND
//CCALL_DE_REMOVESELFKIND
class AddSelfKind : public Object
{
public:
	wchar_t Name[MAX_NAME_LENGTH+1];
};
typedef Handle<AddSelfKind> AddSelfKindPtr;
class RemoveSelfKind : public Object
{
public:
	KindInfo Kind;
};
typedef Handle<RemoveSelfKind> RemoveSelfKindPtr;
//CCALL_DE_ADDSELFCOMMODITY,
//CCALL_DE_REMOVESELFCOMMODITY,
class AddSelfCommodity : public Object
{
public:
	KindInfo Kind;
	COMREFLIST CommodityList;
};
typedef AddSelfCommodity RemoveSelfCommodity;
typedef Handle<AddSelfCommodity> AddSelfCommodityPtr;
typedef Handle<RemoveSelfCommodity> RemoveSelfCommodityPtr;

//EVT_PLAT_POST
enum
{
	MREQUEST_PLAT_NULL = 0,
	MREQUEST_PLAT_DE,

	MREQUEST_PLAT_MAX
};
//MREQUEST_PLAT_DE
enum
{
	CREQUEST_DE_NULL = 0,
	CREQUEST_DE_CANCEL,
	CREQUEST_DE_REGPUSH,
	CREQUEST_DE_FIELD_VALUE,
	CREQUEST_DE_HISDATA,
	CREQUEST_DE_ORDERSEND,
	CREQUEST_DE_MAX
};
//���ݲ��Ѷ���Order���
//CREQUEST_DE_ORDERSEND 
/*class REQ_OrderSend : public RequestInfo
{
public:
	COMREF Commodity;
	//
	int      cmd;
	double   volume;
	double   price;
	int      slippage;
	double   stoploss;
	double   takeprofit;
	std::string  comment; //UTF-8
	int      magic;
	unsigned long date;
	unsigned long time;
};
typedef Handle<REQ_OrderSend> REQ_OrderSendPtr;
//CREQUEST_DE_ORDERCLOSE
class REQ_OrderClose : public RequestInfo
{
public:
	COMREF Commodity;
	//
	int ticket;
	double lots;
	double price;
	int slippage;
};
typedef Handle<REQ_OrderClose> REQ_OrderClosePtr;
//CREQUEST_DE_MODIFY
class REQ_OrderModify : public RequestInfo
{
public:
	COMREF Commodity;
	int ticket;
	double price;
	double stoploss;
	double takeprofit;
	unsigned long expiration;
};
typedef Handle<REQ_OrderModify> REQ_OrderModifyPtr;*/

//EVT_PLAT_NOTIFY
enum
{
	MNOTIFY_PLAT_NULL = 0,
	MNOTIFY_PLAT_OBJECT,
	MNOTIFY_PLAT_FRAME,
	MNOTIFY_PLAT_LOGIN,
	MNOTIFY_PLAT_INDICATOR,
	MNOTIFY_PLAT_DE,			//�������ݲ�֪ͨ�¼�

	MNOTIFY_PLAT_MAX
};

//MNOTIFY_PLAT_OBJECT
enum
{
	CNOTIFY_OBJECT_NULL = 0,
	CNOTIFY_OBJECT_MAX
};
//MNOTIFY_PLAT_FRAME
enum
{
	CNOTIFY_FRAME_NULL = 0,
	CNOTIFY_FRAME_MAX
};
//MNOTIFY_PLAT_LOGIN
enum
{
	CNOTIFY_LOGIN_NULL = 0,
	CNOTIFY_LOGIN_MAX
};
//MNOTIFY_PLAT_INDICATOR
enum
{
	CNOTIFY_INDICATOR_NULL = 0,
	CNOTIFY_INDICATOR_MAX
};
//MREQUEST_PLAT_DE,MNOTIFY_PLAT_DE
enum
{
	CNOTIFY_DE_NULL = 0,
	//CNOTIFY_DE_OFFLINE,		//�����Ǳ�ʾ�����г�������
	//CNOTIFY_DE_INITDATA,		//�����ߣ�Ҳû��ȫ������,�����ϢֻҪһ���г�����֪ͨ���ͻᷢһ�����֪ͨ,���������Ϣ�ڵ�¼��ʱ��϶�
	CNOTIFY_DE_ONLINE,			//ȫ��������
	CNOTIFY_DE_RESPONSE_REGPUSH,
	CNOTIFY_DE_RESPONSE_FIELD_VALUE,
	CNOTIFY_DE_PUSH_FIELD_VALUE,
	CNOTIFY_DE_RESPONSE_HISDATA,
	CNOTIFY_DE_PUSH_HISDATA,
	CNOTIFY_DE_RESPONSE_ORDERSEND,
	CNOTIFY_DE_PUSH_ORDER,
	CNOTIFY_DE_PUSH_TRADE,
	CNOTIFY_DE_PUSH_POSITION,
	CNOTIFY_DE_MAX
};



#endif//_H_XEVTDEFINE_H_