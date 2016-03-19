#include "CirLinkList.h"


///*////////////////////////////////////////////////////////////////////////////
///
///	�����ͳ�ʼ��������
///
///	����һ�����������ݽṹ������ʼ��ͷ��㣬Ȼ�󽫴����õĵ�����ָ�뷵��
///	CirLinkList* CreatCirLinkList(void)
///
///	��ʼ��������
///	void InitCirLinkList(CirLinkList *tail)
///*///////////////////////////////////////////////////////////////////////////

/**
CirLinkList* CreatCirLinkList(void)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
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
	CirLinkList *tail = NULL;
	if((tail = (CirLinkList *)malloc(sizeof(CirLinkList))) == NULL)		// ���ٵ�����β��㣨��ͷ��㣩�Ŀռ�
	{	// ����ʧ��
        fprintf(stderr, "not enough memory when CREATE LIST...\n");
        exit(EXIT_FAILURE);
	}

	InitCirLinkList(tail);				// ��ʼ��������
#ifdef DEBUG
	printf("ѭ�������ͷ���%p\n", tail);
#endif // DEBUG
	return tail;						// ������β���
}



/**
void InitCirLinkList(CirLinkList *tail)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
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
void InitCirLinkList(CirLinkList *tail)
{
	// ��ʼ��ͷ�����Ϣ
	tail->m_next = tail;					// ��ʼ��ֻ��ͷ���[��ѭ�����������]
	tail->m_data = 0;						// ����Ԫ�ظ���Ϊ0
}

///*////////////////////////////////////////////////////////////////////////////
///
///	�����Լ���������
///
///	������CreateCirLinkList�����ĵ�����
///	void DestroyCirLinkList(CirLinkList *tail)
///
///	��������
///	void FinitCirLinkList(CirLinkList *tail)
///
/// ��յ������е�����Ԫ��
///	void ClearCirLinkList(CirLinkList *tail)
///*////////////////////////////////////////////////////////////////////////////

/**
void DestroyCirLinkList(CirLinkList *tail)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	������CreateCirLinkList�����ĵ�����ִ�����²���
	����յ�����	���ͷ�ͷ���	���ͷŵ�����
ע��
	ʹ��CreateCirLinkList�����ĵ�������Ҫ��DestroyCirLinkList������
	���ⷢ���ڴ�й©
*/
CirLinkList* DestroyCirLinkList(CirLinkList **tail)
{
	ClearCirLinkList(tail);			// �������
	FinitCirLinkList(*tail);			// ����ͷ���
	if((*tail) != NULL)				// ��������Ŀռ�
	{
		free(*tail);
		*tail = NULL;
	}
}





/**
void FinitCirLinkList(CirLinkList *tail)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
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
void FinitCirLinkList(CirLinkList *tail)
{

	if(tail != NULL)			// �����ʱͷ���ռ�δ������
	{
		free(tail);				// ���β��㼴ͷ���

		tail = NULL;
	}
}



/**
void ClearCirLinkList(CirLinkList *tail)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��յ������е�����Ԫ��
*/
void ClearCirLinkList(CirLinkList **tail)
{
	while((*tail)->m_next->m_data != 0)
	//while(IsEmptyCirLinkList(tail) != true)
	{
        DeleteNode(tail, 0);
	}
}

