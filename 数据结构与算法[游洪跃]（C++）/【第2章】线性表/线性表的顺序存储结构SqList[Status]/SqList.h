/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : SqList.h
Description: ���Ա�˳��洢�ṹ
Author     : Gatie_Me
Version    : Copyright 2012
Data_Time  : 20112-8-29 10:28:43
Content    : ���ݽṹ���㷨��C++��������Դ��
********************************************************************************/


/********************************************************************************
History    :C++����˳���ģ���ʵ��
********************************************************************************/


#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED




#include "MyHeadFile.h"

///˳��ģ����SqList���岿��======================================================================
template <class ElemType>   //���ݳ�ԱElemType
class SqList
{
/*===========================[Friend-=>��Ԫ����]===========================*/
    //friend std::istream &operator>>(std::istream &in, const SqList<ElemType> &inList);

    //friend std::ostream &operator<<(std::ostream &out, const SqList<ElemType> &outList);

    friend SqList<ElemType> Difference(const SqList<ElemType> &listA, const SqList<ElemType> &listB);  //�󼯺�listA�뼯��listB�Ĳ

    friend SqList<ElemType> Comon(const SqList<ElemType> &listA, const SqList<ElemType> &listB);

    friend SqList<ElemType> ComOrDiff(const SqList<ElemType> &listA, const SqList<ElemType> &listB, bool isExist = false);
/*===========================[Friend-=>��Ԫ����]===========================*/



/*===========================[PUBLIC-=>�����ӿ�]===========================*/
//�����������ͷ������������ر���ϵͳĬ�Ϸ���������
  public :
//ģ���������Ա��������
    SqList(int size = DEFAULT_SIZE);            //���캯��ģ��   //��ͷ�ļ���DEFAULT_SIZE�궨��Ϊ1000

    SqList(const SqList<ElemType> &copy);       //��ֵ���캯��ģ��

    virtual ~SqList( );                         //����������ģ��
//ģ����������Ա��������
    int Length( ) const;                       //��ȡ���Ա���

    int Size( ) const;                          //��ȡ���Ա����󳤶�

    bool Empty( ) const;                       //�ж����Ա��Ƿ�Ϊ��

    void Clean( );                             //������Ա�

    void Traverse(void(*visit)(const ElemType &)) const;     //�������Ա�


    bool IsExist(const ElemType &elemType) const;   //�ж�����elemType�ڲ��ڵ�ǰ���Ա���

    StatusCode GetElem(int position, ElemType &elemType);  //���ָ��λ��position��Ԫ��

    StatusCode SetElem(int position, const ElemType &elemType);   //����ָ��λ��position��Ԫ��

    StatusCode Delete(int position, const ElemType &elemType);               //ɾ��ָ��λ��position��Ԫ��

    StatusCode Insert(int position, const ElemType &elemType);   //��ָ��λ��position����Ԫ��

    StatusCode InList(const ElemType &elemType);       //������elemType�������Ա��ĩβ

//���غ�������
    SqList<ElemType> &operator=(const SqList<ElemType> &copy);      //��ֵ���������

    SqList<ElemType> &operator[](const int index);                 //�����±���ʺ���

//���⺯��ģ��[����Sort]
    StatusCode Swap(int &mPosition, int &nPosition);    //�������Ա��mPosition��Ԫ�غ͵�nPosition��Ԫ��

    StatusCode BubbleSort(bool minTomax = true);     //ð�ݷ�����

    StatusCode SelectSort(bool minTomax = true);      //ѡ������

/*===========================[PUBLIC-=>�����ӿ�]===========================*/


/*==========================[PROTECTED-=>��������]==========================*/
  protected :
//������������
    bool Full( ) const;      //�ж����Ա��Ƿ�����
    void Init(int size = DEFAULT_SIZE);     //��ʼ�����Ա�
//�������ݳ�Ա
    int length;                                 //���Ա�Ԫ�ظ���
    int maxSize;                                //˳������Ԫ�ظ���
    ElemType *elems;                           //Ԫ�ش洢�ռ�
   // enum StatusCode = {RANGE_ERROR, EMPTY_ERROE, SUCCESS, FULL_lIST};
/*==========================[PROTECTED-=>��������]==========================*/

};


