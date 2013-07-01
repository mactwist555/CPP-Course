#ifndef _ENEMY
#define _ENEMY

#include "Character.h"
#include "Player.h"

class Enemy : public Character
{
	public:
	void Move( Player player );
};

#endif
