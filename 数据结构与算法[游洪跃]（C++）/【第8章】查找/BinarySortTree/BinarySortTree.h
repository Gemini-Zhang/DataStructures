/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : BinTreeNode.h                                                *
*  Description: ����������BinarySortTreeͷ�ļ�                              *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/


#ifndef BINARYSORTTREE_H_INCLUDED
#define BINARYSORTTREE_H_INCLUDED

/// ����������BinarySortTree��������
template <class ElemType, class KeyType>
class BinarySortTree
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // ����������BinarySortTree������Ա����
    BinarySortTree( );          // Ĭ�Ϲ��캯��

    BinarySortTree(BinTreeNode<ElemType> *root);        // ������rootΪ���Ķ���������

    BinarySortTree(const BinarySortTree<ElemType, KeyType> &copy); // ���ƹ��캯��

    BinarySortTree<ElemType, KeyType> &operator=(const BinarySortTree<ElemType, KeyType> &copy);    // ���ظ�ֵ�����
    virtual ~BinarySortTree( );         // ����������

    // ����������BinarySortTree������Ա����
    BinTreeNode<ElemType>* GetRoot( ) const;      // ��ȡ�����������ĸ�

    bool Empty( ) const;                // �жϵ�ǰ�����������ǲ��ǿ�

    int NodeCount( ) const;             // ������������Ľ�����

    int Height( ) const;                // ������������ĸ߶�

    BinTreeNode<ElemType>* LeftChild(const BinTreeNode<ElemType> *cur) const;       // ���ض���������������

    BinTreeNode<ElemType>* RightChild(const BinTreeNode<ElemType> *cur) const;       // ���ض���������������

    BinTreeNode<ElemType>* Parent(const BinTreeNode<ElemType> *cur) const;       // ���ض���������������

    bool GetElem(BinarySortTree<ElemType> *cur, ElemType &elem) const;  // ��elem���ؽ������Ԫ��ֵ
    ElemType GetElem(BinarySortTree<ElemType> *cur) const;              // ֱ�ӷ��ؽ������Ԫ��ֵ

    bool SetElem(BinarySortTree<ElemType> *cur, ElemType &elem) const;  // ����cue�������Ԫ��ֵΪelem

    // ����������BinarySortTree��������
    void InOrder(void (* Visit)(const ElemType &)) const;               // �������������������

    void PreOrder(void (* Visit)(const ElemType &)) const;               // �������������������

    void PostOrder(void (* Visit)(const ElemType &)) const;               // �����������ĺ������

    void LevelOrder(void (* Visit)(const ElemType &)) const;               // �����������Ĳ�α���
/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
/////////////////////////////////////////////////////////////////////////////////
/*===========================��PROTECTED:������Ա��============================*/
  protected :   // �������ݳ�Ա
    // ����������BinarySortTree���ݳ�Ա
    BinTreeNode *m_root;          // �����������

    // ����������BinarySortTree��������ģ��
    BinTreeNode<ElemType> *CopyTree(BinarySortTree<ElemType> *copy);    // ���ƶ���������

    void Destroy(BinTreeNode<ElemType> * &root);        // ������rootΪ���Ķ���������

    void InOrder(const BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;               // �������������������

    void PreOrder(const BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;               // �������������������

    void PostOrder(const BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;               // �����������ĺ������

    void LevelOrder(const BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;               // �����������Ĳ�α���

/*===========================��PROTECTED:������Ա��============================*/
};
#endif // BINARYSORTTREE_H_INCLUDED
