/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : Mym_firstFile.h
Description: ʵ�ó��������
Author     : Gatie_Me
Version    : Copyright 2012
Data_Time  : 20112-8-4 15:36:24
********************************************************************************/


/********************************************************************************
Problem    :��������һ����򵥵����Ա����ʽ�洢�ṹ, ������Ҳ��Ϊ��������
            �������洢���Ա�ʱ, ÿ������Ԫ����һ����㣨node�����洢, һ�����
            �ַ�Ϊ���������, һ���Ǵ������Ԫ�ص�data, ��һ���Ǵ洢��һ�����
            ��ַ��Ϣ��ָ����next,
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����

�汾1.0.0  :����#define DEBUG, #define REMIND������ѡ���[2012/9/14 15:47:34]

�汾1.0.1  :�޸�Delete�����г��ֵĴ���[2012/9/15 11:27]

�汾1.0.2  :��ǰ�汾����Bug, ɾ���Ͳ����һ��Ԫ�ص�ʱ�����
********************************************************************************/


#ifndef SimpleLinkWithoutHeadListWithoutHead_H_INCLUDED
#define SimpleLinkWithoutHeadList_H_INCLUDED

#include "Node.h"


//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�

///��������ģ�涨�岿��
// ��ͷ���
template <class ElemType>
class SimpleLinkWithoutHeadList
{
/*=========================��PUBLIC�������ӿڡ�=========================*/
  public :
  // ��Ļ�����Ա����
    SimpleLinkWithoutHeadList( );     // Ĭ�Ϲ��캯��ģ��

    SimpleLinkWithoutHeadList(const SimpleLinkWithoutHeadList<ElemType> &copy);   //��ֵ���캯��ģ��

    virtual ~SimpleLinkWithoutHeadList( );     // ����������ģ��

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
    SimpleLinkWithoutHeadList<ElemType> &operator=(const SimpleLinkWithoutHeadList<ElemType> &copy);  // ���ظ�ֵ�����

  // ���⴦��ģ��
    bool Swap(int positionA, int positionB);                   // �������� ��

    bool BubbleSort(bool minTomax = true);     //ð�ݷ�����

    bool SelectSort(bool minTomax = true);      //ѡ������

    bool QuickSort(int start, int end);         // ����������

    bool CutOddEven( );         // ����������ָ�������ż��������
/*=========================��PUBLIC�������ӿڡ�=========================*/
//////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////
/*========================��PROTECTED��������Ա��========================*/
  protected :
  // ����������Ա������������
    Node<ElemType> *GetElemPtr(int position) const; // ����ָ���position������ָ��

    void Init( );               // ��ʼ�����Ա�

  // �������ݳ�Ա
    Node<ElemType> *m_first;        // ͷ���ָ����
/*========================��PROTECTED��������Ա��========================*/
};



/**����������Ա��ʵ�֡�******************************************************
    Node<ElemType> *GetElemPtr(int position) const;����ָ���position������ָ��
    void Init( );               ��ʼ�����Ա�
******************************************************����������Ա��ʵ�֡�**/

//�������ƣ�Node<ElemType> *GetElemPtr(int position) const
//��ʼ���������������Ѿ�����, �Ҳ�Ϊ��
//�������������ָ���position������ָ��
template <class ElemType>
Node<ElemType>* SimpleLinkWithoutHeadList<ElemType>::GetElemPtr(int position) const // ����ָ���position������ָ��
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"GetElemPtr..." <<std::endl;
#endif

    // ����ʵ��
    if(this->m_first == NULL)      // ���ֻ��һ��ͷ���
    {
        std::cout <<"��ǰ��������Ϊ��, �޷����ҵ�" <<position <<"��������Ϣ" <<std::endl;
        return NULL;            // ���ؿ�
    }

    Node<ElemType> *tempPtr = this->m_first;     // ��ָ��tempPtr��������������ҵ�position�����
    int curPosition = 0;                        // temp�����Ѿ������Ľ����

    // ������tempPtr����ѭ������position������λ��
    while(curPosition < position && tempPtr != NULL)
    {
        tempPtr = tempPtr->m_next;
        curPosition++;
    }

    if(tempPtr != NULL && curPosition == position)   //
    {
        return tempPtr;     // ���ҳɹ�
    }
    else
    {
        return NULL;    // δ���ҳɹ����ؿ�ָ��
    }
}

