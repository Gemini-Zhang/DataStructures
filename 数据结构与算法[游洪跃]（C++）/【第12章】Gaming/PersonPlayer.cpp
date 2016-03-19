/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : PersonPlayer.cpp                                             *
*  Description: �������ʵ���ļ�                                            *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++����ʯͷ������                          *
******************************************************************************
**/

#include "PersonPlayer.h"

bool SayYes( );




void PersonPlayer::InitPlayer( )         // �����Ϣ��ʼ��
{
    std::cout <<"��������������:";
    std::cin >>this->m_name;            // �����������

    this->m_select = NULLOUT;
    this->m_winCount = 0;

//    std::cout <<std::endl;
//    std::cout <<"******************************************" <<std::endl;
//    std::cout <<"**�������Ƿ�ͬ����һ����ʵ����Ҳμ���Ϸ**" <<std::endl;
//    std::cout <<"**��ʵ����ҳ���ȭ�ᱻ��Ϸ��Ϊ�������..**" <<std::endl;
//    std::cout <<"******************************************" <<std::endl;
//    if(SayYes( ) == true)
//    {
//        this->m_character = Honest;     // ��ʵ�����
//    }
//    else
//    {
//        this->m_character = Funny;      // ���������
//    }
}


SelectType PersonPlayer::Select( )
{
//    ROCK = 1, // ʯͷ
//    SCISSOR = 2, // ����
//    CLOTH = 3,  // ��
//    NULLOUT = 4,
    bool reponse = true;
    char temp;
    do
    {
        std::cout <<std::endl;
        if(reponse == false)
        {
            std::cout <<"��Ϊһ����ʵ�����, ���ղ�һ���������" <<std::endl;
        }
        std::cout <<"��" <<this->m_name <<"ѡ���ȭ" <<std::endl;         // ��Ϣ��ʾ
        std::cout <<"R|r|1[ʯͷ] OR S|s|2[��] OR C|c|3[��]" <<std::endl;

        std::cin >>temp;
        reponse = false;
    }while(this->CheckSelect(temp) == false);      // ֻҪ����Ľ�����Ϸ���һֱ����

    if(temp == '1' || temp == 'R' || temp == 'r')
    {
        this->m_select = ROCK;          // ��ҳ���ʯͷ
    }
    else if(temp == 'S' || temp == 's' || temp == '2')
    {
        this->m_select = SCISSOR;           // ��ҳ��˼���
    }
    else if(temp == 'C' || temp == 'c' || temp == '3')
    {
        this->m_select = CLOTH;         // ��ҳ��˲�
    }
    else if(this->m_character == Funny)
    {
        this->m_select = NULLOUT;       // ��������ҳ��˿�ȭ
    }
    return this->m_select;
}


bool PersonPlayer::CheckSelect(char temp)            // ��ȡ�û���ѡ��
{
    if(this->m_character == Honest       // ��ʵ������������Ϸ�
       && temp != 'R' && temp != 'r' && temp != '1'
       && temp != 'S' && temp != 's' && temp != '2'
       && temp != 'C' && temp != 'c' && temp != '3')
    {
        return false;
    }
    else                // �����������������ֵ����
    {
        return true;
    }
}
