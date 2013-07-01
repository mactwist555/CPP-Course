#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Generally, you would use a nice library to output
// code for you - generating it manually like this is a waste of time!
void OutputWebpageTop( ofstream& outfile )
{
	outfile << "<html><head><title>Sample Webpage</title>" << endl;
	outfile << "<style type='text/css'>" << endl;
	outfile << "body { background: #92eeff; font-family: 'Arial'; }" << endl;
	outfile << "h1 { text-align: center; }" << endl;
	outfile << "table { border: solid 1px #000000; width: 50%; margin: 0 auto; }" << endl;
	outfile << "table td { border: solid 1px #434dd4; }" << endl;
	outfile << "</style></head><body>" << endl;
	outfile << "<h1>MENU</h1>" << endl;
	outfile << "<table><tr><td>ITEM</td><td>PRICE</td></tr>" << endl;
}

void OutputWebpageBottom( ofstream& outfile )
{
	outfile << "</table></body></html>" << endl;
}

void OutputMenuItem( ofstream& outfile, string name, float price )
{
	outfile << "<tr><td>";
	outfile << name;
	outfile << "</td><td>";
	outfile << "$" << price;
	outfile << "</td></tr>" << endl;
}

int main()
{
	bool done = false;

	ofstream outfile;
	outfile.open( "Menu.html" );

	OutputWebpageTop( outfile );

	while ( !done )
	{
		cout << endl;
		string name;
		float price;

		cout << "Enter food item name or QUIT to quit: ";
		cin >> name;

		if ( name == "quit" || name == "QUIT" )
		{
			done = true;
		}
		else
		{
			cout << "Menu item price: $";
			cin >> price;

			OutputMenuItem( outfile, name, price );
		}
	}

	OutputWebpageBottom( outfile );

	outfile.close();

	return 0;
}
