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

�汾1.0.0   �����2012/9/4 20:25�����ⲿ�����ļ�Other
            ����ʵ��SqList.h�ļ��Ļ�������, ���ұ���ͨ��...
********************************************************************************/


#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED



#include <cstdio>
//#include <iostream>
//using namespace std;


//#define DEBUG                     // ������е����뽫��ע�ʹ�
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
    SqList(int size = 100);            //���캯��ģ��   //��ͷ�ļ���DEFAULT_SIZE�궨��Ϊ1000

    SqList(const SqList<ElemType> &copy);       //��ֵ���캯��ģ��

    virtual ~SqList( );                         //����������ģ��
//ģ����������Ա��������
    int Length( ) const;                       //��ȡ���Ա���

    int Size( ) const;                          //��ȡ���Ա����󳤶�

    bool Empty( ) const;                       //�ж����Ա��Ƿ�Ϊ��

    void Clean( );                             //������Ա�

    bool SetLength(int len);                    // �����������Ա�ı�

    bool Reset(int size);                              // �������Ա�Ԫ

    bool Traverse(void(*visit)(const ElemType &));     //�������Ա�

    bool IsExist(const ElemType &elemType) const;   //�ж�����elemType�ڲ��ڵ�ǰ���Ա���

    bool GetElem(int position, ElemType &elemType);  //���ָ��λ��position��Ԫ��

    bool SetElem(int position, const ElemType &elemType);   //����ָ��λ��position��Ԫ��

    bool Delete(int position, ElemType &elemType);               //ɾ��ָ��λ��position��Ԫ��

    bool Insert(int position, const ElemType &elemType);   //��ָ��λ��position����Ԫ��

    bool InList(const ElemType &elemType);       //������elemType�������Ա��ĩβ

//���غ�������
    SqList<ElemType> &operator=(const SqList<ElemType> &copy);      //��ֵ���������

    SqList<ElemType> &operator[](const int index);                 //�����±���ʺ���

//���⺯��ģ��[����Sort]
    bool Swap(int mPosition, int nPosition);    //�������Ա��mPosition��Ԫ�غ͵�nPosition��Ԫ��

    bool BubbleSort(bool minTomax = true);     //ð�ݷ�����

    bool SelectSort(bool minTomax = true);      //ѡ������

/*===========================[PUBLIC-=>�����ӿ�]===========================*/


/*==========================[PROTECTED-=>��������]==========================*/
  protected :
//������������
    /// �û��޷��鿴�������Ա��Ƿ�Ϊ��
    bool Full( ) const;      //�ж����Ա��Ƿ�����
    /// ������bool Reset( )��SqList( )�о�ʹ����Init����������Ʒ�����˴˽ӿ�
    void Init(int size = 100);      //��ʼ�����Ա�
