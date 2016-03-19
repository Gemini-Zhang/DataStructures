/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : SqDoubleStack.h
Description: ˳��ջSqDoubleStackʵ��ͷ�ļ�
Author     : Gatie_Me
Version    : Copyright 2012
Data_Time  : 20112-9-19 18:11:24
Content    : ���ݽṹ���㷨��C++��������
********************************************************************************/


/********************************************************************************
History    :C++˳��ջ��ʵ��

�汾1.0.0
********************************************************************************/




#ifndef SQDOUBLESTACK_H_INCLUDED
#define SQDOUBLESTACK_H_INCLUDED



//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�

/// ˳��ջ��SqDoubleStack���岿��
template <class ElemType>
class SqDoubleStack
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
    SqDoubleStack(int size = 100);            // ˳��ջ���캯��ģ��

    SqDoubleStack(const SqDoubleStack &copy);       // ˳��ջ�ิ�ƹ��캯��

    virtual ~SqDoubleStack( );                // ˳��ջ��������ģ��

    // ˳��ջ��������������
    int Length(int index = 0) const;                // ��ȡ��ǰ˳��ջ��ջ����

    void Clear(int index = 0);                      // ��յ�ǰ˳��ջ

    void Traverse(void(*Visit)(const ElemType &)) const;        //������ǰ˳��ջ

    bool Empty(int index = 0) const;                // �жϵ�ǰ˳��ջ�Ƿ�Ϊ��ջ

    bool Full( ) const;                 // �ж�ջ�Ƿ�����

    bool Top(int index, ElemType &elem) const;           // ����ջ������

    bool Push(int index, const ElemType &elem);    // ������elem��ջ

    bool Pop(int index, ElemType &elem);           // ������elem��ջ

    ElemType Pop(int index);              // �����ݵ������ҷ���

    // ���ز���������
    SqDoubleStack<ElemType> &operator=(const SqDoubleStack<ElemType> &copy);        // ���ظ�ֵ�����
/*===========================[PUBLIC-=>�����ӿ�]===========================*/


/*==========================[PROTECTED-=>��������]==========================*/
  protected :   /// ˳��ջ�ı�����Ա
    // ˳��ջ�����ݳ�Ա
    ElemType *m_elems;            // Ԫ�ش洢�Ŀռ�
    int m_maxSize;                // ջ���ռ伴���Ԫ�ظ���
    int m_leftLen;                // ��ջԪ�ظ���
    int m_rightLen;               // ��ջԪ�ظ���

    // ��������ģ��
    void Init(int size = 100);        // ��ʼ����ǰջ��Ϣ
/*==========================[PROTECTED-=>��������]==========================*/
};


/// ˳��ջ��SqDoubleStackʵ�ֲ���
/**��������ģ�桾ʵ�֡�**************************************************************
    void Init(int size);        // ��ʼ����ǰջ��Ϣ
**************************************************************��ʵ�֡���������ģ��**/
// �������ƣ�void Init(int size)
// ��ʼ������˳��ջ��Ϣ��Ҫ��ʼ��
// �����������˳����������Ԫ�س�ʼ��
template <class ElemType>
void SqDoubleStack<ElemType>::Init(int size/*= 100*/)         // ��ʼ����ǰ����ջ��Ϣ
{
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Length..." <<std::endl;
#endif
    m_elems = new ElemType[size];    // ���ٿռ�
    if(m_elems == NULL)
    {
        #ifdef REMIND
        std::cout <<"�ڴ�ռ䲻��..." <<std::endl;
        #endif
        exit(-1);
    }
    this->m_maxSize = size;
    this->m_leftLen = 0;
    this->m_rightLen = 0;
}


