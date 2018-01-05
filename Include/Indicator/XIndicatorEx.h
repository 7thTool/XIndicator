#ifndef _H_XINDICATOREX_H_
#define _H_XINDICATOREX_H_

#include <DataStd.h>
#include <FaceDef.h>

#include "XIndicator.h"
#include "IndicatorExDef.h"

//#if defined(__cplusplus)
//extern "C" {
//#endif//

	XINDICATOR_API const char* iExchange2String(unsigned char exchange, char* str, int len);
	XINDICATOR_API const wchar_t* iExchange2String(unsigned char exchange, wchar_t* str, int len);
	XINDICATOR_API unsigned char iString2Exchange(const char* str);
	XINDICATOR_API unsigned char iString2Exchange(const wchar_t* str);

	XINDICATOR_API LPCSTR iObject2String(COMREF object, LPSTR str, int len);
	XINDICATOR_API LPCWSTR iObject2String(COMREF object, LPWSTR str, int len);
	XINDICATOR_API COMREF iString2Object(LPCSTR str);
	XINDICATOR_API COMREF iString2Object(LPCWSTR str);

	XINDICATOR_API ENUM_TIMEFRAMES iPeriod2Period(int iPeriod, int* pPeriodEx = NULL);
	XINDICATOR_API int Period2iPeriod(ENUM_TIMEFRAMES Period, int PeriodEx);
	XINDICATOR_API void Period2TimeSpan(ENUM_TIMEFRAMES Period, int PeriodEx
		, unsigned long* Days, unsigned long* Hours, unsigned long* Minutes, unsigned long* Seconds);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	//C/C++�ӿ��ṩ��λ�û�����������˳��
	//�ű��ӿ��ṩ��������λ�ã��������෴����ǰ��������Ϊ0��ǰһ��������Ϊ1���Դ�����
	//������iReverseOffset������ת��
	//

	XINDICATOR_API voidptr iRefData(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	XINDICATOR_API voidptr iRefFieldData(COMREF object);
	XINDICATOR_API voidptr iRefDataEx(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, unsigned long flags);
	XINDICATOR_API void iReqData(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);

	XINDICATOR_API COMREF iObject(voidptr dataptr);

	XINDICATOR_API bool iRefDefault(const wchar_t* name, INDICATORCONTEXTINFO* ctx);

	//����ָ��
	XINDICATOR_API iHandle iRefA(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, LPCSTR name, LPCSTR xml, int xmlflag);
	XINDICATOR_API iHandle iRefW(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, LPCWSTR name, LPCWSTR xml, int xmlflag);
	XINDICATOR_API iHandle iRefA(LPCSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	XINDICATOR_API iHandle iRefW(LPCWSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);

	XINDICATOR_API iHandle iTestA(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, LPCSTR name, LPCSTR xml, int xmlflag);
	XINDICATOR_API iHandle iTestW(COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate, LPCWSTR name, LPCWSTR xml, int xmlflag);
	XINDICATOR_API iHandle iTestA(LPCSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);
	XINDICATOR_API iHandle iTestW(LPCWSTR name, INPUTINFO* input, COMREF object, int period, ENUM_DWTYPE dwtype, unsigned long dwdate);

	XINDICATOR_API iHandle iScript(COMREF		object,			// ����Ʒ��
		int			period,			// ����
		ENUM_DWTYPE	dwtype,			// ����Ȩ���� 
		unsigned long	dwdate,			// �������Ȩ����
		LPCTSTR		name,			// ָ��
		LPCTSTR		xml,			// �������
		int			xmlflag,		// ���������־
		LPCTSTR		scripts,		// �ű�
		LPCTSTR		language		// ����
		);


	XINDICATOR_API void iAddPool(COMREF object, iHandle handle);
	XINDICATOR_API void iRemovePool(COMREF object, iHandle handle);

	//�ڽ�ָ��
	//����ֵ
	//�������⼼��ָ�괦������ʧ�ܷ��� INVALID_HANDLE��

	//������ָ�겢���ش�������ֻ��һ����������
	XINDICATOR_API iHandle  iAC(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate// �������Ȩ����
		);

	//���������ۻ�/����ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iAD(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		INDICATOR_APPLIED_PRICE applied_volume	// ���ڼ���Ľ���������
		);

	//��������ƽ�������ƶ�ָ��ָ�괦������
	XINDICATOR_API iHandle  iADX(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int	adx_period		// ƽ������
		);

	//��������Τ����ƽ�������ƶ�ָ����������
	XINDICATOR_API iHandle  iADXWilder(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate, // �������Ȩ����
		int adx_period		// ƽ������
		);

	//������������ָ�괦������
	XINDICATOR_API iHandle  iAlligator(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate, // �������Ȩ����
		int jaw_period,       // �ʺ��������
		int jaw_shift,        // �ʺ�ƽ��
		int teeth_period,     // ���ݼ�������
		int teeth_shift,      // ����ƽ��
		int lips_period,      // ������������
		int lips_shift,       // ����ƽ��
		INDICATOR_MA_METHOD ma_method,		// ƽ������
		INDICATOR_APPLIED_PRICE applied_price	// �۸���ߴ���������
		);


	//���������ʵ��ƶ�ƽ��ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iAMA(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ama_period,		//  AMAƽ������
		int fast_ma_period,	// ���� MA ����
		int slow_ma_period,	// ���� MA ����
		int ama_shift,		// ָ��ƽ��
		INDICATOR_APPLIED_PRICE applied_price	// �۸���ߴ���������
		);

	//�������ض�����ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iAO(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate// �������Ȩ����
		);

	//��������ƽ����ʵ����ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iATR(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period	// ƽ������ 
		);

	//������������ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iBearsPower(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period	// ƽ������
		);

	//�������ز��ִ�ָ�괦������
	XINDICATOR_API iHandle  iBands(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,	// �������Ȩ����
		int bands_period,		// ƽ���߼�������
		int bands_shift,		// ָ��ƽ��
		double deviation,		// ��׼����
		INDICATOR_APPLIED_PRICE applied_price	// �۸����������
		);

	//��������ţ��ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iBullsPower(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period	// ƽ������
		);

	//��������˳��ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iCCI(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period,			// ƽ������
		INDICATOR_APPLIED_PRICE applied_price	// �۸����������
		);

	//The function returns the handle of the Chaikin Oscillator indicator. It has only one buffer.
	XINDICATOR_API iHandle  iChaikin(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int fast_ma_period,	// ��������
		int slow_ma_period,	// ��������
		INDICATOR_MA_METHOD ma_method,	// ƽ������
		INDICATOR_APPLIED_PRICE applied_volume	// ����������
		);

	//��������˫ָ���ƶ�ƽ����ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iDEMA(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period,         // ƽ������
		int ma_shift,          // ƽ��
		INDICATOR_APPLIED_PRICE applied_price	// �۸���ߴ���������
		);

	//��������DeMarkerָ�괦������ֻ��һ���������� 
	XINDICATOR_API iHandle  iDeMarker(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period		// ƽ������
		);

	//�������ع����ָ�괦������
	XINDICATOR_API iHandle  iEnvelopes(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period,	// ƽ���߼�������
		int ma_shift,		// ָ��ƽ��
		INDICATOR_MA_METHOD ma_method,	// ƽ������
		INDICATOR_APPLIED_PRICE applied_price,	// �۸���ߴ���������
		double deviation	// ���߽߱��(�ٷ���)
		);

	//��������ǿ��ָ��ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iForce(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period,		// ƽ������
		INDICATOR_MA_METHOD ma_method,	// ƽ������
		INDICATOR_APPLIED_PRICE applied_volume	// ����Ľ���������
		);

	//�������ط���ѧָ�괦������
	XINDICATOR_API iHandle  iFractals(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate// �������Ȩ����
		);

	//�������ط���ѧ�ʺ��ƶ�ƽ��ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iFrAMA(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period,		// ƽ������
		int ma_shift,			// ͼ��ƽ��
		INDICATOR_APPLIED_PRICE applied_price	// �۸���ߴ���������
		);

	//����������������ָ�괦������������ʾ����ָ�����ߺͺ��ߣ�������״ͼ���������Լ����ߺ����ߵ������½���״ͼ����
	XINDICATOR_API iHandle  iGator(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int jaw_period,		// �ʺ��������
		int jaw_shift,		// �ʺ�ƽ��
		int teeth_period,		// ���ݼ�������
		int teeth_shift,		// ����ƽ��
		int lips_period,		// ������������
		int lips_shift,		// ����ƽ��
		INDICATOR_MA_METHOD ma_method, // ƽ������
		INDICATOR_APPLIED_PRICE applied_price	// �۸���ߴ���������
		);

	//��������һĿ����ͼָ�괦������
	XINDICATOR_API iHandle  iIchimoku(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int tenkan_sen,	// Tenkan-senת��������
		int kijun_sen,		// Kijun-sen��׼������
		int senkou_span_b	// Senkou Span B����
		);

	//���������г�����ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iBWMFI(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		INDICATOR_APPLIED_PRICE applied_volume	// ����Ľ���������
		);

	//�������ض���ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iMomentum(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int mom_period,	// ƽ������
		INDICATOR_APPLIED_PRICE applied_price	// �۸���ߴ���������
		);

	//���������ʽ�����ָ�괦������
	XINDICATOR_API iHandle  iMFI(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period,			// ƽ������
		INDICATOR_APPLIED_PRICE applied_volume	// ����Ľ���������
		);

	//���������ƶ�ƽ����ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iMA(
		COMREF object,			// ����Ʒ��
		int period,				// ����
		ENUM_DWTYPE dwtype,		// ����Ȩ���� 
		unsigned long dwdate,	// �������Ȩ����
		int ma_period,			// ƽ������
		int ma_shift,			// ƽ��
		INDICATOR_MA_METHOD ma_method, // ƽ������
		INDICATOR_APPLIED_PRICE applied_price // �۸���ߴ����������
		);

	//���������ƶ�ƽ����ָ�괦������OsMA������ʾMACD����ѶϢ��֮�������ֻ��һ����������
	XINDICATOR_API iHandle  iOsMA(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int fast_ema_period,	// �����ƶ�ƽ��������
		int slow_ema_period,	// �����ƶ�ƽ��������
		int signal_period,		// ��ͬ���ƽ������
		INDICATOR_APPLIED_PRICE applied_price // �۸���ߴ�����������
		);

	//���������ƶ�ƽ������/ɢָ�괦��������OsMA����ΪMACD��״ͼ��ϵͳ�У���ָ����ʾΪ�����ߡ��ڿͻ����ƶ�ƽ������/ɢ����״ͼ��
	XINDICATOR_API iHandle  iMACD(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int fast_ema_period,	// �����ƶ�ƽ��������
		int slow_ema_period,	// �����ƶ�ƽ��������
		int signal_period,		// ��ͬ���ƽ������
		INDICATOR_APPLIED_PRICE applied_price // �۸���ߴ�����������
		);

	//��������ƽ�⽻����ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iOBV(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		INDICATOR_APPLIED_PRICE applied_volume // ����Ľ���������
		);

	//������������ת��ϵͳָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iSAR(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		double step,			// ������
		double maximum			// ���ֹ��ˮƽ
		);

	//�����������ǿ��ָ��ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iRSI(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period,			// ƽ������
		INDICATOR_APPLIED_PRICE applied_price // �۸���ߴ���������
		);

	//����������Ի���ָ��ָ�괦������
	XINDICATOR_API iHandle  iRVI(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period			// ƽ������
		);

	//�������ر�׼ƫ��ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iStdDev(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period,		// ƽ������
		int ma_shift,		// ƽ��
		INDICATOR_MA_METHOD ma_method, // ƽ������
		INDICATOR_APPLIED_PRICE applied_price // �۸���ߴ���������
		);

	//������������ڶ�ָ�괦������
	XINDICATOR_API iHandle  iStochastic(
		COMREF object,	// ����Ʒ��
		int period,		// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int Kperiod,         // K������ (���ڼ��������)
		int Dperiod,         // D������ (��ʼƽ������)
		int slowing,         // ����ƽ��
		INDICATOR_MA_METHOD ma_method, // ƽ������
		INDICATOR_STO_PRICE sto_price // ������㷨
		);
