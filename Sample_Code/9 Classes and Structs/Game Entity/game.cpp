#include <iostream>
#include <string>
using namespace std;

class Player
{
    public:
    void Setup( const string& name, int hp )
    {
        this->name = name;
        this->hp = hp;
    }

    bool IsAlive()
    {
        return ( hp > 0 );
    }

    int GetHP()
    {
        return hp;
    }

    string GetName()
    {
        return name;
    }

    void SetAttackAndDefense( int attack, int defense )
    {
        this->attack = attack;
        this->defense = defense;
    }

    int GetAttack()
    {
        return attack;
    }

    void TakeDamage( int amount )
    {
        float damage = amount - defense;
        cout << name << " hit for " << damage << " of damage!" << endl;
        hp -= damage;
    }

    private:
    string name;
    int hp;
    int attack;
    int defense;
};

int ChooseAction()
{
    int choice;
    cout << "1. offensive attack" << endl;
    cout << "2. defensive attack" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    Player players[2];
    players[0].Setup( "Player1", 100 );
    players[1].Setup( "Player2", 100 );

    while ( players[0].IsAlive() && players[1].IsAlive() )
    {
        cout << endl << "------------------------------------" << endl;
        for ( int p = 0; p < 2; p++ )
        {
            cout << players[p].GetName() << ": " << players[p].GetHP() << "\t";
        }
        cout << endl;

        for ( int p = 0; p < 2; p++ )
        {
            cout << players[p].GetName() << "'s turn" << endl;
            int choice = ChooseAction();

            if ( choice == 1 )
            {
                players[p].SetAttackAndDefense( 10, 2 );
            }
            else if ( choice == 2 )
            {
                players[p].SetAttackAndDefense( 5, 5 );
            }
        }

        players[0].TakeDamage( players[1].GetAttack() );
        players[1].TakeDamage( players[0].GetAttack() );
    }

    return 0;
}



