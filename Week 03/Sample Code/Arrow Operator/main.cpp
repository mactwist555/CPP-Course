#include <iostream>
#include <string>
using namespace std;

class Vector
{
	public:
	int x, y;

	void SetX( int x )
	{
		Vector::x = x;
		this->x = x;
	}
};

int main()
{
	Vector vectorU;
	vectorU.x = 20;
	vectorU.y = 40;

	Vector* ptrVec = &vectorU;

	cout << ptrVec->x << endl;
	cout << ptrVec->y << endl;

	ptrVec->SetX( 400 );

	cout << ptrVec->x << endl;

	int number = 100;

	// Cannot change value of variable being pointed to
	const int* ptrNumber;
	ptrNumber = &number;
	*ptrNumber = 300;

	int* ptrNumber2;
	ptrNumber2 = &number;
	*ptrNumber2 = 300;

	return 0;
}
