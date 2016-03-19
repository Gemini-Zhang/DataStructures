/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : Sort.h                                                       *
*  Description: ������ģ��                                                *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                            *
******************************************************************************
**/
#include <iostream>
#include <algorithm>
#include <functional>
#include "LinkList.h"
#include <cmath>
#ifndef SORT_H_INCLUDE
#define SORT_H_INCLUDE

///
#define SIZE 10
#define STEP false
#define NOMAL true
typedef bool OutWay;


//#ifdef SWAP_FUN

/// ��������
template <class ElemType>
void Write(const ElemType &elem);
//#endif

/******************************************************��������BEGIN******************************************************/
//#ifdef INSERT_SORT_FUN
//#error "You must define INSERT_SORT_FUN macro before include this file"
//#else

/// �򵥲�������
// �������ƣ�void StraightInsertSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ��򵥲�������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void StraightInsertSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *),  void (*Visit)(const ElemType &), OutWay outWay = NOMAL);

// �������ƣ�void ShellSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ϣ����������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void ShellSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *),  void (*Visit)(const ElemType &), OutWay outWay = NOMAL);

//#endif
/******************************************************��������_END_******************************************************/



/******************************************************��������BEGIN******************************************************/
//#ifdef SWAP_SORT_FUN
//#error "You must define SWAP_SORT_FUN macro before include this file"
//#else
/// ð�������㷨
// �������ƣ�void BubbleSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ���������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void BubbleSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *),  void (*Visit)(const ElemType &), OutWay outWay = NOMAL);

// �������ƣ�void BubbleUpSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ�������������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void BubbleUpSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *),  void (*Visit)(const ElemType &), OutWay outWay = NOMAL);

// �������ƣ�void BubbleDownSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ��³���������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void BubbleDownSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *),  void (*Visit)(const ElemType &), OutWay outWay = NOMAL);

/// ���������㷨
// �������ƣ�void QuickSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ��򵥲�������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void QuickSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *), OutWay outWay);


template <class ElemType>
int Partition(ElemType elem[], int low, int high);
template <class ElemType>
void Quick_Sort_Help(ElemType *elem, int low, int high);
template <class ElemType>
void Quick_Sort(ElemType *elem, int n);
//#endif
/******************************************************��������_END_******************************************************/


/******************************************************ѡ������BEGIN******************************************************/
//#ifdef SWAP_SORT_FUN
//#error "You must define SWAP_SORT_FUN macro before include this file"
//#else
/// ��ѡ�������㷨
// �������ƣ�void BubbleSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ���������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template <class ElemType>
void SelectSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *), void (*Visit)(const ElemType &), OutWay outWa = NOMAL);

/// �����������㷨
// �������ƣ�void BubbleSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ���������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template <class ElemType>
void SiftAdjust(ElemType *elem, int low, int high, bool (*Comp)(const void *, const void *));
template<class ElemType>
void HeapSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *),  void (*Visit)(const ElemType &), OutWay outWay = NOMAL);
//#endif
//#endif
/******************************************************ѡ������_END_******************************************************/


/******************************************************�鲢����BEGIN******************************************************/
//#ifdef MEEGING_SORT_FUN
//#error "You must define MERGING_SORT_FUN macro before include this file"
//#else
/// �鲢�����㷨
// �������ƣ�void BubbleSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ���������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void MergeSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *), OutWay outWay);
// �������ƣ�MergeSort
// �������ܣ����ø�������ռ�tempElem��Elem����low��highλ�õ����ݽ�������
template <class ElemType>
void MergeSort(ElemType *elem, ElemType *tempElem, int low, int high, bool (*Comp)(const void *, const void *), OutWay outWay);
// �������ƣ�Merge
// �������ܣ������������������[low, mid]��[mid+1, high]�鲢Ϊ�µ�
template <class ElemType>
void Merge(ElemType *elem, ElemType *tempElem, int low, int mid, int high, bool (*Comp)(const void *, const void *));


/******************************************************�鲢����_END_******************************************************/

/******************************************************��������BEGIN*****************************************************/

template <class ElemType>
void Distribute(ElemType elem[], int n, int r, int d, int i, LinkList<ElemType> list[]);


template <class ElemType>
void Colect(ElemType elem[], int n, int r, int d, int i, LinkList<ElemType> list[], OutWay outWay);

