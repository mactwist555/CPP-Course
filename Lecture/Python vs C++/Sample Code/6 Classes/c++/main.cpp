/*
 * Python vs. C++ Example 6
 * Rachel J. Morris, 2013 - RachelJMorris@gmail.com, Moosader.com, github.com/Moosader
 * MIT License
*/

#include <iostream>
#include <string>

#include "Pet.h"

using namespace std;

int main()
{
	Pet pet;

	cout << "VIRTUAL PET" << endl;
	cout << "What should your pet's name be? ";
	string name;
	cin >> name;
	pet.SetName( name );

	bool done = false;
	int choice;

	while ( !done )
	{
		cout << "***********************************" << endl;
		bool isPetSleeping = pet.Update();

		if ( !isPetSleeping )
		{
			cout << "1. View " << pet.GetName() << "'s Stats" << endl;
			cout << "2. Feed " << pet.GetName() << endl;
			cout << "3. Play with " << pet.GetName() << endl;
			cout << "4. Send " << pet.GetName() << " to bed" << endl;
			cout << "5. Quit" << endl;
			cout << "What do you want to do? ";
			cin >> choice;

			while ( choice < 1 || choice > 5 )
			{
				cout << "Invalid choice. What do you want to do? ";
				cin >> choice;
			}

			switch( choice )
			{
				case 1:		// Stats
					pet.PrintInfo();
				break;

				case 2:		// Feed
					cout << "\n -----------------------------" << endl;
					cout << "1. Bacon" << endl;
					cout << "2. Carrots" << endl;
					cout << "3. Candy" << endl;
					cout << "What do you want to feed " << pet.GetName() << "? ";
					cin >> choice;

					while ( choice < 1 || choice > 5 )
					{
						cout << "Invalid choice. What do you want to feed " << pet.GetName() << "? ";
						cin >> choice;
					}

					if ( choice == 1 )
					{
						pet.Feed( "bacon" );
					}
					else if ( choice == 2 )
					{
						pet.Feed( "cheese" );
					}
					else if ( choice == 3 )
					{
						pet.Feed( "candy" );
					}

				break;

				case 3:		// Play
					pet.Play();
				break;

				case 4:		// Sleep
					pet.Sleep();
				break;

				case 5:		// Quit
					done = true;
				break;
			}
		}
		else
		{
			// Pet is asleep
			cout << "Cannot do anything this turn!" << endl;
		}
	}

	cout << "Goodbye!" << endl;

	return 0;
}



