#ifndef _H_BASE_H_
#define _H_BASE_H_

// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 BASE_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// BASE_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef BASE_EXPORTS
#define BASE_API __declspec(dllexport)
#else
#define BASE_API __declspec(dllimport)
#endif

#ifndef BASE_EXPORTS
#pragma comment(lib, "Base.lib")
#endif//

// 此类是从 Base.dll 导出的
class BASE_API CBase {
public:
	CBase(void);
	// TODO: 在此添加您的方法。
};

extern BASE_API int nBase;

BASE_API int fnBase(void);

//////////////////////////////////////////////////////////////////////////
///非界面的数据处理库

#include <DataStd.h>
#include <FieldDef.h>
#include <XLib/XTime.h>

BASE_API int GetDecimalDigits(double v); //取浮点数小数位数

BASE_API unsigned char Exchange2IdA(const char* szExchange);
BASE_API unsigned char Exchange2IdW(const wchar_t* szExchange);
BASE_API const char* Id2ExchangeA(const unsigned char Id);
BASE_API const wchar_t* Id2ExchangeW(const unsigned char Id);
#ifndef UNICODE
#define Exchange2Id	Exchange2IdA
#define Id2Exchange	Id2ExchangeA
#else
#define Exchange2Id	Exchange2IdW
#define Id2Exchange	Id2ExchangeW
#endif//

struct BASE_API KINDLess
{
	bool operator()(const KIND& x, const KIND& y) const;
};

struct BASE_API KINDEqual
{
	bool operator()(const KIND& x, const KIND& y) const;
};

BASE_API bool operator == (const KIND & x, const KIND & y);
BASE_API bool operator != (const KIND & x, const KIND & y);
BASE_API bool operator < (const KIND & x, const KIND & y);
BASE_API bool operator > (const KIND & x, const KIND & y);
BASE_API int KINDCmp (const KIND* pX, const KIND * pY);

BASE_API bool IsCommodityNormalize(COMREF Commodity);

struct BASE_API COMREFLess
{
	bool operator()(const COMREF& x, const COMREF& y) const;
};

struct BASE_API COMREFEqual
{
	bool operator()(const COMREF& x, const COMREF& y) const;
};

BASE_API bool operator == (const COMREF & x, const COMREF & y);
BASE_API bool operator != (const COMREF & x, const COMREF & y);
BASE_API bool operator < (const COMREF & x, const COMREF & y);
BASE_API bool operator > (const COMREF & x, const COMREF & y);
BASE_API int COMREFCmp (const COMREF* pX, const COMREF * pY);

enum
{
	STOCK_GROUP_STOCK = 1,
	STOCK_GROUP_INDEX,
	STOCK_GROUP_FUND,
	STOCK_GROUP_BOUND,
	STOCK_GROUP_OPTION,
};

BASE_API int StockGroup(unsigned char Group);
BASE_API int StockGroup(const COMREF& Comodity);
#define IsStockGroupStock(g)	((g)==STOCK_GROUP_STOCK)
#define IsStockGroupIndex(g)	((g)==STOCK_GROUP_INDEX)
#define IsStockGroupFund(g)		((g)==STOCK_GROUP_FUND)
#define IsStockGroupBound(g)	((g)==STOCK_GROUP_BOUND)
#define IsStockGroupOption(g)	((g)==STOCK_GROUP_OPTION)
#define IsStockStock(x)			(StockGroup(x)==STOCK_GROUP_STOCK)
#define IsStockIndex(x)			(StockGroup(x)==STOCK_GROUP_INDEX)
#define IsStockFund(x)			(StockGroup(x)==STOCK_GROUP_FUND)
#define IsStockBound(x)			(StockGroup(x)==STOCK_GROUP_BOUND)
#define IsStockOption(x)		(StockGroup(x)==STOCK_GROUP_OPTION)

#define STOCKGROUP_STOCKA	"Stock"
#define STOCKGROUP_INDEXA	"Index"
#define STOCKGROUP_FUNDA	"Fund"
#define STOCKGROUP_BOUNDA	"Bound"
#define STOCKGROUP_OPTIONA	"Option"

#define STOCKGROUP_STOCKW	L"Stock"
#define STOCKGROUP_INDEXW	L"Index"
#define STOCKGROUP_FUNDW	L"Fund"
#define STOCKGROUP_BOUNDW	L"Bound"
#define STOCKGROUP_OPTIONW	L"Option"

BASE_API LPCSTR StockGroup2StrA(unsigned char Group);
BASE_API LPCWSTR StockGroup2StrW(unsigned char Group);
#ifndef UNICODE
#define StockGroup2Str	StockGroup2StrA
#else
#define StockGroup2Str	StockGroup2StrW
#endif//

