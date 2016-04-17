#include <iostream>
using namespace std;

void InsertionSort( char arr[], int size );
void InsertionSort_Verbose( char arr[], int size );
void DisplayList( char arr[], int size );

int main()
{
    char letters[] = { 'Q', 'W', 'E', 'R', 'T', 'Y' };
    int size = 6;

    cout << "ORIGINAL LIST:" << endl;
    DisplayList( letters, size );

//    InsertionSort_Iterative( letters, size );
    InsertionSort_Iterative_Verbose( letters, size );

    cout << "SORTED LIST:" << endl;
    DisplayList( letters, size );

    return 0;
}

void InsertionSort( char arr[], int size )
{
    int j;
    for ( int p = 1; p < size; p++ )
    {
        char value = arr[p];

        for ( j = p; j > 0 && value < arr[j-1]; j-- )
        {
            arr[j] = arr[j-1];
        }
        arr[j] = value;
    }
}

void InsertionSort_Verbose( char arr[], int size )
{
    cout << "INSERTION SORT! Array size: " << size << endl;

    int j;
    for ( int p = 1; p < size; p++ )
    {
        cout << "p = " << p << ", value is " << arr[p] << endl;
        char value = arr[p];

        j = p;
        if ( ! ( j > 0 && value < arr[j-1] ) )
        {
            cout << "\t Skip loop" << endl;
            cout << "\t\t " << value << " < " << arr[j-1] << " ? " << ( value < arr[j-1] ) << endl;
            cout << "\t\t " << j << " > 0 ? " << ( j > 0 ) << endl;
        }

        for ( j = p; j > 0 && value < arr[j-1]; j-- )
        {
            cout << "\t Move index " << j-1 << " -> " << j << "; Arr[" << j << "] = " << arr[j-1] << endl;
            arr[j] = arr[j-1];
        }
        cout << "Set index " << j << " to value of " << value << endl;
        arr[j] = value;

        cout << "End of loop iteration " << p << ", list status:" << endl;
        DisplayList( arr, size );
        cout << "------------------------------------" << endl;
    }
}

void DisplayList( char arr[], int size )
{
    for ( int i = 0; i < size; i++ )
    {
        cout << "[" << i << "=" << arr[i] << "] ";
    }
    cout << endl << endl;
}
