#include <iostream>
#include <stdlib.h>
using namespace std;

void ChangePrice( float value );

int main()
{
	float prices[10];

	// Initialize values
	for ( int i = 0; i < 10; i++ )
	{
		prices[i] = rand() % 200;
	}

	cout << "main(): Price #3: " << prices[2] << endl;
	ChangePrice( prices[2] );
	cout << "main(): Price #3: " << prices[2] << endl;

	return 0;
}

void ChangePrice( float value )
{
	cout << "ChangePrice(): Original value: " << value << endl;
	value = 3;
	cout << "ChangePrice(): New value: " << value << endl;
}
