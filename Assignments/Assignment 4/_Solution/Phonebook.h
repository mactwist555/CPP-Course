#ifndef _PHONEBOOK
#define _PHONEBOOK

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "List.h"
#include "PhoneNumber.h"

class Phonebook
{
	public:
	void ReadFile( const string& filename );

	private:
	List<PhoneNumber>	m_listPhoneNumbers;
	List<string>		m_listCountries;
};

#endif
