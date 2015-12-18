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
	bool CheckLevelUp();

public:
	//Hero();
	Hero(string name, int attack, int defense, int stamina, int intelligence,
		int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<int> skills) :
		Life(name, attack, defense, stamina, intelligence, stun, weak, HP, MP, totalHP, totalMP, skills) {}
    bool CheckOwnership(Item& item);
    bool useItem(string itemName);
    void UpdateLevel();   // might call CheckLevelUp()
    bool PurchaseItem(string itemName);
    bool SellItem(string itemName);
    //bool WearEquip(Equipment equ);
    //bool TakeOffEquip(Equipment equ);



};