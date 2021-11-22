// Battle class implementation
// By Nick Verrochi
// Last Modified: 5/8/15

#include "Battle.h"
using namespace std;

Battle::Battle(Player *p, Monster *m) {
	player = p;
	monster = m;
}

bool Battle::fight() {
	while (player->isAlive() && monster->isAlive() && !player->isEscaping()) {
		printBattleStats();
		if (player->getSpeed() >= monster->getSpeed()) {
			playerTurn();
			if (monster->isAlive() && !player->isEscaping()) {
				monsterTurn();
			}
		}
		else {
			monsterTurn();
			if (player->isAlive()) {
				playerTurn();
			}
		}
		system("pause");
	}

	system("cls");
	printBattleStats();
	if (player->isAlive() && !player->isEscaping()) {
		player->setExp(player->getExp() + monster->getExpReward());
		cout << player->getName() << " has won! Gained " << monster->getExpReward() << " exp! \n";
		if (player->getExp() >= player->getExpToNext()) player->levelUp();
		player->setHp(player->getHpMax());
		player->setMp(player->getMpMax());
		delete monster;
		system("pause");
		return true;
	}
	else if (player->isEscaping()) {
		player->setHp(player->getHpMax());
		player->setMp(player->getMpMax());
		player->setEscaping(false);
		delete monster;
		system("pause");
		return true;
	}
	else {
		cout << monster->getName() << " has won! \n";
		player->setHp(player->getHpMax());
		player->setMp(player->getMpMax());
		delete monster;
		system("pause");
		return false;
	}
}

void Battle::playerTurn() {
	int choice;
	bool continueInput = true;

	while (continueInput) {
		cout << "Please choose a move: \n\n";
		player->printMenu();
		cout << endl << "Enter the number of your selection: ";
		cin >> choice;

		try {
			player->action(choice, monster);
			continueInput = false;
		}
		catch (string ex) {
			cout << ex;
			cin.clear();
			cin.ignore(80, '\n');
			printBattleStats();
		}
	}
}

void Battle::monsterTurn() {
	monster->action(player);
}

void Battle::printBattleStats() {
	system("cls");
	
	cout << player->getName() << " " << player->getPlayerClass() << " LVL " << player->getLevel()  << " (" << player->getExp() << "/" << player->getExpToNext() << "): \n"
		<< "\t HP: " << player->getHp() << "/" << player->getHpMax() << " "
		<< "MP: " << player->getMp() << "/" << player->getMpMax() << "\n\n";

	cout << monster->getName() << ": \n"
		<< "\t HP: " << monster->getHp() << "\n\n";
}