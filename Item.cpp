#include "Item.h"
#include <sstream>
#include "Hero.h"
#include "Monster.h"

bool Item::operator< (const Item &right) const
{
    return (this->buyInPrice < right.buyInPrice);
}

string Item::ToString() const
{
	std::ostringstream out;
	//oss << text << i;
							//std::cout << oss.str();
	out << this->name;
	for (int i = 0; i< 20 - this->name.size(); i++)
	{
		out << " ";
	}
	
	//out+=this->GetDescription();
	//out+="\n";
	//out+="Sell out for: "
	for (int i = 0; i < 4/*-(this->count/10)*/; i++)
	{
		out << " ";
	}
	out<<this->count;
	out<<"          ";  // 10 spaces
	out<<this->sellOutPrice;
	return out.str();
}

bool Item::Use(Hero &h, Monster &m)
{
	if (this->GetCount() > 0)
	{
		for (int i = 0; i < this->modifyAttributes.size(); i++)
		{
            int amount = modifyAttributes[i];
            switch(amount){
				case '0':
                    h.UpdateAtt(amount);
                    break;
				case '1':
                    h.UpdateDef(amount);
                    break;
				case '2':
                    break;
				case '3':
                    break;
				case '4':
                    break;
				case '5':
                    break;
				case '6':
                    break;
				case '7':
                    break;
				case '8':
                    break;
            }

		}
	}
	return false;
}