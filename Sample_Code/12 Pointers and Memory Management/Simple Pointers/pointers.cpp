#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Variables
    int number = 10;
    string text = "Hello!";
    float money = 9.99;

    // Pointer Variables
    int* ptrInteger;
    string* ptrString;
    float* ptrFloat;

    // Assign memory addresses
    // to pointers
    ptrInteger = &number;
    ptrString = &text;
    ptrFloat = &money;

    // Can access the value of
    // those variables through
    // the pointer...
    cout << "Number: " << (*ptrInteger) << endl;
    cout << "String: " << (*ptrString) << endl;
    cout << "Float:  " << (*ptrFloat) << endl << endl;

    // We can also change the
    // value of the pointed-to variables...
    *ptrInteger = 30;
    *ptrString = "New Text";
    *ptrFloat = 3.99;

    // We can also access the
    // address that the pointer
    // is pointing to:
    cout << "ptrInteger points to: " << ptrInteger << endl;
    cout << "ptrString points to:  " << ptrString << endl;
    cout << "ptrFloat points to:   " << ptrFloat << endl << endl;

    // Pointers have their own
    // addresses, too, since they
    // are also variables.
    cout << "ptrInteger address: " << &ptrInteger << endl;
    cout << "ptrString address:  " << &ptrString << endl;
    cout << "ptrFloat address:   " << &ptrFloat << endl;

    return 0;
}
