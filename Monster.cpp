#include "Monster.h"

/*class Monster : public Life {
private:
	vector<std::pair<Item, int>>dropItems;
	int gold;
	int EXP;
public:
	int GiveGold();
	int GiveEXP();
	vector<Item> DropOff();
};*/

int Monster::GiveEXP() {
	return EXP;
}

//return 50%+ rand() amount of gold
int Monster::GiveGold() {
	int temp = gold / 2;
	srand(time(NULL));
	temp = rand() % temp;
	std::cout << "Extr gold it will give is " << temp << std::endl;
	return gold / 2 + temp;
}

vector<Item> Monster::DropOff() {
	vector<Item> drops;
	srand(time(NULL));
	for (std::pair<Item, int> p : dropItems) {
		std::cout << "rand() % 1000 is " << rand() % 1000 << std::endl;
		if (rand() % 1000 < p.second)
			drops.push_back(p.first);
	}
	return drops;
}
