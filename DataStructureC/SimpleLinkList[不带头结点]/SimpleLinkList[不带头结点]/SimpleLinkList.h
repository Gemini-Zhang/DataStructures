#ifndef __SIMPLELINKLIST_H___
#define __SIMPLELINKLIST_H___


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//#define DEBUG				// ���Բ�׮��Ϣ��

///	�汾V0.0.2����
///	�ٽ�InsertNode����ʵ��Ϊ��������
//	������data��������ĵ�position��λ��
//	LinkListNode* InsertNode(LinkList *list, int position, ElemType data)
//	������data���������pNode������һ��λ�ø�λ��
//	LinkListNode* AddNode(LinkList *list, LinkListNode *prevNode, ElemType data)

///	�ڽ�DelNode����ʵ��Ϊ��������
//	ɾ������list�е�position��ָ��
//	ElemType DeleteNode(LinkList *list, int position)
//	ɾ������list��prevNode���֮���ָ���ָ��
//	ElemType SubNode(LinkListNode *prevNode)
//	ɾ������list��currNodeָ����ָ����Ǹ����
//	ElemType DeleteCurrNode(LinkList *list, LinkListNode *currNode)

/// �۽�FindNode����ʵ��Ϊ��������
//	���ҵ�����list�е�position�����
//	LinkListNode* FindPosNode(LinkList *list, int position);
//	������list���ҵ�currNode��ǰһ�����
//	LinkListNode *FindPrevNode(LinkList *list, LinkListNode *currNode);
//	�жϽ��nodeָ��������ǲ��������еĽ��
//	int IsNodeInList(LinkList *list, LinkListNode *node);


///*////////////////////////////////////////////////////////////////////////////
///
///	��ͷ���ĵ�����ṹ��
///
///*////////////////////////////////////////////////////////////////////////////

typedef int ElemType;		// �Զ�����������

//typedef struct LinkListNode*	PLinkListNode;			// ������ָ����

// ������������
typedef struct LinkListNode
{
	ElemType			m_data;			// ������
	struct LinkListNode	*m_next;			// ָ����
}LinkListNode;

// ��ͷ���ĵ�������
typedef struct LinkList
{
	LinkListNode	*m_head;				// ����ͷ���
	int				m_length;			// ���������ݽ�����ָ����
}LinkList;




///*////////////////////////////////////////////////////////////////////////////
///
///	�����ͳ�ʼ��������
///
///	����һ�����������ݽṹ������ʼ��ͷ��㣬Ȼ�󽫴����õĵ�����ָ�뷵��
///	LinkList* CreatLinkList(void)
///
///	��ʼ��������
///	void InitLinkList(LinkList *list)
///*///////////////////////////////////////////////////////////////////////////

/**
LinkList* CreatLinkList(void)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	���ɹ����ش����õĵ������ָ��
����
	����һ�����������ݽṹ������ʼ��ͷ��㣬Ȼ�󽫴����õĵ�����ָ�뷵��
ע��
	ʹ��CreateLinkList�����ĵ�������Ҫ��DestroyLinkList������
	���ⷢ���ڴ�й©
*/
LinkList* CreateLinkList(void);

/**
void InitLinkList(LinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��ʼ�������� ִ�����²���
	�ٿ���ͷ���Ŀռ� �ڽ��б�Ҫ�ĳ�ʼ��[ͷ���ĳ�ʼ���͵���������Ŀ�ĳ�ʼ��]
ע��
	ʹ��InitLinkList��ʼ���ĵ�����(��ʼ��ʱmalloc��ͷ���m_head�Ŀռ�)
	��ʹ����FinitLinkList�����к���(����ʱfree��ͷ����m_head�ռ�)
	���ⷢ���ڴ�й©
*/
void InitLinkList(LinkList *list);

