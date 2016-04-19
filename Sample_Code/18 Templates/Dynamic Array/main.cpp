#include <iostream>
#include <string>
using namespace std;

#include "DynamicArray.hpp"

int main()
{
    DynamicArray<string> states;
    states.Insert( "Kansas" );
    states.Insert( "Missouri" );
    states.Insert( "Nebraska" );
    states.Insert( "Colorado" );
    states.Insert( "Michigan" );
    states.Insert( "Wyoming" );
    states.Insert( "Oregon" );
    states.Insert( "Washington" );
    states.Display();

    DynamicArray<float> prices;
    prices.Insert( 9.99 );
    prices.Insert( 2.99 );
    prices.Insert( 3.99 );
    prices.Insert( 4.99 );
    prices.Insert( 5.99 );
    prices.Display();

    return 0;
}
