#ifndef _H_XINDICATOREX_HPP_
#define _H_XINDICATOREX_HPP_

#include "XIndicatorImp.h"

//////////////////////////////////////////////////////////////////////////

class XINDICATOR_API IndicatorEx 
	: public Indicator
{
	typedef IndicatorEx This;
	typedef Indicator Base;
#if XINDICATORSERVER
#else
	friend class IndicatorContainer;
#endif//
public:
	IndicatorEx();
	virtual ~IndicatorEx();

protected:
	//���㸽����Ϣ
	double mmxvalues[MAX_INDICATOR_INDEX][MMX_INDEX_COUNT]; //�����¼��ÿһ��ָ���߼������С���ֵ
	double mmxvalue[MMX_COUNT]; //�����¼��ָ������MMX_MIN��MMX_MAX��MMX_MINDISPVALUE��MMX_MAXDISPVALUE��ֵ����K�����ݵĸ�����С���ֵ��λ��

protected:
	void EmptyMmxValue(bool bAll = true);

protected:
	virtual long DoInit();
	virtual void DoInput();
	virtual void DoPreFilter();
	virtual long DoFilter();
	virtual void DoAfterFilter();
	virtual void DoPreCalc();
	virtual long DoCalc();
	virtual void DoAfterCalc(long counted);
	virtual void DoDeInit();

public:
	virtual long GetMmxPos(int mmx, int index_pos = -1);
	virtual double GetMmxValue(int mmx, int index_pos = -1);

};

#endif//_H_XINDICATOREX_HPP_

