// Monster class implementation
// By Nick Verrochi
// Last Modified: 5/12/15

#include "Monster.h"
using namespace std;

Monster::Monster(const int &playerLevel) {
	int random; // stores random offset for bounds testing

	srand(static_cast<unsigned int>(time(0)));

	if (rand() % 10 > 8) {
		random = rand() % 3;
		level = (playerLevel + random <= LEVEL_CAP ? playerLevel + random : LEVEL_CAP);
	}
	else {
		random = rand() % 6;
		level = (playerLevel - random > 0 ? playerLevel - random : 1);
	}
}

void Monster::setExpReward(const unsigned long long &num) {
	expReward = (num > 0 ? num : 1);
}

unsigned long long Monster::getExpReward() const {
	return expReward;
}