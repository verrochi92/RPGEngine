// Ninja class implementation
// By Nick Verrochi
// Last Modified: 5/6/15

#include "Player_Ninja.h"
using namespace std;

Ninja::Ninja(const string &playerName) : Player(playerName) {
	attack = 25;
	defense = 15;
	hpMax = 100;
	hp = hpMax;
	mpMax = 25;
	mp = mpMax;
	magicPower = 20;
	speed = 25;

	setID(NINJA);
	setPlayerClass("Ninja");
}

void Ninja::levelUp() {
	if (level != LEVEL_CAP) {
		srand(static_cast<unsigned int>(time(0)));

		++level;
		attack += 15 + (rand() % 5);
		defense += 10 + (rand() % 5);
		hpMax += 25 + (rand() % 5);
		mpMax += 10 + (rand() % 5);
		magicPower += 10 + (rand() % 10);
		speed += 15 + (rand() % 5);

		exp = exp - expToNext;
		expToNext = static_cast<int>(expToNext * 1.5);

		cout << name << " has leveled up! \n";

		if (exp >= expToNext) levelUp(); // recursion!
	}
}

void Ninja::printMenu() {
	cout << "\t 1. Attack \n"
		<< "\t 2. Double Attack (10 mp) \n"
		<< "\t 3. Escape \n";
}

void Ninja::action(const int &choice, Entity *target) {
	switch (choice) {
	case 1:
		launchAttack(target, NONE);
		cout << name << " attacks! \n";
		break;
	case 2:
		if (mp >= 10) {
			launchAttack(target, NONE);
			launchAttack(target, NONE);
			mp -= 10;
			cout << name << " attacks twice! \n";
		}
		else {
			cout << "Not enough mp! \n";
		}
		break;
	case 3:
		setEscaping(true);
		cout << name << " escapes! \n";
		break;
	default: 
		throw Player::ChoiceOutOfRangeException;
	}
}