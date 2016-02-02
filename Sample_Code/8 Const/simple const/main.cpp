#include <iostream>
#include <string>
using namespace std;

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

        cout << endl;
        cout << "Student #" << (i+1) << endl;
        cout << "Name: ";
        cin >> studentNames[i];
        cout << "GPA: ";
        cin >> gpa[i];
        studentCount++;
    }

    cout << "Total students: " << studentCount << endl;

    cout << endl;

    cout << "NAME \tGPA" << endl;
    for ( int i = 0; i < studentCount; i++ )
    {
        cout << studentNames[i] << "\t" << gpa[i] << endl;
    }

    return 0;
}
