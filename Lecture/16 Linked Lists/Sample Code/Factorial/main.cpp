#include <iostream>
using namespace std;

int Factorial( int n )
{
	if ( n == 1 )
	{
		return n;
	}
	else
	{
		return Factorial( n-1 ) * n;
	}
}

int main()
{
	int fac = Factorial( 6 );
	cout << fac << endl;

	return 0;
}
