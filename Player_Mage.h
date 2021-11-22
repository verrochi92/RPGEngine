// Mage player class header
// This class focuses on magical attacks
// By Nick Verrochi
// Last Modified: 5/7/15

#ifndef MAGE_H
#define MAGE_H

#include "Player.h"
using namespace std;

class Mage : public Player {
public:
	Mage(const string &);
	
	virtual void levelUp() override final;
	virtual void printMenu() override final;

	virtual void action(const int &, Entity *) override final;
	// throws Player::ChoiceOutOfRangeException
};

#endif