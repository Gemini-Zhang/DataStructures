/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : SqList.h
Description: ���Ա�˳��洢�ṹ[�ⲿ����ʵ��]
Author     : Gatie_Me
Version    : Copyright 2012
Data_Time  : 20112-8-29 10:28:43
Content    : ���ݽṹ���㷨��C++��������Դ��
********************************************************************************/

#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <ctime>

using namespace std;


// �������ƣ�template <class ElemType> void Write(const ElemType &e)
// �������: ��������Ԫ��
template <class ElemType>
void Read(ElemType &elem)
{
    cin >>elem;    //����Ԫ�ص���Ϣ
}

// �������ƣ�template <class ElemType> void Write(const ElemType &e)
// �������: ��ʾ����Ԫ��
template <class ElemType>
void Write(ElemType &elem)
{
    cout <<elem <<"  ";     //���Ԫ�ص���Ϣ
}

void Welcome( )    //ѡ��1�����˶Կ�ʱ��ĳ�����Ϣ
{
    const char *inFor[11];
    inFor[0] = "               ****************************************************              ";
    inFor[1] = "               *                                                  *              ";
    inFor[2] = "               *========Welcome To The Quick Hit World!!!=========*              ";
    inFor[3] = "               *                                                  *              ";
    inFor[4] = "               *The Result is Not Only You Win But Only Also I Win*              ";
    inFor[5] = "               *                                                  *              ";
    inFor[6] = "               *=======We All Hope That Which Is Said To Us=======*              ";
    inFor[7] = "               *                                                  *              ";
    inFor[8] = "               *===========Success Is Only The Begining===========*              ";
    inFor[9] = "               *                                                  *              ";
    inFor[10] = "              ****************************************************              ";

	int i,j;

	long start;

    cout <<endl <<endl;
    for ( i = 0; i < 11; i++ )        //ѭ��11��
	{
		for ( j = 0; j < 68; j++ )           //ѭ��ÿ��68���ַ�
		{
			if( inFor[i][j] == ' ' )           //�����ǰ�ַ�Ϊ�ո�
				cout <<( inFor[i][j] );
			else if( inFor[i][j]=='*' )              //�����ǰ�ַ�Ϊ*
			{
				start = clock();
				while ( clock()-start < 20 );
                cout <<( *(inFor[i]+j) );
			}
			else                   //����ǰ�ַ�ΪӢ���ַ�
			{
				start = clock();
				while(clock()-start<300);
				cout <<( *(inFor[i]+j) ) <<"\a";
			}
		}
		cout <<endl;
	}

	cout <<"Press any key to continue..." <<endl;
	//while (!kbhit());
	getch();
    system("cls");
}


void Menu( )
{
    system("cls");
    const char *menu[9] = {
        "\t\t********************************************",
        "\t\t**        1 -=> �½�һ�������Ա�          **",
        "\t\t**        2 -=> ��ʾ���������Ա�          **",
        "\t\t**        3 -=> �����������Ա�          **",
        "\t\t**     4 -=> �����Ա�ֳ���ż������       **",
        "\t\t**           5 -=> ɾ��Ԫ��               **",
        "\t\t**          6 -=> ������Ա�              **",
        "\t\t**          0 -=> �˳�����                **",
        "\t\t********************************************",
        };

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; menu[i][j] != '\0'; j++)
        {
            cout <<menu[i][j];
        }
        cout <<endl;
    }
    cout <<"����������ѡ��" <<endl;
}


// ��ʱ����
void Delay( )
{
    for(int i = 0; i < 1000000; i++);
}

// ���뺯��
void Lording( )
{
    system("cls");

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10000000; j++);
        cout <<"��";
    }
    cout <<endl;

    system("cls");
}

void Stop( )        // ֹͣ����
{
    char answer;

    do
    {	// ѭ��ֱ���û�����ǡ���Ļش�Ϊֹ
        cout << "(y, n)?";
        cout << "��y��n�ش�:";
        while ((answer = getchar( )) == '\n');	// �����ո�,�Ʊ�������з���ȡһ�ַ�

    }while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');

    #if (VERSION)     // ���������Ϣ���
    Version( );         // ��ʾ����ı�����Ϣ
    #endif

    if(answer == 'y' || answer == 'Y')
    {
        cout <<"�û�ѡ���˳�";
        exit(0);
    }
    else
    {
        cout <<"�û�ȡ��" <<endl;
    }
}


void Version( )
{

    cout <<"\t\t**************************************************" <<endl;
    cout <<"\t\t**  Wacky Window (c) 2012 Wacky SoftWare. Inc.  **"<<endl;
    cout <<"\t\t**     Complied on " <<__DATE__ <<" at " <<__TIME__ <<"      **"<<endl;
    cout <<"\t\t**************************************************" <<endl;
    system("pause");

}
