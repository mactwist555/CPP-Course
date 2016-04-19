#include <iostream>
#include "Metric.hpp"
using namespace std;

template <typename T>
float CalculateArea( const T& width, const T& height )
{
    return width.Get() * height.Get();
}

int main()
{
    int roomCount;
    cout << "How many rooms? ";
    cin >> roomCount;

    float totalArea = 0;
    string unitSuffix;
    for ( int i = 0; i < roomCount; i++ )
    {
        cout << "[M]eters or [F]eet? ";
        char unit;
        cin >> unit;
        unit = tolower( unit );

        float w, h, area;
        if ( unit == 'm' )
        {
            cout << "Width: ";
            cin >> w;
            Meter width( w );
            width.Output();

            cout << "Height: ";
            cin >> h;
            Meter height( h );
            height.Output();

            unitSuffix = width.GetSquaredUnit();
            area = CalculateArea( width, height );
        }
        else
        {
            cout << "Width: ";
            cin >> w;
            Feet width( w );
            width.Output();

            cout << "Height: ";
            cin >> h;
            Feet height( h );
            height.Output();

            unitSuffix = width.GetSquaredUnit();
            area = CalculateArea( width, height );
        }

        cout << "Total area: " << area << " " << unitSuffix << endl;
    }

    return 0;
}