template <class ElemType>
void RadixSort(ElemType elem[], int n, int r, int d, OutWay outWay);
/******************************************************��������_END_******************************************************/



template <class ElemType>
void Write(const ElemType &elem)
{
    std::cout <<std::setw(4)<<elem;
}




/// �򵥲�������
// �������ƣ�void StraightInsertSort(ElemType , int , bool (*Comp)(  ), void (*Visit)(ElemType &), OutWay);
// �������ܣ��򵥲�������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void StraightInsertSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *), void (*Visit)(const ElemType &), OutWay outWay)
{
    // ���ԭʼ����
    if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
    {
        std::cout <<"ԭʼ_���У�";
        for(int pos = 0; pos < length; pos++)
        {
            Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
        }
        std::cout <<std::endl;
    }
    // ���򲿷�
    int i, j;
    ElemType temp;

    for(i = 1; i < length; i++)      // ѭ����1�������Ժ��ÿ������
    {
        temp = elem[i];         // �����i������,
        for(j = i - 1; j >= 0 && Comp(&temp, &elem[j]); j--)      // ���ȱ�������ݶ�������
        {
            elem[j + 1] = elem[j];
        }
        // ѭ����������������0-i��λ�����ҵ���tempӦ�ò����λ��(j + 1)
        elem[j + 1] = temp;         // ����������ݲ����


        if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
        {
            std::cout <<"��" <<i <<"������";
            for(int pos = 0; pos < length; pos++)
            {
                Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
            }
            std::cout <<std::endl;
        }
    }

}

// �������ƣ�void ShellSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ϣ����������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void ShellSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *), void (*Visit)(const ElemType &), OutWay outWay)
{
    // ���ԭʼ����
    if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
    {
        std::cout <<"ԭʼ_���У�";
        for(int pos = 0; pos < length; pos++)
        {
            Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
        }
        std::cout <<std::endl;
    }
    // ����������
    int incr/*Shell����*/, i/*����ÿ�˲����Ĳ������*/, j/*ѭ���ƶ�Ԫ��*/;
    ElemType temp;          // һ����λ�ĸ����ռ�
    for(incr = length / 2; incr >= 1; incr /= 2)          // ����ÿ������������
    {   // ��coun������-=>����Ϊincr
        for(i = incr; i < length; i++)      // ����ÿ�˲����Ĳ������
        {   // ÿ������Ĳ������
            temp = elem[i];
            for(j = i - incr; j >= 0 && Comp(&temp, &elem[j]); j -= incr)     // Ѱ�Ҳ���λ��
            {   // �����������λ��Ҫ���Ԫ�����κ���
                elem[j + incr] = elem[j];
            }
            elem[j + incr] = temp;      // ��Ԫ�ز���
        }
            // ���ԭʼ����
        if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
        {
            std::cout <<"��ǰ����" <<incr <<"��";
            for(int pos = 0; pos < length; pos++)
            {
                Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
            }
            std::cout <<std::endl;
        }
    }
}




/// ð�������㷨
// �������ƣ�void BubbleSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ���������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void BubbleSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *),  void (*Visit)(const ElemType &), OutWay outWay)
{
    // ���ԭʼ����
    if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
    {
        std::cout <<"ԭʼ_���У�";
        for(int pos = 0; pos < length; pos++)
        {
            Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
        }
        std::cout <<std::endl;
    }
    int j/*����ÿ��ѭ��*/, i/*�����������ݵıȽ�ѭ��*/;
    bool flag = true;           // ������ɵı�־
    // �������
    for(i = 1; i < length; i++)        // ���ƽ���length-1��ѭ��
    {
        flag = false;           // ��ʼĬ�������������
        for(j = 0; j < (length - i) && flag == true; j++)   // ÿ��ѭ���Ƚ�length-1-j��
        {
            if(Comp(&elem[j], &elem[j+1]) == true)    // �����ǰ��Ԫ�����һ��Ԫ�ز������������
            {
                swap(elem[j], elem[j+1]);
                flag = true;                // ��Ȼ��Ҫ����˵��, ��Ȼ����
            }
        }
        // �����������е�������Ϣ
        if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
        {
            std::cout <<"��" <<i  <<"��ѭ����";
            for(int pos = 0; pos < length; pos++)
            {
                Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
            }
            std::cout <<std::endl;
        }
    }
}

