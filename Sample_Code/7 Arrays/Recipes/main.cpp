#include <iostream>
#include <string>
using namespace std;

int GetValidChoice( int min, int max );

int main()
{
    const int MAX_RECIPES = 10;
    const int MAX_INGREDIENTS = 5;

    string recipes[MAX_RECIPES];
    string ingredients[MAX_RECIPES][MAX_INGREDIENTS];

    int recipeCount = 0;

    bool done = false;

    string menuOptions[] = {
        "Add Recipe",
        "View Recipes",
        "Exit"
    };

    while ( !done )
    {
        cout << endl << "MAIN MENU" << endl;
        for ( int i = 0; i < 3; i++ )
        {
            cout << (i+1) << ". " << menuOptions[i] << endl;
        }
        int choice = GetValidChoice( 1, 3 );

        if ( choice == 1 )
        {
            cout << "Recipe title: ";
            cin.ignore();
            getline( cin, recipes[ recipeCount ] );

            for ( int i = 0; i < MAX_INGREDIENTS; i++ )
            {
                cout << "Ingredient " << (i+1) << ": ";
                getline( cin, ingredients[ recipeCount ][ i ] );
            }

            recipeCount++;
        }
        else if ( choice == 2 )
        {
            cout << endl << "RECIPES" << endl;
            for ( int r = 0; r < recipeCount; r++ )
            {
                cout << "\tRecipe " << (r+1) << ": " << recipes[r] << endl;
                for ( int i = 0; i < MAX_INGREDIENTS; i++ )
                {
                    cout << "\t\t" << (i+1) << ". " << ingredients[r][i] << endl;
                }
                cout << endl;
            }
        }
        else
        {
            done = true;
        }
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
