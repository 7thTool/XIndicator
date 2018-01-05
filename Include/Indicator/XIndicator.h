#ifndef _H_XINDICATOR_H_
#define _H_XINDICATOR_H_
/*
// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 XINDICATOR_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// XINDICATOR_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef XINDICATOR_EXPORTS
#define XINDICATOR_API __declspec(dllexport)
#else
#define XINDICATOR_API __declspec(dllimport)
#endif
#ifndef XINDICATOR_EXPORTS
#pragma comment(lib, "XIndicator.lib")
#endif//*/
/*
// 此类是从 Indicator.dll 导出的
class XINDICATOR_API CIndicator {
public:
	CIndicator(void);
	// TODO: 在此添加您的方法。
};

extern XINDICATOR_API int nIndicator;

XINDICATOR_API int fnIndicator(void);
*/
//////////////////////////////////////////////////////////////////////////

#include "XIndicatorDef.h"
#include "XIndicatorApi.h"

//////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif//

//////////////////////////////////////////////////////////////////////////

//内建函数

/*XINDICATOR_API void iLogA(INDICATOR_LOG_LEVEL level, const char* str);
XINDICATOR_API void iLogW(INDICATOR_LOG_LEVEL level, const wchar_t* str);
#ifndef UNICODE
#define iLog iLogA
#else
#define iLog iLogW
#endif//*/

//XINDICATOR_API int iIsEmptyValue(double value);
XINDICATOR_API int iIsEmptyStringA(const char* lpszStr);
XINDICATOR_API int iIsEmptyStringW(const wchar_t* lpszStr);
#ifndef UNICODE
#define iIsEmptyString iIsEmptyStringA
#else
#define iIsEmptyString iIsEmptyStringW
#endif//

XINDICATOR_API int iIsCrossBuffer(int offset, int count, double* src, double* dst);

XINDICATOR_API const char* iPriceType2StringA(int price, char* str, int len);
XINDICATOR_API const wchar_t* iPriceType2StringW(int price, wchar_t* str, int len);
XINDICATOR_API int iString2PriceTypeA(const char* str);
XINDICATOR_API int iString2PriceTypeW(const wchar_t* str);
#ifndef UNICODE
#define iPriceType2String iPriceType2StringA
#define iString2PriceType iString2PriceTypeA
#else
#define iPriceType2String iPriceType2StringW
#define iString2PriceType iString2PriceTypeW
#endif//

XINDICATOR_API const char* iPeriod2StringA(int iPeriod, char* str, int len);
XINDICATOR_API const wchar_t* iPeriod2StringW(int iPeriod, wchar_t* str, int len);
#ifndef UNICODE
#define iPeriod2String iPeriod2StringA
#else
#define iPeriod2String iPeriod2StringW
#endif//

XINDICATOR_API int iString2DrawlineA(const char* str);
XINDICATOR_API int iString2DrawlineW(const wchar_t* str);
XINDICATOR_API const char* iDrawline2StringA(char* str, int len, int Drawline);
XINDICATOR_API const wchar_t* iDrawline2StringW(wchar_t* str, int len, int Drawline);
#ifndef UNICODE
#define iString2Drawline iString2DrawlineA
#define iDrawline2String iDrawline2StringA
#else
#define iString2Drawline iString2DrawlineW
#define iDrawline2String iDrawline2StringW
#endif//

////辅助功能函数
//XINDICATOR_API void iString2RefvalueA(const char* str, REFVALUE* pRefvalue);
//XINDICATOR_API void iString2RefvalueW(const wchar_t* str, REFVALUE* pRefvalue);
//#ifndef UNICODE
//#define iString2Refvalue iString2RefvalueA
//#else
//#define iString2Refvalue iString2RefvalueW
//#endif//
//XINDICATOR_API void iRefvalue2Refvalue(const REFVALUE src, REFVALUE dst);
//
//XINDICATOR_API char* iFormatRefvalueA(REFVALUE refvalue, char* szBuf, int nBufLen, int nDecimalDigits, int nDivisor = 1);
//XINDICATOR_API wchar_t* iFormatRefvalueW(REFVALUE refvalue, wchar_t* szBuf, int nBufLen, int nDecimalDigits, int nDivisor = 1);
//XINDICATOR_API char* iFormatRefvalueExA(REFVALUE refvalue, char* szBuf, int nBufLen, char* szFormat, int nDivisor = 1);
//XINDICATOR_API wchar_t* iFormatRefvalueExW(REFVALUE refvalue, wchar_t* szBuf, int nBufLen, wchar_t* szFormat, INT nDivisor = 1);
//#ifndef UNICODE
//#define iFormatRefvalue iFormatRefvalueA
//#define iFormatRefvalueEx iFormatRefvalueExA
//#else
//#define iFormatRefvalue iFormatRefvalueW
//#define iFormatRefvalueEx iFormatRefvalueExA
//#endif//

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//C/C++接口提供的位置还是数组索引顺序
//脚本接口提供的是引用位置，即数组相反，当前交易周期为0，前一交易周期为1，以此类推
//可以用iReverseOffset来互相转换
//

