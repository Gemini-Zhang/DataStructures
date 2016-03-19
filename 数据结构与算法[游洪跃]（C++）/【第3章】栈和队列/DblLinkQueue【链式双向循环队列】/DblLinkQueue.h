/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : DblLinkQueue.h
Description: ��ʽ���ж���ͷ�ļ�
Author     : Gatie_Me
Version    : �汾����
Data_Time  : 20112-9-27 19:1:24
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
********************************************************************************/

#ifndef DblLinkQueue_H_INCLUDED
#define DblLinkQueue_H_INCLUDED


#include "DblNode.h"


//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�


/// ��ʽջ��ģ��
template <class ElemType>
class DblLinkQueue        /// ��ͷ���
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // ��ʽջ������Ա����
    DblLinkQueue( );               // �޲����Ĺ��캯��ģ��

    DblLinkQueue(const DblLinkQueue<ElemType> &copy);     // ���ƹ��캯��ģ��

    virtual ~DblLinkQueue( );      // ��������ģ��

    // ��ʽջ������Ա����
    int Length( ) const;            // ��ȡ��ǰ��ʽջ�ĳ���

    bool Empty( ) const;                // �жϵ�ǰ��ʽ�����Ƿ�Ϊ��ջ

    void Clear( );                      // ��յ�ǰ��ʽ����

    bool GetHead(ElemType &elem) const;           // ����ջ������

    bool InQueue(const ElemType &elem);    // ������elem��ջ

    bool OutQueue(ElemType &elem);           // ������elem��ջ

    ElemType OutQueue( );              // �����ݵ������ҷ���

    // ���ز���������
    DblLinkQueue<ElemType> &operator=(const DblLinkQueue<ElemType> &copy);        // ���ظ�ֵ�����
/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*=========================��PROTECTED��������Ա��===========================*/
  protected :
  // ��ʽջ���ݳ�Ա
    DblNode<ElemType> *m_rear/*��β*/;      // ջ��ָ��

  // ����������ģ��
    void Init( );               // ��ʼ��ջ
/*=========================��PROTECTED����������Ա��=========================*/
};


/**��������ģ�桾ʵ�֡�**************************************************************
    void Init(int size);        // ��ʼ����ǰջ��Ϣ
**************************************************************��ʵ�֡���������ģ��**/
// �������ƣ�void Init(int size)
// ��ʼ��������ʽ������Ϣ��Ҫ��ʼ��
// �����������˳����������Ԫ�س�ʼ��
template <class ElemType>
void DblLinkQueue<ElemType>::Init( )         // ��ʼ����ǰ����ջ��Ϣ
{
    // ��ʼ����ͷm_front���βm_rearΪͬһ���ڴ�ռ�

}


/**��ʽ�����������Ա������ʵ�֡�******************************************************
    DblLinkQueue( );            // ��ʽ���й��캯��ģ��
    DblLinkQueue(const DblDblLinkQueue&copy);       // ��ʽ�����ิ�ƹ��캯��
    virtual ~DblLinkQueue( );                // ��ʽ������������ģ��
******************************************************��ʵ�֡���ʽ�����������Ա����**/
// �������ƣ�DblLinkQueue(int size = 100)
// ��ʼ��������ʽ���ж���δ����
// �������������һ���µ���ʽ���ж����ջ
template <class ElemType>
DblLinkQueue<ElemType>::DblLinkQueue( )         // ��ʽ���й��캯��ģ��
{
    // ��ʼ����ͷ��βָ��ͬһ����Ԫ
    //this->Init( );
}

// �������ƣ�DblLinkQueue(const DblDblLinkQueue&copy)
// ��ʼ��������ʱ��ȱ
// �����������һ����ʽ���ж���copy������ǰ��ʽ���ж���
template <class ElemType>
DblLinkQueue<ElemType>::DblLinkQueue(const DblLinkQueue<ElemType> &copy)     // ��ʽ�����ิ�ƹ��캯��
{

}


