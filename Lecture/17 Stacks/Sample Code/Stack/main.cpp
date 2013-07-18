#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"

int main()
{
	Stack<string> myStringStack;

	myStringStack.Push( "Hello" );
	myStringStack.Push( "Saluton" );
	myStringStack.Push( "Konnichiwa" );
	myStringStack.Push( "Bonjour" );
	myStringStack.Push( "Hola" );

	while ( myStringStack.GetSize() != 0 )
	{
		cout << myStringStack.Top() << endl;
		myStringStack.Pop();
	}

	Stack<int> myIntStack;

	myIntStack.Push( 1 );
	myIntStack.Push( 1 );
	myIntStack.Push( 2 );
	myIntStack.Push( 3 );
	myIntStack.Push( 5 );

	while ( myIntStack.GetSize() != 0 )
	{
		cout << myIntStack.Top() << endl;
		myIntStack.Pop();
	}


	return 0;
}
