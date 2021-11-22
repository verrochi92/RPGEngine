// Mage class implementation
// By Nick Verrochi
// Last Modified: 5/8/15

#include "Player_Mage.h"
using namespace std;

Mage::Mage(const string &playerName) : Player(playerName) {
	attack = 15;
	defense = 15;
	hpMax = 100;
	hp = hpMax;
	mpMax = 75;
	mp = mpMax;
	magicPower = 30;
	speed = 15;

	setID(MAGE);
	setPlayerClass("Mage");
}

void Mage::levelUp() {
	if (level != LEVEL_CAP) {
		srand(static_cast<unsigned int>(time(0)));

		++level;
		attack += 5 + (rand() % 5);
		defense += 5 + (rand() % 5);
		hpMax += 25 + (rand() % 5);
		mpMax += 10 + (rand() % 5);
		magicPower += 10 + (rand() % 10);
		speed += 5 + (rand() % 5);

		exp = exp - expToNext;
		expToNext = static_cast<int>(expToNext * 1.5);

		cout << name << " has leveled up! \n";

		if (exp >= expToNext) levelUp(); // recursion
	}
}

void Mage::printMenu() {
	cout << "\t 1. Attack \n"
		<< "\t 2. Fire Spell    (10 mp) \n"
		<< "\t 3. Ice Spell     (10 mp) \n"
		<< "\t 4. Thunder Spell (10 mp) \n"
		<< "\t 5. Heal          (5 mp) \n";
}

void Mage::action(const int &choice, Entity *target) {
	switch (choice) {
	case 1:
		launchAttack(target, NONE);
		cout << name << " attacks! \n";
		break;
	case 2:
		if (mp >= 10) {
			launchAttack(target, FIRE);
			cout << name << " casts a fire spell! \n";
			mp -= 10;
		}
		else {
			cout << "Failed to cast spell! \n";
		}
		break;
	case 3:
		if (mp >= 10) {
			launchAttack(target, ICE);
			cout << name << " casts an ice spell! \n";
			mp -= 10;
		}
		else {
			cout << "Failed to cast spell! \n";
		}
		break;
	case 4:
		if (mp >= 10) {
			launchAttack(target, THUNDER);
			cout << name << " casts a thunder spell! \n";
			mp -= 10;
		}
		else {
			cout << "Failed to cast spell! \n";
		}
		break;
	case 5:
		if (heal()) {
			cout << name << " has healed their wounds. \n";
		}
		else {
			cout << "Failed to cast spell! \n";
		}
		break;
	default:
		throw Player::ChoiceOutOfRangeException;
	}
}