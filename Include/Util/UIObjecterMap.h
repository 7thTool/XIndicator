#ifndef _H_UIOBJECTERMAP_H_
#define _H_UIOBJECTERMAP_H_

#include "EvtDefine.h"
#include "ObjecterMap.h"

template<class T>
class UIObjecterMap : public ObjecterMap<T>
{
	typedef UIObjecterMap<T> This;
	typedef ObjecterMap<T> Base;
protected:
	ObjectDispInfoPtr m_DispInfoPtr;

public:
	void Clear()
	{
		Base::Clear();
		m_DispInfoPtr = 0;
	}
	const ObjectDispInfoPtr& GetDispInfoPtr()
	{
		return m_DispInfoPtr;
	}
	void OnDispInfoChanged()
	{
	}

	/*void OnGetDispInfo(ObjectDispInfoPtr& objPtr)
	{
		ASSERT(objPtr && objPtr!=m_DispInfoPtr);
		objPtr->crBackgnd = m_DispInfoPtr->crBackgnd;		//背景
		objPtr->crTabSelBackgnd = m_DispInfoPtr->crTabSelBackgnd;	//标签选中背景
		objPtr->crRptTitleBakcgnd = m_DispInfoPtr->crRptTitleBakcgnd;//报表标题背景
		objPtr->crRptSelBackgnd = m_DispInfoPtr->crRptSelBackgnd;	//报表选中背景

		objPtr->crTitle = m_DispInfoPtr->crTitle;			//标题
		objPtr->crName = m_DispInfoPtr->crName;			//名称
		objPtr->crText = m_DispInfoPtr->crText;			//文字
		objPtr->crRising = m_DispInfoPtr->crRising;			//上涨
		objPtr->crFalling = m_DispInfoPtr->crFalling;		//下跌
		objPtr->crCommodityCode = m_DispInfoPtr->crCommodityCode;	//代码
		objPtr->crCommodityName = m_DispInfoPtr->crCommodityName;	//名称
		objPtr->crAmount = m_DispInfoPtr->crAmount;			//价
		objPtr->crVolume = m_DispInfoPtr->crVolume;			//量
		objPtr->crTabSel = m_DispInfoPtr->crTabSel;			//标签选中

		objPtr->crLine = m_DispInfoPtr->crLine;			//线
		objPtr->crAverageLine = m_DispInfoPtr->crAverageLine;	//均线
		objPtr->crDrawLine = m_DispInfoPtr->crDrawLine;		//画线
		objPtr->crXYLine = m_DispInfoPtr->crXYLine;			//X、Y分隔线
		objPtr->crXText = m_DispInfoPtr->crXText;			//X坐标文字
		objPtr->crYText = m_DispInfoPtr->crYText;			//Y坐标文字
		objPtr->crCrossCursor = m_DispInfoPtr->crCrossCursor;	//十字游标	
		objPtr->crRptLine = m_DispInfoPtr->crRptLine;		//报表线

		LOGPEN lgPen;
		GetObject(m_DispInfoPtr->hPen, sizeof(LOGPEN), &lgPen);
		objPtr->hPen = CreatePenIndirect(&lgPen);
		GetObject(m_DispInfoPtr->hRisingPen, sizeof(LOGPEN), &lgPen);
		objPtr->hRisingPen = CreatePenIndirect(&lgPen);
		GetObject(m_DispInfoPtr->hFallingPen, sizeof(LOGPEN), &lgPen);
		objPtr->hFallingPen = CreatePenIndirect(&lgPen);
		GetObject(m_DispInfoPtr->hDrawLinePen, sizeof(LOGPEN), &lgPen);
		objPtr->hDrawLinePen = CreatePenIndirect(&lgPen);

		LOGBRUSH lgBrush;
		GetObject(m_DispInfoPtr->hBrush, sizeof(LOGBRUSH), &lgBrush);
		objPtr->hBrush = CreateBrushIndirect(&lgBrush);
		GetObject(m_DispInfoPtr->hRisingBrush, sizeof(LOGBRUSH), &lgBrush);
		objPtr->hRisingBrush = CreateBrushIndirect(&lgBrush);
		GetObject(m_DispInfoPtr->hFallingBrush, sizeof(LOGBRUSH), &lgBrush);
		objPtr->hFallingBrush = CreateBrushIndirect(&lgBrush);
		GetObject(m_DispInfoPtr->hDrawLineBrush, sizeof(LOGBRUSH), &lgBrush);
		objPtr->hDrawLineBrush = CreateBrushIndirect(&lgBrush);
		objPtr->hNullBrush = m_DispInfoPtr->hNullBrush;

		LOGFONT lgFont;
		GetObject(m_DispInfoPtr->hName, sizeof(LOGFONT), &lgFont);
		objPtr->hName = CreateFontIndirect(&lgFont);
		GetObject(m_DispInfoPtr->hText, sizeof(LOGFONT), &lgFont);
		objPtr->hText = CreateFontIndirect(&lgFont);
		GetObject(m_DispInfoPtr->hTabTitle, sizeof(LOGFONT), &lgFont);
		objPtr->hTabTitle = CreateFontIndirect(&lgFont);
		GetObject(m_DispInfoPtr->hRptTitle, sizeof(LOGFONT), &lgFont);
		objPtr->hRptTitle = CreateFontIndirect(&lgFont);
		GetObject(m_DispInfoPtr->hRptText, sizeof(LOGFONT), &lgFont);
		objPtr->hRptText = CreateFontIndirect(&lgFont);
		GetObject(m_DispInfoPtr->hTechTitle, sizeof(LOGFONT), &lgFont);
		objPtr->hTechTitle = CreateFontIndirect(&lgFont);
		GetObject(m_DispInfoPtr->hXText, sizeof(LOGFONT), &lgFont);
		objPtr->hXText = CreateFontIndirect(&lgFont);
		GetObject(m_DispInfoPtr->hYText, sizeof(LOGFONT), &lgFont);
		objPtr->hYText = CreateFontIndirect(&lgFont);

		//字体高宽
		objPtr->xyName = m_DispInfoPtr->xyName;
		objPtr->xyText = m_DispInfoPtr->xyText;
		objPtr->xyTabTitle = m_DispInfoPtr->xyTabTitle;
		objPtr->xyRptTitle = m_DispInfoPtr->xyRptTitle;
		objPtr->xyRptText = m_DispInfoPtr->xyRptText;
		objPtr->xyTechTitle = m_DispInfoPtr->xyTechTitle;
		objPtr->xyXText = m_DispInfoPtr->xyXText;
		objPtr->xyYText = m_DispInfoPtr->xyYText;
		objPtr->xySpace = m_DispInfoPtr->xySpace;

		//窗体高宽
		objPtr->xyTabCtrl = m_DispInfoPtr->xyTabCtrl;
		objPtr->xyScrollBar = m_DispInfoPtr->xyScrollBar;

		objPtr->xyWndIndicator = m_DispInfoPtr->xyWndIndicator;
		objPtr->xyInfoIndicator = m_DispInfoPtr->xyInfoIndicator;
		objPtr->xyCoordinate = m_DispInfoPtr->xyCoordinate;

		memcpy(objPtr->nBarWidth, m_DispInfoPtr->nBarWidth, sizeof(objPtr->nBarWidth));
		memcpy(objPtr->nBarSpace, m_DispInfoPtr->nBarSpace, sizeof(objPtr->nBarSpace));
		objPtr->nBarScale = m_DispInfoPtr->nBarScale;
		objPtr->nBarShift = m_DispInfoPtr->nBarShift;
	}*/

