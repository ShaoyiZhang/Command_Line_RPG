#include "NPC.h"

/*class NPC {
private:
	vector<pair<Item, int>> itemForSale;
	vector<pair<Item, int>> specialItem;
	vector<string> talkings;
public:
	NPC(vector<pair<Item, int>> itemForSale, vector<pair<Item, int>> specialItem, vector<string>talkings);
	void Talking(Hero& h);
	void Trade(Hero & h);
	
	//improve the quality of the equiment, might result in the destroy of the equiment 
	//TO DO
	//void Enhance(Hero & h);

};*/

NPC::NPC(vector<Item> itemForSale, vector<Item> specialItem, vector<string>talkings, string specialMessage) {
	this->itemForSale = itemForSale;
	this->specialItem = specialItem;
	this->talkings = talkings;
	this->specialMessage = specialMessage;
}

//1% chance of trigger the hidden message and get to buy the special Item
void NPC::Talking(Hero& h) {
	int size = talkings.size();
	srand(time(NULL));
	if (rand() % 100 == 0) {
		cout << specialMessage << endl;
		TradeSpecialItem(h);
	}
}

void NPC::TradeSpecialItem(Hero & h) {
	int size = specialItem.size();
	srand(time(NULL));
	int index = rand() % size;
	cout<<"You are lucky today and I have something special to you"

}

void ShowItemsByIndex(vector<Item> items) {
	int size = items.size();
	for (int i = 0; i < size; i++) {
		cout << i << ". " << items[i].GetName() << "  $" << items[i].GetBuyPrice() << endl;
	}
}
