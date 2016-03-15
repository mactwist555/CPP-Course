/*
Rachel's special "I'M TIRED OF WRITING MENUS"
class object.
*/

#ifndef _MENU
#define _MENU

#include <iostream>
using namespace std;

class Menu
{
    public:
    static int ShowMenu( const string options[], int size );
    static int GetValidChoice( int min, int max );
    static void ClearScreen();

    private:
};

int Menu::ShowMenu( const string options[], int size )
{
    for ( int i = 0; i < size; i++ )
    {
        cout << (i+1) << ".\t" << options[i] << endl;
    }
    int choice = GetValidChoice( 1, size );
    return choice - 1;
}

int Menu::GetValidChoice( int min, int max )
{
    int choice;
    cout << ">> ";
    cin >> choice;

    while ( choice < min || choice > max )
    {
        cout << "Invalid selection. Try again." << endl;
        cout << ">> ";
        cin >> choice;
    }

    return choice;
}

void Menu::ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

#endif
