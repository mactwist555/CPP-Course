#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream infile;
	infile.open( "secret_message.txt" );

	string message;
	string buffer;

	while ( getline( infile, buffer ) )
	{
		message += buffer + "\n";
	}

	infile.close();

	cout << message << endl;

	for ( int i = 0; i < message.size(); i++ )
	{
		message[i] = char(message[i] - 20);
	}

	cout << "Message is:" << endl;
	cout << message << endl;

	return 0;
}
