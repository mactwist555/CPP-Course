#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
};

class Course
{
    private:
    int studentCount;
    Student students[30];

    public:
    Course() // Constructor! <3
    {
        studentCount = 0;
    }

    Student GetStudent( int index )
    {
        return students[index];
    }
};


    class Assignment
    {
        private:
        float totalPoints;
        float receivedPoints;
        float weight;

        public:
        Assignment()
        {
            totalPoints = 100;
            receivedPoints = 0;
            weight = 0.20;
        }

        Assignment( float totalPoints, float weight )
        {
            this->totalPoints = totalPoints;
            this->weight = weight;
            receivedPoints = 0;
        }
    };



int main()
{
    Assignment assignment1;

    Assignment assignment2( 100, 0.30 );

    return 0;
}

