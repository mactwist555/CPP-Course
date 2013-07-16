#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Returns index of item
int BruteForceSearch( string listOfStates[], int size, const string& item );

void LoadStateList( string listOfStates[50] );

int main()
{
	string listOfStates[50];
	LoadStateList( listOfStates );

	string state;
	cout << "Enter a state name: ";
	cin >> state;

	int index = BruteForceSearch( listOfStates, 50, state );

	for ( int i = 0; i < 50; i++ )
	{
		if ( i == index )
		{
			cout << i << ": " << listOfStates[i] << " <--------- HERE" << endl;
		}
		else
		{
			cout << i << ": " << listOfStates[i] << endl;
		}
	}

	return 0;
}

void LoadStateList( string listOfStates[50] )
{
	ifstream infile( "States.txt" );

	int index = 0;
	string buffer;

	while ( infile >> listOfStates[ index++ ] ) { ; }

	infile.close();
}

int BruteForceSearch( string listOfStates[], int size, const string& item )
{
	for ( int i = 0; i < size; i++ )
	{
		if ( listOfStates[i] == item )
		{
			return i;
		}
	}
	return -1;
}



