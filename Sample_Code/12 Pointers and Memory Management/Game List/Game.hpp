#ifndef _GAME
#define _GAME

#include <string>
#include <iostream>
using namespace std;

#include "Extras.hpp"

class Game
{
    public:
    void Setup( const string& title, Genre* genre, Platform* platform )
    {
        m_title = title;
        m_pGenre = genre;
        m_pPlatform = platform;
    }

    void Display()
    {
        cout << m_title << endl
            << "\tGENRE:    " << m_pGenre->name << endl
            << "\tPLATFORM: " << m_pPlatform->name << endl;
    }

    private:
    Genre* m_pGenre;
    Platform* m_pPlatform;
    string m_title;
};

#endif
