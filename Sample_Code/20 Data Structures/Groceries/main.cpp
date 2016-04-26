#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct Customer
{
    string name;
    stack<string> cartItems;
};

void LoadCustomers( queue<Customer>& customers );

void ProcessCustomers( queue<Customer>& customers );

int main()
{
    queue<Customer> customers;

    LoadCustomers( customers );
    ProcessCustomers( customers );

    return 0;
}

void ProcessCustomers( queue<Customer>& customers )
{
    int count = 0;
    while ( !customers.empty() )
    {
        cout << "CUSTOMER #" << (count+1) << endl;
        cout << "\t" << customers.front().name << endl;

        int items = 0;
        while ( !customers.front().cartItems.empty() )
        {
            cout << "\t\t" << (items+1) << " " << customers.front().cartItems.top() << endl;
            customers.front().cartItems.pop();
        }

        customers.pop();
        count++;
    }
}

void LoadCustomers( queue<Customer>& customers )
{
    ifstream input( "grocery.txt" );
    string buffer;

    while ( getline( input, buffer ) )  // Customer 0
    {
        Customer c;
        getline( input, c.name ); // name
        getline( input, buffer ); // CART
        int cartSize;
        input >> cartSize;
        input.ignore();

        for ( int i = 0; i < cartSize; i++ )
        {
            getline( input, buffer );
            c.cartItems.push( buffer );
        }

        customers.push( c );
        getline( input, buffer ); // empty line
    }

    input.close();
}
