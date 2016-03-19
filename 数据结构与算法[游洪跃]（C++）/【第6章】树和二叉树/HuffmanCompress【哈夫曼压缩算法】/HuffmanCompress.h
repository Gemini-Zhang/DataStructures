/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : HuffmanTree.h                                                *
*  Description: ��������ѹ����HuffmanCompress��ͷ�ļ�HuffmanCompress.h      *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++��������Դ��                             *
******************************************************************************
**/


#ifndef HUFFMANCOMPRESS_H_INCLUDED
#define HUFFMANCOMPRESS_H_INCLUDED

#include <ios>
#include <iostream>

#include "Error.h"
#include "BufferType.h"
#include "HuffmanTree.h"


/// ��������ѹ����HuffmanCompress����������
class HuffmanCompress
{

/*==============================[�����ӿ�:PUBLIC]============================*/
public:
    // ������ѹ���෽����������

    // ������ѹ����ڻ�����Ա����
    HuffmanCompress( );         // �޲����Ĺ��캯��

    HuffmanCompress(const HuffmanCompress &copy);   // ���ƹ��캯��

    ~HuffmanCompress( );        // ��������

    // ��������غ���=
    HuffmanCompress& operator=(const HuffmanCompress &copy);    // ���ظ�ֵ�����=

    // ������ѹ�����������Ա����
    void EnCompress( );           // ѹ���㷨

    void UnCompress( );         // ��ѹ���㷨
/*==============================[�����ӿ�:PUBLIC]============================*/
/*============================[������Ա:PROTECTED]===========================*/
protected:
    // ��������ѹ����HuffmanCompress�������ݳ�Ա
    HuffmanTree<char, unsigned long> *m_pHuffmanTree;       // ����������ָ��
    FILE *m_infp, *m_outfp;                             // ����/����ļ�
    BufferType m_buffer;                            // �ַ�������

    // ������Ա����
    void Write(unsigned int bit);                   // ��Ŀ���ļ���д��һ��bit
    void WriteOutfp( );                             // ǿ�н��ַ�����д��Ŀ���ļ�
/*============================[������Ա:PROTECTED]===========================*/

};



/// ��������ѹ����HuffmanCompress��ʵ�ֲ���


/**������Ա����[ʵ��]**********************************************************
    void Write(unsigned int bit);   // ��Ŀ���ļ���д��һ��bit
    void WriteOutfp( );             // ǿ�н��ַ�����д��Ŀ���ļ�
**********************************************************[ʵ��]������Ա����**/
// �������ƣ�void Write(unsigned int bit);
// �����������Ŀ���ļ���д��һ��bit
// Write�����������ַ�������д��һ����,
// ���������еı�����Ϊ8(Ҳ����һ���ֽ�ʱ)
// �������е��ַ�д��Ŀ���ļ�
void HuffmanCompress::Write(unsigned int bit)          // ��Ŀ���ļ���д��һ��bit
{
    this->m_buffer.m_bits++;            // ÿд��һ��bitλ, ���û������������1
    this->m_buffer.m_character = (this->m_buffer.m_character << 1) | bit;

    if(m_buffer.m_bits == 8)            // 8λΪһ���ֽ�, ����������
    {       // ����Ϣд��Ŀ���ļ�
        fputc(this->m_buffer.m_character, m_outfp);

        m_buffer.InitBuffer( );         // ��ʼ��������
    }
}


// �������ƣ�void WriteOutfp( );
// �����������Ŀ���ļ���д��һ��bit
// WriteOutfp�����ڹ������������ʱ, ǿ�н�����д��Ŀ���ļ���,
// Ҳ���ǲ��ܹ�����8λ[һ���ֽ�],
// �ڹ������������ʱ, ��Ҫ����Ϣд��Ŀ���ļ�
void HuffmanCompress::WriteOutfp( )         // ǿ�н��ַ�����д��Ŀ���ļ�
{
    unsigned int len = m_buffer.m_bits;     // ��ǰ������ʵ�ʱ�����Ŀ

    if(len > 0)     // ֻҪ���������ǿյ�
    {   // �ͽ������ܱߵı�����Ŀ���ӵ�8, �Զ�д���ļ���
        for(unsigned int i = 0; i < 8-len; i++)
        {
            Write(0);
        }

    }
}


