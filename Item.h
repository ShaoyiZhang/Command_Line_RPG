#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Item
{
private:
    string name;
	int buyInPrice;
	int sellOutPrice;
	// each int indicate an attribute to be changed after using this item
	// HP MP attack deff stamina intelligence stun weak
	vector<int> modifyAttributes;

public:
	Item(string name, int buyInPrice, int sellOutPrice):name(name),buyInPrice(buyInPrice), sellOutPrice(sellOutPrice){};
	Item(string name, int buyInPrice, int sellOutPrice, vector<int> modifyAttributes){};
	void use();
    bool operator < (const Item &right) const;
    int GetBuyPrice(){ return this->buyInPrice; };
    int GetSellPrice(){ return this->sellOutPrice; };
};

#endif
