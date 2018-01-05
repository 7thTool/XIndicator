#ifndef _H_EVTDEFINE_H_
#define _H_EVTDEFINE_H_

#include "XEvtDefine.h"
#include "cmdmsgid.h"

//#include "WndObjecter.h"
#include <XLib/UIEvent.h>

class WndObjecter;

//CGET_OBJECT_DISPINFO
#define MAX_BAR_SCALE	9
class ObjectDispInfo : public Object
{
public:
	ObjectDispInfo()
	{
		hCurDraw = NULL;

		crBackgnd = CLR_INVALID;
		crTabSelBackgnd = CLR_INVALID;
		crRptTitleBakcgnd = CLR_INVALID;
		crRptSelBackgnd = CLR_INVALID;

		crTitle = CLR_INVALID;
		crName = CLR_INVALID;
		crText = CLR_INVALID;
		crRising = CLR_INVALID;
		crFalling = CLR_INVALID;
		crCommodityCode = CLR_INVALID;
		crCommodityName = CLR_INVALID;
		crAmount = CLR_INVALID;
		crVolume = CLR_INVALID;
		crTabSel = CLR_INVALID;

		crLine = CLR_INVALID;
		crAverageLine = CLR_INVALID;
		crDrawLine = CLR_INVALID;
		crXYLine = CLR_INVALID;
		crXText = CLR_INVALID;
		crYText = CLR_INVALID;
		crCrossCursor = CLR_INVALID;
		crRptLine = CLR_INVALID;
		crRisingLine = CLR_INVALID;
		crFallingLine = CLR_INVALID;
		crILine[8] = CLR_INVALID;
		crRefline = CLR_INVALID;
		crOrderLine = CLR_INVALID;

		hPen = NULL;
		hRisingPen = NULL;
		hFallingPen = NULL;
		hDrawLinePen = NULL;
		hCrossCursorPen = NULL;
		hNowPen = NULL;
		hOrderPen = NULL;
		pen = NULL;
		penRising = NULL;
		penFalling = NULL;
		penDrawLine = NULL;
		penCrossCursor = NULL;
		penNow = NULL;
		penOrder = NULL;

		hBrush = NULL;
		hRisingBrush = NULL;
		hFallingBrush = NULL;
		hDrawLineBrush = NULL;
		hNullBrush = NULL;
		brush = NULL;
		brushRising = NULL;
		brushFalling = NULL;
		brushDrawLine = NULL;
		brushNull = NULL;

		hName = NULL;
		hText = NULL;
		hTabTitle = NULL;
		hRptTitle = NULL;
		hRptText = NULL;
		hTechTitle = NULL;
		hXText = NULL;
		hYText = NULL;
		hOrder = NULL;
		fontName = NULL;
		fontText = NULL;
		fontTabTitle = NULL;
		fontRptTitle = NULL;
		fontRptText = NULL;
		fontTechTitle = NULL;
		fontXText = NULL;
		fontYText = NULL;
		fontOrder = NULL;

		memset(&xyName, 0, sizeof(SIZE));
		memset(&xyText, 0, sizeof(SIZE));
		memset(&xyTabTitle, 0, sizeof(SIZE));
		memset(&xyRptTitle, 0, sizeof(SIZE));
		memset(&xyRptText, 0, sizeof(SIZE));
		memset(&xyTechTitle, 0, sizeof(SIZE));
		memset(&xyXText, 0, sizeof(SIZE));
		memset(&xyYText, 0, sizeof(SIZE));
		memset(&xyOrder, 0, sizeof(SIZE));
		memset(&xySpace, 0, sizeof(SIZE));

		memset(&xyTabCtrl, 0, sizeof(SIZE));
		memset(&xyScrollBar, 0, sizeof(SIZE));
		memset(&xyWndIndicator, 0, sizeof(SIZE));
		memset(&xyInfoIndicator, 0, sizeof(SIZE));
		memset(&xyCoordinate, 0, sizeof(SIZE));

		memset(&nBarWidth, 0, sizeof(nBarWidth));
		memset(&nBarSpace, 0, sizeof(nBarSpace));
		nBarScale = 0;
		nBarShift = 0;
	}

