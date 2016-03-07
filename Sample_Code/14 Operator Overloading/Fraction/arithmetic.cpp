#include <iostream>
using namespace std;

class Fraction
{
    private:
    int m_denom, m_num;

    public:
    Fraction()                  { Setup( 1, 1 ); }
    Fraction( int n, int d )    { Setup( n, d ); }
    void SetNum( int n )        { m_num = n; }
    void SetDenom( int d )      { m_denom = d; }
    void Setup( int n, int d )  { m_num = n; m_denom = d; }

    // Arithmetic Operator Overloading
    // * Fraction return type
    // * Two Fractions references as parameters
    friend Fraction operator+( const Fraction& item1, const Fraction& item2 );
    friend Fraction operator-( const Fraction& item1, const Fraction& item2 );
    friend Fraction operator*( const Fraction& item1, const Fraction& item2 );
    friend Fraction operator/( const Fraction& item1, const Fraction& item2 );

    // Stream Operator Overloading
    // * Returns a stream object
    // * Takes in a stream reference and fraction reference as params
    friend ostream& operator<<( ostream& out, Fraction& item );
    friend istream& operator>>( istream& in, Fraction& item );

    // Relational Operator Overloading
    // * Returns a boolean
    // * Takes in two Fraction references to compare
    friend bool operator==( Fraction& item1, Fraction& item2 );
    friend bool operator!=( Fraction& item1, Fraction& item2 );
    friend bool operator<( Fraction& item1, Fraction& item2 );
    friend bool operator<=( Fraction& item1, Fraction& item2 );
    friend bool operator>( Fraction& item1, Fraction& item2 );
    friend bool operator>=( Fraction& item1, Fraction& item2 );

    // Subscript Operator Overloading
    // * Returns any kind of data type you wish to return
    // * Takes in an index as the parameter
    // Is a member of the class, unlike the other friends
    int operator[]( const int index );

    // Assignment Operator Overloading
    // * Returns a Fraction as a parameter
    // * Takes a Fraction reference as a parameter
    Fraction& operator=( const Fraction& rhs );
};

string TrueOrFalse( bool val ) { return val ? "true" : "false"; }

int main()
{
    Fraction a, b;
    cout << "FRACTION 1: Enter numerator and denominator: ";
    cin >> a;
    cout << "FRACTION 2: Enter numerator and denominator: ";
    cin >> b;

    Fraction sum = a + b;
    Fraction diff = a - b;
    Fraction prod = a * b;
    Fraction quot = a / b;

    cout << endl << "ARITHMETIC" << endl;
    cout << a << " + " << b << " = " << sum << endl;
    cout << a << " - " << b << " = " << diff << endl;
    cout << a << " * " << b << " = " << prod << endl;
    cout << a << " / " << b << " = " << quot << endl;

    cout << endl << "RELATIONAL" << endl;
    cout << a << " == " << b << " ? " << TrueOrFalse( a == b ) << endl;
    cout << a << " != " << b << " ? " << TrueOrFalse( a != b ) << endl;
    cout << a << " <  " << b << " ? " << TrueOrFalse( a < b )  << endl;
    cout << a << " <= " << b << " ? " << TrueOrFalse( a <= b ) << endl;
    cout << a << " >  " << b << " ? " << TrueOrFalse( a > b )  << endl;
    cout << a << " >= " << b << " ? " << TrueOrFalse( a >= b ) << endl;

    cout << endl << "SUBSCRIPT" << endl;
    cout << "Fraction 1 Numerator:   " << a[0] << endl;
    cout << "Fraction 1 Denominator: " << a[1] << endl;
    cout << "Fraction 2 Numerator:   " << b[0] << endl;
    cout << "Fraction 2 Denominator: " << b[1] << endl;

    cout << endl << "ASSIGNMENT" << endl;
    cout << "Old: " << a << endl;
    a = Fraction( 3, 5 );
    cout << "New: " << a << endl;

    return 0;
}

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
