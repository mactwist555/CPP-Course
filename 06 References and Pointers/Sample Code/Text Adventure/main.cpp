#include <iostream>
using namespace std;

#include "Tile.h"

//	0	1	2
// 	3	4	5

int main()
{
	Tile tiles[6];

	tiles[0].Setup( "North-West Corner", 	"There is a house here" );
	tiles[1].Setup( "North Corner", 		"This is a forest" );
	tiles[2].Setup( "North-East Corner", 	"This is a desert" );
	tiles[3].Setup( "South-West Corner", 	"There is a cave" );
	tiles[4].Setup( "South Corner", 		"There is a lake" );
	tiles[5].Setup( "South-East Corner", 	"This is a field of flowers" );

	tiles[0].SetNeighbor( SOUTH, &tiles[3] );
	tiles[1].SetNeighbor( SOUTH, &tiles[4] );
	tiles[2].SetNeighbor( SOUTH, &tiles[5] );

	tiles[3].SetNeighbor( NORTH, &tiles[0] );
	tiles[4].SetNeighbor( NORTH, &tiles[1] );
	tiles[5].SetNeighbor( NORTH, &tiles[2] );

	tiles[0].SetNeighbor( EAST, &tiles[1] );
	tiles[1].SetNeighbor( EAST, &tiles[2] );
	tiles[3].SetNeighbor( EAST, &tiles[4] );
	tiles[4].SetNeighbor( EAST, &tiles[5] );

	tiles[2].SetNeighbor( WEST, &tiles[1] );
	tiles[1].SetNeighbor( WEST, &tiles[0] );
	tiles[5].SetNeighbor( WEST, &tiles[4] );
	tiles[4].SetNeighbor( WEST, &tiles[3] );

	Tile* currentTile = &tiles[0];

	bool done = false;
	int move;
	while ( !done )
	{
		currentTile->Output();

		cout << "0. NORTH \t 1. SOUTH \t 2. EAST \t 3. WEST" << endl;
		cout << "Go which direction? ";
		cin >> move;

		Tile* neighbor = currentTile->GetNeighbor( Direction( move ) );
		if ( neighbor == NULL )
		{
			cout << "Cannot move that direction!" << endl;
		}
		else
		{
			currentTile = neighbor;
		}
	}

	return 0;
}
