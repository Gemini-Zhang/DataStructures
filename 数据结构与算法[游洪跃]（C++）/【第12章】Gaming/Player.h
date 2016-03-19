/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : Player.h                                                     *
*  Description: ��ҳ�����                                                   *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++����ʯͷ������                          *
******************************************************************************
**/

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED


#include <iostream>

#include "Gaming.h"


#define Funny false     // ����������ǻ����ȭ��
#define Honest true     // ��ʵ����Ҳ������ȭ, ��˳�ʵ�����������˴������Ϣ�ǻᱻ���ѵ�

// �����
class Player
{

  public  :  // �����������
    Player( )
    {
        this->m_name = "NULLNAME";
        this->m_winCount = 0;
        this->m_totalCount = 0;
    }                          // Ĭ�Ϲ��캯��

    virtual ~Player( ){ }                 // ��������

    virtual void InitPlayer( ) = 0;          // �����Ϣ��ʼ��

    void SetName(std::string name);             // ������ҵ�����

    std::string GetName( );                 // ��ȡ��ҵ�����

    SelectType GetSelect( );        // ��ȡ��ҵĳ�ȭ��Ϣ

    bool GetCharacter( );           // ��ȡ��ҵ��Ը���Ϣ

    int GetWinCount( );             // ��ȡ��ҵķ���

    void ShowSelect( );         // ��ʾ��ҵĳ�ȭ��Ϣ

    bool SelectCharacter( );        // �޸�������Ը�

    void ShowCharacter( );      // ��ʾ��ҵ��Ը�

    virtual SelectType Select( ) = 0;              // ѡ��

    int AddWinCount( );         // ��ʤ��Ŀ����1

    int AddTotalCount( );      // ��ʤ�ܼ�

    int GetTotalCount( );
  protected :   // ˽�����ݳ�Ա

    std::string m_name;         // ��ҵ�����
    SelectType m_select;        // ��ҵ�ѡ����Ϣ
    int m_winCount;             // ��ҵĻ�ʤ��Ŀ������
    int m_totalCount;           // ����ܼ�
    bool m_character;             // ����Ƿ�Ὺ��Ц[����Ц������ǻ����ȭ�İ�]
};









#endif // PLAYER_H_INCLUDED
