#include "Kitten.h"

void Kitten::Setup( const string& name, int age )
{
	m_name = name;
	m_age = age;
}

void Kitten::Print()
{
	cout << m_name << " is " << m_age << " years old" << endl;
}


// Assignment operator overloading

Kitten& Kitten::operator=( const Kitten& newValue )
{
	// Will cause problems if you try to assign an instance to itself!
	if ( this == &newValue )
	{
		return *this;
	}

	m_name = newValue.m_name;
	m_age = newValue.m_age;

	return *this;
}
