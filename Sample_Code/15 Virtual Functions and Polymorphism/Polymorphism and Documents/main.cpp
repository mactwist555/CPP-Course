#include <iostream>
#include <string>
using namespace std;

#include "Document.hpp"

int main()
{
    bool done = false;

    string ext;
    string docname;

    while ( !done )
    {
        cout << endl << endl << "Enter the document name:   ";
        cin >> docname;
        cout << "Enter the file extention:  " << docname << ".";
        cin >> ext;

        string filename = docname + "." + ext;

        IDocument* doc = NULL;

        if ( ext == "txt" )         { doc = new TextDocument; }
        else if ( ext == "csv" )    { doc = new CsvDocument; }
        else if ( ext == "html" )   { doc = new WebDocument; }
        else
        {
            cout << "Unknown file type" << endl;
            continue;
        }

        doc->GetInput();
        doc->Save( filename );
        delete doc;
    }

    return 0;
}


