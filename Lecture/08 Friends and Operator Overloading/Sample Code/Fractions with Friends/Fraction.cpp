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
