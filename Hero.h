#ifndef HERO_H_
#define HERO_H_

#include "Life.h"
#include "Bag.h"
//#include "NPC.h"

class Hero: public Life
{
private:
    int ownership;  // distinct value stored in World class, indicating Ownership
    int coins;
    int level;
    int experience;
    int maxEXP;
    Bag bag;
    //vector<equipment> equips;

public:
    Hero(){};
    Hero(string name, int attack, int defense, int stamina, int intelligence,
        int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<int> skills) :
        Life(name, attack, defense, stamina, intelligence, stun, weak, HP, MP, totalHP, totalMP, skills) {maxEXP = 5;}
    Hero(string name);
    bool CheckLevelUp();
    bool CheckOwnership(Item& item);
    //void UseItem(string itemName);
    void UseItem(int itemNum);
    void UpdateLevel();   // might call CheckLevelUp()
    bool PurchaseItem(string itemName);
    bool PurchaseItem(Item item);
    void PurchaseItem(Item item, int howMany);
    bool SellItem(string itemName);
    bool SellItem(Item item);
    bool SellItem(string itemName, int howMany);
    bool UseItem(int itemNum, Hero &h, Monster &m);
    // Get Methods for player
    int GetLevel(){ return this->level; }
    int GetCoins(){ return this->coins; }
    int GetEXP(){ return this->experience; };
    Bag GetBag(){ return this->bag; };
    void PrintLevel();
    void PrintCoins();
    void PrintEXP();
    // string GetBag() { return bag.ToString(); }

    void GainItem(Item i) { bag.PutInBag(i); }
    void GainCoins(int i) { coins += i; }
    void GainEXP(int i) { experience += i; UpdateLevel(); };
    
    void UseSkill(int skillNum);
    void SkillsToString(){};    /// #####################
    //bool WearEquip(Equipment equ);
    //bool TakeOffEquip(Equipment equ);



};
#endif