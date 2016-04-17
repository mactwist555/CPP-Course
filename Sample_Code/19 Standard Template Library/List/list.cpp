#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    list<string> states;

    // Insert at end
    states.push_back( "Missouri" );
    states.push_back( "California" );

    // Insert at start
    states.push_front( "Kansas" );
    states.push_front( "Nebraska" );

    // Insert at any position
    list<string>::iterator pos = states.begin();
    pos++; pos++; // start at 0 and move right twice
    states.insert( pos, "Washington" );

    states.sort();
    states.reverse();

    for (
        list<string>::iterator it = states.begin();
        it != states.end();
        it++
    )
    {
        cout << *it << endl;
    }

    return 0;
}


