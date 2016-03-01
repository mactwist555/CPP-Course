#ifndef _DOCUMENT
#define _DOCUMENT

#include <string>
using namespace std;

class Document
{
    public:
    void Output( const string& filename );
    void SetText( const string& text );

    protected:
    string m_text;

    private:
    // Unique function
    void WriteTextFile( const string& filename );
};

#endif


