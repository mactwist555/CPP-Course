#include <iostream>
#include <string>
using namespace std;

#include "List.h"

int main()
{
	List myList;

	myList.Push( "Good Morning!" );
	myList.Push( "Ohayou Gozaimasu!" );
	myList.Push( "Bonan Matenon!" );
	myList.Push( "Goedemorgen!" );
	myList.Push( "Guten Morgen!" );

	string value = myList.GetItem( 1 );
	cout << value << endl;

	myList.Pop();

	value = myList.GetItem( 3 );
	cout << value << endl;

	return 0;
}
