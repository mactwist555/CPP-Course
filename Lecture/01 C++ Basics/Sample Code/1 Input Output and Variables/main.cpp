/*
 * Python vs. C++ Example 1
 * Rachel J. Morris, 2013 - RachelJMorris@gmail.com, Moosader.com, github.com/Moosader
 * MIT License
*/

#include <iostream>		// Input/Output library
#include <string>		// String library
using namespace std;	// Standard C++ namespace "std"

int main()
{
	// -- GREET USER
	cout << "Welcome to the program!" << endl;
	cout << endl;
	
	// -- GET USER INPUT
	string name;
	cout << "What is your name? ";
	cin >> name;
	
	int age;
	cout << "What is your age? ";
	cin >> age;
	
	float price;
	cout << "How much does a soda cost? (Dollars and cents) $";
	cin >> price;
	
	cout << endl << endl;
	
	// -- RESULTS
	name = "Captain " + name;
	cout << "Your name is now " << name << endl << endl;
	
	age += 1;
	cout << "Next year you will be " << age << endl << endl;
	
	price = price + ( price * 0.725 ); // Adding tax
	cout << "With a tax of 7.25%, a soda is $" << price << endl;
	
	cout << endl << endl;
	cout << "Goodbye!" << endl;
	
	return 0;
}
