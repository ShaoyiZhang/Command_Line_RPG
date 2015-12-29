#ifndef MONSTER_H_
#define MONSTER_H_

#include "Life.h"
#include "Item.h"
#include <time.h>

using std::to_string;

class Monster : public Life {
private:
	//secomd is a percent 1~1000, represent perecentage/10
	vector<std::pair<Item, int>>dropItems;
	//To Do: add a vector of Equiment drop off
	int gold;
	int EXP;
public:
	//Life(string name, int attack, int defense, int stamina, int intelligence,
		//int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<int> skills);
	Monster(string name, int attack, int defense, int stamina, int intelligence,
		int TotalHP, int TotalMP, vector<int>skills, vector<std::pair<Item, int>>dpitems, int g, int exp)
		: Life(name, attack, defense, stamina, intelligence, 0, 0, TotalHP, TotalMP, totalHP, TotalMP, skills), dropItems(dpitems), gold(g), EXP(exp) {}

	int GiveGold();
	int GiveEXP();
//    void UpdateHP(int amount){ this->}; // ################################### TO DO ##########################
	vector<Item> DropOff();
	string To_String_Part_One();
	string To_String_Part_Two();
};

#endif

