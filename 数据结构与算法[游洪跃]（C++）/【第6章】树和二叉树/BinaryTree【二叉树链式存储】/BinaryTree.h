/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : BinaryTree.h                                                    *
*  Description: ������������BinaryTreeģ��ͷ�ļ�                               *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/

/**
2012/11/13_15:41
�����ش�����:
��ȷʹ��&���÷���

�� -=> �ݹ齨������
    void PreCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));  // ����Visit����ǰ����һ����rootΪ������ʽ��������
    void InCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));  // ����Visit����������һ����rootΪ������ʽ��������
    void PostCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));  // ����Visit����������һ����rootΪ������ʽ��������
�в���root����������÷��š�&��, �������ò��������ĳ����޷���ȷ����
�����һ������, �������ʹ������, ��ᷢ���㽫���ò�ʹ��ָ��ָ���ָ��**root�ſ���ֱ�Ӷ�ָ�����ݽ��в���


�����ڻ�ȡ�����Ŀ������ȸ�������ģ����
    int Height(const BinTreeNode<ElemType> * &root) const;	// ���ض������ĸ�
	int NodeCount(const BinTreeNode<ElemType> * &root) const;// ���ض������Ľ�����
�������������á�&��, �����������ĳ���ѹ���޷�ͨ������
**/


#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <stdexcept>        // ��׼�쳣���������
#include <exception>
//using namespace std;

#include "BinTreeNode.h"    // �����������
#include "LinkQueue.h"

//#define DEBUG           // ��׮������Ϣ[�궨��]
#define SHOW        // ���������а�æ��ʾ�ս�����Ϣ

/// ��ʽ��������BinaryTree��������
template <class ElemType>
class BinaryTree
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // ��ʽ��������BinaryTree������Ա����
    BinaryTree( ); // Ĭ�Ϲ��캯��ģ��

	BinaryTree(const ElemType &elem);							// ������eΪ���Ķ�����

	BinaryTree(const BinTreeNode<ElemType> * &root);					// ������rΪ���Ķ�����

    BinaryTree(const BinaryTree<ElemType> &copy);     // ���ƹ��캯��

    virtual ~BinaryTree( );            // ����������ģ��

    BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &copy);

    // ��ʽ��������BinaryTree������Ա����

    // ��ʽ��������BinaryTree����Ϣ��ȡ����
    int NodeCount( ) const;         // ���ض������Ľ�����

    int Height( ) const;            // ���ض����������

    bool Empty( ) const;            // �ж϶������Ƿ�Ϊ��

    BinTreeNode<ElemType>* Search(const ElemType &elem);        // Ѱ������Ԫ�ص�ֵ

    void DeleteNode(BinTreeNode<ElemType> *node); // ɾ���������ĺ���
    // ��ʽ��������BinaryTree�Ľ����Ϣ������
    BinTreeNode<ElemType> *GetRoot( ) const;         // ���ض������ĸ����
    ElemType GetElem(BinTreeNode<ElemType> * &cur) const;               // ���ؽ��cur��Ԫ��ֵ
    void SetElem(BinTreeNode<ElemType> * &cur, ElemType &elem) const;   //�޸Ľ��cur��Ԫ��ֵ

    // ˫�׵Ĵ�����
    BinTreeNode<ElemType> *Parent(const BinTreeNode<ElemType> * &cur) const;      // ��ȡcue����˫�׽��
    // ����Ĵ�����
    BinTreeNode<ElemType> *LeftChild(const BinTreeNode<ElemType> * &cur) const; // ��ȡcur�������ӽ��
    void InsertLeftChild(BinTreeNode<ElemType> * &cur, const ElemType &elem); // ����cur�������ӽ��
    void DeleteLeftChild(BinTreeNode<ElemType> * &cur); // ɾ��cur�������ӽ��
    // �ҽ��Ĵ�����
    BinTreeNode<ElemType> *RightChild(const BinTreeNode<ElemType> * &cur) const; // ��ȡcur�������ӽ��
    void InsertRightChild(BinTreeNode<ElemType> * &cur, const ElemType &elem); // ����cur�������ӽ��
    void DeleteRightChild(BinTreeNode<ElemType> * &cur); // ɾ��cur�������ӽ��

    // ��ʽ��������BinaryTree��������
    // �ݹ齨���㷨
    void PreCreate(void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));          // ���������������
    void InCreate(void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));           // ���������������
    void PostCreate(void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));         // �������ĺ������
    // �ݹ�����㷨
    void PreOrder(void (* Visit)(ElemType &));          // ���������������
    void InOrder(void (* Visit)(ElemType &));           // ���������������
    void PostOrder(void (* Visit)(ElemType &));         // �������ĺ������

    // �ǵݹ�����㷨
    void NonRecurPreOrder(const BinaryTree<ElemType> &root, void (* Visit)(ElemType &));  // �ǵݹ���������㷨
    void NonRecurInOrder(const BinaryTree<ElemType> &root, void (* Visit)(ElemType &));   // �ǵݹ���������㷨
    void NonRecurPostPrder(const BinaryTree<ElemType> &root, void (* Visit)(ElemType &)); // �ǵݹ��������㷨
    void LevelOrder(void (* Visit)(ElemType &));        // �������Ĳ�α���
