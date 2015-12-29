#include "Hero.h"
#include "Monster.h"
#include "Dungeon.h"
#include <iostream>
using namespace std;

int main() {
	//Hero(string name, int attack, int defense, int stamina, int intelligence,
		//int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<int> skills)

	//Initaliziation Test for Life and Hero
	vector<int>temp;
	Life pony = Life("person", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, temp);
	Hero Saber = Hero("Saber", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, temp);


    
	cout << "pony attack = " << pony.GetAtt()<<endl;

	cout << "Saber HP = " << Saber.GetHP()<<endl<<endl;

	//Item(string name,string description, int buyInPrice, int sellOutPrice)
	//Initalization Test for Item
	Item Primary_HP_Potion("Primary HP Potion", "restore 10 HP", 5, 2,1);
	cout<<"Buy in price for hp potion is" << Primary_HP_Potion.GetBuyPrice() << endl;
	cout << "Sell out price for Hp potion is " << Primary_HP_Potion.GetSellPrice() << endl;
	cout << "Description is " << Primary_HP_Potion.GetDescription() << endl<<endl;




	//Monster(string name, int attack, int defense, int stamina, int intelligence,
	//int TotalHP, int TotalMP, vector<int>skills, vector<std::pair<Item, int>>dpitems, int g, int exp)
	//initalization test for Monster
	vector<pair<Item, int>> dpitems;
	vector<Item> drop_from_Monster1;
	dpitems.push_back(pair<Item, int>(Primary_HP_Potion, 200));
	Monster monster_NO1("Imp", 3, 2, 4, 0, 12, 0, temp, dpitems, 5, 5);
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

	
	//Initilization Test for Dungeon
	//Dungeon(const vector<vector<Monster>> &monsters, string s1, const vector<int> &goldByStages,
		//const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage);
	vector<Monster>monsters;
	monsters.push_back(monster_NO1);
	monsters.push_back(monster_NO1);
	vector<vector<Monster>>m1;
	m1.push_back(monsters);
	vector<vector<vector<char>>> stages;
        string s1 = "S      000  0 C 1 000000       T 1  0  000   C 000 0  T000        E                                 ";
	cout<<"Length of s1 is "<<s1.size()<<endl;
	vector<int>goldByStages;
	goldByStages.push_back(20);
	vector<int>expByStages;
	expByStages.push_back(20);
	vector<std::pair<Item, int>> itemsByStage;
	Dungeon d1(m1, s1, goldByStages, expByStages, itemsByStage);

	d1.DisplayFogAtLevel(1);
	cout << endl;
	d1.StartDungeon(Saber);
	

}