///˳��ģ����SqListʵ�ֲ���===============================================================
/**��Ԫ������ʵ�֡�*****************************************************************
   // friend std::istream &operator>>(std::istream &in, const SqList<ElemType> &inList);//������ȡ������
  //  friend std::ostream &operator<<(std::ostream &out, const SqList<ElemType> &outList);//���ز��������
    friend SqList<ElemType> Difference(const SqList<ElemType> &listA, const Sqlist<ElemType>listB);//�󼯺�listA�뼯��listB�Ĳ
    friend SqList<ElemType> Comon(const SqList<ElemType> &listA, const Sqlist<ElemType> &listB);
    friend SqList<ElemType> ComOrDiff(const SqList<ElemType> &listA, const Sqlist<ElemType> &listB, bool isExist = false);
*****************************************************************��ʵ�֡���Ԫ����**/
//�������ƣ�istream &operator>>(istream &in, const SqList<ElemType>inList)
//��ʼ���������Ա��Ѿ�����, ��Ԫ������ElemType����ʹ��>>(��ȡ), <<()
////��������������Ա��������ȡ����������
//template <class ElemType>
//std::istream &operator>>(std::istream &in, const SqList<ElemType>inList)
//{
//
//    return in;
//}

//�������ƣ�ostream &operator<<(ostream &out, const SqList<ElemType> &outList)
//��ʼ���������Ա��Ѿ�����
//��������������Ա����.�ݲ��뵽�������
//template <class ElemType>
//std::ostream &operator<<(std::ostream &out, const SqList<ElemType> &outList)
//{
//    return out;
//}


//�������ƣ�SqList<ElemType> Difference(const Sqlist<ElemType> &listA, const SqList<ElemType> &listB)
//��ʼ�������������Ա�listA��listB������,
//��������������listA��listB���ϵĲ
//������������listA��ȡ��Ԫ����listB�н��в���, ���δ��listB�г���, ����鵽listC��
template <class ElemType>
SqList<ElemType> Difference(const SqList<ElemType> &listA, const SqList<ElemType> &listB)
{
    ElemType temp;
    SqList<ElemType> listC;

//listC.Clean( );     //����������
    for(int aPosition = 1; aPosition < listA.length; aPosition++)   //ѭ�����Ա�Aÿ����Ԫ��
    {
        listA.GetElem(aPosition, temp);     //ȡ�����Ա�A�ĵ�ǰλ�õ�Ԫ��
        if(listB.IsExist(temp) == false)     //���listA��ȡ��������temo����listB��
        {
            listC.InList(temp);    //������temp����listC��ĩβ
        }
    }
    return listC;
}


//�������ƣ�SqList<ElemType> Difference(const Sqlist<ElemType> &listA, const SqList<ElemType> &listB)
//��ʼ�������������Ա�listA��listB������,
//��������������listA��listB���ϵĽ���
//������������listA��ȡ��Ԫ����listB�н��в���, ���δ��listB�г���, ����鵽listC��
template <class ElemType>
SqList<ElemType> Comon(const SqList<ElemType> &listA, const SqList<ElemType> &listB)
{
    ElemType temp;
    SqList<ElemType> listC;

//listC.Clean( );     //����������
    for(int aPosition = 1; aPosition < listA.length; aPosition++)   //ѭ�����Ա�Aÿ����Ԫ��
    {
        listA.GetElem(aPosition, temp);     //ȡ�����Ա�A�ĵ�ǰλ�õ�Ԫ��
        if(listB.IsExist(temp) == true)     //���listA��ȡ��������temp��listB��
        {
            listC.InList(temp);    //������temp����listC��ĩβ
        }
    }
    return listC;
}


//�������ƣ�SqList<ElemType> Difference(const Sqlist<ElemType> &listA, const SqList<ElemType> &listB)
//��ʼ�������������Ա�listA��listB������,
//����������isExist = false��, isExist = true�󽻼�
template <class ElemType>
SqList<ElemType> Difference(const SqList<ElemType> &listA, const SqList<ElemType> &listB, bool isExist/* = false*/)
{
    ElemType temp;
    SqList<ElemType> listC;

//listC.Clean( );     //����������
    for(int aPosition = 1; aPosition < listA.length; aPosition++)   //ѭ�����Ա�Aÿ����Ԫ��
    {
        listA.GetElem(aPosition, temp);     //ȡ�����Ա�A�ĵ�ǰλ�õ�Ԫ��
        if(listB.IsExist(temp) == isExist)     //���listA��ȡ��������temo����listB��
        {
            listC.InList(temp);    //������temp����listC��ĩβ
        }
    }
    return listC;
}

