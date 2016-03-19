/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : LinkQueue.h
Description: ��ʽ���ж���ͷ�ļ�
Author     : Gatie_Me
Version    : �汾����
Data_Time  : 20112-9-27 19:1:24
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
********************************************************************************/

#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED


#include "Node.h"


//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�


/// ��ʽջ��ģ��
template <class ElemType>
class LinkQueue         /// ��ͷ���
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // ��ʽջ������Ա����
    LinkQueue( );               // �޲����Ĺ��캯��ģ��

    LinkQueue(const LinkQueue<ElemType> &copy);     // ���ƹ��캯��ģ��

    virtual ~LinkQueue( );      // ��������ģ��

    // ��ʽջ������Ա����
    int Length( ) const;            // ��ȡ��ǰ��ʽջ�ĳ���

    bool Empty( ) const;                // �жϵ�ǰ��ʽ�����Ƿ�Ϊ��ջ

    void Clear( );                      // ��յ�ǰ��ʽ����

    bool GetHead(ElemType &elem) const;           // ����ջ������

    bool InQueue(const ElemType &elem);    // ������elem��ջ

    bool OutQueue(ElemType &elem);           // ������elem��ջ

    ElemType OutQueue( );              // �����ݵ������ҷ���

    // ���ز���������
    LinkQueue<ElemType> &operator=(const LinkQueue<ElemType> &copy);        // ���ظ�ֵ�����
/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*=========================��PROTECTED��������Ա��===========================*/
  protected :
  // ��ʽջ���ݳ�Ա
    Node<ElemType> *m_front/*��ͷ*/, *m_rear/*��β*/;      // ջ��ָ��
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
void LinkQueue<ElemType>::Init( )         // ��ʼ����ǰ����ջ��Ϣ
{
    // ��ʼ����ͷm_front���βm_rearΪͬһ���ڴ�ռ�
    this->m_rear = this->m_front = new Node<ElemType>;       // ����ͷ���,
}


/**��ʽ�����������Ա������ʵ�֡�******************************************************
    LinkQueue( );            // ��ʽ���й��캯��ģ��
    LinkQueue(const LinkQueue &copy);       // ��ʽ�����ิ�ƹ��캯��
    virtual ~LinkQueue( );                // ��ʽ������������ģ��
******************************************************��ʵ�֡���ʽ�����������Ա����**/
// �������ƣ�LinkQueue(int size = 100)
// ��ʼ��������ʽ���ж���δ����
// �������������һ���µ���ʽ���ж����ջ
template <class ElemType>
LinkQueue<ElemType>::LinkQueue( )         // ��ʽ���й��캯��ģ��
{
    // ��ʼ����ͷ��βָ��ͬһ����Ԫ
    //this->Init( );
    this->m_front = this->m_rear = new Node<ElemType>;

}

// �������ƣ�LinkQueue(const LinkQueue &copy)
// ��ʼ��������ʱ��ȱ
// �����������һ����ʽ���ж���copy������ǰ��ʽ���ж���
template <class ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType> &copy)     // ��ʽ�����ิ�ƹ��캯��
{
    this->Init( );         // ����ͷ���, �Ƕ�ͷ��βָ��ͬ���ڴ浥Ԫ

    for(Node<ElemType> *tempPtr = copy.m_front->m_next; tempPtr != NULL; tempPtr = tempPtr->m_next)
    {   // ��copy����ÿ��Ԫ���������
        this->InQueue(tempPtr->m_data);
    }
}


// �������ƣ�virtual ~LinkQueue( );
// ��ʼ��������ʱ��ȱ
// �����������һ����ʽ���ж���copy������ǰ��ʽ���ж���
template <class ElemType>
LinkQueue<ElemType>::~LinkQueue( )      // ��ʽ������������ģ��
{
    this->Clear( );                     // �����ʽ��
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
int LinkQueue<ElemType>::Length( ) const      // ��ȡ��ǰ��ʽ���е�ջ����
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Length..." <<std::endl;
#endif
    // ����ʵ��
    int count = 0;
    for(Node<ElemType> *tempPtr = this->m_front->m_next; tempPtr != NULL; tempPtr = tempPtr->m_next)
    {
        count++;
    }
    return count;
}

// �������ƣ�void Clear( );
// ��ʼ��������ʽ�����Ѿ�����
// ������������ص�ǰ��ʽ���е�ջ����
template <class ElemType>
void LinkQueue<ElemType>::Clear( )            // ��յ�ǰ��ʽ����
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Clear..." <<std::endl;
#endif
    // ����ʵ��
    ElemType elem;
    while(this->Length() > 0)       // ֻҪ��ǰ���в��ǿն�
    {
        this->OutQueue(elem);       // �ͽ����ݳ���
    }
}


