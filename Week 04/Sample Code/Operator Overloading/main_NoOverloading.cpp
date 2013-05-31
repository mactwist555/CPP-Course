#include <iostream>
using namespace std;

#include "Fraction.h"

int main()
{
	Fraction frac1;
	Fraction frac2;

	cout << "FRACTION 1" << endl;
	cout << "\t Numerator? ";
	int num1;
	cin >> num1;
	cout << "\t Denominator? ";
	int denom1;
	cin >> denom1;

	cout << endl << "FRACTION 2" << endl;
	cout << "\t Numerator? ";
	int num2;
	cin >> num2;
	cout << "\t Denominator? ";
	int denom2;
	cin >> denom2;

	frac1.Setup( num1, denom1 );
	frac2.Setup( num2, denom2 );

	cout << endl << "ARE THEY EQUAL?";
	if ( frac1.IsEqual( frac2 ) )
	{
		cout << "\t Yes" << endl;
	}
	else
	{
		cout << "\t No" << endl;
	}

	Fraction sum = frac1.Add( frac2 );
	Fraction difference = frac1.Subtract( frac2 );
	Fraction product = frac1.Multiply( frac2 );
	Fraction quotient = frac1.Divide( frac2 );

	cout << endl << "ADDITION: \t";
	sum.Output();

	cout << endl << "SUBTRACTION: \t";
	difference.Output();

	cout << endl << "MULTIPLICATION: \t";
	product.Output();

	cout << endl << "DIVISION: \t";
	quotient.Output();

	return 0;
}
