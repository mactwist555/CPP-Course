#include <iostream>
using namespace std;

#include "Phonebook.h"

int main()
{
	Phonebook phonebook;
	phonebook.ReadFile( "numbers.txt" );

	return 0;
}
