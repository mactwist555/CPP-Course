#include <iostream>
using namespace std;

#include "Fraction.h"

Fraction Add( const Fraction& fraction1, const Fraction& fraction2 )
{
	Fraction sum;

	// Lazy common denominator
	Fraction commonDenom1 = fraction1, commonDenom2 = fraction2;

	commonDenom1.m_numerator *= fraction2.m_denominator;
	commonDenom1.m_denominator *= fraction2.m_denominator;

	commonDenom2.m_numerator *= fraction1.m_denominator;
	commonDenom2.m_denominator *= fraction1.m_denominator;

	sum.m_numerator = commonDenom1.m_numerator + commonDenom2.m_numerator;
	sum.m_denominator = commonDenom1.m_denominator;

	return sum;
}

int main()
{
	Fraction f1, f2;

	f1.Setup( 1, 2 );
	f2.Setup( 1, 2 );

	Fraction sum = Add( fraction1, fraction2 );

	Fraction sum = fraction1 + fraction2;

	f1.Print();
	cout << " + ";
	f2.Print();
	cout << " = ";
	sum.Print();

	return 0;
}
