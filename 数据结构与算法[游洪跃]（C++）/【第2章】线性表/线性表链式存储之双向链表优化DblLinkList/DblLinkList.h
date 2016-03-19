/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : Mym_headFile.h
Description: ʵ�ó��������
Author     : Gatie_Me
Version    : Copyright 2012
Data_Time  : 20112-8-4 15:36:24
********************************************************************************/


/********************************************************************************
Problem    :��������һ����򵥵����Ա����ʽ�洢�ṹ, ������Ҳ��Ϊ��������
            �������洢���Ա�ʱ, ÿ������Ԫ����һ����㣨DblNode�����洢, һ�����
            �ַ�Ϊ���������, һ���Ǵ������Ԫ�ص�data, ��һ���Ǵ洢��һ�����
            ��ַ��Ϣ��ָ����next,

            ������Ĵ洢����ǰ��������һ��ͷ���, ������û�д洢�κ�����Ԫ��
            ���ǳ�Ϊͷ���m_head, �ڵ�����������ͷ�����Ȼ�����˴洢�ռ�, ���㷨ʵ��
            ���Ӽ�, Ч�ʸ���,
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����

�汾1.0.0  :����#define DEBUG, #define REMIND������ѡ���[2012/9/14 15:47:34]

�汾1.0.1  :�޸�Delete�����г��ֵĴ���[2012/9/15 11:27]
********************************************************************************/


#ifndef DBLLINKLIST_H_INCLUDED
#define DBLLINKLIST_H_INCLUDED

#include "DblNode.h"



//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�

///��������ģ�涨�岿��
// ��ͷ���
template <class ElemType>
class DblLinkList
{
/*=========================��PUBLIC�������ӿڡ�=========================*/
  public :
  // ��Ļ�����Ա����
    DblLinkList( );     // Ĭ�Ϲ��캯��ģ��

    DblLinkList(const DblLinkList<ElemType> &copy);   //��ֵ���캯��ģ��

    virtual ~DblLinkList( );     // ����������ģ��

  // ���������Ա����
    int Length( ) const;            // ��ȡ��������ĳ���

    bool Empty( ) const;            // �ж����������Ƿ�Ϊ��

    void Clean( );            // ��յ�ǰ��������

    void Traverse(void(*visit)(const ElemType &)) const;    // �������Ա�

    bool GetElem(int position, ElemType &elem);              // ��ȡ��position����������

    bool SetElem(int position, const ElemType &elem);       // ���õ�position������������Ϊelem

    bool Delete(int position, ElemType &elem);              // ɾ�������position����������, ���������ݷ��ظ�elem

    bool Insert(int position, const ElemType &elem);        // ������elem���뵽��position�����

    void Inlist(const ElemType &elem);        // ������elem���뵽���������ĩβ

  // ���غ���ģ��
    DblLinkList<ElemType> &operator=(const DblLinkList<ElemType> &copy);  // ���ظ�ֵ�����

  // ���⴦��ģ��
    bool Swap(int positionA, int positionB);                   // �������� ��

    bool BubbleSort(bool minTomax = true);     //ð�ݷ�����

    bool SelectSort(bool minTomax = true);      //ѡ������

    bool QuickSort(int start, int end);         // ����������
/*=========================��PUBLIC�������ӿڡ�=========================*/
//////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////
/*========================��PROTECTED��������Ա��========================*/
  protected :
  // ����������Ա������������
    DblNode<ElemType> *GetElemPtr(int position) const; // ����ָ���position������ָ��

    void Init( );               // ��ʼ�����Ա�

  // �������ݳ�Ա
    DblNode<ElemType> *m_head;        // ͷ���ָ����
    mutable DblNode<ElemType> *m_curPtr;   // ָ��ǰλ�õ�ָ��
    mutable int m_curPosition;          // �������浱ǰ���ʵ���Ԫ�����
    int m_length;                       // ���浱ǰ����Ԫ�ظ������ź�
/*========================��PROTECTED��������Ա��========================*/
};



