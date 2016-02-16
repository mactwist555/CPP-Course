// Uses dynamic arrays

#include <iostream>
using namespace std;

#include "dictionary.hpp"

int main()
{
    const string FROM_LANG = "English";
    Dictionary dictionary;

    cout << "Dictionary Program" << endl;

    while ( true )
    {
        cout << "New word? (y/n): ";
        string choice;
        cin >> choice;

        if ( choice == "n" )
        {
            break;
        }

        dictionary.AddEntry( FROM_LANG );
    }

    dictionary.Display();

    return 0;
}