/**������������ʵ�֡�*******************************************************
    bool Full( ) const;      //�ж����Ա��Ƿ�����
    void Init(int size);     //��ʼ�����Ա�
********************************************************��ʵ�֡�������������*/

//�������ƣ�Full( ) const
//��ʼ���������Ա��Ѿ�����
//���������������Ա��������򷵻�True�����򷵻�False
template <class ElemType>
bool SqList<ElemType>::Full( ) const              //�ж����Ա��Ƿ�����
{
    return length == maxSize;
}


//�������ƣ�void Init( ) const
//��ʼ��������ʼ�����Ա�
//�����������ʼ�����Ա�Ϊ���Ԫ�ظ���Ϊsize�Ŀ����Ա�
template <class ElemType>
void SqList<ElemType>::Init(int size)
{
    maxSize = size;    //��ʼ�����Ա��СΪsize
    if(elems != NULL) delete elems;  //������Ա�ռ䱻ռ�ã����������
    elems = new ElemType(maxSize);   //���ٿռ�
    length = 0;   //��ǰԪ�ظ���Ϊ0
}


/**ģ���������Ա������ʵ�֡�**********************************************
    SqList(int size = DEFAULT_SIZE);            //���캯��ģ��
    SqList(const SqList<ElemType> &copy);       //��ֵ���캯��
    virtual ~SqList( );                         //����������ģ��
*********************************************��ʵ�֡�ģ���������Ա����**/

//�������ƣ�SqList(int size = DEFAULT_SIZE);
//��ʼ�����������������
//�������������һ�����Ԫ�ظ���Ϊsize�Ŀ�˳���
template <class ElemType>
SqList<ElemType>::SqList(int size)     //���캯��ģ��
{
    elems = NULL;     //˳��ռ�ָ���
    Init(size);       //��ʼ�����Ա�
}

//�������ƣ�SqList(const SqList<ElemType> &copy);
//��ʼ�����������������
//����������ɲ������Ա������ͬ�������Ա�
template <class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType> &copy)    //��ֵ���캯��
{
    maxSize = copy.maxSize;     //[����]�������Ա�����Ԫ�ظ���
    length = copy.length;       //[����]�������Ա��Ԫ�ظ���

    ElemType elem;
    Init(copy.maxSize);     //�Բ������Ա�����Ԫ�ظ�����ʼ��Ŀ�����Ա�

    for(int curPosition = 1; curPosition <= copy.length; curPosition++)   //ѭ�����Ƹ������Ա������Ԫ��
    {
        //����Ĳ����ȼ���this->elems[position-1] = copy.elems[position-1];
        copy.GetElem(curPosition, elem);            //ȡ���������Ա�ĵ�curPosition��Ԫ��, �洢��elems��
        this->SetElem(curPosition, elem);           //������elems����Ŀ�����Ա�ĵ�curPosition��λ��
        //this->Insert(curPosition, elems);         //Ҳ���Խ�����elems�������Ա�ĵ�curPosition��λ��

        //this->InList(elem);                       //���ǲ����Խ�Ԫ��ֱ���������Ա�
    }
}


//�������ƣ�virtual ~SqList( );
//��ʼ�������ѽ��������
//����������������Ա�
template <class ElemType>
SqList<ElemType>::~SqList( )    //����������ģ��
{
    if(elems != NULL)
    {
        delete elems;   //�ͷŴ洢�ռ�
    }
}

/**ģ����������Ա������ʵ�֡�*************************************************************
    int Length( ) const;             //��ȡ���Ա���
    int Size( ) const;             //��ȡ���Ա����󳤶�
    bool Empty( ) const;          //�ж����Ա��Ƿ�Ϊ��
    void Clean( );                             //������Ա�
    void Traverse(void(*visit)(const ElemType &)) const;//�������Ա�
    bool IsExist(const ElemType &elemType) const;   //�ж�����elemType�ڲ��ڵ�ǰ���Ա���
    StatusCode GetElem(int position, const ElemType &elemType);//��ȡָ��λ��position��Ԫ��
    StatusCode SetElem(int position, const ElemType &elemType);//����ָ��λ��position��Ԫ��
    StatusCode Delete(int position);    //ɾ��ָ��λ��position��Ԫ��
    StatusCode Insert(int position, const ElemType &elemType);//��ָ��λ��position����Ԫ��
    StatusCode InList(const ElemType &elemType);       //������elemType�������Ա��ĩβ
ģ����������Ա������ʵ�֡�***************************************************************/