/**����������Ա��ʵ�֡�******************************************************
    DblNode<ElemType> *GetElemPtr(int position) const;����ָ���position������ָ��
    void Init( );               ��ʼ�����Ա�
******************************************************����������Ա��ʵ�֡�**/

//�������ƣ�DblNode<ElemType> *GetElemPtr(int position) const
//��ʼ���������������Ѿ�����, �Ҳ�Ϊ��
//�������������ָ���position������ָ��
template <class ElemType>
DblNode<ElemType>* DblLinkList<ElemType>::GetElemPtr(int position) const // ����ָ���position������ָ��
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"GetElemPtr..." <<std::endl;
#endif

    // ����ʵ��
    if(this->m_curPosition < position)
    {   // �����ǰ����λ����������λ����ǰ, ��������
        for( ; this->m_curPosition < position; this->m_curPosition++)
        {
            this->m_curPtr =  this->m_curPtr->m_next;     // �������������
        }

    }
    else if(this->m_curPosition > position)
    {   // �����ǰ����λ����������λ���Ժ�, ����Ҫ��ǰ����
        for( ; this->m_curPosition > position; this->m_curPosition--)
        {
            this->m_curPtr = this->m_curPtr->m_back;    // ���������ǰ��
        }
    }

    return this->m_curPtr;      // �Żط�����Ϣ
}

//�������ƣ� void Init( );
//��ʼ���������Ա���Ϣδ��ʼ��
//�����������ʼ�����������������Ϣ
template <class ElemType>
void DblLinkList<ElemType>::Init( )  // ��ʼ�����Ա�
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Init..." <<std::endl;
#endif

    // ����ʵ��
    if(this->Length() > 0)      // �����ǰ��������Ϊ��
    {
        this->Clean( );               // ��յ�ǰ���Ա�
    }
    // ��ѭ���б�Ϊ��ʱ, ͷ����ָ����ָ��ͷ���
    this->m_head = new DblNode<ElemType>;      // ���ȹ���ͷָ��
    // ��˫������-=>ͷ���ǰ������ָ��ͷ��㱾��
    this->m_head->m_next =  this->m_head;
    this->m_head->m_back = this->m_head;
    // ��ʼ��������Ϣ
    this->m_curPosition = this->m_head;     // ��ʼԪ�ط���λ��Ϊͷָ��
    this->m_curPtr = 0;                     // ��ʼ��Ԫ�ط���λ���±�Ϊ0
    this-m_length = 0;                      // Ԫ�ظ�����ʼ��Ϊ0
}


/**��Ļ�����Ա������ʵ�֡�************************************************
    DblLinkList( );     // Ĭ�Ϲ��캯��ģ��
    DblLinkList(const DblLinkList<ElemType> &copy);//��ֵ���캯��ģ��
    virtual ~DblLinkList( );     // ����������ģ��
************************************************��ʵ�֡���Ļ�����Ա����**/
//�������ƣ� DblLinkList( );
//��ʼ���������Ա�δ����
//�������������һ��������
template <class ElemType>
DblLinkList<ElemType>::DblLinkList( )     // Ĭ�Ϲ��캯��ģ��
{
    // ��ѭ���б�Ϊ��ʱ, ͷ����ָ����ָ��ͷ���
    this->m_head = new DblNode<ElemType>;      // ����ͷָ��

    // ��˫������-=>ͷ���ǰ������ָ��ͷ��㱾��
    this->m_head->m_next =  this->m_head;
    this->m_head->m_back = this->m_head;
    // ��ʼ��������Ϣ
    this->m_curPosition = 0;     // ��ʼԪ�ط���λ��Ϊͷָ��
    this->m_curPtr = this->m_head;                     // ��ʼ��Ԫ�ط���λ���±�Ϊ0
    this->m_length = 0;                      // Ԫ�ظ�����ʼ��Ϊ0
}

