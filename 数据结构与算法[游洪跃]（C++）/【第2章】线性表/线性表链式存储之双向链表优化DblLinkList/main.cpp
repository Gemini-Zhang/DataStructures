/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : SqList.h
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

#include "DblLinkList.h"
using namespace std;

//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define VERSION  1                  // ���������ʾ�汾�Լ�������Ϣ�뽫�ú궨����Ϊ0
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�

/// �ⲿ�����������ļ�Other.cpp��
void Welcome( );        // ��ӭ����
void Menu( );       // �˵���ʾ����
void Delay( );      // ��ʱ����
void Lording( );    // ���뺯��
void Stop( );       // ��ֹ����

///// �ڲ�����
//template <class ElemType>
//void Display(const DblLinkList<ElemType> &list)    // ��ʾ����
//


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
    cout <<"\t\t**            Test DblLinkList Of              **" <<endl;
    cout <<"\t\t****************************************************" <<endl;
    #endif

    Welcome( );         // ��ӭ����

    // �����ʼ������
    int choice, length, temp, position;
    int leftPosition, rightPosition, leftItem, rightItem;                // ��֧ѡ����Ϣ
    DblLinkList<int> list;       // �½�һ��������������

    Lording( );         // ���뺯��

    while( 1 )
    {

        Menu( );        // ϵͳ�˵�

        cin >>choice;         //��������ѡ��
        switch(choice)
        {
            /// 1 -=> �½�һ�������Ա�
          case 1:
            system("cls");
            // ϵͳ��Ϣ��ʾ
            cout <<"******************************************" <<endl;
            cout <<"** ����ǰ��ѡ��1 -=> �½�һ������������ **" <<endl;
            cout <<"******************************************" <<endl <<endl <<endl;

            // ��Ϣ����
            cout <<"ϵͳ���½�һ����������, ������һЩ�������" <<endl <<endl;
            cout <<"�����뵱ǰ��������ı�" <<endl <<"length = ";     // ������Ϣѧ��ʾ
            cin >>length;                           // ��������

            // DblLinkList������Ϣ
            srand(time(NULL));          // �������������
            for(int i = 1; i <= length; i++)
            {
                temp = rand() %100 + 1;             // ����һ��1-100�������
                list.Inlist(temp);     // ֱ�ӽ����õ����Ԫ��temp�������������ĩβ
                //list.Insert(i, temp);       //Ҳ���Խ����õ������, ���뵱ǰ��������ĵ�i��λ��

                // �����ʾ��Ϣ
              //  #if define REMIND                    // ���������REMIND��, ������������Ϣ
                cout <<"������" <<temp <<"������������ĵ�" <<i <<"��λ��" <<endl <<endl;     // ��ʾ��Ϣ
              //  #endif              // ��������

            }

            // ϵͳ��Ϣ��ʾ
            cout <<"���ݲ������" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            //getchar( );
            system("pause");
            break;

          /// 2 -=> ��ʾ��������������
          case 2:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"******************************************" <<endl;
            cout <<"** ����ǰ��ѡ��2 -=> ��ʾ�������������� **" <<endl;
            cout <<"******************************************" <<endl <<endl <<endl;

            // ������Ա��е�����


            // DblLinkList������Ϣ
            length = list.Length( );

            cout <<"��ǰ������������" <<length <<"������" <<endl;
            cout <<"����ȡ������������Ա��е�ÿ����" <<endl;
            for(int i = 1; i <= length; i++)
            {
               // system("pause");
                if(list.GetElem(i, temp) == true)      // ȡ����������ĵ�i��Ԫ��, ����ȡ�������ݴ��ڱ���temp��
                {
                    cout <<setw(4)<<temp;
                }
                else
                {
                    cout <<"ȡ������ʧ��" <<endl;
                }
            }
            cout <<endl <<endl;     // ִ�л�����Ϣ

            // ϵͳ��ʾ��Ϣ
            cout <<"����������" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            system("pause");
            break;

          case 3:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"****************************************" <<endl;
            cout <<"** ����ǰ��ѡ��3 -=> �����������Ա� **" <<endl;
            cout <<"****************************************" <<endl <<endl <<endl;

            // ������Բ���
            // ����ǰ�����
            cout <<"��ǰ���������е�����Ϊ:" <<endl;
            for(int i = 1; i <= length; i++)
            {
               // system("pause");
                if(list.GetElem(i, temp) == true)      // ȡ����������ĵ�i��Ԫ��, ����ȡ�������ݴ��ڱ���temp��
                {
                    cout <<setw(4)<<temp;
                }
                else
                {
                    cout <<"ȡ������ʧ��" <<endl;
                }
            }
            cout <<endl <<endl;     // ִ�л�����Ϣ

            cout <<"����������Ԫ��Ϊ��" <<endl;
            if((list.SelectSort( ) == true) && (list.BubbleSort() == true))
            {
                cout <<"��С���������Ľ��Ϊ��" <<endl;
                for(int i = 1; i <= length; i++)
                {
                // system("pause");
                    if(list.GetElem(i, temp) == true)      // ȡ����������ĵ�i��Ԫ��, ����ȡ�������ݴ��ڱ���temp��
                    {
                        cout <<setw(4)<<temp;
                    }
                    else
                    {
                        cout <<"ȡ������ʧ��" <<endl;
                    }
                }
                cout <<endl <<endl;     // ִ�л�����Ϣ
            }

            // ϵͳ��ʾ��Ϣ
            cout <<"�����������" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            system("pause");
            break;

          /// 4 -=> �����Ա�ֳ���ż������
          case 4:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"**********************************************" <<endl;
            cout <<"** ����ǰ��ѡ��4 -=> �����Ա�ֳ���ż������ **" <<endl;
            cout <<"**********************************************" <<endl <<endl <<endl;

            cout <<"��ǰ���������е�ԭ�����ݵ�˳��Ϊ:" <<endl;
            for(int i = 1; i <= length; i++)
            {
               // system("pause");
                if(list.GetElem(i, temp) == true)      // ȡ����������ĵ�i��Ԫ��, ����ȡ�������ݴ��ڱ���temp��
                {
                    cout <<setw(4)<<temp;
                }
                else
                {
                    cout <<"ȡ������ʧ��" <<endl;
                }
            }
            cout <<endl <<endl;     // ִ�л�����Ϣ

            leftPosition = 1;
            rightPosition = list.Length( );
            while(leftPosition < rightPosition)
            {
                list.GetElem(leftPosition, leftItem);   //ȡ��list��ߵ�����leftItem
                list.GetElem(rightPosition, rightItem); //ȡ��list�ұߵ�����rightItem

                if(leftItem % 2 == 1)   //�����ߵ���leftItem������
                {
                    leftPosition++;    //���Ͻ��Ҫ��, ���ǽ�leftPosition���Ƶ���һ����
                    //cout <<leftItem <<"  " <<rightItem <<"����A"<<endl;
                }
                else if(rightItem % 2 == 0)   //����ұߵ���rightItem��ż��
                {
                    rightPosition--;    //���Ͻ��Ҫ��, ���ǽ�rightPositionǰ�Ƶ���һ����
                   // cout <<leftItem <<"  " <<rightItem <<"����B"<<endl;
                }
                else //���list��ߵ���leftItemΪż��, ���ұߵ���rightItemΪ����
                {   //���������������Ҫ����Ҫ -=> ������������
                   // list.SetElem(leftPosition++, rightItem);
                    //list.SetElem(rightPosition--, leftItem);
                    list.Swap(leftPosition++, rightPosition--);
                    //cout <<leftItem <<"  " <<rightItem <<"����C"<<endl;
                //    if(leftPosition == rightPosition)  break;
                }
            }

            cout <<"������˳��Ϊ��" <<endl;
            for(int i = 1; i <= length; i++)
            {
               // system("pause");
                if(list.GetElem(i, temp) == true)      // ȡ����������ĵ�i��Ԫ��, ����ȡ�������ݴ��ڱ���temp��
                {
                    cout <<setw(4)<<temp;
                }
                else
                {
                    cout <<"ȡ������ʧ��" <<endl;
                }
            }
            cout <<endl <<endl;     // ִ�л�����Ϣ

            // ϵͳ��ʾ��Ϣ
            cout <<"���ݷָ����" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            system("pause");
            break;

          /// 5 -=> ���Ԫ��
          case 5:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"************************************" <<endl;
            cout <<"**   ����ǰ��ѡ��5 -=> ���Ԫ��   **" <<endl;
            cout <<"*************************************" <<endl <<endl <<endl;


            // ������Բ���
            length = list.Length( );
            // ����ǰ�����
            cout <<"��ǰ���������е�����Ϊ:" <<endl;
            for(int i = 1; i <= length; i++)
            {
               // system("pause");
                if(list.GetElem(i, temp) == true)      // ȡ����������ĵ�i��Ԫ��, ����ȡ�������ݴ��ڱ���temp��
                {
                    cout <<setw(4)<<temp;
                }
                else
                {
                    cout <<"ȡ������ʧ��" <<endl;
                }
            }
            cout <<endl <<endl;     // ִ�л�����Ϣ
            while( 1 )
            {
                cout <<"������������Ԫ��[����0 0�������]" <<endl;
                cout <<"������Ҫ��ӳ��ڼ���Ԫ�غ���Ҫ��ӵ�����" <<endl;
                cin >>position >>temp;
                if(position == 0 && temp == 0 )
                {
                    break;
                }

                if(list.Insert(position, temp) == true)
                {
                    length++;
                    cout <<"����ӵ�Ԫ��" <<temp <<"��ǰ���������й���" <<length <<"��Ԫ��" <<endl;
                    cout <<"���Ԫ�غ�, ��ǰ���Ա����Ϣ����" <<endl;
                }

                for(int i = 1; i <= length; i++)
                {
                    list.GetElem(i, temp);
                    cout <<setw(4)<<temp;
                }
                cout <<endl <<endl;
            }

            // ϵͳ��ʾ��Ϣ
            cout <<"����������" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            system("pause");
            break;

          /// 6 -=> ɾ��Ԫ��
          case 6:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"************************************" <<endl;
            cout <<"**   ����ǰ��ѡ��6 -=> ɾ��Ԫ��   **" <<endl;
            cout <<"*************************************" <<endl <<endl <<endl;

            // ������Բ���
            length = list.Length( );
            // ɾ��ǰ�����
            cout <<"��ǰ���������е�����Ϊ:" <<endl;
            for(int i = 1; i <= length; i++)
            {
               // system("pause");
                if(list.GetElem(i, temp) == true)      // ȡ����������ĵ�i��Ԫ��, ����ȡ�������ݴ��ڱ���temp��
                {
                    cout <<setw(4)<<temp;
                }
                else
                {
                    cout <<"ȡ������ʧ��" <<endl;
                }
            }
            cout <<endl <<endl;     // ִ�л�����Ϣ
            while( 1 )
            {
                cout <<"ɾ�����Ա��Ԫ��[����0����ɾ��]" <<endl;
                cout <<"������Ҫɾ�����ڼ���Ԫ��" <<endl;
                cin >>position;
                if(position == 0)       // ����0ʱ����ɾ������
                {
                    break;
                }

                if(list.Delete(position, temp) == true)
                {
                    length--;
                    cout <<"��ɾ����Ԫ��" <<temp <<", ��ǰ���������л�ʣ��" <<length <<"��Ԫ��" <<endl;
                    cout <<"ɾ����Ԫ�غ�, ��ǰ���Ա����Ϣ����" <<endl;
                }
                else
                {
                    cout <<"����ʧ��...." <<endl;           // ��ʾ��Ϣ
                }

                // �����ǰ��Ԫ����Ϣ
                for(int i = 1; i <= length; i++)
                {
                    list.GetElem(i, temp);
                    cout <<setw(4)<<temp;
                }
                cout <<endl <<endl;
            }

            // ϵͳ��ʾ��Ϣ
            cout <<"����ɾ�����" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            system("pause");
            break;

          /// 7 -=> �����������
          case 7:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"**************************************" <<endl;
            cout <<"**   ����ǰ��ѡ��7 -=> ������Ա�   **" <<endl;
            cout <<"**************************************" <<endl <<endl <<endl;

            cout <<"���Ա���ԭ������" <<endl;
            length = list.Length( );
            // ɾ��ǰ�����
            cout <<"��ǰ���������е�����Ϊ:" <<endl;
            for(int i = 1; i <= length; i++)
            {
               // system("pause");
                if(list.GetElem(i, temp) == true)      // ȡ����������ĵ�i��Ԫ��, ����ȡ�������ݴ��ڱ���temp��
                {
                    cout <<setw(4)<<temp;
                }
                else
                {
                    cout <<"ȡ������ʧ��" <<endl;
                }
            }
            cout <<endl <<endl;     // ִ�л�����Ϣ

            cout <<"�������" <<endl <<endl;
            list.Clean( );          // �����������

            cout <<"��ճɹ���, ��������Ϊ��, �޷�����" <<endl;

            // ϵͳ��ʾ��Ϣ
            cout <<"����������ճɹ�" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            system("pause");

          /// 0 -=> �˳�����
          case 0:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"***********************************" <<endl;
            cout <<"**   ����ǰ��ѡ��0 -=> �˳�����  **" <<endl;
            cout <<"***********************************" <<endl <<endl <<endl;            // ϵͳ��ʾ��Ϣ

            Stop( );
//            #if (VERSION)     // ���������Ϣ���
//            cout <<"\t\t**************************************************" <<endl;
//            cout <<"\t\t**  Wacky Window (c) 2012 Wacky SoftWare. Inc.  **"<<endl;
//            cout <<"\t\t**     Complied on " <<__DATE__ <<" at " <<__TIME__ <<"      **"<<endl;
//            cout <<"\t\t**************************************************" <<endl;
//
//            system("pause");
//            #endif

        Lording( );         // ���뺯��
        }
    }

    return 0;
}



//// �������ƣ�void Display(const DblLinkList<ElemType> &list)
//// ��ʼ���������Ա��Ѿ�����, ���������Ѿ�����
//// ������������Ԫ�ض���
//template <class ElemType>
//void Display(const DblLinkList<ElemType> &list)    // ��ʾ����
//{
//    int length = list.Length( );
//
//    if(length == 0)
//    {
//        cout <<"��ǰ���������Ϊ" <<length <<", ������ʾʧ��" <<endl;
//        return;
//    }
//
//    ElemType temp;
//    for(int i = 1; i < length; i++)
//    {
//        if(list.GetElem(i, temp) == true)      // ȡ����������ĵ�i��Ԫ��, ����ȡ�������ݴ��ڱ���temp��
//        {
//            cout <<setw(4)<<temp;
//        }
//        else
//        {
//            cout <<"ȡ������ʧ��" <<endl;
//        }
//    }
//    cout <<endl <<endl;     // ִ�л�����Ϣ
//}
