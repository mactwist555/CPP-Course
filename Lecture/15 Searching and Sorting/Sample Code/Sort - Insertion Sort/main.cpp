#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;

#include <stdlib.h>

void GenerateValues( int array[], int size );
void Insertion( int array[], int size, int maxSize, int newValue );
void DisplayList( int list[], int size );

ofstream out;

int main()
{
	out.open( "Output.txt" );

	int myArray[20];

	// Initialize
	for ( int i = 0; i < 20; i++ ) { myArray[i] = 0; }

	int size = 10;

	GenerateValues( myArray, size );
	DisplayList( myArray, 20 );

	out << "Insert 15" << endl;
	Insertion( myArray, size++, 20, 15 );
	DisplayList( myArray, 20 );

	out << "Insert 45" << endl;
	Insertion( myArray, size++, 20, 45 );
	DisplayList( myArray, 20 );

	out << "Insert 99" << endl;
	Insertion( myArray, size++, 20, 99 );
	DisplayList( myArray, 20 );

	out.close();
	return 0;
}

void GenerateValues( int array[], int size )
{
	out << endl << endl << "GENERATE VALUES" << endl;
	for ( int i = 0; i < size; i++ )
	{
		array[i] = rand() % 10 + (10 * i);
		out << i << " = " << array[i] << endl;
	}
}

void Insertion( int array[], int size, int maxSize, int newValue )
{
	out << endl << endl << "INSERT " << newValue << " INTO ARRAY" << endl;

	assert( size + 1 < maxSize );

	// Find place to insert
	int insertAfter = 0;
	for ( int i = 0; i < size; i++ )
	{
		if ( array[i] < newValue )
		{
			insertAfter = i;
		}
	}

	// Move all the elements back
	for ( int i = size; i > insertAfter; i-- )
	{
		out << "Element " << i << " move back..." << endl;
		array[i + 1] = array[i];
	}

	// Insert the new element
	out << "Insert new element at position " << insertAfter + 1 << endl;
	array[ insertAfter + 1 ] = newValue;
}

void DisplayList( int list[], int size )
{
	out << endl << endl << "DISPLAY LIST" << endl;
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
