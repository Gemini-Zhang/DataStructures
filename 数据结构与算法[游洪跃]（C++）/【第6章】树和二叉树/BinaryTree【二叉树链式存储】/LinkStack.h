/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : LinkStack.h
Author     : Gatie_Me
Version    : �汾����
Data_Time  : 20112-9-27 19:1:24
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
********************************************************************************/

#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED


#include "Node.h"


//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�


/// ��ʽջ��ģ��
template <class ElemType>
class LinkStack         /// ����ͷ���
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // ��ʽջ������Ա����
    LinkStack( );               // �޲����Ĺ��캯��ģ��

    LinkStack(const LinkStack<ElemType> &copy);     // ���ƹ��캯��ģ��

    virtual ~LinkStack( );      // ��������ģ��

    // ��ʽջ������Ա����
    int Length( ) const;            // ��ȡ��ǰ��ʽջ�ĳ���

    bool Empty( ) const;                // �жϵ�ǰ��ʽջ�Ƿ�Ϊ��ջ

    void Clear( );                      // ��յ�ǰ��ʽջ

    bool Top(ElemType &elem) const;           // ����ջ������

    bool Push(const ElemType &elem);    // ������elem��ջ

    bool Pop(ElemType &elem);           // ������elem��ջ

    ElemType Pop( );              // �����ݵ������ҷ���

    // ���ز���������
    LinkStack<ElemType> &operator=(const LinkStack<ElemType> &copy);        // ���ظ�ֵ�����
/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*=========================��PROTECTED��������Ա��===========================*/
  protected :
  // ��ʽջ���ݳ�Ա
    Node<ElemType> *m_top;      // ջ��ָ��
  // ����������ģ��
    void Init( );               // ��ʼ��ջ
/*=========================��PROTECTED����������Ա��=========================*/
};


/**��������ģ�桾ʵ�֡�**************************************************************
    void Init(int size);        // ��ʼ����ǰջ��Ϣ
**************************************************************��ʵ�֡���������ģ��**/
// �������ƣ�void Init(int size)
// ��ʼ��������ʽջ��Ϣ��Ҫ��ʼ��
// �������������ʽ���������Ԫ�س�ʼ��
template <class ElemType>
void LinkStack<ElemType>::Init( )         // ��ʼ����ǰ����ջ��Ϣ
{
    this->m_top = NULL;     // ���춥ָ��
}


/**��ʽջ�������Ա������ʵ�֡�******************************************************
    LinkStack( );            // ��ʽջ���캯��ģ��
    LinkStack(const LinkStack &copy);       // ��ʽջ�ิ�ƹ��캯��
    virtual ~LinkStack( );                // ��ʽջ��������ģ��
******************************************************��ʵ�֡���ʽջ�������Ա����**/
// �������ƣ�LinkStack(int size = 100)
// ��ʼ��������ʽջ����δ����
// �������������һ���µ���ʽջ�����ջ
template <class ElemType>
LinkStack<ElemType>::LinkStack( )         // ��ʽջ���캯��ģ��
{
    this->Init( );          // ���ó�ʼ������, ����һ����ջ��
}

// �������ƣ�LinkStack(const LinkStack &copy)
// ��ʼ��������ʱ��ȱ
// �����������һ����ʽջ����copy������ǰ��ʽջ����
template <class ElemType>
LinkStack<ElemType>::LinkStack(const LinkStack<ElemType> &copy)     // ��ʽջ�ิ�ƹ��캯��
{
    if(copy.Empty() == true)            // ���copy�ַ���Ϊ��
    {
        this->Init( );                  // ֱ�ӵ��ó�ʼ��������Ŀ������ջ���Ϊ�մ�
    }
    else        // ��������ʽջcop���ǿմ�
    {
        this->m_top = new Node<ElemType>(copy.top->data);       // ���ɵ�ǰջ����Ϣ
        Node<ElemType> *buttomPtr = this->m_top;                    // ��ǰջ����Ϣ

        for(Node<ElemType> *tempPtr = copy.m_top->m_next; tempPtr != NULL; tempPtr = tempPtr->m_next)
        {   // ��ָ��tempPtr���η��ʵ�copyջ�е�Ԫ��
            buttomPtr->m_next = new Node<ElemType>(tempPtr->data);      // ��ջ���������Ԫ��
            buttomPtr = buttomPtr->m_next;          // buttomPtrָ���µ�ջ��
        }
    }
}


