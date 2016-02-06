#include <iostream>
using namespace std;

struct Rectangle
{
    int x, y, width, height;

    void Setup( int x, int y, int width, int height )
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    int GetX1() { return x; }
    int GetX2() { return x + width; }
    int GetY1() { return y; }
    int GetY2() { return y + height; }

    void DisplayInfo()
    {
        cout << "(" << x << ", " << y << "), " << width << " x " << height << endl;
    }
};

int main()
{
    Rectangle rectangles[5];

    for ( int i = 0; i < 5; i++ )
    {
        rectangles[i].Setup( i, i, 3, 2 );
        rectangles[i].DisplayInfo();
    }

    return 0;
}




