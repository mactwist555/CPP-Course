#include <iostream>		// i/o stream
#include <fstream>		// file stream
#include <string>
using namespace std;

int GetUserInput(int minimum, int maximum)
{
	int choice;
	cin >> choice;

	while (choice < minimum || choice > maximum)
	{
		cout << "Invalid choice. Try again: ";
		cin >> choice;
	}
	return choice;
}

void ShowMenu()
{
	cout << "-------------------" << endl;
	cout << "1. Add to list" << endl;
	cout << "2. Save and quit" << endl;
}

void AddItem(ofstream & outputFile, int number)
{
	string item;
	cout << "What do you want to do? ";
	cin.ignore();
	getline(cin, item); // Get a line of text

	outputFile << number << ". " << item << endl;
}

int main()
{
	ofstream outputFile;
	outputFile.open("todo.txt"); 

	bool done = false;
	int number = 1;

	while (!done)
	{
		ShowMenu();
		int choice = GetUserInput(1, 2);
		if (choice == 1)
		{
			AddItem(outputFile, number);
			number++;
		}
		else
		{
			done = true;
		}
	}

	outputFile.close();

	return 0;
}
