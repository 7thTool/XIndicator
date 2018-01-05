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
	//计算附加信息
	double mmxvalues[MAX_INDICATOR_INDEX][MMX_INDEX_COUNT]; //这里记录了每一条指标线计算的最小最大值
	double mmxvalue[MMX_COUNT]; //这里记录了指标计算的MMX_MIN，MMX_MAX，MMX_MINDISPVALUE，MMX_MAXDISPVALUE的值，和K线数据的各类最小最大值的位置

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

