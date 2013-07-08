#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main()
{
	int myInt = 20;
	float myFloat = 19.99;
	string myString = "Hello!";
	char myChar = 'A';

	int* ptrInt = &myInt;
	int& refInt = myInt;

	cout << typeid( myInt ).name() << endl;
	cout << typeid( myFloat ).name() << endl;
	cout << typeid( myString ).name() << endl;
	cout << typeid( myChar ).name() << endl;
	cout << typeid( ptrInt ).name() << endl;
	cout << typeid( refInt ).name() << endl;

	return 0;
}

