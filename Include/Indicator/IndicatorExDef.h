#ifndef _H_INDICATOREXDEF_H_
#define _H_INDICATOREXDEF_H_

#include <DataStd.h>
#include <FaceDef.h>

#include "IndicatorDef.h"

#pragma pack(1) 

//这里的参数会影响计算结果
typedef struct tagInputValue
{
	wchar_t name[MAX_INDICATOR_NAME];
	wchar_t value[MAX_INDICATOR_STRING];
	int number:1;
	int digits:4;
	int visible:1;
	int reserved:26;
}INPUTVALUE,*PINPUTVALUE;
typedef struct tagInputInfo
{
	int count;
	INPUTVALUE input[MAX_INPUT_VALUE];
}INPUTINFO,*PINPUTINFO;

//REFLINE
typedef struct tagRefline
{
	wchar_t name[MAX_INDICATOR_NAME];
	int type:4;				//ENUM_REFLINE_TYPE
	int width:4;			//线宽
	int style:4;			//INDICATOR_LINE_STYLE
	int digits:4;			//指标精度,如果指定了精度就不使用商品的digits
	COLORREF color;			//指标颜色
	double dvalue;			//参考值
}REFLINE,*PREFLINE;

typedef struct tagIndexInfo
{
	wchar_t name[MAX_INDICATOR_NAME];
	int type:4;				//INDICATOR_INDEX_TYPE
	int shift:8;			//指标偏移
	int begin:8;			//指标开始
	int draw:4;				//INDICATOR_DRAW_TYPE
	int line:4;				//INDICATOR_LINE_TYPE
	int next:4;				//画线关联指标线
	int :0;
	int digits:4;			//指标精度,如果指定了精度就不使用商品的digits
	int width:4;			//线宽
	COLORREF color;			//指标颜色
	//double min_value;		//指标最大值
	//double max_value;		//指标最小值
	//double base_value;	//基准值
	//int level_count:8;	//水平线数目
	//int level_style:24;	//水平线风格
	//COLORREF level_color;	//水平线颜色
}INDEXINFO,*PINDEXINFO;

typedef struct tagIndexValue
{
	union
	{
		double dvalue;
		char value[8];
	};
}INDEXVALUE,*PINDEXVALUE;

typedef struct tagCalcData
{
	COMREF object;			//当前商品
	int period;				//当前交易品种的周期,以秒为单位的周期1秒=1 1分钟=60 5分钟=300......。
	int digits;				//当前交易品种的价格精确度

	int count;				//K线数目
	BAR* bars;				//K线数据
	BAR* original_bars;		//K线原始数据
	BAR* dw_bars;			//K线除复权数据

	int weight_count;		//权息数目
	WEIGHT* weight;			//权息
	ENUM_DWTYPE dwtype;		//除权类型
	unsigned long dwdate;   //指定权息日

	double field[INDICATOR_FIELD_MAX];//动态数据
}CALCDATA,*PCALCDATA;

//context
typedef struct tagIndicatorContextInfo
{
	wchar_t name[MAX_INDICATOR_NAME];						//指标名称
	unsigned long type:8;
	unsigned long style:24;									//风格
	INPUTINFO input;										//输入信息,除了显示信息外的可以用户修改的计算信息
	int tradeable:1;										//是否可以交易
	int shift:7;											//指标偏移
	int refcount:24;										//参考线数目
	double refline[MAX_INDICATOR_REFLINE];					//参考线
	int count;												//index个数
	INDEXINFO index[MAX_INDICATOR_INDEX];					//index信息
}INDICATORCONTEXTINFO,*PINDICATORCONTEXTINFO;

typedef struct tagIndicatorCalcContextInfo
{
	COMREF object;											//当前商品
	int period;												//当前交易品种的周期,以秒为单位的周期1秒=1 1分钟=60 5分钟=300......。

	ENUM_DWTYPE dwtype;										//除权类型
	unsigned long dwdate;									//指定权息日

	voidptr dataptr;										//计算对象数据
}INDICATORCALCCONTEXTINFO,*PINDICATORCALCCONTEXTINFO;

typedef struct tagIndicatorCalcInfo
{
	int count;												//指标总数目
	int counted;											//已经计算指标数目
	double* index[MAX_INDICATOR_INDEX];						//指标线数据指针，最多MAX_INDICATOR_INDEX条指标
}INDICATORCALCINFO,*PINDICATORCALCINFO;

#pragma pack()

#if defined(__cplusplus)
extern "C" {
#endif//

//////////////////////////////////////////////////////////////////////////
//C接口
typedef long (*pfninit)(PINDICATORCONTEXTINFO ctx);
typedef long (*pfncalc)(PINDICATORCONTEXTINFO ctx, PINDICATORCALCCONTEXTINFO clx, PINDICATORCALCINFO clc);
typedef void (*pfndeinit)(PINDICATORCONTEXTINFO ctx);
/*C指标需要实现一下接口
int init(const PIN_INDICATORINFO in, POUT_INDICATORINFO out);
void deinit();
int	calc(PINDICATORCALCINFO in);*/

#if defined(__cplusplus)
}

#endif//

#endif//_H_INDICATOREXDEF_H_

