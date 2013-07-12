#include <iostream>
using namespace std;

// A = 65, Z = 90
// Once our function hits 91, we're done
void WriteAlphabet( int start )
{
    if ( start == 91 )
    {
        return;
    }
    else
    {
        cout << char( start );
        WriteAlphabet( start+1 );
    }
}

int main()
{
    WriteAlphabet( 65 );

    return 0;
}

