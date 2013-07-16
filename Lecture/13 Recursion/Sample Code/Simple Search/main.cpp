#include <iostream>
#include <string>
using namespace std;

// For formatting
void Indent( int amount )
{
    cout << endl;
    for ( int i = 0; i < amount; i++ )
    {
        cout << "---";
    }
}

// needle = string we're searching for
int IndexOfValueRecursive( string array[], int startIndex, int endIndex, const string& needle )
{
    Indent( startIndex );
    cout << "int IndexOfValueRecursive( array, " << startIndex << ", " << needle << ")" << endl;

    // Base Cases
    if ( startIndex == endIndex )
    {
        // Not found
        return -1;
    }
    if ( array[startIndex] == needle )
    {
        // Found Item
        Indent( startIndex );
        cout << startIndex << ": Base Case. Return " << startIndex << endl;

        return startIndex;
    }
    // Recursive Case
    else
    {
        Indent( startIndex );
        cout << startIndex << ": Recursive Case" << endl;

        int retIndex = IndexOfValueRecursive( array, startIndex + 1, endIndex, needle );

        Indent( startIndex );
        cout << startIndex << ": Return Value " << retIndex << endl;

        return retIndex;
    }
}

int IndexOfValueIterative( string array[], int startIndex, int endIndex, const string& needle )
{
    for ( int i = 0; i < endIndex; i++ )
    {
        if ( array[i] == needle )
        {
            // Return index of found value
            return i;
        }
    }

    // Item not found: return -1
    return -1;
}

int main()
{
    string myArray[] = {
        "Raz",
        "Lili",
        "Dogen",
        "Boyd",
        "Loboto"
        };

    for ( int i = 0; i < 5; i++ )
    {
        cout << i << ":\t" << myArray[i] << endl;
    }

    // Begin RECURSIVE function to find index
    int index = IndexOfValueRecursive( myArray, 0, 5, "Boyd" );
    cout << "Found \"Boyd\" at index: " << index << endl;

    // Begin ITERATIVE loop to find index
    index = IndexOfValueIterative( myArray, 0, 5, "Boyd" );
    cout << "Found \"Boyd\" at index: " << index << endl;

    return 0;
}