//�������ƣ� DblLinkList(const DblLinkList<ElemType> &copy);
//��ʼ���������Ա�δ����
//�������������һ��������
template <class ElemType>
DblLinkList<ElemType>::DblLinkList(const DblLinkList<ElemType> &copy)
{
    // ���ȹ���ͷָ��
    this->Init( );     //���ȵ��ó�ʼ���������쵱ǰ�����ͷָ��
    // this->m_head = new DblNode<ElemType>

//    DblNode<ElemType> *copyPtr = copy.m_head->m_next;    // ����һ�����ָ���ʼ������ĵ�һ����Ϣ
//    DblNode<ElemType> *tempPtr;                          // �½�һ�����, ��Ϊѭ�������
//    this->m_head->m_next = tempPtr;                   // ����ǰ�������ͷָ�뽨����ϵ
//    this->m_head->m_back =
//    while(copyPtr != copy.m_head)   // ����ѭ��
//    {
//        // ���Ƚ���һ���������һ�����ݡ�
//        DblNode<ElemType> *nextPtr, *backPtr;     // �½���һ�����Ϊ��һ�������׼��
//
//        // Ϊ��ǰѭ��������������ֵ
//        tempPtr->m_data = copyPtr->m_data;        // ��ǰѭ������������Ϊ��ǰ����ֵ��������Ӧλ�õ�������
//        // ��ǰѭ������ָ����
//        tempPtr->m_next = nextPtr;
//        tempPtr->m_back =
//        // �����ָ����һ�����
//        tempPtr = nextPtr; //tempPtr->m_next;              // ����ǰѭ������ָ����ָ����һ�����
//        copyPtr = copyPtr->m_next;                        // ������ֵ����ָ����һ��ָ����
//    }
//
//    tempPtr->m_next = this->m_head;     // ����ѭ��

// ��һ��д����
    ElemType elem;
    for (int curPosition = 1; curPosition <= copy.Length( ); curPosition++)
	{	// ��������Ԫ��
		copy.GetElem(curPosition, elem);	// ȡ����curPosition��Ԫ��
		this->Inlist(elem);		// ��e���뵽��ǰ���Ա�
	}
}

//�������ƣ� virtual ~DblLinkList( );     // ����������ģ��
//��ʼ���������Ա���
//����������������Ա�
template <class ElemType>
DblLinkList<ElemType>::~DblLinkList( )        // ����������ģ��
{
    Clean( );
    delete this->m_head;
}


/**���������Ա������ʵ�֡�**************************************************
    int Length( ) const;            // ��ȡ��������ĳ���
    bool Empty( ) const;            // �ж����������Ƿ�Ϊ��
    void Clean( ) const;            // ��յ�ǰ��������
    void Traverse(void(*visit)(const ElemType &)) const;//�������Ա�
    bool GetElem(int psition, ElemType &elem);//��ȡ��position����������
    bool SetElem(int position, const ElemType &elem);// ���õ�position������������Ϊelem
    bool Delete(int position, ElemType &elem);// ɾ�������position����������, ���������ݷ��ظ�elem
    bool Insert(int position, const ElemType &elem);// ������elem���뵽��position�����
    bool Inlist(int position, const ElemType &elem);// ������elem���뵽���������ĩβ
**************************************************��ʵ�֡����������Ա����*/
//�������ƣ�int Length( ) const;
//��ʼ���������������Ѿ�����
//������������ص�ǰ����ı�
template <class ElemType>
int DblLinkList<ElemType>::Length( ) const // ��ȡ��������ĳ���
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Length..." <<std::endl;
#endif
    // ����ʵ��
    return this->m_length;
}

//�������ƣ�bool Empty( ) const;
//��ʼ���������������Ѿ�����
//��������������ǰ��������Ϊ��, ����True, ���򷵻�False
template <class ElemType>
bool DblLinkList<ElemType>::Empty( )const    // �ж����������Ƿ�Ϊ��
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Empty..." <<std::endl;
#endif
    // ����ʵ��
    return (this->m_length == 0);   // ���ͷָ�����һ�����λ��Ϊ����ͷ���, ��ѭ������Ϊ��
}