/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*=========================��PROTECTED��������Ա��===========================*/
  protected :
    // ��ʽ��������BinaryTree���ݳ�Ա
    BinTreeNode<ElemType> *m_root;      // �������Ϣ


    // ������Ա����ģ��[������C����ʵ�ַ���]

    // ������Ա����������Ϣ

	BinTreeNode<ElemType> *CopyTree(BinTreeNode<ElemType> * &copy);	// ���ƶ���������ĸ�������
	void Destroy(BinTreeNode<ElemType> * &root);						// ������rootΪ������������ĸ�������


    // ������ĸ�������
	BinTreeNode<ElemType> *Search(BinTreeNode<ElemType> *&root, const ElemType &elem) const;	        // ������������������Ϊelem�Ķ�һ�����
		// ���ҹؼ���Ϊkey������Ԫ��
    // ������Ա����������Ϣ
    // �ݹ齨������
    void PreCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));  // ����Visit����ǰ����һ����rootΪ������ʽ��������
    void InCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));  // ����Visit����������һ����rootΪ������ʽ��������
    void PostCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));  // ����Visit����������һ����rootΪ������ʽ��������

	// �ݹ麯���ĸ�������
	void PreOrder(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &)) const;	// ���������������
	void InOrder(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &)) const;	// ���������������
	void PostOrder(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &)) const;// ���������������
    // �ǵݹ麯���ĸ�������
    //BinTreeNode<ElemType>* GoFarLeft(BinaryTree<ElemType> *root, LinkStack<BinTreeNode<ElemType>* > &stack);
    void LevelOrder(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &)) const;        // �������Ĳ�α���
    // ��ȡ�����Ŀ������ȸ���ģ��
    int Height(const BinTreeNode<ElemType> *root) const;	// ���ض������ĸ�
	int NodeCount(const BinTreeNode<ElemType> *root) const;// ���ض������Ľ�����

    // ��ȡ�����Ϣ��������
	BinTreeNode<ElemType> *Parent(BinTreeNode<ElemType> * &root, const BinTreeNode<ElemType> * &cur) const;			// ����cur��˫��
};

/**������Ա����ģ��[ʵ��]****************************************************************************
    // ������Ա����������Ϣ
	BinTreeNode<ElemType> *CopyTree(BinTreeNode<ElemType> *copy);	// ���ƶ�����
	void Destroy(BinTreeNode<ElemType> * &root);						// ������rΪ��������
	// ������ĸ�������
    void DeleteNode(BinTreeNode<ElemType> * &node); // ɾ���������ĺ���
	BinTreeNode<ElemType> *SearchHelp(BinTreeNode<ElemType> *&root, const ElemType &elem) const;	        // ������������������Ϊelem�Ķ�һ�����
    // �ݹ齨������
    void PreCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));  // ����Visit����ǰ����һ����rootΪ������ʽ��������
    void InCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));  // ����Visit����������һ����rootΪ������ʽ��������
    void PostCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));  // ����Visit����������һ����rootΪ������ʽ��������
    // ������Ա����������Ϣ
	void PreOrder(BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;	// ���������������
	void InOrder(BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;	// ���������������
	void PostOrder(BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;// ���������������
    // ��ȡ�����Ŀ������ȸ���ģ��
    int Height(const BinTreeNode<ElemType> * &root) const;	// ���ض������ĸ�
	int NodeCount(const BinTreeNode<ElemType> * &root) const;// ���ض������Ľ�����
    // ��ȡ�����Ϣ��������
	BinTreeNode<ElemType> *ParentHelp(BinTreeNode<ElemType> * &root, const BinTreeNode<ElemType> * &cur) const;			// ����cur��˫��
****************************************************************************[ʵ��]������Ա����ģ��**/
/// ������Ա����������Ϣ
// �������ƣ�BinTreeNode<ElemType> *CopyTree(BinTreeNode<ElemType> *copy);
// ����������ݹ鸴��ÿ��������Ϣ
template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::CopyTree(BinTreeNode<ElemType> * &copy)	// ���ƶ�������������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(copy != NULL)    // ֻҪ��ǰ��㲻Ϊ��
    {
        BinTreeNode<ElemType> *leftChild  = CopyTree(copy->m_leftChild);  // ���������Ƶ�ǰ������������Ϣ
        BinTreeNode<ElemType> *rightChild = CopyTree(copy->m_rightChild); // �ѻ񲢸��Ƶ�ǰ������������Ϣ

		BinTreeNode<ElemType> *node = new BinTreeNode<ElemType>(copy->data, leftChild, rightChild); // ���ƽ����Ϣ
        return node;        // ���ص�ǰ���
    }
    else
    {
        return NULL;   // �����ϢΪ��ʱ��ʼ����
    }
}


