/**
*********************************************************************************
*   CopyRight  : 2012-2013, HerBinUnversity, GatieMe                            *
*   File Name  : main.cpp                                                       *
*   Description: RefGenList[���÷������]�������ļ�                            *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2012                                                 *
*   Data_Time  : 20112-10-30 18:43:34                                           *
*   Content    : ���ݽṹ���㷨��C++��������Դ��                               *
*********************************************************************************
**/


#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <fstream>


#include "RefGenList.h"


using namespace std;

#define SIZE 81



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
    #ifndef DEBUG        // ����궨����DEBUG, ִ��һ�����
    cout <<"\t\t**************************************************** " <<endl;
    cout <<"\t\t**           Test TriSparseMatrix Of              **" <<endl;
    cout <<"\t\t****************************************************" <<endl;
    #endif

    Welcome( );         // ��ӭ����

    // �����ʼ������
    int choice;
    Lording( );         // ���뺯��

    while( 1 )
    {

        Menu( );        // ϵͳ�˵�

        cin >>choice;         //��������ѡ��
        system("cls");
        switch(choice)
        {
          /// 1 -=> ����ϡ�����
          case 1:
            // ϵͳ��Ϣ��ʾ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**   ����ǰ��ѡ�� 1 -=> ����ϡ�����    **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���

            // ϵͳ��Ϣ��ʾ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            //getchar( );
            system("pause");
            break;

          /// 2 -=> ���ļ���ȡϡ�����
          case 2:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**  ����ǰ��ѡ��2 -=> ���ļ���ȡϡ�����  **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            // ������Բ���

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**              ����������              **" <<endl;
            cout <<"\t\t**             �����������˵�             **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 3 -=> ���ϡ�����
          case 3:
            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**   ����ǰ��ѡ�� 3 -=> ���ϡ�����    **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;


            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ����������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 4 -=> ���ľ�������
          case 4:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**    ����ǰ��ѡ��4 -=> ���ľ�������    **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���


            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݸ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;



          /// 5 -=> ��ϡ���������ݴ����ļ�
          case 5:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**����ǰ��ѡ�� 5 -=> ��ϡ���������ļ� **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;


            // ������Բ���

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݴ洢���            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 6 -=> ��ϡ�����ת��
          case 6:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**   ����ǰ��ѡ�� 6 -=> ��ϡ�����ת��  **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ����ת�����            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 7 -=> ���������
          case 7:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**     ����ǰ��ѡ�� 7 -=> ���������    **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              �����������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;
          /// 0 -=> �˳�����
          case 0:
            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;          // ϵͳ��ʾ��Ϣ

            Stop( );

            Lording( );         // ���뺯��
        }
    }

    return 0;
}


