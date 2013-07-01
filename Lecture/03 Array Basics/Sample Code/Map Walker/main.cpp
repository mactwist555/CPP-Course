// Sample Code for CS 201 - Map Walker
// Rachel J. Morris, 2013
// License: WTFPL

#include <iostream>
#include <string>
using namespace std;

// Map Locations
//      N
//    0 1 2
// E  3 4 5  W
//    6 7 8
//      S

int main()
{
	string lstLocations[9];

	lstLocations[0] = "DESERT\nYou are standing in a desert. There are dry bones on the ground!";
	lstLocations[1] = "LAKE\nYou are wading through a shallow lake. It is kind of cold here.";
	lstLocations[2] = "FOREST\nYou are in the forest. There are many trees here.";
	lstLocations[3] = "MARS\nYou have wandered to Mars. You would be dead if you weren't a Waterbear!";
	lstLocations[4] = "GROCERY STORE\nYou are in line at a grocery store. The person in front of you is apparently buying dinner for an entire orphanage, because it's taking too damn long!";
	lstLocations[5] = "THRONE ROOM\nYou are in a castle in front of the king's throne. He looks kind of pissed for some reason.";
	lstLocations[6] = "CABIN\nYou are outside of a cabin. You need to think of a way to get in, but HOW?!";
	lstLocations[7] = "COFFEE SHOP\nYou are in a coffee shop. Unfortunately, it is not Christmas so they have no Peppermint Mocha Lattes.";
	lstLocations[8] = "BATHTUB\nYou are taking a bath. Good job!";

	int currentMap = 0;
	int mapWidth = 3, mapHeight = 3;

	bool done = false;
	string choice;

	while ( !done )
	{
		cout << "\n\n" << lstLocations[ currentMap ] << endl;
		cout << "What direction do you want to go? (North/South/East/West or Exit): ";
		cin >> choice;

		if ( choice == "North" || choice == "north" )
		{
			if ( currentMap - mapWidth < 0 )
			{
				cout << "You cannot move North!" << endl;
			}
			else
			{
				currentMap = currentMap - mapWidth;
			}
		}

		else if ( choice == "South" || choice == "south" )
		{
			if ( currentMap + mapWidth >= mapWidth * mapHeight )
			{
				cout << "You cannot move South!" << endl;
			}
			else
			{
				currentMap = currentMap + mapWidth;
			}
		}

		else if ( choice == "East" || choice == "east" )
		{
			if ( currentMap + 1 >= mapWidth * mapHeight || currentMap % mapWidth == 2 )
			{
				cout << "You cannot move East!" << endl;
			}
			else
			{
				currentMap += 1;
			}
		}

		else if ( choice == "West" || choice == "west" )
		{
			if ( currentMap - 1 < 0 || currentMap % mapWidth == 0 )
			{
				cout << "You cannot move West!" << endl;
			}
			else
			{
				currentMap -= 1;
			}
		}

		else if ( choice == "Exit" || choice == "exit" )
		{
			done = true;
			cout << "OK :(" << endl;
		}

		else
		{
			cout << "Invalid command" << endl;
		}
	}

	return 0;
}
