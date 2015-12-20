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

void ShowItemsByIndex(vector<Item> items) {
	int size = items.size();
	for (int i = 0; i < size; i++) {
		cout << i << ". " << items[i].GetName() << "  $" << items[i].GetBuyPrice() << endl;
		cout << "  " << items[i].GetDescription() << endl << endl;
	}
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

void NPC::Buy(Hero & h) {
	int size = itemForSale.size(), index =0, number = 0;
	ShowItemsByIndex(itemForSale);
	cout << "Enter the index of the items you want to purcahse\n";
	cin >> index;
	if (index >= size) {
		cout << "Wrong Index! I don't want to do businees with fools /Smile\n";
		return;
	}
	cout << "Etner the number of " << itemForSale[index].GetName() << " you want to purchase";
	cin >> number;
	h.PurchaseItem(itemForSale[index].GetName(),number);
	cout << "Thanks for coming\n";
}

void NPC::Sell(Hero & h) {
	cout << h.GetBag() << endl;
	string itemName = "";
	int number = 0;
	cout << "Enter the name of the Item you wan to sell\n";
	cin >> itemName;
	cout << "Enter the number of the " << itemName << " you want to sell\n";
	cin >> number;
	h.SellItem(itemName, number);
	cout << "Thanks for coming\n";
}


void NPC::TradeSpecialItem(Hero & h) {
	int size = specialItem.size();
	srand(time(NULL));
	int index = rand() % size;
	cout << "You are lucky today and I have something special to you\n";
	cout << specialItem[index].GetName() << "  $" << specialItem[index].GetBuyPrice() << endl;
	cout << "  " << specialItem[index].GetDescription() << endl;

	cout << "\nDo you want to buy it? Enter Y to confirm and everything else otherwise\n";
	string input;
	cin >> input;
	if (input == "Y" || input == "y") {
		h.PurchaseItem(specialItem[index]);
	}

}

