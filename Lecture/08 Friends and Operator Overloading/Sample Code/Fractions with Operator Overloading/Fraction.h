#ifndef _FRACTION
#define _FRACTION

#include <iostream>
using namespace std;

class Fraction
{
	public:
	Fraction();
	Fraction( int num, int denom );

	void Setup( int num, int denom );

	void Print();

	// Operator Overloading: Arithmetic
	friend Fraction operator+( const Fraction& fraction1, const Fraction& fraction2 );
	friend Fraction operator-( const Fraction& fraction1, const Fraction& fraction2 );
	friend Fraction operator*( const Fraction& fraction1, const Fraction& fraction2 );
	friend Fraction operator/( const Fraction& fraction1, const Fraction& fraction2 );

	// Operator Overloading: Streams
	friend ostream& operator<<( ostream& out, const Fraction& fraction );
	friend istream& operator>>( istream& in, Fraction& fraction );

	// Operator Overloading: Comparisons
	friend bool operator==( const Fraction& fraction1, const Fraction& fraction2 );
	friend bool operator!=( const Fraction& fraction1, const Fraction& fraction2 );
	friend bool operator>( 	const Fraction& fraction1, const Fraction& fraction2 );
	friend bool operator>=( const Fraction& fraction1, const Fraction& fraction2 );
	friend bool operator<( 	const Fraction& fraction1, const Fraction& fraction2 );
	friend bool operator<=( const Fraction& fraction1, const Fraction& fraction2 );

	private:
	int m_numerator;
	int m_denominator;
};

#endif
