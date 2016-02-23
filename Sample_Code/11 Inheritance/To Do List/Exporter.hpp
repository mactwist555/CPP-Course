#ifndef _EXPORTER
#define _EXPORTER

#include <fstream>
#include <string>
using namespace std;

class Exporter
{
    public:
    Exporter( const string& filename )
    {
        outfile.open( filename.c_str() );
    }

    ~Exporter()
    {
        outfile.close();
    }

    void Save( string contents[], int size ) { }

    protected:
    ofstream outfile;
};

class TextExporter : public Exporter
{
    public:
    TextExporter( const string& filename ) : Exporter( filename ) { }

    void Save( string contents[], int size )
    {
        for ( int i = 0; i < size; i++ )
        {
            outfile << (i+1) << ".\t" << contents[i] << endl;
        }
    }
};

class CsvExporter : public Exporter
{
    public:
    CsvExporter( const string& filename ) : Exporter( filename ) { }

    void Save( string contents[], int size )
    {
        outfile << "PRIORITY,DESCRIPTION" << endl;
        for ( int i = 0; i < size; i++ )
        {
            outfile << (i+1) << "," << contents[i] << endl;
        }
    }
};

#endif
