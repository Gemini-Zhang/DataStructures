/**
******************************************************************************
*  Copyright  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : Error.h                                                      *
*  Description: �쳣������                                               *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 25/10/12 17:20                                              *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/

#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED


// ͨ���쳣��
#define MAX_ERROR_MESSAGE_LEN 81

class Error
{
  private:
// ���ݳ�Ա
	char m_message[MAX_ERROR_MESSAGE_LEN];// �쳣��Ϣ

  public:
//  ��������
	Error(char *message = "һ�����쳣!");	// ���캯��

	~Error( ){ };					// ��������

	void Show( ) const;					// ��ʾ�쳣��Ϣ
};


/// ͨ���쳣���ʵ�ֲ���
/**Error�������Ա����[ʵ��]**********************************
	Error(char *message = "һ�����쳣!");	// ���캯��
	~Error( ){ };					// ��������
	void Show( ) const;					// ��ʾ�쳣��Ϣ
**********************************[ʵ��]Error�������Ա����**/
// �����������mes����ͨ���쳣����
Error::Error(char *mes)
{
	strcpy(m_message, mes);				// �����쳣��Ϣ
}


// �����������ʾ�쳣��Ϣ
void Error::Show()const
{
	std::cout <<m_message <<std::endl;			// ��ʾ�쳣��Ϣ
}


#endif // ERROR_H_INCLUDED
