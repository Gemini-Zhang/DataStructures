/**
*********************************************************************************
*   CopyRight  : 2012-2013, HerBinUnversity, GatieMe                            *
*   File Name  : RefGenListNode.cpp                                             *
*   Description: �����������������RefGenListNodeͷ�ļ�                      *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2012                                                 *
*   Data_Time  : 20112-10-30 18:43:34                                           *
*   Content    : ���ݽṹ���㷨��C++��������Դ��                               *
*********************************************************************************
**/




/// ���ȶ���һ���������ö����
#ifndef REFGENLISTNODETYPE_INCLUDE
#define REFGENLISTNODETYPE_INCLUDE

// �������ö����
typedef enum{
    HEAD,   // ��ʾΪͷ���,
    DATA,   // ��ʾΪԭ�ӽ��
    LIST,   // ��ʾΪ����
}RefGenListNodeType;

#endif      // �����������ö����ı�����Ϣ



#ifndef REFGENLISTNODE_H_INCLUDED
#define REFGENLISTNODE_H_INCLUDED


/// �����������������ģ��
template <class ElemType>
struct RefGenListNode
{
    // ���ݳ�Ա��
    RefGenListNodeType m_tag;       // ö�������ʶ
    // ��ʶtagΪHEAD[0]:��ʾ��ǰ���Ϊͷ���
    // ��ʶtagΪATOM[1]:��ʾ��ǰ���Ϊԭ�����ݽ��
    // ��ʶtagΪLIST[2]:��ʾ��ǰ���Ϊ����
    union          // ������[���ݱ�ʶȷ�������������]
    {
        int m_ref;          // tag=HEAD[0] -=> ��ͷ����������, ���ڴ��������
        ElemType m_data;    // tag=ATOM[1] -=> ԭ�ӽ���������, ���ڴ��ԭ��Ԫ�ص�ֵ
        RefGenListNode<ElemType> *m_subLink;    // tag=LIST[2] -=>  ����ָ����, ���ڴ�ű�ĵ�ַ
    };
    RefGenListNode<ElemType> *m_nextLink;   // ָ����һ������ָ����

    // ��Ա����
    RefGenListNode(RefGenListNodeType tag = HEAD, RefGenListNode<ElemType> *nextLink = NULL)    // ������
    {
        m_tag = tag;        //ȷ����ǰ���ı�ʶ��Ϣ
        switch(m_tag)   // �ɱ�ʶtag����������Ϣ
        {
            case 0: m_ref = 1;
            case 1: m_data = 0 ;
            case 2: m_subLink = NULL;
        }
        m_nextLink = nextLink;

    }
};


#endif // REFGENLISTNODE_H_INCLUDED