/// ������ĸ�������
// �������ƣ�void DeleteNode(BinTreeNode<ElemType> *&node)
// ���������ɾ��node������Ϣ
template <class ElemType>
void BinaryTree<ElemType>::DeleteNode(BinTreeNode<ElemType> *node)
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
	BinTreeNode<ElemType> *tempPtr, *tmpF;
	if (node->m_leftChild == NULL && node->m_rightChild == NULL)
	{	// nodeΪҶ���
		delete node;
		node = NULL;
	}
	else if (node->m_leftChild == NULL)
	{	// nodeֻ��������Ϊ��
		tempPtr = node;
		node = node->m_rightChild;
		delete tempPtr;
	}
	else if (node->m_rightChild == NULL)
	{	// nodeֻ���������ǿ�
		tempPtr = node;
		node = node->m_leftChild;
		delete tempPtr;
	}
	else
	{	// node�����ӷǿ�
		tmpF = node;
		tempPtr = node->m_leftChild;
		while (tempPtr->m_rightChild != NULL)
		{	// ����node������������ֱ��ǰ��tempPtr����˫��tmpF,ֱ��tempPtr������Ϊ��
			tmpF = tempPtr;
			tempPtr = tempPtr->m_rightChild;
		}
		node->m_data = tempPtr->m_data;
			// ��tempPtrָ���������Ԫ��ֵ��ֵ��tmpFָ���������Ԫ��ֵ

		// ɾ��tempPtrָ��Ľ��
		if (tmpF->m_rightChild == tempPtr)
		{	// ɾ��tmpF���Һ���
			DeleteNode(tmpF->m_rightChild);
		}
		else
		{	// ɾ��tmpF������
			DeleteNode(tmpF->m_leftChild);
		}
	}
}


// �������ƣ�BinTreeNode<ElemType>* Search(BinTreeNode<ElemType> * &root, const ElemType &elem) const // ������������������Ϊelem�Ķ�һ�����
// ������������������������elem�Ľ��
// ʵ�ַ�����ʵ�ַ������α����ķ�����ͬ, ֻ��Ҫ�ж�������Ϊelem���ؾͿ���
template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::Search(BinTreeNode<ElemType> * &root, const ElemType &elem) const // ������������������Ϊelem�Ķ�һ�����
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(root == NULL)
    {
        throw std::invalid_argument("����curΪ��, �޷���ʼ��α�������Ϣ\n");
    }

    LinkQueue<BinTreeNode<ElemType> *> queue;   // ����һ��������Ϊ��ǰ�����ָ�����͵Ķ���
    BinTreeNode<ElemType> *node = root;          // �ӵ�ǰ����㿪ʼ���в�α���

    queue.InQueue(node);            // ����������

    while(queue.Empty() != true)    // ֻҪ��ǰ���в�Ϊ��, ˵��������δ������
    {
        queue.OutQueue(node);

        //(* Visit)(node->m_data);     // ���ʵ�ǰ����������
        if(node->m_data == elem)        // �����ǰ����������Ϊelem
        {
            return node;
        }

        if(node->m_leftChild != NULL)   // ֻҪ�ý�����Ӵ���
        {
            queue.InQueue(node->m_leftChild);   // ���������
        }

        if(node->m_rightChild != NULL)   // ֻҪ�ý���Һ��Ӵ���
        {
            queue.InQueue(node->m_rightChild);   // ���Һ������
        }
    }

    return NULL;
}

// �������ƣ�void Destroy(BinTreeNode<ElemType> * &root);
// ����������ݹ����ٵ�ǰ���root������
template <class ElemType>
void BinaryTree<ElemType>::Destroy(BinTreeNode<ElemType> * &root)	// ������rΪ��������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(root != NULL)    // ֻҪ��ǰ��㲻Ϊ��
    {
        Destroy(root->m_leftChild);     // �ݹ��������������
        Destroy(root->m_rightChild);    // �ݹ��������������
        delete root;
        root = NULL;            // ��ֹ����Ұָ��
    }
    else
    {
        return;     // ���Ϊ��ʱ��ʼ����
    }
}

