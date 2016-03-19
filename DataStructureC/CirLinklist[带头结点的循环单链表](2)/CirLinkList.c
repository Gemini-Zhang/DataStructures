#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//#define DEBUG				// ���Բ�׮��Ϣ��

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
typedef struct CirLinkList
{
	CirLinkListNode	*m_head;				// ����ͷ���
	CirLinkListNode *m_tail;				// ѭ������β��
	int				m_length;				// ���������ݽ�����ָ����
//  this->m_head == this->m_tail->m_next;	// ���ֻ��β���Ҫ���˵ȼ۹�ϵ
}CirLinkList;



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
CirLinkList* CreateCirLinkList(void)
{
	CirLinkList *list = NULL;
	if((list = (CirLinkList *)malloc(sizeof(CirLinkList))) == NULL)		// ���ٵ�����Ŀռ�
	{	// ����ʧ��
        fprintf(stderr, "not enough memory when CREATE LIST...\n");
        exit(EXIT_FAILURE);
	}

	InitCirLinkList(list);				// ��ʼ��������

	return list;
}



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
void InitCirLinkList(CirLinkList *list)
{
	if((list->m_head = malloc(sizeof(CirLinkListNode))) == NULL)		// Ϊͷ��㿪�ٿռ�
	{	// ����ʧ��
        fprintf(stderr, "not enough memory when MALLOC HEAD...");
        exit(EXIT_FAILURE);
	}

	// ��ʼ��ͷ�����Ϣ
	list->m_head->m_next = list->m_head;	// ��ʼ��ֻ��ͷ���[��ѭ�����������]
	list->m_head->m_data = 0;				// ����Ԫ�ظ���Ϊ0
	list->m_length = 0;						// ����Ԫ�ظ���Ϊ0
	list->m_tail = list->m_head;			// βָ��ָ��ͷ���
}

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
CirLinkList* DestroyCirLinkList(CirLinkList *list)
{
	ClearCirLinkList(list);			// �������
	FinitCirLinkList(list);			// ����ͷ���
	if(list != NULL)				// ��������Ŀռ�
	{
		free(list);
		list = NULL;
	}
}





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
void FinitCirLinkList(CirLinkList *list)
{
	assert(list->m_head->m_next == list->m_head);		// ����ָ����Կ�����
	// assert(list->m_length == 0);
	if(list->m_head != NULL)			// �����ʱͷ���ռ�δ������
	{
		free(list->m_head);

		list->m_head = NULL;
		list->m_length = -1;			// δ����ʼ���ĵ�����Ԫ�ظ�����Ϊ-1
	}
}



/**
void ClearCirLinkList(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��յ������е�����Ԫ��
*/
void ClearCirLinkList(CirLinkList *list)
{
	while(list->m_head->m_next != list->m_head)
	{
        DeleteNode(list, 0);
	}
}

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
CirLinkListNode* FindPosNode(CirLinkList *list, int position)
{
	assert(list != NULL);									// ������Ϊ��
	assert(position >= -1 && position < list->m_length);	// �����wλ��ֻ����[-1~length]

	CirLinkListNode 	*pNode	= list->m_head->m_next;
//	CirLinkListNode *pNode = list->m_tail->m_next;			// ��ѭ������ֻ��βָ��ʱ���ô˴���

	if(position == -1)											// -1��ʾѰ��ͷָ���ǰ��
	{
		return list->m_head;								// ֱ�ӷ���ǰ��
	}

    int 			pos 	= 0;

    while(pNode != list->m_head && pos < position)		// �����������ҵ���position������λ��
	{
		pNode = pNode->m_next;
		pos++;
	}

	if(pos < position)		// ����ҵ�����β����û���ҵ�
	{
		return NULL;
	}
	else
	{
#ifdef DEBUG
		printf("Find the %d point SUCCESS...[%p]\n", position, pNode);
#endif // DEBUG
		return pNode;
	}
}

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

