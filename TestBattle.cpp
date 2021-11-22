// This is a test for the battle system
// By Nick Verrochi
// Last Modified: 5/13/15

#include "Battle.h"
#include "Save.h"
#include "Player_Warrior.h"
#include "Player_Ninja.h"
#include "Player_Mage.h"
#include "Monster_Slime.h"
#include "Monster_Dragon.h"
#include "Monster_GiantCrab.h"
#include "Monster_Golem.h"
#include "Monster_FinalBoss.h"
using namespace std;

int main() {
	int menuChoice;
	string name;

	Battle *battle = nullptr;
	Player *player = nullptr;
	Save *gameSave = nullptr;
	Monster *enemy = nullptr;

	while (player == nullptr) {
		cout << "Welcome! Which would you like: \n"
			<< "\t 1. New game \n"
			<< "\t 2. Load \n";
		cout << "Enter your choice: ";
		cin >> menuChoice;   cin.ignore();

		if (menuChoice == 1) {
			cout << "Enter a character name: ";
			getline(cin, name);

			cout << "Pick a class: \n"
				<< "\t 1. Warrior \n"
				<< "\t 2. Ninja \n"
				<< "\t 3. Mage \n";
			cout << "Enter your choice: ";
			cin >> menuChoice;
			cin.ignore(80, '\n');

			switch (menuChoice) {
			case 1:
				player = new Warrior(name);
				break;
			case 2:
				player = new Ninja(name);
				break;
			case 3:
				player = new Mage(name);
				break;
			default:
				cout << "Invalid choice, defaulting to Warrior...\n";
				player = new Warrior(name);
				cin.clear();   cin.ignore(80, '\n'); 
			}

			gameSave = new Save(player);
		}
		else {
			cout << "Enter filename (in format ClassName_PlayerName.sav)\n: ";
			getline(cin, name);
			try {
				gameSave = new Save(name);
				player = gameSave->getCharacterPointer();
			}
			catch (string ex) {
				cout << ex;
				system("pause");
				system("cls");
			}
		}
	}

	while (true) {
		system("cls");
		cout << "What would you like to fight? \n"
			<< "\t 1. Slime      (rec level: 1) \n"
			<< "\t 2. Dragon     (rec level: 3) \n"
			<< "\t 3. Giant Crab (rec level: 5) \n"
			<< "\t 4. Golem      (rec level: 8) \n"
			<< "\t 5. Final Boss (rec level: 15) \n"
			<< "Enter your choice: ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			enemy = new Slime(player->getLevel());
			break;
		case 2:
			enemy = new Dragon(player->getLevel());
			break;
		case 3:
			enemy = new GiantCrab(player->getLevel());
			break;
		case 4:
			enemy = new Golem(player->getLevel());
			break;
		case 5:
			enemy = new Delta();
			cout << "So you think you can program? \n";
			system("pause");
			break;
		default:
			cout << "Invalid entry, defaulting to slime...\n";
			enemy = new Slime(player->getLevel());
			cin.clear();   cin.ignore(80, '\n');
		}

		system("cls");
		battle = new Battle(player, enemy);
		battle->fight();
		gameSave = new Save(player);
		if (menuChoice == 5) {
			system("cls");
			cout << "POST! \n";
			system("pause");
		}
	}

	system("pause");
	return 0;
}