#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<int, string> employees;

    employees.insert( pair<int, string>( 1001, "Dorian" ) );
    employees.insert( pair<int, string>( 1004, "Turk" ) );
    employees.insert( pair<int, string>( 1007, "Reid" ) );

    employees.erase( 1001 );

    for (
        map<int, string>::iterator it = employees.begin();
        it != employees.end();
        it++ )
    {
        int id      = it->first;
        string name = it->second;
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    employees.clear();

    return 0;
}


