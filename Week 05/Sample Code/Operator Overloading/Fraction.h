#ifndef _FRACTION
#define _FRACTION

#include <fstream>
using namespace std;

class Fraction
{
	public:
	Fraction();
	Fraction( int num, int denom );

	int GetDenominator() const;
	int GetNumerator() const;
	int GetCommonDenominator( Fraction frac2 ) const;

	friend ostream& operator<<( ostream& out, Fraction& fraction );
	friend istream& operator>>( istream& in, Fraction& fraction );

	friend bool operator==( Fraction& frac1, Fraction& frac2 );
	friend bool operator!=( Fraction& frac1, Fraction& frac2 );

	friend Fraction operator+( const Fraction& frac1, const Fraction& frac2 );
	friend Fraction operator-( const Fraction& frac1, const Fraction& frac2 );
	friend Fraction operator*( const Fraction& frac1, const Fraction& frac2 );
	friend Fraction operator/( const Fraction& frac1, const Fraction& frac2 );

	private:
	int m_numerator;
	int m_denominator;
};

#endif
