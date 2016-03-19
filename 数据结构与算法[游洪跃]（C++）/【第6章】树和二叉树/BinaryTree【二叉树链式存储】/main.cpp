/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : main.cpp                                                     *
*  Description: ����������BinTree������Դ�ļ�                               *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/


#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

#include "BinaryTree.h"

#ifdef DEBUG
#undef DEBUG
//#define DEBUG
#endif

using namespace std;

/// �ⲿ�����������ļ�Other.cpp��
void Read(char &);
void Write(char &);
bool IsNull(char &);
void Welcome( );        // ��ӭ����
void Menu( );       // �˵���ʾ����
void Delay( );      // ��ʱ����
void Lording( );    // ���뺯��
void Stop( );       // ��ֹ����



// �ڲ�����(main.cpp)
void CreateTree(BinaryTree<char> &tree);    // ������ʽ������
void ShowTree(BinaryTree<char> &tree);  // �����ʽ������
void InsertTree(BinaryTree<char> &tree);        // ��ӽ��
void DeleteTree(BinaryTree<char> &tree);        // ɾ�����
void Destroy(BinaryTree<char> &tree);     // ��ն�����
/// ������
int main( )
{
    system("title ����������");     // ����ϵͳ�������DOS��������

    // ����״̬�µ������Ϣ
#ifdef DEBUG           // ����궨����DEBUG, ִ��һ�����
    cout <<"\t\tHello World*****************************************" <<endl;
    cout <<"\t\t**              Now Start Debug                   **" <<endl;
    cout <<"\t\t*****************************************Hello World" <<endl;
#else
    cout <<"\t\t****************************************************" <<endl;
    cout <<"\t\t**              Test BinaryTree Of                **" <<endl;
    cout <<"\t\t****************************************************" <<endl;
#endif

    Welcome( );         // ��ӭ����

    // �����ʼ������
    int choice;
    BinaryTree<char> tree;
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
            cout <<"\t\t**   ����ǰ��ѡ��1 -=> �½���ʽ������   **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;


            // ������Բ���
            cout <<"��ʽ�������Ѿ���ʼ��\n�뿪ʼ�������ַ�������\n����'#'��ʾ��" <<endl <<endl;
            cout <<"�ļ�InPut.txt�и����˼����������, ���������Բ���" <<endl <<endl;
            CreateTree(tree);

            // ϵͳ��Ϣ��ʾ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            //getchar( );
            system("pause");
            break;



            /// ������ʽ������
        case 2:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**   ����ǰ��ѡ��2 -=> ������ʽ������   **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���
            cout <<"Ϊ�˷�����֤�������ȷ��, ���ǽ�������ʾ�����ֱ�����ʽ" <<endl <<endl;
            ShowTree(tree);

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

            /// 4 -=> ��ӽ��
        case 3:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**       ����ǰ��ѡ��3 -=> ��ӽ��       **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            // ������Բ���
            InsertTree(tree);

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t**              ���ݲ������              **" <<endl;
            cout <<"\t\t**             �����������˵�             **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

            /// 4 -=> ɾ�����
        case 4:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**      ����ǰ��ѡ��4 -=> ɾ�����      **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;


            // ������Բ���
            DeleteTree(tree);


            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

            /// 5 -=> �����ʽ������
        case 5:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**   ����ǰ��ѡ��5 -=> �����ʽ������   **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���
            Destroy(tree);

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



//template <class ElemType>
void CreateTree(BinaryTree<char> &tree) // ������ʽ������
{
/*
    int choice;
    cout <<"************************" <<endl;
    cout <<"** ��ѡ�����Ľ�����ʽ **" <<endl;
    cout <<"** 1 -=> ǰ��ʽ���� **" <<endl;
    cout <<"** 2 -=> ����ʽ���� **" <<endl;
    cout <<"** 3 -=> ����ʽ���� **" <<endl;
    cout <<"************************" <<endl;
    cout <<"Please enter tour choice" <<endl;

    cin >>choice;
    cout <<"��������������, ����#��ʶ���Ϊ��" <<endl <<endl;
    switch(choice)
    {
    case 1:
        tree.PreCreate(Read, IsNull);
        break;
    case 2:
        tree.InCreate(Read, IsNull);
        break;
    case 3:
        tree.PostCreate(Read, IsNull);
        break;
    }*/
    cout <<"ǰ����������" <<endl;
    cout <<"��������������, ����#��ʶ���Ϊ��" <<endl <<endl;
    tree.PreCreate(Read, IsNull);
}

void ShowTree(BinaryTree<char> &tree)       // ������ʽ������
{
    cout <<"��ǰ�����������HEIGHT: "<<tree.Height( ) <<", �����Ŀ" <<tree.NodeCount( ) <<endl <<endl;
    cout <<"ǰ����������" <<endl;
    tree.PreOrder(Write);          // ���������������

    cout <<endl <<"������������" <<endl;
    tree.InOrder(Write);           // ���������������

    cout <<endl <<"������������" <<endl;
    tree.PostOrder(Write);         // �������ĺ������

    cout <<endl <<"��α��������" <<endl;
    tree.LevelOrder(Write);        // �������Ĳ�α���

    cout <<endl <<endl;
}


void InsertTree(BinaryTree<char> &tree)     // ����������Ľ��
{
    char elem, temp;
    BinTreeNode<char> *node;
    while( 1 )
    {
        // ��������Ľ��
        cout <<endl <<"��ǰ��������α��������" <<endl;
        tree.LevelOrder(Write);        // �������Ĳ�α���
        cout <<endl <<endl;

        // ������Ϣ��ʾ
        cout <<"��������Ҫ��ӵ����ݵ�λ��, ֱ��������λ�õ�����ֵ" <<endl;
        cout <<"����#��������" <<endl;
        cin >>elem;

        if(elem == '#')     // ѭ����ֹ����
        {
            break;
        }
        node = tree.Search(elem);   // ��ѯ��Ҫ�����λ��

        if(node == NULL)    // �����ѯʧ��
        {
            cout <<"�����λ������, ��ѯ����" <<temp <<"���" <<endl <<endl;
            continue;
        }
        else        // ����������������Լ����뷽ʽ
        {
            cout <<"��������Ҫ���������ֵ, �Լ�����ķ�ʽ[��Ϊ���ӽ�����l, ���ӽ��r]" <<endl;
            cout <<"ELEM = ";
            cin >>elem;
            cout <<"Ll or Rr: ";
            cin >>temp;

            switch(temp)
            {
            case 'l':
            case 'L':
                tree.InsertLeftChild(node, elem);   // ��������
                break;
            case 'r':
            case 'R':
                tree.InsertRightChild(node, elem);  // ��Ϊ�ҽ�����
                break;
            }
            cout <<"����ɹ�" <<endl <<endl <<endl;
        }
    }
}



void DeleteTree(BinaryTree<char> &tree) // ɾ���������Ľ��
{
    char elem, temp;
    BinTreeNode<char> *node;
    while( 1 )
    {
        // ��������Ľ��
        cout <<endl <<"��ǰ��������α��������" <<endl;
        tree.LevelOrder(Write);        // �������Ĳ�α���
        cout <<endl;

        // ������Ϣ��ʾ
        cout <<"��������Ҫɾ�������ݵĸ��ڵ�����" <<endl;
        cout <<"����#����ɾ��" <<endl;
        cin >>elem;

        if(elem == '#')     // ѭ����ֹ����
        {
            break;
        }
        node = tree.Search(elem);   // ��ѯ��Ҫ�����λ��
        if(node == NULL)    // �����ѯʧ��
        {
            cout <<"�����λ������, ��ѯ����" <<temp <<"���" <<endl <<endl;
            continue;
        }
        else        // ����������������Լ����뷽ʽ
        {
            cout <<"��������Ҫɾ����λ��[ɾ��������l, ������r]" <<endl;
            cout <<"Ll or Rr: ";
            cin >>temp;

            switch(temp)
            {
            case 'l':
            case 'L':
                tree.DeleteLeftChild(node);     // ɾ��node��������
                break;
            case 'r':
            case 'R':
                tree.DeleteRightChild(node);     // ɾ��node��������
                break;
            }
            cout <<"ɾ���ɹ�" <<endl <<endl <<endl;
        }
    }
}


void Destroy(BinaryTree<char> &tree)     // ��ն�����
{
    // ������ǰ�Ľ��
    cout <<endl <<"��ǰ��������α��������" <<endl;
    tree.LevelOrder(Write);        // �������Ĳ�α���
    cout <<endl;
    cout <<"��ǰ�����������HEIGHT: "<<tree.Height( ) <<", �����Ŀ" <<tree.NodeCount( ) <<endl <<endl <<endl;


    cout <<"��ն�������" <<endl;
    tree.~BinaryTree( );
    cout <<"��ǰ�����������HEIGHT: "<<tree.Height( ) <<", �����Ŀ" <<tree.NodeCount( ) <<endl <<endl;
}
