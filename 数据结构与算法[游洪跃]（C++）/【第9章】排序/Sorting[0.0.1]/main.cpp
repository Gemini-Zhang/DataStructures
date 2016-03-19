#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <algorithm>



#define SIZE 10
// ���������й鲢
#include "Sort.h"

bool SmallThan(const void *a, const void *b)
{
    int *pa = (int *)a;
    int *pb = (int *)b;
    return (*pa < *pb);
}

bool BigThan(const void *a, const void *b)
{
    int *pa = (int *)a;
    int *pb = (int *)b;
    return (*pa > *pb);
}


#ifdef DEBUG
#undef DEBUG
//#define DEBUG
#endif

using namespace std;

/// �ⲿ�����������ļ�Other.cpp��
void Read(char &);
void Write(const char &);
void Welcome( );        // ��ӭ����
void Menu( );       // �˵���ʾ����
void Delay( );      // ��ʱ����
void Lording( );    // ���뺯��
void Stop( );       // ��ֹ����


/// �ڲ�����
// ��ʼ��������Ϣ
void InitArray(int *array, int length);
// ���к�������
void ArrySortFunction(int *array, int length, int choice);
/// ������
int main( )
{
    system("title ��������");     // ����ϵͳ�������DOS��������

    // ����״̬�µ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
    cout <<"\t\tHello World*****************************************" <<endl;
    cout <<"\t\t**              Now Start Debug                   **" <<endl;
    cout <<"\t\t*****************************************Hello World" <<endl;
#else
    cout <<"\t\t****************************************************" <<endl;
    cout <<"\t\t**               Test Sorting Of                  **" <<endl;
    cout <<"\t\t****************************************************" <<endl;
#endif

    Welcome( );         // ��ӭ����

    // �����ʼ������
    int choice;
    int *array = new int[SIZE];           // ���ٴ��������ݵ���Ϣ


    InitArray(array, SIZE);
    system("pause");
    Lording( );         // ���뺯��

    while( 1 )
    {
        Menu( );        // ϵͳ�˵�

        cin >>choice;         //��������ѡ��
        system("cls");
        switch(choice)
        {
            /// 1 -=> ֱ�Ӳ�������
        case 1:
            // ϵͳ��Ϣ��ʾ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**    ����ǰ��ѡ��1 -=> ֱ�Ӳ�������    **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;


            // ������Բ���
            ArrySortFunction(array, SIZE, choice);

            // ϵͳ��Ϣ��ʾ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            //getchar( );
            system("pause");
            break;

            /// 2 -=> Shell�����㷨
        case 2:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**     ����ǰ��ѡ��2 -=> Shell�����㷨    **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            // ������Բ���
            ArrySortFunction(array, SIZE, choice);

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**              ���ݲ������              **" <<endl;
            cout <<"\t\t**             �����������˵�             **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

            /// 3 -=> ��������ͼ�ı�
        case 3:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**    ����ǰ��ѡ��3 -=> ð�������㷨    **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���
            ArrySortFunction(array, SIZE, choice);

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

            /// 4 -=> ɾ������ͼ�ı�
        case 4:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**    ����ǰ��ѡ��4 -=> ���������㷨    **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;


            // ������Բ���
            ArrySortFunction(array, SIZE, choice);

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;



            /// 5 -=>����ͼ�ı�������
        case 5:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**    ����ǰ��ѡ��5 -=> ��ѡ������      **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            // ������Բ���
            ArrySortFunction(array, SIZE, choice);

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**              ���ݲ������              **" <<endl;
            cout <<"\t\t**             �����������˵�             **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;


            /// 6 -=> ������__�㷨
        case 6:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**    ����ǰ��ѡ��6 -=> ������__�㷨      **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            // ������Բ���
            ArrySortFunction(array, SIZE, choice);

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**              ���ݲ������              **" <<endl;
            cout <<"\t\t**             �����������˵�             **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

            /// 7 -=> �鲢�����㷨
        case 7:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**    ����ǰ��ѡ��7 -=> �鲢�����㷨      **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            // ������Բ���
            ArrySortFunction(array, SIZE, choice);

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**              ���ݲ������              **" <<endl;
            cout <<"\t\t**             �����������˵�             **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

            /// 7 -=>����ͼ�ı�������
        case 8:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**    ����ǰ��ѡ��8 -=> ���������㷨       **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            // ������Բ���
            ArrySortFunction(array, SIZE, choice);

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**              ���ݲ������              **" <<endl;
            cout <<"\t\t**             �����������˵�             **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl;
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


// ��ʼ��������Ϣ
void InitArray(int *array, int length)
{
    cout <<"���ڳ�ʼ���������Ϣ" <<endl;

    srand(time(NULL));          // �����Ӻ��������������

    for(int i = 0; i < length; i++)
    {
        array[i] = rand( ) % 101;           // ����0-100�������

        cout <<setw(4)<<array[i];
    }
    cout <<endl;
    cout <<"������Ϣ��ʼ�����" <<endl <<endl;
}

// ���к�������
void ArrySortFunction(int *array, int length, int choice)
{
    bool outWay;
    //#define STEP false
    //#define NOMAL true
    cout <<"**************************" <<endl;
    cout <<"**  0-�������������Ϣ  **" <<endl;
    cout <<"**  1-ֱ�����������  **" <<endl;
    cout <<"**************************" <<endl;
    cin >>outWay;

    switch(choice)
    {
        case 1: StraightInsertSort(array, length, BigThan, Write, outWay);
                break;
        case 2: ShellSort(array, length, BigThan, Write, outWay);
                break;
        case 3: BubbleUpSort(array, length, BigThan, Write, outWay);
                break;
        case 4: QuickSort(array, length, BigThan, outWay);
                break;
        case 5: SelectSort(array, length, BigThan, Write, outWay);
                break;
        case 6: HeapSort(array, length, BigThan, Write, outWay);
                break;
        case 7: MergeSort(array, length, BigThan, outWay);
                break;
        case 8: RadixSort(array, length, 9, 3, outWay);

    }
    cout <<"������ ��";
    for(int i = 0; i < length; i++)
    {
        cout <<setw(4)<<array[i];
    }
    cout <<endl;
}
