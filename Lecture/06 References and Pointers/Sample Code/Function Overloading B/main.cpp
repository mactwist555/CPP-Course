#include <iostream>
using namespace std;

int Area( int& radius )
{
	float pi = 3.14159;
	return pi * radius * radius;
}

int Area( int width, int height )
{
	return width * height;
}

int main()
{
	cout << "circle or rectangle?" << endl;

	return 0;
}
