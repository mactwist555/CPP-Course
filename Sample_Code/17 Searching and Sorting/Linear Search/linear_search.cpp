#include <iostream>
#include <string>
using namespace std;

int FindName_Iterative( const string names[], int listSize, const string& searchTerm );
int FindName_Recursive( const string names[], int listSize, const string& searchTerm );

int main()
{
    string names[] = { "Alistair", "Morrigan", "Leilana", "Sten", "Wynne", "Oghren", "Zevran" };

    int foundIndex = FindName_Iterative( names, 7, "Sten" );
    cout << "Found " << names[ foundIndex ] << " at index " << foundIndex << endl;

    foundIndex = FindName_Recursive( names, 7, "Leilana" );
    cout << "Found " << names[ foundIndex ] << " at index " << foundIndex << endl;

    return 0;
}

int FindName_Iterative( const string names[], int listSize, const string& searchTerm )
{
    for ( int i = 0; i < listSize; i++ )
    {
        if ( names[i] == searchTerm )
            return i;
    }
    return -1; // not found
}

int FindName_Recursive( const string names[], int listSize, const string& searchTerm )
{
    if ( listSize == 0 )
        return -1; // not found
    else if ( names[ listSize - 1 ] == searchTerm )
        return listSize - 1;
    else
        return FindName_Recursive( names, listSize - 1, searchTerm );
}

