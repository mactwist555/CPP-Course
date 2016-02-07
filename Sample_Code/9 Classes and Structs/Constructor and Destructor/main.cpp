#include <iostream>
using namespace std;

class MyClass
{
    public:
    MyClass()
    {
        cout << "Constructor" << endl;
    }

    MyClass( const string& value )
    {
        cout << "Constructor with value " << value << endl;
    }

    ~MyClass()
    {
        cout << "Destructor" << endl;
    }
};

int main()
{
    MyClass classA;

    if ( true )
    {
        MyClass classB( "B!" );
        MyClass classC;
    }

    return 0;
}
