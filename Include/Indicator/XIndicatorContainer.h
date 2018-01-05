#ifndef _H_XIndicatorContainer_HPP_
#define _H_XIndicatorContainer_HPP_

#if XINDICATORSERVER

#include "XIndicatorImp.h"

#else

#include "XIndicatorExImp.h"

//#define INDICATOR_POINT_RECT_WIDTH	2
//#define INDICATOR_POINT_RECT_HEIGHT	2

//////////////////////////////////////////////////////////////////////////

class XINDICATOR_API IndicatorContainer 
	: public IndicatorEx
{
	typedef IndicatorContainer This;
	typedef IndicatorEx Base;
	//DECLARE_DYNCREATE_OBJECTER(IndicatorContainer,_T("Indicator"),Objecter)
protected:
	//��ʾָ���������ڽ�������ʾ�ģ�����֪�������ļ���ָ�꣬������Ҫ�����������Ե���Ϣ���Ա�����������Ϣָ���ļ���ָ��
	//����û�û������ָ����ʾ���ԣ�����ͨ������ָ���ȡĬ�ϵ���ʾ���ԣ��Ա������ʾָ��
	//����ָ��
	XIndicator* m_pCalcIndicator;

	//�����MMXֻ��¼��ʾ�������С������
	//��ʾ��Ϣ,������ʾ��RECT POINT����Ϣ��������ڸ����ڵ�λ��
	//CRect rect;
public:
	IndicatorContainer();
	virtual ~IndicatorContainer();

	//virtual HWND Create(HWND hWndParent, LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	//virtual void Destroy();
	
	void Load(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);
	void Save(LPCTSTR lpszXml = NULL, UINT XmlFlag = XML_FLAG_FILE);

	virtual LRESULT SetAttributeString(LPCTSTR lpszAttr, LPCTSTR lpszValue, UINT uFlags = 0);
	virtual LRESULT SetIndexAttributeString(UINT nIndex, LPCTSTR lpszAttr, LPCTSTR lpszValue, UINT uFlags = 0);
	
	virtual bool IsTest(int* cursor = NULL);

	//virtual long Init();
	virtual long Calc(PINDICATORCALCCONTEXTINFO in);
protected:
	virtual long Calc();
public:
	//virtual void DeInit();
protected:
	virtual long DoInit();
	virtual void DoPreCalc();
	//virtual long DoCalc();
	virtual void DoAfterCalc(long err);

protected:
	virtual XIndicator* RefIndicator(LPCTSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	virtual long ReleaseIndicator(XIndicator* handle);
	virtual void ReleaseIndicatorAll();

protected:
//	virtual long GetMmxPos(int mmx, int index_pos = -1);
//	virtual double GetMmxValue(int mmx, int index_pos = -1);
//
//public:
//	virtual double GetLineValue(
//		int       line,
//		int       shift
//		);
//	virtual double GetPriceValue(
//		int       price,
//		int       shift
//		);
//
//	virtual long  CopyIndexValue(
//		int       index,   // ָ�껺��λ��
//		int       offset,		// ����λ��
//		int       count,		// �����ܶ�
//		double*   buffer		// ���Ƶ�Ŀ������
//		);
//
//	virtual long GetPos(unsigned long date,
//		unsigned long time,
//		unsigned long *pos
//		);
//
//	virtual long GetTime(unsigned long pos,
//		unsigned long *date,
//		unsigned long *time
//		);
//
//protected:
//	WndObjecter* m_pWndParent;
//
//public:
//	void GetRect(LPRECT lpRect) { *lpRect = rect; }
//
//	void Invalidate();
//
//protected:
//	int GetBarDispStart(int index = -1);
//	int GetBarDispEnd(int index = -1);
//	int GetBarDispCount(int index = -1);
//	bool IsBarDispPosOk(int nPos, int index = -1);
//
//	//ʵ������Щ�������Է��ط���ʾ���ֵ�����,�����п����и�ֵ������Pos������ʾ����
//	long GetDispIndexPoint(int index, unsigned long pos, LPPOINT lppt);
//	long GetDispValuePoint(double dvalue, unsigned long pos, LPPOINT lppt);
//	long GetDispPointValue(POINT pt, unsigned long* pos, double* dvalue = NULL);
//
//	long GetDispIndexInfo(IndicatorIndexInfoPtr& infoPtr);
//	long GetDispPointInfo(IndicatorPointInfoPtr& infoPtr);
//	virtual long GetDispPointInfoEx(IndicatorPointInfoExPtr& infoPtr);
//
//	virtual void DrawOneRefline(HDC hdc, LPCTSTR lpszText, int nTextLen, int x1, int y1, int x2);
//	virtual void DrawRefline(HDC hdc, RECT rc, double maxvalue, double minvalue, double yscale, int ybase);
//public:
//	void UpdateMmxDispValue();
//
//	virtual void OnIndicatorCalcInfoChanged();
//	virtual void OnIndicatorDispInfoChanged();
//	virtual void OnIndicatorDispInfoExChanged();
//	virtual void OnDispInfoChanged();
//
//	virtual long OnKeyEvent(MsgEventPtr & evtPtr, bool & handled);
//	virtual long OnMouseEvent(MsgEventPtr & evtPtr, bool & handled);
//	virtual long OnCommandEvent(MsgEventPtr & evtPtr, bool & handled);
//	virtual long OnMoveEvent(MsgEventPtr & evtPtr, bool & handled);
//	virtual long OnSizeEvent(MsgEventPtr & evtPtr, bool & handled);
//	virtual long OnEraseBkgndEvent(MsgEventPtr & evtPtr, bool & handled);
//	virtual long OnPaintEvent(MsgEventPtr & evtPtr, bool & handled);
//
//	virtual void EraseBkgnd(HDC hdc);
//	virtual void Paint(HDC hdc);
//
	BEGIN_EVT_MAP(This)
		ON_EVT(EVT_PLAT_CALL,OnCall)
		ON_EVT(EVT_PLAT_NOTIFY,OnNotify)
		CHAIN_EVT_MAP(Base)
	END_EVT_MAP()

	long OnCall(Event& evt);
	long OnNotify(Event& evt);
};

#endif//

#endif//_H_XIndicatorContainer_HPP_

