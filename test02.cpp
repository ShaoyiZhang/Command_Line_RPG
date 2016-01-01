#include "Hero.h"
#include "Monster.h"
#include "Dungeon.h"
#include "World.h"
#include <iostream>
using namespace std;

int main() {
	//Hero(string name, int attack, int defense, int stamina, int intelligence,
		//int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<int> skills)

	//Initaliziation Test for Life and Hero
	vector<int>temp;
	Life pony = Life("person", 1, 2, 3, 4, 5, 6, 7, 8,  temp);
	Hero Saber = Hero("Saber", 1, 20, 10, 3, 4, 0,0,12, 16,  temp);


    
	cout << "pony attack = " << pony.GetAtt()<<endl;

	cout << "Saber HP = " << Saber.GetHP()<<endl<<endl;

	//Item(string name,string description, int buyInPrice, int sellOutPrice)
	//Initalization Test for Item
	Item Primary_HP_Potion("Primary HP Potion", "restore 10 HP", 5, 2,1);
	cout<<"Buy in price for hp potion is" << Primary_HP_Potion.GetBuyPrice() << endl;
	cout << "Sell out price for Hp potion is " << Primary_HP_Potion.GetSellPrice() << endl;
	cout << "Description is " << Primary_HP_Potion.GetDescription() << endl<<endl;
	
	Item Advance_HP_Potion(" Advance_HP_Potion", "restore 20 HP", 10,4,1);


	//Initilization of NPC 
	// NPC(vector<Item> itemForSale, vector<Item> specialItem, 
	//vector<string>talkings, string specialMessage);
	vector<string>talkings;
	talkings.push_back("It is a good day today\n");
	talkings.push_back("I like here. Do you?\n");
	talkings.push_back("God, it is so borning.\n");
	talkings.push_back("What are you looking at?\n");
	talkings.push_back("I will go back to my village once I get enoguh money\n");
	
	vector<Item>npcItems;
	npcItems.push_back(Primary_HP_Potion);

	vector<Item>specialNPCItem;
	specialNPCItem.push_back(Advance_HP_Potion);
	
	string specialMessage = "Hmm.. You are lucky today, I have something special for you\n";

	NPC merchant(npcItems,specialNPCItem,talkings,specialMessage);

	merchant.Talking(Saber);
	merchant.Talking(Saber);
	merchant.Talking(Saber);
	




	//Monster(string name, int attack, int defense, int stamina, int intelligence,
	//int TotalHP, int TotalMP, vector<int>skills, vector<std::pair<Item, int>>dpitems, int g, int exp)
	//initalization test for Monster
	vector<pair<Item, int>> dpitems;
	vector<Item> drop_from_Monster1;
	dpitems.push_back(pair<Item, int>(Primary_HP_Potion, 1000));
	Monster monster_NO1("Imp", 11, 2, 4, 0, temp, dpitems, 5, 5);
	cout << "The name of this monter for testing is " << monster_NO1.GetName()<<endl;
	cout << "The gold that monster_NO1 will drop is " << monster_NO1.GiveGold()<<endl;
	drop_from_Monster1 = monster_NO1.DropOff();
	cout << "The Exp that this monster_NO1 will give is " << monster_NO1.GiveEXP() << endl;
	cout << "The size of the vector of Item that this monster will give is " << drop_from_Monster1.size() << endl;
	if (drop_from_Monster1.size() != 0) {
		for (Item i : drop_from_Monster1)
			cout<<"The name of the drop of is " << i.GetName() << endl;
	}
	cout << endl;


	//Monster 02 with same dropoff
	Monster monster_NO2("Bat", 13, 1, 4, 2,  temp, dpitems, 7, 7);
	cout << "The name of this monter for testing is " << monster_NO2.GetName()<<endl;
	cout << "The gold that monster_NO2 will drop is " << monster_NO2.GiveGold()<<endl;
	drop_from_Monster1 = monster_NO2.DropOff();
	cout << "The Exp that this monster_NO2 will give is " << monster_NO2.GiveEXP() << endl;
	cout << "The size of the vector of Item that this monster will give is " << drop_from_Monster1.size() << endl;
	if (drop_from_Monster1.size() != 0) {
		for (Item i : drop_from_Monster1)
			cout<<"The name of the drop of is " << i.GetName() << endl;
	}
	cout << endl;


	



	
	//Initilization Test for Dungeon
	//Dungeon(const vector<vector<Monster>> &monsters, string s1, const vector<int> &goldByStages,
		//const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage);
	vector<Monster>monsters;
	monsters.push_back(monster_NO1);
	monsters.push_back(monster_NO1);
	vector<vector<Monster>>m1;
	m1.push_back(monsters);
	//Monster for second level
	monsters.clear();
	monsters.push_back(monster_NO1);
	monsters.push_back(monster_NO2);
	m1.push_back(monsters);
	vector<vector<vector<char>>> stages;

        string s1 = "       000  0 C 1 000000       T 1  0  000   C 000 0  T000        E                                            0   C 0    0 1    0           0  1  1              0     C        0   C 1 C             E";
	cout<<"Length of s1 is "<<s1.size()<<endl;
	vector<int>goldByStages;
	goldByStages.push_back(20);
	goldByStages.push_back(40);
	vector<int>expByStages;
	expByStages.push_back(20);
	expByStages.push_back(40);
	vector<std::pair<Item, int>> itemsByStage;
	itemsByStage.push_back(pair<Item,int>(Primary_HP_Potion,500));
	itemsByStage.push_back(pair<Item,int>(Primary_HP_Potion,500));

	vector<int>minGold;
	vector<int>maxGold;
	minGold.push_back(5);
	minGold.push_back(10);
	maxGold.push_back(20);
	maxGold.push_back(30);
	
	Dungeon d1("Dark Forest",1,minGold, maxGold, m1, s1, goldByStages, expByStages, itemsByStage);
	cout << endl;
	//d1.StartDungeon(Saber); 


	//initalize world
	//World(const Hero &hero, const Dungeon &dungeons);
	vector<Dungeon>dungeons;
	dungeons.push_back(d1);

	vector<NPC>npcs;
	npcs.push_back(merchant);
	
	World w1(Saber,dungeons,npcs);
	w1.DisplayVillage();
	w1.StartGame();

}
