#include <iostream>
#include <string>
using namespace std;

#include <stdlib.h>

// Returns index of item
int BinarySearch( int numberList[], int min, int max, int item );

void LoadList( int numberList[50] );

int main()
{
	int numberList[50];
	LoadList( numberList );

	int value;
	cout << "Enter a number to search for: ";
	cin >> value;

	int index = BinarySearch( numberList, 0, 50, value );

	cout << endl << endl << value << " found at " << index << endl;

	return 0;
}

void LoadList( int numberList[50] )
{
	for ( int i = 0; i < 50; i++ )
	{
		numberList[i] = (rand() % 10 + (i * 10));
		cout << i << " = " << numberList[i] << endl;
	}
}

// Assuming the list is sorted
int BinarySearch( int numberList[], int min, int max, int item )
{
	int middle;
	while ( max >= min )
	{
		middle = ( min + max ) / 2;

		if ( numberList[ middle ] > item )
		{
			max = middle - 1;
		}
		else if ( numberList[ middle ] < item )
		{
			min = middle + 1;
		}
		else
		{
			return middle;
		}
	}

	return -1;
}



