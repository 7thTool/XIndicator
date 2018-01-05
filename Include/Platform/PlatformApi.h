// PlatformApi.h
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _H_PLATFORMAPI_H_
#define _H_PLATFORMAPI_H_

#include "ThreadApi.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if defined(__cplusplus)
extern "C" {
#endif//

PLATFORM_API int Platform_Init(const char* appname, const char* workdir, const char* datadir);
PLATFORM_API void Platform_Term();

PLATFORM_API int Platform_Run(bool bJoin);

#if defined(__cplusplus)
}

class PLATFORM_API PlatformSpi 
	: public ThreadSpi
{
public:
	/**
	* @brief 线程API实例运行回调
	* @remark 这是用户调用了CreateThread，系统创建了线程API实例后，会调用平台OnRunThread接口运行，OnRunThread默认会调用线程API实例的OnRun
	* @remark 这是运行在线程API实例的线程中，不是平台线程
    * @return 线程退出代码
    */
	virtual int OnRunThread();
};

class PLATFORM_API PlatformApi
{
public:
	/**
    * @brief 获取平台实例
    * @return 平台实例
    */
	static PlatformApi* GetInstance();
	/**
	* @brief 判断平台是否实例化了
	* @return true表示创建了，false表示没有创建
    */
	static bool IsInstanced();
	/**
	* @brief 释放平台实例
    * @return 无
    */
	static void ReleaseInstance();

public:
	/**
    * @brief 注册回调接口
    * @param[in] pSpi 派生自回调接口类的实例
    * @return 无
    */
	virtual void RegisterSpi(PlatformSpi *pSpi) = 0;

	/**
    * @brief 初始化
	* @remark 初始化运行环境
	* @param[in] appname 接口使用者名字
	* @param[in] workdir 接口使用者工作目录
	* @param[in] datadir 接口使用者数据目录
    * @return 初始化是否成功
    */
	virtual int Init(const char* appname, const char* workdir, const char* datadir) = 0;

	/**
    * @brief 终止
	* @remark 终止运行环境，释放所有资源
	* @param[in] appname 接口使用者名字
	* @param[in] workdir 接口使用者工作目录
	* @param[in] datadir 接口使用者数据目录
    * @return 初始化是否成功
    */
	virtual void Term() = 0;

	/**
    * @brief 等待接口线程结束运行
    * @return 线程退出代码
    */
	virtual int Run(bool bJoin = true) = 0;

	/**
    * @brief 登录
    * @return 非0表示成功，0表示失败
    */
	virtual int Login(const char* user, const char* password, const char* xml = NULL) = 0;

	/**
    * @brief 获取线程ID
    * @return 线程ID
    */
	virtual unsigned long GetThreadId() = 0;

	/**
	* @brief 发送命令
	* @remark 接口使用者可以通过RegisterSpi，然后再pSpi的OnHandle里处理命令
	* @param[in] cmd 命令
	* @param[in] param 命令参数
    * @return 发送命令返回值
    */
	virtual int Send(int cmd, void* param = NULL) = 0;
	virtual int Post(int cmd, void* param = NULL) = 0;
	
	/**
    * @brief 通知线程退出
    * @return 通知是否发送成功
    */
	virtual int PostQuit() = 0;

	/**
    * @brief 创建线程实例
    * @return 线程实例
    */
	virtual ThreadApi* CreateThread(const char* name, ThreadSpi *pSpi = NULL) = 0;

	/**
    * @brief 销毁线程实例
    * @return 无
    */
	virtual void DestroyThread(ThreadApi* pThread) = 0;

	/**
    * @brief 获取线程实例
    * @return 线程实例
    */
	virtual ThreadApi* GetThread(unsigned int nThreadId) = 0;

protected:
	virtual ~PlatformApi();
};

#endif//

#endif//_H_PLATFORMAPI_H_
