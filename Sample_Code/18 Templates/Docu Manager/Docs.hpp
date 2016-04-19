#ifndef DOCS_HPP
#define DOCS_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Doc
{
    public:
    vector<string> content;
    virtual void Save() = 0;
};

class TextDoc : public Doc
{
    public:
    virtual void Save()
    {
        ofstream output( "blah.txt" );
        for ( unsigned int i = 0; i < content.size(); i++ )
        {
            output << content[i] << endl;
        }
        output.close();
    }
};

class CsvDoc : public Doc
{
    public:
    virtual void Save()
    {
        ofstream output( "blah.csv" );
        for ( unsigned int i = 0; i < content.size(); i++ )
        {
            if ( i % 5 == 0 ) { output << "\n"; }
            else if ( i != 0 ) { output << ","; }
            output << content[i];
        }
        output.close();
    }
};

#endif
