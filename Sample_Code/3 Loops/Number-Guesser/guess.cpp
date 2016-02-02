#include <iostream>
#include <stdlib.h> // rand()
#include <ctime> // time()
using namespace std;

int main()
{
	srand(time(NULL)); // Seed the random number generator
	int randomNumber = rand() % 10;

	cout << "GUESS THE NUMBER!" << endl;
	cout << "Between 0 and 9" << endl;
	cout << "(it is " << randomNumber << ")" << endl;

	for (int chances = 3; chances >= 0; chances--)
	{
		cout << endl;
		cout << "Chance " << chances << endl;

		cout << "Guess number: ";
		int guess;
		cin >> guess;

		if (guess > randomNumber) 
		{ 
			cout << "Too high!" << endl; 
		}
		else if (guess < randomNumber)
		{
			cout << "Too low!" << endl;
		}
		else
		{
			cout << "You got it!" << endl;
			break;
		}
	}

	return 0;
}
