#include <iostream>
using namespace std;

void Move( double totalDistance )
{
    if ( totalDistance == 0 )
    {
        // Our double can't handle such a small number!
        cout << "OK close enough" << endl;
        return;
    }

    cout << "Move half the distance: " << totalDistance/2 << endl;
    Move( totalDistance/2 );
}

int main()
{
    cout << "How much distance is there? ";
    double totalDistance;
    cin >> totalDistance;

    Move( totalDistance );

    return 0;
}
