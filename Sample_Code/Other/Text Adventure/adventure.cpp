// ADVENTURE

#include <iostream>
#include <string>
using namespace std;

#include "Room.hpp"

void LoadRooms( Room rooms[9] );

int main()
{
    bool done = false;

    string directions[4];
    directions[0] = "NORTH";
    directions[1] = "SOUTH";
    directions[2] = "EAST";
    directions[3] = "WEST";

    Room rooms[9];
    LoadRooms( rooms );
    int currentRoom = 0;

    string lastMessage = "";

    while ( !done )
    {
        system( "clear" );

        rooms[ currentRoom ].Display();
        for ( int i = 0; i < 4; i++ )
        {
            int neighborIndex = rooms[ currentRoom ].GetNeighbor( Direction( i ) );
            if ( neighborIndex != -1 )
            {
                cout << "To the " << directions[i] << " is " << rooms[ neighborIndex ].GetName() << endl;
            }
        }

        cout << endl;
        cout << "OPTIONS" << endl;
        cout << "W. NORTH" << endl;
        cout << "S. SOUTH" << endl;
        cout << "A. WEST" << endl;
        cout << "D. EAST" << endl;
        char choice;
        cout << endl << "What will you do? ";
        cin >> choice;
        choice = tolower( choice );

        while ( choice != 'w' && choice != 'a' && choice != 's' && choice != 'd' )
        {
            cout << "Invalid option. Try again." << endl;
            cout << endl << "What will you do? ";
            cin >> choice;
        }

        int dir;
        if      ( choice == 'w' ) { dir = 0; }
        else if ( choice == 's' ) { dir = 1; }
        else if ( choice == 'd' ) { dir = 2; }
        else if ( choice == 'a' ) { dir = 3; }

        int neighborIndex = rooms[ currentRoom ].GetNeighbor( Direction( dir ) );
        if ( neighborIndex != -1 )
        {
            currentRoom = neighborIndex;
        }
    }
}

// 8
// 5 6 7
//     4
// 0 1 2 3

void LoadRooms( Room rooms[9] )
{
    rooms[0].Setup( "Arbara Forest Entrance", "You are standing at the entrance to a dense forest." );
    rooms[0].SetNeighbor( EAST, 1 );

    rooms[1].Setup( "Arbara Forest Passage", "The trees on either side of you form an impassable wall." );
    rooms[1].SetNeighbor( WEST, 0 );
    rooms[1].SetNeighbor( EAST, 2 );

    rooms[2].Setup( "Arbara Forest Fork", "The forest forks in three directions here." );
    rooms[2].SetNeighbor( WEST, 1 );
    rooms[2].SetNeighbor( EAST, 3 );
    rooms[2].SetNeighbor( NORTH, 4 );

    rooms[3].Setup( "Arbara Forest Dead End", "A cliff wall blocks the way forward here." );
    rooms[3].SetNeighbor( WEST, 2 );

    rooms[4].Setup( "Largha River", "You are crossing a bridge across a river" );
    rooms[4].SetNeighbor( NORTH, 7 );
    rooms[4].SetNeighbor( SOUTH, 2 );

    rooms[7].Setup( "Malplena Grassland, Riverside east", "You are standing in a grassy clearing." );
    rooms[7].SetNeighbor( SOUTH, 4 );
    rooms[7].SetNeighbor( WEST, 6 );

    rooms[6].Setup( "Malplena Grassland, Riverside central", "The stream flows to one side, the grassland expands to the other." );
    rooms[6].SetNeighbor( EAST, 7 );
    rooms[6].SetNeighbor( WEST, 5 );

    rooms[5].Setup( "Malplena Grassland, Riverside west", "You see a cave here." );
    rooms[5].SetNeighbor( EAST, 6 );
    rooms[5].SetNeighbor( NORTH, 8 );

    rooms[8].Setup( "Malluma Cavern", "You've found a dark cave." );
    rooms[8].SetNeighbor( SOUTH, 5 );
}




