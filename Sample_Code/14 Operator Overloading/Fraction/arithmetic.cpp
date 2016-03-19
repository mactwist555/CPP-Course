#include <iostream>
using namespace std;

#include "Fraction.hpp"

string TrueOrFalse( bool val ) { return val ? "true" : "false"; }

int main()
{
    Fraction a, b;
    cout << "FRACTION 1: Enter numerator and denominator: ";
    cin >> a;
    cout << "FRACTION 2: Enter numerator and denominator: ";
    cin >> b;

    Fraction sum = a + b;
    Fraction diff = a - b;
    Fraction prod = a * b;
    Fraction quot = a / b;

    cout << endl << "ARITHMETIC" << endl;
    cout << a << " + " << b << " = " << sum << endl;
    cout << a << " - " << b << " = " << diff << endl;
    cout << a << " * " << b << " = " << prod << endl;
    cout << a << " / " << b << " = " << quot << endl;

    cout << endl << "RELATIONAL" << endl;
    cout << a << " == " << b << " ? " << TrueOrFalse( a == b ) << endl;
    cout << a << " != " << b << " ? " << TrueOrFalse( a != b ) << endl;
    cout << a << " <  " << b << " ? " << TrueOrFalse( a < b )  << endl;
    cout << a << " <= " << b << " ? " << TrueOrFalse( a <= b ) << endl;
    cout << a << " >  " << b << " ? " << TrueOrFalse( a > b )  << endl;
    cout << a << " >= " << b << " ? " << TrueOrFalse( a >= b ) << endl;

    cout << endl << "SUBSCRIPT" << endl;
    cout << "Fraction 1 Numerator:   " << a[0] << endl;
    cout << "Fraction 1 Denominator: " << a[1] << endl;
    cout << "Fraction 2 Numerator:   " << b[0] << endl;
    cout << "Fraction 2 Denominator: " << b[1] << endl;

    cout << endl << "ASSIGNMENT" << endl;
    cout << "Old: " << a << endl;
    a = Fraction( 3, 5 );
    cout << "New: " << a << endl;

    return 0;
}
