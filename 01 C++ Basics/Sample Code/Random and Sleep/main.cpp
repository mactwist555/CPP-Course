#include <stdlib.h>		// Random numbers
#include <time.h>		// Time

#include <unistd.h>		// Delay
// #include <windows.h> for Windows machines

#include <iostream>
using namespace std;

int main()
{
	srand( time( NULL ) );

	while ( true )
	{
		// number = random.randint( 0, 10 )
		int randomNumber = rand() % 5 + 10;
		cout << randomNumber << endl;
		sleep( 1 );
	}

	return 0;
}
