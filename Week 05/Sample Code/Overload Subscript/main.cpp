#include <iostream>
using namespace std;

#include "Classroom.h"

int main()
{
	Classroom myClassroom;

	myClassroom.AddStudent( "Ron", 		"Gilbert" );
	myClassroom.AddStudent( "Tim", 		"Schafer" );
	myClassroom.AddStudent( "Jane", 	"Jensen" );
	myClassroom.AddStudent( "Roberta", 	"Williams" );
	myClassroom.AddStudent( "Lori Ann", "Cole" );
	myClassroom.AddStudent( "Al", 		"Lowe" );

	myClassroom.SetRandomGrades();

	bool done = false;

	string choice;
	while ( !done )
	{
		cout << endl;
		cout << "Type the last name of the person whose grade you want to check" << endl;
		cout << "Or type EXIT" << endl;
		cin >> choice;

		if ( choice == "EXIT" || choice == "exit" )
		{
			done = true;
		}
		else
		{
			Student lookup = myClassroom[ choice ];

			cout << endl;
			cout << lookup.firstName << " " << lookup.lastName << ": ";
			cout << lookup.grade << endl;
		}
	}

	return 0;
}
