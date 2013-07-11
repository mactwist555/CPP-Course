#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<float> myQueue;
    myQueue.push( 2.99 );
    myQueue.push( 34.99 );
    myQueue.push( 5.99 );
    myQueue.push( 6.99 );

    cout << "Size: " << myQueue.size() << endl;

    while ( myQueue.size() != 0 )
    {
        float value = myQueue.front();
        cout << value << endl;
        myQueue.pop();
    }

    myQueue.empty();
    cout << "Size: " << myQueue.size() << endl;

    return 0;
}
