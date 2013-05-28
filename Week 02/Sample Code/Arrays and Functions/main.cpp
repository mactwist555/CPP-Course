#include <iostream>
#include <stdlib.h>
using namespace std;

void AdjustForInflation( float prices[], int size );
void PrintAllPrices( float prices[], int size );

int main()
{
	float prices[10];

	// Initialize values
	for ( int i = 0; i < 10; i++ )
	{
		prices[i] = rand() % 200;
	}

	cout << "ORIGINAL PRICES:" << endl;
	PrintAllPrices( prices, 10 );

	AdjustForInflation( prices, 10 );

	cout << endl << "AFTER INFLATION:" << endl;
	PrintAllPrices( prices, 10 );

	return 0;
}

void AdjustForInflation( float prices[], int size )
{
	for ( int i = 0; i < size; i++ )
	{
		prices[i] = prices[i] * 2;
	}
}

void PrintAllPrices( float prices[], int size )
{
	for ( int i = 0; i < size; i++ )
	{
		cout << "$" << prices[i] << endl;
	}
}
