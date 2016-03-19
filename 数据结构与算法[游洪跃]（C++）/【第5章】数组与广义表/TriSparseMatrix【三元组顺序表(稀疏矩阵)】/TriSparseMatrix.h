/**
******************************************************************************
*  Copymatrix  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : TriSparseMatrix<ElemType>.h                                  *
*  Description: ��Ԫ��˳���[ϡ�����]��TriSparseMatrix<ElemType>ͷ�ļ�     *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 23/10/12 10:23                                               *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/

#ifndef TRISPARSEMATRIX_H_INCLUDED
#define TRISPARSEMATRIX_H_INCLUDED


#include "Triple.h"


#define  ROW_SIZE  10
#define  COL_SIZE  10
#define  NUM_SIZE   0


/// ��Ԫ��˳���[ϡ�����]��TriSparseMatrix<ElemType>��������
template <class ElemType>
class TriSparseMatrix       /// ��ͷ���
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // ��Ԫ��˳���[ϡ�����]�������Ա����
    TriSparseMatrix(int rows = ROW_SIZE, int cols = COL_SIZE, int size = NUM_SIZE);// ���캯��

    TriSparseMatrix(const TriSparseMatrix<ElemType> &copy);     // ���ƹ��캯��

    virtual ~TriSparseMatrix( );

    TriSparseMatrix<ElemType> &operator=(const TriSparseMatrix<ElemType> &copy);
    // ��Ԫ��˳���[ϡ�����]��������Ա����
    int Rows( ) const;       // ��ȡϡ����������

    int Cols( ) const;       // ��ȡϡ����������

    int Size( ) const;       // ��ȡϡ������Ԫ�ظ���

    Triple<ElemType> GetTriple(int index);      // ��ȡ��index����Ԫ�����Ϣ

    bool IsTripleIn(int row, int col) const;        // �жϵ�ǰλ���Ƿ���������,Ҳ���ǵ�ǰλ�������Ƿ�Ϊ0

    void SetMatrix(int rows, int cols);       // �������õ�ǰ�������Ϣ

    bool SetElem(int row, int col, const ElemType &elem);  // ���ö�Ӧrow��col��Ԫ�ص�ֵ

    bool GetElem(int row, int col, ElemType &elem) const;     // ��ȡ��Ӧrow��col��Ԫ�ص�ֵ

    // ϡ�����ת�ú�������
    static void SimpleTranspose(TriSparseMatrix<ElemType> &dest, const TriSparseMatrix<ElemType> &source);
    static void FastTranspose(TriSparseMatrix<ElemType> &dest, const TriSparseMatrix<ElemType> &source);

    TriSparseMatrix<ElemType> operator+(const TriSparseMatrix<ElemType> &matrix);
    TriSparseMatrix<ElemType> operator-(const TriSparseMatrix<ElemType> &matrix);
    // ���ؾ���ļӼ�������
    //friend TriSparseMatrix<ElemType> operator+(const TriSparseMatrix<ElemType> &this, const TriSparseMatrix<ElemType> &right);
    //friend TriSparseMatrix<ElemType> operator-(const TriSparseMatrix<ElemType> &this, const TriSparseMatrix<ElemType> &right);
/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*=========================��PROTECTED��������Ա��===========================*/
  protected :
    // ��Ԫ��˳���[ϡ�����]�����ݳ�Ա
    int m_rows, m_cols, m_size;         // ϡ����������, �����Լ���0Ԫ�صĸ���
    int m_maxSize;                    // ϡ���������Ԫ�ظ���
    Triple<ElemType> *m_triElems;   // �洢ϡ�����Ԫ�ص���Ԫ�������ַ
/*=========================��PROTECTED����������Ա��=========================*/
};



/// ��Ԫ��˳���[ϡ�����]��TriSparseMatrix<ElemType>ʵ�ֲ���
/**��Ԫ��˳���[ϡ�����]�������Ա����[ʵ��]************************************************
    TriSparseMatrix<ElemType>(int rows = ROW_SIZE, int cols = COL_SIZE, int size = NUM_SIZE);// ���캯��
    TriSparseMatrix<ElemType>(const TriSparseMatrix<ElemType> &copy);     // ���ƹ��캯��
    virtual ~TriSparseMatrix<ElemType>( );
    TriSparseMatrix<ElemType> &operator=(const TriSparseMatrix<ElemType> &copy);
************************************************[ʵ��]��Ԫ��˳���[ϡ�����]�������Ա����**/

