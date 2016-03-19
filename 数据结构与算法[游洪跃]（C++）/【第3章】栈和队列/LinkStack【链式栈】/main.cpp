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

#include "LinkStack.h"
using namespace std;

/// �ⲿ�����������ļ�Other.cpp��
void Welcome( );        // ��ӭ����
void Menu( );       // �˵���ʾ����
void Delay( );      // ��ʱ����
void Lording( );    // ���뺯��
void Stop( );       // ��ֹ����

/// �ڲ������������ļ���ǰ�ļ�main.cpp��
void MatchFile( );          // ��ʼ����ƥ����ļ�����
bool Match(char *s);        // ����ƥ��

/// ������
int main( )
{
    // ����״̬�µ������Ϣ
    #if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
    cout <<"\t\tHello World*****************************************" <<endl;
    cout <<"\t\t**              Now Start Debug                   **" <<endl;
    cout <<"\t\t*****************************************Hello World" <<endl;
    #endif

    // �ǵ���״̬�µ������Ϣ
    #ifndef DEBUG                // ����궨����DEBUG, ִ��һ�����
    cout <<"\t\t**************************************************** " <<endl;
    cout <<"\t\t**            Test SimpleLinkList Of              **" <<endl;
    cout <<"\t\t****************************************************" <<endl;
    #endif

    Welcome( );         // ��ӭ����



    // �����ʼ������
    char answer;
    int choice, length, temp;

    LinkStack<int> stack;     // ����һ��˳��ջ

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
            cout <<"\t\t** ����ǰ��ѡ��1 -=> �½�һ������������ **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���
            cout <<"��������ϣ��������˳��ջ��ջ��" <<endl;
            cout <<"�����ϵͳ�Ὠ��һ��˳��ջ�������" <<endl;
            cin >>length;       // ����˳��ջ������

            srand(time(NULL));              // �������������
            for(int i = 0; i < length; i++) // ��ϵͳ���õ�����ѹ��ջ��
            {
                temp = rand() % 100 + 1;                    // ����һ��1-100�������
                stack.Push(temp);                           // ������ѹ��ջ��
                cout <<"������" <<temp <<"ѹ��ջ��" <<endl; // ��ʾ��Ϣ
            }

            // ϵͳ��Ϣ��ʾ
            cout <<endl <<endl;
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 2 -=> ��ʾ��������������
          case 2:
            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t********************************************" <<endl;
            cout <<"\t\t** ����ǰ��ѡ��2 -=> ���ε���˳��ջ������ **" <<endl;
            cout <<"\t\t********************************************" <<endl <<endl <<endl;

            while(!stack.Empty())
            {
                cout <<"����������: "<<stack.Pop() <<endl;
            }

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 3 -=> ����ƥ����
          case 3:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**    ����ǰ��ѡ��3 -=> ����ƥ����    **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���

            MatchFile( );
            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**            ���ż��������          **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 4 -=> Ԫ����ջ
          case 4:

            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**      ����ǰ��ѡ��5 -=> Ԫ����ջ      **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;


            // ������Բ���
            cout <<"��������ջ���ݽṹ, �޷����ò���λ��" <<endl <<endl;
            while( 1 )
            {
                cout <<"��������Ҫ���������[����0��������]" <<endl;
                cin >>temp;
                if(temp == 0)
                {
                    break;
                }
                stack.Push(temp);
                cout <<"������" <<temp <<"����ջ��" <<endl;
            }
            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ����������            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 5 -=> Ԫ�س�ջ
          case 5:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**      ����ǰ��ѡ��5 -=> Ԫ�س�ջ     **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���

            do
            {	// ѭ��ֱ���û�����ǡ���Ļش�Ϊֹ
                cout <<"�������Ƿ�ȷ����Ҫ����ջ������" <<endl;
                cout << "(y, n)?" << "��y��n�ش�:";
                while ((answer = getchar( )) == '\n');	// �����ո�,�Ʊ�������з���ȡһ�ַ�
                if(answer == 'y' || answer == 'Y')         // ֻҪջ���ǿյ�
                {
                    if(stack.Pop(temp) == true)     // ����ջ��Ԫ��
                    {
                        cout <<"����ջ������" <<temp <<endl;
                    }
                }
                else if(answer != 'n' && answer != 'N')
                {
                    cout <<"��Ϣ��������, ����������" <<endl;
                }

                if(stack.Empty() == true)   // �����ǰ˳��ջΪ��, ��ϵͳ���Զ��������˵�
                {
                    break;
                }
            }while (answer != 'n' && answer != 'N');

            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݳ�ջ���            **" <<endl;
            cout <<"\t\t**             �����������˵�           **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl;
            cout <<"Please ent any key to continue........................" <<endl;
            system("pause");
            break;

          /// 6 -=> �����������
          case 6:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**     ����ǰ��ѡ��6 -=> ���˳��ջ     **" <<endl;
            cout <<"\t\t******************************************" <<endl <<endl <<endl;

            // ������Բ���
            stack.Clear( );         // ��˳��ջ���
            cout <<"������, ��ǰ˳��ջ����" <<stack.Length() <<endl <<endl;
            // ϵͳ��ʾ��Ϣ
            cout <<"\t\t******************************************" <<endl;
            cout <<"\t\t**              ���ݲ������            **" <<endl;
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



// ��������Ƿ�ƥ��
void MatchFile( )
{
    char str[100], fName[] = "StackInput.txt";                 // ��ʱ�ַ�
    ifstream fpi;                  // �����ļ�

    fpi.open(fName, ios::binary);     // �������ļ�
    if(fpi.fail() == true)  exit(1);        // ���ļ�ʧ�ܹرճ���
    while( 1 )
    {
        fpi.getline(str, 1000);     // ����һ���ַ���

        cout <<"��ǰ��Ҫ�жϵ��ַ���\"" <<str <<"\""<<endl;     // �����Ϣ��ʾ

        if(Match(str) == true)
        {
            cout <<"��ǰ������ƥ���" <<endl;
        }
        else
        {
            cout <<"��ǰ���Ų�ƥ��" <<endl;
        }
        if(fpi.fail() == true || strcmp(str, "") == 0)
        {
            break;      // �����ļ�ĩβ��ʱ��ֹͣ
        }
    }

}

// ��������Ƿ�ƥ��
bool Match(char *str)
{
    LinkStack<char> strStack;     // �ַ���ջ
    char tempCh;                // ��ʱ�ַ�

    for(int i = 0; str[i] != '\0'; i++)
    {
       /* switch(str[i])
        {
          //�������е�һ��������ջ
          case '(':            // ����������ַ���(
          case '[':             // ����������ַ���[
          case '{':             // ����������ַ���{
            strStack.Push(str[i]);  break;      // �ͽ��ַ�ѹ��ջ��

          // ���()�Ƿ�ƥ��
          case ')':     // ��鵱ǰ��()�Ƿ�ƥ��
            if(strStack.Empty())    // ����Ǹ���ջ, �����ſӶ���ƥ��
            {
                return false;
            }
            else if(strStack.Top(tempCh), tempCh == ')')     // �����ǰ�������ƥ��
            {
                strStack.Pop(tempCh);           // ���Ѿ�ƥ������ŵ���
            }
            else
            {
                return false;
            }

            break;

          // ���[]�����Ƿ�ƥ��
          case ']':
            if(strStack.Empty())    // ����Ǹ���ջ, �����ſӶ���ƥ��
            {
                return false;
            }
            else if(strStack.Top(tempCh), tempCh == ']')     // �����ǰ�������ƥ��
            {
                strStack.Pop(tempCh);           // ���Ѿ�ƥ������ŵ���
            }
            else
            {
                return false;
            }

            break;

          // ���{ }�Ƿ�ƥ��
          case '}':
            if(strStack.Empty())    // ����Ǹ���ջ, �����ſӶ���ƥ��
            {
                return false;
            }
            else if(strStack.Top(tempCh), tempCh == '}')     // �����ǰ�������ƥ��
            {
                strStack.Pop(tempCh);           // ���Ѿ�ƥ������ŵ���
            }
            else
            {
                return false;
            }
        }*/
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')     //�������е�һ��������ջ
        {
            strStack.Push(str[i]);    // �ͽ��ַ�ѹ��ջ��
        }
        else if(str[i] == ')')  // ���()�Ƿ�ƥ��// ��鵱ǰ��()�Ƿ�ƥ��
        {
            if(strStack.Empty())    // ����Ǹ���ջ, �����ſӶ���ƥ��
            {
                return false;
            }
            else if(strStack.Top(tempCh), tempCh == '(')     // �����ǰ�������ƥ��
            {
                strStack.Pop(tempCh);           // ���Ѿ�ƥ������ŵ���
            }
            else
            {
                return false;
            }
        }
        else if(str[i] == ']')  // ���[]�����Ƿ�ƥ��
        {
            if(strStack.Empty())    // ����Ǹ���ջ, �����ſӶ���ƥ��
            {
                return false;
            }
            else if(strStack.Top(tempCh), tempCh == '[')     // �����ǰ�������ƥ��
            {
                strStack.Pop(tempCh);           // ���Ѿ�ƥ������ŵ���
            }
            else
            {
                return false;
            }
        }
        else if(str[i] == '}')
        {
            if(strStack.Empty())    // ����Ǹ���ջ, �����ſӶ���ƥ��
            {
                return false;
            }
            else if(strStack.Top(tempCh), tempCh == '{')     // �����ǰ�������ƥ��
            {
                strStack.Pop(tempCh);           // ���Ѿ�ƥ������ŵ���
            }
            else
            {
                return false;
            }
        }
    }

    if(strStack.Empty())        // ����Ƿ�ƥ��
    {
        return true;
    }
    else
    {
        return false;
    }
}



