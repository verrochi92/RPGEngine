// Ninja class header
// This class is focused on speed and attack power
// Has lower defense and health, and can't heal, 
// but can attack twice and escape from battle
// By Nick Verrochi
// Last Modified: 5/4/15

#ifndef NINJA_H
#define NINJA_H

#include "Player.h"
using namespace std;

class Ninja : public Player {
public:
	Ninja(const string &);
	// constructs a new Ninja character with name passed

	virtual void levelUp() override final;
	virtual void printMenu() override final;

	virtual void action(const int &, Entity *);
	// throws Player::ChoiceOutOfRangeException
};

#endif