/// �ݹ齨������
// �������ƣ�void CreateTree(BinTreeNode<ElrmType> *root, void (* Visit)(ElemType &));
// �������������Visit��������һ����rootΪ������ʽ��������
template <class ElemType>
void BinaryTree<ElemType>::PreCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &))  // ����Visit��������һ����rootΪ������ʽ��������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    ElemType elem;
    (* Visit)(elem);     // ���뵱ǰ�ڵ��������

    if(IsNull(elem) == true)     // ����Ľ��������Ϊ��
    {
        root = NULL;
    }
    else
    {
        root = new BinTreeNode<ElemType>(elem);
        if(root == NULL)
        {
            std::cout <<"�ڴ治��" <<std::endl;
            exit(-1);
        }
        else
        {
            PreCreate(root->m_leftChild, Visit, IsNull);   // �ݹ齨��������
            PreCreate(root->m_rightChild, Visit, IsNull);  // �ݹ齨��������
        }
    }
}
// �������ƣ�void CreateTree(BinTreeNode<ElrmType> *root, void (* Visit)(ElemType &));
// �������������Visit��������һ����rootΪ������ʽ��������
template <class ElemType>
void BinaryTree<ElemType>::InCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &))  // ����Visit��������һ����rootΪ������ʽ��������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    ElemType elem;
    (* Visit)(elem);     // ���뵱ǰ�ڵ��������

    if(IsNull(elem) == true)     // ����Ľ��������Ϊ��
    {
        return;
    }
    else
    {
        root = new BinTreeNode<ElemType>( );
        if(root == NULL)
        {
            std::cout <<"�ڴ治��" <<std::endl;
            exit(-1);
        }
        else
        {
            InCreate(root->m_leftChild, Visit, IsNull);   // �ݹ齨��������
            root->m_data = elem;
            InCreate(root->m_rightChild, Visit, IsNull);  // �ݹ齨��������
        }
    }
}
// �������ƣ�void CreateTree(BinTreeNode<ElrmType> *root, void (* Visit)(ElemType &));
// �������������Visit��������һ����rootΪ������ʽ��������
template <class ElemType>
void BinaryTree<ElemType>::PostCreate(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &), bool (* IsNull)(ElemType &))  // ����Visit��������һ����rootΪ������ʽ��������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    ElemType elem;
    (* Visit)(elem);     // ���뵱ǰ�ڵ��������

    if(IsNull(elem) == true)     // ����Ľ��������Ϊ��
    {
        root = NULL;
    }
    else
    {
        root = new BinTreeNode<ElemType>( );
        if(root == NULL)
        {
            std::cout <<"�ڴ治��" <<std::endl;
            exit(-1);
        }
        else
        {
            PostCreate(root->m_leftChild, Visit, IsNull);   // �ݹ齨��������
            PostCreate(root->m_rightChild, Visit, IsNull);  // �ݹ齨��������
            root->m_data = elem;
        }
    }
}


/// ��ȡ�����Ŀ������ȸ���ģ��
// �������ƣ�int Height(const BinTreeNode<ElemType> * &root) const;	// ���ض������ĸ�
// ����������������������ȵĸ�������[������rootΪͷ�Ķ����������]
template <class ElemType>
int BinaryTree<ElemType>::Height(const BinTreeNode<ElemType> *root) const	// ���ض������ĸ�
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(root != NULL)    // ֻҪ����㲻�ǿյ�
    {
        int leftHeight = Height(root->m_leftChild);
        int rightHeight = Height(root->m_rightChild);
        return 1/*���ϸ����*/ + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
    else    // �ն��������Ϊ0
    {
        return 0;
    }
}


// �������ƣ�int NodeCount(const BinTreeNode<ElemType> * &root) const;// ���ض������Ľ�����
// ��������������������������Ŀ�ĸ�������[������rootΪͷ�Ķ������Ľ����Ŀ]
template <class ElemType>
int BinaryTree<ElemType>::NodeCount(const BinTreeNode<ElemType> *root) const// ���ض������Ľ�����
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int leftCount = NodeCount(root->m_leftChild);
        int rightCount = NodeCount(root->m_rightChild);

        return leftCount + rightCount + 1/*���ϸ����*/;
    }
}


/// ������Ա����������Ϣ
// �������ƣ�void PreOrder(BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;	// ���������������
// ���������ǰ��ݹ����������
template <class ElemType>
void BinaryTree<ElemType>::PreOrder(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &)) const	// ���������������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(root != NULL)
    {
         (*Visit)(root->m_data);       // �ȷ��ʽ�����Ϣ
         PreOrder(root->m_leftChild, Visit);   // �ݹ������������
         PreOrder(root->m_rightChild, Visit);  // �ݹ������������
    }
    else
    {
        #ifdef SHOW     // ��æ��ʾ�ս�����Ϣ
        std::cout <<'#';
        #endif
        return ;        // ���Ϊ��ʱ��ʼ����
    }
}



