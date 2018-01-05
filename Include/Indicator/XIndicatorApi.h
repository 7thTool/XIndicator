#ifndef _H_XINDICATORAPI_H_
#define _H_XINDICATORAPI_H_

#include "XIndicatorDef.h"

//---------------------------------------------------------------------------
// API Export/Import Macros
//---------------------------------------------------------------------------
/** Indicates an exported and imported shared library function. */
#ifdef XINDICATOR_EXPORTS
#define XINDICATOR_API __declspec(dllexport)
#else
#define XINDICATOR_API __declspec(dllimport)
#endif
#ifndef XINDICATOR_EXPORTS
#pragma comment(lib, "XIndicator.lib")
#endif//

#if defined(__cplusplus)
extern "C" {
#endif//

//---------------------------------------------------------------------------
// ��������
// C/C++�ӿ��ṩ��λ�û�����������˳��
// �ű��ӿ��ṩ��������λ�ã��������෴����ǰ��������Ϊ0��ǰһ��������Ϊ1����
// �����ƣ�������iReversePos������ת��
//---------------------------------------------------------------------------

/**
    * @brief ����λ�� 
    * @param[in] pos ����λ��
    * @param[in] count λ������
    * @return ����λ��
    */
int iReversePos(int pos, int count);

/**
    * @brief �����־ 
    * @param[in] level ��־����
    * @param[in] str ��־����
    * @return ��
    */
XINDICATOR_API void iLogA(INDICATOR_LOG_LEVEL level, const char* str);
XINDICATOR_API void iLogW(INDICATOR_LOG_LEVEL level, const wchar_t* str);
#ifndef UNICODE
#define iLog iLogA
#else
#define iLog iLogW
#endif//

/**
    * @brief ��ֵ/��Чֵ�ж� 
    * @param[in] value ��Ҫ�жϵ�ֵ
    * @return ����˵��
    *        -<em>0</em> ���ǿ�ֵ������Чֵ
    *        -<em>��0</em> �ǿ�ֵ/��Чֵ
    */
XINDICATOR_API int iIsEmptyValue(double value);

//---------------------------------------------------------------------------
// ���ݽӿ�
//---------------------------------------------------------------------------

/**
    * @brief iRefData/iRefFieldData/iRefDataEx��������
    * @param[in] symbol ����
	* @param[in] period ����
	* @param[in] flags ���ñ�־
    * @return ����˵��
    *        -<em>0</em> ����ʧ��
    *        -<em>��0</em> �������ݾ��
	* @note �������ݳɹ��󣬱���ʹ��iReleaseData�����ر�
    * @par ʾ��:
    * @code
    *        voidptr dataptr = iRefData("600000.SH", INDICATOR_PERIOD_DAY);
	*		 if(dataptr) {
	*			iReleaseData(dataptr);
	*		 }
    * @endcode
    */
XINDICATOR_API voidptr iRefData(const char* symbol, int period);
XINDICATOR_API voidptr iRefFieldData(const char* symbol);
XINDICATOR_API voidptr iRefDataEx(const char* symbol, int period, unsigned long flags);
/**
    * @brief �������� 
    * @param[in] dataptr ���ݾ��
    * @return ��
    */
XINDICATOR_API void iRequestData(voidptr dataptr);
/**
    * @brief �ͷ����� 
    * @param[in] dataptr ���ݾ��
    * @return ��
    */
XINDICATOR_API void iReleaseData(voidptr dataptr);

/**
    * @brief ��ȡ���� 
    * @param[in] dataptr ���ݾ��
    * @return ����
    */
XINDICATOR_API const char* iSymbol(voidptr dataptr);
/**
    * @brief ��ȡ���� 
    * @param[in] dataptr ���ݾ��
    * @return ����
    */
XINDICATOR_API int iPeriod(voidptr dataptr);
/**
    * @brief ��ȡ�۸�С��λ�� 
    * @param[in] dataptr ���ݾ��
    * @return С��λ��
    */
XINDICATOR_API int iDigits(voidptr dataptr);

/**
    * @brief ��ȡ�����ֶ�ֵ 
    * @param[in] field �ֶ�
    * @param[in] dataptr ���ݾ��
    * @return �ֶ�ֵ
    */
XINDICATOR_API double iField(INDICATOR_FIELD field, voidptr dataptr);

/**
    * @brief ��ȡ���������Ŀ
    * @param[in] dataptr ���ݾ��
    * @return ��Ŀ
    */
XINDICATOR_API int iDataCount(voidptr dataptr);

/**
    * @brief ��ȡ��������/ʱ�� 
    * @param[in] offset ����ƫ��
    * @param[in] dataptr ���ݾ��
    * @return ����/ʱ��
    */
XINDICATOR_API unsigned int iPriceDate(int offset, voidptr dataptr);
XINDICATOR_API unsigned int iPriceTime(int offset, voidptr dataptr);
/**
    * @brief ��ȡ����۸� 
    * @param[in] price �۸�����
    * @param[in] offset ����ƫ��
    * @param[in] dataptr ���ݾ��
    * @return �۸�
    */
XINDICATOR_API double iPrice(INDICATOR_APPLIED_PRICE price, int offset, voidptr dataptr);

/**
    * @brief ��ȡ�������� 
    * @param[in] finance ������������
    * @param[in] offset ����ƫ��
    * @param[in] dataptr ���ݾ��
    * @return ��������ֵ
    */
XINDICATOR_API double iFinance(int finance, int offset, voidptr dataptr);

//---------------------------------------------------------------------------
// ����ָ��
//---------------------------------------------------------------------------

/**
    * @brief iRef/iRefPool����ָ��/����
    * @param[in] symbol ����
	* @param[in] period ����
    * @param[in] name ָ��/������
	* @param[in] xml ָ��/����XML��ʽ����
	* @param[in] xmlflag XML��־
    * @return ָ����
	* @note ����ָ��/���Գɹ��󣬱���ʹ��iRelease�����ͷ�ָ��/����
    * @par ʾ��:
    * @code
    *        iHandle hMA = iRefA("600000.SH", INDICATOR_PERIOD_DAY, "MA", NULL, XML_FLAG_STREAM);
	*		 if(hMA) {
	*			iRelease(hMA);
	*		 }
    * @endcode
    */
XINDICATOR_API iHandle iRefA(const char* symbol, int period, const char* name, const char* xml, int xmlflag);
XINDICATOR_API iHandle iRefW(const char* symbol, int period, const wchar_t* name, const wchar_t* xml, int xmlflag);
XINDICATOR_API iHandle iRefPoolA(const char* name, const char* xml, int xmlflag);
XINDICATOR_API iHandle iRefPoolW(const wchar_t* name, const wchar_t* xml, int xmlflag);
#ifndef UNICODE
#define iRef iRefA
#define iRefPool iRefPoolA
#else
#define iRef iRefW
#define iRefPool iRefPoolW
#endif//
XINDICATOR_API void iRelease(iHandle h);

/**
    * @brief iTest/iTestPool����ָ��/����
    * @param[in] symbol ����
	* @param[in] period ����
    * @param[in] name ָ��/������
	* @param[in] xml ָ��/����XML��ʽ����
	* @param[in] xmlflag XML��־
    * @return ָ����
	* @note ����ָ��/���Գɹ��󣬱���ʹ��iRelease�����ͷ�ָ��/����
    * @par ʾ��:
    * @code
    *        iHandle hMA = iTestA("600000.SH", INDICATOR_PERIOD_DAY, "MA", NULL, XML_FLAG_STREAM);
	*		 if(hMA) {
	*			iRelease(hMA);
	*		 }
    * @endcode
    */
XINDICATOR_API iHandle iTestA(const char* symbol, int period, const char* name, const char* xml, int xmlflag);
XINDICATOR_API iHandle iTestW(const char* symbol, int period, const wchar_t* name, const wchar_t* xml, int xmlflag);
XINDICATOR_API iHandle iTestPoolA(const char* name, const char* xml, int xmlflag);
XINDICATOR_API iHandle iTestPoolW(const wchar_t* name, const wchar_t* xml, int xmlflag);
#ifndef UNICODE
#define iTest iTestA
#define iTestPool iTestPoolA
#else
#define iTest iTestW
#define iTestPool iTestPoolW
#endif//

//XINDICATOR_API LPCTSTR iGetName(iHandle handle);
/**
    * @brief ��ȡָ������ 
    * @param[in] handle ָ����
    * @return ָ������
    */
XINDICATOR_API long iGetType(iHandle handle);
/**
    * @brief ��ȡָ���� 
    * @param[in] handle ָ����
    * @return ָ����
    */
XINDICATOR_API long iGetStyle(iHandle handle);
/**
    * @brief ��ȡָ���������ֵ
    * @param[in] name ������
    * @param[out] str ���ղ���ֵ����
    * @param[out] len ���ղ���ֵ���鳤��
    * @param[in] handle ָ����
    * @return ����ֵ
    */
XINDICATOR_API const char* iGetInputA(const char* name, char* str, int len, iHandle handle);
XINDICATOR_API const wchar_t* iGetInputW(const wchar_t* name, wchar_t* str, int len, iHandle handle);
/**
    * @brief ��ȡָ���������ֵ 
    * @param[in] name ������
    * @param[in] handle ָ����
    * @return ����ֵ
    */
XINDICATOR_API double iGetInputValueA(const char* name, iHandle handle);
XINDICATOR_API double iGetInputValueW(const wchar_t* name, iHandle handle);
#ifndef UNICODE
#define iGetInput iGetInputA
#define iGetInputValue iGetInputValueA
#else
#define iGetInput iGetInputW
#define iGetInputValue iGetInputValueW
#endif//

/**
    * @brief ��ȡָ������Ŀ
    * @param[in] handle ָ����
    * @return ָ������
    */
XINDICATOR_API long iGetIndexCount(iHandle handle);
/**
    * @brief ��ȡָ��������
    * @param[in] index ָ��������
    * @param[out] str ����ָ������������
    * @param[out] len ����ָ�����������鳤��
    * @param[in] handle ָ����
    * @return ָ��������
    */
XINDICATOR_API const char* iGetIndexNameA(int index, char* str, int len, iHandle handle);
XINDICATOR_API const wchar_t* iGetIndexNameW(int index, wchar_t* str, int len, iHandle handle);
#ifndef UNICODE
#define iGetIndexName iGetIndexNameA
#else
#define iGetIndexName iGetIndexNameW
#endif//
/**
    * @brief ��ȡָ���߷��
    * @param[in] index ָ��������
    * @param[in] handle ָ����
    * @return ָ���߷��
    */
XINDICATOR_API long iGetIndexStyle(int index, iHandle handle);
/**
    * @brief ��ȡָ����С��λ��
    * @param[in] index ָ��������
    * @param[in] handle ָ����
    * @return ָ����С��λ��
    */
XINDICATOR_API long iGetIndexDigits(int index, iHandle handle);
/**
    * @brief ��ȡָ����ƫ��
    * @param[in] index ָ��������
    * @param[in] handle ָ����
    * @return ָ����ƫ��
    */
XINDICATOR_API long iGetIndexShift(int index, iHandle handle);
/**
    * @brief ��ȡָ���߻��ƿ�ʼλ��
    * @param[in] index ָ��������
    * @param[in] handle ָ����
    * @return ָ���߻��ƿ�ʼλ��
    */
XINDICATOR_API long iGetIndexDrawBegin(int index, iHandle handle);
/**
    * @brief ��ȡָ���߻��Ʒ�ʽ
    * @param[in] index ָ��������
    * @param[in] handle ָ����
    * @return ָ���߻��Ʒ�ʽ
    */
XINDICATOR_API long iGetIndexDraw(int index, iHandle handle);
/**
    * @brief ��ȡָ��������
    * @param[in] index ָ��������
    * @param[in] handle ָ����
    * @return ָ��������
    */
XINDICATOR_API long iGetIndexLine(int index, iHandle handle);
/**
    * @brief ��ȡָ���߹���ָ����
    * @param[in] index ָ��������
    * @param[in] handle ָ����
    * @return ָ���߹���ָ����
    */
XINDICATOR_API long iGetIndexNext(int index, iHandle handle);
/**
    * @brief ��ȡָ���߿��
    * @param[in] index ָ��������
    * @param[in] handle ָ����
    * @return ָ���߿��
    */
XINDICATOR_API long iGetIndexWidth(int index, iHandle handle);
/**
    * @brief ��ȡָ������ɫ
    * @param[in] index ָ��������
    * @param[in] handle ָ����
    * @return ָ������ɫ
    */
XINDICATOR_API COLORREF iGetIndexColor(int index, iHandle handle);

/**
    * @brief ��ȡָ��������Ŀ
    * @param[in] handle ָ����
    * @return ָ��������Ŀ
    */
XINDICATOR_API long iGetPriceCount(iHandle handle);
/**
    * @brief ��ȡָ����������/ʱ��
    * @param[in] offset ����ƫ��
    * @param[in] handle ָ����
    * @return ָ����������/ʱ��
    */
XINDICATOR_API unsigned long iGetPriceDate(int offset, iHandle handle);
XINDICATOR_API unsigned long iGetPriceTime(int offset, iHandle handle);
/**
    * @brief ��ȡָ������ֵ
    * @param[in] index/line ָ��������
    * @param[in] offset ����ƫ��
    * @param[in] handle ָ����
    * @return ָ������ֵ
    */
XINDICATOR_API double iGetIndexValue(int index, int offset, iHandle handle);
XINDICATOR_API double iGetLineValue(int line , int offset, iHandle handle);
/**
    * @brief ��ȡָ��۸�
    * @param[in] price �۸�����
    * @param[in] offset ����ƫ��
    * @param[in] handle ָ����
    * @return �۸�ֵ
    */
XINDICATOR_API double iGetPriceValue(int price, int offset, iHandle handle);
#define iGetVolumeValue(offset,handle) iGetPriceValue(PRICE_VOLUME,offset,handle)
#define iGetAmountValue(offset,handle) iGetPriceValue(PRICE_AMOUNT,offset,handle)
/**
    * @brief ��ȡָ���������
    * @param[in] field �����ֶ�
    * @param[in] offset ����ƫ��
    * @param[in] handle ָ����
    * @return �۸�ֵ
    */
XINDICATOR_API double iGetFinanceValue(int finance, int offset, iHandle handle);
/**
    * @brief ��ȡָ������ֶ�ֵ
    * @param[in] field �ֶ�����
    * @param[in] handle ָ����
    * @return �ֶ�ֵ
    */
XINDICATOR_API double iGetFieldValue(INDICATOR_FIELD field, iHandle handle);
/**
    * @brief ��ȡָ��mmxֵ
    * @param[in] mmx mmx����
    * @param[in] handle ָ����
    * @return mmxֵ
    */
XINDICATOR_API long iGetMmxOffset(int index, int mmx, iHandle handle);
XINDICATOR_API double iGetMmxValue(int index, int mmx, iHandle handle);

/**
    * @brief ��ȡ���Գؼ����Ʒ����
    * @param[in] handle ָ����
    * @return ��Ʒ����
    */
XINDICATOR_API int iPoolsTotal(iHandle handle);
/**
    * @brief ��ȡ���Գؼ����Ʒ
    * @param[in] offset ��Ʒ����
    * @param[in] str ������Ʒ��������
    * @param[in] len ������Ʒ�������鳤��
    * @param[in] handle ָ����
    * @return ����˵��
    *        -<em>0</em> ʧ��
    *        -<em>��0</em> �ɹ�
    */
XINDICATOR_API int iPoolSelect(int offset, char* str, int len, iHandle handle);

/**
    * @brief �ж�ָ���ǲ��ǽ���ָ��/����
    * @param[in] handle ָ����
    * @return ����˵��
    *        -<em>0</em> ����
    *        -<em>��0</em> ��
    */
XINDICATOR_API int iIsTrade(iHandle handle);
/**
    * @brief �ж�ָ���Ƿ���Խ���
    * @param[in] handle ָ����
    * @return ����˵��
    *        -<em>0</em> ������
    *        -<em>��0</em> ����
    */
XINDICATOR_API int iIsTradeable(iHandle handle);
/**
    * @brief �ж�ָ���Ƿ�����
    * @param[in] handle ָ����
    * @return ����˵��
    *        -<em>0</em> û��
    *        -<em>��0</em> ����
    */
XINDICATOR_API int iIsCalculate(iHandle handle);


/**
    * @brief ����ָ�귴��ƫ��
    * @param[in] offset ����ƫ��
    * @param[in] handle ָ����
    * @return ����ƫ��
    */
XINDICATOR_API int iReverseOffset(int offset, iHandle handle);
/**
    * @brief ����ָ���Ƿ�Խ
    * @param[in] src ָ��������
    * @param[in] dst ָ��������
    * @param[in] offset �жϴ�Խλ�ã����ж�src��offsetλ���Ƿ�Խ��dst
    * @param[in] handle ָ����
    * @return ����˵��
    *        -<em>С��0</em> ���´�Խ
    *        -<em>0</em> û��
    *        -<em>����0</em> ���ϴ�Խ
    */
XINDICATOR_API int iIsCross(int src, int dst, int offset, iHandle handle);


//---------------------------------------------------------------------------
// ���뺯��
//---------------------------------------------------------------------------

/**
    * @brief �������
    * @param[in] key �ؼ���
    * @param[in] flags ��־
    * @param[in] handle ָ����
    * @return ��������
    */
XINDICATOR_API int iObjectsFindA(const char* key, unsigned long flags, iHandle handle);
XINDICATOR_API int iObjectsFindW(const wchar_t* key, unsigned long flags, iHandle handle);
#ifdef UNICODE
#define iObjectsFind iObjectsFindW
#else
#define iObjectsFind iObjectsFindA
#endif//
/**
    * @brief ��������
    * @param[in] market �г�
    * @param[in] handle ָ����
    * @return ��������
    */
XINDICATOR_API int iObjectsTotalA(const char* market, iHandle handle);
XINDICATOR_API int iObjectsTotalW(const wchar_t* market, iHandle handle);
#ifdef UNICODE
#define iObjectsTotal iObjectsTotalW
#else
#define iObjectsTotal iObjectsTotalA
#endif//
/**
    * @brief ��ȡ����
    * @param[in] offset ��������
    * @param[out] str ����ָ������������
    * @param[out] len ����ָ�����������鳤��
    * @param[in] handle ָ����
    * @return ����
    */
XINDICATOR_API const char* iObjectSelect(int offset, char* str, int len, iHandle handle);


//---------------------------------------------------------------------------
// �˻�������
//---------------------------------------------------------------------------

/**
    * @brief �û�����
    * @return �û�����
    */
XINDICATOR_API int iUsersTotal();
/**
    * @brief ѡ���û�ByIndex/ByName
    * @return ����˵��
    *        -<em>С��0</em> ʧ��
    *        -<em>���ڵ���0</em> �ɹ���ֵΪ����
    */
XINDICATOR_API int iUserSelectByIndex(int index);
XINDICATOR_API int iUserSelectByNameA(const char* name);
XINDICATOR_API int iUserSelectByNameW(const wchar_t* name);
#ifdef UNICODE
#define iUserSelectByName iUserSelectByNameW
#else
#define iUserSelectByName iUserSelectByNameA
#endif//
/**
    * @brief ѡ��֧��ָ�����뽻���˻�
    * @param[in] symbol ����
    * @return ����˵��
    *        -<em>С��0</em> ʧ��
    *        -<em>���ڵ���0</em> �ɹ���ֵΪ����
    */
XINDICATOR_API int iUserSelectBySymbol(const char* symbol);

/**
    * @brief ��ȡ�û��������
    * @param[in] field ������
    * @return ��������ֵ
    */
XINDICATOR_API double iUserFieldValueA(const char* field);
XINDICATOR_API double iUserFieldValueW(const wchar_t* field);
/**
    * @brief ��ȡ�û��������
    * @param[in] field ������
    * @param[out] str ����ָ������������
    * @param[out] len ����ָ�����������鳤��
    * @return ��������ֵ
    */
XINDICATOR_API const char* iUserFieldStringA(const char* field, char* str, int len);
XINDICATOR_API const wchar_t* iUserFieldStringW(const wchar_t* field, wchar_t* str, int len);
#ifdef UNICODE
#define iUserFieldValue iUserFieldValueW
#define iUserFieldString iUserFieldStringW
#else
#define iUserFielValued iUserFieldValueA
#define iUserFieldString iUserFieldStringA
#endif//
/**
    * @brief ��ȡ�û���
    * @param[out] str ����ָ������������
    * @param[out] len ����ָ�����������鳤��
    * @return �����û���
    */
XINDICATOR_API const char* iUserAccountA(char* str, int len);
XINDICATOR_API const wchar_t* iUserAccountW(wchar_t* str, int len);
/**
    * @brief ��ȡ�˻����ҷ���
    * @param[out] str ����ָ������������
    * @param[out] len ����ָ�����������鳤��
    * @return �����˻����ҷ���
    */
XINDICATOR_API const char* iUserMoneySymbolA(char* str, int len);
XINDICATOR_API const wchar_t* iUserMoneySymbolW(wchar_t* str, int len);
#ifdef UNICODE
#define iUserAccount iUserAccountA
#define iUserMoneySymbol iUserMoneySymbolA
#else
#define iUserAccount iUserAccountW
#define iUserMoneySymbol iUserMoneySymbolW
#endif//
/**
    * @brief ��ȡ�˻����ʽ�
    * @return �����˻����ʽ�
    */
XINDICATOR_API double iUserMoneyTotal();
/**
    * @brief ��ȡ�˻������ʽ�
    * @return �����˻������ʽ�
    */
XINDICATOR_API double iUserMoneyAvailable();
/**
    * @brief ��ȡ�˻������ʽ�
    * @return �����˻������ʽ�
    */
XINDICATOR_API double iUserMoneyFreeze();
/**
    * @brief ��ȡ�˻���ȡ�ʽ�
    * @return �����˻���ȡ�ʽ�
    */
XINDICATOR_API double iUserMoneyFree();
/**
    * @brief ��ȡ�˻�ת���ʽ�
    * @return �����˻�ת���ʽ�
    */
XINDICATOR_API double iUserMoneyIn();
/**
    * @brief ��ȡ�˻�ת���ʽ�
    * @return �����˻�ת���ʽ�
    */
XINDICATOR_API double iUserMoneyOut();

//---------------------------------------------------------------------------
// ���׺���
//---------------------------------------------------------------------------

/**
    * @brief ����ί�ж���
    * @param[in] symbol ����
	* @param[in] cmd ί�ж���ָ��
	* @param[in] volume ί�ж�����
	* @param[in] price ί�ж�����
	* @param[in] slippage ί�ж�����������
	* @param[in] stoploss ί�ж���ֹ���
	* @param[in] takeprofit ί�ж���ֹӯ��
	* @param[in] comment ί�ж���ע��˵��
	* @param[in] magic ί�ж���ħ����
	* @param[in] date ί�ж�������
	* @param[in] time ί�ж���ʱ��
    * @return ����˵��
    *        -<em>С��0</em> ʧ��
    *        -<em>���ڵ���0</em> ����ί�ж�������ɹ�
    * @par ʾ��:
    * @code
    *        iOrderSendA("600000.SH", OP_BUY, 100, 12.67, 1, 0, 0, "", 0, 0, 0);
    * @endcode
    */
XINDICATOR_API int iOrderSendA(const char* symbol,int cmd, double volume,double price,int slippage, double stoploss, double takeprofit,
							   const char* comment,int magic,unsigned long date,unsigned long time);
XINDICATOR_API int iOrderSendW(const char* symbol,int cmd, double volume,double price,int slippage, double stoploss, double takeprofit,
							   const wchar_t* comment,int magic,unsigned long date,unsigned long time);
//XINDICATOR_API int OrderBuy();
//XINDICATOR_API int OrderSell();
//XINDICATOR_API int OrderBuyShort();
//XINDICATOR_API int OrderSellShort();
#ifdef UNICODE
#define iOrderSend iOrderSendW
#else
#define iOrderSend iOrderSendA
#endif//

/**
    * @brief ѡ�񶩵��б�����
    * @return ���ض����б�����
    */
XINDICATOR_API int iOrdersSelect(int pool);
/**
    * @brief ��ȡ��������
    * @return ���ض�������
    */
XINDICATOR_API int iOrdersTotal();
/**
    * @brief ѡ�񶩵�ByIndex/ByTicket/ByMagic
    * @param[in] index ��������
    * @param[in] ticket �������
    * @param[in] magic ����ħ����
    * @return ���ض�������
    */
XINDICATOR_API int iOrderSelectByIndex(int index);
XINDICATOR_API int iOrderSelectByTicketA(const char* ticket);
XINDICATOR_API int iOrderSelectByTicketW(const wchar_t* ticket);
#ifdef UNICODE
#define iOrderSelectByTicket iOrderSelectByTicketW
#else
#define iOrderSelectByTicket iOrderSelectByTicketA
#endif//
XINDICATOR_API int iOrderSelectByMagic(int magic);

/**
    * @brief ��ȡ��������
    * @return ���ض�������
    */
XINDICATOR_API int iOrderType();
/**
    * @brief ��ȡ�������
    * @param[out] str ���ն����������
    * @param[out] len ���ն���������鳤��
    * @return ���ض������
    */
XINDICATOR_API const char* iOrderTicket(char* str, int len);

/**
    * @brief ƽ��
    * @param[in] lots ƽ������
    * @param[in] price ƽ�ּ۸�
    * @param[in] slippage ��������
    * @return ����˵��
    *        -<em>С��0</em> ʧ��
    *        -<em>���ڵ���0</em> ����ƽ������ɹ�
    */
XINDICATOR_API int iOrderClose(double lots, double price, int slippage);
/**
    * @brief ƽ�ֲ����򿪲�
    * @param[in] opposite �Ƿ��򿪲�
    * @return ����˵��
    *        -<em>С��0</em> ʧ��
    *        -<em>���ڵ���0</em> ����ƽ�ֲ����򿪲�����ɹ�
    */
XINDICATOR_API int iOrderCloseBy(int opposite);
/**
    * @brief ɾ������
    * @return ����˵��
    *        -<em>С��0</em> ʧ��
    *        -<em>���ڵ���0</em> ����ɾ����������ɹ�
    */
XINDICATOR_API int iOrderDelete();
/**
    * @brief �޸Ķ���
    * @param[in] price �޸�ί�п��ּ۸�
    * @param[in] stoploss �޸�ֹ��۸�
    * @param[in] takeprofit �޸�ֹӯ�۸�
    * @param[in] expiration �޸ĳ�ʱʱ��
    * @return ����˵��
    *        -<em>С��0</em> ʧ��
    *        -<em>���ڵ���0</em> �����޸Ķ�������ɹ�
    */
XINDICATOR_API int iOrderModify(double price,double stoploss,double takeprofit,unsigned long expiration);

/**
    * @brief ��ȡ������Ĵ���
    * @param[out] str ���ն�����Ĵ�������
    * @param[out] len ���ն�����Ĵ������鳤��
    * @return ���ض�����Ĵ���
    */
XINDICATOR_API const char* iOrderSymbol(char* str, int len);

/**
    * @brief ��ȡ�������ּ۸�
    * @return ���ض������ּ۸�
    */
XINDICATOR_API double iOrderOpenPrice();
/**
    * @brief ��ȡ����ƽ�ּ۸�
    * @return ���ض���ƽ�ּ۸�
    */
XINDICATOR_API double iOrderClosePrice();

/**
    * @brief ��ȡ��������ʱ��
    * @param[out] date ���ն������������ֶ�
    * @return ���ض�������ʱ��
    */
XINDICATOR_API unsigned long iOrderOpenTime(unsigned long* date);
/**
    * @brief ��ȡ����ƽ��ʱ��
    * @param[out] date ���ն���ƽ�������ֶ�
    * @return ���ض���ƽ��ʱ��
    */
XINDICATOR_API unsigned long iOrderCloseTime(unsigned long* date);
/**
    * @brief ��ȡ������ʱʱ��
    * @param[out] date ���ն�����ʱ�����ֶ�
    * @return ���ض�����ʱʱ��
    */
XINDICATOR_API unsigned long iOrderExpiration(unsigned long* date);

/**
    * @brief ��ȡ�����ֱ���
    * @return ���ض����ֱ���
    */
XINDICATOR_API double iOrderLots();
/**
    * @brief ��ȡ��������
    * @return ���ض�������
    */
XINDICATOR_API double iOrderProfit();
/**
    * @brief ��ȡ����ֹӯ��
    * @return ���ض���ֹӯ��
    */
XINDICATOR_API double iOrderTakeProfit();
/**
    * @brief ��ȡ����ֹ���
    * @return ���ض���ֹ���
    */
XINDICATOR_API double iOrderStopLoss();
/**
    * @brief ��ȡ����Ӷ��
    * @return ���ض���Ӷ��
    */
XINDICATOR_API double iOrderCommission();
/**
    * @brief ��ȡ����ħ����
    * @return ���ض���ħ����
    */
XINDICATOR_API int iOrderMagicNumber();
/**
    * @brief ��ȡ����ע��
    * @param[out] str ���ն���ע������
    * @param[out] len ���ն���ע�����鳤��
    * @return ���ض���ע��
    */
XINDICATOR_API const char* iOrderComment(char* str, int len);

/**
    * @brief ��ȡ���������ֶ�
    * @param[out] str ���ն��������ֶ�����
    * @param[out] len ���ն��������ֶ����鳤��
    * @return ���ض��������ֶ�
    */
XINDICATOR_API const char* iOrderFieldString(const char* field, char* str, int len);

#if defined(__cplusplus)
}