BASE_API LPSTR Period2StringA(LPSTR lpszStr, int nStrLen, ENUM_TIMEFRAMES Period, int PeriodEx, int nLanguage = LANG_NEUTRAL);
BASE_API LPWSTR Period2StringW(LPWSTR lpszStr, int nStrLen, ENUM_TIMEFRAMES Period, int PeriodEx, int nLanguage = LANG_NEUTRAL);
#ifndef UNICODE
#define Period2String	Period2StringA
#else
#define Period2String	Period2StringW
#endif//

BASE_API LPTSTR DWType2String(LPTSTR lpszStr, ENUM_DWTYPE DWType, int nLanguage = LANG_NEUTRAL);

//格式化
BASE_API LPCSTR Number2StringA(LPSTR lpszString, int nNumber, int nLanguage = LANG_NEUTRAL);
BASE_API LPCWSTR Number2StringW(LPWSTR lpszString, int nNumber, int nLanguage = LANG_NEUTRAL);
BASE_API LPCSTR WeekDay2StringA(LPSTR lpszString, int nWeekDay, int nLanguage = LANG_NEUTRAL);
BASE_API LPCWSTR WeekDay2StringW(LPWSTR lpszString, int nWeekDay, int nLanguage = LANG_NEUTRAL);
#ifndef UNICODE
#define Number2String	Number2StringA
#define WeekDay2String	WeekDay2StringA
#else
#define Number2String	Number2StringW
#define WeekDay2String	WeekDay2StringW
#endif//

BASE_API LPCSTR FormatFloatStringA(LPSTR lpszString, double dValue, int nDecimalDigits, int nDivisor = 1, int nLanguage = LANG_NEUTRAL);
BASE_API LPCWSTR FormatFloatStringW(LPWSTR lpszString, double dValue, int nDecimalDigits, int nDivisor = 1, int nLanguage = LANG_NEUTRAL);
BASE_API LPCSTR FormatAmountStringA(LPSTR lpszString, double dAmount, int nDecimalDigits, int nDivisor = 1, int nLanguage = LANG_NEUTRAL);
BASE_API LPCWSTR FormatAmountStringW(LPWSTR lpszString, double dAmount, int nDecimalDigits, int nDivisor = 1, int nLanguage = LANG_NEUTRAL);
BASE_API LPCSTR FormatVolumeStringA(LPSTR lpszString, double dAmount, int nDecimalDigits, int nDivisor = 1, int nLanguage = LANG_NEUTRAL);
BASE_API LPCWSTR FormatVolumeStringW(LPWSTR lpszString, double dAmount, int nDecimalDigits, int nDivisor = 1, int nLanguage = LANG_NEUTRAL);
#ifndef UNICODE
#define FormatFloatString	FormatFloatStringA
#define FormatAmountString	FormatAmountStringA
#define FormatVolumeString	FormatVolumeStringA
#else
#define FormatFloatString	FormatFloatStringW
#define FormatAmountString	FormatAmountStringW
#define FormatVolumeString	FormatVolumeStringW
#endif//

#define INVALID_FIELD_STRINGA	"----"
#define INVALID_FIELD_STRINGW	L"----"
#ifndef UNICODE
#define INVALID_FIELD_STRING	INVALID_FIELD_STRINGA
#else
#define INVALID_FIELD_STRING	INVALID_FIELD_STRINGW
#endif//

BASE_API LPCSTR InitFieldNameA(FIELD_NAME& FieldValue, int nLanguage = LANG_NEUTRAL);
BASE_API LPCWSTR InitFieldNameW(FIELD_NAME& FieldValue, int nLanguage = LANG_NEUTRAL);
BASE_API LPCSTR FieldName2StringA(FIELD_NAME& FieldValue, LPCSTR lpszDefault = INVALID_FIELD_STRINGA);
BASE_API LPCWSTR FieldName2StringW(FIELD_NAME& FieldValue, LPCWSTR lpszDefault = INVALID_FIELD_STRINGW);
#ifndef UNICODE
#define InitFieldName		InitFieldNameA
#define FieldName2String	FieldName2StringA
#else
#define InitFieldName		InitFieldNameW
#define FieldName2String	FieldName2StringW
#endif//

