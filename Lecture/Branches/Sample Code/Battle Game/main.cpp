#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	// Seed the random number generator
	srand( 3 );
	
	bool playerDead = false;
	bool monsterDead = false;
	bool playerIsBlocking = false;
	
	int playerHP = 100;
	int monsterHP = 100;
	
	string choice;
	
	/* GAME LOOP - Game repeats until the Player or Monster die */
	while ( !playerDead && !monsterDead )
	{
		// Reset any commands from last time:
		playerIsBlocking = false;
		
		// Display the player menu
		cout << endl << endl;
		cout << "-----------------------------" << endl;
		cout << "Your HP: \t" << playerHP << endl;
		cout << "Monster HP: \t" << monsterHP << endl;
		cout << "-----------------------------" << endl;
		cout << "A. Attack" << endl;
		cout << "B. Block" << endl;
		cout << "H. Heal" << endl;
		
		// Ask the player for their choice
		cout << "What will you do?" << endl;
		cin >> choice;
		
		/* ATTACK */
		if ( choice == "a" || choice == "A" )
		{
			// Randomly generate attack damage
			int playerDamage = rand() % 11;
			cout << endl;
			cout << "You swing your sword!" << endl;
			cout << "You hit the monster for " << playerDamage << " damage!" << endl;
			
			// Remove damage from the monster's HP, check if it's dead
			monsterHP -= playerDamage;
			if ( monsterHP <= 0 )
			{
				cout << "You have slain the monster!" << endl;
				monsterDead = true;
			}
		}
		/* BLOCK */
		else if ( choice == "b" || choice == "B" )
		{
			cout << "You block!" << endl;
			playerIsBlocking = true;
		}
		/* HEAL */
		else if ( choice == "h" || choice == "H" )
		{
			cout << "You use a potion!" << endl;
			int healAmount = rand() % 5;
			cout << "You heal " << healAmount << " HP!" << endl;
			
			playerHP += healAmount;
			if ( playerHP > 100 )
			{
				playerHP = 100;
			}
		}
		
		/* MONSTER ATTACKS (if it's not dead) */
		if ( !monsterDead )
		{
			// Now monster attacks you!
			// Randomly generate attack damage
			int monsterDamage = rand() % 10;
			if ( playerIsBlocking )
			{
				monsterDamage = monsterDamage / 2;
			}
			
			cout << endl;
			cout << "The monster claws at you!" << endl;
			cout << "The monster does " << monsterDamage << " damage to you !" << endl;
			
			// Remove damage from player's HP, check if you're dead
			playerHP -= monsterDamage;			
			if ( playerHP <= 0 )
			{
				cout << "You have fallen!" << endl;
				playerDead = true;
			}
		}
	}
	
	if ( playerDead )
	{
		cout << "\n\nMan, who hired you to hunt monsters? You suck." << endl;
	}
	else if ( monsterDead )
	{
		cout << "\n\nYou killed the monster and are awarded with fifty mansions!" << endl;
	}
	
	return 0;
} 
