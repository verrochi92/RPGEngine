// Slime class implementation
// By Nick Verrochi
// Last Modified: 5/1/15

#include "Monster_Slime.h"
using namespace std;

Slime::Slime(const int &playerLevel) : Monster(playerLevel) {
	srand(static_cast<unsigned int>(time(0)));

	name = "Slime";
	
	hpMax = (level * 10) + 40;
	hp = hpMax;
	mpMax = 0;
	mp = mpMax;
	attack = (level * 5) + 20;
	defense = (level * 5) + 20;
	magicPower = (level * 15) + 10;
	speed = (level * 2) + 1;

	resistanceList.push_back(FIRE);
	resistanceList.push_back(ICE);
	resistanceList.push_back(THUNDER);

	expReward = (level * 25) + (rand() % (level * 10));
}

void Slime::action(Entity *target) {
	launchAttack(target, NONE);
	cout << name << " attacks! \n";
}