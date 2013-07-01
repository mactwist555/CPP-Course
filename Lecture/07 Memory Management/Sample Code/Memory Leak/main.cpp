#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Very small memory leak
	for ( int i = 0; i < 20; i++ )
	{
		int* newList = new int[10];

		for ( int j = 0; j < 10; j++ )
		{
			newList[j] = i * 15 + j;
		}
	}

	return 0;
}
