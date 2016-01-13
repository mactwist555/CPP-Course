/*
 * Python vs. C++ Example5
 * Rachel J. Morris, 2013 - RachelJMorris@gmail.com, Moosader.com, github.com/Moosader
 * MIT License
*/

#include <iostream>
#include <string>
using namespace std;

int SumTwoNumbers( int num1, int num2 )
{
	return num1 + num2;
}

float SumTwoNumbers( float num1, float num2 )
{
	return num1 + num2;
}

bool IsButtonClicked( int mouseX, int mouseY, int buttonX, int buttonY, int buttonWidth, int buttonHeight )
{
	if ( 	buttonX <= mouseX && mouseX <= buttonX + buttonWidth &&
			buttonY <= mouseY && mouseY <= buttonY + buttonHeight )
	{
		return true;
	}

	return false;
}

bool IsValidUsername( string username )
{
	// This will automatically return true or false based on the conditional
	// There is no need to put an if/else statement with return true or false inside.
	return ( username == "rachel" );
}

void GetValidMessage( bool isValid, string attemptedName )
{
	if ( isValid )
	{
		cout << attemptedName << " is the correct username" << endl;
	}
	else
	{
		cout << attemptedName << " is an invalid username" << endl;
	}
}

int main()
{
	// Function 1: Sum
	cout << SumTwoNumbers( 1, 2 ) << endl;
	cout << SumTwoNumbers( 1.5f, 2.3f ) << endl;

	return 0;
}



