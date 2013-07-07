#include <iostream>
#include <string>
using namespace std;

#include "Webpage.h"

int main()
{
	cout << "Enter a filename: ";
	string filename;
	cin >> filename;
	filename += ".html";

	cout << "Choose a type of output: " << endl;
	cout << "1. Standard Webpage" << endl;
	cout << "2. Styled Webpage" << endl;

	int choice;
	cin >> choice;

	Webpage* webpage;

	if ( choice == 1 )
	{
		webpage = new BasicWebpage( filename );
	}
	else if ( choice == 2 )
	{
		webpage = new StyledWebpage( filename );
	}

	bool done = false;
	while ( !done )
	{
		cout << "Enter a line of text, or \"quit\" to quit:" << endl;

		string line;
		getline( cin, line, '\n' );

		size_t locationFound = line.find( "quit" );
		if ( locationFound != string::npos )
		{
			done = true;
		}
		else
		{
			webpage->WriteLine( line );
		}
	}

	delete webpage;

	return 0;
}