/**������ѹ����ڻ�����Ա����[ʵ��]********************************************
    HuffmanCompress( );         // �޲����Ĺ��캯��
    HuffmanCompress(const HuffmanCompress &copy);   // ���ƹ��캯��
    ~HuffmanCompress( );        // ��������
********************************************[ʵ��]������ѹ����ڻ�����Ա����**/
// �������ƣ�HuffmanCompress( );
// �������������һ���յĹ�����ѹ�������, ���ٳ���Ҫ�Ŀռ�
HuffmanCompress::HuffmanCompress( )     // �޲����Ĺ��캯��
{
    this->m_pHuffmanTree = NULL;          // ����������ָ��
    this->m_infp = NULL;                  // �����ļ�
    this->m_outfp = NULL;                  // ����ļ�
}

// �������ƣ�HuffmanCompress(const HuffmanCompress &copy);
// �������������һ���յĹ�����ѹ�������, ���ٳ���Ҫ�Ŀռ�
HuffmanCompress::HuffmanCompress(const HuffmanCompress &copy)   // ���ƹ��캯��
{
    this->m_pHuffmanTree = copy.m_pHuffmanTree;          // ����������ָ��
    this->m_infp = copy.m_infp;                  // �����ļ�
    this->m_outfp = copy.m_outfp;                  // ����ļ�
    this->m_buffer = copy.m_buffer;                // ������
}

// �������ƣ�~HuffmanCompress( );        // ��������
// ����������ͷű�Ҫ�Ŀռ�
HuffmanCompress::~HuffmanCompress( )        // ��������
{

}

/**��������غ���=[ʵ��]********************************************************
    HuffmanCompress& operator=(const HuffmanCompress &copy);  // ���ظ�ֵ�����=
********************************************************[ʵ��]��������غ���=**/
// �������ƣ�HuffmanCompress& operator=(const HuffmanCompress &copy);    // ���ظ�ֵ�����=
HuffmanCompress& HuffmanCompress::operator=(const HuffmanCompress &copy)    // ���ظ�ֵ�����=
{
    this->m_pHuffmanTree = copy.m_pHuffmanTree;          // ����������ָ��
    this->m_infp = copy.m_infp;                  // �����ļ�
    this->m_outfp = copy.m_outfp;                  // ����ļ�
    this->m_buffer = copy.m_buffer;                // ������

    return (*this);
}


