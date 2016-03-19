/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : main.cpp                                                     *
*  Description: �ڽӱ�����ͼ��AdjListUndirGraph����ͷ�ļ�                               *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/

#ifndef ADJLISTGRAPHVERTEXNODE_H_INCLUDED
#define ADJLISTGRAPHVERTEXNODE_H_INCLUDED

#include "LinkList.h"

template <class ElemType>
class AdjListGraphVertexNode
{
/*===========================��PUBLIC�������ӿڡ�============================*/
public :      // �����ӿ�
    // �ڽӱ�����ͼ�����AdjListGraphVertexNode���ݳ�Ա
    ElemType m_data;                // ����Ԫ��ֵ
    LinkList<int> *m_adjLink;         // �ڽ�����


    // �ڽӱ�����ͼ�����AdjListGraphVertexNode������Ա����
    AdjListGraphVertexNode( );          // Ĭ�Ϲ��캯��ģ��

    AdjListGraphVertexNode(ElemType elem, LinkList<int> *adjLink = NULL);// ���춥��Ϊelem, ָ���ڽӱ��ָ��ΪadjLink�Ľ��

    AdjListGraphVertexNode(const AdjListGraphVertexNode<ElemType> &copy);   // ���ƹ��캯��

    AdjListGraphVertexNode& operator=(const AdjListGraphVertexNode<ElemType> &copy);   // ��ֵ��������غ���


/*===========================��PUBLIC�������ӿڡ�============================*/
};


/**�ڽӱ�����ͼ�����AdjListGraphVertexNode������Ա����************************************
    AdjListGraphVertexNode( );          // Ĭ�Ϲ��캯��ģ��
    AdjListGraphVertexNode(ElemType elem, LinkList<int> *adjLink = NULL);// ���춥��Ϊelem, ָ���ڽӱ��ָ��ΪadjLink�Ľ��
************************************�ڽӱ�����ͼ�����AdjListGraphVertexNode������Ա����**/
// �������ƣ�AdjListGraphVertexNode( );
// ���������Ĭ�Ϲ��캯��ģ��
template <class ElemType>
AdjListGraphVertexNode<ElemType>::AdjListGraphVertexNode( )          // Ĭ�Ϲ��캯��ģ��
{
    this->m_adjLink = NULL;
}

// �������ƣ�AdjListGraphVertexNode(ElemType elem, LinkList<int> *adjLink = NULL);
// ������������춥��Ϊelem, ָ���ڽӱ��ָ��ΪadjLink�Ľ��
template <class ElemType>
AdjListGraphVertexNode<ElemType>::AdjListGraphVertexNode(ElemType elem, LinkList<int> *adjLink/*= NULL*/)// ���춥��Ϊelem, ָ���ڽӱ��ָ��ΪadjLink�Ľ��
{
    this->m_data = elem;
    this->m_adjLink = adjLink;
}



// �������ƣ�AdjListGraphVertexNode(const AdjListGraphVertexNode<ElemType> &copy);
// ������������ƹ��캯��
template <class ElemType>
AdjListGraphVertexNode<ElemType>::AdjListGraphVertexNode(const AdjListGraphVertexNode<ElemType> &copy)   // ���ƹ��캯��
{
    this->m_data = copy.m_data;
    if(copy.m_adjLink != NULL)
    {
        this->m_adjLink = new LinkList<int>(*copy.m_adjLink);
    }
    else
    {
        this->m_adjLink = NULL;
    }
}

// �������ƣ�AdjListGraphVertexNode& operator=(const AdjListGraphVertexNode<ElemType> &copy);
// �����������ֵ��������غ���
// ������������ƹ��캯��
template <class ElemType>
AdjListGraphVertexNode<ElemType>& AdjListGraphVertexNode<ElemType>::operator=(const AdjListGraphVertexNode<ElemType> &copy)   // ��ֵ��������غ���
{
    if(this == &copy)
    {
        return *this;
    }

    this->m_data = copy.m_data;
    if(copy.m_adjLink != NULL)
    {
        this->m_adjLink = new LinkList<int>(*copy.m_adjLink);
    }
    else
    {
        this->m_adjLink = NULL;
    }

    return (*this);
}



#endif // ADJLISTGRAPHVERTEXNODE_H_INCLUDED
