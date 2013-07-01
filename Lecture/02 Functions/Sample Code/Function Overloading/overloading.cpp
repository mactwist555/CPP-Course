#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Print( string state );
void Print( string

int main()
{
	ofstream outfile;
	outfile.open( "file.txt" );



	outfile.close();

	return 0;
}