//XINDICATOR_API voidptr iRefData(const char* symbol, int period);
//XINDICATOR_API voidptr iRefFieldData(const char* symbol);
//XINDICATOR_API voidptr iRefDataEx(const char* symbol, int period, unsigned long flags);
XINDICATOR_API void iReqData(const char* symbol, int period);
//XINDICATOR_API void iReleaseData(voidptr dataptr);

//XINDICATOR_API const char* iSymbol(voidptr dataptr);
//XINDICATOR_API int iPeriod(voidptr dataptr);
//XINDICATOR_API int iDigits(voidptr dataptr);
XINDICATOR_API int iDWType(voidptr dataptr);
XINDICATOR_API int iDWDate(voidptr dataptr);

//XINDICATOR_API int iDataCount(voidptr dataptr);

//XINDICATOR_API unsigned int iDate(int offset, voidptr dataptr);
//XINDICATOR_API unsigned int iTime(int offset, voidptr dataptr);
//XINDICATOR_API double iOpen(int offset, voidptr dataptr);
//XINDICATOR_API double iHigh(int offset, voidptr dataptr);
//XINDICATOR_API double iLow(int offset, voidptr dataptr);
//XINDICATOR_API double iClose(int offset, voidptr dataptr);
//XINDICATOR_API double iVolume(int offset, voidptr dataptr);
//XINDICATOR_API double iAmount(int offset, voidptr dataptr);

//XINDICATOR_API double iField(INDICATOR_FIELD field, voidptr dataptr);

//XINDICATOR_API double iPrice(INDICATOR_APPLIED_PRICE price, int offset, voidptr dataptr);
XINDICATOR_API double iMaxPrice(INDICATOR_APPLIED_PRICE price, int offset, int period, voidptr dataptr);
XINDICATOR_API double iMinPrice(INDICATOR_APPLIED_PRICE price, int offset, int period, voidptr dataptr);
XINDICATOR_API double iSumPrice(INDICATOR_APPLIED_PRICE price, int offset, int period, voidptr dataptr);

XINDICATOR_API double iMaxBuffer(double* buffer, int offset, int period, int count);
XINDICATOR_API double iMinBuffer(double* buffer, int offset, int period, int count);
XINDICATOR_API double iSumBuffer(double* buffer, int offset, int period, int count);

//////////////////////////////////////////////////////////////////////////
//一下buffer必须和Index一样大小

//均值
XINDICATOR_API long iMABuffer(double* buffer, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price, int start, int count, voidptr dataptr);
XINDICATOR_API long iMABufferOnBuffer(double* buffer, int period, INDICATOR_MA_METHOD method, int start, int count, double* srcbuffer);
//协方差
//XINDICATOR_API long iCOVBuffer(double* buffer, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price, int start, int count, voidptr xdataptr, voidptr ydataptr);
//方差
XINDICATOR_API long iS2Buffer(double* buffer, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price, int start, int count, voidptr dataptr);
XINDICATOR_API long iS2BufferOnBuffer(double* buffer, int period, INDICATOR_MA_METHOD method, int start, int count, double* srcbuffer);
//标准差
XINDICATOR_API long iStdDevBuffer(double* buffer, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price, int start, int count, voidptr dataptr);
XINDICATOR_API long iStdDevBufferOnBuffer(double* buffer, int period, INDICATOR_MA_METHOD method, int start, int count, double* srcbuffer);

//////////////////////////////////////////////////////////////////////////

