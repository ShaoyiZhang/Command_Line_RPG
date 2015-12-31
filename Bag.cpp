#include "Bag.h"
using std::iterator;
using std::endl;
using std::cout;
/*Bag::Bag(map<Item, int> oneBag)
{
    for (map<Item, int>::iterator current = oneBag.begin(); current!=oneBag.end(); current++)
    {
        
        string tempName = current->first();
        if (Bag.find(tempName) != Bag.end())
        {
            
        }
        this->Bag;
    }
}
*/
/*
Bag::Bag(map<Item, int> oneBag)
{

}
*/
Bag::Bag()
{
	used = 0;
}

size_t Bag::GetUsed()
{
    return this->used;
}

bool Bag::IsFull()
{
    return used >= MAX_BAG_CAPACITY;
}

bool Bag::UseItem(int itemNum, Hero &h, Monster &m)
{
    if (itemNum<used)
    {
        if (this->bag[itemNum].Use(h,m))
        {
            if (bag[itemNum].GetCount() == 0)
            {
                this->RemoveFromBag(itemNum,0);
            }
            return true;
        }
    }
        return false; 
}

int Bag::FindIndex(Item item)
{
    int index = 0;
    for (int i = 0; (i < used)&&(bag[i].GetName() != item.GetName()&&(bag[i].GetName()!="...s")); i++)
        {
            index = i;
        }

    if (index < used)
        return index;
    return -1;
}

void Bag::UpdateCount(int index, int amount)
{
    this->bag[index].IncrCount(amount);
}

bool Bag::PutInBag(Item &newItem)
{
    int index = 0;
    if (!this->IsFull())
    {        
        index = this->FindIndex(newItem);
        if (index == -1)
        {
			if (used <= 0)
				index = 0;
            this->bag[index] = newItem;
            cout << "I have put " << newItem.GetName() << " into your bag, Master." << endl;
            used++;
        }
        else
        {
            this->UpdateCount(index, newItem.GetCount() + bag[index].GetCount());
            cout << "You now have " << bag[index].GetCount() << " " << bag[index].GetName() << "s, Master." << endl;
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
        if (bag[index].GetCount() == amount)
        {
            bag[index] = bag[used-1];
            bag[used-1] = Item();
        }
        else
        {
            bag[index].IncrCount(-amount);
        }
        used--;
        return true;
    }
}

string Bag::ToString() const
{
    string out = "";
    for (int i = 0; i < used; i++)
    {
        out+=this->bag[i].ToString();
    }
    return out;
}