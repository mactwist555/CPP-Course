#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct MenuItem
{
	string title;
	float price;
};

int main()
{
	ifstream inFile;
	inFile.open( "data.txt" );

	MenuItem menu[6];
	int menuSize = 0;

	string placeholderTitle;
	float placeholderPrice;
	while ( inFile >> placeholderTitle >> placeholderPrice )
	{
		menu[menuSize].title = placeholderTitle;
		menu[menuSize].price = placeholderPrice;
		menuSize++;
	}

	inFile.close();

	cout << "MENU: " << endl;
	for ( int i = 0; i < menuSize; i++ )
	{
		cout << i+1 << ". " << menu[i].title << "\t$" << menu[i].price << endl;
	}

	return 0;
}
