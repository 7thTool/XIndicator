#ifndef _H_DATASTD_H_
#define _H_DATASTD_H_

#include "ErrDef.h"
#include "NetDef.h"

#pragma pack(1)

#define UINT64_TO_DOUBLE(x)		(double)((signed __int64)(x))

#define YYMMDD_TO_ULONG(y,m,d)		((y)*10000+m*100+d)
#define ULONG_TO_YYMMDD(x,y,m,d)	((y)=(x)/10000,(m)=(x)/100%100,(d)=(x)%100)

#define HHMMSS_TO_ULONG(h,m,s)		((h)*10000+m*100+s)
#define ULONG_TO_HHMMSS(x,h,m,s)	((h)=(x)/10000,(m)=(x)/100%100,(s)=(x)%100)

#define HHMMSSsss_TO_ULONG(h,m,s,sss)		(HHMMSS_TO_ULONG(h,m,s)*1000+(sss))
#define ULONG_TO_HHMMSSsss(x,h,m,s,sss)		((h)=(x)/(10000000),(m)=(x)/100000%100000,(s)=(x)/1000%1000,(sss)=(x)%1000)

#define MINUTE_TO_HHMM(x)		((x)/60*100 + (x)%60)
#define HHMM_TO_MINUTE(x)		((x)/100*60 + (x)%100)

#define SECOND_TO_HHMM(x)		MINUTE_TO_HHMM((x)/60)
#define HHMM_TO_SECOND(x)		(HHMM_TO_MINUTE(x)*60)

#define HHMMSS_TO_MINUTE(x)		HHMM_TO_MINUTE((x)/100)
#define HHMMSSsss_TO_MINUTE(x)	HHMMSS_TO_MINUTE((x)/1000)
#define MINUTE_TO_HHMMSS(x)		(MINUTE_TO_HHMM(x)*100)
#define MINUTE_TO_HHMMSSsss(x)	(MINUTE_TO_HHMMSS(x)*1000)

#define HHMMSS_TO_SECOND(x)		((x)/10000*60*60 + (x)%10000/100*60 + (x)%10000%100)
#define HHMMSSsss_TO_SECOND(x)	HHMMSS_TO_SECOND((x)/1000)
#define SECOND_TO_HHMMSS(x)		((x)/(60*60)*10000 + (x)%(60*60)/60*100 + (x)%60)
#define SECOND_TO_HHMMSSsss(x)	(SECOND_TO_HHMMSS(x)*1000)

typedef struct tagServerInfo
{
	union
	{
		struct  
		{
			char szSrvName[256];	//服务器名称
			char szSrvIp[256];		//服务器ip地址
			unsigned short usPort;	//服务器端口
			unsigned char ucSrvType;//服务器类型
			char other[1024-256-256-sizeof(unsigned short)-sizeof(unsigned char)];
		};
		char Reserved[1024];
	};
}SERVERINFO,*PSERVERINFO;

enum // 市场种类
{
	XMT_NONE		= 0,				// 无
	XMT_STOCK,							// 证券市场
	XMT_FUTURES,						// 期货市场
	XMT_OPTION,							// 期权市场
	XMT_FOREX,							// 外汇
	XMT_SPOT,							// 现货
	XMT_ZXXX,							// 资讯信息
	XMT_MASK		= 0XF
};

enum //股票市场
{
	XSE_NONE		= XMT_STOCK << 4,
	XSE_SH,								//上海证券交易所
	XSE_SZ,								//深圳证券交易所
	XSE_HK,								//香港联合证券交易所
	XSE_NY,								//美股纽约证券交易所
	XSE_NASDAQ,							//美股纳斯达克证券交易所
	XSE_AMEX,							//美股美国证券交易所
	XSE_SGX,							//新加坡证券交易所
	XSE_MASK		= 0xFF,
};

enum
{
	XFE_NONE		= XMT_FUTURES << 4,
	XFE_SH,								//上海期货
	XFE_DL,								//大连期货
	XFE_ZZ,								//郑州期货
	XFE_CF,								//中金所期货
	XFE_MASK		= 0XFF
};

enum
{
	XOE_NONE		= XMT_OPTION << 4,
	XOE_SH,								//上证期权
	XOE_SZ,								//深证期权
	XOE_CF,								//中金期权
	XOE_MASK		= 0XFF
};

enum
{
	XZX_NONE		= XMT_ZXXX << 4,
	XZX_XX,								//默认资讯
	XZX_MASK		= 0XFF
};

#define XEN_SHANGHAIA	"SH"
#define XEN_SHENZHENA	"SZ"
#define XEN_CFA			"CF"
#define XEN_ZX3XA		"X3"

#define XEN_SHANGHAIW	L"SH"
#define XEN_SHENZHENW	L"SZ"
#define XEN_CFW			L"CF"
#define XEN_ZX3XW		L"X3"

#define MarketType(x)	((((unsigned char)x) >> 4) & 0x0f) //市场类型

