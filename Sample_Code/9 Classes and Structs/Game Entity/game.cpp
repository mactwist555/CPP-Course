#include <iostream>
#include <string>
using namespace std;

class Player
{
    public:
    void Setup( const string& name, int hp )
    {
        this->hp = hp;
        this->name = name;
    }

    void DisplayStats()
    {
        cout << name << ": " << hp << " Hit Points" << endl;
    }

    private:
    int hp;
    string name;
};

int main()
{
    Player players[2];
    players[0].Setup( "Trevor", 100 );
    players[1].Setup( "Larry", 100 );

    for ( int i = 0; i < 2; i++ )
    {
        players[i].DisplayStats();
    }

    return 0;
}



