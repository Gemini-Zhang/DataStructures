#include <stdio.h>
#include <stdlib.h>


// �������޸�һ��������ֵ
typedef struct
{
	int *value;
	int length
}List;

int gloValue1 = 0;
int gloValue2 = 10;						// ȫ�ֱ���

void Modify1(List list);		// ������Ϊ����
void Modify2(List *list);		// ������ָ����Ϊ����


int main(void)
{

	List list = {&gloValue1, 0};
	printf("&gloValue1 = %p, &gloValue = %p\n", &gloValue1, &gloValue2);
	printf("value = %d, addr = %p, length = %d after func\n\n", *(list.value), list.value, list.length);

	Modify1(list);
	printf("value = %d, addr = %p, length = %d after Modify1\n\n", *(list.value), list.value, list.length);

	Modify2(&list);
	printf("value = %d, addr = %p, length = %d after Modify2\n\n", *(list.value), list.value, list.length);
	return EXIT_SUCCESS;
}


// ������Ϊ����
void Modify1(List list)
{
	list.value = &gloValue2;								// �޸�ָ���ֵ(��ָ���ָ��)  failed
	list.length = 10;										// failed
	printf("value = %d, addr = %p, length = %d in %s\n", *(list.value), list.value, list.length, __func__);
}


// ������Ϊ����
void Modify2(List *list)
{
	list->value = &gloValue2;								// �޸�ָ���ֵ(��ָ���ָ��) success
	list->length = 10;										//						  success
	printf("value = %d, addr = %p, length = %d in %s\n", *(list->value), list->value, list->length, __func__);
}

// ����ͷ���ĵ����������Ԫʱ����Ҫ�޸�ͷָ���ָ��
(*list) = newNode;					// ��ʱ�޸�ָ�뱾���ָ����Ҫ����LinkListNode **
// ����ͷ���ĵ�����������
typedef struct LinkListNode*  LinkList;
//��������	
LinkListNode* InsertNode(LinkList *list,	// LinkList * == LinkListNode**	 
						 int position, 
						 ElemType data)

// ��newNode����pNode֮��ʱ����Ҫ�޸�newNode��pNodeָ�����ָ��
newNode->m_next = pNode->m_next;	// ��ʱֻ��Ҫ����LinkListNode *����, ��Ϊָ����m_next��node�����ݳ�Ա, �Ѿ��Ǹ�ָ���Ա����
pNode->m_next = newNode;			// ����LinkListNode *, m_next�ͳ�Ϊһ��ָ���ָ��
// ��������
LinkListNode *AddNode(LinkList *list,							
					  LinkListNode *prevNode,				// ����LinkListNode *, �����޸�prevNode->m_next = @@@@@
					  ElemType data)

// ����ͷ���ĵ�������
typedef struct LinkListNode*  LinkList;
// ��ͷ���ĵ�����
typedef struct LinkListNode LinkList;