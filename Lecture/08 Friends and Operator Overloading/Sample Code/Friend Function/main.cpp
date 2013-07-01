#include <iostream>
using namespace std;

#include "Button.h"

int main()
{
	Button buttons[5];
	buttons[0].Setup( "New", 	15, 5 );
	buttons[1].Setup( "Save", 	15, 3 );
	buttons[2].Setup( "Save", 	15, 3 );
	buttons[3].Setup( "Undo", 	10, 5 );
	buttons[4].Setup( "Exit", 	12, 3 );

	for ( int i = 0; i < 5; i++ )
	{
		Draw( buttons[i] );
	}

	return 0;
}
