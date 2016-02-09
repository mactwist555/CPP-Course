#ifndef _CAT
#define _CAT

#include <string>
using namespace std;

namespace CuteAnimals
{

class Cat
{
    public:
    void Meow();
    string GetName();
    void SetName( const string& value );

    private:
    string name;
};

}

#endif



