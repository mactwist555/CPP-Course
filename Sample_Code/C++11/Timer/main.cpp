#include <iostream>
#include <unistd.h>
using namespace std;

#include "SimpleTimer.hpp"

int main()
{
    SimpleTimer timer;

    cout << "Begin timer!" << endl;
    timer.Start();

    sleep( 2 );

    cout << "Elapsed time: " << timer.GetElapsed() << endl;

    return 0;
}