class XINDICATOR_API XIndicatorSpi
{
public:
	//Global
	virtual void OnLog(INDICATOR_LOG_LEVEL level, const char* str) {}

	virtual void OnInit() {}
	virtual void OnTerm() {}

	//Data
	virtual void OnUpdateHisData(const char* symbol) {}
	virtual void OnUpdateFinanceData(const char* symbol) {}
	virtual void OnUpdateFieldData(const char* symbol) {}
	virtual void OnUpdateOrderData() {}
	
	//Calc
	virtual void OnTest(iHandle handle) {}
	virtual void OnCalc(iHandle handle) {}
};

class XINDICATOR_API XIndicatorQuoteProvider
{
public:
	//Symbol
	virtual int OnSymbolsFind(const char* key, unsigned int flags) { return 0; }
	virtual int OnSymbolsTotal(const char* market) { return 0; }
	virtual const char* OnSymbolSelect(int index, char* str, int len) { return str; }

	//Calc Data
	virtual voidptr OnRefCalcData(const char* symbol, int period, unsigned int flags = REF_CALCDATA_DEFAULT) { return 0; }
	virtual void OnReleaseCalcData(voidptr dataptr) {}
	virtual const char* OnGetSymbol(voidptr dataptr, char* str, int len) { return str; }
	virtual int OnGetPeriod(voidptr dataptr) { return 0; }
	virtual int OnGetPriceCount(voidptr dataptr) { return 0; }
	virtual unsigned int OnGetPriceDate(voidptr dataptr, int offset) { return 0; }
	virtual unsigned int OnGetPriceTime(voidptr dataptr, int offset) { return 0; }
	virtual double OnGetPriceValue(voidptr dataptr, int price, int offset) { return 0.; }
	virtual double OnGetFinanceValue(voidptr dataptr, int finance, int offset) { return 0.; }
	virtual double OnGetFieldValue(voidptr dataptr, INDICATOR_FIELD field) { return 0.; }
};

