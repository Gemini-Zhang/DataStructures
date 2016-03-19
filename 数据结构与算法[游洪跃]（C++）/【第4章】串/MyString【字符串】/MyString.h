/********************************************************************************
CopyRight  : 2012-2013, HerBinUnversity, GatieMe
File Name  : MyString.h
Author     : Gatie_Me
Version    : �汾����
Data_Time  : 20112-9-27 19:1:24
********************************************************************************/

/********************************************************************************
History    :�޸���ʷ��¼�б�, ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸����Լ��޸�����
********************************************************************************/

#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED



#include <cstring>
#include <cassert>
#include "LinkList.h"
#include <iostream>

//#define DEBUG                     // ������е����뽫��ע�ʹ�
#define REMIND                    // ��������������Ϣ, �뽫��ע�ʹ�


/// �ҵ��ַ�����������
class MyString
{
/*===========================��PUBLIC�������ӿڡ�============================*/
/*===========================��PUBLIC�������ӿڡ�============================*/
//friend istream &operator>>(istream &in, MyString &rhs)          //�������������
//{
//    std::cout <<"Please enter your string\nstring=" <<std::endl; //������Ϣ��ʾ
//    in >>rhs.m_length;           //�����ַ��������ַ�������������ȡstrAdd��ָ����ַ�����
//    rhs.m_length = strlen(rhs.m_length);  //ȷ���ַ�����С
//
//    return in;           //����Ϣ����
//}
//
//friend ostream &operator<<(ostream &out, const MyString &rhs)    //�����������
//{
//   // out <<"the string is " <<endl;
//    out <<rhs.m_strVal;   //����ַ�������strAdd��ָ����ַ�����������
//
//    return out;           //����Ϣ����
//}
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*===========================��PUBLIC�������ӿڡ�============================*/
  public :      // �����ӿ�
    // �ַ����������Ա����
    MyString( );              // Ĭ�Ϲ��캯��

    MyString(const LinkList<char> &copy);   //���������캯������һ���ַ��������ʼ����ǰ��ֵ

    MyString(const char* copy);       // ���������캯������һ��ָ��ָ���ַ�����ʼ����ǰ��ֵ
    MyString(const MyString &copy);   // ��ֵ���캯������һ���������ʼ����ǰ������

    MyString( const MyString &rhs, unsigned int pos, unsigned int n );   //������rhs�еĴ���λ��pos��ʼȡn���ַ�,������ʼ��MyString��Ķ���
    MyString( const char *str, unsigned int pos, unsigned int n );       //��ָ��str��ָ����ַ�����λ��pos��ʼȡn���ַ�������ʼ��MyString��Ķ���

    MyString( const MyString &rhs, unsigned int n );         //�ö���rhs��ǰn�������ʼ��MyString����
    MyString( const char *str, unsigned int n );     //��ָ��str��ָ����ַ�����ǰn���ַ���ʼ��MyString��Ķ���

    MyString( const char op, unsigned int n );         //������op�ظ�n�γ�ʼ��MyString�����


    virtual ~MyString( ){  delete[] m_strVal;  }               // ����������

    // �ַ���������Ժ���
    void GetStr( )
    {
        m_strVal = new char[81];
        std::cin >>m_strVal;
        m_length = strlen(m_strVal);
    }

    void PutStr( ) const
    {
        std::cout <<m_strVal <<std::endl;
    }
    int Length( ) const;                      // ���㴮��

    bool Empty( ) const;                        // �жϵ�ǰ�ַ����ǲ��ǿմ�

    const char* CStr( ) const;      // ����ת��ΪC���, �ȼ��ڡ�*��������
    //������������أ�*, [], =
    char* operator*( );      //������ָ���������==*rhs����ֱ�ӷ���MyString�����ĵ�ַ

    char& operator[]( int index ) const;    //������[]��������rhs[n]ָ����ʵ�n-1���ַ�

    MyString& operator=( const MyString &rhs );   //������=��������rhs1=rhs2ֱ������һ�������rhs2Ϊrhs1��ֵ
    MyString& operator=( const char *str );      //������=��������rhs=strֱ����ָ��str��ָ����ַ���Ϊrhs��ֵ

    //�����������+, +=
    MyString operator+( const MyString &rhs ) const;          //������+��������rhs1 + rhs2
    MyString operator+( const char *str ) const;              //������+��������rhs + str

