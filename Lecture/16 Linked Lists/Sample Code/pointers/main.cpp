#include <iostream>
#include <string>
using namespace std;

#include "Class.h"

int main()
{
	int number = 30;

	int* ptrNum = &number;

	SmartPointer pointer;

	pointer.SetPointer( number );
	pointer.SetPointer( &number );

	int* myNumber = new int;
	int* myArray = new int[30];

	int* ptrArray[2];
	ptrArray[0] = new int;
	ptrArray[1] = &number;

	delete ptrArray[0];

	delete myNumber;
	delete [] myArray;


	return 0;
}
