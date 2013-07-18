#include <iostream>
using namespace std;

template <typename T>
void SelectionSort( T array[], int size )
{
	for ( int i = 0; i < size - 1; i++ )
	{
		int minIndex = i + 1;

		for ( int j = i+1; j < size; j++ )
		{
			if ( array[j] < array[ minIndex ] )
			{
				minIndex = j;
			}
		}

		if ( array[ minIndex ] < array[i] )
		{
			T tempValue = array[i];
			array[i] = array[ minIndex ];
			array[ minIndex ] = tempValue;
		}
	}
}

int main()
{
	int myList[] = { 2, 4, 6, 3, 2, 4, 1, 5 };

	SelectionSort<int>( myList, 8 );

	for ( int i = 0; i < 8; i++ )
	{
		cout << myList[i] << endl;
	}

	return 0;
}
