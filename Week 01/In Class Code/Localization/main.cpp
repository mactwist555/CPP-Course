#include <iostream>
#include <string>
using namespace std;

enum Language { ENGLISH, GERMAN, ESPERANTO };
enum ProgramText { LANGUAGE_NAME, WELCOME, ADD_NUMBERS, EXIT, NUMBER, SUM, GOODBYE };

void SetupLanguage( string text[3][7] );

int main()
{
	string text[3][7];
	SetupLanguage( text );

	// ---------- program begin

	// Display language choices
	for ( int i = 0; i < 3; i++ )
	{
		cout << i << ". " << text[ i ][ LANGUAGE_NAME ] << endl;
	}

	int language;
	cout << "? ";
	cin >> language;

	cout << text[ language ][ WELCOME ] << endl;

	bool done = false;
	int choice;
	while ( !done )
	{
		cout << endl << "-------------------------" << endl;
		cout << "1. " << text[ language ][ ADD_NUMBERS ] << endl;
		cout << "2. " << text[ language ][ EXIT ] << endl;
		cin >> choice;

		if ( choice == 2 )
		{
			done = true;
		}
		else if ( choice == 1 )
		{
			int num1, num2, sum;
			cout << text[ language ][ NUMBER ] << " 1: ";
			cin >> num1;

			cout << text[ language ][ NUMBER ] << " 2: ";
			cin >> num2;

			sum = num1 + num2;
			cout << text[ language ][ SUM ] << ": " << sum << endl;
		}
	}

	cout << text[ language ][ GOODBYE ] << endl;

	return 0;
}

void SetupLanguage( string text[3][7] )
{
	text[ ENGLISH ]		[ LANGUAGE_NAME ] = "English";
	text[ ESPERANTO ]	[ LANGUAGE_NAME ] = "Esperanto";
	text[ GERMAN ]		[ LANGUAGE_NAME ] = "Deutsch";

	text[ ENGLISH ]		[ WELCOME ] = "Welcome!";
	text[ ESPERANTO ]	[ WELCOME ] = "Bonvolu!";
	text[ GERMAN ]		[ WELCOME ] = "Herzlich Willkommen!";

	text[ ENGLISH ]		[ ADD_NUMBERS ] = "Add numbers";
	text[ ESPERANTO ]	[ ADD_NUMBERS ] = "Aldoni nombroj";
	text[ GERMAN ]		[ ADD_NUMBERS ] = "Addieren von Zahlen";

	text[ ENGLISH ]		[ EXIT ] = "Exit";
	text[ ESPERANTO ]	[ EXIT ] = "Eliri!";
	text[ GERMAN ]		[ EXIT ] = "Verlassen";

	text[ ENGLISH ]		[ NUMBER ] = "Number";
	text[ ESPERANTO ]	[ NUMBER ] = "Nombro!";
	text[ GERMAN ]		[ NUMBER ] = "Anzahl";

	text[ ENGLISH ]		[ SUM ] = "Sum";
	text[ ESPERANTO ]	[ SUM ] = "Sumo";
	text[ GERMAN ]		[ SUM ] = "Summe";

	text[ ENGLISH ]		[ GOODBYE ] = "Goodbye!";
	text[ ESPERANTO ]	[ GOODBYE ] = "Gxis!";
	text[ GERMAN ]		[ GOODBYE ] = "Auf Wiedersehen!";
}
