#ifndef _ITEM
#define _ITEM

#include "Tile.h"

#include <string>
#include <iostream>
using namespace std;

class Item
{
	public:
	Item()
	{
		parent = NULL;
		isOnMap = true;
	}

	void Setup( const string& n, Tile* p )
	{
		name = n;
		parent = p;
	}

	void Output()
	{
		cout << name << endl;
	}

	Tile* GetParent()
	{
		return parent;
	}

	string GetName()
	{
		return name;
	}

	bool IsOnMap()
	{
		return isOnMap;
	}

	void SetIsOnMap( bool val )
	{
		isOnMap = val;
	}

	private:
	string name;
	Tile* parent;
	bool isOnMap;
};

#endif
