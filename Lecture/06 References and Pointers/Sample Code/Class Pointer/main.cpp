#include <iostream>
#include <string>
using namespace std;

class Student
{
	public:
	string name;
	float gpa;

	Student( string init_name, float init_gpa )
	{
		name = init_name;
		gpa = init_gpa;
	}
};

int main()
{
	Student studentSam( "Sam", 3.2 );
	Student* currentStudent = &studentSam;

	// cout << *currentStudent.name << endl; // Doesn't work

	// Address
	cout << currentStudent << endl;

	// studentSam's "name" member
	cout << (*currentStudent).name << endl;

	// Same as above
	cout << currentStudent->name << endl;

	currentStudent = NULL;

	return 0;
}
