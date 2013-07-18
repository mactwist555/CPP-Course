#include <iostream>
#include <string>
using namespace std;

#include "List.h"

int main()
{
	List<string> myList;

	string value = myList.GetItem( 2 );

	cout << value << endl;

	return 0;
}
