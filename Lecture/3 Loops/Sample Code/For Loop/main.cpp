#include <iostream>
using namespace std;

int main()
{
    // Add 1 each time
    cout << " i++" << endl;
    for ( int i = 0; i < 10; i++ )
    {
        cout << i << ",";
    }

    // Add 2 each time
    cout << "\n\n i += 2" << endl;
    for ( int i = 0; i < 10; i += 2 )
    {
        cout << i << ",";
    }

    // Subtract 1 each time
    cout << "\n\n i--" << endl;
    for ( int i = 10; i > 0; i-- )
    {
        cout << i << ",";
    }

    // multiply by 2 each time
    cout << "\n\n i *= 2" << endl;
    for ( int i = 2; i < 100; i *= 2 )
    {
        cout << i << ",";
    }

    return 0;
}

