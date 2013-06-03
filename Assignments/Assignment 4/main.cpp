#include <iostream>
using namespace std;

#include "TextFile.h"
#include "HtmlFile.h"
#include "CsvFile.h"

int main()
{
	TextFile text;
	CsvFile csv;
	HtmlFile html;

	// Open files
	text.Open( "Restaurant.txt" );

	csv.Open( "Restaurant.csv" );

	html.Open( "Restaurant.html" );
	html.Initialize();

	// Write headers
	text.Write( "Bob's Restaurant", 1 );
	csv.Write( "Bob's Restaurant", 1 );
	html.Write( "Bob's Restaurant", 1 );

	text.Write( "Menu", 2 );
	csv.Write( "Menu", 2 );
	html.Write( "Menu", 2 );

	// Write table
	string menu[10][10];
	menu[0][0] = "Hamburger";
	menu[0][1] = "$5.99";

	menu[1][0] = "French fries";
	menu[1][1] = "$2.99";

	menu[2][0] = "Soft drink";
	menu[2][1] = "$1.99";

	menu[3][0] = "Chicken strips";
	menu[3][1] = "$4.99";

	menu[4][0] = "Milkshake";
	menu[4][1] = "$3.99";

	text.Write( menu, 5, 2 );
	csv.Write( menu, 5, 2 );
	html.Write( menu, 5, 2 );

	// Header
	text.Write( "History", 2 );
	csv.Write( "History", 2 );
	html.Write( "History", 2 );

	// Write list
	string events[5];
	events[0] = "In 1956 we opened our first restaurant!";
	events[1] = "In 1960 we expanded! One chain store per city in Kansas!";
	events[2] = "In 1970 we stopped serving cake";
	events[3] = "In 1985 we adopted our hair-metal mascot";
	events[4] = "In 1992 we changed our mascot to a grungey guy";

	text.Write( events, 5 );
	csv.Write( events, 5 );
	html.Write( events, 5 );

	// Close
	text.Close();

	csv.Close();

	html.Deinitialize();
	html.Close();

	return 0;
}
