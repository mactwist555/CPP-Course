#include "Animal.h"

#include <iostream>
using namespace std;

Animal::Animal()
{
	m_name = "Generic Animal";
	m_call = "Generic Animal Noise";
}

void Animal::Speak()
{
	cout << m_call << endl;
}

string Animal::GetName()
{
	return m_name;
}

void Animal::ReactToDanger()
{
	cout << "Ehh." << endl;
}





