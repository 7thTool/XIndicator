#ifndef _H_INDICATOROBJECTER_H_
#define _H_INDICATOROBJECTER_H_

#include "Objecter.h"

class Indicator;

DECLARE_DYNCCREATE_FACTORY_EX(UTIL_API,Indicator)

//////////////////////////////////////////////////////////////////////////
//ж��һ��ָ�경�裺(�����ʾ�û�ָ����ʹ�ã�����ɾ��ָ�꣬Ȼ���ٴμ���ָ��)
//1ȡ��ָ��ע��DYNCREATE_UNREGISTER
//2��¼ʹ�ø�ָ��Ķ���
//3ɾ��ָ����� 
//4����ע��ָ��DYNCREATE_REGISTER
//5�Ӽ�¼�����¼���ָ��
//6���¼���
//7ˢ��
//��������ʾ�ķ�ʽʵ�֣�����ȷ���û�ֹͣʹ��ָ���ˣ��������û��޸Ĳ�ʹ���µ�ָ��
//////////////////////////////////////////////////////////////////////////

class UTIL_API Indicator : virtual public Objecter
{
public:
	//Indicator();
	//virtual ~Indicator();
};

#endif//_H_INDICATOROBJECTER_H_