#include <stdio.h>
#include <stdlib.h>


// �������޸�һ��������ֵ
void Modify1(int value);		// ������Ϊ����
void Modify2(int *value);		// ����ָ����Ϊ����

int main(void)
{
	int value = 0;
	Modify1(value);
	printf("value = %d after func\n\n", value);		// modify failed

	Modify2(&value);
	printf("value = %d after func\n\n", value);		// modify success

	return EXIT_SUCCESS;
}


// ������Ϊ����
void Modify1(int value)
{
	value = 10;
	printf("value = %d in %s\n", value, __func__);
}

// ����ָ����Ϊ����
void Modify2(int *value)
{
	*value = 10;
	printf("value = %d in %s\n", *value, __func__);
}