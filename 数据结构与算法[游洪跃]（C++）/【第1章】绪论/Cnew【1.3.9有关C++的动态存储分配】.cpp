/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : Cnew��1.3.9�й�C++�Ķ�̬�洢���䡿
Description: newd��ʹ�÷���
Author     : Gatie_Me
Version    : Copyright 2012
Data_Time  : 20112-8-4 15:36:24
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
********************************************************************************/


#ifndef _MSC_VER            //�����ǰ���뻷����VC
#if _MSC_VER == 1200      //��ʾ��ǰ�����汾��ΪVC6.0
#include <iostream.h>       //�Դ��ַ�ʽ����cout
#else                       //��������VC�汾
#include <iostream>         //�Դ��ַ�ʽ����cout
using namespace std;
#endif                      //����_MSC_VER�жϽ���, ��ָ�ж��������뻷��
#else                       //��VC���뻷��
#include <iostream>
using namespace std;
#endif                      //�����ж�

#include <fstream>
#include <cstdlib>
#include <cstring>

#define MAX_LINE_LENGTH 100


int main(int argc, char *argv[])
{
    cout <<"***********************************" <<endl;
    cout <<"**  CPludPlus's new and delete   **" <<endl;
    cout <<"***********************************" <<endl;

    ifstream *inFilePtr;
    char *strPtr, *strFileNamePtr;
    strPtr = new char[MAX_LINE_LENGTH];         //��̬�����ڴ�
    strFileNamePtr = new char[MAX_LINE_LENGTH]; //��̬�����ڴ�

    if(argc != 2)
    {
        cout <<"��������Ҫ��ʾ���ı��ļ���" <<endl;
        cin >>strFileNamePtr;  //�����ļ���
    }
    else
    {
        strcpy(strFileNamePtr, argv[1]);
    }

    inFilePtr = new ifstream(strFileNamePtr);
    if(inFilePtr == NULL)
    {
        cout <<"���ļ�" <<strFileNamePtr <<"ʧ��" <<endl;
        exit(1);    //�������˳�
    }

    while(!inFilePtr->eof())   //���ļ�inFilePtrδ����ʱѭ��
    {
          inFilePtr->getline(strPtr, MAX_LINE_LENGTH);  //����һ���ַ�
          cout <<strPtr <<endl;                         //��ʾһ���ַ�
    }

    delete []strPtr;   //��̬�ͷ��ַ���
    delete []strFileNamePtr;//��̬�ͷ��ַ���
    delete []inFilePtr;   //��̬�ͷ��ַ���


    system("pause");

    return 0;
}

///����ע��
/**********************************************************************
Function      :      ///��������
Description   :      ///�������ܡ����ܵȵ�����
Calls         :      ///�����������õĺ����嵥
Called By     :      ///���ñ������ĺ����嵥
Table Accessed:      ///�����ʵı����������ǣ�������ݿ�����ĳ���
Table Update  :      ///���޸ĵı����������ǣ�������ݿ�����ĳ���
Input         :      ///�����������˵��, ����ÿ�����������á�ȡֵ˵����������Ĺ�ϵ
Output        :      ///�����������˵��
Return        :      ///��������ֵ��˵��
Others        :      ///����˵��
**********************************************************************/
