#ifndef DUNGEON_H_
#define DUNGEON_H_
#include "Monster.h"
#include "Hero.h"
#include<iostream>
#include <conio.h>
#include<string>
using namespace std;

//Each stage is 7x7
class Dungeon {
private:
	//vector reprents the monster in each stage, monsters[0][0] reprents monter No 0 in stage 0
	vector<vector<Monster>>monsters;
	//space represents nothing, H represents hero, number 0-9 represents monsters, T represents trap, 
	//I represents Item, C reprents Coins, E reprents exit
	vector<vector<vector<char>>>stages;
	//vector represents the same stage but with the Fog of War
	vector<vector<vector<char>>>Fog_of_War;

	int level;
	//from 1 to the level, 
	int LevelComplete=0;
	int playerX = 0;
	int playerY = 0;
	vector<int>goldByStages;
	vector<int>expByStages;
	//int represent percentage/10
	vector<std::pair<Item, int>> itemsByStage;

public:
	Dungeon(const vector<vector<Monster>> &monsters, const vector<vector<vector<char>>> &stages, const vector<int> &goldByStages,
		const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage);
	Dungeon(const vector<vector<Monster>> &monsters, string s1, const vector<int> &goldByStages,
		const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage);
	void StartDungeon(Hero & h) ;
	void LeaveDungeon(Hero& h);
	void DisplayFogAtLevel(int n);
	void ClearAllNearBlock();
};



#endif