    MyString& operator+=( const MyString &rhs );         //������+=��������rhs1 += rhs2
    MyString& operator+=( const char *str );         //������+=��������rhs += str

    //���ع�ϵ�������==, != , >, <, >=, <=
    bool operator==( const MyString &rhs ) const;          //������==��������rhs1 == rhs2
    bool operator==( const char *str ) const;              //������==��������rhs == str

    bool operator!=( const MyString &rhs ) const;          //������==��������rhs1 != rhs2
    bool operator!=( const char *str ) const;              //������==��������rhs != str

    bool operator>( const MyString &rhs ) const;         //������>��������rhs1 > rhs2
    bool operator>( const char *str ) const;         //������>��������rhs > str

    bool operator<( const MyString &rhs ) const;          //������<��������rhs1 < rhs2
    bool operator<( const char *str ) const;              //������<��������rhs < str

    bool operator>=( const MyString &rhs ) const;         //������>=��������rhs1 >= rhs2
    bool operator>=( const char *str ) const;         //������>=��������rhs >= str

    bool operator<=( const MyString &rhs ) const;         //������<=��������rhs1 <= rhs2
    bool operator<=( const char *str ) const;         //������<=��������rhs <= str
/*===========================��PUBLIC�������ӿڡ�============================*/
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
/*=========================��PROTECTED��������Ա��===========================*/
  protected :   // �������ݳ�Ա
    mutable char *m_strVal;     // ��ֵ���ַ���ָ��
    int m_length;               // �������ַ�������
/*=========================��PROTECTED����������Ա��=========================*/
};


/// �ҵ��ַ���MyStringʵ�ֲ���

/**�ַ����������Ա������ʵ�֡�***************************************************************
    MyString( );              // Ĭ�Ϲ��캯��
    MyString(const LinkList<char> &copy);   //���������캯������һ���ַ��������ʼ����ǰ��ֵ
    MyString(const char* copy);       // ���������캯������һ��ָ��ָ���ַ�����ʼ����ǰ��ֵ
    MyString(const MyString &copy);   // ��ֵ���캯������һ���������ʼ����ǰ������
    MyString( const MyString &rhs, unsigned int pos, unsigned int n );   //������rhs�еĴ���λ��pos��ʼȡn���ַ�,������ʼ��MyString��Ķ���
    MyString( const char *str, unsigned int pos, unsigned int n );       //��ָ��str��ָ����ַ�����λ��pos��ʼȡn���ַ�������ʼ��MyString��Ķ���
    MyString( const MyString &rhs, unsigned int n );         //�ö���rhs��ǰn�������ʼ��MyString����
    MyString( const char *str, unsigned int n );     //��ָ��str��ָ����ַ�����ǰn���ַ���ʼ��MyString��Ķ���
    MyString( const char op, unsigned int n );         //������op�ظ�n�γ�ʼ��MyString�����
    virtual ~MyString( );               // ����������
***************************************************************��ʵ�֡��ַ����������Ա����**/

// �������ƣ�MyString( );
// ��ʼ�������ַ���δ����
// �������������һ���յ��ַ���
MyString::MyString( )       // Ĭ�Ϲ��캯��
{
//    this->m_strVal = new char[1];
//    if(this->m_strVal == NULL)      // ���δ��ȷ���ٿռ�
//    {
//        std::cout <<"�ڴ治��" <<std::endl;
//        exit(-1);       // �����˳�
//    }
//    else
//    {
//       // this->m_strVal = "\0";
//        strcpy(this->m_strVal, "\0");   // �մ�����ϢΪ�ַ���������־
//        this->m_length = 0;         // �մ��ĳ���Ϊ0
//    }
      this->m_strVal = NULL;
      this->m_length = 0;
}

// �������ƣ�MyString::MyString(const LinkList<char> &copy)
// ��ʼ�������ַ���δ����
// ������������ݲ����ַ�����, ����һ���µ��ַ�������
MyString::MyString(const LinkList<char> &copy)   //���������캯������һ���ַ��������ʼ����ǰ��ֵ
{
    m_strVal = new char[copy.Length()+1];     // �����ڴ�ռ�

    if(this->m_strVal == NULL)      // ���δ��ȷ���ٿռ�
    {
        std::cout <<"�ڴ治��" <<std::endl;
        exit(-1);       // �����˳�
    }
    else        // ���򿪱��ڴ�ʧ��
    {
        char temp;
        int cur;
        for(cur = 0; cur < copy.Length(); cur++)
        {
            copy.GetElem(cur + 1, temp);    // ���ַ������еĵ�cur��Ԫ��ȡ����
            *(m_strVal + cur) = temp;       // ���ַ����뿪�ٵ��ڴ��к��ʵ�λ��
        }
        *(m_strVal + cur) = '\0';         // ����ַ���������־
    }
}


