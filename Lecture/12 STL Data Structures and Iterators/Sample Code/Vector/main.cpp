#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> myIntList;

    myIntList.push_back( 2 );
    myIntList.push_back( 4 );

    cout << myIntList[0] << endl;

    for ( int i = 0; i < myIntList.size(); i++ )
    {
        cout << myIntList[i] << endl;
    }

    myIntList.clear();

    return 0;
}

