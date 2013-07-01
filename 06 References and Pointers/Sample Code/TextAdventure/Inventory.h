#ifndef _INVENTORY
#define _INVENTORY

#include "Item.h"

class Inventory
{
	public:
	Inventory()
	{
		inventorySize = 0;
		for ( int i = 0; i < 4; i++ )
		{
			items[i] = NULL;
		}
	}

	void GetItem( Item* item )
	{
		items[ inventorySize ] = item;
		items[ inventorySize ]->SetIsOnMap( false );

		inventorySize++;
	}

	void Output()
	{
		cout << "INVENTORY" << endl;
		for ( int i = 0; i < 4; i++ )
		{
			if ( items[i] != NULL )
			{
				items[i]->Output();
			}
		}
	}

	private:
	Item* items[4];
	int inventorySize;
};

#endif