// �������ƣ�MyString::MyString(const char* copy)
// ��ʼ�������ַ���δ����
// �����������һ��ָ��ָ���ַ�����ʼ����ǰ��ֵ
MyString::MyString(const char* copy)       // ���������캯������һ��ָ��ָ���ַ�����ʼ����ǰ��ֵ)
{
    m_strVal = new char[strlen(copy)+1];     // �����ڴ�ռ�

    if(this->m_strVal == NULL)      // ���δ��ȷ���ٿռ�
    {
        std::cout <<"�ڴ治��" <<std::endl;
        exit(-1);       // �����˳�
    }
    else
    {
        strcpy(this->m_strVal, copy);  // �����´������ݶ���
        this->m_length = strlen(copy);         // ȷ���´��ĳ���
    }
}

// �������ƣ�MyString(const MyString &copy)
// ��ʼ�������ַ���δ����
// �����������һ��ָ��ָ���ַ�����ʼ����ǰ��ֵ
MyString::MyString(const MyString &copy)   // ���ƹ��캯������һ���������ʼ����ǰ������
{
    m_strVal = new char[copy.m_length + 1];     // �����ڴ�ռ�

    if(this->m_strVal == NULL)      // ���δ��ȷ���ٿռ�
    {
        std::cout <<"�ڴ治��" <<std::endl;
        exit(-1);       // �����˳�
    }
    else
    {
        strcpy(this->m_strVal, copy.m_strVal);      // �����´������ݶ���
        this->m_length = copy.m_length;     // ȷ���´��ĳ���
    }
}


// �������ƣ�MyString( const MyString &rhs, unsigned int pos, unsigned int n )
// ��ʼ�������ַ���δ����
// ���������������rhs�еĴ���λ��pos��ʼȡn���ַ�,������ʼ��MyString��Ķ���
MyString::MyString( const MyString &rhs, unsigned int pos, unsigned int n )   //������rhs�еĴ���λ��pos��ʼȡn���ַ�,������ʼ��MyString��Ķ���
{
    this->m_strVal = new char[n+1];
    if(this->m_strVal == NULL)      // ���δ��ȷ���ٿռ�
    {
        std::cout <<"�ڴ治��" <<std::endl;
        exit(-1);       // �����˳�
    }
    else
    {
        unsigned int i = pos, j = 0;

        while(j < n)        // ѭ�����Ƹ�ֵ�����n���ַ�
        {
            this->m_strVal[j++] = *(rhs.m_strVal+i++);
        }
        m_strVal[j] = '\0';   // �ַ���������־
        this->m_length = n;
    }
/*  char *pStart = rhs.strAdd + pos;           //��ֵ��ʼλ��
    char *pEnd = rhs.m_strVal + pos + n;         //��ֵ����λ��

    m_strVal = new char[n+1];             //���ٿռ�
    m_length = n;                           //ȷ�����ĳ���

    char *pThis = strAdd;               //����Ŀ�Ĵ�λ��
    while( (pStart < pEnd) &&  *pThis++ = *pStart++ );      //ѭ�����Ƹ�ֵͬʱ��ֵ
    *(pThis) = '\0';
*/
}


// �������ƣ�MyString( const char *str, unsigned int pos, unsigned int n )
// ��ʼ�������ַ���δ����
// �����������ָ��str��ָ����ַ�����λ��pos��ʼȡn���ַ�������ʼ��MyString��Ķ���
MyString::MyString( const char *str, unsigned int pos, unsigned int n )       //��ָ��str��ָ����ַ�����λ��pos��ʼȡn���ַ�������ʼ��MyString��Ķ���
{
    this->m_strVal = new char[n+1];
    if(this->m_strVal == NULL)      // ���δ��ȷ���ٿռ�
    {
        std::cout <<"�ڴ治��" <<std::endl;
        exit(-1);       // �����˳�
    }
    else
    {
        unsigned int i = pos, j = 0;

        while(j < n)        // ѭ�����Ƹ�ֵ�����n���ַ�
        {
            this->m_strVal[j++] = *(str+i++);
        }
        m_strVal[j] = '\0';   // �ַ���������־
        this->m_length = n;
    }
}


