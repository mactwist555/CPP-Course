#include <iostream>
using namespace std;

class Rectangle
{
    private:
    int x, y, width, height;

    public:
    // This const function is now guaranteed
    // to not be able to change any member variables
    // of this class.
    void Display() const
    {
        cout << "(" << x << ", " << y << ")\t"
            << width << " x " << height << endl;
    }

    void SetX( int val )        { x = val; }
    void SetY( int val )        { y = val; }
    void SetWidth( int val )    { width = val; }
    void SetHeight( int val )   { height = val; }
};

int main()
{
    return 0;
}




