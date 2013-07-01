#include <iostream>
#include <fstream>
using namespace std;

#include "Books.h"

int main()
{
	Book books[20];

	ifstream bookFile;
	bookFile.open( "books.txt" );

	bool done = false;

	int currentBook = 0;
	while ( !bookFile.eof() )
	{
		string title;
		string author;
		string isbn;

		getline( bookFile, title, '\n' );
		getline( bookFile, author, '\n' );
		getline( bookFile, isbn, '\n' );

		cout << currentBook << ": " << title << endl;
		if ( title != "" )
		{
			books[ currentBook ].Setup( title, author, isbn );
			currentBook++;
		}
	}

	bookFile.close();

	ifstream isbnFile;
	isbnFile.open( "isbns.txt" );

	string isbn;
	while ( isbnFile >> isbn )
	{
		for ( int i = 0; i < currentBook; i++ )
		{
			if ( books[i].IsbnMatches( isbn ) )
			{
				books[i].ToggleBook();
			}
		}
	}

	isbnFile.close();

	return 0;
}
