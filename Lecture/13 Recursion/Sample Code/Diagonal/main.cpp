#include <iostream>
using namespace std;

void Indent( int amount )
{
    for ( int i = 0; i < amount; i++ )
    {
        cout << " ";
    }
}

void Diagonal( int i )
{
    if ( i == 0 )
    {
        return;
    }
    else
    {
        Diagonal( i - 1 );

        for ( int j = 0; j < i*8; j++ )
        {
            if ( j == 0 )
            {
                cout << i;
            }
            else if ( j == i/2 )
            {
                cout << i;
            }
            else if ( j == 3 * i/2 )
            {
                cout << i;
            }
            else if ( j == 2 * i )
            {
                cout << i;
            }
            else if ( j == 4 * i )
            {
                cout << i;
            }
            else
            {
                cout << " ";
            }
        }

        cout << i << endl;
    }
}

int main()
{
    cout << "num: ";
    int num;
    cin >> num;

    Diagonal( num );

    return 0;
}
