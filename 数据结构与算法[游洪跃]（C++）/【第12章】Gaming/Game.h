/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : Game.h                                                       *
*  Description: ��Ϸ������                                                *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++����ʯͷ������                          *
******************************************************************************
**/

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED




#include "Gaming.h"
#include "PersonPlayer.h"
#include "ComputerPlayer.h"

class Game
{
   public :         // ���������ṹ
    Game( ):m_person( ), m_computer( )
    {
        this->m_gameCount = 0;
        this->m_timeCount = 0;
    }   // ���캯��

    virtual ~Game( ){ };            // ��������

    void InitGame( );            // ��ʼ����Ϸ��Ϣ

    int Menu( );                // ��Ϸ�˵�

    void Help( );                // ������Ϣ

    void PlayGame( );            // ������Ϸ�ĺ���

    void EndGame( );             // ��Ϸ����

    int DisResult( );         // ��ʾ�������

    void ShowResult( );      //

    void Gaming( );         // ������Ϸ���й���
protected :         // �������ݳ�Ա�Լ�������Ϣ
    // ������Ա
    void InitComPuter( );               // ��ʼ�������ĵ���

    void InitPerson( );              // ��ʼ����ʵ�ĵ���

    void Delay( );

    void Stop( );
    void Lording( );
    // ���ݳ�Ա
    PersonPlayer m_person;              // �����Ϣ
    ComputerPlayer m_computer;          // ������Ϣ
    int m_gameCount;                    // ��Ϸ����
    int m_timeCount;                  //   �غϴ���
};
#endif // GAME_H_INCLUDED
