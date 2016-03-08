#include <iostream>
using namespace std;

#include "Phrase.hpp"

int main()
{
    Phrase p1( "Elephant in the room" );
    Phrase p2( "Kick the bucket" );
    Phrase p3( "Couch potato" );
    Phrase p4( "Piece of cake" );

    cout << "Phrase 1: " << p1 << endl;
    cout << "Phrase 2: " << p2 << endl;
    cout << "Phrase 3: " << p3 << endl;
    cout << "Phrase 4: " << p4 << endl;

    cout << endl << "Subscripts:" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << p1[i] << p2[i] << p3[i] << p4[i] << endl;
    }

    cout << endl << "Math:" << endl;
    Phrase add = p1 + p2;
    Phrase subtract = p3 - Phrase( "potato" );
    cout << "Phrase 1 + Phrase 2: \"" << add << "\"" << endl;
    cout << "Phrase 3 - potato: \"" << subtract << "\"" << endl;


    cout << endl << "Relational:" << endl;
    cout << "Phrase 1 < Phrase 2? " << ( p1 < p2 ) << endl;
    cout << "Phrase 2 < Phrase 3? " << ( p2 < p3 ) << endl;
    cout << "Phrase 3 < Phrase 4? " << ( p3 < p4 ) << endl;

    return 0;
}
