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

#include "SqList.h"
using namespace std;

//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define VERSION  1                  // ���������ʾ�汾�Լ�������Ϣ�뽫�ú궨����Ϊ0


/// �ⲿ�����������ļ�Other.cpp��
template <class ElemType>
void Read(ElemType &elem);        // ��������Ԫ��

template <class ElemType>
void Write(ElemType &elem);       // ��������Ԫ��

//void Read(const int);        // ��������Ԫ��
////
////
//void Write(const int);       // ��������Ԫ��

void Menu( );
void Delay( );   // ��ʱ����
void Lording( );   // ���뺯��

// ������
int main( )
{

    // Ԥ���봦��
 //   typedef void (*FunctionPoint)(int);
    // ����״̬�µ������Ϣ
    #if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
    cout <<"\t\t\tHello World***********************" <<endl;
    cout <<"\t\t\t**     Now Start Debug          **" <<endl;
    cout <<"\t\t\t***********************Hello World" <<endl;
    #endif

    // �ǵ���״̬�µ������Ϣ
    #ifndef DEBUG                // ����궨����DEBUG, ִ��һ�����
    cout <<"\t\t\t**********************************" <<endl;
    cout <<"\t\t\t**       Test Sqlist Of         **" <<endl;
    cout <<"\t\t\t**********************************" <<endl;
    #endif

    cout <<"Please any key to continue";
    getchar( );
    system("cls");

    int choice = 1, temp, lenList; /*��*/;
    int leftPosition, rightPosition;   //�±�����Ϣ
    int leftItem, rightItem;
    SqList<int> list;   //����һ������˳���[Ĭ�ϴ������Ԫ�ص�Ԫ]


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
            cout <<"****************************************" <<endl;
            cout <<"** ����ǰ��ѡ��1 -=> �½�һ�������Ա� **" <<endl;
            cout <<"****************************************" <<endl <<endl <<endl;

            cout <<"ѡ���ϵͳ���Զ�����һ�����Ա�[�������]" <<endl;

            // �����
            cout <<"�����뼴���������Ա�ı�" <<endl;
            cin >>lenList;          // �����

            srand( time(NULL) );     // �����漴����
            cout <<"��ʾ�������ݵ����" <<endl;
            for(int i = 1; i <= lenList; i++)         // ��������
            {
                temp = rand() %100 + 1;
                if(list.Insert(i, temp) == true)        // �����ݲ���
                {
                    cout <<"������" <<temp <<"�������Ա�ĵ�" <<i <<"��λ��" <<endl;
                    cout <<"��ǰ���Ա�ĳ���Ϊ��" <<list.Length( ) <<endl <<endl;
                    Delay( );
                }
            }

            cout <<"���ݲ������" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            //getchar( );
            system("pause");
            break;

          case 2:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"****************************************" <<endl;
            cout <<"** ����ǰ��ѡ��2 -=> ��ʾ���������Ա� **" <<endl;
            cout <<"****************************************" <<endl <<endl <<endl;
            // ������Ա��е�����
            cout <<endl <<"������Ա���" <<list.Length( ) <<"������Ϊ��" <<endl;     // ���Ա�������
            //  list.Traverse(Write<int>);

            cout <<"����ȡ������������Ա��е�ÿ����" <<endl;
            for(int i = 1; i <= lenList; i++)
            {
                list.GetElem(i, temp);
                cout <<temp <<" ";
            }
            cout <<endl <<endl;

            // ϵͳ��ʾ��Ϣ
            cout <<"����������" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            //getchar( );
            system("pause");
            break;

          case 3:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"****************************************" <<endl;
            cout <<"** ����ǰ��ѡ��3 -=> �����������Ա� **" <<endl;
            cout <<"****************************************" <<endl <<endl <<endl;
            list.SelectSort( );
            // list.BubbleSort( );

            cout <<"��������Ա���" <<list.Length( ) <<"������Ϊ��" <<endl;     // ���Ա�������
            cout <<"����ȡ������������Ա��е�ÿ����" <<endl;
            //  list.Traverse(Write<int>);
            for(int i = 1; i <= lenList; i++)
            {
                list.GetElem(i, temp);
                cout <<temp <<" ";
            }
            cout <<endl <<endl;

            // ϵͳ��ʾ��Ϣ
            cout <<"�����������" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            system("pause");
            break;

          case 4:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"**********************************************" <<endl;
            cout <<"** ����ǰ��ѡ��4 -=> �����Ա�ֳ���ż������ **" <<endl;
            cout <<"**********************************************" <<endl <<endl <<endl;
//�������Ҫ˼·���£�
//                ����leftPosition = 1, rightPosition = list.lenList;
//                list�ĵ�leftPosition��Ԫ��ΪleftItem, list�ĵ�rightPosition��Ԫ��ΪrightItem,
//                ��list��ߵ���leftItemΪ����ʱ, ��leftPosition++;
//                ��list�ұߵ���rightItemΪż��ʱ, ��rightPosition--;
//                ����list��ߵ���leftItemΪż��, ���ұߵ���rightItemΪ����ʱ,
//                �ͽ���leftItem��rightItem, ͬʱleftPosition++, rightPosition--;
//                ֱ��leftPosition == rightPositionʱΪֹ;
//                �㷨���Ӷ�ΪO(n)
            // һ������int��˳���, ����㷨�������Ϊ����������
            // ��߲���ȫΪ����,�ұ߲���ȫΪż��, ����Ҫ���㷨��ʱ�临�Ӷ�ΪO(n)

            // ʵ�ֽ������������Ա�ָ�Ϊ�������ֵ��㷨
                             //�������
            leftPosition = 1;
            rightPosition = list.Length( );   //�±�����Ϣ

            while(leftPosition < rightPosition)
            {
                list.GetElem(leftPosition, leftItem);   //ȡ��list��ߵ�����leftItem
                list.GetElem(rightPosition, rightItem); //ȡ��list�ұߵ�����rightItem

                // ������Ϣ
                #if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
                cout <<leftItem <<"  " <<rightItem <<endl;
                //    system("pause");
                #endif

                if(leftItem % 2 == 1)   //�����ߵ���leftItem������
                {
                    leftPosition++;    //���Ͻ��Ҫ��, ���ǽ�leftPosition���Ƶ���һ����
                //    if(leftPosition == rightPosition)  break;
                }
                else if(rightItem % 2 == 0)   //����ұߵ���rightItem��ż��
                {
                    rightPosition--;    //���Ͻ��Ҫ��, ���ǽ�rightPositionǰ�Ƶ���һ����
                   // if(leftPosition == rightPosition)  break;
                }
                else //���list��ߵ���leftItemΪż��, ���ұߵ���rightItemΪ����
                {   //���������������Ҫ����Ҫ -=> ������������
                    //list.SetElem(leftPosition, rightItem);
                    // list.SetElem(rightPosition, leftItem);
                    list.Swap(leftPosition++, rightPosition--);
                //    if(leftPosition == rightPosition)  break;
                }
            }

            cout <<"�����Ա�ָ�Ϊ����ż�������������Ժ�";
            cout <<"�������ݵ��������Ϊ��" <<endl;     // ���Ա�������
            //  list.Traverse(Write<int>);
            for(int i = 1; i <= lenList; i++)
            {
                list.GetElem(i, temp);
                cout <<temp <<" ";
            }
            cout <<endl <<endl;

            // ϵͳ��ʾ��Ϣ
            cout <<"���ݷָ����" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            system("pause");
            break;

          case 5:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"************************************" <<endl;
            cout <<"**   ����ǰ��ѡ��5 -=> ɾ��Ԫ��   **" <<endl;
            cout <<"*************************************" <<endl <<endl <<endl;

            int position;
            while( 1 )
            {
                cout <<"ɾ�����Ա��Ԫ��[����0����ɾ��]" <<endl;
                cout <<"������Ҫɾ�����ڼ���Ԫ��" <<endl;
                cin >>position;
                if(position == 0)
                {
                    break;
                }

                if(list.Delete(position, temp) == true)
                {
                    cout <<"��ɾ����Ԫ��" <<temp <<endl;
                    cout <<"ɾ����Ԫ�غ�, ��ǰ���Ա����Ϣ����" <<endl;
                }
                for(int i = 1; i <= list.Length( ); i++)
                {
                    list.GetElem(i, temp);
                    cout <<temp <<" ";
                }
                cout <<endl <<endl;
            }

            // ϵͳ��ʾ��Ϣ
            cout <<"����ɾ�����" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            system("pause");
            break;

          case 6:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"**************************************" <<endl;
            cout <<"**   ����ǰ��ѡ��6 -=> ������Ա�   **" <<endl;
            cout <<"**************************************" <<endl <<endl <<endl;
            list.Clean( );
            cout <<"��ճɹ�" <<endl;
            cout <<"��ǰ���Ա�ĳ���Ϊ" <<list.Length( ) <<endl;

            // ϵͳ��ʾ��Ϣ
            cout <<"����ɾ�����" <<endl <<endl;
            cout <<"�����������˵�" <<endl <<endl;
            cout <<"Please ent any key to continue" <<endl;
            system("pause");
          case 0:
            // ϵͳ��ʾ��Ϣ
            system("cls");
            cout <<"***********************************" <<endl;
            cout <<"**   ����ǰ��ѡ��0 -=> �˳�����  **" <<endl;
            cout <<"***********************************" <<endl <<endl <<endl;            // ϵͳ��ʾ��Ϣ

            char answer;
            do
            {	// ѭ��ֱ���û�����ǡ���Ļش�Ϊֹ

                cout << "(y, n)?";
                cout << "��y��n�ش�:";
                while ((answer = getchar( )) == '\n');	// �����ո�,�Ʊ�������з���ȡһ�ַ�
            }while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');

            #if (VERSION)     // ���������Ϣ���
            cout <<"\t\t**************************************************" <<endl;
            cout <<"\t\t**  Wacky Window (c) 2012 Wacky SoftWare. Inc.  **"<<endl;
            cout <<"\t\t**     Complied on " <<__DATE__ <<" at " <<__TIME__ <<"      **"<<endl;
            cout <<"\t\t**************************************************" <<endl;

            system("pause");
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
    //        break;

        }
        Lording( );         // ���뺯��
    }

    return 0;
}

