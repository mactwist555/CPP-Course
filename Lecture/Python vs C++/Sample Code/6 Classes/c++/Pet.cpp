/*
 * Python vs. C++ Example 6
 * Rachel J. Morris, 2013 - RachelJMorris@gmail.com, Moosader.com, github.com/Moosader
 * MIT License
*/

#include "Pet.h"

#include <iostream>
using namespace std;

Pet::Pet()
{
	m_hunger = m_energy = m_happiness = m_sleepTurns = 0;
	m_name = "";
}

void Pet::SetName( string name )
{
	m_name = name;
}

string Pet::GetName()
{
	return m_name;
}

bool Pet::Update()
{
	if ( m_sleepTurns > 0 )
	{
		cout << m_name << " is sleeping... " << m_sleepTurns << endl;
		m_sleepTurns -= 1;
		m_energy += 25;
		Balance();

		if ( m_energy == 100 )
		{
			m_sleepTurns = 0;
			cout << m_name << " wakes up!" << endl;
		}

		return true;
	}

	// Not sleeping otherwise
	Balance();
	return false;
}

void Pet::Balance()
{
	// Unary operators!
	m_hunger = ( m_hunger > 100 ) ? 100 : m_hunger;
	m_hunger = ( m_hunger < 0 ) ? 0 : m_hunger;

	m_energy = ( m_energy > 100 ) ? 100 : m_energy;
	m_energy = ( m_energy < 0 ) ? 0 : m_energy;

	m_happiness = ( m_happiness > 100 ) ? 100 : m_happiness;
	m_happiness = ( m_happiness < 0 ) ? 0 : m_happiness;
}

// This *should* be a const string reference,
// But we'll cover this in 201. :)
void Pet::Feed( string foodType )
{
	// These could also be enums, which would be much better
	if ( foodType == "bacon" )
	{
		m_hunger -= 10;
		m_happiness += 5;
		m_energy += 5;
	}
	else if ( foodType == "carrots" )
	{
		m_hunger -= 8;
		m_happiness -= 2;
	}
	else if ( foodType == "candy" )
	{
		m_hunger -= 5;
		m_happiness += 2;
	}
}

void Pet::Play()
{
	m_happiness += 10;
	m_energy -= 5;
}

void Pet::Sleep()
{
	m_sleepTurns = 3;
}

void Pet::PrintInfo()
{
	cout << "------------------------------" << endl;

	cout << m_name << "'s Mood: \t\t";
	if ( m_happiness <= 25 ) { cout << "Miserable "; }
	if ( m_happiness <= 50 ) { cout << "Adequate "; }
	if ( m_happiness <= 75 ) { cout << "Content "; }
	if ( m_happiness <= 100 ) { cout << "Joyous "; }
	cout << "(" << m_happiness << "/100)" << endl;

	cout << m_name << "'s Hunger: \t";
	if ( m_hunger <= 25 ) { cout << "Full "; }
	if ( m_hunger <= 50 ) { cout << "Content "; }
	if ( m_hunger <= 75 ) { cout << "Peckish "; }
	if ( m_hunger <= 100 ) { cout << "Starving "; }
	cout << "(" << m_hunger << "/100)" << endl;

	cout << m_name << "'s Energy: \t";
	if ( m_energy <= 25 ) { cout << "Exhausted "; }
	if ( m_energy <= 50 ) { cout << "Drowsy "; }
	if ( m_energy <= 75 ) { cout << "Awake "; }
	if ( m_energy <= 100 ) { cout << "Energetic "; }
	cout << "(" << m_energy << "/100)" << endl;
}
