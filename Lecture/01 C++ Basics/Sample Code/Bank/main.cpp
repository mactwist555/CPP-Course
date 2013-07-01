// Sample Code for CS 201 - Bank
// Rachel J. Morris, 2013
// License: WTFPL

#include <iostream>
using namespace std;

int main()
{
	bool done = false;
	int transactions = 0;
	float balance = 0.0;

	int choice;

	while ( !done )
	{
		cout << endl << endl << endl;
		cout << "-------------------------------------" << endl;
		cout << "Your current balance is $" << balance << endl;
		cout << "You have made " << transactions << " transactions" << endl << endl;
		cout << "1. Deposit money" << endl;
		cout << "2. Withdraw money" << endl;
		cout << "3. Leave" << endl;

		cout << "What do you want to do? ";
		cin >> choice;

		if ( choice == 1 )
		{
			cout << "How much do you want to deposit? ";
			float amount;
			cin >> amount;
			balance += amount;
			transactions++;
		}

		else if ( choice == 2 )
		{
			cout << "How much do you want to withdraw? ";
			float amount;
			cin >> amount;

			if ( balance - amount < 0 )
			{
				cout << "You cannot withdraw that amount; you would end up with less than $0!" << endl;
			}
			else
			{
				balance -= amount;
				cout << "$" << amount << " withdrawn. New balance is $" << balance << endl;
				transactions++;
			}
		}

		else if ( choice == 3 )
		{
			done = true;
			cout << "Thank you for using ATM" << endl;
		}

		else
		{
			cout << "Invalid option, try again" << endl;
		}
	}

	return 0;
}
