/*
 * Python vs. C++ Example 4
 * Rachel J. Morris, 2013 - RachelJMorris@gmail.com, Moosader.com, github.com/Moosader
 * MIT License
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	// Generally, these shouldn't be stored in separate lists; we would create
	// a class to store name & age, but we will do this in a later example.
	vector<string> lstStudentNames;
	vector<int> lstStudentAges;
	bool doneWithProgram = false;

	while ( !doneWithProgram )
	{
		cout << endl << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. Add another student" << endl;
		cout << "2. End" << endl;
		cout << "? ";
		int choice;
		cin >> choice;

		// Keep getting user input until they enter a valid choice.
		while ( choice != 1 && choice != 2 )
		{
			cout << "Invalid choice, try again: ";
			cin >> choice;
		}

		if ( choice == 2 )
		{
			doneWithProgram = true;
		}
		else
		{
			cout << "Add new student: " << endl;
			string name;
			int age;

			cout << "Name? ";
			cin >> name;

			cout << "Age? ";
			cin >> age;

			while ( age < 0 || age > 120 )
			{
				cout << "Invalid age, must be between 0 and 120 years old" << endl;
				cout << "Age? ";
				cin >> age;
			}

			// Add new student to list
			lstStudentNames.push_back( name );
			lstStudentAges.push_back( age );
		}
	} // while ( !doneWithProgram )

	// Program over - Display students
	cout << "\n\nYour students: " << endl;
	for ( int i = 0; i < lstStudentNames.size(); i++ )
	{
		cout << lstStudentNames[i] << "\t\tAge " << lstStudentAges[i] << endl;
	}

	return 0;
}
