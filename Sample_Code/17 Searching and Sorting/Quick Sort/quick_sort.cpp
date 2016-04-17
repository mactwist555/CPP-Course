#include <iostream>
using namespace std;

void QuickSort( char arr[], int left, int right );
void QuickSort( int arr[], int left, int right, int size );
void DisplayList( char arr[], int size );
void DisplayList( int arr[], int size );

int main()
{
//    char letters[10] = {
//        'Q', 'W', 'E', 'R', 'T',
//        'A', 'S', 'D', 'F', 'G'
//        };
//
//    cout << "ORIGINAL LIST:";
//    DisplayList( letters, 10 );
//
//    QuickSort( letters, 0, 9 );
//
//    cout << "SORTED LIST:";
//    DisplayList( letters, 10 );

    int numbers[5] = { 5, 3, 7, 2, 1 };
    cout << "ORIGINAL LIST:" << endl;
    DisplayList( numbers, 5 );

    QuickSort( numbers, 0, 5, 5 );

    cout << "SORTED LIST:" << endl;
    DisplayList( numbers, 5 );

    return 0;
}

void QuickSort( char arr[], int left, int right )
{
    int i = left, j = right;
    int pivot = arr[ (left + right) / 2 ];
    char value;

    while ( i <= j )
    {
        while ( arr[i] < pivot ) { i++; }
        while ( arr[j] > pivot ) { j--; }

        if ( i <= j )
        {
            value = arr[i];
            arr[i] = arr[j];
            arr[j] = value;
            i++;
            j--;
        }
    }

    if ( left < j )  { QuickSort( arr, left, j ); }
    if ( right > i ) { QuickSort( arr, i, right ); }
}

void DisplayList( char arr[], int size )
{
    for ( int i = 0; i < size; i++ )
    {
        if ( i % 5 == 0 ) { cout << endl; }
        cout << i << ": " << arr[i] << "\t";
    }
    cout << endl << endl;
}

void QuickSort( int arr[], int left, int right, int size )
{
    int i = left, j = right;
    int pivot = arr[ (left + right) / 2 ];
    char value;

    cout << "-----------------------------------------------" << endl;
    cout << "QuickSort call - left: " << left << ", right: " << right << ", pivot: " << pivot << endl;
    DisplayList( arr, size );

    while ( i <= j )
    {
        cout << endl << "WHILE i <= j | i=" << i << " j=" << j << endl;
        while ( arr[i] < pivot ) { i++; }
        while ( arr[j] > pivot ) { j--; }
        cout << "Pivotted: i = " << i << " j = " << j << endl;

        if ( i <= j )
        {
            cout << "arr[i] = " << arr[i] << " arr[j] = " << arr[j] << " i <= j, swap." << endl;

            value = arr[i];
            arr[i] = arr[j];
            arr[j] = value;
            i++;
            j--;
        }
    }

    cout << "Call QuickSort. LEFT: [" << left << ", " << j << "] RIGHT: [" << i << ", " << right << "]" << endl;
    if ( left < j )  { QuickSort( arr, left, j, size ); }
    if ( right > i ) { QuickSort( arr, i, right, size ); }
}

void DisplayList( int arr[], int size )
{
    for ( int i = 0; i < size; i++ )
    {
        cout << " " << i << "  ";
    }

    cout << endl;

    for ( int i = 0; i < size; i++ )
    {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl << endl;
}
