#include <iostream>
using namespace std;

#include "fractionobject.hpp"

Fraction Multiply( Fraction& one, Fraction& two )
{
    Fraction product;

    product.SetNumerator( one.GetNumerator() * two.GetNumerator() );
    product.SetDenominator( one.GetDenominator() * two.GetDenominator() );

    return product;
}

int main()
{
    Fraction fraction1, fraction2, product;

    fraction1.GetUserInput();
    fraction2.GetUserInput();
    product = Multiply( fraction1, fraction2 );

    fraction1.Display();
    cout << " x ";
    fraction2.Display();
    cout << " = ";
    product.Display();
    cout << endl;

    return 0;
}
