#include <iostream>
#include <string>
#include <stdlib.h>	// random
using namespace std;

class StudentList
{
	public:
	string names[20];
	int listSize;

	StudentList() { listSize = 20; }
};

void OutputStudentList( const StudentList& list );
void GenerateStudentNames( StudentList& list );

int main()
{
	StudentList studentList;

	GenerateStudentNames( studentList );
	OutputStudentList( studentList );

	return 0;
}

void OutputStudentList( const StudentList& list )
{
	for ( int i = 0; i < list.listSize; i++ )
	{
		cout << "Student " << i << ": ";
		cout << list.names[i] << endl;
	}
}

void GenerateStudentNames( StudentList& list )
{
	// Randomly generate names
	for ( int i = 0; i < list.listSize; i++ )
	{
		list.names[i] = char( rand() % 25 + 65 );

		int nameLength = rand() % 10 + 2;
		for ( int j = 0; j < nameLength; j++ )
		{
			// Add random letter
			list.names[i] += char( rand() % 25 + 97 );
		}
		cout << endl;
	}
}
