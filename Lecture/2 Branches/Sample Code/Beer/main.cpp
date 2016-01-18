#include <iostream>
using namespace std;

int main()
{
    cout << "Do you want a beer? (y/n): ";
    char wantBeer;
    cin >> wantBeer;

    if ( wantBeer == 'y' || wantBeer == 'Y' )
    {
        cout << "What is your age? ";
        int age;
        cin >> age;

        if ( age < 21 )
        {
            cout << "You can't have a beer!" << endl;
        }
        else
        {
            cout << "Here is a beer!" << endl;
        }
    }
    else if ( wantBeer == 'n' || wantBeer == 'N' )
    {
        cout << "OK, here is some soda instead." << endl;
    }
    else
    {
        cout << "I don't know what '" << wantBeer << "' means!" << endl;
    }

    return 0;
}