// �������ƣ�TriSparseMatrix<ElemType>(int rows = ROW_SIZE, int cols = COL_SIZE, int size = NUM_SIZE);
// �������������һ���µ�ϡ��������
template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(int rows/* = ROW_SIZE*/, int cols/* = COL_SIZE*/, int size/* = NUM_SIZE*/) // ���캯��
{
    m_rows = rows;
    m_cols = cols;
    m_maxSize = m_rows * m_cols;
    m_size = 0;         // Ԫ�ظ���Ϊ0

    m_triElems = new Triple<ElemType>[m_maxSize];        // �����ڴ�ռ�
}

// �������ƣ�TriSparseMatrix<ElemType>(const TriSparseMatrix<ElemType> &copy);
// �������������һ���µ�ϡ��������
template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(const TriSparseMatrix<ElemType> &copy) // ���ƹ��캯��
{
    m_rows = copy.m_rows;
    m_cols = copy.m_cols;
    m_size = copy.m_size;
    m_maxSize = m_rows * m_cols;        // ȷ������Ԫ�ظ���

    m_triElems = new Triple<ElemType>[copy.m_maxSize];        // �����ڴ�ռ�

    for(int position = 1; position <= m_size; position++)   // ȷ��ÿ����Ԫ��Ԫ�ص���Ϣ
    {
        m_triElems[position] = copy.m_triElems[position];
    }
}

// �������ƣ�virtual ~TriSparseMatrix<ElemType>( );
// ������������ٶ������Ϣ
template <class ElemType>
TriSparseMatrix<ElemType>::~TriSparseMatrix( )
{
    if(m_triElems != NULL)
    {
        delete[] m_triElems;
    }
}

// �������ƣ�TriSparseMatrix<ElemType> &operator=(const TriSparseMatrix<ElemType> &copy);
// �������������=
template <class ElemType>
TriSparseMatrix<ElemType>& TriSparseMatrix<ElemType>::operator=(const TriSparseMatrix<ElemType> &copy)
{
    m_rows = copy.m_rows;
    m_cols = copy.m_cols;
    m_size = copy.m_size;
    m_maxSize = m_rows * m_cols;
    if(m_triElems != NULL)  // �����ǰĿ�Ķ����Ѿ������ʿռ�ɾ��ԭ�еĿռ�
    {
        delete[] m_triElems;
    }
    m_triElems = new Triple<ElemType>[copy.m_maxSize];        // ���¿����ڴ�ռ�

    for(int position = 0; position < m_size; position++)   // ȷ��ÿ����Ԫ��Ԫ�ص���Ϣ
    {
        m_triElems[position] = copy.m_triElems[position];
    }

    return (*this);
}


/**��Ԫ��˳���[ϡ�����]��������Ա����[ʵ��]************************************************
    int Rows( ) const;       // ��ȡϡ����������
    int Cols( ) const;       // ��ȡϡ����������
    int Size( ) const;       // ��ȡϡ������Ԫ�ظ���
    Triple<ElemType> GetTriple(int index);      // ��ȡ��index����Ԫ�����Ϣ
    bool SetMatrix(int rows, int cols, int size);       // �������õ�ǰ�������Ϣ
    bool SetElem(int row, int col, const ElemType &elem);  // ���ö�Ӧrow��col��Ԫ�ص�ֵ
    bool GetElem(int row, int col, ElemType &elem);     // ��ȡ��Ӧrow��col��Ԫ�ص�ֵ
************************************************[ʵ��]��Ԫ��˳���[ϡ�����]��������Ա����**/

// �������ƣ�int Rows( ) const;
// �����������ȡϡ����������
template <class ElemType>
int TriSparseMatrix<ElemType>::Rows( ) const      // ��ȡϡ����������
{
    return m_rows;
}

// �������ƣ�int Cols( ) const;
// �����������ȡϡ����������
template <class ElemType>
int TriSparseMatrix<ElemType>::Cols( ) const      // ��ȡϡ����������
{
    return m_cols;
}

