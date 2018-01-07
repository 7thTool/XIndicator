#ifndef _H_CTPDEF_H_
#define _H_CTPDEF_H_

#include <CTPDataStd.h>

//////////////////////////////////////////////////////////////////////////

#define STRCTPTRADERA	"CTPTrader"
#define STRCTPTRADERW	L"CTPTrader"
#ifdef UNICODE
#define STRCTPTRADER STRCTPTRADERW
#else
#define STRCTPTRADER STRCTPTRADERA
#endif//

enum
{
	//����
	CTP_STAT_DISCONNECT					= 0,
	CTP_STAT_CONNECTING					= 0X00000001,	//������
	CTP_STAT_CONNECT					= 0X00000002,	//����
	//��¼
	CTP_STAT_AUTHENTICATE				= 0X00000004,	//��֤
	CTP_STAT_LOGIN						= 0X00000008,	//��¼
	CTP_STAT_INVESTORINFO				= 0X00000010,	//Ͷ������Ϣ
	CTP_STAT_TRADINGACCOUNT				= 0X00000020,	//�����˻�
	CTP_STAT_TRADINGCODE				= 0X00000040,	//���ױ���
	CTP_STAT_NOTICE						= 0X00000080,	//����֪ͨ
	CTP_STAT_CFMMC						= 0X00000100,	//��֤����ϵͳ���͹�˾�ʽ��˻���Կ	
	CTP_STAT_QRYSETTLEMENTINFOCONFIRM	= 0X00000200,	//��ѯ���㵥ȷ��
	CTP_STAT_QRYSETTLEMENTINFO			= 0X00000400,	//��ѯ���㵥
	CTP_STAT_SETTLEMENTINFOCONFIRM		= 0X00000800,	//���㵥ȷ��
	//���㵥ȷ�ϱ�ʶ��¼�ɹ�
	//��֤
	CTP_STAT_ACCOUNTREGISTER			= 0X00001000,	//����ǩԼ��ϵ
	CTP_STAT_BANK						= 0X00002000,	//ת������
	//��Ʒ
	CTP_STAT_EXCHANGE					= 0X00004000,	//�г��б�
	CTP_STAT_PRODUCT					= 0X00008000,	//��Ʒ�б�
	CTP_STAT_INSTRUMENT					= 0X00010000,	//��Լ�б�
	//����
	CTP_STAT_PARKEDORDER				= 0X00020000,	//Ԥ��
	CTP_STAT_ORDER						= 0X00040000,	//ί�е�
	CTP_STAT_TRADE						= 0X00080000,	//�ɽ���
	CTP_STAT_POSITION					= 0X00100000,	//�ֲ�
	CTP_STAT_POSITIONDETAIL				= 0X00200000,	//�ֲ���ϸ
};

#endif//_H_CTPDEF_H_