	~ObjectDispInfo()
	{
		if(hCurDraw) {
			//
		}
		if(hPen) {
			DeleteObject((HGDIOBJ)hPen);
		}
		if(hRisingPen) {
			DeleteObject((HGDIOBJ)hRisingPen);
		}
		if(hFallingPen) {
			DeleteObject((HGDIOBJ)hFallingPen);
		}
		if(hDrawLinePen) {
			DeleteObject((HGDIOBJ)hDrawLinePen);
		}
		if(hCrossCursorPen) {
			DeleteObject((HGDIOBJ)hCrossCursorPen);
		}
		if(hNowPen) {
			DeleteObject((HGDIOBJ)hNowPen);
		}
		if(hOrderPen) {
			DeleteObject((HGDIOBJ)hOrderPen);
		}
		if(pen) {
			delete pen;
		}
		if(penRising) {
			delete penRising;
		}
		if(penFalling) {
			delete penFalling;
		}
		if(penDrawLine) {
			delete penDrawLine;
		}
		if(penCrossCursor) {
			delete penCrossCursor;
		}
		if(penNow) {
			delete penNow;
		}
		if(penOrder) {
			delete penOrder;
		}
		if(hBrush) {
			DeleteObject((HGDIOBJ)hBrush);
		}
		if(hRisingBrush) {
			DeleteObject((HGDIOBJ)hRisingBrush);
		}
		if(hFallingBrush) {
			DeleteObject((HGDIOBJ)hFallingBrush);
		}
		if(hDrawLineBrush) {
			DeleteObject((HGDIOBJ)hDrawLineBrush);
		}
		if(brush) {
			delete brush;
		}
		if(brushRising) {
			delete brushRising;
		}
		if(brushFalling) {
			delete brushFalling;
		}
		if(brushDrawLine) {
			delete brushDrawLine;
		}
		if(brushNull) {
			delete brushNull;
		}
		if(hName) {
			DeleteObject((HGDIOBJ)hName);
		}
		if(hText) {
			DeleteObject((HGDIOBJ)hText);
		}
		if(hTabTitle) {
			DeleteObject((HGDIOBJ)hTabTitle);
		}
		if(hRptTitle) {
			DeleteObject((HGDIOBJ)hRptTitle);
		}
		if(hRptText) {
			DeleteObject((HGDIOBJ)hRptText);
		}
		if(hTechTitle) {
			DeleteObject((HGDIOBJ)hTechTitle);
		}
		if(hXText) {
			DeleteObject((HGDIOBJ)hXText);
		}
		if(hYText) {
			DeleteObject((HGDIOBJ)hYText);
		}
		if(hOrder) {
			DeleteObject((HGDIOBJ)hOrder);
		}
		if(fontName) {
			delete fontName;
		}
		if(fontText) {
			delete fontText;
		}
		if(fontTabTitle) {
			delete fontTabTitle;
		}
		if(fontRptTitle) {
			delete fontRptTitle;
		}
		if(fontRptText) {
			delete fontRptText;
		}
		if(fontTechTitle) {
			delete fontTechTitle;
		}
		if(fontXText) {
			delete fontXText;
		}
		if(fontYText) {
			delete fontYText;
		}
		if(fontOrder) {
			delete fontOrder;
		}
	}

	COLORREF GetUpDownColor(int nUpDown)
	{
		if (nUpDown < 0) {
			return crFalling;
		} else if(nUpDown > 0) {
			return crRising;
		}
		return crText;
	}

	COLORREF GetUpDownLineColor(int nUpDown)
	{
		if (nUpDown < 0) {
			return crFallingLine;
		} else if(nUpDown > 0) {
			return crRisingLine;
		}
		return crLine;
	}

	HPEN GetUpDownPen(int nUpDown)
	{
		if (nUpDown < 0) {
			return hFallingPen;
		} else if(nUpDown > 0) {
			return hRisingPen;
		}
		return hPen;
	}

	Pen* GetUpDownLinePen(int nUpDown)
	{
		if (nUpDown < 0) {
			return penFalling;
		} else if(nUpDown > 0) {
			return penRising;
		}
		return pen;
	}

	HBRUSH GetUpDownBrush(int nUpDown)
	{
		if (nUpDown < 0) {
			return hFallingBrush;
		} else if(nUpDown > 0) {
			return hRisingBrush;
		}
		return hBrush;
	}

	Brush* GetUpDownLineBrush(int nUpDown)
	{
		if (nUpDown < 0) {
			return brushFalling;
		} else if(nUpDown > 0) {
			return brushRising;
		}
		return brush;
	}

	COLORREF GetFieldColor(const FIELD_VALUE& FieldValue)
	{
		if (!FieldValue.bCalculated) {
			return crText;
		}

		switch (FieldValue.FieldID)
		{
		case IDF_COMMODITY_CODE:
			return crCommodityCode;
			break;
		case IDF_COMMODITY_NAME:
			return crCommodityName;
			break;
		default:
			if (FieldValue.cUpDown < 0) {
				return crFalling;
			} else if(FieldValue.cUpDown > 0) {
				return crRising;
			}
			switch(FieldValue.cValueType)
			{
			case FIELD_VALUE_AMOUNT:
				return crAmount;
				break;
			case FIELD_VALUE_VOLUME:
				return crVolume;
			default:
				break;
			}
			break;
		}
		return crText;
	}

