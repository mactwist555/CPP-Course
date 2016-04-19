#include <iostream>
#include <string>
#include <list>
using namespace std;

struct Student
{
    Student( const string& n, float g ) { name = n; gpa = g; }
    void Output() { cout << gpa << "\t" << name << endl; }

    bool operator<( const Student& s )      { return ( gpa < s.gpa ); }
    bool operator>( const Student& s )      { return ( gpa > s.gpa ); }
    bool operator<=( const Student& s )     { return ( gpa <= s.gpa ); }
    bool operator>=( const Student& s )     { return ( gpa >= s.gpa ); }
    bool operator==( const Student& s )     { return ( gpa == s.gpa ); }
    bool operator!=( const Student& s )     { return ( gpa != s.gpa ); }

    string name;
    float gpa;
};

void DisplayStudents( list<Student>& students )
{
    for ( list<Student>::iterator it = students.begin();
        it != students.end();
        it++ )
    {
        it->Output();
    }
}

int main()
{
    list<Student> students;
    students.push_back( Student( "Paul Armstrong", 4.00 ) );
    students.push_back( Student( "Betty Armstrong", 2.02 ) );
    students.push_back( Student( "Roger Fleming", 3.92 ) );
    students.push_back( Student( "Lattis", 3.89 ) );
    students.push_back( Student( "Kro-Bar", 3.79 ) );

    cout << "ALL STUDENTS BY ENTRY:" << endl;
    DisplayStudents( students );

    students.sort();
    students.reverse();

    cout << endl << "ALL STUDENTS BY GPA:" << endl;
    DisplayStudents( students );

    return 0;
}
