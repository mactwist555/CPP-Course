#include <iostream>
#include <string>
using namespace std;

class Point
{
    public:
    void Set( int x, int y )
    {
        m_x = x;
        m_y = y;
    }

    void Display()
    {
        cout << "(" << m_x << ", " << m_y << ")";
    }

    string pointName;

    private:
    int m_x, m_y;
};

int main()
{
    Point firstPoint;
    Point secondPoint;

    firstPoint.Set( 0, 5 );
    secondPoint.Set( 10, 12 );

    cout << "Point 1: ";
    firstPoint.Display();
    cout << "\t Point 2: ";
    secondPoint.Display();

    Point* ptrPoint = &firstPoint;

    cout << "\n Pointer value:" << endl;
    // Option 1:    Access with the de-reference operator;
    //              must be surrounded with parenthesis.
    (*ptrPoint).Display();

    // This won't work due to order of operations:
    // *ptrPoint.Display();

    cout << "\n Pointer value:" << endl;
    // Option 2:    Access with the member access operator:
    ptrPoint->Display();

    return 0;
}
