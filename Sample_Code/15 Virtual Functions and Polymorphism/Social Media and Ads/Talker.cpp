#include "Talker.hpp"

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Menu.hpp"

Talker::Talker()
{
    m_accountFile = "accounts.txt";
    m_postFile = "posts.txt";
    m_done = false;
    LoadAccounts();
    LoadPosts();
}

Talker::~Talker()
{
    SaveAccounts();
    SavePosts();

    for ( int i = 0; i < m_accounts.size(); i++ )
    {
        delete m_accounts[i];
    }
}

void Talker::Run()
{
    GetLanguage();

    while ( !m_done )
    {
        Login();
        MainMenu();
    }
}

void Talker::LoadAccounts()
{
    ifstream input( m_accountFile.c_str() );
    if ( input.bad() ) { return; }

    string buffer;
    string type;
    string username;
    float balance;

    while ( input >> buffer )
    {
        IAccount* newAccount;

        input >> type;        // User type
        input >> buffer;
        input >> username;

        if ( type == "USER" )
        {
            newAccount = new UserAccount;
        }
        else if ( type == "ADMIN" )
        {
            newAccount = new AdminAccount;
        }
        else if ( type == "ADVERT" )
        {
            newAccount = new AdAccount;
            input >> buffer;
            input >> balance;
            dynamic_cast<AdAccount*>( newAccount )->SetBalance( balance );
        }
        newAccount->SetUsername( username );
        m_accounts.push_back( newAccount );
    }

    input.close();
}

void Talker::LoadPosts()
{
    ifstream input( m_postFile.c_str() );
    if ( input.bad() ) { return; }
    input.close();
}

void Talker::SaveAccounts()
{
    ofstream output( m_accountFile.c_str() );
    for ( int i = 0; i < m_accounts.size(); i++ )
    {
        string accountType = m_accounts[i]->AccountType();

        output  << "TYPE " << m_accounts[i]->AccountType()
                << "\t USERNAME " << m_accounts[i]->GetUsername();

        if ( accountType == "ADVERT" )
        {
            output << "\t BALANCE " << dynamic_cast<AdAccount*>( m_accounts[i] )->GetBalance();
        }
        output << endl;
    }
    output.close();
}

void Talker::SavePosts()
{
    for ( int i = 0; i < m_accounts.size(); i++ )
    {
    }
}

void Talker::MainMenu()
{
    vector<MenuOption> options;
    options.push_back( MenuOption( "CREATE", m_local[ "CREATE NEW ACCOUNT" ] ) );
    options.push_back( MenuOption( "NEW POST", m_local[ "NEW POST" ] ) );
    options.push_back( MenuOption( "VIEW WALL", m_local[ "VIEW WALL" ] ) );
    options.push_back( MenuOption( "VIEW FRIENDS", m_local[ "VIEW FRIENDS" ] ) );
    options.push_back( MenuOption( "ADD FRIEND", m_local[ "ADD FRIEND" ] ) );
    options.push_back( MenuOption( "LOG OUT", m_local[ "LOG OUT" ] ) );

    Menu::ClearScreen();
    Menu::Header( m_local[ "MAIN MENU" ] + " " + m_currentUser->GetUsername() );
    Menu::ShowMenu( options );
    int choice = Menu::GetValidChoice( 1, options.size() );
    choice -= 1;
}

void Talker::Login()
{
    vector<MenuOption> options;
    options.push_back( MenuOption( "CREATE", m_local[ "CREATE NEW ACCOUNT" ] ) );

    for ( int i = 0; i < m_accounts.size(); i++ )
    {
        options.push_back( MenuOption( m_accounts[i]->GetUsername(), m_accounts[i]->GetUsername() ) );
    }
    options.push_back( MenuOption( "QUIT", m_local[ "QUIT" ] ) );

    Menu::ClearScreen();
    Menu::Header( "LOGIN" );
    Menu::ShowMenu( options );
    int choice = Menu::GetValidChoice( 1, options.size() );
    choice -= 1;

    if ( options[ choice ].key == "CREATE" )
    {
        CreateAccount();
    }
    else
    {
        m_currentUser = m_accounts[ choice ];
    }
}

void Talker::CreateAccount()
{
    MenuOption options[] = {
        MenuOption( "USER",     m_local[ "USER ACCOUNT" ] ),
        MenuOption( "ADMIN",    m_local[ "ADMIN ACCOUNT" ] ),
        MenuOption( "ADVERT",   m_local[ "ADVERT ACCOUNT"] )
    };

    Menu::ClearScreen();
    Menu::Header( "CREATE ACCOUNT" );

    string username;
    cout << " Username: ";
    cin >> username;

    cout << " Account Type" << endl;
    int choice = Menu::ShowMenuWithPrompt( options, 3 );

    IAccount* account;
    if ( options[ choice ].key == "USER" )
    {
        account = new UserAccount;
    }
    else if ( options[ choice ].key == "ADMIN" )
    {
        account = new AdminAccount;
    }
    else if ( options[ choice ].key == "ADVERT" )
    {
        account = new AdAccount;

        cout << " Advertising balance: $";
        float balance;
        cin >> balance;
        dynamic_cast<AdAccount*>( account )->SetBalance( balance );
    }

    account->SetUsername( username );
    m_accounts.push_back( account );
    SaveAccounts();
}

void Talker::GetLanguage()
{
    string options[] = {
        "English", "Esperanto", "Pig Latin"
    };
    string filenames[] = {
        "english.txt", "esperanto.txt", "piglatin.txt"
    };

    Menu::ClearScreen();
    Menu::Header( "LANGUAGE SELECT" );
    Menu::ShowMenu( options, 3 );
    int choice = Menu::GetValidChoice( "Select your language", 1, 3 );
    choice -= 1;

    m_local.LoadFile( filenames[ choice ] );
}
