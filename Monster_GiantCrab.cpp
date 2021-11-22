// GiantCrab class implementation
// By Nick Verrochi
// Last Modified: 5/10/15

#include "Monster_GiantCrab.h"
using namespace std;

GiantCrab::GiantCrab(const int &playerLevel) : Monster(playerLevel) {
	srand(static_cast<unsigned int>(time(0)));

	name = "Giant Enemy Crab";

	hpMax = (level * 30) + 150;
	hp = hpMax;
	mpMax = 0;
	mp = 0;
	attack = (level * 15) + 25;
	defense = (level * 10) + 25;
	magicPower = (level * 10) + 20;
	speed = (level * 10) + 10;

	weaknessList.push_back(THUNDER);
	resistanceList.push_back(FIRE);

	expReward = (level * 75) + (rand() % (level * 10));
}

void GiantCrab::action(Entity *target) {
	launchAttack(target, NONE);
	cout << name << " attacks! \n";
}