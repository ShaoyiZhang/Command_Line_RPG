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
	int buyInPrice;
	int sellOutPrice;
	// each int indicate an attribute to be changed after using this item
	// HP MP attack deff stamina intelligence stun weak
	vector<int> modifyAttributes;

public:
	void use();

};

#endif
