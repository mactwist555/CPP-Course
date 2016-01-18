#include <iostream>
using namespace std;

int main()
{
    int counter = 0;
    while ( true )  // infinite loop!
    {
        cout << "Whee " << counter << endl;

        counter++;

        if ( counter == 100 )
        {
            break;  // leave the loop
        }
    }

    return 0;
}


