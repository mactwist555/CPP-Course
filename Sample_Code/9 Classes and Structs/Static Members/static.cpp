#include <iostream>
#include <fstream>
using namespace std;

class OutputFile
{
    public:
    OutputFile( const string& filename )
    {
        file.open( filename.c_str() );
        IncFileCount();
    }

    ~OutputFile()
    {
        file.close();
        DecFileCount();
    }

    void WriteText( const string& text )
    {
        file << text << endl;
    }

    static int GetFileCount()
    {
        return fileCount;
    }

    private:

    void IncFileCount()
    {
        // These ought to be private so the
        // user isn't calling these.
        fileCount++;
    }

    void DecFileCount()
    {
        // These ought to be private so the
        // user isn't calling these.
        fileCount--;
    }


    ofstream file;
    // Declaration
    static int fileCount;
};

// Definition
int OutputFile::fileCount = 0;

int main()
{
    cout << "1 Files: " << OutputFile::GetFileCount() << endl;

    OutputFile programLog( "Log.txt" );
    cout << "2 Files: " << programLog.GetFileCount() << endl;

    OutputFile information( "Info.txt" );
    cout << "3 Files: " << information.GetFileCount() << endl;

    if ( true )
    {
        OutputFile tempFile( "Temp.txt" );
        cout << "4 Files: " << tempFile.GetFileCount() << endl;
        tempFile.WriteText( "test" );
    }

    cout << "5 Files: " << information.GetFileCount() << endl;

    return 0;
}
