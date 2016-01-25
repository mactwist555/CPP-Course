#include <iostream>
using namespace std;

int main()
{
    int counter = 100;

    while ( counter > 0 )
    {
        // the \t is a tab character.
        cout << counter << "\t";
        counter--;
    }

    return 0;
}

