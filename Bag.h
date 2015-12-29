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
	const static int MAX_BAG_CAPACITY = 64;
	Item myBag[MAX_BAG_CAPACITY];
	int used;
   	void UpdateCount(int index, int amount);

public:
    Bag(){};
    //Bag(pair<Item, int> oneBag);

	size_t GetUsed();
	bool IsFull();
	int IsContain(Item &item); // -1 for not Contain , other value means index

	//bool UseItem(string itemName);
	bool UseItem(int itemNum);
	bool PutInBag(Item &itemName);
	bool RemoveFromBag(int Index, int amount);
	string ToString() const;
};

#endif