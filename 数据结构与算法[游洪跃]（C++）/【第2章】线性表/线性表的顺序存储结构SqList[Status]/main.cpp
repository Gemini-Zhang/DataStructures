/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : SqList.h
Description: ����һ������int��˳���, ����㷨�������Ϊ����������
             ��߲���ȫΪ����,�ұ߲���ȫΪż��, ����Ҫ���㷨��ʱ�临�Ӷ�ΪO(n)
Dssign     : �������Ҫ˼·���£�
                ����leftPosition = 1, rightPosition = list.length;
                list�ĵ�leftPosition��Ԫ��ΪleftItem, list�ĵ�rightPosition��Ԫ��ΪrightItem,
                ��list��ߵ���leftItemΪ����ʱ, ��leftPosition++;
                ��list�ұߵ���rightItemΪż��ʱ, ��rightPosition--;
                ����list��ߵ���leftItemΪż��, ���ұߵ���rightItemΪ����ʱ,
                �ͽ���leftItem��rightItem, ͬʱleftPosition++, rightPosition--;
                ֱ��leftPosition == rightPositionʱΪֹ;
                �㷨���Ӷ�ΪO(n)
Author     : Gatie_Me
Version    : Copyright 2012
Data_Time  : 20112-8-29 10:28:43
Content    : ���ݽṹ���㷨��C++��������Դ��
********************************************************************************/


/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
********************************************************************************/

#include <iostream>
#include "SqList.h"
using namespace std;


int main()
{
    cout <<"**********************************" <<endl;
    cout <<"**       Test Sqlist Of         **" <<endl;
    cout <<"**********************************" <<endl;
    cout << "Hello world!" << endl;

    SqList<int> list;   //����һ������˳���

    int leftPosition = 1, rightPosition = list.Length( );   //�±�����Ϣ
    int leftItem, rightItem;                                //�������

    while(leftPosition == rightPosition)
    {
        list.GetElem(leftPosition, leftItem);   //ȡ��list��ߵ�����leftItem
        list.GetElem(rightPosition, rightItem); //ȡ��list�ұߵ�����rightItem
        if(leftItem % 2 == 1)   //�����ߵ���leftItem������
        {
            leftPosition++;    //���Ͻ��Ҫ��, ���ǽ�leftPosition���Ƶ���һ����
        }
        if(rightPosition % 2 == 0)   //����ұߵ���rightItem��ż��
        {
            rightPosition--;    //���Ͻ��Ҫ��, ���ǽ�rightPositionǰ�Ƶ���һ����
        }

        if(leftItem % 2 == 0 && rightItem % 2 == 1)  //���list��ߵ���leftItemΪż��, ���ұߵ���rightItemΪ����
        {   //���������������Ҫ����Ҫ -=> ������������
            list.SetElem(leftPosition, rightItem);
            list.SetElem(rightPosition, leftItem);
        }
    }

    return 0;
}

