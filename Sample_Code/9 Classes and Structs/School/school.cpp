#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Assignment
{
    string title;
    float totalPoints;
    float attainedPoints;

    float GetPercent()
    {
        return attainedPoints / totalPoints * 100;
    }
};

struct Student
{
    string name;
    int id;
    Assignment assignments[10];

    float GetAverage()
    {
        float sum = 0;
        for ( int i = 0; i < 10; i++ )
        {
            sum += assignments[i].GetPercent();
        }
        float average = sum / 10;
        return average;
    }

    char GetLetterGrade()
    {
        float average = GetAverage();
        if      ( average >= 90 ) { return 'A'; }
        else if ( average >= 80 ) { return 'B'; }
        else if ( average >= 70 ) { return 'C'; }
        else if ( average >= 60 ) { return 'D'; }
        else                      { return 'F'; }
    }
};

struct Course
{
    string name;
    int id;
    int totalStudents;
    Student students[30];

    void Setup( int id, const string& name )
    {
        totalStudents = 0;
        this->name = name;
        this->id = id;
    }

    void DisplayClassSummary()
    {
        cout << "Name: " << name << ", ID: " << id << ", Total Students: " << totalStudents << endl;

        for ( int i = 0; i < totalStudents; i++ )
        {
            cout << "\t" << students[i].id
                << "\t" << students[i].GetAverage()
                << "% \t " << students[i].GetLetterGrade()
                << " \t " << students[i].name << "\t" << endl;
        }
    }

    void RegisterStudent( const string& name )
    {
        students[ totalStudents ].name = name;
        students[ totalStudents ].id = totalStudents + 100;
        totalStudents++;
    }
};

void PopulateInformation( Course& course );
int GetRandom( int minimum, int maximum );
string GetRandomName();

int main()
{
    srand( time( NULL ) );

    Course myCourse;
    myCourse.Setup( 456, "CS123" );
    PopulateInformation( myCourse );

    myCourse.DisplayClassSummary();

    return 0;
}

int GetRandom( int minimum, int maximum )
{
    int diff = maximum - minimum;
    return rand() % diff + minimum;
}

void PopulateInformation( Course& course )
{
    int totalStudents = GetRandom( 10, 30 );

    for ( int i = 0; i < totalStudents; i++ )
    {
        course.RegisterStudent( GetRandomName() );

        for ( int a = 0; a < 10; a++ )
        {
            course.students[i].assignments[a].attainedPoints = GetRandom( 60, 100 );
            course.students[i].assignments[a].totalPoints = 100;
            course.students[i].assignments[a].title = char( 65 + a );
        }
    }
}

string GetRandomName()
{
    int first = GetRandom( 0, 10 );
    int last = GetRandom( 0, 10 );

    string name = "";
    if      ( first == 0 ) { name += "Regan"; }
    else if ( first == 1 ) { name += "Delora"; }
    else if ( first == 2 ) { name += "Yuhanna"; }
    else if ( first == 3 ) { name += "Tajana"; }
    else if ( first == 4 ) { name += "Batul"; }
    else if ( first == 5 ) { name += "Alexandrine"; }
    else if ( first == 6 ) { name += "Pol"; }
    else if ( first == 7 ) { name += "Benjamin"; }
    else if ( first == 8 ) { name += "Rosabella"; }
    else if ( first == 9 ) { name += "Amelia"; }

    name += " ";

    if      ( last == 0 ) { name += "Horvath"; }
    else if ( last == 1 ) { name += "McTaggart"; }
    else if ( last == 2 ) { name += "Stern"; }
    else if ( last == 3 ) { name += "Hardwick"; }
    else if ( last == 4 ) { name += "Abraham"; }
    else if ( last == 5 ) { name += "Randal"; }
    else if ( last == 6 ) { name += "Abano"; }
    else if ( last == 7 ) { name += "Crusan"; }
    else if ( last == 8 ) { name += "Thorley"; }
    else if ( last == 9 ) { name += "Ruggeri"; }

    return name;
}
