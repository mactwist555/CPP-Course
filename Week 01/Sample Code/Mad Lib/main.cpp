// Sample Code for CS 201 - Mad Lib
// Rachel J. Morris, 2013
// License: WTFPL

#include <iostream>		// Include the I/O Stream library
#include <string>		// Include the String library
using namespace std;	// Using the STD (Standard) namespace in our program

int main()
{
	cout << "MADDDDDD LIB!\n\n" << endl;

	string season;
	string name;
	string noun;
	string verbed;
	string location;
	string take;

	cout << "Please enter a season: ";
	cin >> season;

	cout << "Please enter a name: ";
	cin >> name;

	cout << "Please enter a noun: ";
	cin >> noun;

	cout << "Please enter a verb, ending in \"ed\": ";
	cin >> verbed;

	cout << "Please enter a location: ";
	cin >> location;

	cout << "Please enter something that you take: ";
	cin >> take;

	cout << "\n\n" << endl;
	cout << "One warm " << season << " day, " << name << " fell over a large " << noun << "." << endl;
	cout << "Irate, " << name << " " << verbed << " and yelled at the " << noun << " so loudly that everyone in " << location << " could hear him!" << endl;
	cout << endl << endl;
	cout << name << "was, unfortunately, kicked out of " << location << " permanently, so he headed home and took a " << take << "." << endl;
	cout << endl << "THE END" << endl;

	return 0;
}
