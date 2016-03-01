#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int grade;
};

int main()
{
    const int STUDENT_COUNT = 2;
    Student students[STUDENT_COUNT];
    Student* ptrCurrent;

    for ( int i = 0; i < STUDENT_COUNT; i++ )
    {
        ptrCurrent = &students[i];

        cout << "Enter a name: ";
        cin >> ptrCurrent->name;

        cout << "Enter the grade: ";
        cin >> ptrCurrent->grade;
    }

    for ( int i = 0; i < STUDENT_COUNT; i++ )
    {
        ptrCurrent = &students[i];
        cout << "NAME:  " << ptrCurrent->name << endl;
        cout << "GRADE: " << ptrCurrent->grade << endl;
    }

    return 0;
}
