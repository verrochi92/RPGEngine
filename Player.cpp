// Player class implementation
// By Nick Verrochi
// Last Modified: 5/12/15

#include "Player.h"
using namespace std;

Player::Player(const string &playerName) {
	name = playerName;
	level = 1;
	exp = 0;
	expToNext = 100;
	escaping = false;
}

void Player::setExp(const unsigned long long &num) {
	exp = (num < 0 ? 0 : num);
}

unsigned long long Player::getExp() const {
	return exp;
}

void Player::setExpToNext(const unsigned long long &num) {
	expToNext = (num > 0 ? num : 1);
}

unsigned long long Player::getExpToNext() const {
	return expToNext;
}

void Player::setPlayerClass(const string &name) {
	playerClass = name;
}

string Player::getPlayerClass() const {
	return playerClass;
}

void Player::setID(const ClassID &id) {
	classID = id;
}

ClassID Player::getID() const {
	return classID;
}

void Player::setEscaping(const bool &esc) {
	escaping = esc;
}

bool Player::isEscaping() const {
	return escaping;
}

const string Player::ChoiceOutOfRangeException = "Error! Choice out of Range! \n";