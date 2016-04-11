#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "FileSystemObject.hpp"
#include "FileSystemHandler.hpp"

int main()
{
    // mp3 - vlc
    // images - eom
    // txt - geany
    string basePath = "~/TestDirectory";

    FileSystemHandler fs( basePath, "base.txt" );

    while ( true )
    {
        cout << endl << endl;
        fs.DisplayAllFiles();

        cout << "open which? ";
        int index;
        cin >> index;
        fs.Open( index );
    }

    return 0;
}
