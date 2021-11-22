// Dragon monster class header
// By Nick Verrochi
// Last Modified: 5/6/15

#ifndef DRAGON_H
#define DRAGON_H

#include "Monster.h"
using namespace std;

class Dragon : public Monster {
public:
	Dragon(const int &);
	// creates a dragon scaled to level passed as argument

	virtual void action(Entity *) override final;
	// controls attack behavior
	// two thirds of the time, the dragon will attack
	// sometimes will launched a fire-elemental attack
};

#endif