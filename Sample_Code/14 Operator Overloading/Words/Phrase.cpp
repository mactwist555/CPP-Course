#include "Phrase.hpp"

ostream& operator<<( ostream& out, Phrase& item )
{
	out << item.m_text;
	return out;
}

istream& operator>>( istream& in, Phrase& item )
{
    in >> item.m_text;
	return in;
}

Phrase operator+( const Phrase& item1, const Phrase& item2 )
{
	return Phrase( item1.m_text + item2.m_text );
}

Phrase operator-( const Phrase& item1, const Phrase& item2 )
{
    string result = item1.m_text;
    int foundPos = result.find( item2.m_text );
    if ( foundPos != string::npos )
    {
        result.erase( foundPos, item2.m_text.size() );
    }

	return Phrase( result );
}

bool operator==( Phrase& item1, Phrase& item2 )
{
    return ( item1.m_text.size() == item2.m_text.size() );
}

bool operator!=( Phrase& item1, Phrase& item2 )
{
    return ( item1.m_text.size() != item2.m_text.size() );
}

bool operator<( Phrase& item1, Phrase& item2 )
{
    return ( item1.m_text.size() < item2.m_text.size() );
}

bool operator<=( Phrase& item1, Phrase& item2 )
{
    return ( item1 < item2 || item1 == item2 );
}

bool operator>( Phrase& item1, Phrase& item2 )
{
    return ( item1.m_text.size() > item2.m_text.size() );
}

bool operator>=( Phrase& item1, Phrase& item2 )
{
    return ( item1 > item2 || item1 == item2 );
}

char Phrase::operator[]( const int index )
{
    if ( index >= 0 && index < m_text.size() )
    {
        return m_text[ index ];
    }
    else
    {
        return ' ';
    }
}

Phrase& Phrase::operator=( const Phrase& rhs )
{
	if ( this == &rhs ) { return *this; }

	m_text = rhs.m_text;

	return *this;
}
