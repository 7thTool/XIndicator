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

//Ϊ����Objecter��Ӧ�ã�����ҵ����صĻ����⣨��������ͷǽ��湦�ܣ�
//�Ѿ���ʵ��Ӧ���ˣ�����ֱ����TCHAR������������DLL��Ӧ�ñ���ʹ�ú�DLLһ�µ��ַ�����


#endif//_H_UTIL_H_

