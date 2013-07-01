#include <iostream>
using namespace std;

#include "Kitten.h"

int main()
{
	Kitten kitten1, kitten2;
	kitten2.Setup( "Allen", 2 );

	kitten1.Print();

	kitten1 = kitten2;

	kitten1.Print();

	return 0;
}
