#include <iostream>
#include <string>
using namespace std;

void IncrementNumber( int* number )
{
	(*number) += 1;
}

void IncrementNumber( int& number )
{
	number++;
}

int main()
{

	cout << "1. " << number << endl;

	IncrementNumber( number );
	cout << "2. " << number << endl;

	int number = 20;
	int* ptrNumber = &number;

	IncrementNumber( ptrNumber );


	return 0;
}

