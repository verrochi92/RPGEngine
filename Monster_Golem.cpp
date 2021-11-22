// Golem class implementation
// By Nick Verrochi
// Last Modified: 5/12/15

#include "Monster_Golem.h"
using namespace std;

Golem::Golem(const int &playerLevel) : Monster(playerLevel) {
	srand(static_cast<unsigned int>(time(0)));

	name = "Golem";

	hpMax = (level * 50) + 200;
	hp = hpMax;
	mpMax = 0;
	mp = mpMax;
	attack = (level * 15) + 30;
	defense = (level * 15) + 25;
	magicPower = (level * 5) + 20;
	speed = (level * 5) + 10;

	weaknessList.push_back(ICE);
	resistanceList.push_back(THUNDER);

	expReward = (level * 100) + (rand() % (level * 10));
}

void Golem::action(Entity *target) {
	srand(static_cast<unsigned int>(time(0)));

	switch (rand() % 5) {
	case 4:
		defense += 5;
		cout << name << " hardens! Defense increased! \n";
		break;
	default:
		launchAttack(target, NONE);
		cout << name << " attacks! \n";
	}
}