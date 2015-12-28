#include "Bag.h"
using std::iterator;
using std::endl;
using std::cout;
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
/*
Bag::Bag(map<Item, int> oneBag)
{

}

Bag::Bag()
{
	
}

void Bag::UpdateCount(string itemName)
{
  	return;  
}
*/
size_t Bag::GetUsed()
{
	return this->used;
}

bool Bag::IsFull()
{
	return used >= MAX_BAG_CAPACITY;
}

bool Bag::UseItem(int itemNum)
{
    return false;
}

int Bag::IsContain(Item &item)
{
    int index = 0;
    for (size_t i = 0; (i < used)&&(myBag[i].GetName() != item.GetName()); i++)
        {
            index++;
        }

    if (index < used)
        return index;
    return -1;
}

void Bag::UpdateCount(int index, int amount)
{
    this->myBag[index].IncrCount(amount);
}

bool Bag::PutInBag(Item &newItem)
{
    int index = 0;
    if (!this->IsFull())
    {        
        index = this->IsContain(newItem);
        if (index == -1)
        {
            this->myBag[index] = newItem;
            cout << "I have put " << newItem.GetName() << " into your bag, Master." << endl;
        }
        else
        {
            this->UpdateCount(index, newItem.GetCount() + myBag[index].GetCount());
            cout << "You now have " << myBag[index].GetCount() << " " << myBag[index].GetName() << "s, Master." << endl;
        }

        return true;  
    }

    return false;


}

bool Bag::RemoveFromBag(int index, int amount)
{
    if (index >= used)
	   return false;
    else // does contain, start removal
    {
        if (myBag[index].GetCount() == amount)
        {
            myBag[index] = myBag[used-1];
            myBag[used-1] = Item();
        }
        else
        {
            myBag[index].IncrCount(-amount);
        }
        return true;
    }
}

string Bag::toString() const
{
	return "stub";
}