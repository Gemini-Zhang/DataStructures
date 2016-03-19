/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : HuffmanTree.h                                                *
*  Description: ��������ѹ����HuffmanCompress�ַ��������ļ�BufferType.h     *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/

#ifndef BUFFERTYPE_H_INCLUDED
#define BUFFERTYPE_H_INCLUDED



/// �ַ�������
class BufferType
{
    /*===========================��PUBLIC�������ӿڡ�============================*/
public :      // �����ӿ�
    BufferType( );              // Ĭ�Ϲ��캯��
    ~BufferType( );             // ��������

    char m_character;               // �ַ���Ϣ
    unsigned int m_bits;            // ʵ�ʱ�����Ŀ

    void InitBuffer( );             // ��ʼ��������Ϣ
};


BufferType::BufferType( )              // Ĭ�Ϲ��캯��
{
    this->InitBuffer( );
}


BufferType::~BufferType( )             // ��������
{

}
// �������ƣ�void InitBuffer( );
// �����������ʼ��������Ϣ
void BufferType::InitBuffer( )             // ��ʼ��������Ϣ
{
    this->m_bits  = 0;          // ��ʼ����������С[��0]
    this->m_character = 0;      // ��ʼ���ַ���Ϣ
}


#endif // HuffmanTree_H_INCLUDED
