#include <iostream>
using namespace std;

int main()
{
	int* myArray = new int[50];

	delete [] myArray;

	delete [] myArray;
}
