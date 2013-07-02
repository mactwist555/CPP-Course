#include <iostream>
#include <string>
using namespace std;

struct Vector
{
	int x, y;
};

int main()
{
	// Create Variables
	int number = 50;

	Vector vector;
	vector.x = 20;
	vector.y = 25;

	string name = "Guybrush Threepwood";

	// Create Pointers
	int* ptrToNumber 	= &number;
	Vector* ptrToVector = &vector;
	string* ptrToString = &name;

	cout << *ptrToNumber << endl;
	cout << (*ptrToVector).x << ", " << (*ptrToVector).y << endl;
	cout << *ptrToString << endl;

	return 0;
}