/**˳��ջ�������Ա������ʵ�֡�******************************************************
    SqDoubleStack(int size = 100);            // ˳��ջ���캯��ģ��
    SqDoubleStack(const SqDoubleStack &copy);       // ˳��ջ�ิ�ƹ��캯��
    virtual ~SqDoubleStack( );                // ˳��ջ��������ģ��
******************************************************��ʵ�֡�˳��ջ�������Ա����**/
// �������ƣ�SqDoubleStack(int size = 100)
// ��ʼ������˳��ջ����δ����
// �������������һ���µ�˳��ջ����
template <class ElemType>
SqDoubleStack<ElemType>::SqDoubleStack(int size/* = 100*/)         // ˳��ջ���캯��ģ��
{
    this->m_elems = new ElemType[size];    // ���ٿռ�
    if(m_elems == NULL)
    {
        #ifdef REMIND
        std::cout <<"�ڴ�ռ䲻��..." <<std::endl;
        #endif
        exit(-1);
    }
    this->m_maxSize = size;
    this->m_leftLen = 0;
    this->m_rightLen = 0;
}

// �������ƣ�SqDoubleStack(const SqDoubleStack &copy)
// ��ʼ��������ʱ��ȱ
// �����������һ��˳��ջ����copy������ǰ˳��ջ����
template <class ElemType>
SqDoubleStack<ElemType>::SqDoubleStack(const SqDoubleStack<ElemType> &copy)     // ˳��ջ�ิ�ƹ��캯��
{
    this->Init(copy.m_maxSize);     // �Ը�ֵ����˳��ջ�����Ԫ��ֵ��ʼ����ǰ˳��ջ�����Ԫ��
    ///
}


// �������ƣ�virtual ~SqDoubleStack( );
// ��ʼ��������ʱ��ȱ
// �����������һ��˳��ջ����copy������ǰ˳��ջ����
template <class ElemType>
SqDoubleStack<ElemType>::~SqDoubleStack( )      // ˳��ջ��������ģ��
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
int SqDoubleStack<ElemType>::Length(int index/* = 0*/) const      // ��ȡ��ǰ˳��ջ��ջ����
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Length..." <<std::endl;
#endif
    // ����ʵ��
    if(index == 0)      // Ҫ�󷵻���ջ�Ŀռ�
    {
        return m_leftLen + m_rightLen;
    }
    else if(index == -1)    // Ҫ�󷵻���ջ�Ŀռ�
    {
        return m_leftLen;
    }
    else if(index == 1)     // Ҫ�󷵻���ջ�Ŀռ�
    {
        return m_rightLen;
    }
    else                    // �������������
    {
        #ifdef REMIND
        std::cout <<"Length()��������..." <<std::endl;
        #endif
        int in;
        std::cout <<"�������������index" <<std::endl;
        std::cout <<"-1 -= ��ȡ��ջԪ�ظ���" <<std::endl;
        std::cout <<" 0 -= ��ȡ��ջԪ�ظ���" <<std::endl;
        std::cout <<" 1 -= ��ȡ��ջԪ�ظ���" <<std::endl <<std::endl;
        std::cin >>in;
        this->Length(in);
    }
    return false;
}

// �������ƣ�void Clear( );
// ��ʼ������˳��ջ�Ѿ�����
// ������������ص�ǰ˳��ջ��ջ����
template <class ElemType>
void SqDoubleStack<ElemType>::Clear(int index/* = 0*/)            // ��յ�ǰ˳��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Clear..." <<std::endl;
#endif
    // ����ʵ��
    if(index == 0)
    {
        this->m_leftLen = 0;                             // ֱ�ӽ�˳��ջ��ջ����Ϊ0����
        this->m_rightLen = 0;
    }
    else if(index == -1)
    {
        this->m_leftLen = 0;
    }
    else if(index == 1)
    {
        this->m_rightLen = 0;
    }
    else                    // �������������
    {
        #ifdef REMIND
        std::cout <<"Clear()��������..." <<std::endl;
        #endif
        int in;
        std::cout <<"�������������index" <<std::endl;
        std::cout <<"-1 -= �����ջ" <<std::endl;
        std::cout <<" 0 -= �����ջ" <<std::endl;
        std::cout <<" 1 -= �����ջ" <<std::endl <<std::endl;
        std::cin >>in;
        this->Clear(in);
    }
}


