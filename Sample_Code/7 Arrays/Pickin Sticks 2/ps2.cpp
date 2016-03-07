#include <iostream>
#include <string>
using namespace std;

void CreateBoard( char board[10][5] );
void DrawBoard( const char board[10][5], int playerX, int playerY, int stickX, int stickY );
char GetInput();
void HandleInput( char choice, int & playerX, int & playerY );
void ClearScreen();
void GenerateRandomCoordinates( int & x, int & y );
bool CheckCollision( int & x1, int & y1, int & x2, int & y2 );

int main()
{
    srand( time( NULL ) );

    char board[10][5];
    CreateBoard( board );

    int score = 0;
    int playerX = 5, playerY = 2;
    int stickX, stickY;
    GenerateRandomCoordinates( stickX, stickY );

    while ( true )
    {
        ClearScreen();
        DrawBoard( board, playerX, playerY, stickX, stickY );
        cout << "Score: " << score << endl;
        char choice = GetInput();
        HandleInput( choice, playerX, playerY );

        if ( CheckCollision( playerX, playerY, stickX, stickY ) )
        {
            score += 1;
        }
    }

    return 0;
}

bool CheckCollision( int & x1, int & y1, int & x2, int & y2 )
{
    if ( x1 == x2 && y1 == y2 )
    {
        GenerateRandomCoordinates( x2, y2 );
        return true;
    }
    return false;
}

void GenerateRandomCoordinates( int & x, int & y )
{
    x = rand() % 10;
    y = rand() % 5;
}

void ClearScreen()
{
    #if defined ( WIN32 ) || defined( _WIN32 ) || defined( __WIN32 )
    system("cls");
    #else
    system("clear");
    #endif
}

void HandleInput( char choice, int & playerX, int & playerY )
{
    if ( choice == 'n' )
    {
        playerY -= 1;
    }
    else if ( choice == 's' )
    {
        playerY += 1;
    }
    else if ( choice == 'w' )
    {
        playerX -= 1;
    }
    else if ( choice == 'e' )
    {
        playerX += 1;
    }
}

char GetInput()
{
    cout << "N, W, S, E: ";
    char choice;
    cin >> choice;
    choice = tolower( choice );
    return choice;
}

void CreateBoard( char board[10][5] )
{
    for ( int y = 0; y < 5; y++ )
    {
        for ( int x = 0; x < 10; x++ )
        {
            board[x][y] = '.';
        }
    }
}

void DrawBoard( const char board[10][5], int playerX, int playerY, int stickX, int stickY )
{
    for ( int y = 0; y < 5; y++ )
    {
        for ( int x = 0; x < 10; x++ )
        {
            if ( x == playerX && y == playerY )
            {
                cout << "@";
            }
            else if ( x == stickX && y == stickY )
            {
                cout << "Y";
            }
            else
            {
                cout << board[x][y];
            }
        }
        cout << endl;
    }
}
