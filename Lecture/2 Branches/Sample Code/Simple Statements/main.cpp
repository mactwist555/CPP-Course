#include <iostream>
using namespace std;

int main()
{
    char choice;

    cout << "Yes or no? (y/n): ";
    cin >> choice;

    if ( choice == 'y' )
    {
        cout << "OK!" << endl;
    }
    else
    {
        cout << "Why not?" << endl;
    }

    return 0;
}
