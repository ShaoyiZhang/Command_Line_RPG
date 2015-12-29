#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Hero;
class Monster;

class Item
{
private:
    string name;
	string description;
	int buyInPrice;
	int sellOutPrice;
	// each int indicate an attribute to be changed after using this item
	// HP MP attack deff stamina intelligence stun weak
	vector<int> modifyAttributes;

	int count;
	
public:
	Item():name("..."), description("..."), buyInPrice(0), sellOutPrice(0), count(0){};
	Item(string name,string description, int buyInPrice, int sellOutPrice,int count):name(name),description(description), buyInPrice(buyInPrice), sellOutPrice(sellOutPrice), count(count){};
	Item(string name, string description, int buyInPrice, int sellOutPrice, vector<int> modifyAttributes, int count):name(name),description(description), buyInPrice(buyInPrice), sellOutPrice(sellOutPrice),modifyAttributes(modifyAttributes), count(count){};
	bool Use(Hero &h, Monster &m);
    bool operator < (const Item &right) const;
    //int SetCount(int count){ this->count = count; }
    void IncrCount(int amount){ this->count += amount; };
    int GetCount(){ return this->count; };
    int GetBuyPrice(){ return this->buyInPrice; };
    int GetSellPrice(){ return this->sellOutPrice; };
	string GetName() { return name; }
	string GetDescription() { return description; }
	string ToString() const;
};

#endif