//�������ƣ�bool Clean( ) const;
//��ʼ���������������Ѿ�����
//��������������ǰ��������Ϊ��, ����True, ���򷵻�False
template <class ElemType>
void DblLinkList<ElemType>::Clean( )            // ��յ�ǰ��������
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Clean..." <<std::endl;
#endif
    // ����ʵ��
    ElemType tempElem;      // ��ʱԪ��ֵ

    //while(this->Length() > 0)
    while(this->m_head->m_next != this->m_head)   // ֻҪ��������Ϊ��
    {
        this->Delete(1, tempElem);     // ��ɾ����һ��Ԫ��
    }
}

//�������ƣ�void Traverse(void(*visit)(const ElemType &)) const;
//��ʼ���������������Ѿ�����
//��������������ǰ��������Ϊ��, ����True, ���򷵻�False
template <class ElemType>
void DblLinkList<ElemType>::Traverse(void(*visit)(const ElemType &)) const        //�������Ա�
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Traverse..." <<std::endl;
#endif
    // ����ʵ��
    for(DblNode<ElemType> *tempPtr = this->m_head->m_next; tempPtr != this->m_head; tempPtr = tempPtr->m_next)
    {
        // ��temp����ָ��ÿ��Ԫ��
        (*visit)(tempPtr->m_data);     // ����ÿһ��Ԫ��
    }
}

//�������ƣ�bool GetElem(int psition, ElemType &elem);
//��ʼ���������������Ѿ�����
//�����������ȡ��position����������
template <class ElemType>
bool DblLinkList<ElemType>::GetElem(int position, ElemType &elem)     //��ȡ��position����������
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"GetElem..." <<std::endl;
#endif
    // ����ʵ��
    int length = this->Length( );

    if(position < 1 || position > length)   // �������ֵ���Ϸ�
    {
        // �����ʾ��Ϣ
        #if define REMIND
        if(position < 1)
        {
            std::cout <<"����ֵ" <<position <<"Ϊ����߸�" <<std::endl;
        }
        else
        {
            std::cout <<"��ǰ���������" <<length <<", ����ֵ" <<position <<"Խ��." <<std::endl;
        }
        #endif
        return false;
    }
    else        // �������position�Ϸ�
    {
        DblNode<ElemType> *tempPtr;
        tempPtr = this->GetElemPtr(position);  // ȡ��ָ���position������ָ��
        elem = tempPtr->m_data;            // ��e���ص�podition��Ԫ�ص�ֵ
// ����Ĵ���Ҳ�������Ե�
//        int curPosition = 0;
//        DblNode<ElemeType> *tempPtr = head->m_next;  // ��tempPtrָ���ָ�Ľ��
//        while( position <tempPtr != this->m_head; )
//        {   // ��tempPtr����ָ��ÿ��Ԫ��
//            curPosition++;
//            tempPtr = tempPtr->m_next��
//        }
//        elem = tempPtr->m_data;
        return true;
    }
}

//�������ƣ�bool SetElem(int position, const ElemType &elem);
//��ʼ���������������Ѿ�����,
//������������õ�position������������Ϊelem
template <class ElemType>
bool DblLinkList<ElemType>::SetElem(int position, const ElemType &elem)  // ���õ�position������������Ϊelem
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Traverse..." <<std::endl;
#endif
    // ����ʵ��
    // ����ʵ��
    int length = this->Length( );
    if(position < 1 || position > length)   // �������ֵ���Ϸ�
    {
        // �����ʾ��Ϣ
        #if define REMIND
        if(position < 1)
        {
            std::cout <<"����ֵ" <<position <<"Ϊ����߸�" <<std::endl;
        }
        else
        {
            std::cout <<"��ǰ���������" <<length <<", ����ֵ" <<position <<"Խ��." <<std::endl;
        }
        #endif
        return false;
    }
    else        // �������position�Ϸ�
    {
        DblNode<ElemType> *tempPtr;
        tempPtr = GetElemPtr(position);  // ȡ��ָ���position������ָ��
        tempPtr->m_data = elem;            // ��e���ص�podition��Ԫ�ص�ֵ
// ����Ĵ���Ҳ�������Ե�
//        int curPosition = 0;
//        DblNode<ElemeType> *tempPtr = head->m_next;  // ��tempPtrָ���ָ�Ľ��
//        while( position <tempPtr != NULL; )
//        {   // ��tempPtr����ָ��ÿ��Ԫ��
//            curPosition++;
//            tempPtr = tempPtr->m_next��
//        }
//        elem = tempPtr->m_data;
        return true;
    }
}


