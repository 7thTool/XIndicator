#ifndef _H_XUTIL_H_
#define _H_XUTIL_H_

#ifdef XUTIL_EXPORTS
#define XUTIL_API __declspec(dllexport)
#else
#define XUTIL_API __declspec(dllimport)
#endif

#ifndef XUTIL_EXPORTS
#pragma comment(lib, "XUtil.lib")
#endif//

#include "../Base/Base.h"
#include "XEvtDefine.h"

//为基于Objecter的应用，处理业务相关的基础库（包括界面和非界面功能）
//已经到实际应用了，所以直接用TCHAR，其他依赖该DLL的应用必须使用和DLL一致的字符类型

XUTIL_API long IndicatorField2FieldID(long Id);
XUTIL_API long FieldID2IndicatorField(long Id);

//////////////////////////////////////////////////////////////////////////

//
//字符串匹配
//
XUTIL_API size_t strch_and_match(char* src, char* dst);
XUTIL_API size_t wcsch_and_match(wchar_t* src, wchar_t* dst);
#ifdef UNICODE
#define _tcsch_and_match wcsch_and_match
#else
#define _tcsch_and_match strch_and_match
#endif//

XUTIL_API size_t strch_or_match(char* src, char* dst);
XUTIL_API size_t wcsch_or_match(wchar_t* src, wchar_t* dst);
#ifdef UNICODE
#define _tcsch_or_match wcsch_or_match
#else
#define _tcsch_or_match strch_or_match
#endif//

XUTIL_API size_t strnich_and_match(char* src, int srclen, char* dst, int dstlen);
XUTIL_API size_t wcsnich_and_match(wchar_t* src, int srclen, wchar_t* dst, int dstlen);
#ifdef UNICODE
#define _tcsnich_and_match wcsnich_and_match
#else
#define _tcsnich_and_match strnich_and_match
#endif//
/*
UTIL_API size_t strnich_or_match(char* src, int srclen, char* dst, int dstlen);
UTIL_API size_t wcsnich_or_match(wchar_t* src, int srclen, wchar_t* dst, int dstlen);
#ifdef UNICODE
#define _tcsnich_or_match wcsnich_or_match
#else
#define _tcsnich_or_match strnich_or_match
#endif//*/

XUTIL_API size_t strich_and_match(char* src, char* dst);
XUTIL_API size_t wcsich_and_match(wchar_t* src, wchar_t* dst);
#ifdef UNICODE
#define _tcsich_and_match wcsich_and_match
#else
#define _tcsich_and_match strich_and_match
#endif//

XUTIL_API size_t strich_or_match(char* src, char* dst);
XUTIL_API size_t wcsich_or_match(wchar_t* src, wchar_t* dst);
#ifdef UNICODE
#define _tcsich_or_match wcsich_or_match
#else
#define _tcsich_or_match strich_or_match
#endif//

XUTIL_API size_t strstr_match(char* src, char* dst);
XUTIL_API size_t wcsstr_match(wchar_t* src, wchar_t* dst);
#ifdef UNICODE
#define _tcsstr_match wcsstr_match
#else
#define _tcsstr_match strstr_match
#endif//

XUTIL_API size_t stristr_match(char* src, char* dst);
XUTIL_API size_t wcsistr_match(wchar_t* src, wchar_t* dst);
#ifdef UNICODE
#define _tcsistr_match wcsistr_match
#else
#define _tcsistr_match stristr_match
#endif//

XUTIL_API size_t strnstr_match(char* src, int srclen, char* dst, int dstlen);
XUTIL_API size_t wcsnstr_match(wchar_t* src, int srclen, wchar_t* dst, int dstlen);
#ifdef UNICODE
#define _tcsnstr_match wcsnstr_match
#else
#define _tcsnstr_match strnstr_match
#endif//

XUTIL_API size_t strnistr_match(char* src, int srclen, char* dst, int dstlen);
XUTIL_API size_t wcsnistr_match(wchar_t* src, int srclen, wchar_t* dst, int dstlen);
#ifdef UNICODE
#define _tcsnistr_match wcsnistr_match
#else
#define _tcsnistr_match strnistr_match
#endif//

XUTIL_API long EvtRequest2ResponseValue(long req);
XUTIL_API long EvtResponse2RequestValue(long res);

#endif//_H_XUTIL_H_

