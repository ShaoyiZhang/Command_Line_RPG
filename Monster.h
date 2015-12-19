#include "Life.h"
#include "Item.h"
#include <time.h>


class Monster : public Life {
private:
	//secomd is a percent 1~1000, represent perecentage/10
	vector<std::pair<Item, int>>dropItems;
	int gold;
	int EXP;
public:
	int GiveGold();
	int GiveEXP();
	vector<Item> DropOff();
};