class XINDICATOR_API XIndicatorTradeProvider
{
public:
	//User
	virtual int OnUsersTotal() { return 0; }
	virtual int OnUserSelectReset() { return -1; }
	virtual int OnUserSelectByIndex(int index) { return -1; }
	virtual int OnUserSelectByName(const char* name) { return -1; }
	virtual int OnUserSelectByObject(const char* symbol) { return -1; }
	virtual double OnGetUserFieldValue(const char* field) { return 0.; }
	virtual const char* OnGetUserFieldString(const char* field, char* str, int len) { return str; }

	//Trade
	virtual int OnOrderSend(const char* symbol, int cmd, double volume, double price
		, int slippage, double stoploss, double takeprofit
		, const char* comment, int magic) { return -1; }
	virtual int OnOrdersSelect(int pool) { return -1; }
	virtual int OnOrdersTotal() { return 0; }
	virtual int OnOrderSelectReset() { return -1; }
	virtual int OnOrderSelectByIndex(int index) { return -1; }
	virtual int OnOrderSelectByTicket(const char* ticket) { return -1; }
	virtual int OnOrderSelectByMagic(int magic) { return -1; }

	virtual int OnOrderClose(double lots, double price, int slippage) { return -1; }
	virtual int OnOrderCloseBy(int opposite) { return -1; }
	virtual int OnOrderDelete() { return -1; }
	virtual int OnOrderModify(double price,double stoploss,double takeprofit,unsigned long expiration) { return -1; }

