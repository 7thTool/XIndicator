// XPlatformApi.h
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _H_XPLATFORMAPI_H_
#define _H_XPLATFORMAPI_H_

#include "XThreadApi.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if defined(__cplusplus)
extern "C" {
#endif//

XPLATFORM_API int XPlatform_Init(const char* appname, const char* workdir, const char* datadir);
XPLATFORM_API void XPlatform_Term();

XPLATFORM_API int XPlatform_Run(bool bJoin);

#if defined(__cplusplus)
}

class XPLATFORM_API XPlatformSpi 
	: public XThreadSpi
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

class XPLATFORM_API XPlatformApi
{
public:
	/**
    * @brief ��ȡƽ̨ʵ��
    * @return ƽ̨ʵ��
    */
	static XPlatformApi* GetInstance();
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
	virtual void RegisterSpi(XPlatformSpi *pSpi) = 0;
	
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
	virtual XThreadApi* CreateThread(const char* name, XThreadSpi *pSpi = NULL) = 0;
	
	/**
    * @brief �����߳�ʵ��
    * @return ��
    */
	virtual void DestroyThread(XThreadApi* pThread) = 0;
	
	/**
    * @brief ��ȡ�߳�ʵ��
    * @return �߳�ʵ��
    */
	virtual XThreadApi* GetThread(unsigned int nThreadId) = 0;

protected:
	virtual ~XPlatformApi();
};

#endif//

#endif//_H_XPLATFORMAPI_H_