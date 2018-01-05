// XThreadApi.h
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _H_XTHREADAPI_H_
#define _H_XTHREADAPI_H_

#include "XPlatformApiDef.h"
#include <Indicator/XIndicatorApi.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if defined(__cplusplus)
extern "C" {
#endif//

	//

#if defined(__cplusplus)
}

class XPLATFORM_API XThreadSpi 
	: public XIndicatorSpi //指标系统
{
public:
	/**
	* @brief 线程API运行回调
	* @remark 这里接口使用者可以自定义加载数据，如果调用基类的OnRun使用系统默认消息循环，用户也可以不调用基类，而是使用自己的消息循环
	* @remark 这是运行在线程API实例的线程中
    * @return 线程退出代码
    */
	virtual int OnRun(bool bJoin);

	/**
	* @brief 命令响应回调
	* @remark 这里接口使用者可以响应用户Send/Post的命令，然后调用基类的默认处理
    * @return 命令返回值
    */
	virtual int OnHandle(int cmd, void* param);

	/**
	* @brief 空闲处理
	* @remark 这里接口使用者可以处理一些非紧急的，不耗时的操作
    * @return 无
    */
	virtual void OnIdle(unsigned int tick);
};

class XPLATFORM_API XThreadApi 
{
public:
	/**
    * @brief 获取当前线程Api实例
    * @return 线程Api实例
    */ 
	static XThreadApi* GetInstance();
	/**
    * @brief 判断当前线程Api实例是否创建了
    * @return true表示创建了，false表示没有创建
    */
	static bool IsInstanced();
	/**
    * @brief 释放
	* @remark 释放当前线程实例
    * @return 无
    */ 
	static void ReleaseInstance();

public:
	/**
    * @brief 注册回调接口
    * @param[in] pSpi 派生自回调接口类的实例
    * @return 无
    */
	//virtual void RegisterSpi(XThreadSpi *pSpi) = 0;

	///初始化
	///@remark 初始化运行环境
	//virtual int Init(const char* name, const char* workdir, const char* datadir) = 0;

	//终止
	///@remark 终止运行环境，释放所有资源
	//virtual void Term() = 0;
	
	/**
	* @brief 运行
	* @param[in] bJoin true表示等待接口线程结束运行，系统默认运行消息循环，消息循环退出Run才会返回，false表示不等待
    * @return bJoin为true时是线程退出代码，bJoin为false时是Run有没有成功
    */
	virtual int Run(bool bJoin = true) = 0;
	
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

protected:
	virtual ~XThreadApi();
};

#endif//

#endif//_H_XTHREADAPI_H_