CirLinkListNode *FindPrevNode(CirLinkList *list, CirLinkListNode *currNode)
{
	assert(list != 	NULL);
	assert(currNode != NULL);

	CirLinkListNode *pNode = list->m_head;
//	CirLinkListNode *pNode = list->m_tail->m_next;			// ��ѭ������ֻ��βָ��ʱ���ô˴���

	while(pNode->m_next != list->m_head && pNode->m_next != currNode)
	{
		pNode = pNode->m_next;
	}

	if(pNode->m_next == currNode)				// ���ҳɹ�
	{
		return pNode;
	}
	else										// ����ʧ��
	{
		return NULL;
	}
}



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
int IsNodeInList(CirLinkList *list, CirLinkListNode *node)
{
	assert(list != NULL);									// ������Ϊ��	assert(Node != NULL);									// �����ҵ�ָ�벻��Ϊ��

	CirLinkListNode 	*pNode	= list->m_head->m_next;
//	CirLinkListNode *pNode = list->m_tail->m_next;			// ��ѭ������ֻ��βָ��ʱ���ô˴���
    int 			pos 	= 0;

    while(pNode != list->m_head && pNode != node)		// �����������ҵ���position������λ��
	{
		pNode = pNode->m_next;
		pos++;
	}

	if(pNode != node)
	{	// ���ҳɹ�
		return -1;
	}
	else
	{	// ����ʧ��
#ifdef DEBUG
		printf("Find the [%p] point in the first %d pointer of the list...\n", fNode, pos);
#endif // DEBUG
		return pos;
	}
}


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
CirLinkListNode* FindDataNode(CirLinkList *list, ElemType data, int *position)
{
	CirLinkListNode *node = list->m_head->m_next;
//	CirLinkListNode *pNode = list->m_tail->m_next;			// ��ѭ������ֻ��βָ��ʱ���ô˴���

	int pos = 0;
	while(node != list->m_head && node->m_data != data)
	{
		node = node->m_next;
		pos++;
	}
	*position = pos;				// �����ֵ�λ�ô��ݻ�ȥ

	return node;					// ���ؽ�����Ϣ
}


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
CirLinkListNode* AddNode(CirLinkList *list, CirLinkListNode *prevNode, ElemType data)
{
	assert(prevNode != NULL);						// ����㲻���ǿ�ָ��

	CirLinkListNode *newNode = NULL;

	if((newNode = (CirLinkListNode *)malloc(sizeof(CirLinkListNode))) == NULL)	// Ϊ�½�㿪�ٿռ�
	{	// �����½��ʧ��
		fprintf(stderr, "not enough memeory\n");
        exit(EXIT_FAILURE);
	}
	else
	{
		// �����½��ɹ�
		newNode->m_data = data;
		newNode->m_next = NULL;
	}

	// ��ָ��newNode������pNode�ĺ���
	newNode->m_next = prevNode->m_next;
	prevNode->m_next = newNode;

	list->m_length++;				// �����Ŀ����һ��
	list->m_head->m_data++;			// ͷ����������ͬ���洢�Ž������
	//}
#ifdef DEBUG
	printf("The new node is inserted after point pointer[%p]\n", pNode);
#endif // DEBUG
	return newNode;
}


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
CirLinkListNode* InsertNode(CirLinkList *list, int position, ElemType data)
{
	assert(list != NULL);
	assert(position >=0 && position < list->m_length + 1);

	CirLinkListNode *prevNode = FindPosNode(list, position - 1);			// �ҵ�������λ�õ�ǰһ�����
	CirLinkListNode *newNode = NULL;

	// �������InsertPointNodeֱ�ӽ������뵽pNode������
	if((newNode = AddNode(list, prevNode, data)) != NULL)	// ���µĽ����뵽������ǰһ��ָ��ĺ���
	{	// ����ɹ�
		return newNode;								// �����²���Ľ��
#ifdef DEBUG
		printf("Insert the value %d into list at position %d...\n", data, position);
#endif // DEBUG
	}
	else
	{
		return NULL;								// ����ʧ�ܷ���NULL
	}

//	//	�Կ���ʹ������Ĵ���
//	if((newNode = (CirLinkListNode *)malloc(sizeof(CirLinkListNode))) == NULL)	// Ϊ�½�㿪�ٿռ�
//	{	// �����½��ʧ��
//		fprintf(stderr, "not enough memeory\n");
//        exit(EXIT_FAILURE);
//	}
//	else
//	{	// �����½��ɹ�
//	newNode->m_data = data;
//	newNode->m_next = NULL;
//
//	// ��ָ��newNode������pNode�ĺ���
//	newNode->m_next = prevNode->m_next;
//	prevNode->m_next = newNode;
//
//	list->m_length++;				// �����Ŀ����һ��
//	list->m_head->m_data++;			// ͷ����������ͬ���洢�Ž������
//	}
}


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
ElemType DeleteNode(CirLinkList *list, int position)
{
	assert(list != NULL);
	assert(position >=0 && position < list->m_length);
	CirLinkListNode *prevNode = FindPosNode(list, position - 1);			// �ҵ���position - 1�����

	// ɾ��pNode�ĺ�һ�����
	CirLinkListNode *delNode = prevNode->m_next;
	ElemType delElem = delNode->m_data;
	prevNode->m_next = delNode->m_next;
	free(delNode);

	list->m_length--;				// �����Ŀ����һ��
	list->m_head->m_data--;			// ͷ����������ͬ���洢�Ž������

	return delElem;
}


