/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : ComputerPlayer.h                                             *
*  Description: ������Ҷ����ļ�                                            *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++����ʯͷ������                          *
******************************************************************************
**/



#ifndef COMPUTERPLAYER_H_INCLUDED
#define COMPUTERPLAYER_H_INCLUDED


#include "Player.h"



class ComputerPlayer : public Player
{
    public :
    ComputerPlayer( )       // ���캯��
    :Player( )
    {

    }

    virtual ~ComputerPlayer( ){ };  // ��������

    void InitPlayer( );       // �����麯��

    SelectType Select( );       // �����麯��
};

#endif // COMPUTERPLAYER_H_INCLUDED
