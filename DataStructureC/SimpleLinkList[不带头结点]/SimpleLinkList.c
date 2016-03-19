#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



///*////////////////////////////////////////////////////////////////////////////
///
///	�����ͳ�ʼ��������
///
///	����		LinkList* CreatLinkList(void)
///	��ʼ��	void InitLinkList(LinkList *list)
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
LinkList* CreateLinkList(void)
{
	LinkList *list = NULL;
	if((list = (LinkList *)malloc(sizeof(LinkList))) == NULL)		// ���ٵ�����Ŀռ�
	{	// ����ʧ��
        fprintf(stderr, "not enough memory when CREATE LIST...\n");
        exit(EXIT_FAILURE);
	}

	InitLinkList(list);				// ��ʼ��������

	return list;
}

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
void InitLinkList(LinkList *list)
{
	list->m_head = NULL;			// ��ʼ��ֻ��ͷ���
	list->m_length = 0;						// ����Ԫ�ظ���Ϊ0
}


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
LinkList* DestroyLinkList(LinkList *list)
{
	ClearLinkList(list);			// �������
	FinitLinkList(list);			// ����ͷ���
	if(list != NULL)				// ��������Ŀռ�
	{
		free(list);
		list = NULL;
	}
}



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
void FinitLinkList(LinkList *list)
{
	assert(list->m_head == NULL);		// ����ָ����Կ�����
	// list->m_head = NULL;
	list->m_length = -1;			// δ����ʼ���ĵ�����Ԫ�ظ�����Ϊ-1
}


