#include <iostream>
#include <cstdlib>
using namespace std;

#include "Character.hpp"

void DrawSeparator( int length )
{
    cout << endl;
    for ( int i = 0; i < length; i++ )
    {
        cout << "-";
    }
    cout << endl;
}

void DisplayMenu( int round, int playerHP, int enemyHP )
{
    DrawSeparator( 30 );
    cout << endl;
    cout << "ROUND " << round << endl;
    cout << "Your HP: " << playerHP << "\tEnemy HP: " << enemyHP << endl << endl;
    cout << "0. Attack" << endl;
    cout << "1. Heal" << endl;
}

int main()
{
    Player player;
    player.Setup( "Player", 10, 10 );

    NPC npc;
    npc.Setup( "Enemy", 5, 5 );

    ICharacter* ptrPlayers[2];
    ptrPlayers[0] = &player;
    ptrPlayers[1] = &npc;

    int round = 1;

    while ( ptrPlayers[0]->GetHP() > 0 && ptrPlayers[1]->GetHP() > 0 )
    {
        DisplayMenu( round, ptrPlayers[0]->GetHP(), ptrPlayers[1]->GetHP() );

        for ( int i = 0; i < 2; i++ )
        {
            TurnChoice choice = ptrPlayers[i]->GetChoice();

            int otherPlayer;
            if ( i == 0 )   { otherPlayer = 1; }
            else            { otherPlayer = 0; }

            cout << endl;

            if ( choice == ATTACK )
            {
                int damage = ptrPlayers[i]->GetAttack();

                cout    << ptrPlayers[i]->GetName() << " attacks "
                        << ptrPlayers[ otherPlayer ]->GetName() << " for "
                        << damage << " damage!" << endl;

                ptrPlayers[ otherPlayer ]->SubtractDamage( damage );
            }
            else if ( choice == HEAL )
            {
                int health = ptrPlayers[i]->GetHealing();

                cout    << ptrPlayers[i]->GetName() << " heals themself for "
                        << health << " HP!" << endl;
            }
        }

        cout << endl;

        round++;
    }

    for ( int i = 0; i < 2; i++ )
    {
        if ( ptrPlayers[i]->GetHP() <= 0 )
        {
            cout << ptrPlayers[i]->GetName() << " has been defeated!" << endl;
        }
    }

    cout << endl << "GAME OVER" << endl;

    return 0;
}
