#include <iostream>
#include <string>
using namespace std;

struct Vector
{
	float x;
	float y;
};

int main()
{
	Vector vectorU, vectorV;

	cout << "Enter Vector u's x y: ";
	cin >> vectorU.x >> vectorU.y;

	cout << "Enter Vector v's x y: ";
	cin >> vectorV.x >> vectorV.y;

	Vector sum;
	sum.x = vectorU.x + vectorV.x;
	sum.y = vectorU.y + vectorV.y;

	cout << "u + v = (" << sum.x << ", " << sum.y << ")" << endl;

	return 0;
}

