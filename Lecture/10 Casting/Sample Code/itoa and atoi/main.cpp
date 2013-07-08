

#include <iostream>
using namespace std;

/*
itoa and atoi are not standard
*/

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;

	char convertedNumber[128];
	itoa( number, convertedNumber, 10 ); // integer, char array, and base-10

	cout << "As a string: " << convertedNumber << endl;

	string str;
	cout << "\nEnter another number: ";
	cin >> str;

	int convertedStr = atoi( str );
	cout << "As an integer: " << convertedStr << endl;

	return 0;
}
