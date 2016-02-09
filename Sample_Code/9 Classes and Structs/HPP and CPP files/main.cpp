#include <iostream>
#include <string>

#include "Cat.hpp"

using namespace std;
using namespace CuteAnimals;

int main()
{
    Cat myCat;
    myCat.Meow();

    cout << "Enter a name: ";
    string name;
    cin >> name;
    myCat.SetName( name );

    return 0;
}


