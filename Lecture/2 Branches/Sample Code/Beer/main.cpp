#include <iostream>
using namespace std;

int main()
{
    char wantBeer;

    cout << "Do you want beer? (y/n): ";
    cin >> wantBeer;

    if ( wantBeer == 'y' || wantBeer == 'Y' )
    {
        int age;
        cout << "What is your age? ";
        cin >> age;

        if ( age >= 21 )
        {
            cout << "Have a beer!" << endl;
        }
        else
        {
            cout << "You can't have beer!!" << endl;
        }
    }
    else
    {
        cout << "Have a soda!" << endl;
    }

    return 0;
}

