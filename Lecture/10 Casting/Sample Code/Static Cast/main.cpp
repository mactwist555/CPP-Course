#include <iostream>
using namespace std;

#include "Label.h"

int main()
{
	Label* introLabel = new Label( "Welcome!" );
	Label* startButton = new FancyLabel( "Start Program" );

	FancyLabel* fancy;

	fancy = static_cast<FancyLabel*>( introLabel );
	fancy->Output();
	fancy->UniqueFunction();

	fancy = static_cast<FancyLabel*>( startButton );
	fancy->Output();
	fancy->UniqueFunction();

	delete introLabel;
	delete startButton;

	return 0;
}
