/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : SqStack.h
Description: ˳��ջSqStackʵ��ͷ�ļ�
Author     : Gatie_Me
Version    : Copyright 2012
Data_Time  : 20112-9-19 18:11:24
Content    : ���ݽṹ���㷨��C++��������
********************************************************************************/


/********************************************************************************
History    :C++˳��ջ��ʵ��

�汾1.0.0
********************************************************************************/


#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED

//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�

/// ˳��ջ��SqStack���岿��
template <class ElemType>
class SqStack
{
/*===========================[Friend-=>��Ԫ����]===========================*/
        ///��ʱ��ȱ
/*===========================[Friend-=>��Ԫ����]===========================*/
/////////////////////////////////////////////////////////////////////////////
//
//
/////////////////////////////////////////////////////////////////////////////
/*===========================[PUBLIC-=>�����ӿ�]===========================*/
  public :      ///�����ӿ�
    // ˳��ջ�������Ա����[����]
    SqStack(int size = 100);            // ˳��ջ���캯��ģ��

    SqStack(const SqStack &copy);       // ˳��ջ�ิ�ƹ��캯��

    virtual ~SqStack( );                // ˳��ջ��������ģ��

    // ˳��ջ��������������
    int Length( ) const;                // ��ȡ��ǰ˳��ջ��ջ����

    void Clear( );                      // ��յ�ǰ˳��ջ

    void Traverse(void(*Visit)(const ElemType &)) const;        //������ǰ˳��ջ

    bool Empty( ) const;                // �жϵ�ǰ˳��ջ�Ƿ�Ϊ��ջ

    bool Full( ) const;                 // �ж�ջ�Ƿ�����

    bool Top(ElemType &elem) const;           // ����ջ������

    bool Push(const ElemType &elem);    // ������elem��ջ

    bool Pop(ElemType &elem);           // ������elem��ջ

    ElemType Pop( );              // �����ݵ������ҷ���

    // ���ز���������
    SqStack<ElemType> &operator=(const SqStack<ElemType> &copy);        // ���ظ�ֵ�����
/*===========================[PUBLIC-=>�����ӿ�]===========================*/


/*==========================[PROTECTED-=>��������]==========================*/
  protected :   /// ˳��ջ�ı�����Ա
    // ˳��ջ�����ݳ�Ա
    ElemType *m_elems;            // Ԫ�ش洢�Ŀռ�
    int m_maxSize;                // ���Ԫ�ظ���
    int m_length;                 // ջ��ǰԪ�ظ���

    // ��������ģ��
    void Init(int size = 100);        // ��ʼ����ǰջ��Ϣ


/*==========================[PROTECTED-=>��������]==========================*/
};


/// ˳��ջ��SqStackʵ�ֲ���
/**��������ģ�桾ʵ�֡�**************************************************************
    void Init(int size);        // ��ʼ����ǰջ��Ϣ
**************************************************************��ʵ�֡���������ģ��**/
// �������ƣ�void Init(int size)
// ��ʼ������˳��ջ��Ϣ��Ҫ��ʼ��
// �����������˳����������Ԫ�س�ʼ��
template <class ElemType>
void SqStack<ElemType>::Init(int size/*= 100*/)         // ��ʼ����ǰ����ջ��Ϣ
{
    if(m_elems != NULL)                       // �����ǰ����Ϊ��
    {
        delete []m_elems;                     // ��ɾ��ԭ����������Ϣ
    }
    this->m_maxSize = size;                 // ���ݲ���ȷ�����Ԫ�ص���Ϣ
    this->m_elems = new ElemType[m_maxSize];        // ͬʱ�����µ�����
    this->m_length = 0;
}


/**˳��ջ�������Ա������ʵ�֡�******************************************************
    SqStack(int size = 100);            // ˳��ջ���캯��ģ��
    SqStack(const SqStack &copy);       // ˳��ջ�ิ�ƹ��캯��
    virtual ~SqStack( );                // ˳��ջ��������ģ��
******************************************************��ʵ�֡�˳��ջ�������Ա����**/
// �������ƣ�SqStack(int size = 100)
// ��ʼ������˳��ջ����δ����
// �������������һ���µ�˳��ջ����
template <class ElemType>
SqStack<ElemType>::SqStack(int size/* = 100*/)         // ˳��ջ���캯��ģ��
{
    this->m_maxSize = size;                 // ���ݲ���ȷ�����Ԫ�ص���Ϣ
    this->m_elems = new ElemType[m_maxSize];        // ͬʱ�����µ�����
    this->m_length = 0;
}

