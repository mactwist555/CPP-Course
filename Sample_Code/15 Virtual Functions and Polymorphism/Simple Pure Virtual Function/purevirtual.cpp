#include <iostream>
#include <string>
using namespace std;

#include "Feline.hpp"

int main()
{
    HouseCat cat( "Fluffy" );
    Lion lion( "Leon" );

    cat.Purr();
    cat.Meow();

    lion.Purr();
    lion.Meow();

    return 0;
}
