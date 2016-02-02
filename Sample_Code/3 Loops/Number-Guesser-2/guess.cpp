#include <iostream>
#include <stdlib.h> // rand()
#include <ctime> // time()
using namespace std;

int GetRandomNumber(int minimum, int maximum)
{
	int diff = maximum - minimum;
	return rand() % diff + minimum;
}

bool IsCorrectGuess(int randomNumber, int guess)
{
	if (guess > randomNumber)
	{
		cout << "Too high!" << endl;
		return false;
	}
	else if (guess < randomNumber)
	{
		cout << "Too low!" << endl;
		return false;
	}
	else
	{
		cout << "You got it!" << endl;
		return true;
	}
}

int main()
{
	srand(time(NULL)); // Seed the random number generator
	int randomNumber = GetRandomNumber(1, 10);

	cout << "GUESS THE NUMBER!" << endl;
	cout << "Between 0 and 9" << endl;

	for (int chances = 3; chances >= 0; chances--)
	{
		cout << endl;
		cout << "Chance " << chances << endl;

		cout << "Guess number: ";
		int guess;
		cin >> guess;

		if (IsCorrectGuess(randomNumber, guess))
		{
			break;
		}
	}

	return 0;
}
