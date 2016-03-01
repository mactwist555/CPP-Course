#include <iostream>
#include <string>
using namespace std;

#include "DynamicString.hpp"

int main()
{
    DynamicString muffins( 5 );

    muffins.Set( 0, "Chocolate" );
    muffins.Set( 1, "Blueberry" );
    muffins.Set( 2, "Lemon" );
    muffins.Set( 3, "Apple" );
    muffins.Set( 4, "Strawberry" );
    muffins.Set( 5, "Banana" );

    for ( int i = 0; i < muffins.Size(); i++ )
    {
        cout << (i+1)
            << "\t"
            << muffins.Get( i ) << endl;
    }

    return 0;
}