//�������ƣ�bool Delete(int position, ElemType &elem);// ɾ�������position����������, ���������ݷ��ظ�elem
//��ʼ���������������Ѿ�����, ������position�Ϸ�
//���������ɾ�������position����������, ���������ݷ��ظ�elem
template <class ElemType>
bool DblLinkList<ElemType>::Delete(int position, ElemType &elem)         // ɾ�������position����������, ���������ݷ��ظ�elem
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Delete..." <<std::endl;
#endif
    // ����ʵ��
    int length = this->Length( );   // ���ȱ��浱ǰ���Ա�ı�, ��Ϊ�����ݿ��ܶ���õ�, ��ֹ��Ϊ������ε�������ʱ�临�Ӷ�

    if(position < 1 || position > length)     // �����������Ϸ�
    {
        // �����ʾ��Ϣ
        if(position < 1)
        {
            std::cout <<"����ֵ" <<position <<"Ϊ����߸�" <<std::endl;
        }
        else
        {
            std::cout <<"��ǰ���������" <<length <<", ����ֵ" <<position <<"Խ��." <<std::endl;
        }
        return false;
    }
    else            // ��������position�Ϸ�
    {
        //tempPtr   nextPtr
        //���� ���������������� ���� ������������ ����
        //        position
        DblNode<ElemType> *tempPtr;
        tempPtr = this->GetElemPtr(position);     // �ҵ�Ҫɾ��λ�õĽ����
        // ʵ��Ŀ�����ɾ������
        tempPtr->m_back->m_next = tempPtr->m_next;  // �޸�ǰһ�����ĺ��
        tempPtr->m_next->m_back = tempPtr->m_back;  // �޸ĺ�һ������ǰ��

        // ����ֵ��Ϣ����
        elem = tempPtr->m_data;                     // ��elem��ɾ����������

        if(position == this->Length())   // ���ɾ����Ԫ�������һ��Ԫ��
        {   // ɾ��β���, ��ǰ����λ�ø���Ϊ��ʼ
            this->m_curPosition = 0;
            this->m_curPtr = this->m_head;
        }
        else
        {
            this->m_curPosition = position;
            this->m_curPtr = tempPtr->m_next;
        }
        this->m_length--;           // Ԫ�ظ�������1

        // delete tempPtr;                             // ɾ��Ŀ�Ľ��

        return true;
    }
}

//�������ƣ�bool Inlist(int position, const ElemType &elem);
//��ʼ���������������Ѿ�����
//���������������elem���뵽���������ĩβ
template <class ElemType>
bool DblLinkList<ElemType>::Insert(int position, const ElemType &elem)  // ������elem���뵽���������ĩβ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Insert..." <<std::endl;
#endif
    // ����ʵ��
    int length = this->Length( );   // ���ȱ��浱ǰ���Ա�ı�, ��Ϊ�����ݿ��ܶ���õ�, ��ֹ��Ϊ������ε�������ʱ�临�Ӷ�

    if(position < 1 || position > length+1)     // �����������Ϸ�
    {
        // �����ʾ��Ϣ
        if(position < 1)
        {
            std::cout <<"����ֵ" <<position <<"Ϊ����߸�" <<std::endl;
        }
        else
        {
            std::cout <<"��ǰ���������" <<length <<", ����ֵ" <<position <<"Խ��." <<std::endl;
        }
        return false;
    }
    else            // ��������position�Ϸ�
    {
        //���� ���������������� ���� ������������ ����
        //        position
        DblNode<ElemType> *tempPtr, *nextPtr, *newPtr;   //

        tempPtr = this->GetElemPtr(position-1);   // �ҵ�Ҫ����λ�õ�ǰһ�������
        nextPtr = tempPtr->m_next;                // nextPtrָ���position�����
        newPtr = new DblNode<ElemType>(elem, tempPtr, nextPtr); // ���������
        tempPtr->m_next = newPtr;           // ��ǰһ�����������㽨����Ȼ��ϵ
        nextPtr->m_back = newPtr;           // ����һ�����������㽨����Ȼ��ϵ

        // ��������ķ���λ
        this->m_curPosition = position;
        this->m_curPtr = newPtr;
        this->m_length++;

        return true;
    }
}

