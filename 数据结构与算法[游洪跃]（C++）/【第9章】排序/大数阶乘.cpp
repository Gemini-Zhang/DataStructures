#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
#define N 20000

int Input(int *result)								//����m�׳˵ļ���
{

    int i, j, len, n, flag = 0, num;
    char ch[N];
    result[N-1] = 1;

    while( !flag )						//��ʾ����m�����������������
    {
        cout<<"***********************************" <<std::endl;
        cout<<"������Ҫ��׳˵���:";
        cin>>ch;
        cout<<"***********************************" <<std::endl;
        len = strlen(ch);
        for(i = 0 ; i < len; i++)
        {
            if(ch[i] < 47 || ch[i] > 58)
            {
                flag = 0;
                cout<<"\t\t\t\t  �������룬������!!!\n";
                break;
            }
            flag = 1;
        }
    }
    num = atoi(ch);							//��������ַ���ת������Ӧ������
    for(i = 1; i <= num; i++)					//��ʼ���н׳˵ļ���
    {
        for(j = 0; j <= N-1; j++)			//��ʼ��ˣ�result[N-1]��ŵ��Ǹ�λ����result[N-2]��ʮλ����������ȥ
        {
            result[j] = result[j] * i;
        }
        for(j = N-1; j >= 1; j--)
        {
            if(result[j] >= 10)
            {
                result[j-1] = result[j-1] + result[j]/10;	//���result[j]����10����ʼ��result[j-1]λ��һ
                result[j] = result[j] % 10;			//result[j]�Լ�����λ����������ȥ
            }
		}
    }
    j = 0;
    while(result[j] == 0)						//��result[0]��ʼѰ�ҽ׳˸�λ��ʼ��nֵ
    {
        j = j+1;
    }
    n = j;
    cout <<num <<"�Ľ׳�Ϊ��" <<endl;
    return n;
}

// ����ӭ����
void Menu( )
{
    cout<<"***********************************************" <<std::endl;
	cout<<"**                   ����׳�                **" <<std::endl;
	cout<<"***����:�����ڴ����ޣ�������Ҫ������������***" <<std::endl;
    cout<<"*******              1.��ʼ             *******" <<std::endl;
    cout<<"*******              2.�˳�             *******" <<std::endl;
    cout<<"***********************************************" <<std::endl;

    //system("cls");
}


void OutPut(int *result, int n)
{
    int j = n;
    //cout<<m<<"�Ľ׳���:";
    for( ;j <= N-1; j++)					//���׳˴Ӹ�λ������ʾ����
    {
        if((j-n)%50==0)  cout<<endl;//ÿ��20λ����
        cout<<result[j];
    }
    cout<<"\n";
    system("pause");
    system("cls");
}


void End( )
{
    cout <<"\t\t************************************" <<endl;
    cout <<"\t\t****        �û�����            ****" <<endl;
    cout <<"\t\t************************************" <<endl;
}


int  main()
{
	int choice,flag=0, len;
	char str[N];
    int result[N]={NULL};
	while(!flag)
	{
		int f=0;
		while(!f)
		{
		    system("cls");
            Menu( );            // �˵���Ϣ
			cin>>str;
			for(int i=0;str[i]!='\0';i++)
			{								//�������ʱ�����ֵ��ַ�������ʾ��������
				if(str[i]>'9'||str[i]<'0')
				{
					cout<<"\t\t\t\t\t��������!!!\n\n";
					system("pause");
					f = 0;
				    break;
				}
				f = 1;
			}
		}
		choice = atoi(str);
        system("cls");
		switch(choice)
		{
		case 1:
			len = Input(result);						//��ʼ����m�׳˵ļ���
			OutPut(result, len);
			break;
		case 2:
			flag = 1;							//�˳�ѭ��
            End( );
			break;
		default:							//�����1����2�����֣���ʾ��������
			cout<<"\t\t\t\t\t��������!!!\n\n";
			system("pause");
			break;
		}
	}
}
