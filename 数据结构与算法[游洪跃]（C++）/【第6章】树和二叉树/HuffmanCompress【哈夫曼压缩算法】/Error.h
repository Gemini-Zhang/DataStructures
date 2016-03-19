/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : MyHeadFile.h
Description: ʵ�ó��������
Author     : Gatie_Me
Version    : Copyright 2012
Data_Time  : 20112-8-4 15:36:24
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
********************************************************************************/



#ifndef __ERROR_H__				// ���û�ж���__UTILITY_H__
#define __ERROR_H__				// ��ô����__UTILITY_H__

#include <cstring>



// ͨ���쳣��
#define MAX_ERROR_MESSAGE_LEN 100
class Error
{
  private:
// ���ݳ�Ա
	char m_message[MAX_ERROR_MESSAGE_LEN];// �쳣��Ϣ
    //std::string m_message;
  public:
//  ��������
	Error(char *message);//char *message = "һ�����쳣!");	// ���캯��
	~Error( ){ };					// ��������
	void Show( ) const;					// ��ʾ�쳣��Ϣ
};


// ͨ���쳣���ʵ�ֲ���
// �����������mes����ͨ���쳣����
Error::Error(char *message)
{
	strcpy(m_message, message);				// �����쳣��Ϣ
//	m_message = message;
}


// �����������ʾ�쳣��Ϣ
void Error::Show( )const
{
	std::cout <<m_message <<std::endl;			// ��ʾ�쳣��Ϣ
}




#endif     //����__MYHEADFILE_H__����
