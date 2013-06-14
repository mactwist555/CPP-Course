#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream infile;
	infile.open( "message.txt" );

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
		message[i] = char(message[i] + 20);
	}

	cout << message << endl;

	ofstream outfile;
	outfile.open( "secret_message.txt" );

	outfile << message;

	outfile.close();

	return 0;
}