	virtual double OnGetOrderFieldValue(const char* field) { return 0.; }
	virtual const char* OnGetOrderFieldString(const char* field, char* str, int len) { return str; }

	virtual int OnGetOrderType() { return OP_NONE; }
	virtual const char* OnGetOrderTicket(char* str, int len) { return str; }

	virtual const char* OnGetOrderSymbol(char* str, int len) { return str; }

	virtual double OnGetOrderOpenPrice() { return EMPTY_VALUE; }
	virtual double OnGetOrderClosePrice() { return EMPTY_VALUE; }

	virtual unsigned int OnGetOrderOpenTime(unsigned long* date) { return 0; }
	virtual unsigned int OnGetOrderCloseTime(unsigned long* date) { return 0; }
	virtual unsigned int OnGetOrderExpiration(unsigned long* date) { return 0; }

	virtual double OnGetOrderLots() { return 0.; }
	virtual double OnGetOrderProfit() { return 0.; }
	virtual double OnGetOrderTakeProfit() { return 0.; }
	virtual double OnGetOrderStopLoss() { return 0.; }
	virtual double OnGetOrderCommission() { return 0.; }
	virtual int OnGetOrderMagicNumber() { return 0; }
	virtual const char* OnGetOrderComment(char* str, int len) { return str; }
};