/**
void ClearLinkList(LinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��յ������е�����Ԫ��
*/
void ClearLinkList(LinkList *list)
{
    while(list->m_head != NULL)
	{
        DeleteNode(list, 0);
	}
}



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
LinkListNode* FindPosNode(LinkList *list, int position)
{
	assert(list != NULL);									// ������Ϊ��
	assert(position >= 0 && position < list->m_length);		// ���ҵ�λ��ֻ����[0, length)

	LinkListNode 	*pNode	= list->m_head;
    int 			pos 	= 0;

    while(pNode != NULL && pos < position)		// �����������ҵ���position������λ��
	{
		pNode = pNode->m_next;
		pos++;
	}

	if(pNode == NULL || pos < position)
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
LinkListNode *FindPrevNode(LinkList *list, LinkListNode *currNode)
{
	assert(list != 	NULL);
	assert(currNode != NULL);

	LinkListNode *pNode = list->m_head;

	while(pNode->m_next != NULL && pNode->m_next != currNode)
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
int IsNodeInList(LinkList *list, LinkListNode *node)
{
	assert(list != NULL);									// ������Ϊ��	assert(Node != NULL);									// �����ҵ�ָ�벻��Ϊ��

	LinkListNode 	*pNode	= list->m_head;
    int 			pos 	= 0;

    while(pNode != NULL && pNode != node)		// �����������ҵ���position������λ��
	{
		pNode = pNode->m_next;
		pos++;
	}

	if(pNode != node)
	{	// ����ʧ��
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
LinkListNode* InsertNode(LinkList *list, int position, ElemType data)
{
	assert(list != NULL);									// ������Ϊ��
	assert(position >=0 && position < list->m_length + 1);	// �����λ��Ӧ����[0-length]

	LinkListNode *prevNode = NULL;
	LinkListNode *newNode = NULL;

	// Ϊ�½�㿪�ٿռ䲢��
	if((newNode = (LinkListNode *)malloc(sizeof(LinkListNode))) == NULL)	// Ϊ�½�㿪�ٿռ�
	{	// �����½��ʧ��
		fprintf(stderr, "not enough memeory\n");
        exit(EXIT_FAILURE);
	}
	else
	{	// �����½��ɹ����Ҹ�ֵ
		newNode->m_data = data;
		newNode->m_next = NULL;
	}

	// ���½�������������
	if(position == 0)			// �����ǰ�����ǿ�����
	{	/// ���������е�һ����㣬 ����ͷ���ĵ���������ɾ����һ��Ԫ��ʱ��Ҫ���������ж�
		if(list->m_head == NULL)	// �������֮ǰ�������ǿձ�
		{
			list->m_head = newNode;		// �ձ�ֱ�ӽ��½����뼴��
		}
		else						// ���������ǿձ�
		{
			//prevNode = list->m_head;
			newNode->m_next = list->m_head;		// ���½�����ͷָ���ǰ�漴��
			list->m_head = newNode;
		}
	}
	else								// ����ǰ�����ǿ�����
	{
		prevNode = FindPosNode(list, position - 1);		// �ҵ���������ǰһ��ָ��
		// ��ָ��newNode������pNode�ĺ���
		newNode->m_next = prevNode->m_next;
		prevNode->m_next = newNode;
	}

	list->m_length++;				// �����Ŀ����һ��

#ifdef DEBUG
	printf("Insert the value %d into list at position %d...\n", data, position);
#endif // DEBUG


	return newNode;					// ����ָ�������½���ָ��
}


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
[ע��]	���ڵ�������������ͷ����ô��һ��Ԫ�ز�����ǰ������˲����һ��Ԫ��ʱ��Ĭ����prevNode��list
*/
LinkListNode *AddNode(LinkList *list, LinkListNode *prevNode, ElemType data)
{
	assert(prevNode != NULL);						// ����㲻���ǿ�ָ��

	LinkListNode *newNode = NULL;
	if((newNode = (LinkListNode *)malloc(sizeof(LinkListNode))) == NULL)	// Ϊ�½�㿪�ٿռ�
	{	// �����½��ʧ��
		fprintf(stderr, "not enough memeory\n");
        exit(EXIT_FAILURE);
	}
	//else
	//{
	// �����½��ɹ�
	newNode->m_data = data;
	newNode->m_next = NULL;
	if(prevNode == (LinkListNode *)list)
	{	/// ���������е�һ����㣬 ����ͷ���ĵ���������ɾ����һ��Ԫ��ʱ��Ҫ���������ж�
		if(list->m_head == NULL)	// �������֮ǰ�������ǿձ�
		{
			list->m_head = newNode;		// �ձ�ֱ�ӽ��½����뼴��
		}
		else						// ���������ǿձ�
		{
			//prevNode = list->m_head;
			newNode->m_next = list->m_head;		// ���½�����ͷָ���ǰ�漴��
			list->m_head = newNode;
		}
	}
	else
	{
		// ��ָ��newNode������pNode�ĺ���
		newNode->m_next = prevNode->m_next;
		prevNode->m_next = newNode;
	}
	list->m_length++;				// �����Ŀ����һ��
	//}
#ifdef DEBUG
	printf("The new node is inserted after point pointer[%p]\n", pNode);
#endif // DEBUG
	return newNode;
}



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
ElemType DeleteNode(LinkList *list, int position)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	��������ĵ�position�����ɾ��
*/
ElemType DeleteNode(LinkList *list, int position)
{
	assert(list != NULL);									// ɾ������Ϊ��
	assert(position >=0 && position < list->m_length);		// ��ɾ����ָ��λ�ý����������д��ڵ�λ��

	LinkListNode	*delNode = NULL;
	ElemType		delElem = -1;
	if(position == 0)					// �����ɾ�����������е�һ��ָ�룬 ��һ��Ԫ��û��ǰ�����
	{	// ɾ�������е�һ�����
		delNode = list->m_head;

		if(list->m_head->m_next == NULL)	// ���������ֻʣ��һ��Ԫ��
		{
			list->m_head = NULL;
		}
		else								// ����������ʣ�¶��Ԫ��
		{
			list->m_head = delNode->m_next;
		}
	}
	else								// �����ɾ�������������
	{
		LinkListNode *pNode = FindPosNode(list, position - 1);			// �ҵ���position - 1�����

		// ɾ��pNode�ĺ�һ�����
		delNode = pNode->m_next;
		pNode->m_next = delNode->m_next;
	}
	delElem = delNode->m_data;		// �����ɾ������������
	free(delNode);
	list->m_length--;				// �����Ŀ����һ��
#ifdef DEBUG
	printf("Delete the list in the first %d node...\n", position);
#endif // DEBUG
	return delElem;
}


/**
ElemType SubNode(LinkList *list, LinkListNode *prevNode)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	ɾ������list��prevNode���֮���ָ���ָ��
*/
ElemType SubNode(LinkList *list, LinkListNode *prevNode)
{
	assert(list != NULL);						// ������Ϊ��
	assert(prevNode != NULL);						// ��ɾ������ǰһ��λ�ò���Ϊ��
	assert(IsNodeInList(list, prevNode) != -1);	// ��ɾ��λ�õ�ǰһ����������������

	LinkListNode	*delNode = NULL;
	ElemType		delElem = -1;

	if(prevNode == list)		// �����ɾ�����������е�һ��ָ�룬 ��һ��Ԫ��û��ǰ�����[������ʱĬ��Ϊlist]
	{	// ɾ�������е�һ�����
		delNode = list->m_head;			// ��ɾ����Ԫ��Ϊͷָ��ָ���Ԫ��

		if(list->m_head->m_next == NULL)	// ���������ֻʣ��һ��Ԫ��
		{
			list->m_head = NULL;
		}
		else								// ����������ʣ�¶��Ԫ��
		{
			list->m_head = delNode->m_next;
		}
	}
	else								// �����ɾ�������������
	{
		// ɾ��pNode�ĺ�һ�����
		delNode = prevNode->m_next;
		prevNode->m_next = delNode->m_next;
	}
	delElem = delNode->m_data;
	free(delNode);

	list->m_length--;				// �����Ŀ����һ��
	list->m_head->m_data--;			// ͷ����������ͬ���洢�Ž������

	return delElem;
}


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
ElemType DeleteCurrNode(LinkList *list, LinkListNode *currNode)
{
	assert(list != NULL);							// ������Ϊ��
	assert(currNode != NULL);						// ��ɾ������ǰһ��λ�ò���Ϊ��
	assert(IsNodeInList(list, currNode) != -1);		// ��ɾ���Ľ�������������

	ElemType delElem = -1;							// ��ɾ������������
	LinkListNode *delNode = NULL;					// ָ��Ҫɾ���Ľ���ָ��

	if(currNode == list->m_head)					// �����ɾ�����ǵ�һ�����
	{	// ɾ�������е�һ����㣬 ����ͷ���ĵ���������ɾ����һ��Ԫ��ʱ��Ҫ���������ж�
		delNode = list->m_head;			// ��ɾ����Ԫ��Ϊͷָ��ָ���Ԫ��

		if(list->m_head->m_next == NULL)	// ���������ֻʣ��һ��Ԫ��
		{
			list->m_head = NULL;
		}
		else								// ����������ʣ�¶��Ԫ��
		{
			list->m_head = delNode->m_next;
		}
	}
	else									// ����ɾ���Ĳ��ǵ�һ�����
	{
		if(currNode->m_next != NULL)					// �����ɾ����㲻�����һ�����
		{	// ɾ�����������һ�����ʱ����Ҫ����ǰ����ָ�����ÿ�
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
			LinkListNode *prevNode = FindPrevNode(list, currNode);
			prevNode->m_next = NULL;
		}
	}
	free(delNode);
	list->m_length--;				// �����Ŀ����һ��
	return delElem;
}



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

/**
void ShowLinkList(LinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��ʾ���������Ϣ
*/
void ShowList(LinkList *list)
{
	printf("there are %d data in list\n", list->m_length);

	LinkListNode *pNode = list->m_head;			// ��ͷָ�뿪ʼ����

	while(pNode != NULL)								//��ʼ����������
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
void SetNode(LinkList *list, int position, ElemType data)
{
	LinkListNode *pNode = FindPosNode(list, position);		// �ҵ�������ĵ�position�����

	pNode->m_data = data;
}


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
ElemType GetNode(LinkList *list, int position)
{
	LinkListNode *pNode = FindPosNode(list, position);		// �ҵ�������ĵ�position�����

	return pNode->m_data;
}


/**
int LengthLinkList(LinkList *list)
����
	list	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	������ĳ���
����
	��ȡ������ĳ���
*/
int LengthLinkList(LinkList *list)
{
	return list->m_length;
}


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
bool IsEmptyLinkList(LinkList *list)
{
	return (list->m_length == 0);
	// return (list->m_head == NULL);
}




#define LIST_SIZE 7
// main
int main(void)
{
	int pos;

	printf("TEST 1...\n");
	LinkList *plist = CreateLinkList( );				// ����������
	for(int pos = 0; pos < LIST_SIZE; pos++)			// ѭ���������в�������
	{
		InsertNode(plist, pos, pos + 1);
		printf("HEAD = %p\n", plist->m_head);
	}
	ShowList(plist);									// �����������ʾ���������Ϣ

	DeleteNode(plist, 0);								// ɾ����һ��Ԫ��
	ShowList(plist);
	DeleteNode(plist, 1);								// ɾ���ڶ���Ԫ��
	ShowList(plist);

	ClearLinkList(plist);								// �����������
	ShowList(plist);
	DestroyLinkList(plist);								// ������������
	plist = NULL;

	printf("\n\nTEST 2...\n");
	LinkList list;
	InitLinkList(&list);								// ��ʼ��������
	for(int pos = 0; pos < LIST_SIZE; pos++)			// ѵ���������в�������
	{
		InsertNode(&list, pos, pos + 1);
	}
	ShowList(&list);									// ��ʾ������
	ClearLinkList(&list);								// ��յ�����
//	FinitLinkList(&list);		// ERROR== list->m_head->m_next == NULL
	ShowList(&list);

	printf("\n\nTEST 3...\n");
	LinkListNode *prevNode = NULL;
	LinkListNode *addNode = NULL;
	prevNode = InsertNode(&list, 0, 1);					// ���ڲ���ͷ������Խ��в����һ��Ԫ��ʱ��һ��Ԫ��û��ǰ�����
														// ����Ҳ����ʹ������ע�ӵ��Ĵ���
	for(int pos = 1; pos < LIST_SIZE; pos++)
	{
		if((addNode = AddNode(&list, prevNode, pos + 1)) != NULL)
		{
            prevNode = addNode;
		}
	}
//	LinkListNode *prevNode = (LinkListNode*)&list;
//	LinkListNode *addNode = NULL;
//	for(int pos = 0; pos < LIST_SIZE; pos++)
//	{
//		if((addNode = AddNode(&list, prevNode, pos + 1)) != NULL)
//		{
//            prevNode = addNode;
//		}
//	}
	ShowList(&list);
	while(IsEmptyLinkList(&list) != true)			// ѭ��ɾ���������е�����
	{
		DeleteCurrNode(&list, list.m_head);			// ɾ����һ��Ԫ��
	}
	ShowList(&list);									// ��ʾ������

	return 	EXIT_SUCCESS;
}
