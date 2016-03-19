#include "CirLinklist.h"




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