//�������ƣ�Inlist(const ElemType &elem)
//��ʼ���������������Ѿ�����
//��������������ǰ��������Ϊ��, ����True, ���򷵻�False
template <class ElemType>
void DblLinkList<ElemType>::Inlist(const ElemType &elem)   // ������elem���뵽���������ĩβ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Insert..." <<std::endl;
#endif
    // ����ʵ��
//    for(DblNode<ElemType> *tempPtr = this->m_head; tempPtr->m_next != NULL; tempPtr = tempPtr->m_next)       // ����ѭ���ҵ���Position������λ��
//    {   // tempPtr���α�����������
//        continue;
//    }       // ѭ�������Ժ�tempPt�Ѿ��������һ�������
    DblNode<ElemType> *tempPtr = this->m_head;
    while(tempPtr->m_next != this->m_head)       // ����ѭ���ҵ���Position������λ��
    {   // tempPtr���α�����������
        tempPtr = tempPtr->m_next;
    }       // ѭ�������Ժ�tempPt�Ѿ��������һ�������
    DblNode<ElemType> *newPtr = new DblNode<ElemType>(elem, tempPtr, this->m_head);   // �½�һ�������
    tempPtr->m_next = newPtr;       // ���½������ԭ�������һ����㽨����ϰ
    this->m_head->m_back = newPtr;  // ������Ľ����Ϊĩβָ�뼴ͷ���ĺ��
    // ����һ��, �Ͱ�Ԫ��elem���������������ĩβ

    // ��������ķ���λ
    this->m_length++;
    this->m_curPosition = this->m_length;
    this->m_curPtr = newPtr;

}


/*************************************************************************************************
    DblLinkList<ElemType> &operator=(const DblLinkList<ElemType> &copy);  // ���ظ�ֵ�����
**************************************************************************��ʵ�֡����غ���ģ��**/
//�������ƣ�DblLinkList<ElemType> &operator=(const DblLinkList<ElemType> &copy);
//��ʼ���������������Ѿ�����
//��������������ǰ��������Ϊ��, ����True, ���򷵻�False
template <class ElemType>
DblLinkList<ElemType>& DblLinkList<ElemType>::operator=(const DblLinkList<ElemType> &copy)     // ���ظ�ֵ�����
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"operator=..." <<std::endl;
#endif
    // ����ʵ��
    if(&copy != this)
    {
        // ���ȹ���ͷָ��
        this->Init( );     //���ȵ��ó�ʼ���������쵱ǰ�����ͷָ��
        // this->m_head = new DblNode<ElemType>

        DblNode<ElemType> *copyPtr = copy.m_head->m_next;    // ����һ�����ָ���ʼ������ĵ�һ����Ϣ
        DblNode<ElemType> *tempPtr = new DblNode<ElemType>;   // �½�һ�����, ��Ϊѭ�������
        tempPtr = this->m_head->m_next;                   // ����ǰ�������ͷָ�뽨����ϵ

        while(tempPtr != copy.m_head)   // ����ѭ��
        {
            // ���Ƚ���һ���������һ�����ݡ�
            DblNode<ElemType> *nextPtr;     // �½���һ�����Ϊ��һ�������׼��

            // Ϊ��ǰѭ��������������ֵ
            tempPtr = copyPtr->m_data;        // ��ǰѭ������������Ϊ��ǰ����ֵ��������Ӧλ�õ�������
            tempPtr->m_next = nextPtr;        // ��ǰѭ������ָ����

            // �����ָ����һ�����
            tempPtr = nextPtr; //tempPtr->m_next;              // ����ǰѭ������ָ����ָ����һ�����
            copyPtr = copyPtr->m_next;                        // ������ֵ����ָ����һ��ָ����
        }

        tempPtr = this->m_head;

        // ��һ��д����
        //  for (int curPosition = 1; curPosition <= copy.Length( ); curPosition++)
        //	{	// ��������Ԫ��
        //		copy.GetElem(curPosition, e);	// ȡ����curPosition��Ԫ��
        //		Insert(Length() + 1, e);		// ��e���뵽��ǰ���Ա�
        //	}
    }

    return *this;
}

