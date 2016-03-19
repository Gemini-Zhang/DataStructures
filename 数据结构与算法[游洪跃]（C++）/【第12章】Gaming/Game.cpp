/**
******************************************************************************
*  CopyRight  : 2012-2013, HerBinUnversity, GatieMe                          *
*  File Name  : Game.cpp                                                     *
*  Description: ��Ϸ������                                                  *
*  Author     : Gatie_Me                                                     *
*  Version    : Copyright 2012 JULY_CITY                                     *
*  Data_Time  : 2012-11-6_10:21:43                                           *
*  Content    : ���ݽṹ���㷨��C++����ʯͷ������                          *
******************************************************************************
**/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include "Game.h"



bool SayYes( );
void Game::InitComPuter( )               // ��ʼ�������ĵ���
{
    this->m_computer.InitPlayer( );
}

void Game::InitPerson( )              // ��ʼ����ʵ�ĵ���
{
    this->m_person.InitPlayer( );
    std::cout <<"����ע������: " <<this->m_person.GetName( ) <<std::endl;
    this->m_gameCount = 0;
    system("pause");
    system("cls");
}

void Game::Delay( )
{
    for(int i = 0; i < 1000000; i++);
}

// ���뺯��
void Game::Lording( )
{
    system("cls");

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 100000000; j++);
        std::cout <<"��";
    }
    std::cout <<std::endl;

    system("cls");
}

void Game::Stop( )        // ֹͣ����
{
    char answer;

    do
    {	// ѭ��ֱ���û�����ǡ���Ļش�Ϊֹ
        std::cout << "(y, n)?";
        std::cout << "��y��n�ش�:";
        while ((answer = getchar( )) == '\n');	// �����ո�,�Ʊ�������з���ȡһ�ַ�

    }while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');

    //#if (VERSION)     // ���������Ϣ���
    //Version( );         // ��ʾ����ı�����Ϣ
  //  #endif

    if(answer == 'y' || answer == 'Y')
    {
    std::cout <<"**********************" <<std::endl;
    std::cout <<"**���ѡ���������Ϸ**" <<std::endl;
    std::cout <<"**********************" <<std::endl;
        exit(0);
    }
    else
    {
        std::cout <<"�û�ȡ��" <<std::endl;
    }
}

void Game::InitGame( )            // ��ʼ����Ϸ��Ϣ
{
    if(this->m_person.GetName( ) == "NULLNAME")
    {
        this->m_person.InitPlayer( );       // ��ʼ�������Ϣ
    }

    this->m_person.SelectCharacter( );

    this->m_computer.InitPlayer( );     // ��ʼ��������Ϣ

    std::cout <<std::endl <<"********************" <<std::endl;
    std::cout <<"**�μ���Ϸ�����Ϣ**" <<std::endl;
    std::cout <<"������" <<std::setw(10)<<this->m_person.GetName( ) <<"�Ը�";
    this->m_person.ShowCharacter( );
    std::cout <<"������" <<std::setw(10)<<this->m_computer.GetName( ) <<"�Ը�";
    this->m_computer.ShowCharacter( );
    std::cout <<"********************" <<std::endl;

    this->m_timeCount = 0;      // ��Ϸ��������1
}

int Game::Menu( )                // ��Ϸ�˵�
{

    system("cls");
    int choice;
    const int SIZE = 6;
    const char *menu[SIZE] = {
        "\t\t********************************************",
        "\t\t**             1 -=> ��Ϸע��             **",
        "\t\t**             2 -=> ������Ϸ             **",
        "\t\t**             3-=>  ��Ϸ����             **",
        "\t\t**          0 -=> �˳�����                **",
        "\t\t********************************************",
        };

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; menu[i][j] != '\0'; j++)
        {
            std::cout <<menu[i][j];
        }
        std::cout <<std::endl;
    }
    std::cout <<"����������ѡ��" <<std::endl;

    while( 1 )
    {
        std::cin >>choice;
        if(choice >= 0 && choice < 4)
        {
            break;
        }
        std::cout <<"�������,����������" <<std::endl;
    }
    //system("cls");
    this->Lording( );

    return choice;
}


void Game::Help( )                // ������Ϣ
{
    std::cout <<"=====================��Ϸ�����˵�=====================" <<std::endl;

    std::cout <<"==============��Ϸ��ʼ֮ǰ��Ҫ�Ƚ���ע��==============" <<std::endl;

    std::cout <<"=ע���Ժ���Կ�ʼ��Ϸ, ��Ϸ���������ѡ�����һ������=" <<std::endl;

    std::cout <<"=========��Һ͵��Ծ�������������ݼ�����Ϸ:.=========" <<std::endl;\
    std::cout <<"1-=>��ʵ���ص�    2-=>����̰���" <<std::endl;
    std::cout <<"��ʵ���أ���������ݼ�����Ϸ,���ڳ�ȭʱ�ǲ����Գ���ȭ��," <<std::endl;
    std::cout <<"          �����ҳ��˿�ȭ, �ᱻϵͳ��Ϊ�������, ��Ҫ���ٴ�����" <<std::endl;
    std::cout <<"����̰�棺������ݵ���һ��ߵ���, ���Գ���ȭ, " <<std::endl;
    std::cout <<"��˼��������ļ�, �ǻᱻ�����ǳ��˿�ȭ��" <<std::endl;


    std::cout <<"Please enter any key to continue" <<std::endl;
    system("pause");
    system("cls");
}


