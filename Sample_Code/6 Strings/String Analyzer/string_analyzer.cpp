#include <iostream>
#include <string>
using namespace std;

void AnalyzeString( string sentence, string searchTerm, int& hitCount )
{
    hitCount = 0;

    int foundPosition = sentence.find( searchTerm );
    while ( foundPosition != string::npos )
    {
        hitCount++;
        sentence = sentence.replace( foundPosition, searchTerm.size(), "" );
        foundPosition = sentence.find( searchTerm );
    }
}

int main()
{
    while ( true )
    {
        string phrase = " Peter Piper picked a pack of pickled peppers. \n A pack of pickled peppers Peter Piper picked.";
        string searchTerm = "pickled";

        cout << phrase << endl;
        cout << "Search for what? ";
        cin >> searchTerm;

        int hitCount;
        AnalyzeString( phrase, searchTerm, hitCount );

        cout << hitCount << " hits" << endl << endl;
    }

    return 0;
}
