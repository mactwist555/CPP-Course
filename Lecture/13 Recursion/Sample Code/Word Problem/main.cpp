#include <iostream>
using namespace std;

/*
9.  A ball is dropped from a height of 8 feet.
The ball bounces to 80% of its previous height
with each bounce.  How high (to the nearest
tenth of a foot) does the ball bounce on the
fifth bounce?
http://www.regentsprep.org/Regents/math/algtrig/ATP2/GeoSeq.htm
*/

float ratio = 0.8f;

// Return height
float Bounce( int bouncesLeft, float height )
{
    if ( bouncesLeft == 0 )
    {
        cout << "Base: " << height << endl;
        return height;
    }
    else
    {
        float returnHeight = Bounce( bouncesLeft - 1, height ) * ratio;

        cout << "Bounce " << bouncesLeft << ": " << returnHeight << " ft" << endl;
        return returnHeight;
    }
}

int main()
{
    cout << "Initial height in feet? (Float, Default 8): ";
    float initHeight;
    cin >> initHeight;

    cout << "Amount of bounces? (Int, Default 5): ";
    int bounceCount;
    cin >> bounceCount;

    cout << "Amount of height lost each bounce (between 0.0 - 1.0, Default 0.8): ";
    cin >> ratio;

    cout << endl << endl;
    float height = Bounce( bounceCount, initHeight );

    cout << endl << endl;
    cout << "The ball's height during bounce #" << bounceCount << " is " << height << " ft." << endl;

    return 0;
}


// 2.6