// �������ƣ�void BubbleUpSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ�������������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void BubbleUpSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *),  void (*Visit)(const ElemType &), OutWay outWay)
{
    // ���ԭʼ����
    if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
    {
        std::cout <<"ԭʼ_���У�";
        for(int pos = 0; pos < length; pos++)
        {
            Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
        }
        std::cout <<std::endl;
    }
    int j/*����ÿ��ѭ��*/, i/*�����������ݵıȽ�ѭ��*/;
    // �������
    for(i = 1; i < length; i++)        // ���ƽ���length-1��ѭ��
    {
        for(j = length - i; j > 0; j--)   // ÿ��ѭ���Ƚ�length-1-j��
        {
            if(Comp(&elem[j-1], &elem[j]) == true)    // �����ǰ��Ԫ�����һ��Ԫ�ز������������
            {
                swap(elem[j], elem[j-1]);
            }

        }
        // �����������е�������Ϣ
        if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
        {
            std::cout <<"��" <<i  <<"��ѭ����";
            for(int pos = 0; pos < length; pos++)
            {
                Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
            }
            std::cout <<std::endl;
        }
    }
}
// �������ƣ�void BubbleDownSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ��³���������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void BubbleDownSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *),  void (*Visit)(const ElemType &), OutWay outWay)
{
        // ���ԭʼ����
    if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
    {
        std::cout <<"ԭʼ_���У�";
        for(int pos = 0; pos < length; pos++)
        {
            Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
        }
        std::cout <<std::endl;
    }
    int j/*����ÿ��ѭ��*/, i/*�����������ݵıȽ�ѭ��*/;
    // �������
    for(i = 1; i < length; i++)        // ���ƽ���length-1��ѭ��
    {
        for(j = 0; j < (length - i); j++)   // ÿ��ѭ���Ƚ�length-1-j��
        {
            if(Comp(&elem[j], &elem[j+1]) == true)    // �����ǰ��Ԫ�����һ��Ԫ�ز������������
            {
                swap(elem[j], elem[j+1]);
            }

        }
        // �����������е�������Ϣ
        if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
        {
            std::cout <<"��" <<i  <<"��ѭ����";
            for(int pos = 0; pos < length; pos++)
            {
                Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
            }
            std::cout <<std::endl;
        }
    }
}
/// ���������㷨
// �������ƣ�void QuickSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ��򵥲�������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template <class ElemType>
void QuickSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *), OutWay outWay)
{
    if(length > 1)
    {

        int pivot = 0, j;
        for(j = 1; j < length; j++)        // ѭ���������Ͻ��н���
        {
            if(Comp(elem+j, elem + 0) == true)
            {
                swap(elem[++pivot], elem[j]);
            }
        }
        swap(elem[0], elem[pivot]);

        QuickSort(elem, pivot, Comp, outWay);          // �ݹ�����������

        QuickSort(elem + pivot + 1, length - pivot - 1, Comp, outWay); // �ݹ������Ҳ�����

    }
}



/// ��ѡ�������㷨
// �������ƣ�void BubbleSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ���������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void SelectSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *), void (*Visit)(const ElemType &), OutWay outWay)
{
    // ���ԭʼ����
    if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
    {
        std::cout <<"ԭʼ_���У�";
        for(int pos = 0; pos < length; pos++)
        {
            Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
        }
        std::cout <<std::endl;
    }
    int i, j, index;
    for(i = 0; i < length - 1; i++)     // ѭ��ÿ������
    {
        index = i;
        for(j = i + 1; j < length; j++)
        {
            if(Comp(elem + j, elem + index) == true)
            {
                index  = j;     // �ҵ���ǰ��ֵԪ�ص��±�
            }
        }
        if(index != i)
        {
            swap(elem[i], elem[index]);     // ����ֵ���浽Ӧ�������λ��
        }
        // ���ԭʼ����
        if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
        {
            std::cout <<"��" <<i <<"������";
            for(int pos = 0; pos < length; pos++)
            {
                Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
            }
            std::cout <<std::endl;
        }
    }
}