#define		MAX_EXCH_LENGTH			2	//市场代码最大长度
#define		MAX_CODE_LENGTH			16	//商品代码最大长度
#define		MAX_NAME_LENGTH			16	//商品名称最大长度

typedef struct tagExchangeInfo
{
	union
	{
		struct
		{
			unsigned char Exchange;				// 市场ID
			unsigned char TimeZone;				// 该市场所处时区
			unsigned char PeriodsCount;			// 交易时段数量
			unsigned short Periods[4][2];		// 交易时段描述[最多只是4个交易时段，每个时段包括开始、结束时间，精确到分，HH * 60 + MM格式]
			unsigned short DelayTime;			// 该市场行情延时时间[单位：秒]
			unsigned short CloseTime;			// 收盘时间
			unsigned long Date;					// 市场日期[YYYYMMDD格式]
			unsigned long Time;					// 市场时间[HHMMSS格式]
			unsigned short WareCount;			// 商品数量[该市场所有商品数量]
			unsigned char KindCount;			// 类别数量
		};
		char Reserved[512];
	};
}EXCHANGEINFO,*PEXCHANGEINFO;

enum
{
	KIND_TYPE_DEFAULT	= 0,
	KIND_TYPE_SYSTEM,					// 系统板块，不允许用户作修改，一般与服务器保持同步
	KIND_TYPE_USER,						// 用户自定义的板块
	KIND_TYPE_TMP,
};

enum
{
	KIND_INDEX_SELF = 0,	//自选股板块，1-9，值为QSB_SELFBLK+(0-8)
	KIND_INDEX_SELF1, 
	KIND_INDEX_SELF2,
	KIND_INDEX_SELF3,
	KIND_INDEX_SELF4,
	KIND_INDEX_SELF5,
	KIND_INDEX_SELF6,
	KIND_INDEX_SELF7,
	KIND_INDEX_SELF8,
	KIND_INDEX_SELFCOUNT,
	KIND_INDEX_SELFMAX = 16,
};

typedef struct tagKindReference
{
	union
	{
		struct
		{
			union
			{
				struct  
				{
					unsigned char	Exchange;	// 分类市场
					unsigned char	Type;		// 分类类型
					unsigned short	Index;		// 分类索引
				};
				unsigned long Id;				// 唯一ID
			};
			char Code[MAX_CODE_LENGTH+1];
			wchar_t Name[MAX_NAME_LENGTH+1];
		};
		char Reserved[64];
	};
} KIND,*PKIND;

typedef struct tagKindInfo
{
	union
	{
		struct
		{
			KIND			Kind;
			unsigned char	PeriodsCount;			// 交易时段数量
			unsigned short	Periods[4][2];			// 交易时段描述[最多只是4个交易时段，每个时段包括开始、结束时间，精确到分，HH * 60 + MM格式]
			unsigned short	DelayTime;				// 该市场行情延时时间[单位：秒]
			unsigned short	CloseTime;				// 收盘时间
			unsigned short	WareCount;				// 该分类的商品数量
			unsigned long	PriceRate;				// 该分类价格放大倍数[10的多少次方]
			unsigned char	Digits;					// 有效数字位数
			unsigned char	DecimalDigits;			// 该分类价格显示小数位数
			unsigned short	LotSize;				// 该分类的"手"比率[每手包括多少股]
			unsigned char	Group;					// 客户端商品类型
		};
		char Reserved[64];
	};
} KINDINFO,*PKINDINFO;

enum
{
	COMREF_TYPE_STRUCT	= 0,
	COMREF_TYPE_SZEXCH  = 1,
	COMREF_TYPE_STRING	= 2,	//SH,0000001
};

// 商品引用结构
typedef struct tagCommodityReference
{
	union
	{
		struct  
		{
			unsigned char Type;
			union
			{
				struct
				{
					unsigned char	Exchange;				// 市场ID
					unsigned char   Kind;					// 服务器分类
					//
					unsigned char   Group;					// 客户端分组
				};
				struct
				{
					char Exch[MAX_EXCH_LENGTH+1];
				};
				char Reserved[3];
			};
			char Code[MAX_CODE_LENGTH+1];
			wchar_t Name[MAX_NAME_LENGTH+1];
		};
		char String[64];
	};
} COMREF,*PCOMREF;

typedef struct tagCommodityInfo
{
	union
	{
		struct
		{
			COMREF			Commodity;
			unsigned char	PeriodsCount;			// 交易时段数量
			unsigned short	Periods[4][2];			// 交易时段描述[最多只是4个交易时段，每个时段包括开始、结束时间，精确到分，HH * 60 + MM格式]
			unsigned short	DelayTime;				// 该市场行情延时时间[单位：秒]
			unsigned short	CloseTime;				// 收盘时间
			unsigned long	PriceRate;				// 该分类价格放大倍数[10的多少次方]
			unsigned char	Digits;					// 有效数字位数
			unsigned char	DecimalDigits;			// 该分类价格显示小数位数
			unsigned short	LotSize;				// 该分类的"手"比率[每手包括多少股]
		};
		char Reserved[64];
	};
}COMMODITYINFO,*PCOMMODITYINFO;

