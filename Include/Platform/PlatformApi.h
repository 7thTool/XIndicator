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
	* @brief �߳�APIʵ�����лص�
	* @remark �����û�������CreateThread��ϵͳ�������߳�APIʵ���󣬻����ƽ̨OnRunThread�ӿ����У�OnRunThreadĬ�ϻ�����߳�APIʵ����OnRun
	* @remark �����������߳�APIʵ�����߳��У�����ƽ̨�߳�
    * @return �߳��˳�����
    */
	virtual int OnRunThread();
};

class PLATFORM_API PlatformApi
{
public:
	/**
    * @brief ��ȡƽ̨ʵ��
    * @return ƽ̨ʵ��
    */
	static PlatformApi* GetInstance();
	/**
	* @brief �ж�ƽ̨�Ƿ�ʵ������
	* @return true��ʾ�����ˣ�false��ʾû�д���
    */
	static bool IsInstanced();
	/**
	* @brief �ͷ�ƽ̨ʵ��
    * @return ��
    */
	static void ReleaseInstance();

public:
	/**
    * @brief ע��ص��ӿ�
    * @param[in] pSpi �����Իص��ӿ����ʵ��
    * @return ��
    */
	virtual void RegisterSpi(PlatformSpi *pSpi) = 0;

	/**
    * @brief ��ʼ��
	* @remark ��ʼ�����л���
	* @param[in] appname �ӿ�ʹ��������
	* @param[in] workdir �ӿ�ʹ���߹���Ŀ¼
	* @param[in] datadir �ӿ�ʹ��������Ŀ¼
    * @return ��ʼ���Ƿ�ɹ�
    */
	virtual int Init(const char* appname, const char* workdir, const char* datadir) = 0;

	/**
    * @brief ��ֹ
	* @remark ��ֹ���л������ͷ�������Դ
	* @param[in] appname �ӿ�ʹ��������
	* @param[in] workdir �ӿ�ʹ���߹���Ŀ¼
	* @param[in] datadir �ӿ�ʹ��������Ŀ¼
    * @return ��ʼ���Ƿ�ɹ�
    */
	virtual void Term() = 0;

	/**
    * @brief �ȴ��ӿ��߳̽�������
    * @return �߳��˳�����
    */
	virtual int Run(bool bJoin = true) = 0;

	/**
    * @brief ��¼
    * @return ��0��ʾ�ɹ���0��ʾʧ��
    */
	virtual int Login(const char* user, const char* password, const char* xml = NULL) = 0;

	/**
    * @brief ��ȡ�߳�ID
    * @return �߳�ID
    */
	virtual unsigned long GetThreadId() = 0;

	/**
	* @brief ��������
	* @remark �ӿ�ʹ���߿���ͨ��RegisterSpi��Ȼ����pSpi��OnHandle�ﴦ������
	* @param[in] cmd ����
	* @param[in] param �������
    * @return ���������ֵ
    */
	virtual int Send(int cmd, void* param = NULL) = 0;
	virtual int Post(int cmd, void* param = NULL) = 0;
	
	/**
    * @brief ֪ͨ�߳��˳�
    * @return ֪ͨ�Ƿ��ͳɹ�
    */
	virtual int PostQuit() = 0;

	/**
    * @brief �����߳�ʵ��
    * @return �߳�ʵ��
    */
	virtual ThreadApi* CreateThread(const char* name, ThreadSpi *pSpi = NULL) = 0;

	/**
    * @brief �����߳�ʵ��
    * @return ��
    */
	virtual void DestroyThread(ThreadApi* pThread) = 0;

	/**
    * @brief ��ȡ�߳�ʵ��
    * @return �߳�ʵ��
    */
	virtual ThreadApi* GetThread(unsigned int nThreadId) = 0;

protected:
	virtual ~PlatformApi();
};

#endif//

#endif//_H_PLATFORMAPI_H_
