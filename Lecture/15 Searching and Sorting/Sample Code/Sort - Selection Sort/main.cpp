#include <iostream>
#include <fstream>
using namespace std;

#include <stdlib.h>

void GenerateNumbers( int list[], int size );
void SortList( int list[], int size );
void DisplayList( int list[], int size );

const int arraySize = 20;
ofstream out;

int main()
{
	out.open( "Output.txt" );

	// Generate random numbers to fill list
	int numberList[ arraySize ];
	GenerateNumbers( numberList, arraySize );

	// Display all the numbers
	out << "BEFORE SORT:" << endl;
	DisplayList( numberList, arraySize );

	// Sort the list
	SortList( numberList, arraySize );

	out << "AFTER SORT:" << endl;
	DisplayList( numberList, arraySize );

	out.close();

	return 0;
}

void SortList( int list[], int size )
{
	out << "Sorting..." << endl;
	for ( int i = 0; i < size - 1; i++ )
	{
		out << "i = " << i << endl;

		int minIndex = i + 1;
		for ( int j = i + 1; j < size; j++ )
		{
			if ( list[ j ] < list[ minIndex ] )
			{
				out << "\t\tNew minIndex at " << j << "(" << list[ minIndex ] << " vs. " << list[ j ] << ")" << endl;

				minIndex = j;
			}
		}

		if ( list[ minIndex ] < list[i] )
		{
			out << "\tSearched entire list, swap out index " << i << " (" << list[i] << ")";
			out << " with index " << minIndex << " (" << list[minIndex] << ")" << endl;

			// Swap out
			int oldVal = list[i];
			list[i] = list[ minIndex ];
			list[ minIndex ] = oldVal;
		}

		DisplayList( list, size );
	}
}

void GenerateNumbers( int list[], int size )
{
	out << "Generating numbers..." << endl;

	for ( int i = 0; i < size; i++ )
	{
		list[i] = rand() % 100;
	}
}

void DisplayList( int list[], int size )
{
	int counter = 0;

	for ( int i = 0; i < size; i++ )
	{
		out << i << ":  " << list[i] << "\t\t";

		if ( counter++ == 3 )
		{
			counter = 0;
			out << endl;
		}
	}
	out << endl;
}