//周期定义
enum ENUM_TIMEFRAMES
{
	CYC_TICK=0,
	//CYC_1SEC,
	CYC_5SEC,
	CYC_ANYSEC,
	CYC_1MIN,
	CYC_5MIN,
	CYC_15MIN,
	CYC_30MIN,
	CYC_60MIN,
	CYC_ANYMIN,
	CYC_DAY,
	CYC_WEEK,
	CYC_MONTH,
	CYC_SEASON,
	CYC_YEAR,
	CYC_ANYDAY,
	CYC_MAX,
} ;

//除权方式定义
enum ENUM_DWTYPE
{
	DW_NONE=0,	//不除权
	DW_BACKWARD,//向后	
	DW_FORWARD, //向前
	DW_DAY,		//指定日期
	DW_ALL,		//全程复权
	DW_MAX,
} ;

//明细结构
typedef struct tagCommodityTick
{
	union
	{
		struct
		{
			unsigned long		Serial;			// 序号(按个股从0开始编序)，如果为0xFFFFFFFF表示是拼接明细
			unsigned long		Time;			// 交易时间HH*3600+MM*60+SS
			double				Price;			// 交易价格，当然也是最新价，单位：元，放大PriceRate倍
			double				Volume;			// 成交量(现量)，单位：最小单位(股，张等)
			//XMT_STOCK
			union 
			{
				struct			// 指数
				{
					double		Amount;			// 现额
				};
				struct			// 个股
				{
					double		BidPrice;		// 委买价，单位：元，放大PriceRate倍
					double		AskPrice;		// 委卖价，单位：元，放大PriceRate倍
					char		BoughtSoldFlag;	// 内、外盘标志，0平盘；1外盘；-1内盘
				};
			};
			//XMT_FUTURES
			union
			{
				unsigned short	Bargain;		// 成交笔数(现笔)，沪深证券交易所专用
				char			PublicTradeType;// 公共交易类型，香港交易所专用
				double			OpenInterest;	// 持仓量，单位：最小单位
			};
			
		};
		char Reserved[64];
	};
} TICK,*PTICK;

typedef struct tagCommodityHistory 
{
	union
	{
		struct
		{
			unsigned long	Date;
			unsigned long	Time;
			char			IsInvalid;			// 1表示该时间点是无效数据。0表示是有效数据，用于造假数据。
			double			Open;				// 开盘价，单位：元(针对大盘指数表示开盘指数)，放大PriceRate倍
			double			High;				// 最高价，单位：元(针对大盘指数表示最高指数)，放大PriceRate倍
			double			Low;				// 最低价，单位：元(针对大盘指数表示最低指数)，放大PriceRate倍
			double			Close;				// 收盘价，单位：元(针对大盘指数表示收盘指数)，放大PriceRate倍
			double			Amount;				// 成交金额，单位：元
			long			Volume;				// 成交量，单位：最小单位(如股、张等)
			long			TickVolume;			// 跳动量，明细跳动次数，即成交笔数(现笔)
			
			struct 
			{
				union
				{
					char	PublicTradeType;	// 公共交易类型，香港交易所专用
					double	OpenInterest;		// 持仓量，单位：最小单位
				};
			};
		
			union
			{
				struct //明细
				{
					double		BidPrice;		// 委买价，单位：元，放大PriceRate倍
					double		AskPrice;		// 委卖价，单位：元，放大PriceRate倍
					char		BoughtSoldFlag;	// 内、外盘标志，0平盘；1外盘；-1内盘	
				};
				struct // 用于证券市场指数
				{
					unsigned short	RiseCount;	// 上涨家数
					unsigned short	DropCount;	// 下跌家数
					short			sec5;
					short			rddiff;		//rd-df
				};
				struct //债券基金
				{
					double	Interest;		// 证券市场债券利息，
					double	PreNetValue;	// 证券市场深证ETF、LOF或非LOF昨日基金净值，
				};
				struct //期货
				{
					double	Settlement;		// 结算价
				};
			};
		};
		char	Reserved[128];
	};
} HISDATA,*PHISDATA,BAR,*PBAR;

typedef struct tagWeightInfo
{
	union
	{
		struct
		{
			unsigned long	Date;
			//unsigned long	Time;
			float			PresentNumber;		// 每10股送股数，
			float			MatchNumber;		// 每10股配股数，
			float			MatchPrice;			// 配股价(元)，
			float			Bonus;				// 每10股红利，
			float			AddedNumber;		// 每10股增发股数
			double			TotalShare;			// 总股本
			double			CurrentShare;		// 流通股本
			long			SplitConsolidation;	// 拆并股，拆股为正(1→X时为X)；并股为负(Y→1时为-Y)，放大1000倍——港股专用
		};
		char	Reserved[64];
	};
} WEIGHT,*PWEIGHT;

#pragma pack()

#endif//_H_DATASTD_H_