// �������ƣ�void InOrder(BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;	// ���������������
// �������������ݹ����������
template <class ElemType>
void BinaryTree<ElemType>::InOrder(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &)) const	// ���������������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(root != NULL)
    {
         InOrder(root->m_leftChild, Visit);   // �ݹ������������
         (*Visit)(root->m_data);       // �ȷ��ʽ�����Ϣ
         InOrder(root->m_rightChild, Visit);  // �ݹ������������
    }
    else
    {
        #ifdef SHOW     // ��æ��ʾ�ս�����Ϣ
        std::cout <<'#';
        #endif
        return ;        // ���Ϊ��ʱ��ʼ����
    }
}

// �������ƣ�void PoStrOrder(BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;	// ���������������
// �������������ݹ����������
template <class ElemType>
void BinaryTree<ElemType>::PostOrder(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &)) const   // ���������������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(root != NULL)
    {
         PostOrder(root->m_leftChild, Visit);   // �ݹ������������
         PostOrder(root->m_rightChild, Visit);  // �ݹ������������
         (*Visit)(root->m_data);       // �ȷ��ʽ�����Ϣ
    }
    else
    {
        #ifdef SHOW     // ��æ��ʾ�ս�����Ϣ
        std::cout <<'#';
        #endif
        return ;        // ���Ϊ��ʱ��ʼ����
    }
}


// �������ƣ�void PoStrOrder(BinTreeNode<ElemType> * &root, void (* Visit)(const ElemType &)) const;	// ���������������
// �������������ݹ����������
template <class ElemType>
void BinaryTree<ElemType>::LevelOrder(BinTreeNode<ElemType> * &root, void (* Visit)(ElemType &)) const   // ���������������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(root == NULL)
    {
        throw std::invalid_argument("����curΪ��, �޷���ʼ��α�������Ϣ\n");
    }

    LinkQueue<BinTreeNode<ElemType> *> queue;   // ����һ��������Ϊ��ǰ�����ָ�����͵Ķ���
    BinTreeNode<ElemType> *node = root;          // �ӵ�ǰ����㿪ʼ���в�α���

    queue.InQueue(node);            // ����������

    while(queue.Empty() != true)    // ֻҪ��ǰ���в�Ϊ��, ˵��������δ������
    {
        queue.OutQueue(node);

        (* Visit)(node->m_data);     // ���ʵ�ǰ����������

        if(node->m_leftChild != NULL)   // ֻҪ�ý�����Ӵ���
        {
            queue.InQueue(node->m_leftChild);   // ���������
        }
        if(node->m_rightChild != NULL)   // ֻҪ�ý���Һ��Ӵ���
        {
            queue.InQueue(node->m_rightChild);   // ���Һ������
        }
    }
}


/// ��ȡ�����Ϣ��������
// �������ƣ�BinTreeNode<ElemType> *ParentHelp(BinTreeNode<ElemType> * &root, const BinTreeNode<ElemType> * &cur) const;
// ���������Ѱ��cur����˫�׵ĸ�������
template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(BinTreeNode<ElemType> * &root, const BinTreeNode<ElemType> * &cur) const			// ����cur��˫��
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
	if (root == NULL)
	{
        throw std::invalid_argument("����curΪ��, �޷���ȡ��˫�׵���Ϣ\n");
	}
	else if(root->m_leftChild == cur || root->m_rightChild == cur)
	{
	    return m_root; // ������cur��˫��ʱ����
	}
	else
	{
		BinTreeNode<ElemType> *temp;

		temp = Parent(root->leftChild, cur);	// ��������������cur��˫��
		if(temp != NULL)
		{
		    return temp;			// ˫������������
		}

		temp = Parent(root->rightChild, cur);	// ��������������cur��˫��
		if(temp != NULL)
		{
		    return temp;			// ˫������������
		}
		// ��������������϶�δ�ҵ��򷵻�NULL
		else
		{
		    return NULL;						// ��ʾcur��˫��
	    }
	}
}


/// ��ʽ��������BinaryTreeʵ�ֲ���
/**��ʽ��������BinaryTree������Ա����[ʵ��]**********************************************************
    BinaryTree( ); // Ĭ�Ϲ��캯��ģ��
    BinaryTree(const ElemType &e);							// ������eΪ���Ķ�����
    BinaryTree(BinTreeNode<ElemType> *r);					// ������rΪ���Ķ�����
    BinaryTree(const BinaryTree<ElemType> &copy);     // ���ƹ��캯��
    virtual ~BinaryTree( );                // ����������ģ��
    BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &copy);
    // ��ʽ��������BinaryTree����Ϣ��ʼ����
    void CreateTree(void (* Visit)(ElemType &), bool (* IsNull)(ElemType &));         // ����Visit��������һ����ʽ��������
**********************************************************[ʵ��]��ʽ��������BinaryTree������Ա����**/
// �������ƣ�BinaryTree( ); // Ĭ�Ϲ��캯��ģ��
// �������������һ���ն���������
template <class ElemType>
BinaryTree<ElemType>::BinaryTree( )
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    m_root = NULL;
}

