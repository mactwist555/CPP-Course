/*
 * Python vs. C++ Example 6
 * Rachel J. Morris, 2013 - RachelJMorris@gmail.com, Moosader.com, github.com/Moosader
 * MIT License
*/

#ifndef _PET
#define _PET

#include <string>
using namespace std;

class Pet
{
	public:
	Pet();

	bool Update();
	void Balance();
	void Feed( string foodType );
	void Play();
	void Sleep();
	void PrintInfo();

	void SetName( string name );
	string GetName();

	private:
	int m_hunger;
	int m_energy;
	int m_happiness;
	string m_name;
	int m_sleepTurns;
};

#endif
