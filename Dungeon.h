#ifndef DUNGEON_H_
#define DUNGEON_H_
#include "Monster.h"
#include "Hero.h"

class Dungeon {
private:
	vector<vector<Monster>>stages;
	int size;
	int LevelComplete;
	vector<int>goldByStages;
	vector<int>expByStages;
	//int represent percentage/10
	vector<std::pair<Item, int>> itemsByStage;

public:
	void StartDungeon(Hero & h) ;
	void LeaveDungeon(Hero& h);
};



#endif