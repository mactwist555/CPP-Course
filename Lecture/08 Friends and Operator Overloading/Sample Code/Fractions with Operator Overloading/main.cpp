#include <iostream>
using namespace std;

#include "Fraction.h"


int main()
{
	Fraction f1, f2;

	// Input Stream
	cout << "Enter Fraction 1: ";
	cin >> f1;

	cout << "Enter Fraction 2: ";
	cin >> f2;

	Fraction sum 			= f1 + f2;
	Fraction difference 	= f1 - f2;
	Fraction product 		= f1 * f2;
	Fraction quotient 		= f1 / f2;

	// Math and Output Stream
	cout << f1 << " + " << f2 << "\t = " << sum << endl;
	cout << f1 << " - " << f2 << "\t = " << difference << endl;
	cout << f1 << " * " << f2 << "\t = " << product << endl;
	cout << f1 << " / " << f2 << "\t = " << quotient << endl;

	// Comparison
	cout << f1 << " < " << f2 << " ?\t " << ( f1 < f2 ) << endl;
	cout << f1 << " <= " << f2 << " ?\t " << ( f1 <= f2 ) << endl;
	cout << f1 << " > " << f2 << " ?\t " << ( f1 > f2 ) << endl;
	cout << f1 << " >= " << f2 << " ?\t " << ( f1 >= f2 ) << endl;
	cout << f1 << " == " << f2 << " ?\t " << ( f1 == f2 ) << endl;
	cout << f1 << " != " << f2 << " ?\t " << ( f1 != f2 ) << endl;

	return 0;
}
