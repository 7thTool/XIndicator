#ifndef _H_NET_DEF_H_
#define _H_NET_DEF_H_

#include <XLib/XSocketDef.h>
#include "ErrDef.h"

#pragma pack(1)

/*#define PROXYTYPE_NONE		0
#define PROXYTYPE_SOCKS4	1
#define PROXYTYPE_SOCKS4A	2
#define PROXYTYPE_SOCKS5	3
#define PROXYTYPE_HTTP10	4
#define PROXYTYPE_HTTP11	5

typedef struct tagProxyInfo
{	
	u_char		nType;			//代理类型
	char 		szHost[256];	//代理服务器的地址
	u_short 	nPort;			//代理服务器的端口
	bool		bAuth;			//是否需要认证
	char 		szUser[64];		//用户名
	char		szPwd[64];		//密码
} PROXYINFO,* PPROXYINFO;*/

#pragma pack()

#endif//_H_NET_DEF_H_