#include <iostream>
#include <stdlib.h> // used for rand()
using namespace std;

int main()
{
    char keepGoing = 'y';

    do
    {
        int maximum;
        cout << "Max value: ";
        cin >> maximum;

        int random = rand() % maximum;

        cout << random << endl;
        cout << endl;
        cout << "Get another? (y/n): ";
        cin >> keepGoing;

    } while ( keepGoing == 'y' || keepGoing == 'Y' );

    return 0;
}
