#include <iostream>
#include <cassert>
using namespace std;

#include "File.h"

int main()
{
	string filename;
	cout << "Filename: ";
	filename = "";

	assert( filename != "" );

	File programLog( filename );

	string message = "";
	while ( message.find( "quit" ) == string::npos )
	{
		File::WriteLine( "Enter a message: " );
		getline( cin, message, '\n' );

		File::WriteLine( message );
	}

	File::WriteLine( "Goodbye!" );

	return 0;
}
