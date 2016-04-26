#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Seat
{
    string passenger;
    int row;
    int column;
};

void Board( stack<Seat>& airplane );
void Clear( stack<Seat>& airplane );

int main()
{
    stack<Seat> airplane;

    Board( airplane );

    cout << endl << " Plane arrived at destination" << endl;

    Clear( airplane );

    return 0;
}

void Board( stack<Seat>& airplane )
{
    cout << endl << "Boarding..." << endl;
    int row = 0;
    int column = 0;
    string buffer;

    ifstream input( "passengers.txt" );

    while ( input >> buffer )
    {
        Seat s;
        s.passenger = buffer;
        s.row = row;
        s.column = column;

        column++;
        if ( column == 4 )
        {
            row++;
            column++;
        }

        cout << s.passenger << " boards, assigned seat "
            << s.row << "-" << s.column << endl;
        airplane.push( s );
    }

    input.close();
}

void Clear( stack<Seat>& airplane )
{
    cout << endl << "Emptying..." << endl;
    while ( !airplane.empty() )
    {
        Seat s = airplane.top();
        cout << s.passenger << " exits the plane" << endl;
        airplane.pop();
    }
}
