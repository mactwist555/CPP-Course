/*
CS 201 Summer 2013 Assignment 4: Phonebook appliccation
Solution by Rachel J. Morris
*/

#ifndef _PHONENUMBER
#define _PHONENUMBER

#include <string>
using namespace std;

class PhoneNumber
{
	public:
	PhoneNumber();
	PhoneNumber( const string& first, const string& last, const string& phone, const string& country );
	void Setup( const string& first, const string& last, const string& phone, const string& country );

	friend bool operator==( const PhoneNumber& item1, const PhoneNumber& item2 );

	private:
	string m_firstName;
	string m_lastName;
	string m_phoneNumber;
	string m_country;
};

#endif
