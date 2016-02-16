#include <iostream>
#include <cmath>
using namespace std;

int* GetAddress( int& item )
{
    return &item;
}

int main()
{
    int myNumber = 300;
    int* ptrNumber = GetAddress( myNumber );

    cout << "Address of myNumber:           " << &myNumber << endl;
    cout << "Address ptrNumber points to:   " << ptrNumber << endl;
    cout << "Value:                         " << *ptrNumber << endl;

    return 0;
}



