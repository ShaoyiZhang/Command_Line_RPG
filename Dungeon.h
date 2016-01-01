#ifndef DUNGEON_H_
#define DUNGEON_H_
#include "Monster.h"
#include "Hero.h"
#include<iostream>
#include<string>
using namespace std;
//class World;
//class Monster;
//class Hero;

//Each stage is 10x10
class Dungeon {
 private:
  //vector reprents the monster in each stage, monsters[0][0] reprents monter No 0 in stage 0
  vector<vector<Monster>>monsters;
  //space represents nothing, H represents hero, number 0-9 represents monsters, T represents trap, 
  //I represents Item, C reprents Coins, E reprents exit
  vector<vector<vector<char>>>stages;
  //vector represents the same stage but with the Fog of War
  vector<vector<vector<char>>>Fog_of_War;
  //vector that represents if hero clear the certian level
  vector<bool>levelClear;
  //true monster indexed by their position
  vector<vector<pair<int,Monster>>> monstersByPosition;

  string name;
  int minimumLevelEnter;
  int level;
  //from 1 to the level, 
  int LevelComplete=0;
  int playerX = 0;
  int playerY = 0;
  bool autoFight = false;
  vector<int>goldByStages;
  vector<int>expByStages;
  //int represent percentage/10
  vector<std::pair<Item, int>> itemsByStage;
  //minimum gold and maximum gold in dungeon that can be picked up at each level
  vector<int> minGold;
  vector<int> maxGold;
 public:
 Dungeon() : name("Default"){}
  Dungeon(string name, int minimumLevelEnter, const vector<int> &minGold, const vector<int> &maxGold, const vector<vector<Monster>> &monsters, const vector<vector<vector<char>>> &stages, const vector<int> &goldByStages,
	  const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage);
  Dungeon(string name, int minimumLevelEnter, const vector<int> &minGold, const vector<int> &maxGold, const vector<vector<Monster>> &monsters, string s1, const vector<int> &goldByStages,
	  const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage);
  void StartDungeon(Hero & h) ;
  void LeaveDungeon(Hero& h);
  void DisplayFogAtLevel(int n);
  void ClearAllNearBlock();

  static void Help();
  static void FightInstruction();
  void Attack(Hero &h, Monster &m, int attacker); // 0 for monster, 1 for hero
  void MonsterTurn(Hero &h, Monster &m);
  void Fight(Hero &h, Monster &m);
  void Fight(Hero &h, Monster &m, int pro);
  //Get Monster By combination of Xindex and YIndex from monstersByPosition
  Monster& GetMonster(int l, int x, int y);
  void PickUpGoldAtLevel(Hero &h, int l);
  string GetName() {return name;}
  int GetMinLevel() {return minimumLevelEnter;}
  int GetDirection();
  void Reset();
};



#endif
