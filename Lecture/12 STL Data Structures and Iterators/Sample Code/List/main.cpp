#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> myIntList;

    myIntList.push_back( 2 );
    myIntList.push_front( 4 );

    cout << myIntList[0] << endl;

    for ( int i = 0; i < myIntList.size(); i++ )
    {
        cout << myIntList[i] << endl;
    }

    myIntList.clear();

    return 0;
}


