#ifndef _H_BASE_H_
#define _H_BASE_H_

// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� BASE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// BASE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef BASE_EXPORTS
#define BASE_API __declspec(dllexport)
#else
#define BASE_API __declspec(dllimport)
#endif

#ifndef BASE_EXPORTS
#pragma comment(lib, "Base.lib")
#endif//

// �����Ǵ� Base.dll ������
class BASE_API CBase {
public:
	CBase(void);
	// TODO: �ڴ�������ķ�����
};

extern BASE_API int nBase;

BASE_API int fnBase(void);

//////////////////////////////////////////////////////////////////////////
///�ǽ�������ݴ����

#include <DataStd.h>
#include <FieldDef.h>
#include <XLib/XTime.h>

BASE_API int GetDecimalDigits(double v); //ȡ������С��λ��

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

//��ʽ��
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

// ���ݸ����Ĺ�ʽ������PV��ֵ
// y ������
// f ÿ���֧��Ƶ��
// c Ʊ�������
// M ��ծ�ľ���
// Day �ܹ�ʱ��
// W �� D/��365��f��  DΪ��Ϣ�յ���һ����Ϣ�յ�ʵ������
BASE_API double CalcPV( double y , short f , long c , long M , short Day , double W );

// PV Ϊծȯȫ�� = ����ʱ���ծ�ľ��� + Ӧ����Ϣ  ΪPrice * 1000
// ����ֵΪ double���͵������� y
// beginDate ��������
// endDate   ��������
// f         ֧����Ϣ��Ƶ�ʣ�һ��ȡֵΪ 1 �� 2
// c         Ʊ�������                      ��λ   price * 1000
// M         ��ծ��Ʊ��                      ��λ   price * 1000(����ծȯM=100)
// N         ծȯ�������ޣ��꣩              ����һ�λ�����Ϣծȯ����ʱ��Ч
// GZType    ��ծ����                        0��Ϣծȯ, 1����ծȯ,2����һ�λ�����Ϣծȯ
// ������ -1 ʱ�򣬱�ʾ�����д�����ߺ�����������г��ִ���
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
//���Ȩ // ��(����)���Ȩ
BASE_API void DisrightByDate(HISDATA *pData, unsigned long Count, WEIGHT *pWeight, unsigned long WeightCount, unsigned long Date);
//����Ȩ,ʵ���ǶԵ�����һ��ȨϢ���ǰһ�������Ȩ
BASE_API void DisrightBackward(HISDATA *pData, unsigned long Count, WEIGHT *pWeight, unsigned long WeightCount);
//��������Ȩ
BASE_API void DisrightBackward2(HISDATA *pData, unsigned long Count, WEIGHT *pWeight, unsigned long WeightCount);

#endif//_H_BASE_H_
