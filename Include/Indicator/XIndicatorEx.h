#ifndef _H_XINDICATOREX_H_
#define _H_XINDICATOREX_H_

#include <DataStd.h>
#include <FaceDef.h>

#include "XIndicator.h"
#include "IndicatorExDef.h"

//#if defined(__cplusplus)
//extern "C" {
//#endif//

	XINDICATOR_API const char* iExchange2String(unsigned char exchange, char* str, int len);
	XINDICATOR_API const wchar_t* iExchange2String(unsigned char exchange, wchar_t* str, int len);
	XINDICATOR_API unsigned char iString2Exchange(const char* str);
	XINDICATOR_API unsigned char iString2Exchange(const wchar_t* str);

	XINDICATOR_API LPCSTR iObject2String(COMREF object, LPSTR str, int len);
	XINDICATOR_API LPCWSTR iObject2String(COMREF object, LPWSTR str, int len);
	XINDICATOR_API COMREF iString2Object(LPCSTR str);
	XINDICATOR_API COMREF iString2Object(LPCWSTR str);

	XINDICATOR_API ENUM_TIMEFRAMES iPeriod2Period(int iPeriod, int* pPeriodEx = NULL);
	XINDICATOR_API int Period2iPeriod(ENUM_TIMEFRAMES Period, int PeriodEx);
	XINDICATOR_API void Period2TimeSpan(ENUM_TIMEFRAMES Period, int PeriodEx
		, unsigned long* Days, unsigned long* Hours, unsigned long* Minutes, unsigned long* Seconds);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	//C/C++接口提供的位置还是数组索引顺序
	//脚本接口提供的是引用位置，即数组相反，当前交易周期为0，前一交易周期为1，以此类推
	//可以用iReverseOffset来互相转换
	//

	XINDICATOR_API voidptr iRefData(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	XINDICATOR_API voidptr iRefFieldData(COMREF object);
	XINDICATOR_API voidptr iRefDataEx(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, unsigned long flags);
	XINDICATOR_API void iReqData(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);

	XINDICATOR_API COMREF iObject(voidptr dataptr);

	XINDICATOR_API bool iRefDefault(const wchar_t* name, INDICATORCONTEXTINFO* ctx);

	//引用指标
	XINDICATOR_API iHandle iRefA(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, LPCSTR name, LPCSTR xml, int xmlflag);
	XINDICATOR_API iHandle iRefW(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, LPCWSTR name, LPCWSTR xml, int xmlflag);
	XINDICATOR_API iHandle iRefA(LPCSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	XINDICATOR_API iHandle iRefW(LPCWSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);

	XINDICATOR_API iHandle iTestA(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, LPCSTR name, LPCSTR xml, int xmlflag);
	XINDICATOR_API iHandle iTestW(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, LPCWSTR name, LPCWSTR xml, int xmlflag);
	XINDICATOR_API iHandle iTestA(LPCSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	XINDICATOR_API iHandle iTestW(LPCWSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);

	XINDICATOR_API iHandle iScript(COMREF		object,			// 交易品种
		int			period,			// 周期
		ENUM_DWTYPE	dwtype,			// 除复权类型 
		unsigned long	dwdate,			// 定点除复权日期
		LPCTSTR		name,			// 指标
		LPCTSTR		xml,			// 输入参数
		int			xmlflag,		// 输入参数标志
		LPCTSTR		scripts,		// 脚本
		LPCTSTR		language		// 语言
		);


	XINDICATOR_API void iAddPool(COMREF object, iHandle handle);
	XINDICATOR_API void iRemovePool(COMREF object, iHandle handle);

	//内建指标
	//返回值
	//返回特殊技术指标处理器，失败返回 INVALID_HANDLE。

	//加速振荡指标并返回处理器，只有一个缓冲区。
	XINDICATOR_API iHandle  iAC(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate// 定点除复权日期
		);

	//函数返回累积/分配指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iAD(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		INDICATOR_APPLIED_PRICE applied_volume	// 用于计算的交易量类型
		);

	//函数返回平均定向移动指数指标处理器。
	XINDICATOR_API iHandle  iADX(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int	adx_period		// 平均周期
		);

	//函数返回韦尔达平均定向移动指数处理器。
	XINDICATOR_API iHandle  iADXWilder(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate, // 定点除复权日期
		int adx_period		// 平均周期
		);

	//函数返回鳄鱼指标处理器。
	XINDICATOR_API iHandle  iAlligator(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate, // 定点除复权日期
		int jaw_period,       // 咽喉计算周期
		int jaw_shift,        // 咽喉平移
		int teeth_period,     // 牙齿计算周期
		int teeth_shift,      // 牙齿平移
		int lips_period,      // 唇部计算周期
		int lips_shift,       // 唇部平移
		INDICATOR_MA_METHOD ma_method,		// 平滑类型
		INDICATOR_APPLIED_PRICE applied_price	// 价格或者处理器类型
		);


	//函数返回适当移动平均指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iAMA(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ama_period,		//  AMA平均周期
		int fast_ma_period,	// 快速 MA 周期
		int slow_ma_period,	// 慢速 MA 周期
		int ama_shift,		// 指标平移
		INDICATOR_APPLIED_PRICE applied_price	// 价格或者处理器类型
		);

	//函数返回动量震荡指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iAO(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate// 定点除复权日期
		);

	//函数返回平均真实区域指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iATR(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period	// 平均周期 
		);

	//函数返回熊市指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iBearsPower(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period	// 平均周期
		);

	//函数返回布林带指标处理器。
	XINDICATOR_API iHandle  iBands(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,	// 定点除复权日期
		int bands_period,		// 平均线计算周期
		int bands_shift,		// 指标平移
		double deviation,		// 标准差数
		INDICATOR_APPLIED_PRICE applied_price	// 价格或处理器类型
		);

	//函数返回牛市指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iBullsPower(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period	// 平均周期
		);

	//函数返回顺势指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iCCI(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period,			// 平均周期
		INDICATOR_APPLIED_PRICE applied_price	// 价格或处理器类型
		);

	//The function returns the handle of the Chaikin Oscillator indicator. It has only one buffer.
	XINDICATOR_API iHandle  iChaikin(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int fast_ma_period,	// 快速周期
		int slow_ma_period,	// 慢速周期
		INDICATOR_MA_METHOD ma_method,	// 平滑类型
		INDICATOR_APPLIED_PRICE applied_volume	// 交易量类型
		);

	//函数返回双指数移动平均线指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iDEMA(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period,         // 平均周期
		int ma_shift,          // 平移
		INDICATOR_APPLIED_PRICE applied_price	// 价格或者处理器类型
		);

	//函数返回DeMarker指标处理器。只有一个缓冲区。 
	XINDICATOR_API iHandle  iDeMarker(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period		// 平均周期
		);

	//函数返回轨道线指标处理器。
	XINDICATOR_API iHandle  iEnvelopes(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period,	// 平均线计算周期
		int ma_shift,		// 指标平移
		INDICATOR_MA_METHOD ma_method,	// 平滑类型
		INDICATOR_APPLIED_PRICE applied_price,	// 价格或者处理器类型
		double deviation	// 中线边界差(百分率)
		);

	//函数返回强力指数指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iForce(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period,		// 平均周期
		INDICATOR_MA_METHOD ma_method,	// 平滑类型
		INDICATOR_APPLIED_PRICE applied_volume	// 计算的交易量类型
		);

	//函数返回分形学指标处理器。
	XINDICATOR_API iHandle  iFractals(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate// 定点除复权日期
		);

	//函数返回分形学适合移动平均指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iFrAMA(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period,		// 平均周期
		int ma_shift,			// 图表平移
		INDICATOR_APPLIED_PRICE applied_price	// 价格或者处理器类型
		);

	//函数返回鳄鱼振荡器指标处理器。振荡器表示鳄鱼指标蓝线和红线（上升柱状图）的区别以及红线和绿线的区别（下降柱状图）。
	XINDICATOR_API iHandle  iGator(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int jaw_period,		// 咽喉计算周期
		int jaw_shift,		// 咽喉平移
		int teeth_period,		// 牙齿计算周期
		int teeth_shift,		// 牙齿平移
		int lips_period,		// 唇部计算周期
		int lips_shift,		// 唇部平移
		INDICATOR_MA_METHOD ma_method, // 平滑类型
		INDICATOR_APPLIED_PRICE applied_price	// 价格或者处理器类型
		);

	//函数返回一目均衡图指标处理器。
	XINDICATOR_API iHandle  iIchimoku(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int tenkan_sen,	// Tenkan-sen转换线周期
		int kijun_sen,		// Kijun-sen基准线周期
		int senkou_span_b	// Senkou Span B周期
		);

	//函数返回市场便利指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iBWMFI(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		INDICATOR_APPLIED_PRICE applied_volume	// 计算的交易量类型
		);

	//函数返回动量指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iMomentum(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int mom_period,	// 平均周期
		INDICATOR_APPLIED_PRICE applied_price	// 价格或者处理器类型
		);

	//函数返回资金流向指标处理器。
	XINDICATOR_API iHandle  iMFI(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period,			// 平均周期
		INDICATOR_APPLIED_PRICE applied_volume	// 计算的交易量类型
		);

	//函数返回移动平均数指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iMA(
		COMREF object,			// 交易品种
		int period,				// 周期
		ENUM_DWTYPE dwtype,		// 除复权类型 
		unsigned long dwdate,	// 定点除复权日期
		int ma_period,			// 平均周期
		int ma_shift,			// 平移
		INDICATOR_MA_METHOD ma_method, // 平滑类型
		INDICATOR_APPLIED_PRICE applied_price // 价格或者处理程序类型
		);

	//函数返回移动平均震荡指标处理器。OsMA振荡器显示MACD与其讯息线之间的区别。只有一个缓冲区。
	XINDICATOR_API iHandle  iOsMA(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int fast_ema_period,	// 快速移动平均数周期
		int slow_ema_period,	// 慢速移动平均数周期
		int signal_period,		// 不同点的平均周期
		INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器的类型
		);

	//函数返回移动平均数聚/散指标处理器。在OsMA被称为MACD柱状图的系统中，该指标显示为两条线。在客户端移动平均数聚/散像柱状图。
	XINDICATOR_API iHandle  iMACD(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int fast_ema_period,	// 快速移动平均数周期
		int slow_ema_period,	// 慢速移动平均数周期
		int signal_period,		// 不同点的平均周期
		INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器的类型
		);

	//函数返回平衡交易量指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iOBV(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		INDICATOR_APPLIED_PRICE applied_volume // 计算的交易量类型
		);

	//函数返回抛物转向系统指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iSAR(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		double step,			// 逐步增加
		double maximum			// 最大止损水平
		);

	//函数返回相对强度指数指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iRSI(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period,			// 平均周期
		INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器类型
		);

	//函数返回相对活力指数指标处理器。
	XINDICATOR_API iHandle  iRVI(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period			// 平均周期
		);

	//函数返回标准偏差指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iStdDev(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period,		// 平均周期
		int ma_shift,		// 平移
		INDICATOR_MA_METHOD ma_method, // 平滑类型
		INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器类型
		);

	//函数返回随机摆动指标处理器。
	XINDICATOR_API iHandle  iStochastic(
		COMREF object,	// 交易品种
		int period,		// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int Kperiod,         // K线周期 (用于计算的柱数)
		int Dperiod,         // D线周期 (开始平滑周期)
		int slowing,         // 最终平滑
		INDICATOR_MA_METHOD ma_method, // 平滑类型
		INDICATOR_STO_PRICE sto_price // 随机计算法
		);
