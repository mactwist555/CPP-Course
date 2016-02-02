#include <iostream>
#include <string>
using namespace std;

void EnterStudent( int studentNumber, string& studentName, float& gpa )
{
    cout << "Student #" << studentNumber << endl;
    cout << "Name: ";
    cin >> studentName;
    cout << "GPA: ";
    cin >> gpa;
}

void DisplayStudent( int studentNumber, const string& studentName, const float& gpa )
{
    cout << "Student #" << studentNumber << "\tName: " << studentName << "\tGPA: " << gpa << endl;
}

int main()
{
    const int MAX_STUDENTS = 30;

    string studentNames[MAX_STUDENTS];
    float gpa[MAX_STUDENTS];

    int studentCount = 0;

    for ( int i = 0; i < MAX_STUDENTS; i++ )
    {
        cout << "Enter another student? (y/n): ";
        char choice;
        cin >> choice;
        if ( choice == 'n' )
        {
            break;
        }

        EnterStudent( i+1, studentNames[i], gpa[i] );
        studentCount++;
    }

    cout << "Total students: " << studentCount << endl;

    cout << endl;

    for ( int i = 0; i < studentCount; i++ )
    {
        DisplayStudent( i+1, studentNames[i], gpa[i] );
    }

    return 0;
}

