#include <iostream>
#include <string>
using namespace std;

void FireEmployees_Iterative( string employed[3], string fired[3], int amount );
void FireEmployees_Recursive( string employed[3], string fired[3], int amount );

void Display( string employed[3], string fired[3] );

int main()
{
    string employedA[3] = { "Bernard", "Hoagie", "Lavern" };
    string firedA[3];

    Display( employedA, firedA );

    FireEmployees_Iterative( employedA, firedA, 3 );
    Display( employedA, firedA );


    string employedB[3] = { "Hikaru", "Umi", "Fuu" };
    string firedB[3];

    Display( employedB, firedB );

    FireEmployees_Recursive( employedB, firedB, 3 );
    Display( employedB, firedB );

    return 0;
}

void FireEmployees_Iterative( string employed[3], string fired[3], int amount )
{
    for ( int i = 0; i < amount; i++ )
    {
        fired[i] = employed[i];
        employed[i] = "";
    }
}

void FireEmployees_Recursive( string employed[3], string fired[3], int amount )
{
    if ( amount == 0 ) return;
    fired[ amount-1 ] = employed[ amount-1 ];
    employed[ amount-1 ] = "";
    FireEmployees_Recursive( employed, fired, amount-1 );
}

void Display( string employed[3], string fired[3] )
{
    cout << endl << "EMPLOYED:" << endl;
    for ( int i = 0; i < 3; i++ )
    {
        cout << employed[i] << endl;
    }
    cout << endl << "FIRED:" << endl;
    for ( int i = 0; i < 3; i++ )
    {
        cout << fired[i] << endl;
    }
    cout << "----------------------------" << endl;
}