///*////////////////////////////////////////////////////////////////////////////
///
///	�����Լ���������
///
///	������CreateLinkList�����ĵ�����
///	void DestroyLinkList(LinkList *list)
///
///	��������
///	void FinitLinkList(LinkList *list)
///
/// ��յ������е�����Ԫ��
///	void ClearLinkList(LinkList *list)
///*////////////////////////////////////////////////////////////////////////////

/**
void DestroyLinkList(LinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	������CreateLinkList�����ĵ�����ִ�����²���
	����յ�����	���ͷ�ͷ���	���ͷŵ�����
ע��
	ʹ��CreateLinkList�����ĵ�������Ҫ��DestroyLinkList������
	���ⷢ���ڴ�й©
*/
LinkList* DestroyLinkList(LinkList *list);





/**
void FinitLinkList(LinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	�������� ִ�����²���
	�ٿ���ͷ���Ŀռ� �ڽ��б�Ҫ�ĳ�ʼ��[ͷ���ĳ�ʼ���͵���������Ŀ�ĳ�ʼ��]
ע��
	ʹ��InitLinkList��ʼ���ĵ�����(��ʼ��ʱmalloc��ͷ���m_head�Ŀռ�)
	��ʹ����FinitLinkList�����к���(����ʱfree��ͷ����m_head�ռ�)
	���ⷢ���ڴ�й©
*/
void FinitLinkList(LinkList *list);



/**
void ClearLinkList(LinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��յ������е�����Ԫ��
*/
void ClearLinkList(LinkList *list);



///*////////////////////////////////////////////////////////////////////////////
///
///	���Һ���
///
///	���ҵ�����list�е�position�����
///	LinkListNode* FindPosNode(LinkList *list, int position)
///
///	������list���ҵ�currNode��ǰһ�����
///	LinkListNode *FindPrevNode(LinkList *list, LinkListNode *currNode)
///
/// �жϽ��nodeָ��������ǲ��������еĽ��
///	int IsNodeInList(LinkList *list, LinkListNode *node)
///
///	�ҵ�������Ϊdata�Ľ���״γ��ֵ�λ�ò����ؽ����Ϣ
///	LinkListNode* FindDataNode(LinkList *list, ElemType data, int *position)
///*////////////////////////////////////////////////////////////////////////////
/**
LinkListNode* FindPosNode(LinkList *list, int position)

����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	�����ҵ�����ָ���λ��
����ֵ
	���ɹ�����ָ������ҽ���ָ��
	��ʧ�ܷ���NULL
����
	�ú����Ĺ�����:	���ҵ�����list�е�position�����
*/
LinkListNode* FindPosNode(LinkList *list, int position);


/**
LinkListNode *FindPrevNode(LinkList *list, LinkListNode *currNode);

����
	list		:	ָ��һ������ָ�룬�˴������ͷ��ַ
	currNode	:	�����ҵ�����ָ���λ��
����ֵ
	���ɹ�����ָ������ҽ���ָ��
	��ʧ�ܷ���NULL
����
	������list���ҵ�currNode��ǰһ�����
*/

LinkListNode *FindPrevNode(LinkList *list, LinkListNode *currNode);



/**
int IsNodeInList(LinkList *list, LinkListNode *node)

����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	node	:	ָ������ҵĽ���ָ��
����ֵ
	���ɹ� ���ؽ��node�������е�λ��
	��ʧ�� ����-1
����
	�жϽ��nodeָ��������ǲ��������еĽ��
*/
int IsNodeInList(LinkList *list, LinkListNode *node);


/**
LinkListNode* FindDataNode(LinkList *list, ElemType data, int *position

����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	data	:	�����ҵĽ���������Ϣ
����ֵ
	���ɹ� ���ؽ��node�������е�λ��
	��ʧ�� ����-1
����
	�ҵ�������Ϊdata�Ľ���״γ��ֵ�λ�ò����ؽ����Ϣ
*/
LinkListNode* FindDataNode(LinkList *list, ElemType data, int *position);



