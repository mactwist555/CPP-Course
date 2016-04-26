#include <iostream>
#include <stack>
using namespace std;

/*
goto statements are frowned upon!
But if you were writing something like ASM,
there wouldn't be function calls, and
you would use "jumps" to access other parts of the program.
*/

int main()
{
    stack<int> values;

    values.push( 10 );

    loop:
    int countDown = values.top();
    values.pop();

    if ( countDown == 0 )
    {
        goto done;
    }
    if ( countDown != 0 )
    {
        cout << countDown << endl;
        values.push( countDown - 1 );
        goto loop;
    }

    done:

    return 0;
}
