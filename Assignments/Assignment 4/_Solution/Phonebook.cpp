#include "Phonebook.h"

void Phonebook::ReadFile( const string& filename )
{
	ifstream infile( filename.c_str() );

	string first, last, phone, country;
	while ( infile >> first >> last >> phone >> country )
	{
		PhoneNumber tempPhone( first, last, phone, country );
		m_listPhoneNumbers.AddItem( tempPhone );
		m_listCountries.AddItem( country );
	}

	infile.close();
	cout << "Read file " << filename;
	cout << "\t" << m_listPhoneNumbers.GetSize() << " phone numbers";
	cout << "\t" << m_listCountries.GetSize() << " countries" << endl;
}

