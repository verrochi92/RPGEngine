// Final Boss class implementation
// By Nick Verrochi
// Last Modified: 5/13/15

#include "Monster_FinalBoss.h"
using namespace std;

Delta::Delta() : Monster(99) {
	name = "Professor Delta";
	hpMax = 2000;
	hp = hpMax;
	mpMax = 0;
	mp = mpMax;
	attack = 255;
	defense = 125;
	magicPower = 255;
	speed = 0;

	expReward = 100000;
}

void Delta::action(Entity *target) {
	srand(static_cast<unsigned int>(time(0)));

	switch (rand() % 3) {
	case 0:
		launchAttack(target, NONE);
		cout << name << " pounds you repeatedly with the hammer of programming knowledge! \n";
		break;
	case 1:
		launchAttack(target, NONE);
		cout << "Do it again! \n";
		break;
	case 2:
		launchAttack(target, NONE);
		cout << "That is bad programming! \n";
	}
}