	long OnKeyEvent(MsgEventPtr & evtPtr, bool & handled)
	{
		return RLT_UNKNOWN;
	}
	long OnMouseEvent(MsgEventPtr & evtPtr, bool & handled)
	{
		return RLT_UNKNOWN;
	}
	long OnCommandEvent(MsgEventPtr & evtPtr, bool & handled)
	{
		return RLT_UNKNOWN;
	}
	long OnMoveEvent(MsgEventPtr & evtPtr, bool & handled)
	{
		return RLT_UNKNOWN;
	}
	long OnSizeEvent(MsgEventPtr & evtPtr, bool & handled)
	{
		return RLT_UNKNOWN;
	}
	long OnEraseBkgndEvent(MsgEventPtr & evtPtr, bool & handled)
	{
		return RLT_UNKNOWN;
	}
	long OnPaintEvent(MsgEventPtr & evtPtr, bool & handled)
	{
		return RLT_UNKNOWN;
	}
	long OnMessageEvent(MsgEventPtr & evtPtr, bool & handled)
	{
		T* pT = static_cast<T*>(this);
		if (evtPtr->message>=WM_KEYFIRST && evtPtr->message<=WM_KEYLAST) {
			return pT->OnKeyEvent(evtPtr, handled);
		} else if (evtPtr->message>=WM_MOUSEFIRST && evtPtr->message<=WM_MOUSELAST) {
			return pT->OnMouseEvent(evtPtr, handled);
		} else if(evtPtr->message>=WM_COMMAND) {
			return pT->OnCommandEvent(evtPtr, handled);
		} else if(evtPtr->message>=WM_MOVE) {
			return pT->OnMoveEvent(evtPtr, handled);
		} else if(evtPtr->message>=WM_SIZE) {
			return pT->OnSizeEvent(evtPtr, handled);
		}  else if(evtPtr->message>=WM_ERASEBKGND) {
			return pT->OnEraseBkgndEvent(evtPtr, handled);
		}  else if(evtPtr->message>=WM_PAINT) {
			return pT->OnPaintEvent(evtPtr, handled);
		} 
		return RLT_UNKNOWN;
	}