/**������ѹ�����������Ա����[ʵ��]********************************************
    void EnCompress( );           // ѹ���㷨
    void UnCompress( );         // ��ѹ���㷨
********************************************[ʵ��]������ѹ�����������Ա����**/
// �������ƣ�void EnCompress( );
// ���������Ӧ����������ѹ��
void HuffmanCompress::EnCompress( )           // ѹ���㷨
{
    const unsigned long maxSize = 256;
    char infName[maxSize], outfName[maxSize];       // ��������ļ���

    std::cout <<"������Դ�ļ���[<4GB]:" <<std::endl;     // ��ʾ��Ϣ
    std::cin >>infName;                              // ����Դ�ļ���
    if((this->m_infp = fopen(infName, "rb")) == NULL)
    {
        std::cout <<"��Դ�ļ�ʧ��" <<std::endl;
        throw Error("��Դ�ļ�ʧ��\n");
    }

    //fgetc(this->m_infp);              // ȡ��Դ�ļ��еĵ�һ���ַ�
    /*if(ftell(this->m_infp) <= 0)         // �����ǰ�ļ��ǿյ�
    {
        std::cout <<"���ļ�" <<std::endl;
        throw Error("���ļ�\n");
    }*/
    if(fgetc(m_infp) == EOF)
    {
        throw Error("���ļ�\n");
    }
    rewind(m_infp);
//    while( 1 )
//    {
//        char choice;
//        std::cout <<"������Ŀ���ļ���:" <<std::endl;
//        std::cin >>outfName;                 // ����Ŀ���ļ���
//        if((this->m_outfp = fopen(outfName, "wb")) == NULL)
//        {
//            throw Error("��Ŀ���ļ�ʧ��\n");
//        }
//
//        if(ftell(this->m_outfp) > 0)            // ���Ŀ���ļ����ǿյ�
//        {               // ѯ���Ƿ񸲸�
//            while( 1 )
//            {
//                std::cout <<"Ŀ���ļ���Ϊ��..." <<std::endl;
//                std::cout <<"ȷ�θ��Ǵ��ļ�ô[y/Y  OR  n/N]:" <<std::endl;
//
//                std::cin >>choice;
//                if(choice == 'y' || choice == 'Y' || choice == 'N' || choice == 'n')
//                {
//                    break;
//                }
//                std::cout <<"��������, ����������" <<std::endl;
//            }
//
//            if(choice == 'y' || choice == 'Y')      // ���ȷ�ϸ��Ǿ�ֹͣ
//            {
//                break;
//            }
//
//        }
//        else
//        {
//            break;
//        }
//    }

    std::cout <<"������Ŀ���ļ���:" <<std::endl;
    std::cin >>outfName;                 // ����Ŀ���ļ���
    if((this->m_outfp = fopen(outfName, "wb")) == NULL)
    {
        throw Error("��Ŀ���ļ�ʧ��\n");
    }

    std::cout <<"����ѹ����, ���Ժ�..." <<std::endl;

    char chars[maxSize];                // �ַ�����
    unsigned long weight[maxSize];         // �ַ����ֵ�
    unsigned long i, size = 0;
    char charType;

    rewind(m_infp);
    for(i = 0; i < maxSize; i++)
    {
        chars[i] = (char)(i);           // ��ʼ���ַ�����
        weight[i] = 0;                  // ��ʼ��Ȩֵ����
    }

    while((charType = fgetc(this->m_infp)) != EOF)  // ȡ���ļ��е�ÿ���ַ�
    {
        weight[(unsigned char)charType]++;            // �ַ�charType���ֵ�Ƶ������1
        size++;                                       // �ļ���С�Լ�1
    }

    if(m_pHuffmanTree != NULL)      // �����ǰ��������������Ϣ��Ϊ��
    {
        delete m_pHuffmanTree;    // ɾ���ռ�
    }
system("pause");
    this->m_pHuffmanTree = new HuffmanTree<char, unsigned long>(chars, weight, size);  // ���ɹ���������
system("pause");

    rewind(m_outfp);
    fwrite(&size, sizeof(unsigned long), 1, m_outfp);   // ��Ŀ���ļ���д��Դ�ļ���С
   // for(i = 0; i < size; i++)
    //{   // ���ļ��ղ�д���ַ�����Ƶ��
        fwrite(&weight[0], sizeof(unsigned long), size, m_outfp);
    //}
system("pause");
    this->m_buffer.InitBuffer( );      // ��ʼ��������

    rewind(m_infp);                     // ʹԴ��ָ�붨λ���ļ��Ŀ�ʼ
    while((charType = fgetc(m_infp)) != EOF)
    {
        //��Դ�ļ��ַ����б���, ����������Ϣд��Ŀ���ļ�
        std::string strTemp = m_pHuffmanTree->EnCode(charType);

        // ������л��Ŀ���ļ�
        for(i = 0; i < strTemp.size(); i++)
        {
            if(strTemp[i] == '0')
            {
                this->Write(0);
            }
            else
            {
                this->Write(1);
            }
        }
    }
    this->WriteOutfp( );            // ǿ�н�������Ϣд��Ŀ���ļ�
system("pause");

    // �ر��ļ�
    fclose(this->m_infp);       // �ر�Դ�ļ�
    fclose(this->m_outfp);      // �ر�Ŀ���ļ�
    std::cout <<"�������..." <<std::endl;
}