// �������ƣ�BinaryTree(const ElemType &elem);
// ���������������eΪ���Ķ�����
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &elem)							// ��������������Ϊelem������
{
    this->m_root = new BinTreeNode<ElemType>(elem);
}


// �������ƣ�BinaryTree(BinTreeNode<ElemType> *root)
// ���������������rootΪ���Ķ�����
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinTreeNode<ElemType> * &root)					// ������rootΪ���Ķ�����
{
    this->m_root = root;
}


// �������ƣ�BinaryTree(const BinaryTree<ElemType> &copy);     // ���ƹ��캯��
// �������������copy���󴴽�һ������������
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &copy)     // ���ƹ��캯��
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    CopyTree(this->m_root);   // ���ø��������ݹ鸴����m_rootΪ���Ķ�����
}

// �������ƣ�virtual ~BinaryTree( );
// ������������ٶ�����������ڴ�ռ�
template <class ElemType>
BinaryTree<ElemType>::~BinaryTree( )      // ����������ģ��
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    Destroy(this->m_root);
}

// �������ƣ�BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &copy);
// �����������ֵ����[���Ӱ���ֵ�����]
template <class ElemType>
BinaryTree<ElemType>& BinaryTree<ElemType>::operator=(const BinaryTree<ElemType> &copy)   // ��ֵ����
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if (this != &copy)
	{
		Destroy(this->m_root);				// �ͷŶ�������ռ�õ��ڴ�ռ�
		m_root = CopyTree(copy.root);	        // ���ƶ���������Ϣ
	}

	return *this;
}

/**��ʽ��������BinaryTree����Ϣ��ȡ����[ʵ��]*********************************************************
    int NodeCount( ) const;         // ���ض������Ľ�����
    int Height( ) const;            // ���ض����������
    bool Empty( ) const;            // �ж϶������Ƿ�Ϊ��
    BinTreeNode<ElemType>* Search(const ElemType &elem);        // Ѱ������Ԫ�ص�ֵ
*********************************************************��ʽ��������BinaryTree����Ϣ��ȡ����[ʵ��]**/
// �������ƣ�int NodeCount( ) const;         // ���ض������Ľ�����
// ������������㵱ǰ����������Ľ�����
template <class ElemType>
int BinaryTree<ElemType>::NodeCount( ) const         // ���ض������Ľ�����
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    return NodeCount(this->m_root);
}

// �������ƣ�int Height( ) const;            // ���ض����������
// ������������㵱ǰ��������������
template <class ElemType>
int BinaryTree<ElemType>::Height( ) const            // ���ض����������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    return Height(this->m_root);
}


// �������ƣ�bool Empty( ) const;            // �ж϶������Ƿ�Ϊ��
// ����������жϵ�ǰ�����������Ƿ�Ϊ��
template <class ElemType>
bool BinaryTree<ElemType>::Empty( ) const
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    return (m_root == NULL);
}

// �������ƣ� BinTreeNode<ElemType>*  Search(const ElemType &elem);        // Ѱ������Ԫ�ص�ֵ
template <class ElemType>
BinTreeNode<ElemType>*  BinaryTree<ElemType>::Search(const ElemType &elem)        // Ѱ������Ԫ�ص�ֵ
{
    return this->Search(m_root, elem);
}

/**��ʽ��������BinaryTree�Ľ����Ϣ��ȡ����[ʵ��]*****************************************************
    BinTreeNode<ElemType> *GetRoot( ) const;         // ���ض������ĸ����
    ElemType GetElem(BinTreeNode<ElemType> * &cur) const;               // ���ؽ��cur��Ԫ��ֵ
    bool SetElem(BinTreeNode<ElemType> * &cur, ElemType &elem) const;   // �޸Ľ��cur��Ԫ��ֵ
    // ˫�׵Ĵ�����
    BinTreeNode<ElemType> *Parent(const BinTreeNode<ElemType> * &cur);      // ��ȡcue����˫�׽��
    // ����Ĵ�����
    BinTreeNode<ElemType> *LeftChild(const BinTreeNode<ElemType> * &cur) const; // ��ȡcur�������ӽ��
    BinTreeNode<ElemType> *InsertLeftChild(const BinTreeNode<ElemType> * &cur) const; // ����cur�������ӽ��
    BinTreeNode<ElemType> *DeleteLeftChild(const BinTreeNode<ElemType> * &cur) const; // ɾ��cur�������ӽ��
    // �ҽ��Ĵ�����
    BinTreeNode<ElemType> *RightChild(const BinTreeNode<ElemType> * &cur) const; // ��ȡcur�������ӽ��
    BinTreeNode<ElemType> *InsertRightChild(const BinTreeNode<ElemType> * &cur) const; // ����cur�������ӽ��
    BinTreeNode<ElemType> *DeleteRightChild(const BinTreeNode<ElemType> * &cur) const; // ɾ��cur�������ӽ��
    // ��ʽ��������BinaryTree��������
    void PreOrder(void (* Visit)(ElemType &));          // ���������������
    void InOrder(void (* Visit)(ElemType &));           // ���������������
    void PostOrder(void (* Visit)(ElemType &));         // �������ĺ������
    void LevelOrder(void (* Visit)(ElemType &));        // �������Ĳ�α���
*****************************************************[ʵ��]��ʽ��������BinaryTree�Ľ����Ϣ��ȡ����**/
template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::GetRoot( ) const         // ���ض������ĸ����
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    return m_root;      // ���ض������ĸ����
}


