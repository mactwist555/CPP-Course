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

	cout << endl << "ADDITION" << endl;
	Fraction sum = frac1.Add( frac2 );
	sum.Output();

	cout << endl << "SUBTRACTION" << endl;
	Fraction difference = frac1.Subtract( frac2 );
	difference.Output();

	cout << endl << "MULTIPLICATION" << endl;
	Fraction product = frac1.Multiply( frac2 );
	product.Output();

	cout << endl << "DIVISION" << endl;
	Fraction quotient = frac1.Divide( frac2 );
	quotient.Output();

	return 0;
}