// �������ƣ�(const MyString &rhs, unsigned int n)
// ��ʼ�������ַ���δ����
// ����������ö���rhs��ǰn�������ʼ��MyString����
MyString::MyString(const MyString &rhs, unsigned int n)         //�ö���rhs��ǰn�������ʼ��MyString����
{
    this->m_strVal = new char[n+1];
    if(this->m_strVal == NULL)      // ���δ��ȷ���ٿռ�
    {
        std::cout <<"�ڴ治��" <<std::endl;
        exit(-1);       // �����˳�
    }
    else
    {
        unsigned int i = 0;

        while(i < n)        // ѭ�����Ƹ�ֵ�����n���ַ�
        {
            this->m_strVal[i] = *(rhs.m_strVal+i);
            i++;
        }
        m_strVal[i] = '\0';   // �ַ���������־

        this->m_length = n;
    }
}

// �������ƣ�MyString( const char *str, unsigned int pos, unsigned int n )
// ��ʼ�������ַ���δ����
// �����������ָ��str��ָ����ַ�����λ��pos��ʼȡn���ַ�������ʼ��MyString��Ķ���
MyString::MyString( const char *str, unsigned int n)     //��ָ��str��ָ����ַ�����ǰn���ַ���ʼ��MyString��Ķ���
{
    this->m_strVal = new char[n+1];
    if(this->m_strVal == NULL)      // ���δ��ȷ���ٿռ�
    {
        std::cout <<"�ڴ治��" <<std::endl;
        exit(-1);       // �����˳�
    }
    else
    {
        unsigned int i = 0;

        while(i < n)        // ѭ�����Ƹ�ֵ�����n���ַ�
        {
            this->m_strVal[i] = *(str+i);
            i++;
        }
        m_strVal[i] = '\0';   // �ַ���������־

        this->m_length = n;
    }
}

// �������ƣ�MyString( const char op, unsigned int n )
// ��ʼ�������ַ���δ����
// ���������������op�ظ�n�γ�ʼ��MyString�����
MyString::MyString( const char op, unsigned int n )         //������op�ظ�n�γ�ʼ��MyString�����
{
    unsigned int i  = 0;

    this->m_strVal = new char[n+1];
    if(this->m_strVal == NULL)      // ���δ��ȷ���ٿռ�
    {
        std::cout <<"�ڴ治��" <<std::endl;
        exit(-1);       // �����˳�
    }
    else
    {
        while(i < n)
        {
            this->m_strVal[i++] = op;
        }
        m_strVal[i] = '\0';

        m_length = n;
    }
}

/**�ַ���������Ժ�����ʵ�֡�*****************************************************************
    int Length( ) const;                      // ���㴮��

    bool Empty( ) const;                        // �жϵ�ǰ�ַ����ǲ��ǿմ�

    const char* CStr( ) const;      // ����ת��ΪC���, �ȼ��ڡ�*��������
*****************************************************************��ʵ�֡��ַ���������Ժ���**/
// �������ƣ�int Length( ) const;
// ��ʼ�������ַ������Ѿ�����
// ������������ص�ǰ�ַ����Ĵ���
int MyString::Length( ) const
{
    return m_length;
}

// �������ƣ�bool Empty( ) const;
// ��ʼ�������ַ��������Ѿ�����
// ����������жϵ�ǰ�ַ����Ƿ�Ϊ��
bool MyString::Empty( ) const
{
    return m_length == 0;
}

// �������ƣ�bool Empty( ) const;
// ��ʼ�������ַ��������Ѿ�����
// �������������ת��ΪC���, �ȼ��ڡ�*��������
const char* MyString::CStr( ) const
{
    return m_strVal;        // �����ַ����ĵ�ַָ��
}


