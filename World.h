#ifndef WORLD_H_
#define WORLD_H_
#include "Hero.h"
#include "Dungeon.h"
#include "NPC.h"
#include<iostream>
#include<istream>
#include<fstream>
using namespace std;



class World {
private:
	Hero hero;
	vector<Dungeon> dungeons;
	int villageX = 0;
	int villageY=0;
	vector<vector<char>>village;
	vector<vector<char> >current;
	vector<NPC> npcs;
public:
	World();
	World(const Hero &hero, const vector<Dungeon> &dungeons, vector<NPC>npcs);
	void StartGame();
	void DisplayVillage();
	void Save(Hero& h);
	void Load();
	void DisplayDungeons();
	void EnterDungeon();

	
};


#endif
