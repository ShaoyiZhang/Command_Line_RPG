#ifndef NPC_H_
#define NPC_H_
#include "Hero.h"
#include<iostream>
#include <time.h>

using std::pair;
using std::cout;
using std::cin;
using std::endl;

class NPC {
private:
	vector<Item> itemForSale;
	vector<Item> specialItem;
	vector<string> talkings;
	string specialMessage;
public:
	NPC(vector<Item> itemForSale, vector<Item> specialItem, vector<string>talkings, string specialMessage);
	void Talking(Hero& h);
	void Trade(Hero & h);
	void TradeSpecialItem(Hero & h);
	
	//improve the quality of the equiment, might result in the destroy of the equiment 
	//TO DO
	//void Enhance(Hero & h);

};


#endif