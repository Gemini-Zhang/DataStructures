/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : SqList.h
Description: ˳��ջ������Դ�����ļ�
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


#include "TriSparseMatrix.h"
using namespace std;

#define SIZE 81



/// �ⲿ�����������ļ�Other.cpp��
void Welcome( );        // ��ӭ����
void Menu( );       // �˵���ʾ����
void Delay( );      // ��ʱ����
void Lording( );    // ���뺯��
void Stop( );       // ��ֹ����


void ShowMatrix(TriSparseMatrix<int> &matrix);      // ���ϡ��������Ϣ
void ReadMatrix(TriSparseMatrix<int> &matrix);  // ���ļ��ж�ȡϡ��������Ϣ
void WriteMatrix(TriSparseMatrix<int> &matrix); // ���ļ���д��ϡ��������Ϣ
void SetMatrixData(TriSparseMatrix<int> &matrix);  // ����4��������
void OperatorMatrix( );         // �������
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
    int choice, rows/*��*/, cols/*��*/, size, temp;

    TriSparseMatrix<int> matrix;         // ������
    TriSparseMatrix<int> newMatrix;
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
            cout <<"������ϡ��������row����col����:" <<endl;
            cout <<"ROWS = ";
            cin >>rows;
            cout <<"COLS = ";
            cin >>cols;
            matrix.SetMatrix(rows, cols);       // ����ԭ��������к�Ԫ�ظ�����Ϣ
            cout <<endl <<"�Ѿ������Ծ�����Ϣ" <<endl;
            cout <<"��ǰ����Matrix�У�" <<matrix.Rows() <<", �У�" <<matrix.Cols( ) <<", ��ǰ��0Ԫ�ظ�����" <<matrix.Size( ) <<endl <<endl;

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
            ReadMatrix(matrix);

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


            ShowMatrix(matrix);

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

            SetMatrixData(matrix);

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

            WriteMatrix(matrix);
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
            rows = matrix.Rows( );
            cols = matrix.Cols( );
            size = matrix.Size( );
            cout <<"��ǰ����Matrix�У�" <<rows <<", �У�" <<cols <<", ��0Ԫ�ظ�����" <<size <<endl <<endl;

            cout <<"ת��ǰ�ľ�����Ϣ" <<endl <<endl;
            ShowMatrix(matrix);
            newMatrix.SetMatrix(rows, cols);
            //TriSparseMatrix<int>::FastTranspose(newMatrix, matrix);
            TriSparseMatrix<int>::SimpleTranspose(newMatrix, matrix);
            cout <<"ת��ǰ�ľ�����Ϣ" <<endl <<endl;
            ShowMatrix(newMatrix);
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
            OperatorMatrix( );
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

void ShowMatrix(TriSparseMatrix<int> &matrix)
{
    int rows, cols, size, temp;
    rows = matrix.Rows( );      // ��ȡ����Ϣ
    cols = matrix.Cols( );      // ��ȡ����Ϣ
    size = matrix.Size( );

    cout <<"��ǰ����Matrix�У�" <<rows <<", �У�" <<cols <<", ��0Ԫ�ظ�����" <<size <<endl <<endl;

    for(int row = 1; row <= rows; row++)
    {
        for(int col = 1; col <= cols; col++)
        {
            matrix.GetElem(row, col, temp);    // ��������
            printf("%4d", temp);
        }
        cout <<endl;
    }
    cout <<endl <<endl;
}

void ReadMatrix(TriSparseMatrix<int> &matrix)
{
    int choice, rows, cols, temp, size;
    char fName[SIZE];
    FILE *fpi/*�����ļ�*/;

    cout <<"****************************" <<endl;
    cout <<"** 1 -=> �ļ��д洢��Ԫ�� **" <<endl;
    cout <<"**2 -=> �ļ��д洢ϡ�����**" <<endl;
    cout <<"****************************" <<endl;
    cout <<"Please entere your choic...." <<endl;
    cin >>choice;
    switch(choice)
    {
      // ����ļ��д洢������Ԫ������
      case 1:
        strcpy(fName, "InTriple.txt");    // �����ļ���
        if((fpi = fopen(fName, "r")) == NULL)   // ���ļ����жϴ��Ƿ�ɹ�
        {
            printf("can't open the input file %s", fName);
            exit(-1);
        }
        fscanf(fpi, "%d%d%d", &rows, &cols, &size);
        matrix.SetMatrix(rows, cols);       // ����ԭ��������к�Ԫ�ظ�����Ϣ
        cout <<endl <<"�Ѿ������Ծ�����Ϣ" <<endl;
        cout <<"��ǰ����Matrix�У�" <<matrix.Rows() <<", �У�" <<matrix.Cols( ) <<endl <<endl;
        while( 1 )
        {
            if(fscanf(fpi, "%d%d%d", &rows, &cols, &temp) == EOF) // ��������
            {
                break;
            }
            if(matrix.SetElem(rows, cols, temp) == true)       // ��������
            {
                cout <<"����״̬, ���ݸ��³ɹ�..." <<endl;
            }
            else
            {
                cout <<"����״̬, ���ݸ���ʧ��..." <<endl;
            }
//            if(feof(fpi) == true)
//            {
//                break;
//            }
        }
        cout <<"��ǰ����Matrix�У�" <<matrix.Rows() <<", �У�" <<matrix.Cols( ) <<", ��0Ԫ�ظ�����" <<matrix.Size( ) <<endl <<endl;
        fclose(fpi);
        break;

      // ����ļ��д洢���Ǿ������Ϣ
      case 2:
        strcpy(fName, "InMatrix.txt");    // �����ļ���
        if((fpi = fopen(fName, "r")) == NULL)   // ���ļ����жϴ��Ƿ�ɹ�
        {
            printf("can't open the input file %s", fName);
            exit(-1);
        }
        fscanf(fpi, "%d%d%d", &rows, &cols, &size);
        matrix.SetMatrix(rows, cols);       // ����ԭ��������к�Ԫ�ظ�����Ϣ
        cout <<endl <<"�Ѿ������Ծ�����Ϣ" <<endl;
        cout <<"��ǰ����Matrix�У�" <<matrix.Rows() <<", �У�" <<matrix.Cols( ) <<", ��0Ԫ�ظ�����" <<matrix.Size( ) <<endl <<endl;

        for(int row = 1; row <= rows; row++)
        {
            for(int col = 1; col <= cols; col++)
            {
                if(fscanf(fpi, "%d", &temp) == EOF)
                {
                    break;
                }
                if(temp != 0)
                {
                    matrix.SetElem(row, col, temp);      // ��������
                    cout <<"���õ�����" <<temp <<endl <<endl;
                }
            }
        }
        fclose(fpi);
        //break;
      default:
        cout <<"ѡ�����" <<endl;
    }
}