// �������ƣ�int Size( ) const;
// �����������ȡϡ������Ԫ�ظ���
template <class ElemType>
int TriSparseMatrix<ElemType>::Size( ) const      // ��ȡϡ������Ԫ�ظ���
{
    return m_size;
}

// �������ƣ�Triple<ElemType> GetTriple(int index);
// �����������ȡ��index����Ԫ�����Ϣ
template <class ElemType>
Triple<ElemType> TriSparseMatrix<ElemType>::GetTriple(int index)      // ��ȡ��index����Ԫ�����Ϣ
{
    return m_triElems[index-1];
}

// �������ƣ�SetMatrix(int rows, int cols, int size/*= NOT_DEFINE*/) const
// �������������ԭ��������к�Ԫ�ظ�����Ϣ,
//           �����ǰ����size����Ĭ����Ĭ��ֻ������������
template <class ElemType>
void TriSparseMatrix<ElemType>::SetMatrix(int rows, int cols)     // ��ȡϡ������Ԫ�ظ���
{
    m_rows = rows;
    m_cols = cols;
    m_size = 0;
    m_maxSize = m_rows * m_cols;

    if(m_triElems != NULL)
    {
        delete[] m_triElems;    // ɾ��ԭ�пռ�
    }
    m_triElems = new Triple<ElemType>[m_maxSize];
}

template <class ElemType>
bool TriSparseMatrix<ElemType>::IsTripleIn(int row, int col) const       // �жϵ�ǰλ���Ƿ���������,Ҳ���ǵ�ǰλ�������Ƿ�Ϊ0
{
//    int i;
//     �����жϵ�ǰ����λ���Ƿ�������Ԫ��������
//    for(i = 0; i < m_size; i++)
//    {
//        if(m_triElems[i].IsThisPoint(row, col) == true)     // ���ҵ���ǰ��Ϣ����λ
//        {
//            return true;
//        }
//    }
//    return false;
    int j;
    // ����ѭ���жϵ�ǰ����Ϊ[row, col]�Ƿ��Ѿ�����ԭ��Ԫ��������
    for(j = m_size-1; j >= 0
                   && (row <= m_triElems[j].m_row && col < m_triElems[j].m_col); j--);

    // ��ѭ������ʱ, �����ԭ��Ԫ���������ҵ���ָ��λ�õ���Ԫ��
    if(j >= 0 && row == m_triElems[j].m_row && col == m_triElems[j].m_col)
    {
        return true;
    }
    return false;
}


