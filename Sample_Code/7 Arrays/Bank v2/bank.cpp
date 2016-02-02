#include <iostream>
using namespace std;

int main()
{
    float balances[10]; // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

    for ( int i = 0; i < 10; i++ )
    {
        balances[i] = 0;
    }

    bool done = false;

    while ( !done )
    {
        int acct;
        cout << "What is your account number? ";
        cin >> acct;

        if ( acct == -1 )
        {
            for ( int i = 0; i < 10; i++ )
            {
                cout << "Balance for account #" << i << " = $" << balances[i] << endl;
            }
        }

        while ( acct < 0 || acct > 9 )
        {
            cout << "Invalid account number." << endl;
            cout << "What is your account number? ";
            cin >> acct;
        }

        cout << endl << "BANK" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Quit" << endl;
        cout << "Balance: $" << balances[acct] << endl;
        cout << ">> ";
        int choice;
        cin >> choice;

        if ( choice == 1 )
        {
            float amount;
            cout << "How much to deposit: ";
            cin >> amount;
            balances[acct] += amount;
        }
        else if ( choice == 2 )
        {
            float amount;
            cout << "How much to withdraw: ";
            cin >> amount;
            balances[acct] -= amount;
        }
        else
        {
            cout << "Goodbye" << endl;
        }

        cout << "Transaction done. Logging out" << endl << endl;
    }

    return 0;
}
