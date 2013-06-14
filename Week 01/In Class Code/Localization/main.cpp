#include <iostream>
#include <string>
using namespace std;

enum Language { ENGLISH, GERMAN, ESPERANTO };
enum ProgramText { LANGUAGE_NAME, WELCOME, NUM_1, NUM_2, SUM, BYE };

void SetupLanguage( string text[3][6] );

int main()
{
	string text[3][6];
	SetupLanguage( text );


	for ( int i = 0; i < 3; i++ )
	{
		cout << i << ". " << text[i][ LANGUAGE_NAME ] << endl;
	}

	int language;
	cout << "Which language? ";
	cin >> language;

	cout << text[ language ][ WELCOME ] << endl;

	cout << text[ language ][ NUM_1 ] << endl;
	int number1;
	cin >> number1;

	cout << text[ language ][ NUM_2 ];
	int number2;
	cin >> number2;

	int sum = number1 + number2;
	cout << text[ language ][ SUM ] << sum << endl;

	cout << text[ language ][ BYE ] << endl;

	return 0;
}

void SetupLanguage( string text[3][6] )
{
	text[ ENGLISH ]		[ LANGUAGE_NAME ] = "English!";
	text[ GERMAN ]		[ LANGUAGE_NAME ] = "German!";
	text[ ESPERANTO ]	[ LANGUAGE_NAME ] = "Esperanto!";

	text[ ENGLISH ]		[ NUM_1 ] = "Enter number 1:";
	text[ GERMAN ]		[ NUM_1 ] = "Geben Sie die Nummer 1:";
	text[ ESPERANTO ]	[ NUM_1 ] = "Entajpu numeron 1:";

	text[ ENGLISH ]		[ NUM_2 ] = "Enter number 2:";
	text[ GERMAN ]		[ NUM_2 ] = "Geben Sie die Nummer 2:";
	text[ ESPERANTO ]	[ NUM_2 ] = "Entajpu numeron 2:";

	text[ ENGLISH ]		[ SUM ] = "Sum:";
	text[ GERMAN ]		[ SUM ] = "Summe:";
	text[ ESPERANTO ]	[ SUM ] = "Sumo:";

	text[ ENGLISH ]		[ BYE ] = "Bye!";
	text[ GERMAN ]		[ BYE ] = "Auf Wiedersehen!";
	text[ ESPERANTO ]	[ BYE ] = "Gxis!";
}