/*//引用指标
XINDICATOR_API iHandle iRefA(const char* symbol, int period, const char* name, const char* xml, int xmlflag);
XINDICATOR_API iHandle iRefW(const char* symbol, int period, const wchar_t* name, const wchar_t* xml, int xmlflag);
XINDICATOR_API iHandle iRefPoolA(const char* name, const char* xml, int xmlflag);
XINDICATOR_API iHandle iRefPoolW(const wchar_t* name, const wchar_t* xml, int xmlflag);
#ifndef UNICODE
#define iRef iRefA
#define iRefPool iRefPoolA
#else
#define iRef iRefW
#define iRefPool iRefPoolW
#endif//
//XINDICATOR_API iHandle iCalc(voidptr dataptr, const char* name, const char* xml, int xmlflag);
//XINDICATOR_API iHandle iScript(const char* symbol, int period, const char* name, const char* xml, int xmlflag, const char* scripts, const char* language);
//XINDICATOR_API iHandle iScriptCalc(voidptr dataptr, const char* name, const char* xml, int xmlflag, const char* scripts, const char* language);

XINDICATOR_API void iRelease(iHandle h);
*/
//XINDICATOR_API long iSetName(LPCTSTR name, iHandle handle);
XINDICATOR_API long iSetType(long type, iHandle handle);
XINDICATOR_API long iSetStyle(long style, iHandle handle);
XINDICATOR_API long iSetInputA(const char* name, const char* value, iHandle handle);
XINDICATOR_API long iSetInputW(const wchar_t* name, const wchar_t* value, iHandle handle);
XINDICATOR_API long iSetInputValueA(const char* name, double value, iHandle handle);
XINDICATOR_API long iSetInputValueW(const wchar_t* name, double value, iHandle handle);
#ifndef UNICODE
#define iSetInput iSetInputA
#define iSetInputValue iSetInputValueA
#else
#define iSetInput iSetInputW
#define iSetInputValue iSetInputValueW
#endif//
XINDICATOR_API long iSetShift(long value, iHandle handle);
//XINDICATOR_API long iSetIndexCount(int value, iHandle handle);
XINDICATOR_API long iSetIndexNameA(int index, const char* value, iHandle handle);
XINDICATOR_API long iSetIndexNameW(int index, const wchar_t* value, iHandle handle);
#ifndef UNICODE
#define iSetIndexName iSetIndexNameA
#else
#define iSetIndexName iSetIndexNameW
#endif//
XINDICATOR_API long iSetIndexType(int index, long value, iHandle handle);
XINDICATOR_API long iSetIndexDigits(int index, long value, iHandle handle);
XINDICATOR_API long iSetIndexShift(int index, long value, iHandle handle);
XINDICATOR_API long iSetIndexBegin(int index, long value, iHandle handle);
XINDICATOR_API long iSetIndexDraw(int index, long value, iHandle handle);
XINDICATOR_API long iSetIndexLine(int index, long value, iHandle handle);
XINDICATOR_API long iSetIndexNext(int index, long value, iHandle handle);
XINDICATOR_API long iSetIndexWidth(int index, long width, iHandle handle);
XINDICATOR_API long iSetIndexColor(int index, long color, iHandle handle);
//XINDICATOR_API long iSetIndexAttribute(int index, LPCTSTR attr, LPCTSTR value, iHandle handle);
//XINDICATOR_API long iSetIndexAttributeValue(int index, LPCTSTR attr, double value, iHandle handle);
XINDICATOR_API long iSetIndexValue(int index, int offset, double value, iHandle handle);

