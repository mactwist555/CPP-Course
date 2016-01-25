#include <iostream>
using namespace std;

int main()
{
    int width;
    int height;

    cout << "Width and height: ";
    cin >> width >> height;

    // Draw a square
    cout << width << "x" << height << ":" << endl;
    for ( int y = 0; y < height; y++ )
    {
        for ( int x = 0; x < width; x++ )
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}


