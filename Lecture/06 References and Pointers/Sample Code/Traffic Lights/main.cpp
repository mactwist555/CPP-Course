#include <stdlib.h>
#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;

enum LightState { GREEN, YELLOW, RED };

string Name( LightState state )
{
	if ( state == GREEN ) { return "GREEN"; }
	else if ( state == YELLOW ) { return "YELLOW"; }
	else if ( state == RED ) { return "RED"; }
}

void DisplayIntersection( LightState lights[4] )
{
	cout << "\t" << Name(lights[0]) << endl << endl;
	cout << Name(lights[1]) << "\t\t" << Name(lights[3]) << endl << endl;
	cout << "\t" << Name(lights[2]) << endl;
}

int main()
{
	LightState lights[4] = { GREEN, RED, GREEN, RED };

	bool done = false;
	int counter = 0;
	int maxCounter = 2;

	bool lastGreenOdd = false;

	while ( !done )
	{

		system( "clear" );
		if ( counter == maxCounter )
		{
			for ( int i = 0; i < 4; i++ )
			{
				if ( lights[i] == GREEN )
				{
					lights[i] = YELLOW;
				}
				else if ( lights[i] == YELLOW )
				{
					lights[i] = RED;
				}
			}
			counter = 0;
		}

		if ( lights[0] == RED &&
				lights[1] == RED &&
				lights[2] == RED &&
				lights[3] == RED )
		{
			if ( lastGreenOdd )
			{
				lights[0] = lights[2] = GREEN;
				lastGreenOdd = false;
			}
			else
			{
				lights[1] = lights[3] = GREEN;
				lastGreenOdd = true;
			}
		}

		cout << "Counter: " << counter << endl;
		DisplayIntersection( lights );
		// pause
		sleep( 1 );
		//cin.get();

		counter++;
	}

	return 0;
}

