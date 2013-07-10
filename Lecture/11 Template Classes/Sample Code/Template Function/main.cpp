#include <string>
#include <iostream>
using namespace std;

/* FUNCTION OVERLOADING */
int Add( int num1, int num2 )
{
    return num1 + num2;
}

float Add( float num1, float num2 )
{
    return num1 + num2;
}

/* TEMPLATE VERSION */
template <typename T> // could also use <class T>
T Add( T num1, T num2 )
{
    return num1 + num2;
}

int main()
{
    // Add two floats
    float float1, float2;
    cout << "Enter two floats, separated by a space: ";
    cin >> float1 >> float2;

    float sum1 = Add( float1, float2 );             // Overload version
    float sum2 = Add<float>( float1, float2 );      // Template version

    cout << sum1 << ", " << sum2 << endl;

    // Add two ints
    int int1, int2;
    cout << "Enter two ints, separated by a space: ";
    cin >> int1 >> int2;

    int sum3 = Add( int1, int2 );       // Overload version
    int sum4 = Add<int>( int1, int2 );  // Template version

    cout << sum3 << ", " << sum4 << endl;


    // But that's not all... with Templates, we can use Add on anything
    // that has the + operator overloaded!

    string string1, string2;
    cout << "Enter two strings, separated by a space: ";
    cin >> string1 >> string2;

    string sum5 = Add<string>( string1, string2 );

    cout << sum5 << endl;

    return 0;
}