//�������ƣ�int Length( ) const;
//��ʼ���������Ա��Ѿ�����
//����������������Ա�Ԫ�ظ���
template <class ElemType>
int SqList<ElemType>::Length( ) const         //��ȡ���Ա���
{
    return length;
}

//�������ƣ�int Size( ) const;
//��ʼ���������Ա��Ѿ�����
//����������������Ա����Ԫ�صĸ���
template <class ElemType>
int SqList<ElemType>::Size( ) const  //��ȡ���Ա����󳤶�
{
    return maxSize;
}

//�������ƣ�bool Empty( ) const;
//��ʼ���������Ա��Ѿ�����
//���������������Ա�Ϊ��, ����True�����򷵻�False
template <class ElemType>
bool SqList<ElemType>::Empty( ) const     //�ж����Ա��Ƿ�Ϊ��
{
    return (length == 0);
//    if(length == 0)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
}

//�������ƣ�void Clean( );
//��ʼ���������Ա����
//���������������Ա�
template <class ElemType>
void SqList<ElemType>::Clean( ) //������Ա�
{
    length = 0;    //ֻ�轫Ԫ�ظ�����Ϊ�ռ���, ����ɾ�����Ա��ڴ�ռ�
}

//�������ƣ�void Traverse(void(*visit)(const ElemType &)) const;
//��ʼ���������Ա��Ѿ�����
//������������ζ����Ա��ô��Ԫ�ص��ã�* visit��
template <class ElemType>
void SqList<ElemType>::Traverse(void(*visit)(const ElemType &)) const  //�������Ա�
{
    for(int position = 1; position <= length; position++)   //ѭ������
    {
        (* visit)(this->elems[position-1]);    //�����Ա��ÿ��Ԫ�ص��ú�����* visit��
    }
}

//�������ƣ�bool IsExist(const ElemType &elemType) const;
//��ʼ���������Ա��Ѵ���
//����������������elemType�����Ա���, ����True, ���򷵻�False
template <class ElemType>
bool SqList<ElemType>::IsExist(const ElemType &elemType) const   //�ж�����elemType�ڲ��ڵ�ǰ���Ա���
{
    if(length == 0)
    {
        return false;
    }
    //ElemType temp;
    for(int curPosition = 1; curPosition < length; curPosition++)   //ѭ��ÿ��Ԫ��
    {
        if(elems[curPosition-1] == elemType)
        {
            return true;   //����elemType�����Ա���
        }
//        this->GetElem(position, temp)
//        if(temp == elemType)
//        {
//            return true;
//        }
    }
    return false;
}

//�������ƣ�StatusCode GetElem(int position, const ElemType &elemType);
//��ʼ���������Ա��Ѵ���, 1<=position<=length
//�����������ȼ�����Ա��Ƿ��Ѿ��ÿ�, ����ǿյģ�����EMPTY_LIST,
//          Ȼ������±�position���Ϸ�����NOT_PRESENT,
//          ������elemType�������Ա��position��Ԫ�أ�����ENTRY_FOUND
template <class ElemType>
StatusCode SqList<ElemType>::GetElem(int position, ElemType &elemType)  //��ȡָ��λ��position��Ԫ��
{
//д����
    if(length == 0)
    {
        return NOT_STRUCT;     //���Ա�Ϊ��
    }

    if(position < 0 || position > length)    //����������Ϸ�
    {
        return NOT_PRESENT;
    }
    else      //��������position�ǺϷ���
    {
        elemType = elems[position-1];    //��elemType�������Ա�ĵ�position��Ԫ��, ��Ԫ���±�Ϊposition-1

        return ENTRY_FUOND;    //Ԫ�ش���
    }
////д����
//    if(position >= 1 && position <= length)
//    {
//        elems = elems[position-1];
//        return ENTEY_FOUND;
//    }
//    else
//    {
//        return NOT_PRESENT;
//    }
}

