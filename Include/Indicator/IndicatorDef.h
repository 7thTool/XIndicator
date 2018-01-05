#ifndef _H_INDICATORDEF_H_
#define _H_INDICATORDEF_H_

#include "XIndicatorDef.h"

#pragma pack(1) 

/*typedef void* iHandle;
typedef void* voidptr;
#define INVALID_INDICATOR_HANDLE NULL

#define CHARTS_MAX				100

#ifndef CLR_NONE
#define CLR_NONE                0xFFFFFFFFL
#endif//CLR_NONE

#define EMPTY_VALUE				(1e16)
//#define INVALID_HANDLE		-1
#define WHOLE_ARRAY				-1
#define WRONG_VALUE				-1

#define MAX_DECIMAL_NUM			7

#define MAX_INPUT_VALUE			32

enum INDICATOR_LOG_LEVEL
{
	LOGLEVEL_DEBUG	= 0,
	LOGLEVEL_INFO,
	LOGLEVEL_WARN,
	LOGLEVEL_ERROR,
};

enum INDICATOR_COORD_TYPE
{
	CT_NORMAL	=	0,			//��ͨ�ȷ�����
	CT_LOG		=	0x01,		//��������
	CT_MASK1	=	0X0F,
	CT_DIFF		=	0x10,		//�Ȳ�����(���ȷ�����)
	CT_SCALE	=	0x20,		//�ȱ�����
	CT_PERCENT	=	0x40,		//�ٷֱ�����
	CT_GOLDEN	=	0x80,		//�ƽ�ָ�
	CT_MASK2	=	0XF0,
};

//����ָ��ļ���Ҫ��۸��ֵ�ͳɽ�����ֵ���ü��㽫ִ�У���7��Ԥ�ȵı�ʶ����INDICATOR_APPLIED_PRICE ��Ŀ�У���ָ�������������ֵ������
enum INDICATOR_APPLIED_PRICE
{
	PRICE_CLOSE,		//���̼۸�
	PRICE_OPEN,			//���̼۸�
	PRICE_HIGH,			//��߼۸�
	PRICE_LOW,			//��ͼ۸�
	PRICE_MEDIAN,		//�м�ֵ����+�ͣ�/2
	PRICE_TYPICAL,		//���ͼ۸񣨸�+��+���̼ۣ�/3
	PRICE_WEIGHTED,		//ƽ���۸񣨸�+��+���̼۸�+���̼۸�/4
	PRICE_AMOUNT,		//�ɽ���
	PRICE_VOLUME,		//�ɽ���
	PRICE_TICKVOLUME,	//������
	PRICE_AVPRICE,		//ƽ���ۣ��ɽ���/�ɽ�����
};

//Period
#define INDICATOR_PERIOD_TICK		0
//#define INDICATOR_PERIOD_1SEC		1
#define INDICATOR_PERIOD_5SEC		5
#define INDICATOR_PERIOD_1MIN		60
#define INDICATOR_PERIOD_5MIN		60*5
#define INDICATOR_PERIOD_15MIN		60*15
#define INDICATOR_PERIOD_30MIN		60*30
#define INDICATOR_PERIOD_60MIN		60*60
#define INDICATOR_PERIOD_DAY		60*60*24
#define INDICATOR_PERIOD_WEEK		60*60*24*7
#define INDICATOR_PERIOD_MONTH		60*60*24*30
#define INDICATOR_PERIOD_SEASON		60*60*24*90
#define INDICATOR_PERIOD_YEAR		60*60*24*365

//���ֵ��Сֵ����
enum INDICATOR_MMX_TYPE
{
	MMX_MIN = 0,
	MMX_MAX,

	MMX_MINDISPVALUE,
	MMX_MAXDISPVALUE,

	MMX_INDEX_COUNT,

	MMX_MINOPEN = MMX_INDEX_COUNT,
	MMX_MAXOPEN,
	MMX_MINHIGH,
	MMX_MAXHIGH,
	MMX_MINLOW,
	MMX_MAXLOW,
	MMX_MINCLOSE,
	MMX_MAXCLOSE,
	MMX_MINVOLUME,
	MMX_MAXVOLUME,
	MMX_MINAMOUNT,
	MMX_MAXAMOUNT,

	MMX_MINDISPPRICE,
	MMX_MAXDISPPRICE,
	MMX_MINDISPVOLUME,
	MMX_MAXDISPVOLUME,
	MMX_MINDISPAMOUNT,
	MMX_MAXDISPAMOUNT,

	MMX_COUNT,
};

enum INDICATOR_STO_PRICE
{
	STO_LOWHIGH,	//������ͼ�/��߼۵ļ���
	STO_OPENCLOSE,	//���ڿ��̼�/���̼۵ļ���
};

enum INDICATOR_MA_METHOD
{
	MODE_SMA,	//���ƶ�ƽ���� (SMA)��Simple Moving Average
	MODE_EMA,	//ָ���ƶ�ƽ���� (EMA)��Exponential MA
	MODE_SMMA,	//ͨ���ƶ�ƽ���� (SMMA)��Smoothed MA
	MODE_LWMA,	//����Ȩ���ƶ�ƽ���� (LWMA)��Linear Weighted MA
	MODE_DMA,	//��̬�ƶ�ƽ���� Dynamic Moving Average
	//MDOE_TMA, //�ݹ��ƶ�ƽ��
	//MODE_WMA, //��Ȩ�ƶ�ƽ��
};

enum INDICATOR_TRADE_TYPE
{
	TT_BUY=0,
	TT_BUYSHORT=1,
	TT_SELL=2,
	TT_SELLSHORT=3,
	TT_LOSS=4,		//ֹ��
	TT_WIN=5,		//ֹӮ
	TT_DROP=6,		//����
	TT_STATIC=7,	//����
};

enum INDICATOR_PRICE_TYPE
{
	PT_CLOSE=0,
	PT_MARKET=1,
	PT_LIMIT=2,
	PT_STOP=3,
};

enum INDICATOR_KLINE_TYPE
{
	KLINE_K = 0,	//K��
	KLINE_BAR,		//������
	KLINE_TREND,	//������
	KLINE_MAX,
};

enum INDICATOR_STICK_TYPE
{
	STICK_LINE = 0,	//��״��
	STICK_BAR,		//��״ͼ
	STICK_MAX,
};

enum INDICATOR_HISTOGRAM_TYPE
{
	HISTOGRAM_LINE = 0,	//��״��
	HISTOGRAM_BAR,		//������
	HISTOGRAM_K,		//K��
	HISTOGRAM_MAX,
};

enum INDICATOR_TYPE
{
	INDICATOR_TYPE_MAIN			= 0,			//��ͼָ��
	INDICATOR_TYPE_SECOND,						//��ͼָ��
	INDICATOR_TYPE_POOL,						//����/��ָ��
};

enum INDICATOR_STYLE
{
	INDICATOR_STYLE_TRADER		= 0X01,			//����ָ��
	INDICATOR_STYLE_CONTAINER	= 0X02,			//����ָ��
	INDICATOR_STYLE_DRAWLINE	= 0X04,			//����ָ��
};

//�����������ͺͷ�񣬿����и��ɷ���ָ�꣬���ɷ�������ָ�꣬���Է���ָ�꣬���Է�������ָ���
//��Щָ�������INDICATOR_STYLE_CONTAINER����ָ�����������У�ͨ����������ʾָ��/����������
//���ɷ�������ָ����Ի��߽���
//���ڽű��Ļ��������и��ɽű��Ͳ��Խű����ű����Խ���
//�ű�������INDICATOR_STYLE_CONTAINER����ָ�����������У�ͨ����������ʾָ��/����������

#define MAX_INDICATOR_REFLINE	16
#define MAX_INDICATOR_INDEX		16
#define MAX_INDICATOR_NAME		32
#define MAX_INDICATOR_STRING	64

enum INDICATOR_INDEX_TYPE
{
	INDEX_LINE = 0,		//ָ����
	INDEX_CALC,			//��������
};

enum INDICATOR_DRAW_TYPE
{
	DRAW_LINE,				//����
	DRAW_SECTION,			//����
	DRAW_STICK,				//���ڻ��߻���״��
	DRAW_HISTOGRAM,			//���ڻ��߻���״ͼ
	DRAW_HISTOGRAM2,		//����ָ���������״ͼ
	DRAW_HISTOGRAM3,		//����ָ���������״ͼ
	DRAW_HISTOGRAM4,		//�ĸ�ָ���������״ͼ
	DRAW_CANDLES,			//������̨����չʾ
	DRAW_ARROW,				//����ͷ
	DRAW_FILLING,			//��������ɫ
	DRAW_ZIGZAG,			//֮���������ֱ����
	DRAW_BARS,				//���ַ�����չʾ

	DRAW_COLOR_LINE,		//��ɫ��
	DRAW_COLOR_SECTION,		//��ɫ�ֶ�
	DRAW_COLOR_HISTOGRAM,	//���ڻ��ߵĶ�ɫֱ��ͼ
	DRAW_COLOR_HISTOGRAM2,	//����ָ�껺�����Ķ�ɫֱ��ͼ
	DRAW_COLOR_CANDLES,		//��ɫ����̨
	DRAW_COLOR_ARROW,		//����ɫ��ͷ
	DRAW_COLOR_ZIGZAG,		//��ɫ֮����
	DRAW_COLOR_BARS,		//��ɫ�ֽ�
};

enum INDICATOR_LINE_TYPE
{
	LINE_SOLID,		//ʵ��
	LINE_DASH,		//����
	LINE_DOT,			//����
	LINE_DASHDOT,		//�۵���
	LINE_DASHDOTDOT,	//˫�۵���
};

enum INDICATOR_CUSTOMIND_PROPERTY_STRING
{
	INDICATOR_SHORTNAME,
	INDICATOR_LEVELTEXT,
};

enum INDICATOR_REFVALUE_TYPE
{
	REFVALUE_NONE	= 0,
	REFVALUE_BOOL,
	REFVALUE_INTEGER,
	REFVALUE_DATE,
	REFVALUE_TIME,
	REFVALUE_FLOAT,
	REFVALUE_STRINGA,
	REFVALUE_STRINGW,
#ifndef UNICODE
	REFVALUE_STRING = REFVALUE_STRINGA,
#else
	REFVALUE_STRING = REFVALUE_STRINGW,
#endif//
	REFVALUE_POINT,
};

typedef struct tagRefValue
{
	int type:4;
	int size:14;
	int maxsize:14;
	void* ptr;							//refvalue ptr
}REFVALUE,*PREFVALUE;

//#define SYMBOL_SHSE "SH" //�Ϻ��г�
//#define SYMBOL_SZSE "SZ" //�����г�

//typedef const char* SYMBOL; //code.market,eg��000001.SZ ƽ������

enum INDICATOR_FIELD
{
	INDICATOR_FIELD_0 = 0,
	INDICATOR_FIELD_DATE,
	INDICATOR_FIELD_TIME,
	INDICATOR_FIELD_CLOSE,
	INDICATOR_FIELD_OPEN, //0-4
	INDICATOR_FIELD_HIGH,
	INDICATOR_FIELD_LOW,
	INDICATOR_FIELD_NOW,
	INDICATOR_FIELD_VOLUME,
	INDICATOR_FIELD_LAST_VOLUME, //5-9
	INDICATOR_FIELD_AMOUNT,
	INDICATOR_FIELD_AVERAGE_PRICE,
	INDICATOR_FIELD_DELTA,
	INDICATOR_FIELD_RANGE_PERCENT,
	INDICATOR_FIELD_DELTA_PERCENT, //10-14
	INDICATOR_FIELD_WEIBI,
	INDICATOR_FIELD_BID_ASK_VOLUME_DIFF,
	INDICATOR_FIELD_VOLUME_RATIO,
	INDICATOR_FIELD_BID_VOLUME,
	INDICATOR_FIELD_ASK_VOLUME, //15-19
	INDICATOR_FIELD_BID_PRICE,
	INDICATOR_FIELD_ASK_PRICE,
	INDICATOR_FIELD_SOLD_VOLUME,
	INDICATOR_FIELD_BOUGHT_VOLUME,
	INDICATOR_FIELD_RECENT_DELTA_PERCENT, //20-24
	INDICATOR_FIELD_TURNOVER_RATE,
	INDICATOR_FIELD_AVERAGE_VOLUME,
	INDICATOR_FIELD_PRICE_EARNING_RATIO,
	INDICATOR_FIELD_POSITION,
	INDICATOR_FIELD_INTEREST, //25-29
	INDICATOR_FIELD_FULL_PRICE,
	INDICATOR_FIELD_BARGAIN,
	INDICATOR_FIELD_AVERAGE_BARGAIN_VOLUME,
	INDICATOR_FIELD_CEILING_PRICE,
	INDICATOR_FIELD_FLOOR_PRICE, //30-34
	INDICATOR_FIELD_TOTAL_VALUE,
	INDICATOR_FIELD_CURRENT_VALUE,
	INDICATOR_FIELD_PRICE_BOOK_VALUE_RATIO,
	INDICATOR_FIELD_PREV_POSITION,
	INDICATOR_FIELD_PREV_SETTLEMENT, //35-39
	INDICATOR_FIELD_SETTLEMENT,
	INDICATOR_FIELD_LAST_DELTA_POSITION,
	INDICATOR_FIELD_DELTA_POSITION,
	INDICATOR_FIELD_LAST_OPEN_CLOSE_POSITION,
	INDICATOR_FIELD_RISE_COUNT, //40-44
	INDICATOR_FIELD_DROP_COUNT,
	INDICATOR_FIELD_EQUAL_COUNT, //45-46
	INDICATOR_FIELD_DIGITS,
	INDICATOR_FIELD_BASE_MAX,
	//QUOTE
	INDICATOR_FIELD_ASK_PRICE_10 = INDICATOR_FIELD_BASE_MAX, // ��ʮ��		��(Ԫ)/��
	INDICATOR_FIELD_ASK_PRICE_9, // ���ż�		��(Ԫ)/��
	INDICATOR_FIELD_ASK_PRICE_8, // ���˼�		��(Ԫ)/��
	INDICATOR_FIELD_ASK_PRICE_7, // ���߼�		��(Ԫ)/��
	INDICATOR_FIELD_ASK_PRICE_6, // ������		��(Ԫ)/��
	INDICATOR_FIELD_ASK_PRICE_5, // �����		��(Ԫ)/��
	INDICATOR_FIELD_ASK_PRICE_4, // ���ļ�		��(Ԫ)/��
	INDICATOR_FIELD_ASK_PRICE_3, // ������		��(Ԫ)/��
	INDICATOR_FIELD_ASK_PRICE_2, // ������		��(Ԫ)/��
	INDICATOR_FIELD_ASK_PRICE_1, // ��һ�ۣ�ͬ������IDF_ASK_PRICE
	INDICATOR_FIELD_BID_PRICE_1, // ��һ�ۣ�ͬ�����IDF_BID_PRICE
	INDICATOR_FIELD_BID_PRICE_2, // �����		��(Ԫ)/��
	INDICATOR_FIELD_BID_PRICE_3, // ������		��(Ԫ)/��
	INDICATOR_FIELD_BID_PRICE_4, // ���ļ�		��(Ԫ)/��
	INDICATOR_FIELD_BID_PRICE_5, // �����		��(Ԫ)/��
	INDICATOR_FIELD_BID_PRICE_6, // ������		��(Ԫ)/��
	INDICATOR_FIELD_BID_PRICE_7, // ���߼�		��(Ԫ)/��
	INDICATOR_FIELD_BID_PRICE_8, // ��˼�		��(Ԫ)/��
	INDICATOR_FIELD_BID_PRICE_9, // ��ż�		��(Ԫ)/��
	INDICATOR_FIELD_BID_PRICE_10, // ��ʮ��		��(Ԫ)/��
	INDICATOR_FIELD_ASK_VOLUME_10, // ��ʮ��		��(�ɡ��š���)
	INDICATOR_FIELD_ASK_VOLUME_9, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_ASK_VOLUME_8, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_ASK_VOLUME_7, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_ASK_VOLUME_6, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_ASK_VOLUME_5, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_ASK_VOLUME_4, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_ASK_VOLUME_3, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_ASK_VOLUME_2, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_ASK_VOLUME_1, // ��һ��		��(�ɡ��š���)
	INDICATOR_FIELD_BID_VOLUME_1, // ��һ��		��(�ɡ��š���)
	INDICATOR_FIELD_BID_VOLUME_2, // �����		��(�ɡ��š���)
	INDICATOR_FIELD_BID_VOLUME_3, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_BID_VOLUME_4, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_BID_VOLUME_5, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_BID_VOLUME_6, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_BID_VOLUME_7, // ������		��(�ɡ��š���)
	INDICATOR_FIELD_BID_VOLUME_8, // �����		��(�ɡ��š���)
	INDICATOR_FIELD_BID_VOLUME_9, // �����		��(�ɡ��š���)
	INDICATOR_FIELD_BID_VOLUME_10, // ��ʮ��	IDF_ASK_VOL_DIFF_
	INDICATOR_FIELD_MAX,
};

enum 
{
	REF_CALCDATA_NONE				= 0,	//Ĭ��ֻ�������ݻ���
	REF_CALCDATA_LOADDATA			= 0X01,	//���ؼ�������
	REF_CALCDATA_LOADFINANCE		= 0X02, //���ز�������
	REF_CALCDATA_LOADFIELD			= 0X04,	//�����ֶ�����
	REF_CALCDATA_AUTOREQDATA		= 0X10,	//�Զ������������
	REF_CALCDATA_AUTOREQFINANCE		= 0X20,	//�Զ������������
	REF_CALCDATA_AUTOREQFIELD		= 0X40,	//�Զ������ֶ�����
	REF_CALCDATA_AUTOREQQUOTEFIELD	= 0X80,	//�Զ����󱨼��ֶ�����
	REF_CALCDATA_DEFAULT			= (REF_CALCDATA_LOADDATA|REF_CALCDATA_AUTOREQDATA)
};

//////////////////////////////////////////////////////////////////////////
///���߲���

enum INDICATOR_DRAWLINE_TYPE
{
	TVLT_NONE		= 0,	//
	TVLT_DDLINE,			// ����ֱ��
	TVLT_DOTDOT,			// �����߶�
	TVLT_PLINE,				// ƽ����
	TVLT_PERLINE,			// �ٷֱ���
	TVLT_RADIALLINE,		// ��������
	TVLT_BARLINE,			// դ����
	//UGUNSLINE,			// �ϸ�����
	//DGUNSLINE,			// �¸�����
	TVLT_GUNSLINE,			// ������
	TVLT_GOLDLINE,			// �ƽ�ָ���
	TVLT_BLACKHOLE,			// ���غڶ�
	TVLT_ELLIPSEARC,		// Բ��
	TVLT_MULTIARC,			// ��Բ��
	TVLT_GOLDARC,			// ���Ȼƽ���
	TVLT_CIRCLE,			// Բ
	TVLT_MULTIELLIPSE,		// ��Բ
	TVLT_CYCLELINE,			// ������
	TVLT_FABCYCLELINE,		// �Ѳ�����������
	TVLT_SUZULINE,			// ������
	TVLT_SINLINE,			// ������
	TVLT_RECTANGLE,			// ����
	TVLT_TEXT,				// ����
	TVLT_UPARROW,			// �ϼ�ͷ
	TVLT_DOWNARROW,			// �¼�ͷ
	TVLT_STOCKBOX,			// ������
	TVLT_REGRESSLINE,		// ���Իع�
	TVLT_REGRESSZONE,		// ���Իع��
	TVLT_REGRESSCHANNEL,	// �ع�ͨ��
	TVLT_COUNT=TVLT_REGRESSCHANNEL,	// ���������������ڲ�������
	TVLT_MAX,
};

typedef struct tagTPoint
{
	double dvalue;			//yֵ
	unsigned long date;		//x����
	unsigned long time;		//xʱ��
	//char lable[32];
}TPOINT,*PTPOINT;*/

//////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif//_H_INDICATORDEF_H_