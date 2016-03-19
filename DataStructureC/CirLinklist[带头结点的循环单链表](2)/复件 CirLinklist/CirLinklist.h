#ifndef __CIRCirLinkList_H__
#define __CIRCirLinkList_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



#define DEBUG				// ���Բ�׮��Ϣ��

///*////////////////////////////////////////////////////////////////////////////
///
///	��ͷ���ĵ�����ṹ��
///
///*////////////////////////////////////////////////////////////////////////////
typedef int ElemType;		// �Զ�����������

//typedef struct CirLinkListNode*	PCirLinkListNode;			// ������ָ����

// ������������
typedef struct CirLinkListNode
{
	ElemType				m_data;			// ������
	struct CirLinkListNode	*m_next;		// ָ����
}CirLinkListNode;

// ��ͷ���ĵ�������
typedef struct CirLinkListNode* CirLinkList;




///*////////////////////////////////////////////////////////////////////////////
///
///	�����ͳ�ʼ��������
///
///	����һ�����������ݽṹ������ʼ��ͷ��㣬Ȼ�󽫴����õĵ�����ָ�뷵��
///	CirLinkList* CreatCirLinkList(void)
///
///	��ʼ��������
///	void InitCirLinkList(CirLinkList *list)
///*///////////////////////////////////////////////////////////////////////////

/**
CirLinkList* CreatCirLinkList(void)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	���ɹ����ش����õĵ������ָ��
����
	����һ�����������ݽṹ������ʼ��ͷ��㣬Ȼ�󽫴����õĵ�����ָ�뷵��
ע��
	ʹ��CreateCirLinkList�����ĵ�������Ҫ��DestroyCirLinkList������
	���ⷢ���ڴ�й©
*/
CirLinkList* CreateCirLinkList(void);



/**
void InitCirLinkList(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��ʼ�������� ִ�����²���
	�ٿ���ͷ���Ŀռ� �ڽ��б�Ҫ�ĳ�ʼ��[ͷ���ĳ�ʼ���͵���������Ŀ�ĳ�ʼ��]
ע��
	ʹ��InitCirLinkList��ʼ���ĵ�����(��ʼ��ʱmalloc��ͷ���m_head�Ŀռ�)
	��ʹ����FinitCirLinkList�����к���(����ʱfree��ͷ����m_head�ռ�)
	���ⷢ���ڴ�й©
*/
void InitCirLinkList(CirLinkList *tail);

///*////////////////////////////////////////////////////////////////////////////
///
///	�����Լ���������
///
///	������CreateCirLinkList�����ĵ�����
///	void DestroyCirLinkList(CirLinkList *list)
///
///	��������
///	void FinitCirLinkList(CirLinkList *list)
///
/// ��յ������е�����Ԫ��
///	void ClearCirLinkList(CirLinkList *list)
///*////////////////////////////////////////////////////////////////////////////

/**
void DestroyCirLinkList(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	������CreateCirLinkList�����ĵ�����ִ�����²���
	����յ�����	���ͷ�ͷ���	���ͷŵ�����
ע��
	ʹ��CreateCirLinkList�����ĵ�������Ҫ��DestroyCirLinkList������
	���ⷢ���ڴ�й©
*/
CirLinkList* DestroyCirLinkList(CirLinkList *list);





/**
void FinitCirLinkList(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	�������� ִ�����²���
	�ٿ���ͷ���Ŀռ� �ڽ��б�Ҫ�ĳ�ʼ��[ͷ���ĳ�ʼ���͵���������Ŀ�ĳ�ʼ��]
ע��
	ʹ��InitCirLinkList��ʼ���ĵ�����(��ʼ��ʱmalloc��ͷ���m_head�Ŀռ�)
	��ʹ����FinitCirLinkList�����к���(����ʱfree��ͷ����m_head�ռ�)
	���ⷢ���ڴ�й©
*/
void FinitCirLinkList(CirLinkList *list);



/**
void ClearCirLinkList(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��յ������е�����Ԫ��
*/
void ClearCirLinkList(CirLinkList *list);



///*////////////////////////////////////////////////////////////////////////////
///
///	���Һ���
///
///	���ҵ�����list�е�position�����
///	CirLinkListNode* FindPosNode(CirLinkList *list, int position)
///
///	������list���ҵ�currNode��ǰһ�����
///	CirLinkListNode *FindPrevNode(CirLinkList *list, CirLinkListNode *currNode)
///
/// �жϽ��nodeָ��������ǲ��������еĽ��
///	int IsNodeInList(CirLinkList *list, CirLinkListNode *node)
///
///	�ҵ�������Ϊdata�Ľ���״γ��ֵ�λ�ò����ؽ����Ϣ
///	CirLinkListNode* FindDataNode(CirLinkList *list, ElemType data, int *position)
///*////////////////////////////////////////////////////////////////////////////
/**
CirLinkListNode* FindPosNode(CirLinkList *list, int position)

����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	�����ҵ�����ָ���λ��
����ֵ
	���ɹ�����ָ������ҽ���ָ��
	��ʧ�ܷ���NULL
����
	�ú����Ĺ�����:	���ҵ�����list�е�position�����
*/
CirLinkListNode* FindPosNode(CirLinkList *list, int position);


/**
CirLinkListNode *FindPrevNode(CirLinkList *list, CirLinkListNode *currNode);

����
	list		:	ָ��һ������ָ�룬�˴������ͷ��ַ
	currNode	:	�����ҵ�����ָ���λ��
����ֵ
	���ɹ�����ָ������ҽ���ָ��
	��ʧ�ܷ���NULL
����
	������list���ҵ�currNode��ǰһ�����
*/

CirLinkListNode *FindPrevNode(CirLinkList *list, CirLinkListNode *currNode);