//�������ƣ�StatusCode SetElem(int position, const ElemType &elemType);
//��ʼ���������Ա��Ѵ���, 1<=position<=length
//��������: �ȼ�����Ա��Ƿ��Ѿ��ÿ�, ����ǿյģ�����EMPTY_LIST,
//          Ȼ�����position�Ϸ�ʱ�������Ա��position��Ԫ���޸�ΪelemType��
//          ������SUCCESS, ���򷵻�RANGE_ERROR
template <class ElemType>
StatusCode SqList<ElemType>::SetElem(int position, const ElemType &elemType)
{
    if(length = 0)
    {
        return NOT_STRUCT;   //���Ա�Ϊ��
    }

    if(position < 0 || position > length)    //����������Ϸ�
    {
        return RANGE_ERROR;   //�������Ϸ�
    }
    else      //����position�Ϸ�
    {
        elems[position-1] = elemType;    //��������Ӧ������ֵ�޸�ΪelemType
        return SUCCESS;
    }
}

//�������ƣ�StatusCode Delete(int position);
//��ʼ���������Ա����, 1<=position<=length
//����������������Ա�Ϊ�գ�����EMPTY_LIST,
//          Ȼ���������position���Ϸ�����RANGE_ERROR,
//          ����ɾ����ǰ���Ա���������Ӧ��Ԫ��, ����elemType������ֵ, ͬʱ����SUCCESS
template <class ElemType>
StatusCode SqList<ElemType>::Delete(int position, const ElemType &elemType)   //ɾ��ָ��λ��position��Ԫ��
{
    if(length == 0)
    {
        return NOT_STRUCT;      //���Ա�Ϊ��
    }

    if(position < 0 || position > length)
    {
        return RANGE_ERROR;
    }
    else
    {
        ElemType temp;
        elemType = elems[position-1];   //��elemType��������position��Ӧ��ֵ
        for(int curPosition = position+1; curPosition <= length; curPosition++)  //���ν�����position���������ǰ��һλ
        {
            this->GetElem(curPosition, temp);    //���浱ǰλ�õ�����
            this->SetElem(curPosition-1, temp);    //����ǰ�����ݲ��뵽ǰһ��λ��
        }
        length--;           //ɾ��position��Ԫ�غ����Ա��Ԫ�ظ�������1

        return SUCCESS;     //ɾ���ɹ�

//    //�������ѭ���ȼ۵Ĵ���΢�
//        for(int curPosition = position, curPosition <= length-1; curPosition++)
//        {
//            this->GetElem(curPosition+1, temp);    //���浱ǰλ����һλ������
//            this->SetElem(curPosition, temp);    //����һλ�����ݲ��뵽��ǰλ��
//        }
//    //�������ѭ���ȼ۵Ĵ���΢�
//        for(int curPosition = length; curPosition > position; curPosition--)
//        {
//            this->GetElem(curPosition, temp);    //���浱ǰλ�õ�����
//            this->SetElem(curPosition-1, temp);    //����ǰ�����ݲ��뵽ǰһ��λ��
//        }
//    //�������ѭ���ȼ۵Ĵ���΢�
//        for(int curPosition = length-1; curPosition >= position; curPosition--)
//        {
//            this->GetElem(curPosition+1, temp);    //���浱ǰλ�õ�����
//            this->SetElem(curPosition, temp);    //����ǰ�����ݲ��뵽ǰһ��λ��
//        }
    }
}

//�������ƣ�StatusCode Insert(int position, const ElemType &elemType);
//��ʼ���������Ա��Ѵ���, 1<=position<=length+1
//���������������elemType�������Ա�ĵ�position��λ��
//ʵ�ַ���: �ȼ�����Ա��Ƿ��Ѿ��ÿ�, ����ǿյģ�����EMPTY_LIST,
//          Ȼ�����position�Ϸ�ʱ��������elemType�������Ա�ĵ�position��λ��
//          ������SUCCESS, �������������Ա��Ϸ�����RANGE_ERROR
template <class ElemType>
StatusCode SqList<ElemType>::Insert(int position, const ElemType &elemType)
{
    if(length == 0)
    {
        return NOT_STRUCT;    //���Ա��ǿյ�
    }

    if(position < 0 || position >length+1)
    {
        return RANGE_ERROR;
    }
    else
    {
        ElemType temp;

        for(int curPosition = length; curPosition >= position; curPosition--)   //������Ŀ����Ժ���������κ���
        {
            this->GetElem(position, temp);   //���浱ǰλ�õ�����
            this->SetElem(position+1, temp); //����������������
        }
//     //�����ѭ���ȼ���
//        for(int curPosition = length+1; curPosition > position; curPosition++)
//        {
//            this->GetElem(position-1, temp);   //���浱ǰλ�õ�����
//            this->SetElem(position, temp); //����������������
//        }
       // elems[position-1] = elemType;   //������elemType�洢�����Ա�ĵ�position��λ��
        this->SetElem(position, elemType);  //ͬ��-������elemType�洢�����Ա�ĵ�position��λ��

        length++;    //���в�����ɺ�, �Ѿ�����һ������, ��ʱ���Ա��Ԫ�ظ�����1

        return SUCCESS;     //����ɹ�
    }
}