//�������ƣ� void Init( );
//��ʼ���������Ա���Ϣδ��ʼ��
//�����������ʼ�����������������Ϣ
template <class ElemType>
void SimpleLinkWithoutHeadList<ElemType>::Init( )  // ��ʼ�����Ա�
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Init..." <<std::endl;
#endif

    // ����ʵ��
    if(this->Length() > 0)      // �����ǰ��������Ϊ��
    {
        Clean( );               // ��յ�ǰ���Ա�
    }
    this->m_first = NULL;        // ����ͷָ��
}


/**��Ļ�����Ա������ʵ�֡�************************************************
    SimpleLinkWithoutHeadList( );     // Ĭ�Ϲ��캯��ģ��
    SimpleLinkWithoutHeadList(const SimpleLinkWithoutHeadList<ElemType> &copy);//��ֵ���캯��ģ��
    virtual ~SimpleLinkWithoutHeadList( );     // ����������ģ��
************************************************��ʵ�֡���Ļ�����Ա����**/
//�������ƣ� SimpleLinkWithoutHeadList( );
//��ʼ���������Ա�δ����
//�������������һ��������
template <class ElemType>
SimpleLinkWithoutHeadList<ElemType>::SimpleLinkWithoutHeadList( )     // Ĭ�Ϲ��캯��ģ��
{
    this->m_first = new Node<ElemType>;        // ����ͷָ��
}

//�������ƣ� SimpleLinkWithoutHeadList(const SimpleLinkWithoutHeadList<ElemType> &copy);
//��ʼ���������Ա�δ����
//�������������һ��������
template <class ElemType>
SimpleLinkWithoutHeadList<ElemType>::SimpleLinkWithoutHeadList(const SimpleLinkWithoutHeadList<ElemType> &copy)
{
    // ���ȹ���ͷָ��
    this->Init( );     //���ȵ��ó�ʼ���������쵱ǰ�����ͷָ��
    // this->m_first = new Node<ElemType>

//    Node<ElemType> *copyPtr = copy.m_first;    // ����һ�����ָ���ʼ������ĵ�һ����Ϣ
//    Node<ElemType> *tempPtr;                          // �½�һ�����, ��Ϊѭ�������
//    tempPtr = this->m_first;                   // ����ǰ�������ͷָ�뽨����ϵ
//
//    while(tempPtr->m_next != NULL)   // ����ѭ��
//    {
//        // ���Ƚ���һ���������һ�����ݡ�
//        Node<ElemType> *nextPtr;     // �½���һ�����Ϊ��һ�������׼��
//
//        // Ϊ��ǰѭ��������������ֵ
//        tempPtr = copyPtr->m_data;        // ��ǰѭ������������Ϊ��ǰ����ֵ��������Ӧλ�õ�������
//        tempPtr->m_next = nextPtr;        // ��ǰѭ������ָ����
//
//        // �����ָ����һ�����
//        tempPtr = nextPtr; //tempPtr->m_next;              // ����ǰѭ������ָ����ָ����һ�����
//        copyPtr = copyPtr->m_next;                        // ������ֵ����ָ����һ��ָ����
//    }

// ��һ��д����
    ElemType elem;
    for (int curPosition = 1; curPosition <= copy.Length( ); curPosition++)
	{	// ��������Ԫ��
		copy.GetElem(curPosition, elem);	// ȡ����curPosition��Ԫ��
		this->Inlist(elem);		// ��e���뵽��ǰ���Ա�
	}
}

