#include "WebDocument.hpp"

#include <fstream>
using namespace std;

void WebDocument::Output( const string& filename )
{
    WriteHtmlFile( filename );
}

void WebDocument::WriteHtmlFile( const string& filename )
{
    ofstream output( filename.c_str() );
    output << "<html>" << endl;
    output << "<head><title>" << filename << "</title></head>" << endl;
    output << "<body>" << endl;
    output << "<p>" << m_text << "</p>" << endl;
    output << "</body>" << endl;
    output << "</html>" << endl;
    output.close();
}
