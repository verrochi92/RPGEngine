// Warrior class header
// This is a player character, focused on high physical strength, but weakness to magic
// By Nick Verrochi
// Last Modified: 5/1/15

#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
using namespace std;

class Warrior : public Player {
public:
	Warrior(const string &);
	// sets base stats for warrior type character

	virtual void levelUp() override final;
	virtual void printMenu() override final;

	virtual void action(const int &, Entity *) override final;
	// throws Player::ChoiceOutOfRangeException
};

#endif