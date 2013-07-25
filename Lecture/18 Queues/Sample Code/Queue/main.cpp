#include <iostream>
#include <string>
using namespace std;

#include "Queue.h"
#include "Stack.h"

int main()
{
	Queue<string> myStringQueue;

	myStringQueue.Push( "Hello" );
	myStringQueue.Push( "Saluton" );
	myStringQueue.Push( "Konnichiwa" );
	myStringQueue.Push( "Bonjour" );
	myStringQueue.Push( "Hola" );

	Stack<string> myStringStack;

	myStringStack.Push( "Hello" );
	myStringStack.Push( "Saluton" );
	myStringStack.Push( "Konnichiwa" );
	myStringStack.Push( "Bonjour" );
	myStringStack.Push( "Hola" );

	int count = 0;
	while ( myStringStack.GetSize() != 0 )
	{
		cout << "Loop " << count << endl;
		cout << "\t Stack: " << myStringStack.Top() << endl;
		cout << "\t Queue: " << myStringQueue.Front() << endl;
		cout << endl;
		count++;

		myStringStack.Pop();
		myStringQueue.Pop();
	}

	cout << "Press a key to continue..." << endl;
	cin.get();

	Queue<int> myIntQueue;

	myIntQueue.Push( 1 );
	myIntQueue.Push( 1 );
	myIntQueue.Push( 2 );
	myIntQueue.Push( 3 );
	myIntQueue.Push( 5 );

	Stack<int> myIntStack;

	myIntStack.Push( 1 );
	myIntStack.Push( 1 );
	myIntStack.Push( 2 );
	myIntStack.Push( 3 );
	myIntStack.Push( 5 );

	count = 0;
	while ( myIntStack.GetSize() != 0 )
	{
		cout << "Loop " << count << endl;
		cout << "\t Stack: " << myIntStack.Top() << endl;
		cout << "\t Queue: " << myIntQueue.Front() << endl;
		cout << endl;
		count++;

		myIntStack.Pop();
		myIntQueue.Pop();
	}

	cout << "Press a key to exit..." << endl;
	cin.get();

	return 0;
}
