#include <iostream>
using namespace std;

#include <stdlib.h>

int Search( int myArray[], int value )
{
	int index = 0;

	while ( myArray[ index ] != value )
	{
		index++;
	}

	return index;
}

void GenerateValues( int twoDimenArray[10][10] )
{
	for ( int i = 0; i < 10; i++ )
	{
		for ( int j = 0; j < 10; j++ )
		{
			twoDimenArray[i][j] = rand() % 100;
			cout << i << "," << j << ": ";
			cout << twoDimenArray[i][j] << endl;
		}
	}
}

void DisplayMenu()
{
	cout << "1. New 	Employee" << endl;
	cout << "2. Edit 	Employee" << endl;
	cout << "3. Delete 	Employee" << endl;
	cout << "4. Quit" << endl;
}

int main()
{
	int numberArray[] = { 2, 4, 6, 8, 0, 1, 3, 5, 7, 9 };

	int index = Search( numberArray, 1 );
	cout << index << endl;

	int twoDimenArray[10][10];
	GenerateValues( twoDimenArray );

	return 0;
}
