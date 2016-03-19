/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : PersonPlayer.h                                               *
*  Description: ������Ҷ����ļ�                                            *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++����ʯͷ������                          *
******************************************************************************
**/


#ifndef PERSONPLAYER_H_INCLUDED
#define PERSONPLAYER_H_INCLUDED


#include "Player.h"

class PersonPlayer : public Player
{
    public :
    PersonPlayer( )         // ���캯��
    :Player( )
    {
    }

    virtual ~PersonPlayer( ){ }       // ��������

    void InitPlayer( );         // �����Ϣ��ʼ��

    // ���ѡ���Լ��ĳ�ȭ
    SelectType Select( );

    protected:
    bool CheckSelect(char temp);            // ���û������Ƿ�Ϸ�
};

#endif // PERSONPLAYER_H_INCLUDED
