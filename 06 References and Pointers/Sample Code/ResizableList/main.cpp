#include <iostream>
using namespace std;

#include "List.h"

int main()
{
	List list;

	cout << "output1" << endl;
	list.OutputAllElements();

	bool success;

	for ( int i = 0; i < 6; i++ )
	{
		success = list.Append( i * 3 );
	}

	cout << "output2" << endl;
	list.OutputAllElements();

	cout << "Remove index 3" << endl;
	list.Remove( 3 );
	list.OutputAllElements();

	cout << list.GetItemAtPosition( 3 ) << endl;

	return 0;
}