// �������ƣ�bool SetElem(int row, int col, const ElemType &elem);
// ������������ö�Ӧrow��col��Ԫ�ص�ֵ
// �㷨ʵ�֣�����ѭ���жϵ�ǰ����Ϊ[row, col]�Ƿ��Ѿ�����ԭ��Ԫ��������
//           ����������������޸�ԭλ�õ�ֵ, �����ÿպ��޸�
//               ���elem����Ϊ0���ǽ�ԭ����Ϊ���, ��ʱ��Ҫ��Ԫ������Ԫ����������ɾ��
//               ����ֻ��Ҫ�޸����ݼ���
//           �������������Ҳ�����ǰ����λ
template <class ElemType>
bool TriSparseMatrix<ElemType>::SetElem(int row, int col, const ElemType &elem)
{
    // �жϲ����ĺϷ���
    if(row > this->m_rows || col > this->m_cols || row < 1 || col < 1)
    {
        std::cerr <<"��ǰ������" <<row <<"��" <<col <<"�������ô���" <<std::endl;
        return false;
    }

    // ���ԭ��ϡ������ǿյ�, ��Ҫ��������
//    if(m_size == 0)
//    {
//        m_triElems[0] = Triple<ElemType>(row, col, elem);
//        m_size++;
//        return true;
//    }

    int i, j;
    // ����ѭ���жϵ�ǰ����Ϊ[row, col]�Ƿ��Ѿ�����ԭ��Ԫ��������
    for(j = m_size-1; j >= 0
                   && (row <= m_triElems[j].m_row && col < m_triElems[j].m_col); j--);

    // ��ѭ������ʱ, �����ԭ��Ԫ���������ҵ���ָ��λ�õ���Ԫ��
    if(j >= 0 && row == m_triElems[j].m_row && col == m_triElems[j].m_col)
    {

        /// ������һ����ʵ���е�Σ�յ���Ϊ���ǲ���ȷ��ElemType����һ������������elem== 0 ��һ������
        if(elem == 0)   // �����������Ϊ0
        {               // ����Ҫ����ǰλ��Ԫ��ɾ��
            for(i = j+1; i < m_size; i++)   // ������Ԫ������ǰ��
            {
                m_triElems[i-1] = m_triElems[i];
            }
            m_size--;           // ��Ԫ��Ԫ�ظ�������1
            std::cout <<"��ǰλ��[" <<row <<", " <<col <<"]" <<"������Ϣ�Ѿ����" <<std::endl;
        }
        else    // ���������ָ��λ�õ���Ԫ������ֵΪelem
        {
            m_triElems[j].m_data = elem;
            std::cout <<"��ǰλ��[" <<row <<", " <<col <<"]" <<"������Ϣ����" <<std::endl;
        }

        return true;            // �����ɹ�
    }
    else if(elem != 0)      // ����ǰ����λ������Ԫ��������
    {
        if(m_size < m_maxSize)  // ��ǰ��Ԫ������δ��
        {   // ��Ҫ����ǰ����λ����Ϣ������Ԫ��������
            for(i = m_size-1; i > j; i--)       // �������Ԫ�����κ���
            {
                m_triElems[i+1] = m_triElems[i];
            }
            m_triElems[j+1] = Triple<ElemType>(row, col, elem);       // ���뵱ǰ��Ԫ�����Ϣ
            // Ҳ����ִ��m_triElems[i].SetTriple(row, col, elem);
            m_size++;
            std::cout <<"��ǰλ��[" <<row <<", " <<col <<"]" <<"������Ϣ�Ѿ����" <<std::endl;
        }
        else
        {
            std::cerr <<"��ǰϡ�������������, �޷�����������" <<std::endl;
            return false;
        }
    }

    return true;
}

// �������ƣ�bool GetElem(int row, int col, ElemType &elem);
// �����������ȡ��Ӧrow��col��Ԫ�ص�ֵ
template <class ElemType>
bool TriSparseMatrix<ElemType>::GetElem(int row, int col, ElemType &elem) const
{
    // �жϲ����ĺϷ���
    if(row > this->m_rows || col > this->m_cols || row < 1 || col < 1)
    {
        std::cerr <<"��ǰ������" <<row <<"��" <<col <<"�������ô���" <<std::endl;
        return false;
    }

    int i;
    // �����жϵ�ǰ����λ���Ƿ�������Ԫ��������
    for(i = 0; i < m_size; i++)
    {
        if(m_triElems[i].IsThisPoint(row, col) == true)     // ���ҵ���ǰ��Ϣ����λ

        {
            elem =  m_triElems[i].m_data;               // ����Ԫ������
            break;
        }
    }
    if(i == m_size)
    {
        elem = 0;
       // return false;
    }
    return true;
//    int j;
//    // ����ѭ���жϵ�ǰ����Ϊ[row, col]�Ƿ��Ѿ�����ԭ��Ԫ��������
//    for(j = m_size-1; j >= 0
//                   && (row <= m_triElems[j].m_row && col < m_triElems[j].m_col); j--);
//
//    // ��ѭ������ʱ, �����ԭ��Ԫ���������ҵ���ָ��λ�õ���Ԫ��
//    if(j >= 0 && (row == m_triElems[j].m_row && col == m_triElems[j].m_col))
//    {
//        elem = m_triElems[j].m_data;
//        //return true;
//    }
//    else
//    {
//        elem = 0;
//        //return false;
//    }
//    return true;
}

