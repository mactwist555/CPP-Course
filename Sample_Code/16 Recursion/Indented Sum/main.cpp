#include <iostream>
using namespace std;

// For formatting
void Indent( int amount )
{
    for ( int i = 0; i < amount; i++ )
    {
        cout << "---";
    }
}

// Recursive function
// SUM ( i - 1 )
int Sum( int i )
{
    Indent( i );
    cout << i << "  Sum( " << i << " ) called" << endl;

    if ( i == 1 )
    {
        Indent( i );
        cout << i << "  Base: Return " << ( i - 1 ) << endl;

        return i - 1;
    }
    else
    {
        int lastVal = Sum( i - 1 );

        Indent( i );
        cout << i << "  Recursive: Return " << ( lastVal + i - 1 ) << endl;

        return lastVal + i - 1;
    }
}

int main()
{
    cout << "Sum how many numbers? " << endl;
    int sumCount;
    cin >> sumCount;

    int sum = Sum( sumCount );
    cout << "\n\n The Sum from 1 to 5 of (i - 1) is: " << sum << endl;

    return 0;
}