// �������ƣ�virtual ~LinkStack( );
// ��ʼ��������ʱ��ȱ
// �����������һ����ʽջ����copy������ǰ��ʽջ����
template <class ElemType>
LinkStack<ElemType>::~LinkStack( )      // ��ʽջ��������ģ��
{
    this->Clear( );             // ��ջ���
}


/**��ʽջ������������ʵ�֡�******************************************************
    int Length( ) const;                // ��ȡ��ǰ��ʽջ��ջ����
    void Clear( );                      // ��յ�ǰ��ʽջ
    bool Empty( ) const;                // �жϵ�ǰ��ʽջ�Ƿ�Ϊ��ջ
    bool Top(ElemType) const;           // ����ջ������
    bool Push(const ElemType &elem);    // ������elem��ջ
    bool Pop(ElemType &elem);           // ������elem��ջ
    ElemType Pop( ) const;              // �����ݵ������ҷ���
******************************************************��ʵ�֡���ʽջ����������**/
// �������ƣ�int Length( ) const;
// ��ʼ��������ʽջ�Ѿ�����
// ������������ص�ǰ��ʽջ��ջ����
template <class ElemType>
int LinkStack<ElemType>::Length( ) const      // ��ȡ��ǰ��ʽջ��ջ����
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Length..." <<std::endl;
#endif
    // ����ʵ��
    int len = 0;
    for(Node<ElemType> *tempPtr = this->m_top; tempPtr != NULL; tempPtr = tempPtr->m_next)
    {   // ��tempPtr����ָ��ÿ��Ԫ��
        len++;          // ��ջ�е�Ԫ�ؽ��м���
    }

    return len;         // ���ؼ�����Ϣ
}

// �������ƣ�void Clear( );
// ��ʼ��������ʽջ�Ѿ�����
// ������������ص�ǰ��ʽջ��ջ����
template <class ElemType>
void LinkStack<ElemType>::Clear( )            // ��յ�ǰ��ʽջ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Clear..." <<std::endl;
#endif
    // ����ʵ��
    ElemType elem;
    while(this->m_top != NULL)      // ֻҪ��ʽջ��η��
    {
        this->Pop(elem);            //��Ԫ����Ϣ����, ����ʵ�����
    }
}


// �������ƣ�bool Empty( ) const;
// ��ʼ��������ʽջ�Ѿ�����
// ����������жϵ�ǰ��ʽջ�Ƿ�Ϊ��ջ
template <class ElemType>
bool LinkStack<ElemType>::Empty( ) const          // �жϵ�ǰ��ʽջ�Ƿ�Ϊ��ջ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Empty..." <<std::endl;
#endif
    // ����ʵ��
    return this->m_top == NULL;         // ���ջ��ָ��Ϊ��, ��˵����ǰ��ʽջΪ��
}

// �������ƣ�bool Top(ElemType) const;
// ��ʼ��������ʽջ�Ѿ�����
// ����������жϵ�ǰ��ʽջ����
template <class ElemType>
bool LinkStack<ElemType>::Top(ElemType &elem) const           // ����ջ������
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Top..." <<std::endl;
#endif
    // ����ʵ��
    if(this->m_top == NULL)     // �����ǰ��ʽջΪ��ջ
    {
        // ��������������Ϣ
        #if define REMIND       // ���ǰ�涨����REMIND��, �����Ϣ���μӱ���
        cout <<"��ǰ��ʽջΪ��, �޷���ȡջ��Ԫ�ص���Ϣ" <<endl;
        #endif

        return false;           // �޷���ȡջ��Ԫ��
    }
    else        // ����ǰ��ʽջ���ǿյ�
    {
        elem = this->m_top->m_data;         // ��ȡ��ʽջջ��Ԫ�ص���Ϣ
        return true;            // ��ȡ�¹�
    }

}

