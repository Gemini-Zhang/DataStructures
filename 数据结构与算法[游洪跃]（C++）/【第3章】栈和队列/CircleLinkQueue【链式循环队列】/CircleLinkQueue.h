/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : CircleLinkQueue.h
Description: ��ʽѭ�����ж���ͷ�ļ�
Author     : Gatie_Me
Version    : �汾����
Data_Time  : 20112-9-27 19:1:24
********************************************************************************/

/********************************************************************************
History    :

********************************************************************************/


#ifndef CIRCLELINKQUEUE_H_INCLUDED
#define CIRCLELINKQUEUE_H_INCLUDED


#include "Node.h"


//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�


/// ��ʽջ��ģ��
template <class ElemType>
class CircleLinkQueue        /// ��ͷ���[����û�ж�ͷ���ݳ�Ա]
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // ��ʽջ������Ա����
    CircleLinkQueue( );               // �޲����Ĺ��캯��ģ��

    CircleLinkQueue(const CircleLinkQueue<ElemType> &copy);     // ���ƹ��캯��ģ��

    virtual ~CircleLinkQueue( );      // ��������ģ��

    // ��ʽջ������Ա����
    int Length( ) const;            // ��ȡ��ǰ��ʽջ�ĳ���

    bool Empty( ) const;                // �жϵ�ǰ��ʽѭ�������Ƿ�Ϊ��ջ

    bool Full( ) const;                 // �жϵ�ǰ��ʽѭ�������Ƿ�����

    void Clear( );                      // ��յ�ǰ��ʽѭ������

    bool GetHead(ElemType &elem) const;           // ����ջ������

    bool InQueue(const ElemType &elem);    // ������elem��ջ

    bool OutQueue(ElemType &elem);           // ������elem��ջ

    ElemType OutQueue( );              // �����ݵ������ҷ���

    // ���ز���������
    CircleLinkQueue<ElemType> &operator=(const CircleLinkQueue<ElemType> &copy);        // ���ظ�ֵ�����
/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*=========================��PROTECTED��������Ա��===========================*/
  protected :
  // ��ʽջ���ݳ�Ա
    Node<ElemType> *m_rear/*��β*/;      // ջ��ָ��
  //  int m_length;      // ���浱ǰ����Ԫ�ظ������ź�
  // ����������ģ��
    void Init( );               // ��ʼ��ջ

    Node<ElemType>* GetFrontPtr( ) const;     // ��ȡ��ǰ�Ķ�ͷԪ����Ϣ

    Node<ElemType>* GetHeadPtr( ) const;      // ��ȡ��ǰ��ͷ������Ϣ
/*=========================��PROTECTED����������Ա��=========================*/
};


/**��������ģ�桾ʵ�֡�**************************************************************
    void Init(int size);        // ��ʼ����ǰջ��Ϣ
    Node<ElemType>* GetFrontPtr( );     // ��ȡ��ǰ�Ķ�ͷԪ����Ϣ
    Node<ElemType>* GetHeadPtr( );      // ��ȡ��ǰ��ͷ������Ϣ
**************************************************************��ʵ�֡���������ģ��**/
// �������ƣ�void Init(int size)
// ��ʼ��������ʽѭ��������Ϣ��Ҫ��ʼ��
// �����������˳����������Ԫ�س�ʼ��
template <class ElemType>
void CircleLinkQueue<ElemType>::Init( )         // ��ʼ����ǰ����ջ��Ϣ
{
    // ��ʼ����ͷm_front���βm_rearΪͬһ���ڴ�ռ�
    this->m_rear = new Node<ElemType>;          // Ϊ��㿪�ٿռ�
    this->m_rear->m_next = m_rear;              // �ն��е�β���ָ���Լ�����
   // this->m_length = 0;
}


//// �������ƣ�Node<ElemType>* GetFrontPtr( );
//// ��ʼ��������ʽѭ��������Ϣ�Ѿ�����
//// ������������ص�ǰ����Ԫ�صĶ�ͷָ��
//template <class ElemType>
//Node<ElemType>* CircleLinkQueue<ElemType>::GetFrontPtr( ) const  // ��ȡ��ǰ�Ķ�ͷԪ����Ϣ
//{
//    return this->m_rear->m_next->m_next;        // ���ص�ǰ���еĶ�ͷԪ��
//}
//
//// �������ƣ�Node<ElemType>* GetHeafPtr06( );
//// ��ʼ��������ʽѭ��������Ϣ�Ѿ�����
//// ������������ص�ǰ����Ԫ�ص�ͷ���ָ��
//template <class ElemType>
//Node* CircleLinkQueue<ElemType>::GetFrontPtr( ) const   // ��ȡ��ǰ��ͷ���Ԫ����Ϣ
//{
//    return this->m_rear->m_next;        // ���ص�ǰ���е�ͷ���
//}


