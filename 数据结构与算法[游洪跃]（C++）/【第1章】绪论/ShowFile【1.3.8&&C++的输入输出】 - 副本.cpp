/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : ��ʾ�ı��ļ�
Description: ��ʾ�ı��ļ�
Author     : Gatie_Me
Version    : �汾����
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

#include <fstream>          //�����ļ���
#include <cstdlib>

const int MAX_LINE_LENGTH = 100;
//#define  MAX_LINE_LENGTH    100
//������
int main(int argc, char *argv[])  //
{
    cout <<"******************************" <<endl;
    cout<<"**       Show The File       **" <<endl;
    cout <<"******************************" <<endl;

    if(argc != 2)
    {
        cout <<"�÷���ShowSFile�ı��ļ���" <<endl;
        system("pause");                //���ÿ⺯��, �ȴ��û���Ӧ
        exit(1);                        //�������˳�1-��������������
    }

    ifstream inFile(argv[1]);     //�����ı��ļ�
    if(inFile.fail())
    {
        cout <<"���ļ�" <<argv[1] <<"ʧ��!" <<endl;
        system("pause");                //���ÿ⺯��, �ȴ��û���Ӧ
        exit(2);                      //�������˳�2-���ļ�ʧ��
    }

    char str[MAX_LINE_LENGTH];
    inFile>>str;        //���ļ��������ַ���

    while(inFile.eof())
    {
        cout <<str <<endl;        //����ַ���
        inFile>>str;              //�����ַ���
    }

    inFile.close( );     //�ر��ļ�


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