/**ϡ�����ת�ú�������[ʵ��]****************************************************************************
    static void SimpleTranspose(TriSparseMatrix<ElemType> &dest, const TriSparseMatrix<ElemType> &source);
    static void FastTranspose(TriSparseMatrix<ElemType> &dest, const TriSparseMatrix<ElemType> &source);
****************************************************************************ϡ�����ת�ú�������[ʵ��]**/
//�������ƣ�static void SimpleTranspose(TriSparseMatrix<ElemType> &dest, const TriSparseMatrix<ElemType> &source);
//�����������ϡ�����sourceת�ó�ϡ�����dest�ļ򵥷���
//�㷨ʵ�֣�ֻ��Ҫ��ԭ����Ԫ�����Ԫ������Ԫ��λ�û���,
//          ����ϡ�����Ĵ洢��Ԫ���а��б���С��������
template <class ElemType>
/*static*/void TriSparseMatrix<ElemType>::SimpleTranspose(TriSparseMatrix<ElemType> &dest, const TriSparseMatrix<ElemType> &source)
{
    dest.m_rows = source.m_cols;
    dest.m_cols = source.m_rows;
    dest.m_size = source.m_size;
    dest.m_maxSize = source.m_maxSize;

    if(dest.m_triElems != NULL)     // ɾ��Ŀ��ϡ�����ԭ�е��ڴ�ռ�
    {
        delete[] dest.m_triElems;
    }
    dest.m_triElems = new Triple<ElemType>[dest.m_maxSize]; // ���ٿռ�ռ�

    if(dest.m_size > 0)
    {
        int destPos = 0;            // ϡ�����dest����Ԫ����λ��

        for(int col = 1; col <= source.m_cols; col++)       // ѭ��ÿһ�е���Ϣ
        {
            for(int sourcePos = 0; sourcePos < source.m_size; sourcePos++)
            {   // ��Դ�����в���col�е���Ԫ����Ϣ
                if(source.m_triElems[sourcePos].m_col == col)
                {   // �ҵ���col�е���Ԫ����Ϣ
                    dest.m_triElems[destPos].m_row = source.m_triElems[sourcePos].m_col;  // ת�ú������Ϊԭ��������
                    dest.m_triElems[destPos].m_col = source.m_triElems[sourcePos].m_row;  // ת�ú������Ϊԭ��������
                    dest.m_triElems[destPos].m_data = source.m_triElems[sourcePos].m_data;  // ת�ú�Ԫ�ص�����ֵ�����
                    destPos++;          // ��������1
                }
            }
        }
    }
}


//�������ƣ�static TriSparseMatrix<ElemType>::FastTranspose(TriSparseMatrix<ElemType> &dest, const TriSparseMatrix<ElemType> &source)
//�����������ϡ�����sourceת�ó�ϡ�����dest�ļ򵥷���
//�㷨ʵ�֣�ֻ��Ҫ��ԭ����Ԫ�����Ԫ������Ԫ��λ�û���,
//          ����ϡ�����Ĵ洢��Ԫ���а��б���С��������
template <class ElemType>
/*static*/void TriSparseMatrix<ElemType>::FastTranspose(TriSparseMatrix<ElemType> &dest, const TriSparseMatrix<ElemType> &source)
{
    dest.m_rows = source.m_cols;
    dest.m_cols = source.m_rows;
    dest.m_size = source.m_size;
    dest.m_maxSize = source.m_maxSize;

    if(dest.m_triElems != NULL)     // ɾ��Ŀ��ϡ�����ԭ�е��ڴ�ռ�
    {
        delete[] dest.m_triElems;
    }
    dest.m_triElems = new Triple<ElemType>[dest.m_maxSize]; // ���ٿռ�ռ�

    int col;                // ����Ϣ
    int sourcePos, destPos;          // ����ϡ�����source��dest�ı���
    int cNum[dest.m_rows];  //
    int cPos[dest.m_cols];  // cPos[col]=source��col���ϵ�һ����0Ԫ����dest��Ӧ���õ�λ��
    if(dest.m_size > 0)
    {
        for(col = 1; col <= source.m_cols; col++)   // ��ʼ��cNum
        {
            cNum[col] = 0;
        }

        for(sourcePos = 0; sourcePos < source.m_size; sourcePos++)
        {   // ͳ��Դ����source��ÿһ�еķ�0Ԫ�ظ���
            ++cNum[source.m_triElems[sourcePos].m_col];
        }

        cPos[1] = 0;        // ǰһ�еĵ�һ����0Ԫ����dest�洢����ʼλ��

        for(col = 2; col <= source.m_cols; col++)
        {   // ѭ����ÿһ�еĵ�һ����0Ԫ����dest�洢����ʼλ��
            cPos[col] = cPos[col-1] + cNum[col-1];
        }

        for(sourcePos = 0; sourcePos < source.m_size; sourcePos++)
        {   // ѭ������source����Ԫ��
            destPos = cPos[source.m_triElems[sourcePos].m_col];  // ����Ŀ��ϡ�����ĵ�ǰ�洢λ��

            dest.m_triElems[destPos].m_row = source.m_triElems[sourcePos].m_col;    // ת�ú��б���
            dest.m_triElems[destPos].m_col = source.m_triElems[sourcePos].m_row;    // ת�ú��б���
            dest.m_triElems[destPos].m_data = source.m_triElems[sourcePos].m_data;  // ת�ú����ݲ���
        }
    }
}