//�������ƣ�StatusCode InList(const ElemType &elemType);
//��ʼ���������Ա��Ѵ���, ��δ����[lenght < maxSize]
//���������������ж����Ա��Ƿ�����, �������, ����FULL_LIST,
//          Ȼ��Ԫ�ز��������Ա��ĩβ�� ������SUCCESS;
template <class ElemType>
StatusCode SqList<ElemType>::InList(const ElemType &elemType)       //������elemType�������Ա��ĩβ
{
    //if(lenth == maxSize)
    if(this->Full() == true)
    {
        return NOT_STRUCT;    //���Ա�����
    }

    elems[length] = elemType;   //������elemType�������Ա��ĩβ

    return SUCCESS;
}

/**���غ���������ʵ�֡�***************************************************************************
    SqList<ElemType> &operator=(const SqList<ElemType> &copy);      //��ֵ���������
    SqList<ElemType> &operator[](const int index);                 //�����±���ʺ���
***************************************************************************��ʵ�֡����غ�������**/

//�������ƣ�SqList<ElemType> &operator=(const SqList<ElemType> &copy);      //��ֵ���������
//��ʼ����������ֵ��this�͸�ֵ��copy���Ѵ���
//��������������Ա�ֵ����ǰĿ�����Ա�
template <class ElemType>
SqList<ElemType> Sqlist<ElemType>::&operator=(const SqList<ElemType> &copy)
{
    if(copy == this)                // �������ֵ�����Ա�copy��Ŀ�����Ա���ͬһ����
    {
        return *this;               //  ֱ�ӷ��ص�ǰ���Ա�
    }

    if(copy.Empty( ) == true)       // ���������ֵ��copy�Ǹ��մ�
    {
        this->Clean( );             //ֱ�Ӱ�Ŀ�����Ա����
        return *this;               //���ص�ǰĿ�����Ա����
    }

    this->Init(copy.maxSize);       // �Ը�ֵ���Ա����Ϣ��ʼ����ǰĿ�����Ա�
//    ElemType temp;
    for(int position = 1; position <= copy.length; position++)  // ѭ��������ֵ����copy��ÿ������Ԫ��
    {
        this->elems[position-1] = copy.elems[position-1];       // �����Ա�copy�ĵ�position��Ԫ�ظ�ֵ��Ŀ�����Ա�*this�ĵ�position���ַ���
//        copy.GetElem(position, temp);   // ȡ����ֵ���Ա�ĵ�position��Ԫ��
//        this->SetElem(position, temp);   // ��ȡ����Ԫ������Ŀ�����Ա�ĵ�position��λ��
    }

   // this->maxSize = copy.maxSize;       // ȷ��Ŀ�����Ա�����Ԫ�ظ��������Ϣ
    this->length = copy.length;         // ȷ��Ŀ�����Ա��Ԫ�ظ���

    return *this;            // ���ص�ǰĿ�����Ա�
}

//�������ƣ�SqList<ElemType> &operator[](const SqList<ElemType> &copy);      //��ֵ���������
//��ʼ����������ֵ��this�͸�ֵ��copy���Ѵ���
//��������������Ա�ֵ����ǰĿ�����Ա�
/**���⺯��ģ��[����Sort]��ʵ�֡�*****************************************************************
    StatusCode Swap(int mPosition, int nPosition);//�������Ա��mPosition��Ԫ�غ͵�nPosition��Ԫ��
    StatusCode BubbleSort(bool minTomax = true);     //ð�ݷ�����
    StatusCode SelectSort(boolminTomax = true);      //ѡ������
*****************************************************************��ʵ�֡����⺯��ģ��[����Sort]**/
//�������ƣ�StatusCode SqList<ElemType>::Swqp(int &mPosition, int &nPosition)
//��ʼ���������Ա����, ��mPosition��nPosition����Ҫ��
//����������������Ա��е�mPosition���͵�nPosition��Ԫ��
template <class ElemType>
StatusCode SqList<ElemType>::Swap(int &mPosition, int &nPosition)
{
    if((mPosition < 0 || mPosition > length)
     || (nPosition < 0 || nPosition > length))
    {
        return NOT_STRUCT;
    }
    ElemType temp;
    temp = elems[mPosition];
    elems[mPosition] = elems[nPosition];
    elems[nPosition] = temp;
}
//StatusCode SqList<ElemType>::Swqp(int mPosition, int nPosition)
//{
//    ElemType temp;
//    temp = elems[mPosition];
//    elems[mPosition] = elems[nPosition];
//    elems[nPosition] = temp;
//}
//StatusCode SqList<ElemType>::Swqp(int *mPosition, int *nPosition)
//{
//    ElemType temp;
//    temp = elems[*mPosition];
//    elems[*mPosition] = elems[*nPosition];
//    elems[*nPosition] = temp;
//}


