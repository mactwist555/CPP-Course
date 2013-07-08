#include <iostream>
using namespace std;

int main()
{
	int dollars, cents;

	cout << "Enter amount of dollars: ";
	cin >> dollars;

	cout << "Enter amount of cents: ";
	cin >> cents;

	float total;

	// No Cast
	total = dollars + ( cents / 100 );
	cout << "This won't work: $" << total << endl;

	// C++ Style Cast
	total = dollars + float( cents ) / 100;
	cout << "This should work: $" << total << endl;

	// C Style Cast
	total = dollars + (float)cents / 100;
	cout << "This should also work: $" << total << endl;

	cout << "\n\n";

	return 0;
}
