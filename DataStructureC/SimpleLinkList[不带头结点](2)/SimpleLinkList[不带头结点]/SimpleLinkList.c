#include "SimpleLinkList.h"






// ��ʼ��������list
void InitLinkList(LinkList *list)
{
	(*list) = NULL;			// ��ʼ��ֻͷָ��
}

// �Ե�������к���
void FinitLinkList(LinkList *list)
{
	(*list) = NULL;
}

// ��յ�����
void ClearLinkList(LinkList *list)
{
    while((*list) != NULL)
	{
        DeleteNode(list, 0);
	}
}



// ���ҵ�����list�е�position�����
LinkListNode* FindPosNode(LinkList *list, int position)
{
	assert(list != NULL);
	assert((*list) != NULL);									// ������Ϊ��
	assert(position >= 0 && position < LengthLinkList(list));		// ���ҵ�λ��ֻ����[0, length)

	LinkListNode 	*pNode	= (LinkListNode *)(*list);
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


// ������list���ҵ�currNode��ǰһ�����
LinkListNode *FindPrevNode(LinkList *list, LinkListNode *currNode)
{
	assert(list != 	NULL);
	assert(currNode != NULL);

	LinkListNode *pNode = (LinkListNode *)(*list);

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

// �жϽ��nodeָ��������ǲ��������еĽ��
int IsNodeInList(LinkList *list, LinkListNode *node)
{
	assert(list != NULL);									// ������Ϊ��	assert(Node != NULL);									// �����ҵ�ָ�벻��Ϊ��

	LinkListNode 	*pNode	= (LinkListNode *)(*list);
    int 			pos 	= -1;

    while(pNode != NULL && pNode != node)		// �����������ҵ���position������λ��
	{
		pNode = pNode->m_next;
		pos++;
	}

	if(pNode == NULL)
	{	// ���ҳɹ�
		return -1;
	}
	else
	{	// ����ʧ��
#ifdef DEBUG
		printf("Find the [%p] point in the first %d pointer of the list...\n", node, pos);
#endif // DEBUG
		return pos;
	}
}

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
LinkListNode* FindDataNode(LinkList *list, ElemType data, int *position)
{
	LinkListNode *node = (LinkListNode *)(*list);
	int pos = 0;
	while(node != NULL && node->m_data != data)
	{
		node = node->m_next;
		pos++;
	}
	*position = pos;				// �����ֵ�λ�ô��ݻ�ȥ

	return node;					// ���ؽ�����Ϣ
}



// ������data��������ĵ�position��λ��
LinkListNode* InsertNode(LinkList *list, int position, ElemType data)
{
	assert(position >=0 && position < LengthLinkList(list) + 1);	// �����λ��Ӧ����[0-length]

	LinkListNode *pNode = NULL;
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
	if(position == 0)			// ���Ҫ�����һ��Ԫ��
	{
		// �����ǰ�����ǿ�����
		if(list != NULL && (*list) == NULL)	// LinkList list = NULL�����Ŀ�����
		{	// ��ʱ(*list)->m_next�����ERROR
			(*list) = newNode;
		}
		else								// ���������ǿ�����
		{
			newNode->m_next = (*list);
			(*list) = newNode;
			//printf("%p  %p %p\n\n", *list, newNode, (*list)->m_next);
		}
	}
	else								// ����ǰ�����ǿ�����
	{
		pNode = FindPosNode(list, position - 1);		// �ҵ���������ǰһ��ָ��
		// ��ָ��newNode������pNode�ĺ���
		newNode->m_next = pNode->m_next;
		pNode->m_next = newNode;
	}
#ifdef DEBUG
	printf("Insert the value %d into list at position %d...\n", data, position);
#endif // DEBUG

	return newNode;					// ����ָ�������½���ָ��
}


// ������data���������pNode������һ��λ�ø�λ��
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
	if(prevNode == (LinkListNode *)(*list))		// ���Ҫ�����Ԫ���ǵ�һ��Ԫ��
	{
		if(list != NULL && (*list) == NULL)	// �����ǰ�����ǿ�����(LinkList list = NULL�����Ŀ�����)
		{	// ��ʱ(*list)->m_next�����ERROR
			(*list) = newNode;
		}
		else								// ���������ǿ�����
		{
			newNode->m_next = (*list)->m_next;
			(*list) = newNode;
		}
	}
	else
	{
		// ��ָ��newNode������pNode�ĺ���
		newNode->m_next = prevNode->m_next;
		prevNode->m_next = newNode;
	}

#ifdef DEBUG
	printf("The new node is inserted after point pointer[%p]\n", prevNode);
#endif // DEBUG
	return newNode;
}


// ɾ������list�е�position��ָ��
ElemType DeleteNode(LinkList *list, int position)
{
	assert(list != NULL);									// ����ָ�벻��Ϊ�ղ���Ϊ��
	assert(position >=0 && position < LengthLinkList(list));		// ��ɾ����ָ��λ�ý����������д��ڵ�λ��

	LinkListNode	*delNode = NULL;
	ElemType		delElem = -1;

	if(position == 0)				// ��������н�ʣ���һ��Ԫ��
	{
		delNode = (*list);				// ��ɾ���Ľ�����ͷָ��ָ��Ľ��
		if((*list)->m_next == NULL)	// ��ǰ�����н�ʣ���һ��Ԫ��
		{
			(*list) = NULL;			// �޸�ͷָ��Ϊ��[��������ʹ��LinkListNode **��ʽ�� ��Ϊ�޸���ͷָ���ָ��]
		}
		else						// ����������ж��Ԫ��
		{
			(*list) = delNode->m_next;
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
#ifdef DEBUG
	printf("Delete the list in the first [%d, %d] node...\n", position, delElem);
#endif // DEBUG
	return delElem;
}


// ɾ������list��prevNode���֮���ָ���ָ��
ElemType SubNode(LinkList *list, LinkListNode *prevNode)
{
	assert(list != NULL);						// ������Ϊ��
	assert(prevNode != NULL);						// ��ɾ������ǰһ��λ�ò���Ϊ��
	assert(IsNodeInList(list, prevNode) != -1);	// ��ɾ��λ�õ�ǰһ����������������

	LinkListNode	*delNode = NULL;
	ElemType		delElem = -1;

	if(prevNode == (*list))				// �����ɾ����Ԫ���������е�һ��Ԫ��
	{
		delNode = (*list);				// ��ɾ���Ľ�����ͷָ��ָ��Ľ��
		if((*list)->m_next == NULL)	// ��ǰ�����н�ʣ���һ��Ԫ��
		{
			(*list) = NULL;			// �޸�ͷָ��Ϊ��[��������ʹ��LinkListNode **��ʽ�� ��Ϊ�޸���ͷָ���ָ��]
		}
		else						// ����������ж��Ԫ��
		{
			(*list) = delNode->m_next;
		}
	}
	else								// �����ɾ�������������
	{
		// ɾ��prevode�ĺ�һ�����
		LinkListNode *delNode = prevNode->m_next;
		prevNode->m_next = delNode->m_next;
	}
	delElem = delNode->m_data;
	free(delNode);


	return delElem;

}

// ɾ������list��currNodeָ����ָ����Ǹ����
ElemType DeleteCurrNode(LinkList *list, LinkListNode *currNode)
{
	assert(list != NULL);							// ������Ϊ��
	assert(currNode != NULL);							// ��ɾ������ǰһ��λ�ò���Ϊ��
	assert(IsNodeInList(list, currNode) != -1);	// ��ɾ���Ľ�������������

	ElemType delElem = -1;							// ��ɾ������������
	LinkListNode *delNode = NULL;					// ָ��Ҫɾ���Ľ���ָ��

	if(currNode->m_next != NULL)					// �����ɾ����㲻�����һ�����
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
		LinkListNode *prevNode = FindPrevNode(list, currNode);
		prevNode->m_next = NULL;

	}
	free(delNode);

	return delElem;
}

// ��ʾ������
void ShowList(LinkList *list)
{
	printf("there are %d data in list\n", LengthLinkList(list));

	LinkListNode *pNode = (LinkListNode *)(*list);			// ��ͷָ�뿪ʼ����

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

// �޸ĵ�����list��position������������Ϊdata
void SetNode(LinkList *list, int position, ElemType data)
{
	LinkListNode *pNode = FindPosNode(list, position);		// �ҵ�������ĵ�position�����

	pNode->m_data = data;
}


// ��ȡ������list��position������������
ElemType GetNode(LinkList *list, int position)
{
	LinkListNode *pNode = FindPosNode(list, position);		// �ҵ�������ĵ�position�����

	return pNode->m_data;
}

// ��ȡ������ĳ���
int LengthLinkList(LinkList *list)
{
	assert(list != NULL);

	int length = 0;
	LinkListNode *pNode = (LinkListNode *)(*list);

	while(pNode != NULL)
	{
		pNode = pNode->m_next;
		length++;
	}
	return length;
}


//	�жϵ������ǲ��ǿձ�
bool IsEmptyLinkList(LinkList *list)
{
	return (list == NULL);
	// return (list->m_head == NULL);
}

