#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int i = 20;

    cout << "ONE" << endl;

    while ( i > 0 )
    {
        cout << i << "\t";
        i--;
    }

    cout << endl << endl << "TWO" << endl;

    for ( i = 20; i > 0; i-- )
    {
        cout << i << "\t";
    }

    return 0;
}
