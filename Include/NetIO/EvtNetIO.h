#ifndef _H_NETIOPACKET_H_
#define _H_NETIOPACKET_H_

#include <XLib/XEvent.h>
#include <XLib/XMemory.h>
#include "NetIODef.h"

//#include <boost/shared_ptr.hpp>
//using namespace boost;
#include <string>
using namespace std;

//所有发起的异步事件都有对应通知
//主动发起关闭相关事件，没有通知，被动关闭，有通知
//原因是主动关闭，一般马上会销毁对象，如果后面还有通知的话，就有可能访问非法地址

enum 
{
	EVT_NETIO_FIRST = EVT_MAX,
	EVT_NETIO_LISTEN = EVT_NETIO_FIRST,	//监听连接事件
	EVT_NETIO_LISTENED,					//监听到一个连接到来事件[OnListen]
	//EVT_NETIO_ACCEPT,					//
	EVT_NETIO_CONNECT,					//表示发起建立连接事件
	EVT_NETIO_CONNECTED,				//表示已经连接完成事件,有可能连接失败[OnConnect]
	EVT_NETIO_CLOSE,					//表示关闭连接事件[Disconnect连接事件/Close监听事件]
	EVT_NETIO_CLOSED,					//表示连接已经关闭事件[OnDisconnect]或者监听连接关闭[OnClose]
	EVT_NETIO_CANCEL,					//表示撤销事件
	EVT_NETIO_SEND,						//表示发送数据包事件
	EVT_NETIO_SENDED,					//表示已经发送数据包事件，有可能发送失败[OnSend]
	EVT_NETIO_RECEIVE,					//表示接收到数据包事件，有可能接收失败的回应等[OnReceive]
	EVT_NETIO_STAT,						//表示状态统计事件，比如查询是相关信息，通知相关信息等,同步调用实现
	EVT_NETIO_END
};

//所有请求和回应都在同一个Packet里面

typedef struct tagHostInfo
{
	//地址信息
	CHAR		szHostAddress[256];	//ip or url address
	UINT		nHostPort;			//port
	//网络类型
	int			nSockAf;			//address family : AF_INET
	int			nSockType;			//socket type : SOCK_STREAM
	//代理信息
	PROXYINFO	ProxyInfo;			//proxy info
}HOSTINFO,*PHOSTINFO;

//EVT_NETIO_LISTEN
//请求:
//回应:

//EVT_NETIO_CONNECT
//请求:
//回应:

//EVT_NETIO_CLOSE
//请求:
//回应:

//EVT_NETIO_SEND
//请求:请求流
//回应:结果流

//EVT_NETIO_STAT
//请求:tagNetIOStatInfo|自定义数据[可有可无]
//回应:tagNetIOStatInfo|自定义数据[可有可无]
enum
{
	STAT_NONE					= 0,//无
	
	//STAT_SET_CONNECT_HOSTINFO,	//设置连接主机信息
	STAT_SET_CONNECT_TIMEOUT,		//设置连接超时
	STAT_SET_SEND_TIMEOUT,			//设置发送超时
	STAT_SET_RECEIVE_TIMEOUT,		//设置接收超时

	//STAT_GET_CONNECT_HOSTINFO,	//返回连接主机信息
	STAT_GET_CONNECT_TIMEOUT,		//返回连接超时时间
	STAT_GET_CONNECT_TIME,			//返回连接时间
	STAT_GET_SEND_TIMEOUT,			//返回发送超时时间
	STAT_GET_RECEIVE_TIMEOUT,		//返回接收超时时间
	STAT_GET_HEART_TIME,			//返回心跳报时间

	STAT_IS_HOSTINFO,				//是否主机信息相同

};
typedef struct tagStatInfo
{
	unsigned long Type;
	union
	{
		unsigned long Id;
		unsigned long Time;
		unsigned long TimeOut;
		HOSTINFO HostInfo;
		char Reserved[60];
	};
}STATINFO,*PSTATINFO;

//typedef shared_ptr<string> stringptr;
class NetBuffer : public CBufferT<char,8192>
{
	typedef CBufferT<char,8192> Base;
public:
	NetBuffer() { memset(m_pT, 0, m_nCount); }
	NetBuffer(int nBufferLength) : Base(nBufferLength) { memset(m_pT, 0, m_nCount); }
	NetBuffer(char* pBuffer, int nBufferLength) : Base(pBuffer,nBufferLength) { }
};

class SendBuffer 
	: public NetBuffer
	, public Object
{
public:
	SendBuffer() { }
	SendBuffer(int nBufferLength) : NetBuffer(nBufferLength) { }
	SendBuffer(char* pBuffer, int nBufferLength) : NetBuffer(pBuffer,nBufferLength) { }
};
typedef Handle<SendBuffer> SendBufferPtr;

class NETIO_API Packet : public ObjectExT<Packet>
{
public:
	SendBufferPtr	Send;		//发送包
	NetBuffer	Receive;		//接收包
	//string	Reserved;		//自定义模糊数据,用户不可见数据
	SOCKADDR	Addr;
	int			AddrLen;

	Packet();
	Packet(const SendBufferPtr & InPtr);
	Packet(char* lpInBuf, int nInBufLen);
	Packet(char* lpInBuf, int nInBufLen, char* lpOutBuf, int nOutBufLen);
	virtual ~Packet();

	/*void SetSockAddr(SOCKADDR* pAddr, int AddrLen);
	bool GetSockAddr(SOCKADDR* pAddr, int* pAddrLen);
	SOCKADDR & GetSockAddr();
	int & GetSockAddrLen();*/
};
typedef Handle<Packet> PacketPtr;

#endif//_H_NETIOPACKET_H_
