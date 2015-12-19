#include "Life.h"
#include "Bag.h"


class Hero: public Life
{
private:
	int ownership;	// distinct value stored in World class, indicating Ownership
	int coins;
	int level;
	int experience;
	Bag bag;
	//vector<equipment> equips;

public:
	//Hero();
	Hero(string name, int attack, int defense, int stamina, int intelligence,
		int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<int> skills) :
		Life(name, attack, defense, stamina, intelligence, stun, weak, HP, MP, totalHP, totalMP, skills) {}
	Hero(string name);
	bool CheckLevelUp();
    bool CheckOwnership(Item& item);
    bool useItem(string itemName);
    void UpdateLevel();   // might call CheckLevelUp()
    bool PurchaseItem(string itemName);
    bool SellItem(string itemName);
	int GetLevel() { return level; }
	int GetCoins() { return coins; }
	int GetEXP() { return experience; }
	Bag GetBag() { return bag; }
	void GainItem(Item i) { bag.PutInBag(i); }
	void GainCoins(int i) { coins += i; }
	void GainEXP(int i) { experience += i; UpdateLevel(); };

    //bool WearEquip(Equipment equ);
    //bool TakeOffEquip(Equipment equ);



};