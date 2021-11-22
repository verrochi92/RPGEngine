// Entity Class Implementation
// By Nick Verrochi
// Last Modified: 5/12/15

#include "Entity.h"
using namespace std;

void Entity::setName(const string &n) {
	name = n;
}

string Entity::getName() const {
	return name;
}

void Entity::setLevel(const int &lvl) {
	level = (lvl <= LEVEL_CAP && lvl > 0 ? lvl : LEVEL_CAP);
}

int Entity::getLevel() const {
	return level;
}

void Entity::setHpMax(const int &max) {
	hpMax = (max > 0 ? max : 1);
}

int Entity::getHpMax() const {
	return hpMax;
}

void Entity::setMpMax(const int &max) {
	mpMax = (max > 0 ? max : 1);
}

int Entity::getMpMax() const {
	return mpMax;
}

void Entity::setAttack(const int &num) {
	attack = (num > 0 ? num : 1);
}

int Entity::getAttack() const {
	return attack;
}

void Entity::setDefense(const int &num) {
	defense = (num > 0 ? num : 1);
}

int Entity::getDefense() const {
	return defense;
}

void Entity::setSpeed(const int &num) {
	speed = (num > 0 ? num : 1);
}

int Entity::getSpeed() const {
	return speed;
}

void Entity::setMagicPower(const int &num) {
	magicPower = (num > 0 ? num : 1);
}

int Entity::getMagicPower() const {
	return magicPower;
}

void Entity::setHp(const int &num) {
	hp = (num > 0 ? num : 0);
	if (hp > hpMax) {
		hp = hpMax;
	}
}

int Entity::getHp() const {
	return hp;
}

void Entity::setMp(const int &num) {
	mp = (num > 0 ? num : 0);
}

int Entity::getMp() const {
	return mp;
}

bool Entity::isAlive() const {
	return (hp > 0);
}

bool Entity::hasWeakness(const Element &element) const {
	bool found = false;

	for (unsigned int i = 0; i < weaknessList.size(); ++i) {
		if (weaknessList[i] == element) {
			found = true;
		}
	}

	return found;
}

bool Entity::hasResistance(const Element &element) const {
	bool found = false;

	for (unsigned int i = 0; i < resistanceList.size(); ++i) {
		if (resistanceList[i] == element) {
			found = true;
		}
	}

	return found;
}

void Entity::launchAttack(Entity *target, const Element &element) {
	int damage = 0;

	srand(static_cast<unsigned int>(time(0)));

	if (element == NONE) {
		damage = (attack - (target->getDefense() / 2)) + (rand() % attack / 5);
	}
	else {
		if (target->hasWeakness(element)) {
			damage = static_cast<int>((magicPower - (target->getMagicPower() / 2) + (rand() % magicPower / 5)) * 1.5);
		}
		else if (target->hasResistance(element)) {
			damage = static_cast<int>((magicPower - (target->getMagicPower() / 2) + (rand() % magicPower / 5)) / 1.5);
		}
		else {
			damage = magicPower - (target->getMagicPower() / 2) + (rand() % magicPower / 5);
		}
	}
	if (damage < 1) damage = 1;
	target->setHp(target->getHp() - damage);
}

bool Entity::heal() {
	if (mp >= 5) {
		setHp(hp + ((magicPower + (rand() % 10)) * 10));
		mp -= 5; 
		if (mp < 0) mp = 0;
		return true;
	}
	return false;
}

const int Entity::LEVEL_CAP = 99;