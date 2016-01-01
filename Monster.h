#ifndef MONSTER_H_
#define MONSTER_H_

#include "Life.h"
#include "Item.h"
#include "Hero.h"
#include <time.h>

using namespace std;


class Monster : public Life {
private:
	//secomd is a percent 1~1000, represent perecentage/10
	vector<std::pair<Item, int>>dropItems;
	//To Do: add a vector of Equiment drop off
	int gold;
	int EXP;
public:
	/*Life(string name, int attack, int defense, int stamina, int intelligence,
         int stun, int weak,int HP, int MP,vector<int> skills);
	 Life(string name, int attack, int defense, int stamina, int intelligence, vector<int> skills);*/
 Monster() : Life("Default", 0, 0, 0, 0, vector<int>()), gold(0), EXP(0) {}
	Monster(string name, int attack, int defense, int stamina, int intelligence,
	 vector<int>skills, vector<std::pair<Item, int>>dpitems, int g, int exp)
		: Life(name, attack, defense, stamina, intelligence,  skills), dropItems(dpitems), gold(g), EXP(exp) {}

	void DefeatedBy(Hero& h);
	int GiveGold();
	int GiveEXP();
//    void UpdateHP(int amount){ this->}; // ################################### TO DO ##########################
	vector<Item> DropOff();
	string To_String_Part_One();
	string To_String_Part_Two();
};

#endif

