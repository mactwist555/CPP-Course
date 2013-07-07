#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int StringToInt( string strNum )
{
	istringstream stringStream( strNum );

	int intNum;
	stringStream >> intNum;
	return intNum;
}

string IntToString( int intNum )
{
	stringstream stringStream;
	stringStream << intNum;
	return stringStream.str();
}

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;

	string convertedNumber = IntToString( number );
	cout << "As a string: " << convertedNumber << endl;

	string str;
	cout << "Enter another number: ";
	cin >> str;

	int convertedStr = StringToInt( str );
	cout << "As an integer: " << convertedStr << endl;

	return 0;
}