XINDICATOR_API void iAddPool(const char* symbol, iHandle handle);
XINDICATOR_API void iRemovePool(const char* symbol, iHandle handle);
/*
//XINDICATOR_API LPCTSTR iGetName(iHandle handle);
XINDICATOR_API long iGetType(iHandle handle);
XINDICATOR_API long iGetStyle(iHandle handle);
XINDICATOR_API const char* iGetInputA(const char* name, char* str, int len, iHandle handle);
XINDICATOR_API const wchar_t* iGetInputW(const wchar_t* name, wchar_t* str, int len, iHandle handle);
XINDICATOR_API double iGetInputValueA(const char* name, iHandle handle);
XINDICATOR_API double iGetInputValueW(const wchar_t* name, iHandle handle);
#ifndef UNICODE
#define iGetInput iGetInputA
#define iGetInputValue iGetInputValueA
#else
#define iGetInput iGetInputW
#define iGetInputValue iGetInputValueW
#endif//
XINDICATOR_API long iGetIndexCount(iHandle handle);
XINDICATOR_API const char* iGetIndexNameA(int index, char* str, int len, iHandle handle);
XINDICATOR_API const wchar_t* iGetIndexNameW(int index, wchar_t* str, int len, iHandle handle);
#ifndef UNICODE
#define iGetIndexName iGetIndexNameA
#else
#define iGetIndexName iGetIndexNameW
#endif//
XINDICATOR_API long iGetIndexStyle(int index, iHandle handle);
XINDICATOR_API long iGetIndexDigits(int index, iHandle handle);
XINDICATOR_API long iGetIndexShift(int index, iHandle handle);
XINDICATOR_API long iGetIndexDrawBegin(int index, iHandle handle);
XINDICATOR_API long iGetIndexDraw(int index, iHandle handle);
XINDICATOR_API long iGetIndexLine(int index, iHandle handle);
XINDICATOR_API long iGetIndexNext(int index, iHandle handle);
XINDICATOR_API long iGetIndexWidth(int index, iHandle handle);
XINDICATOR_API COLORREF iGetIndexColor(int index, iHandle handle);
//XINDICATOR_API double iGetIndexAttribute(int index, LPCTSTR attr, iHandle handle);
//XINDICATOR_API double iGetIndexAttributeValue(int index, LPCTSTR attr, iHandle handle);
XINDICATOR_API long iGetPriceCount(iHandle handle);
XINDICATOR_API unsigned long iGetPriceDate(int offset, iHandle handle);
XINDICATOR_API unsigned long iGetPriceTime(int offset, iHandle handle);
XINDICATOR_API double iGetIndexValue(int index, int offset, iHandle handle);
XINDICATOR_API double iGetLineValue(int line , int offset, iHandle handle);
XINDICATOR_API double iGetPriceValue(int price, int offset, iHandle handle);
#define iGetVolumeValue(offset,handle) iGetPriceValue(PRICE_VOLUME,offset,handle)
#define iGetAmountValue(offset,handle) iGetPriceValue(PRICE_AMOUNT,offset,handle)
XINDICATOR_API double iGetFieldValue(INDICATOR_FIELD field, iHandle handle);
XINDICATOR_API long iGetMmxOffset(int index, int mmx, iHandle handle);
XINDICATOR_API double iGetMmxValue(int index, int mmx, iHandle handle);*/

XINDICATOR_API voidptr iGetData(iHandle handle);
/*
XINDICATOR_API int iPoolsTotal(iHandle handle);
XINDICATOR_API int iPoolSelect(int offset, char* str, int len, iHandle handle);

XINDICATOR_API int iIsTrade(iHandle handle);
XINDICATOR_API int iIsTradeable(iHandle handle);
XINDICATOR_API int iIsCalculate(iHandle handle);
*/
//内建指标计算函数
//
//buffer大小必须和K线数量、Index大小一样
XINDICATOR_API int iMABufferOnPrice(double* buffer, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price, int offset, int count, iHandle handle);
XINDICATOR_API int iMABufferOnIndex(double* buffer, int period, INDICATOR_MA_METHOD method, int index, int offset, int count, iHandle handle);
//
XINDICATOR_API int iMAIndexOnPrice(int index, int period, INDICATOR_MA_METHOD method, INDICATOR_APPLIED_PRICE price, iHandle handle);
XINDICATOR_API int iMAIndexOnLine(int index, int period, INDICATOR_MA_METHOD method, int line, iHandle handle);