BASE_API long SetFieldText(FIELD_VALUE& FieldValue, LPCSTR lpszText);
BASE_API long SetFieldText(FIELD_VALUE& FieldValue, LPCWSTR lpszText);
BASE_API long FormatFieldText(FIELD_VALUE& FieldValue, int nDecimalDigits, int nDivisor = 1);
BASE_API long FormatFieldText(FIELD_VALUE& FieldValue, LPCSTR lpszFormat, int nDivisor = 1);
BASE_API long FormatFieldText(FIELD_VALUE& FieldValue, LPCWSTR lpszFormat, int nDivisor = 1);
BASE_API long FormatFieldTextWithUnit(FIELD_VALUE& FieldValue, int nLanguage = LANG_NEUTRAL);
BASE_API LPCSTR FormatFieldStringA(FIELD_VALUE& FieldValue, LPSTR lpszString, int nDecimalDigits, int nDivisor = 1);
BASE_API LPCWSTR FormatFieldStringW(FIELD_VALUE& FieldValue, LPWSTR lpszString, int nDecimalDigits, int nDivisor = 1);
BASE_API LPCSTR FormatFieldStringA(FIELD_VALUE& FieldValue, LPSTR lpszString, LPCSTR lpszFormat, int nDivisor = 1);
BASE_API LPCWSTR FormatFieldStringW(FIELD_VALUE& FieldValue, LPWSTR lpszString, LPCWSTR lpszFormat, int nDivisor = 1);
#ifndef UNICODE
#define FormatFieldString	FormatFieldStringA
#else
#define FormatFieldString	FormatFieldStringW
#endif//
BASE_API LPCSTR FieldValue2StringA(FIELD_VALUE& FieldValue, LPCSTR lpszDefault = INVALID_FIELD_STRINGA);
BASE_API LPCWSTR FieldValue2StringW(FIELD_VALUE& FieldValue, LPCWSTR lpszDefault = INVALID_FIELD_STRINGW);
#ifndef UNICODE
#define FieldValue2String	FieldValue2StringA
#else
#define FieldValue2String	FieldValue2StringW
#endif//

BASE_API double FieldValue2Float(FIELD_VALUE& FieldValue);

// 根据复利的公式，计算PV的值
// y 收益率
// f 每年的支付频率
// c 票面的利率
// M 国债的净价
// Day 总共时间
// W ＝ D/（365÷f）  D为计息日到下一个付息日的实际天数
BASE_API double CalcPV( double y , short f , long c , long M , short Day , double W );

// PV 为债券全价 = 购买时候国债的净价 + 应计利息  为Price * 1000
// 返回值为 double类型的收益率 y
// beginDate 交割日期
// endDate   到期日期
// f         支付利息的频率，一般取值为 1 和 2
// c         票面的利率                      单位   price * 1000
// M         国债的票面                      单位   price * 1000(贴现债券M=100)
// N         债券偿还期限（年）              到期一次还本付息债券计算时有效
// GZType    国债类型                        0附息债券, 1贴现债券,2到期一次还本付息债券
// 当返回 -1 时候，表示参数有错误或者函数计算过程中出现错误
BASE_API double CalcShouYi(long PV , unsigned long StartDate  , unsigned long EndDate , short f , long c , long M , unsigned char N, unsigned char GZType);

#define TICKA		"tick"
#define MINUTEA		"minute"
#define MINA		"min"
#define HOURA		"hour"
#define DAYA		"day"
#define WEEKA		"week"
#define MONTHA		"month"
#define YEARA		"year"

#define TICKW		L"tick"
#define MINUTEW		L"minute"
#define MINW		L"min"
#define HOURW		L"hour"
#define DAYW		L"day"
#define WEEKW		L"week"
#define MONTHW		L"month"
#define YEARW		L"year"

#define HISTORY_TICKA		"tick"
#define HISTORY_1SECA		"1sec"
#define HISTORY_5SECA		"5sec"
#define HISTORY_1MINA		"1min"
#define HISTORY_5MINA		"5min"
#define HISTORY_15MINA		"15min"
#define HISTORY_DAYA		"day"
#define HISTORY_WEEKA		"week"
#define HISTORY_MONTHA		"month"
#define HISTORY_YEARA		"year"

#define HISTORY_TICKW		L"tick"
#define HISTORY_1SECW		L"1sec"
#define HISTORY_5SECW		L"5sec"
#define HISTORY_1MINW		L"1min"
#define HISTORY_5MINW		L"5min"
#define HISTORY_15MINW		L"15min"
#define HISTORY_DAYW		L"day"
#define HISTORY_WEEKW		L"week"
#define HISTORY_MONTHW		L"month"
#define HISTORY_YEARW		L"year"

BASE_API LPCSTR Period2StrA(ENUM_TIMEFRAMES Period);
BASE_API LPCWSTR Period2StrW(ENUM_TIMEFRAMES Period);
#ifndef UNICODE
#define Period2Str	Period2StrA
#else
#define Period2Str	Period2StrW
#endif//

BASE_API long CalcPeriodCount(int Days, int MinutePerDay, ENUM_TIMEFRAMES Period);

BASE_API long FindHisDataPos(unsigned long* pPos, HISDATA* pData, unsigned long Count, unsigned long Date, unsigned long Time);

BASE_API void DisrightForward(HISDATA *pData, unsigned long Count, WEIGHT *pWeight, unsigned long WeightCount);
//点除权 // 定(日期)点除权
BASE_API void DisrightByDate(HISDATA *pData, unsigned long Count, WEIGHT *pWeight, unsigned long WeightCount, unsigned long Date);
//向后除权,实际是对倒数第一个权息点的前一天做点除权
BASE_API void DisrightBackward(HISDATA *pData, unsigned long Count, WEIGHT *pWeight, unsigned long WeightCount);
//单纯向后除权
BASE_API void DisrightBackward2(HISDATA *pData, unsigned long Count, WEIGHT *pWeight, unsigned long WeightCount);

#endif//_H_BASE_H_
