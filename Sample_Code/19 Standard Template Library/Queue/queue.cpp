#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    queue<string> presidents;

    presidents.push( "George" );
    presidents.push( "John" );
    presidents.push( "Thomas" );
    presidents.push( "James" );

    while ( !presidents.empty() )
    {
        cout << presidents.size() << " in line" << endl;

        cout << "pop " << presidents.front() << endl << endl;

        presidents.pop();
    }

    return 0;
}


