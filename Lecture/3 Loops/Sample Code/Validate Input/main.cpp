#include <iostream>
using namespace std;

int main()
{
    bool done = false;

    while ( !done )
    {
        cout << endl << "------------------" << endl;
        cout << "1. Add numbers" << endl;
        cout << "2. Subtract numbers" << endl;
        cout << "3. Exit" << endl;
        cout << "What do you want to do? ";
        int choice;
        cin >> choice;

        // only checks once if you use an if statement
        // so use a while loop to check the validity of the input.
        while ( choice != 1 && choice != 2 && choice != 3 )
        {
            cout << "Invalid choice. Please select 1 or 2: ";
            cin >> choice;
        }



        if ( choice == 1 )
        {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;

            int sum = a + b;
            cout << a << " + " << b << " = " << sum << endl;
        }
        else if ( choice == 2 )
        {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;

            int difference = a - b;
            cout << a << " - " << b << " = " << difference << endl;
        }
        else if ( choice == 3 )
        {
            done = true;
        }
    }

    return 0;
}


