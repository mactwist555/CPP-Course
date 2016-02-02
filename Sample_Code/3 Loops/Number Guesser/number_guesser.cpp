#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    srand( time( NULL ) );
    int randomNumber = rand() % 10;
    bool wonGame = false;

    cout << "GUESS THE NUMBER!" << endl;
    cout << "I'm thinking of a number between 0 and 10!" << endl;

    for ( int chances = 5; chances > 0; chances-- )
    {
        cout << endl << "You have " << chances << " chances left!" << endl;
        cout << "Guess: ";
        int guess;
        cin >> guess;

        if ( guess > randomNumber )
        {
            cout << "Too high!" << endl;
        }
        else if ( guess < randomNumber )
        {
            cout << "Too low!" << endl;
        }
        else
        {
            cout << "You got it!" << endl;
            wonGame = true;
            break;
        }
    }

    if ( wonGame )
    {
        cout << "YOU WIN!" << endl;
    }
    else
    {
        cout << "You lose :(" << endl;
    }

    return 0;
}
