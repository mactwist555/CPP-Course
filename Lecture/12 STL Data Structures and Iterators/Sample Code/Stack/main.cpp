#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> myStack;
    myStack.push( "Olathe" );
    myStack.push( "Raytown" );
    myStack.push( "Gladstone" );

    cout << "Size: " << myStack.size() << endl;

    string value;
    while ( myStack.size() != 0 )
    {
        value = myStack.top();
        myStack.pop();
        cout << value << endl;
    }

    myStack.empty();
    cout << "Size: " << myStack.size() << endl;

    return 0;
}