/**��ʽѭ�������������Ա������ʵ�֡�******************************************************
    CircleLinkQueue( );            // ��ʽѭ�����й��캯��ģ��
    CircleLinkQueue(const DblCircleLinkQueue&copy);       // ��ʽѭ�������ิ�ƹ��캯��
    virtual ~CircleLinkQueue( );                // ��ʽѭ��������������ģ��
******************************************************��ʵ�֡���ʽѭ�������������Ա����**/
// �������ƣ�CircleLinkQueue(int size = 100)
// ��ʼ��������ʽѭ�����ж���δ����
// �������������һ���µ���ʽѭ�����ж����ջ
template <class ElemType>
CircleLinkQueue<ElemType>::CircleLinkQueue( )         // ��ʽѭ�����й��캯��ģ��
{
    // ��ʼ����ͷm_front���βm_rearΪͬһ���ڴ�ռ�
    this->m_rear = new Node<ElemType>;          // Ϊ��㿪�ٿռ�
    this->m_rear->m_next = m_rear;              // �ն��е�β���ָ���Լ�����
}

// �������ƣ�CircleLinkQueue(const DblCircleLinkQueue&copy)
// ��ʼ��������ʱ��ȱ
// �����������һ����ʽѭ�����ж���copy������ǰ��ʽѭ�����ж���
template <class ElemType>
CircleLinkQueue<ElemType>::CircleLinkQueue(const CircleLinkQueue<ElemType> &copy)     // ��ʽѭ�������ิ�ƹ��캯��
{
    ///��ʱ��ȱ
    for()
}


// �������ƣ�virtual ~CircleLinkQueue( );
// ��ʼ��������ʱ��ȱ
// �����������һ����ʽѭ�����ж���copy������ǰ��ʽѭ�����ж���
template <class ElemType>
CircleLinkQueue<ElemType>::~CircleLinkQueue( )      // ��ʽѭ��������������ģ��
{
    this->Clear( );
}


/**��ʽѭ������������������ʵ�֡�******************************************************
    int Length( ) const;                // ��ȡ��ǰ��ʽѭ�����е�ջ����
    void Clear( );                      // ��յ�ǰ��ʽѭ������
    bool Empty( ) const;                // �жϵ�ǰ��ʽѭ�������Ƿ�Ϊ��ջ
    bool OutQueue(ElemType) const;           // ����ջ������
    bool InQueue(const ElemType &elem);    // ������elem��ջ
    bool OutQueue(ElemType &elem);           // ������elem��ջ
    ElemType OutQueue( ) const;              // �����ݵ������ҷ���
******************************************************��ʵ�֡���ʽѭ����������������**/
// �������ƣ�int Length( ) const;
// ��ʼ��������ʽѭ�������Ѿ�����
// ������������ص�ǰ��ʽѭ�����е�ջ����
template <class ElemType>
int CircleLinkQueue<ElemType>::Length( ) const      // ��ȡ��ǰ��ʽѭ�����е�ջ����
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Length..." <<std::endl;
#endif
    // ����ʵ��
    //return length;
    int count = 0;
    for(Node<ElemType> *tempPtr = m_rear->m_next;//Node<ElemType> *tempPtr = this->GetFrontPtr( );// ָ���һ��Ԫ��
        tempPtr != this->m_rear;
        tempPtr = tempPtr->m_next)
    {
        count++;
    }

    return count;
}

// �������ƣ�void Clear( );
// ��ʼ��������ʽѭ�������Ѿ�����
// ������������ص�ǰ��ʽѭ�����е�ջ����
template <class ElemType>
void CircleLinkQueue<ElemType>::Clear( )            // ��յ�ǰ��ʽѭ������
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Clear..." <<std::endl;
#endif
    // ����ʵ��
    while(this->Empty() == false)
    {
        this->OutQueue( );
    }
}


// �������ƣ�bool Empty( ) const;
// ��ʼ��������ʽѭ�������Ѿ�����
// ����������жϵ�ǰ��ʽѭ�������Ƿ�Ϊ��ջ
template <class ElemType>
bool CircleLinkQueue<ElemType>::Empty( ) const          // �жϵ�ǰ��ʽѭ�������Ƿ�Ϊ��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Empty..." <<std::endl;
#endif
    // ����ʵ��
    return (this->m_rear->m_next == this->m_rear); // ͷ������βָ��ͬһ����
    //return (this->GetHead() == this->m_rear);
}


