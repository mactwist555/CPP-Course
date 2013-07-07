#ifndef _CHARACTER
#define _CHARACTER

#include <string>
using namespace std;

class Character
{
	public:
	virtual int DecideAction( string choices[3] );

	protected:
	int atk, def, agi;
};

class Player : public Character
{
	public:
	virtual int DecideAction( string choices[3] );
};

class Enemy : public Character
{
	public:
	virtual int DecideAction( string choices[3] );
};

#endif
