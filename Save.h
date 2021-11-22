// Save class header
// this class maintains a single saved character
// By Nick Verrochi
// Last Modified: 5/12/15

#ifndef SAVE_H
#define SAVE_H

#include <fstream>
#include "Player_Warrior.h"
#include "Player_Ninja.h"
#include "Player_Mage.h"
using namespace std;

struct CharacterStats {
// this structure holds character stats as objects
// must be serialized before binary i/o
	ClassID id;
	string name;
	string playerClass;

	int level;
	unsigned long long exp;
	unsigned long long expToNext;

	int attack;
	int defense;
	int magicPower;
	int speed;
	int hp; 
	int hpMax;
	int mp;
	int mpMax;
};

class Save {
public:
	Save(Player *);
	// creates a new save and generates a filename

	Save(const string &);
	// load a save using filename
	// throws FileNotFoundException
	// and InvalidFileNameException

	Player * getCharacterPointer();

	void setFileName(const string &);
	string getFileName() const;
	
	long getFileSize() const;

	CharacterStats * ripStats(Player *);
	// rips stats from a player object
	void setStats(CharacterStats *);
	// sets stats to player object pointed to by character

private:
	Player *character;
	string fileName;
	fstream fileStream;
	long fileSize;

	static const string FileNotFoundException;
	static const string InvalidFileNameException;
};

#endif