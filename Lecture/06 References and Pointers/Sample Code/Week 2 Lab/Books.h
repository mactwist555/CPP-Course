#ifndef _BOOKS
#define _BOOKS

#include <string>
#include <iostream>
using namespace std;

class Book
{
	public:
	void Setup( string& title, string& author, string isbn )
	{
		m_isCheckedOut = false;
		m_title = title;
		m_author = author;
		m_isbn = isbn;
	}

	bool IsbnMatches( const string& isbn )
	{
		return ( m_isbn == isbn );
	}

	void ToggleBook()
	{
		m_isCheckedOut = !m_isCheckedOut;

		if ( m_isCheckedOut )
		{
			cout << "Book " << m_title << " was checked out" << endl;
		}
		else
		{
			cout << "Book " << m_title << " was returned" << endl;
		}
	}


	private:
	string m_title;
	string m_author;
	string m_isbn;
	bool m_isCheckedOut;
};

#endif
