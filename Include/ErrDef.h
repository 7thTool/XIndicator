#ifndef _H_ERR_DEF_H_
#define _H_ERR_DEF_H_

#include <XLib/XLib.h>

#define RLT_ERR_UNKNOWN		RLT_UNKNOWN
#define RLT_ERR_FAILED		RLT_FAILED
#define RLT_ERR_FALSE		RLT_FALSE
#define RLT_ERR_OK			RLT_OK	
#define RLT_ERR_TRUE		RLT_TRUE

//
//�����Ϊ3������ϵͳ���󡢹�������Ӧ�ò����
//����ǰ���ִ�����ô�������ʾ������ͨ����������ֵһ��һ�����ϴ��ݣ�һֱ����Ӧ�ò㡣Ӧ�ò�������־ϵͳ�����Ǳ��ֳ�����
//���ԣ����ھ��󲿷���Ҫ�жϵĺ��������÷���int��������>=0��ʾ��������[��һ���ǳɹ�]��<0��ʾ����ķ���
//
#define ERROR_SYSTEM		0x80000000					//ϵͳ����
#define ERROR_SYSTEM_MASK	0X8F000000					//ϵͳ��������
//����ֵ = ERROR_SYSTEM + GetLastError() 

#define ERROR_USER			0x90000000					//�Զ������
#define ERROR_USER_MASK		0x9F000000					//�Զ����������
//����ֵ = ERROR_USER + �Զ������

#define ERROR_TYPE_MASK		0XFF000000					//���������������룬����ϵͳ�����Զ�������
#define ERROR_VALUE_MASK	0X00FFFFFF					//���������ֵ���룬����ϵͳ�����Զ�������

#define ERROR_OK			1
#define ERROR_NONE			0L
#define ERROR_NULL			0L
#define ERROR_ERROR			-1

//����ϵͳ����
#define ERROR_SYSTEM_NET	0x81000000					//ϵͳ�������

//�����Զ������
#define ERROR_USER_NET		0x91000000					//�Զ����������

#define IsSystemError(e)	((e)&ERROR_SYSTEM)

#define IsUserError(e)		((e)&ERROR_USER)

#define MAKEERROR(x,y)		((x)|(y))

#define GetErrorType(e)		(ERROR_TYPE_MASK&(e))

#define GetErrorValue(e)	(ERROR_VALUE_MASK&(e))

#define GetErrorString(e)	#e

#define IsError(e)			((e)<ERROR_NULL)
#define IsErrorNet(e)		((GetErrorType(e)==ERROR_SYSTEM_NET)||(GetErrorType(e)==ERROR_USER_NET))

//ErrorCode ERROR_USER_NET
enum
{
	ERROR_NET_UNKNOWN = 0,				// �������
	ERROR_NET_CONNECT_TIMEOUT,			// �������ӳ�ʱ
	ERROR_NET_SEND_TIMEOUT,				// ���緢�ͳ�ʱ
	ERROR_NET_RECEIVE_TIMEOUT,			// ������ճ�ʱ
	ERROR_NET_SHUTDOWN,					// �׽����Ѿ����ر�
	ERROR_NET_PACKET,					// ��������ݰ�
	ERROR_NET_COMPRESS,					// ѹ������ʧ��
	ERROR_NET_UNCOMPRESS,				// ��ѹ������ʧ��
	ERROR_NET_INVALID_SVRADDR,			// ����ķ�������ַ	
};

#endif//_H_ERR_DEF_H_