#define iKDJ iStochastic

	//������������ָ���ƶ�ƽ��ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iTEMA(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period,         // ƽ������
		int ma_shift,          // ָ��ƽ��
		INDICATOR_APPLIED_PRICE applied_price // �۸���ߴ���������
		);

	//������������ָ���ƶ�ƽ������ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iTriX(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int ma_period,         // ƽ������
		INDICATOR_APPLIED_PRICE applied_price // �۸���ߴ���������
		);

	//������������ָ��ָ�ꡣֻ��һ����������
	XINDICATOR_API iHandle  iWPR(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int calc_period			// ƽ������
		);


	//�������ر���ָ����̬ƽ����ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iVIDyA(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		int cmo_period,		// Chande ����ָ������
		int ema_period,		// EMA ƽ������
		int ma_shift,			// �۸�ͼ��ƽ��
		INDICATOR_APPLIED_PRICE applied_price // �۸���ߴ���������
		);

	//�������ؽ�����ָ�괦������ֻ��һ����������
	XINDICATOR_API iHandle  iVolumes(
		COMREF object,		// ����Ʒ��
		int period,			// ����
		ENUM_DWTYPE dwtype,	// ����Ȩ���� 
		unsigned long dwdate,// �������Ȩ����
		INDICATOR_APPLIED_PRICE applied_volume // ����Ľ���������
		);

	//////////////////////////////////////////////////////////////////////////

	XINDICATOR_API int iObjectSelect(int offset, COMREF* object, int count, iHandle handle);

	XINDICATOR_API int iPoolSelect(int offset, COMREF* object, int count, iHandle handle);

	//////////////////////////////////////////////////////////////////////////
	///�˻�������

	XINDICATOR_API int iUserSelectByObject(COMREF object, BOOL trade);

	XINDICATOR_API int iOrderSendA(COMREF object,int cmd, double volume,double price,int slippage, double stoploss, double takeprofit,
		LPCSTR comment,int magic,unsigned long date,unsigned long time);
	XINDICATOR_API int iOrderSendW(COMREF object,int cmd, double volume,double price,int slippage, double stoploss, double takeprofit,
		LPCWSTR comment,int magic,unsigned long date,unsigned long time);

	XINDICATOR_API COMREF iOrderObject();

//////////////////////////////////////////////////////////////////////////

//�ڽ�����

//#if defined(__cplusplus)
//}

XINDICATOR_API int iIndicatorsTotal();
XINDICATOR_API int iIndicatorGet(int offset, wchar_t* str, int len, INDICATORCONTEXTINFO* ctx = NULL);

XINDICATOR_API voidptr iRefCalcData(COMREF object, int period, ENUM_DWTYPE dwtype = DW_FORWARD, unsigned long dwdate = 0, UINT uFlags = REF_CALCDATA_NONE);
XINDICATOR_API void iRefCalcDataMore(COMREF object, int period, ENUM_DWTYPE dwtype = DW_FORWARD, unsigned long dwdate = 0);
XINDICATOR_API void iReleaseCalcData(voidptr dataptr);

//XINDICATOR_API XIndicator* iRef(iHandle handle);
XINDICATOR_API voidptr iRefCalcData(iHandle handle);

XINDICATOR_API BAR* iRefBar(int offset, voidptr dataptr);

//#endif//

#endif//_H_XINDICATOREX_H_

