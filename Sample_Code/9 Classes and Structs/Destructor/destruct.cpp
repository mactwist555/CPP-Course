#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileWriter
{
    private:
    ofstream outfile;

    public:
    FileWriter( string filename ) // Constructor
    {
        outfile.open( filename.c_str() );
    }

    ~FileWriter() // Destructor
    {
        outfile.close();
    }

    void WriteText( string text )
    {
        outfile << text << endl;
    }
};

int main()
{
    FileWriter file( "MyFile.txt" );
    file.WriteText( "Hello, World!" );
    file.WriteText( "Saluton, Mondo!" );
    file.WriteText( "Ellohay, Orldway!" );

    return 0;
}


