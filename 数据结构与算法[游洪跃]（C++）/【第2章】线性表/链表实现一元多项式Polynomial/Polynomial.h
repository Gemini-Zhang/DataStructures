/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  :��00��ACMģ��
Description:
Author     : Gatie_Me
Version    : �汾����
Data_Time  : 20112-8-4 15:36:24
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
********************************************************************************/

#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED


#include "LinkList.h"
#include "PolyItem.h"


#define DEBUG       // ���������Ϣ

/// ����������������
class Polynomail
{
/*============================[PUBLIC-=>�����ӿ�]============================*/
  protected:        // ������Ա
    LinkList<PolyItem> polyList;        // ����ʽ��ɵ����Ա�
/*============================[PUBLIC-=>�����ӿ�]============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
////////////////////////////////////////////////////////////////////////////////
/*===========================[PROTECTED-=>������Ա]===========================*/

  public  :// �����ӿ�
    // ����ʽ�������Ա����[����]
    Polynomail( );                // �޲�������ʽ�๹�캯��

    Polynomail(const Polynomail &copy); // ���ƹ��캯��

    Polynomail(const LinkList<PolyItem> &copyLinkList); // �ɶ���ʽ��ɵ����Ա������ʽ

    ~Polynomail( );                // ��������

    // �����������[����]
    int Length( ) const;                // �����ʽ������

    bool IsZero( ) const;               // �ж϶���ʽ�Ƿ�Ϊ0

    void SetZero( );                    // ������ʽ��0

    void Display( );                    // ��ʾ����ʽ

    void InsItem(const PolyItem &item); // ����һ��

    Polynomail operator+(const Polynomail &polynomail) const; // �ӷ����������

    Polynomail operator-(const Polynomail &Polynomail) const; // ���������

    Polynomail operator*(const Polynomail &Polynomail) const; // �˷������

    // �������������
    Polynomail &operator=(const Polynomail &copy);      // ��ֵ���������

    Polynomail &operator=(const LinkList<PolyItem> &copyLinkList);  // ��ֵ���������
/*===========================[PROTECTED-=>������Ա]]==========================*/
};





/// ����ʽ��Polynomial���岿��
/**����ʽ�������Ա����[ʵ��]*************************************************************
    Polynomail( );                // �޲�������ʽ�๹�캯��
    Polynomail(const Polynomail &copy); // ���ƹ��캯��
    Polynomail(const LinkList<PolyItem> &copyLinkList); // �ɶ���ʽ��ɵ����Ա������ʽ
    ~Polynomail( );                // ��������
*************************************************************[ʵ��]����ʽ�������Ա����**/
// �������ƣ�Polynomail( );                // �޲�������ʽ�๹�캯��
// ��ʼ��������ǰ����ʽδ����
// �������������һ���յĶ���ʽ��Ϣ
Polynomail::Polynomail( )                // �޲�������ʽ�๹�캯��
: polyList( )       // ֱ�ӽ���һ���յĶ���ʽ����
{
}

// �������ƣ�Polynomail(const Polynomail &copy);
// ��ʼ��������ǰ����ʽδ����
// �������������һ�����������ʽ��ȫ��ͬ�Ķ���ʽ
Polynomail::Polynomail(const Polynomail &copy)      // ���ƹ��캯��
: polyList(copy.polyList)                // ֱ�ӵ��ö����Ա�ĸ��ƹ��캯��
{
}

// �������ƣ�Polynomail(const LinkList<PolyItem> &copyLinkList); // �ɶ���ʽ��ɵ����Ա������ʽ
// ��ʼ��������ǰ����ʽδ����
// �������������һ���յĶ���ʽ��Ϣ
Polynomail::Polynomail(const LinkList<PolyItem> &copyLinkList)
: polyList(copyLinkList)
{
}

// �������ƣ�~Polynomail( );
// ��ʼ��������ǰ����ʽδ����
// �������������һ���յĶ���ʽ��Ϣ
Polynomail::~Polynomail( )            // ��������
{
}



/**�����������[ʵ��]**********************************************************************
    int Length( ) const;                // �����ʽ������
    bool IsZero( ) const;               // �ж϶���ʽ�Ƿ�Ϊ0
    void SetZero( );                    // ������ʽ��0
    void Display( );                    // ��ʾ����ʽ
    void InsItem(const PolyItem &item); // ����һ��
    Polynomail operator+(const Polynomail &polynomail) const; // �ӷ����������
    Polynomail operator-(const Polynomail &Polynomail) const; // ���������
    Polynomail operator*(const Polynomail &Polynomail) const; // �˷������
**********************************************************************[ʵ��]�����������**/
// �������ƣ�int Length( ) const;
// ��ʼ��������ʽ����ʽ�Ѿ�����
// ���������������ʽ����ʽ�ĳ���
int Polynomail::Length( ) const           // �����ʽ������
{
    return polyList.Length( );      // �������Զ���ʽ�ı�
}


// �������ƣ�bool IsZero( ) const;               // �ж϶���ʽ�Ƿ�Ϊ0
// ��ʼ��������ʽ����ʽ�Ѿ�����
// ����������������ʽΪ0, ����True, ����Ϊ����False
bool Polynomail::IsZero( ) const        // �ж϶���ʽ�Ƿ�Ϊ0
{
#ifdef DEBUG
std::cout <<"InZero..." <<std::endl;
#endif
    int length = this->Length( );   // �ȼ��㵱ǰ����ʽ������

    if(length == 0)
    {
        std::cout <<"��ǰ����ʽΪ��, �޷��ж����Ƿ�Ϊ0" <<std::endl;
        return false;
    }

    PolyItem tempItem;
    for(int curPosition = 1; curPosition <= length; curPosition++)
    {
        polyList.GetElem(curPosition, tempItem);        // ȡ����ǰ��i��������Ϣ
        if(tempItem.m_coef != 0)                // �����ǰ���ϵ����Ϊ0
        {
            return false;        // ���������ʽ�ض���Ϊ0
        }
    }

    return true;                // ��һֱ��ѭ������, ��û�з���, ��ζ���ʽ��ÿһ��ϵ����Ϊ0
    // ���ζ���ʽֵΪ0
}


/**�������������[ʵ��]********************************************************************
    Polynomail &operator=(const Polynomail &copy);      // ��ֵ���������
    Polynomail &operator=(const LinkList<PolyItem> &copyLinkList);  // ��ֵ���������
********************************************************************[ʵ��]�������������**/
// �������ƣ�Polynomail &operator=(const Polynomail &copy);
// ��ʼ������
// ���������
Polynomail& Polynomail::operator=(const Polynomail &copy)       // ��ֵ���������
{

}



#endif // POLYNOMIAL_H_INCLUDED
