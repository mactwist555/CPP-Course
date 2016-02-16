#include <iostream>
using namespace std;

class Room
{
    public:
    string name;
    string description;

    Room* north;
    Room* south;
    Room* east;
    Room* west;

    Room()
    {
        north = south = east = west = NULL;
    }

    void Setup( string n, string d )
    {
        name = n;
        description = d;
    }
};

void SetupRooms( Room rooms[3] );

int main()
{
    Room rooms[3];
    SetupRooms( rooms );

    Room* ptrCurrent = &rooms[0];

    while ( true )
    {
        cout << endl << ptrCurrent->name << endl;
        cout << ptrCurrent->description << endl;
        cout << "Room address: " << ptrCurrent << endl;

        cout << "You can go:";
        if ( ptrCurrent->north != NULL )   { cout << "\t North"; }
        if ( ptrCurrent->south != NULL )   { cout << "\t South"; }
        if ( ptrCurrent->east != NULL )    { cout << "\t East"; }
        if ( ptrCurrent->west != NULL )    { cout << "\t West"; }
        cout << endl;

        cout << "N, E, S, W?" << endl;
        char dir;
        cin >> dir;
        dir = tolower( dir );

        // Handle Movement
        if ( dir == 'n' && ptrCurrent->north != NULL )
        {
            ptrCurrent = ptrCurrent->north;
        }
        else if ( dir == 's' && ptrCurrent->south != NULL )
        {
            ptrCurrent = ptrCurrent->south;
        }
        else if ( dir == 'e' && ptrCurrent->east != NULL )
        {
            ptrCurrent = ptrCurrent->east;
        }
        else if ( dir == 'w' && ptrCurrent->west != NULL )
        {
            ptrCurrent = ptrCurrent->west;
        }
    }

    return 0;
}

void SetupRooms( Room rooms[3] )
{
    rooms[0].Setup( "Forest", "You are standing in a dark forest." );
    rooms[1].Setup( "Cottage", "You have entered a tiny cottage." );
    rooms[2].Setup( "Closet", "You are standing in a coat closet." );

    rooms[0].north = &rooms[1];
    rooms[1].south = &rooms[0];

    rooms[1].west = &rooms[2];
    rooms[2].east = &rooms[1];
}






