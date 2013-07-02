#include <iostream>
using namespace std;

#include "File.h"

int main()
{
	string filename;

	cout << "Enter a filename: ";
	cin >> filename;

	File programLog( filename );

	string message = "";
	while ( message.find( "quit" ) == string::npos )
	{
		cout << "Enter a message, or quit: ";
		getline( cin, message, '\n' );

		programLog.WriteLine( message );
	}

	return 0;
}
