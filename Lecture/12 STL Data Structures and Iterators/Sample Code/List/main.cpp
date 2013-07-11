#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> myIntList;

    myIntList.push_back( 2 );
    myIntList.push_front( 4 );
    myIntList.push_back( 6 );
    myIntList.push_front( 8 );

    for (
         list<int>::iterator it = myIntList.begin();
         it != myIntList.end();
         it++
         )
    {
        cout << *it << endl;
    }

    myIntList.sort();
    cout << "Sorted..." << endl;

    for (
         list<int>::iterator it = myIntList.begin();
         it != myIntList.end();
         it++
         )
    {
        cout << *it << endl;
    }

    myIntList.clear();

    return 0;
}


