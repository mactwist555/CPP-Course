#include <iostream>
using namespace std;

int main()
{
	cout << endl << endl;
	int myVariable;
	cout << "Please enter a number: ";
	cin >> myVariable;

	int* myPointer = &myVariable;

	cout << "Your variable: " << myVariable << endl;
	cout << "Your pointer: " << myPointer << endl;

	cout << "Your pointer value: " << *myPointer << endl;

	return 0;
}
