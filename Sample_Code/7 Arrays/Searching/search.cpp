#include <iostream>
using namespace std;

// Returns the position that it was found, or -1.
int FindValue( char haystack[], int maxSize, char searchVal )
{
    for ( int i = 0; i < maxSize; i++ )
    {
        if ( haystack[i] == searchVal )
        {
            // Found at this position
            return i;
        }
    }

    // Not found
    return -1;
}

int main()
{
    char letterArray[] = { 'h', 'e', 'l', 'l', 'o', '!' };
    int arrayLength = 6;
    char searchFor;
    int foundPosition = -1;

    cout << "Search for letter: ";
    cin >> searchFor;

    foundPosition = FindValue( letterArray, arrayLength, searchFor );
    cout << "Found at position: " << foundPosition << endl;

    return 0;
}
