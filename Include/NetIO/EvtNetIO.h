#ifndef _H_NETIOPACKET_H_
#define _H_NETIOPACKET_H_

#include <XLib/XEvent.h>
#include <XLib/XMemory.h>
#include "NetIODef.h"

//#include <boost/shared_ptr.hpp>
//using namespace boost;
#include <string>
using namespace std;

//���з�����첽�¼����ж�Ӧ֪ͨ
//��������ر�����¼���û��֪ͨ�������رգ���֪ͨ
//ԭ���������رգ�һ�����ϻ����ٶ���������滹��֪ͨ�Ļ������п��ܷ��ʷǷ���ַ

enum 
{
	EVT_NETIO_FIRST = EVT_MAX,
	EVT_NETIO_LISTEN = EVT_NETIO_FIRST,	//���������¼�
	EVT_NETIO_LISTENED,					//������һ�����ӵ����¼�[OnListen]
	//EVT_NETIO_ACCEPT,					//
	EVT_NETIO_CONNECT,					//��ʾ�����������¼�
	EVT_NETIO_CONNECTED,				//��ʾ�Ѿ���������¼�,�п�������ʧ��[OnConnect]
	EVT_NETIO_CLOSE,					//��ʾ�ر������¼�[Disconnect�����¼�/Close�����¼�]
	EVT_NETIO_CLOSED,					//��ʾ�����Ѿ��ر��¼�[OnDisconnect]���߼������ӹر�[OnClose]
	EVT_NETIO_CANCEL,					//��ʾ�����¼�
	EVT_NETIO_SEND,						//��ʾ�������ݰ��¼�
	EVT_NETIO_SENDED,					//��ʾ�Ѿ��������ݰ��¼����п��ܷ���ʧ��[OnSend]
	EVT_NETIO_RECEIVE,					//��ʾ���յ����ݰ��¼����п��ܽ���ʧ�ܵĻ�Ӧ��[OnReceive]
	EVT_NETIO_STAT,						//��ʾ״̬ͳ���¼��������ѯ�������Ϣ��֪ͨ�����Ϣ��,ͬ������ʵ��
	EVT_NETIO_END
};

//��������ͻ�Ӧ����ͬһ��Packet����

typedef struct tagHostInfo
{
	//��ַ��Ϣ
	CHAR		szHostAddress[256];	//ip or url address
	UINT		nHostPort;			//port
	//��������
	int			nSockAf;			//address family : AF_INET
	int			nSockType;			//socket type : SOCK_STREAM
	//������Ϣ
	PROXYINFO	ProxyInfo;			//proxy info
}HOSTINFO,*PHOSTINFO;

//EVT_NETIO_LISTEN
//����:
//��Ӧ:

//EVT_NETIO_CONNECT
//����:
//��Ӧ:

//EVT_NETIO_CLOSE
//����:
//��Ӧ:

//EVT_NETIO_SEND
//����:������
//��Ӧ:�����

//EVT_NETIO_STAT
//����:tagNetIOStatInfo|�Զ�������[���п���]
//��Ӧ:tagNetIOStatInfo|�Զ�������[���п���]
enum
{
	STAT_NONE					= 0,//��
	
	//STAT_SET_CONNECT_HOSTINFO,	//��������������Ϣ
	STAT_SET_CONNECT_TIMEOUT,		//�������ӳ�ʱ
	STAT_SET_SEND_TIMEOUT,			//���÷��ͳ�ʱ
	STAT_SET_RECEIVE_TIMEOUT,		//���ý��ճ�ʱ

	//STAT_GET_CONNECT_HOSTINFO,	//��������������Ϣ
	STAT_GET_CONNECT_TIMEOUT,		//�������ӳ�ʱʱ��
	STAT_GET_CONNECT_TIME,			//��������ʱ��
	STAT_GET_SEND_TIMEOUT,			//���ط��ͳ�ʱʱ��
	STAT_GET_RECEIVE_TIMEOUT,		//���ؽ��ճ�ʱʱ��
	STAT_GET_HEART_TIME,			//����������ʱ��

	STAT_IS_HOSTINFO,				//�Ƿ�������Ϣ��ͬ

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
	SendBufferPtr	Send;		//���Ͱ�
	NetBuffer	Receive;		//���հ�
	//string	Reserved;		//�Զ���ģ������,�û����ɼ�����
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