/**������������أ�*, [], =��ʵ�֡�***********************************************************
    const char* operator*( ) const;      //������ָ���������==*rhs����ֱ�ӷ���MyString�����ĵ�ַ
    char& operator[]( int index ) const;    //������[]��������rhs[n]ָ����ʵ�n-1���ַ�
    MyString& operator=( const MyString &rhs );   //������=��������rhs1=rhs2ֱ������һ�������rhs2Ϊrhs1��ֵ
    MyString& operator=( const char *str );      //������=��������rhs=strֱ����ָ��str��ָ����ַ���Ϊrhs��ֵ
    //�����������+, +=
    MyString operator+( const MyString &rhs ) const;          //������+��������rhs1 + rhs2
    MyString operator+( const char *str ) const;              //������+��������rhs + str
    bool operator+=( const MyString &rhs );         //������+=��������rhs1 += rhs2
    bool operator+=( const char *str );         //������+=��������rhs += str
    //���ع�ϵ�������==, != , >, <, >=, <=
    bool operator==( const MyString &rhs ) const;          //������==��������rhs1 == rhs2
    bool operator==( const char *str ) const;              //������==��������rhs == str
    bool operator!=( const MyString &rhs ) const;          //������==��������rhs1 != rhs2
    bool operator!=( const char *str ) const;              //������==��������rhs != str
    bool operator>( const MyString &rhs ) const;         //������>��������rhs1 > rhs2
    bool operator>( const char *str ) const;         //������>��������rhs > str
    bool operator<( const MyString &rhs ) const;          //������<��������rhs1 < rhs2
    bool operator<( const char *str ) const;              //������<��������rhs < str
    bool operator>=( const MyString &rhs ) const;         //������>=��������rhs1 >= rhs2
    bool operator>=( const char *str ) const;         //������>=��������rhs >= str
    bool operator<=( const MyString &rhs ) const;         //������<=��������rhs1 <= rhs2
    bool operator<=( const char *str ) const;         //������<=��������rhs <= str
***********************************************************��ʵ�֡�������������أ�*, [], =**/

/// �������������*, [], =
// �������ƣ�const char* operator*( );
// ��ʼ�������ַ������Ѿ�����
// ������������ء�*��������, ����ǰ������ת��ΪC���Ĵ�
char* MyString::operator*( )
{
    return m_strVal;
}


// �������ƣ�char& operator[]( int index );
// ��ʼ�������ַ������Ѿ�����
// ���������[����[]������]-=> rhs[n]ָ����ʵ�n-1���ַ�
char& MyString::operator[](int index) const
{
    assert(index >= 0 && index < this->m_length);   // �ж������Ƿ�Ϸ�

    return m_strVal[index];     // ���ص�ǰ������Ԫ��
}


// �������ƣ�MyString& operator=( const MyString &rhs );
// ��ʼ�������ַ������Ѿ�����
// ���������������=��������rhs1=rhs2ֱ������һ�������rhs2Ϊrhs1��ֵ
MyString& MyString::operator=(const MyString &rhs)
{
    if(this == &rhs)    // �жϵ�ǰԴĿ�Ĵ��Ƿ�ΪͬһĿ��
    {
        return (*this);     // ��ͬһĿ��ֻ��Ҫ��ֱ�ӷ���
    }
    else
    {
        if(m_strVal != NULL)
        {
            delete[] m_strVal;
        }
        m_strVal = new char[rhs.m_length+1];
        strcpy(m_strVal, rhs.m_strVal);
        m_length = rhs.m_length;
    }

    return (*this);
}

// �������ƣ�MyString& operator=( const char *str );
// ��ʼ�������ַ������Ѿ�����
// ���������������=��������rhs=strֱ����ָ��str��ָ����ַ���Ϊrhs��ֵ
MyString& MyString::operator=(const char *str)
{
    if(m_strVal != NULL)
    {
        delete[] m_strVal;
    }
    m_strVal = new char[strlen(str)+1];
    strcpy(m_strVal, str);
    m_length = strlen(str);

    return (*this);
}

//�����������+, +=
MyString MyString::operator+(const MyString &rhs) const          //������+��������rhs1 + rhs2
{
    MyString strResult;

    if(rhs.m_strVal == NULL)    // ������Ӵ�Ϊ��
    {
        strResult = rhs;    // ���������Դ��
    }
    else if(m_strVal == NULL)   // ���򸽼Ӵ���Ϊ��, ����Դ��Ϊ��, +�Ľ���Ǹ��Ӵ�
    {
        strResult = rhs;
    }
    else
    {
//        strResut = *this;
//        strResult += rhs;
          strResult.m_strVal = new char[this->m_length+rhs.m_length+1];   // ɾ��������Ŀռ�
          strcpy(strResult.m_strVal, this->m_strVal);
          strcat(strResult.m_strVal, rhs.m_strVal);
    }

    return strResult;
}

