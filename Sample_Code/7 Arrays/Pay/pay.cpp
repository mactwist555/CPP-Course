#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int PEOPLE_COUNT = 5;

	string people[PEOPLE_COUNT];
	float balance[PEOPLE_COUNT];
	float hourlyPay[PEOPLE_COUNT];

	for (int i = 0; i < PEOPLE_COUNT; i++)
	{
		cout << "Entry " << (i + 1) << endl;

		cout << "Person Name: ";
		cin >> people[i];

		cout << "Hourly Pay:  ";
		cin >> hourlyPay[i];

		balance[i] = 0;
	}

	int hours;
	cout << "How many hours is everybody working? ";
	cin >> hours;

	for (int h = 0; h < hours; h++)
	{
		cout << endl << "Hour " << h << ":" << endl;

		// Add pay per hour to employee's balance
		for (int e = 0; e < PEOPLE_COUNT; e++)
		{
			balance[e] += hourlyPay[e];
			cout << people[e] << ": $" << balance[e] << endl;
		}
	}

	return 0;
}
