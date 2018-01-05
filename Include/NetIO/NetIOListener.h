#ifndef _H_NETIO_LISTENER_H_
#define _H_NETIO_LISTENER_H_

#include "EvtNetIO.h"

class NetIOHandler;

//这里收到的都是完整的包，NetIO里才要考虑不完整包的问题,除非异常，比如网络错误返回异常包
enum
{
	PARSE_PACKET_FLAG_NONE		= 0,				//未知
	//PARSE_PACKET_FLAG_SEND	= 0X00000001,		//发送包
	PARSE_PACKET_FLAG_RECEIVE	= 0X00000010,		//接收包
	PARSE_PACKET_FLAG_RESPONSE	= 0X00000020,		//回应包
	PARSE_PACKET_FLAG_PENDING	= 0x00000040,		//收到完整完成，但是是中间包，本次请求还有包要来
	PARSE_PACKET_FLAG_COMPLETE	= 0x00000080,		//本次请求包已收完,即是本次请求回应的最后包
	PARSE_PACKET_FLAG_CONTINUE	= 0X00000100,		//还要继续请求
	PARSE_PACKET_FLAG_ERROR		= 0X00000200,		//返回错误
};
#define IsPacketOk(f)			((f)&(PARSE_PACKET_FLAG_PENDING|PARSE_PACKET_FLAG_COMPLETE|PARSE_PACKET_FLAG_CONTINUE))
#define IsPacketError(f)		!IsPacketOk(f)
#define IsPacketException(f)	!((f)&(PARSE_PACKET_FLAG_PENDING|PARSE_PACKET_FLAG_COMPLETE|PARSE_PACKET_FLAG_CONTINUE|PARSE_PACKET_FLAG_ERROR))
#define IsPacketPending(f)		((f)&PARSE_PACKET_FLAG_PENDING)
#define IsPacketComplete(f)		((f)&PARSE_PACKET_FLAG_COMPLETE)
#define IsPacketContinue(f)		((f)&PARSE_PACKET_FLAG_CONTINUE)
#define IsLastPacket(f)			(((f)&(PARSE_PACKET_FLAG_COMPLETE|PARSE_PACKET_FLAG_CONTINUE))==PARSE_PACKET_FLAG_COMPLETE)

class NETIO_API NetIOListener : public EvtListener
{
protected:
	NetIOHandler* m_pHandler;
public:
	NetIOListener();
	virtual ~NetIOListener();

public:
	//用户所在线程调用
	virtual bool IsOK();
	virtual long Open(LPCSTR lpszHandlerName
		, LPCSTR lpszHostAddress, UINT nHostPort
		, PPROXYINFO pProxy = NULL, int nSockType = SOCK_STREAM, int nSockAf = AF_INET);
	virtual long Listen();
	virtual long Connect();
	virtual long Close();

	virtual long CancelPacket(PacketPtr& PackPtr);
	virtual long SendPacket(PacketPtr& PackPtr);

	virtual long Stat(PacketPtr& PackPtr);

	//事件响应线程调用
	//Listen
	/*BEGIN_EVT_MAP(This)
		ON_EVT(EVT_NETIO_LISTENED, OnListened)
		ON_EVT(EVT_NETIO_CLOSED, OnClosed)
		ON_EVT(EVT_NETIO_SENDED, OnSended)
		ON_EVT(EVT_NETIO_RECEIVE, OnReceive)
	END_EVT_MAP()*/
	//CONNECT
	/*BEGIN_EVT_MAP(This)
		ON_EVT(EVT_NETIO_CONNECTED, OnConnected)
		ON_EVT(EVT_NETIO_CLOSED, OnDisconnected)
		ON_EVT(EVT_NETIO_SENDED, OnRequested)
		ON_EVT(EVT_NETIO_RECEIVE, OnReponse)
	END_EVT_MAP()*/

protected:
	//解析接收到的数据包状态，参看PARSE_PACKET_FLAG_xxx
	virtual long ParseReceive(const Event& evt);
};

#endif//_H_NETIO_LISTENER_H_