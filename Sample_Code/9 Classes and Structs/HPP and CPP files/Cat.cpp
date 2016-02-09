#include <iostream>
using namespace std;

#include "Cat.hpp"

namespace CuteAnimals
{

void Cat::Meow()
{
    cout << "Meow!" << endl;
}
string Cat::GetName()
{
    return name;
}
void Cat::SetName( const string& value )
{
    name = value;
}

}

