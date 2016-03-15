#include "Localization.hpp"

#include <fstream>
using namespace std;

void Localization::LoadFile( const string& filename )
{
    ifstream infile( filename.c_str() );

    string key, value, blank;
    while ( getline( infile, key ) )
    {
        getline( infile, value );
        if ( key == "LANGUAGE" )
        {
            m_language = value;
        }
        else
        {
            m_translations[ key ] = value;
        }
        getline( infile, blank );
    }

    infile.close();
}

string& Localization::Text( const string& key )
{
    return m_translations[ key ];
}

string& Localization::operator[]( const string& key )
{
    return Text( key );
}
