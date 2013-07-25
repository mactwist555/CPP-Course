#include "PhoneNumber.h"

bool operator==( const PhoneNumber& item1, const PhoneNumber& item2 )
{
	return ( 	item1.m_firstName 	== item2.m_firstName
			&& 	item1.m_lastName 	== item2.m_lastName
			&& 	item1.m_country 	== item2.m_country
			&& 	item1.m_phoneNumber == item2.m_phoneNumber );
}

PhoneNumber::PhoneNumber()
{
	m_firstName = m_lastName = m_phoneNumber = m_country = "Not Setup";
}

PhoneNumber::PhoneNumber( const string& first, const string& last, const string& phone, const string& country )
{
	Setup( first, last, phone, country );
}

void PhoneNumber::Setup( const string& first, const string& last, const string& phone, const string& country )
{
	m_firstName 	= first;
	m_lastName 		= last;
	m_phoneNumber	= phone;
	m_country		= country;
}
