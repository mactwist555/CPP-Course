#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int MAX = 3;
	string names[MAX];
	int total = 0;

	while (true) 
	{
		cout << endl << "NAMES:" << endl;
		for (int i = 0; i < total; i++)
		{
			cout << i << ". " << names[i] << endl;
		}
		cout << total << " out of " << MAX << endl;

		cout << endl << "OPTIONS:" << endl;
		cout << "1. Add, 2. Remove Top, 3. Quit" << endl;
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			// Add
			if (total < MAX)
			{
				cout << "Add name #" << total << ": ";
				cin >> names[total];
				total++;
			}
			else
			{
				cout << "Not enough space" << endl;
			}
		}
		else if (choice == 2)
		{
			// Remove
			if (total > 0)
			{
				names[total - 1] = "";
				total--;
			}
			else
			{
				cout << "List is empty" << endl;
			}
		}
		else
		{
			break;
		}
		cout << endl;
	}

	return 0;
}

