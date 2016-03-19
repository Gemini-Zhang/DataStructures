/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  :��00��ACMģ��
Description: ������ϸ˵���˳����ļ���ɵ���Ҫ����, ������ģ������Ľӿڡ�
             ���ֵ��ȡֵ��Χ�����弰������Ŀ��ơ�˳�򡢶����������ȹ�ϵ
Author     : Gatie_Me
Version    : �汾����
Data_Time  : 20112-8-4 15:36:24
Content    : ������Acm����Problem List��1005Beavergnaw��
History    : ��ϸ��Ϣ����
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
********************************************************************************/

/********************************************************************************
Problem    :ACM��Ŀ��Ϣ����ϸ����
********************************************************************************/


#ifndef SIMPLELINKLIST_H_INCLUDED
#define SIMPLELINKLIST_H_INCLUDED





///�����ģ�涨�岿��
template <class ElemType>
class Node
{
/*=========================��PUBLIC�������ӿڡ�=========================*/
  public :
// ��Ļ�����Ա����
    Node( );                   //Ĭ�Ϲ��캯��ģ��

    Node(const ElemType elem, Node<ElemType> *link = NULL);     //�������Ĺ��캯��ģ��

    virtual ~Node( );           //����������ģ��
// ������Ա����
    void SetNode(const ElemType &elem, Node<ElemType> *link = NULL);     // ���ý�������

    void SetElem(const ElemType &elem);         // ���Ľ���������
// ���ݳ�Ա:PUBLIC
    ElemType m_data;              // ������[���洢������]
    Node<ElemType> *m_next;   // ָ����[ָ����һ��������ݵ�ַ��ָ��]
/*=========================��PUBLIC�������ӿڡ�=========================*/
};



///�����ģ��ʵ�ֲ���
//�������ƣ�Node( );
//��ʼ������Node����δ����
//�������������һ����������Ϣ��Node����
template <class ElemType>
Node<ElemType>::Node( )                   //Ĭ�Ϲ��캯��ģ��
{
    m_next = NULL;
}

//�������ƣ�Node(ElemType item, Node<ElemType> *link = NULL);
//��ʼ������Node����δ����
//�������������һ����������Ϣ��Node����
template <class ElemType>
Node<ElemType>::Node(const ElemType elem, Node<ElemType> *link/*= NULL*/)         //�������Ĺ��캯��ģ��
{
    m_data = elem;
    m_next = link;
}

//�������ƣ�virtual ~Node( );
//��ʼ������Node����δ����
//������������ն���ǰ, ���ٿ��ٵĶ��ڴ�
template <class ElemType>
Node<ElemType>::~Node( )         //����������ģ��
{
    if(m_next != NULL)
    {
        delete m_next;
    }
}

// �������ƣ�void SetElem(const ElemType &elem, Node<ElemType> *link = NULL);
// ��ʼ����������Ѿ�����
// ����������϶����Ľ�������ָ����
template <class ElemType>
void Node<ElemType>::SetNode(const ElemType &elem, Node<ElemType> *link/*= NULL*/)     // ���ý�������
{
    this->m_data = elem;            // ����������
    this->m_next = link;            // ����ָ����
}

// �������ƣ�void SetElem(const ElemType &elem)
// ��ʼ����������Ѿ�����
// ������������Ľ���������
template <class ElemType>
void Node<ElemType>::SetElem(const ElemType &elem)
{
    this->m_data = elem;
}



// �и�����Ϊʲô���캯��Node(), �Լ�SetNode()�е�ָ����������ܶ���Ϊconst����
#endif // SIMPLELINKLIST_H_INCLUDED
