#ifndef _FRACTION
#define _FRACTION

class Fraction
{
	public:
	Fraction();
	Fraction( int num, int denom );

	void Setup( int num, int denom );

	void Print();

	friend Fraction Add( const Fraction& fraction1, const Fraction& fraction2 );

	private:
	int m_numerator;
	int m_denominator;
};

#endif