/// �����������㷨
// �������ƣ�void BubbleSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ���������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template <class ElemType>
void SiftAdjust(ElemType *elem, int low, int high, bool (*Comp)(const void *, const void *))
{
    for(int f = low, i = 2*low+1; i <= high; i = 2*i+1)
    {   // fΪ�����������ĸ����, i��ʼ��Ϊ������, Ȼ��ݹ�������Ӷ�ɸѡ,
        if(i < high && Comp(elem + i, elem + i + 1) == true)
        {       // iָ��f���Ӻ��Һ����нϴ���Ǹ�
            i++;
        }
        if(Comp(elem + f, elem + i) == false)
        {
            break;
        }

        swap(elem[f], elem[i]);

        f = i;          // ���浱ǰ���ڵ��λ��
    }
}

template<class ElemType>
void HeapSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *),  void (*Visit)(const ElemType &), OutWay outWay)
{
    // ���ԭʼ����
    if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
    {
        std::cout <<"ԭʼ_���У�";
        for(int pos = 0; pos < length; pos++)
        {
            Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
        }
        std::cout <<std::endl;
    }
    int i;
    for(i = (length-2)/2; i >= 0; i--)      // ���Ƚ���һ����
    {
        SiftAdjust(elem, i, length - 1, Comp);
    }
    // ���ԭʼ����
    if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
    {
        std::cout <<"����_���У�";
        for(int pos = 0; pos < length; pos++)
        {
            Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
        }
        std::cout <<std::endl;
    }
    for(i = length - 1; i > 0; i--)
    {
        swap(elem[0], elem[i]);     // ���Ѷ���Ԫ�غ����һ��[i]Ԫ�齻��
        // ���ԭʼ����
        if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
        {
            std::cout <<"����_���У�";
            for(int pos = 0; pos < length; pos++)
            {
                Visit(elem[pos]);             // ��ӡÿ����¼��Ϣ
            }
            std::cout <<std::endl;
        }
        SiftAdjust(elem, 0, i-1, Comp);
    }
}


/// �鲢�����㷨
// �������ƣ�void BubbleSort(ElemType , int , bool (*Comp)(  ), OutWay);
// �������ܣ�ð�ݷ���������
// elem�����������, length����������ĳ���, Comp( )���ݱȽϺ���,
template<class ElemType>
void MergeSort(ElemType *elem, int length, bool (*Comp)(const void *, const void *), OutWay outWay)
{
    ElemType *tempElem = new ElemType[length];      // ������ʱ����ռ�

    MergeSort(elem, tempElem, 0, length - 1, Comp, outWay);       // �鲢�������

    delete[] tempElem;                              // ɾ����ʱ����ռ�
}


// �������ƣ�MergeSort
// �������ܣ����ø�������ռ�tempElem��Elem����low��highλ�õ����ݽ�������
template <class ElemType>
void MergeSort(ElemType *elem, ElemType *tempElem, int low, int high, bool (*Comp)(const void *, const void *), OutWay outWay)
{
    if(low < high)
    {
        int mid = (low + high) / 2;                 // ������������ֳ�[low, mid]��[mid + 1, high]����������������

        MergeSort(elem, tempElem, low, mid, Comp, outWay);        // ��elem[low, mid]���й鲢����
        MergeSort(elem, tempElem, mid + 1, high, Comp, outWay);   // ��elem[mid + 1, high]���й鲢����

        Merge(elem, tempElem, low, mid, high, Comp);      // �����������������й鲢Ϊһ������

        if(outWay == STEP)
        {
            for(int pos = 0; pos < SIZE; pos++)
            {
                std::cout <<std::setw(4) <<elem[pos];
            }
            std::cout <<std::endl;
        }
    }
}


// �������ƣ�Merge
// �������ܣ������������������[low, mid]��[mid+1, high]�鲢Ϊ�µ�
template <class ElemType>
void Merge(ElemType *elem, ElemType *tempElem, int low, int mid, int high, bool (*Comp)(const void *, const void *))
{
    int i, j, k;

    for(i = low,j = mid + 1, k = low;   // �ϲ�[i, k] -=>[low, mid]    AND    �ϲ�[j, high] -=> [mid + 1, high]
        i <= mid && j <= high;
        k++)
    {
       if(Comp(elem + i, elem +j))          // elem[i]��С�Ļ����Ⱥϲ�
        //if(elem[i] <= elem[j])
        {
            tempElem[k] = elem[i];
            i++;
        }
        else                            // ����elem[j]��С
        {
            tempElem[k] = elem[j];
            j++;
        }
    }

    for( ; i <= mid; i++, k++)           // �鲢elem[low, mid]��ʣ��Ԫ��
    {
        tempElem[k] = elem[i];
    }
    for( ; j <= high; j++, k++)           // �鲢elem[mid+1, high]��ʣ��Ԫ��
    {
        tempElem[k] = elem[j];
    }
    for( i = low; i <= high; i++)      // ��������ʱ�������Ѿ��ϲ�����Ϣ���´浽ԭ����֮��
    {
        elem[i] = tempElem[i];
    }
}