	//Ĭ����ʾ����

	//���
	HCURSOR hCurDraw;

	//��ɫ
	COLORREF crBackgnd;			//����
	COLORREF crTabSelBackgnd;	//��ǩѡ�б���
	COLORREF crRptTitleBakcgnd;	//������ⱳ��
	COLORREF crRptSelBackgnd;	//����ѡ�б���

	COLORREF crTitle;			//����
	COLORREF crName;			//����
	COLORREF crText;			//����
	COLORREF crRising;			//����
	COLORREF crFalling;			//�µ�
	COLORREF crCommodityCode;	//����
	COLORREF crCommodityName;	//����
	COLORREF crAmount;			//��
	COLORREF crVolume;			//��
	COLORREF crTabSel;			//��ǩѡ��

	COLORREF crLine;			//��
	COLORREF crAverageLine;		//����
	COLORREF crDrawLine;		//����
	COLORREF crXYLine;			//X��Y�ָ���
	COLORREF crXText;			//X��������
	COLORREF crYText;			//Y��������
	COLORREF crCrossCursor;		//ʮ���α�	
	COLORREF crRptLine;			//������
	COLORREF crRisingLine;		//������
	COLORREF crFallingLine;		//�µ���
	COLORREF crILine[8];		//ָ����
	COLORREF crRefline;			//�ο���
	COLORREF crOrderLine;		//������

	//����
	HPEN hPen;
	HPEN hRisingPen;
	HPEN hFallingPen;
	HPEN hDrawLinePen;
	HPEN hCrossCursorPen;
	HPEN hYCrossCursorPen;
	HPEN hNowPen;
	HPEN hOrderPen;
	Pen* pen;
	Pen* penRising;
	Pen* penFalling;
	Pen* penDrawLine;
	Pen* penCrossCursor;
	Pen* penNow;
	Pen* penOrder;

	//��ˢ
	HBRUSH hBrush;
	HBRUSH hRisingBrush;
	HBRUSH hFallingBrush;
	HBRUSH hDrawLineBrush;
	HBRUSH hNullBrush;
	Brush* brush;
	Brush* brushRising;
	Brush* brushFalling;
	Brush* brushDrawLine;
	Brush* brushNull;

	//����
	HFONT hName;
	HFONT hText;
	HFONT hTabTitle;
	HFONT hRptTitle;
	HFONT hRptText;
	HFONT hTechTitle;
	HFONT hXText;
	HFONT hYText;
	HFONT hOrder;
	Font* fontName;
	Font* fontText;
	Font* fontTabTitle;
	Font* fontRptTitle;
	Font* fontRptText;
	Font* fontTechTitle;
	Font* fontXText;
	Font* fontYText;
	Font* fontOrder;

	//����߿�
	SIZE xyName;
	SIZE xyText;
	SIZE xyTabTitle;
	SIZE xyRptTitle;
	SIZE xyRptText;
	SIZE xyTechTitle;
	SIZE xyXText;
	SIZE xyYText;
	SIZE xyOrder;
	SIZE xySpace;

	//����߿������ˮƽ���ߴ�ֱ���֣�
	SIZE xyTabCtrl;								//Ĭ�ϱ�ǩˮƽ�߶ȣ����ߴ�ֱʱ���
	SIZE xyScrollBar;							//Ĭ�Ϲ�����ˮƽ�߶ȣ����ߴ�ֱʱ���
	SIZE xyWndIndicator;						//Ĭ��ָ�괰��ˮƽ�߶ȣ����ߴ�ֱʱ���
	SIZE xyInfoIndicator;						//Ĭ��ָ����Ϣ��ˮƽ�Ҳ���Ϣ����ȺͶ����������߶ȣ����ߴ�ֱʱ�����ԣ�
	SIZE xyCoordinate;							//Ĭ��ʱ��������ˮƽ�߶ȣ����ߴ�ֱʱ�����ԣ�

	int nBarWidth[MAX_BAR_SCALE];				//K������ȵ���
	int nBarSpace[MAX_BAR_SCALE];				//K������϶����
	int nBarScale;
	int nBarShift;								//ƽ��ͼ��,0��ʾ��ƽ��
};
typedef Handle<ObjectDispInfo> ObjectDispInfoPtr;

class ContainerInfo : public Object
{
public:
	ContainerInfo()
	{
		bInteractive = TRUE;
		pContainer = NULL;
		//KindList;
		CommodityListPtr = new CommodityListInfo();
		CurCommodityPos = -1;
	}

