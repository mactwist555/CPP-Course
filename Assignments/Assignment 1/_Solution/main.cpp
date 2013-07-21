/*
CS 201 Summer 2013 Assignment 1: Battle Game Part 1
Solution by Rachel J. Morris
*/

#include <iostream>
#include <string>
#include <stdlib.h>		// Needed for rand()
#include <time.h>		// Needed for time (seed rand generator)
#include <unistd.h>		// For delay()
using namespace std;

int main()
{
	cout << "BATTLE GAME" << endl;

	srand( time( NULL ) );
	int delayLength = 1;

	bool done = false;
	int round = 0;

	int playerHP = 20;
	int playerAtk = rand() % 3 + 5;
	int playerDef = rand() % 3 + 5;
	int playerAgi = rand() % 3 + 5;

	int enemyHP = 20;
	int enemyAtk = rand() % 2 + 5;
	int enemyDef = rand() % 2 + 5;
	int enemyAgi = rand() % 2 + 5;

	cout << endl;
	cout << "-------------" << endl;
	cout << "FIGHTER STATS" << endl;
	cout << "-------------" << endl;

	cout << endl << "PLAYER STATS: HP " << playerHP << ", ATK: " << playerAtk
		<< " DEF: " << playerDef << " AGI: " << playerAgi << endl;
	cout << "ENEMY STATS: HP " << enemyHP << ", ATK: " << enemyAtk
		<< " DEF: " << enemyDef << " AGI: " << enemyAgi << endl;

	cout << endl <<	 "Ready to begin? (yes/no) ";
	string answer;
	cin >> answer;
	while ( answer != "yes" )
	{
		cout << "Well, what are you waiting for?" << endl;
		cout << endl <<	 "Ready to begin? (yes/no) ";
		cin >> answer;
	}

	int playerChoice, enemyChoice;
	while ( !done )
	{
		round++;
		cout << endl;
		cout << "###########################################" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "ROUND " << round << endl;
		cout << "PLAYER: ";
		cout << "\t HP " << playerHP << " ATK " << playerAtk << " DEF " << playerDef << " AGI " << playerAgi << endl;
		cout << "ENEMY: ";
		cout << "\t\t HP " << enemyHP << " ATK " << enemyAtk << " DEF " << enemyDef << " AGI " << enemyAgi << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1. Quick Attack" << endl;
		cout << "2. Standard Attack" << endl;
		cout << "3. Heavy Attack" << endl;
		cout << "What will you do? ";
		cin >> playerChoice;
		cout << "-------------------------------------------" << endl;
		// Randomly choose enemy's choice
		enemyChoice = rand() % 3 + 1; // 1 to 3. Without the +1 it'd be 0 to 2.
		cout << "Enemy chooses option " << enemyChoice << "!" << endl;

		// Adjust stats based on type of attack!
		int adjustedPlayerAtk = playerAtk;
		int adjustedPlayerAgi = playerAgi;
		int adjustedEnemyAtk = enemyAtk;
		int adjustedEnemyAgi = enemyAgi;

		if ( playerChoice == 1 )
		{
			adjustedPlayerAgi += 2;
			adjustedPlayerAtk -= 1;
		}
		else if ( playerChoice == 3 )
		{
			adjustedPlayerAtk += 2;
			adjustedPlayerAgi -= 1;
		}

		if ( enemyChoice == 1 )
		{
			adjustedEnemyAgi += 2;
			adjustedEnemyAtk -= 1;
		}
		else if ( enemyChoice == 3 )
		{
			adjustedEnemyAtk += 2;
			adjustedEnemyAgi -= 1;
		}

		cout << "PLAYER attacks ENEMY!" << endl;
		int randDiff = ( rand() % adjustedPlayerAgi );
		sleep( delayLength );
		randDiff -= ( rand() % adjustedEnemyAgi );

		if ( randDiff >= 1 )
		{
			// Figure out damage
			int damage = adjustedPlayerAtk - enemyDef/2;
			cout << "PLAYER hits ENEMY for " << damage << " damage!" << endl;
			enemyHP -= damage;
		}
		else
		{
			cout << "PLAYER misses!" << endl;
		}
		sleep( delayLength );

		cout << endl;
		cout << "ENEMY attacks PLAYER!" << endl;
		randDiff = randDiff = ( rand() % adjustedEnemyAgi );
		sleep( delayLength );
		randDiff -= ( rand() % adjustedPlayerAgi );

		if ( randDiff >= 1 )
		{
			// Figure out damage
			int damage = adjustedEnemyAtk - playerDef/2;
			cout << "ENEMY hits PLAYER for " << damage << " damage!" << endl;
			playerHP -= damage;
		}
		else
		{
			cout << "ENEMY misses!" << endl;
		}
		sleep( delayLength );

		if ( playerHP <= 0 )
		{
			cout << "PLAYER has fallen!" << endl;
			done = true;
		}
		else if ( enemyHP <= 0 )
		{
			cout << "ENEMY has fallen!" << endl;
			done = true;
		}

	}

	cout << endl;
	cout << "    #####################################   " << endl;
	cout << " ####                                   ####" << endl;
	cout << "#           G A M E     O V E R             #" << endl;
	cout << "# ######################################### #" << endl;
	cout << "##                                         ##" << endl << endl;

	// player or enemy was defeated
	if ( playerHP <= 0 )
	{
		cout << "Too bad, you lose!" << endl;
	}
	else if ( enemyHP <= 0 )
	{
		cout << "Congratulations, you won!" << endl;
	}

	return 0;
}









