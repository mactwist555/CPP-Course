#ifndef _CAT
#define _CAT

#include "Animal.h"

class Cat : public Animal
{
	public:
	Cat();
	void ReactToDanger();
	void Dance(); // Unique to Cat

	protected:
	int m_hoursSlept;
};

#endif


