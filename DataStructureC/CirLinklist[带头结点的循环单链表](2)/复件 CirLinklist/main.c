#include "CirLinklist.h"




#define LIST_SIZE 7
// ������
int main(void)
{
	int pos;

	printf("TEST 1...\n");
	CirLinkList plist = NULL;				// ����������
	InitCirLinkList(&plist);
	for(int pos = 0; pos < LIST_SIZE; pos++)			// ѭ���������в�������
	{
		InsertNode(&plist, pos, pos + 1);
	}
	ShowList(&plist);									// �����������ʾ���������Ϣ

	DeleteNode(&plist, 0);								// ɾ����һ��Ԫ��
	ShowList(&plist);
	DeleteNode(&plist, 1);								// ɾ���ڶ���Ԫ��
	ShowList(&plist);

	ClearCirLinkList(&plist);								// �����������
	ShowList(&plist);
	FinitCirLinkList(&plist);								// ������������
	plist = NULL;


	return 	EXIT_SUCCESS;
}
