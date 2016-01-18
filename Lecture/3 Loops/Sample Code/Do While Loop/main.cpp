#include <iostream>
using namespace std;

int main()
{
    bool done = true;

    // Run the internal code at least once.
    // If the criteria is TRUE, loop through again.
    do
    {
        cout << "Done? (y/n): ";
        char choice;
        cin >> choice;

        if ( choice == 'y' )
        {
            done = true;
        }
        else
        {
            done = false;
        }

    } while ( !done );


    return 0;
}
