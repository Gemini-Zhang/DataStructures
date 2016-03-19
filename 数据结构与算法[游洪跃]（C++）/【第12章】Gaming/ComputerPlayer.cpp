/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : ComputerPlayer.cpp                                           *
*  Description: �������ʵ���ļ�                                            *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++����ʯͷ������                          *
******************************************************************************
**/

#include <stdlib.h>
#include <time.h>

#include "ComputerPlayer.h"

bool SayYes( );


void ComputerPlayer::InitPlayer( )
{
    this->m_select = NULLOUT;
    this->m_winCount = 0;

    std::cout <<std::endl;
    std::cout <<"******************************************" <<std::endl;
    std::cout <<"*�������Ƿ�ͬ��һ����ʵ�ĵ��Լ���������Ϸ*" <<std::endl;
    std::cout <<"***��ʵ�ĵ��Գ���ȭ�ᱻ��Ϸ��Ϊ�������***" <<std::endl;
    std::cout <<"******************************************" <<std::endl;
    if(SayYes( ) == true)
    {
        this->m_character = Honest;     // ��ʵ�����
        this->SetName("Honnest");      // ���õ�������
    }
    else
    {
        this->m_character = Funny;      // ���������
        this->SetName("Funny");
    }
}


SelectType ComputerPlayer::Select( )
{
    int SIZE = ((this->m_character == Funny) ? 4 : 3);

    srand(time(NULL));
    this->m_select = (SelectType)(rand( ) % SIZE + 1);

    return this->m_select;
}
