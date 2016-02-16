#include "Document.hpp"

#include <fstream>
using namespace std;

void Document::Output( const string& filename )
{
    WriteTextFile( filename );
}

void Document::SetText( const string& text )
{
    m_text = text;
}

void Document::WriteTextFile( const string& filename )
{
    ofstream output( filename.c_str() );
    output << m_text << endl;
    output.close();
}
