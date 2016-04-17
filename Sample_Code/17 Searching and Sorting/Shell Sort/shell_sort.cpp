#include <iostream>
using namespace std;

void ShellSort( char arr[], int size );
void DisplayList( char arr[], int size );

void ShellSort( int arr[], int size );
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
//    ShellSort( letters, 10 );
//
//    cout << "SORTED LIST:";
//    DisplayList( letters, 10 );

    int numbers[6] = { 9, 3, 2, 5, 1, 7 };

    cout << "ORIGINAL LIST:" << endl;
    DisplayList( numbers, 6 );

    ShellSort( numbers, 6 );

    cout << "SORTED LIST:" << endl;
    DisplayList( numbers, 6 );

    return 0;
}

void ShellSort( char a[], int size )
{
    for ( int gap = size / 2; gap > 0; gap /= 2 )
    {
        for ( int i = gap; i < size; i++ )
        {
            char value = a[i];
            int j = i;

            for ( ; j >= gap && value < a[j-gap]; j -= gap )
            {
                a[j] = a[j-gap];
            }
            a[j] = value;
        }
    }
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

void ShellSort( int a[], int size )
{
    cout << "SHELL SORT, ARRAY SIZE: " << size << endl;
    int count = 0;
    for ( int gap = size / 2; gap > 0; gap /= 2 )
    {
        cout << "Gap loop " << count++ << endl;
        for ( int i = gap; i < size; i++ )
        {
            cout << "--------------------" << endl;
            int value = a[i];
            int j = i;

            for ( ; j >= gap && value < a[j-gap]; j -= gap )
            {
                cout << "BEFORE Gap=" << gap << " i=" << i << " j=" << j << endl;
                DisplayList( a, size );
                a[j] = a[j-gap];
                cout << "AFTER  Gap=" << gap << " i=" << i << " j=" << j << "\t a[j] = a[j-gap]" << endl;
                DisplayList( a, size );
            }

            a[j] = value;
            cout << "FINALLY  Gap=" << gap << " i=" << i << " j=" << j << "\t a[j] = value" << endl;
            DisplayList( a, size );
        }
    }
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
