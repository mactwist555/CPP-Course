#include <iostream>
using namespace std;

#include "Fraction.hpp"

int main()
{
    Fraction f1, f2;
    f1.Setup( 1, 2 );
    f2.Setup( 3, 4 );

    Fraction product = Multiply( f1, f2 );

    Fraction product = f1 * f2;


    f1.Display();
    cout << " x ";
    f2.Display();
    cout << " = ";
    product.Display();

    return 0;
}

Fraction Multiply( const Fraction& one, const Fraction& two )
{
    Fraction result;
    result.Setup(
        one.m_num * two.m_num,
        one.m_denom * two.m_denom
        );
    return result;
}



