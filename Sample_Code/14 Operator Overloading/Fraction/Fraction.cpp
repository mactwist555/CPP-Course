#include "Fraction.hpp"

ostream& operator<<( ostream& out, Fraction& item )
{
    // When streaming out, display with a / between numerator and denominator
	out << item.m_num << "/" << item.m_denom;
	return out;
}

istream& operator>>( istream& in, Fraction& item )
{
    // When streaming data in, get both the numerator and denominator
	in >> item.m_num >> item.m_denom;
	return in;
}

Fraction operator+( const Fraction& item1, const Fraction& item2 )
{
	Fraction result;
	result.SetDenom( item1.m_denom * item2.m_denom );
	result.SetNum( (item1.m_num * item2.m_denom) + (item2.m_num * item1.m_denom) );
	return result;
}

Fraction operator-( const Fraction& item1, const Fraction& item2 )
{
	Fraction result;
	result.SetDenom( item1.m_denom * item2.m_denom );
	result.SetNum( (item1.m_num * item2.m_denom) - (item2.m_num * item1.m_denom) );
	return result;
}

Fraction operator*( const Fraction& item1, const Fraction& item2 )
{
	Fraction result;
	result.SetDenom( item1.m_denom * item2.m_denom );
	result.SetNum( item1.m_num * item2.m_num );
	return result;
}

Fraction operator/( const Fraction& item1, const Fraction& item2 )
{
	Fraction result;
	result.SetDenom( item1.m_denom * item2.m_num );
	result.SetNum( item1.m_num * item2.m_denom );
	return result;
}

bool operator==( Fraction& item1, Fraction& item2 )
{
    Fraction commonItem1 = item1 * Fraction( item2.m_denom, item2.m_denom );
    Fraction commonItem2 = item2 * Fraction( item1.m_denom, item1.m_denom );
    return ( commonItem1.m_num == commonItem2.m_num && commonItem1.m_denom == commonItem2.m_denom );
}

bool operator!=( Fraction& item1, Fraction& item2 )
{
    Fraction commonItem1 = item1 * Fraction( item2.m_denom, item2.m_denom );
    Fraction commonItem2 = item2 * Fraction( item1.m_denom, item1.m_denom );
    return !(commonItem1 == commonItem2);
}

bool operator<( Fraction& item1, Fraction& item2 )
{
    Fraction commonItem1 = item1 * Fraction( item2.m_denom, item2.m_denom );
    Fraction commonItem2 = item2 * Fraction( item1.m_denom, item1.m_denom );
    return ( commonItem1.m_num < commonItem2.m_num );
}

bool operator<=( Fraction& item1, Fraction& item2 )
{
    Fraction commonItem1 = item1 * Fraction( item2.m_denom, item2.m_denom );
    Fraction commonItem2 = item2 * Fraction( item1.m_denom, item1.m_denom );
    return ( commonItem1.m_num < commonItem2.m_num || commonItem1 == commonItem2 );
}

bool operator>( Fraction& item1, Fraction& item2 )
{
    Fraction commonItem1 = item1 * Fraction( item2.m_denom, item2.m_denom );
    Fraction commonItem2 = item2 * Fraction( item1.m_denom, item1.m_denom );
    return ( commonItem1.m_num > commonItem2.m_num );
}

bool operator>=( Fraction& item1, Fraction& item2 )
{
    Fraction commonItem1 = item1 * Fraction( item2.m_denom, item2.m_denom );
    Fraction commonItem2 = item2 * Fraction( item1.m_denom, item1.m_denom );
    return ( commonItem1.m_num > commonItem2.m_num || commonItem1 == commonItem2 );
}

int Fraction::operator[]( const int index )
{
	if      ( index == 0 ) { return m_num; }
	else if ( index == 1 ) { return m_denom; }
	else                   { return -1; }
}

Fraction& Fraction::operator=( const Fraction& rhs )
{
	if ( this == &rhs ) { return *this; }

	m_num   = rhs.m_num;
	m_denom = rhs.m_denom;

	return *this;
}
