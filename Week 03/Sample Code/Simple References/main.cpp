#include <iostream>
using namespace std;

int main()
{
	cout << endl << endl;
	int myVariable;
	cout << "Please enter a number: ";
	cin >> myVariable;

	int& myReference = myVariable;

	cout << "Your variable: " << myVariable << endl;
	cout << "Your reference: " << myReference << endl;

	cout << "Your variable address: " << &myVariable << endl;
	cout << "Your reference address: " << &myReference << endl;

	cout << endl << endl;
	return 0;
}