	void OnInvalidate(ObjectPtr objPtr)
	{
		
	}

	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		CHAIN_EVT_MAP(Base)
	END_EVT_MAP()

	long OnCall(Event& evt)
	{
		switch(evt.value)
		{
		/*case MAKEVALUE(MGET_PLAT_OBJECT,CGET_OBJECT_DISPINFO):
			{
				T* pT = static_cast<T*>(this);
				pT->OnGetDispInfo(ObjectDispInfoPtr::dynamicCast(evt.objPtr));
				return RLT_OK;
			}
			break;*/
		//////////////////////////////////////////////////////////////////////////
		case MAKEVALUE(MSET_PLAT_OBJECT,CSET_OBJECT_DISPINFO):
			{
				T* pT = static_cast<T*>(this);
				m_DispInfoPtr = ObjectDispInfoPtr::dynamicCast(evt.objPtr);
				pT->OnDispInfoChanged();
				return RLT_OK;
			}
			break;
		//////////////////////////////////////////////////////////////////////////
		case MAKEVALUE(MCALL_PLAT_OBJECT,CCALL_OBJECT_KEY):
			{
				MsgEventPtr objPtr = MsgEventPtr::dynamicCast(evt.objPtr);
				if (objPtr) {
					T* pT = static_cast<T*>(this);
					return pT->OnKeyEvent(objPtr, evt.handled);
				}
			}
			break;
		case MAKEVALUE(MCALL_PLAT_OBJECT,CCALL_OBJECT_MOUSE):
			{
				MsgEventPtr objPtr = MsgEventPtr::dynamicCast(evt.objPtr);
				if (objPtr) {
					T* pT = static_cast<T*>(this);
					return pT->OnMouseEvent(objPtr, evt.handled);
				}
			}
			break;
		case MAKEVALUE(MCALL_PLAT_OBJECT,CCALL_OBJECT_COMMAND):
			{
				MsgEventPtr objPtr = MsgEventPtr::dynamicCast(evt.objPtr);
				if (objPtr) {
					T* pT = static_cast<T*>(this);
					return pT->OnCommandEvent(objPtr, evt.handled);
				}
			}
			break;
		case MAKEVALUE(MCALL_PLAT_OBJECT,CCALL_OBJECT_MOVE):
			{
				MsgEventPtr objPtr = MsgEventPtr::dynamicCast(evt.objPtr);
				if (objPtr) {
					T* pT = static_cast<T*>(this);
					return pT->OnMoveEvent(objPtr, evt.handled);
				}
			}
			break;
		case MAKEVALUE(MCALL_PLAT_OBJECT,CCALL_OBJECT_SIZE):
			{
				MsgEventPtr objPtr = MsgEventPtr::dynamicCast(evt.objPtr);
				if (objPtr) {
					T* pT = static_cast<T*>(this);
					return pT->OnSizeEvent(objPtr, evt.handled);
				}
			}
			break;
		case MAKEVALUE(MCALL_PLAT_OBJECT,CCALL_OBJECT_ERASEBKGND):
			{
				MsgEventPtr objPtr = MsgEventPtr::dynamicCast(evt.objPtr);
				if (objPtr) {
					T* pT = static_cast<T*>(this);
					return pT->OnEraseBkgndEvent(objPtr, evt.handled);
				}
			}
			break;
		case MAKEVALUE(MCALL_PLAT_OBJECT,CCALL_OBJECT_PAINT):
			{
				MsgEventPtr objPtr = MsgEventPtr::dynamicCast(evt.objPtr);
				if (objPtr) {
					T* pT = static_cast<T*>(this);
					return pT->OnPaintEvent(objPtr, evt.handled);
				}
			}
			break;
		case MAKEVALUE(MCALL_PLAT_OBJECT,CCALL_OBJECT_INVALIDATE):
			{
				T* pT = static_cast<T*>(this);
				pT->OnInvalidate(evt.objPtr);
				return RLT_OK;
			}
			break;
		default:
			evt.handled = false;
			break;
		}
		return RLT_UNKNOWN;
	}
};

#endif//_H_UIOBJECTERMAP_H_