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
			char szSrvName[256];	//����������
			char szSrvIp[256];		//������ip��ַ
			unsigned short usPort;	//�������˿�
			unsigned char ucSrvType;//����������
			char other[1024-256-256-sizeof(unsigned short)-sizeof(unsigned char)];
		};
		char Reserved[1024];
	};
}SERVERINFO,*PSERVERINFO;

enum // �г�����
{
	XMT_NONE		= 0,				// ��
	XMT_STOCK,							// ֤ȯ�г�
	XMT_FUTURES,						// �ڻ��г�
	XMT_OPTION,							// ��Ȩ�г�
	XMT_FOREX,							// ���
	XMT_SPOT,							// �ֻ�
	XMT_ZXXX,							// ��Ѷ��Ϣ
	XMT_MASK		= 0XF
};

enum //��Ʊ�г�
{
	XSE_NONE		= XMT_STOCK << 4,
	XSE_SH,								//�Ϻ�֤ȯ������
	XSE_SZ,								//����֤ȯ������
	XSE_HK,								//�������֤ȯ������
	XSE_NY,								//����ŦԼ֤ȯ������
	XSE_NASDAQ,							//������˹���֤ȯ������
	XSE_AMEX,							//��������֤ȯ������
	XSE_SGX,							//�¼���֤ȯ������
	XSE_MASK		= 0xFF,
};

enum
{
	XFE_NONE		= XMT_FUTURES << 4,
	XFE_SH,								//�Ϻ��ڻ�
	XFE_DL,								//�����ڻ�
	XFE_ZZ,								//֣���ڻ�
	XFE_CF,								//�н����ڻ�
	XFE_MASK		= 0XFF
};

enum
{
	XOE_NONE		= XMT_OPTION << 4,
	XOE_SH,								//��֤��Ȩ
	XOE_SZ,								//��֤��Ȩ
	XOE_CF,								//�н���Ȩ
	XOE_MASK		= 0XFF
};

enum
{
	XZX_NONE		= XMT_ZXXX << 4,
	XZX_XX,								//Ĭ����Ѷ
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

#define MarketType(x)	((((unsigned char)x) >> 4) & 0x0f) //�г�����

#define		MAX_EXCH_LENGTH			2	//�г�������󳤶�
#define		MAX_CODE_LENGTH			16	//��Ʒ������󳤶�
#define		MAX_NAME_LENGTH			16	//��Ʒ������󳤶�

typedef struct tagExchangeInfo
{
	union
	{
		struct
		{
			unsigned char Exchange;				// �г�ID
			unsigned char TimeZone;				// ���г�����ʱ��
			unsigned char PeriodsCount;			// ����ʱ������
			unsigned short Periods[4][2];		// ����ʱ������[���ֻ��4������ʱ�Σ�ÿ��ʱ�ΰ�����ʼ������ʱ�䣬��ȷ���֣�HH * 60 + MM��ʽ]
			unsigned short DelayTime;			// ���г�������ʱʱ��[��λ����]
			unsigned short CloseTime;			// ����ʱ��
			unsigned long Date;					// �г�����[YYYYMMDD��ʽ]
			unsigned long Time;					// �г�ʱ��[HHMMSS��ʽ]
			unsigned short WareCount;			// ��Ʒ����[���г�������Ʒ����]
			unsigned char KindCount;			// �������
		};
		char Reserved[512];
	};
}EXCHANGEINFO,*PEXCHANGEINFO;

enum
{
	KIND_TYPE_DEFAULT	= 0,
	KIND_TYPE_SYSTEM,					// ϵͳ��飬�������û����޸ģ�һ�������������ͬ��
	KIND_TYPE_USER,						// �û��Զ���İ��
	KIND_TYPE_TMP,
};

enum
{
	KIND_INDEX_SELF = 0,	//��ѡ�ɰ�飬1-9��ֵΪQSB_SELFBLK+(0-8)
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
					unsigned char	Exchange;	// �����г�
					unsigned char	Type;		// ��������
					unsigned short	Index;		// ��������
				};
				unsigned long Id;				// ΨһID
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
			unsigned char	PeriodsCount;			// ����ʱ������
			unsigned short	Periods[4][2];			// ����ʱ������[���ֻ��4������ʱ�Σ�ÿ��ʱ�ΰ�����ʼ������ʱ�䣬��ȷ���֣�HH * 60 + MM��ʽ]
			unsigned short	DelayTime;				// ���г�������ʱʱ��[��λ����]
			unsigned short	CloseTime;				// ����ʱ��
			unsigned short	WareCount;				// �÷������Ʒ����
			unsigned long	PriceRate;				// �÷���۸�Ŵ���[10�Ķ��ٴη�]
			unsigned char	Digits;					// ��Ч����λ��
			unsigned char	DecimalDigits;			// �÷���۸���ʾС��λ��
			unsigned short	LotSize;				// �÷����"��"����[ÿ�ְ������ٹ�]
			unsigned char	Group;					// �ͻ�����Ʒ����
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

// ��Ʒ���ýṹ
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
					unsigned char	Exchange;				// �г�ID
					unsigned char   Kind;					// ����������
					//
					unsigned char   Group;					// �ͻ��˷���
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
			unsigned char	PeriodsCount;			// ����ʱ������
			unsigned short	Periods[4][2];			// ����ʱ������[���ֻ��4������ʱ�Σ�ÿ��ʱ�ΰ�����ʼ������ʱ�䣬��ȷ���֣�HH * 60 + MM��ʽ]
			unsigned short	DelayTime;				// ���г�������ʱʱ��[��λ����]
			unsigned short	CloseTime;				// ����ʱ��
			unsigned long	PriceRate;				// �÷���۸�Ŵ���[10�Ķ��ٴη�]
			unsigned char	Digits;					// ��Ч����λ��
			unsigned char	DecimalDigits;			// �÷���۸���ʾС��λ��
			unsigned short	LotSize;				// �÷����"��"����[ÿ�ְ������ٹ�]
		};
		char Reserved[64];
	};
}COMMODITYINFO,*PCOMMODITYINFO;

