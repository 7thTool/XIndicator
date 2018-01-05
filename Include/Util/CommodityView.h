#ifndef _H_COMMODITYVIEW_H_
#define _H_COMMODITYVIEW_H_

#include "../Util/ViewObjecter.h"

template<class T, class TBase = UIXWnd2>
class CommodityViewImpl 
	: public ViewObjecterImpl<T,TBase>
	, public UIPaint<T>
{
	typedef CommodityViewImpl<T,TBase> This;
	typedef ViewObjecterImpl<T,TBase> Base;
	typedef UIPaint<T> PaintMap;
public:
	CommodityViewImpl()
	{
	}

public:

	BEGIN_MSG_MAP(This)
		CHAIN_MSG_MAP(PaintMap)
		CHAIN_MSG_MAP(Base)
	END_MSG_MAP()
};

#endif//_H_COMMODITYVIEW_H_