/**���⴦��ģ�桾ʵ�֡�******************************************************
    void Swap( );                   // ��������
    bool BubbleSort(bool minTomax = true);     //ð�ݷ�����
    bool SelectSort(bool minTomax = true);      //ѡ������
    bool QuickSort(int start, int end);         // ����������
    bool DblLinkList<ElemType>::CutOddEven( )         // ����������
******************************************************��ʵ�֡����⴦��ģ��**/
//�������ƣ�void Swap( )
//��ʼ���������������Ѿ�����
//����������������������positionA��λ�õ�Ԫ�غ͵�positionB��λ�õ�Ԫ��
template <class ElemType>
bool DblLinkList<ElemType>::Swap(int positionA, int positionB)                // ��������
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Swap..." <<std::endl;
#endif
    // ����ʵ��
    int length = this->Length( );                  // ���ȱ���

    if(positionA < 1 || positionA > length
    || positionB < 1 || positionB > length)
    {
        std::cout <<"�����±겻�Ϸ�" <<std::endl;
        return false;
    }

    // ʵ�ֽ���
    DblNode<ElemType> *ptrA = this->GetElemPtr(positionA);     // ��ȡ��positionA��ָ��
    DblNode<ElemType> *ptrB = this->GetElemPtr(positionB);     // ��ȡ��positionB��ָ��

    // ʵ�ֵ�position��Ԫ�����position��Ԫ�صĽ���
    ElemType temp;          // �����м����
    temp = ptrA->m_data;
    ptrA->m_data = ptrB->m_data;
    ptrB->m_data = temp;

//    // ʵ�ֽ�������һ��д��
//    ElemType tempElem, elemA, elemB;      // �����м����
//
//    // ȡ����ӦԪ��
//    this->GetElem(positionA, elemA);        // ����������ĵ�positionA��Ԫ��ȡ��������elemA��
//    this->GetElem(positionB, elemB);        // ����������ĵ�positionB��Ԫ��ȡ��������elemB��
//    // ��Ŷ�ӦԪ��
//    this->SetElem(positionA, elemB);        // ������elemB��������Ա�ĵ�positionA��λ��
//    this->SetElem(positionB, elemA);        // ������elemB��������Ա�ĵ�positionA��λ��
    return true;            // �����ɹ�
}


