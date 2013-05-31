#include <iostream>
using namespace std;

#include "Fraction.h"

int main()
{
	Fraction frac1;
	Fraction frac2;

	cout << "FRACTION 1" << endl;
	cout << "Enter Numerator and Denominator, separated by a space: ";
	cin >> frac1;

	cout << endl << "FRACTION 2" << endl;
	cout << "Enter Numerator and Denominator, separated by a space: ";
	cin >> frac2;

	cout << endl << "ARE THEY EQUAL?";
	if ( frac1 == frac2 )
	{
		cout << "\t Yes" << endl;
	}
	else
	{
		cout << "\t No" << endl;
	}

	Fraction sum = frac1 + frac2;
	Fraction difference = frac1 - frac2;
	Fraction product = frac1 * frac2;
	Fraction quotient = frac1 / frac2;

	cout << endl << "ADDITION \t";
	cout << sum << endl;

	cout << endl << "SUBTRACTION \t";
	cout << difference << endl;

	cout << endl << "MULTIPLICATION \t";
	cout << product << endl;

	cout << endl << "DIVISION \t";
	cout << quotient << endl;

	return 0;
}
