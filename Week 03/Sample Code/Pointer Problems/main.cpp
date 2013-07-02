#include <iostream>
#include <string>
using namespace std;

void Segfault();
void ChangeDatatypes();

int main()
{
	//SegFault();
	ChangeDatatypes();

	return 0;
}

void SegFault()
{
	// What about a NULL pointer?
	int* nullptr = NULL;
	cout << "Your pointer: " << nullptr << endl;
	cout << "Your pointer value: " << endl;
	cout << *nullptr << endl; // SEGFAULT HERE

	// What does an Uninitialized pointer show?
	int* uninit;
	cout << "Your pointer: " << uninit << endl;
	cout << "Your pointer value: " << endl;
	cout << *uninit << endl; // SEGFAULT HERE
}

void ChangeDatatypes()
{
	// This won't compile!
	string name = "Guybrush";

	//int* ptrName = &name;

	//cout << ptrName << endl;
	//cout << *ptrName << endl;
}