///*////////////////////////////////////////////////////////////////////////////
///
///	���Һ���
///
///	���ҵ�����tail�е�position�����
///	CirLinkListNode* FindPosNode(CirLinkList *tail, int position)
///
///	������tail���ҵ�currNode��ǰһ�����
///	CirLinkListNode *FindPrevNode(CirLinkList *tail, CirLinkListNode *currNode)
///
/// �жϽ��nodeָ��������ǲ��������еĽ��
///	int IsNodeInList(CirLinkList *tail, CirLinkListNode *node)
///
///	�ҵ�������Ϊdata�Ľ���״γ��ֵ�λ�ò����ؽ����Ϣ
///	CirLinkListNode* FindDataNode(CirLinkList *tail, ElemType data, int *position)
///*////////////////////////////////////////////////////////////////////////////
/**
CirLinkListNode* FindPosNode(CirLinkList *tail, int position)

����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	�����ҵ�����ָ���λ��
����ֵ
	���ɹ�����ָ������ҽ���ָ��
	��ʧ�ܷ���NULL
����
	�ú����Ĺ�����:	���ҵ�����tail�е�position�����
*/
CirLinkListNode* FindPosNode(CirLinkList *tail, int position)
{
	assert(tail != NULL);									// ������Ϊ��
	assert(position >= -1 && position < tail->m_next->m_data);	// �����wλ��ֻ����[-1~length]

	CirLinkListNode 	*pNode	= tail->m_next->m_next;		// β������һ��λ����ͷ���, ͷ������һ����

	if(position == -1)											// -1��ʾѰ��ͷָ���ǰ��
	{
		return tail->m_next;									// ֱ�ӷ���ǰ��[��ͷ���]
	}

    int pos 	= 0;

    while(pNode != tail && pos < position)		// �����������ҵ���position������λ��
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
CirLinkListNode *FindPrevNode(CirLinkList *tail, CirLinkListNode *currNode);

����
	tail		:	ָ��һ������ָ�룬�˴������ͷ��ַ
	currNode	:	�����ҵ�����ָ���λ��
����ֵ
	���ɹ�����ָ������ҽ���ָ��
	��ʧ�ܷ���NULL
����
	������tail���ҵ�currNode��ǰһ�����
*/

CirLinkListNode *FindPrevNode(CirLinkList *tail, CirLinkListNode *currNode)
{
	assert(tail != 	NULL);
	assert(currNode != NULL);

	CirLinkListNode *pNode = tail->m_next->m_next;
//	CirLinkListNode *pNode = tail->m_tail->m_next;			// ��ѭ������ֻ��βָ��ʱ���ô˴���

	while(pNode != tail 							// ���δ���ҵ�����β��
	   && pNode->m_next != currNode)				// ���ҵ���һ��ָ��������currNode��˵�����ҳɹ�
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
int IsNodeInList(CirLinkList *tail, CirLinkListNode *node)

����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	node	:	ָ������ҵĽ���ָ��
����ֵ
	���ɹ� ���ؽ��node�������е�λ��
	��ʧ�� ����-1
����
	�жϽ��nodeָ��������ǲ��������еĽ��
*/
int IsNodeInList(CirLinkList *tail, CirLinkListNode *node)
{
	assert(tail != NULL);									// ������Ϊ��	assert(Node != NULL);									// �����ҵ�ָ�벻��Ϊ��

	CirLinkListNode 	*pNode	= tail->m_next->m_next;
//	CirLinkListNode *pNode = tail->m_tail->m_next;			// ��ѭ������ֻ��βָ��ʱ���ô˴���
    int 			pos 	= 0;

    while(pNode != tail->m_next && pNode != node)		// �����������ҵ���position������λ��
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
		printf("Find the [%p] point in the first %d pointer of the tail...\n", node, pos);
#endif // DEBUG
		return pos;
	}
}


/**
CirLinkListNode* FindDataNode(CirLinkList *tail, ElemType data, int *position

����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	data	:	�����ҵĽ���������Ϣ
����ֵ
	���ɹ� ���ؽ��node�������е�λ��
	��ʧ�� ����-1
����
	�ҵ�������Ϊdata�Ľ���״γ��ֵ�λ�ò����ؽ����Ϣ
*/
CirLinkListNode* FindDataNode(CirLinkList *tail, ElemType data, int *position)
{
	CirLinkListNode *node = tail->m_next->m_next;
//	CirLinkListNode *pNode = tail->m_tail->m_next;			// ��ѭ������ֻ��βָ��ʱ���ô˴���

	int pos = 0;
	while(node != tail->m_next && node->m_data != data)
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
///	CirLinkListNode *AddNode(CirLinkList *tail, CirLinkListNode *prevNode, ElemType data)
///
///	������data��������ĵ�position��λ��
///	CirLinkListNode *InsertNode(CirLinkList *tail, int position, ElemType data)
///*////////////////////////////////////////////////////////////////////////////


/**
CirLinkListNode* AddNode(CirLinkList *tail, CirLinkListNode *prevNode, ElemType data);
����
	tail		:	ָ��һ������ָ�룬�˴������ͷ��ַ
	prevNode	:	������λ�õ�ǰһ�����
	data		:	�������������
����ֵ
	��
����
	�ú����Ĺ�����:	������data���������prevNode������һ��λ�ø�λ��
*/
CirLinkListNode* AddNode(CirLinkList **tail, CirLinkListNode *prevNode, ElemType data)
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

	if(prevNode == *tail)
	{
		*tail = newNode;
		printf("�޸�βָ��%p\n", *tail);
	}
	(*tail)->m_next->m_data++;			// ͷ����������洢�Ž������

#ifdef DEBUG
	printf("�¿��ٵ��������ַ%p, ������%d, ָ����%p\n", newNode, newNode->m_data, newNode->m_next);
#endif // DEBUG
	return newNode;
}


/**
void InsertNode(CirLinkList *tail, int position, ElemType data)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	���������λ��
	data	:	�������������
����ֵ
	��
����
	�ú����Ĺ�����:	������data��������ĵ�position��λ��
*/
CirLinkListNode* InsertNode(CirLinkList **tail, int position, ElemType data)
{
	assert(*tail != NULL);
	assert(position >=0 && position < (*tail)->m_next->m_data + 1);

	CirLinkListNode *prevNode = FindPosNode(*tail, position - 1);			// �ҵ�������λ�õ�ǰһ�����
	CirLinkListNode *newNode = NULL;

	// �������InsertPointNodeֱ�ӽ������뵽pNode������
	if((newNode = AddNode(tail, prevNode, data)) != NULL)	// ���µĽ����뵽������ǰһ��ָ��ĺ���
	{	// ����ɹ�

		return newNode;								// �����²���Ľ��
#ifdef DEBUG
		printf("Insert the value %d into tail at position %d...\n", data, position);
#endif // DEBUG
	}
	else
	{
		return NULL;								// ����ʧ�ܷ���NULL
	}
}


///*////////////////////////////////////////////////////////////////////////////
///
///	ɾ������
///
///	ɾ������tail��prevNode���֮���ָ���ָ��
///	void DeleteNode(CirLinkList *tail, int position)
///
///	ɾ������tail��prevNode���֮���ָ���ָ��
///	ElemType SubNode(CirLinkList *tail, CirLinkListNode *prevNode)
///
///	ɾ������tail��prevNode���֮���ָ���ָ��
///	ElemType DeleteCurrNode(CirLinkList *tail, CirLinkListNode *currNode)
///*////////////////////////////////////////////////////////////////////////////

/**
void DeleteNode(CirLinkList *tail, int position)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	��������ĵ�position�����ɾ��
*/
ElemType DeleteNode(CirLinkList **tail, int position)
{
	assert(*tail != NULL);
	assert(position >= 0 && position < (*tail)->m_next->m_data);

	CirLinkListNode *prevNode = FindPosNode((*tail), position - 1);			// �ҵ���position - 1�����

	// ɾ��pNode�ĺ�һ�����
	CirLinkListNode *delNode = prevNode->m_next;
	ElemType delElem = delNode->m_data;
	prevNode->m_next = delNode->m_next;
	free(delNode);

	if(position == (*tail)->m_next->m_data)
	{
		printf("�޸�βָ��%p\n", prevNode);
		(*tail) = prevNode;
	}

	(*tail)->m_next->m_data--;			// ͷ����������ͬ���洢�Ž������

	return delNode;
}


/**
ElemType SubNode(CirLinkList *tail, CirLinkListNode *prevNode)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	ɾ������tail��prevNode���֮���ָ���ָ��
*/
ElemType SubNode(CirLinkList *tail, CirLinkListNode *prevNode)
{
	assert(tail != NULL);						// ������Ϊ��
	assert(prevNode != NULL);						// ��ɾ������ǰһ��λ�ò���Ϊ��
	assert(IsNodeInList(tail, prevNode) != -1);	// ��ɾ��λ�õ�ǰһ����������������

	// ɾ��pNode�ĺ�һ�����
	CirLinkListNode *delNode = prevNode->m_next;
	ElemType delElem = delNode->m_data;
	prevNode->m_next = delNode->m_next;

	free(delNode);

	tail->m_next->m_data--;			// ͷ����������ͬ���洢�Ž������

	return delElem;
}



/**
ElemType DeleteCurrNode(CirLinkList *tail, CirLinkListNode *currNode);
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon	:	��ɾ������λ��
����ֵ
	���ش�ɾ������������
����
	ɾ������tail��prevNode���֮���ָ���ָ��
*/
ElemType DeleteCurrNode(CirLinkList **tail, CirLinkListNode *currNode)
{
	assert(*tail != NULL);							// ������Ϊ��
	assert(currNode != NULL);							// ��ɾ������ǰһ��λ�ò���Ϊ��
	assert(IsNodeInList(*tail, currNode) != -1);	// ��ɾ���Ľ�������������

	ElemType 			delElem = -1;							// ��ɾ������������
	CirLinkListNode 	*delNode = NULL;					// ָ��Ҫɾ���Ľ���ָ��


	// ֱ�ӽ����һ�����ɾ�����ɣ� Ӧ�ð���ǰһ������ָ����ֵΪ��
	delNode = currNode;
	// ����Ӧ�ý�currnNode��ǰһ������ָ����ֵΪ��[ʱ�临�Ӷ�O(n)]
	CirLinkListNode *prevNode = FindPrevNode((*tail), currNode);
	prevNode->m_next = (*tail)->m_next;			/// BUG1  ���һ�����ĺ�һ�����


	if(currNode != (*tail))					// �����ɾ����㲻�����һ�����
	{
		(*tail) = prevNode;
	}

	free(delNode);

	(*tail)->m_next->m_data--;			// ͷ����������ͬ���洢�Ž������

	return delElem;
}




///*////////////////////////////////////////////////////////////////////////////
///
///	��������
///
///	��ʾ���������Ϣ
///	void ShowList(CirLinkList *tail
///
///	ɾ������tail��prevNode���֮���ָ���ָ��
///	void SetNode(CirLinkList *tail, int position, ElemType data)
///
///	��ȡ������tail��position������������
/// ElemType GetNode(CirLinkList *tail, int position)
///
///	��ȡ������tail�ĳ���[��Ԫ�ظ���]
///	int LengthCirLinkList(CirLinkList *tail)
///
///	�жϵ�ǰ�����Ƿ��ǿ�����
///	bool IsEmptyCirLinkList(CirLinkList *tail)
///*////////////////////////////////////////////////////////////////////////////

/**
void ShowCirLinkList(CirLinkList *tail)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	��
����
	��ʾ���������Ϣ
*/
void ShowList(CirLinkList *tail)
{
// assert(tail->m_next != NULL)
	if(tail->m_next ==  NULL)			//  ���������û�б���ʼ��
	{
		fprintf(stderr, "you can't SHOW the tail without the tail INITLINKLIST...\n");
		return ;
	}


	printf("there are %d data in tail\n", tail->m_next->m_data);
	if(tail->m_next->m_data == 0)
	{
		return ;
	}

	CirLinkListNode *pNode = tail->m_next->m_next;			// ��ͷָ�뿪ʼ����

	while(pNode != tail->m_next)								//��ʼ����������
	{
		printf("%d  ", pNode->m_data);
        pNode = pNode->m_next;
	}
	printf("\n");

//	ElemType data;
//	for(int pos = 0; pos < tail->m_next->m_data; pos++)
//	{
//		data = GetNode(tail, pos);
//		printf("%d  ", data);
//	}
//	printf("\n");
}

/**
void SetNode(CirLinkList *tail, int position, ElemType data)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon :	���޸ĵĽ�������
	data	:	����������������
����ֵ
	��
����
	�޸ĵ�����tail��position������������Ϊdata
*/
void SetNode(CirLinkList *tail, int position, ElemType data)
{
	CirLinkListNode *pNode = FindPosNode(tail, position);		// �ҵ�������ĵ�position�����

	pNode->m_data = data;
}

/**
ElemType GetNode(CirLinkList *tail, int position
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
	positon :	����ѯ�Ľ���λ��
����ֵ
	��ȡ���Ľ������
����
	��ȡ������tail��position������������
*/
ElemType GetNode(CirLinkList *tail, int position)
{
	CirLinkListNode *pNode = FindPosNode(tail, position);		// �ҵ�������ĵ�position�����

	return pNode->m_data;
}


/**
int LengthCirLinkList(CirLinkList *tail)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	������ĳ���
����
	��ȡ������ĳ���
*/
int LengthCirLinkList(CirLinkList *tail)
{
	return tail->m_next->m_data;
}


/**
bool IsEmptyCirLinkList(CirLinkList *tail)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	����������ǿձ�����true
	���򷵻�false
����
	��ȡ������ĳ���
*/
bool IsEmptyCirLinkList(CirLinkList *tail)
{
    return (tail->m_next->m_next == tail->m_next);
//	return (tail->m_tail == this->m_head);
}


/**
CirLinkListNode* GetFisrtNode(CirLinkList *tail)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	����ͷָ��
����
	��ȡѭ�������ͷָ��
*/
CirLinkListNode* GetFisrtNode(CirLinkList *tail)
{
	return tail->m_next->m_next;
//	return tail->m_tail->m_next->m_next;			// ֻ��βָ���ʱ��ʹ�ô˴���
}


/**
CirLinkListNode* GetHeadNode(CirLinkList *tail)
����
	tail	:	ָ��һ������ָ�룬�˴������ͷ��ַ
����ֵ
	����ͷ���ĵ�ַ
����
	��ȡָ��ͷ����ָ��
*/
CirLinkListNode* GetHeadNode(CirLinkList *tail)
{
	return tail->m_next;
//	return tail->m_tail->m_next;			// ֻ��βָ���ʱ��ʹ�ô˴���
}
