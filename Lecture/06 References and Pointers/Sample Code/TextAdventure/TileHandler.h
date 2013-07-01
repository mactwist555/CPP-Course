#ifndef _TH
#define _TH

#include "Tile.h"
#include "Item.h"
#include <iostream>
#include <fstream>
using namespace std;

class TileHandler
{
	public:
	~TileHandler()
	{
		delete [] lstTiles;
	}


	TileHandler()
	{
		ifstream infile( "maps.txt" );

		string buffer;
		int arraySize = 6;
		int currentIndex = 0;

		lstTiles = new Tile[arraySize];

		while ( !infile.eof() )
		{
			getline( infile, buffer, '\n' );
			cout << "Buffer: " << buffer << endl;

			string name, description;

			if ( buffer.find( "NAME" ) != string::npos )
			{
				cout << "Store name " << endl;
				getline( infile, name, '\n' );
			}
			else if ( buffer.find("DESCRIPTION") != string::npos )
			{
				getline( infile, description, '\n' );
			}
			else if ( buffer.find("END_MAP") != string::npos )
			{
				lstTiles[ currentIndex ].Setup( name, description );

				lstTiles[ currentIndex ].Output();

				cout << "Tile " << currentIndex << ": ";
				cout << "\t" << name << ", " << description << endl;

				currentIndex++;
			}
		}

		infile.close();
//
//		items[0].Setup( "food", &tiles[0] );
//		items[1].Setup( "grog", &tiles[3] );
//		items[2].Setup( "food", &tiles[4] );
//		items[3].Setup( "food", &tiles[6] );

		currentTile = &lstTiles[0];
	}

	void OutputCurrentMapInfo()
	{
		currentTile->Output();

		for ( int i = 0; i < 4; i++)
		{
			if ( items[i].GetParent() == currentTile &&
					items[i].IsOnMap() )
			{
				items[i].Output();
			}
		}
	}

	void Move( Direction dir )
	{
		Tile* neighbor = currentTile->GetNeighbor( dir );
		if ( neighbor == NULL )
		{
			cout << "You cannot move in that direction!" << endl;
		}
		else
		{
			currentTile = neighbor;
		}
	}

	Item* GetItem()
	{
		for ( int i = 0; i < 4; i++)
		{
			if ( items[i].GetParent() == currentTile )
			{
				return &items[i];
			}
		}
		return NULL;
	}

	private:
	Tile* lstTiles;
	Tile* currentTile;
	Item items[4];
};

#endif