//�������ƣ� virtual ~SimpleLinkWithoutHeadList( );     // ����������ģ��
//��ʼ���������Ա���
//����������������Ա�
template <class ElemType>
SimpleLinkWithoutHeadList<ElemType>::~SimpleLinkWithoutHeadList( )        // ����������ģ��
{
    Clean( );
    delete this->m_first;
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
int SimpleLinkWithoutHeadList<ElemType>::Length( ) const // ��ȡ��������ĳ���
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Length..." <<std::endl;
#endif
    // ����ʵ��
    int len = 0;          // ������

    for(Node<ElemType> *tempPtr = m_first; tempPtr->m_next != NULL; tempPtr = tempPtr->m_next)
    {   // ��tempPtr����ָ��ÿ��Ԫ��
        len++;
    }
//    �������������C���Գ�����ƣ��ִ�����
//    for(Node<ElemType> *tempPtr = m_first->m_next; count < position; tempPtr = tempPtr->m_next, count++)
//    {
//        continue;
//    }
    return len;             // ���ؽ���
}

//�������ƣ�bool Empty( ) const;
//��ʼ���������������Ѿ�����
//��������������ǰ��������Ϊ��, ����True, ���򷵻�False
template <class ElemType>
bool SimpleLinkWithoutHeadList<ElemType>::Empty( )const    // �ж����������Ƿ�Ϊ��
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Empty..." <<std::endl;
#endif
    // ����ʵ��
    return this->m_first == NULL;   // ���ͷָ�����һ�����λ��Ϊ��, ������Ա�Ϊ��
}



//�������ƣ�bool Clean( ) const;
//��ʼ���������������Ѿ�����
//��������������ǰ��������Ϊ��, ����True, ���򷵻�False
template <class ElemType>
void SimpleLinkWithoutHeadList<ElemType>::Clean( )            // ��յ�ǰ��������
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Clean..." <<std::endl;
#endif
    // ����ʵ��
    ElemType tempElem;      // ��ʱԪ��ֵ

    //while(this->Length() > 0)
    while(this->m_first != NULL)   // ֻҪ��������Ϊ��
    {
        this->Delete(1, tempElem);     // ��ɾ����һ��Ԫ��
    }
}

//�������ƣ�void Traverse(void(*visit)(const ElemType &)) const;
//��ʼ���������������Ѿ�����
//��������������ǰ��������Ϊ��, ����True, ���򷵻�False
template <class ElemType>
void SimpleLinkWithoutHeadList<ElemType>::Traverse(void(*visit)(const ElemType &)) const        //�������Ա�
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Traverse..." <<std::endl;
#endif
    // ����ʵ��
    for(Node<ElemType> *tempPtr = this->m_first; tempPtr != NULL; tempPtr = tempPtr->m_next)
    {
        // ��temp����ָ��ÿ��Ԫ��
        (*visit)(tempPtr->m_next);     // ����ÿһ��Ԫ��
    }
}

//�������ƣ�bool GetElem(int psition, ElemType &elem);
//��ʼ���������������Ѿ�����
//�����������ȡ��position����������
template <class ElemType>
bool SimpleLinkWithoutHeadList<ElemType>::GetElem(int position, ElemType &elem)     //��ȡ��position����������
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
        Node<ElemType> *tempPtr;
        tempPtr = this->GetElemPtr(position);  // ȡ��ָ���position������ָ��
        elem = tempPtr->m_data;            // ��e���ص�podition��Ԫ�ص�ֵ
// ����Ĵ���Ҳ�������Ե�
//        int curPosition = 0;
//        Node<ElemeType> *tempPtr = head->m_next;  // ��tempPtrָ���ָ�Ľ��
//        while( position <tempPtr != NULL; )
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
bool SimpleLinkWithoutHeadList<ElemType>::SetElem(int position, const ElemType &elem)  // ���õ�position������������Ϊelem
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
        Node<ElemType> *tempPtr;
        tempPtr = GetElemPtr(position);  // ȡ��ָ���position������ָ��
        tempPtr->m_data = elem;            // ��e���ص�podition��Ԫ�ص�ֵ
