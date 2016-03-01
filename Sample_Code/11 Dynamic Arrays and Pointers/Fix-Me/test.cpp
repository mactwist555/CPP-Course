#include <iostream>
#include <string>
using namespace std;

#include "Inventory.hpp"

int FirstFreeItem(Inventory* inventory[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (inventory[i] == NULL)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	Inventory* inventory[10];
	for (int i = 0; i < 10; i++)
	{
		inventory[i] = NULL;
	}

	while (true)
	{
		cout << "1. Add movie" << endl;
		cout << "2. Add food" << endl;
		cout << "3. Quit" << endl;
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			int index = FirstFreeItem(inventory);
			if (index != -1)
			{
				inventory[index] = new Movie("G", "Comedy", 9.99, 20, 1234, "Electronics", "MOVIE");
			}
		}
		else if (choice == 2)
		{
			int index = FirstFreeItem(inventory);
			if (index != -1)
			{
				inventory[index] = new Food("2017-01-01", true, "Vegetable", 1.22, 20, 1234, "Produce", "Asparagus");
			}
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (inventory[i] != NULL)
		{
			cout << endl << "Delete" << endl;
			delete inventory[i];
		}
	}

	return 0;
}
