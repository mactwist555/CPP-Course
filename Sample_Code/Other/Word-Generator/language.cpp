#include <iostream>
#include <string>
#include <cstdlib> // stdlib.h - rand()
#include <ctime>
#include <map>
using namespace std;

int GetRandomNumber(int minimum, int maximum)
{
	int diff = maximum - minimum;
	return rand() % diff + minimum;
}

string GenerateRandomWord(char vowels[], char consonants[], int vowelCount, int consonantCount, int wordLength)
{
	string word = "";
	for (int i = 0; i < wordLength; i++)
	{
		if (i % 2 == 0)
		{
			int randConsonant = GetRandomNumber(0, consonantCount);
			word += consonants[randConsonant];
		}
		else
		{
			int randVowel = GetRandomNumber(0, vowelCount);
			word += vowels[randVowel];
		}
	}
	return word;
}

int main()
{
	srand(time(NULL));

	char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	char consonants[] = { 'd', 'y', 'r', 's', 't', 'l', 'n' };

	map<string, string> words;

	// How are you today?
	words["how"] = GenerateRandomWord(vowels, consonants, 5, 7, GetRandomNumber(3, 10));
	words["are"] = GenerateRandomWord(vowels, consonants, 5, 7, GetRandomNumber(3, 10));
	words["you"] = GenerateRandomWord(vowels, consonants, 5, 7, GetRandomNumber(3, 10));
	words["today"] = GenerateRandomWord(vowels, consonants, 5, 7, GetRandomNumber(3, 10));

	cout << "How are you today?" << endl;
	cout << words["how"] << " "
		<< words["are"] << " "
		<< words["you"] << " "
		<< words["today"] << endl;

	while (true)
	{
		int length = GetRandomNumber(3, 10);
		string randomWord = GenerateRandomWord(vowels, consonants, 5, 7, length);
		cout << endl << endl << randomWord << endl;

		cout << "Another? (y/n): ";
		char choice;
		cin >> choice;
		if (choice == 'n')
		{
			break;
		}
	}

	return 0;
}
