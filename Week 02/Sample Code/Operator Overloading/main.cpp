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

	cout << endl << "ADDITION \t";
	Fraction sum = frac1 + frac2;
	cout << sum << endl;

	cout << endl << "SUBTRACTION \t";
	Fraction difference = frac1 - frac2;
	cout << difference << endl;

	cout << endl << "MULTIPLICATION \t";
	Fraction product = frac1 * frac2;
	cout << product << endl;

	cout << endl << "DIVISION \t";
	Fraction quotient = frac1 / frac2;
	cout << quotient << endl;

	return 0;
}