void WriteMatrix(TriSparseMatrix<int> &matrix)
{
    char fName[SIZE];
    int rows, cols, size, temp;
    FILE *fpo/*����ļ�*/;

    strcpy(fName, "OutMatrix.txt");
    rows = matrix.Rows( );
    cols = matrix.Cols( );
    size = matrix.Size( );

    if((fpo = fopen(fName, "w")) == NULL)
    {
        printf("can't open the output file\n");
        exit(-1);
    }

    fprintf(fpo, "�����ROW = %d, COL = %d, SIZE = %d, MAXSIZE = %d:\n", rows, cols, size, rows*cols);
    Triple<int> triple;
    fprintf(fpo, "�������Ԫ��������ϢΪ:\n");
    for(int pos = 1; pos <= size; pos++)
    {
        triple = matrix.GetTriple(pos);     // ��ȡ��pos����Ԫ�����Ϣ
        fprintf(fpo, "[%2d,%2d,%2d]\n", triple.m_row, triple.m_col, triple.m_data);
    }
    for(int row = 1; row <= rows; row++)
    {
        for(int col = 1; col <= cols; col++)
        {
            matrix.GetElem(row, col, temp);      // ��������
            fprintf(fpo, "%4d", temp);
        }
        fprintf(fpo, "\n");
    }

    cout <<"�Ѿ�������������" <<endl <<endl;

    fclose(fpo);
}

// ���ľ��������
void SetMatrixData(TriSparseMatrix<int> &matrix)
{
    int rows, cols, temp;
    cout <<"��������[�л���������0���������ļ�ĩβ��־Ctrl+Z����]";
    while( 1 )
    {
        // �û���������
        cout <<"���������ݵ�λ�ú�����" <<endl;        // ������Ϣ
        cout <<"ROW = ";
        if(scanf("%d", &rows) == EOF || rows == 0)
        {
            cout <<endl <<"�û���ֹ����" <<endl;
            break;
        }
        cout <<"COL = ";
        if(scanf("%d", &cols) == EOF || cols == 0)
        {
            cout <<endl <<"�û���ֹ����" <<endl;
            break;
        }
        cout <<"DATA = ";
        if(scanf("%d", &temp) == EOF)
        {
            cout <<endl <<"�û���ֹ����" <<endl;
            break;
        }

        // ϵͳ������Ϣ
        if(matrix.SetElem(rows, cols, temp) == true)       // ��������
        {
            cout <<"����״̬, ���ݸ��³ɹ�..." <<endl;
        }
        else
        {
            cout <<"����״̬, ���ݸ���ʧ��..." <<endl;
        }
    }
}


void OperatorMatrix( )
{
    int choice;
    TriSparseMatrix<int> leftMatrix;
    TriSparseMatrix<int> rightMatrix;
    TriSparseMatrix<int> matrix;

    ReadMatrix(leftMatrix);
    ShowMatrix(leftMatrix);
    ReadMatrix(rightMatrix);
    ShowMatrix(rightMatrix);

    cout <<"****************************" <<endl;
    cout <<"**   1 -=> �����������   **" <<endl;
    cout <<"**   2 -=> �����������   **" <<endl;
    cout <<"****************************" <<endl;
    cout <<"Please entere your choic...." <<endl;

    cin >>choice;
    switch(choice)
    {
        case 1:
           matrix = (leftMatrix + rightMatrix);
           break;
        case 2:
           matrix = (leftMatrix - rightMatrix);
           break;
    }
    ShowMatrix(matrix);
}
