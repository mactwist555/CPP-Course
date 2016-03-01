#include <iostream>
using namespace std;

void SetNumber( int& number )
{
    number = 5;
}

int main()
{
    int myNumber1, myNumber2, myNumber3;
    SetNumber( myNumber1 );
    myNumber2 = 20;
    myNumber3 = 10;

    cout << "Variable value 1:   " << myNumber1 << endl;
    cout << "Variable address 1: " << &myNumber1 << endl << endl;

    cout << "Variable value 2:   " << myNumber2 << endl;
    cout << "Variable address 2: " << &myNumber2 << endl << endl;

    cout << "Variable value 3:   " << myNumber3 << endl;
    cout << "Variable address 3: " << &myNumber3 << endl;

    return 0;
}
