// Sample Code for CS 201 - Math
// Rachel J. Morris, 2013
// License: WTFPL

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// FLOATS
	float costOfDVD;
	float tax = 0.0725;

	cout << "\n\n How much does a DVD cost? $";
	cin >> costOfDVD;

	float totalCostOfDVD = costOfDVD + ( costOfDVD * tax );

	cout << "With tax, that is $" << totalCostOfDVD << endl;


	// INTS
	int howMany;
	cout << "\n\n How many fibonacci numbers do you want? ";
	cin >> howMany;

	int lastNumber = 1;
	int thisNumber = 1;

	cout << lastNumber << "\t";
	for ( int i = 0; i < howMany; i++ )
	{
		cout << thisNumber << endl;

		int oldNumber = thisNumber;
		thisNumber = thisNumber + lastNumber;
		lastNumber = oldNumber;
	}


	// STRINGS
	string firstName;
	string lastName;

	cout << "\n\n What is your first name? ";
	cin >> firstName;

	cout << "What is your last name? ";
	cin >> lastName;

	string fullName = lastName + ", " + firstName;

	cout << "Your name is \"" << fullName << "\"." << endl;

	return 0;
}
