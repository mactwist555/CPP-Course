#include <iostream>
#include <string>
using namespace std;

string FormatName( string first, string last )
{
    return last + ", " + first;
}

int main()
{
    while ( true )
    {
        string first, last;
        cout << "First and last name: ";
        cin >> first >> last;
        string formatted = FormatName( first, last );
        cout << formatted << endl << endl;
    }

    return 0;
}

