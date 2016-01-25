#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Number 1: ";
    cin >> a;
    cout << "Number 2: ";
    cin >> b;

    cout << endl << "Type of operation?" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;

    int choice;
    cin >> choice;

    if ( choice == 1 )
    {
        int result = a + b;
        cout << a << " + " << b << " = " << result << endl;
    }
    else if ( choice == 2 )
    {
        int result = a - b;
        cout << a << " - " << b << " = " << result << endl;
    }
    else if ( choice == 3 )
    {
        int result = a * b;
        cout << a << " * " << b << " = " << result << endl;
    }
    else if ( choice == 4 )
    {
        int result = a / b;
        cout << a << " / " << b << " = " << result << endl;
    }
    else
    {
        cout << "Invalid option" << endl;
    }

    return 0;
}
