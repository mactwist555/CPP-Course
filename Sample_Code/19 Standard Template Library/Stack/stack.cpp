#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    stack<string> presidents;

    presidents.push( "George" );
    presidents.push( "John" );
    presidents.push( "Thomas" );
    presidents.push( "James" );

    while ( !presidents.empty() )
    {
        cout << presidents.size() << " in line" << endl;
        cout << "pop " << presidents.top() << endl << endl;
        presidents.pop();
    }

    return 0;
}