/*//指标辅助函数
//
XINDICATOR_API int iReverseOffset(int offset, iHandle handle);
XINDICATOR_API int iCross(int src, int dst, int offset, iHandle handle);
*/
//内建指标
//返回值
//返回特殊技术指标处理器，失败返回 INVALID_HANDLE。
/*
//加速振荡指标并返回处理器，只有一个缓冲区。
XINDICATOR_API iHandle  iAC(
					   const char* symbol,		// 交易品种
					   int period,			// 周期
					   );

//函数返回累积/分配指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iAD(
					   const char* symbol,		// 交易品种
					   int period,			// 周期
					   INDICATOR_APPLIED_PRICE applied_volume	// 用于计算的交易量类型
					   );

//函数返回平均定向移动指数指标处理器。
XINDICATOR_API iHandle  iADX(
						const char* symbol,		// 交易品种
						int period,			// 周期
						int	adx_period		// 平均周期
						);

//函数返回韦尔达平均定向移动指数处理器。
XINDICATOR_API iHandle  iADXWilder(
							  const char* symbol,		// 交易品种
							  int period,			// 周期
							  int adx_period		// 平均周期
							  );

//函数返回鳄鱼指标处理器。
XINDICATOR_API iHandle  iAlligator(
							  const char* symbol,		// 交易品种
							  int period,			// 周期
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
						const char* symbol,		// 交易品种
						int period,			// 周期
						int ama_period,		//  AMA平均周期
						int fast_ma_period,	// 快速 MA 周期
						int slow_ma_period,	// 慢速 MA 周期
						int ama_shift,		// 指标平移
						INDICATOR_APPLIED_PRICE applied_price	// 价格或者处理器类型
						);

//函数返回动量震荡指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iAO(
					   const char* symbol,		// 交易品种
					   int period,			// 周期
					   );

//函数返回平均真实区域指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iATR(
						const char* symbol,		// 交易品种
						int period,			// 周期
						int ma_period	// 平均周期 
						);

//函数返回熊市指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iBearsPower(
							   const char* symbol,		// 交易品种
							   int period,			// 周期
							   int ma_period	// 平均周期
							   );

//函数返回布林带指标处理器。
XINDICATOR_API iHandle  iBands(
						  const char* symbol,		// 交易品种
						  int period,			// 周期
						  int bands_period,		// 平均线计算周期
						  int bands_shift,		// 指标平移
						  double deviation,		// 标准差数
						  INDICATOR_APPLIED_PRICE applied_price	// 价格或处理器类型
						  );

//函数返回牛市指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iBullsPower(
							   const char* symbol,		// 交易品种
							   int period,			// 周期
							   int ma_period	// 平均周期
							   );

//函数返回顺势指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iCCI(
						const char* symbol,		// 交易品种
						int period,			// 周期
						int ma_period,			// 平均周期
						INDICATOR_APPLIED_PRICE applied_price	// 价格或处理器类型
						);

//The function returns the handle of the Chaikin Oscillator indicator. It has only one buffer.
XINDICATOR_API iHandle  iChaikin(
							const char* symbol,		// 交易品种
							int period,			// 周期
							int fast_ma_period,	// 快速周期
							int slow_ma_period,	// 慢速周期
							INDICATOR_MA_METHOD ma_method,	// 平滑类型
							INDICATOR_APPLIED_PRICE applied_volume	// 交易量类型
							);

//函数返回双指数移动平均线指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iDEMA(
						 const char* symbol,		// 交易品种
						 int period,			// 周期
						 int ma_period,         // 平均周期
						 int ma_shift,          // 平移
						 INDICATOR_APPLIED_PRICE applied_price	// 价格或者处理器类型
						 );

//函数返回DeMarker指标处理器。只有一个缓冲区。 
XINDICATOR_API iHandle  iDeMarker(
							 const char* symbol,		// 交易品种
							 int period,			// 周期
							 int ma_period		// 平均周期
							 );

//函数返回轨道线指标处理器。
XINDICATOR_API iHandle  iEnvelopes(
							  const char* symbol,		// 交易品种
							  int period,			// 周期
							  int ma_period,	// 平均线计算周期
							  int ma_shift,		// 指标平移
							  INDICATOR_MA_METHOD ma_method,	// 平滑类型
							  INDICATOR_APPLIED_PRICE applied_price,	// 价格或者处理器类型
							  double deviation	// 中线边界差(百分率)
							  );

//函数返回强力指数指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iForce(
						  const char* symbol,		// 交易品种
						  int period,			// 周期
						  int ma_period,		// 平均周期
						  INDICATOR_MA_METHOD ma_method,	// 平滑类型
						  INDICATOR_APPLIED_PRICE applied_volume	// 计算的交易量类型
						  );

//函数返回分形学指标处理器。
XINDICATOR_API iHandle  iFractals(
							 const char* symbol,		// 交易品种
							 int period,			// 周期
							 );

//函数返回分形学适合移动平均指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iFrAMA(
						  const char* symbol,		// 交易品种
						  int period,			// 周期
						  int ma_period,		// 平均周期
						  int ma_shift,			// 图表平移
						  INDICATOR_APPLIED_PRICE applied_price	// 价格或者处理器类型
						  );

//函数返回鳄鱼振荡器指标处理器。振荡器表示鳄鱼指标蓝线和红线（上升柱状图）的区别以及红线和绿线的区别（下降柱状图）。
XINDICATOR_API iHandle  iGator(
						  const char* symbol,		// 交易品种
						  int period,			// 周期
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
							 const char* symbol,		// 交易品种
							 int period,			// 周期
							 int tenkan_sen,	// Tenkan-sen转换线周期
							 int kijun_sen,		// Kijun-sen基准线周期
							 int senkou_span_b	// Senkou Span B周期
							 );

//函数返回市场便利指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iBWMFI(
						  const char* symbol,		// 交易品种
						  int period,			// 周期
						  INDICATOR_APPLIED_PRICE applied_volume	// 计算的交易量类型
						  );

//函数返回动量指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iMomentum(
							 const char* symbol,		// 交易品种
							 int period,			// 周期
							 int mom_period,	// 平均周期
							 INDICATOR_APPLIED_PRICE applied_price	// 价格或者处理器类型
							 );

//函数返回资金流向指标处理器。
XINDICATOR_API iHandle  iMFI(
						const char* symbol,		// 交易品种
						int period,			// 周期
						int ma_period,			// 平均周期
						INDICATOR_APPLIED_PRICE applied_volume	// 计算的交易量类型
						);

//函数返回移动平均数指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iMA(
					   const char* symbol,			// 交易品种
					   int period,				// 周期
					   int ma_period,			// 平均周期
					   int ma_shift,			// 平移
					   INDICATOR_MA_METHOD ma_method, // 平滑类型
					   INDICATOR_APPLIED_PRICE applied_price // 价格或者处理程序类型
					   );

//函数返回移动平均震荡指标处理器。OsMA振荡器显示MACD与其讯息线之间的区别。只有一个缓冲区。
XINDICATOR_API iHandle  iOsMA(
						 const char* symbol,		// 交易品种
						 int period,			// 周期
						 int fast_ema_period,	// 快速移动平均数周期
						 int slow_ema_period,	// 慢速移动平均数周期
						 int signal_period,		// 不同点的平均周期
						 INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器的类型
						 );

//函数返回移动平均数聚/散指标处理器。在OsMA被称为MACD柱状图的系统中，该指标显示为两条线。在客户端移动平均数聚/散像柱状图。
XINDICATOR_API iHandle  iMACD(
						 const char* symbol,		// 交易品种
						 int period,			// 周期
						 int fast_ema_period,	// 快速移动平均数周期
						 int slow_ema_period,	// 慢速移动平均数周期
						 int signal_period,		// 不同点的平均周期
						 INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器的类型
						 );

//函数返回平衡交易量指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iOBV(
						const char* symbol,		// 交易品种
						int period,			// 周期
						INDICATOR_APPLIED_PRICE applied_volume // 计算的交易量类型
						);

//函数返回抛物转向系统指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iSAR(
						const char* symbol,		// 交易品种
						int period,			// 周期
						double step,			// 逐步增加
						double maximum			// 最大止损水平
						);

//函数返回相对强度指数指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iRSI(
						const char* symbol,		// 交易品种
						int period,			// 周期
						int ma_period,			// 平均周期
						INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器类型
						);

//函数返回相对活力指数指标处理器。
XINDICATOR_API iHandle  iRVI(
						const char* symbol,		// 交易品种
						int period,			// 周期
						int ma_period			// 平均周期
						);

//函数返回标准偏差指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iStdDev(
						   const char* symbol,		// 交易品种
						   int period,			// 周期
						   int ma_period,		// 平均周期
						   int ma_shift,		// 平移
						   INDICATOR_MA_METHOD ma_method, // 平滑类型
						   INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器类型
						   );

//函数返回随机摆动指标处理器。
XINDICATOR_API iHandle  iStochastic(
							   const char* symbol,	// 交易品种
							   int period,		// 周期
							   int Kperiod,         // K线周期 (用于计算的柱数)
							   int Dperiod,         // D线周期 (开始平滑周期)
							   int slowing,         // 最终平滑
							   INDICATOR_MA_METHOD ma_method, // 平滑类型
							   INDICATOR_STO_PRICE sto_price // 随机计算法
							   );
#define iKDJ iStochastic

//函数返回三倍指数移动平均指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iTEMA(
						 const char* symbol,		// 交易品种
						 int period,			// 周期
						 int ma_period,         // 平均周期
						 int ma_shift,          // 指标平移
						 INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器类型
						 );

//函数返回三倍指数移动平均数振荡指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iTriX(
						 const char* symbol,		// 交易品种
						 int period,			// 周期
						 int ma_period,         // 平均周期
						 INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器类型
						 );

//函数返回威廉指数指标。只有一个缓冲区。
XINDICATOR_API iHandle  iWPR(
						const char* symbol,		// 交易品种
						int period,			// 周期
						int calc_period			// 平均周期
						);


//函数返回变量指数动态平均数指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iVIDyA(
						  const char* symbol,		// 交易品种
						  int period,			// 周期
						  int cmo_period,		// Chande 动量指标周期
						  int ema_period,		// EMA 平滑周期
						  int ma_shift,			// 价格图表平移
						  INDICATOR_APPLIED_PRICE applied_price // 价格或者处理器类型
						  );

//函数返回交易量指标处理器。只有一个缓冲区。
XINDICATOR_API iHandle  iVolumes(
							const char* symbol,		// 交易品种
							int period,			// 周期
							INDICATOR_APPLIED_PRICE applied_volume // 计算的交易量类型
							);
*/

