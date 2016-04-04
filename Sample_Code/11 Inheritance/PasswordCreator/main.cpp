#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Password.hpp"

int main()
{
    srand( time( NULL ) );

    while ( true )
    {
        for ( int i = 0; i < 20; i++ )
        {
            cout << endl;
        }

        WeakPassword weakPass;
        cout << "Random weak password: " << weakPass.GetRandomPassword() << endl << endl;

        MediumPassword mediumPass;
        cout << "Random medium password: " << mediumPass.GetRandomPassword() << endl << endl;

        HarderPassword hardPass;
        cout << "Random hard password: " << hardPass.GetRandomPassword() << endl << endl;

        cout << "Generate another password set? (y/n): ";
        char choice;
        cin >> choice;
        if ( tolower( choice ) == 'n' )
        {
            break;
        }
    }
}
