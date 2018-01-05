#ifndef _H_NETIO_LISTENER_H_
#define _H_NETIO_LISTENER_H_

#include "EvtNetIO.h"

class NetIOHandler;

//�����յ��Ķ��������İ���NetIO���Ҫ���ǲ�������������,�����쳣������������󷵻��쳣��
enum
{
	PARSE_PACKET_FLAG_NONE		= 0,				//δ֪
	//PARSE_PACKET_FLAG_SEND	= 0X00000001,		//���Ͱ�
	PARSE_PACKET_FLAG_RECEIVE	= 0X00000010,		//���հ�
	PARSE_PACKET_FLAG_RESPONSE	= 0X00000020,		//��Ӧ��
	PARSE_PACKET_FLAG_PENDING	= 0x00000040,		//�յ�������ɣ��������м�������������а�Ҫ��
	PARSE_PACKET_FLAG_COMPLETE	= 0x00000080,		//���������������,���Ǳ��������Ӧ������
	PARSE_PACKET_FLAG_CONTINUE	= 0X00000100,		//��Ҫ��������
	PARSE_PACKET_FLAG_ERROR		= 0X00000200,		//���ش���
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
	//�û������̵߳���
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

	//�¼���Ӧ�̵߳���
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
	//�������յ������ݰ�״̬���ο�PARSE_PACKET_FLAG_xxx
	virtual long ParseReceive(const Event& evt);
};

#endif//_H_NETIO_LISTENER_H_