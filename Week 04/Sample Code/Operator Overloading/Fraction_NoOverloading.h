#ifndef _FRACTION
#define _FRACTION

class Fraction
{
	public:
	Fraction();
	Fraction( int num, int denom );

	int GetDenominator();
	int GetNumerator();
	int GetCommonDenominator( Fraction frac2 );

	void Output();
	void Setup( int num, int denom );

	bool IsEqual( Fraction frac2 );

	Fraction Add( Fraction frac2 );
	Fraction Subtract( Fraction frac2 );
	Fraction Multiply( Fraction frac2 );
	Fraction Divide( Fraction frac2 );

	private:
	int m_numerator;
	int m_denominator;
};

#endif
