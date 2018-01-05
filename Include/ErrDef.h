#ifndef _H_ERR_DEF_H_
#define _H_ERR_DEF_H_

#include <XLib/XLib.h>

#define RLT_ERR_UNKNOWN		RLT_UNKNOWN
#define RLT_ERR_FAILED		RLT_FAILED
#define RLT_ERR_FALSE		RLT_FALSE
#define RLT_ERR_OK			RLT_OK	
#define RLT_ERR_TRUE		RLT_TRUE

//
//错误分为3个级别，系统错误、公共错误、应用层错误
//对于前两种错误采用错误代码表示，并且通过函数返回值一层一层向上传递，一直传到应用层。应用层利用日志系统将他们表现出来。
//所以，对于绝大部分需要判断的函数都采用返回int的做法，>=0表示正常返回[不一定是成功]，<0表示错误的发生
//
#define ERROR_SYSTEM		0x80000000					//系统错误
#define ERROR_SYSTEM_MASK	0X8F000000					//系统错误掩码
//错误值 = ERROR_SYSTEM + GetLastError() 

#define ERROR_USER			0x90000000					//自定义错误
#define ERROR_USER_MASK		0x9F000000					//自定义错误掩码
//错误值 = ERROR_USER + 自定义错误

#define ERROR_TYPE_MASK		0XFF000000					//整个错误类型掩码，包括系统错误，自定义错误等
#define ERROR_VALUE_MASK	0X00FFFFFF					//整个错误的值掩码，包括系统错误，自定义错误等

#define ERROR_OK			1
#define ERROR_NONE			0L
#define ERROR_NULL			0L
#define ERROR_ERROR			-1

//公共系统错误
#define ERROR_SYSTEM_NET	0x81000000					//系统网络错误

//公共自定义错误
#define ERROR_USER_NET		0x91000000					//自定义网络错误

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
	ERROR_NET_UNKNOWN = 0,				// 网络错误
	ERROR_NET_CONNECT_TIMEOUT,			// 网络连接超时
	ERROR_NET_SEND_TIMEOUT,				// 网络发送超时
	ERROR_NET_RECEIVE_TIMEOUT,			// 网络接收超时
	ERROR_NET_SHUTDOWN,					// 套接字已经被关闭
	ERROR_NET_PACKET,					// 错误的数据包
	ERROR_NET_COMPRESS,					// 压缩数据失败
	ERROR_NET_UNCOMPRESS,				// 解压缩数据失败
	ERROR_NET_INVALID_SVRADDR,			// 错误的服务器地址	
};

#endif//_H_ERR_DEF_H_