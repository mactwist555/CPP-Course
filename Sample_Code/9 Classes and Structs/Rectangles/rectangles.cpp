#include <iostream>
using namespace std;

int GetRandom( int minimum, int maximum )
{
    int diff = maximum - minimum;
    return rand() % diff + minimum;
}

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

    void Display()
    {
        cout << "(" << x << ", " << y << ")\t"
            << width << " x " << height << endl;
    }

    int GetXLeft()      { return x; }
    int GetXRight()     { return x + width; }
    int GetYTop()       { return y; }
    int GetYBottom()    { return y + height; }
};

int main()
{
    Rectangle rect[5];

    Rectangle rectA;
    Rectangle rectB;

    rectA.x = 50;
    rectB.x = 30;

    for ( int i = 0; i < 5; i++ )
    {
        rect[i].Setup( GetRandom( 0, 10 ), GetRandom( 0, 10 ), GetRandom( 2, 10 ), GetRandom( 2, 10 ) );
        rect[i].Display();
    }

    for ( int i = 0; i < 5; i++ )
    {
        cout << endl;
        cout << "Rectangle # " << i << endl;
        cout << "Top-left: (" << rect[i].GetXLeft() << ", " << rect[i].GetYTop()<< ")" << endl;
        cout << "Top-right: (" << rect[i].GetXRight() << ", " << rect[i].GetYTop() << ")" << endl;
        cout << "Bottom-left: (" << rect[i].GetXLeft() << ", " << rect[i].GetYBottom() << ")" << endl;
        cout << "Bottom-right: (" << rect[i].GetXRight() << ", " << rect[i].GetYBottom() << ")" << endl;
    }

    return 0;
}




