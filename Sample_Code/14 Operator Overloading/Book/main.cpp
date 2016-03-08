#include <iostream>
using namespace std;

#include "Book.hpp"

int main()
{
    Book alice;
    alice.Load( "Alice" );

    while ( true )
    {
        cout << endl << "-----------------" << endl;
        for ( int i = 0; i < alice.ChapterCount(); i++ )
        {
            cout << i+1 << "\t" << alice[i].GetTitle() << endl;
        }

        int choice;
        cout << "Choice: ";
        cin >> choice;
        choice -= 1;

        cout << alice[choice] << endl;
    }

    return 0;
}
