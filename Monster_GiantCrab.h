// GiantCrab monster class header
// By Nick Verrochi
// Last Modified: 5/10/15

#ifndef CRAB_H
#define CRAB_H

#include "Monster.h"
using namespace std;

class GiantCrab : public Monster {
public:
	GiantCrab(const int &);
	// creates a monster scaled to level passed

	virtual void action(Entity *) override final;
	// controls attack behavior
};

#endif