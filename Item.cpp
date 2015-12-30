#include "Item.h"
#include <sstream>
#include "Life.h"
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

int Item::TrueVal(Life &l, int original, int symbol, int amount)
{
	// Calculate new attribute depending on original value, operator(symbol), and the amount of change
	// symbol(operator): 0 for +, 1 for *
	 
	int trueVal = original + amount;
	if (symbol == 1)
	{
		trueVal = original * amount;
	}
}


bool Item::Use(Hero &h, Monster &m)
{
	if (this->GetCount() > 0)
	{
		for (int i = 0; i < this->modifyAttributes.size(); i++)
		{
			// symbol(operator): 0 for +, 1 for *

			char symbol = modifyAttributes[i].first;
            char amount = modifyAttributes[i].second;
            //int heroVal = TrueVal(h,symbol,amount);
            //int monsterVal = TrueVal(m,symbol,amount);
            switch(i){
				case '0':
                    h.SetAtt(TrueVal(h,h.GetAtt(),symbol,amount));
                    break;
				case '1':
                    h.SetDef(TrueVal(h,h.GetDef(),symbol,amount));
                    break;
				case '2':
					h.SetStam(TrueVal(h,h.GetStam(),symbol,amount));                    
					break;
				case '3':
					h.SetIntl(TrueVal(h,h.GetIntl(),symbol,amount));
                    break;
				case '4':
					h.SetStun(TrueVal(h,h.GetStun(),symbol,amount));
                    break;
				case '5':
					h.SetWeak(TrueVal(h,h.GetWeak(),symbol,amount));
                    break;
				case '6':
					h.SetHP(TrueVal(h,h.GetHP(),symbol,amount));
                    break;
				case '7':
					h.SetMP(TrueVal(h,h.GetMP(),symbol,amount));
                    break;
				case '8':
                    m.SetAtt(TrueVal(h,h.GetAtt(),symbol,amount));
                    break;
                case '9':
                	m.SetDef(TrueVal(h,h.GetDef(),symbol,amount));
                	break;
                case '10':
                	m.SetStam(TrueVal(h,h.GetStam(),symbol,amount));    
                	break;
 				case '11':
 					m.SetIntl(TrueVal(h,h.GetIntl(),symbol,amount));
 					break;
 				case '12':
 					m.SetStun(TrueVal(h,h.GetStun(),symbol,amount));
 					break;
 				case '13':
 					m.SetWeak(TrueVal(h,h.GetWeak(),symbol,amount));
 					break;
 				case '14':
 					m.SetHP(TrueVal(h,h.GetHP(),symbol,amount));
 					break;
 				case '15':
 					m.SetMP(TrueVal(h,h.GetMP(),symbol,amount));
 					break;
            }

		}
	}
	return false;
}