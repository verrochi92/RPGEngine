// Warrior class implementation
// By Nick Verrochi
// Last Modified: 5/8/15

#include "Player_Warrior.h"
using namespace std;

Warrior::Warrior(const string &playerName) : Player(playerName) {
	attack = 25;
	defense = 25;
	hpMax = 150;
	hp = hpMax;
	mpMax = 10;
	mp = mpMax;
	magicPower = 15;
	speed = 10;

	setID(WARRIOR);
	setPlayerClass("Warrior");
}

void Warrior::levelUp() {
	if (level != LEVEL_CAP) {
		srand(static_cast<unsigned int>(time(0)));
		
		++level;
		attack += 15 + (rand() % 5);
		defense += 15 + (rand() % 5);
		hpMax += 35 + (rand() % 5);
		mpMax += 10 + (rand() % 5);
		magicPower += 3 + (rand() % 10);
		speed += 3 + (rand() % 5);
		
		exp = exp - expToNext;
		expToNext = static_cast<int>(expToNext * 1.5);

		cout << name << " has leveled up! \n";

		if (exp >= expToNext) levelUp(); // recursion
	}
}

void Warrior::printMenu() {
	cout << "\t 1. Attack \n"
		<< "\t 2. Heal (5 mp)\n";
}

void Warrior::action(const int &choice, Entity *target) {
	switch (choice) {
	case 1:
		launchAttack(target, NONE);
		cout << name << " attacks! \n";
		break;
	case 2:
		if (!heal()) {
			cout << "Failed to cast spell! \n";
		}
		else {
			cout << name << " has healed their wounds. \n";
		}
		break;
	default:
		throw Player::ChoiceOutOfRangeException;
	}
}

