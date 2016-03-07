#include <iostream>
using namespace std;

class Vector
{
    public:
    Vector( float x, float y )
    {
        m_x = x;
        m_y = y;
    }

    void Display() const
    {
        cout << "(" << m_x << ", " << m_y << ")" << endl;
    }

    private:
    float m_x, m_y;
};

int main()
{
    Vector v( 2, 4 );
    v.Display();

    return 0;
}
