#include <iostream>
using namespace std;

int main()
{
    int counter = 100;

    while ( counter-- > 0 )
    {
        cout << endl;
        cout << "counter: " << counter << endl;

        if ( counter % 2 == 0 ) // if counter is even
        {
            cout << "Even number!" << endl;
            continue;
        }

        // This isn't displayed if continue is hit.
        cout << "next iteration!" << endl;
    }

    return 0;
}


