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
        IDocument* doc = NULL;

        cout << endl << endl << "Enter the document name:   ";
        cin >> docname;
        cout << "Enter the file extention:  " << docname << ".";
        cin >> ext;

        string filename = docname + "." + ext;

        if ( ext == "txt" )
        {
            doc = new TextDocument;
            doc->GetInput();
            doc->Save( filename );
        }
        else if ( ext == "csv" )
        {
            doc = new CsvDocument;
            doc->GetInput();
            doc->Save( filename );
        }
        else if ( ext == "html" )
        {
            doc = new WebDocument;
            doc->GetInput();
            doc->Save( filename );
        }
        else
        {
            cout << "Unknown file type" << endl;
        }

        if ( doc != NULL )
        {
            delete doc;
        }
    }

    return 0;
}


