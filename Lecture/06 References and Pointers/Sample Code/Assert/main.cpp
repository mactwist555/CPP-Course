#include <iostream>
#include <cassert>
using namespace std;

int main()
{
	int age;
	cout << "What is your age? ";
	cin >> age;

	assert( age >= 0 && age <= 150 );

	if ( age < 13 )
		cout << "You're a kid!" << endl;
	else if ( age < 20 )
		cout << "You're a teen!" << endl;
	else
		cout << "You're an adult!" << endl;

	return 0;
}
