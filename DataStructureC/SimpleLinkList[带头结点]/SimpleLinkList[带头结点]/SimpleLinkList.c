#include "SimpleLinkList.h"





// ����һ�����������ݽṹ�� ��������ָ��
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

// ��ʼ��������list
void InitLinkList(LinkList *list)
{
	if((list->m_head = malloc(sizeof(LinkListNode))) == NULL)		// Ϊͷ��㿪�ٿռ�
	{	// ����ʧ��
        fprintf(stderr, "not enough memory when MALLOC HEAD...");
        exit(EXIT_FAILURE);
	}
	list->m_head->m_next = NULL;			// ��ʼ��ֻ��ͷ���
	list->m_head->m_data = 0;				// ����Ԫ�ظ���Ϊ0
	list->m_length = 0;						// ����Ԫ�ظ���Ϊ0
}

// ���ٵ�����list
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

// ��յ�����
void ClearLinkList(LinkList *list)
{
    while(list->m_head->m_next != NULL)
	{
        DeleteNode(list, 0);
	}
}

// �Ե�������к���
void FinitLinkList(LinkList *list)
{
	assert(list->m_head->m_next == NULL);		// ����ָ����Կ�����
	// assert(list->m_length == 0);
	if(list->m_head != NULL)			// �����ʱͷ���ռ�δ������
	{
		free(list->m_head);

		list->m_head = NULL;
		list->m_length = -1;			// δ����ʼ���ĵ�����Ԫ�ظ�����Ϊ-1
	}
}

// ���ҵ�����list�е�position�����
LinkListNode* FindPosNode(LinkList *list, int position)
{
	assert(list != NULL);									// ������Ϊ��
	assert(position >= -1 && position < list->m_length);	// �����wλ��ֻ����[-1~length]

	LinkListNode 	*pNode	= list->m_head;
    int 			pos 	= -1;

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


// �жϽ��nodeָ��������ǲ��������еĽ��
int IsNodeInList(LinkList *list, LinkListNode *node)
{
	assert(list != NULL);									// ������Ϊ��	assert(Node != NULL);									// �����ҵ�ָ�벻��Ϊ��

	LinkListNode 	*pNode	= list->m_head->m_next;
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
		printf("Find the [%p] point in the first %d pointer of the list...\n", fNode, pos);
#endif // DEBUG
		return pos;
	}
}


//	�ҵ�������Ϊdata�Ľ���״γ��ֵ�λ�ò����ؽ����Ϣ
LinkListNode* FindDataNode(LinkList *list, ElemType data, int *position)
{
	LinkListNode *node = list->m_head->m_next;
	int pos = 0;
	while(node != NULL && node->m_data != data)
	{
		node = node->m_next;
		pos++;
	}
	*position = pos;				// �����ֵ�λ�ô��ݻ�ȥ

	return node;					// ���ؽ�����Ϣ
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


// ������data��������ĵ�position��λ��
LinkListNode *InsertNode(LinkList *list, int position, ElemType data)
{
	assert(list != NULL);
	assert(position >=0 && position < list->m_length + 1);

	LinkListNode *prevNode = FindPosNode(list, position - 1);			// �ҵ�������λ�õ�ǰһ�����
	LinkListNode *newNode = NULL;

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
//	if((newNode = (LinkListNode *)malloc(sizeof(LinkListNode))) == NULL)	// Ϊ�½�㿪�ٿռ�
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


// ɾ������list�е�position��ָ��
ElemType DeleteNode(LinkList *list, int position)
{
	assert(list != NULL);
	assert(position >=0 && position < list->m_length);
	LinkListNode *prevNode = FindPosNode(list, position - 1);			// �ҵ���position - 1�����

	// ɾ��pNode�ĺ�һ�����
	LinkListNode *delNode = prevNode->m_next;
	ElemType delElem = delNode->m_data;
	prevNode->m_next = delNode->m_next;
	free(delNode);

	list->m_length--;				// �����Ŀ����һ��
	list->m_head->m_data--;			// ͷ����������ͬ���洢�Ž������

	return delNode;
}

// ɾ������list��prevNode���֮���ָ���ָ��
ElemType SubNode(LinkList *list, LinkListNode *prevNode)
{
	assert(list != NULL);						// ������Ϊ��
	assert(prevNode != NULL);						// ��ɾ������ǰһ��λ�ò���Ϊ��
	assert(IsNodeInList(list, prevNode) != -1);	// ��ɾ��λ�õ�ǰһ����������������

	// ɾ��pNode�ĺ�һ�����
	LinkListNode *delNode = prevNode->m_next;
	ElemType delElem = delNode->m_data;
	prevNode->m_next = delNode->m_next;
	free(delNode);

	list->m_length--;				// �����Ŀ����һ��
	list->m_head->m_data--;			// ͷ����������ͬ���洢�Ž������

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
	list->m_length--;				// �����Ŀ����һ��
	list->m_head->m_data--;			// ͷ����������ͬ���洢�Ž������

	return delElem;
}
// ��ʾ������
void ShowList(LinkList *list)
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

	LinkListNode *pNode = list->m_head->m_next;			// ��ͷָ�뿪ʼ����

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
	return list->m_length;
}


//	�жϵ������ǲ��ǿձ�
bool IsEmptyLinkList(LinkList *list)
{
	return (list->m_length == 0);
	// return (list->m_head->m_next == NULL);
}


