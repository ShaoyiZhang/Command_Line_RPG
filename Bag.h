#ifndef BAG_H_
#define BAG_H_

#include <iostream>
#include <map>
#include "Item.h"
using std::vector;
using std::map;
using std::string;

class Hero;
class Monster;

class Bag
{

private:
	const static int MAX_BAG_CAPACITY = 64;
	Item bag[MAX_BAG_CAPACITY];
	int used;

public:
    Bag();
    //Bag(pair<Item, int> oneBag);

	size_t GetUsed();
	bool IsFull();
	int FindIndex(Item &item); // -1 for not Contain , other value means index

	bool UseItem(int itemNum){ return false; };
	bool UseItem(int itemNum, Hero &h, Monster &m);
	bool PutInBag(Item &itemName);
	bool RemoveFromBag(int Index, int amount);
    void UpdateCount(int index, int amount);
	string ToString() const;
};

#endif