// Final Boss monster class header
// By Nick Verrochi
// Last Modified: 5/13/15

#ifndef DELTA_H
#define DELTA_H

#include "Monster.h"
using namespace std;

class Delta : public Monster {
public:
	Delta();
	// constructs final boss

	virtual void action(Entity *) override final;
	// controls attack behavior
};

#endif