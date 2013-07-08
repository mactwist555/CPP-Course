#include <iostream>
using namespace std;

#include "Label.h"
#include "Unrelated.h"

int main()
{
	Label* 		introLabel = new Label( "Welcome!" );
	Label* 		startButton = new FancyLabel( "Start Program" );
	Unrelated*	unrelated = new Unrelated( "How are you" );

	FancyLabel* fancy;

	fancy = reinterpret_cast<FancyLabel*>( startButton );
	fancy = reinterpret_cast<FancyLabel*>( introLabel );
	fancy = reinterpret_cast<FancyLabel*>( unrelated );

	fancy->UniqueFunction();

	fancy->Output(); // Segfault

	delete introLabel;
	delete startButton;
	delete unrelated;

	return 0;
}
