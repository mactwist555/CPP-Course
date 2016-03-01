#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "GameManager.hpp"

int GetValidChoice( int min, int max );

int main()
{
    GameManager mgr;
    mgr.DisplayGames();

    return 0;
}

int GetValidChoice( int min, int max )
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
