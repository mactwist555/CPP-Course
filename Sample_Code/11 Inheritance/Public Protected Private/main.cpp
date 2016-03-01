#include <iostream>

#include "Document.hpp"
#include "WebDocument.hpp"

int main()
{
    Document doc;
    WebDocument webDoc;

    doc.SetText( "Hello, World!" );
    webDoc.SetText( "Hello, World!" );

    doc.Output( "TextFile.txt" );
    webDoc.Output( "WebFile.html" );

    return 0;
}


