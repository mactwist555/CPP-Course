#include <iostream>
using namespace std;

void DrawLine_Iterative( int amount, char symbol );
void DrawLine_Recursive( int amount, char symbol );

int main()
{
    DrawLine_Iterative( 10, 'I' );

    cout << endl << endl;

    DrawLine_Recursive( 10, 'R' );

    cout << endl << endl;

    return 0;
}

void DrawLine_Iterative( int amount, char symbol )
{
    for ( int i = 0; i < amount; i++ )
    {
        cout << symbol;
    }
}

void DrawLine_Recursive( int amount, char symbol )
{
    if ( amount == 0 )  return;

    cout << symbol;
    DrawLine_Recursive( amount-1, symbol );
}



