#include <iostream>
using namespace std;

#include "CalorieItem.hpp"

int main()
{
    CalorieItem ingredients[11];

    ingredients[0].Setup( "Beef", 70 );
    ingredients[1].Setup( "Refried Beans", 140 );

    ingredients[2].Setup( "Cheddar Cheese", 25 );
    ingredients[3].Setup( "Iceberg Lettuce", 0 );
    ingredients[4].Setup( "Tomatoes", 0 );
    ingredients[5].Setup( "Onions", 0 );

    ingredients[6].Setup( "Taco Shell", 70 );
    ingredients[7].Setup( "Flour Tortilla", 200 );

    ingredients[8].Setup( "Red Sauce", 10 );
    ingredients[9].Setup( "Nacho Cheese Sauce", 30 );
    ingredients[10].Setup( "Low-fat Sour Cream", 20 );

    CalorieItem meal;
    meal.SetName( "Your Meal" );

    while ( true )
    {
        for ( int i = 0; i < 11; i++ )
        {
            cout << (i+1) << ". " << ingredients[i] << endl;
        }
        cout << "12. Finish" << endl;

        int choice;
        cout << "Choice: ";
        cin >> choice;

        if ( choice == 12 )
        {
            break;
        }
        else
        {
            choice = choice - 1;
            meal += ingredients[choice];
        }
        cout << endl;
    }

    meal.Display();

    return 0;
}
