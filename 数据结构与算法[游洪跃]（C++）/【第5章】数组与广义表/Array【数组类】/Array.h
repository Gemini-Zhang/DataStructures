/**
******************************************************************************
*  Copyright  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : Array.h                                                      *
*  Description: ������ͷ�ļ�                                                *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 25/10/12 17:20                                              *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/

#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED


#include "Error.h"
// ������ģ��
template <class ElemType>
class Array
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // �����������ͷ��������Լ����ر༭ϵͳĬ�Ϸ�������
    Array(int dim,...);       // ��ά��dim�����ĸ���ά�ȳ��ȹ�������

    Array(const Array<ElemType> &copy);     // ���ƹ��캯��

    ~Array( );                  // ��������ģ��

    Array<ElemType> &operator=(const Array<ElemType> &copy);    // ���ظ�ֵ�����

    ElemType &operator()(int sub,...);     // ���غ��������
/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*=========================��PROTECTED��������Ա��===========================*/
  protected :       // �������ݳ�Ա
    ElemType *m_arr;        // ������׵�ַ
    int m_dim;              // �����ά��
    int *m_bounds;          // �����ά�ĳ���
    int *m_constants;       // ����ӳ��������

    // ����������Ա
    int Locate(int sub, va_list &va);       // ��Ԫ����˳��洢�е�λ��
/*=========================��PROTECTED����������Ա��=========================*/
};


/**������Ա����[ʵ��]*********************************************************
int Locate(int sub, va_list &va);       // ��Ԫ����˳��洢�е�λ��
*********************************************************[ʵ��]������Ա����**/
// ��Ԫ����˳��洢�е�λ��
int Array<ElemTYpe>::Locate(inr sub, va_list &va)
{
    if(sub >= 0 && sub < m_bounds)
    {
        throw Error("�±����!");   // �׳��쳣
    }

    int off = m_constants[0]*sub;   // ��ʼ��Ԫ����˳��洢�е�λ��

}

/**������Ļ�����Ա����[ʵ��]*************************************************
    Array(int dim,...);       // ��ά��dim�����ĸ���ά�ȳ��ȹ�������
    Array(const Array<ElemType> &copy);     // ���ƹ��캯��
    ~Array( );                  // ��������ģ��
*************************************************[ʵ��]������Ļ�����Ա����**/
// �������ƣ�Array(int dim,...);
// �����������ά��dim�����ĸ�ά���ȹ���һ���µ�����
template <class ElemType>
Array<ElemType>::Array(int dim,...)     // ��ά��dim�����ĸ���ά�ȳ��ȹ�������
{
    if(dim < 1)
    {
        throw Error("����Arrayά�Ȳ���С��1!"); // �׳��쳣
    }

    m_dim = dim;    // ����ά��
    m_bounds = new int[dim];        // ����ռ�洢ÿ��ά�ȵĵĳ�����Ϣ
    va_list va;                 // �䳤��������
    int elemTotal = 1;      // Ԫ������������
    int i;                  // ѭ������

    va_start(va, dim);    // ��ʼ���䳤��������va, ���ڴ洢�䳤��������Ϣ, dimΪʡ�Ժ�������ұߵĲ�����ʶ

    for(i = 0; i < m_dim; i++)
    {   // Ϊ��ά���ȸ�ֵ������������Ԫ�ظ���
        m_bounds[i] = va_arg(va, int);      // ȡ���䳤������Ϊ��ά����
        elemTotal *= m_bounds[i];           // ͳ�������е���Ԫ�ظ���
    }
    va_end(va);     // �����䳤����������

    m_arr = new ElemType[elemTotal];    // ����������ڴ�ռ�

    m_constants =  new int[m_dim];      // ���亯��ӳ�䳣�����ڴ�ռ�
    // ��������Ӱ�亯������
    m_constants[m_dim-1] = 1;
    for(i = m_dim-2; i >= 0; i--)
    {
        m_constants[i] = m_bounds[i+1] * m_constants[i+1];  //
    }
}

// �������ƣ�Array(const Array<ElemType> &copy);
// ���������������copy����������, ���ƹ��캯��ģ��
Array<ElemType>::Array(const Array<ElemType> &copy)    // ���ƹ��캯��
{
    m_dim = copy.m_dim;

    int elemTotal = 1;      //  ����Ԫ������
    int i;                  //  ѭ������

    m_bounds = new int[m_dim];      // ���ٴ洢��ά���ݵ��ڴ�ռ�
    m_constants = new int[m_dim];   // �洢����ӳ�亯���������ڴ�ռ�
    for(i = 0; i < m_dim; i++)
    {   // ͳ��������Ԫ��
        m_bounds[i] = copy.m_bounds[i];         // ����ά�ĳ���
        m_constants[i] = copy.m_constants[i];   // ����ӳ�亯������

        elemTotal *= m_bounds[i];       // ����������Ԫ�صĳ���
    }

    m_arr = new ElemType[elemTotal];        // ������ڴ�ռ�
    for(i = 0; i < elemTotal; i++)      // ����Ϊÿ��Ԫ�ظ�ֵ
    {
        m_arr[i] = copy.m_arr[i];
    }
}


// �������ƣ�~Array( );
// �����������������Ķ���ռ�
template <class ElemType>
Array<ElemType>::~Array( )
{
    if(m_arr != NULL)       // �ͷ������ڴ�ռ�
    {
        delete[] m_arr;
    }
    if(m_bounds != NULL)        // ɾ����ά�ȳ��ȵĴ洢��Ϣ
    {
        delete[] m_bounds;
    }
    if(m_constants != NULL)     // ɾ��ӳ�亯�������ռ�
    {
        delete[] m_constants;
    }
}

/**�����������Ա������Ա[ʵ��]**************************************************
    Array<ElemType> &operator=(const Array<ElemType> &copy);    // ���ظ�ֵ�����
    ElemType &operator()(int sub,...);     // ���غ��������
**************************************************[ʵ��]�����������Ա������Ա**/
// �������ƣ�Array<ElemType> &operator=(const Array<ElemType> &copy);
// ���������
Array<ElemType>& Array<ElemType>::operator=(const Array<ElemType> &copy)
{
    if(&copy != this)
    {
        if(m_arr != NULL)       // �ͷ������ڴ�ռ�
        {
            delete[] m_arr;
        }
        if(m_bounds != NULL)        // ɾ����ά�ȳ��ȵĴ洢��Ϣ
        {
            delete[] m_bounds;
        }
        if(m_constants != NULL)     // ɾ��ӳ�亯�������ռ�
        {
            delete[] m_constants;
        }

        m_dim = copy.m_dim;

        int elemTotal = 1;      //  ����Ԫ������
        int i;                  //  ѭ������

        m_bounds = new int[m_dim];      // ���ٴ洢��ά���ݵ��ڴ�ռ�
        m_constants = new int[m_dim];   // �洢����ӳ�亯���������ڴ�ռ�
        for(i = 0; i < m_dim; i++)
        {   // ͳ��������Ԫ��
            m_bounds[i] = copy.m_bounds[i];         // ����ά�ĳ���
            m_constants[i] = copy.m_constants[i];   // ����ӳ�亯������

            elemTotal *= m_bounds[i];       // ����������Ԫ�صĳ���
        }

        m_arr = new ElemType[elemTotal];        // ������ڴ�ռ�
        for(i = 0; i < elemTotal; i++)      // ����Ϊÿ��Ԫ�ظ�ֵ
        {
            m_arr[i] = copy.m_arr[i];
        }
    }

    return (*this);
}
#endif // ARRAY_H_INCLUDED
