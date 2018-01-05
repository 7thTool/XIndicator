#ifndef _H_Windicator_H_
#define _H_Windicator_H_

#include "XIndicatorContainer.h"
#include "../Util/WndObjecterMap.h"
#include "../Util/IndicatorMap.h"

#define INDICATOR_POINT_RECT_WIDTH	2
#define INDICATOR_POINT_RECT_HEIGHT	2

//////////////////////////////////////////////////////////////////////////

class Windicator 
	: public IndicatorContainer
	, public UIObjecterMap<Windicator>
	, public IndicatorMap<Windicator>
{
	typedef Windicator This;
	typedef IndicatorContainer Base;
	typedef UIObjecterMap<Windicator> ObjectMap;
	typedef IndicatorMap<Windicator> WindicatorMap;
	DECLARE_DYNCREATE_OBJECTER(Windicator,_T("Indicator"),Objecter)
protected:
	//这里的MMX只记录显示的最大最小等数据
	//显示信息,所有显示的RECT POINT等信息都是相对于父窗口的位置
	CRect rect;
public:
	Windicator();
	virtual ~Windicator();

	virtual HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	virtual void Destroy();

	virtual bool IsTest(int* cursor = NULL);
	
protected:
	virtual long GetMmxPos(int mmx, int index_pos = -1);
	virtual double GetMmxValue(int mmx, int index_pos = -1);

public:
	virtual double GetLineValue(
		int       line,
		int       shift
		);
	virtual double GetPriceValue(
		int       price,
		int       shift
		);

	virtual long  CopyIndexValue(
		int       index,   // 指标缓冲位置
		int       offset,		// 启动位置
		int       count,		// 复制总额
		double*   buffer		// 复制的目标数组
		);

	virtual long GetPos(unsigned long date,
		unsigned long time,
		unsigned long *pos
		);

	virtual long GetTime(unsigned long pos,
		unsigned long *date,
		unsigned long *time
		);

protected:
	WndObjecter* m_pWndParent;

public:
	void GetRect(LPRECT lpRect) { *lpRect = rect; }

	void Invalidate();

protected:
	int GetBarDispStart(int index = -1);
	int GetBarDispEnd(int index = -1);
	int GetBarDispCount(int index = -1);
	bool IsBarDispPosOk(int nPos, int index = -1);

	//实际上这些函数可以返回非显示部分的数据,所以有可能有负值，或者Pos不在显示区域
	long GetDispIndexPoint(int index, unsigned long pos, LPPOINT lppt);
	long GetDispValuePoint(double dvalue, unsigned long pos, LPPOINT lppt);
	long GetDispPointValue(POINT pt, unsigned long* pos, double* dvalue = NULL);

	long GetDispIndexInfo(IndicatorIndexInfoPtr& infoPtr);
	long GetDispPointInfo(IndicatorPointInfoPtr& infoPtr);
	virtual long GetDispPointInfoEx(IndicatorPointInfoExPtr& infoPtr);

	virtual void DrawOneRefline(HDC hdc, LPCTSTR lpszText, int nTextLen, int x1, int y1, int x2);
	virtual void DrawRefline(HDC hdc, RECT rc, double maxvalue, double minvalue, double yscale, int ybase);
public:
	void UpdateMmxDispValue();

	virtual void OnIndicatorCalcInfoChanged();
	virtual void OnIndicatorDispInfoChanged();
	virtual void OnIndicatorDispInfoExChanged();
	virtual void OnDispInfoChanged();

	virtual long OnKeyEvent(MsgEventPtr & evtPtr, bool & handled);
	virtual long OnMouseEvent(MsgEventPtr & evtPtr, bool & handled);
	virtual long OnCommandEvent(MsgEventPtr & evtPtr, bool & handled);
	virtual long OnMoveEvent(MsgEventPtr & evtPtr, bool & handled);
	virtual long OnSizeEvent(MsgEventPtr & evtPtr, bool & handled);
	virtual long OnEraseBkgndEvent(MsgEventPtr & evtPtr, bool & handled);
	virtual long OnPaintEvent(MsgEventPtr & evtPtr, bool & handled);

	virtual void EraseBkgnd(HDC hdc);
	virtual void Paint(HDC hdc);

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
		CHAIN_EVT_MAP(ObjectMap)
		CHAIN_EVT_MAP(WindicatorMap)
		CHAIN_EVT_MAP(Base)
	END_EVT_MAP()

	long OnCall(Event& evt);
	long OnNotify(Event& evt);
};

#endif//_H_Windicator_H_
