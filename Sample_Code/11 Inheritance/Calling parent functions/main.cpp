#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
    void Setup( const string& name )
    {
        cout << "Person Setup Begin" << endl;
        m_name = name;
        m_location = "unset";
        cout << "Person Setup End" << endl;
    }

    protected:
    string m_name;
    string m_location;
};

class Student : public Person
{
    public:
    void Setup( const string& name )
    {
        cout << "Student Setup 1 Begin" << endl;
        Person::Setup( name );
        m_gpa = 0;
        cout << "Student Setup 1 End" << endl << endl;
    }

    void Setup( const string& name, float gpa )
    {
        cout << "Student Setup 2 Begin" << endl;
        Person::Setup( name );
        m_gpa = gpa;
        cout << "Student Setup 2 End" << endl << endl;
    }

    protected:
    float m_gpa;
};

int main()
{
    Student studentA;
    studentA.Setup( "Ada" );

    Student studentB;
    studentB.Setup( "Grace", 4.0 );

    return 0;
}



