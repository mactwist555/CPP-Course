#include <iostream>
#include <string>
using namespace std;

#include "Character.h"

int main()
{
	Player player;
	Enemy enemy;

	Character* currentTurn;

	currentTurn = &player;
	currentTurn->DecideAction();

	currentTurn = &enemy;
	currentTurn->DecideAction();

	return 0;
}
