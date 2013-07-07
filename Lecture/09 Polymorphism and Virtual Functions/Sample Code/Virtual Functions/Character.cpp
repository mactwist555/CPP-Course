#include "Character.h"

#include <stdlib.h>	// rand()

#include <iostream>
using namespace std;

int Character::DecideAction( string choices[3] )
{
	return 1;
}

int Player::DecideAction( string choices[3] )
{
	cout << "Choose an action: " << endl;
	for ( int i = 0; i < 3; i++ )
	{
		cout << i << ". " << choices[i] << endl;
	}

	int choice;
	cin >> choice;

	return choice;
}

int Enemy::DecideAction( string choices[3] )
{
	int choice = rand() % 3;
	return choice;
}
