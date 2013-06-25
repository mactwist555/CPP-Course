#include <string>
#include <iostream>
using namespace std;

#include <stdlib.h>     // Random numbers
#include <time.h>       // Time
#include <windows.h>    // Sleep()

int main()
{
    cout << "BATTLE GAME" << endl;

    bool done = false;

    int combatRound = 0;

    int playerHP = 20;
    int playerAtk = 5 + rand() % 3;
    int playerDef = 5 + rand() % 3;
    int playerAgi = 5 + rand() % 3;

    int enemyHP = 20;
    int enemyAtk = 5 + rand() % 2;
    int enemyDef = 5 + rand() % 2;
    int enemyAgi = 5 + rand() % 2;

    float delayLength = 200;

    /* DISPLAY STATS SCREEN */
    cout << endl;
    cout << "--------------" << endl;
    cout << "FIGHTER STATS" << endl;
    cout << "--------------" << endl;

    cout << endl;
    cout << "PLAYER: ";
    cout << "\t HP: " << playerHP;
    cout << "\t Atk: " << playerAtk;
    cout << "\t Def: " << playerDef;
    cout << "\t Agi: " << playerAgi;


    cout << endl;
    cout << "ENEMY: \t";
    cout << "\t HP: " << enemyHP;
    cout << "\t Atk: " << enemyAtk;
    cout << "\t Def: " << enemyDef;
    cout << "\t Agi: " << enemyAgi;

    cout << endl << "Are you ready to begin? (yes/no) ";
    string choice;
    cin >> choice;

    while ( choice != "yes" )
    {
        cout << "What are you waiting for?" << endl;
        cout << endl << "Are you ready to begin? (yes/no) ";
        cin >> choice;
    }

    cout << "BEGIN THE GAME!" << endl;

    /* MAIN GAME LOOP */
    while ( !done )
    {
        combatRound++;

        /* ATTACK MENU */
        cout << endl;
        cout << "###########################################" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "ROUND " << combatRound << endl;
        cout << "PLAYER:\t HP: " << playerHP;
        cout << "\t ATK: " << playerAtk;
        cout << "\t DEF: " << playerDef;
        cout << "\t AGI: " << playerAgi;

        cout << endl << endl;

        cout << "ENEMY:\t HP: " << enemyHP;
        cout << "\t ATK: " << enemyAtk;
        cout << "\t DEF: " << enemyDef;
        cout << "\t AGI: " << enemyAgi;

        cout << endl << endl;
        cout << "-------------------------------------------" << endl;
        cout << "1. Quick Attack" << endl;
        cout << "2. Standard Attack" << endl;
        cout << "3. Heavy Attack" << endl;

        // Player Input
        int playerChoice;
        cout << "What will you do? ";
        cin >> playerChoice;

        while ( playerChoice < 1 || playerChoice > 3 )
        {
            cout << "Invalid option!" << endl;
            cout << "What will you do? ";
            cin >> playerChoice;
        }

        // Enemy Input
        int enemyChoice = rand() % 3 + 1;

        cout << "Enemy choose option " << enemyChoice << endl;
        cout << "-------------------------------------------" << endl;

        /* STAT ADJUSTMENT */
        int adjustedPlayerAtk = playerAtk;
        int adjustedPlayerAgi = playerAgi;

        if ( playerChoice == 1 )
        {
            // Quick attack
            adjustedPlayerAgi += 2;
            adjustedPlayerAtk -= 1;
        }
        else if ( playerChoice == 3 )
        {
            // Heavy attack
            adjustedPlayerAtk += 2;
            adjustedPlayerAgi -= 1;
        }

        int adjustedEnemyAtk = enemyAtk;
        int adjustedEnemyAgi = enemyAgi;

        if ( enemyChoice == 1 )
        {
            // Quick attack
            adjustedEnemyAgi += 2;
            adjustedEnemyAtk -= 1;
        }
        else if ( enemyChoice == 3 )
        {
            // Heavy attack
            adjustedEnemyAtk += 2;
            adjustedEnemyAgi -= 1;
        }

        /* BATTLE OUTPUT */
        cout << "PLAYER attacks ENEMY!" << endl;
        Sleep( delayLength );

        int randDiff = rand() % adjustedPlayerAgi;

        if ( randDiff >= 1 )
        {
            int damage = int( adjustedPlayerAtk - enemyDef / 2 );
            cout << "PLAYER hits ENEMY for " << damage << " damage!" << endl;
            enemyHP -= damage;
        }
        else
        {
            cout << "PLAYER misses!" << endl;
        }
        Sleep( delayLength );

        cout << "ENEMY attacks PLAYER!" << endl;
        Sleep( delayLength );

        randDiff = rand() % adjustedPlayerAgi;

        if ( randDiff >= 1 )
        {
            int damage = int( adjustedEnemyAtk - playerDef / 2 );
            cout << "ENEMY hits PLAYER for " << damage << " damage!" << endl;
            playerHP -= damage;
        }
        else
        {
            cout << "ENEMY misses!" << endl;
        }
        Sleep( delayLength );

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

    } // while ( !done )

    cout << endl << endl;

    cout << "-------------------------------------------" << endl;
    cout << "GAME OVER" << endl;

    if ( playerHP <= 0 )
    {
        cout << "Too bad, you lost!" << endl;
    }
    else if ( enemyHP <= 0 )
    {
        cout << "Congratulations!" << endl;
    }

    return 0;
}





