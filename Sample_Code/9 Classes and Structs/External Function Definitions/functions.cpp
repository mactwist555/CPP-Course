#include <iostream>
#include <string>
using namespace std;

class Student
{
    public:
    void SetName( string value );
    string GetName();

    void SetGPA( float value );
    float GetGPA();

    private:
    string name;
    float gpa;
};



void Student::SetName( string value )
{
    name = value;
}

string Student::GetName()
{
    return name;
}




int main()
{

    return 0;
}