	BOOL IsInteractive()
	{
		return bInteractive;
	}

	WndObjecter* GetContainer()
	{
		return pContainer;
	}
	std::vector<KindInfo>& GetKindList()
	{
		return KindList.KindList;
	}
	/*KindInfo& GetKind(int Pos)
	{
		return KindList.KindList[Pos];
	}*/
	int GetCurKindPos()
	{
		if (!KindList.KindList.empty()) {
			return KindList.CurKindPos;
		}
		return -1;
	}
	KindInfo& GetCurKind()
	{
		return CommodityListPtr->Kind;
	}
	int SetCurKind(int Pos)
	{
		int OldPos = KindList.CurKindPos;
		KindList.CurKindPos = Pos;
		return OldPos;
	}
	int SetCurKind(const KindInfo& Kind)
	{
		for (int i=0; i<KindList.KindList.size(); i++)
		{
			if (KindList.KindList[i] == Kind) {
				return SetCurKind(i);
			}
		}
		return -1;
	}
	COMREFLIST& GetCommodityList()
	{
		return CommodityListPtr->CommodityList;
	}
	/*COMREF& GetCommodity(int Pos)
	{
		return CommodityListPtr->CommodityList[Pos];
	}*/
	int GetCurCommodityPos()
	{
		return CurCommodityPos;
	}
	int GetCurCommodity(COMREF* pCommodity = NULL)
	{
		if(pCommodity) {
			ASSERT(CommodityListPtr);
			if(CurCommodityPos>=0 && CurCommodityPos<=CommodityListPtr->CommodityList.size()) {
				*pCommodity = CommodityListPtr->CommodityList[CurCommodityPos];
			}
		}
		return CurCommodityPos;
	}
	int SetCurCommodity(int Pos)
	{
		int OldPos = CurCommodityPos;
		CurCommodityPos = Pos;
		return OldPos;
	}
	int SetCurCommodity(const COMREF& Commodity)
	{
		for (int i=0; i<CommodityListPtr->CommodityList.size(); i++)
		{
			if (CommodityListPtr->CommodityList[i] == Commodity) {
				return SetCurCommodity(i);
			}
		}
		return -1;
	}

	BOOL bInteractive;
	WndObjecter* pContainer;
	KindListInfo KindList;
	CommodityListInfoPtr CommodityListPtr;
	int CurCommodityPos;
};
typedef Handle<ContainerInfo> ContainerInfoPtr;

class ViewInfo : public Object
{
public:
	ViewInfo()
	{

	}
	ContainerInfoPtr InfoPtr;

	//HisDataInfoPtr TechDataPtr;
};
typedef Handle<ViewInfo> ViewInfoPtr;
class ViewDispInfo : public Object
{
public:
	ViewDispInfo()
	{
		Period = CYC_DAY;
		PeriodEx = 0;
		DWType = DW_FORWARD;
		DWDate = 0;
		/*bShowMiniTrader = false;
		bRobot = false;
		bBarAutoScroll = true;
		nBarShift = 2;*/
	}
	
	//��������������Ϣ
	ENUM_TIMEFRAMES Period;
	int PeriodEx;

	ENUM_DWTYPE DWType;
	unsigned long DWDate;

	/*BOOL bShowMiniTrader:1;		//�Ƿ���ʾ�������
	BOOL bRobot:1;				//�Ƿ��������ܽ���ϵͳ
	BOOL bBarAutoScroll:1;		//�Ƿ����Զ�����
	BOOL nBarShift:13;			//����ƫ����*/
	//////////////////////////////////////////////////////////////////////////
		
};
typedef Handle<ViewDispInfo> ViewDispInfoPtr;

//CCALL_FRAME_GOTOCONTAINER
class DoGotoContainer : public Object
{
public:
	DoGotoContainer(LPCTSTR lpszName, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE, BOOL bNew = FALSE)
		:bNew(bNew),lpszName(lpszName),lpszXml(lpszXml),XmlFlag(XmlFlag){}

	BOOL bNew;
	LPCTSTR lpszName;
	LPCTSTR lpszXml;
	UINT XmlFlag;

	ContainerInfoPtr InfoPtr;
};
typedef Handle<DoGotoContainer> DoGotoContainerPtr;

//CCALL_LOGIN_LOGIN
class DoLogin : public Object 
{
public:
	DoLogin()
	{
		modal = 0;
		hParent = NULL;
		//strParam;
	}
	int modal;
	HWND hParent;
	CString strParam;
};
typedef Handle<DoLogin> DoLoginPtr;

#endif//_H_EVT_DEFINE_H_