// �������ƣ�SqStack(const SqStack &copy)
// ��ʼ��������ʱ��ȱ
// �����������һ��˳��ջ����copy������ǰ˳��ջ����
template <class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType> &copy)     // ˳��ջ�ิ�ƹ��캯��
{
    this->Init(copy.m_maxSize);     // �Ը�ֵ����˳��ջ�����Ԫ��ֵ��ʼ����ǰ˳��ջ�����Ԫ��

    for(int curPosition = 0; curPosition < this->m_length; curPosition++)
    {       // ��curPosition����copy˳��ջ��ÿ��Ԫ��
        this->m_elems[curPosition] = copy.elems[curPosition];      // ͬʱ��copy��ÿ��Ԫ�ظ�����ǰ˳��ջ
    }
}


// �������ƣ�virtual ~SqStack( );
// ��ʼ��������ʱ��ȱ
// �����������һ��˳��ջ����copy������ǰ˳��ջ����
template <class ElemType>
SqStack<ElemType>::~SqStack( )      // ˳��ջ��������ģ��
{
    if(m_elems != NULL)             // �����ǰ����ջ�ռ䲻Ϊ��
    {
        delete []m_elems;           // ��ɾ����ǰջ��Ϣ���ѷ���ѿռ�
    }
}


/**˳��ջ������������ʵ�֡�******************************************************
    int Length( ) const;                // ��ȡ��ǰ˳��ջ��ջ����
    void Clear( );                      // ��յ�ǰ˳��ջ
    void Traverse(void(*Visit)(const ElemType<ElemType> &)) const//������ǰ˳��ջ
    bool Empty( ) const;                // �жϵ�ǰ˳��ջ�Ƿ�Ϊ��ջ
    bool Full( ) const;                 // �ж�ջ�Ƿ�����
    bool Top(ElemType) const;           // ����ջ������
    bool Push(const ElemType &elem);    // ������elem��ջ
    bool Pop(ElemType &elem);           // ������elem��ջ
    ElemType Pop( ) const;              // �����ݵ������ҷ���
******************************************************��ʵ�֡�˳��ջ����������**/
// �������ƣ�int Length( ) const;
// ��ʼ������˳��ջ�Ѿ�����
// ������������ص�ǰ˳��ջ��ջ����
template <class ElemType>
int SqStack<ElemType>::Length( ) const      // ��ȡ��ǰ˳��ջ��ջ����
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Length..." <<std::endl;
#endif
    // ����ʵ��
    return m_length;                      // ���ص�ǰ˳��ջ��ջ��
}

// �������ƣ�void Clear( );
// ��ʼ������˳��ջ�Ѿ�����
// ������������ص�ǰ˳��ջ��ջ����
template <class ElemType>
void SqStack<ElemType>::Clear( )            // ��յ�ǰ˳��ջ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Clear..." <<std::endl;
#endif
    // ����ʵ��
    this->m_length = 0;                             // ֱ�ӽ�˳��ջ��ջ����Ϊ0����
}

// �������ƣ�void Traverse(void(*Visit)(const ElemType<ElemType> &)) const//������ǰ˳��ջ
// ��ʼ������˳��ջ�Ѿ�����
// �����������ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���(*visit)
template <class ElemType>
void SqStack<ElemType>::Traverse(void(*Visit)(const ElemType &)) const       //������ǰ˳��ջ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Traverse..." <<std::endl;
#endif
    // ����ʵ��
    // ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���(*visit)
    for(int curPosition = 0; curPosition < this->m_length; curPosition++)
    {
        (*Visit)(m_elems[curPosition]);
    }
}


// �������ƣ�bool Empty( ) const;
// ��ʼ������˳��ջ�Ѿ�����
// ����������жϵ�ǰ˳��ջ�Ƿ�Ϊ��ջ
template <class ElemType>
bool SqStack<ElemType>::Empty( ) const          // �жϵ�ǰ˳��ջ�Ƿ�Ϊ��ջ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Empty..." <<std::endl;
#endif
    // ����ʵ��
    return m_length == 0;           // ���˳��ջΪ��(m_length == 0)�򷵻�true, ���򷵻�false
}