//�������ƣ�StatusCode SqList<ElemType>::BubbleSort(bool minTomax = true)
//��ʼ���������Ա��Ѿ�����, ���Ҳ��ǿմ�
//������������Ա�����ݻ�������������[��С����OR�Ӵ�С]
template <class ElemType>
StatusCode SqList<ElemType>::BubbleSort(bool minTomax/*= true*/)
{
    if(length == 0)
    {
        return NOT_STRUCT;     //�Կմ�����ִ���������
    }
    //��ð�ݷ�д����������ð�ݷ����³�
    for(int j = 1; j < this->length; j++)     //���ƽ���lengh-1�αȽ�
    {
        for(int i = 1; i < this->length-j; i++)     //�ӵ�һ������ʼһֱ�Ƚϵ���
        {
            if(((elems[i] > elems[i+1]) && (minTomax == true))    //��ʱ��С��������
              || ((elems[i] < elems[i+1]) && (minTomax == false)))   //��ʱ�Ӵ�С����
            {
                this->Swap(i, i+1);   //����:������i�����ݺ͵�i+1������, �������i�������³�һλ��Ϊ��i+1����
            }
            //Ȼ��i++, ��ǰ�͵��˵�i+1����[Ҳ����ԭ����i����], Ȼ��������������ж�
            //һֱ������������ͷ����˵�ǰѭ�����һ��λ��, Ҳ���ǵ�length-1-j��λ��
        }
    }

    return SUCCESS;


//    //��ð�ݷ�д����������ð�ݷ�������
//    for(int j = 1; j < this->length; j++)
//    {
//        for(int i = length; i > j+1; i--)
//        {
//            if(((elems[i] < elems[i-1]) && (minTomax == true))     //��ʱ��С����
//              || ((elems[i] > elems[i-1]) && (minTomax == false)))  //��ʱ�Ӵ�С
//            {
//                this->Swap(i, i-1);     //������������i�������i-1����, �������ʱ���i������������һλ, ��Ϊ��i-1����
//
//            }
//            //Ȼ��i--, ��ǰ�͵��˵�i����[Ҳ����ԭ����i����], Ȼ��������������ж�
//            //һֱ������������ͷ����˵�ǰѭ�����һ��λ��, Ҳ���ǵ�length-1-j��λ��
//        }
//    }
}


//�������ƣ�StatusCode SqList<ElemType>::SelectSort(bool minTomax = true)
//��ʼ���������Ա��Ѿ�����, ���Ҳ��ǿմ�
//������������Ա�����ݻ�������������[��С����OR�Ӵ�С]
template <class ElemType>
StatusCode SqList<ElemType>::SelectSort(bool minTomax/*= true*/)      //ѡ������
{
    if(length == 0)
    {
        return NOT_STRUCT;      //�Կմ�����ִ���������
    }
    for(int i = 1; i < this->length; i++)    //ѭ�����Ա��ÿ��ǰ����
    {
        int k = i;        //���浱ǰѭ�������λ��
        for(int j = i+1; j < this->length; j++)   //ѭ�����Ա��ÿһ����Ԫ��
        {
            if(((elems[j] < elems[k]) && (minTomax == true))  //��С����
              || ((elems[j] > elems[k]) && (minTomax == false))) //�Ӵ�С
            {
                k = j;    //���浱ǰ��ֵӵ�����±�
            }
        }      //����ѭ��һ���Ժ�, k�ͱ����˵�ǰ��ֵ���±�
        if(k != i)
        {
            this->Swap(k , i);
        }
    }
    return SUCCESS;           // ����ɹ�
}




#endif // SQLIST_H_INCLUDED


