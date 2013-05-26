#ifndef _ANIMAL
#define _ANIMAL

#include <string>
using namespace std;

class Animal
{
	public:
	Animal();

	void Speak();
	string GetName();
	void ReactToDanger();	// Overwritten

	protected:
	string m_call;
	string m_name;
};

#endif
