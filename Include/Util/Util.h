#ifndef _H_UTIL_H_
#define _H_UTIL_H_

#ifdef UTIL_EXPORTS
#define UTIL_API __declspec(dllexport)
#else
#define UTIL_API __declspec(dllimport)
#endif

#ifndef UTIL_EXPORTS
#pragma comment(lib, "Util.lib")
#endif//

#include "XUtil.h"
#include "EvtDefine.h"

//为基于Objecter的应用，处理业务相关的基础库（包括界面和非界面功能）
//已经到实际应用了，所以直接用TCHAR，其他依赖该DLL的应用必须使用和DLL一致的字符类型


#endif//_H_UTIL_H_