MyString MyString::operator+(const char *str) const             //������+��������rhs + str
{
    MyString strResult;

    if(str == NULL)    // ������Ӵ�Ϊ��
    {
        strResult = *this;    // ���������Դ��
    }
    else if(m_strVal == NULL)   // ���򸽼Ӵ���Ϊ��, ����Դ��Ϊ��, +�Ľ���Ǹ��Ӵ�
    {
        strResult = str;
    }
    else
    {
//        strResut = *this;
//        strResult += rhs;
          strResult.m_strVal = new char[this->m_length+strlen(str)+1];   // ɾ��������Ŀռ�
          strcpy(strResult.m_strVal, this->m_strVal);
          strcat(strResult.m_strVal, str);
    }

    return strResult;
}


MyString& MyString::operator+=(const MyString &rhs)         //������+=��������rhs1 += rhs2
{
    if(rhs.m_strVal != NULL)    // �����ַ������ʿ�
    {



        if(this->m_strVal == NULL)  // ���Դ��Ϊ��
        {
            m_strVal = new char[rhs.m_length+1];
            strcpy(m_strVal, rhs.m_strVal);
            this->m_length = rhs.m_length;
        }
        else
        {
            char *temp = new char[m_length+1];
            strcpy(temp, this->m_strVal);
            delete[] m_strVal;
            this->m_strVal = new char[m_length+rhs.m_length+1];
            strcpy(m_strVal, temp);
            strcat(m_strVal, rhs.m_strVal);
            this->m_length += rhs.m_length;
        }
    }

    return (*this);
}


MyString& MyString::operator+=( const char *str )         //������+=��������rhs += str
{
    if(str != NULL)    // �����ַ������ʿ�
    {

        if(this->m_strVal == NULL)  // ���Դ����Ϊ����Ҫ����
        {
            m_strVal = new char[strlen(str)+1];
            strcpy(m_strVal, m_strVal);
            this->m_length = strlen(str);
        }
        else
        {

            char *temp = new char[m_length+1];
            strcpy(temp, this->m_strVal);
            delete[] m_strVal;
            this->m_strVal = new char[m_length+strlen(str)+1];
            strcpy(m_strVal, temp);
            strcat(m_strVal, str);
        }
    }

    return (*this);
}


bool MyString::operator==( const MyString &rhs ) const          //������==��������rhs1 == rhs2
{
    return (strcmp(m_strVal, rhs.m_strVal) == 0);
}
bool MyString::operator==( const char *str ) const              //������==��������rhs == str
{
    return (strcmp(m_strVal, str) == 0);
}
bool MyString::operator!=( const MyString &rhs ) const          //������==��������rhs1 != rhs2
{
    return !(*this == rhs);
}
bool MyString::operator!=( const char *str ) const              //������==��������rhs != str
{
    return !(*this == str);
}

bool MyString::operator>( const MyString &rhs ) const         //������>��������rhs1 > rhs2
{
    return (strcmp(m_strVal, rhs.m_strVal) > 0);
}


bool MyString::operator>( const char *str ) const         //������>��������rhs > str
{
    return (strcmp(m_strVal, str) > 0);
}

bool MyString::operator<( const MyString &rhs ) const          //������<��������rhs1 < rhs2
{
    return (strcmp(m_strVal, rhs.m_strVal) < 0);
}


bool MyString::operator<( const char *str ) const              //������<��������rhs < str
{
    return (strcmp(m_strVal, str) < 0);
}
bool MyString::operator>=( const MyString &rhs ) const         //������>=��������rhs1 >= rhs2
{
    return (strcmp(m_strVal, rhs.m_strVal) >= 0);
}


bool MyString::operator>=( const char *str ) const         //������>=��������rhs >= str
{
    return (strcmp(m_strVal, str) >= 0);
}
bool MyString::operator<=( const MyString &rhs ) const         //������<=��������rhs1 <= rhs2
{
    return (strcmp(m_strVal, rhs.m_strVal) <= 0);
}

bool MyString::operator<=( const char *str ) const         //������<=��������rhs <= str
{
    return (strcmp(m_strVal, str) <= 0);
}

#endif // MYSTRING_H_INCLUDED