class XINDICATOR_API XIndicatorApi
{
public:
	static XIndicatorApi* GetInstance();
	static XIndicatorApi* GetInstanceA(const char* workdir, const char* datadir);
	static XIndicatorApi* GetInstanceW(const wchar_t* workdir, const wchar_t* datadir);
	static void ReleaseInstance();

public:
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	//virtual void Init() = 0;
	//virtual void Term() = 0;

	/**
    * @brief ע��ص��ӿ�
    * @param[in] pSpi �����Իص��ӿ����ʵ��
    * @return ��
    */
	virtual void RegisterSpi(XIndicatorSpi *pSpi) = 0;
	/**
    * @brief ע������ص��ӿ�
    * @param[in] pProvider ����������ص��ӿ����ʵ��
    * @return ��
    */
	virtual void RegisterQuoteProvider(XIndicatorQuoteProvider *pProvider) = 0;
	/**
    * @brief ע�ύ�׻ص��ӿ�
    * @param[in] pProvider �����Խ��׻ص��ӿ����ʵ��
    * @return ��
    */
	virtual void RegisterTradeProvider(XIndicatorTradeProvider *pProvider) = 0;

	/**
    * @brief ����ӿڣ���Ҫ�ӿ�ʹ���߲�ͣ���ã�����ָ��ϵͳ������������
    * @return ��
    */
	virtual void Handle() = 0;