// �������ƣ�bool Empty( ) const;
// ��ʼ������˳��ջ�Ѿ�����
// ����������жϵ�ǰ˳��ջ�Ƿ�Ϊ��ջ
template <class ElemType>
bool SqDoubleStack<ElemType>::Empty(int index/* = 0*/) const          // �жϵ�ǰ˳��ջ�Ƿ�Ϊ��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Empty..." <<std::endl;
#endif
    // ����ʵ��
    if(index == 0)
    {
        return (this->m_leftLen == 0                              // ֱ�ӽ�˳��ջ��ջ����Ϊ0����
               && this->m_rightLen == 0);
    }
    else if(index == -1)
    {
        return (this->m_leftLen == 0);
    }
    else if(index == 1)
    {
        return (this->m_rightLen == 0);
    }
    else                    // �������������
    {
        #ifdef REMIND
        std::cout <<"Empty()��������..." <<std::endl;
        #endif
        int in;
        std::cout <<"�������������index" <<std::endl;
        std::cout <<"-1 -= �ж���ջ�Ƿ�Ϊ��" <<std::endl;
        std::cout <<" 0 -= �ж���ջ�Ƿ�Ϊ��" <<std::endl;
        std::cout <<" 1 -= �ж���ջ�Ƿ�Ϊ��" <<std::endl <<std::endl;
        std::cin >>in;
        this->Empty(in);
    }
    return false;
}


// �������ƣ�bool Full( ) const;
// ��ʼ������˳��ջ�Ѿ�����
// ����������жϵ�ǰ˳��ջ����
template <class ElemType>
bool SqDoubleStack<ElemType>::Full( ) const                 // �ж�ջ�Ƿ�����
{
    return (this->m_leftLen + this->m_rightLen == m_maxSize);
}

// �������ƣ�bool Top(ElemType) const;
// ��ʼ������˳��ջ�Ѿ�����
// ����������жϵ�ǰ˳��ջ����
template <class ElemType>
bool SqDoubleStack<ElemType>::Top(int index/* = 0*/, ElemType &elem) const           // ����ջ������
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Top..." <<std::endl;
#endif
    // ����ʵ��
    if(index == -1)
    {
        if(this->m_leftLen == 0)//this->Empty( ) == true // �����ǰ˳��ջ�ǿյ�
        {
            std::cout <<"��ǰ��ջΪ��, �޷�����ջ������" <<std::endl;

            return false;       // �޷���ȡջ������
        }
        else
        {
            elem = this->m_elems[m_leftLen-1];       // ��elems����ջ��Ԫ��
            return true;        // ��ȡջ�����ݳɹ�
        }
    }
    else if(index == 1)
    {
        if(this->m_rightLen == 0)//this->Empty( ) == true // �����ǰ˳��ջ�ǿյ�
        {
            std::cout <<"��ǰ��ջΪ��, �޷�����ջ������" <<std::endl;
            return false;       // �޷���ȡջ������
        }
        else
        {
            elem = this->m_elems[m_maxSize-m_rightLen];       // ��elems����ջ��Ԫ��
            return true;        // ��ȡջ�����ݳɹ�
        }
    }
    else
    {
        #ifdef REMIND
        std::cout <<"Top()��������..." <<std::endl;
        #endif
        int in;
        std::cout <<"�������������index" <<std::endl;
        std::cout <<"-1 -= ��ȡ��ջջ��Ԫ��" <<std::endl;
        std::cout <<" 1 -= �ж���ջջ��Ԫ��" <<std::endl <<std::endl;
        std::cin >>in;
        this->Top(in, elem);
    }
    return false;
}

