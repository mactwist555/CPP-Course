#include <iostream>
#include <string>
using namespace std;

float GetVelocity( float t, float a, float v0 )
{
    return a*t + v0;
}

float GetPosition( float t, float v, float a, float p0 )
{
    return 0.5*a*t*t + v*t + p0;
}

int main()
{
    float a = -9.8;
    float initVel = 0;
    float initPos = 100;


    for ( float t = 0; t < 100; t += 0.1 )
    {
        float v = GetVelocity( t, a, initVel );
        float s = GetPosition( t, v, a, initPos );

        cout << "Time " << t << " Acceleration " << a << " Velocity " << v << " Position " << s << endl;

        if ( s <= 0 )
        {
            break;
        }
    }

    return 0;
}
