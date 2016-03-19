/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : SqQueue.h
Description: ˳��ѭ�����ж���ͷ�ļ�
Author     : Gatie_Me
Version    : �汾����
Data_Time  : 20112-9-27 19:1:24
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
********************************************************************************/

#ifndef SqQueue_H_INCLUDED
#define SqQueue_H_INCLUDED



//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�
#define DEFAULT_SIZE  100

/// ˳��ѭ��������ģ��
template <class ElemType>
class SqQueue        /// ��ͷ���
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // ˳��ѭ�����л�����Ա����
    SqQueue(int size = DEFAULT_SIZE);               // �޲����Ĺ��캯��ģ��

    SqQueue(const SqQueue<ElemType> &copy);     // ���ƹ��캯��ģ��

    virtual ~SqQueue( );      // ��������ģ��

    // ˳��ѭ������������Ա����
    int Length( ) const;            // ��ȡ��ǰ˳��ѭ�����еĳ���

    bool Empty( ) const;                // �жϵ�ǰ˳��ѭ�������Ƿ�Ϊ��

    bool Full( ) const;                 // �жϵ�ǰ˳��ѭ�������Ƿ�����

    void Clear( );                      // ��յ�ǰ˳��ѭ������

    bool GetHead(ElemType &elem) const;           // ���ض��ж�����

    bool InQueue(const ElemType &elem);    // ������elem�����

    bool OutQueue(ElemType &elem);           // ������elem������

    ElemType OutQueue( );              // �����ݵ������ҷ���

    // ���ز���������
    SqQueue<ElemType> &operator=(const SqQueue<ElemType> &copy);        // ���ظ�ֵ�����
/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*=========================��PROTECTED��������Ա��===========================*/
  protected :
    // ˳��ѭ���������ݳ�Ա
    int m_front/*��ͷ*/, m_rear/*��β*/;     // ���ж�ָ��
    int m_maxSize;                          // �������Ԫ�ظ���
    ElemType *m_elems;                        // Ԫ�ش洢�ռ�


    // ����������ģ��
    void Init( );               // ��ʼ������
/*=========================��PROTECTED����������Ա��=========================*/
};


/**��������ģ�桾ʵ�֡�**************************************************************
    void Init(int size);        // ��ʼ����ǰ������Ϣ
**************************************************************��ʵ�֡���������ģ��**/
// �������ƣ�void Init(int size)
// ��ʼ������˳��ѭ��������Ϣ��Ҫ��ʼ��
// �����������˳����������Ԫ�س�ʼ��
template <class ElemType>
void SqQueue<ElemType>::Init( )         // ��ʼ����ǰ���Զ�����Ϣ
{
    this->m_front = this->m_rear = 0;       // ��ʼ����ǰ��ͷ�Ͷ�β��ָ���ʼ0�±�
}


/**˳��ѭ�������������Ա������ʵ�֡�******************************************************
    SqQueue( );            // ˳��ѭ�����й��캯��ģ��
    SqQueue(const SqQueue&copy);       // ˳��ѭ�������ิ�ƹ��캯��
    virtual ~SqQueue( );                // ˳��ѭ��������������ģ��
******************************************************��ʵ�֡�˳��ѭ�������������Ա����**/
// �������ƣ�SqQueue(int size = DEFAULT_SIZE)
// ��ʼ������˳��ѭ�����ж���δ����
// �������������һ���µ�˳��ѭ�����ж���ն���
template <class ElemType>
SqQueue<ElemType>::SqQueue(int size/* = DEFAULT_SIZE*/)         // ˳��ѭ�����й��캯��ģ��
{
    this->m_elems =  new ElemType[size];    // Ϊ���п����ڴ�ռ�
    if(this->m_elems == NULL)
    {
        #ifdef REMIND
        std::cout <<"ϵͳ�ڴ治��" <<std::endl;
        #endif
        exit(-1);
    }
    this->m_maxSize = size-1;           // ���ö��е����Ԫ��ֵ
    this->m_front = this->m_rear = 0;   // ��ʼ����ǰ��ͷ�Ͷ�β��ָ���ʼ0�±�
}

