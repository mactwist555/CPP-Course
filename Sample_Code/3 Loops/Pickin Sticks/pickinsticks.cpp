#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
    int width = 30;
    int height = 10;

    int playerX = 15;
    int playerY = 5;

    int stickX = rand() % width;
    int stickY = rand() % height;

    int computerX = 0;
    int computerY = 0;

    int playerScore = 0;
    int computerScore = 0;

    bool done = false;

    while ( !done )
    {
        system( "clear" ); // system("cls");

        // Draw to the screen
        for ( int y = 0; y < height; y++ )
        {
            for ( int x = 0; x < width; x++ )
            {
                if ( x == playerX && y == playerY )
                {
                    cout << "@";
                }
                else if ( x == stickX && y == stickY )
                {
                    cout << "|";
                }
                else if ( x == computerX && y == computerY )
                {
                    cout << "#";
                }
                else
                {
                    cout << ".";
                }
            }
            cout << endl;
        }

        // Get user input
        cout << endl;
        cout << "Player Score: " << playerScore << endl;
        cout << "Computer Score: " << computerScore << endl;
        cout << "N, W, S, E: ";
        string choice;
        cin >> choice;

        // Handle user input
        if ( choice == "N" )
        {
            playerY--;
        }
        else if ( choice == "S" )
        {
            playerY++;
        }
        else if ( choice == "W" )
        {
            playerX--;
        }
        else if ( choice == "E" )
        {
            playerX++;
        }

        if ( computerX < stickX )
        {
            computerX++;
        }
        else if ( computerX > stickX )
        {
            computerX--;
        }
        else if ( computerY < stickY )
        {
            computerY++;
        }
        else if ( computerY > stickY )
        {
            computerY--;
        }

        if ( playerX == stickX && playerY == stickY )
        {
            playerScore++;
            stickX = rand() % width;
            stickY = rand() % height;
        }

        if ( computerX == stickX && computerY == stickY )
        {
            computerScore++;
            stickX = rand() % width;
            stickY = rand() % height;
        }

        if ( computerScore == 5 || playerScore == 5 )
        {
            done = true;
        }

    }

    cout << "GAME OVER" << endl;

    return 0;
}