#define iKDJ iStochastic

	//函数返回三倍指数移动平均指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iTEMA(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period,         // 平均周期
		int ma_shift,          // 指标平移
		INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器类型
		);

	//函数返回三倍指数移动平均数振荡指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iTriX(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int ma_period,         // 平均周期
		INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器类型
		);

	//函数返回威廉指数指标。只有一个缓冲区。
	XINDICATOR_API iHandle  iWPR(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int calc_period			// 平均周期
		);


	//函数返回变量指数动态平均数指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iVIDyA(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		int cmo_period,		// Chande 动量指标周期
		int ema_period,		// EMA 平滑周期
		int ma_shift,			// 价格图表平移
		INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器类型
		);

	//函数返回交易量指标处理器。只有一个缓冲区。
	XINDICATOR_API iHandle  iVolumes(
		COMREF object,		// 交易品种
		int period,			// 周期
		ENUM_DWTYPE dwtype,	// 除复权类型 
		unsigned long dwdate,// 定点除复权日期
		INDICATOR_APPLIED_PRICE applied_volume // 计算的交易量类型
		);

	//////////////////////////////////////////////////////////////////////////

	XINDICATOR_API int iObjectSelect(int offset, COMREF* object, int count, iHandle handle);

	XINDICATOR_API int iPoolSelect(int offset, COMREF* object, int count, iHandle handle);

	//////////////////////////////////////////////////////////////////////////
	///账户管理函数

	XINDICATOR_API int iUserSelectByObject(COMREF object, BOOL trade);

	XINDICATOR_API int iOrderSendA(COMREF object,int cmd, double volume,double price,int slippage, double stoploss, double takeprofit,
		LPCSTR comment,int magic,unsigned long date,unsigned long time);
	XINDICATOR_API int iOrderSendW(COMREF object,int cmd, double volume,double price,int slippage, double stoploss, double takeprofit,
		LPCWSTR comment,int magic,unsigned long date,unsigned long time);

	XINDICATOR_API COMREF iOrderObject();

//////////////////////////////////////////////////////////////////////////

//内建函数

//#if defined(__cplusplus)
//}

XINDICATOR_API int iIndicatorsTotal();
XINDICATOR_API int iIndicatorGet(int offset, wchar_t* str, int len, INDICATORCONTEXTINFO* ctx = NULL);

XINDICATOR_API voidptr iRefCalcData(COMREF object, int period, ENUM_DWTYPE dwtype = DW_FORWARD, unsigned long dwdate = 0, UINT uFlags = REF_CALCDATA_NONE);
XINDICATOR_API void iRefCalcDataMore(COMREF object, int period, ENUM_DWTYPE dwtype = DW_FORWARD, unsigned long dwdate = 0);
XINDICATOR_API void iReleaseCalcData(voidptr dataptr);

//XINDICATOR_API XIndicator* iRef(iHandle handle);
XINDICATOR_API voidptr iRefCalcData(iHandle handle);

XINDICATOR_API BAR* iRefBar(int offset, voidptr dataptr);

//#endif//

#endif//_H_XINDICATOREX_H_

