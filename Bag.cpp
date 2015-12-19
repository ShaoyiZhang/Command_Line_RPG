#include "Bag.h"
using std::iterator;

/*Bag::Bag(map<Item, int> oneBag)
{
    for (map<Item, int>::iterator current = oneBag.begin(); current!=oneBag.end(); current++)
    {
		
        string tempName = current->first();
        if (myBag.find(tempName) != myBag.end())
        {
            
        }
        this->myBag;
    }
}
*/

Bag::Bag(map<Item, int> oneBag)
{

}

Bag::Bag()
{
	
}

void Bag::IncrementCount(string itemName)
{
  	return;  
}

size_t Bag::GetUsed()
{
	return this->myBag.size();
}

bool Bag::IsFull()
{
	return false;
}

bool Bag::UseItem(string itemName)
{
	return false;
}

bool Bag::PutInBag(Item &itemName)
{
	return false;
}

bool Bag::RemoveFromBag(Item &item, size_t number)
{
	return false;
}

string Bag::toString() const
{
	return "stub";
}