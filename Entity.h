// Entity Class Header
// This class is a super class for ALL characters
// By Nick Verrochi
// Last Modified: 5/12/15

#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

enum Element { NONE, FIRE, ICE, THUNDER };
// elements, used for weaknesses and resistances in enemies
// as well as attack types for magic-using player characters

class Entity {
public:
	void setName(const string &);
	string getName() const;

	void setLevel(const int &);
	int getLevel() const;

	void setHpMax(const int &);
	int getHpMax() const;

	void setMpMax(const int &);
	int getMpMax() const;

	void setAttack(const int &);
	int getAttack() const;

	void setDefense(const int &);
	int getDefense() const;

	void setSpeed(const int &);
	int getSpeed() const;

	void setMagicPower(const int &);
	int getMagicPower() const;

	void setHp(const int &);
	int getHp() const;

	void setMp(const int &);
	int getMp() const;

	bool isAlive() const;

	bool hasWeakness(const Element &) const;
	bool hasResistance(const Element &) const;

	void launchAttack(Entity *, const Element &);
	// launches offensive maneuvers
	// does NOT take away mp
	// that must be coded into individual classes

	bool heal();
	// used for healing magic
	// returns true if player has enough mp
	// otherwise false

	static const int LEVEL_CAP;

protected:
	string name;
	int level;
	
	// stats
	int hpMax;
	int mpMax;
	int attack;
	int defense;
	int speed;
	int magicPower;

	int hp;
	int mp;

	vector<Element> weaknessList;
	vector<Element> resistanceList;
};

#endif