///*////////////////////////////////////////////////////////////////////////////
///
///	���뺯��
///
///	������data���������prevNode������һ��λ�ø�λ��
///	LinkListNode *AddNode(LinkList *list, LinkListNode *prevNode, ElemType data)
///
///	������data��������ĵ�position��λ��
///	LinkListNode *InsertNode(LinkList *list, int position, ElemType data)
///*////////////////////////////////////////////////////////////////////////////
/**
void InsertNode(LinkList *list, int position, ElemType data)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	���������λ��
	data	:	�������������
����ֵ
	��
����
	�ú����Ĺ�����:	������data��������ĵ�position��λ��
*/
LinkListNode* InsertNode(LinkList *list, int position, ElemType data);


/**
LinkListNode* AddNode(LinkList *list, LinkListNode *prevNode, ElemType data);
����
	list		:	ָ��һ������ָ�룬�˴������ͷ��ַ
	prevNode	:	������λ�õ�ǰһ�����
	data		:	�������������
����ֵ
	��
����
	�ú����Ĺ�����:	������data���������prevNode������һ��λ�ø�λ��
*/
LinkListNode* AddNode(LinkList *list, LinkListNode *prevNode, ElemType data);


///*////////////////////////////////////////////////////////////////////////////
///
///	ɾ������
///
///	ɾ������list��prevNode���֮���ָ���ָ��
///	void DeleteNode(LinkList *list, int position)
///
///	ɾ������list��prevNode���֮���ָ���ָ��
///	ElemType SubNode(LinkList *list, LinkListNode *prevNode)
///
///	ɾ������list��prevNode���֮���ָ���ָ��
///	ElemType DeleteCurrNode(LinkList *list, LinkListNode *currNode)
///*////////////////////////////////////////////////////////////////////////////

/**
void DeleteNode(LinkList *list, int position)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	��������ĵ�position�����ɾ��
*/
ElemType DeleteNode(LinkList *list, int position);


/**
void DeleteNode(LinkList *list, int position)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	ɾ������list��prevNode���֮���ָ���ָ��
*/
ElemType SubNode(LinkList *list, LinkListNode *prevNode);

/**
ElemType DeleteCurrNode(LinkList *list, LinkListNode *currNode);
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	ɾ������list��prevNode���֮���ָ���ָ��
*/
ElemType DeleteCurrNode(LinkList *list, LinkListNode *currNode);

/**
void ShowLinkList(LinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��ʾ���������Ϣ
*/


///*////////////////////////////////////////////////////////////////////////////
///
///	��������
///
///	��ʾ���������Ϣ
///	void ShowList(LinkList *list
///
///	ɾ������list��prevNode���֮���ָ���ָ��
///	void SetNode(LinkList *list, int position, ElemType data)
///
///	��ȡ������list��position������������
/// ElemType GetNode(LinkList *list, int position)
///
///	��ȡ������list�ĳ���[��Ԫ�ظ���]
///	int LengthLinkList(LinkList *list)
///
///	�жϵ�ǰ�����Ƿ��ǿ�����
///	bool IsEmptyLinkList(LinkList *list)
///*////////////////////////////////////////////////////////////////////////////

void ShowList(LinkList *list);

/**
void SetNode(LinkList *list, int position, ElemType data)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon :	���޸ĵĽ�������
	data	:	����������������
����ֵ
	��
����
	�޸ĵ�����list��position������������Ϊdata
*/
void SetNode(LinkList *list, int position, ElemType data);


/**
ElemType GetNode(LinkList *list, int position
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon :	����ѯ�Ľ���λ��
����ֵ
	��ȡ���Ľ������
����
	��ȡ������list��position������������
*/
ElemType GetNode(LinkList *list, int position);

/**
int LengthLinkList(LinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	������ĳ���
����
	��ȡ������ĳ���
*/
int LengthLinkList(LinkList *list);


/**
bool IsEmptyLinkList(LinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	����������ǿձ�����true
	���򷵻�false
����
	��ȡ������ĳ���
*/
bool IsEmptyLinkList(LinkList *list);

#endif // SIMPLELINKLIST_H_INCLUDED
