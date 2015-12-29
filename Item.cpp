#include "Item.h"
#include <sstream>
void Item::use()
{
    
}

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