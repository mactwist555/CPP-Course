#include <iostream>
using namespace std;

#include "TileHandler.h"
#include "Inventory.h"

int main()
{
	TileHandler tileHandler;
	Inventory inventory;

	bool done = false;
	int move;

	while ( !done )
	{
		tileHandler.OutputCurrentMapInfo();

		inventory.Output();

		cout << NORTH << ". NORTH" << endl;
		cout << SOUTH << ". SOUTH" << endl;
		cout << EAST << ". EAST" << endl;
		cout << WEST << ". WEST" << endl;
		cout << "0. Pick up item" << endl;

		cout << "Go: ";
		cin >> move;

		if ( move == 0 )
		{
			Item* ptrItem = tileHandler.GetItem();
			cout <<  "GET ITEM: " << endl;
			ptrItem->Output();
			if ( ptrItem != NULL )
			{
				inventory.GetItem( ptrItem );
			}
		}
		else
		{
			tileHandler.Move( Direction( move ) );
		}
	}

	return 0;
}
