#ifndef BAG_H_
#define BAG_H_

#include <iostream>
#include <map>
#include "Item.h"
using std::vector;
using std::map;
using std::string;

class Bag
{

private:
	const static size_t MAX_BAG_CAPACITY = 64;
	map<Item, int> myBag;
    void IncrementCount(string itemName);
public:
    Bag();
    Bag(map<Item, int> oneBag);
	size_t GetUsed();
	bool IsFull();
	bool UseItem(string itemName);
	bool PutInBag(Item &itemName);
	bool RemoveFromBag(Item &item, size_t number);
	string toString() const;


};

#endif