//�������ƣ�bool BubbleSort(bool minTomax = true)
//��ʼ���������������Ѿ�����
//��������������ݷ�������������
template <class ElemType>
bool DblLinkList<ElemType>::BubbleSort(bool minTomax/*= true*/)     //ð�ݷ�����
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"BubbleSort..." <<std::endl;
#endif
    // ����ʵ��
    // д��һ�������ʵ�ַ���

    int length = this->Length( );
    if(length == 0)
    {
        std::cout <<"��ǰ��������Ϊ��, �޷���������" <<std::endl;
        return false;
    }

    for(int j = 1; j < length; j++)         // ð�ݷ�����Ҫ����length-1������
    {
        int i = 1;
        DblNode<ElemType> *tempPtr = this->m_head->m_next;
        while(i < length-j && tempPtr != NULL)            //ÿ��ѭ���Ƚ�length-1-j��
        {
//            #if defined DEBUG
//            system("pause");
//            #endif
              // ���αȽ����ڵ�������
            if( ((tempPtr->m_data > tempPtr->m_next->m_data) && (minTomax)) // ������ڵ�������ǰһ�����Ⱥ�һ������, �����С�������������
             || ((tempPtr->m_data < tempPtr->m_next->m_data) && !(minTomax)) )  // ������ڵ�������ǰһ�����Ⱥ�һ����С, ����Ӵ�С���������
             {
                 this->Swap(i, i+1);
             }
            // ѭ������
            i++, tempPtr = tempPtr->m_next;        // ѭ������, �����߽�1, ͬʱ�������ָ��������
        }
    }

    return true;            // ����ɹ�
//    // д����: ����д��, ����д��˼·��, ����Ч�ʵ�, ��������̫��
//    ElemType lastItem, nextItem;
//    int length = this->Length( );
//    for(int j = 1; j < length; j++)
//    {
//        for(int i = 1; i < length-j; i++)
//        {
//            // ȡ���������ڵ�Ԫ��
//            this->GetElem(i, lastItem);
//            this->GetElem(i+1, nextItem);
//
//            if( ((lastItem > nextItem) && (minTomax))   // �����С��������Ҫ���
//             || ((lastItem < nextItem) && !(minTomax)) ) // ����Ӵ�����Ҫ���
//            {
//                this->Swap(i, i+1);             // ������i�����͵�i+1����
//            }
//        }
//    }
    return true;
}

//�������ƣ�bool SelectSort(bool minTomax = true)
//��ʼ���������������Ѿ�����
//��������������ݷ�������������
template <class ElemType>
bool DblLinkList<ElemType>::SelectSort(bool minTomax/*= true*/)      //ѡ������
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"SelectSort..." <<std::endl;
#endif
    // ����ʵ��
    int length = this->Length( );
    if(length == 0)
    {
        std::cout <<"��ǰ��������Ϊ��, �޷���������" <<std::endl;
        return false;
    }
    // ���������ǰ������
    ElemType tempItem, sortItem;
   // ElemType elem;
    for(int i = 1; i < length; i++)
    {
        int k = i;      // ��k���浱ǰ�Ƚ�λ��[���ݴ����]
        this->GetElem(i, tempItem);
      //  elem = tempItem;         // tempptr��������̨���浱ǰ�����еļ�ֵ

        for(int j = i+1; j < length; j++)
        {
            this->GetElem(j, sortItem);         // ȡ����ǰ��ȡ���Ƚϵ�Ԫ��
            if( ((sortItem < tempItem) && (minTomax))       // ������Ƚϵ�Ԫ��[j]����Ҫ��
             || ((sortItem > tempItem) && !(minTomax)) )
            {
                k = j;                  // ��k���浱ǰ����Ҫ�����ݵ�λ��
                tempItem = sortItem;    // ͬʱ��tempItem���浱ǰ����Ҫ�������
            }
        }       // һ��ѭ����, k�ͱ����˵�ǰ��СԪ�ص�λ��, tempPtr�ͱ����˵�ǰ��ֵԪ�ص�ֵ
                // �����������Ҫ���ڵ�i��λ��

        if(k != i/*tempItem != elem*/)
        {
            this->Swap(k, i);
            //this->SetElem(i, tempItem);
            //this->SetElem(k, elem);
        }
    }
    return true;
}

//�������ƣ�bool QuickSort(bool minTomax = true)
//��ʼ���������������Ѿ�����
//�����������������������������
template <class ElemType>
bool DblLinkList<ElemType>::QuickSort(int start, int end)         // ����������
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"QuickSort..." <<std::endl;
#endif
    // ����ʵ��
    /// ����������...
    return true;
}


#endif
