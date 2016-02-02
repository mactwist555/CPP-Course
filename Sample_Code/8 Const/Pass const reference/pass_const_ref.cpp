#include <iostream>
#include <string>
#include <list>
using namespace std;

struct User
{
    string firstName, lastName;
    string city, state;
    int zipCode;
};

void UserFunction( const list<User> & lst );

void DisplayName( const string& first, const string& last );

int main()
{
    // List of Users
    list<User> userList;

    cout << "Create users" << endl;

    for ( int i = 0; i < 10000; i++ )
    {
        User u;
        u.firstName = u.lastName = "name";
        u.city = "Kansas City";
        u.state = "Missouri";
        u.zipCode = i;
        userList.push_back( u );
    }

    cout << "Done making users" << endl;

    UserFunction( userList );

    return 0;
}