void Game::PlayGame( )            // ������Ϸ�ĺ���
{
    this->InitGame( );          // ��Ϸ��ʼ��
    while( 1 )
    {
        this->m_computer.Select( );     // ���Գ�ȭ
        this->m_person.Select( );       // ��ҳ�ȭ

        this->ShowResult( );            // ����ж�
        std::cout <<std::endl <<"**�������Ƿ����**" <<std::endl;
        this->m_timeCount++;        // �غϼ�������1
        if(SayYes( ) == false)
        {
            break;
        }
    }
    this->m_gameCount++;            // û����һ����Ϸ��Ϸ��������1
    this->m_person.AddTotalCount( );
    this->m_computer.AddTotalCount( );
    std::cout <<"���غϽ���" <<std::endl;
    std::cout <<"���ƽ���" <<std::setw(2)<<this->m_gameCount <<"������, ����" <<this->m_timeCount <<"�غ�" <<std::endl;
    std::cout <<"���" <<this->m_person.GetName( );
    std::cout <<"������ʤ" <<this->m_person.GetWinCount( ) <<"�غ�, �ܼƻ�ʤ" <<this->m_person.GetTotalCount( ) <<"�غ�" <<std::endl <<std::endl;
    system("pause");
}


void Game::EndGame( )             // ��Ϸ����
{
    this->Stop( );

    system("pause");
}


int Game::DisResult( )         // ��ʾ�������
{   // 1���Ӯ, -1����Ӯ, 0ƽ��
    //   ʯͷ > ���� > �� �� ʯͷ
    //   1      2      3      1
    //%2  1     0
    // return = ��man - computer+4��%3 - 1
//    11    0
//    12  3  >
//    13  4  <
//    21  3  <
//    22  4  0
//    23  5  >
//    31  4  >
//    32  5  <
//    33  6  0
    std::cout <<std::endl <<"RESULT :" <<std::endl;
    std::cout <<"****************************************" <<std::endl;
    this->m_person.ShowSelect( );
    this->m_computer.ShowSelect( );

    if(this->m_computer.GetSelect( ) == NULLOUT
       //&& this->m_computer.GetCharacter( ) == Funny
       && this->m_person.GetSelect( )  != NULLOUT)       // �����ĵ��Գ��˿�ȭ�������û�г���ȭ
    {

        //std::cout <<"**************************************" <<std::endl;
        std::cout <<"����" <<std::setw(10)<<this->m_computer.GetName( ) <<"�ոտ���һ����Ц" <<std::endl;
        //std::cout <<"**************************************" <<std::endl;

        return 1;       // �ж���������
    }
    else if(this->m_person.GetSelect( ) == NULLOUT
       //&& this->m_person.GetCharacter( ) == Funny
       && this->m_computer.GetSelect( ) != NULLOUT)     // ��������ҳ��˿�ȭ���ǵ���û�г���ȭ
    {
        //this->m_computer.ShowSelect( );
        std::cout <<"����������, �����ȭ���ǻ������" <<std::endl;
        return -1;       // �ж��������
    }
    else if(this->m_computer.GetSelect( ) == NULLOUT        // ��Һ͵��Զ����˿�ȭ
         && this->m_person.GetSelect( ) == NULLOUT)
    {

        std::cout <<"����������ϵͳ�ɾ�������" <<std::endl;
        return 0;               // ƽ�ְ�
    }
    else
    {
        //this->m_person.ShowSelect( );       // ��ʾ��ҳ�ȭ
        //this->m_computer.ShowSelect( );     // ��ʾ���Գ�ȭ
        return ((this->m_computer.GetSelect( ) - this->m_person.GetSelect( ) + 4) % 3 - 1);     // ���ؽ��
    }

}

void Game::ShowResult( )      //
{
    std::cout <<std::endl;
    switch(this->DisResult( ))
    {
    case -1:
        //std::cout <<"****************************************" <<std::endl;
        std::cout <<"==========" <<std::setw(10)<<this->m_computer.GetName( ) <<"WIN...==========*" <<std::endl;
        std::cout <<"�����㼼������Ĳ��а�......." <<std::endl;
        std::cout <<"****************************************" <<std::endl;
        this->m_computer.AddWinCount( );
        break;
    case  0:
        //std::cout <<"****************************************" <<std::endl;
        std::cout <<"==========ƽ��==========" <<std::endl;
        std::cout <<"����������ʲô��, ��������������ô׬Ǯ��" <<std::endl;
        std::cout <<"****************************************" <<std::endl;
        break;
    case  1:
        //std::cout <<"****************************************" <<std::endl;
        std::cout <<"==========" <<std::setw(10)<<this->m_person.GetName( ) <<"WIN...==========" <<std::endl;
        std::cout <<"�����Ǵ��񼶱�...." <<std::endl;
        std::cout <<"****************************************" <<std::endl;
        this->m_person.AddWinCount( );
        break;
    }
}


void Game::Gaming( )         // ������Ϸ���й���
{
    while( 1 )
    {
        int choice = this->Menu( );      // ��ʾ��Ϸ�˵�
        switch(choice)
        {
        case 1:
            this->InitPerson( );        // ע�������Ϣ
            system("cls");

            break;
        case 2:
            this->PlayGame( );          // ��Ϸ����
            break;
        case 3:
            this->Help( );
            break;
        case 0:
            this->EndGame( );
            break;
        default:
            break;
        }
    }
}