// ����Ĵ���Ҳ�������Ե�
//        int curPosition = 0;
//        Node<ElemeType> *tempPtr = head->m_next;  // ��tempPtrָ���ָ�Ľ��
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
bool SimpleLinkWithoutHeadList<ElemType>::Delete(int position, ElemType &elem)         // ɾ�������position����������, ���������ݷ��ظ�elem
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
        if(position > 1)
        {
            //tempPtr   nextPtr
            //���� ���������������� ���� ������������ ����
            //        position
            Node<ElemType> *tempPtr;
            tempPtr = this->GetElemPtr(position-1);     // �ҵ�Ҫɾ��λ�õ�ǰһ�������
            Node<ElemType> *nextPtr = tempPtr->m_next;  // ƾ���ҵ��Ľ���ҵ�Ҫɾ����λ��
            tempPtr->m_next = tempPtr->m_next->m_next;//nextPtr->m_next;          // ���½���ɾ�������ϵ
            elem = nextPtr->m_data;                     // ��elem��ɾ����������
            // delete nextPtr;                             // ɾ��Ŀ�Ľ��
        }
        else if(position == 1)
        {
            Node<ElemType> *tempPtr = this->m_first;
            this->m_first = this->m_first->m_next;            // ɾ��ͷָ�����ô��һ��������ͷָ����
            delete tempPtr;     // ɾ��ԭ��ͷָ��Ŀռ�
        }

        return true;
    }
}

//�������ƣ�bool Inlist(int position, const ElemType &elem);
//��ʼ���������������Ѿ�����
//���������������elem���뵽���������ĩβ
template <class ElemType>
bool SimpleLinkWithoutHeadList<ElemType>::Insert(int position, const ElemType &elem)  // ������elem���뵽���������ĩβ
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
        if(position > 1)
        {
            Node<ElemType> *tempPtr = this->GetElemPtr(position-1);   // �ҵ�Ҫ����λ�õ�ǰһ�������
            Node<ElemType> *newPtr = new Node<ElemType>(elem, tempPtr->m_next);  // ���µĽ����������λ�õ���һ����㽨����ϵ
            tempPtr->m_next = newPtr;
        }
        else//if(psotion == 1)
        {   /// ����������
            Node<ElemType> *newPtr = new Node<ElemType>(elem, this->m_first);      // ����һ��ͷָ��, ��Ϊ�µ�ͷָ��
            this->m_first = newPtr;
        }
        return true;
    }
}

//�������ƣ�Inlist(const ElemType &elem)
//��ʼ���������������Ѿ�����
//��������������ǰ��������Ϊ��, ����True, ���򷵻�False
template <class ElemType>
void SimpleLinkWithoutHeadList<ElemType>::Inlist(const ElemType &elem)   // ������elem���뵽���������ĩβ
{
    // ������Ϣ
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"Insert..." <<std::endl;
#endif
    if(this->m_first == NULL)  // ���ͷ���Ϊ��, ˵�������������ǿյ�
    {
        this->m_first->SetNode(elem);     // ֱ�Ӹ���ͷָ���������
    }
    else
    {
        Node<ElemType> *tempPtr = this->m_first;
        while(tempPtr->m_next != NULL)       // ����ѭ���ҵ���Position������λ��
        {   // tempPtr���α�����������
            tempPtr = tempPtr->m_next;
        }       // ѭ�������Ժ�tempPt�Ѿ��������һ�������
        Node<ElemType> *newPtr = new Node<ElemType>(elem);   // �½�һ�������
        tempPtr->m_next = newPtr;       // ���½������ԭ�������һ����㽨����ϰ
        // ����һ��, �Ͱ�Ԫ��elem���������������ĩβ
    }
}