////�������ƣ�operator+(const TriSparseMatrix<ElemType> &left, const TriSparseMatrix<ElemType> &right)
////�������������+������
//template <class ElemType>
//TriSparseMatrix<ElemType> operator+(const TriSparseMatrix<ElemType> &left, const TriSparseMatrix<ElemType> &right)
//{
//    if(left.m_rows != right.m_rows
//     ||right.m_rows != right.m_cols)
//    {
//        std::cerr <<"�������������ͬ, �޷�����+����" <<std::endl;
//        exit(-2);
//    }
//    ElemType leftElem, rightElem;
//    TriSparseMatrix<ElemType> matrix(left.m_rows, left.m_cols, 0);
//    for(int row = 1; row <= left.m_rows; row++)
//    {
//        for(int col = 1; col <= left.m_cols; col++)
//        {
//            left.GetElem(row, col, leftElem);
//            right.GetElem(row, col, rightElem);
//            matrix.SetElem(row, col, leftElem+rightElem);
//        }
//    }
//
//    return matrix;
//}
//
//
//template <class ElemType>
//TriSparseMatrix<ElemType> operator-(const TriSparseMatrix<ElemType> &left, const TriSparseMatrix<ElemType> &right)
//{
//    if(left.m_rows != right.m_rows
//     ||right.m_rows != right.m_cols)
//    {
//        std::cerr <<"�������������ͬ, �޷�����+����" <<std::endl;
//        exit(-2);
//    }
//    ElemType leftElem, rightElem;
//    TriSparseMatrix<ElemType> matrix(left.m_rows, left.m_cols, 0);
//    for(int row = 1; row <= left.m_rows; row++)
//    {
//        for(int col = 1; col <= left.m_cols; col++)
//        {
//            left.GetElem(row, col, leftElem);
//            right.GetElem(row, col, rightElem);
//            matrix.SetElem(row, col, leftElem-rightElem);
//        }
//    }
//
//    return matrix;
//}

template <class ElemType>
TriSparseMatrix<ElemType> TriSparseMatrix<ElemType>::operator+(const TriSparseMatrix<ElemType> &matrix)
{
    if(this->m_rows != matrix.m_rows
     ||matrix.m_rows != matrix.m_cols)
    {
        std::cerr <<"�������������ͬ, �޷�����+����" <<std::endl;
        exit(-2);
    }
    ElemType thisElem, matrixElem;
    TriSparseMatrix<ElemType> result(this->m_rows, this->m_cols, 0);
    for(int row = 1; row <= this->m_rows; row++)
    {
        for(int col = 1; col <= this->m_cols; col++)
        {
            this->GetElem(row, col, thisElem);
            matrix.GetElem(row, col, matrixElem);
            result.SetElem(row, col, thisElem+matrixElem);
        }
    }

    return result;
}

template <class ElemType>
TriSparseMatrix<ElemType> TriSparseMatrix<ElemType>::operator-(const TriSparseMatrix<ElemType> &matrix)
{
    if(this->m_rows != matrix.m_rows
     ||matrix.m_rows != matrix.m_cols)
    {
        std::cerr <<"�������������ͬ, �޷�����+����" <<std::endl;
        exit(-2);
    }
    ElemType thisElem, matrixElem;
    TriSparseMatrix<ElemType> result(this->m_rows, this->m_cols, 0);
    for(int row = 1; row <= this->m_rows; row++)
    {
        for(int col = 1; col <= this->m_cols; col++)
        {
            this->GetElem(row, col, thisElem);
            matrix.GetElem(row, col, matrixElem);
            result.SetElem(row, col, thisElem-matrixElem);
        }
    }

    return result;
}
#endif // TriSparseMatrix<ElemType>_H_INCLUDED
