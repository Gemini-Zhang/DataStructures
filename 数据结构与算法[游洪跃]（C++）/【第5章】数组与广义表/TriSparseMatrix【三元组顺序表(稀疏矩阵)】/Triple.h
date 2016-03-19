/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : TriSparseMatrix.cpp                                            *
*  Description: ��Ԫ��˳���[ϡ�����]��TriSparseMatrixԴ�ļ�               *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 23/10/12 10:23                                               *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/


#ifndef TRIPLE_H_INCLUDED
#define TRIPLE_H_INCLUDED


#include <iostream>

/// ��Ԫ����ģ����������
template <class ElemType>
class Triple
{
//  friend istream &operator>>(istream &in, Triple<ElemType> &triple);
//  friend ostream &operator<<(ostream &in, const Triple<ElemType> &triple);
  public :
    // ��Ԫ�����Ա����ģ��
    Triple( );                       // Ĭ�Ϲ��캯��

    Triple(int row, int col, const ElemType &data); // �������Ĺ��캯��

    Triple &operator=(const Triple<ElemType> &copy); // ����=������

    void SetTriple(int row, int col, const ElemType &elem);     // ������Ԫ��������Ϣ

    bool IsThisPoint(int row, int col);             // �жϵ�ǰ��Ԫ�ص�λ����Ϣ�Ƿ�Ϊrow��col��
    // ���ݳ�Ա
    int m_row, m_col;           // ��0Ԫ�ص������row��������
    ElemType m_data;           // ��0Ԫ�ص�ֵ
};



/// ��Ԫ����ģ��ʵ�ֲ���
/**��Ԫ�����Ա����ģ��[ʵ��]*********************************************************
    Triple( );                       // Ĭ�Ϲ��캯��
    Triple(int row, int col, const ElemType &data); // �������Ĺ��캯��
    Triple &operator=(const Triple<ElemType> &copy); // ����=������
    void SetTriple(int row, int col, const ElemType &elem);     // ������Ԫ��������Ϣ
    bool IsThisPoint(int row, int col);             // �жϵ�ǰ��Ԫ�ص�λ����Ϣ�Ƿ�Ϊrow��col��
*********************************************************[ʵ��]��Ԫ�����Ա����ģ��**/
// �������ƣ�Triple( );
// ��������������յ���Ԫ�����
template <class ElemType>
Triple<ElemType>::Triple( )                        // Ĭ�Ϲ��캯��
{
}

// �������ƣ�Triple(int row, int col, const ElemType &data);
// ��������������յ���Ԫ�����
template <class ElemType>
Triple<ElemType>::Triple(int row, int col, const ElemType &data) // �������Ĺ��캯��
{
    m_row = row;
    m_col = col;
    m_data = data;
}

// �������ƣ�Triple &operator=(const Triple<ElemType> &copy);
// ��������������յ���Ԫ�����
template <class ElemType>
Triple<ElemType>& Triple<ElemType>::operator=(const Triple<ElemType> &copy) // ����=������
{
    m_row = copy.m_row;
    m_col = copy.m_col;
    m_data = copy.m_data;

    return (*this);
}

// �������ƣ�void SetTriple(int row, int col, const ElemType &elem);
// ���������������Ԫ���������Ϣ
template <class ElemType>
void Triple<ElemType>::SetTriple(int row, int col, const ElemType &elem)
{
    m_row = row;
    m_col = col;
    m_data = elem;      // ��ҪElemType���͵�����֧��=����������
}

// �������ƣ�bool IsThisPoint(int row, int col)
// ����������жϵ�ǰ��Ԫ�ص�λ����Ϣ�Ƿ�Ϊrow��col��
template <class ElemType>
bool Triple<ElemType>::IsThisPoint(int row, int col)     // �жϵ�ǰ��Ԫ�ص�λ����Ϣ�Ƿ�Ϊrow��col��
{
    return (m_row == row && m_col == col);
}

#endif // TRIPLE_H_INCLUDED
