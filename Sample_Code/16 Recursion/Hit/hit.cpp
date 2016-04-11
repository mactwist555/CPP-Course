#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
    Person( const string& name )
    {
        m_name = name;
    }

    void Hit( const Person& p )
    {
        cout << "Stop hitting " << p.m_name << endl;
        Hit( p );
    }

    private:
    string m_name;
};

int main()
{
    Person yourself( "yourself" );
    yourself.Hit( yourself );

    return 0;
}