// �������ƣ�bool Push(const ElemType &elem);
// ��ʼ������˳��ջ�Ѿ�����
// ����������жϵ�ǰ˳��ջ����
template <class ElemType>
bool SqDoubleStack<ElemType>::Push(int index, const ElemType &elem)    // ������elem��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
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
        if(index == -1)
        {
            m_elems[m_leftLen++] = elem;
            return true;
        }
        else if(index == 1)
        {
            m_elems[m_maxSize-m_rightLen-1] = elem;
            m_rightLen++;
            return true;
        }
        else
        {
            #ifdef REMIND
            std::cout <<"Push()��������..." <<std::endl;
            #endif
            int in;
            std::cout <<"�������������index" <<std::endl;
            std::cout <<"-1 -= Ԫ��ѹ����ջ" <<std::endl;
            std::cout <<" 1 -= Ԫ��ѹ����ջ" <<std::endl <<std::endl;
            std::cin >>in;
            this->Push(in, elem);
        }
    }

    return false;
}

// �������ƣ�bool Pop(ElemType &elem);
// ��ʼ������˳��ջ�Ѿ�����
// ����������жϵ�ǰ˳��ջ����
template <class ElemType>
bool SqDoubleStack<ElemType>::Pop(int index, ElemType &elem)          // ������elem��ջ
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Pop..." <<std::endl;
#endif
    // ����ʵ��
    if(index == -1)
    {
        if(this->m_leftLen == 0)//this->Empty( ) == true // �����ǰ˳��ջ�ǿյ�
        {
            std::cout <<"��ǰ��ջΪ��, �޷�����ջ������" <<std::endl;

            return false;       // �޷���ȡջ������
        }
        else
        {
            elem = m_elems[--m_leftLen];       // ��elems����ջ��Ԫ��
            return true;        // ��ȡջ�����ݳɹ�
        }
    }
    else if(index == 1)
    {
        if(this->m_rightLen == 0) // �����ǰ˳��ջ�ǿյ�
        {
            std::cout <<"��ǰ��ջΪ��, �޷�����ջ������" <<std::endl;
            return false;       // �޷���ȡջ������
        }
        else
        {
            elem = this->m_elems[m_maxSize-m_rightLen];       // ��elems����ջ��Ԫ��
            m_rightLen--;
            return true;        // ��ȡջ�����ݳɹ�
        }
    }
    else
    {
        #ifdef REMIND
        std::cout <<"Top()��������..." <<std::endl;
        #endif
        int in;
        std::cout <<"�������������index" <<std::endl;
        std::cout <<"-1 -= ��ȡ��ջջ��Ԫ��" <<std::endl;
        std::cout <<" 1 -= �ж���ջջ��Ԫ��" <<std::endl <<std::endl;
        std::cin >>in;
        this->Pop(in, elem);
    }

   return false;
}


// �������ƣ�ElemType Pop( ) const;
// ��ʼ������˳��ջ�Ѿ�����, ���Ҳ�������
// �����������ջ�������ݷ���
template <class ElemType>
ElemType SqDoubleStack<ElemType>::Pop(int index)
{
    ElemType elem;
    if(this->Pop(index, elem) == true)
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
    SqDoubleStack<EelmType> &operator=(const SqDoubleStack<ElemType> &copy);        // ���ظ�ֵ�����
****************************************************************��ʵ�֡����ز���������**/
template <class ElemType>
SqDoubleStack<ElemType>& SqDoubleStack<ElemType>::operator=(const SqDoubleStack<ElemType> &copy)
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Pop..." <<std::endl;
#endif
    // ����ʵ��
    this->Init(copy.m_maxSize);     // �Ը�ֵ����˳��ջ�����Ԫ��ֵ��ʼ����ǰ˳��ջ�����Ԫ��

    for(int curPosition = 0; curPosition < this->m_length; curPosition++)
    {       // ��curPosition����copy˳��ջ��ÿ��Ԫ��
        this->m_elems[curPosition] = copy.elems[curPosition];      // ͬʱ��copy��ÿ��Ԫ�ظ�����ǰ˳��ջ
    }
}


/*

������24ѹ��ջ��
������46ѹ��ջ��
������30ѹ��ջ��
������17ѹ��ջ��
������33ѹ��ջ��
*/
#endif // SqDoubleStack_H_INCLUDED
