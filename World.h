#ifndef WORLD_H_
#define WORLD_H_
#include "Hero.h"
#include "Dungeon.h"
#include "NPC.h"
#include<istream>
#include<fstream>
using namespace std;



class World {
private:
	Hero hero;
	Dungeon dungeons;
	vector<NPC> npcs;
public:
	World(Hero hero, Dungeon dungeons, vector<NPC>npcs);
	void Save(Hero& h);
	void Load();
	
};


#endif