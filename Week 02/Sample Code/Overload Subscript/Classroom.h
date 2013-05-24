#ifndef _CLASSROOM
#define _CLASSROOM

#include <string>
using namespace std;

struct Student
{
	string firstName;
	string lastName;
	char grade;
};

class Classroom
{
	public:
	Classroom();

	void AddStudent( string firstName, string lastName );
	void SetRandomGrades();

	Student& operator[]( const string lastName );

	private:
	int m_classSize;
	Student m_students[20];
};

#endif
