#include <iostream>
using namespace std;

int main()
{
    bool done = false;
    int counter = 100;

    while ( !done )
    {
        cout << counter << endl;
        counter--;

        if ( counter == 0 )
        {
            done = true;
        }
    }

    return 0;
}

