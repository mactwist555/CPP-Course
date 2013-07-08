#include <iostream>
using namespace std;

int main()
{
	int userNumber = 20;

	const int* ptrNum = &userNumber;

	int* ptrSecond;
	ptrSecond = const_cast<int*>( ptrNum );

	return 0;
}