// �������ƣ�SqQueue(const SqQueue&copy)
// ��ʼ��������ʱ��ȱ
// �����������һ��˳��ѭ�����ж���copy������ǰ˳��ѭ�����ж���
template <class ElemType>
SqQueue<ElemType>::SqQueue(const SqQueue<ElemType> &copy)     // ˳��ѭ�������ิ�ƹ��캯��
{
    this->m_elems = new ElemType[copy.m_maxSize+1]; // ���ո�ֵ���еĴ�С��Ϣ���ٿռ�

    if(this->m_elems == NULL)
    {
        #ifdef REMIND
        std::cout <<"ϵͳ�ڴ治��" <<std::endl;
        #endif
        exit(-1);
    }

    this->m_maxSize = copy.m_maxSize;
    this->m_front = copy.m_front;
    this->m_rear = copy.m_rear;

    // Ϊ���е�ÿ��Ԫ�ظ�ֵ
    for(int curPosition = this->m_front;
            curPosition != this->m_rear;
            curPosition = (curPosition+1)%(this->m_maxSize+1))
    {
        this->elems[curPosition] = this->copy.m_elems[curPosition];
    }
}


// �������ƣ�virtual ~SqQueue( );
// ��ʼ��������ʱ��ȱ
// ������������ٶ�����ڴ�ռ�
template <class ElemType>
SqQueue<ElemType>::~SqQueue( )      // ˳��ѭ��������������ģ��
{
    delete[] this->m_elems;     // ɾ���ڴ�ռ�
}


/**˳��ѭ������������������ʵ�֡�******************************************************
    int Length( ) const;                // ��ȡ��ǰ˳��ѭ�����еĶ��г���
    void Clear( );                      // ��յ�ǰ˳��ѭ������
    bool Empty( ) const;                // �жϵ�ǰ˳��ѭ�������Ƿ�Ϊ�ն���
    bool OutQueue(ElemType) const;           // ���ض��ж�����
    bool InQueue(const ElemType &elem);    // ������elem�����
    bool OutQueue(ElemType &elem);           // ������elem������
    ElemType OutQueue( ) const;              // �����ݵ������ҷ���
******************************************************��ʵ�֡�˳��ѭ����������������**/
// �������ƣ�int Length( ) const;
// ��ʼ������˳��ѭ�������Ѿ�����
// ������������ص�ǰ˳��ѭ�����еĶ��г���
template <class ElemType>
int SqQueue<ElemType>::Length( ) const      // ��ȡ��ǰ˳��ѭ�����еĶ��г���
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Length..." <<std::endl;
#endif
    // ����ʵ��
    return (m_rear - m_front + m_maxSize + 1) % (m_maxSize+1);
}

// �������ƣ�void Clear( );
// ��ʼ������˳��ѭ�������Ѿ�����
// ������������ص�ǰ˳��ѭ�����еĶ��г���
template <class ElemType>
void SqQueue<ElemType>::Clear( )            // ��յ�ǰ˳��ѭ������
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Clear..." <<std::endl;
#endif
    // ����ʵ��
    m_front = m_rear = 0;

}


// �������ƣ�bool Empty( ) const;
// ��ʼ������˳��ѭ�������Ѿ�����
// ����������жϵ�ǰ˳��ѭ�������Ƿ�Ϊ�ն���
template <class ElemType>
bool SqQueue<ElemType>::Empty( ) const          // �жϵ�ǰ˳��ѭ�������Ƿ�Ϊ�ն���
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Empty..." <<std::endl;
#endif
    // ����ʵ��
    return (m_rear == m_front);
}


// �������ƣ�bool Full( ) const;
// ��ʼ������˳��ѭ�������Ѿ�����
// ����������жϵ�ǰ˳��ѭ�������Ƿ�Ϊ�ն���
template <class ElemType>
bool SqQueue<ElemType>::Full( ) const
{
    return (m_rear+1)%(m_maxSize + 1) == m_front;
}

