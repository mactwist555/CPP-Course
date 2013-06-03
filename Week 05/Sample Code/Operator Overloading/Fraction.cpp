#include "Fraction.h"

#include <iostream>
using namespace std;

Fraction::Fraction()
{
	m_numerator = 0;
	m_denominator = 1;
}

Fraction::Fraction( int num, int denom )
{
	m_numerator = num;
	m_denominator = denom;
}

int Fraction::GetCommonDenominator( Fraction frac2 ) const
{
	return frac2.GetDenominator() * GetDenominator();
}

int Fraction::GetNumerator() const
{
	return m_numerator;
}

int Fraction::GetDenominator() const
{
	return m_denominator;
}

ostream& operator<<( ostream& out, Fraction& fraction )
{
	out << fraction.m_numerator << "/" << fraction.m_denominator;
	return out;
}

istream& operator>>( istream& in, Fraction& fraction )
{
	in >> fraction.m_numerator;
	in >> fraction.m_denominator;
}

bool operator==( Fraction& frac1, Fraction& frac2 )
{
	int numerator1 = frac1.GetNumerator();
	int numerator2 = frac2.GetNumerator();

	numerator1 *= frac2.GetDenominator();
	numerator2 *= frac1.GetDenominator();

	return ( numerator1 == numerator2 );
}

bool operator!=( Fraction& frac1, Fraction& frac2 )
{
	return !( frac1 == frac2 );
}

Fraction operator+( const Fraction& frac1, const Fraction& frac2 )
{
	int commonDenom = frac1.GetCommonDenominator( frac2 );

	int numerator1 = frac1.GetNumerator();
	int numerator2 = frac2.GetNumerator();

	numerator1 *= frac2.GetDenominator();
	numerator2 *= frac1.GetDenominator();

	Fraction sum( numerator1 + numerator2, commonDenom );
	return sum;
}

Fraction operator-( const Fraction& frac1, const Fraction& frac2 )
{
	int commonDenom = frac1.GetCommonDenominator( frac2 );

	int numerator1 = frac1.GetNumerator();
	int numerator2 = frac2.GetNumerator();

	numerator1 *= frac2.GetDenominator();
	numerator2 *= frac1.GetDenominator();

	Fraction difference( numerator1 - numerator2, commonDenom );
	return difference;
}

Fraction operator*( const Fraction& frac1, const Fraction& frac2 )
{
	int numerator 	= frac1.GetNumerator() 		* frac2.GetNumerator();
	int denominator = frac1.GetDenominator() 	* frac2.GetDenominator();
	Fraction product( numerator, denominator );
	return product;
}

Fraction operator/( const Fraction& frac1, const Fraction& frac2 )
{
	int numerator 	= frac1.GetNumerator() 		* frac2.GetDenominator();
	int denominator = frac1.GetDenominator() 	* frac2.GetNumerator();
	Fraction quotient( numerator, denominator );
	return quotient;
}