/**
ElemType SubNode(CirLinkList *list, CirLinkListNode *prevNode)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	ɾ������list��prevNode���֮���ָ���ָ��
*/
ElemType SubNode(CirLinkList *list, CirLinkListNode *prevNode)
{
	assert(list != NULL);						// ������Ϊ��
	assert(prevNode != NULL);						// ��ɾ������ǰһ��λ�ò���Ϊ��
	assert(IsNodeInList(list, prevNode) != -1);	// ��ɾ��λ�õ�ǰһ����������������

	// ɾ��pNode�ĺ�һ�����
	CirLinkListNode *delNode = prevNode->m_next;
	ElemType delElem = delNode->m_data;
	prevNode->m_next = delNode->m_next;
	free(delNode);

	list->m_length--;				// �����Ŀ����һ��
	list->m_head->m_data--;			// ͷ����������ͬ���洢�Ž������

	return delElem;
}



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
ElemType DeleteCurrNode(CirLinkList *list, CirLinkListNode *currNode)
{
	assert(list != NULL);							// ������Ϊ��
	assert(currNode != NULL);							// ��ɾ������ǰһ��λ�ò���Ϊ��
	assert(IsNodeInList(list, currNode) != -1);	// ��ɾ���Ľ�������������

	ElemType 			delElem = -1;							// ��ɾ������������
	CirLinkListNode 	*delNode = NULL;					// ָ��Ҫɾ���Ľ���ָ��

//	if(list->m_length == 0)
//	{
//
//		return -1;
//	}
//	printf("length = %d\n", list->m_length);
	if(currNode->m_next != list->m_head)					// �����ɾ����㲻�����һ�����
	{
		// ��currNode�ĺ�һ�����delNode��Ϊɾ�����,
		delNode = currNode->m_next;
		currNode->m_next = delNode->m_next;			//��������ɾ��delNode

		// ����delNode�������򱣴浽delNode��
		delElem = currNode->m_data;					// delElem����currNode��������
		currNode->m_data = delNode->m_data;			// ����ɾ���Ľ����ʵ��currNode��һ�����, �����currNode������һ������������
	}
	else											// �����ɾ����������һ�����
	{
		// ֱ�ӽ����һ�����ɾ�����ɣ� Ӧ�ð���ǰһ������ָ����ֵΪ��
		delNode = currNode;
		// ����Ӧ�ý�currnNode��ǰһ������ָ����ֵΪ��[ʱ�临�Ӷ�O(n)]
		CirLinkListNode *prevNode = FindPrevNode(list, currNode);
		prevNode->m_next = list->m_head;			/// BUG1  ���һ�����ĺ�һ�����
	}
	free(delNode);
	list->m_length--;				// �����Ŀ����һ��
	list->m_head->m_data--;			// ͷ����������ͬ���洢�Ž������

	return delElem;
}




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
///*////////////////////////////////////////////////////////////////////////////

