// Dragon class implementation
// By Nick Verrochi
// Last Modified: 5/10/15

#include "Monster_Dragon.h"
using namespace std;

Dragon::Dragon(const int &playerLevel) : Monster(playerLevel) {
	srand(static_cast<unsigned int>(time(0)));

	name = "Dragon";

	hpMax = (level * 30) + 100;
	hp = hpMax;
	mpMax = 50;
	mp = mpMax;
	attack = (level * 15) + 20;
	defense = (level * 10) + 20;
	magicPower = (level * 15) + 20;
	speed = (level * 5) + 5;

	weaknessList.push_back(ICE);
	resistanceList.push_back(FIRE);

	expReward = (level * 50) + (rand() % (level * 10));
}

void Dragon::action(Entity *target) {
	srand(static_cast<unsigned int>(time(0)));
	switch (rand() % 3) {
	case 2:
		if (mp >= 10) {
			launchAttack(target, FIRE);
			cout << name << " breathes fire! \n";
			mp -= 10;
		}
		else {
			launchAttack(target, NONE);
			cout << name << " attacks! \n";
		}
		break;
	default:
		launchAttack(target, NONE);
		cout << name << "attacks! \n";
	}
}