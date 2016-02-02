#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

string GetNoun()
{
    int random = rand() % 3;
    if      ( random == 0 ) { return "Pie"; }
    else if ( random == 1 ) { return "Life"; }
    else if ( random == 2 ) { return "Eye"; }
}

string GetVerb()
{
    int random = rand() % 3;
    if      ( random == 0 ) { return "Smells"; }
    else if ( random == 1 ) { return "Is"; }
    else if ( random == 2 ) { return "Sees"; }
}

string GetAdjective()
{
    int random = rand() % 3;
    if      ( random == 0 ) { return "Beautiful"; }
    else if ( random == 1 ) { return "Fragrant"; }
    else if ( random == 2 ) { return "Large"; }
}

int main()
{
    srand( time( NULL ) );

    int sentenceCount = rand() % 5 + 5;

    for ( int i = 0; i < sentenceCount; i++ )
    {
        cout << GetAdjective() << " " << GetNoun() << " " << GetVerb() << endl;
    }

    return 0;
}
