// Golem monster class header
// By Nick Verrochi
// Last Modified: 5/12/15

#ifndef GOLEM_H
#define GOLEM_H

#include "Monster.h"
using namespace std;

class Golem : public Monster {
public:
	Golem(const int &);
	// creates a monster scaled to level passed

	virtual void action(Entity *) override final;
	// controls battle behavior
};

#endif