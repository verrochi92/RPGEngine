// Player class header
// This is a superclass for all player character classes
// By Nick Verrochi
// Last Modified: 5/12/15

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
using namespace std;

enum ClassID { WARRIOR, NINJA, MAGE };
// class IDs used for loading saves

class Player : public Entity {
public:
	Player(const string &playerName);
	// new player from scratch, defaults level, exp, and expToNext
	// does NOT set initial stats as these are based on class

	void setExp(const unsigned long long &);
	unsigned long long getExp() const;

	void setExpToNext(const unsigned long long &);
	unsigned long long getExpToNext() const;

	void setPlayerClass(const string &);
	string getPlayerClass() const;

	void setID(const ClassID &);
	ClassID getID() const;
	// returns the class ID for loading saves

	void setEscaping(const bool &);
	bool isEscaping() const;
	// used for moves that allow the player to leave battle

	virtual void levelUp() = 0;
	// levels up character and updates stats
	// unique to each player class, as stats will
	// increase to fit the class's playing style

	virtual void printMenu() = 0;
	// prints menu for player to choose moves
	// unique to each player class

	virtual void action(const int &, Entity *) = 0;
	// determines which action to do based off a menu choice
	// throws exception ChoiceOutOfRangeException if int argument
	// is out of range of possible choices for the character

protected:
	unsigned long long exp;	// current exp
	unsigned long long expToNext; // exp to next level
	string playerClass; // class name, used for displaying stats
	ClassID classID;
	bool escaping;

	static const string ChoiceOutOfRangeException;
};

#endif