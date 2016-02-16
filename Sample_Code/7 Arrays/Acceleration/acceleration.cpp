#include <iostream>
#include <string>
using namespace std;

#include "Header.h" // ignore me

int main()
{
	const int PEOPLE_COUNT = 3;

	// Use arrays instead:
	float position[PEOPLE_COUNT];
	float velocity[PEOPLE_COUNT];
	float acceleration[PEOPLE_COUNT];
	string name[PEOPLE_COUNT];

	for (int p = 0; p < PEOPLE_COUNT; p++)
	{
		cout << endl << "Person " << p << endl;
		cout << "Person name: ";
		cin >> name[p];

		cout << "Acceleration: ";
		cin >> acceleration[p];
		
		position[p] = 0;
		velocity[p] = 0;
	}

	for (int s = 0; s < 100; s++)
	{
		for (int p = 0; p < PEOPLE_COUNT; p++)
		{
			// update
			cout << "Person " << name[p] << ", Position: " << position[p] << endl;
			position[p] += velocity[p];
			velocity[p] += acceleration[p];
		}
		cout << "________________" << endl;
	}

	return 0;
}
