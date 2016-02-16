#include <iostream>
#include <string>
using namespace std;

int main()
{
    int* myInteger;
    myInteger = new int;

    (*myInteger) = 30;

    cout << "Address of new integer: " << myInteger << endl;
    cout << "Value of new integer:   " << (*myInteger) << endl;

    delete myInteger; // Free the memory
    myInteger = NULL; // Reset the pointer to no address

    return 0;
}


