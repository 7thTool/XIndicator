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
	: public XIndicatorSpi //ָ��ϵͳ
{
public:
	/**
	* @brief �߳�API���лص�
	* @remark ����ӿ�ʹ���߿����Զ���������ݣ�������û����OnRunʹ��ϵͳĬ����Ϣѭ�����û�Ҳ���Բ����û��࣬����ʹ���Լ�����Ϣѭ��
	* @remark �����������߳�APIʵ�����߳���
    * @return �߳��˳�����
    */
	virtual int OnRun(bool bJoin);

	/**
	* @brief ������Ӧ�ص�
	* @remark ����ӿ�ʹ���߿�����Ӧ�û�Send/Post�����Ȼ����û����Ĭ�ϴ���
    * @return �����ֵ
    */
	virtual int OnHandle(int cmd, void* param);

	/**
	* @brief ���д���
	* @remark ����ӿ�ʹ���߿��Դ���һЩ�ǽ����ģ�����ʱ�Ĳ���
    * @return ��
    */
	virtual void OnIdle(unsigned int tick);
};

class XPLATFORM_API XThreadApi 
{
public:
	/**
    * @brief ��ȡ��ǰ�߳�Apiʵ��
    * @return �߳�Apiʵ��
    */ 
	static XThreadApi* GetInstance();
	/**
    * @brief �жϵ�ǰ�߳�Apiʵ���Ƿ񴴽���
    * @return true��ʾ�����ˣ�false��ʾû�д���
    */
	static bool IsInstanced();
	/**
    * @brief �ͷ�
	* @remark �ͷŵ�ǰ�߳�ʵ��
    * @return ��
    */ 
	static void ReleaseInstance();

public:
	/**
    * @brief ע��ص��ӿ�
    * @param[in] pSpi �����Իص��ӿ����ʵ��
    * @return ��
    */
	//virtual void RegisterSpi(XThreadSpi *pSpi) = 0;

	///��ʼ��
	///@remark ��ʼ�����л���
	//virtual int Init(const char* name, const char* workdir, const char* datadir) = 0;

	//��ֹ
	///@remark ��ֹ���л������ͷ�������Դ
	//virtual void Term() = 0;
	
	/**
	* @brief ����
	* @param[in] bJoin true��ʾ�ȴ��ӿ��߳̽������У�ϵͳĬ��������Ϣѭ������Ϣѭ���˳�Run�Ż᷵�أ�false��ʾ���ȴ�
    * @return bJoinΪtrueʱ���߳��˳����룬bJoinΪfalseʱ��Run��û�гɹ�
    */
	virtual int Run(bool bJoin = true) = 0;
	
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

protected:
	virtual ~XThreadApi();
};

#endif//

#endif//_H_XTHREADAPI_H_