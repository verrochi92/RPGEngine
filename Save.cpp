// Save class implementation
// By Nick Verrochi
// Last Modified: 5/8/15

#include "Save.h"
using namespace std;

Save::Save(Player * player) {
	CharacterStats *stats = ripStats(player);
	character = player;

	fileName = character->getPlayerClass() + "_" + character->getName() + ".sav";
	fileSize = sizeof(CharacterStats);

	fileStream.open(fileName, ios::out | ios::binary);
	fileStream.write(reinterpret_cast<char *>(stats), fileSize);
	fileStream.close();
}

Save::Save(const string &file) {
	CharacterStats *stats = new CharacterStats;

	fileName = file;
	fileSize = sizeof(CharacterStats);

	fileStream.open(fileName, ios::in | ios::binary);
	if (!fileStream.is_open()) {
		fileStream.close();
		throw FileNotFoundException;
	}
	else {
		fileStream.read(reinterpret_cast<char *>(stats), fileSize);
		switch (stats->id) {
		case WARRIOR:
			character = new Warrior("");
			break;
		case NINJA:
			character = new Ninja("");
			break;
		case MAGE:
			character = new Mage("");
			break;
		default:
			throw InvalidFileNameException;
		}
	}
	fileStream.close();
	setStats(stats);
}

Player * Save::getCharacterPointer() {
	return character;
}

void Save::setFileName(const string &name) {
	fileName = name;
}

string Save::getFileName() const {
	return fileName;
}

long Save::getFileSize() const {
	return fileSize;
}

CharacterStats * Save::ripStats(Player *player) {
	CharacterStats *stats = new CharacterStats;

	stats->id = player->getID();
	stats->name = player->getName();
	stats->playerClass = player->getPlayerClass();
	

	stats->level = player->getLevel();
	stats->exp = player->getExp();
	stats->expToNext = player->getExpToNext();

	stats->attack = player->getAttack();
	stats->defense = player->getDefense();
	stats->magicPower = player->getMagicPower();
	stats->speed = player->getSpeed();
	stats->hp = player->getHp();
	stats->hpMax = player->getHpMax();
	stats->mp = player->getMp();
	stats->mpMax = player->getMpMax();

	return stats;
}

void Save::setStats(CharacterStats *stats) {
	character->setID(stats->id);
	character->setName(stats->name);
	character->setPlayerClass(stats->playerClass);

	character->setLevel(stats->level);
	character->setExp(stats->exp);
	character->setExpToNext(stats->expToNext);

	character->setAttack(stats->attack);
	character->setDefense(stats->defense);
	character->setMagicPower(stats->magicPower);
	character->setSpeed(stats->speed);
	character->setHpMax(stats->hpMax);
	character->setHp(stats->hpMax);
	character->setMpMax(stats->mpMax);
	character->setMp(stats->mpMax);
}

const string Save::FileNotFoundException = "Error! File not found. \n";
const string Save::InvalidFileNameException = "Error! Invalid file name. \n";