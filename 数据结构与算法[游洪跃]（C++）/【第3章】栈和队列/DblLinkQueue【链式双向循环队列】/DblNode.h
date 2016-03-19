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


#ifndef DBLlINKQUEUE_H_INCLUDED
#define DBLLINKQUEUE_H_INCLUDED





///�����ģ�涨�岿��
template <class ElemType>
class DblNode
{
/*=========================��PUBLIC�������ӿڡ�=========================*/
  public :
// ��Ļ�����Ա����
    DblNode( );                   //Ĭ�Ϲ��캯��ģ��

    DblNode(const ElemType elem, DblNode<ElemType> *linkBack = NULL, DblNode<ElemType> *linkNext = NULL);     //�������Ĺ��캯��ģ��

    virtual ~DblNode( );           //����������ģ��

// ���ݳ�Ա:PUBLIC
    ElemType m_data;              // ������[���洢������]
    DblNode<ElemType> *m_back;    // ָ����[ָ����һ��������ݵ�ַ��ָ��]
    DblNode<ElemType> *m_next;    // ָ����[ָ����һ��������ݵ�ַ��ָ��]
/*=========================��PUBLIC�������ӿڡ�=========================*/
};



///�����ģ��ʵ�ֲ���
//�������ƣ�DblNode( );
//��ʼ������DblNode����δ����
//�������������һ����������Ϣ��DblNode����
template <class ElemType>
DblNode<ElemType>::DblNode( )                   //Ĭ�Ϲ��캯��ģ��
{
    m_next = NULL;
}

//�������ƣ�DblNode(ElemType item, DblNode<ElemType> *link = NULL);
//��ʼ������DblNode����δ����
//�������������һ����������Ϣ��DblNode����
template <class ElemType>
DblNode<ElemType>::DblNode(const ElemType elem, DblNode<ElemType> *linkBack/*= NULL*/, DblNode<ElemType> *linkNext/* = NULL*/)         //�������Ĺ��캯��ģ��
{
    m_data = elem;
    m_back = linkBack;
    m_next = linkNext;
}

//�������ƣ�virtual ~DblNode( );
//��ʼ������DblNode����δ����
//������������ն���ǰ, ���ٿ��ٵĶ��ڴ�
template <class ElemType>
DblNode<ElemType>::~DblNode( )         //����������ģ��
{
    if(m_back != NULL)
    {
        delete m_back;
    }
    if(m_next != NULL)
    {
        delete m_next;
    }
}

#endif // SIMPLELINKLIST_H_INCLUDED
