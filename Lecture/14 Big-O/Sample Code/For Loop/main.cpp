#include <iostream>
#include <string>
using namespace std;

// O(1)
void OutputData( const string& data )
{
	cout << data << endl;
}

// O(n)
int ForLoop( int begin, int end )
{
	int sum = 0;
	for ( int i = begin; i < end; i++ )
	{
		sum += i;
		cout << sum << endl;
	}
	return sum;
}

// O(n)
int ForLoops( int begin, int end )
{
	int sum = 0;
	for ( int i = begin; i < end; i++ )
	{
		sum += i;
		cout << sum << endl;
	}
	for ( int i = begin; i < end; i++ )
	{
		sum += i;
		cout << sum << endl;
	}
	return sum;
}

// O(n^2)
int TwoForLoops( int begin, int end )
{
	int sum = 0;
	for ( int i = begin; i < end; i++ )
	{
		for ( int j = begin; j < end; j++ )
		{
			sum += i*j;
			cout << sum << endl;
		}
	}
	return sum;
}

int main()
{
	int result = TwoForLoops( 0, 10 );

	cout << result << endl;

	return 0;
}

