#ifndef _Phrase
#define _Phrase

#include <string>
using namespace std;

class Phrase
{
    public:
    Phrase() { m_text = ""; }
    Phrase( const string& phrase ) { m_text = phrase; }

    friend Phrase operator+( const Phrase& item1, const Phrase& item2 );
    friend Phrase operator-( const Phrase& item1, const Phrase& item2 );

    friend ostream& operator<<( ostream& out, Phrase& item );
    friend istream& operator>>( istream& in, Phrase& item );

    friend bool operator==( Phrase& item1, Phrase& item2 );
    friend bool operator!=( Phrase& item1, Phrase& item2 );
    friend bool operator<( Phrase& item1, Phrase& item2 );
    friend bool operator<=( Phrase& item1, Phrase& item2 );
    friend bool operator>( Phrase& item1, Phrase& item2 );
    friend bool operator>=( Phrase& item1, Phrase& item2 );

    char operator[]( const int index );

    Phrase& operator=( const Phrase& rhs );

    private:
    string m_text;
};

#endif