// �������ƣ�void UnCompress( );
// ����������ù����������н�ѹ��
void HuffmanCompress::UnCompress( )         // ��ѹ���㷨
{
    const unsigned long maxSize = 256;
    char infName[maxSize], outfName[maxSize];       // ��������ļ���

    std::cout <<"������ѹ���ļ���:" <<std::endl;     // ��ʾ��Ϣ
    std::cin >>infName;                              // ����Դ�ļ���
    if((this->m_infp = fopen(infName, "rb")) == NULL)
    {
        throw Error("��Դ�ļ�ʧ��\n");
    }

    if(fgetc(m_infp) == EOF)
    {
        throw Error("���ļ�\n");
    }

    rewind(m_infp);
//    while( 1 )
//    {
//        char choice;
//        std::cout <<"������Ŀ���ļ���:" <<std::endl;
//        std::cin >>outfName;                 // ����Ŀ���ļ���
//        if((this->m_outfp = fopen(outfName, "wb")) == NULL)
//        {
//            throw Error("��Ŀ���ļ�ʧ��\n");
//        }
//
//        if(ftell(this->m_outfp) > 0)            // ���Ŀ���ļ����ǿյ�
//        {               // ѯ���Ƿ񸲸�
//            while( 1 )
//            {
//                std::cout <<"Ŀ���ļ���Ϊ��..." <<std::endl;
//                std::cout <<"ȷ�θ��Ǵ��ļ�ô[y/Y  OR  n/N]:" <<std::endl;
//
//                std::cin >>choice;
//                if(choice == 'y' || choice == 'Y' || choice == 'N' || choice == 'n')
//                {
//                    break;
//                }
//                std::cout <<"��������, ����������" <<std::endl;
//            }
//
//            if(choice == 'y' || choice == 'Y')      // ���ȷ�ϸ��Ǿ�ֹͣ
//            {
//                break;
//            }
//        }
//        else
//        {
//            break;
//        }
//    }
    std::cout <<"������Ŀ���ļ���:" <<std::endl;
    std::cin >>outfName;                 // ����Ŀ���ļ���
    if((this->m_outfp = fopen(outfName, "wb")) == NULL)
    {
        throw Error("��Ŀ���ļ�ʧ��\n");
    }
    std::cout <<"���ڽ�ѹ����, ���Ժ�..." <<std::endl;

    char chars[maxSize];                // �ַ�����
    unsigned long weight[maxSize];         // �ַ����ֵ�
    unsigned long i, size = 0;
    char charType;

    rewind(m_infp);         // ʹѹ���ļ���λ�ڿ�ͷ
    rewind(m_outfp);
    fread(&size, sizeof(unsigned long), 1, m_infp);     // ��ȡĿ���ļ��Ĵ�С
    for(i = 0; i < size; i++)                   //
    {
        chars[i] = (char)i;                 // ��ʼ��chars[i]
        fread(&weight[i], sizeof(unsigned long), 1, m_infp);    // ��ȡ�ַ�Ƶ��
    }

    if(m_pHuffmanTree != NULL)
    {
        delete[] m_pHuffmanTree;// �ͷ��Ѿ�����ı���ռ�
    }
    m_pHuffmanTree = new HuffmanTree<char, unsigned long>(chars, weight, size);// ���ɹ�������


    unsigned long len = 0;
    while((charType = fgetc(m_infp)) != EOF)
    {   // ���ļ����н���
        std::string strTemp = "";
        unsigned char charTemp = (unsigned char)charType;

        for(i = 0; i < 8; i++)
        {
            if(charTemp < 128)
            {
                strTemp += '0';
            }
            else
            {
                strTemp += '1';
            }
            charTemp = charTemp<<1;     // ����һλ
        }

        std::string deString(m_pHuffmanTree->DeCode(strTemp));  // �Զ���������Ϣ��������
        for(i = 1; i <= strTemp.size(); i++)
        {
            len++;
            fputc(strTemp[i-1], m_outfp);
            if(len == size)
            {
                break;
            }
        }
        if(len == size)
        {
            break;
        }
    }

    fclose(m_infp);
    fclose(m_outfp);

    std::cout <<"�������..." <<std::endl;
}

#endif // HUFFMANCOMPRESS_H_INCLUDED
