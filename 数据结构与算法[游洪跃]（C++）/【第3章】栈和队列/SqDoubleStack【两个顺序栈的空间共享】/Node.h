/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : Node.h
Author     : Gatie_Me
Version    : �汾����
Data_Time  : 20112-9-27 19:1:24
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
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

#endif // SIMPLELINKLIST_H_INCLUDED