/*//////////////////////////////////////////////////////////////////////////
//品种函数

XINDICATOR_API int iObjectsFindA(const char* key, unsigned long flags, iHandle handle);
XINDICATOR_API int iObjectsFindW(const wchar_t* key, unsigned long flags, iHandle handle);
#ifdef UNICODE
#define iObjectsFind iObjectsFindW
#else
#define iObjectsFind iObjectsFindA
#endif//
XINDICATOR_API int iObjectsTotalA(const char* market, iHandle handle);
XINDICATOR_API int iObjectsTotalW(const wchar_t* market, iHandle handle);
#ifdef UNICODE
#define iObjectsTotal iObjectsTotalW
#else
#define iObjectsTotal iObjectsTotalA
#endif//
XINDICATOR_API int iObjectSelect(int offset, char* str, int len, iHandle handle);
*/

/*//////////////////////////////////////////////////////////////////////////
///账户管理函数

XINDICATOR_API int iUsersTotal();
XINDICATOR_API int iUserSelectByIndex(int index);
XINDICATOR_API int iUserSelectByNameA(const char* name);
XINDICATOR_API int iUserSelectByNameW(const wchar_t* name);
#ifdef UNICODE
#define iUserSelectByName iUserSelectByNameW
#else
#define iUserSelectByName iUserSelectByNameA
#endif//
XINDICATOR_API int iUserSelectBySymbol(const char* symbol);
XINDICATOR_API double iUserFieldValueA(const char* field);
XINDICATOR_API double iUserFieldValueW(const wchar_t* field);
XINDICATOR_API const char* iUserFieldStringA(const char* field, char* str, int len);
XINDICATOR_API const wchar_t* iUserFieldStringW(const wchar_t* field, wchar_t* str, int len);
#ifdef UNICODE
#define iUserFieldValue iUserFieldValueW
#define iUserFieldString iUserFieldStringW
#else
#define iUserFielValued iUserFieldValueA
#define iUserFieldString iUserFieldStringA
#endif//
XINDICATOR_API const char* iUserAccountA(char* str, int len);
XINDICATOR_API const wchar_t* iUserAccountW(wchar_t* str, int len);
XINDICATOR_API const char* iUserMoneySymbolA(char* str, int len);
XINDICATOR_API const wchar_t* iUserMoneySymbolW(wchar_t* str, int len);
#ifdef UNICODE
#define iUserAccount iUserAccountA
#define iUserMoneySymbol iUserMoneySymbolA
#else
#define iUserAccount iUserAccountW
#define iUserMoneySymbol iUserMoneySymbolW
#endif//
XINDICATOR_API double iUserMoneyTotal();
XINDICATOR_API double iUserMoneyAvailable();
XINDICATOR_API double iUserMoneyFreeze();
XINDICATOR_API double iUserMoneyFree();
XINDICATOR_API double iUserMoneyIn();
XINDICATOR_API double iUserMoneyOut();*/

