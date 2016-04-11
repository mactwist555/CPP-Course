#include <iostream>
using namespace std;

void ShellSort( char arr[], int size );
void DisplayList( char arr[], int size );

int main()
{
    char letters[10] = {
        'Q', 'W', 'E', 'R', 'T',
        'A', 'S', 'D', 'F', 'G'
        };

    cout << "ORIGINAL LIST:";
    DisplayList( letters, 10 );

    ShellSort( letters, 10 );

    cout << "SORTED LIST:";
    DisplayList( letters, 10 );

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
