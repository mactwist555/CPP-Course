#include <iostream>
using namespace std;

#include "Label.h"

int main()
{
	Label* introLabel = new Label( "Welcome!" );
	Label* startButton = new FancyLabel( "Start Program" );

	FancyLabel* fancy;

	fancy = dynamic_cast<FancyLabel*>( introLabel );
	if ( fancy == NULL )		// TRUE
	{
		cerr << "fancy = dynamic_cast<FancyLabel*>( introLabel ); NULL" << endl;
	}
	// fancy->Output();	// Causes a Segfault

	fancy = dynamic_cast<FancyLabel*>( startButton );
	if ( fancy == NULL )		// FALSE
	{
		cerr << "fancy = dynamic_cast<FancyLabel*>( startButton ); NULL" << endl;
	}
	fancy->Output();	// OK

	delete introLabel;
	delete startButton;


	// Another example
	Label 		label1( "Label 1" );
	FancyLabel 	label2( "Label 2" );

	Label* 			ptrLabel;
	FancyLabel* 	ptrFancyLabel;

	ptrLabel = &label1;
	ptrFancyLabel = dynamic_cast<FancyLabel*>( ptrLabel );
	// ptrFancyLabel->Output();		// Segfault

	ptrLabel = &label2;
	ptrFancyLabel = dynamic_cast<FancyLabel*>( ptrLabel );
	ptrFancyLabel->Output();		// OK

	return 0;
}
