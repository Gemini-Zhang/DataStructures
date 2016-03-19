/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : main.h
Description: ��ʽ����������Դ�����ļ�
Author     : Gatie_Me
Version    : Copyright 2012
Data_Time  : 20112-8-29 10:28:43
Content    : ���ݽṹ���㷨��C++��������Դ��
********************************************************************************/
#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include "LinkQueue.h"


using namespace std;

/// �ⲿ�����������ļ�Other.cpp��
void Welcome( );        // ��ӭ����
void Menu( );       // �˵���ʾ����
void Delay( );      // ��ʱ����
void Lording( );    // ���뺯��
void Stop( );       // ��ֹ����


/// ������
int main( )
{
    // ����״̬�µ������Ϣ
    #ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
    cout <<"\t\tHello World*****************************************" <<endl;
    cout <<"\t\t**              Now Start Debug                   **" <<endl;
    cout <<"\t\t*****************************************Hello World" <<endl;
    #endif

    // �ǵ���״̬�µ������Ϣ
    #ifndef DEBUG                // ����궨����DEBUG, ִ��һ�����
    cout <<"\t\t**************************************************** " <<endl;
    cout <<"\t\t**               Test SqQueue Of                  **" <<endl;
    cout <<"\t\t****************************************************" <<endl;
    #endif

    Welcome( );         // ��ӭ����



    // �����ʼ������
    char answer;
    int choice, length, temp;

    LinkQueue<int> queue;     // ����һ��˳���

    Lording( );         // ���뺯��
    while( 1 )
    {

        Menu( );        // ϵͳ�˵�

        cin >>choice;         // ��������ѡ��

        system("cls");        // ȷ���Լ���ѡ�������

        // ��֧�������ж�
        switch(choice)
        {
            /// 1 -=> �½�һ�������Ա�
          case 1:
            // ϵͳ��Ϣ��ʾ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t** ����ǰ��ѡ��1 -=> �½�һ����˳��ѭ������ **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���
            cout <<"��������ϣ��������˳��ӵĶӿ�" <<endl;
            cout <<"�����ϵͳ�Ὠ��һ��˳����������" <<endl;
            cin >>length;       // ����˳��ӵ�����

            srand(time(NULL));              // �������������
            for(int i = 0; i < length; i++) // ��ϵͳ���õ�����ѹ�����
            {
                temp = rand() % 100 + 1;                    // ����һ��1-100�������
                queue.InQueue(temp);                           // ������ѹ�����
                cout <<"������" <<temp <<"ѹ�����" <<endl; // ��ʾ��Ϣ
            }
            cout <<"��ǰ��ʽѭ�����еĳ���" <<queue.Length( ) <<endl;
            // ϵͳ��Ϣ��ʾ
            cout <<endl <<endl;
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ����������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 2 -=> ��ʾ������˳��ѭ������
          case 2:
            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t** ����ǰ��ѡ��2 -=> ���ε���˳��ӵ����� **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            while(!queue.Empty())
            {
                cout <<"����������: " <<queue.OutQueue() <<endl;
            }
            cout <<"��ǰ��ʽѭ�����еĳ���" <<queue.Length( ) <<endl;

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ����������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 3 -=> Ԫ�����
          case 3:

            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**      ����ǰ��ѡ��5 -=> Ԫ�����      **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;


            // ������Բ���
            cout <<"�������Ƕ����ݽṹ, �޷��������λ��" <<endl <<endl;
            while( 1 )
            {
                cout <<endl <<endl <<"��������Ҫ��ӵ�����[����0�������]" <<endl;
                cin >>temp;
                if(temp == 0)
                {
                    break;
                }
                queue.InQueue(temp);
                cout <<"������" <<temp <<"����Ӷ�" <<endl;
            }
            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ����������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 4 -=> Ԫ�س���
          case 4:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**      ����ǰ��ѡ��5 -=> Ԫ�س���     **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���

            do
            {	// ѭ��ֱ���û�����ǡ���Ļش�Ϊֹ
                cout <<endl <<endl <<"�������Ƿ�ȷ����Ҫ�����Ӷ�����" <<endl;
                cout << "(y, n)?" << "��y��n�ش�:";
                while ((answer = getchar( )) == '\n');	// �����ո�,�Ʊ�������з���ȡһ�ַ�
                if(answer == 'y' || answer == 'Y')         // ֻҪ�Ӳ��ǿյ�
                {
                    if(queue.OutQueue(temp) == true)     // �����Ӷ�Ԫ��
                    {
                        cout <<"�����Ӷ�����" <<temp <<endl;
                    }
                }
                else if(answer != 'n' && answer != 'N')
                {
                    cout <<"��Ϣ��������, ����������" <<endl;
                }

                if(queue.Empty() == true)   // �����ǰ˳���Ϊ��, ��ϵͳ���Զ��������˵�
                {
                    cout <<"������Ԫ��ȫ������, �޷���������" <<endl;
                    break;
                }
            }while (answer != 'n' && answer != 'N');

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݳ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 5 -=> ���˳��ѭ������
          case 5:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**     ����ǰ��ѡ��6 -=> ���˳���     **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���
            queue.Clear( );         // ��˳������
            cout <<"������, ��ǰ˳��ӳ���" <<queue.Length() <<endl <<endl;
            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ����������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 0 -=> �˳�����
          case 0:
            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ѡ�����            **" <<endl;
            cout <<"\t\t**           ϵͳ���������ش���         **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;          // ϵͳ��ʾ��Ϣ

            Stop( );

            Lording( );         // ���뺯��
        }
    }

    return 0;
}

