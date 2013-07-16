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

int BinarySearch( int numberList[], int min, int max, int item )
{
	if ( max < min )
	{
		return -1;
	}
	else
	{
		int mid = ( min + max ) / 2;

		if ( numberList[ mid ] > item )
		{
			return BinarySearch( numberList, min, max - 1, item );
		}
		else if ( numberList[ mid ] < item )
		{
			return BinarySearch( numberList, min + 1, max, item );
		}
		else
		{
			return mid;
		}
	}
}




