#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int GENRE_COUNT = 5;
const int TITLE_COUNT = 5;

int GetValidChoice( int min, int max );
void DisplayGenres( string genres[ GENRE_COUNT ] );
void DisplayGames( string titles[ TITLE_COUNT ], const string& genreName );
void DisplayOptions();
void LoadGames( string gameList[ GENRE_COUNT ][ TITLE_COUNT ] );

int main()
{
    string genres[ GENRE_COUNT ] = {
        "Action",
        "Adevnture",
        "FPS",
        "Puzzle",
        "RPG",
        };

    string gameList[ GENRE_COUNT ][ TITLE_COUNT ];
    LoadGames( gameList );

    bool done = false;
    while ( !done )
    {
        DisplayGenres( genres );

        int choice = GetValidChoice( 1, GENRE_COUNT );
        int genreIndex = choice - 1;

        DisplayGames( gameList[ genreIndex ], genres[ genreIndex ] );

        cout << "Add game at what index?" << endl;

        choice = GetValidChoice( 1, TITLE_COUNT );
        int gameIndex = choice - 1;

        cout << "Game title: ";
        cin >> gameList[ genreIndex ][ gameIndex ];

        cout << "Done" << endl << endl;
    }

    return 0;
}



int GetValidChoice( int min, int max )
{
    int choice;
    cout << ">> ";
    cin >> choice;

    while ( choice < min || choice > max )
    {
        cout << "Invalid selection. Try again." << endl;
        cout << ">> ";
        cin >> choice;
    }

    return choice;
}

void DisplayGenres( string genres[ GENRE_COUNT ] )
{
    cout << "GENRES" << endl;
    for ( int i = 0; i < GENRE_COUNT; i++ )
    {
        cout << (i+1) << "\t" << genres[ i ] << endl;
    }
}

void DisplayGames( string titles[ TITLE_COUNT ], const string& genreName )
{
    cout << "\t" << genreName << " GAMES" << endl;
    for ( int i = 0; i < TITLE_COUNT; i++ )
    {
        cout << "\t" << (i+1) << "\t" << titles[ i ] << endl;
    }
}

void LoadGames( string gameList[ GENRE_COUNT ][ TITLE_COUNT ] )
{
    ifstream input( "games.txt" );

    int g = 0, t = 0;
    string buffer;

    while ( input >> buffer )
    {
        // Skip first item (header), then load in the games.
        input   >> gameList[g][t];
        input   >> gameList[g][++t];
        input   >> gameList[g][++t];
        input   >> gameList[g][++t];
        input   >> gameList[g][++t];

        t = 0;
        g++;
    }

    input.close();
}
