/**
*********************************************************************************
*   CopyRight  : 2012-2013, HerBinUnversity, GatieMe                            *
*   File Name  : RefGenList.cpp                                             *
*   Description: ���������������RefGenListͷ�ļ�                      *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2012                                                 *
*   Data_Time  : 20112-10-30 18:43:34                                           *
*   Content    : ���ݽṹ���㷨��C++��������Դ��                               *
*********************************************************************************
**/



#ifndef REFGENLIST_H_INCLUDED
#define REFGENLIST_H_INCLUDED

#include "RefGenListNode.h"

/// ���������������ģ��
template <class ElemType>
class RefGenList
{
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // RefGenList[���������������]�������Ա����
    RefGenList( );      // Ĭ�Ϲ��캯��ģ��

    RefGenList(const RefGenListNode<ElemType> * &head); // ��ͷ���ָ�빹���������������

    RefGenList(const RefGenList<ElemType> &copy);       // ���ƹ��캯��ģ��

    RefGenList<ElemType> &operator=(const RefGenList<ElemType> &copy);  // ����=��ֵ�����

    virtual ~RefGenList( );         // ��������ģ��

    // RefGenList[���������������]������Ա����
    RefGenListNode<ElemType> *First( ) const;       // ���ر�ͷ���������������ĵ�һ��Ԫ�صĽ��

    RefGenListNode<ElemType> *End( ) const;        // ���ر�β��

    RefGenListNode<ElemType> *Next(const RefGenListNode<ElemType> *elemPtr) const;// ����elemPtrָ����������������Ԫ�صĺ��

    bool Empty( ) const;                // �жϵ�ǰ��������������Ƿ�Ϊ��

    int Depth( ) const;             // ���㵱ǰ�����������������

    void Input( ) const;              // ��������

    void Show( ) const;             // ��������

    void Push(const ElemType &elem);        // ��ԭ��Ԫ��elem��Ϊ��ͷ���뵽���������������ǰ��

    void Push(const RefGenList<ElemType> &subList); // ���ӱ�subList��Ϊ��ͷ���뵽���������������ǰ��

/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*=========================��PROTECTED��������Ա��===========================*/
  protected :   // ������Ա
    // RefGenList[���������������]�����ݳ�Ա
    RefGenListNode<ElemType> *m_head;     // ��������������ͷָ��

    // ������Ա����ģ��
    void ShowHelp(RefGenListNode<ElemType> * &head) const;    // ��ʾ��headΪͷ�����������������

    int DepthHelp(const RefGenListNode<ElemType> * &head) const;    // ������headΪ��ͷ�������������������

    void ClearHelp(RefGenListNode<ElemType> * &head); // �ͷ���headΪ�н������������������Է����ڴ�ռ�

    void CopyHelp(const RefGenListNode<ElemType> *sourceHead,
                  const RefGenListNode<ElemType> * &destHead);  // ����destHeadΪͷ������������������Ƴ���sourceHeadΪͷ�����������������

    void CreateHelp(RefGenListNode<ElemType> * &first); // ������firstΪͷ�����������������
/*=========================��PROTECTED����������Ա��=========================*/
};



/**������Ա����ģ��[ʵ��]************************************************************************
    void ShowHelp(RefGenListNode<ElemType> *head) const;    // ��ʾ��headΪͷ�����������������
    int DepthHelp(const RefGenListNode<ElemType> *head);    // ������headΪ��ͷ�������������������
    void ClearHelp(RefGenListNode<ElemType> *head); // �ͷ���headΪ�н������������������Է����ڴ�ռ�
    void CopyHelp(const RefGenListNode<ElemType> *sourceHead,
                  const RefGenListNode<ElemType> * &destHead);  // ����destHeadΪͷ������������������Ƴ���sourceHeadΪͷ�����������������
    void CreateHelp(RefGenListNode<ElemType> * &first); // ������firstΪͷ�����������������
************************************************************************[ʵ��]������Ա����ģ��**/
// �������ƣ�void ShowHelp(RefGenListNode<ElemType> *head) const;
// �������ܣ���������:void Show( ) const�ĸ�������
// �����������ʾ�����headΪͷ�����������������
template <class ElemType>
void RefGenList<ElemType>::ShowHelp(RefGenListNode<ElemType> * &head) const     // ��ʾ��headΪͷ�����������������
{
}

// �������ƣ�int DepthHelp(const RefGenListNode<ElemType> *head);    // ������headΪ��ͷ�������������������
// �������ܣ����㵱ǰ�����������������:int Depth( ) const�ĸ�������
// ������������ص�ǰ�����������������
template <class ElemType>
int RefGenList<ElemType>::DepthHelp(const RefGenListNode<ElemType> * &head) const
{
}

