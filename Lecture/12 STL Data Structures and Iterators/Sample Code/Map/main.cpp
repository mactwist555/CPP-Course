#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> nameAndAge;

    nameAndAge.insert( pair<string, int>( "Lucille",    23 ) );
    nameAndAge.insert( pair<string, int>( "George",     66 ) );
    nameAndAge.insert( pair<string, int>( "Michael",    40 ) );
    nameAndAge.insert( pair<string, int>( "Lindsay",    42 ) );
    nameAndAge.insert( pair<string, int>( "Gob",        43 ) );

    cout << "Size: " << nameAndAge.size() << endl;

    for (
         map<string, int>::iterator it = nameAndAge.begin();
         it != nameAndAge.end();
         it++
         )
     {
         cout << it->first << ", " << it->second << endl;
     }

    cout << nameAndAge[ "Lucille" ] << endl;

    return 0;
}
