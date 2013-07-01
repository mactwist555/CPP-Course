#include <iostream>
using namespace std;

int main()
{
	// De-allocated Memory
	cout << "List of Numbers" << endl;

	int* listOfNumbers = new int[5];

	for ( int i = 0; i < 5; i++ )
	{
		listOfNumbers[i] = i*3;
		cout << i << " = " << listOfNumbers[i] << "\t";
	}

	delete [] listOfNumbers;

	listOfNumbers[3] = 300;

	// Un-allocated Memory
	float* listOfPrices;
	listOfPrices[2] = 300;

	for ( int i = 0; i < 5; i++ )
	{
		cout << i << " = " << listOfNumbers[i] << "\t";
	}

	return 0;
}