// �������ƣ�void ClearHelp(RefGenListNode<ElemType> *head); // �ͷ���headΪ�н������������������Է����ڴ�ռ�
// �������ܣ�~RefGenList( )��������ģ��ĸ�������
// ���������ɾ����ǰĿ�Ĺ�����Է�����ڴ�ռ�
template <class ElemType>
void RefGenList<ElemType>::ClearHelp(RefGenListNode<ElemType> * &head)
{
}

// �������ƣ�void RefGenList<ElemType>::CopyHelp(const RefGenListNode<ElemType> *sourceHead,
//                                               const RefGenListNode<ElemType> * &destHead);
// �������ܣ���ֵ���캯���Լ���ֵ��������غ����ĸ�������
// ����destHeadΪͷ������������������Ƴ���sourceHeadΪͷ�����������������
template <class ElemType>
void RefGenList<ElemType>::CopyHelp(const RefGenListNode<ElemType> *sourceHead,
                                    const RefGenListNode<ElemType> * &destHead)
{
}

// �������ƣ�void CreateHelp(RefGenListNode<ElemType> * &first);
// �������ܣ����캯���ĸ��������Լ�Input���뺯���ĸ�������
// ���������������firstΪͷ�����������������
template <class ElemType>
void CreateHelp(RefGenListNode<ElemType> * &first) // ������firstΪͷ�����������������
{
}

/**RefGenList[���������������]�������Ա����[ʵ��]**********************************************
    RefGenList( );      // Ĭ�Ϲ��캯��ģ��
    RefGenList(const RefGenListNode<ElemType> * &head); // ��ͷ���ָ�빹���������������
    RefGenList(const RefGenList<ElemType> &copy);       // ���ƹ��캯��ģ��
    RefGenList<ElemType> &operator=(const RefGenList<ElemType> &copy);  // ����=��ֵ�����
    virtual ~RefGenList( );         // ��������ģ��
**********************************************RefGenList[���������������]�������Ա����[ʵ��]**/
// �������ƣ�RefGenList( );
// �����������ʼ��һ���յ��������������
template <class ElemType>
RefGenList<ElemType>::RefGenList( )     // Ĭ�Ϲ��캯��ģ��
{
    m_head = new RefGenListNode<ElemType>(HEAD);
    m_head->m_ref = 1;      // ����������������������Ϊ1
}


// �������ƣ�RefGenList(const RefGenListNode<ElemType> * &head);
// �����������ͷ���ָ�빹���������������
template <class ElemType>
RefGenList<ElemType>::RefGenList(const RefGenListNode<ElemType> * &head)    // �������Ĺ��캯��
{
}


// �������ƣ�RefGenList(const RefGenList<ElemType> &copy);
// ����������ɲ����������������copy������ǰĿ�Ĺ����
template <class ElemType>
RefGenList<ElemType>::RefGenList(const RefGenList<ElemType> &copy)    // ���ƹ��캯��ģ��
{

}

// �������ƣ�RefGenList<ElemType> &operator=(const RefGenList<ElemType> &copy);
// ����������ò����������������copy����ǰĿ�Ĺ����ֵ
template <class ElemType>
RefGenList<ElemType>& RefGenList<ElemType>::operator=(const RefGenList<ElemType> &copy) // ����=��ֵ�����
{

}

// �������ƣ�virtual ~RefGenList( );
// �������������Ŀ�Ĺ�����Ѿ�������ڴ�ռ�
template <class ElemType>
RefGenList<ElemType>::~RefGenList( )    // ��������ģ��
{
}

/**RefGenList[���������������]������Ա����[ʵ��]*************************************************
    RefGenListNode<ElemType> *First( ) const;       // ���ر�ͷ���������������ĵ�һ��Ԫ�صĽ��
    RefGenListNode<ElemType> *End( ) const;        // ���ر�β��
    RefGenListNode<ElemType> *Next(const RefGenListNode<ElemType> *elemPtr) const;// ����elemPtrָ����������������Ԫ�صĺ��
    bool Empty( ) const;                // �жϵ�ǰ��������������Ƿ�Ϊ��
    int Depth( ) const;             // ���㵱ǰ�����������������
    void Input( ) const;              // ��������
    void Show( ) const;             // ��������
    void Push(const ElemType &elem);        // ��ԭ��Ԫ��elem��Ϊ��ͷ���뵽���������������ǰ��
    void Push(const RefGenList<ElemType> &subList); // ���ӱ�subList��Ϊ��ͷ���뵽���������������ǰ��
*************************************************[ʵ��]RefGenList[���������������]������Ա����**/

#endif // REFGENLIST_H_INCLUDED
