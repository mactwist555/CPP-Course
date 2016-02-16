#include <iostream>
using namespace std;

#include "vehicle.hpp"

int main()
{
    // Oh my! We're making a dynamic array of dynamic variables!
    // Spooky!
    Vehicle** vehicles = new Vehicle*[ 3 ];
    vehicles[0] = new Bicycle;
    vehicles[1] = new Horse;
    vehicles[2] = new Car;

    for ( int time = 0; time < 10; time++ )
    {
        cout << "Time: " << time << endl;

        for ( int i = 0; i < 3; i++ )
        {
            vehicles[i]->Move();
            vehicles[i]->Display();
        }

        cout << endl << "-------------------------" << endl;
    }

    // Clear each item!
    for ( int i = 0; i < 3; i++ )
    {
        delete vehicles[i];
    }

    // Clear the array!
    delete [] vehicles;

    return 0;
}