//�������ݳ�Ա
    int length;                                 //���Ա�Ԫ�ظ���
    int maxSize;                                //˳������Ԫ�ظ���
    ElemType *elems;                           //Ԫ�ش洢�ռ�
   // enum bool = {RANGE_ERROR, EMPTY_ERROE, true, FULL_lIST};
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
void SqList<ElemType>::Init(int size/**/)
{
    maxSize = size;    //��ʼ�����Ա��СΪsize
    if(elems != NULL) delete elems;  //������Ա�ռ䱻ռ�ã����������
    elems = new ElemType[maxSize];   //���ٿռ�
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
   // elems = NULL;     //˳��ռ�ָ���
   // Init(size);       //��ʼ�����Ա�
	maxSize = size;						// ���Ԫ�ظ���
	//if (elems != NULL) delete []elems;	// �ͷŴ洢�ռ�
	elems = new ElemType[maxSize];		// ����洢�ռ�
	length = 0;							// �����Ա�Ԫ�ظ���Ϊ0
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
    bool Reset( );                              // �������Ա�Ԫ
    bool Acquire(void(*visit)(const ElemType &))
    bool Traverse(void(*visit)(const ElemType &)) const;//�������Ա�
    bool IsExist(const ElemType &elemType) const;   //�ж�����elemType�ڲ��ڵ�ǰ���Ա���
    bool GetElem(int position, const ElemType &elemType);//��ȡָ��λ��position��Ԫ��
    bool SetElem(int position, const ElemType &elemType);//����ָ��λ��position��Ԫ��
    bool Delete(int position);    //ɾ��ָ��λ��position��Ԫ��
    bool Insert(int position, const ElemType &elemType);//��ָ��λ��position����Ԫ��
    bool InList(const ElemType &elemType);       //������elemType�������Ա��ĩβ
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
void SqList<ElemType>::Clean( ) // ������Ա�
{
    length = 0;    //ֻ�轫Ԫ�ظ�����Ϊ�ռ���, ����ɾ�����Ա��ڴ�ռ�
}


//�������ƣ�bool SetLength(int len);
//��ʼ���������Ա����, lenֵ����Ҫ��
//��������������������Ա��
template <class ElemType>
bool SqList<ElemType>::SetLength(int len)		                 // �������Ա�ı�
{
    if(len > this->maxSize)
	{
	    std::cout <<"�������Ա����󳤶�" <<std::endl;
	    return false;
	}
	else if(len < this->length)
	{
		char answer;
	    std::cout <<"��Ҫ���ĵı�С�ڵ�ǰ���Ա�ı�" <<std::endl;
        std::cout <<"�������Ŀ��ܻ���ʧ����, �Ƿ����?(y/n)" <<std::endl;
		while( 1 )
		{
			answer = getchar();
			if(answer == 'y' || answer == 'Y')
			{
			    std::cout <<"�û�ȷ��, ���ĳɹ�" <<std::endl;
				length = len;
				return true;
			}
			else if(answer == 'n' || answer == 'N')
			{
			    std::cout <<"�û�ȡ��, �ɹ��˳�"  <<std::endl;
			    return  false;
			}
		}
	}
	this->length = len;
	std::cout <<"������Ϸ�, �ɹ��޸����Ա�Ϊ" <<this->length <<std::endl;

	return true;
}


//�������ƣ�bool Reset(int size)
//��ʼ���������Ա����
//�������������û��ش���, ��ɾ��ԭ���ĵ�Ԫ�������µĵ�Ԫ
template <class ElemType>
bool SqList<ElemType>::Reset(int size/*= maxSize*/)                              // �������Ա�Ԫ
{
    std::cout <<"��ǰ���Ա�����Ϊ" <<this->maxSize <<"�Ѿ��洢��" <<this->length <<"������" <<std::endl <<std::endl;
    if(size == this->maxSize)   // �����ǰ�����Ա����Ŀ�����ǵ�ǰ�Ĳ���
    {
        std::cout <<"���õ�Ԫ��С��ԭ��Ԫ��С��ͬ, ����Ҫ����." <<std::endl;
        return false;
    }
    else
    {
        std::cout <<"�����������Ҫ���ô˵�Ԫô?" <<std::endl;

        char ch;
        bool answer = true;      // ��ʼ��������ԪΪfalse
        do
        {	// ѭ��ֱ���û�����ǡ���Ļش�Ϊֹ
            if (answer)
            {	// ��ʼ�ش�
                std::cout << "(y, n)?";
            }
            else
            {	// �ǳ�ʼ�ش�
                std::cout << "��y��n�ش�:";
            }

            while ((ch = getchar( )) == '\n');	// �����ո�,�Ʊ�������з���ȡһ�ַ�
            answer = false;
        }while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');

        if(ch == 'n' || ch == 'N')
        {
            std::cout <<"�û�ȡ������..." <<std::endl;
            return false;
        }
        else
        {
            std::cout <<"���ÿ�ʼ..." <<std::endl;
            this->Init(size);   // ��ʼ����Ԫ

//            if(this->elems != NULL)
//            {
//                delete[] elems;     // ɾ��ԭ�е��ڴ浥Ԫ
//            }
//            elems = new elems[size];  // �����µ�Ԫ
//            this->maxSize = size;     // ����
//            this->length = 0;
        }
    }
}


//�������ƣ�void Traverse(void(*visit)(const ElemType &));
//��ʼ���������Ա��Ѿ�����
//������������ζ����Ա��ô��Ԫ�ص��ã�* visit��

template <class ElemType>
bool SqList<ElemType>::Traverse(void (*visit)(const ElemType &))
{
    if(this->length == 0)
    {
        std::cout <<"��ǰ���Ա�Ϊ��, �޷�ʵ�ֱ���..." <<std::endl;   // ������Ϣ��ʾ
        return false;
    }
	for (int curPosition = 1; curPosition <= Length(); curPosition++)
	{	// �����Ա��ÿ��Ԫ�ص��ú���(*visit)
		(*visit)(elems[curPosition - 1]);
        return true;
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

//�������ƣ�bool GetElem(int position, const ElemType &elemType);
//��ʼ���������Ա��Ѵ���, 1<=position<=length
//�����������ȼ�����Ա��Ƿ��Ѿ��ÿ�, ����ǿյģ�����EMPTY_LIST,
//          Ȼ������±�position���Ϸ�����NOT_PRESENT,
//          ������elemType�������Ա��position��Ԫ�أ�����ENTRY_FOUND
template <class ElemType>
bool SqList<ElemType>::GetElem(int position, ElemType &elemType)  //��ȡָ��λ��position��Ԫ��
{
//д����
    if(length == 0)
    {
        std::cout <<"��ǰ���Ա�Ϊ��, �޷���ȡ��" <<position <<"��Ԫ�ص���Ϣ" <<std::endl;
        return false;     //���Ա�Ϊ��
    }

    if(position < 1 || position > length)    //����������Ϸ�
    {
        if(position < 1)
        {
            std::cout <<"����" <<position <<"Ϊ��..." <<std::endl;
        }
        else
        {
            std::cout <<"��ǰ���Ա�" <<this->length <<", ����" <<position <<"Խ��..." <<std::endl;
        }
        return false;
    }
    else      //��������position�ǺϷ���
    {
        elemType = elems[position-1];    //��elemType�������Ա�ĵ�position��Ԫ��, ��Ԫ���±�Ϊposition-1

        return true;    //Ԫ�ش���
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

//�������ƣ�bool SetElem(int position, const ElemType &elemType);
//��ʼ���������Ա��Ѵ���, 1<=position<=length
//�������: �����Ա��position��Ԫ���޸�ΪelemType��
//ʵ�ַ������ȼ�����Ա��Ƿ��Ѿ��ÿ�, ����ǿյģ�����false,
//          Ȼ�����position�Ϸ�ʱ�������Ա��position��Ԫ���޸�ΪelemType��
//          ������true, ���򷵻�false
template <class ElemType>
bool SqList<ElemType>::SetElem(int position, const ElemType &elemType)
{
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"����SetElem..." <<std::endl;
#endif
///��Ϊ����ע�͵��Ĵ���, �ҵĳ��������һ���ǳ��޴�Ĵ���
//    if(length = 0)
//    {
//        std::cout <<"��ǰ���Ա�Ϊ��,�޷��޸ĵ�" <<position <<"��Ԫ�ص���Ϣ" <<std::endl;
//        return false;   //���Ա�Ϊ��
//    }
    if(position < 1 || position > length+1)    //����������Ϸ�
    {
        if(position < 1)
        {
            std::cout <<"����" <<position <<"Ϊ��..." <<std::endl;
        }
        else
        {
            std::cout <<"��ǰ���Ա�" <<this->Length( ) <<", ����" <<position <<"Խ��..." <<std::endl;
        }
        return false;   //�������Ϸ�
    }
    else      //����position�Ϸ�
    {
        elems[position-1] = elemType;    //��������Ӧ������ֵ�޸�ΪelemType
        return true;
    }
}

//�������ƣ�bool Delete(int position);
//��ʼ���������Ա����, 1<=position<=length
//���������ɾ����ǰ���Ա���������Ӧ��Ԫ��
//ʵ�ַ������������Ա�Ϊ�գ�����EMPTY_LIST,
//          Ȼ���������position���Ϸ�����RANGE_ERROR,
//          ����ɾ����ǰ���Ա���������Ӧ��Ԫ��, ����elemType������ֵ, ͬʱ����true
template <class ElemType>
bool SqList<ElemType>::Delete(int position, ElemType &elemType)   //ɾ��ָ��λ��position��Ԫ��
{
    if(length == 0)
    {
        std::cout <<"���Ա�Ϊ��, �޷�ɾ����" <<position <<"��Ԫ�ص���Ϣ" <<std::endl;
        return false;      //���Ա�Ϊ��
    }
    if(position < 1 || position > length)
    {
        if(position < 1)
        {
            std::cout <<"����" <<position <<"Ϊ��Ϊ��..." <<std::endl;
        }
        else
        {
            std::cout <<"��ǰ���Ա�" <<this->length <<", ����" <<position <<"Խ��..." <<std::endl;
        }
        return false;
    }
    else
    {
        ElemType temp;
        //elemType = elems[position-1];   //��elemType��������position��Ӧ��ֵ
        this->GetElem(position, elemType);
        for(int curPosition = position+1; curPosition <= length; curPosition++)  //���ν�����position���������ǰ��һλ
        {
            this->GetElem(curPosition, temp);    //���浱ǰλ�õ�����
            this->SetElem(curPosition-1, temp);    //����ǰ�����ݲ��뵽ǰһ��λ��
        }
        length--;           //ɾ��position��Ԫ�غ����Ա��Ԫ�ظ�������1

        return true;     //ɾ���ɹ�

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

//�������ƣ�bool Insert(int position, const ElemType &elemType);
//��ʼ���������Ա��Ѵ���, 1<=position<=length+1
//���������������elemType�������Ա�ĵ�position��λ��
//ʵ�ַ���: �ȼ�����Ա��Ƿ��Ѿ��ÿ�, ����ǿյģ�����EMPTY_LIST,
//          Ȼ�����position�Ϸ�ʱ��������elemType�������Ա�ĵ�position��λ��
//          ������true, �������������Ա��Ϸ�����RANGE_ERROR
template <class ElemType>
bool SqList<ElemType>::Insert(int position, const ElemType &elemType)
{
#if defined DEBUG           // ����궨����DEBUG, ִ��һ�����
std::cout <<"����Insert..." <<std::endl;
#endif

    if(this->Full())
    {
        std::cout <<"���Ա�����, �޷���������Ԫ��" <<std::endl;
        return false;
    }
    else if(position < 1 || position > this->length+1)
    {
        if(position < 1)
        {
            std::cout <<"����" <<position <<"Ϊ����߸�..." <<std::endl;
        }
        else
        {
            std::cout <<"��ǰ���Ա�" <<this->Length() <<", ����" <<position <<"Խ��..." <<std::endl;
        }
        return false;
    }
    else
    {

        ElemType temp;
        if(length == 0)
        {
            this->SetElem(1, elemType);
            length++;
            return true;
        }

        for(int curPosition = this->length; curPosition >= position; curPosition--)   //������Ŀ����Ժ���������κ���
        {
            this->GetElem(curPosition, temp);   //���浱ǰλ�õ�����
            this->SetElem(curPosition+1, temp); //����������������
        }
//     //�����ѭ���ȼ���
//        for(int curPosition = length+1; curPosition > position; curPosition++)
//        {
//            this->GetElem(position-1, temp);   //���浱ǰλ�õ�����
//            this->SetElem(position, temp); //����������������
//        }
       // elems[position-1] = elemType;   //������elemType�洢�����Ա�ĵ�position��λ��
        this->SetElem(position, elemType);  //ͬ��-������elemType�洢�����Ա�ĵ�position��λ��
        this->length++;    //���в�����ɺ�, �Ѿ�����һ������, ��ʱ���Ա��Ԫ�ظ�����1
        return true;     //����ɹ�
    }
}

//�������ƣ�bool InList(const ElemType &elemType);
//��ʼ���������Ա��Ѵ���, ��δ����[lenght < maxSize]
//���������������ж����Ա��Ƿ�����, �������, ����FULL_LIST,
//          Ȼ��Ԫ�ز��������Ա��ĩβ�� ������true;
template <class ElemType>
bool SqList<ElemType>::InList(const ElemType &elemType)       //������elemType�������Ա��ĩβ
{
    //if(lenth == maxSize)
    if(this->Full() == true)
    {
        std::cout <<"��ǰ���Ա�����, �޷������ݲ���β��.." <<std::endl;
        return false;    //���Ա�����
    }

    elems[length] = elemType;   //������elemType�������Ա��ĩβ
    this->length++;
   // this->SetElem(++length, elemType);


    return true;
}

/**���غ���������ʵ�֡�***************************************************************************
    SqList<ElemType> &operator=(const SqList<ElemType> &copy);      //��ֵ���������
    SqList<ElemType> &operator[](const int index);                 //�����±���ʺ���
***************************************************************************��ʵ�֡����غ�������**/

//�������ƣ�SqList<ElemType> &operator=(const SqList<ElemType> &copy);      //��ֵ���������
//��ʼ����������ֵ��this�͸�ֵ��copy���Ѵ���
//��������������Ա�ֵ����ǰĿ�����Ա�
template <class ElemType>
SqList<ElemType>& SqList<ElemType>::operator=(const SqList<ElemType> &copy)
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
    bool Swap(int mPosition, int nPosition);//�������Ա��mPosition��Ԫ�غ͵�nPosition��Ԫ��
    bool BubbleSort(bool minTomax = true);     //ð�ݷ�����
    bool SelectSort(boolminTomax = true);      //ѡ������
*****************************************************************��ʵ�֡����⺯��ģ��[����Sort]**/
//�������ƣ�bool Swqp(int &mPosition, int &nPosition)
//��ʼ���������Ա����, ��mPosition��nPosition����Ҫ��
//����������������Ա��е�mPosition���͵�nPosition��Ԫ��
template <class ElemType>
bool SqList<ElemType>::Swap(int mPosition, int nPosition)
{
    if((mPosition < 0 || mPosition > length)
     || (nPosition < 0 || nPosition > length))
    {
        std::cout <<"�����±겻�Ϸ�" <<std::endl;
        return false;
    }
    ElemType temp;
    temp = elems[mPosition-1];
    elems[mPosition-1] = elems[nPosition-1];
    elems[nPosition-1] = temp;

    return true;
}
//bool SqList<ElemType>::Swqp(int mPosition, int nPosition)
//{
//    ElemType temp;
//    temp = elems[mPosition];
//    elems[mPosition] = elems[nPosition];
//    elems[nPosition] = temp;
//}
//bool SqList<ElemType>::Swqp(int *mPosition, int *nPosition)
//{
//    ElemType temp;
//    temp = elems[*mPosition];
//    elems[*mPosition] = elems[*nPosition];
//    elems[*nPosition] = temp;
//}


//�������ƣ�bool SqList<ElemType>::BubbleSort(bool minTomax = true)
//��ʼ���������Ա��Ѿ�����, ���Ҳ��ǿմ�
//������������Ա�����ݻ�������������[��С����OR�Ӵ�С]
template <class ElemType>
bool SqList<ElemType>::BubbleSort(bool minTomax/*= true*/)
{
    if(length == 0)
    {
        std::cout <<"��ǰ���Ա�Ϊ��, �޷������������..." <<std::endl;
        return false;     //�Կմ�����ִ���������
    }
    //��ð�ݷ�д����������ð�ݷ����³�
    for(int j = 0; j < this->length-1; j++)     //���ƽ���lengh-1�αȽ�
    {
        for(int i = 0; i < this->length-j-1; i++)     //�ӵ�һ������ʼһֱ�Ƚϵ���
        {
            if(((elems[i] > elems[i+1]) && (minTomax == true))    //��ʱ��С��������
              || ((elems[i] < elems[i+1]) && (minTomax == false)))   //��ʱ�Ӵ�С����
            {
                this->Swap(i+1, i+2);   //����:������i�����ݺ͵�i+1������, �������i�������³�һλ��Ϊ��i+1����
            }
            //Ȼ��i++, ��ǰ�͵��˵�i+1����[Ҳ����ԭ����i����], Ȼ��������������ж�
            //һֱ������������ͷ����˵�ǰѭ�����һ��λ��, Ҳ���ǵ�length-1-j��λ��
        }
    }
//    ElemType lastItem, nextItem;
//    for(int j = 1; j < this->length; j++)     //���ƽ���lengh-1�αȽ�
//    {
//        for(int i = 1; i < this->length-j; i++)     //�ӵ�һ������ʼһֱ�Ƚϵ���
//        {
//            this->GetElem(i, lastItem);
//            this->GetElem(i+1, nextItem);
//            if(((lastItem > nextItem) && (minTomax == true))    //��ʱ��С��������
//              || ((lastItem < nextItem) && (minTomax == false)))   //��ʱ�Ӵ�С����
//            {
//                this->Swap(i, i+1);   //����:������i�����ݺ͵�i+1������, �������i�������³�һλ��Ϊ��i+1����
//            }
//            //Ȼ��i++, ��ǰ�͵��˵�i+1����[Ҳ����ԭ����i����], Ȼ��������������ж�
//            //һֱ������������ͷ����˵�ǰѭ�����һ��λ��, Ҳ���ǵ�length-1-j��λ��
//        }
//    }
    return true;


//    //��ð�ݷ�д����������ð�ݷ�������
//    for(int j = 0; j < this->length-1; j++)
//    {
//        for(int i = length-1; i > j; i--)
//        {
//            if(((elems[i-1] < elems[i]) && (minTomax == true))     //��ʱ��С����
//              || ((elems[i-1] > elems[i]) && (minTomax == false)))  //��ʱ�Ӵ�С
//            {
//                this->Swap(i+1, i);     //������������i�������i-1����, �������ʱ���i������������һλ, ��Ϊ��i-1����
//
//            }
//            //Ȼ��i--, ��ǰ�͵��˵�i����[Ҳ����ԭ����i����], Ȼ��������������ж�
//            //һֱ������������ͷ����˵�ǰѭ�����һ��λ��, Ҳ���ǵ�length-1-j��λ��
//        }
//    }
}


//�������ƣ�bool SqList<ElemType>::SelectSort(bool minTomax = true)
//��ʼ���������Ա��Ѿ�����, ���Ҳ��ǿմ�
//������������Ա�����ݻ�������������[��С����OR�Ӵ�С]
template <class ElemType>
bool SqList<ElemType>::SelectSort(bool minTomax/*= true*/)      //ѡ������
{
    if(length == 0)
    {
        std::cout <<"��ǰ���Ա�Ϊ��, �޷������������" <<std::endl;
        return false;      //�Կմ�����ִ���������
    }

    for(int i = 0; i < this->length-1; i++)    //ѭ�����Ա��ÿ��ǰ����
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
            this->Swap(k+1 , i+1);
        }
    }

//    ElemType itemJ, itemK;
//    for(int i = 1; i < this->length; i++)    //ѭ�����Ա��ÿ��ǰ����
//    {
//        int k = i;        //���浱ǰѭ�������λ��
//        for(int j = i+1; j < this->length; j++)   //ѭ�����Ա��ÿһ����Ԫ��
//        {
//            this->GetElem(j, itemJ);
//            this->GetElem(k, itemK);
//            if(((itemJ < itemK) && (minTomax == true))  //��С����
//              || ((itemJ > itemK) && (minTomax == false))) //�Ӵ�С
//            {
//                k = j;    //���浱ǰ��ֵӵ�����±�
//            }
//        }      //����ѭ��һ���Ժ�, k�ͱ����˵�ǰ��ֵ���±�
//        if(k != i)
//        {
//            this->Swap(k , i);
//        }
//    }
    return true;           // ����ɹ�
}




#endif // SQLIST_H_INCLUDED


