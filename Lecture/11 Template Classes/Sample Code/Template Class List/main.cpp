#include <iostream>
#include <string>
using namespace std;

#include "List.h"

int main()
{
    List<int> lstInts( "Int List" );

    lstInts.AddValue( 20 );
    lstInts.AddValue( 35 );
    lstInts.AddValue( 75 );

    lstInts.OutputAll();

    List<string> lstStrings( "String List" );

    lstStrings.AddValue( "Cat" );
    lstStrings.AddValue( "Dog" );
    lstStrings.AddValue( "Rat" );

    lstStrings.OutputAll();

    return 0;
}
