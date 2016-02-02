#include <iostream>
#include <string>
using namespace std;

int main()
{
    string log[6] = {
        "Hello!", "Hi!", "How are you?", "I'm alright",
        "OK Bye!", "Goodbye!"
    };

    for ( int i = 0; i < 6; i++ )
    {
        if ( i % 2 == 0 )
        {
            cout << "Person A: ";
        }
        else
        {
            cout << "Person B: ";
        }
        cout << log[i] << endl;
    }

    return 0;
}