/**
void ShowCirLinkList(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��ʾ���������Ϣ
*/
void ShowList(CirLinkList *list)
{
// assert(list->m_head != NULL)
	if(list->m_head ==  NULL)			//  ���������û�б���ʼ��
	{
		fprintf(stderr, "you can't SHOW the list without the list INITLINKLIST...\n");
		return ;
	}


	printf("there are %d data in list\n", list->m_length);
	if(list->m_length == 0)
	{
		return ;
	}

	CirLinkListNode *pNode = list->m_head->m_next;			// ��ͷָ�뿪ʼ����

	while(pNode != list->m_head)								//��ʼ����������
	{
		printf("%d  ", pNode->m_data);
        pNode = pNode->m_next;
	}
	printf("\n");

//	ElemType data;
//	for(int pos = 0; pos < list->m_length; pos++)
//	{
//		data = GetNode(list, pos);
//		printf("%d  ", data);
//	}
//	printf("\n");
}

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
void SetNode(CirLinkList *list, int position, ElemType data)
{
	CirLinkListNode *pNode = FindPosNode(list, position);		// �ҵ�������ĵ�position�����

	pNode->m_data = data;
}

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
ElemType GetNode(CirLinkList *list, int position)
{
	CirLinkListNode *pNode = FindPosNode(list, position);		// �ҵ�������ĵ�position�����

	return pNode->m_data;
}


/**
int LengthCirLinkList(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	������ĳ���
����
	��ȡ������ĳ���
*/
int LengthCirLinkList(CirLinkList *list)
{
	return list->m_length;
}


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
bool IsEmptyCirLinkList(CirLinkList *list)
{
    return (list->m_head->m_next == list->m_head);
//	return (list->m_tail == this->m_head);
}


/**
CirLinkListNode* GetFisrtNode(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	����ͷָ��
����
	��ȡѭ�������ͷָ��
*/
CirLinkListNode* GetFisrtNode(CirLinkList *list)
{
	return list->m_head->m_next;
//	return list->m_tail->m_next->m_next;			// ֻ��βָ���ʱ��ʹ�ô˴���
}


/**
CirLinkListNode* GetHeadNode(CirLinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	����ͷ���ĵ�ַ
����
	��ȡָ��ͷ����ָ��
*/
CirLinkListNode* GetHeadNode(CirLinkList *list)
{
	return list->m_head;
//	return list->m_tail->m_next;			// ֻ��βָ���ʱ��ʹ�ô˴���
}






#define LIST_SIZE 7
// ������
int main(void)
{
	int pos;

	printf("TEST 1...\n");
	CirLinkList *plist = CreateCirLinkList( );				// ����������
	for(int pos = 0; pos < LIST_SIZE; pos++)			// ѭ���������в�������
	{
		InsertNode(plist, pos, pos + 1);
	}
	ShowList(plist);									// �����������ʾ���������Ϣ

	DeleteNode(plist, 0);								// ɾ����һ��Ԫ��
	ShowList(plist);
	DeleteNode(plist, 1);								// ɾ���ڶ���Ԫ��
	ShowList(plist);

	ClearCirLinkList(plist);								// �����������
	ShowList(plist);
	DestroyCirLinkList(plist);								// ������������
	plist = NULL;

	printf("\n\nTEST 2...\n");
	CirLinkList list;
	InitCirLinkList(&list);								// ��ʼ��������
	for(int pos = 0; pos < LIST_SIZE; pos++)			// ѵ���������в�������
	{
		InsertNode(&list, pos, pos + 1);
	}
	ShowList(&list);									// ��ʾ������
	ClearCirLinkList(&list);								// ��յ�����
//	FinitLinkList(&list);		// ERROR== list->m_head->m_next == NULL
	ShowList(&list);

	printf("\n\nTEST 3...\n");
	CirLinkListNode *prevNode = list.m_head;
	CirLinkListNode *addNode = NULL;
	for(int pos = 0; pos < LIST_SIZE; pos++)
	{
		if((addNode = AddNode(&list, prevNode, pos + 1)) != NULL)
		{
            prevNode = addNode;
		}
	}
	ShowList(&list);
	while(IsEmptyCirLinkList(&list) != true)			// ѭ��ɾ���������е�����
	{
		//printf("%p == %p\n", list.m_head->m_next, list.m_head);
		DeleteCurrNode(&list, list.m_head->m_next);
	}
	ShowList(&list);									// ��ʾ������

	return 	EXIT_SUCCESS;
}