/*************************************************************************************************
    SimpleLinkWithoutHeadList<ElemType> &operator=(const SimpleLinkWithoutHeadList<ElemType> &copy);  // ���ظ�ֵ�����
**************************************************************************��ʵ�֡����غ���ģ��**/
//�������ƣ�SimpleLinkWithoutHeadList<ElemType> &operator=(const SimpleLinkWithoutHeadList<ElemType> &copy);
//��ʼ���������������Ѿ�����
//��������������ǰ��������Ϊ��, ����True, ���򷵻�False
template <class ElemType>
SimpleLinkWithoutHeadList<ElemType>& SimpleLinkWithoutHeadList<ElemType>::operator=(const SimpleLinkWithoutHeadList<ElemType> &copy)     // ���ظ�ֵ�����
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
        // this->m_first = new Node<ElemType>

//        Node<ElemType> *copyPtr = copy.m_firstt;    // ����һ�����ָ���ʼ������ĵ�һ����Ϣ
//        Node<ElemType> *tempPtr = new Node<ElemType>;   // �½�һ�����, ��Ϊѭ�������
//        tempPtr = this->m_first;                   // ����ǰ�������ͷָ�뽨����ϵ
//
//        while(tempPtr->m_next != NULL)   // ����ѭ��
//        {
//            // ���Ƚ���һ���������һ�����ݡ�
//            Node<ElemType> *nextPtr;     // �½���һ�����Ϊ��һ�������׼��
//
//            // Ϊ��ǰѭ��������������ֵ
//            tempPtr = copyPtr->m_data;        // ��ǰѭ������������Ϊ��ǰ����ֵ��������Ӧλ�õ�������
//            tempPtr->m_next = nextPtr;        // ��ǰѭ������ָ����
//
//            // �����ָ����һ�����
//            tempPtr = nextPtr; //tempPtr->m_next;              // ����ǰѭ������ָ����ָ����һ�����
//            copyPtr = copyPtr->m_next;                        // ������ֵ����ָ����һ��ָ����
//        }

        // ��һ��д����
        ElemType elem;
        for (int curPosition = 1; curPosition <= copy.Length( ); curPosition++)
        {	// ��������Ԫ��
            copy.GetElem(curPosition, elem);	// ȡ����curPosition��Ԫ��
            this->Inlist(elem);		// ��e���뵽��ǰ���Ա�
        }
    }

    return *this;
}

/**���⴦��ģ�桾ʵ�֡�******************************************************
    void Swap( );                   // ��������
    bool BubbleSort(bool minTomax = true);     //ð�ݷ�����
    bool SelectSort(bool minTomax = true);      //ѡ������
    bool QuickSort(int start, int end);         // ����������
    bool SimpleLinkWithoutHeadList<ElemType>::CutOddEven( )         // ����������
******************************************************��ʵ�֡����⴦��ģ��**/
//�������ƣ�void Swap( )
//��ʼ���������������Ѿ�����
//����������������������positionA��λ�õ�Ԫ�غ͵�positionB��λ�õ�Ԫ��
template <class ElemType>
bool SimpleLinkWithoutHeadList<ElemType>::Swap(int positionA, int positionB)                // ��������
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
    Node<ElemType> *ptrA = this->GetElemPtr(positionA);     // ��ȡ��positionA��ָ��
    Node<ElemType> *ptrB = this->GetElemPtr(positionB);     // ��ȡ��positionB��ָ��

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
bool SimpleLinkWithoutHeadList<ElemType>::BubbleSort(bool minTomax/*= true*/)     //ð�ݷ�����
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
        Node<ElemType> *tempPtr = this->m_first;
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
bool SimpleLinkWithoutHeadList<ElemType>::SelectSort(bool minTomax/*= true*/)      //ѡ������
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
bool SimpleLinkWithoutHeadList<ElemType>::QuickSort(int start, int end)         // ����������
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
