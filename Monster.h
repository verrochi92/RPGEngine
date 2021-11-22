// Monster class header
// Superclass for all monster types
// By Nick Verrochi
// Last Modified: 5/12/15

#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"
#include "Player.h"
using namespace std;

class Monster : public Entity {
public:
	Monster(const int &);
	// generate monster scaled to level passed as argument

	void setExpReward(const unsigned long long &);
	unsigned long long getExpReward() const;

	virtual void action(Entity *) = 0;
	// handles combat behaviour of the enemy

protected:
	unsigned long long expReward; // amount of exp gained from defeating the monster
};

#endif