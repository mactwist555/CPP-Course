#include <iostream>
#include <string>
using namespace std;

int main()
{
    string yourName;
    cout << "Enter your name: ";
    cin >> yourName;

    string friendsName;
    cout << "Enter your friend's name: ";
    cin >> friendsName;

    string* ptrCurrentName;

    cout << "1. Your name's address:           " << &yourName << endl;
    cout << "2. Your friend's name's address:  " << &friendsName << endl;

    int choice;
    while ( choice != 3 )
    {
        cout << "Point to which address?" << endl;
        cin >> choice;

        if ( choice == 1 )
        {
            ptrCurrentName = &yourName;
        }
        else
        {
            ptrCurrentName = &friendsName;
        }

        cout << "Memory address: " << ptrCurrentName << endl;
    }

    return 0;
}
