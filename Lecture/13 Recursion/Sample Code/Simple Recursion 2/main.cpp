#include <iostream>
using namespace std;

// For formatting
void Indent( int amount )
{
    for ( int i = 0; i < amount; i++ )
    {
        cout << "---";
    }
}

// Recursive function adds [number] to itself [times] times.
int Multiply( int number, int times )
{
    cout << endl;
    Indent( times );
    cout << "int Multiply(" << number << ", " << times << ")" << endl;

    // Base Case
    if ( times == 1 )
    {
        Indent( times );
        cout << times << ": Base Case. Return " << number << endl;
        return number;
    }
    // Recursive Case
    else
    {
        Indent( times );
        cout << times << ": Recursive Case" << endl;

        int value = Multiply( number, times-1 ) + number;

        cout << endl;
        Indent( times );
        cout << times << ": Return Value " << value << endl;

        return value;
    }
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int product = Multiply( num1, num2 );

    cout << num1 << " x " << num2 << " = " << product << endl;

    return 0;
}


