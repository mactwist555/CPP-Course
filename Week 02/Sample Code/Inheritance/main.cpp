#include <iostream>
using namespace std;

#include "Cat.h"

int main()
{
	Animal animal;
	Cat cat;

	cout << endl;
	cout << animal.GetName() << ":\n";
	cout << "Speak: ";
	animal.Speak();
	cout << "Danger: ";
	animal.ReactToDanger();

	cout << endl;
	cout << cat.GetName() << ":\n";
	cout << "Speak: ";
	cat.Speak();
	cout << "Danger: ";
	cat.ReactToDanger();

	return 0;
}