/**
int IsNodeInList(CirLinkList *list, CirLinkListNode *node)

����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	node	:	ָ������ҵĽ���ָ��
����ֵ
	���ɹ� ���ؽ��node�������е�λ��
	��ʧ�� ����-1
����
	�жϽ��nodeָ��������ǲ��������еĽ��
*/
int IsNodeInList(CirLinkList *list, CirLinkListNode *node);


/**
CirLinkListNode* FindDataNode(CirLinkList *list, ElemType data, int *position

����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	data	:	�����ҵĽ���������Ϣ
����ֵ
	���ɹ� ���ؽ��node�������е�λ��
	��ʧ�� ����-1
����
	�ҵ�������Ϊdata�Ľ���״γ��ֵ�λ�ò����ؽ����Ϣ
*/
CirLinkListNode* FindDataNode(CirLinkList *list, ElemType data, int *position);



///*////////////////////////////////////////////////////////////////////////////
///
///	���뺯��
///
///	������data���������prevNode������һ��λ�ø�λ��
///	CirLinkListNode *AddNode(CirLinkList *list, CirLinkListNode *prevNode, ElemType data)
///
///	������data��������ĵ�position��λ��
///	CirLinkListNode *InsertNode(CirLinkList *list, int position, ElemType data)
///*////////////////////////////////////////////////////////////////////////////
/**
void InsertNode(CirLinkList *list, int position, ElemType data)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	���������λ��
	data	:	�������������
����ֵ
	��
����
	�ú����Ĺ�����:	������data��������ĵ�position��λ��
*/
CirLinkListNode* InsertNode(CirLinkList *list, int position, ElemType data);


/**
CirLinkListNode* AddNode(CirLinkList *list, CirLinkListNode *prevNode, ElemType data);
����
	list		:	ָ��һ������ָ�룬�˴������ͷ��ַ
	prevNode	:	������λ�õ�ǰһ�����
	data		:	�������������
����ֵ
	��
����
	�ú����Ĺ�����:	������data���������prevNode������һ��λ�ø�λ��
*/
CirLinkListNode* AddNode(CirLinkList *list, CirLinkListNode *prevNode, ElemType data);


///*////////////////////////////////////////////////////////////////////////////
///
///	ɾ������
///
///	ɾ������list��prevNode���֮���ָ���ָ��
///	void DeleteNode(CirLinkList *list, int position)
///
///	ɾ������list��prevNode���֮���ָ���ָ��
///	ElemType SubNode(CirLinkList *list, CirLinkListNode *prevNode)
///
///	ɾ������list��prevNode���֮���ָ���ָ��
///	ElemType DeleteCurrNode(CirLinkList *list, CirLinkListNode *currNode)
///*////////////////////////////////////////////////////////////////////////////

/**
void DeleteNode(CirLinkList *list, int position)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	��������ĵ�position�����ɾ��
*/
ElemType DeleteNode(CirLinkList *list, int position);


/**
void DeleteNode(CirLinkList *list, int position)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	ɾ������list��prevNode���֮���ָ���ָ��
*/
ElemType SubNode(CirLinkList *list, CirLinkListNode *prevNode);

/**
ElemType DeleteCurrNode(CirLinkList *list, CirLinkListNode *currNode);
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	ɾ������list��prevNode���֮���ָ���ָ��
*/
ElemType DeleteCurrNode(CirLinkList *list, CirLinkListNode *currNode);

/**
void ShowCirLinkList(CirLinkList *list)
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
///	void ShowList(CirLinkList *list
///
///	ɾ������list��prevNode���֮���ָ���ָ��
///	void SetNode(CirLinkList *list, int position, ElemType data)
///
///	��ȡ������list��position������������
/// ElemType GetNode(CirLinkList *list, int position)
///
///	��ȡ������list�ĳ���[��Ԫ�ظ���]
///	int LengthCirLinkList(CirLinkList *list)
///
///	�жϵ�ǰ�����Ƿ��ǿ�����
///	bool IsEmptyCirLinkList(CirLinkList *list)
///
///	��ȡѭ�������ͷָ��
///	CirLinkListNode* GetFisrtNode(CirLinkList *list)
///
///	��ȡָ��ͷ����ָ��
///	CirLinkListNode* GetHeadNode(CirLinkList *list)
///*////////////////////////////////////////////////////////////////////////////

void ShowList(CirLinkList *list);

/**
void SetNode(CirLinkList *list, int position, ElemType data)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon :	���޸ĵĽ�������
	data	:	����������������
����ֵ
	��
����
	�޸ĵ�����list��position������������Ϊdata
*/
void SetNode(CirLinkList *list, int position, ElemType data);


/**
ElemType GetNode(CirLinkList *list, int position
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon :	����ѯ�Ľ���λ��
����ֵ
	��ȡ���Ľ������
����
	��ȡ������list��position������������
*/
ElemType GetNode(CirLinkList *list, int position);

/**
int LengthCirLinkList(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	������ĳ���
����
	��ȡ������ĳ���
*/
int LengthCirLinkList(CirLinkList *list);


/**
bool IsEmptyCirLinkList(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	����������ǿձ�����true
	���򷵻�false
����
	��ȡ������ĳ���
*/
bool IsEmptyCirLinkList(CirLinkList *list);

/**
CirLinkListNode* GetFisrtNode(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	����ͷָ��
����
	��ȡѭ�������ͷָ��
*/
CirLinkListNode* GetFisrtNode(CirLinkList *list);


/**
CirLinkListNode* GetHeadNode(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	����ͷ���ĵ�ַ
����
	��ȡָ��ͷ����ָ��
*/
CirLinkListNode* GetHeadNode(CirLinkList *list);

#endif // __CIRCirLinkList_H__
