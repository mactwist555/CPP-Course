#include <iostream>
using namespace std;

int main()
{
	bool done = false;
	float balance = 0;

	while ( !done ) // done == false
	{
		cout << endl << "BANK PROGRAM" << endl;
		cout << "1. Deposit funds" << endl;
		cout << "2. Withdraw funds" << endl;
		cout << "3. Check balance" << endl;
		cout << "4. Exit" << endl;

		int choice;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "How much do you want to deposit? ";
			float amount;
			cin >> amount;

			if (amount <= 0)
			{
				// Invalid!
				cout << "You cannot deposit $0 or less!" << endl;
			}
			else
			{
				// Valid!
				balance += amount; // balance = balance + amount
			}

		}
		else if (choice == 2)
		{
			cout << "How much do you want to withdraw? ";
			float amount;
			cin >> amount;

			if (amount <= 0)
			{
				cout << "You cannot withdraw $0 or less!" << endl;
			}
			else if (amount > balance)
			{
				cout << "You cannot withdraw more than your balance!" << endl;
			}
			else
			{
				balance -= amount; // balance = balance - amount;
			}
		}
		else if (choice == 3)
		{
			cout << "Current balance: ";
			cout << "$" << balance << endl;
		}
		else if (choice == 4)
		{
			cout << "Are you SURE you want to quit? (y/n): ";
			char chooseQuit;
			cin >> chooseQuit;
			if (chooseQuit == 'y' || chooseQuit == 'Y') // && 
			{
				done = true;
			}
		}
	}

	return 0;
}
