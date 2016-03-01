#ifndef _WEBDOCUMENT
#define _WEBDOCUMENT

#include <string>
using namespace std;

#include "Document.hpp"

class WebDocument : public Document
{
    public:
    // overwrite Output
    void Output( const string& filename );

    protected:

    private:
    // Unique function
    void WriteHtmlFile( const string& filename );
};

#endif
