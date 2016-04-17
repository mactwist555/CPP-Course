#include <iostream>
using namespace std;

// Utilizing function overloading
//float Sum( float arr[], int size );
//int Sum( int arr[], int size );

// Utilizing templates

template <typename T>
T Sum( T arr[], int size );

template <typename T>
void OutputResult( T arr[], int size, T sum );


int main()
{
    int numbers[] = { 4, 3, 6, 2, 1 };
    int isum = Sum( numbers, 5 );
    OutputResult( numbers, 5, isum );

    float prices[] = { 2.99, 3.19, 5.29 };
    float fsum = Sum( prices, 3 );
    OutputResult( prices, 3, fsum );

    return 0;
}

template <typename T>
T Sum( T arr[], int size )
{
    T sum = 0;
    for ( int i = 0; i < size; i++ ) { sum += arr[i]; }
    return sum;
}

template <typename T>
void OutputResult( T arr[], int size, T sum )
{
    for ( int i = 0; i < size; i++ )
    {
        if ( i != 0 )
            cout << " + ";

        cout << arr[i];
    }
    cout << " = " << sum << endl;
}

//float Sum( float arr[], int size )
//{
//    float sum = 0;
//    for ( int i = 0; i < size; i++ ) { sum += arr[i]; }
//    return sum;
//}

//int Sum( int arr[], int size )
//{
//    int sum = 0;
//    for ( int i = 0; i < size; i++ ) { sum += arr[i]; }
//    return sum;
//}