// �������ƣ�bool OutQueue(ElemType &elem);
// ��ʼ������˳��ѭ�������Ѿ�����
// ����������жϵ�ǰ˳��ѭ����������
template <class ElemType>
bool SqQueue<ElemType>::GetHead(ElemType &elem)  const       // ������elem������
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"GetHead..." <<std::endl;
#endif
    // ����ʵ��
    if(this->Empty() == true)   // �����ǰ�����ǿյ�
    {
        #ifdef REMIND
        std::cout <<"��ǰ˳��ѭ������Ϊ��, �޷���ȡ��ͷԪ��" <<std::endl;
        #endif
        return false;
    }
    else
    {
        elem = this->m_elems[m_front];
        return true;
    }
}

// �������ƣ�bool OutQueue(ElemType) const;
// ��ʼ������˳��ѭ�������Ѿ�����
// ����������жϵ�ǰ˳��ѭ����������
template <class ElemType>
bool SqQueue<ElemType>::OutQueue(ElemType &elem)         // ���ض��ж�����
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"OutQueue..." <<std::endl;
#endif
    // ����ʵ��
    if(this->Full( ) == true)   // �����ǰ�����ǿյ�
    {
        #ifdef REMIND
        std::cout <<"��ǰ˳��ѭ����������, �޷��񽫵�ǰԪ�����" <<std::endl;
        #endif
        return false;
    }
    else
    {
        elem = this->m_elems[m_front];
        this->m_front = (m_front + 1) % (m_maxSize + 1);

        return true;
    }
}

// �������ƣ�ElemType OutQueue( ) const;
// ��ʼ������˳��ѭ�������Ѿ�����, ���Ҳ�������
// ��������������ж������ݷ���
template <class ElemType>
ElemType SqQueue<ElemType>::OutQueue( )
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


// �������ƣ�bool InQueue(const ElemType &elem);
// ��ʼ������˳��ѭ�������Ѿ�����
// ����������жϵ�ǰ˳��ѭ����������
template <class ElemType>
bool SqQueue<ElemType>::InQueue(const ElemType &elem)    // ������elem�����
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"InQueue..." <<std::endl;
#endif
    // ����ʵ��
    if(this->Full( ) == true)   // �����ǰ�����ǿյ�
    {
        #ifdef REMIND
        std::cout <<"��ǰ˳��ѭ����������, �޷��񽫵�ǰԪ�����" <<std::endl;
        #endif
        return false;
    }
    else
    {
        this->m_elems[m_rear] = elem;
        this->m_rear = (m_rear + 1) % (m_maxSize + 1);

        return true;
    }
}
// �����ݵ������ҷ���
/**���ز�����������ʵ�֡�****************************************************************
    SqQueue<EelmType> &operator=(const SqQueue<ElemType> &copy);        // ���ظ�ֵ�����
****************************************************************��ʵ�֡����ز���������**/
template <class ElemType>
SqQueue<ElemType>& SqQueue<ElemType>::operator=(const SqQueue<ElemType> &copy)
{
    // ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"OutQueue..." <<std::endl;
#endif
    // ����ʵ��
    this->m_elems = new ElemType[copy.m_maxSize + 1];
    if(m_elems == NULL)
    {
        #ifdef REMIND
        std::cout <<"ϵͳ�ڴ治��" <<std::endl;
        #endif
        exit(-1);
    }

    this->m_maxSize = copy.m_maxSize;
    this->m_front = copy.m_front;
    this->m_rear = copy.m_rear;

    for(int curPosition = m_front;
            curPosition != m_rear;
            curPosition = (curPosition + 1) % (m_maxSize + 1))
    {
        m_elems[curPosition] = copy.m_elems[curPosition];
    }
}


#endif // SqQueue_H_INCLUDED
