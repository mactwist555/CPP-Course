#include <iostream>
#include <string>
using namespace std;

int main()
{
    string* dynArray = new string[ 10 ];

    for ( int i = 0; i < 10; i++ )
    {
        dynArray[i] = char( 65 + i );
    }

    // This program could crash and cause a memory leak!
    for ( int i = 0; i < 50; i++ )
    {
        cout << i << "\t" << dynArray[ i ] << endl;
    }

    delete [] dynArray;
}