// �������ƣ�bool Push(const ElemType &elem);
// ��ʼ��������ʽջ�Ѿ�����
// ����������жϵ�ǰ��ʽջ����
template <class ElemType>
bool LinkStack<ElemType>::Push(const ElemType &elem)    // ������elem��ջ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Push..." <<std::endl;
#endif
    // ����ʵ��
    Node<ElemType> *newTop = new Node<ElemType>(elem, m_top);     // ���ȿ����µĽ��ռ�, �ý���nextָ��ָ��ջ��m
    if(newTop == NULL)
    {
        // ��������������Ϣ
        #if define REMIND       // ���ǰ�涨����REMIND��, �����Ϣ���μӱ���
        cout <<"��̬�ڴ�ľ�..." <<endl;
        #endif

        return false;
    }
    else
    {
        this->m_top = newTop;     // �����ٵ��½������Ϊ��ջ��

        return true;
    }


}

// �������ƣ�bool Pop(ElemType &elem);
// ��ʼ��������ʽջ�Ѿ�����
// ����������жϵ�ǰ��ʽջ����
template <class ElemType>
bool LinkStack<ElemType>::Pop(ElemType &elem)          // ������elem��ջ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Pop..." <<std::endl;
#endif
    // ����ʵ��
    if(this->m_top == NULL)     // �����ǰ��ʽջΪ��ջ
    {
        // ��������������Ϣ
        #if define REMIND       // ���ǰ�涨����REMIND��, �����Ϣ���μӱ���
        cout <<"��ǰ��ʽջΪ��, �޷���ȡջ��Ԫ�ص���Ϣ" <<endl;
        #endif

        return false;           // �޷���ȡջ��Ԫ��
    }
    else
    {
        Node<ElemType> *oldTop = this->m_top;   // �����ջ��
        elem = oldTop->m_data;          // ��elem���ؾ�ջ����������
        m_top = m_top->m_next;              // ��ջ������Ϊ����ջ�����ݺ��µ�ջ��, Ҳ���Ǿ�ջ������һ�������Ϣ

        return oldTop;          // ɾ����ջ������Ϣ
    }

}


// �������ƣ�ElemType Pop( ) const;
// ��ʼ��������ʽջ�Ѿ�����, ���Ҳ�������
// �����������ջ�������ݷ���
template <class ElemType>
ElemType LinkStack<ElemType>::Pop( )
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Pop..." <<std::endl;
#endif
    ElemType elem;
    if(this->Pop(elem) == true)
    {
        return elem;
    }
    else
    {
        return -1;      // ���ǻ������ĵ�����û�취��Ϊ����һ������
    }
}

// �����ݵ������ҷ���
/**���ز�����������ʵ�֡�****************************************************************
    LinkStack<EelmType> &operator=(const LinkStack<ElemType> &copy);        // ���ظ�ֵ�����
****************************************************************��ʵ�֡����ز���������**/
template <class ElemType>
LinkStack<ElemType>& LinkStack<ElemType>::operator=(const LinkStack<ElemType> &copy)
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Pop..." <<std::endl;
#endif
    // ����ʵ��
    if(copy.Empty() == true)            // ���copy�ַ���Ϊ��
    {
        this->Init( );                  // ֱ�ӵ��ó�ʼ��������Ŀ������ջ���Ϊ�մ�
    }
    else        // ��������ʽջcop���ǿմ�
    {
        this->m_top = new Node<ElemType>(copy.top->data);       // ���ɵ�ǰջ����Ϣ
        Node<ElemType> *buttomPtr = this->m_top;                    // ��ǰջ����Ϣ

        for(Node<ElemType> *tempPtr = copy.m_top->m_next; tempPtr != NULL; tempPtr = tempPtr->m_next)
        {   // ��ָ��tempPtr���η��ʵ�copyջ�е�Ԫ��
            buttomPtr->m_next = new Node<ElemType>(tempPtr->data);      // ��ջ���������Ԫ��
            buttomPtr = buttomPtr->m_next;          // buttomPtrָ���µ�ջ��
        }
    }
}


#endif // LINKSTACK_H_INCLUDED
