#include <iostream>
#include <vector>
using namespace std;

void SetupVector( vector<float>& list );

int main()
{
    vector<float> lstFloats;
    SetupVector( lstFloats );

    // Output all items with normal for-loop:
    for ( int i = 0; i < lstFloats.size(); i++ )
    {
        cout << lstFloats[i] << endl;
    }

    // Output all items with ITERATORS:
    for (
         vector<float>::iterator it = lstFloats.begin();
         it != lstFloats.end();
         it++
         )
    {
        // Must de-reference the iterator
        cout << *it << endl;
    }

    return 0;
}

void SetupVector( vector<float>& list )
{
    for ( int i = 0; i < 10; i++ )
    {
        list.push_back( i * 2 + i );
    }
}
