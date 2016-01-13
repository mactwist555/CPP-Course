#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
	// -- VECTOR
	vector<string> studentNames;
	
	studentNames.push_back( "Kourtney" );
	studentNames.push_back( "Frank" );
	studentNames.push_back( "Patel" );
	studentNames.push_back( "Hana" );
	
	int i = 3;
	studentNames.erase( studentNames.begin() + i );
	
	for ( int i = 0; i < studentNames.size(); i++ )
	{
		cout << studentNames[i] << endl;
	}
	
	cout << endl;
	
	// -- MAP
	map<string, int> gradeLookup;
	
	gradeLookup.insert( pair<string, int>( "Elizabeth", 100 ) );
	gradeLookup.insert( pair<string, int>( "Anne", 75 ) );
	gradeLookup.insert( pair<string, int>( "Aki", 86 ) );
	
	// This is how you do a for-each loop in C++98
	// and it is very ugly.
	for ( map<string, int>::iterator iter = gradeLookup.begin();
		iter != gradeLookup.end();	
		iter++ )
	{
		cout << "Name: " << (*iter).first << "\t Grade: " << (*iter).second << endl;
	}
	
	return 0;
} 
