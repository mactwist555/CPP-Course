#include <iostream>
using namespace std;

#include "myfunctions.hpp"

void Exercise4();

int main()
{
    Exercise4();



    return 0;
}

int Multiply( int num1, int num2 )
{
    return num1 * num2;
}

float Multiply( float num1, float num2 )
{
    return num1 * num2;
}

void Multiply( int num1, int denom1, int num2, int denom2, int & pnum, int & pdenom )
{
    pnum = num1 * num2;
    pdenom = denom1 * denom2;
}

void Exercise4()
{
    int a = 5, b = 10;
    float c = 2.3, d = 4.0;

    int num1 = 1, num2 = 2, denom1 = 2, denom2 = 5;
    int pnum, pdenom;

    cout << a << " x " << b << " = " << Multiply( a, b ) << endl;
    cout << c << " x " << d << " = " << Multiply( c, d ) << endl;

    Multiply( num1, denom1, num2, denom2, pnum, pdenom );

    cout << num1 << "/" << denom1 << " x "
            << num2 << "/" << denom2 << " = "
            << pnum << "/" << pdenom << endl;
}
