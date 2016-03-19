#ifndef _FRACTION
#define _FRACTION

#include <fstream>
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

#endif