//���ڶ���
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

//��Ȩ��ʽ����
enum ENUM_DWTYPE
{
	DW_NONE=0,	//����Ȩ
	DW_BACKWARD,//���	
	DW_FORWARD, //��ǰ
	DW_DAY,		//ָ������
	DW_ALL,		//ȫ�̸�Ȩ
	DW_MAX,
} ;

//��ϸ�ṹ
typedef struct tagCommodityTick
{
	union
	{
		struct
		{
			unsigned long		Serial;			// ���(�����ɴ�0��ʼ����)�����Ϊ0xFFFFFFFF��ʾ��ƴ����ϸ
			unsigned long		Time;			// ����ʱ��HH*3600+MM*60+SS
			double				Price;			// ���׼۸񣬵�ȻҲ�����¼ۣ���λ��Ԫ���Ŵ�PriceRate��
			double				Volume;			// �ɽ���(����)����λ����С��λ(�ɣ��ŵ�)
			//XMT_STOCK
			union 
			{
				struct			// ָ��
				{
					double		Amount;			// �ֶ�
				};
				struct			// ����
				{
					double		BidPrice;		// ί��ۣ���λ��Ԫ���Ŵ�PriceRate��
					double		AskPrice;		// ί���ۣ���λ��Ԫ���Ŵ�PriceRate��
					char		BoughtSoldFlag;	// �ڡ����̱�־��0ƽ�̣�1���̣�-1����
				};
			};
			//XMT_FUTURES
			union
			{
				unsigned short	Bargain;		// �ɽ�����(�ֱ�)������֤ȯ������ר��
				char			PublicTradeType;// �����������ͣ���۽�����ר��
				double			OpenInterest;	// �ֲ�������λ����С��λ
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
			char			IsInvalid;			// 1��ʾ��ʱ�������Ч���ݡ�0��ʾ����Ч���ݣ�����������ݡ�
			double			Open;				// ���̼ۣ���λ��Ԫ(��Դ���ָ����ʾ����ָ��)���Ŵ�PriceRate��
			double			High;				// ��߼ۣ���λ��Ԫ(��Դ���ָ����ʾ���ָ��)���Ŵ�PriceRate��
			double			Low;				// ��ͼۣ���λ��Ԫ(��Դ���ָ����ʾ���ָ��)���Ŵ�PriceRate��
			double			Close;				// ���̼ۣ���λ��Ԫ(��Դ���ָ����ʾ����ָ��)���Ŵ�PriceRate��
			double			Amount;				// �ɽ�����λ��Ԫ
			long			Volume;				// �ɽ�������λ����С��λ(��ɡ��ŵ�)
			long			TickVolume;			// ����������ϸ�������������ɽ�����(�ֱ�)
			
			struct 
			{
				union
				{
					char	PublicTradeType;	// �����������ͣ���۽�����ר��
					double	OpenInterest;		// �ֲ�������λ����С��λ
				};
			};
		
			union
			{
				struct //��ϸ
				{
					double		BidPrice;		// ί��ۣ���λ��Ԫ���Ŵ�PriceRate��
					double		AskPrice;		// ί���ۣ���λ��Ԫ���Ŵ�PriceRate��
					char		BoughtSoldFlag;	// �ڡ����̱�־��0ƽ�̣�1���̣�-1����	
				};
				struct // ����֤ȯ�г�ָ��
				{
					unsigned short	RiseCount;	// ���Ǽ���
					unsigned short	DropCount;	// �µ�����
					short			sec5;
					short			rddiff;		//rd-df
				};
				struct //ծȯ����
				{
					double	Interest;		// ֤ȯ�г�ծȯ��Ϣ��
					double	PreNetValue;	// ֤ȯ�г���֤ETF��LOF���LOF���ջ���ֵ��
				};
				struct //�ڻ�
				{
					double	Settlement;		// �����
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
			float			PresentNumber;		// ÿ10���͹�����
			float			MatchNumber;		// ÿ10���������
			float			MatchPrice;			// ��ɼ�(Ԫ)��
			float			Bonus;				// ÿ10�ɺ�����
			float			AddedNumber;		// ÿ10����������
			double			TotalShare;			// �ܹɱ�
			double			CurrentShare;		// ��ͨ�ɱ�
			long			SplitConsolidation;	// �𲢹ɣ����Ϊ��(1��XʱΪX)������Ϊ��(Y��1ʱΪ-Y)���Ŵ�1000�������۹�ר��
		};
		char	Reserved[64];
	};
} WEIGHT,*PWEIGHT;

#pragma pack()

#endif//_H_DATASTD_H_