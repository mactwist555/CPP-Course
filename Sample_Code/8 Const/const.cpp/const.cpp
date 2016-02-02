#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int screenWidth = 20;
    const int screenHeight = 10;

    for ( int y = 0; y < screenHeight; y++ )
    {
        for ( int x = 0; x < screenWidth; x++ )
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