template <class ElemType>
void Distribute(ElemType elem[], int n, int r, int d, int i, LinkList<ElemType> list[])
{
	for (int power = (int)pow((double)r, i - 1), j = 0; j < n; j++)
	{	// ���е�i�����
		int index = (elem[j] / power) % r;
		list[index].Insert(list[index].Length() + 1, elem[j]);
	}
}

template <class ElemType>
void Colect(ElemType elem[], int n, int r, int d, int i, LinkList<ElemType> list[], OutWay outWay)
{
	for (int k = 0, j = 0; j < r; j++)
	{	// ���е�i�����
		ElemType tmpElem;
		while (!list[j].Empty())
		{	// �ռ�list[j]
			list[j].Delete(1, tmpElem);
			elem[k++] = tmpElem;
		}
        if(outWay == STEP)
        {
            for(i = 0; i < n; i++)
            {
                std::cout <<std::setw(4)<<elem[i];
            }
            std::cout <<std::endl;
        }
	}
}

template <class ElemType>
void RadixSort(ElemType elem[], int n, int r, int d, OutWay outWay)
{
	LinkList<ElemType> *list;	// ���ڴ洢����������Ա�����
	list = new LinkList<ElemType>[r];
	for (int i = 1; i <= d; i++)
	{	// ��i�˷������ռ�
		Distribute(elem, n, r, d, i, list);	// ����
		Colect(elem, n, r, d, i, list, outWay);		// �ռ�
	}
	delete []list;
}




template <class ElemType>
int Partition(ElemType elem[], int low, int high)
// �������:����elem[low .. high]�е�Ԫ��,ʹ�����ƶ����ʵ���,Ҫ��������֮ǰ��Ԫ��
//	����������,������֮���Ԫ�ز�С�������,�����������λ��

{
	while (low < high)
	{
		while (low < high && elem[high] >= elem[low])
		{	// elem[low]Ϊ����,ʹhigh�ұߵ�Ԫ�ز�С��elem[low]
			high--;
		}
		swap(elem[low], elem[high]);

		while (low < high && elem[low] <= elem[high])
		{	// elem[high]Ϊ����,ʹlow��ߵ�Ԫ�ز�����elem[high]
			low++;
		}
		swap(elem[low], elem[high]);
	}
	return low;	// ��������λ��
}

// �������ƣ�Quick_Sort_Help(ElemType *elem, int low, int high)
// �������:������elem[low .. high]�еļ�¼���п�������
template <class ElemType>
void Quick_Sort_Help(ElemType *elem, int low, int high, OutWay outWay)
{
	if (low < high)
	{
		int pivotLoc = Partition(elem, low, high);	// ����һ�˻���
		Quick_Sort_Help(elem, low, pivotLoc - 1, outWay);		// ���ӱ�elem[low, pivotLoc - 1]�ݹ�����
		Quick_Sort_Help(elem, pivotLoc + 1, high, outWay);	// ���ӱ�elem[pivotLoc + 1, high]�ݹ�����
	}
    if(outWay == STEP)     // ���ϵͳҪ�󵥲����������Ϣ
    {
        for(int i = 0; i < SIZE; i++)
        {
            std::cout <<std::setw(4)<<elem[i];
        }
        std::cout <<std::endl;
    }
}

// �������ƣ�Quick_Sort_Help(ElemType *elem, int low, int high)
// �������:������elem���п�������
template <class ElemType>
void Quick_Sort(ElemType *elem, int n, OutWay outWay)
{
	Quick_Sort_Help(elem, 0, n - 1, outWay);
}


#endif // SORT_H_INCLUDE
