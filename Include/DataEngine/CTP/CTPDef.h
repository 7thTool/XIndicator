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
	//连接
	CTP_STAT_DISCONNECT					= 0,
	CTP_STAT_CONNECTING					= 0X00000001,	//连接中
	CTP_STAT_CONNECT					= 0X00000002,	//连接
	//登录
	CTP_STAT_AUTHENTICATE				= 0X00000004,	//认证
	CTP_STAT_LOGIN						= 0X00000008,	//登录
	CTP_STAT_INVESTORINFO				= 0X00000010,	//投资者信息
	CTP_STAT_TRADINGACCOUNT				= 0X00000020,	//交易账户
	CTP_STAT_TRADINGCODE				= 0X00000040,	//交易编码
	CTP_STAT_NOTICE						= 0X00000080,	//公告通知
	CTP_STAT_CFMMC						= 0X00000100,	//保证金监管系统经纪公司资金账户密钥	
	CTP_STAT_QRYSETTLEMENTINFOCONFIRM	= 0X00000200,	//查询结算单确认
	CTP_STAT_QRYSETTLEMENTINFO			= 0X00000400,	//查询结算单
	CTP_STAT_SETTLEMENTINFOCONFIRM		= 0X00000800,	//结算单确认
	//结算单确认标识登录成功
	//银证
	CTP_STAT_ACCOUNTREGISTER			= 0X00001000,	//银期签约关系
	CTP_STAT_BANK						= 0X00002000,	//转帐银行
	//商品
	CTP_STAT_EXCHANGE					= 0X00004000,	//市场列表
	CTP_STAT_PRODUCT					= 0X00008000,	//产品列表
	CTP_STAT_INSTRUMENT					= 0X00010000,	//合约列表
	//交易
	CTP_STAT_PARKEDORDER				= 0X00020000,	//预埋单
	CTP_STAT_ORDER						= 0X00040000,	//委托单
	CTP_STAT_TRADE						= 0X00080000,	//成交单
	CTP_STAT_POSITION					= 0X00100000,	//持仓
	CTP_STAT_POSITIONDETAIL				= 0X00200000,	//持仓明细
};

#endif//_H_CTPDEF_H_