// �������ƣ�ElemType GetElem(BinTreeNode<ElemType> * &cur) const;               // ���ؽ��cur��Ԫ��ֵ
// ������������ؽ��cur�Ľ��Ԫ��ֵ
template <class ElemType>
ElemType BinaryTree<ElemType>::GetElem(BinTreeNode<ElemType> * &cur) const               // ���ؽ��cur��Ԫ��ֵ
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(cur == NULL)
    {
        throw std::invalid_argument("����curΪ��, �޷���ȡ����Ԫ����Ϣ\n");
    }
    else
    {
        return cur->m_data;     // ����Ԫ��ֵ
    }
}


// �������ƣ�bool SetElem(BinTreeNode<ElemType> * &cur, ElemType &elem) const;   // �޸Ľ��cur��Ԫ��ֵ
// �������������cur��������ֵ
template <class ElemType>
void BinaryTree<ElemType>::SetElem(BinTreeNode<ElemType> * &cur, ElemType &elem) const   // �޸Ľ��cur��Ԫ��ֵ
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(cur == NULL)
    {
        throw std::invalid_argument("����curΪ��, �޷���ȡ����Ԫ����Ϣ\n");
    }
    else
    {
        cur->m_data = elem;     // ���Ľ������
    }
}


// ˫�׵Ĵ�����
// �������ƣ�BinTreeNode<ElemType> *Parent(const BinTreeNode<ElemType> * &cur);      // ��ȡcue����˫�׽��
// �������������cur���ĸ�ĸ���
template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(const BinTreeNode<ElemType> * &cur) const     // ��ȡcue����˫�׽��
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    return ParentHelp(this->m_root, cur);      // ���ø�������
}



/// ����Ĵ�����
// �������ƣ�BinTreeNode<ElemType> *LeftChild(const BinTreeNode<ElemType> * &cur) const; // ��ȡcur�������ӽ��
// �������������cur�����ӽ��
template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::LeftChild(const BinTreeNode<ElemType> * &cur) const // ��ȡcur�������ӽ��
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(cur == NULL)
    {
        throw std::invalid_argument("����curΪ��, �޷���ȡ�����ӽڵ����Ϣ\n");
    }
    else
    {
        return cur->m_leftChild;     // ���������ӽڵ����Ϣ
    }
}


// �������ƣ�BinTreeNode<ElemType> *InsertLeftChild(const BinTreeNode<ElemType> * &cur) const; // ����cur�������ӽ��
// �������������cur�����ӽ��, ���cur�����ӽڵ����, ��curԭ����������Ϊelem����������
template <class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinTreeNode<ElemType> * &cur, const ElemType &elem) // ����cur�������ӽ��
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
	if(cur == NULL)
	{	// curΪ�գ�����
        throw std::invalid_argument("����curΪ��, �޷����������ӽڵ����Ϣ\n");
	}
	else
	{	// �����Һ���
		BinTreeNode<ElemType> *newLeftChild =  new BinTreeNode<ElemType>(elem);// elem��Ϊ������Ľ��
		if (cur->m_leftChild != NULL)
		{	// cur���Һ��ӷǿ�
			newLeftChild->m_leftChild = cur->m_leftChild;	// curԭ����������Ϊe��������
		}
		cur->m_leftChild = newLeftChild;					// e��Ϊcur���Һ���
	}
}


// �������ƣ�BinTreeNode<ElemType> *DeleteLeftChild(const BinTreeNode<ElemType> * &cur) const; // ɾ��cur����������
// ���������
template <class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinTreeNode<ElemType> * &cur)// ɾ��cur����������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(cur == NULL)
    {
        throw std::invalid_argument("����curΪ��, �޷�ɾ����������");
    }
	else
	{	// cur�ǿ�
		Destroy(cur->m_leftChild);	// ɾ��cur������
	}
}

