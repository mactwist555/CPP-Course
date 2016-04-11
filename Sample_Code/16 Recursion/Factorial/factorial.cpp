#include <iostream>
using namespace std;

int Factorial_Iterative( int number );
int Factorial_Recursive( int number );

int main()
{
    int fOne = Factorial_Iterative( 5 );
    int fTwo = Factorial_Iterative( 5 );

    cout << fOne << "\t" << fTwo << endl;

    return 0;
}

int Factorial_Iterative( int number )
{
    int value = number;
    for ( int i = number-1; i > 0; i-- )
    {
        value *= i;
    }
    return value;
}

int Factorial_Recursive( int number )
{
    if ( number == 0 )
        return 1;

    return ( number * Factorial_Recursive( number - 1 ) );
}


