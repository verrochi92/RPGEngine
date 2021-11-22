// Battle class header
// objects of this class can handle creating 
// and playing through battles
// also handles player development post-battle
// By Nick Verrochi
// Last Modified: 4/30/15

#ifndef BATTLE_H
#define BATTLE_H

#include "Monster.h"
#include "Player.h"
using namespace std;

class Battle {
public:
	Battle(Player *, Monster *);
	// creates a battle between a player and a monster

	bool fight();
	// runs through a battle process untill one enemy is defeated
	// returns true if player wins, false if they are defeated

	void playerTurn();
	void monsterTurn();

	void printBattleStats();
	// clears screen and prints statistics of the combatants
	// essentially creates a battle mode screen

private:
	Player *player;
	Monster *monster;
};

#endif