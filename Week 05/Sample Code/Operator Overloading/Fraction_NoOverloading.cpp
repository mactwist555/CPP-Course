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
	Setup( num, denom );
}

int Fraction::GetCommonDenominator( Fraction frac2 )
{
	return frac2.GetDenominator() * GetDenominator();
}

int Fraction::GetNumerator()
{
	return m_numerator;
}

int Fraction::GetDenominator()
{
	return m_denominator;
}

/* These could be replaced by Stream Operators */
void Fraction::Setup( int num, int denom ) // >>
{
	m_numerator = num;
	m_denominator = denom;
}

void Fraction::Output() // <<
{
	cout << m_numerator << "/ " << m_denominator << endl;
}

/* This could be replaced by a Comparison Operator */
bool Fraction::IsEqual( Fraction frac2 ) // ==
{
	int numerator1 = GetNumerator();
	int numerator2 = frac2.GetNumerator();

	numerator1 *= frac2.GetDenominator();
	numerator2 *= GetDenominator();

	return ( numerator1 == numerator2 );
}

/* These could be replaced by Arithmetic Operators */
Fraction Fraction::Add( Fraction frac2 ) // +
{
	int commonDenom = GetCommonDenominator( frac2 );

	int numerator1 = GetNumerator();
	int numerator2 = frac2.GetNumerator();

	numerator1 *= frac2.GetDenominator();
	numerator2 *= GetDenominator();

	Fraction sum( numerator1 + numerator2, commonDenom );
	return sum;
}

Fraction Fraction::Subtract( Fraction frac2 ) // -
{
	int commonDenom = GetCommonDenominator( frac2 );

	int numerator1 = GetNumerator();
	int numerator2 = frac2.GetNumerator();

	numerator1 *= frac2.GetDenominator();
	numerator2 *= GetDenominator();

	Fraction difference( numerator1 - numerator2, commonDenom );
	return difference;
}

Fraction Fraction::Multiply( Fraction frac2 ) // *
{
	int numerator = GetNumerator() * frac2.GetNumerator();
	int denominator = GetDenominator() * frac2.GetDenominator();
	Fraction product( numerator, denominator );
	return product;
}

Fraction Fraction::Divide( Fraction frac2 ) // /
{
	int numerator = GetNumerator() * frac2.GetDenominator();
	int denominator = GetDenominator() * frac2.GetNumerator();
	Fraction quotient( numerator, denominator );
	return quotient;
}



