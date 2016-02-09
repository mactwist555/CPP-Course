#include <iostream>
#include <string>
#include <cstdlib> // stdlib.h - rand()
#include <ctime>
#include <map>
#include <fstream>
using namespace std;

int GetRandomNumber(int minimum, int maximum)
{
	int diff = maximum - minimum;
	return rand() % diff + minimum;
}

string ToLower( const string& text )
{
    string lower = "";
    for ( int i = 0; i < text.size(); i++ )
    {
        lower += tolower( text[i] );
    }
    return lower;
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
    ofstream output( "Dictionary.txt" );
    output << "ENGLISH, GENERATED" << endl;
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
        cout << endl;
        cout << "Enter a word to generate a translation for: ";
        string word;
        cin >> word;
        if ( word == "QUIT" ) { break; }

        word = ToLower( word );

        if ( words.find(word) == words.end() )
        {
            // Generate new
            int length = GetRandomNumber(3, 10);
            string randomWord = GenerateRandomWord(vowels, consonants, 5, 7, length);

            words[word] = randomWord;
            cout << word << " = " << randomWord << endl;
        }
        else
        {
            // Already exists
            cout << word << " = " << words[word] << endl;
        }
	}

	for ( map<string,string>::iterator it = words.begin(); it != words.end(); it++ )
	{
        output << it->first << ", " << it->second << endl;
	}

	output.close();

	return 0;
}
