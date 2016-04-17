#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> cities;

    cities.push_back( "Raytown" );
    cities.push_back( "Lee's Summit" );
    cities.push_back( "Independence" );

    cout << "\n Begin" << endl;
    for ( unsigned int i = 0; i < cities.size(); i++ )
    {
        cout << i << "\t" << cities[i] << endl;
    }

    cities.erase( cities.begin() + 1 );

    cout << "\n After erase" << endl;
    for ( unsigned int i = 0; i < cities.size(); i++ )
    {
        cout << i << "\t" << cities[i] << endl;
    }

    cities.clear();

    cout << "\n After clear" << endl;
    for ( unsigned int i = 0; i < cities.size(); i++ )
    {
        cout << i << "\t" << cities[i] << endl;
    }

    return 0;
}




