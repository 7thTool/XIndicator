#ifndef _H_INDICATOROBJECTER_H_
#define _H_INDICATOROBJECTER_H_

#include "Objecter.h"

class Indicator;

DECLARE_DYNCCREATE_FACTORY_EX(UTIL_API,Indicator)

//////////////////////////////////////////////////////////////////////////
//卸载一个指标步骤：(最好提示用户指标在使用，请先删除指标，然后再次加载指标)
//1取消指标注册DYNCREATE_UNREGISTER
//2记录使用该指标的对象
//3删除指标对象 
//4重新注册指标DYNCREATE_REGISTER
//5从记录里重新加载指标
//6重新计算
//7刷新
//现在用提示的方式实现，必须确保用户停止使用指标了，才允许用户修改并使用新的指标
//////////////////////////////////////////////////////////////////////////

class UTIL_API Indicator : virtual public Objecter
{
public:
	//Indicator();
	//virtual ~Indicator();
};

#endif//_H_INDICATOROBJECTER_H_