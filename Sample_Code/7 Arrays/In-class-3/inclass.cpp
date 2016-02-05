#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void ex1();
void ex2();
void ex3();

int main()
{
	ex3();
	return 0;
}

int GetRandom(int minimum, int maximum)
{
	int diff = maximum - minimum;
	return rand() % diff + minimum;
}

void RandomWord(string& word, int length)
{
	char vowels[] = { 'A', 'E', 'I', 'O', 'U' };
	char consonants[] = { 'P', 'B', 'D' };
	word = "";
	for (int i = 0; i < length; i++)
	{
		if (i % 2 == 0)
		{
			char letter = vowels[GetRandom(0, 5)];
			word += letter;
		}
		else
		{
			char letter = consonants[GetRandom(0,2)];
			word += letter;
		}

	}
}

void ex3()
{
	char another = 'y';
	do
	{
		string randWord;
		RandomWord(randWord, GetRandom(3,6));
		cout << "\n  Word: " << randWord << endl;

		cout << "Another? ";
		cin >> another;
	} while (another == 'y');
}

char BinaryToText(const bool binary[8])
{
	int sum = 0;
	int max = 128;
	for (int i = 0; i < 8; i++)
	{
		if (binary[i] == 1)
		{
			sum += max;
		}

		max = max / 2;
	}

	return char(sum);
}

void TextToBinary(char letter, bool binary[8])
{
	int ascii = int(letter);
	int max = 128;
	for (int i = 0; i < 8; i++)
	{
		if (ascii - max >= 0)
		{
			binary[i] = 1;
			ascii -= max;
		}
		else
		{
			binary[i] = 0;
		}
		max = max / 2;
	}
}

void ex2()
{
	bool binary1[8] = { 0, 1, 0, 0, 0, 0, 0, 1 }; // 'A'
	bool binary2[8] = { 0, 1, 0, 0, 0, 0, 1, 1 };
	bool binary3[8] = { 0, 1, 0, 0, 0, 1, 1, 1 };

	cout << BinaryToText(binary1);
	cout << BinaryToText(binary2);
	cout << BinaryToText(binary3) << endl;


	cout << "Enter a letter: ";
	char a;
	cin >> a;

	bool binary4[8];
	TextToBinary(a, binary4);

	for (int i = 0; i < 8; i++)
	{
		cout << binary4[i] << " ";
	}
}


bool IsEqual(const char wordA[], const char wordB[], int length)
{
	// Compare each letter of both words.
	for (int i = 0; i < length; i++)
	{
		if (wordA[i] != wordB[i])
		{
			return false;
		}
	}
	return true;
}

void ex1()
{
	char word1[] = { 'c', 'a', 't', '\0' };
	char word2[] = { 'c', 'a', 't', '\0' };
	char word3[] = { 'r', 'a', 't', '\0' };
	char word4[] = { 'r', 'a', 't', 'e', '\0' };

	cout << word1 << " & " << word2 << ": " << IsEqual(word1, word2, 4) << endl;
	cout << word1 << " & " << word3 << ": " << IsEqual(word1, word3, 4) << endl;
	cout << word3 << " & " << word4 << ": " << IsEqual(word3, word4, 4) << endl;
}

