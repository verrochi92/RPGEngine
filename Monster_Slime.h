// Slime class header
// By Nick Verrochi
// Last Modified: 4/27/15

#ifndef SLIME_H
#define SLIME_H

#include "Monster.h"
using namespace std;

class Slime : public Monster {
public:
	Slime(const int &);
	// constructs Slime scaled to level passed as argument
	// sets stats and elemental resistances

	virtual void action(Entity *) override final;
	// this monster will simply attack each turn
};

#endif