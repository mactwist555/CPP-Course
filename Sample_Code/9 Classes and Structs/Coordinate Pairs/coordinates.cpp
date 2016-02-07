#include <iostream>
using namespace std;

class CoordPair
{
    float x, y;

    void GetUserInput()
    {
        cout << "Enter an X, Y coordinate: ";
        cin >> x >> y;
    }

    void Display()
    {
        cout << "(" << x << ", " << y << ")";
    }
};

float GetSlope( const CoordPair& one, const CoordPair& two )
{
    return (one.y - two.y) / (one.x - two.x);
}

int main()
{
    CoordPair first, second;

    first.GetUserInput();
    second.GetUserInput();

    cout << "First: ";
    first.Display();
    cout << ", Second: ";
    second.Display();
    cout << endl;

    float slope = GetSlope( first, second );
    cout << "Slope is: " << slope << endl;

    return 0;
}