// �������ƣ�virtual ~DblLinkQueue( );
// ��ʼ��������ʱ��ȱ
// �����������һ����ʽ���ж���copy������ǰ��ʽ���ж���
template <class ElemType>
DblLinkQueue<ElemType>::~DblLinkQueue( )      // ��ʽ������������ģ��
{

}


/**��ʽ����������������ʵ�֡�******************************************************
    int Length( ) const;                // ��ȡ��ǰ��ʽ���е�ջ����
    void Clear( );                      // ��յ�ǰ��ʽ����
    bool Empty( ) const;                // �жϵ�ǰ��ʽ�����Ƿ�Ϊ��ջ
    bool OutQueue(ElemType) const;           // ����ջ������
    bool InQueue(const ElemType &elem);    // ������elem��ջ
    bool OutQueue(ElemType &elem);           // ������elem��ջ
    ElemType OutQueue( ) const;              // �����ݵ������ҷ���
******************************************************��ʵ�֡���ʽ��������������**/
// �������ƣ�int Length( ) const;
// ��ʼ��������ʽ�����Ѿ�����
// ������������ص�ǰ��ʽ���е�ջ����
template <class ElemType>
int DblLinkQueue<ElemType>::Length( ) const      // ��ȡ��ǰ��ʽ���е�ջ����
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Length..." <<std::endl;
#endif
    // ����ʵ��
}

// �������ƣ�void Clear( );
// ��ʼ��������ʽ�����Ѿ�����
// ������������ص�ǰ��ʽ���е�ջ����
template <class ElemType>
void DblLinkQueue<ElemType>::Clear( )            // ��յ�ǰ��ʽ����
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Clear..." <<std::endl;
#endif
    // ����ʵ��
}


// �������ƣ�bool Empty( ) const;
// ��ʼ��������ʽ�����Ѿ�����
// ����������жϵ�ǰ��ʽ�����Ƿ�Ϊ��ջ
template <class ElemType>
bool DblLinkQueue<ElemType>::Empty( ) const          // �жϵ�ǰ��ʽ�����Ƿ�Ϊ��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Empty..." <<std::endl;
#endif
    // ����ʵ��

}

// �������ƣ�bool OutQueue(ElemType &elem);
// ��ʼ��������ʽ�����Ѿ�����
// ����������жϵ�ǰ��ʽ��������
template <class ElemType>
bool DblLinkQueue<ElemType>::GetHead(ElemType &elem)  const       // ������elem��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"GetHead..." <<std::endl;
#endif
    // ����ʵ��
}

// �������ƣ�bool InQueue(const ElemType &elem);
// ��ʼ��������ʽ�����Ѿ�����
// ����������жϵ�ǰ��ʽ��������
template <class ElemType>
bool DblLinkQueue<ElemType>::InQueue(const ElemType &elem)    // ������elem��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"InQueue..." <<std::endl;
#endif
    // ����ʵ��
}


// �������ƣ�bool OutQueue(ElemType) const;
// ��ʼ��������ʽ�����Ѿ�����
// ����������жϵ�ǰ��ʽ��������
template <class ElemType>
bool DblLinkQueue<ElemType>::OutQueue(ElemType &elem)         // ����ջ������
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"OutQueue..." <<std::endl;
#endif
    // ����ʵ��
}

// �������ƣ�ElemType OutQueue( ) const;
// ��ʼ��������ʽ�����Ѿ�����, ���Ҳ�������
// �����������ջ�������ݷ���
template <class ElemType>
ElemType DblLinkQueue<ElemType>::OutQueue( )
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"OutQueue..." <<std::endl;
#endif
    // ����ʵ��
}

// �����ݵ������ҷ���
/**���ز�����������ʵ�֡�****************************************************************
    DblLinkQueue<EelmType> &operator=(const DblLinkQueue<ElemType> &copy);        // ���ظ�ֵ�����
****************************************************************��ʵ�֡����ز���������**/
template <class ElemType>
DblLinkQueue<ElemType>& DblLinkQueue<ElemType>::operator=(const DblLinkQueue<ElemType> &copy)
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"OutQueue..." <<std::endl;
#endif
    // ����ʵ��
}


#endif // DblLinkQueue_H_INCLUDED
