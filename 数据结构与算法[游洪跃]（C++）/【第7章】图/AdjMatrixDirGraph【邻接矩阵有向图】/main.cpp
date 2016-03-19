/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : main.cpp                                                     *
*  Description: �ڽӾ�������ͼ��AdjMatrixDirGraph������Դ�ļ�                               *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/


#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <algorithm>

#include "AdjMatrixDirGraph.h"

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



// �ڲ�����(main.cpp)
// ����һ���ڽӾ�������ͼ
void CreateGraph(AdjMatrixDirGraph<char> &graph);
// �޸�ͼ����Ϣ
void InsertGraph(AdjMatrixDirGraph<char> &graph);
void DeleteGraph(AdjMatrixDirGraph<char> &graph);
// ����ͼ����Ϣ
void Travel(AdjMatrixDirGraph<char> &graph);


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
    cout <<"\t\t**             Test HufffmanTree Of               **" <<endl;
    cout <<"\t\t****************************************************" <<endl;
#endif

    Welcome( );         // ��ӭ����

    // �����ʼ������
    int choice;
    AdjMatrixDirGraph<char> graph;
    Lording( );         // ���뺯��

    while( 1 )
    {

        Menu( );        // ϵͳ�˵�

        cin >>choice;         //��������ѡ��
        system("cls");
        switch(choice)
        {
            /// 1 -=> �½�һ�������Ա�
        case 1:
            // ϵͳ��Ϣ��ʾ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t** ����ǰ��ѡ��1 -=> �½��ڽӾ�������ͼ **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;


            // ������Բ���
            cout <<"���򽫴��ļ��ж���ͼ����Ϣ, Ϊ�㽨��һ������ͼ" <<endl;
            cout <<"�����ļ�MatrixGraph.txt" <<endl;
            CreateGraph(graph);

            // ϵͳ��Ϣ��ʾ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            //getchar( );
            system("pause");
            break;

            /// 2 -=> �������ͼ���ڽӾ�����Ϣ
        case 2:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**����ǰ��ѡ��2-=>�������ͼ���ڽӾ�����Ϣ**" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            // ������Բ���
            graph.ShowMarix( );

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
            cout <<"\t\t**   ����ǰ��ѡ��3 -=> ��������ͼ�ı�   **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���
            InsertGraph(graph);

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
            cout <<"\t\t**   ����ǰ��ѡ��4 -=> ɾ������ͼ�ı�   **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;


            // ������Բ���
            DeleteGraph(graph);


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
            cout <<"\t\t**   ����ǰ��ѡ��5 -=>����ͼ�ı�������    **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            // ������Բ���
           // graph.DFSTraverse(Write);
            Travel(graph);

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




// ����һ���ڽӾ�������ͼ
void CreateGraph(AdjMatrixDirGraph<char> &graph)
{
    int vertexNum, temp;
    char *vertexs;
    fstream cin("MatrixGraph.txt");
    cin >>vertexNum/*������Ŀ*/;
    cout <<"��ǰͼ�Ķ�����Ŀ" <<vertexNum <<endl;
    //char vertexs[vertexNum];
    vertexs = new char[vertexNum];  // ���ٽ����Ϣ
//   int matrix[vertexNum][vertexNum];


    cout <<"ͼ�ı���Ϣ" <<endl;
    for(int i = 0; i < vertexNum; i++)
    {
        cin >>vertexs[i];       // ���붥����Ϣ
        // cout <<setw(5)<<vertexs[i];
    }
    cout <<endl;
    // ͼ�Ķ���Ϊertexs, ����ϢΪedgeNum

    graph.SetGraph(vertexs, vertexNum);      // �޸�ͼ����Ϣ);

    for(int i = 0; i < vertexNum; i++)
    {
        for(int j = 0; j < vertexNum; j++)
        {
            cin >>temp;
            cout <<setw(4)<<temp;
            if(temp == 1)
            {
                graph.InsertEdge(i, j);
            }
        }
        cout <<endl;
    }

//    for(int i = 0; i < vertexNum; i++)
//    {
//        for(int j = 0; j < vertexNum; j++)
//        {
//            cin >>matrix[i][j];
//            cout <<setw(4)<<matrix[i][j];
//        }
//        cout <<endl;
//    }
//
//    for(int i = 0; i < vertexNum; i++)
//    {
//        for(int j = 0; j <= i; j++)
//        {
//            if(matrix[i][j] == 1)
//            {
//                graph.InsertEdge(i, j);
//            }
//        }
//    }
}


// �޸�ͼ����Ϣ
void InsertGraph(AdjMatrixDirGraph<char> &graph)
{
    char vertex1, vertex2;
    int v1, v2;
    cout <<"��������Ҫ��ӵı������������Ϣ" <<endl;
    cout <<"�κ�һ������, ��������" <<endl;

    while( 1 )
    {
        while( 1 )
        {
            cout <<"VERTEX:";
            cin >>vertex1 >>vertex2;
            if(vertex1 == '#' || vertex2 == '#')
            {
                break;
            }
            //cout <<vertex1 <<vertex2 <<endl;
            //system("pause");
            v1 = graph.GetVertex(vertex1);
            v2 = graph.GetVertex(vertex2);
            //system("pause");
            // cout <<v1 <<v2 <<endl;
            if(v1 != -1 && v2 != -1)
            {
                break;
            }

            cout <<"����Ķ�����Ϣ����, ����������" <<endl;
        }

        if(vertex1 == '#' || vertex2 == '#')
        {
            cout <<"�û���ֹ����" <<endl;
            break;
        }

        if(graph.InsertEdge(v1, v2) == true)
        {
            cout <<"��Ӷ���" <<vertex1 <<"�붥��" <<vertex2 <<"�ı���Ϣ" <<endl <<endl <<endl;
        }
        else
        {
            cout <<"����ͼ�иñ��Ѿ�����, ���������" <<endl;
        }
    }
}



void DeleteGraph(AdjMatrixDirGraph<char> &graph)
{
    char vertex1, vertex2;
    int v1, v2;
    cout <<"��������Ҫɾ���ı������������Ϣ" <<endl;
    cout <<"�κ�һ������, ��������" <<endl;

    while( 1 )
    {
        while( 1 )
        {
            cout <<"VERTEX:";
            cin >>vertex1 >>vertex2;
            if(vertex1 == '#' || vertex2 == '#')
            {
                break;
            }
            //cout <<vertex1 <<vertex2 <<endl;
            //system("pause");
            v1 = graph.GetVertex(vertex1);
            v2 = graph.GetVertex(vertex2);
            //system("pause");
            // cout <<v1 <<v2 <<endl;
            if(v1 != -1 && v2 != -1)
            {
                break;
            }

            cout <<"����Ķ�����Ϣ����, ����������" <<endl;
        }

        if(vertex1 == '#' || vertex2 == '#')
        {
            cout <<"�û���ֹ����" <<endl;
            break;
        }


        if(graph.DeleteEdge(v1, v2) == true)
        {
            cout <<"ɾ������" <<vertex1 <<"�붥��" <<vertex2 <<"�ı���Ϣ" <<endl <<endl <<endl;
        }
        else
        {
            cout <<"����ͼ�иñ߱��Ͳ�����, ������ɾ��" <<endl;
        }
    }
}


// ����ͼ����Ϣ
void Travel(AdjMatrixDirGraph<char> &graph)
{
    cout <<"************************" <<endl;
    cout <<"** 1 -=> ��������㷨 **" <<endl;
    cout <<"** 2 -=> ��������㷨 **" <<endl;
    cout <<"************************" <<endl;

    int choice;
    cin >>choice;

    switch(choice)
    {
        case 1:
          cout <<"DFS���Ϊ��";
          graph.DFSTraverse(Write);        // ���з���
          cout <<endl <<endl;
          break;

        case 2:
          cout <<"��ǰ�����������BFS" <<endl <<endl;
          cout <<"BFS���Ϊ��";
          graph.BFSTraverse(Write);        // ���з���
          cout <<endl <<endl;
          break;
    }
}