/// �ҽ��Ĵ�����
// �������ƣ�BinTreeNode<ElemType> *RightChild(const BinTreeNode<ElemType> * &cur) const; // ��ȡcur�������ӽ��
// ���������ɾ�����������cur��������
template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::RightChild(const BinTreeNode<ElemType> * &cur) const // ��ȡcur�������ӽ��
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(cur == NULL)
    {
        throw std::invalid_argument("����curΪ��, �޷���ȡ�����ӽ�����Ϣ\n");
    }
    else
    {
        return cur->m_leftChild;     // �������ӽڵ�
    }
}


// �������ƣ�BinTreeNode<ElemType> *InsertRightChild(const BinTreeNode<ElemType> * &cur) const; // ����cur�������ӽ��
// �������������cur�����ӽ��, ���cur�����ӽڵ����, ��curԭ����������Ϊelem����������
template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType> * &cur, const ElemType &elem) // ����cur�������ӽ��
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
	if(cur == NULL)
	{	// curΪ�գ�����
        throw std::invalid_argument("����curΪ��, �޷����������ӽ�����Ϣ\n");
	}
	else
	{	// �����Һ���
		BinTreeNode<ElemType> *newRightChild =  new BinTreeNode<ElemType>(elem);// elem��Ϊ������Ľ��
		if (cur->m_rightChild != NULL)
		{	// cur���Һ��ӷǿ�
			newRightChild->m_rightChild = cur->m_rightChild;	// curԭ����������Ϊe��������
		}
		cur->m_rightChild = newRightChild;					// e��Ϊcur���Һ���
	}
}

// �������ƣ�BinTreeNode<ElemType> *DeleteRightChild(const BinTreeNode<ElemType> * &cur) const; // ɾ��cur�������ӽ��
// ���������ɾ�����������cur��������
template <class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinTreeNode<ElemType> * &cur) // ɾ��cur�������ӽ��
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    if(cur == NULL)
    {
        throw std::invalid_argument("����curΪ��, �޷�ɾ����������");
    }
	else
	{	// cur�ǿ�
		Destroy(cur->m_rightChild);	// ɾ��cur������
	}
}

// �ݹ齨���㷨
// �������ƣ�void PreCreate(void (* Visit)(ElemType &), bool (* IsNull)(ElemType &))
// ���������ǰ������ʽ������
template <class ElemType>
void BinaryTree<ElemType>::PreCreate(void (* Visit)(ElemType &), bool (* IsNull)(ElemType &))         // ����Visit��������һ����ʽ��������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    PreCreate(this->m_root, Visit, IsNull);
}

// �������ƣ�void PreCreate(void (* Visit)(ElemType &), bool (* IsNull)(ElemType &))
// �����������������ʽ������
template <class ElemType>
void BinaryTree<ElemType>::InCreate(void (* Visit)(ElemType &), bool (* IsNull)(ElemType &))           // ���������������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    InCreate(this->m_root, Visit, IsNull);
}

// �������ƣ�void PreCreate(void (* Visit)(ElemType &), bool (* IsNull)(ElemType &))
// �����������������ʽ������
template <class ElemType>
void BinaryTree<ElemType>::PostCreate(void (* Visit)(ElemType &), bool (* IsNull)(ElemType &))        // �������ĺ������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    PostCreate(this->m_root, Visit, IsNull);
}
/// ��ʽ��������BinaryTree��������

// �������ƣ�void PreOrder(void (* Visit)(ElemType &));          // ���������������
// ����������������������
template <class ElemType>
void BinaryTree<ElemType>::PreOrder(void (* Visit)(ElemType &))          // ���������������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    PreOrder(this->m_root, Visit);      // �������
}


// �������ƣ�void InOrder(void (* Visit)(ElemType &));           // ���������������
// ����������������������
template <class ElemType>
void BinaryTree<ElemType>::InOrder(void (* Visit)(ElemType &))           // ���������������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    InOrder(this->m_root, Visit);
}


// �������ƣ�void PostOrder(void (* Visit)(ElemType &));         // �������ĺ������
// ����������������������
template <class ElemType>
void BinaryTree<ElemType>::PostOrder(void (* Visit)(ElemType &))          // �������ĺ������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<"FUN:"<<__func__  <<", LINE:" <<__line__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    PostOrder(this->m_root, Visit); // �������
}


// �������ƣ�void LevelOrder(void (* Visit)(ElemType &));        // �������Ĳ�α���
// �����������α���������
template <class ElemType>
void BinaryTree<ElemType>::LevelOrder(void (* Visit)(ElemType &))           // ���������������
{
#ifdef DEBUG    // ��׮������Ϣ
std::cout <<__func__ <<std::endl;   // ���������Ϣ
#endif
    // ����ʵ����Ϣ
    LevelOrder(m_root, Visit); // �������
}


#endif // BinaryTree_H_INCLUDED
