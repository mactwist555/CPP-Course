#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
    Person( const string& name ) : m_name( name ), m_location( "unset" )
    {
        cout << "Person constructor" << endl;
    }

    protected:
    string m_name;
    string m_location;
};

class Student : public Person
{
    public:
    Student( const string& name ) : Person( name ), m_gpa( 0 )
    {
        cout << "Student constructor 1" << endl;
    }

    Student( const string& name, float gpa ) : Person( name ), m_gpa( gpa )
    {
        cout << "Student constructor 2" << endl;
    }

    protected:
    float m_gpa;
};

int main()
{
    Person person( "Ada" );
    cout << endl;
    Student studentA( "Stephanie" );
    cout << endl;
    Student studentB( "Grace", 4.0 );

    return 0;
}