// �������ƣ�bool InQueue(const ElemType &elem);
// ��ʼ��������ʽѭ�������Ѿ�����
// ����������жϵ�ǰ��ʽѭ����������
template <class ElemType>
bool CircleLinkQueue<ElemType>::InQueue(const ElemType &elem)    // ������elem��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"InQueue..." <<std::endl;
#endif
    // ����ʵ��
//    if(m_length == 0)   // �����ǰ˳������ǿյ�
//    {
//        this->m_rear->m_data = elem;    // ֱ�ӽ��������������
//        return true;                    //
//    }

    //��������----��������  ��������--{
    Node<ElemType> *newRear = new Node<ElemType>(elem);
    if(newRear == NULL)
    {
        #ifdef REMIND
        std::cout <<"ϵͳ�ڴ��Ѿ��þ�" <<std::endl;
        #endif
        //return false;
        exit(-1);
    }

    newRear->m_next = this->m_rear->m_next; // ʼ�ձ��ֵ�ǰ˳����ж�β�����ͷ����ϵ
    this->m_rear->m_next = newRear;
    this->m_rear = newRear;                 // rearָ���¶�β
    //this->m_length++;
    return true;                            // ��ӳɹ�
}


// �������ƣ�bool OutQueue(ElemType &elem);
// ��ʼ��������ʽѭ�������Ѿ�����
// ����������жϵ�ǰ��ʽѭ����������
template <class ElemType>
bool CircleLinkQueue<ElemType>::GetHead(ElemType &elem)  const       // ������elem��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"GetHead..." <<std::endl;
#endif
    // ����ʵ��
    if(this->Empty() == true)
    {
        #ifdef REMIND
        std::cout <<"��ǰ��ʽѭ������Ϊ��, �޷���ȡ��ͷ��Ϣ..." <<std::endl;
        #endif
        return false;
    }
    elem = this->m_rear->m_next->m_next->m_data;    // ����Ԫ�ص���Ϣ
    //Node<ElemType> *tempPtr = this->GetFrontPtr();
    //Node<ElemType> *tempPtr = this->m_rear->m_next->m_next;
    //elem = tempPtr->m_data;
    return true;
}


// �������ƣ�bool OutQueue(ElemType) const;
// ��ʼ��������ʽѭ�������Ѿ�����
// ����������жϵ�ǰ��ʽѭ����������
template <class ElemType>
bool CircleLinkQueue<ElemType>::OutQueue(ElemType &elem)         // ����ջ������
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"OutQueue..." <<std::endl;
#endif
    // ����ʵ��
    if(this->Empty() == true)
    {
        #ifdef REMIND
        std::cout <<"��ǰ��ʽѭ������Ϊ��, �޷���ȡ��ͷ��Ϣ..." <<std::endl;
        #endif
        return false;
    }
    else
    {
        Node<ElemType> *tempPtr = this->m_rear->m_next->m_next; // ���浱ǰ��ͷ��ָ��
        elem = tempPtr->m_data;     // ���ض�ͷ��������
        this->m_rear->m_next->m_next = tempPtr->m_next;
        if(tempPtr == this->m_rear)  // �����ͷָ���������βָ����ͬһλ��˵����ǰ����ֻ��һ��Ԫ��
        {       // ��ô���Ӻ�û��Ԫ��
            this->m_rear = this->m_rear->m_next;
        }
        /// ��windows������, ����Ĵ������ǳ���, Ϊ�˳����ܹ������ҽ���ע��
        //delete tempPtr;       // ɾ���������ڴ���Ϣ


        return true;
    }
}

// �������ƣ�ElemType OutQueue( ) const;
// ��ʼ��������ʽѭ�������Ѿ�����, ���Ҳ�������
// �����������ջ�������ݷ���
template <class ElemType>
ElemType CircleLinkQueue<ElemType>::OutQueue( )
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
    CircleLinkQueue<EelmType> &operator=(const CircleLinkQueue<ElemType> &copy);        // ���ظ�ֵ�����
****************************************************************��ʵ�֡����ز���������**/
template <class ElemType>
CircleLinkQueue<ElemType>& CircleLinkQueue<ElemType>::operator=(const CircleLinkQueue<ElemType> &copy)
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"OutQueue..." <<std::endl;
#endif
    // ����ʵ��
}


#endif // CircleLinkQueue_H_INCLUDED
