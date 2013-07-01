#include "Fraction.h"

#include <iostream>
using namespace std;

Fraction::Fraction()
{
	// Prevent divide by 0!
	m_numerator = m_denominator = 1;
}

Fraction::Fraction( int num, int denom )
{
	Setup( num, denom );
}

void Fraction::Setup( int num, int denom )
{
	if ( denom == 0 )
	{
		cout << "ERROR: Cannot set denominator to 0!" << endl;
		return; // Don't do anything else here!
	}

	m_numerator = num;
	m_denominator = denom;
}

void Fraction::Print()
{
	cout << m_numerator << "/" << m_denominator;
}


// Operator Overloading: Arithmetic
Fraction operator+( const Fraction& fraction1, const Fraction& fraction2 )
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

Fraction operator-( const Fraction& fraction1, const Fraction& fraction2 )
{
	Fraction difference;

	// Lazy common denominator
	Fraction commonDenom1 = fraction1, commonDenom2 = fraction2;

	commonDenom1.m_numerator *= fraction2.m_denominator;
	commonDenom1.m_denominator *= fraction2.m_denominator;

	commonDenom2.m_numerator *= fraction1.m_denominator;
	commonDenom2.m_denominator *= fraction1.m_denominator;

	difference.m_numerator = commonDenom1.m_numerator - commonDenom2.m_numerator;
	difference.m_denominator = commonDenom1.m_denominator;

	return difference;
}

Fraction operator*( const Fraction& fraction1, const Fraction& fraction2 )
{
	Fraction product = fraction1;

	product.m_numerator *= fraction2.m_numerator;
	product.m_denominator *= fraction2.m_denominator;

	return product;
}

Fraction operator/( const Fraction& fraction1, const Fraction& fraction2 )
{
	Fraction quotient = fraction1;

	quotient.m_numerator *= fraction2.m_denominator;
	quotient.m_denominator *= fraction2.m_numerator;

	return quotient;
}


// Operator Overloading: Streams
ostream& operator<<( ostream& out, const Fraction& fraction )
{
	out << fraction.m_numerator << "/" << fraction.m_denominator;
}

istream& operator>>( istream& in, Fraction& fraction )
{
	in >> fraction.m_numerator >> fraction.m_denominator;
}


// Operator Overloading: Comparisons
bool operator==( const Fraction& fraction1, const Fraction& fraction2 )
{
	// Get common denominator (lazy)
	Fraction commonDenom1 = fraction1, commonDenom2 = fraction2;

	commonDenom1.m_numerator *= fraction2.m_denominator;
	commonDenom1.m_denominator *= fraction2.m_denominator;

	commonDenom2.m_numerator *= fraction1.m_denominator;
	commonDenom2.m_denominator *= fraction1.m_denominator;

	return ( commonDenom1.m_numerator == commonDenom2.m_numerator );
}

bool operator!=( const Fraction& fraction1, const Fraction& fraction2 )
{
	// Get common denominator (lazy)
	Fraction commonDenom1 = fraction1, commonDenom2 = fraction2;

	commonDenom1.m_numerator *= fraction2.m_denominator;
	commonDenom1.m_denominator *= fraction2.m_denominator;

	commonDenom2.m_numerator *= fraction1.m_denominator;
	commonDenom2.m_denominator *= fraction1.m_denominator;

	return ( commonDenom1.m_numerator != commonDenom2.m_numerator );
}

bool operator>( 	const Fraction& fraction1, const Fraction& fraction2 )
{
	// Get common denominator (lazy)
	Fraction commonDenom1 = fraction1, commonDenom2 = fraction2;

	commonDenom1.m_numerator *= fraction2.m_denominator;
	commonDenom1.m_denominator *= fraction2.m_denominator;

	commonDenom2.m_numerator *= fraction1.m_denominator;
	commonDenom2.m_denominator *= fraction1.m_denominator;

	return ( commonDenom1.m_numerator > commonDenom2.m_numerator );
}

bool operator>=( const Fraction& fraction1, const Fraction& fraction2 )
{
	// Get common denominator (lazy)
	Fraction commonDenom1 = fraction1, commonDenom2 = fraction2;

	commonDenom1.m_numerator *= fraction2.m_denominator;
	commonDenom1.m_denominator *= fraction2.m_denominator;

	commonDenom2.m_numerator *= fraction1.m_denominator;
	commonDenom2.m_denominator *= fraction1.m_denominator;

	return ( commonDenom1.m_numerator >= commonDenom2.m_numerator );
}

bool operator<( 	const Fraction& fraction1, const Fraction& fraction2 )
{
	// Get common denominator (lazy)
	Fraction commonDenom1 = fraction1, commonDenom2 = fraction2;

	commonDenom1.m_numerator *= fraction2.m_denominator;
	commonDenom1.m_denominator *= fraction2.m_denominator;

	commonDenom2.m_numerator *= fraction1.m_denominator;
	commonDenom2.m_denominator *= fraction1.m_denominator;

	return ( commonDenom1.m_numerator < commonDenom2.m_numerator );
}

bool operator<=( const Fraction& fraction1, const Fraction& fraction2 )
{
	// Get common denominator (lazy)
	Fraction commonDenom1 = fraction1, commonDenom2 = fraction2;

	commonDenom1.m_numerator *= fraction2.m_denominator;
	commonDenom1.m_denominator *= fraction2.m_denominator;

	commonDenom2.m_numerator *= fraction1.m_denominator;
	commonDenom2.m_denominator *= fraction1.m_denominator;

	return ( commonDenom1.m_numerator <= commonDenom2.m_numerator );
}