// �������ƣ�bool Full( ) const;
// ��ʼ������˳��ջ�Ѿ�����
// ����������жϵ�ǰ˳��ջ����
template <class ElemType>
bool SqStack<ElemType>::Full( ) const                 // �ж�ջ�Ƿ�����
{
    return m_length == m_maxSize;       // ���˳��ջ����(m_length == m_maxSize)�򷵻�true, ���򷵻�false
}

// �������ƣ�bool Top(ElemType) const;
// ��ʼ������˳��ջ�Ѿ�����
// ����������жϵ�ǰ˳��ջ����
template <class ElemType>
bool SqStack<ElemType>::Top(ElemType &elem) const           // ����ջ������
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Top..." <<std::endl;
#endif
    // ����ʵ��
    if(this->m_length == 0)//this->Empty( ) == true // �����ǰ˳��ջ�ǿյ�
    {
        std::cout <<"��ǰ���Ա�Ϊ��, �޷�����ջ������" <<std::endl;

        return false;       // �޷���ȡջ������
    }
    else
    {
        elem = this->m_elems[m_length-1];       // ��elems����ջ��Ԫ��

        return true;        // ��ȡջ�����ݳɹ�
    }
}

// �������ƣ�bool Push(const ElemType &elem);
// ��ʼ������˳��ջ�Ѿ�����
// ����������жϵ�ǰ˳��ջ����
template <class ElemType>
bool SqStack<ElemType>::Push(const ElemType &elem)    // ������elem��ջ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Push..." <<std::endl;
#endif
    // ����ʵ��
    if(this->Full( ))//this->m_length == this->m_maxSize       // �����ǰջ����ջ
    {
        std::cout <<"��ǰ˳��ջ�Ѿ�����, �޷��ٽ�����ѹ��ջ..." <<std::endl; // ��ʾ��Ϣ
        return false;                   // ��ջʧ��
    }
    else
    {
        this->m_elems[m_length++] = elem;           // ������elemѹ��ջ��
        return true;                        // ��ջ�ɹ�
    }
}

// �������ƣ�bool Pop(ElemType &elem);
// ��ʼ������˳��ջ�Ѿ�����
// ����������жϵ�ǰ˳��ջ����
template <class ElemType>
bool SqStack<ElemType>::Pop(ElemType &elem)          // ������elem��ջ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Pop..." <<std::endl;
#endif
    // ����ʵ��
    if(this->Empty( ))//this->m_length == 0     // �����ǰ˳��ջΪ��
    {
        std::cout <<"��ǰ˳��ջΪ��, �޷������ݵ���ջ..." <<std::endl;
        return false;           // ��ջʧ��
    }
    else
    {
        elem = this->m_elems[--m_length];   // ��elem���ؼ���������Ԫ��
        return true;                // ��ջ�ɹ�
    }
}


// �������ƣ�ElemType Pop( ) const;
// ��ʼ������˳��ջ�Ѿ�����, ���Ҳ�������
// �����������ջ�������ݷ���
template <class ElemType>
ElemType SqStack<ElemType>::Pop( )
{
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
    SqStack<EelmType> &operator=(const SqStack<ElemType> &copy);        // ���ظ�ֵ�����
****************************************************************��ʵ�֡����ز���������**/
template <class ElemType>
SqStack<ElemType>& SqStack<ElemType>::operator=(const SqStack<ElemType> &copy)
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Pop..." <<std::endl;
#endif
    // ����ʵ��
    this->Init(copy.m_maxSize);     // �Ը�ֵ����˳��ջ�����Ԫ��ֵ��ʼ����ǰ˳��ջ�����Ԫ��

    for(int curPosition = 0; curPosition < this->m_length; curPosition++)
    {       // ��curPosition����copy˳��ջ��ÿ��Ԫ��
        this->m_elems[curPosition] = copy.elems[curPosition];      // ͬʱ��copy��ÿ��Ԫ�ظ�����ǰ˳��ջ
    }
}





#endif // SQSTACK_H_INCLUDED