	/**
    * @brief ������ʷ���ݽӿڣ�
	*
	* ����ӿ�ʹ�����Լ��ṩ�������ݣ���RegisterQuoteProvider�ˣ�����Ҫÿ����ʷ���ݱ仯ʱ���ô˽ӿ�
    * @return ��
    */
	virtual void UpdateHisData(const char* symbol) = 0;

	/**
    * @brief ���²������ݽӿڣ�
	*
	* ����ӿ�ʹ�����Լ��ṩ�������ݣ���RegisterQuoteProvider�ˣ�����Ҫÿ�β������ݱ仯ʱ���ô˽ӿ�
    * @return ��
    */
	virtual void UpdateFinanceData(const char* symbol) = 0;

	/**
    * @brief ����ʵʱ�������ݽӿڣ�
	*
	* ����ӿ�ʹ�����Լ��ṩ�������ݣ���RegisterQuoteProvider�ˣ�����Ҫÿ��ʵʱ�������ݱ仯ʱ���ô˽ӿ�
    * @return ��
    */
	virtual void UpdateFieldData(const char* symbol) = 0;

	/**
    * @brief ���½������ݽӿڣ�
	*
	* ����ӿ�ʹ�����Լ��ṩ���׽ӿں����ݣ���RegisterTradeProvider�ˣ�����Ҫÿ�ν������ݱ仯ʱ���ô˽ӿ�
    * @return ��
    */
	virtual void UpdateOrderData() = 0;

protected:
	virtual ~XIndicatorApi() {};
};

#endif//

#endif//_H_XINDICATORAPI_H_