/*//////////////////////////////////////////////////////////////////////////
///交易函数

enum
{
	OP_NONE			= 0,
	OP_BUY			= 1,	//Buy operation
	OP_SELL			= 2,	//Sell operation
	OP_BUYLIMIT		= 3,	//Buy limit pending order
	OP_SELLLIMIT	= 4,	//Sell limit pending order
	OP_BUYSTOP		= 5,	//Buy stop pending order
	OP_SELLSTOP		= 6,	//Sell stop pending order
};
*/
XINDICATOR_API const char* iOrderCmd2StringA(int cmd, char* str, int len);
XINDICATOR_API const wchar_t* iOrderCmd2StringW(int cmd, wchar_t* str, int len);
#ifdef UNICODE
#define iOrderCmd2String iOrderCmd2StringW
#else
#define iOrderCmd2String iOrderCmd2StringA
#endif//
/*
XINDICATOR_API int iOrderSendA(const char* symbol,int cmd, double volume,double price,int slippage, double stoploss, double takeprofit,
							   const char* comment,int magic,unsigned long date,unsigned long time);
XINDICATOR_API int iOrderSendW(const char* symbol,int cmd, double volume,double price,int slippage, double stoploss, double takeprofit,
							   const wchar_t* comment,int magic,unsigned long date,unsigned long time);
//XINDICATOR_API int OrderBuy();
//XINDICATOR_API int OrderSell();
//XINDICATOR_API int OrderBuyShort();
//XINDICATOR_API int OrderSellShort();
#ifdef UNICODE
#define iOrderSend iOrderSendW
#else
#define iOrderSend iOrderSendA
#endif//

enum 
{
	MODE_NONE = 0,
	MODE_ORDERS,
	MODE_HISTORY_ORDERS,
	MODE_TRADES,
	MODE_HISTORY_TRADES,
	MODE_POSITION,
};

XINDICATOR_API int iOrdersSelect(int pool);
XINDICATOR_API int iOrdersTotal();
XINDICATOR_API int iOrderSelectByIndex(int index);
XINDICATOR_API int iOrderSelectByTicketA(const char* ticket);
XINDICATOR_API int iOrderSelectByTicketW(const wchar_t* ticket);
#ifdef UNICODE
#define iOrderSelectByTicket iOrderSelectByTicketW
#else
#define iOrderSelectByTicket iOrderSelectByTicketA
#endif//
XINDICATOR_API int iOrderSelectByMagic(int magic);

XINDICATOR_API int iOrderType();
XINDICATOR_API const char* iOrderTicket();

XINDICATOR_API int iOrderClose(double lots, double price, int slippage);
XINDICATOR_API int iOrderCloseBy(int opposite);
XINDICATOR_API int iOrderDelete();
XINDICATOR_API int iOrderModify(double price,double stoploss,double takeprofit,unsigned long expiration);

XINDICATOR_API const char* iOrderSymbol();

XINDICATOR_API double iOrderOpenPrice();
XINDICATOR_API double iOrderClosePrice();

XINDICATOR_API unsigned long iOrderOpenTime(unsigned long* date);
XINDICATOR_API unsigned long iOrderCloseTime(unsigned long* date);
XINDICATOR_API unsigned long iOrderExpiration(unsigned long* date);

XINDICATOR_API double iOrderLots();
XINDICATOR_API double iOrderProfit();
XINDICATOR_API double iOrderTakeProfit();
XINDICATOR_API double iOrderStopLoss();
XINDICATOR_API double iOrderCommission();
XINDICATOR_API int iOrderMagicNumber();
XINDICATOR_API const char* iOrderComment();

XINDICATOR_API const char* iOrderFieldString(const char* field, char* str, int len);*/

#if defined(__cplusplus)
}

//

#endif//

#endif//_H_XINDICATOR_H_

