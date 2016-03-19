/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : BinTreeNode.h                                                *
*  Description: ����������BinTree�����������ģ��ͷ�ļ�                    *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/

#ifndef BINTREENODE_H_INCLUDED
#define BINTREENODE_H_INCLUDED


/// �����������ģ����������
template <class ElemType>
class BinTreeNode
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�

    // �����������BinTreeNode���ݳ�Ա
    ElemType m_data;                        // ���������
    BinTreeNode<ElemType> *m_leftChild;     // ���ӽ��ָ����
    BinTreeNode<ElemType> *m_rightChild;    // ���ӽ��ָ����

    // �����������BinTreeNode������Ա����
    BinTreeNode( );     // Ĭ�Ϲ��캯��ģ��

    BinTreeNode(const ElemType &data, BinTreeNode<ElemType> *leftChild = NULL, BinTreeNode<ElemType> *rightChild = NULL);     // ���ƹ��캯��

    virtual ~BinTreeNode( );

    BinTreeNode<ElemType> &operator=(const BinTreeNode<ElemType> &copy);        // ���ظ�ֵ�����

    // ��Ԫ��˳���[ϡ�����]��������Ա����
    /*--------------��ʱ��ȱ--------------*/
/*===========================��PUBLIC�������ӿڡ�============================*/
};



/// �����������ģ��ʵ�ֲ���

// �������ƣ�BinTreeNode( );
// �������������һ��Ҷ�ӽڵ�, ��ָ������ȷ��ʼ��
template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode( )       // Ĭ�Ϲ��캯��ģ��
{
    m_leftChild = m_rightChild = NULL;  // Ҷ�ӽ���ָ����Ϊ��
}

// �������ƣ�BinTreeNode(const ElemType &data, BinTreeNode<ElemType> *leftChild = NULL, BinTreeNode<ElemType> *rightChild = NULL);
// �������������һ��Ҷ�ӽڵ�, ��ָ������ȷ��ʼ��
template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType &data, BinTreeNode<ElemType> *leftChild/*= NULL*/, BinTreeNode<ElemType> *rightChild/*= NULL*/)    // ���ƹ��캯��
{
    m_data = data;
    m_leftChild = leftChild;
    m_rightChild = rightChild;
}

// �������ƣ�virtual ~BinTreeNode( );
// �����������ȷɾ���Ѿ�������ڴ�ռ�
template <class ElemType>
BinTreeNode<ElemType>::~BinTreeNode( )      // ����������ģ��
{
    if(m_leftChild != NULL)
    {
        delete m_leftChild;
    }
    if(m_rightChild != NULL)
    {
        delete m_rightChild;
    }
}


// �������ƣ�BinTreeNode<ElemType> &operator=(const BinTreeNode<ElemType> &copy);
template <class ElemType>
BinTreeNode<ElemType>& BinTreeNode<ElemType>::operator=(const BinTreeNode<ElemType> &copy) // ���ظ�ֵ�����
{
    this.m_data = copy.m_data;
    /**
            ��ʱ��ȱ�ĺ�����Ϣ
    **/
}

#endif // BINTREENODE_H_INCLUDED
