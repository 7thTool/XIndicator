#ifndef _H_INDICATOR_H_
#define _H_INDICATOR_H_

// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� INDICATOR_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// INDICATOR_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef INDICATOR_EXPORTS
#define INDICATOR_API __declspec(dllexport)
#else
#define INDICATOR_API __declspec(dllimport)
#endif
#ifndef INDICATOR_EXPORTS
#pragma comment(lib, "Indicator.lib")
#endif//
/*
// �����Ǵ� Indicator.dll ������
class INDICATOR_API CIndicator {
public:
	CIndicator(void);
	// TODO: �ڴ�������ķ�����
};

extern INDICATOR_API int nIndicator;

INDICATOR_API int fnIndicator(void);
*/
//////////////////////////////////////////////////////////////////////////

#include "IndicatorDef.h"
#include "XIndicator.h"

//////////////////////////////////////////////////////////////////////////

#endif//_H_INDICATOR_H_