// �������ƣ�bool Empty( ) const;
// ��ʼ��������ʽ�����Ѿ�����
// ����������жϵ�ǰ��ʽ�����Ƿ�Ϊ��ջ
template <class ElemType>
bool LinkQueue<ElemType>::Empty( ) const          // �жϵ�ǰ��ʽ�����Ƿ�Ϊ��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Empty..." <<std::endl;
#endif
    // ����ʵ��
    return this->m_front == this->m_rear;        // ��ջ��һ�����Ծ��Ƕ�ͷ��β����ָ��ͬһ���ڴ浥Ԫ
}

// �������ƣ�bool OutQueue(ElemType &elem);
// ��ʼ��������ʽ�����Ѿ�����
// ����������жϵ�ǰ��ʽ��������
template <class ElemType>
bool LinkQueue<ElemType>::GetHead(ElemType &elem)  const       // ������elem��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"GetHead..." <<std::endl;
#endif
    // ����ʵ��
    if(this->Empty() == true)       // �����ǰ��ʽ����Ϊ��
    {
        #if define REMIND
        std::cout <<"��ǰ��ʽ��Ϊ��, �޷������ݳ���" <<std::endl;
        #endif

        return false;
    }
    else
    {
        // ָ����ʽ���еĶ�ͷ, ���ӿ϶��Ǵ��ͷ��ʼ��
        elem = this->m_front->m_next->m_data;                             // ȡ����ͷ������

        return true;
    }

}

// �������ƣ�bool InQueue(const ElemType &elem);
// ��ʼ��������ʽ�����Ѿ�����
// ����������жϵ�ǰ��ʽ��������
template <class ElemType>
bool LinkQueue<ElemType>::InQueue(const ElemType &elem)    // ������elem��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"InQueue..." <<std::endl;
#endif
    // ����ʵ��

    // [���ֻ��Ҫ�����׷�����ڵ�ǰ�����β��, Ȼ���ö�β����]
    Node<ElemType> *newRear = new Node<ElemType>(elem);    // �¶�β����һ��ָ�����ȻΪ��
    this->m_rear->m_next = newRear;                         // �µĽ��׷���������ĩβ
    this->m_rear = newRear;                                 // ����β���Ƶ��½��Ķ�β

    return true;
}


// �������ƣ�bool OutQueue(ElemType) const;
// ��ʼ��������ʽ�����Ѿ�����
// ����������жϵ�ǰ��ʽ��������
template <class ElemType>
bool LinkQueue<ElemType>::OutQueue(ElemType &elem)         // ����ջ������
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"OutQueue..." <<std::endl;
#endif
    // ����ʵ��

    if(this->Empty() == true)       // �����ǰ��ʽ����Ϊ��
    {
        #ifdef REMIND
        std::cout <<"��ǰ��ʽ��Ϊ��, �޷������ݳ���" <<std::endl;
        #endif

        return false;
    }
    else
    {
        Node<ElemType> *oldHead = this->m_front->m_next;     // ָ����ʽ���еĶ�ͷ, ���ӿ϶��Ǵ��ͷ��ʼ��
        elem = oldHead->m_data;                             // ȡ����ͷ������
        this->m_front->m_next = oldHead->m_next;

        if(this->m_rear == oldHead)             // ���ԭ����ʽ������ֻ��һ��Ԫ��
        {   // �����Ժ���ʽ����Ϊ��
            this->m_rear = this->m_front;        // ���ö���Ϊ��
        }

        //delete oldHead;     // �ͷų��ӵĽ��

        return true;
    }
}

// �������ƣ�ElemType OutQueue( ) const;
// ��ʼ��������ʽ�����Ѿ�����, ���Ҳ�������
// �����������ջ�������ݷ���
template <class ElemType>
ElemType LinkQueue<ElemType>::OutQueue( )
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"OutQueue..." <<std::endl;
#endif
    // ����ʵ��
    ElemType elem;
    if(this->OutQueue(elem) == true)
    {
        return elem;
    }
    else
    {
        return -1;
    }
}

// �����ݵ������ҷ���
/**���ز�����������ʵ�֡�****************************************************************
    LinkQueue<EelmType> &operator=(const LinkQueue<ElemType> &copy);        // ���ظ�ֵ�����
****************************************************************��ʵ�֡����ز���������**/
template <class ElemType>
LinkQueue<ElemType>& LinkQueue<ElemType>::operator=(const LinkQueue<ElemType> &copy)
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"OutQueue..." <<std::endl;
#endif
    // ����ʵ��
    if(copy != this)
    {
        this->Clear( );     // �����

        for(Node<ElemType> *tempPtr = copy.m_front->m_next; tempPtr != NULL; tempPtr = tempPtr->m_next)
        {   // ��tempPtrָ�����η���copy�е�ÿ��Ԫ����Ϣ
            this->InQueue(tempPtr->m_data);     // ��Ԫ����Ϣ���
        }
    }
}


#endif // LinkQueue_H_INCLUDED
